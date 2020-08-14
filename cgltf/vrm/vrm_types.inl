static void cgltf_vrm_secondaryanimation_collidergroup_colliders_free(const struct cgltf_memory_options* memory, cgltf_vrm_secondaryanimation_collidergroup_colliders* data) {
	memory->free(memory->user_data, data->offset);
}

static void cgltf_vrm_secondaryanimation_spring_free(const struct cgltf_memory_options* memory, cgltf_vrm_secondaryanimation_spring* data) {
	memory->free(memory->user_data, data->comment);
	memory->free(memory->user_data, data->gravityDir);
	memory->free(memory->user_data, data->bones);
	memory->free(memory->user_data, data->colliderGroups);
}

static void cgltf_vrm_secondaryanimation_collidergroup_free(const struct cgltf_memory_options* memory, cgltf_vrm_secondaryanimation_collidergroup* data) {
	for (cgltf_size i = 0; i < data->colliders_count; i++) {
		cgltf_vrm_secondaryanimation_collidergroup_colliders_free(memory, &data->colliders[i]);
	}
	memory->free(memory->user_data, data->colliders);
}

static void cgltf_vrm_secondaryanimation_free(const struct cgltf_memory_options* memory, cgltf_vrm_secondaryanimation* data) {
	for (cgltf_size i = 0; i < data->boneGroups_count; i++) {
		cgltf_vrm_secondaryanimation_spring_free(memory, &data->boneGroups[i]);
	}
	memory->free(memory->user_data, data->boneGroups);
	for (cgltf_size i = 0; i < data->colliderGroups_count; i++) {
		cgltf_vrm_secondaryanimation_collidergroup_free(memory, &data->colliderGroups[i]);
	}
	memory->free(memory->user_data, data->colliderGroups);
}

static void cgltf_vrm_blendshape_bind_free(const struct cgltf_memory_options* memory, cgltf_vrm_blendshape_bind* data) {
	(void)memory;
	(void)data;
}

static void cgltf_vrm_blendshape_materialbind_free(const struct cgltf_memory_options* memory, cgltf_vrm_blendshape_materialbind* data) {
	memory->free(memory->user_data, data->materialName);
	memory->free(memory->user_data, data->propertyName);
	memory->free(memory->user_data, data->targetValue);
}

static void cgltf_vrm_blendshape_group_free(const struct cgltf_memory_options* memory, cgltf_vrm_blendshape_group* data) {
	memory->free(memory->user_data, data->name);
	for (cgltf_size i = 0; i < data->binds_count; i++) {
		cgltf_vrm_blendshape_bind_free(memory, &data->binds[i]);
	}
	memory->free(memory->user_data, data->binds);
	for (cgltf_size i = 0; i < data->materialValues_count; i++) {
		cgltf_vrm_blendshape_materialbind_free(memory, &data->materialValues[i]);
	}
	memory->free(memory->user_data, data->materialValues);
}

static void cgltf_vrm_blendshape_free(const struct cgltf_memory_options* memory, cgltf_vrm_blendshape* data) {
	for (cgltf_size i = 0; i < data->blendShapeGroups_count; i++) {
		cgltf_vrm_blendshape_group_free(memory, &data->blendShapeGroups[i]);
	}
	memory->free(memory->user_data, data->blendShapeGroups);
}

static void cgltf_vrm_firstperson_degreemap_free(const struct cgltf_memory_options* memory, cgltf_vrm_firstperson_degreemap* data) {
	memory->free(memory->user_data, data->curve);
}

static void cgltf_vrm_firstperson_meshannotation_free(const struct cgltf_memory_options* memory, cgltf_vrm_firstperson_meshannotation* data) {
	memory->free(memory->user_data, data->firstPersonFlag);
}

static void cgltf_vrm_firstperson_free(const struct cgltf_memory_options* memory, cgltf_vrm_firstperson* data) {
	memory->free(memory->user_data, data->firstPersonBoneOffset);
	for (cgltf_size i = 0; i < data->meshAnnotations_count; i++) {
		cgltf_vrm_firstperson_meshannotation_free(memory, &data->meshAnnotations[i]);
	}
	memory->free(memory->user_data, data->meshAnnotations);
	cgltf_vrm_firstperson_degreemap_free(memory, &data->lookAtHorizontalInner);
	cgltf_vrm_firstperson_degreemap_free(memory, &data->lookAtHorizontalOuter);
	cgltf_vrm_firstperson_degreemap_free(memory, &data->lookAtVerticalDown);
	cgltf_vrm_firstperson_degreemap_free(memory, &data->lookAtVerticalUp);
}

static void cgltf_vrm_humanoid_bone_free(const struct cgltf_memory_options* memory, cgltf_vrm_humanoid_bone* data) {
	memory->free(memory->user_data, data->min);
	memory->free(memory->user_data, data->max);
	memory->free(memory->user_data, data->center);
}

static void cgltf_vrm_humanoid_free(const struct cgltf_memory_options* memory, cgltf_vrm_humanoid* data) {
	for (cgltf_size i = 0; i < data->humanBones_count; i++) {
		cgltf_vrm_humanoid_bone_free(memory, &data->humanBones[i]);
	}
	memory->free(memory->user_data, data->humanBones);
}

static void cgltf_vrm_material_free(const struct cgltf_memory_options* memory, cgltf_vrm_material* data) {
	memory->free(memory->user_data, data->name);
	memory->free(memory->user_data, data->shader);
	for (cgltf_size i = 0; i < data->floatProperties_count; i++) {
		memory->free(memory->user_data, data->floatProperties_keys[i]);
	}
	memory->free(memory->user_data, data->floatProperties_keys);
	memory->free(memory->user_data, data->floatProperties_values);
	for (cgltf_size i = 0; i < data->vectorProperties_count; i++) {
		memory->free(memory->user_data, data->vectorProperties_keys[i]);
		memory->free(memory->user_data, data->vectorProperties_values[i]);
	}
	memory->free(memory->user_data, data->vectorProperties_keys);
	memory->free(memory->user_data, data->vectorProperties_values);
	memory->free(memory->user_data, data->vectorProperties_floats_size);
	for (cgltf_size i = 0; i < data->textureProperties_count; i++) {
		memory->free(memory->user_data, data->textureProperties_keys[i]);
	}
	memory->free(memory->user_data, data->textureProperties_keys);
	memory->free(memory->user_data, data->textureProperties_values);
	for (cgltf_size i = 0; i < data->keywordMap_count; i++) {
		memory->free(memory->user_data, data->keywordMap_keys[i]);
	}
	memory->free(memory->user_data, data->keywordMap_keys);
	memory->free(memory->user_data, data->keywordMap_values);
	for (cgltf_size i = 0; i < data->tagMap_count; i++) {
		memory->free(memory->user_data, data->tagMap_keys[i]);
		memory->free(memory->user_data, data->tagMap_values[i]);
	}
	memory->free(memory->user_data, data->tagMap_keys);
	memory->free(memory->user_data, data->tagMap_values);
}

