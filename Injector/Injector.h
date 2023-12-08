#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <TlHelp32.h>
#include <comdef.h>

int GetPIDByName(const char* ProcName);
HANDLE OpenProc(const char* ProcName);
bool Inject(HANDLE hProc, const char* DLLName);
