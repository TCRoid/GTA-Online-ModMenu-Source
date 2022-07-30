//Hooking.cpp
#pragma once
#include "stdafx.h"
#include <inttypes.h>
using namespace Memory;
ScriptThread*(*GetActiveThread)() = nullptr;
HMODULE _hmoduleDLL;
HANDLE mainFiber;
DWORD wakeAt;
twoBytes*										i_objBypass;
twoBytes*                                       model_spawn_bypass_info;
Bytes24*                                        model_check_bypass_info;
fpDrawRect										Hooking::draw_rect;
std::vector<LPVOID>		                        Hooking::m_hooks;
uint64_t*				                        Hooking::m_frameCount;
fpIsDLCPresent			                        Hooking::is_DLC_present;
twoBytes*                                       owned_explossion_bypass_info;
fpGetEventData									Hooking::get_event_data;

static eGameState* 											m_gameState;
static uint64_t												m_worldPtr;
static BlipList*											m_blipList;
static Hooking::NativeRegistrationNew**						m_registrationTable;
static std::unordered_map<uint64_t, Hooking::NativeHandler>	m_handlerCache;
static std::vector<LPVOID>									m_hookedNative;
static __int64**                                            m_globalPtr;

const int EVENT_COUNT = 78;
static std::vector<void*> EventPtr;
static char EventRestore[EVENT_COUNT] = {};

bool nonhostkickprotex = false;
bool ceo_events = false;
bool SECrashprotex = false;
bool Transaction_Error = false;
bool bannerprotex = false;
bool load_screen = false;
bool blackscreen = false;
fpGetEventData m_OriginalGetEventData = nullptr;
BOOL GetEventData(__int64 a1, __int64 a2)
{
	unsigned __int8 argsSize = *reinterpret_cast<DWORD*>(a1 + 548) / 8;
	__int64* args = reinterpret_cast<__int64*>(a1 + 112);
	unsigned __int8 sender = *reinterpret_cast<BYTE*>(a2 + 45);
	const auto senderName = PLAYER::GET_PLAYER_NAME(sender);
	char bufLog[2048];
	int block = -1;

	if (nonhostkickprotex)
	{
		for (int i = 0; i < eventsidListKicks.size(); i++)
		{
			if ((int)args[0] == eventsidKicks.at(i))
			{
				if ((int)args[0] == KICK_1)
				{
					if ((int)args[3] >= 0 && (int)args[3] <= 19) break;
				}
				else if ((int)args[0] == KICK_2IMP)
				{
					if ((int)args[2] >= 0 && (int)args[2] <= 49) break;
				}
				else if ((int)args[0] == KICK_TO_SM)
				{
					if ((int)args[2] >= 0 && (int)args[2] <= 19) break;
				}
				else if ((int)args[0] == KICK_3)
				{
					if ((int)args[2] >= 0 && (int)args[2] <= 19) break;
				}
				else if ((int)args[0] == KICK_4XF)
				{
					if ((int)args[4] >= 0 && (int)args[4] <= 19) break;
				}
			}
			block = i + 100;
		}
	}

	if (block == -1)
	{
		for (int i = 1; i < eventsidlist.size(); i++)
		{
			if ((int)args[0] == eventsidlist.at(i))
			{
				if (ceo_events)
				{
					if ((int)args[0] == -701823896)
					{
						block = i;
						break;
					}
					if ((int)args[0] == -327286343)
					{
						block = i;
						break;
					}
				}
				if (Transaction_Error)
				{
					if ((int)args[0] == 189238289)
					{
						block = i;
						break;
					}
				}
				if (bannerprotex)
				{
					if ((int)args[0] == 561831609)
					{
						block = i;
						break;
					}
				}
				if (load_screen)
				{
					if ((int)args[0] == -125347541)
					{
						block = i;
						break;
					}
				}
				if (blackscreen)
				{
					if ((int)args[0] == -1246838892)
					{
						block = i;
						break;
					}
				}
				if (SECrashprotex)
				{
					if ((int)args[0] == SE_Crash)
					{
						block = i;
						break;
					}
					if ((int)args[0] == Unkonwn)
					{
						block = i;
						break;
					}
					if ((int)args[0] == Unkonwn2)
					{
						block = i;
						break;
					}
					if ((int)args[0] == -1256990787)
					{
						block = i;
						break;
					}
					if ((int)args[0] == -498955166)
					{
						block = i;
						break;
					}
					if ((int)args[0] == 564131320)
					{
						block = i;
						break;
					}
				}
			}
		}
	}
	if (block != -1)
	{
		IconNotification(" Event: %s\n Status: ~r~Blocked\n Sender: %s", "Decider", "Protection",  block >= 100 ? eventsidListKicks[block - 100] : eventsidList[block], senderName);
	}
	return m_OriginalGetEventData(a1, a2);
}
/* Start Hooking */
void Hooking::Start(HMODULE hmoduleDLL)
{
	_hmoduleDLL = hmoduleDLL;
	Log::Init(hmoduleDLL);
	FindPatterns();
	if (!InitializeHooks()) Cleanup();
}
BOOL Hooking::InitializeHooks()
{
	BOOL returnVal = TRUE;

	if (!iHook.Initialize()) {

		Log::Error("Failed to initialize InputHook");
		returnVal = FALSE;
	}

	if (MH_Initialize() != MH_OK) {
		Log::Error("MinHook failed to initialize");
		returnVal = FALSE;
	}

	if (!HookNatives()) {

		Log::Error("Failed to initialize NativeHooks");
		returnVal = FALSE;
	}

	return returnVal;
}

