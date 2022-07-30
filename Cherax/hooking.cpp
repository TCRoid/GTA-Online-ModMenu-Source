#include "hooking.h"
#include "D3DHooking.h"
#include "pointers.h"
#include "script_mgr.h"
#include "gta_util.h"
#include "nativeFuncs.h"

hooking::hooking() :
	m_swapchain_hook(*g_pointers->m_swapchain, 19)
	//m_detectWinApiHooks_hook("WinAPI hook",g_pointers->m_detectWinApiHooks, &g_hooking->hk_detectWinApiHooks),
	//m_ntqvm_hook("NTQVM hook", g_pointers->m_ntqvm, &g_hooking->hk_ntqvm)
{
	g_hooking = this;

	printf("Creating hooks\n");

	//MH_CreateHook(g_pointers->m_detectWinApiHooks, g_hooking->hk_detectWinApiHooks,(LPVOID*)&o_detectWinApiHooks);
	//MH_EnableHook(g_pointers->m_detectWinApiHooks);
	//MH_CreateHook(g_pointers->m_ntqvm, g_hooking->hk_ntqvm, (LPVOID*)&o_ntqvm);
	//MH_EnableHook(g_pointers->m_ntqvm);
	//MH_CreateHook(g_pointers->m_VirtualQuery, g_hooking->hk_VirtualQuery, (LPVOID*)&o_VirtualQuery);
	//MH_CreateHook(g_pointers->m_VirtualQueryEx, g_hooking->hk_VirtualQueryEx, (LPVOID*)&o_VirtualQueryEx);


	MH_CreateHook(g_pointers->m_convert_thread_to_fiber, g_hooking->hk_convert_thread_to_fiber, (LPVOID*)&o_convert_thread_to_fiber);
	MH_CreateHook(g_pointers->m_run_script_threads, g_hooking->hk_run_script_threads, (LPVOID*)&o_run_script_threads);

	MH_CreateHook(g_pointers->m_eventHandler, g_hooking->hk_eventHandler, (LPVOID*)&o_eventHandler);
	MH_CreateHook(g_pointers->m_changeSessionWeather, g_hooking->hk_changeSessionWeather, (LPVOID*)&o_changeSessionWeather);
	MH_CreateHook(g_pointers->m_getEventData, g_hooking->hk_getEventData, (LPVOID*)&o_getEventData);
	MH_CreateHook(g_pointers->m_receivedEventHandler, g_hooking->hk_receivedEventHandler, (LPVOID*)&o_receivedEventHandler);
	MH_CreateHook(g_pointers->m_networkIncresementStatEvent, g_hooking->hk_networkIncreasementStatEvent, (LPVOID*)&o_networkIncreasementStatEvent);
	MH_CreateHook(g_pointers->m_GetLabelText, g_hooking->hk_GetLabelText, (LPVOID*)&o_GetLabelText);
	MH_CreateHook(g_pointers->m_ridHandler, g_hooking->hk_ridHandler, (LPVOID*)&o_ridHandler);
	MH_CreateHook(g_pointers->m_ridJoiner, g_hooking->hk_ridJoiner, (LPVOID*)&o_ridJoiner);

	m_swapchain_hook.hook(8, &g_renderer->hkPresent);
	m_swapchain_hook.hook(13, &g_renderer->hkResizebuffers);

	enable();
}

hooking::~hooking()
{
	if (m_enabled)
		disable();

	MH_Uninitialize();
	g_hooking = nullptr;
}

