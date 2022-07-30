#pragma once
#include "common.hpp"
#include "gta/fwddec.hpp"
#include "gta/enums.hpp"
#include "function_types.hpp"

namespace big
{
	class pointers
	{
	public:
		explicit pointers();
		~pointers();
	public:
		HWND m_hwnd{};

		eGameState* m_game_state{};

		bool* m_is_session_started{};

		CPedFactory** m_ped_factory{};

		CNetworkPlayerMgr** m_network_player_mgr{};

		rage::scrNativeRegistrationTable* m_native_registration_table{};
		functions::get_native_handler_t m_get_native_handler{};
		functions::fix_vectors_t m_fix_vectors{};

		rage::atArray<GtaThread*>* m_script_threads{};
		rage::scrProgramTable* m_script_program_table{};
		functions::run_script_threads_t m_run_script_threads{};
		std::int64_t** m_script_globals{};
		rage::BlipList* m_blip_list{};
		functions::world_to_screen_t m_world_to_screen{};
		functions::get_net_game_player_t* m_get_net_game_player{};

		CGameScriptHandlerMgr** m_script_handler_mgr{};
		IDXGISwapChain** m_swapchain{};
		PVOID m_model_spawn_bypass{};
		int64_t* m_menu_ptr{};
		functions::get_friend_rid_t m_get_friend_rid{};
		functions::rid_joiner_t m_rid_joiner{};
		PVOID m_send_net_info_to_lobby{};
		rage::CReplayInterface** m_replay_interface{};
		functions::ptr_to_handle_t m_ptr_to_handle{};

		PVOID m_gta_thread_tick{};
		PVOID m_gta_thread_kill{};

		functions::clone_create_t m_clone_create{};
		functions::clone_sync_t m_clone_sync{};
		functions::clone_remove_t m_clone_remove{};

		functions::increment_stat_event_t m_increment_stat_event{};
		PVOID m_is_dlc_present;

		PVOID m_error_screen{};

		functions::read_bitbuf_array_t m_read_bitbuf_array{};
		functions::read_bitbuf_dword_t m_read_bitbuf_dword{};
		functions::received_event_t m_received_event{};
		functions::send_event_ack_t m_send_event_ack{};

		PVOID m_scripted_game_event{};

		PVOID m_player_has_joined{};
		PVOID m_player_has_left{};

		functions::get_network_object_t m_get_network_object{};

		functions::getSyncTreeForType_t m_getSyncTreeForType{};

		functions::getModelInfo_t m_getModelInfo{};

		functions::getNetObjectByNetId_t m_getNetObjectByNetId{};

		functions::pack_clone_create_t m_pack_clone_create{};
		functions::pack_clone_remove_t m_pack_clone_remove{};
		functions::send_clone_sync_t m_send_clone_sync{};

		functions::sync_can_apply_t m_sync_can_apply{};

		functions::RemovePlayer_t m_RemovePlayer{};

		functions::forceScriptHost_t m_forceScriptHost{};
	};

	inline pointers* g_pointers{};
}