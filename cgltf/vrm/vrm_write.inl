static const char* cgltf_vrm_blendshape_group_presetName_to_str(const cgltf_vrm_blendshape_group_presetName in) {
	switch (in) {
		case cgltf_vrm_blendshape_group_presetName_unknown: return "unknown";
		case cgltf_vrm_blendshape_group_presetName_neutral: return "neutral";
		case cgltf_vrm_blendshape_group_presetName_a: return "a";
		case cgltf_vrm_blendshape_group_presetName_i: return "i";
		case cgltf_vrm_blendshape_group_presetName_u: return "u";
		case cgltf_vrm_blendshape_group_presetName_e: return "e";
		case cgltf_vrm_blendshape_group_presetName_o: return "o";
		case cgltf_vrm_blendshape_group_presetName_blink: return "blink";
		case cgltf_vrm_blendshape_group_presetName_joy: return "joy";
		case cgltf_vrm_blendshape_group_presetName_angry: return "angry";
		case cgltf_vrm_blendshape_group_presetName_sorrow: return "sorrow";
		case cgltf_vrm_blendshape_group_presetName_fun: return "fun";
		case cgltf_vrm_blendshape_group_presetName_lookup: return "lookup";
		case cgltf_vrm_blendshape_group_presetName_lookdown: return "lookdown";
		case cgltf_vrm_blendshape_group_presetName_lookleft: return "lookleft";
		case cgltf_vrm_blendshape_group_presetName_lookright: return "lookright";
		case cgltf_vrm_blendshape_group_presetName_blink_l: return "blink_l";
		case cgltf_vrm_blendshape_group_presetName_blink_r: return "blink_r";
		default: return "";
	}
}

static const char* cgltf_vrm_firstperson_lookAtTypeName_to_str(const cgltf_vrm_firstperson_lookAtTypeName in) {
	switch (in) {
		case cgltf_vrm_firstperson_lookAtTypeName_Bone: return "Bone";
		case cgltf_vrm_firstperson_lookAtTypeName_BlendShape: return "BlendShape";
		default: return "";
	}
}

