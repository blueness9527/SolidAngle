// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UNavArea;
#ifdef ENGINE_NavModifierVolume_generated_h
#error "NavModifierVolume.generated.h already included, missing '#pragma once' in NavModifierVolume.h"
#endif
#define ENGINE_NavModifierVolume_generated_h

#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetAreaClass) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_NewAreaClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetAreaClass(Z_Param_NewAreaClass); \
		P_NATIVE_END; \
	}


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetAreaClass) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_NewAreaClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetAreaClass(Z_Param_NewAreaClass); \
		P_NATIVE_END; \
	}


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h_21_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesANavModifierVolume(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_ANavModifierVolume(); \
	public: \
	DECLARE_CLASS(ANavModifierVolume, AVolume, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Engine"), ENGINE_API) \
	DECLARE_SERIALIZER(ANavModifierVolume) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<ANavModifierVolume*>(this); }


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h_21_INCLASS \
	private: \
	static void StaticRegisterNativesANavModifierVolume(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_ANavModifierVolume(); \
	public: \
	DECLARE_CLASS(ANavModifierVolume, AVolume, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Engine"), ENGINE_API) \
	DECLARE_SERIALIZER(ANavModifierVolume) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<ANavModifierVolume*>(this); }


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ENGINE_API ANavModifierVolume(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANavModifierVolume) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ENGINE_API, ANavModifierVolume); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANavModifierVolume); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ENGINE_API ANavModifierVolume(ANavModifierVolume&&); \
	ENGINE_API ANavModifierVolume(const ANavModifierVolume&); \
public:


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ENGINE_API ANavModifierVolume(ANavModifierVolume&&); \
	ENGINE_API ANavModifierVolume(const ANavModifierVolume&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ENGINE_API, ANavModifierVolume); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANavModifierVolume); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANavModifierVolume)


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h_21_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__AreaClass() { return STRUCT_OFFSET(ANavModifierVolume, AreaClass); }


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h_18_PROLOG
#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h_21_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h_21_RPC_WRAPPERS \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h_21_INCLASS \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h_21_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h_21_INCLASS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavModifierVolume_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
