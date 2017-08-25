// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ENGINE_CurveBase_generated_h
#error "CurveBase.generated.h already included, missing '#pragma once' in CurveBase.h"
#endif
#define ENGINE_CurveBase_generated_h

#define Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetValueRange) \
	{ \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_MinValue); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_MaxValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->GetValueRange(Z_Param_Out_MinValue,Z_Param_Out_MaxValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTimeRange) \
	{ \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_MinTime); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_MaxTime); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->GetTimeRange(Z_Param_Out_MinTime,Z_Param_Out_MaxTime); \
		P_NATIVE_END; \
	}


#define Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetValueRange) \
	{ \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_MinValue); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_MaxValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->GetValueRange(Z_Param_Out_MinValue,Z_Param_Out_MaxValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTimeRange) \
	{ \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_MinTime); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_MaxTime); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->GetTimeRange(Z_Param_Out_MinTime,Z_Param_Out_MaxTime); \
		P_NATIVE_END; \
	}


#define Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h_20_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUCurveBase(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_UCurveBase(); \
	public: \
	DECLARE_CLASS(UCurveBase, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), 0, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(UCurveBase) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h_20_INCLASS \
	private: \
	static void StaticRegisterNativesUCurveBase(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_UCurveBase(); \
	public: \
	DECLARE_CLASS(UCurveBase, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), 0, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(UCurveBase) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCurveBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCurveBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCurveBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCurveBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCurveBase(UCurveBase&&); \
	NO_API UCurveBase(const UCurveBase&); \
public:


#define Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCurveBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCurveBase(UCurveBase&&); \
	NO_API UCurveBase(const UCurveBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCurveBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCurveBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCurveBase)


#define Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h_20_PRIVATE_PROPERTY_OFFSET
#define Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h_15_PROLOG
#define Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h_20_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h_20_RPC_WRAPPERS \
	Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h_20_INCLASS \
	Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h_20_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h_20_INCLASS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h_20_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class CurveBase."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Engine_Source_Runtime_Engine_Classes_Curves_CurveBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
