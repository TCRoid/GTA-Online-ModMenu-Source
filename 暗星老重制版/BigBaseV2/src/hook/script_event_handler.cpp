#include "hooking.hpp"
#include "gta/enums.hpp"

namespace big
{
	bool hooks::scripted_game_event(CScriptedGameEvent* scripted_game_event, CNetGamePlayer* player)
	{
		return g_hooking->m_scripted_game_event_hook.get_original<decltype(&hooks::scripted_game_event)>()(scripted_game_event, player);
	}
}