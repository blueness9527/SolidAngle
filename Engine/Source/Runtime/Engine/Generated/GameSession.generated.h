// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ENGINE_GameSession_generated_h
#error "GameSession.generated.h already included, missing '#pragma once' in GameSession.h"
#endif
#define ENGINE_GameSession_generated_h

#define Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h_29_RPC_WRAPPERS
#define Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h_29_RPC_WRAPPERS_NO_PURE_DECLS
#define Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h_29_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAGameSession(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_AGameSession(); \
	public: \
	DECLARE_CLASS(AGameSession, AInfo, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(AGameSession) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h_29_INCLASS \
	private: \
	static void StaticRegisterNativesAGameSession(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_AGameSession(); \
	public: \
	DECLARE_CLASS(AGameSession, AInfo, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(AGameSession) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h_29_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGameSession(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGameSession) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameSession); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameSession); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameSession(AGameSession&&); \
	NO_API AGameSession(const AGameSession&); \
public:


#define Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h_29_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGameSession(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameSession(AGameSession&&); \
	NO_API AGameSession(const AGameSession&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameSession); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameSession); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGameSession)


#define Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h_29_PRIVATE_PROPERTY_OFFSET
#define Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h_26_PROLOG
#define Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h_29_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h_29_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h_29_RPC_WRAPPERS \
	Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h_29_INCLASS \
	Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h_29_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h_29_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h_29_INCLASS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h_29_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class GameSession."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Engine_Source_Runtime_Engine_Classes_GameFramework_GameSession_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS