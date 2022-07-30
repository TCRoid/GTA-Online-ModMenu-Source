#include"hooking.hpp"

namespace big
{
	int64_t* hooks::get_friend_rid(int32_t friendIndex)
	{
		auto rid = g_hooking->m_get_friend_rid_hook.get_original<decltype(&hooks::get_friend_rid)>()(friendIndex);
		if (features::bMiscJoinRid)
		{
			*rid = (int64_t)features::bMiscRockstarID;
		}
		return rid;
	}

	BOOL hooks::rid_joiner(int64_t* a1, int* hash)
	{
		features::bMiscJoinRid = true;
		auto result = g_hooking->m_rid_joiner_hook.get_original<decltype(&hooks::rid_joiner)>()(a1, hash);
		features::bMiscJoinRid = false;
		return result;
	}
}