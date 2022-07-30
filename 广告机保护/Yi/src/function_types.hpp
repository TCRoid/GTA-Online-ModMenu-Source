#pragma once
#include "common.hpp"
#include "gta/fwddec.hpp"
#include "gta/natives.hpp"
#include "gta\net_game_event.hpp"

namespace functions
{
	using getPlayerName = const char* (__fastcall*)(int32_t index);
	using getNetPlayer = int64_t(__fastcall*)(int32_t index);
	using triggerScriptEvent = int(__fastcall*)(int eventgroup, uint64_t* arg, int argcount, uint32_t bit);
	using GetEventData = bool(__fastcall*)(std::int32_t eventGroup, std::int32_t eventIndex, std::int64_t* args, std::uint32_t argCount);
	using run_script_threads_t = bool(*)(std::uint32_t ops_to_execute);
	using get_native_handler_t = rage::scrNativeHandler(*)(rage::scrNativeRegistrationTable*, rage::scrNativeHash);
	using fix_vectors_t = void(*)(rage::scrNativeCallContext*);
	using NetEventType7 = bool(CScriptedGameEvent* thisptr, __int64 sender, __int64 receiver);
}
