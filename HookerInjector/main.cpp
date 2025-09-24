#include "pch.h"

int wmain() {
    WCHAR victimCmd[] = L"D:\\Victim.exe";
    // DLL 경로를 ANSI 문자열로 변경
    const char* dllPath = "D:\\Hooker.dll";

    STARTUPINFOW si{}; si.cb = sizeof(si);
    PROCESS_INFORMATION pi{};

    BOOL ok = DetourCreateProcessWithDllW(
        nullptr, victimCmd, nullptr, nullptr, FALSE,
        CREATE_DEFAULT_ERROR_MODE | CREATE_SUSPENDED,
        nullptr, nullptr, &si, &pi, dllPath, nullptr);

    if (!ok) {
        DWORD e = GetLastError();
        std::printf("DetourCreateProcessWithDllW failed: %lu\n", e);
        return 1;
    }
    ResumeThread(pi.hThread);
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hThread); CloseHandle(pi.hProcess);
    return 0;
}