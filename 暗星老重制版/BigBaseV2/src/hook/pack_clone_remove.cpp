#include "hooking.hpp"

namespace big
{
	bool hooks::pack_clone_remove(CNetworkObjectMgr* mgr, rage::netObject* object, CNetGamePlayer* player, bool b)
	{
		return g_hooking->m_pack_clone_remove_hook.get_original<functions::pack_clone_remove_t>()(mgr, object, player, b);
	}
}