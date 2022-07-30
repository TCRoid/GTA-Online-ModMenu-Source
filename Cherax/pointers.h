#pragma once
#include "common.h"
#include "function_types.h"
#include "structs.h"
#include "player.h"

class pointers
{
public:
	explicit pointers();
	~pointers();
public:
	HWND m_hwnd{};
	MODULEINFO mi;

	eGameState* m_game_state{};
	bool* m_is_session_started{};
	CPedFactory** m_ped_factory{};
	uint64_t* m_worldPtr{};
	int64_t** m_script_globals{};
	int64_t m_tunablePtr{};
	PVOID ownedExplosionBypass{};
	CBlipList* m_blitList{};
	CReplayInterface** m_replayIntf{};
	int64_t* transHelper{};
	int64_t* m_menuPtr{};
	static const int EVENT_COUNT = 85;
	std::vector<void*> EventPtr;
	char EventRestore[EVENT_COUNT] = {};

	functions::tNtQueryVirtualMemory m_ntqvm{};
	functions::tVirtualQuery m_VirtualQuery{};
	functions::tVirtualQueryEx m_VirtualQueryEx{};

	functions::getPlayerName m_getPlayerName{};
	functions::getNetPlayer m_getNetPlayer{};
	functions::ridHandler m_ridHandler{};
	functions::ridJoiner m_ridJoiner{};
	functions::world2screen m_world2Screen{};
	functions::GetLabelText m_GetLabelText{};
	functions::detectWinApiHooks m_detectWinApiHooks{};
	functions::eventHandler m_eventHandler{};
	functions::triggerScriptEvent m_triggerScriptEvent{};
	functions::getEventData m_getEventData{};
	functions::receivedEventHandler m_receivedEventHandler{};
	functions::kickVoteHandler m_kickVoteHandler{};
	functions::networkIncreasementStatEvent m_networkIncresementStatEvent{};
	functions::addOwnedExplosion m_addOwnedExplosion{};
	functions::changeSessionWeather m_changeSessionWeather{};
	functions::SetSessionTime m_setSessionTime{};
	functions::transactionPreparer m_transactionPreparer{};
	functions::transactionProcessor m_transactionProcessor{};

	functions::ptrToHandle m_ptr_to_handle{};
	MemoryPool** m_entityPool{};
	MemoryPool** m_pedPool;

	functions::get_native_handler_t m_get_native_handler{};
	functions::fix_vectors_t m_fix_vectors{};
	functions::run_script_threads_t m_run_script_threads{};
	functions::convert_thread_to_fiber m_convert_thread_to_fiber{};

	rage::scrNativeRegistrationTable* m_native_registration_table{};
	rage::atArray<GtaThread*>* m_script_threads{};
	rage::scrProgramTable* m_script_program_table{};
	CGameScriptHandlerMgr** m_script_handler_mgr{};
	IDXGISwapChain** m_swapchain{};
};

inline pointers* g_pointers{};