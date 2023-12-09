#include "Injector.h"

const char* DLLName = "Payload.dll";
const char* ProcName = "Target.exe";

int main() {
	std::filesystem::path DLLAbsolutePath = std::filesystem::absolute(DLLName);

	if (!std::filesystem::exists(DLLAbsolutePath)) {
		printf("[-] Error: Can't find %s\n", DLLName);
		system("pause");
		return 0;
	}

	HANDLE hProc = OpenProc(ProcName);
	if (!hProc)
		return 0;

	printf("[+] %s Handle: %p\n", ProcName, hProc);

	if (!Inject(hProc, DLLAbsolutePath.string().c_str())) {
		CloseHandle(hProc);
		return 0;
	}

	printf("[+] Injected!\n");

	CloseHandle(hProc);
	system("pause");

	return 0;
}
