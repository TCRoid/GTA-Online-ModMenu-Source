#pragma once

#include <SDKDDKVer.h>
#include <Windows.h>
#include <wrl/client.h>

#include <cinttypes>
#include <cstddef>
#include <cstdint>

#include <chrono>
#include <ctime>

#include <Mmsystem.h>
#include <stdio.h>
#include <Psapi.h>
#include <timeapi.h>
#include <time.h>
#include <emmintrin.h>
#include <intrin.h>
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
#include <string.h>
#include <stdlib.h>
#include <string_view>

#include <comdef.h>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <utility>
#include <TlHelp32.h>

#include <stack>
#include <vector>

#include <typeinfo>
#include <type_traits>

#include <exception>
#include <stdexcept>

#include <any>
#include <optional>
#include <variant>

#include <emmintrin.h>
#include <intrin.h>

# include <d3d9.h>

# include <dxgi.h>
# include <d3d10_1.h>
# include <d3d10.h>

# include <dxgi.h>
# include <d3d11.h>

# include <dxgi.h>
# include <d3d12.h>

#include <D3DX11tex.h>
#pragma comment(lib, "D3DX11.lib")

#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

#include "memory.h"
#include "enums.h"
#include "tinyxml2.h"

inline HMODULE g_hmodule{};
inline HANDLE g_main_thread{};
inline DWORD g_main_thread_id{};
inline BOOL g_running{ TRUE };

std::string encryptDecrypt(std::string toEncrypt);