#include <codecvt>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cmath>

#define MATH_PI   3.14159265358979323846264338327950288

struct vmc2bvh_traverse_state
{
	bool loaded;
	bool vrm_received;
	std::uint32_t channels_count;
	std::uint8_t  indent;
	std::ofstream* ofstream_MOTION;
	std::ofstream* ofstream_HIERARCHY;
	float* translation;
	float* rotation;
};

struct vmc2bvh_options
{
	std::string rootbone;
	std::string bvhfile;
	std::string bvhfile_HIERARCHY;
	std::string bvhfile_MOTION;
	bool motion_in_place;
	float interval;
};

struct vmc2bvh_quaternion {
	double x, y, z, w;
};

struct vmc2bvh_degree {
	double roll, pitch, yaw;
};

struct vmc2bvh_humanoid_mapping {
	cgltf_node* hips;
	cgltf_node* leftUpperLeg;
	cgltf_node* rightUpperLeg;
	cgltf_node* leftLowerLeg;
	cgltf_node* rightLowerLeg;
	cgltf_node* leftFoot;
	cgltf_node* rightFoot;
	cgltf_node* spine;
	cgltf_node* chest;
	cgltf_node* neck;
	cgltf_node* head;
	cgltf_node* leftShoulder;
	cgltf_node* rightShoulder;
	cgltf_node* leftUpperArm;
	cgltf_node* rightUpperArm;
	cgltf_node* leftLowerArm;
	cgltf_node* rightLowerArm;
	cgltf_node* leftHand;
	cgltf_node* rightHand;
	cgltf_node* leftToes;
	cgltf_node* rightToes;
	cgltf_node* leftEye;
	cgltf_node* rightEye;
	cgltf_node* jaw;
	cgltf_node* leftThumbProximal;
	cgltf_node* leftThumbIntermediate;
	cgltf_node* leftThumbDistal;
	cgltf_node* leftIndexProximal;
	cgltf_node* leftIndexIntermediate;
	cgltf_node* leftIndexDistal;
	cgltf_node* leftMiddleProximal;
	cgltf_node* leftMiddleIntermediate;
	cgltf_node* leftMiddleDistal;
	cgltf_node* leftRingProximal;
	cgltf_node* leftRingIntermediate;
	cgltf_node* leftRingDistal;
	cgltf_node* leftLittleProximal;
	cgltf_node* leftLittleIntermediate;
	cgltf_node* leftLittleDistal;
	cgltf_node* rightThumbProximal;
	cgltf_node* rightThumbIntermediate;
	cgltf_node* rightThumbDistal;
	cgltf_node* rightIndexProximal;
	cgltf_node* rightIndexIntermediate;
	cgltf_node* rightIndexDistal;
	cgltf_node* rightMiddleProximal;
	cgltf_node* rightMiddleIntermediate;
	cgltf_node* rightMiddleDistal;
	cgltf_node* rightRingProximal;
	cgltf_node* rightRingIntermediate;
	cgltf_node* rightRingDistal;
	cgltf_node* rightLittleProximal;
	cgltf_node* rightLittleIntermediate;
	cgltf_node* rightLittleDistal;
	cgltf_node* upperChest;
};

