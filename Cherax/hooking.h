#pragma once
#include "common.h"
#include "vmtHook.h"
#include "detour_hook.h"
#include "function_types.h"
#include "MinHook/include/MinHook.h"
#pragma comment(lib, "MinHook/lib/libMinHook.x64.lib")

class hooking
{
public:
	explicit hooking();
	~hooking();

	void enable();
	void disable();

	bool MinHookInit{};

	void ensure_dynamic_hooks();
	void** IATfind(const char* function, HMODULE module);


	vmt_hook m_swapchain_hook;
	//detour_hook m_detectWinApiHooks_hook;
	//detour_hook m_ntqvm_hook;

private:
	bool m_enabled{};

	std::unique_ptr<vmt_hook> m_main_persistent_hook;
	static void hk_main_persistent_dtor(CGameScriptHandler* this_, bool free_memory);
	static bool hk_main_persistent_is_networked(CGameScriptHandler* this_);

	std::unique_ptr<vmt_hook> m_script_handler_mgr_hook;
	static void hk_script_handler_mgr_dtor(CGameScriptHandlerMgr* this_, bool free_memory);
	static void hk_on_player_join(CGameScriptHandlerMgr* this_, rage::netPlayer* netPlayer);
	static void hk_on_player_left(CGameScriptHandlerMgr* this_, rage::netPlayer* netPlayer);

	functions::detectWinApiHooks o_detectWinApiHooks{};
	static int64_t hk_detectWinApiHooks();

	functions::tNtQueryVirtualMemory o_ntqvm{};
	static NTSTATUS hk_ntqvm(HANDLE ProcessHandle, PVOID BaseAddress, MEMORY_INFORMATION_CLASS MemoryInformationClass, PVOID Buffer, SIZE_T Length, PSIZE_T ResultLength);

	functions::tVirtualQuery o_VirtualQuery{};
	static SIZE_T hk_VirtualQuery(LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer,	SIZE_T dwLength);

	functions::tVirtualQueryEx o_VirtualQueryEx{};
	static SIZE_T hk_VirtualQueryEx(HANDLE hProcess, LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength);

	functions::run_script_threads_t o_run_script_threads{};
	static bool hk_run_script_threads(std::uint32_t ops_to_execute);

	functions::convert_thread_to_fiber o_convert_thread_to_fiber{};
	static void* hk_convert_thread_to_fiber(void* param);

	functions::changeSessionWeather o_changeSessionWeather{};
	static void hk_changeSessionWeather(int32_t eventGroup, int32_t weatherID, int32_t a3, int64_t alwaysZero);

	functions::eventHandler o_eventHandler{};
	static BOOL hk_eventHandler(int64_t a1, int64_t a2);

	functions::getEventData o_getEventData{};
	static BOOL hk_getEventData(int32_t eventGroup, int32_t eventIndex, int32_t* argStruct, int32_t argStructSize);

	functions::receivedEventHandler o_receivedEventHandler{};
	static void hk_receivedEventHandler(int64_t event_manager, int64_t sender, int64_t receiver, uint16_t event_id, int32_t event_index, int32_t event_handled_bitset, int64_t bit_buffer_size, int64_t bit_buffer);

	functions::GetLabelText o_GetLabelText{};
	static const char* hk_GetLabelText(int64_t script, const char* label);

	functions::networkIncreasementStatEvent o_networkIncreasementStatEvent{};
	static BOOL hk_networkIncreasementStatEvent(uint64_t net_event_struct, int64_t sender, int64_t a3);

	functions::ridHandler o_ridHandler{};
	static int64_t* hk_ridHandler(int32_t friendIndex);

	functions::ridJoiner o_ridJoiner{};
	static BOOL hk_ridJoiner(int64_t* a1, int* hash);
};

inline hooking* g_hooking{};

