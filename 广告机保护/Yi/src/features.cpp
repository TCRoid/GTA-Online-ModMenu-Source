#include "common.hpp"
#include "features.hpp"
#include "logger.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "pointers.hpp"
#include "hooking.hpp"
#include "gta_util.hpp"
#include "gta\replay.hpp"
#include "fiber_pool.hpp"
#include "script_global.hpp"
#include "Ini.h"
#include "hwd.h"
#include "gui.hpp"

void features::run_tick()
{
	TRY_CLAUSE
	{
		GodMode(godmode);
		if (yanz == 1)
		{
			sendloop();
		}
	}
	EXCEPT_CLAUSE
	//updatePlayerData();
}

int features::get_user_rid() {
	return gta_util::get_local_playerinfo()->m_rockstar_id;
}

char features::chongzhika[150];
std::string path = "C:\\ggj\\load.ini";
void features::LoadINI() {
	strcpy(features::chongzhika, INI::GetChar(path, "Auth", "Key"));
	strcpy(features::texts, INI::GetChar(path, "Game", "GT"));
	features::sendbool = INI::GetBool(path, "Game", "GuaJi");
	features::time1 = INI::GetInt(path, "Game", "Time1");
	features::time2 = INI::GetInt(path, "Game", "Time2");
}

char features::texts[500];
int features::time1 = 60000;
int features::time2 = 2000;
int tick1;
int tick2;
bool features::sendbool = false;
void features::sendloop() {
	if (sendbool) {
		if (GetTickCount64() - tick1 > features::time1)
		{
			*script_global(1575004).as<int*>() = 0;
			*script_global(1574587).as<int*>() = 1;
			script::get_current()->yield(200ms);
			*script_global(1574587).as<int*>() = 0;
			tick1 = GetTickCount64();
			LOG(INFO) << "切换战局中";
		}
		if ((GetTickCount64() - tick2 > features::time2) && g_pointers->m_is_session_started)
		{
			int handle[13];
			for (int i{}; i < 32; i++) {
				if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
					int handle[13];
					NETWORK::NETWORK_HANDLE_FROM_PLAYER(i, handle, 13);
					NETWORK::NETWORK_SEND_TEXT_MESSAGE(texts, &handle[0]);
				}
			}
			tick2 = GetTickCount64();
			LOG(INFO) << "发送信息中";
		}
	}
}

void features::notifyleft(char* msg)
{
	HUD::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	//HUD::_SET_NOTIFICATION_MESSAGE("QAQ", 1,1,20,0,"CHAR_RON", "CHAR_RON");
	//HUD::_SET_NOTIFICATION_MESSAGE_2("CHAR_ACTING_UP", "CHAR_ACTING_UP", 0, 1, u8"~r~XIPro", u8"~y~尊贵的VIP用户欢迎您使用XIPro");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(msg);
	HUD::_DRAW_NOTIFICATION(2000, 1);
}

void features::notifyfmt(char* fmt, ...)
{
	char buf[2048] = { 0 };
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	char buff2[2048] = { 0 };
	sprintf_s(buff2, "%s", buf);

	HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(buff2);
	HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(FALSE, FALSE);
}

int features::g_SeletedPlayer = 0;


bool features::IsHost(Player player) {
		if (NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == player) { return true; };
		return false;
}

void features::SpawnVeh(Hash hash) {
	STREAMING::REQUEST_MODEL(hash);
	while (!STREAMING::HAS_MODEL_LOADED(hash))
	{
		script::get_current()->yield();
	}

	Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
	*(unsigned short*)g_pointers->m_model_spawn_bypass = 0x9090;
	Vehicle vehicle = VEHICLE::CREATE_VEHICLE(hash, pos.x, pos.y, pos.z, 0.f, TRUE, FALSE, FALSE);
	*(unsigned short*)g_pointers->m_model_spawn_bypass = 0x0574; //By writing the "old" bypass to the function, running CREATE_VEHICLE, then restoring it, the anti-cheat does not have enough time to catch the function in a dirty state.

	if (*g_pointers->m_is_session_started)
	{
		DECORATOR::DECOR_SET_INT(vehicle, "MPBitset", 0);
		ENTITY::_SET_ENTITY_SOMETHING(vehicle, TRUE); //True means it can be deleted by the engine when switching lobbies/missions/etc, false means the script is expected to clean it up.
		auto networkId = NETWORK::VEH_TO_NET(vehicle);
		if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(vehicle))
			NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);
		VEHICLE::SET_VEHICLE_IS_STOLEN(vehicle, FALSE);
	}
	STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
}
Vector3 features::get_blip_marker()
{
	static Vector3 zero;
	Vector3 coords;

	bool blipFound = false;
	// search for marker blip
	int blipIterator = HUD::_GET_BLIP_INFO_ID_ITERATOR();
	for (Blip i = HUD::GET_FIRST_BLIP_INFO_ID(blipIterator); HUD::DOES_BLIP_EXIST(i) != 0; i = HUD::GET_NEXT_BLIP_INFO_ID(blipIterator))
	{
		if (HUD::GET_BLIP_INFO_ID_TYPE(i) == 4)
		{
			coords = HUD::GET_BLIP_INFO_ID_COORD(i);
			blipFound = true;
			break;
		}
	}
	if (blipFound)
	{
		return coords;
	}
	return zero;
}
void features::tp_to_waypoint() {
	Vector3 coords = features::get_blip_marker();

	if (coords.x == 0 && coords.y == 0)
	{

		return;
	}

	// get entity to teleport
	Entity e = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
	{
		e = PED::GET_VEHICLE_PED_IS_USING(e);
	}


	// load needed map region and check height levels for ground existence
	bool groundFound = false;
	static float groundCheckHeight[] =
	{ 100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
	for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
	{
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, groundCheckHeight[i], 0, 0, 1);
		script::get_current()->yield(100ms);
		if (MISC::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0))
		{
			groundFound = true;
			coords.z += 3.0;
			break;
		}
	}
	// if ground not found then set Z in air and give player a parachute
	if (!groundFound)
	{
		coords.z = 1000.0;
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xFBAB5776, 1, 0);
	}
	//do it
	ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), coords.x, coords.y, coords.z, 0, 0, 0, 1);
	HUD::SET_WAYPOINT_OFF();
}

bool features::isFriend(Player index)
{
	int netHandle[13];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(index, netHandle, 13);
	if (NETWORK::NETWORK_IS_HANDLE_VALID(netHandle, 13))
		if (NETWORK::NETWORK_IS_FRIEND(&netHandle[0]))
			return true;

	return false;
}

bool features::godmode = false;
void features::GodMode(bool toggle) {
	//ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), toggle);
}

void features::script_func()
{
	while (true)
	{
		TRY_CLAUSE
		{
			features::run_tick();
		}
		EXCEPT_CLAUSE
		script::get_current()->yield();
	}
}