static vmc2bvh_humanoid_mapping vrm_get_humanoid_mapping(const cgltf_data* data)
{
	vmc2bvh_humanoid_mapping mapping{};

	for (cgltf_size i = 0; i < data->vrm.humanoid.humanBones_count; i++) {
		const auto bone = data->vrm.humanoid.humanBones[i];
		switch (bone.bone) {
		case cgltf_vrm_humanoid_bone_bone_hips:
			mapping.hips = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftUpperLeg:
			mapping.leftUpperLeg = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightUpperLeg:
			mapping.rightUpperLeg = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftLowerLeg:
			mapping.leftLowerLeg = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightLowerLeg:
			mapping.rightLowerLeg = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftFoot:
			mapping.leftFoot = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightFoot:
			mapping.rightFoot = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_spine:
			mapping.spine = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_chest:
			mapping.chest = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_neck:
			mapping.neck = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_head:
			mapping.head = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftShoulder:
			mapping.leftShoulder = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightShoulder:
			mapping.rightShoulder = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftUpperArm:
			mapping.leftUpperArm = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightUpperArm:
			mapping.rightUpperArm = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftLowerArm:
			mapping.leftLowerArm = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightLowerArm:
			mapping.rightLowerArm = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftHand:
			mapping.leftHand = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightHand:
			mapping.rightHand = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftToes:
			mapping.leftToes = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightToes:
			mapping.rightToes = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftEye:
			mapping.leftEye = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightEye:
			mapping.rightEye = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_jaw:
			mapping.jaw = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftThumbProximal:
			mapping.leftThumbProximal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftThumbIntermediate:
			mapping.leftThumbIntermediate = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftThumbDistal:
			mapping.leftThumbDistal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftIndexProximal:
			mapping.leftIndexProximal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftIndexIntermediate:
			mapping.leftIndexIntermediate = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftIndexDistal:
			mapping.leftIndexDistal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftMiddleProximal:
			mapping.leftMiddleProximal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftMiddleIntermediate:
			mapping.leftMiddleIntermediate = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftMiddleDistal:
			mapping.leftMiddleDistal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftRingProximal:
			mapping.leftRingProximal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftRingIntermediate:
			mapping.leftRingIntermediate = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftRingDistal:
			mapping.leftRingDistal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftLittleProximal:
			mapping.leftLittleProximal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftLittleIntermediate:
			mapping.leftLittleIntermediate = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_leftLittleDistal:
			mapping.leftLittleDistal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightThumbProximal:
			mapping.rightThumbProximal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightThumbIntermediate:
			mapping.rightThumbIntermediate = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightThumbDistal:
			mapping.rightThumbDistal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightIndexProximal:
			mapping.rightIndexProximal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightIndexIntermediate:
			mapping.rightIndexIntermediate = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightIndexDistal:
			mapping.rightIndexDistal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightMiddleProximal:
			mapping.rightMiddleProximal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightMiddleIntermediate:
			mapping.rightMiddleIntermediate = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightMiddleDistal:
			mapping.rightMiddleDistal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightRingProximal:
			mapping.rightRingProximal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightRingIntermediate:
			mapping.rightRingIntermediate = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightRingDistal:
			mapping.rightRingDistal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightLittleProximal:
			mapping.rightLittleProximal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightLittleIntermediate:
			mapping.rightLittleIntermediate = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_rightLittleDistal:
			mapping.rightLittleDistal = &data->nodes[bone.node];
			break;
		case cgltf_vrm_humanoid_bone_bone_upperChest:
			mapping.upperChest = &data->nodes[bone.node];
			break;
		}
	}

	return mapping;
}

