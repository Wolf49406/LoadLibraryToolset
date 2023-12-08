# LoadLibraryToolset
 Everything you need to play with LoadLibrary injection

## Includes:
- Injector.exe
- Payload.dll
- Target.exe

## How to Build:
- Open LoadLibraryToolset.sln
- Set x32 or x64
- Build everything witn Ctrl+Shift+B

## Customisation:
- Open Injector Project -> Main.cpp
- Set DLLName & ProcName (default is Payload.dll & Target.exe)

## Usage (Default):
- Go to LoadLibraryToolset\Build\\_Platform_\\_Configuration_ (ex: x64\Debug)
- Launch Target.exe
- Launch Injector.exe
- Done!

### Notice:
Injector.exe will look for Payload.dll near itself!
