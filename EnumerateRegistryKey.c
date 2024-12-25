#include <windows.h>
#include <stdio.h>

void EnumerateRegistryKey(HKEY hKey, const char *subKey) {
    HKEY hOpenKey;
    LONG result;
    DWORD index = 0;
    char keyName[256];
    char valueName[256];
    BYTE data[1024];
    DWORD keyNameSize, valueNameSize, dataSize;
    DWORD type;

    // Open the specified registry key
    result = RegOpenKeyEx(hKey, subKey, 0, KEY_READ, &hOpenKey);
    if (result != ERROR_SUCCESS) {
        printf("Failed to open registry key: %ld\n", result);
        return;
    }

    printf("Opened registry key: %s\n", subKey);

    // Enumerate subkeys
    while (1) {
        keyNameSize = sizeof(keyName);
        result = RegEnumKeyEx(hOpenKey, index, keyName, &keyNameSize, NULL, NULL, NULL, NULL);
        if (result == ERROR_NO_MORE_ITEMS) {
            break;
        } else if (result == ERROR_SUCCESS) {
            printf("Subkey[%d]: %s\n", index, keyName);
        } else {
            printf("Error enumerating subkeys: %ld\n", result);
            break;
        }
        index++;
    }

    // Enumerate values
    index = 0;
    while (1) {
        valueNameSize = sizeof(valueName);
        dataSize = sizeof(data);
        result = RegEnumValue(hOpenKey, index, valueName, &valueNameSize, NULL, &type, data, &dataSize);
        if (result == ERROR_NO_MORE_ITEMS) {
            break;
        } else if (result == ERROR_SUCCESS) {
            printf("Value[%d]: Name='%s', DataSize=%lu, Type=%lu\n", index, valueName, dataSize, type);
        } else {
            printf("Error enumerating values: %ld\n", result);
            break;
        }
        index++;
    }

    // Close the registry key
    RegCloseKey(hOpenKey);
}

int main() {
    // Example: Scan HKEY_CURRENT_USER\Software
    EnumerateRegistryKey(HKEY_CURRENT_USER, "Software");

    return 0;
}

