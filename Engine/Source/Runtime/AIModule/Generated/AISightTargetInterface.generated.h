// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef AIMODULE_AISightTargetInterface_generated_h
#error "AISightTargetInterface.generated.h already included, missing '#pragma once' in AISightTargetInterface.h"
#endif
#define AIMODULE_AISightTargetInterface_generated_h

#define Engine_Source_Runtime_AIModule_Classes_Perception_AISightTargetInterface_h_15_RPC_WRAPPERS
#define Engine_Source_Runtime_AIModule_Classes_Perception_AISightTargetInterface_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define Engine_Source_Runtime_AIModule_Classes_Perception_AISightTargetInterface_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAISightTargetInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAISightTargetInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAISightTargetInterface); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAISightTargetInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAISightTargetInterface(UAISightTargetInterface&&); \
	NO_API UAISightTargetInterface(const UAISightTargetInterface&); \
public:


#define Engine_Source_Runtime_AIModule_Classes_Perception_AISightTargetInterface_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAISightTargetInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAISightTargetInterface(UAISightTargetInterface&&); \
	NO_API UAISightTargetInterface(const UAISightTargetInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAISightTargetInterface); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAISightTargetInterface); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAISightTargetInterface)


#undef GENERATED_UINTERFACE_BODY_COMMON
#define GENERATED_UINTERFACE_BODY_COMMON() \
	private: \
	static void StaticRegisterNativesUAISightTargetInterface(); \
	friend AIMODULE_API class UClass* Z_Construct_UClass_UAISightTargetInterface(); \
public: \
	DECLARE_CLASS(UAISightTargetInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), 0, TEXT("/Script/AIModule"), NO_API) \
	DECLARE_SERIALIZER(UAISightTargetInterface) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Engine_Source_Runtime_AIModule_Classes_Perception_AISightTargetInterface_h_15_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	GENERATED_UINTERFACE_BODY_COMMON() \
	Engine_Source_Runtime_AIModule_Classes_Perception_AISightTargetInterface_h_15_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Engine_Source_Runtime_AIModule_Classes_Perception_AISightTargetInterface_h_15_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	GENERATED_UINTERFACE_BODY_COMMON() \
	Engine_Source_Runtime_AIModule_Classes_Perception_AISightTargetInterface_h_15_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Engine_Source_Runtime_AIModule_Classes_Perception_AISightTargetInterface_h_15_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IAISightTargetInterface() {} \
public: \
	typedef UAISightTargetInterface UClassType; \
	virtual UObject* _getUObject() const = 0;


#define Engine_Source_Runtime_AIModule_Classes_Perception_AISightTargetInterface_h_15_INCLASS_IINTERFACE \
protected: \
	virtual ~IAISightTargetInterface() {} \
public: \
	typedef UAISightTargetInterface UClassType; \
	virtual UObject* _getUObject() const = 0;


#define Engine_Source_Runtime_AIModule_Classes_Perception_AISightTargetInterface_h_12_PROLOG
#define Engine_Source_Runtime_AIModule_Classes_Perception_AISightTargetInterface_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_AIModule_Classes_Perception_AISightTargetInterface_h_15_RPC_WRAPPERS \
	Engine_Source_Runtime_AIModule_Classes_Perception_AISightTargetInterface_h_15_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Engine_Source_Runtime_AIModule_Classes_Perception_AISightTargetInterface_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_AIModule_Classes_Perception_AISightTargetInterface_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Engine_Source_Runtime_AIModule_Classes_Perception_AISightTargetInterface_h_15_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Engine_Source_Runtime_AIModule_Classes_Perception_AISightTargetInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