template <typename T>
bool Native(DWORD64 hash, LPVOID hookFunction, T** trampoline)
{
	if (*reinterpret_cast<LPVOID*>(trampoline) != NULL)
		return true;
	auto originalFunction = Hooking::GetNativeHandler(hash);
	if (originalFunction != 0) {
		MH_STATUS createHookStatus = MH_CreateHook(originalFunction, hookFunction, reinterpret_cast<LPVOID*>(trampoline));
		if (((createHookStatus == MH_OK) || (createHookStatus == MH_ERROR_ALREADY_CREATED)) && (MH_EnableHook(originalFunction) == MH_OK))
		{
			m_hookedNative.push_back((LPVOID)originalFunction);
			DEBUGMSG("Hooked Native 0x%#p", hash);
			return true;
		}
	}

	return false;
}

uint64_t CMetaData::m_begin = 0;
uint64_t CMetaData::m_end = 0;
DWORD CMetaData::m_size = 0;

uint64_t CMetaData::begin()
{
	return m_begin;
}
uint64_t CMetaData::end()
{
	return m_end;
}
DWORD CMetaData::size()
{
	return m_size;
}

void CMetaData::init()
{
	if (m_begin && m_size)
		return;

	m_begin = (uint64_t)GetModuleHandleA(nullptr);
	const IMAGE_DOS_HEADER*	headerDos = (const IMAGE_DOS_HEADER*)m_begin;
	const IMAGE_NT_HEADERS*	headerNt = (const IMAGE_NT_HEADERS64*)((const BYTE*)headerDos + headerDos->e_lfanew);
	m_size = headerNt->OptionalHeader.SizeOfCode;
	m_end = m_begin + m_size;
	return;
}
fpIsDLCPresent	OG_IS_DLC_PRESENT = nullptr;
BOOL __cdecl HK_IS_DLC_PRESENT()
{
	static uint64_t	last = 0;
	uint64_t		cur = *Hooking::m_frameCount;
	if (last != cur)
	{
		last = cur;
		Hooking::onTickInit();
	}
	return OG_IS_DLC_PRESENT();
}
Hooking::NativeHandler ORIG_WAIT = NULL;
void* __cdecl MY_WAIT(NativeContext *cxt)
{
	static int lastThread = 0;
	int threadId = SCRIPT::GET_ID_OF_THIS_THREAD();
	if (!lastThread)
	{
		char* name = SCRIPT::_GET_NAME_OF_THREAD(threadId);
		if (strcmp(name, "main_persistent") == 0)
		{
			lastThread = threadId;
			Log::Msg("Hooked Script NAME: %s ID: %i", name, threadId);
		}
	}
	if (threadId == lastThread) Hooking::onTickInit();
	ORIG_WAIT(cxt);
	return cxt;
}

