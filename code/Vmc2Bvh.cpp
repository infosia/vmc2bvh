#define CGLTF_IMPLEMENTATION

#include <iostream>
#include <cstring>
#include <cstdlib>

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
		, rootnode(nullptr)
		, options(options)
		, ofstream_MOTION(options.bvhfile_MOTION)
		, state{false, false, 0, 0, nullptr, nullptr}
	{

	}
	virtual ~Vmc2BvhPacketListener() = default;

	virtual void ProcessMessage(const osc::ReceivedMessage& m,
		const IpEndpointName& remoteEndpoint)
	{
		(void)remoteEndpoint; // UNUSED

		auto arg = m.ArgumentsBegin();
		const auto address = m.AddressPattern();
		if (!state.loaded && std::strcmp(address, "/VMC/Ext/OK") == 0 && arg->IsInt32()) {
			const auto value = (arg++)->AsInt32Unchecked();
			if (value == 1) {
				state.loaded = true;
			}
		}
		else if (!state.vrm_received && state.loaded && std::strcmp(address, "/VMC/Ext/VRM") == 0) {
			if (arg->IsString()) {
				const auto value = (arg++)->AsStringUnchecked();
				if (strlen(value) > 0) {

					cgltf_options parse_options = {};
					parse_options.file.read = &vrm_file_read;

					cgltf_data* data = NULL;
					const auto result = cgltf_parse_file(&parse_options, value, &data);

					if (result == cgltf_result_success) {
						cgltf_size index;
						if (vrm_get_root_bone(data, options.rootbone, &index)) {
							std::cout << "[INFO] root bone found at " << index << " name: " << data->nodes[index].name << std::endl;
							rootnode = &data->nodes[index];

							// Constructs humanoid-bone => node mapping 
							humanoid_mapping = vrm_get_humanoid_mapping(data);

							// Write HIERARCHY
							std::wofstream ofstream_HIERARCHY(options.bvhfile_HIERARCHY);
							state.ofstream_HIERARCHY = &ofstream_HIERARCHY;
							state.ofstream_MOTION = &ofstream_MOTION;
							bvh_traverse_bones(rootnode, &state);

							// Write first MOTION
							bvh_traverse_bone_motion(rootnode, &state, true);

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
	}

private:
	cgltf_node* rootnode;
	vmc2bvh_humanoid_mapping humanoid_mapping;

	vmc2bvh_options options;
	vmc2bvh_traverse_state state;
	std::wofstream ofstream_MOTION;
};

int main(int argc, char* argv[])
{
	CLI::App app{ "Vmc2Bvh: Export VMC data to BVH motions" };

	std::uint16_t port = 39539;
	app.add_option<std::uint16_t>("-p,--port", port, "port number to bind");

	std::string bvhfile = "vmc2bvh_output.bvh";
	app.add_option("-f,--file", bvhfile, "bvh file to create");

	std::string rootbone_name;
	app.add_option("-b,--bone", rootbone_name, "root bone name");

	CLI11_PARSE(app, argc, argv);

	vmc2bvh_options options = {};
	options.rootbone = rootbone_name;
	options.bvhfile  = bvhfile;

	std::stringstream ss_HIERARCHY;
	ss_HIERARCHY << bvhfile << ".HIERARCHY.txt";
	options.bvhfile_HIERARCHY = ss_HIERARCHY.str();

	std::stringstream ss_MOTION;
	ss_MOTION << bvhfile << ".MOTION.txt";
	options.bvhfile_MOTION = ss_MOTION.str();

	Vmc2BvhPacketListener listener(options);
	UdpListeningReceiveSocket s(
			IpEndpointName( IpEndpointName::ANY_ADDRESS, port ),
			&listener );

	std::cout << "[INFO] listening for input on port " << port << "..." << std::endl;
	std::cout << "[INFO] press ctrl-c to end" << std::endl;

	s.RunUntilSigInt();

	std::cout << "[INFO] finishing." << std::endl;

	return 0;
}