void hooking::enable()
{
	printf("Enabling hooks\n");

	//m_detectWinApiHooks_hook.enable();
	//m_ntqvm_hook.enable();
	//MH_EnableHook(g_pointers->m_VirtualQuery);
	//MH_EnableHook(g_pointers->m_VirtualQueryEx);


	MH_EnableHook(g_pointers->m_convert_thread_to_fiber);
	MH_EnableHook(g_pointers->m_run_script_threads);

	MH_EnableHook(g_pointers->m_eventHandler);
	MH_EnableHook(g_pointers->m_getEventData);
	MH_EnableHook(g_pointers->m_changeSessionWeather);
	MH_EnableHook(g_pointers->m_receivedEventHandler);
	MH_EnableHook(g_pointers->m_networkIncresementStatEvent);
	MH_EnableHook(g_pointers->m_GetLabelText);
	MH_EnableHook(g_pointers->m_ridHandler);
	MH_EnableHook(g_pointers->m_ridJoiner);

	m_swapchain_hook.enable();
	g_renderer->oWndproc = reinterpret_cast<WNDPROC>(SetWindowLongPtrW(g_pointers->m_hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&g_renderer->wndproc)));

	m_enabled = true;
}

void hooking::disable()
{
	m_enabled = false;

	SetWindowLongPtrW(g_pointers->m_hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(g_renderer->oWndproc));
	m_swapchain_hook.disable();

	if (m_main_persistent_hook)
	{
		m_main_persistent_hook->disable();
	}

	if (m_script_handler_mgr_hook)
	{
		m_script_handler_mgr_hook->disable();
	}

	MH_DisableHook(g_pointers->m_eventHandler);
	MH_DisableHook(g_pointers->m_getEventData);
	MH_DisableHook(g_pointers->m_changeSessionWeather);
	MH_DisableHook(g_pointers->m_receivedEventHandler);
	MH_DisableHook(g_pointers->m_networkIncresementStatEvent);
	MH_DisableHook(g_pointers->m_GetLabelText);
	MH_DisableHook(g_pointers->m_ridHandler);
	MH_DisableHook(g_pointers->m_ridJoiner);

	MH_RemoveHook(g_pointers->m_eventHandler);
	MH_RemoveHook(g_pointers->m_getEventData);
	MH_RemoveHook(g_pointers->m_changeSessionWeather);
	MH_RemoveHook(g_pointers->m_receivedEventHandler);
	MH_RemoveHook(g_pointers->m_networkIncresementStatEvent);
	MH_RemoveHook(g_pointers->m_GetLabelText);
	MH_RemoveHook(g_pointers->m_ridHandler);
	MH_RemoveHook(g_pointers->m_ridJoiner);

	MH_DisableHook(g_pointers->m_run_script_threads);
	MH_RemoveHook(g_pointers->m_run_script_threads);

	MH_DisableHook(g_pointers->m_convert_thread_to_fiber);
	MH_RemoveHook(g_pointers->m_convert_thread_to_fiber);

	//MH_DisableHook(g_pointers->m_ntqvm);
	//MH_RemoveHook(g_pointers->m_ntqvm);
	//MH_DisableHook(g_pointers->m_VirtualQuery);
	//MH_RemoveHook(g_pointers->m_VirtualQuery);
	//MH_DisableHook(g_pointers->m_VirtualQueryEx);
	//MH_RemoveHook(g_pointers->m_VirtualQueryEx);

	//MH_DisableHook(g_pointers->m_detectWinApiHooks);
	//MH_RemoveHook(g_pointers->m_detectWinApiHooks);

	//m_ntqvm_hook.disable();
	//m_detectWinApiHooks_hook.disable();
}


void hooking::ensure_dynamic_hooks()
{
	/*if (!m_script_handler_mgr_hook)
	{
		if (auto scripthandlermgr = *g_pointers->m_script_handler_mgr)
		{
			printf("Dynamically hooking script_handler_mgr @ 0x%.12llX\n", scripthandlermgr);
			m_script_handler_mgr_hook = std::make_unique<vmt_hook>(scripthandlermgr, 16);
			m_script_handler_mgr_hook->hook(12, &hooking::hk_on_player_join);
			m_script_handler_mgr_hook->hook(13, &hooking::hk_on_player_left);
			m_main_persistent_hook->enable();
		}
	}
*/

	if (!m_main_persistent_hook)
	{
		if (auto main_persistent = gta_util::find_script_thread(RAGE_JOAAT("main_persistent")))
		{
			printf("Dynamically hooking main persistent_script_handler @ 0x%.12llX\n", main_persistent->m_handler);
			m_main_persistent_hook = std::make_unique<vmt_hook>(main_persistent->m_handler, 20);
			m_main_persistent_hook->hook(0, &hooking::hk_main_persistent_dtor);
			m_main_persistent_hook->hook(6, &hooking::hk_main_persistent_is_networked);
			m_main_persistent_hook->enable();
		}
	}	
}

