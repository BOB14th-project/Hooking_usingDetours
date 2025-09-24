#include "Process.h"
#include "pch.h"

// � �Լ��� ��ŷ���� ����
static VOID(WINAPI* True_Sleep)(DWORD dwMilliseconds) = Sleep;
static VOID(WINAPI* True_GetLocalTime) (_Out_ LPSYSTEMTIME lpSystemTime) = GetLocalTime;

// ��ŷ �Լ��� ����(��� �Լ��� ������ f12�� ����)
static VOID WINAPI Hooked_Sleep(DWORD dwMilliseconds)
{
	//True_Sleep(dwMilliseconds);
	std::printf("Let's say sleep.... %u\n", dwMilliseconds);
}

static VOID WINAPI Hooked_GetLocalTime(_Out_ LPSYSTEMTIME lpSystemTime)
{
	std::memset(lpSystemTime, 0, sizeof(SYSTEMTIME));
}

void InstallProcessHooks()
{
	DetourAttach(&(PVOID&)True_Sleep, Hooked_Sleep);
	DetourAttach(&(PVOID&)True_GetLocalTime, Hooked_GetLocalTime);
}

void UninstallProcessHooks()
{
	DetourDetach(&(PVOID&)True_Sleep, Hooked_Sleep);
	DetourDetach(&(PVOID&)True_GetLocalTime, Hooked_GetLocalTime);
}