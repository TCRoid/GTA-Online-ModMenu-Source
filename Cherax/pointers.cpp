#include "pointers.h"

#include "handle.h"
#include "module.h"
#include "pattern.h"
#include "pattern_batch.h"
#include "range.h"

pointers::pointers()
{


	m_hwnd = FindWindowW(L"grcWindow", nullptr);
	if (!m_hwnd)
		printf("Couldnt find Window.\n");

	if ((m_convert_thread_to_fiber = (functions::convert_thread_to_fiber)GetProcAddress(GetModuleHandleA("kernel32.dll"), "ConvertThreadToFiber")) == NULL)
		printf("Failed GetProcAddress ConvertThreadToFiber\n");
	else
		printf("Found ConvertThreadToFiber @ 0x%.12llX\n", *m_convert_thread_to_fiber);

	if ((m_VirtualQuery = (functions::tVirtualQuery)GetProcAddress(GetModuleHandleA("kernel32.dll"), "VirtualQuery")) == NULL)
		printf("Failed GetProcAddress VirtualQuery\n");
	else
		printf("Found VirtualQuery @ 0x%.12llX\n", *m_VirtualQuery);

	if ((m_VirtualQueryEx = (functions::tVirtualQueryEx)GetProcAddress(GetModuleHandleA("kernel32.dll"), "VirtualQueryEx")) == NULL)
		printf("Failed GetProcAddress VirtualQueryEx\n");
	else
		printf("Found VirtualQueryEx @ 0x%.12llX\n", *m_VirtualQueryEx);

	if ((m_ntqvm = (functions::tNtQueryVirtualMemory)GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtQueryVirtualMemory")) == NULL)
		printf("Failed GetProcAddress NtQueryVirtualMemory\n");
	else
		printf("Found NtQueryVirtualMemory @ 0x%.12llX\n", *m_ntqvm);

	if (!GetModuleInformation(GetCurrentProcess(), g_hmodule, &mi, sizeof(mi)))
		printf("Failed GetModuleInformation\n");

	memory::pattern_batch main_batch;

	main_batch.add("Game state", "83 3D ? ? ? ? ? 75 17 8B 42 20 25", [this](memory::handle ptr) // 
		{
			m_game_state = ptr.add(2).rip().as<eGameState*>();
		});

	main_batch.add("Is session started", "40 38 35 ? ? ? ? 75 0E 4C 8B C3 49 8B D7 49 8B CE", [this](memory::handle ptr)
		{
			m_is_session_started = ptr.add(3).rip().as<bool*>();
		});

	main_batch.add("Ped factory", "48 8B 05 ? ? ? ? 48 8B 48 08 48 85 C9 74 52 8B 81", [this](memory::handle ptr)
		{
			m_ped_factory = ptr.add(3).rip().as<CPedFactory**>();
			m_worldPtr = ptr.add(3).rip().as<uint64_t*>();
		});

	main_batch.add("Native handlers", encryptDecrypt("59 9C 1C ? ? ? ? 59 9A 05 EB F9 ? ? ? ? 59 94 D1 64 1B").c_str(), [this](memory::handle ptr) // 48 8D 0D ? ? ? ? 48 8B 14 FA E8 ? ? ? ? 48 85 C0 75 0A
		{
			m_native_registration_table = ptr.add(3).rip().as<rage::scrNativeRegistrationTable*>();
			m_get_native_handler = ptr.add(12).rip().as<functions::get_native_handler_t>();
		});

	main_batch.add("Fix vectors", "83 79 18 00 48 8B D1 74 4A FF 4A 18 48 63 4A 18 48 8D 41 04 48 8B 4C CA", [this](memory::handle ptr)
		{
			m_fix_vectors = ptr.as<functions::fix_vectors_t>();
		});

	main_batch.add("Script threads", encryptDecrypt("54 22 E7 9A F8 94 D8 A9").c_str(), [this](memory::handle ptr) // 45 33 F6 8B E9 85 C9 B8
		{
			m_script_threads = ptr.sub(4).rip().sub(8).as<decltype(m_script_threads)>();
			m_run_script_threads = ptr.sub(0x1F).as<functions::run_script_threads_t>();
		});

	main_batch.add("Script programs", "44 8B 0D ? ? ? ? 4C 8B 1D ? ? ? ? 48 8B 1D ? ? ? ? 41 83 F8 FF 74 3F 49 63 C0 42 0F B6 0C 18 81 E1", [this](memory::handle ptr)
		{
			m_script_program_table = ptr.add(17).rip().as<decltype(m_script_program_table)>();
		});

	main_batch.add("Swapchain", "48 8B 0D ? ? ? ? 48 8B 01 44 8D 43 01 33 D2 FF 50 40 8B C8", [this](memory::handle ptr)
		{
			m_swapchain = ptr.add(3).rip().as<IDXGISwapChain**>();
		});

	main_batch.add("Events", "48 83 EC 28 E8 ? ? ? ? 48 8B 0D ? ? ? ? 4C 8D 0D ? ? ? ? 4C 8D 05 ? ? ? ? BA 03", [this](memory::handle ptr)
		{
			char* buffer = ptr.as<char*>();

			int i = 0, j = 0, matches = 0, found = 0;
			char* pattern = (char*)"\x4C\x8D\x05";
			while (found != EVENT_COUNT)
			{
				if (buffer[i] == pattern[j])
				{
					if (++matches == 3)
					{
						EventPtr.push_back((void*)(reinterpret_cast<uint64_t>(buffer + i - j) + *reinterpret_cast<int*>(buffer + i + 1) + 7));
						found++;
						j = matches = 0;
					}
					j++;
				}
				else
				{
					matches = j = 0;
				}
				i++;
			}
		});

	main_batch.add("Script globals", "48 8D 15 ? ? ? ? 4C 8B C0 E8 ? ? ? ? 48 85 FF 48 89 1D", [this](memory::handle ptr)
		{
			m_script_globals = ptr.add(3).rip().as<std::int64_t**>();
		});

	main_batch.add("TunablePtr", "4D 89 B4 F7 ? ? ? ? 48 8B 74 24", [this](memory::handle ptr)
		{
			int* tmp = ptr.add(4).as<int*>();
			m_tunablePtr = Memory::get_base() + *tmp;
		});

	main_batch.add("CGameScriptHandlerMgr", "48 8B 0D ? ? ? ? 4C 8B CE E8 ? ? ? ? 48 85 C0 74 05 40 32 FF", [this](memory::handle ptr)
		{
			m_script_handler_mgr = ptr.add(3).rip().as<CGameScriptHandlerMgr**>();
		});

	main_batch.add("detectHooks", encryptDecrypt("91 2C ? ? ? ? ? 1E 94 ? ? ? ? 59 9A 14 ? ? ? ? 59 9A 19").c_str(), [this](memory::handle ptr) // 80 3D ? ? ? ? ? 0F 85 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 08
		{
			m_detectWinApiHooks = ptr.as<functions::detectWinApiHooks>();
		});

	main_batch.add("WorldToScreen", "48 89 5C 24 ? 55 56 57 48 83 EC 70 65 4C 8B 0C 25", [this](memory::handle ptr)
		{
			m_world2Screen = ptr.as<functions::world2screen>();
		});

	main_batch.add("GetLabelText", "75 44 E8 ? ? ? ? 8B", [this](memory::handle ptr)
		{
			m_GetLabelText = ptr.sub(19).as<functions::GetLabelText>();
		});

	main_batch.add("getPlayerName", "40 53 48 83 EC 20 80 3D ? ? ? ? ? 8B D9 74 22", [this](memory::handle ptr)
		{
			m_getPlayerName = ptr.as<functions::getPlayerName>();
		});

	main_batch.add("getNetPlayer", "48 83 EC 28 33 C0 38 05 ? ? ? ? 74 0A", [this](memory::handle ptr)
		{
			m_getNetPlayer = ptr.as<functions::getNetPlayer>();
		});

	main_batch.add("ridHandler", "75 1C E8 ? ? ? ? 48 85", [this](memory::handle ptr)
		{
			m_ridHandler = ptr.sub(11).as<functions::ridHandler>();
		});

	main_batch.add("ridJoiner", "48 89 5C 24 ? 48 89 74 24 ? 55 57 41 54 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B D9 48 8B 0D", [this](memory::handle ptr)
		{
			m_ridJoiner = ptr.as<functions::ridJoiner>();
		});

	main_batch.add("menuptr", "48 8B 0D ? ? ? ? 48 03 D2 48 8B 0C D1", [this](memory::handle ptr)
		{
			int64_t* tmp = ptr.add(3).rip().as<int64_t*>();
			if (*tmp != NULL)
			{
				m_menuPtr = (int64_t*)(*tmp + 0xA0);
			}
		});

	main_batch.add("eventHandler", encryptDecrypt("51 42 59 90 FD ? ? ? ? 55 9A 90").c_str(), [this](memory::handle ptr) // 40 53 48 81 EC ? ? ? ? 44 8B 81
		{
			m_eventHandler = ptr.as<functions::eventHandler>();
		});

	main_batch.add("changeSessionWeather", encryptDecrypt("59 98 4D 35 ? 59 98 7D 35 ? 59 98 65 35 ? 46 59 92 FD 21 51 9B F8").c_str(), [this](memory::handle ptr) // 48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC 30 40 8A E9
		{
			m_changeSessionWeather = ptr.as<functions::changeSessionWeather>();
		});

	main_batch.add("setSessionTime", encryptDecrypt("59 98 4D 35 ? 46 59 92 FD 31 9A E8 59 9A 1C ? ? ? ? 59 9A CB 22 C3").c_str(), [this](memory::handle ptr) // 48 89 5C 24 ? 57 48 83 EC 20 8B F9 48 8B 0D ? ? ? ? 48 8B DA 33 D2
		{
			m_setSessionTime = ptr.as<functions::SetSessionTime>();
		});

	main_batch.add("getEventData", "48 89 5C 24 ? 57 48 83 EC ? 49 8B F8 4C 8D 05", [this](memory::handle ptr)
		{
			m_getEventData = ptr.as<functions::getEventData>();
		});

	main_batch.add("kickVoteHandler", encryptDecrypt("59 98 4D 35 ? 59 98 65 35 ? 46 59 92 FD 31 59 9C 60 21 59 9A D3 58 9A E9 59 9A C7 50 A9").c_str(), [this](memory::handle ptr) // 48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8D 71 30 48 8B C2 49 8B F8 48 8B D6 41 B8
		{
			m_kickVoteHandler = ptr.as<functions::kickVoteHandler>();
		});

	main_batch.add("receivedEventHandler", "66 41 83 F9 ? 0F 83", [this](memory::handle ptr)
		{
			m_receivedEventHandler = ptr.as<functions::receivedEventHandler>();
		});

	main_batch.add("networkIncresementStatEvent", encryptDecrypt("59 98 4D 35 ? 59 98 65 35 ? 44 46 50 44 50 47 50 46 59 9A FD 59 92 FD 71 9A 68 21").c_str(), [this](memory::handle ptr) // 48 89 5C 24 ? 48 89 74 24 ? 55 57 41 55 41 56 41 57 48 8B EC 48 83 EC 60 8B 79 30
		{
			m_networkIncresementStatEvent = ptr.as<functions::networkIncreasementStatEvent>();
		});

	main_batch.add("triggerScriptEvent", "48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 48 89 78 20 41 56 48 81 EC ? ? ? ? 45 8B F0 41 8B F9", [this](memory::handle ptr)
		{
			m_triggerScriptEvent = ptr.as<functions::triggerScriptEvent>();
		});

	main_batch.add("addOwnedExplosion", "48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 4C 89 70 20 55 48 8D 68 B9 48 81 EC ? ? ? ? 0F 29 70 E8 41 8B D8", [this](memory::handle ptr)
		{
			m_addOwnedExplosion = ptr.as<functions::addOwnedExplosion>();
		});

	main_batch.add("ownedExplosionBytePatch", "3B F8 40 0F 94 C7", [this](memory::handle ptr)
		{
			ownedExplosionBypass = ptr.as<PVOID>();
		});

	main_batch.add("blipList", "4C 8D 05 ? ? ? ? 0F B7 C1", [this](memory::handle ptr)
		{
			m_blitList = ptr.add(3).rip().as<CBlipList*>();		
		});

	main_batch.add("replay_interface", "48 8D 0D ? ? ? ? 48 8B D7 E8 ? ? ? ? 48 8D 0D ? ? ? ? 8A D8 E8 ? ? ? ? 84 DB 75 13 48 8D 0D", [this](memory::handle ptr)
		{
			m_replayIntf = ptr.add(3).rip().as<CReplayInterface**>();
		});

	main_batch.add("ptr_to_handle", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 8B 15 ? ? ? ? 48 8B F9 48 83 C1 10 33 DB", [this](memory::handle ptr)
		{
			m_ptr_to_handle = ptr.as<functions::ptrToHandle>();
		});

	main_batch.add("entityPool", "4C 8B 0D ? ? ? ? 44 8B C1 49 8B 41 08", [this](memory::handle ptr)
		{
			m_entityPool = ptr.add(3).rip().as<MemoryPool**>();
		});

	main_batch.add("pedPool", "48 8B 05 ? ? ? ? 41 0F BF C8 0F BF 40 10", [this](memory::handle ptr)
		{
			m_pedPool = ptr.add(3).rip().as<MemoryPool**>();
		});

	main_batch.add("transactionHelper", encryptDecrypt("59 9A 1C ? ? ? ? 50 9B C8").c_str(), [this](memory::handle ptr) // 48 8B 0D ? ? ? ? 41 8A D9
		{
			transHelper = ptr.add(3).rip().as<int64_t*>();
		});

	main_batch.add("transactionPreparer", encryptDecrypt("59 98 4D 35 ? 59 98 7D 35 ? 59 98 65 35 ? 46 59 92 FD 21 92 1B EE").c_str(), [this](memory::handle ptr) // 48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC 30 83 0A FF
		{
			m_transactionPreparer = ptr.as<functions::transactionPreparer>();
		});

	main_batch.add("transactionProcessor", encryptDecrypt("59 98 4D 35 ? 46 59 92 FD 31 59 9A 48 31 54").c_str(), [this](memory::handle ptr) // 48 89 5C 24 ? 57 48 83 EC 20 48 8B 59 20 45
		{
			m_transactionProcessor = ptr.as<functions::transactionProcessor>();
		});

	/*address = FindPattern("\x48\x8B\xC7\xF3\x0F\x10\x0D", "xxxxxxx") - 0x1D;
	address = address + *reinterpret_cast<int*>(address) + 4;
	_gamePlayCameraAddr = reinterpret_cast<UINT64*>(*reinterpret_cast<int*>(address + 3) + address + 7);*/

	main_batch.run(memory::module(nullptr));

	g_pointers = this;
}

pointers::~pointers()
{
	g_pointers = nullptr;
}