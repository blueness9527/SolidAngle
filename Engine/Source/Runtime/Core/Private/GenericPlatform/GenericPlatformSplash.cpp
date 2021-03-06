// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "GenericPlatform/GenericPlatformSplash.h"
#include "Containers/SolidAngleString.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"

// Supported file extension for splash image
const TCHAR* SupportedSplashImageExt[] = 
{
	TEXT(".png"),
	TEXT(".jpg"),
	nullptr
};

/**
* Return the filename found (look for PNG, JPG and BMP in that order, try to avoid BMP, use more space...)
*/
YString GetSplashFilename(const YString& ContentDir, const YString& Filename)
{
	int index = 0;
	const YString ImageName = ContentDir / Filename;
	YString Path;

	while (SupportedSplashImageExt[index])
	{
		Path = ImageName + SupportedSplashImageExt[index++];

		if (YPaths::FileExists(Path))
			return Path;
	}

	// if no image was found, we assume it's a BMP (default)
	return ImageName + TEXT(".bmp");
}

/**
* Finds a usable splash pathname for the given filename
*
* @param SplashFilename Name of the desired splash name("Splash")
* @param IconFilename Name of the desired icon name("Splash")
* @param OutPath String containing the path to the file, if this function returns true
* @param OutIconPath String containing the path to the icon, if this function returns true
*
* @return true if a splash screen was found
*/
bool FGenericPlatformSplash::GetSplashPath(const TCHAR* SplashFilename, YString& OutPath, bool& OutIsCustom)
{
	YString Filename = YString(TEXT("Splash/")) + SplashFilename;

	// first look in game's splash directory
	OutPath = GetSplashFilename(YPaths::GameContentDir(), Filename);
	OutIsCustom = true;

	// if this was found, then we're done
	if (IFileManager::Get().FileSize(*OutPath) != -1)
		return true;

	// next look in Engine/Splash
	OutPath = YPaths::ConvertRelativePathToFull(GetSplashFilename(YPaths::EngineContentDir(), Filename));
	OutIsCustom = false;

	// if this was found, then we're done
	if (IFileManager::Get().FileSize(*OutPath) != -1)
		return true;

	// if not found yet, then return failure
	return false;
}

bool FGenericPlatformSplash::GetSplashPath(const TCHAR* SplashFilename, const TCHAR* IconFilename, YString& OutPath, YString& OutIconPath, bool& OutIsCustom)
{
	YString Filename = YString(TEXT("Splash/")) + SplashFilename;
	YString IconName = YString(TEXT("Splash/")) + IconFilename;

	// first look in game's splash directory
	OutPath = YPaths::ConvertRelativePathToFull(GetSplashFilename(YPaths::GameContentDir(), Filename));
	OutIconPath = GetSplashFilename(YPaths::GameContentDir(), IconName);
	OutIsCustom = true;

	// if this was found, then we're done
	if (IFileManager::Get().FileSize(*OutPath) != -1)
		return true;

	// next look in Engine/Splash
	OutPath = YPaths::ConvertRelativePathToFull(GetSplashFilename(YPaths::EngineContentDir(), Filename));
	OutIconPath = GetSplashFilename(YPaths::EngineContentDir(), IconName);
	OutIsCustom = false;

	// if this was found, then we're done
	if (IFileManager::Get().FileSize(*OutPath) != -1)
		return true;

	// if not found yet, then return failure
	return false;
}
