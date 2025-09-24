#include "pch.h"
#include "HookingFunc.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID Ipreversed)
{
	if (DetourIsHelperProcess())
		return TRUE;

	if (dwReason == DLL_PROCESS_ATTACH) 
	{
		DetourRestoreAfterWith();
		InstallHookingFunc();
	}
	else if (dwReason == DLL_PROCESS_DETACH) 
	{	
		UninstallHookingFunc();
	}
	return TRUE;
}

//BOOL WINAPI DllMain(HINSTANCE hinst, DWORD dwReason, LPVOID reserved)
//{
//	if (dwReason == DLL_PROCESS_ATTACH) {
//
//	}
//	else if (dwReason == DLL_PROCESS_DETACH) {
//
//	}
//	return TRUE;
//}
