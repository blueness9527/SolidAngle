// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ENGINE_DestructibleMesh_generated_h
#error "DestructibleMesh.generated.h already included, missing '#pragma once' in DestructibleMesh.h"
#endif
#define ENGINE_DestructibleMesh_generated_h

#define Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_421_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FDestructibleParameters(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_360_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FDestructibleSpecialHierarchyDepths(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_307_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FDestructibleAdvancedParameters(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_246_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FDestructibleDebrisParameters(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_176_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FDestructibleDamageParameters(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_70_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FDestructibleParametersFlag(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_47_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FDestructibleDepthParameters(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_460_RPC_WRAPPERS
#define Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_460_RPC_WRAPPERS_NO_PURE_DECLS
#define Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_460_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUDestructibleMesh(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_UDestructibleMesh(); \
	public: \
	DECLARE_CLASS(UDestructibleMesh, USkeletalMesh, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Engine"), ENGINE_API) \
	DECLARE_SERIALIZER(UDestructibleMesh) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_460_INCLASS \
	private: \
	static void StaticRegisterNativesUDestructibleMesh(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_UDestructibleMesh(); \
	public: \
	DECLARE_CLASS(UDestructibleMesh, USkeletalMesh, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Engine"), ENGINE_API) \
	DECLARE_SERIALIZER(UDestructibleMesh) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_460_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ENGINE_API UDestructibleMesh(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDestructibleMesh) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ENGINE_API, UDestructibleMesh); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDestructibleMesh); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ENGINE_API UDestructibleMesh(UDestructibleMesh&&); \
	ENGINE_API UDestructibleMesh(const UDestructibleMesh&); \
public:


#define Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_460_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ENGINE_API UDestructibleMesh(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ENGINE_API UDestructibleMesh(UDestructibleMesh&&); \
	ENGINE_API UDestructibleMesh(const UDestructibleMesh&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ENGINE_API, UDestructibleMesh); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDestructibleMesh); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDestructibleMesh)


#define Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_460_PRIVATE_PROPERTY_OFFSET
#define Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_456_PROLOG
#define Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_460_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_460_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_460_RPC_WRAPPERS \
	Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_460_INCLASS \
	Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_460_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_460_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_460_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_460_RPC_WRAPPERS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_460_INCLASS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h_460_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class DestructibleMesh."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Engine_Source_Runtime_Engine_Classes_Engine_DestructibleMesh_h


#define FOREACH_ENUM_EIMPACTDAMAGEOVERRIDE(op) \
	op(IDO_None) \
	op(IDO_On) \
	op(IDO_Off) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
