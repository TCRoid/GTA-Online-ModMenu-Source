#pragma once
#include "common.hpp"
#include "gta/fwddec.hpp"
#include "gta/natives.hpp"
#include "CNetGamePlayer.hpp"

namespace big::functions
{
	using run_script_threads_t = bool(*)(std::uint32_t ops_to_execute);
	using get_native_handler_t = rage::scrNativeHandler(*)(rage::scrNativeRegistrationTable*, rage::scrNativeHash);
	using fix_vectors_t = void(*)(rage::scrNativeCallContext*);

	using world_to_screen_t = BOOL(__fastcall*)(Vector3 pos, float* ScreenX, float* ScreenY);

	using get_net_game_player_t = CNetGamePlayer * (Player player);

	using get_friend_rid_t = int64_t * (__fastcall*)(int32_t friendIndex);
	using rid_joiner_t = BOOL(__fastcall*)(int64_t* a1, int* hash);

	using ptr_to_handle_t = int32_t(__fastcall*)(PVOID entity);

	using clone_create_t = bool (*) (CNetworkObjectMgr* mgr, CNetGamePlayer* src, CNetGamePlayer* dst, int32_t object_type, int32_t object_id, int32_t object_flag, rage::datBitBuffer* buffer, int32_t timestamp);
	using clone_sync_t = bool (*) (CNetworkObjectMgr* mgr, CNetGamePlayer* src, CNetGamePlayer* dst, int32_t object_type, int32_t object_id, rage::datBitBuffer* buffer, int32_t unk, int32_t timestamp);
	using clone_remove_t = void (*) (CNetworkObjectMgr* mgr, CNetGamePlayer* src, CNetGamePlayer* dst, int32_t object_id, int32_t unk);

	using increment_stat_event_t = bool(*) (uint64_t net_event_struct, int64_t sender, int64_t a3);

	using read_bitbuf_array_t = bool(*) (rage::datBitBuffer* buffer, PVOID read, int bits, int);
	using read_bitbuf_dword_t = bool(*) (rage::datBitBuffer* buffer, PVOID read, int bits);
	using received_event_t = bool(*) (rage::netEventMgr* event_manager, CNetGamePlayer* source_player, CNetGamePlayer* target_player, uint16_t event_id, int event_index, int event_handled_bitset, int64_t bit_buffer_size, int64_t bit_buffer);
	using send_event_ack_t = void(*) (rage::netEventMgr* event_manager, CNetGamePlayer* source_player, CNetGamePlayer* target_player, int event_index, int event_handled_bitset);

	using getSyncTreeForType_t = rage::netSyncTree* (*) (void*, int);
	using getModelInfo_t = CBaseModelInfo * (*) (Hash hash, std::int32_t*);

	using getNetObjectByNetId_t = rage::netObject* (*) (std::uint16_t networkid);

	using get_network_object_t = rage::netObject* (*) (CNetworkObjectMgr*, int16_t, bool);

	using pack_clone_create_t = void (*) (CNetworkObjectMgr* mgr, rage::netObject* netObject, CNetGamePlayer* src, rage::datBitBuffer* buffer);
	using pack_clone_remove_t = bool (*) (CNetworkObjectMgr* mgr, rage::netObject* object, CNetGamePlayer* player, bool);
	using send_clone_sync_t = void (*) (CNetworkObjectMgr* mgr, rage::netObject* object, CNetGamePlayer* player, std::uint64_t a4, std::uint64_t a5, bool a6);

	using sync_can_apply_t = bool (*)(rage::netSyncTree* netSyncTree, rage::netObject* netObject);

	using RemovePlayer_t = void (*)(CNetGamePlayer* net_game_player);
	using forceScriptHost_t = void (*)(rage::scriptHandlerNetComponent*, CNetGamePlayer*);
}