static const char* cgltf_vrm_humanoid_bone_bone_to_str(const cgltf_vrm_humanoid_bone_bone in) {
	switch (in) {
		case cgltf_vrm_humanoid_bone_bone_hips: return "hips";
		case cgltf_vrm_humanoid_bone_bone_leftUpperLeg: return "leftUpperLeg";
		case cgltf_vrm_humanoid_bone_bone_rightUpperLeg: return "rightUpperLeg";
		case cgltf_vrm_humanoid_bone_bone_leftLowerLeg: return "leftLowerLeg";
		case cgltf_vrm_humanoid_bone_bone_rightLowerLeg: return "rightLowerLeg";
		case cgltf_vrm_humanoid_bone_bone_leftFoot: return "leftFoot";
		case cgltf_vrm_humanoid_bone_bone_rightFoot: return "rightFoot";
		case cgltf_vrm_humanoid_bone_bone_spine: return "spine";
		case cgltf_vrm_humanoid_bone_bone_chest: return "chest";
		case cgltf_vrm_humanoid_bone_bone_neck: return "neck";
		case cgltf_vrm_humanoid_bone_bone_head: return "head";
		case cgltf_vrm_humanoid_bone_bone_leftShoulder: return "leftShoulder";
		case cgltf_vrm_humanoid_bone_bone_rightShoulder: return "rightShoulder";
		case cgltf_vrm_humanoid_bone_bone_leftUpperArm: return "leftUpperArm";
		case cgltf_vrm_humanoid_bone_bone_rightUpperArm: return "rightUpperArm";
		case cgltf_vrm_humanoid_bone_bone_leftLowerArm: return "leftLowerArm";
		case cgltf_vrm_humanoid_bone_bone_rightLowerArm: return "rightLowerArm";
		case cgltf_vrm_humanoid_bone_bone_leftHand: return "leftHand";
		case cgltf_vrm_humanoid_bone_bone_rightHand: return "rightHand";
		case cgltf_vrm_humanoid_bone_bone_leftToes: return "leftToes";
		case cgltf_vrm_humanoid_bone_bone_rightToes: return "rightToes";
		case cgltf_vrm_humanoid_bone_bone_leftEye: return "leftEye";
		case cgltf_vrm_humanoid_bone_bone_rightEye: return "rightEye";
		case cgltf_vrm_humanoid_bone_bone_jaw: return "jaw";
		case cgltf_vrm_humanoid_bone_bone_leftThumbProximal: return "leftThumbProximal";
		case cgltf_vrm_humanoid_bone_bone_leftThumbIntermediate: return "leftThumbIntermediate";
		case cgltf_vrm_humanoid_bone_bone_leftThumbDistal: return "leftThumbDistal";
		case cgltf_vrm_humanoid_bone_bone_leftIndexProximal: return "leftIndexProximal";
		case cgltf_vrm_humanoid_bone_bone_leftIndexIntermediate: return "leftIndexIntermediate";
		case cgltf_vrm_humanoid_bone_bone_leftIndexDistal: return "leftIndexDistal";
		case cgltf_vrm_humanoid_bone_bone_leftMiddleProximal: return "leftMiddleProximal";
		case cgltf_vrm_humanoid_bone_bone_leftMiddleIntermediate: return "leftMiddleIntermediate";
		case cgltf_vrm_humanoid_bone_bone_leftMiddleDistal: return "leftMiddleDistal";
		case cgltf_vrm_humanoid_bone_bone_leftRingProximal: return "leftRingProximal";
		case cgltf_vrm_humanoid_bone_bone_leftRingIntermediate: return "leftRingIntermediate";
		case cgltf_vrm_humanoid_bone_bone_leftRingDistal: return "leftRingDistal";
		case cgltf_vrm_humanoid_bone_bone_leftLittleProximal: return "leftLittleProximal";
		case cgltf_vrm_humanoid_bone_bone_leftLittleIntermediate: return "leftLittleIntermediate";
		case cgltf_vrm_humanoid_bone_bone_leftLittleDistal: return "leftLittleDistal";
		case cgltf_vrm_humanoid_bone_bone_rightThumbProximal: return "rightThumbProximal";
		case cgltf_vrm_humanoid_bone_bone_rightThumbIntermediate: return "rightThumbIntermediate";
		case cgltf_vrm_humanoid_bone_bone_rightThumbDistal: return "rightThumbDistal";
		case cgltf_vrm_humanoid_bone_bone_rightIndexProximal: return "rightIndexProximal";
		case cgltf_vrm_humanoid_bone_bone_rightIndexIntermediate: return "rightIndexIntermediate";
		case cgltf_vrm_humanoid_bone_bone_rightIndexDistal: return "rightIndexDistal";
		case cgltf_vrm_humanoid_bone_bone_rightMiddleProximal: return "rightMiddleProximal";
		case cgltf_vrm_humanoid_bone_bone_rightMiddleIntermediate: return "rightMiddleIntermediate";
		case cgltf_vrm_humanoid_bone_bone_rightMiddleDistal: return "rightMiddleDistal";
		case cgltf_vrm_humanoid_bone_bone_rightRingProximal: return "rightRingProximal";
		case cgltf_vrm_humanoid_bone_bone_rightRingIntermediate: return "rightRingIntermediate";
		case cgltf_vrm_humanoid_bone_bone_rightRingDistal: return "rightRingDistal";
		case cgltf_vrm_humanoid_bone_bone_rightLittleProximal: return "rightLittleProximal";
		case cgltf_vrm_humanoid_bone_bone_rightLittleIntermediate: return "rightLittleIntermediate";
		case cgltf_vrm_humanoid_bone_bone_rightLittleDistal: return "rightLittleDistal";
		case cgltf_vrm_humanoid_bone_bone_upperChest: return "upperChest";
		default: return "";
	}
}

static const char* cgltf_vrm_meta_allowedUserName_to_str(const cgltf_vrm_meta_allowedUserName in) {
	switch (in) {
		case cgltf_vrm_meta_allowedUserName_OnlyAuthor: return "OnlyAuthor";
		case cgltf_vrm_meta_allowedUserName_ExplicitlyLicensedPerson: return "ExplicitlyLicensedPerson";
		case cgltf_vrm_meta_allowedUserName_Everyone: return "Everyone";
		default: return "";
	}
}

static const char* cgltf_vrm_meta_violentUssageName_to_str(const cgltf_vrm_meta_violentUssageName in) {
	switch (in) {
		case cgltf_vrm_meta_violentUssageName_Disallow: return "Disallow";
		case cgltf_vrm_meta_violentUssageName_Allow: return "Allow";
		default: return "";
	}
}

