/*windows.h contain declaration of typedef HANDLE, HWND.*/
#include <windows.h>
#include <stdio.h>


int main() {

	/*Handle to Registry Key
	typedef HANDLE HKEY;
	typedef PVOID HANDLE;
	typedef void * PVOID;

	open registry root key (e.g., HKEY_LOCAL_MACHINE)
	*/
	HKEY hRootKey = HKEY_LOCAL_MACHINE, hKey;
	char * keyToScan;

	printf("enter registry to scan (e.g : software\\microsoft) : ");
	scanf("%s", keyToScan);

	/*LSTATUS RegOpenKeyExA(
		[in]           HKEY   hKey,
		[in, optional] LPCSTR lpSubKey,
		[in]           DWORD  ulOptions,
		[in]           REGSAM samDesired,
		[out]          PHKEY  phkResult
	);

	LONG STATUS
	typedef const char * LPCSTR;
	REGistry Security Access Mask
	Pointer Handle KEY
	*/
	if (RegOpenKeyEx(hRootKey, keyToScan, 0, KEY_READ, &hKey) != ERROR_SUCCESS) {

		printf("Error opening registry key.\n");
		return 1;

	}

}
