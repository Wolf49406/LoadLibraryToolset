# LoadLibraryToolset
 Everything you need to play with LoadLibrary injection

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
(ex: `Injector.exe -proc Explorer.exe -dll Payload.dll`)  
Arguments are case INsensitive!

## Notice:
Injector.exe will look for Payload.dll near itself!
