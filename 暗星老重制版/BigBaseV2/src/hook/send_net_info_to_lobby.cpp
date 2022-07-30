#include"hooking.hpp"

namespace big
{
	bool hooks::send_net_info_to_lobby(rage::netPlayerData* player, int64_t a2, int64_t a3, DWORD* a4)
	{
		// check so we're 100% sure we modify data only for ourselves
		if (g_local_player->m_player_info->m_net_player_data.m_rockstar_id == player->m_rockstar_id)
		{
			g_gui.SendNotification("个人信息", "已成功将个人信息发送至此战局！");

			if (g_settings.spoofing.spoof_username)
				memcpy(player->m_name, g_settings.spoofing.username.c_str(), sizeof(player->m_name));

			if (g_settings.spoofing.spoof_ip)
			{
				player->m_external_ip.m_field1 = g_settings.spoofing.ip_address[0];
				player->m_external_ip.m_field2 = g_settings.spoofing.ip_address[1];
				player->m_external_ip.m_field3 = g_settings.spoofing.ip_address[2];
				player->m_external_ip.m_field4 = g_settings.spoofing.ip_address[3];
			}

			if (g_settings.spoofing.spoof_rockstar_id)
			{
				player->m_rockstar_id = g_settings.spoofing.rockstar_id;
				player->m_rockstar_id2 = g_settings.spoofing.rockstar_id;
			}
		}

		return g_hooking->m_send_net_info_to_lobby.get_original<decltype(&hooks::send_net_info_to_lobby)>()(player, a2, a3, a4);
	}
}