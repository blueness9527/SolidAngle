// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreTypes.h"
#include "Containers/Array.h"
#include "Containers/SolidAngleString.h"
#include "Templates/SharedPointer.h"
#include "Delegates/Delegate.h"
#include "Internationalization/Text.h"

#define ENABLE_LOC_TESTING ( UE_BUILD_DEBUG | UE_BUILD_DEVELOPMENT | UE_BUILD_TEST )

#include "Templates/UniqueObj.h"

#define LOC_DEFINE_REGION

class FCulture;
class FICUInternationalization;
class FLegacyInternationalization;

class FInternationalization
{
	friend class FText;

public:
	static CORE_API FInternationalization& Get();

	/** Checks to see that an internationalization instance exists, and has been initialized. Usually you would use Get(), however this may be used to work out whether TearDown() has been called when cleaning up on shutdown. */
	static CORE_API bool IsAvailable();

	static CORE_API void TearDown();

	static CORE_API FText ForUseOnlyByLocMacroAndGraphNodeTextLiterals_CreateText(const TCHAR* InTextLiteral, const TCHAR* InNamespace, const TCHAR* InKey);

	//Set the current culture by name
	CORE_API bool SetCurrentCulture(const YString& Name);

	//@return the current culture
	CORE_API FCultureRef GetCurrentCulture() const
	{
		return CurrentCulture.ToSharedRef();
	}

	//@return culture object by given name, or NULL if not found
	CORE_API FCulturePtr GetCulture(const YString& Name);

	//@return the default culture
	CORE_API TSharedRef< FCulture, ESPMode::ThreadSafe > GetDefaultCulture() const
	{
		return DefaultCulture.ToSharedRef();
	}

	//@return the invariant culture
	CORE_API TSharedRef< FCulture, ESPMode::ThreadSafe > GetInvariantCulture() const
	{
		return InvariantCulture.ToSharedRef();
	}

	CORE_API bool IsInitialized() const { return bIsInitialized; }

	// Load and cache the data needed for every culture we know about (this is usually done per-culture as required)
	CORE_API void LoadAllCultureData();

#if ENABLE_LOC_TESTING
	static CORE_API YString& Leetify(YString& SourceString);
#endif

	CORE_API void GetCultureNames(TArray<YString>& CultureNames) const;

	CORE_API TArray<YString> GetPrioritizedCultureNames(const YString& Name);

	// Given some paths to look at, populate a list of cultures that we have available localization information for. If bIncludeDerivedCultures, include cultures that are derived from those we have localization data for.
	CORE_API void GetCulturesWithAvailableLocalization(const TArray<YString>& InLocalizationPaths, TArray< FCultureRef >& OutAvailableCultures, const bool bIncludeDerivedCultures);

	/** Broadcasts whenever the current culture changes */
	DECLARE_EVENT(FInternationalization, FCultureChangedEvent)
	CORE_API FCultureChangedEvent& OnCultureChanged() { return CultureChangedEvent; }

private:
	FInternationalization();

	void BroadcastCultureChanged() { CultureChangedEvent.Broadcast(); }

	void Initialize();
	void Terminate();

private:
	static FInternationalization* Instance;
	bool bIsInitialized;

	FCultureChangedEvent CultureChangedEvent;

#if UE_ENABLE_ICU
	friend class FICUInternationalization;
	typedef FICUInternationalization FImplementation;
#else
	friend class FLegacyInternationalization;
	typedef FLegacyInternationalization FImplementation;
#endif
	TUniqueObj<FImplementation> Implementation;

	FCulturePtr CurrentCulture;
	FCulturePtr DefaultCulture;
	FCulturePtr InvariantCulture;
};

/** The global namespace that must be defined/undefined to wrap uses of the NS-prefixed macros below */
#undef LOCTEXT_NAMESPACE

/**
* Creates an FText. All parameters must be string literals. All literals will be passed through the localization system.
* The global LOCTEXT_NAMESPACE macro must be first set to a string literal to specify this localization key's namespace.
*/
#define LOCTEXT( InKey, InTextLiteral ) FInternationalization::ForUseOnlyByLocMacroAndGraphNodeTextLiterals_CreateText( TEXT( InTextLiteral ), TEXT(LOCTEXT_NAMESPACE), TEXT( InKey ) )

/**
* Creates an FText. All parameters must be string literals. All literals will be passed through the localization system.
*/
#define NSLOCTEXT( InNamespace, InKey, InTextLiteral ) FInternationalization::ForUseOnlyByLocMacroAndGraphNodeTextLiterals_CreateText( TEXT( InTextLiteral ), TEXT( InNamespace ), TEXT( InKey ) )

#undef LOC_DEFINE_REGION
