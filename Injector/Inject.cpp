#include "Injector.h"

bool Inject(HANDLE hProc, const char* DLLName) {
	LPVOID lpPathAddress = VirtualAllocEx(hProc, nullptr, static_cast<SIZE_T>(lstrlenA(DLLName)) + 1, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	if (!lpPathAddress) {
		printf("[-] VirtualAllocEx error: 0x%X\n", GetLastError());
		system("pause");
		return false;
	}

	DWORD dwWriteResult = WriteProcessMemory(hProc, lpPathAddress, DLLName, static_cast<SIZE_T>(lstrlenA(DLLName)) + 1, nullptr);
	if (!dwWriteResult) {
		printf("[-] WriteProcessMemory error: 0x%X\n", GetLastError());
		system("pause");
		return false;
	}

	HMODULE hModule = GetModuleHandleA("kernel32.dll");
	if (hModule == INVALID_HANDLE_VALUE || hModule == nullptr) {
		printf("[-] GetModuleHandleA(\"kernel32.dll\") error: 0x%X\n", GetLastError());
		system("pause");
		return false;
	}

	FARPROC lpFunctionAddress = GetProcAddress(hModule, "LoadLibraryA");
	if (!lpFunctionAddress) {
		printf("[-] GetProcAddress(\"LoadLibraryA\") error: 0x%X\n", GetLastError());
		system("pause");
		return false;
	}

	HANDLE hThreadCreationResult = CreateRemoteThread(hProc, nullptr, 0, (LPTHREAD_START_ROUTINE)lpFunctionAddress, lpPathAddress, 0, nullptr);
	if (hThreadCreationResult == INVALID_HANDLE_VALUE) {
		printf("[-] CreateRemoteThread error: 0x%X\n", GetLastError());
		system("pause");
		return false;
	}

	return true;
}
