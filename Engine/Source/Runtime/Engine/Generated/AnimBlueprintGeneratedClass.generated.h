// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ENGINE_AnimBlueprintGeneratedClass_generated_h
#error "AnimBlueprintGeneratedClass.generated.h already included, missing '#pragma once' in AnimBlueprintGeneratedClass.h"
#endif
#define ENGINE_AnimBlueprintGeneratedClass_generated_h

#define Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_77_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FAnimBlueprintDebugData(); \
	static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_50_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FAnimationFrameSnapshot(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_28_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FStateMachineDebugData(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_178_RPC_WRAPPERS
#define Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_178_RPC_WRAPPERS_NO_PURE_DECLS
#define Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_178_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUAnimBlueprintGeneratedClass(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_UAnimBlueprintGeneratedClass(); \
	public: \
	DECLARE_CLASS(UAnimBlueprintGeneratedClass, UBlueprintGeneratedClass, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(UAnimBlueprintGeneratedClass) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<UAnimBlueprintGeneratedClass*>(this); }


#define Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_178_INCLASS \
	private: \
	static void StaticRegisterNativesUAnimBlueprintGeneratedClass(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_UAnimBlueprintGeneratedClass(); \
	public: \
	DECLARE_CLASS(UAnimBlueprintGeneratedClass, UBlueprintGeneratedClass, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(UAnimBlueprintGeneratedClass) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<UAnimBlueprintGeneratedClass*>(this); }


#define Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_178_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAnimBlueprintGeneratedClass(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAnimBlueprintGeneratedClass) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAnimBlueprintGeneratedClass); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAnimBlueprintGeneratedClass); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAnimBlueprintGeneratedClass(UAnimBlueprintGeneratedClass&&); \
	NO_API UAnimBlueprintGeneratedClass(const UAnimBlueprintGeneratedClass&); \
public:


#define Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_178_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAnimBlueprintGeneratedClass(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAnimBlueprintGeneratedClass(UAnimBlueprintGeneratedClass&&); \
	NO_API UAnimBlueprintGeneratedClass(const UAnimBlueprintGeneratedClass&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAnimBlueprintGeneratedClass); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAnimBlueprintGeneratedClass); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAnimBlueprintGeneratedClass)


#define Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_178_PRIVATE_PROPERTY_OFFSET
#define Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_175_PROLOG
#define Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_178_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_178_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_178_RPC_WRAPPERS \
	Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_178_INCLASS \
	Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_178_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_178_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_178_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_178_RPC_WRAPPERS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_178_INCLASS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h_178_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class AnimBlueprintGeneratedClass."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Engine_Source_Runtime_Engine_Classes_Animation_AnimBlueprintGeneratedClass_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