static void cgltf_vrm_meta_free(const struct cgltf_memory_options* memory, cgltf_vrm_meta* data) {
	memory->free(memory->user_data, data->title);
	memory->free(memory->user_data, data->version);
	memory->free(memory->user_data, data->author);
	memory->free(memory->user_data, data->contactInformation);
	memory->free(memory->user_data, data->reference);
	memory->free(memory->user_data, data->otherPermissionUrl);
	memory->free(memory->user_data, data->otherLicenseUrl);
}

static void cgltf_vrm_free(const struct cgltf_memory_options* memory, cgltf_vrm* data) {
	memory->free(memory->user_data, data->exporterVersion);
	memory->free(memory->user_data, data->specVersion);
	cgltf_vrm_meta_free(memory, &data->meta);
	cgltf_vrm_humanoid_free(memory, &data->humanoid);
	cgltf_vrm_firstperson_free(memory, &data->firstPerson);
	cgltf_vrm_blendshape_free(memory, &data->blendShapeMaster);
	cgltf_vrm_secondaryanimation_free(memory, &data->secondaryAnimation);
	for (cgltf_size i = 0; i < data->materialProperties_count; i++) {
		cgltf_vrm_material_free(memory, &data->materialProperties[i]);
	}
	memory->free(memory->user_data, data->materialProperties);
}
static cgltf_bool select_cgltf_vrm_blendshape_group_presetName(const char* name, cgltf_vrm_blendshape_group_presetName* out) {
	if (strlen(name) == 0) {
		return 0;
	} else if (strlen(name) == 7 && strncmp(name, "unknown", 7) == 0) {
		*out = cgltf_vrm_blendshape_group_presetName_unknown;
		return 1;
	} else if (strlen(name) == 7 && strncmp(name, "neutral", 7) == 0) {
		*out = cgltf_vrm_blendshape_group_presetName_neutral;
		return 1;
	} else if (strlen(name) == 1 && strncmp(name, "a", 1) == 0) {
		*out = cgltf_vrm_blendshape_group_presetName_a;
		return 1;
	} else if (strlen(name) == 1 && strncmp(name, "i", 1) == 0) {
		*out = cgltf_vrm_blendshape_group_presetName_i;
		return 1;
	} else if (strlen(name) == 1 && strncmp(name, "u", 1) == 0) {
		*out = cgltf_vrm_blendshape_group_presetName_u;
		return 1;
	} else if (strlen(name) == 1 && strncmp(name, "e", 1) == 0) {
		*out = cgltf_vrm_blendshape_group_presetName_e;
		return 1;
	} else if (strlen(name) == 1 && strncmp(name, "o", 1) == 0) {
		*out = cgltf_vrm_blendshape_group_presetName_o;
		return 1;
	} else if (strlen(name) == 5 && strncmp(name, "blink", 5) == 0) {
		*out = cgltf_vrm_blendshape_group_presetName_blink;
		return 1;
	} else if (strlen(name) == 3 && strncmp(name, "joy", 3) == 0) {
		*out = cgltf_vrm_blendshape_group_presetName_joy;
		return 1;
	} else if (strlen(name) == 5 && strncmp(name, "angry", 5) == 0) {
		*out = cgltf_vrm_blendshape_group_presetName_angry;
		return 1;
	} else if (strlen(name) == 6 && strncmp(name, "sorrow", 6) == 0) {
		*out = cgltf_vrm_blendshape_group_presetName_sorrow;
		return 1;
	} else if (strlen(name) == 3 && strncmp(name, "fun", 3) == 0) {
		*out = cgltf_vrm_blendshape_group_presetName_fun;
		return 1;
	} else if (strlen(name) == 6 && strncmp(name, "lookup", 6) == 0) {
		*out = cgltf_vrm_blendshape_group_presetName_lookup;
		return 1;
	} else if (strlen(name) == 8 && strncmp(name, "lookdown", 8) == 0) {
		*out = cgltf_vrm_blendshape_group_presetName_lookdown;
		return 1;
	} else if (strlen(name) == 8 && strncmp(name, "lookleft", 8) == 0) {
		*out = cgltf_vrm_blendshape_group_presetName_lookleft;
		return 1;
	} else if (strlen(name) == 9 && strncmp(name, "lookright", 9) == 0) {
		*out = cgltf_vrm_blendshape_group_presetName_lookright;
		return 1;
	} else if (strlen(name) == 7 && strncmp(name, "blink_l", 7) == 0) {
		*out = cgltf_vrm_blendshape_group_presetName_blink_l;
		return 1;
	} else if (strlen(name) == 7 && strncmp(name, "blink_r", 7) == 0) {
		*out = cgltf_vrm_blendshape_group_presetName_blink_r;
		return 1;
	}
	return 0;
}

static cgltf_bool select_cgltf_vrm_firstperson_lookAtTypeName(const char* name, cgltf_vrm_firstperson_lookAtTypeName* out) {
	if (strlen(name) == 0) {
		return 0;
	} else if (strlen(name) == 4 && strncmp(name, "Bone", 4) == 0) {
		*out = cgltf_vrm_firstperson_lookAtTypeName_Bone;
		return 1;
	} else if (strlen(name) == 10 && strncmp(name, "BlendShape", 10) == 0) {
		*out = cgltf_vrm_firstperson_lookAtTypeName_BlendShape;
		return 1;
	}
	return 0;
}

