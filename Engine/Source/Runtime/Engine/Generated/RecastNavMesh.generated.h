// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ENGINE_RecastNavMesh_generated_h
#error "RecastNavMesh.generated.h already included, missing '#pragma once' in RecastNavMesh.h"
#endif
#define ENGINE_RecastNavMesh_generated_h

#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h_427_RPC_WRAPPERS
#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h_427_RPC_WRAPPERS_NO_PURE_DECLS
#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h_427_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesARecastNavMesh(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_ARecastNavMesh(); \
	public: \
	DECLARE_CLASS(ARecastNavMesh, ANavigationData, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), 0, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(ARecastNavMesh) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h_427_INCLASS \
	private: \
	static void StaticRegisterNativesARecastNavMesh(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_ARecastNavMesh(); \
	public: \
	DECLARE_CLASS(ARecastNavMesh, ANavigationData, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), 0, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(ARecastNavMesh) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h_427_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARecastNavMesh(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARecastNavMesh) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARecastNavMesh); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARecastNavMesh); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARecastNavMesh(ARecastNavMesh&&); \
	NO_API ARecastNavMesh(const ARecastNavMesh&); \
public:


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h_427_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARecastNavMesh(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARecastNavMesh(ARecastNavMesh&&); \
	NO_API ARecastNavMesh(const ARecastNavMesh&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARecastNavMesh); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARecastNavMesh); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARecastNavMesh)


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h_427_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TileSetUpdateInterval() { return STRUCT_OFFSET(ARecastNavMesh, TileSetUpdateInterval); }


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h_424_PROLOG
#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h_427_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h_427_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h_427_RPC_WRAPPERS \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h_427_INCLASS \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h_427_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h_427_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h_427_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h_427_RPC_WRAPPERS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h_427_INCLASS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h_427_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class RecastNavMesh."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Engine_Source_Runtime_Engine_Classes_AI_Navigation_RecastNavMesh_h


#define FOREACH_ENUM_ERECASTPARTITIONING(op) \
	op(ERecastPartitioning::Monotone) \
	op(ERecastPartitioning::Watershed) \
	op(ERecastPartitioning::ChunkyMonotone) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
