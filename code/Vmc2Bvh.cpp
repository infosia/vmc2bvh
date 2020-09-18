#define CGLTF_IMPLEMENTATION

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unordered_map>

#include "osc/OscReceivedElements.h"
#include "osc/OscPacketListener.h"
#include "ip/UdpSocket.h"
#include "cgltf/cgltf.h"
#include "CLI11.hpp"

#include "cgltf_func.inl"

using namespace osc;

class Vmc2BvhPacketListener : public OscPacketListener {
public:

	Vmc2BvhPacketListener(const vmc2bvh_options options) : OscPacketListener()
		, vrmdata(nullptr)
		, rootnode(nullptr)
		, options(options)
		, ofstream_MOTION(options.bvhfile_MOTION)
		, ofstream_BLEND(options.bvhfile_BLEND)
		, state{ false, false, 0, 0, nullptr, nullptr }
		, lasttime_checked()
		, frame_count(0)
		, humanoid_mapping{}
		, blendshapes()
	{

	}

	virtual ~Vmc2BvhPacketListener()
	{
		if (vrmdata != nullptr) {
			cgltf_free(vrmdata);
		}
	}

	virtual void ProcessMessage(const osc::ReceivedMessage& m,
		const IpEndpointName& remoteEndpoint)
	{
		(void)remoteEndpoint; // UNUSED

		auto arg = m.ArgumentsBegin();
		const auto address = m.AddressPattern();
		if (!state.loaded && std::strcmp(address, "/VMC/Ext/OK") == 0 && arg->IsInt32()) {
			const auto loaded = (arg++)->AsInt32Unchecked();
			const auto calibrated = (arg++)->AsInt32Unchecked();
			if (loaded == 1 && calibrated == 3) {
				state.loaded = true;
			}
		}
		else if (!state.vrm_received && state.loaded && std::strcmp(address, "/VMC/Ext/VRM") == 0) {
			if (arg->IsString()) {
				const auto value = (arg++)->AsStringUnchecked();
				if (strlen(value) > 0) {

					cgltf_options parse_options = {};
					parse_options.file.read = &vrm_file_read;

					if (vrmdata != nullptr) {
						cgltf_free(vrmdata);
					}

					const auto result = cgltf_parse_file(&parse_options, value, &vrmdata);

					if (result == cgltf_result_success) {
						cgltf_size index;
						if (vrm_get_root_bone(vrmdata, options.rootbone, &index)) {
							std::cout << "[INFO] Start recording..." << std::endl;
							rootnode = &vrmdata->nodes[index];

							// Keep track of root motion and rotation
							state.translation = rootnode->translation;
							state.rotation = rootnode->rotation;

							// Constructs humanoid-bone => node mapping 
							humanoid_mapping = vrm_get_humanoid_mapping(vrmdata);

							// Write HIERARCHY
							std::ofstream ofstream_HIERARCHY(options.bvhfile_HIERARCHY);
							state.ofstream_HIERARCHY = &ofstream_HIERARCHY;
							state.ofstream_MOTION = &ofstream_MOTION;
							bvh_traverse_bones(rootnode, &state);
							
							// Blendshape
							ofstream_BLEND << "[" << std::endl;

							// Write first MOTION
							bvh_traverse_bone_motion(rootnode, &state, true, options.motion_in_place);
							frame_count++;

							state.vrm_received = true;
						}
						else {
							std::cout << "[ERROR] Unable to find root bone. Please specify root bone name with --bone option" << std::endl;
						}
					}
					else {
						std::cout << "[ERROR] Unable to parse VRM file. Status: " << result << std::endl;
					}

				}
			}
		}
		else if (state.vrm_received && rootnode != nullptr && std::strcmp(address, "/VMC/Ext/Root/Pos") == 0) {

			arg++; // ignore root bone name

			const auto px = (arg++)->AsFloatUnchecked();
			const auto py = (arg++)->AsFloatUnchecked();
			const auto pz = (arg++)->AsFloatUnchecked();
			const auto qx = (arg++)->AsFloatUnchecked();
			const auto qy = (arg++)->AsFloatUnchecked();
			const auto qz = (arg++)->AsFloatUnchecked();
			const auto qw = (arg++)->AsFloatUnchecked();

			rootnode->translation[0] = px;
			rootnode->translation[1] = py;
			rootnode->translation[2] = pz;
			rootnode->rotation[0] = qx;
			rootnode->rotation[1] = qy;
			rootnode->rotation[2] = qz;
			rootnode->rotation[3] = qw;

		}
		else if (state.vrm_received && std::strcmp(address, "/VMC/Ext/Bone/Pos") == 0) {
			const auto name = (arg++)->AsStringUnchecked();
			const auto px = (arg++)->AsFloatUnchecked();
			const auto py = (arg++)->AsFloatUnchecked();
			const auto pz = (arg++)->AsFloatUnchecked();
			const auto qx = (arg++)->AsFloatUnchecked();
			const auto qy = (arg++)->AsFloatUnchecked();
			const auto qz = (arg++)->AsFloatUnchecked();
			const auto qw = (arg++)->AsFloatUnchecked();

			cgltf_node* node = vrm_get_humanoid_bone(name, &humanoid_mapping);

			if (node != nullptr) {
				node->translation[0] = px;
				node->translation[1] = py;
				node->translation[2] = pz;
				node->rotation[0] = qx;
				node->rotation[1] = qy;
				node->rotation[2] = qz;
				node->rotation[3] = qw;
			}
		}
		else if (state.vrm_received && std::strcmp(address, "/VMC/Ext/Blend/Val") == 0) {
			const auto name  = (arg++)->AsStringUnchecked();
			const auto value = (arg++)->AsFloatUnchecked();

			blendshapes[name] = value;
		}
		else if (state.vrm_received && std::strcmp(address, "/VMC/Ext/Blend/Apply") == 0) {
			ofstream_BLEND << "{\"index\":" << frame_count << ", \"value\": {";

			auto p = blendshapes.begin();
			while (p != blendshapes.end()) {
				ofstream_BLEND << "\"" << p->first << "\":" << p->second;
				p++;
				if (p != blendshapes.end()) {
					ofstream_BLEND << ",";
				}
			}
			ofstream_BLEND << "}}," << std::endl;

			blendshapes.clear();
		}

		if (state.vrm_received) {
			const auto time = std::chrono::steady_clock::now();
			const auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(time - lasttime_checked);
			if (delta > options.interval) {
				// Append MOTION
				bvh_traverse_bone_motion(rootnode, &state, true, options.motion_in_place);
				lasttime_checked = time;
				frame_count++;
			}
		}
	}