static cgltf_node* vrm_get_humanoid_bone(const char* name, vmc2bvh_humanoid_mapping* mapping)
{
	if (std::strcmp(name, "Hips") == 0) {
		return mapping->hips;
	}
	else if (std::strcmp(name, "LeftUpperLeg") == 0) {
		return mapping->leftUpperLeg;
	}
	else if (std::strcmp(name, "RightUpperLeg") == 0) {
		return mapping->rightUpperLeg;
	}
	else if (std::strcmp(name, "LeftLowerLeg") == 0) {
		return mapping->leftLowerLeg;
	}
	else if (std::strcmp(name, "RightLowerLeg") == 0) {
		return mapping->rightLowerLeg;
	}
	else if (std::strcmp(name, "LeftFoot") == 0) {
		return mapping->leftFoot;
	}
	else if (std::strcmp(name, "RightFoot") == 0) {
		return mapping->rightFoot;
	}
	else if (std::strcmp(name, "Spine") == 0) {
		return mapping->spine;
	}
	else if (std::strcmp(name, "Chest") == 0) {
		return mapping->chest;
	}
	else if (std::strcmp(name, "Neck") == 0) {
		return mapping->neck;
	}
	else if (std::strcmp(name, "Head") == 0) {
		return mapping->head;
	}
	else if (std::strcmp(name, "LeftShoulder") == 0) {
		return mapping->leftShoulder;
	}
	else if (std::strcmp(name, "RightShoulder") == 0) {
		return mapping->rightShoulder;
	}
	else if (std::strcmp(name, "LeftUpperArm") == 0) {
		return mapping->leftUpperArm;
	}
	else if (std::strcmp(name, "RightUpperArm") == 0) {
		return mapping->rightUpperArm;
	}
	else if (std::strcmp(name, "LeftLowerArm") == 0) {
		return mapping->leftLowerArm;
	}
	else if (std::strcmp(name, "RightLowerArm") == 0) {
		return mapping->rightLowerArm;
	}
	else if (std::strcmp(name, "LeftHand") == 0) {
		return mapping->leftHand;
	}
	else if (std::strcmp(name, "RightHand") == 0) {
		return mapping->rightHand;
	}
	else if (std::strcmp(name, "LeftToes") == 0) {
		return mapping->leftToes;
	}
	else if (std::strcmp(name, "RightToes") == 0) {
		return mapping->rightToes;
	}
	else if (std::strcmp(name, "LeftEye") == 0) {
		return mapping->leftEye;
	}
	else if (std::strcmp(name, "RightEye") == 0) {
		return mapping->rightEye;
	}
	else if (std::strcmp(name, "Jaw") == 0) {
		return mapping->jaw;
	}
	else if (std::strcmp(name, "LeftThumbProximal") == 0) {
		return mapping->leftThumbProximal;
	}
	else if (std::strcmp(name, "LeftThumbIntermediate") == 0) {
		return mapping->leftThumbIntermediate;
	}
	else if (std::strcmp(name, "LeftThumbDistal") == 0) {
		return mapping->leftThumbDistal;
	}
	else if (std::strcmp(name, "LeftIndexProximal") == 0) {
		return mapping->leftIndexProximal;
	}
	else if (std::strcmp(name, "LeftIndexIntermediate") == 0) {
		return mapping->leftIndexIntermediate;
	}
	else if (std::strcmp(name, "LeftIndexDistal") == 0) {
		return mapping->leftIndexDistal;
	}
	else if (std::strcmp(name, "LeftMiddleProximal") == 0) {
		return mapping->leftMiddleProximal;
	}
	else if (std::strcmp(name, "LeftMiddleIntermediate") == 0) {
		return mapping->leftMiddleIntermediate;
	}
	else if (std::strcmp(name, "LeftMiddleDistal") == 0) {
		return mapping->leftMiddleDistal;
	}
	else if (std::strcmp(name, "LeftRingProximal") == 0) {
		return mapping->leftRingProximal;
	}
	else if (std::strcmp(name, "LeftRingIntermediate") == 0) {
		return mapping->leftRingIntermediate;
	}
	else if (std::strcmp(name, "LeftRingDistal") == 0) {
		return mapping->leftRingDistal;
	}
	else if (std::strcmp(name, "LeftLittleProximal") == 0) {
		return mapping->leftLittleProximal;
	}
	else if (std::strcmp(name, "LeftLittleIntermediate") == 0) {
		return mapping->leftLittleIntermediate;
	}
	else if (std::strcmp(name, "LeftLittleDistal") == 0) {
		return mapping->leftLittleDistal;
	}
	else if (std::strcmp(name, "RightThumbProximal") == 0) {
		return mapping->rightThumbProximal;
	}
	else if (std::strcmp(name, "RightThumbIntermediate") == 0) {
		return mapping->rightThumbIntermediate;
	}
	else if (std::strcmp(name, "RightThumbDistal") == 0) {
		return mapping->rightThumbDistal;
	}
	else if (std::strcmp(name, "RightIndexProximal") == 0) {
		return mapping->rightIndexProximal;
	}
	else if (std::strcmp(name, "RightIndexIntermediate") == 0) {
		return mapping->rightIndexIntermediate;
	}
	else if (std::strcmp(name, "RightIndexDistal") == 0) {
		return mapping->rightIndexDistal;
	}
	else if (std::strcmp(name, "RightMiddleProximal") == 0) {
		return mapping->rightMiddleProximal;
	}
	else if (std::strcmp(name, "RightMiddleIntermediate") == 0) {
		return mapping->rightMiddleIntermediate;
	}
	else if (std::strcmp(name, "RightMiddleDistal") == 0) {
		return mapping->rightMiddleDistal;
	}
	else if (std::strcmp(name, "RightRingProximal") == 0) {
		return mapping->rightRingProximal;
	}
	else if (std::strcmp(name, "RightRingIntermediate") == 0) {
		return mapping->rightRingIntermediate;
	}
	else if (std::strcmp(name, "RightRingDistal") == 0) {
		return mapping->rightRingDistal;
	}
	else if (std::strcmp(name, "RightLittleProximal") == 0) {
		return mapping->rightLittleProximal;
	}
	else if (std::strcmp(name, "RightLittleIntermediate") == 0) {
		return mapping->rightLittleIntermediate;
	}
	else if (std::strcmp(name, "RightLittleDistal") == 0) {
		return mapping->rightLittleDistal;
	}
	else if (std::strcmp(name, "UpperChest") == 0) {
		return mapping->upperChest;
	}
	return nullptr;
}

