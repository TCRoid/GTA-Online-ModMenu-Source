#include "memory.h"

void Memory::executable_meta::EnsureInit() {

	if (m_begin) {
		return;
	}

	HMODULE gModule = GetModuleHandle(NULL);

	m_begin = reinterpret_cast<uintptr_t>(gModule);
	const IMAGE_DOS_HEADER* dosHeader = reinterpret_cast<const IMAGE_DOS_HEADER*>(gModule);
	const IMAGE_NT_HEADERS64* ntHeader = reinterpret_cast<const IMAGE_NT_HEADERS64*>(reinterpret_cast<const uint8_t*>(dosHeader) + dosHeader->e_lfanew);
	m_end = m_begin + ntHeader->OptionalHeader.SizeOfCode;
	m_size = ntHeader->OptionalHeader.SizeOfImage;
}

uintptr_t Memory::get_base()
{
	executable_meta executable;
	executable.EnsureInit();
	return executable.begin();
}

DWORD Memory::get_size()
{
	executable_meta executable;
	executable.EnsureInit();
	return executable.size();
}

uintptr_t Memory::get_base_offsetted(DWORD offset)
{
	return get_base() + offset;
}

uintptr_t Memory::get_multilayer_pointer(uintptr_t base_address, std::vector<DWORD> offsets)
{
	uintptr_t ptr = *(uintptr_t*)(base_address);
	if (!ptr) {

		return NULL;
	}
	auto level = offsets.size();

	for (auto i = 0; i < level; i++)
	{
		if (i == level - 1)
		{
			ptr += offsets[i];
			if (!ptr) return NULL;
			return ptr;
		}
		else
		{
			ptr = *(uint64_t*)(ptr + offsets[i]);
			if (!ptr) return NULL;
		}
	}

	return ptr;
}

static bool compare(const uint8_t* pData, const uint8_t* bMask, const char* sMask)
{
	for (; *sMask; ++sMask, ++pData, ++bMask)
		if (*sMask == 'x' && *pData != *bMask)
			return false;

	return *sMask == NULL;
}

std::vector<DWORD64> Memory::get_string_addresses(std::string str)
{
	std::string currentMask;
	const char* to_scan = str.c_str();
	for (uint8_t i = 0; i < strlen(to_scan); i++) currentMask += "x";
	const char* mask = currentMask.c_str();
	std::vector<DWORD64> foundAddrs;
	for (uint32_t i = 0; i < get_size(); ++i)
	{
		auto address = get_base() + i;
		if (compare((BYTE*)(address), (BYTE*)to_scan, mask))
		{
			foundAddrs.push_back((address));
		}
	}
	return foundAddrs;
}

uint64_t Memory::readRelativeAddress(uint64_t addr, int rel /* = 3 */)
{
	const int JUMP_SIZE = 4;
	int	read = *(int*)((addr + rel) + (JUMP_SIZE + rel));
	return addr + read;
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
	const IMAGE_DOS_HEADER* headerDos = (const IMAGE_DOS_HEADER*)m_begin;
	const IMAGE_NT_HEADERS64* headerNt = (const IMAGE_NT_HEADERS64*)((const BYTE*)headerDos + headerDos->e_lfanew);
	m_size = headerNt->OptionalHeader.SizeOfCode;
	m_end = m_begin + m_size;
	return;
}