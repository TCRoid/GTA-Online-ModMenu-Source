#include "common.h"
#include "detour_hook.h"
#include "handle.h"
#include "MinHook/include/MinHook.h"
#pragma comment(lib, "MinHook/lib/libMinHook.x64.lib")


detour_hook::detour_hook(std::string name, void* target, void* detour) :
	m_name(std::move(name)),
	m_target(target),
	m_detour(detour)
{
	fix_hook_address();

	if (auto status = MH_CreateHook(m_target, m_detour, &m_original); status == MH_OK)
	{
		//LOG_INFO("Created hook '{}'.", m_name);
	}
	else
	{
		printf("Failed to create hook %s at 0x%llX error: %s\n", m_name, reinterpret_cast<std::uintptr_t>(m_target), MH_StatusToString(status));

	}
}

detour_hook::~detour_hook() noexcept
{
	if (m_target)
	{
		MH_RemoveHook(m_target);
	}

	//LOG_INFO("Removed hook '{}',", m_name);
}

void detour_hook::enable()
{
	if (auto status = MH_EnableHook(m_target); status == MH_OK)
	{
		//LOG_INFO("Enabled hook '{}'.", m_name);
	}
	else
	{
		printf("Failed to enable hook %s at 0x%llX error: %s\n", m_name, reinterpret_cast<std::uintptr_t>(m_target), MH_StatusToString(status));
	}
}

void detour_hook::disable()
{
	if (auto status = MH_DisableHook(m_target); status == MH_OK)
	{
		//LOG_INFO("Disabled hook '{}'", m_name);
	}
	else
	{
		printf("Failed to disable hook %S", m_name);
	}
}

DWORD exp_handler(PEXCEPTION_POINTERS exp, std::string const& name)
{
	return exp->ExceptionRecord->ExceptionCode == STATUS_ACCESS_VIOLATION
		? EXCEPTION_EXECUTE_HANDLER
		: EXCEPTION_CONTINUE_SEARCH;
}

void detour_hook::fix_hook_address()
{
	__try
	{
		auto ptr = memory::handle(m_target);
		while (ptr.as<std::uint8_t&>() == 0xE9)
		{
			ptr = ptr.add(1).rip();
		}

		m_target = ptr.as<void*>();
	}
	__except (exp_handler(GetExceptionInformation(), m_name))
	{
		[this]()
		{
			printf("Failed to fix hook address for %s", m_name);
		}();
	}
}

