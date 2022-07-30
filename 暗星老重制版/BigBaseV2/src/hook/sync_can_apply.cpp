#include"hooking.hpp"
#include"function_types.hpp"

namespace big
{
	bool hooks::sync_can_apply(rage::netSyncTree* netSyncTree, rage::netObject* netObject)
	{
		return g_hooking->m_sync_can_apply_hook.get_original<functions::sync_can_apply_t>()(netSyncTree, netObject);
	}
}