#include <windows.h> /*HKEY_CURRENT_USER*/
#include <stdio.h>


void EnumerateRegistryKey(HKEY hKey, const char * subKey) {

	long result;
	HKEY hOpenKey;
	char keyName[256];
	DWORD keyNameSize, index = 0;

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

	printf("Open key : %s\n", subKey);

	while (1) {
		
		keyNameSize = sizeof(keyName);

		/*LSTATUS RegEnumKeyExA(
			[in]                HKEY      hKey,
			[in]                DWORD     dwIndex, 		//the index of the subkey to retrieve
							       		//this parameter should be zero for the first call to the RegEnumKeyEx function
									//and then incremented for subsequent calls
			[out]               LPSTR     lpName,		//(char *)Long Pointer STRing;
			[in, out]           LPDWORD   lpcchName,	//long pointer count of character name
									//contains the number of characters stored in the buffer specified by the lpName
                      			    LPDWORD   lpReserved,	//this parameter is reserved and must be NULL
  			[in, out]           LPSTR     lpClass,		//a pointer to a buffer that receives the user-defined class
									//of the enumerated subkey. this parameter can be NULL
			[in, out, optional] LPDWORD   lpcchClass,	//long pointer count of character of user defined class of registry key name.
									//null if lpClass is NULL
			[out, optional]     PFILETIME lpftLastWriteTime	//a pointer to FILETIME structure that receives the time at which
									//the enumerated subkey was last written. this parameter can be NULL
									//typedef struct _FILETIME {
  									//	DWORD dwLowDateTime;
  										DWORD dwHighDateTime;
									//} FILETIME, * PFILETIME, * LPFILETIME;
		  );
		*/
		result = RegEnumKeyEx(hOpenKey, index, keyName, &keyNameSize, 0, 0, 0, 0);	




	}

}


int main() {
	EnumerateRegistryKey(HKEY_CURRENT_USER, "Software");
}
