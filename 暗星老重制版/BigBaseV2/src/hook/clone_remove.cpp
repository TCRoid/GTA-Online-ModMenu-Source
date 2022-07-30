#include"hooking.hpp"
#include"function_types.hpp"
namespace big
{
	void hooks::clone_remove(CNetworkObjectMgr* mgr, CNetGamePlayer* src, CNetGamePlayer* dst, int32_t _object_id, int32_t unk)
	{
		return g_hooking->m_clone_remove_hook.get_original<functions::clone_remove_t>()(mgr, src, dst, _object_id, unk);
	}
}