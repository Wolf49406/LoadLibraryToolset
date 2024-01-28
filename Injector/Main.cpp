#include "Injector.h"

const char* ProcName = "Target.exe";
const char* DLLName = "Payload.dll";

int main(int argc, char* argv[]) {
	if (argc == 5) {
		for (int i = 0; i < argc; i++) {
			if (!strcmp(argv[i], "-proc")) {
				ProcName = argv[i + 1];
				continue;
			}
			if (!strcmp(argv[i], "-dll")) {
				DLLName = argv[i + 1];
				continue;
			}
		}
	}

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
