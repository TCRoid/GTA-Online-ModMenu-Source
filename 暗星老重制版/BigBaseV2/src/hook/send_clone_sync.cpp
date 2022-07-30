#include "hooking.hpp"

namespace big
{
	void hooks::send_clone_sync(CNetworkObjectMgr* mgr, rage::netObject* object, CNetGamePlayer* player, std::uint64_t a4, std::uint64_t a5, bool a6)
	{
		g_hooking->m_send_clone_sync_hook.get_original<functions::send_clone_sync_t>()(mgr, object, player, a4, a5, a6);
	}
}