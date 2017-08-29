// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ESlateVisibility : uint8;
#ifdef UMG_VisibilityBinding_generated_h
#error "VisibilityBinding.generated.h already included, missing '#pragma once' in VisibilityBinding.h"
#endif
#define UMG_VisibilityBinding_generated_h

#define Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetValue) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ESlateVisibility*)Z_Param__Result=this->GetValue(); \
		P_NATIVE_END; \
	}


#define Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetValue) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ESlateVisibility*)Z_Param__Result=this->GetValue(); \
		P_NATIVE_END; \
	}


#define Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h_17_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUVisibilityBinding(); \
	friend UMG_API class UClass* Z_Construct_UClass_UVisibilityBinding(); \
	public: \
	DECLARE_CLASS(UVisibilityBinding, UPropertyBinding, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/UMG"), NO_API) \
	DECLARE_SERIALIZER(UVisibilityBinding) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h_17_INCLASS \
	private: \
	static void StaticRegisterNativesUVisibilityBinding(); \
	friend UMG_API class UClass* Z_Construct_UClass_UVisibilityBinding(); \
	public: \
	DECLARE_CLASS(UVisibilityBinding, UPropertyBinding, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/UMG"), NO_API) \
	DECLARE_SERIALIZER(UVisibilityBinding) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVisibilityBinding(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVisibilityBinding) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVisibilityBinding); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVisibilityBinding); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVisibilityBinding(UVisibilityBinding&&); \
	NO_API UVisibilityBinding(const UVisibilityBinding&); \
public:


#define Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVisibilityBinding(UVisibilityBinding&&); \
	NO_API UVisibilityBinding(const UVisibilityBinding&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVisibilityBinding); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVisibilityBinding); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UVisibilityBinding)


#define Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h_17_PRIVATE_PROPERTY_OFFSET
#define Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h_14_PROLOG
#define Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h_17_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h_17_RPC_WRAPPERS \
	Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h_17_INCLASS \
	Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h_17_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h_17_INCLASS_NO_PURE_DECLS \
	Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Engine_Source_Runtime_UMG_Public_Binding_VisibilityBinding_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS