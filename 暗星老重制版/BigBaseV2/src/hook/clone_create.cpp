#include"hooking.hpp"
#include"function_types.hpp"
#include"gta/net_object_mgr.hpp"
#include"protection/protection.hpp"

namespace big
{
	bool hooks::clone_create(CNetworkObjectMgr* mgr, CNetGamePlayer* src, CNetGamePlayer* dst, int32_t _object_type, int32_t _object_id, int32_t _object_flag, rage::datBitBuffer* buffer, int32_t timestamp)
	{
		return g_hooking->m_clone_create_hook.get_original<functions::clone_create_t>()(mgr, src, dst, _object_type, _object_id, _object_flag, buffer, timestamp);
	}
}