Hooking::NativeHandler  ORIG_NETWORK_SESSION_KICK_PLAYER = NULL;
void *__cdecl MY_NETWORK_SESSION_KICK_PLAYER(NativeContext* cxt)
{
	Player player = cxt->GetArgument<int>(0);
	if (player == PLAYER::PLAYER_ID())
	{
		ORIG_NETWORK_SESSION_KICK_PLAYER(cxt);
	}
	return nullptr;
}


Hooking::NativeHandler  ORIG_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE = NULL;
void *__cdecl MY_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(NativeContext* cxt)
{
	Player player = cxt->GetArgument<int>(0);
	if (player == PLAYER::PLAYER_ID())
	{
		ORIG_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(cxt);
	}
	return nullptr;
}

Hooking::NativeHandler  ORIG_ATTACH_ENTITY_TO_ENTITY = NULL;
void *__cdecl MY_ATTACH_ENTITY_TO_ENTITY(NativeContext* cxt)
{
	Player player = cxt->GetArgument<int>(0);
	if (player == PLAYER::PLAYER_ID())
	{
		ORIG_ATTACH_ENTITY_TO_ENTITY(cxt);
	}
	return nullptr;
}

Hooking::NativeHandler ORIG_CLEAR_PED_TASKS_IMMEDIATELY = NULL;
void *__cdecl MY_CLEAR_PED_TASKS_IMMEDIATELY(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLEAR_PED_TASKS_IMMEDIATELY(cxt);
	}

	return nullptr;
}

Hooking::NativeHandler ORIG_CLEAR_PED_TASKS = NULL;
void *__cdecl MY_CLEAR_PED_TASKS(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLEAR_PED_TASKS(cxt);
	}

	return nullptr;
}

Hooking::NativeHandler ORIG_CLEAR_PED_SECONDARY_TASK = NULL;
void *__cdecl MY_CLEAR_PED_SECONDARY_TASK(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLEAR_PED_SECONDARY_TASK(cxt);
	}
	return nullptr;
}

Hooking::NativeHandler ORIG_CLONE_PED = NULL;
void *__cdecl MY_CLONE_PED(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLONE_PED(cxt);
	}
	return nullptr;
}
bool Hooking::HookNatives()
{
	MH_STATUS status = MH_CreateHook(Hooking::is_DLC_present, HK_IS_DLC_PRESENT, (void**)&OG_IS_DLC_PRESENT);
	if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::is_DLC_present) != MH_OK)
		return false;
	Hooking::m_hooks.push_back(Hooking::is_DLC_present);
	return true;
}

void __stdcall ScriptFunction(LPVOID lpParameter)
{
	try
	{
		ScriptMain();

	}
	catch (...)
	{
		Log::Fatal("Failed scriptFiber");
	}
}

void Hooking::onTickInit()
{
	if (mainFiber == nullptr)
		mainFiber = ConvertThreadToFiber(nullptr);

	if (timeGetTime() < wakeAt)
		return;

	static HANDLE scriptFiber;
	if (scriptFiber)
		SwitchToFiber(scriptFiber);
	else
		scriptFiber = CreateFiber(NULL, ScriptFunction, nullptr);
}

void Hooking::FailPatterns(const char* name)
{
	char buf[4096];
	sprintf_s(buf, "finding %s", name);
	Log::Error(buf);
	Cleanup();
}

