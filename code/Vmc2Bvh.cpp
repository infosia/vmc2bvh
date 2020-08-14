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
		, loaded(false)
		, rootnode(nullptr)
		, options(options)
		, ofstream(options.bvhfile)
		, state()
	{

	}
	virtual ~Vmc2BvhPacketListener() = default;

	virtual void ProcessMessage(const osc::ReceivedMessage& m,
		const IpEndpointName& remoteEndpoint)
	{
		(void)remoteEndpoint; // UNUSED

		state.ofstream = &ofstream;

		auto arg = m.ArgumentsBegin();
		const auto address = m.AddressPattern();
		if (!loaded && std::strcmp(address, "/VMC/Ext/OK") == 0 && arg->IsInt32()) {
			const auto value = (arg++)->AsInt32Unchecked();
			if (value == 1) {
				loaded = true;
			}
		}
		else if (loaded && std::strcmp(address, "/VMC/Ext/VRM") == 0) {
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
							std::cout << "root bone found at " << index << " name: " << data->nodes[index].name << std::endl;
							rootnode = &data->nodes[index];
							bvh_traverse_bones(rootnode, &state);
						}
						else {
							std::cout << "Unable to find root bone! Please specify root bone name with --bone option" << std::endl;
						}
					}
					else {
						std::cout << "Unable to parse VRM file! Status: " << result << std::endl;
					}

				}

			}
		}
		else if (loaded && rootnode != nullptr && std::strcmp(address, "/VMC/Ext/Root/Pos") == 0) {

		}
	}

private:
	bool loaded;
	cgltf_node* rootnode;
	vmc2bvh_options options;
	vmc2bvh_traverse_state state;
	std::wofstream ofstream;
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

	Vmc2BvhPacketListener listener(options);
	UdpListeningReceiveSocket s(
			IpEndpointName( IpEndpointName::ANY_ADDRESS, port ),
			&listener );

	std::cout << "listening for input on port " << port << "..." << std::endl;
	std::cout << "press ctrl-c to end" << std::endl;

	s.RunUntilSigInt();

	std::cout << "finishing." << std::endl;

	return 0;
}
