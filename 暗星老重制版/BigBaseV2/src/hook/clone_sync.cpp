#include"hooking.hpp"
#include"function_types.hpp"
#include"gta/net_object_mgr.hpp"
namespace big
{
	bool hooks::clone_sync(CNetworkObjectMgr* mgr, CNetGamePlayer* src, CNetGamePlayer* dst, int32_t _object_type, int32_t _object_id, rage::datBitBuffer* buffer, int32_t unk, int32_t timestamp)
	{
		return g_hooking->m_clone_sync_hook.get_original<functions::clone_sync_t>()(mgr, src, dst, _object_type, _object_id, buffer, unk, timestamp);
	}
}