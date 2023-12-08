#include <windows.h>

DWORD WINAPI MainThread(HMODULE hModule) {
	MessageBoxA(NULL, "Payload DLL Injected!", "LoadLibraryToolset", MB_OK);
	FreeLibraryAndExitThread(hModule, 0);

	return TRUE;
};

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, NULL);
	}

	return TRUE;
}
