@echo off
set FoundVSInstance=0

rem Change to directory where batch file is located.  We'll restore this later with "popd"
pushd %~dp0

if "%VS140COMNTOOLS%" neq "" (
  set FoundVSInstance=1
  mkdir "%USERPROFILE%\Documents\Visual Studio 2015\Visualizers"
  copy SolidAngle.natvis "%USERPROFILE%\Documents\Visual Studio 2015\Visualizers"
  echo Installed visualizers for Visual Studio 2015
)

if "%VS120COMNTOOLS%" neq "" (
  set FoundVSInstance=1
  mkdir "%USERPROFILE%\Documents\Visual Studio 2013\Visualizers"
  copy SolidAngle.natvis "%USERPROFILE%\Documents\Visual Studio 2013\Visualizers"
  echo Installed visualizers for Visual Studio 2013
)

if "%VS110COMNTOOLS%" neq "" (
  set FoundVSInstance=1
  mkdir "%USERPROFILE%\Documents\Visual Studio 2012\Visualizers"
  copy SolidAngle.natvis "%USERPROFILE%\Documents\Visual Studio 2012\Visualizers"
  echo Installed visualizers for Visual Studio 2012
)

if "%FoundVSInstance%" equ "0" (
  echo ERROR: Could not find a valid version of Visual Studio installed (2012, 2013, 2015)
)

popd
pause
exit