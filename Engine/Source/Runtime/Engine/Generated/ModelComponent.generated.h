// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ENGINE_ModelComponent_generated_h
#error "ModelComponent.generated.h already included, missing '#pragma once' in ModelComponent.h"
#endif
#define ENGINE_ModelComponent_generated_h

#define Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h_35_RPC_WRAPPERS
#define Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h_35_RPC_WRAPPERS_NO_PURE_DECLS
#define Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h_35_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUModelComponent(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_UModelComponent(); \
	public: \
	DECLARE_CLASS(UModelComponent, UPrimitiveComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Engine"), ENGINE_API) \
	DECLARE_SERIALIZER(UModelComponent) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<UModelComponent*>(this); }


#define Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h_35_INCLASS \
	private: \
	static void StaticRegisterNativesUModelComponent(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_UModelComponent(); \
	public: \
	DECLARE_CLASS(UModelComponent, UPrimitiveComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Engine"), ENGINE_API) \
	DECLARE_SERIALIZER(UModelComponent) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<UModelComponent*>(this); }


#define Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h_35_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ENGINE_API UModelComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UModelComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ENGINE_API, UModelComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UModelComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ENGINE_API UModelComponent(UModelComponent&&); \
	ENGINE_API UModelComponent(const UModelComponent&); \
public:


#define Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h_35_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ENGINE_API UModelComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ENGINE_API UModelComponent(UModelComponent&&); \
	ENGINE_API UModelComponent(const UModelComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ENGINE_API, UModelComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UModelComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UModelComponent)


#define Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h_35_PRIVATE_PROPERTY_OFFSET
#define Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h_32_PROLOG
#define Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h_35_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h_35_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h_35_RPC_WRAPPERS \
	Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h_35_INCLASS \
	Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h_35_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h_35_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h_35_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h_35_RPC_WRAPPERS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h_35_INCLASS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h_35_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class ModelComponent."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Engine_Source_Runtime_Engine_Classes_Components_ModelComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