static cgltf_bool select_cgltf_vrm_humanoid_bone_bone(const char* name, cgltf_vrm_humanoid_bone_bone* out) {
	if (strlen(name) == 0) {
		return 0;
	} else if (strlen(name) == 4 && strncmp(name, "hips", 4) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_hips;
		return 1;
	} else if (strlen(name) == 12 && strncmp(name, "leftUpperLeg", 12) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftUpperLeg;
		return 1;
	} else if (strlen(name) == 13 && strncmp(name, "rightUpperLeg", 13) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightUpperLeg;
		return 1;
	} else if (strlen(name) == 12 && strncmp(name, "leftLowerLeg", 12) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftLowerLeg;
		return 1;
	} else if (strlen(name) == 13 && strncmp(name, "rightLowerLeg", 13) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightLowerLeg;
		return 1;
	} else if (strlen(name) == 8 && strncmp(name, "leftFoot", 8) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftFoot;
		return 1;
	} else if (strlen(name) == 9 && strncmp(name, "rightFoot", 9) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightFoot;
		return 1;
	} else if (strlen(name) == 5 && strncmp(name, "spine", 5) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_spine;
		return 1;
	} else if (strlen(name) == 5 && strncmp(name, "chest", 5) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_chest;
		return 1;
	} else if (strlen(name) == 4 && strncmp(name, "neck", 4) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_neck;
		return 1;
	} else if (strlen(name) == 4 && strncmp(name, "head", 4) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_head;
		return 1;
	} else if (strlen(name) == 12 && strncmp(name, "leftShoulder", 12) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftShoulder;
		return 1;
	} else if (strlen(name) == 13 && strncmp(name, "rightShoulder", 13) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightShoulder;
		return 1;
	} else if (strlen(name) == 12 && strncmp(name, "leftUpperArm", 12) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftUpperArm;
		return 1;
	} else if (strlen(name) == 13 && strncmp(name, "rightUpperArm", 13) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightUpperArm;
		return 1;
	} else if (strlen(name) == 12 && strncmp(name, "leftLowerArm", 12) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftLowerArm;
		return 1;
	} else if (strlen(name) == 13 && strncmp(name, "rightLowerArm", 13) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightLowerArm;
		return 1;
	} else if (strlen(name) == 8 && strncmp(name, "leftHand", 8) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftHand;
		return 1;
	} else if (strlen(name) == 9 && strncmp(name, "rightHand", 9) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightHand;
		return 1;
	} else if (strlen(name) == 8 && strncmp(name, "leftToes", 8) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftToes;
		return 1;
	} else if (strlen(name) == 9 && strncmp(name, "rightToes", 9) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightToes;
		return 1;
	} else if (strlen(name) == 7 && strncmp(name, "leftEye", 7) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftEye;
		return 1;
	} else if (strlen(name) == 8 && strncmp(name, "rightEye", 8) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightEye;
		return 1;
	} else if (strlen(name) == 3 && strncmp(name, "jaw", 3) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_jaw;
		return 1;
	} else if (strlen(name) == 17 && strncmp(name, "leftThumbProximal", 17) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftThumbProximal;
		return 1;
	} else if (strlen(name) == 21 && strncmp(name, "leftThumbIntermediate", 21) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftThumbIntermediate;
		return 1;
	} else if (strlen(name) == 15 && strncmp(name, "leftThumbDistal", 15) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftThumbDistal;
		return 1;
	} else if (strlen(name) == 17 && strncmp(name, "leftIndexProximal", 17) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftIndexProximal;
		return 1;
	} else if (strlen(name) == 21 && strncmp(name, "leftIndexIntermediate", 21) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftIndexIntermediate;
		return 1;
	} else if (strlen(name) == 15 && strncmp(name, "leftIndexDistal", 15) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftIndexDistal;
		return 1;
	} else if (strlen(name) == 18 && strncmp(name, "leftMiddleProximal", 18) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftMiddleProximal;
		return 1;
	} else if (strlen(name) == 22 && strncmp(name, "leftMiddleIntermediate", 22) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftMiddleIntermediate;
		return 1;
	} else if (strlen(name) == 16 && strncmp(name, "leftMiddleDistal", 16) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftMiddleDistal;
		return 1;
	} else if (strlen(name) == 16 && strncmp(name, "leftRingProximal", 16) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftRingProximal;
		return 1;
	} else if (strlen(name) == 20 && strncmp(name, "leftRingIntermediate", 20) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftRingIntermediate;
		return 1;
	} else if (strlen(name) == 14 && strncmp(name, "leftRingDistal", 14) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftRingDistal;
		return 1;
	} else if (strlen(name) == 18 && strncmp(name, "leftLittleProximal", 18) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftLittleProximal;
		return 1;
	} else if (strlen(name) == 22 && strncmp(name, "leftLittleIntermediate", 22) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftLittleIntermediate;
		return 1;
	} else if (strlen(name) == 16 && strncmp(name, "leftLittleDistal", 16) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_leftLittleDistal;
		return 1;
	} else if (strlen(name) == 18 && strncmp(name, "rightThumbProximal", 18) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightThumbProximal;
		return 1;
	} else if (strlen(name) == 22 && strncmp(name, "rightThumbIntermediate", 22) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightThumbIntermediate;
		return 1;
	} else if (strlen(name) == 16 && strncmp(name, "rightThumbDistal", 16) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightThumbDistal;
		return 1;
	} else if (strlen(name) == 18 && strncmp(name, "rightIndexProximal", 18) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightIndexProximal;
		return 1;
	} else if (strlen(name) == 22 && strncmp(name, "rightIndexIntermediate", 22) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightIndexIntermediate;
		return 1;
	} else if (strlen(name) == 16 && strncmp(name, "rightIndexDistal", 16) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightIndexDistal;
		return 1;
	} else if (strlen(name) == 19 && strncmp(name, "rightMiddleProximal", 19) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightMiddleProximal;
		return 1;
	} else if (strlen(name) == 23 && strncmp(name, "rightMiddleIntermediate", 23) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightMiddleIntermediate;
		return 1;
	} else if (strlen(name) == 17 && strncmp(name, "rightMiddleDistal", 17) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightMiddleDistal;
		return 1;
	} else if (strlen(name) == 17 && strncmp(name, "rightRingProximal", 17) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightRingProximal;
		return 1;
	} else if (strlen(name) == 21 && strncmp(name, "rightRingIntermediate", 21) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightRingIntermediate;
		return 1;
	} else if (strlen(name) == 15 && strncmp(name, "rightRingDistal", 15) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightRingDistal;
		return 1;
	} else if (strlen(name) == 19 && strncmp(name, "rightLittleProximal", 19) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightLittleProximal;
		return 1;
	} else if (strlen(name) == 23 && strncmp(name, "rightLittleIntermediate", 23) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightLittleIntermediate;
		return 1;
	} else if (strlen(name) == 17 && strncmp(name, "rightLittleDistal", 17) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_rightLittleDistal;
		return 1;
	} else if (strlen(name) == 10 && strncmp(name, "upperChest", 10) == 0) {
		*out = cgltf_vrm_humanoid_bone_bone_upperChest;
		return 1;
	}
	return 0;
}

