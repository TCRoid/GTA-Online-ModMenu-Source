#pragma once
#include "common.hpp"
#include "detour_hook.hpp"
#include "gta/fwddec.hpp"
#include "script_hook.hpp"
#include "vmt_hook.hpp"
#include <gta/script_thread.hpp>
#include <gta/net_game_event.hpp>

namespace big
{
	struct hooks
	{
		static bool run_script_threads(std::uint32_t ops_to_execute);
		static void* convert_thread_to_fiber(void* param);

		static constexpr auto swapchain_num_funcs = 19;
		static constexpr auto swapchain_present_index = 8;
		static constexpr auto swapchain_resizebuffers_index = 13;
		static HRESULT swapchain_present(IDXGISwapChain* this_, UINT sync_interval, UINT flags);
		static HRESULT swapchain_resizebuffers(IDXGISwapChain* this_, UINT buffer_count, UINT width, UINT height, DXGI_FORMAT new_format, UINT swapchain_flags);

		static LRESULT wndproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
		static BOOL set_cursor_pos(int x, int y);

		static bool send_net_info_to_lobby(rage::netPlayerData* player, int64_t a2, int64_t a3, DWORD* a4);

		static int64_t* get_friend_rid(int32_t friendIndex);
		static BOOL rid_joiner(int64_t* a1, int* hash);

		//static GtaThread* gta_thread_start(unsigned int** a1, unsigned int a2);
		static rage::eThreadState gta_thread_tick(GtaThread* a1, unsigned int a2);
		static rage::eThreadState gta_thread_kill(GtaThread* thread);

		static bool clone_create(CNetworkObjectMgr* mgr, CNetGamePlayer* src, CNetGamePlayer* dst, int32_t _object_type, int32_t _object_id, int32_t _object_flag, rage::datBitBuffer* buffer, int32_t timestamp);
		static bool clone_sync(CNetworkObjectMgr* mgr, CNetGamePlayer* src, CNetGamePlayer* dst, int32_t _object_type, int32_t _object_id, rage::datBitBuffer* buffer, int32_t unk, int32_t timestamp);
		static void clone_remove(CNetworkObjectMgr* mgr, CNetGamePlayer* src, CNetGamePlayer* dst, int32_t _object_id, int32_t unk);

		static bool increment_stat_event(CNetworkIncrementStatEvent* net_event_struct, CNetGamePlayer* sender, int64_t a3);

		static bool is_dlc_present(Hash dlc_hash);

		static void set_warning_message_with_header(
			const char* entryHeader,
			const char* entryLine1,
			int instructionalKey,
			const char* entryLine2,
			bool p4,
			Any p5,
			Any* showBackground,
			Any* p7,
			bool p8,
			Any p9
		);

		static bool received_event(
			rage::netEventMgr* event_manager,
			CNetGamePlayer* source_player,
			CNetGamePlayer* target_player,
			uint16_t event_id,
			int event_index,
			int event_handled_bitset,
			int64_t bit_buffer_size,
			int64_t bit_buffer
		);

		static bool scripted_game_event(CScriptedGameEvent* scripted_game_event, CNetGamePlayer* player);

		static void player_join(CNetworkObjectMgr* _this, CNetGamePlayer* net_player);
		static void player_leave(CNetworkObjectMgr* _this, CNetGamePlayer* net_player);

		static void pack_clone_create(CNetworkObjectMgr* mgr, rage::netObject* netObject, CNetGamePlayer* src, rage::datBitBuffer* buffer);
		static bool pack_clone_remove(CNetworkObjectMgr* mgr, rage::netObject* object, CNetGamePlayer* player, bool);
		static void send_clone_sync(CNetworkObjectMgr* mgr, rage::netObject* object, CNetGamePlayer* player, std::uint64_t a4, std::uint64_t a5, bool a6);

		static bool sync_can_apply(rage::netSyncTree* netSyncTree, rage::netObject* netObject);

		static void forceScriptHost(rage::scriptHandlerNetComponent* mgr, CNetGamePlayer* player);
	};

	struct minhook_keepalive
	{
		minhook_keepalive();
		~minhook_keepalive();
	};

	class hooking
	{
		friend hooks;
	public:
		explicit hooking();
		~hooking();

		void enable();
		void disable();

	private:
		bool m_enabled{};
		minhook_keepalive m_minhook_keepalive;

		vmt_hook m_swapchain_hook;
		WNDPROC m_og_wndproc;
		detour_hook m_set_cursor_pos_hook;

		detour_hook m_run_script_threads_hook;
		detour_hook m_convert_thread_to_fiber_hook;

		detour_hook m_send_net_info_to_lobby;

		detour_hook m_get_friend_rid_hook;
		detour_hook m_rid_joiner_hook;

		detour_hook m_gta_thread_tick_hook;
		detour_hook m_gta_thread_kill_hook;

		detour_hook m_clone_create_hook;
		detour_hook m_clone_sync_hook;
		detour_hook m_clone_remove_hook;

		detour_hook m_increment_stat_hook;
		detour_hook m_is_dlc_present_hook;

		detour_hook m_received_event_hook;
		detour_hook m_scripted_game_event_hook;

		detour_hook m_error_screen_hook;

		detour_hook m_player_has_joined_hook;
		detour_hook m_player_has_left_hook;

		detour_hook m_send_clone_sync_hook;
		detour_hook m_pack_clone_create_hook;
		detour_hook m_pack_clone_remove_hook;

		detour_hook m_sync_can_apply_hook;

		detour_hook m_forceScriptHost_hook;
	};

	inline hooking* g_hooking{};
}