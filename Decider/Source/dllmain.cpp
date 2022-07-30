// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#pragma execution_character_set("utf-8")
BOOL SetConsoleColor(WORD wAttributes)//设置控制台文字、背景颜色
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
		return FALSE;

	return SetConsoleTextAttribute(hConsole, wAttributes);
}
DWORD WINAPI ControlThread(LPVOID lpParam)
{
	if (AllocConsole()) {
		freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
		SetConsoleTitleW(L"XXX Menu");

		Log::Msg("Injecting...");
		SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "Status:" << endl;
		cout << "---------------------------------------------------------------" << endl;
		cout << "Cheat Status: Undetected      Version: unknown" << endl;
		cout << "---------------------------------------------------------------" << endl;
		cout << "                                              " << endl;
		cout << "Discord:" << endl;
		cout << "---------------------------------------------------------------" << endl;
		cout << "My Discord: ? "<<endl;
		cout << "---------------------------------------------------------------" << endl;
		cout << "                                              " << endl;
		SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "[INFO] Target Grand Theft Auto V Process Successfully!" << endl;
		cout << "[INFO] Inject Successfully!" << endl;
		SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "---------------------------------------------------------------" << endl;
		cout << "[INFO] Wait for 10s.Press * to open menu." << endl;
		//cout << "[INFO] Free Mod Menu.If u sell the menu,ur mommy will Die soon" << endl;
		SetConsoleCP(CP_UTF8);
		SetConsoleOutputCP(CP_UTF8);
	}

	Hooking::Start((HMODULE)lpParam);
	return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ControlThread, hModule, NULL, NULL);
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		Hooking::Cleanup();
		break;
	}
	return TRUE;
}


