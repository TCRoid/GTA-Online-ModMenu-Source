#include "hooking.hpp"

namespace big
{
	void hooks::pack_clone_create(CNetworkObjectMgr* mgr, rage::netObject* netObject, CNetGamePlayer* src, rage::datBitBuffer* buffer)
	{
		g_hooking->m_pack_clone_create_hook.get_original<functions::pack_clone_create_t>()(mgr, netObject, src, buffer);
	}
}