static const char* cgltf_vrm_meta_sexualUssageName_to_str(const cgltf_vrm_meta_sexualUssageName in) {
	switch (in) {
		case cgltf_vrm_meta_sexualUssageName_Disallow: return "Disallow";
		case cgltf_vrm_meta_sexualUssageName_Allow: return "Allow";
		default: return "";
	}
}

static const char* cgltf_vrm_meta_commercialUssageName_to_str(const cgltf_vrm_meta_commercialUssageName in) {
	switch (in) {
		case cgltf_vrm_meta_commercialUssageName_Disallow: return "Disallow";
		case cgltf_vrm_meta_commercialUssageName_Allow: return "Allow";
		default: return "";
	}
}

static const char* cgltf_vrm_meta_licenseName_to_str(const cgltf_vrm_meta_licenseName in) {
	switch (in) {
		case cgltf_vrm_meta_licenseName_Redistribution_Prohibited: return "Redistribution_Prohibited";
		case cgltf_vrm_meta_licenseName_CC0: return "CC0";
		case cgltf_vrm_meta_licenseName_CC_BY: return "CC_BY";
		case cgltf_vrm_meta_licenseName_CC_BY_NC: return "CC_BY_NC";
		case cgltf_vrm_meta_licenseName_CC_BY_SA: return "CC_BY_SA";
		case cgltf_vrm_meta_licenseName_CC_BY_NC_SA: return "CC_BY_NC_SA";
		case cgltf_vrm_meta_licenseName_CC_BY_ND: return "CC_BY_ND";
		case cgltf_vrm_meta_licenseName_CC_BY_NC_ND: return "CC_BY_NC_ND";
		case cgltf_vrm_meta_licenseName_Other: return "Other";
		default: return "";
	}
}
static void cgltf_write_vrm_secondaryanimation_collidergroup_colliders(cgltf_write_context* context, const cgltf_vrm_secondaryanimation_collidergroup_colliders* data) {
	cgltf_write_line(context, "{");
	if (data->offset_count > 0) {
		cgltf_write_line(context, "\"offset\": {");
		cgltf_write_floatprop_strict(context, "x", data->offset[0]);
		cgltf_write_floatprop_strict(context, "y", data->offset[1]);
		cgltf_write_floatprop_strict(context, "z", data->offset[2]);
		cgltf_write_line(context, "}");
	}
	cgltf_write_floatprop_strict(context, "radius", data->radius);
	cgltf_write_line(context, "}");
}
static void cgltf_write_vrm_secondaryanimation_spring(cgltf_write_context* context, const cgltf_vrm_secondaryanimation_spring* data) {
	cgltf_write_line(context, "{");
	cgltf_write_strprop(context, "comment", data->comment);
	cgltf_write_floatprop_strict(context, "stiffiness", data->stiffiness);
	cgltf_write_floatprop_strict(context, "gravityPower", data->gravityPower);
	if (data->gravityDir_count > 0) {
		cgltf_write_line(context, "\"gravityDir\": {");
		cgltf_write_floatprop_strict(context, "x", data->gravityDir[0]);
		cgltf_write_floatprop_strict(context, "y", data->gravityDir[1]);
		cgltf_write_floatprop_strict(context, "z", data->gravityDir[2]);
		cgltf_write_line(context, "}");
	}
	cgltf_write_floatprop_strict(context, "dragForce", data->dragForce);
	cgltf_write_intprop_strict(context, "center", data->center);
	cgltf_write_floatprop_strict(context, "hitRadius", data->hitRadius);
	cgltf_write_intarrayprop(context, "bones", data->bones, data->bones_count);
	cgltf_write_intarrayprop(context, "colliderGroups", data->colliderGroups, data->colliderGroups_count);
	cgltf_write_line(context, "}");
}
static void cgltf_write_vrm_secondaryanimation_collidergroup(cgltf_write_context* context, const cgltf_vrm_secondaryanimation_collidergroup* data) {
	cgltf_write_line(context, "{");
	cgltf_write_intprop_strict(context, "node", data->node);
	cgltf_write_line(context, "\"colliders\": [");
	for (cgltf_size i = 0; i < data->colliders_count; ++i) {
		cgltf_write_vrm_secondaryanimation_collidergroup_colliders(context, data->colliders + i);
	}
	cgltf_write_line(context, "]");
	cgltf_write_line(context, "}");
}
static void cgltf_write_vrm_secondaryanimation(cgltf_write_context* context, const cgltf_vrm_secondaryanimation* data) {
	cgltf_write_line(context, "{");
	cgltf_write_line(context, "\"boneGroups\": [");
	for (cgltf_size i = 0; i < data->boneGroups_count; ++i) {
		cgltf_write_vrm_secondaryanimation_spring(context, data->boneGroups + i);
	}
	cgltf_write_line(context, "]");
	cgltf_write_line(context, "\"colliderGroups\": [");
	for (cgltf_size i = 0; i < data->colliderGroups_count; ++i) {
		cgltf_write_vrm_secondaryanimation_collidergroup(context, data->colliderGroups + i);
	}
	cgltf_write_line(context, "]");
	cgltf_write_line(context, "}");
}
static void cgltf_write_vrm_blendshape_bind(cgltf_write_context* context, const cgltf_vrm_blendshape_bind* data) {
	cgltf_write_line(context, "{");
	cgltf_write_intprop_strict(context, "mesh", data->mesh);
	cgltf_write_intprop_strict(context, "index", data->index);
	cgltf_write_floatprop_strict(context, "weight", data->weight);
	cgltf_write_line(context, "}");
}
static void cgltf_write_vrm_blendshape_materialbind(cgltf_write_context* context, const cgltf_vrm_blendshape_materialbind* data) {
	cgltf_write_line(context, "{");
	cgltf_write_strprop(context, "materialName", data->materialName);
	cgltf_write_strprop(context, "propertyName", data->propertyName);
	cgltf_write_floatarrayprop(context, "targetValue", data->targetValue, data->targetValue_count);
	cgltf_write_line(context, "}");
}
static void cgltf_write_vrm_blendshape_group(cgltf_write_context* context, const cgltf_vrm_blendshape_group* data) {
	cgltf_write_line(context, "{");
	cgltf_write_strprop(context, "name", data->name);
	cgltf_write_strprop(context, "presetName", cgltf_vrm_blendshape_group_presetName_to_str(data->presetName));
	cgltf_write_line(context, "\"binds\": [");
	for (cgltf_size i = 0; i < data->binds_count; ++i) {
		cgltf_write_vrm_blendshape_bind(context, data->binds + i);
	}
	cgltf_write_line(context, "]");
	cgltf_write_line(context, "\"materialValues\": [");
	for (cgltf_size i = 0; i < data->materialValues_count; ++i) {
		cgltf_write_vrm_blendshape_materialbind(context, data->materialValues + i);
	}
	cgltf_write_line(context, "]");
	cgltf_write_boolprop_strict(context, "isBinary", data->isBinary);
	cgltf_write_line(context, "}");
}
static void cgltf_write_vrm_blendshape(cgltf_write_context* context, const cgltf_vrm_blendshape* data) {
	cgltf_write_line(context, "{");
	cgltf_write_line(context, "\"blendShapeGroups\": [");
	for (cgltf_size i = 0; i < data->blendShapeGroups_count; ++i) {
		cgltf_write_vrm_blendshape_group(context, data->blendShapeGroups + i);
	}
	cgltf_write_line(context, "]");
	cgltf_write_line(context, "}");
}
static void cgltf_write_vrm_firstperson_degreemap(cgltf_write_context* context, const cgltf_vrm_firstperson_degreemap* data) {
	cgltf_write_line(context, "{");
	cgltf_write_floatarrayprop(context, "curve", data->curve, data->curve_count);
	cgltf_write_floatprop_strict(context, "xRange", data->xRange);
	cgltf_write_floatprop_strict(context, "yRange", data->yRange);
	cgltf_write_line(context, "}");
}
static void cgltf_write_vrm_firstperson_meshannotation(cgltf_write_context* context, const cgltf_vrm_firstperson_meshannotation* data) {
	cgltf_write_line(context, "{");
	cgltf_write_intprop_strict(context, "mesh", data->mesh);
	cgltf_write_strprop(context, "firstPersonFlag", data->firstPersonFlag);
	cgltf_write_line(context, "}");
}
static void cgltf_write_vrm_firstperson(cgltf_write_context* context, const cgltf_vrm_firstperson* data) {
	cgltf_write_line(context, "{");
	cgltf_write_intprop_strict(context, "firstPersonBone", data->firstPersonBone);
	if (data->firstPersonBoneOffset_count > 0) {
		cgltf_write_line(context, "\"firstPersonBoneOffset\": {");
		cgltf_write_floatprop_strict(context, "x", data->firstPersonBoneOffset[0]);
		cgltf_write_floatprop_strict(context, "y", data->firstPersonBoneOffset[1]);
		cgltf_write_floatprop_strict(context, "z", data->firstPersonBoneOffset[2]);
		cgltf_write_line(context, "}");
	}
	cgltf_write_line(context, "\"meshAnnotations\": [");
	for (cgltf_size i = 0; i < data->meshAnnotations_count; ++i) {
		cgltf_write_vrm_firstperson_meshannotation(context, data->meshAnnotations + i);
	}
	cgltf_write_line(context, "]");
	cgltf_write_strprop(context, "lookAtTypeName", cgltf_vrm_firstperson_lookAtTypeName_to_str(data->lookAtTypeName));
	cgltf_write_line(context, "\"lookAtHorizontalInner\": ");
	cgltf_write_vrm_firstperson_degreemap(context, &data->lookAtHorizontalInner);
	cgltf_write_line(context, "\"lookAtHorizontalOuter\": ");
	cgltf_write_vrm_firstperson_degreemap(context, &data->lookAtHorizontalOuter);
	cgltf_write_line(context, "\"lookAtVerticalDown\": ");
	cgltf_write_vrm_firstperson_degreemap(context, &data->lookAtVerticalDown);
	cgltf_write_line(context, "\"lookAtVerticalUp\": ");
	cgltf_write_vrm_firstperson_degreemap(context, &data->lookAtVerticalUp);
	cgltf_write_line(context, "}");
}
static void cgltf_write_vrm_humanoid_bone(cgltf_write_context* context, const cgltf_vrm_humanoid_bone* data) {
	cgltf_write_line(context, "{");
	cgltf_write_strprop(context, "bone", cgltf_vrm_humanoid_bone_bone_to_str(data->bone));
	cgltf_write_intprop_strict(context, "node", data->node);
	cgltf_write_boolprop_strict(context, "useDefaultValues", data->useDefaultValues);
	if (data->min_count > 0) {
		cgltf_write_line(context, "\"min\": {");
		cgltf_write_floatprop_strict(context, "x", data->min[0]);
		cgltf_write_floatprop_strict(context, "y", data->min[1]);
		cgltf_write_floatprop_strict(context, "z", data->min[2]);
		cgltf_write_line(context, "}");
	}
	if (data->max_count > 0) {
		cgltf_write_line(context, "\"max\": {");
		cgltf_write_floatprop_strict(context, "x", data->max[0]);
		cgltf_write_floatprop_strict(context, "y", data->max[1]);
		cgltf_write_floatprop_strict(context, "z", data->max[2]);
		cgltf_write_line(context, "}");
	}
	if (data->center_count > 0) {
		cgltf_write_line(context, "\"center\": {");
		cgltf_write_floatprop_strict(context, "x", data->center[0]);
		cgltf_write_floatprop_strict(context, "y", data->center[1]);
		cgltf_write_floatprop_strict(context, "z", data->center[2]);
		cgltf_write_line(context, "}");
	}
	cgltf_write_floatprop_strict(context, "axisLength", data->axisLength);
	cgltf_write_line(context, "}");
}
static void cgltf_write_vrm_humanoid(cgltf_write_context* context, const cgltf_vrm_humanoid* data) {
	cgltf_write_line(context, "{");
	cgltf_write_line(context, "\"humanBones\": [");
	for (cgltf_size i = 0; i < data->humanBones_count; ++i) {
		cgltf_write_vrm_humanoid_bone(context, data->humanBones + i);
	}
	cgltf_write_line(context, "]");
	cgltf_write_floatprop_strict(context, "armStretch", data->armStretch);
	cgltf_write_floatprop_strict(context, "legStretch", data->legStretch);
	cgltf_write_floatprop_strict(context, "upperArmTwist", data->upperArmTwist);
	cgltf_write_floatprop_strict(context, "lowerArmTwist", data->lowerArmTwist);
	cgltf_write_floatprop_strict(context, "upperLegTwist", data->upperLegTwist);
	cgltf_write_floatprop_strict(context, "lowerLegTwist", data->lowerLegTwist);
	cgltf_write_floatprop_strict(context, "feetSpacing", data->feetSpacing);
	cgltf_write_boolprop_strict(context, "hasTranslationDoF", data->hasTranslationDoF);
	cgltf_write_line(context, "}");
}
static void cgltf_write_vrm_material(cgltf_write_context* context, const cgltf_vrm_material* data) {
	cgltf_write_line(context, "{");
	cgltf_write_strprop(context, "name", data->name);
	cgltf_write_strprop(context, "shader", data->shader);
	cgltf_write_intprop_strict(context, "renderQueue", data->renderQueue);
	cgltf_write_line(context, "\"floatProperties\": {");
	for (cgltf_size i = 0; i < data->floatProperties_count; i++) {
		cgltf_write_floatprop_strict(context, data->floatProperties_keys[i], data->floatProperties_values[i]);
	}
	cgltf_write_line(context, "}");
	cgltf_write_line(context, "\"vectorProperties\": {");
	for (cgltf_size i = 0; i < data->vectorProperties_count; i++) {
		cgltf_write_floatarrayprop(context, data->vectorProperties_keys[i], data->vectorProperties_values[i], data->vectorProperties_floats_size[i]);
	}
	cgltf_write_line(context, "}");
	cgltf_write_line(context, "\"textureProperties\": {");
	for (cgltf_size i = 0; i < data->textureProperties_count; i++) {
		cgltf_write_intprop_strict(context, data->textureProperties_keys[i], data->textureProperties_values[i]);
	}
	cgltf_write_line(context, "}");
	cgltf_write_line(context, "\"keywordMap\": {");
	for (cgltf_size i = 0; i < data->keywordMap_count; i++) {
		cgltf_write_boolprop_strict(context, data->keywordMap_keys[i], data->keywordMap_values[i]);
	}
	cgltf_write_line(context, "}");
	cgltf_write_line(context, "\"tagMap\": {");
	for (cgltf_size i = 0; i < data->tagMap_count; i++) {
		cgltf_write_strprop(context, data->tagMap_keys[i], data->tagMap_values[i]);
	}
	cgltf_write_line(context, "}");
	cgltf_write_line(context, "}");
}
static void cgltf_write_vrm_meta(cgltf_write_context* context, const cgltf_vrm_meta* data) {
	cgltf_write_line(context, "{");
	cgltf_write_strprop(context, "title", data->title);
	cgltf_write_strprop(context, "version", data->version);
	cgltf_write_strprop(context, "author", data->author);
	cgltf_write_strprop(context, "contactInformation", data->contactInformation);
	cgltf_write_strprop(context, "reference", data->reference);
	cgltf_write_intprop_strict(context, "texture", data->texture);
	cgltf_write_strprop(context, "allowedUserName", cgltf_vrm_meta_allowedUserName_to_str(data->allowedUserName));
	cgltf_write_strprop(context, "violentUssageName", cgltf_vrm_meta_violentUssageName_to_str(data->violentUssageName));
	cgltf_write_strprop(context, "sexualUssageName", cgltf_vrm_meta_sexualUssageName_to_str(data->sexualUssageName));
	cgltf_write_strprop(context, "commercialUssageName", cgltf_vrm_meta_commercialUssageName_to_str(data->commercialUssageName));
	cgltf_write_strprop(context, "otherPermissionUrl", data->otherPermissionUrl);
	cgltf_write_strprop(context, "licenseName", cgltf_vrm_meta_licenseName_to_str(data->licenseName));
	cgltf_write_strprop(context, "otherLicenseUrl", data->otherLicenseUrl);
	cgltf_write_line(context, "}");
}
static void cgltf_write_vrm(cgltf_write_context* context, const cgltf_vrm* data) {
	cgltf_write_line(context, "{");
	cgltf_write_strprop(context, "exporterVersion", data->exporterVersion);
	cgltf_write_strprop(context, "specVersion", data->specVersion);
	cgltf_write_line(context, "\"meta\": ");
	cgltf_write_vrm_meta(context, &data->meta);
	cgltf_write_line(context, "\"humanoid\": ");
	cgltf_write_vrm_humanoid(context, &data->humanoid);
	cgltf_write_line(context, "\"firstPerson\": ");
	cgltf_write_vrm_firstperson(context, &data->firstPerson);
	cgltf_write_line(context, "\"blendShapeMaster\": ");
	cgltf_write_vrm_blendshape(context, &data->blendShapeMaster);
	cgltf_write_line(context, "\"secondaryAnimation\": ");
	cgltf_write_vrm_secondaryanimation(context, &data->secondaryAnimation);
	cgltf_write_line(context, "\"materialProperties\": [");
	for (cgltf_size i = 0; i < data->materialProperties_count; ++i) {
		cgltf_write_vrm_material(context, data->materialProperties + i);
	}
	cgltf_write_line(context, "]");
	cgltf_write_line(context, "}");
}
