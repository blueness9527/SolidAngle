// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreTypes.h"
#include "Containers/SolidAngleString.h"

class FOutputDeviceConsole;
class FOutputDeviceError;

/**
* Generic implementation for most platforms
*/
struct CORE_API FGenericPlatformOutputDevices
{
	/** Add output devices which can vary depending on platform, configuration, command line parameters. */
	static void							SetupOutputDevices();
	static YString						GetAbsoluteLogFilename();
	static YOutputDevice*				GetLog();

	static YOutputDevice*				GetEventLog()
	{
		return nullptr; // normally only used for dedicated servers
	}

	static FOutputDeviceConsole*		GetLogConsole()
	{
		return nullptr; // normally only used for PC
	}

	static FOutputDeviceError*			GetError();
	static YFeedbackContext*			GetWarn();
};