	void GenerateBVH()
	{
		std::cout << "Generating BVH...";
		std::ofstream ofs(options.bvhfile, std::ios::out | std::ios::binary);

		std::ifstream if_HIERARCHY(options.bvhfile_HIERARCHY, std::ios::in | std::ios_base::binary);
		std::ifstream if_MOTION(options.bvhfile_MOTION, std::ios::in | std::ios_base::binary);

		std::cout << "...";
		ofs << if_HIERARCHY.rdbuf();
		std::cout << "...";
		ofs << "MOTION" << std::endl;
		ofs << "Frames: " << frame_count << std::endl;
		ofs << "Frame Time: " << std::fixed << std::setprecision(3) << std::chrono::duration<float>(options.interval).count() << std::endl;
		std::cout << "...";
		ofs << if_MOTION.rdbuf();
		ofs << std::endl;

		ofstream_BLEND << "]" << std::endl;

		std::cout << "DONE." << std::endl;
	}

private:
	cgltf_data* vrmdata;
	cgltf_node* rootnode;
	vmc2bvh_humanoid_mapping humanoid_mapping;
	std::chrono::steady_clock::time_point lasttime_checked;
	std::uint32_t frame_count;
	std::unordered_map<std::string, float> blendshapes;

	vmc2bvh_options options;
	vmc2bvh_traverse_state state;
	std::ofstream ofstream_MOTION;
	std::ofstream ofstream_BLEND;
};

int main(int argc, char* argv[])
{
	CLI::App app{ "Vmc2Bvh: Export VMC data to BVH motions" };

	std::uint16_t port = 39539;
	app.add_option<std::uint16_t>("-p,--port", port, "port number to bind");

	std::string bvhfile = "output.bvh";
	app.add_option("-f,--file", bvhfile, "bvh file to create");

	std::string rootbone_name;
	app.add_option("-b,--bone", rootbone_name, "root bone name");

	bool motion_in_place = false;
	app.add_flag("-i,--in-place", motion_in_place, "disables root translation");

	std::uint8_t fps = 60;
	app.add_option("-s,--fps", fps, "frame per second");

	CLI11_PARSE(app, argc, argv);

	vmc2bvh_options options = {};
	options.rootbone = rootbone_name;
	options.bvhfile  = bvhfile;
	options.motion_in_place = motion_in_place;
	options.interval = std::chrono::milliseconds(1000 / fps);

	std::stringstream ss_HIERARCHY;
	ss_HIERARCHY << bvhfile << ".HIERARCHY.txt";
	options.bvhfile_HIERARCHY = ss_HIERARCHY.str();

	std::stringstream ss_MOTION;
	ss_MOTION << bvhfile << ".MOTION.txt";
	options.bvhfile_MOTION = ss_MOTION.str();

	std::stringstream ss_BLEND;
	ss_BLEND << bvhfile << ".BLEND.json";
	options.bvhfile_BLEND = ss_BLEND.str();

	Vmc2BvhPacketListener listener(options);
	UdpListeningReceiveSocket s(
			IpEndpointName( IpEndpointName::ANY_ADDRESS, port ),
			&listener );

	std::cout << "[INFO] Listening for input on port " << port << "..." << std::endl;
	std::cout << "[INFO] Type Ctrl-C to end recording and generate BVH file" << std::endl;

	s.RunUntilSigInt();

	listener.GenerateBVH();

	std::cout << "[INFO] Generated " <<  bvhfile << ". Exiting." << std::endl;

	return 0;
}
