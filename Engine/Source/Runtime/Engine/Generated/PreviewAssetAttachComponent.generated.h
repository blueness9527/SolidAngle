// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ENGINE_PreviewAssetAttachComponent_generated_h
#error "PreviewAssetAttachComponent.generated.h already included, missing '#pragma once' in PreviewAssetAttachComponent.h"
#endif
#define ENGINE_PreviewAssetAttachComponent_generated_h

#define Engine_Source_Runtime_Engine_Classes_Animation_PreviewAssetAttachComponent_h_79_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FPreviewAssetAttachContainer(); \
	ENGINE_API static class UScriptStruct* StaticStruct(); \
	FORCEINLINE static uint32 __PPO__AttachedObjects() { return STRUCT_OFFSET(FPreviewAssetAttachContainer, AttachedObjects); }


#define Engine_Source_Runtime_Engine_Classes_Animation_PreviewAssetAttachComponent_h_22_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FPreviewAttachedObjectPair(); \
	ENGINE_API static class UScriptStruct* StaticStruct(); \
	FORCEINLINE static uint32 __PPO__AttachedObject() { return STRUCT_OFFSET(FPreviewAttachedObjectPair, AttachedObject); } \
	FORCEINLINE static uint32 __PPO__Object_DEPRECATED() { return STRUCT_OFFSET(FPreviewAttachedObjectPair, Object_DEPRECATED); }


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Engine_Source_Runtime_Engine_Classes_Animation_PreviewAssetAttachComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS