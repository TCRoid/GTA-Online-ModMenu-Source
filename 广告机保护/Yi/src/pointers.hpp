#pragma once
#include "common.hpp"
#include "gta/fwddec.hpp"
#include "gta/enums.hpp"
#include "function_types.hpp"


class pointers
{
public:
	explicit pointers();
	~pointers();
public:
	HWND m_hwnd{};

	static const int EVENT_COUNT = 85;
	std::vector<void*> EventPtr;

	functions::GetEventData m_get_event_data;

	functions::getPlayerName m_getPlayerName{};
	functions::getNetPlayer m_getNetPlayer{};

	eGameState *m_game_state{};
	bool *m_is_session_started{};

	functions::triggerScriptEvent m_triggerScriptEvent{};

	CPedFactory **m_ped_factory{};
	CNetworkPlayerMgr **m_network_player_mgr{};

	rage::scrNativeRegistrationTable *m_native_registration_table{};
	functions::get_native_handler_t m_get_native_handler{};
	functions::fix_vectors_t m_fix_vectors{};

	functions::NetEventType7* m_get_scriptedgame_events;

	rage::atArray<GtaThread*> *m_script_threads{};
	rage::scrProgramTable *m_script_program_table{};
	functions::run_script_threads_t m_run_script_threads{};
	std::int64_t **m_script_globals{};

	CGameScriptHandlerMgr **m_script_handler_mgr{};

	IDXGISwapChain **m_swapchain{};

	PVOID m_model_spawn_bypass;
	void* m_nativeReturn;
};

inline pointers *g_pointers{};

