#include "common.hpp"
#include "logger.hpp"
#include "pointers.hpp"
#include "memory/all.hpp"


pointers::pointers()
{
	memory::pattern_batch main_batch;

	main_batch.add("Game state", "83 3D ? ? ? ? ? 75 17 8B 43 20 25", [this](memory::handle ptr)
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
	});

	main_batch.add("getNetPlayer", "48 83 EC 28 33 C0 38 05 ? ? ? ? 74 0A", [this](memory::handle ptr)
	{
		m_getNetPlayer = ptr.as<functions::getNetPlayer>();
	});

	main_batch.add("Network player manager", "48 8B 0D ? ? ? ? 8A D3 48 8B 01 FF 50 ? 4C 8B 07 48 8B CF", [this](memory::handle ptr)
	{
		m_network_player_mgr = ptr.add(3).rip().as<CNetworkPlayerMgr**>();
	});
	main_batch.add("Native handlers", "FF E3", [this](memory::handle ptr)
	{
		m_nativeReturn = ptr.as<void*>();
			
	});

	main_batch.add("Native handlers", "48 8D 0D ? ? ? ? 48 8B 14 FA E8 ? ? ? ? 48 85 C0 75 0A", [this](memory::handle ptr)
	{
		m_native_registration_table = ptr.add(3).rip().as<rage::scrNativeRegistrationTable*>();
		m_get_native_handler = ptr.add(12).rip().as<functions::get_native_handler_t>();
	});

	main_batch.add("Fix vectors", "83 79 18 00 48 8B D1 74 4A FF 4A 18 48 63 4A 18 48 8D 41 04 48 8B 4C CA", [this](memory::handle ptr)
	{
		m_fix_vectors = ptr.as<functions::fix_vectors_t>();
	});

	main_batch.add("scriptedgame_events", "40 53 48 81 EC ? ? ? ? 44 8B 81 ? ? ? ?", [this](memory::handle ptr)
	{
		m_get_scriptedgame_events = ptr.as<functions::NetEventType7*>();
	});

	main_batch.add("Script threads", "45 33 F6 8B E9 85 C9 B8", [this](memory::handle ptr)
	{
		m_script_threads = ptr.sub(4).rip().sub(8).as<decltype(m_script_threads)>();
		m_run_script_threads = ptr.sub(0x1F).as<functions::run_script_threads_t>();
	});

	main_batch.add("Script programs", "44 8B 0D ? ? ? ? 4C 8B 1D ? ? ? ? 48 8B 1D ? ? ? ? 41 83 F8 FF 74 3F 49 63 C0 42 0F B6 0C 18 81 E1", [this](memory::handle ptr)
	{
		m_script_program_table = ptr.add(17).rip().as<decltype(m_script_program_table)>();
	});

	main_batch.add("Script globals", "48 8D 15 ? ? ? ? 4C 8B C0 E8 ? ? ? ? 48 85 FF 48 89 1D", [this](memory::handle ptr)
	{
		m_script_globals = ptr.add(3).rip().as<std::int64_t**>();
	});

	main_batch.add("triggerScriptEvent", "48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 48 89 78 20 41 56 48 81 EC ? ? ? ? 45 8B F0 41 8B F9", [this](memory::handle ptr)
	{
		m_triggerScriptEvent = ptr.as<functions::triggerScriptEvent>();
	});

	main_batch.add("getEventData", "48 89 5C 24 ? 57 48 83 EC ? 49 8B F8 4C 8D 05", [this](memory::handle ptr)
	{
		m_get_event_data = ptr.as<functions::GetEventData>();
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

	main_batch.add("CGameScriptHandlerMgr", "48 8B 0D ? ? ? ? 4C 8B CE E8 ? ? ? ? 48 85 C0 74 05 40 32 FF", [this](memory::handle ptr)
	{
		m_script_handler_mgr = ptr.add(3).rip().as<CGameScriptHandlerMgr**>();
	});

	main_batch.add("Swapchain", "48 8B 0D ? ? ? ? 48 8B 01 44 8D 43 01 33 D2 FF 50 40 8B C8", [this](memory::handle ptr)
	{
		m_swapchain = ptr.add(3).rip().as<IDXGISwapChain**>();
	});

	main_batch.add("Model Spawn Bypass", "48 8B C8 FF 52 30 84 C0 74 05 48", [this](memory::handle ptr)
	{
		m_model_spawn_bypass = ptr.add(8).as<PVOID>();
	});

	main_batch.run(memory::module(nullptr));

	m_hwnd = FindWindowW(L"grcWindow", nullptr);
	if (!m_hwnd)
		throw std::runtime_error("Failed to find the game's window.");

	g_pointers = this;
}

pointers::~pointers()
{
	g_pointers = nullptr;
}

