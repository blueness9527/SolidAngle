// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ENGINE_GameViewportClient_generated_h
#error "GameViewportClient.generated.h already included, missing '#pragma once' in GameViewportClient.h"
#endif
#define ENGINE_GameViewportClient_generated_h

#define Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h_63_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetConsoleTarget) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_PlayerIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetConsoleTarget(Z_Param_PlayerIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execShowTitleSafeArea) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ShowTitleSafeArea(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSSSwapControllers) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SSSwapControllers(); \
		P_NATIVE_END; \
	}


#define Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h_63_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetConsoleTarget) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_PlayerIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetConsoleTarget(Z_Param_PlayerIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execShowTitleSafeArea) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ShowTitleSafeArea(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSSSwapControllers) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SSSwapControllers(); \
		P_NATIVE_END; \
	}


#define Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h_63_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUGameViewportClient(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_UGameViewportClient(); \
	public: \
	DECLARE_CLASS(UGameViewportClient, UScriptViewportClient, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(UGameViewportClient) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	DECLARE_WITHIN(UEngine) \
	static const TCHAR* StaticConfigName() {return TEXT("Engine");} \



#define Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h_63_INCLASS \
	private: \
	static void StaticRegisterNativesUGameViewportClient(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_UGameViewportClient(); \
	public: \
	DECLARE_CLASS(UGameViewportClient, UScriptViewportClient, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(UGameViewportClient) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	DECLARE_WITHIN(UEngine) \
	static const TCHAR* StaticConfigName() {return TEXT("Engine");} \



#define Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h_63_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameViewportClient(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameViewportClient) \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameViewportClient); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameViewportClient(UGameViewportClient&&); \
	NO_API UGameViewportClient(const UGameViewportClient&); \
public:


#define Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h_63_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameViewportClient(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameViewportClient(UGameViewportClient&&); \
	NO_API UGameViewportClient(const UGameViewportClient&); \
public: \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameViewportClient); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameViewportClient)


#define Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h_63_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__World() { return STRUCT_OFFSET(UGameViewportClient, World); } \
	FORCEINLINE static uint32 __PPO__GameInstance() { return STRUCT_OFFSET(UGameViewportClient, GameInstance); }


#define Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h_60_PROLOG
#define Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h_63_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h_63_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h_63_RPC_WRAPPERS \
	Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h_63_INCLASS \
	Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h_63_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h_63_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h_63_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h_63_RPC_WRAPPERS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h_63_INCLASS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h_63_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class GameViewportClient."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Engine_Source_Runtime_Engine_Classes_Engine_GameViewportClient_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
