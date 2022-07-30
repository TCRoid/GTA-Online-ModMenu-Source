#pragma once
#pragma execution_character_set("utf-8")
#include <SDKDDKVer.h>
#include <Windows.h>
#include <D3D11.h>
#include <wrl/client.h>

#include <cinttypes>
#include <cstddef>
#include <cstdint>

#include <chrono>
#include <ctime>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <iomanip>

#include <atomic>
#include <mutex>
#include <thread>

#include <memory>
#include <new>
#include <sstream>
#include <string>
#include <string_view>
#include <algorithm>
#include <functional>
#include <utility>
#include <stack>
#include <vector>
#include <typeinfo>
#include <type_traits>
#include <exception>
#include <stdexcept>
#include <any>
#include <optional>
#include <variant>
#include <set>
#include <fmt/format.h>
#include <nlohmann/json.hpp>
#include <MinHook.h>
#include <imgui.h>
#include "backends/imgui_impl_dx11.h"
#include "backends/imgui_impl_win32.h"
#include <imgui_internal.h>

inline const char* MENU_NAME = "DarkStar";
inline const char* MENU_PATH = "C:\\DarkStar";



#include "logger.hpp"
#include "settings.hpp"
#include"translate.hpp"

#include "script_global.hpp"
#include "features.hpp"
#include "CPed.hpp"
#include "Vehicles.h"
#include "gta/blip.hpp"
#include "gta/Weapons.h"
#include "gta/replay.hpp"
#include "scripthookv.hpp"
#include "INI.hpp"
#include <random>

#define IsKeyPressed(key) GetAsyncKeyState(key) & 0x8000
namespace big
{
	using namespace std::chrono_literals;

	template <typename T>
	using comptr = Microsoft::WRL::ComPtr<T>;

	inline HMODULE g_hmodule{};
	inline HANDLE g_main_thread{};
	inline DWORD g_main_thread_id{};
	inline std::atomic_bool g_running{ true };

	inline CPed* g_local_player;
}
inline char* StringToChar(std::string string) // Handy little thing
{
	return _strdup(string.c_str());
}