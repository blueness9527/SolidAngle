// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ENGINE_AutomationTestSettings_generated_h
#error "AutomationTestSettings.generated.h already included, missing '#pragma once' in AutomationTestSettings.h"
#endif
#define ENGINE_AutomationTestSettings_generated_h

#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_342_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FLaunchOnTestSettings(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_325_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FEditorMapPerformanceTestDefinition(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_296_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FBuildPromotionTestSettings(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_274_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FBlueprintEditorPromotionSettings(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_261_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FParticleEditorPromotionSettings(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_238_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FMaterialEditorPromotionSettings(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_221_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FBuildPromotionNewProjectSettings(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_188_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FBuildPromotionOpenAssetSettings(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_135_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FBuildPromotionImportWorkflowSettings(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_118_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FEditorImportWorkflowDefinition(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_93_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FEditorImportExportTestDefinition(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_75_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FImportFactorySettingValues(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_42_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FExternalToolDefinition(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_23_GENERATED_BODY \
	friend ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FOpenTestAsset(); \
	ENGINE_API static class UScriptStruct* StaticStruct();


#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_359_RPC_WRAPPERS
#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_359_RPC_WRAPPERS_NO_PURE_DECLS
#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_359_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUAutomationTestSettings(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_UAutomationTestSettings(); \
	public: \
	DECLARE_CLASS(UAutomationTestSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(UAutomationTestSettings) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	static const TCHAR* StaticConfigName() {return TEXT("Engine");} \



#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_359_INCLASS \
	private: \
	static void StaticRegisterNativesUAutomationTestSettings(); \
	friend ENGINE_API class UClass* Z_Construct_UClass_UAutomationTestSettings(); \
	public: \
	DECLARE_CLASS(UAutomationTestSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(UAutomationTestSettings) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	static const TCHAR* StaticConfigName() {return TEXT("Engine");} \



#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_359_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAutomationTestSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAutomationTestSettings) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAutomationTestSettings); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAutomationTestSettings); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAutomationTestSettings(UAutomationTestSettings&&); \
	NO_API UAutomationTestSettings(const UAutomationTestSettings&); \
public:


#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_359_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAutomationTestSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAutomationTestSettings(UAutomationTestSettings&&); \
	NO_API UAutomationTestSettings(const UAutomationTestSettings&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAutomationTestSettings); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAutomationTestSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAutomationTestSettings)


#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_359_PRIVATE_PROPERTY_OFFSET
#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_356_PROLOG
#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_359_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_359_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_359_RPC_WRAPPERS \
	Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_359_INCLASS \
	Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_359_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_359_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_359_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_359_RPC_WRAPPERS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_359_INCLASS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h_359_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class AutomationTestSettings."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Engine_Source_Runtime_Engine_Classes_Tests_AutomationTestSettings_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