static cgltf_bool select_cgltf_vrm_meta_allowedUserName(const char* name, cgltf_vrm_meta_allowedUserName* out) {
	if (strlen(name) == 0) {
		return 0;
	} else if (strlen(name) == 10 && strncmp(name, "OnlyAuthor", 10) == 0) {
		*out = cgltf_vrm_meta_allowedUserName_OnlyAuthor;
		return 1;
	} else if (strlen(name) == 24 && strncmp(name, "ExplicitlyLicensedPerson", 24) == 0) {
		*out = cgltf_vrm_meta_allowedUserName_ExplicitlyLicensedPerson;
		return 1;
	} else if (strlen(name) == 8 && strncmp(name, "Everyone", 8) == 0) {
		*out = cgltf_vrm_meta_allowedUserName_Everyone;
		return 1;
	}
	return 0;
}

static cgltf_bool select_cgltf_vrm_meta_violentUssageName(const char* name, cgltf_vrm_meta_violentUssageName* out) {
	if (strlen(name) == 0) {
		return 0;
	} else if (strlen(name) == 8 && strncmp(name, "Disallow", 8) == 0) {
		*out = cgltf_vrm_meta_violentUssageName_Disallow;
		return 1;
	} else if (strlen(name) == 5 && strncmp(name, "Allow", 5) == 0) {
		*out = cgltf_vrm_meta_violentUssageName_Allow;
		return 1;
	}
	return 0;
}

static cgltf_bool select_cgltf_vrm_meta_sexualUssageName(const char* name, cgltf_vrm_meta_sexualUssageName* out) {
	if (strlen(name) == 0) {
		return 0;
	} else if (strlen(name) == 8 && strncmp(name, "Disallow", 8) == 0) {
		*out = cgltf_vrm_meta_sexualUssageName_Disallow;
		return 1;
	} else if (strlen(name) == 5 && strncmp(name, "Allow", 5) == 0) {
		*out = cgltf_vrm_meta_sexualUssageName_Allow;
		return 1;
	}
	return 0;
}

static cgltf_bool select_cgltf_vrm_meta_commercialUssageName(const char* name, cgltf_vrm_meta_commercialUssageName* out) {
	if (strlen(name) == 0) {
		return 0;
	} else if (strlen(name) == 8 && strncmp(name, "Disallow", 8) == 0) {
		*out = cgltf_vrm_meta_commercialUssageName_Disallow;
		return 1;
	} else if (strlen(name) == 5 && strncmp(name, "Allow", 5) == 0) {
		*out = cgltf_vrm_meta_commercialUssageName_Allow;
		return 1;
	}
	return 0;
}

