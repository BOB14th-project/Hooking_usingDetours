#include "pch.h"
#include "HookingFunc.h"
#include "Process.h"

void InstallHookingFunc(void)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	InstallProcessHooks();
	DetourTransactionCommit();
}

void UninstallHookingFunc(void)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	UninstallProcessHooks();
	DetourTransactionCommit();
}