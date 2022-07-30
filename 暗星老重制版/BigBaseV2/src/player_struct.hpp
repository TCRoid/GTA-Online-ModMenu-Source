#pragma once
#include "gta/player.hpp"
#include "common.hpp"
#include "natives.hpp"

#ifndef PLAYER_STRUCT
#define PLAYER_STRUCT

namespace big
{
	struct CPlayer
	{
		int32_t id{};
		char name[20];


		//Vector3 SelectedPedpos= ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(id), true);;

		bool is_friend = false;
		
		bool is_online = false;
		

		CNetGamePlayer* net_player{};

		bool operator < (const CPlayer& another) const
		{
			char temp[20], temp2[20];

			for (uint8_t i = 0; i < 20; i++)
			{
				temp[i] = tolower(this->name[i]);
				temp2[i] = tolower(another.name[i]);
			}

			return strcmp(temp, temp2) < 0;
		}
	};
}

#endif