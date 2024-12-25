#include <windows.h> /*HKEY_CURRENT_USER*/
#include <stdio.h>


void EnumerateRegistryKey(HKEY hKey, const char * subKey) {

	long result;
	HKEY hOpenKey;

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
	result = RegOpenKeyEx(hKey, subKey, 0, KEY_READ, &hOpenKey);

	if (result != ERROR_SUCCESS) {
		printf("Failed to open registry key ! %ld\n", result);
	}



}


int main() {

	EnumerateRegistryKey(HKEY_CURRENT_USER, "Software");


}
