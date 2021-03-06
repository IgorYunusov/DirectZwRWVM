#include <Windows.h>
#include <iostream>

using namespace std;

extern "C" NTSTATUS ZwRVM(HANDLE hProcess, void* lpBaseAddress, void* lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesRead = NULL);
extern "C" NTSTATUS ZwWVM(HANDLE hProcess, void* lpBaseAddress, void* lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesRead = NULL);

int main() {
	DWORD pid;
	cout << "PID: ";
	cin >> dec >> pid;
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (!hProcess)
		return EXIT_FAILURE;

	int intBuffer = 555555;
	void* lpBaseAddress = nullptr;
	SIZE_T lpNumberOfBytesRead = 0;
	cout << "Address to read: 0x";
	cin >> hex >> lpBaseAddress;

	NTSTATUS status = ZwRVM(hProcess, lpBaseAddress, &intBuffer, sizeof(int), &lpNumberOfBytesRead);

	cout << "ZwRVM returned " << dec << status << endl;
	cout << "intBuffer = " << dec << intBuffer << endl;
	cout << "lpNumberOfBytesRead = " << lpNumberOfBytesRead << endl;
	system("pause");
    return EXIT_SUCCESS;
}

