// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreTypes.h"
#include "Misc/OutputDeviceError.h"

class YOutputDeviceAnsiError : public YOutputDeviceError
{
public:
	/** Constructor, initializing member variables */
	YOutputDeviceAnsiError();

	/**
	* Serializes the passed in data unless the current event is suppressed.
	*
	* @param	Data	Text to log
	* @param	Event	Event name used for suppression purposes
	*/
	virtual void Serialize(const TCHAR* Msg, ELogVerbosity::Type Verbosity, const class YName& Category) override;

	virtual bool CanBeUsedOnAnyThread() const override
	{
		return true;
	}

	/**
	* Error handling function that is being called from within the system wide global
	* error handler, e.g. using structured exception handling on the PC.
	*/
	void HandleError() override;

private:

	int32		ErrorPos;
};

