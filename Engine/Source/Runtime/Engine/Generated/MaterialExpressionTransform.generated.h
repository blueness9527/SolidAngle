// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ENGINE_MaterialExpressionTransform_generated_h
#error "MaterialExpressionTransform.generated.h already included, missing '#pragma once' in MaterialExpressionTransform.h"
#endif
#define ENGINE_MaterialExpressionTransform_generated_h

#define Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h_63_RPC_WRAPPERS
#define Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h_63_RPC_WRAPPERS_NO_PURE_DECLS
#define Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h_63_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUMaterialExpressionTransform(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_UMaterialExpressionTransform(); \
	public: \
	DECLARE_CLASS(UMaterialExpressionTransform, UMaterialExpression, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(UMaterialExpressionTransform) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h_63_INCLASS \
	private: \
	static void StaticRegisterNativesUMaterialExpressionTransform(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_UMaterialExpressionTransform(); \
	public: \
	DECLARE_CLASS(UMaterialExpressionTransform, UMaterialExpression, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(UMaterialExpressionTransform) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h_63_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMaterialExpressionTransform(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMaterialExpressionTransform) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMaterialExpressionTransform); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMaterialExpressionTransform); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMaterialExpressionTransform(UMaterialExpressionTransform&&); \
	NO_API UMaterialExpressionTransform(const UMaterialExpressionTransform&); \
public:


#define Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h_63_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMaterialExpressionTransform(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMaterialExpressionTransform(UMaterialExpressionTransform&&); \
	NO_API UMaterialExpressionTransform(const UMaterialExpressionTransform&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMaterialExpressionTransform); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMaterialExpressionTransform); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMaterialExpressionTransform)


#define Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h_63_PRIVATE_PROPERTY_OFFSET
#define Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h_60_PROLOG
#define Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h_63_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h_63_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h_63_RPC_WRAPPERS \
	Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h_63_INCLASS \
	Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h_63_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h_63_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h_63_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h_63_RPC_WRAPPERS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h_63_INCLASS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h_63_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class MaterialExpressionTransform."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Engine_Source_Runtime_Engine_Classes_Materials_MaterialExpressionTransform_h


#define FOREACH_ENUM_EMATERIALVECTORCOORDTRANSFORM(op) \
	op(TRANSFORM_Tangent) \
	op(TRANSFORM_Local) \
	op(TRANSFORM_World) \
	op(TRANSFORM_View) \
	op(TRANSFORM_Camera) \
	op(TRANSFORM_ParticleWorld) 
#define FOREACH_ENUM_EMATERIALVECTORCOORDTRANSFORMSOURCE(op) \
	op(TRANSFORMSOURCE_Tangent) \
	op(TRANSFORMSOURCE_Local) \
	op(TRANSFORMSOURCE_World) \
	op(TRANSFORMSOURCE_View) \
	op(TRANSFORMSOURCE_Camera) \
	op(TRANSFORMSOURCE_ParticleWorld) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