/*
//CPatternResult
*/

CPatternResult::CPatternResult(void* pVoid) :
	m_pVoid(pVoid)
{}
CPatternResult::CPatternResult(void* pVoid, void* pBegin, void* pEnd) :
	m_pVoid(pVoid),
	m_pBegin(pBegin),
	m_pEnd(pEnd)
{}
CPatternResult::~CPatternResult() {}

/*
//CPattern Public
*/

CPattern::CPattern(char* szByte, char* szMask) :
	m_szByte(szByte),
	m_szMask(szMask),
	m_bSet(false)
{}
CPattern::~CPattern() {}

CPattern&	CPattern::find(int i, uint64_t startAddress)
{
	match(i, startAddress, false);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPattern&	CPattern::virtual_find(int i, uint64_t startAddress)
{
	match(i, startAddress, true);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPatternResult	CPattern::get(int i)
{
	if (m_result.size() > i)
		return m_result[i];
	return nullptr;
}

/*
//CPattern Private
*/
bool	CPattern::match(int i, uint64_t startAddress, bool virt)
{
	if (m_bSet)
		return false;
	uint64_t	begin = 0;
	uint64_t	end = 0;
	if (!virt)
	{
		CMetaData::init();
		begin = CMetaData::begin() + startAddress;
		end = CMetaData::end();
		if (begin >= end)
			return false;
	}
	int		j = 0;
	do
	{
		if (virt)
			begin = virtual_find_pattern(startAddress, (BYTE*)m_szByte, m_szMask) + 1;
		else
			begin = find_pattern(begin, end, (BYTE*)m_szByte, m_szMask) + 1;
		if (begin == NULL)
			break;
		j++;
	} while (j < i);

	m_bSet = true;
	return true;
}

bool	CPattern::byte_compare(const BYTE* pData, const BYTE* btMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++btMask)
		if (*szMask == 'x' && *pData != *btMask)
			break;
	if ((*szMask) != 0)
		return false;
	return true;
}


uint64_t	CPattern::find_pattern(uint64_t address, uint64_t end, BYTE *btMask, char *szMask)
{
	size_t len = strlen(szMask) + 1;
	for (uint64_t i = 0; i < (end - address - len); i++)
	{
		BYTE*	ptr = (BYTE*)(address + i);
		if (byte_compare(ptr, btMask, szMask))
		{
			m_result.push_back(CPatternResult((void*)(address + i)));
			return address + i;
		}
	}
	return NULL;
}

uint64_t	CPattern::virtual_find_pattern(uint64_t address, BYTE *btMask, char *szMask)
{
	MEMORY_BASIC_INFORMATION mbi;
	char*	pStart = nullptr;
	char*	pEnd = nullptr;
	char*	res = nullptr;
	size_t	maskLen = strlen(szMask);

	while (res == nullptr && sizeof(mbi) == VirtualQuery(pEnd, &mbi, sizeof(mbi)))
	{
		pStart = pEnd;
		pEnd += mbi.RegionSize;
		if (mbi.Protect != PAGE_READWRITE || mbi.State != MEM_COMMIT)
			continue;

		for (int i = 0; pStart < pEnd - maskLen && res == nullptr; ++pStart)
		{
			if (byte_compare((BYTE*)pStart, btMask, szMask))
			{
				m_result.push_back(CPatternResult((void*)pStart, mbi.BaseAddress, pEnd));
				res = pStart;
			}
		}

		mbi = {};
	}
	return (uint64_t)res;
}

void	failPat(const char* name)
{
	Log::Fatal("Failed to find %s pattern.", name);
	exit(0);
}

template <typename T>
void	setPat
(
	const char*	name,
	char*		pat,
	char*		mask,
	T**			out,
	bool		rel,
	int			offset = 0,
	int			deref = 0,
	int			skip = 0
)
{
	T*	ptr = nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	if (rel)
		ptr = pattern.get(skip).get_rel<T>(offset);
	else
		ptr = pattern.get(skip).get<T>(offset);

	while (true)
	{
		if (ptr == nullptr)
			failPat(name);

		if (deref <= 0)
			break;
		ptr = *(T**)ptr;
		--deref;
	}

	*out = ptr;
	return;
}

template <typename T>
void	setFn
(
	const char*	name,
	char*		pat,
	char*		mask,
	T*			out,
	int			skip = 0
)
{
	char*	ptr = nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	ptr = pattern.get(skip).get<char>(0);

	if (ptr == nullptr)
		failPat(name);

	*out = (T)ptr;
	return;
}
void Hooking::FindPatterns()
{
	HANDLE steam = GetModuleHandleA("steam_api64.dll");

	auto p_activeThread = pattern("E8 ? ? ? ? 48 8B 88 10 01 00 00");
	auto p_blipList = pattern("4C 8D 05 ? ? ? ? 0F B7 C1");
	auto p_fixVector3Result = pattern("83 79 18 00 48 8B D1 74 4A FF 4A 18");
	auto p_gameLegals = pattern("72 1F E8 ? ? ? ? 8B 0D");
	auto p_gameLogos = pattern("70 6C 61 74 66 6F 72 6D 3A");
	auto p_gameState = pattern("83 3D ? ? ? ? ? 75 17 8B 43 20 25");
	auto p_modelCheck = pattern("48 85 C0 0F 84 ? ? ? ? 8B 48 50");
	auto p_modelSpawn = pattern("48 8B C8 FF 52 30 84 C0 74 05 48");
	auto p_nativeTable = pattern("76 32 48 8B 53 40 48 8D 0D");
	auto p_worldPtr = pattern("48 8B 05 ? ? ? ? 45 ? ? ? ? 48 8B 48 08 48 85 C9 74 07");
	auto p_globalPtr = pattern("4C 8D 05 ? ? ? ? 4D 8B 08 4D 85 C9 74 11");
	auto p_eventHook = pattern("48 83 EC 28 E8 ? ? ? ? 48 8B 0D ? ? ? ? 4C 8D 0D ? ? ? ? 4C 8D 05 ? ? ? ? BA 03");
	auto p_scriptglobal = pattern("48 8D 15 ? ? ? ? 4C 8B C0 E8 ? ? ? ? 48 85 FF 48 89 1D");
	auto p_playerPtr = pattern("48 8B 0D ? ? ? ? E8 ? ? ? ? 48 8B C8 E8 ? ? ? ? 48 8B CF");
	auto p_swapchain = pattern("48 8B 0D ? ? ? ? 48 8D 55 A0 48 8B 01");
	auto p_nativeRegistration = pattern("48 83 EC 20 48 8D 0D ? ? ? ? E8 ? ? ? ? 0F B7 15 ? ? ? ? 33 FF");
	//auto p_ownedExplosionBypass = pattern("0F 85 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 48 08 E8");

	setPat<uint64_t>("frame count",
		"\x8B\x15\x00\x00\x00\x00\x41\xFF\xCF",
		"xx????xxx",
		&Hooking::m_frameCount,
		true,
		2);

	setFn<fpIsDLCPresent>("is_DLC_present",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x81\xF9\x00\x00\x00\x00",
		"xxxx?xxxxxxx????",
		&Hooking::is_DLC_present);

	char * c_location = nullptr;
	void * v_location = nullptr;

	setPat<twoBytes>("oebypass",
		"\x3B\xF8\x40\x0F\x94\xC7",
		"xxxxxx",
		&owned_explossion_bypass_info,
		false);

	setPat <twoBytes>("msbypass",
		"\xD8\x48\x85\xC0\x74\x12\x48\x8B\x10\x48\x8B\xC8\xFF\x52\x30\x84\xC0\x74\x05",
		"xxxxxxxxxxxxxxxxxxx",
		&model_spawn_bypass_info,
		false,
		17);

	setPat <Bytes24>("mcbypass",
		"\xCE\x33\xC1\x0F\xBA\xF0\x1D\x8B\xC8\x33\x4D\x67",
		"xxxxxxxxxxxx",
		&model_check_bypass_info,
		false,
		40);

	setFn<fpDrawRect>("draw_rect",
		"\x48\x8B\xC4\x48\x89\x58\x08\x57\x48\x83\xEC\x70\x48\x63\x0D\x00\x00\x00\x00\x0F",
		"xxxxxxxxxxxxxxx????x",
		&Hooking::draw_rect);

	Sleep(5000);

	Log::Msg("[INFO] Found GS");
	c_location = p_gameState.count(1).get(0).get<char>(2);
	c_location == nullptr ? FailPatterns("gameState") : m_gameState = reinterpret_cast<decltype(m_gameState)>(c_location + *(int32_t*)c_location + 5);

	Log::Msg("[INFO] Found VRFF");
	v_location = p_fixVector3Result.count(1).get(0).get<void>(0);
	if (v_location != nullptr) scrNativeCallContext::SetVectorResults = (void(*)(scrNativeCallContext*))(v_location);

	Log::Msg("[INFO] Found NRT");
	c_location = p_nativeTable.count(1).get(0).get<char>(9);
	c_location == nullptr ? FailPatterns("native registration table") : m_registrationTable = reinterpret_cast<decltype(m_registrationTable)>(c_location + *(int32_t*)c_location + 4);

	Log::Msg("[INFO] Found WP");
	c_location = p_worldPtr.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("world Pointer") : m_worldPtr = reinterpret_cast<uint64_t>(c_location) + *reinterpret_cast<int*>(reinterpret_cast<uint64_t>(c_location) + 3) + 7;

	Log::Msg("[INFO] Found BL");
	c_location = p_blipList.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("blip List") : m_blipList = (BlipList*)(c_location + *reinterpret_cast<int*>(c_location + 3) + 7);


	Log::Msg("[INFO] Found BOR");

	if (p_modelCheck.size() > 0) {

		v_location = p_modelCheck.count(1).get(0).get<void>(0);
		Memory::nop(v_location, 24);
	}

	if (p_modelSpawn.size() > 0) {

		v_location = p_modelSpawn.count(1).get(0).get<void>(8);
		Memory::nop(v_location, 2);
	}

	Log::Msg("[INFO] Found AST");
	c_location = p_activeThread.count(1).get(0).get<char>(1);
	c_location == nullptr ? FailPatterns("Active Script Thread") : GetActiveThread = reinterpret_cast<decltype(GetActiveThread)>(c_location + *(int32_t*)c_location + 4);

	Log::Msg("[INFO] Found WP");
	c_location = p_globalPtr.count(1).get(0).get<char>(0);
	__int64 patternAddr = NULL;
	c_location == nullptr ? FailPatterns("globalTable") : patternAddr = reinterpret_cast<decltype(patternAddr)>(c_location);
	m_globalPtr = (__int64**)(patternAddr + *(int*)(patternAddr + 3) + 7);

	Log::Msg("[INFO] Found EH");
	if ((c_location = p_eventHook.count(1).get(0).get<char>(0)))
	{
		int i = 0, j = 0, matches = 0, found = 0;
		char* pattern = "\x4C\x8D\x05";
		while (found != EVENT_COUNT)
		{
			if (c_location[i] == pattern[j])
			{
				if (++matches == 3)
				{
					EventPtr.push_back((void*)(reinterpret_cast<uint64_t>(c_location + i - j) + *reinterpret_cast<int*>(c_location + i + 1) + 7));
					found++;
					j = matches = 0;
				}
				j++;
			}
			else
			{
				matches = j = 0;
			}
			i++;
		}
	}
	CrossMapping::initNativeMap();

	Log::Msg("[INFO] Waiting for Grand Theft Auto V....");
	while (*m_gameState != GameStatePlaying) {
		Sleep(200);
	}
	Log::Msg("[INFO] GTA V ready!");
}

static Hooking::NativeHandler _Handler(uint64_t origHash)
{
	uint64_t newHash = CrossMapping::MapNative(origHash);
	if (newHash == 0)
	{
		return nullptr;
	}

	Hooking::NativeRegistrationNew * table = m_registrationTable[newHash & 0xFF];

	for (; table; table = table->getNextRegistration())
	{
		for (uint32_t i = 0; i < table->getNumEntries(); i++)
		{
			if (newHash == table->getHash(i))
			{
				return table->handlers[i];
			}
		}
	}
	return nullptr;
}

Hooking::NativeHandler Hooking::GetNativeHandler(uint64_t origHash)
{
	auto& handler = m_handlerCache[origHash];

	if (handler == nullptr)
	{
		handler = _Handler(origHash);
	}

	return handler;
}

eGameState Hooking::GetGameState()
{
	return *m_gameState;
}

uint64_t Hooking::getWorldPtr()
{
	return m_worldPtr;
}
void WAIT(DWORD ms)
{
	wakeAt = timeGetTime() + ms;
	SwitchToFiber(mainFiber);
}

void Hooking::Cleanup()
{
	Log::Msg("Cleaning up hooks");
	for (int i = 0; i < m_hooks.size(); i++)
		if (MH_DisableHook(m_hooks[i]) != MH_OK && MH_RemoveHook(m_hooks[i]) != MH_OK)
			Log::Error("Failed to unhook %p", (void*)m_hooks[i]);
	MH_Uninitialize();

	FreeLibraryAndExitThread(static_cast<HMODULE>(_hmoduleDLL), 1);
}

void Hooking::defuseEvent(RockstarEvent e, bool toggle)
{
	static const unsigned char retn = 0xC3;
	char* p = (char*)EventPtr[e];
	if (toggle)
	{
		if (EventRestore[e] == 0)
			EventRestore[e] = p[0];
	    *p = retn;
	}
	else
	{
		if (EventRestore[e] != 0)
			*p = EventRestore[e];
	}
}

__int64** Hooking::getGlobalPtr()
{
	return m_globalPtr;
}
__int64* Hooking::getGlobalPatern(int index)
{
	return &m_globalPtr[index >> 0x12 & 0x3F][index & 0x3FFFF];
}
//----------------------BYPASSES-----------------------//

void owned_explossion_bypass(bool toggle)
{
	constexpr twoBytes patched = { 0x39, 0xDB };
	constexpr twoBytes restore = { 0x3B, 0xF8 };
	if (owned_explossion_bypass_info == nullptr)
		return;
	*owned_explossion_bypass_info = toggle ? patched : restore;
}

bool model_spawn_bypass(bool toggle)
{
	constexpr twoBytes patched = { 0x90, 0x90 };
	constexpr twoBytes restore = { 0x74, 0x05 };
	if (model_spawn_bypass_info == nullptr)
		return NULL;
	*model_spawn_bypass_info = toggle ? patched : restore;
	return true;
}

bool model_check_bypass(bool toggle)
{
	constexpr Bytes24 patched = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
		0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
		0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };

	constexpr Bytes24 restore = { 0x48, 0x85, 0xC0, 0x0F, 0x84, 0x99,
		0x02, 0x00, 0x00, 0x8B, 0x48, 0x50, 0xC1, 0xE9, 0x04, 0xF6,
		0xC1, 0x01, 0x0F, 0x84, 0x8A, 0x02, 0x00, 0x00 };
	if (model_check_bypass_info == nullptr)
		return NULL;
	*model_check_bypass_info = toggle ? patched : restore;
	return true;
}

//-----------------------------------------------------//
