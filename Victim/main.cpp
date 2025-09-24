#include "pch.h"

int main()
{
	SYSTEMTIME stTime;
	GetLocalTime(&stTime);

	printf("%04d-%02d-%02d %02d:%02d:%02d.%03d\n",
		stTime.wYear, stTime.wMonth, stTime.wDay,
		stTime.wHour, stTime.wMinute, stTime.wSecond, stTime.wSecond);
	Sleep(100 * 1000);

	return 0;
}