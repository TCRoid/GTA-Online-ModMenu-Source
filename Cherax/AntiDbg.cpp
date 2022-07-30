#include "AntiDbg.h"

const char* BadProcessnameList[] =
{
	"ollydbg.exe",
	"ida.exe",
	"ida64.exe",
	"idag.exe",
	"idag64.exe",
	"idaw.exe",
	"idaw64.exe",
	"idaq.exe",
	"idaq64.exe",
	"idau.exe",
	"idau64.exe",
	"scylla.exe",
	"scylla_x64.exe",
	"scylla_x86.exe",
	"protection_id.exe",
	"x64dbg.exe",
	"x32dbg.exe",
	"windbg.exe",
	"reshacker.exe",
	"ImportREC.exe",
	"IMMUNITYDEBUGGER.EXE",
	"devenv.exe"
};

const char* BadWindowTextList[] =
{
	"OLLYDBG",
	"ida",
	"disassembly",
	"scylla",
	"Debug",
	"[CPU",
	"Immunity",
	"WinDbg",
	"x32dbg",
	"x64dbg"
	"Import reconstructor"
};

const char* BadWindowClassList[] =
{
	"OLLYDBG",
	"Zeta Debugger",
	"Rock Debugger",
	"ObsidianGUI",
	"ID", //Immunity Debugger
	"WinDbgFrameClass", //WinDBG
	"idawindow",
	"tnavbox",
	"idaview",
	"tgrzoom"
};


bool AntiDbg()
{

	static bool timer_reset = true;
	static std::chrono::system_clock::time_point timer_Start;

	if (timer_reset)
	{
		timer_Start = std::chrono::system_clock::now();
		timer_reset = false;
	}

	std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - timer_Start;
	if (elapsed_seconds.count() >= 2.f)
	{
		PROCESSENTRY32 entry;
		entry.dwSize = sizeof(PROCESSENTRY32);

		HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

		if (Process32First(snapshot, &entry))
		{
			while (Process32Next(snapshot, &entry))
			{
				if (entry.th32ProcessID != GetCurrentProcessId())
				{
					if (IsBadProcees(entry))
						return true;
				}
			}
		}

		if (IsWindowBad())
			return true;

		CloseHandle(snapshot);
		return false;

		timer_reset = true;
	}
	return false;
}

bool IsBadProcees(PROCESSENTRY32 entry)
{
	for (const char* str : BadProcessnameList)
	{
		if (!strcmp(entry.szExeFile, str))
		{
			printf("Bad process %s is running\n", str);
			return true;
		}
	}	
	return false;
}

bool IsWindowBad()
{
	for (const char* str : BadWindowTextList)
	{
		if (FindWindow(NULL, str))
		{
			printf("Bad window text %s\n", str);
			return true;
		}
	}

	for (const char* str : BadWindowClassList)
	{
		if (FindWindow(str, NULL))
		{
			printf("Bad window class %s\n", str);
			return true;
		}
	}

	return false;
}