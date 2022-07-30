#include"hooking.hpp"

namespace big
{
	void hooks::forceScriptHost(rage::scriptHandlerNetComponent* mgr, CNetGamePlayer* player)
	{
		if (g_settings.mgr == nullptr)
		{
			g_settings.mgr = mgr;
		}
		return g_hooking->m_forceScriptHost_hook.get_original<functions::forceScriptHost_t>()(mgr, player);
	}
}