static cgltf_bool select_cgltf_vrm_meta_licenseName(const char* name, cgltf_vrm_meta_licenseName* out) {
	if (strlen(name) == 0) {
		return 0;
	} else if (strlen(name) == 25 && strncmp(name, "Redistribution_Prohibited", 25) == 0) {
		*out = cgltf_vrm_meta_licenseName_Redistribution_Prohibited;
		return 1;
	} else if (strlen(name) == 3 && strncmp(name, "CC0", 3) == 0) {
		*out = cgltf_vrm_meta_licenseName_CC0;
		return 1;
	} else if (strlen(name) == 5 && strncmp(name, "CC_BY", 5) == 0) {
		*out = cgltf_vrm_meta_licenseName_CC_BY;
		return 1;
	} else if (strlen(name) == 8 && strncmp(name, "CC_BY_NC", 8) == 0) {
		*out = cgltf_vrm_meta_licenseName_CC_BY_NC;
		return 1;
	} else if (strlen(name) == 8 && strncmp(name, "CC_BY_SA", 8) == 0) {
		*out = cgltf_vrm_meta_licenseName_CC_BY_SA;
		return 1;
	} else if (strlen(name) == 11 && strncmp(name, "CC_BY_NC_SA", 11) == 0) {
		*out = cgltf_vrm_meta_licenseName_CC_BY_NC_SA;
		return 1;
	} else if (strlen(name) == 8 && strncmp(name, "CC_BY_ND", 8) == 0) {
		*out = cgltf_vrm_meta_licenseName_CC_BY_ND;
		return 1;
	} else if (strlen(name) == 11 && strncmp(name, "CC_BY_NC_ND", 11) == 0) {
		*out = cgltf_vrm_meta_licenseName_CC_BY_NC_ND;
		return 1;
	} else if (strlen(name) == 5 && strncmp(name, "Other", 5) == 0) {
		*out = cgltf_vrm_meta_licenseName_Other;
		return 1;
	}
	return 0;
}
static int cgltf_parse_json_vrm_secondaryanimation_collidergroup_colliders(cgltf_options* options, jsmntok_t const* tokens, int i, const uint8_t* json_chunk, cgltf_vrm_secondaryanimation_collidergroup_colliders* out_data) {
	(void)options;
	if (tokens[i].type == JSMN_OBJECT) {
		int size = tokens[i].size; ++i;
		for (int j = 0; j < size; ++j) {
			if (tokens[i].type != JSMN_STRING || tokens[i].size == 0) {
				continue;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "offset") == 0) {
				i = cgltf_parse_json_vec3(options, tokens, i + 1, json_chunk, &out_data->offset, &out_data->offset_count);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "radius") == 0) {
				++i; out_data->radius = cgltf_json_to_float(tokens + i, json_chunk); ++i;
			} else {
				i = cgltf_skip_json(tokens, i + 1);
			}
			if (i < 0) return i;
		}
	} else {
		i = cgltf_skip_json(tokens, i + 1);
	}
	return i;
}
static int cgltf_parse_json_vrm_secondaryanimation_spring(cgltf_options* options, jsmntok_t const* tokens, int i, const uint8_t* json_chunk, cgltf_vrm_secondaryanimation_spring* out_data) {
	(void)options;
	if (tokens[i].type == JSMN_OBJECT) {
		int size = tokens[i].size; ++i;
		for (int j = 0; j < size; ++j) {
			if (tokens[i].type != JSMN_STRING || tokens[i].size == 0) {
				continue;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "comment") == 0) {
				i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out_data->comment);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "stiffiness") == 0) {
				++i; out_data->stiffiness = cgltf_json_to_float(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "gravityPower") == 0) {
				++i; out_data->gravityPower = cgltf_json_to_float(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "gravityDir") == 0) {
				i = cgltf_parse_json_vec3(options, tokens, i + 1, json_chunk, &out_data->gravityDir, &out_data->gravityDir_count);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "dragForce") == 0) {
				++i; out_data->dragForce = cgltf_json_to_float(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "center") == 0) {
				++i; out_data->center = cgltf_json_to_int(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "hitRadius") == 0) {
				++i; out_data->hitRadius = cgltf_json_to_float(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "bones") == 0) {
				i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_int), (void**)&out_data->bones, &out_data->bones_count);
				if (i < 0) return i;
				i = cgltf_parse_json_int_array(tokens, i - 1, json_chunk, out_data->bones, (int)out_data->bones_count);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "colliderGroups") == 0) {
				i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_int), (void**)&out_data->colliderGroups, &out_data->colliderGroups_count);
				if (i < 0) return i;
				i = cgltf_parse_json_int_array(tokens, i - 1, json_chunk, out_data->colliderGroups, (int)out_data->colliderGroups_count);
			} else {
				i = cgltf_skip_json(tokens, i + 1);
			}
			if (i < 0) return i;
		}
	} else {
		i = cgltf_skip_json(tokens, i + 1);
	}
	return i;
}
static int cgltf_parse_json_vrm_secondaryanimation_collidergroup(cgltf_options* options, jsmntok_t const* tokens, int i, const uint8_t* json_chunk, cgltf_vrm_secondaryanimation_collidergroup* out_data) {
	(void)options;
	if (tokens[i].type == JSMN_OBJECT) {
		int size = tokens[i].size; ++i;
		for (int j = 0; j < size; ++j) {
			if (tokens[i].type != JSMN_STRING || tokens[i].size == 0) {
				continue;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "node") == 0) {
				++i; out_data->node = cgltf_json_to_int(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "colliders") == 0) {
				i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_vrm_secondaryanimation_collidergroup_colliders), (void**)&out_data->colliders, &out_data->colliders_count);
				if (i < 0) return i;
				for (cgltf_size k = 0; k < out_data->colliders_count; k++) {
					i = cgltf_parse_json_vrm_secondaryanimation_collidergroup_colliders(options, tokens, i, json_chunk, out_data->colliders + k);
				}
			} else {
				i = cgltf_skip_json(tokens, i + 1);
			}
			if (i < 0) return i;
		}
	} else {
		i = cgltf_skip_json(tokens, i + 1);
	}
	return i;
}
static int cgltf_parse_json_vrm_secondaryanimation(cgltf_options* options, jsmntok_t const* tokens, int i, const uint8_t* json_chunk, cgltf_vrm_secondaryanimation* out_data) {
	(void)options;
	if (tokens[i].type == JSMN_OBJECT) {
		int size = tokens[i].size; ++i;
		for (int j = 0; j < size; ++j) {
			if (tokens[i].type != JSMN_STRING || tokens[i].size == 0) {
				continue;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "boneGroups") == 0) {
				i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_vrm_secondaryanimation_spring), (void**)&out_data->boneGroups, &out_data->boneGroups_count);
				if (i < 0) return i;
				for (cgltf_size k = 0; k < out_data->boneGroups_count; k++) {
					i = cgltf_parse_json_vrm_secondaryanimation_spring(options, tokens, i, json_chunk, out_data->boneGroups + k);
				}
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "colliderGroups") == 0) {
				i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_vrm_secondaryanimation_collidergroup), (void**)&out_data->colliderGroups, &out_data->colliderGroups_count);
				if (i < 0) return i;
				for (cgltf_size k = 0; k < out_data->colliderGroups_count; k++) {
					i = cgltf_parse_json_vrm_secondaryanimation_collidergroup(options, tokens, i, json_chunk, out_data->colliderGroups + k);
				}
			} else {
				i = cgltf_skip_json(tokens, i + 1);
			}
			if (i < 0) return i;
		}
	} else {
		i = cgltf_skip_json(tokens, i + 1);
	}
	return i;
}
static int cgltf_parse_json_vrm_blendshape_bind(cgltf_options* options, jsmntok_t const* tokens, int i, const uint8_t* json_chunk, cgltf_vrm_blendshape_bind* out_data) {
	(void)options;
	if (tokens[i].type == JSMN_OBJECT) {
		int size = tokens[i].size; ++i;
		for (int j = 0; j < size; ++j) {
			if (tokens[i].type != JSMN_STRING || tokens[i].size == 0) {
				continue;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "mesh") == 0) {
				++i; out_data->mesh = cgltf_json_to_int(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "index") == 0) {
				++i; out_data->index = cgltf_json_to_int(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "weight") == 0) {
				++i; out_data->weight = cgltf_json_to_float(tokens + i, json_chunk); ++i;
			} else {
				i = cgltf_skip_json(tokens, i + 1);
			}
			if (i < 0) return i;
		}
	} else {
		i = cgltf_skip_json(tokens, i + 1);
	}
	return i;
}
static int cgltf_parse_json_vrm_blendshape_materialbind(cgltf_options* options, jsmntok_t const* tokens, int i, const uint8_t* json_chunk, cgltf_vrm_blendshape_materialbind* out_data) {
	(void)options;
	if (tokens[i].type == JSMN_OBJECT) {
		int size = tokens[i].size; ++i;
		for (int j = 0; j < size; ++j) {
			if (tokens[i].type != JSMN_STRING || tokens[i].size == 0) {
				continue;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "materialName") == 0) {
				i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out_data->materialName);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "propertyName") == 0) {
				i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out_data->propertyName);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "targetValue") == 0) {
				i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_float), (void**)&out_data->targetValue, &out_data->targetValue_count);
				if (i < 0) return i;
				i = cgltf_parse_json_float_array(tokens, i - 1, json_chunk, out_data->targetValue, (int)out_data->targetValue_count);
			} else {
				i = cgltf_skip_json(tokens, i + 1);
			}
			if (i < 0) return i;
		}
	} else {
		i = cgltf_skip_json(tokens, i + 1);
	}
	return i;
}
static int cgltf_parse_json_vrm_blendshape_group(cgltf_options* options, jsmntok_t const* tokens, int i, const uint8_t* json_chunk, cgltf_vrm_blendshape_group* out_data) {
	(void)options;
	if (tokens[i].type == JSMN_OBJECT) {
		int size = tokens[i].size; ++i;
		for (int j = 0; j < size; ++j) {
			if (tokens[i].type != JSMN_STRING || tokens[i].size == 0) {
				continue;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "name") == 0) {
				i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out_data->name);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "presetName") == 0) {
				char* enum_key = NULL; i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &enum_key);
				i = select_cgltf_vrm_blendshape_group_presetName(enum_key, &out_data->presetName) ? i : -1;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "binds") == 0) {
				i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_vrm_blendshape_bind), (void**)&out_data->binds, &out_data->binds_count);
				if (i < 0) return i;
				for (cgltf_size k = 0; k < out_data->binds_count; k++) {
					i = cgltf_parse_json_vrm_blendshape_bind(options, tokens, i, json_chunk, out_data->binds + k);
				}
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "materialValues") == 0) {
				i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_vrm_blendshape_materialbind), (void**)&out_data->materialValues, &out_data->materialValues_count);
				if (i < 0) return i;
				for (cgltf_size k = 0; k < out_data->materialValues_count; k++) {
					i = cgltf_parse_json_vrm_blendshape_materialbind(options, tokens, i, json_chunk, out_data->materialValues + k);
				}
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "isBinary") == 0) {
				++i; out_data->isBinary = cgltf_json_to_bool(tokens + i, json_chunk); ++i;
			} else {
				i = cgltf_skip_json(tokens, i + 1);
			}
			if (i < 0) return i;
		}
	} else {
		i = cgltf_skip_json(tokens, i + 1);
	}
	return i;
}
static int cgltf_parse_json_vrm_blendshape(cgltf_options* options, jsmntok_t const* tokens, int i, const uint8_t* json_chunk, cgltf_vrm_blendshape* out_data) {
	(void)options;
	if (tokens[i].type == JSMN_OBJECT) {
		int size = tokens[i].size; ++i;
		for (int j = 0; j < size; ++j) {
			if (tokens[i].type != JSMN_STRING || tokens[i].size == 0) {
				continue;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "blendShapeGroups") == 0) {
				i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_vrm_blendshape_group), (void**)&out_data->blendShapeGroups, &out_data->blendShapeGroups_count);
				if (i < 0) return i;
				for (cgltf_size k = 0; k < out_data->blendShapeGroups_count; k++) {
					i = cgltf_parse_json_vrm_blendshape_group(options, tokens, i, json_chunk, out_data->blendShapeGroups + k);
				}
			} else {
				i = cgltf_skip_json(tokens, i + 1);
			}
			if (i < 0) return i;
		}
	} else {
		i = cgltf_skip_json(tokens, i + 1);
	}
	return i;
}
static int cgltf_parse_json_vrm_firstperson_degreemap(cgltf_options* options, jsmntok_t const* tokens, int i, const uint8_t* json_chunk, cgltf_vrm_firstperson_degreemap* out_data) {
	(void)options;
	if (tokens[i].type == JSMN_OBJECT) {
		int size = tokens[i].size; ++i;
		for (int j = 0; j < size; ++j) {
			if (tokens[i].type != JSMN_STRING || tokens[i].size == 0) {
				continue;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "curve") == 0) {
				i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_float), (void**)&out_data->curve, &out_data->curve_count);
				if (i < 0) return i;
				i = cgltf_parse_json_float_array(tokens, i - 1, json_chunk, out_data->curve, (int)out_data->curve_count);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "xRange") == 0) {
				++i; out_data->xRange = cgltf_json_to_float(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "yRange") == 0) {
				++i; out_data->yRange = cgltf_json_to_float(tokens + i, json_chunk); ++i;
			} else {
				i = cgltf_skip_json(tokens, i + 1);
			}
			if (i < 0) return i;
		}
	} else {
		i = cgltf_skip_json(tokens, i + 1);
	}
	return i;
}
static int cgltf_parse_json_vrm_firstperson_meshannotation(cgltf_options* options, jsmntok_t const* tokens, int i, const uint8_t* json_chunk, cgltf_vrm_firstperson_meshannotation* out_data) {
	(void)options;
	if (tokens[i].type == JSMN_OBJECT) {
		int size = tokens[i].size; ++i;
		for (int j = 0; j < size; ++j) {
			if (tokens[i].type != JSMN_STRING || tokens[i].size == 0) {
				continue;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "mesh") == 0) {
				++i; out_data->mesh = cgltf_json_to_int(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "firstPersonFlag") == 0) {
				i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out_data->firstPersonFlag);
			} else {
				i = cgltf_skip_json(tokens, i + 1);
			}
			if (i < 0) return i;
		}
	} else {
		i = cgltf_skip_json(tokens, i + 1);
	}
	return i;
}
static int cgltf_parse_json_vrm_firstperson(cgltf_options* options, jsmntok_t const* tokens, int i, const uint8_t* json_chunk, cgltf_vrm_firstperson* out_data) {
	(void)options;
	if (tokens[i].type == JSMN_OBJECT) {
		int size = tokens[i].size; ++i;
		for (int j = 0; j < size; ++j) {
			if (tokens[i].type != JSMN_STRING || tokens[i].size == 0) {
				continue;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "firstPersonBone") == 0) {
				++i; out_data->firstPersonBone = cgltf_json_to_int(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "firstPersonBoneOffset") == 0) {
				i = cgltf_parse_json_vec3(options, tokens, i + 1, json_chunk, &out_data->firstPersonBoneOffset, &out_data->firstPersonBoneOffset_count);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "meshAnnotations") == 0) {
				i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_vrm_firstperson_meshannotation), (void**)&out_data->meshAnnotations, &out_data->meshAnnotations_count);
				if (i < 0) return i;
				for (cgltf_size k = 0; k < out_data->meshAnnotations_count; k++) {
					i = cgltf_parse_json_vrm_firstperson_meshannotation(options, tokens, i, json_chunk, out_data->meshAnnotations + k);
				}
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "lookAtTypeName") == 0) {
				char* enum_key = NULL; i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &enum_key);
				i = select_cgltf_vrm_firstperson_lookAtTypeName(enum_key, &out_data->lookAtTypeName) ? i : -1;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "lookAtHorizontalInner") == 0) {
				i = cgltf_parse_json_vrm_firstperson_degreemap(options, tokens, i + 1, json_chunk, &out_data->lookAtHorizontalInner);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "lookAtHorizontalOuter") == 0) {
				i = cgltf_parse_json_vrm_firstperson_degreemap(options, tokens, i + 1, json_chunk, &out_data->lookAtHorizontalOuter);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "lookAtVerticalDown") == 0) {
				i = cgltf_parse_json_vrm_firstperson_degreemap(options, tokens, i + 1, json_chunk, &out_data->lookAtVerticalDown);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "lookAtVerticalUp") == 0) {
				i = cgltf_parse_json_vrm_firstperson_degreemap(options, tokens, i + 1, json_chunk, &out_data->lookAtVerticalUp);
			} else {
				i = cgltf_skip_json(tokens, i + 1);
			}
			if (i < 0) return i;
		}
	} else {
		i = cgltf_skip_json(tokens, i + 1);
	}
	return i;
}
static int cgltf_parse_json_vrm_humanoid_bone(cgltf_options* options, jsmntok_t const* tokens, int i, const uint8_t* json_chunk, cgltf_vrm_humanoid_bone* out_data) {
	(void)options;
	if (tokens[i].type == JSMN_OBJECT) {
		int size = tokens[i].size; ++i;
		for (int j = 0; j < size; ++j) {
			if (tokens[i].type != JSMN_STRING || tokens[i].size == 0) {
				continue;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "bone") == 0) {
				char* enum_key = NULL; i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &enum_key);
				i = select_cgltf_vrm_humanoid_bone_bone(enum_key, &out_data->bone) ? i : -1;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "node") == 0) {
				++i; out_data->node = cgltf_json_to_int(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "useDefaultValues") == 0) {
				++i; out_data->useDefaultValues = cgltf_json_to_bool(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "min") == 0) {
				i = cgltf_parse_json_vec3(options, tokens, i + 1, json_chunk, &out_data->min, &out_data->min_count);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "max") == 0) {
				i = cgltf_parse_json_vec3(options, tokens, i + 1, json_chunk, &out_data->max, &out_data->max_count);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "center") == 0) {
				i = cgltf_parse_json_vec3(options, tokens, i + 1, json_chunk, &out_data->center, &out_data->center_count);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "axisLength") == 0) {
				++i; out_data->axisLength = cgltf_json_to_float(tokens + i, json_chunk); ++i;
			} else {
				i = cgltf_skip_json(tokens, i + 1);
			}
			if (i < 0) return i;
		}
	} else {
		i = cgltf_skip_json(tokens, i + 1);
	}
	return i;
}
static int cgltf_parse_json_vrm_humanoid(cgltf_options* options, jsmntok_t const* tokens, int i, const uint8_t* json_chunk, cgltf_vrm_humanoid* out_data) {
	(void)options;
	if (tokens[i].type == JSMN_OBJECT) {
		int size = tokens[i].size; ++i;
		for (int j = 0; j < size; ++j) {
			if (tokens[i].type != JSMN_STRING || tokens[i].size == 0) {
				continue;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "humanBones") == 0) {
				i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_vrm_humanoid_bone), (void**)&out_data->humanBones, &out_data->humanBones_count);
				if (i < 0) return i;
				for (cgltf_size k = 0; k < out_data->humanBones_count; k++) {
					i = cgltf_parse_json_vrm_humanoid_bone(options, tokens, i, json_chunk, out_data->humanBones + k);
				}
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "armStretch") == 0) {
				++i; out_data->armStretch = cgltf_json_to_float(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "legStretch") == 0) {
				++i; out_data->legStretch = cgltf_json_to_float(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "upperArmTwist") == 0) {
				++i; out_data->upperArmTwist = cgltf_json_to_float(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "lowerArmTwist") == 0) {
				++i; out_data->lowerArmTwist = cgltf_json_to_float(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "upperLegTwist") == 0) {
				++i; out_data->upperLegTwist = cgltf_json_to_float(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "lowerLegTwist") == 0) {
				++i; out_data->lowerLegTwist = cgltf_json_to_float(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "feetSpacing") == 0) {
				++i; out_data->feetSpacing = cgltf_json_to_float(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "hasTranslationDoF") == 0) {
				++i; out_data->hasTranslationDoF = cgltf_json_to_bool(tokens + i, json_chunk); ++i;
			} else {
				i = cgltf_skip_json(tokens, i + 1);
			}
			if (i < 0) return i;
		}
	} else {
		i = cgltf_skip_json(tokens, i + 1);
	}
	return i;
}
static int cgltf_parse_json_vrm_material(cgltf_options* options, jsmntok_t const* tokens, int i, const uint8_t* json_chunk, cgltf_vrm_material* out_data) {
	(void)options;
	if (tokens[i].type == JSMN_OBJECT) {
		int size = tokens[i].size; ++i;
		for (int j = 0; j < size; ++j) {
			if (tokens[i].type != JSMN_STRING || tokens[i].size == 0) {
				continue;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "name") == 0) {
				i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out_data->name);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "shader") == 0) {
				i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out_data->shader);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "renderQueue") == 0) {
				++i; out_data->renderQueue = cgltf_json_to_int(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "floatProperties") == 0) {
					i = cgltf_parse_json_float_properties(options, tokens, i + 1, json_chunk, &out_data->floatProperties_keys, &out_data->floatProperties_values, &out_data->floatProperties_count);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "vectorProperties") == 0) {
					i = cgltf_parse_json_floats_properties(options, tokens, i + 1, json_chunk, &out_data->vectorProperties_keys, &out_data->vectorProperties_values, &out_data->vectorProperties_floats_size, &out_data->vectorProperties_count);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "textureProperties") == 0) {
					i = cgltf_parse_json_int_properties(options, tokens, i + 1, json_chunk, &out_data->textureProperties_keys, &out_data->textureProperties_values, &out_data->textureProperties_count);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "keywordMap") == 0) {
					i = cgltf_parse_json_bool_properties(options, tokens, i + 1, json_chunk, &out_data->keywordMap_keys, &out_data->keywordMap_values, &out_data->keywordMap_count);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "tagMap") == 0) {
					i = cgltf_parse_json_chars_properties(options, tokens, i + 1, json_chunk, &out_data->tagMap_keys, &out_data->tagMap_values, &out_data->tagMap_count);
			} else {
				i = cgltf_skip_json(tokens, i + 1);
			}
			if (i < 0) return i;
		}
	} else {
		i = cgltf_skip_json(tokens, i + 1);
	}
	return i;
}
static int cgltf_parse_json_vrm_meta(cgltf_options* options, jsmntok_t const* tokens, int i, const uint8_t* json_chunk, cgltf_vrm_meta* out_data) {
	(void)options;
	if (tokens[i].type == JSMN_OBJECT) {
		int size = tokens[i].size; ++i;
		for (int j = 0; j < size; ++j) {
			if (tokens[i].type != JSMN_STRING || tokens[i].size == 0) {
				continue;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "title") == 0) {
				i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out_data->title);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "version") == 0) {
				i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out_data->version);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "author") == 0) {
				i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out_data->author);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "contactInformation") == 0) {
				i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out_data->contactInformation);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "reference") == 0) {
				i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out_data->reference);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "texture") == 0) {
				++i; out_data->texture = cgltf_json_to_int(tokens + i, json_chunk); ++i;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "allowedUserName") == 0) {
				char* enum_key = NULL; i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &enum_key);
				i = select_cgltf_vrm_meta_allowedUserName(enum_key, &out_data->allowedUserName) ? i : -1;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "violentUssageName") == 0) {
				char* enum_key = NULL; i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &enum_key);
				i = select_cgltf_vrm_meta_violentUssageName(enum_key, &out_data->violentUssageName) ? i : -1;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "sexualUssageName") == 0) {
				char* enum_key = NULL; i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &enum_key);
				i = select_cgltf_vrm_meta_sexualUssageName(enum_key, &out_data->sexualUssageName) ? i : -1;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "commercialUssageName") == 0) {
				char* enum_key = NULL; i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &enum_key);
				i = select_cgltf_vrm_meta_commercialUssageName(enum_key, &out_data->commercialUssageName) ? i : -1;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "otherPermissionUrl") == 0) {
				i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out_data->otherPermissionUrl);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "licenseName") == 0) {
				char* enum_key = NULL; i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &enum_key);
				i = select_cgltf_vrm_meta_licenseName(enum_key, &out_data->licenseName) ? i : -1;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "otherLicenseUrl") == 0) {
				i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out_data->otherLicenseUrl);
			} else {
				i = cgltf_skip_json(tokens, i + 1);
			}
			if (i < 0) return i;
		}
	} else {
		i = cgltf_skip_json(tokens, i + 1);
	}
	return i;
}
static int cgltf_parse_json_vrm(cgltf_options* options, jsmntok_t const* tokens, int i, const uint8_t* json_chunk, cgltf_vrm* out_data) {
	(void)options;
	if (tokens[i].type == JSMN_OBJECT) {
		int size = tokens[i].size; ++i;
		for (int j = 0; j < size; ++j) {
			if (tokens[i].type != JSMN_STRING || tokens[i].size == 0) {
				continue;
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "exporterVersion") == 0) {
				i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out_data->exporterVersion);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "specVersion") == 0) {
				i = cgltf_parse_json_string(options, tokens, i + 1, json_chunk, &out_data->specVersion);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "meta") == 0) {
				i = cgltf_parse_json_vrm_meta(options, tokens, i + 1, json_chunk, &out_data->meta);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "humanoid") == 0) {
				i = cgltf_parse_json_vrm_humanoid(options, tokens, i + 1, json_chunk, &out_data->humanoid);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "firstPerson") == 0) {
				i = cgltf_parse_json_vrm_firstperson(options, tokens, i + 1, json_chunk, &out_data->firstPerson);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "blendShapeMaster") == 0) {
				i = cgltf_parse_json_vrm_blendshape(options, tokens, i + 1, json_chunk, &out_data->blendShapeMaster);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "secondaryAnimation") == 0) {
				i = cgltf_parse_json_vrm_secondaryanimation(options, tokens, i + 1, json_chunk, &out_data->secondaryAnimation);
			} else if (cgltf_json_strcmp(tokens + i, json_chunk, "materialProperties") == 0) {
				i = cgltf_parse_json_array(options, tokens, i + 1, json_chunk, sizeof(cgltf_vrm_material), (void**)&out_data->materialProperties, &out_data->materialProperties_count);
				if (i < 0) return i;
				for (cgltf_size k = 0; k < out_data->materialProperties_count; k++) {
					i = cgltf_parse_json_vrm_material(options, tokens, i, json_chunk, out_data->materialProperties + k);
				}
			} else {
				i = cgltf_skip_json(tokens, i + 1);
			}
			if (i < 0) return i;
		}
	} else {
		i = cgltf_skip_json(tokens, i + 1);
	}
	return i;
}
