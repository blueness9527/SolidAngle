// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ENGINE_NavigationTestingActor_generated_h
#error "NavigationTestingActor.generated.h already included, missing '#pragma once' in NavigationTestingActor.h"
#endif
#define ENGINE_NavigationTestingActor_generated_h

#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h_45_RPC_WRAPPERS
#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h_45_RPC_WRAPPERS_NO_PURE_DECLS
#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h_45_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesANavigationTestingActor(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_ANavigationTestingActor(); \
	public: \
	DECLARE_CLASS(ANavigationTestingActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(ANavigationTestingActor) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<ANavigationTestingActor*>(this); }


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h_45_INCLASS \
	private: \
	static void StaticRegisterNativesANavigationTestingActor(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_ANavigationTestingActor(); \
	public: \
	DECLARE_CLASS(ANavigationTestingActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(ANavigationTestingActor) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<ANavigationTestingActor*>(this); }


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h_45_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ANavigationTestingActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANavigationTestingActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANavigationTestingActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANavigationTestingActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANavigationTestingActor(ANavigationTestingActor&&); \
	NO_API ANavigationTestingActor(const ANavigationTestingActor&); \
public:


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h_45_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ANavigationTestingActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANavigationTestingActor(ANavigationTestingActor&&); \
	NO_API ANavigationTestingActor(const ANavigationTestingActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANavigationTestingActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANavigationTestingActor); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANavigationTestingActor)


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h_45_PRIVATE_PROPERTY_OFFSET
#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h_42_PROLOG
#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h_45_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h_45_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h_45_RPC_WRAPPERS \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h_45_INCLASS \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h_45_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h_45_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h_45_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h_45_INCLASS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h_45_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class NavigationTestingActor."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Engine_Source_Runtime_Engine_Classes_AI_Navigation_NavigationTestingActor_h


#define FOREACH_ENUM_ENAVCOSTDISPLAY(op) \
	op(ENavCostDisplay::TotalCost) \
	op(ENavCostDisplay::HeuristicOnly) \
	op(ENavCostDisplay::RealCostOnly) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