static void quaternion_to_degree_rot(double r11, double r12, double r21, double r31, double r32, vmc2bvh_degree* angles) {
	const auto F = (180.0 / MATH_PI);

	// zyx
	angles->yaw   = atan2(r31, r32) * F;
	angles->pitch = asin(r21) * F;
	angles->roll  = atan2(r11, r12) * F;
}

static vmc2bvh_degree quaternion_to_degree(vmc2bvh_quaternion q)
{
	vmc2bvh_degree angles;

	// xyz
	quaternion_to_degree_rot(-2 * (q.y * q.z - q.w * q.x),
		q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z,
		2 * (q.x * q.z + q.w * q.y),
		-2 * (q.x * q.y - q.w * q.z),
		q.w * q.w + q.x * q.x - q.y * q.y - q.z * q.z, &angles);

	return angles;
}

static bool char_equals_ignoreCase(char& c1, char& c2)
{
	if (c1 == c2) {
		return true;
	}
	else if (std::toupper(c1) == std::toupper(c2)) {
		return true;
	}
	return false;
}

static bool string_equals_ignoreCase(std::string& str1, std::string& str2)
{
	return ((str1.size() == str2.size()) &&
		std::equal(str1.begin(), str1.end(), str2.begin(), &char_equals_ignoreCase));
}

static bool vrm_get_root_bone(cgltf_data* data, std::string& known_name, cgltf_size* index)
{
	static std::string known_name1 = "ROOT";
	static std::string known_name2 = "ARMATURE";
	const auto node_count = data->nodes_count;
	for (cgltf_size i = 0; i < node_count; i++) {
		std::string node_name = data->nodes[i].name;
		if ((!known_name.empty() && string_equals_ignoreCase(node_name, known_name)) || 
			(string_equals_ignoreCase(node_name, known_name1) || string_equals_ignoreCase(node_name, known_name2))) 
		{
			*index = i;
			return true;
		}
	}
	return false;
}

static void bvh_indent(vmc2bvh_traverse_state* state)
{
	auto stream = state->ofstream_HIERARCHY;

	for (std::uint8_t i = 0; i < state->indent; i++) {
		*stream << "  ";
	}
}

static vmc2bvh_quaternion bvh_quaternion_multiply(const vmc2bvh_quaternion q1, const vmc2bvh_quaternion q2) 
{
	vmc2bvh_quaternion q;
	q.x =  q1.x * q2.w + q1.y * q2.z - q1.z * q2.y + q1.w * q2.x;
	q.y = -q1.x * q2.z + q1.y * q2.w + q1.z * q2.x + q1.w * q2.y;
	q.z =  q1.x * q2.y - q1.y * q2.x + q1.z * q2.w + q1.w * q2.z;
	q.w = -q1.x * q2.x - q1.y * q2.y - q1.z * q2.z + q1.w * q2.w;
	return q;
}

static void bvh_traverse_bone_motion(cgltf_node* node, vmc2bvh_traverse_state* state, const bool is_root, const bool motion_in_place)
{
	// Treat first child of root node as a initial node because root node is not actually part of hierarchy
	if (node->parent == nullptr && node->children_count > 0) {
		bvh_traverse_bone_motion(node->children[0], state, true, motion_in_place);
		return;
	}

	auto stream = state->ofstream_MOTION;
	if (node->children_count > 0) {
		const vmc2bvh_quaternion q = { node->rotation[0], -node->rotation[1], -node->rotation[2], node->rotation[3]	 };

		if (is_root) {
			const vmc2bvh_quaternion root_q = { state->rotation[0], -state->rotation[1], -state->rotation[2], state->rotation[3] };
			const auto degree = quaternion_to_degree(bvh_quaternion_multiply(root_q, q));

			const cgltf_float x = -node->translation[0] - (motion_in_place ? 0 : state->translation[0]);
			const cgltf_float y =  node->translation[1] + (motion_in_place ? 0 : state->translation[1]);
			const cgltf_float z = -node->translation[0] + (motion_in_place ? 0 : state->translation[2]);

			*stream << std::fixed << std::setprecision(7)
				<< x << " " << y << " " << z << " "
				<< degree.roll << " " << degree.pitch << " " << degree.yaw << " ";
		}
		else {
			const auto degree = quaternion_to_degree(q);
			*stream << std::fixed << std::setprecision(7)
				<< degree.roll << " " << degree.pitch << " " << degree.yaw << " ";
		}
	}

	for (cgltf_size i = 0; i < node->children_count; i++) {
		bvh_traverse_bone_motion(node->children[i], state, false, motion_in_place);
	}

	if (is_root) {
		*stream << std::endl;
	}
}

static void bvh_traverse_bones(cgltf_node* node, vmc2bvh_traverse_state* state)
{
	auto stream = state->ofstream_HIERARCHY;

	if (stream == nullptr || !stream->is_open()) {
		std::cout << "[ERROR] Unable to open ofstream_HIERARCHY" << std::endl;
		return;
	}

	// Treat first child of root node as a initial node because root node is not actually part of hierarchy
	if (node->parent == nullptr && node->children_count > 0) {
		bvh_traverse_bones(node->children[0], state);
		return;
	}
	const bool is_root = (state->channels_count == 0);
	if (is_root) {
		*stream << "HIERARCHY" << std::endl;
		*stream << "ROOT " << node->name << std::endl;
	}
	else if (node->children_count > 0) {
		bvh_indent(state);
		*stream << "JOINT " << node->name << std::endl;
	}
	else {
		bvh_indent(state);
		*stream << "End Site" << std::endl;
	}

	bvh_indent(state);
	*stream << "{" << std::endl;
	state->indent++;

	bvh_indent(state);
	*stream << "OFFSET " << std::fixed << std::setprecision(7) << (-node->translation[0]) << " " << node->translation[1] << " " << (-node->translation[2]) << std::endl;
	if (is_root) {
		bvh_indent(state);
		*stream << "CHANNELS 6 Xposition Yposition Zposition Xrotation Yrotation Zrotation" << std::endl;
		state->channels_count += 6;
	} else if (node->children_count > 0) {
		bvh_indent(state);
		*stream << "CHANNELS 3 Xrotation Yrotation Zrotation" << std::endl;
		state->channels_count += 3;
	}
	for (cgltf_size i = 0; i < node->children_count; i++) {
		bvh_traverse_bones(node->children[i], state);
	}

	state->indent--;
	bvh_indent(state);
	*stream << "}" << std::endl;
}

static cgltf_result wstring_vrm_file_read(const struct cgltf_memory_options* memory_options, const struct cgltf_file_options* file_options, const std::wstring path, cgltf_size* size, void** data)
{
	(void)file_options;
	void* (*memory_alloc)(void*, cgltf_size) = memory_options->alloc ? memory_options->alloc : &cgltf_default_alloc;
	void (*memory_free)(void*, void*) = memory_options->free ? memory_options->free : &cgltf_default_free;

	FILE* file = _wfopen(path.c_str(), L"rb");

	if (!file)
	{
		return cgltf_result_file_not_found;
	}

	cgltf_size file_size = size ? *size : 0;

	if (file_size == 0)
	{
		fseek(file, 0, SEEK_END);

		long length = ftell(file);
		if (length < 0)
		{
			fclose(file);
			return cgltf_result_io_error;
		}

		fseek(file, 0, SEEK_SET);
		file_size = (cgltf_size)length;
	}

	char* file_data = (char*)memory_alloc(memory_options->user_data, file_size);
	if (!file_data)
	{
		fclose(file);
		return cgltf_result_out_of_memory;
	}

	cgltf_size read_size = fread(file_data, 1, file_size, file);

	fclose(file);

	if (read_size != file_size)
	{
		memory_free(memory_options->user_data, file_data);
		return cgltf_result_io_error;
	}

	if (size)
	{
		*size = file_size;
	}
	if (data)
	{
		*data = file_data;
	}

	return cgltf_result_success;
}

static cgltf_result vrm_file_read(const struct cgltf_memory_options* memory_options, const struct cgltf_file_options* file_options, const char* path, cgltf_size* size, void** data)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	return wstring_vrm_file_read(memory_options, file_options, converter.from_bytes(path), size, data);
}
