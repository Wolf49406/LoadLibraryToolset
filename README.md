# LoadLibraryToolset
 Everything you need to play with LoadLibrary injection

 [![MSBuild](https://github.com/Wolf49406/LoadLibraryToolset/actions/workflows/msbuild.yml/badge.svg?branch=main)](https://github.com/Wolf49406/LoadLibraryToolset/actions/workflows/msbuild.yml)

## Includes:
- Injector.exe
- Payload.dll
- Target.exe

## How to Build:
- Open LoadLibraryToolset.sln
- Set x32 or x64
- Set `ProcName` & `DLLName` in `Injector -> Main.cpp` (default is `Target.exe` & `Payload.dll`)
- Build everything witn Ctrl+Shift+B

## Usage:
- Go to LoadLibraryToolset\Build\\`Platform`\\`Configuration` (ex: x64\Debug)
- Launch Target.exe
- Launch Injector.exe
- Done!

## Arguments:
You can set `ProcName` and `DLLName` with `-proc` and `-dll` arguments  
(ex: `Injector.exe -proc explorer.exe -dll Payload.dll`)  
Arguments are case **sensitive**!

## Notice:
Injector.exe will look for Payload.dll near itself!
