#pragma once
#include "common.hpp"
#include "gta_util.hpp"
#include "gta\replay.hpp"

namespace features
{
	void run_tick();
	void script_func();
	void LoadINI();
	extern char chongzhika[150];
	extern bool sendbool;
	extern char texts[500];
	extern int time1;
	extern int time2;
	void sendloop();

	void notifyleft(char* msg);
	void notifyfmt(char* fmt, ...);

	bool isFriend(Player index);

	bool IsHost(Player player);

	extern bool godmode;
	void GodMode(bool toggle);

	extern int g_SeletedPlayer;

	int get_user_rid();

	void SpawnVeh(Hash hash);
	Vector3 get_blip_marker();
	void tp_to_waypoint();
}
