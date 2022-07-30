#pragma once
#include "common.h"
#include "fwddec.h"
#include "natives.h"

/*typedef enum _MEMORY_INFORMATION_CLASS
{
	MemoryBasicInformation, // MEMORY_BASIC_INFORMATION
	MemoryWorkingSetInformation, // MEMORY_WORKING_SET_INFORMATION
	MemoryMappedFilenameInformation, // UNICODE_STRING
	MemoryRegionInformation, // MEMORY_REGION_INFORMATION
	MemoryWorkingSetExInformation, // MEMORY_WORKING_SET_EX_INFORMATION
	MemorySharedCommitInformation, // MEMORY_SHARED_COMMIT_INFORMATION
	MemoryImageInformation, // MEMORY_IMAGE_INFORMATION
	MemoryRegionInformationEx,
	MemoryPrivilegedBasicInformation,
	MemoryEnclaveImageInformation, // MEMORY_ENCLAVE_IMAGE_INFORMATION // since REDSTONE3
	MemoryBasicInformationCapped
} MEMORY_INFORMATION_CLASS;*/

typedef enum _MEMORY_INFORMATION_CLASS {
	MemoryBasicInformation
} MEMORY_INFORMATION_CLASS;

/*typedef NTSTATUS(NTAPI* tNtQueryVirtualMemory)(
	HANDLE ProcessHandle,
	PVOID BaseAddress, MEMORY_INFORMATION_CLASS MemoryInformationClass,
	PVOID Buffer, SIZE_T Length, PSIZE_T ResultLength
	);*/

/*typedef SIZE_T(NTAPI* VirtualQuery)(
	LPCVOID                   lpAddress,
	PMEMORY_BASIC_INFORMATION lpBuffer,
	SIZE_T                    dwLength
);

typedef SIZE_T(NTAPI* VirtualQueryEx)(
	HANDLE                    hProcess,
	LPCVOID                   lpAddress,
	PMEMORY_BASIC_INFORMATION lpBuffer,
	SIZE_T                    dwLength
	);
*/

namespace functions
{
	typedef long(__stdcall* DX11Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
	typedef long(__stdcall* DX11ResizeBuffers) (IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);

	using getPlayerName = const char* (__fastcall*)(int32_t index);
	using getNetPlayer = int64_t(__fastcall*)(int32_t index);
	using ridHandler = int64_t*(__fastcall*)(int32_t friendIndex);
	using ridJoiner = char(__fastcall*)(int64_t* a1, int* hash);
	using world2screen = BOOL(__fastcall*)(rage::vector3 pos, float* ScreenX, float* ScreenY);
	using GetLabelText = const char* (__fastcall*)(int64_t script, const char* label);
	using detectWinApiHooks = int64_t(__fastcall*)();
	using triggerScriptEvent = int(__fastcall*)(bool unk0, int64_t * args, int32_t argCount, int32_t bitFlags);
	using getEventData = BOOL(__fastcall *)(int32_t eventGroup, int32_t eventIndex, int32_t * argStruct, int32_t argStructSize);
	using eventHandler = BOOL(__fastcall*)(int64_t a1, int64_t a2);
	using receivedEventHandler = void(__fastcall*) (int64_t event_manager, int64_t sender, int64_t receiver, uint16_t event_id, int32_t event_index, int32_t event_handled_bitset, int64_t bit_buffer_size, int64_t bit_buffer);
	using kickVoteHandler = BOOL(__fastcall*)(int64_t a1, int64_t a2, int64_t sender);
	using networkIncreasementStatEvent = BOOL(__fastcall*)(uint64_t net_event_struct, int64_t sender, int64_t a3);
	using addOwnedExplosion = BOOL(__fastcall*)(Ped ped, Vector3 * pos, int32_t type, float dmgScale, bool isAudible, bool isInvis, float fCamShake);
	using SetSessionTime = void(__fastcall*)(int32_t a1, uint64_t a2);
	using changeSessionWeather = void(__fastcall*)(int32_t eventGroup, int32_t weatherID, int32_t a3, int64_t alwaysZero);
	using transactionPreparer = BOOL(__fastcall*)(int64_t a1, DWORD * transactionID, int32_t a3, int64_t a4, int32_t amount, int32_t p4, int32_t mode, int32_t banked);
	using transactionProcessor = BOOL(__fastcall*)(int64_t a1, int64_t transactionID, int64_t unk);
	using ptrToHandle = Entity(__fastcall*)(void* entity);

	using run_script_threads_t = bool(*)(std::uint32_t ops_to_execute);
	using get_native_handler_t = rage::scrNativeHandler(*)(rage::scrNativeRegistrationTable*, rage::scrNativeHash);
	using fix_vectors_t = void(*)(rage::scrNativeCallContext*);

	using convert_thread_to_fiber = void*(*)(void* param);
	using tVirtualQueryEx = SIZE_T(*)(HANDLE hProcess, LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength);
	using tVirtualQuery = SIZE_T(*)(LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength);
	using tNtQueryVirtualMemory =  NTSTATUS(__fastcall*)( HANDLE ProcessHandle,PVOID BaseAddress, MEMORY_INFORMATION_CLASS MemoryInformationClass,PVOID Buffer, SIZE_T Length, PSIZE_T ResultLength);
}