void** hooking::IATfind(const char* function, HMODULE module)
{
	int ip = 0;
	if (module == 0)
		module = GetModuleHandle(0);
	PIMAGE_DOS_HEADER pImgDosHeaders = (PIMAGE_DOS_HEADER)module;
	PIMAGE_NT_HEADERS pImgNTHeaders = (PIMAGE_NT_HEADERS)((LPBYTE)pImgDosHeaders + pImgDosHeaders->e_lfanew);
	PIMAGE_IMPORT_DESCRIPTOR pImgImportDesc = (PIMAGE_IMPORT_DESCRIPTOR)((LPBYTE)pImgDosHeaders + pImgNTHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
	int size = (int)((LPBYTE)pImgDosHeaders + pImgNTHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size);

	if (pImgDosHeaders->e_magic != IMAGE_DOS_SIGNATURE)
		printf("No valid DOS signature\n");

	for (IMAGE_IMPORT_DESCRIPTOR* iid = pImgImportDesc; iid->Name != NULL; iid++) {
		for (int funcIdx = 0; *(funcIdx + (LPVOID*)(iid->FirstThunk + (SIZE_T)module)) != NULL; funcIdx++) {
			char* modFuncName = (char*)(*(funcIdx + (SIZE_T*)(iid->OriginalFirstThunk + (SIZE_T)module)) + (SIZE_T)module + 2);
			if (!_stricmp(function, modFuncName))
			{
				printf("Found %s", function);
				return funcIdx + (LPVOID*)(iid->FirstThunk + (SIZE_T)module);
			}			
		}
	}
	return 0;
}


int64_t hooking::hk_detectWinApiHooks()
{
	return NULL;
}


#define STATUS_ACCESS_DENIED 0xC0000022
#define STATUS_INVALID_PARAMETER 0xC000000D
NTSTATUS hooking::hk_ntqvm(HANDLE ProcessHandle, PVOID BaseAddress, MEMORY_INFORMATION_CLASS MemoryInformationClass, PVOID Buffer, SIZE_T Length, PSIZE_T ResultLength)
{
	//printf("called\n");
	//return g_hooking->m_ntqvm_hook.get_original<decltype(&hk_ntqvm)>()(ProcessHandle, BaseAddress, MemoryInformationClass, Buffer, Length, ResultLength);
	/*	uintptr_t baseScan = (uintptr_t)BaseAddress;
	uintptr_t moduleBase = (uintptr_t)g_pointers->mi.lpBaseOfDll;
	uintptr_t moduleEnd = moduleBase + g_pointers->mi.SizeOfImage;

	printf("ntqvm called\n");

	if (baseScan >= moduleBase && baseScan <= moduleEnd)
	{
		printf("Scanning prevented @ 0x%.12llX\n", baseScan);
		return STATUS_ACCESS_DENIED;
	}

	NTSTATUS res;
	try
	{
		res = g_hooking->m_ntqvm_hook.get_original<decltype(&hk_ntqvm)>()(ProcessHandle, BaseAddress, MemoryInformationClass, Buffer, Length, ResultLength);
	}
	catch (...)
	{
		printf("failed");
		return STATUS_INVALID_PARAMETER;
	}
	return res;*/

	return g_hooking->o_ntqvm(ProcessHandle, BaseAddress, MemoryInformationClass, Buffer, Length, ResultLength);
}


SIZE_T hooking::hk_VirtualQuery(LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength)
{
	uint64_t baseScan = (uint64_t)lpAddress;
	uint64_t moduleBase = (uintptr_t)g_pointers->mi.lpBaseOfDll;
	uint64_t moduleEnd = moduleBase + g_pointers->mi.SizeOfImage;

	printf("hk_VirtualQuery called\n");

	if (baseScan >= moduleBase && baseScan <= moduleEnd)
	{
		printf("Scanning prevented @ 0x%.12llX\n", baseScan);
		return 0;
	}
	baseScan += dwLength;
	if (baseScan >= moduleBase && baseScan <= moduleEnd)
	{
		printf("Scanning prevented @ 0x%.12llX\n", baseScan);
		return 0;
	}
	return g_hooking->o_VirtualQuery(lpAddress, lpBuffer, dwLength);
}

SIZE_T hooking::hk_VirtualQueryEx(HANDLE hProcess, LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength)
{
	uint64_t baseScan = (uint64_t)lpAddress;
	uint64_t moduleBase = (uintptr_t)g_pointers->mi.lpBaseOfDll;
	uint64_t moduleEnd = moduleBase + g_pointers->mi.SizeOfImage;

	printf("hk_VirtualQueryEx called\n");

	if (baseScan >= moduleBase && baseScan <= moduleEnd)
	{
		printf("Scanning prevented @ 0x%.12llX\n", baseScan);
		return 0;
	}
	baseScan += dwLength;
	if (baseScan >= moduleBase && baseScan <= moduleEnd)
	{
		printf("Scanning prevented @ 0x%.12llX\n", baseScan);
		return 0;
	}
	return g_hooking->o_VirtualQueryEx(hProcess, lpAddress, lpBuffer, dwLength);
}


void hooking::hk_script_handler_mgr_dtor(CGameScriptHandlerMgr* this_, bool free_memory)
{
	auto og_func = g_hooking->m_script_handler_mgr_hook->get_original<decltype(&hk_script_handler_mgr_dtor)>(0);
	g_hooking->m_script_handler_mgr_hook->disable();
	g_hooking->m_script_handler_mgr_hook.reset();
	return og_func(this_, free_memory);
}

void hooking::hk_on_player_join(CGameScriptHandlerMgr* this_, rage::netPlayer* netPlayer)
{
	auto og_func = g_hooking->m_script_handler_mgr_hook->get_original<decltype(&hk_script_handler_mgr_dtor)>(12);
	return og_func(this_, netPlayer);
}

void hooking::hk_on_player_left(CGameScriptHandlerMgr* this_, rage::netPlayer* netPlayer)
{
	auto og_func = g_hooking->m_script_handler_mgr_hook->get_original<decltype(&hk_script_handler_mgr_dtor)>(13);
	return og_func(this_, netPlayer);
}

void hooking::hk_main_persistent_dtor(CGameScriptHandler* this_, bool free_memory)
{
	auto og_func = g_hooking->m_main_persistent_hook->get_original<decltype(&hk_main_persistent_dtor)>(0);
	g_hooking->m_main_persistent_hook->disable();
	g_hooking->m_main_persistent_hook.reset();
	return og_func(this_, free_memory);
}

bool hooking::hk_main_persistent_is_networked(CGameScriptHandler* this_)
{
	return *g_pointers->m_is_session_started;
}

bool hooking::hk_run_script_threads(std::uint32_t ops_to_execute)
{
	if (g_running)
	{
		g_script_mgr.tick();
	}

	return g_hooking->o_run_script_threads(ops_to_execute);
}

void* hooking::hk_convert_thread_to_fiber(void* param)
{
	if (IsThreadAFiber())
	{
		return GetCurrentFiber();
	}

	return g_hooking->o_convert_thread_to_fiber(param);
}

void hooking::hk_changeSessionWeather(int32_t eventGroup, int32_t weatherID, int32_t a3, int64_t alwaysZero)
{
	g_hooking->o_changeSessionWeather(eventGroup, weatherID, a3, alwaysZero);
}


BOOL hooking::hk_eventHandler(int64_t a1, int64_t a2)
{
	int playerbit = *reinterpret_cast<int*>(a1 + 544);
	DWORD argCount = *reinterpret_cast<DWORD*>(a1 + 548);
	int64_t* args = reinterpret_cast<int64_t*>(a1 + 112);
	BYTE sender = *reinterpret_cast<BYTE*>(a2 + 45); // CNetGamePlayer
	const auto receiver_id = args[1];
	int tseHash = args[0];
	bool block = true;

	if ((int)receiver_id != (int)sender)
	{
		if (tseHash != 1643902502)
			printf("Script event: S: %hs, R: %hs, %d\n", PLAYER::GET_PLAYER_NAME(sender), PLAYER::GET_PLAYER_NAME(receiver_id), tseHash);
		return true;
	}
		
	return g_hooking->o_eventHandler(a1,a2);
}

BOOL hooking::hk_getEventData(int32_t eventGroup, int32_t eventIndex, int32_t* argStruct, int32_t argStructSize)
{
	return g_hooking->o_getEventData(eventGroup, eventIndex, argStruct, argStructSize);
}

void hooking::hk_receivedEventHandler(int64_t event_manager, int64_t sender, int64_t receiver, uint16_t event_id, int32_t event_index, int32_t event_handled_bitset, int64_t bit_buffer_size, int64_t bit_buffer)
{
	BYTE sender_id = *reinterpret_cast<BYTE*>(sender + 45);
	BYTE receiver_id = *reinterpret_cast<BYTE*>(receiver + 45);
	const std::string event_name = reinterpret_cast<char*>(*reinterpret_cast<__int64*>(event_manager + (__int64)8 * event_id + 241328));

	/*
	if ((int)receiver_id == PLAYER::PLAYER_ID())
	{
		int enumId = event_index - 3;
		switch (enumId)
		{
		case KICK_VOTES_EVENT:
			if (features::bProtectionVoteKick)
				printf("KICK_VOTES_EVENT blocked from %hs\n", PLAYER::GET_PLAYER_NAME(sender_id));
			break;

		case GAME_WEATHER_EVENT:
			if (features::bProtectionWeather)
				printf("GAME_WEATHER_EVENT blocked from %hs\n", PLAYER::GET_PLAYER_NAME(sender_id));
			break;

		case GAME_CLOCK_EVENT:
			if (features::bProtectionClock)
				printf("GAME_CLOCK_EVENT blocked from %hs\n", PLAYER::GET_PLAYER_NAME(sender_id));
			break;
		case NETWORK_CLEAR_PED_TASKS_EVENT:
			if (features::bProtectionFreeze)
				printf("NETWORK_CLEAR_PED_TASKS_EVENT blocked from %hs\n", PLAYER::GET_PLAYER_NAME(sender_id));
			break;

		case GIVE_PED_SCRIPTED_TASK_EVENT:
			if (features::bProtectionFreeze)
				printf("GIVE_PED_SCRIPTED_TASK_EVENT blocked from %hs\n", PLAYER::GET_PLAYER_NAME(sender_id));
			break;

		case GIVE_PED_SEQUENCE_TASK_EVENT:
			if (features::bProtectionFreeze)
				printf("GIVE_PED_SEQUENCE_TASK_EVENT blocked from %hs\n", PLAYER::GET_PLAYER_NAME(sender_id));
			break;

		case REQUEST_CONTROL_EVENT:
			if (features::bProtectionRequestControl)
				printf("REQUEST_CONTROL_EVENT blocked from %hs\n", PLAYER::GET_PLAYER_NAME(sender_id));
			break;

		case EXPLOSION_EVENT:
			if (features::bProtectionExplosion)
				printf("EXPLOSION_EVENT blocked from %hs\n", PLAYER::GET_PLAYER_NAME(sender_id));
			break;

		case FIRE_EVENT:
			if (features::bProtectionFire)
				printf("FIRE_EVENT blocked from %hs\n", PLAYER::GET_PLAYER_NAME(sender_id));

		case NETWORK_PTFX_EVENT:
			if (features::bProtectionPTFX)
				printf("NETWORK_PTFX_EVENT blocked from %hs\n", PLAYER::GET_PLAYER_NAME(sender_id));
			break;

		}
	}
	*/

	return g_hooking->o_receivedEventHandler(event_manager, sender, receiver, event_id, event_index, event_handled_bitset, bit_buffer_size, bit_buffer);
}

const char* hooking::hk_GetLabelText(int64_t script, const char* label)
{
	if (strcmp("PM_SOLO_FM", label) == 0)
		return "Cherax Solo Session";

	if (strcmp("PM_NCREW_FM", label) == 0)
		return "Crew Session With Cherax";

	if (strcmp("PM_CREW_FM", label) == 0)
		return "Closed Crew Session With Cherax";

	if (strcmp("PM_FRIEND_FM", label) == 0)
		return "Closed Friend Session With Cherax";	

	if (strcmp("CTALERT_F_1", label) == 0)
		return "Game Alert";

	if (strcmp("LOADING_SPLAYER_L", label) == 0)
		return "Loading GTA with Cherax";

	if (strcmp("LOADING_MPLAYER_L", label) == 0)
		return "Loading GTA Online with Cherax";

	if (strcmp("PM_INF_PGOT", label) == 0)
		return "Play GTA Online With Cherax";

	if (strcmp("PM_ENTER_MP", label) == 0)
		return "Launch Online With Cherax";

	if (strcmp("HUD_JOINING", label) == 0)
		return "Loading GTA Online with Cherax";

	if (strcmp("PM_INVO_FM", label) == 0)
		return "Launch Invite only With Cherax";

	if (strcmp("PM_INF_PGOT5", label) == 0)
		return "Cherax Invite only session";

	if (strcmp("PM_INF_PGOT0", label) == 0)
		return "Go with Cherax";
	
	if (strcmp("PM_INF_PGOB0", label) == 0)
		return "Head straight into GTA Online with the Cherax Menu.";

	if (strcmp("HUD_QUITTING", label) == 0)
		return "Loading Cherax for Singleplayer";

	if (strcmp("PM_FIND_SESS", label) == 0)
		return "Find a new session with Cherax";

	if (strcmp("HUD_MPREENTER", label) == 0)
		return "Joining a new GTA Online session with Cherax";
	
	if (strcmp("PM_QUIT_MP", label) == 0)
		return "Leave GTA Online with Cherax";

	if (strcmp("NT_INV_CONFIG", label) == 0)
		return "Getting GTA Online session details with Cherax";

	if (strcmp("HUD_BAIL4", label) == 0)
		return "Failed to find a compatible GTA Online session with Cherax";

	if (strcmp("HUD_JOINEVENT", label) == 0)
		return "Joining GTA Online Event with Cherax";

	if (strcmp("PM_FRESES", label) == 0)
		return "Join Friends with Cherax";

	if (strcmp("PM_GO", label) == 0)
		return "Join Open Lobby with Cherax";

	if (strcmp("HUD_TRANSPEND", label) == 0)
		return "Transfer Pending with Cherax";

	if (strcmp("HUD_TRANSP", label) == 0)
		return "Transaction Pending with Cherax";

	if (strcmp("PM_QUIT_GAME", label) == 0)
		return "Are you sure you want to stop playing with Cherax?";

	if (strcmp("PM_PAUSE_HDR", label) == 0)
		return g_gui.watermark.c_str();

	if (strcmp("PCARD_SP", label) == 0)
		return g_gui.watermark.c_str();

	if (rage::joaat(label) == 0x4715EB89)
		return g_gui.watermark.c_str();

	if (rage::joaat(label) == 0x5630D885)
		return g_gui.watermark.c_str();

	if (rage::joaat(label) == 0xB58DC938)
		return g_gui.watermark.c_str();
		
	/*if (rage::joaat(label) == 0x9A094B65)
		return "Are you sure you want to quit Grand Theft Auto V and Cherax?";*/
	
	if (strcmp("RADIO_08_MEXICAN", label) == 0)
		return "Weirdo Mexicano";

	if (strcmp("RADIO_02_POP", label) == 0)
		return "Gay Pop Music";

	if (strcmp("RADIO_01_CLASS_ROCK", label) == 0)
		return "Edgy Memes";

	if (rage::joaat(label) == 1336517554)
		return "You were vote kicked or host kicked by a menu user";

	/*WARNING_EXIT_GAME, WARNING_EXIT_WINDOWS*/

	/*RADIO_04_PUNK FMMCRADIO_4 RADIO_03_HIPHOP_NEW*/

	return g_hooking->o_GetLabelText(script, label);
}

BOOL hooking::hk_networkIncreasementStatEvent(uint64_t net_event_struct, int64_t sender, int64_t a3)
{
	const auto hash = *reinterpret_cast<int64_t*>(net_event_struct + 0x30);
	auto sender_id = *reinterpret_cast<std::int8_t*>(sender + 0x2D);
	auto sender_name = PLAYER::GET_PLAYER_NAME(sender_id);

	bool block{};
	int tmp = hash;
	if (1)
	{

		switch (tmp) //do a switch statement for each hash
		{

		case -1670771646: // for griefing

			/*	sprintf(buf, "~g~Report blocked\n~b~Reported for griefing\n~r~From: %s", sender_name);
			out += std::string(buf);
			*/
			block = true;
			break;

		case -1619412469: // for exploits

			/*	sprintf(buf, "~g~Report blocked\n~b~Reported for game exploits\n~r~From: %s", sender_name);
			out += std::string(buf);*/
			block = true;
			break;

		case -872610652:

			/*sprintf(buf, "~g~Report blocked\n~b~Reported for exploits\n~r~From: %s", sender_name);
			out += std::string(buf);*/
			block = true;
			break;

		case 242250445:

			/*	sprintf(buf, "~g~Report blocked\n~b~Reported for VC hate\n~r~From: %s", sender_name);
				out += std::string(buf);*/
			block = true;
			break;

		case 1222453568:

			/*
			sprintf(buf, "~g~Report blocked\n~b~Reported for text chat annoying\n~r~From: %s", sender_name);
			out += std::string(buf);*/
			block = true;
			break;

		case 1982830996:

			/*sprintf(buf, "~g~Report blocked\n~b~Reported for text chat Hate\n~r~From: %s", sender_name);
			out += std::string(buf);*/
			block = true;
			break;



		default:

			/*	sprintf(buf, "[NSI] ~b~Hash: %d\n~r~From: %s", hash, sender_name);
			out += std::string(buf);*/
			block = true;
			break;
		}	
	}

	if (block)
		return true;
	return g_hooking->o_networkIncreasementStatEvent(net_event_struct, sender, a3);
}

int64_t* hooking::hk_ridHandler(int32_t friendIndex)
{
	auto rid = g_hooking->o_ridHandler(friendIndex);
	if (features::bMiscJoinRid)
	{
		*rid = (int64_t)features::bMiscRockstarID;	
	}
	return rid;
}

BOOL hooking::hk_ridJoiner(int64_t* a1, int* hash)
{
	features::bMiscJoinRid = true;
	auto res = g_hooking->o_ridJoiner(a1, hash);
	features::bMiscJoinRid = false;
	return res;
}

