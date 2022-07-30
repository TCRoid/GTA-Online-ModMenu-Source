//Hooking.cpp
#pragma once
#include "stdafx.h"
#include "Hooking.h"
#include "Scriptthread.h"

using namespace Memory;

bool enable_coloading = true;

ScriptThread*(*GetActiveThread)() = nullptr;
HMODULE _hmoduleDLL;
HANDLE mainFiber;
DWORD wakeAt;
HMODULE Hooking::scriptDLL;

const char NOP = '\x90';
static char object_spawn[2];
static char model_bypass[24];
static void* m_model_bypass;
static void* m_object_spawn;

static uint8_t* m_int_checker;
static char int_check[7];
uint8_t og_int_checker;

void* Hooking::mon;
char* Hooking::loading_text = "Loading X-Force";

bool Hooking::protect = false;
bool Hooking::dump = false;
bool Hooking::notify = false;
bool Hooking::redirect = false;
bool Hooking::blockall = false;
bool Hooking::smart_protex = false;
bool Hooking::smart_pro = false;
bool Hooking::logger = false;
bool Hooking::rdev = false;
bool Hooking::event_handler_on = false;
bool Hooking::e_weather_time = false;
bool Hooking::e_control = false;
bool Hooking::e_explosion = false;
bool Hooking::e_pickup = false;
bool Hooking::e_weapon = false;
bool Hooking::e_wanted = false;
bool Hooking::e_report = false;
bool Hooking::e_kick = false;
bool Hooking::e_freeze = false;
bool Hooking::e_stat = false;
bool Hooking::e_ptfx = false;
bool Hooking::e_redirect = false;
bool Hooking::e_notify = false;
bool Hooking::patch_checker = false;

threeBytes*                             Hooking::infinite_ammo;
threeBytes*                             Hooking::no_reload;
twoBytes*			                  	Hooking::m_ownedExplosionBypass;
BYTE*                                   Hooking::m_ownedExplosionBypass2;
std::vector<LPVOID>                     Hooking::m_hooks;
uint64_t*			                	Hooking::m_frameCount;
fpIsDLCPresent		                	Hooking::is_DLC_present;
TriggerScriptEvent	                	Hooking::trigger_script_event;
SetSessionWeather                       Hooking::set_session_weather;
fpStatSetInt		                	Hooking::stat_set_int;
fpStatSetBool                           Hooking::stat_set_bool;
fpStatSetFloat                          Hooking::stat_set_float;
GetEventData                            Hooking::get_script_event_data;
fpGetPlayerName                         Hooking::GPN;
addOwnedExplosion                       Hooking::add_owned_explosion;
fpGetEventData                          Hooking::get_event_data;
fpSetLobbyTime                          Hooking::set_lobby_time;
fpGetChatMessage                        Hooking::get_chat_message;
fpGetPlayerAddress                      Hooking::get_player_address;
fpAddressToEntity                       Hooking::address_to_entity;
fpEventHandler                          Hooking::event_handler;
fpSetName                               Hooking::set_name_kek;
fpSetSessionTime                        Hooking::set_session_time;
clockTime*                              Hooking::ClockTime;
fpSetEntityMaxHealth                    Hooking::set_entity_max_health;
fpCreateVehicle                         Hooking::create_vehicle;
fpSetVehicleMod                         Hooking::set_vehicle_mod;
fpClearPedTasksImmediately              Hooking::clear_ped_tasks_immediately;
fpGetNumberOfEvents                     Hooking::get_number_of_events;
fpNetworkIsSessionStarted               Hooking::is_session_started;
fpNetworkRequestControlOfNetworkId      Hooking::request_control_of_network_id;
fpNetworkRequestControlOfEntity         Hooking::request_control_of_entity;
fpNetworkHasControlOfEntity             Hooking::has_control_of_entity;
fpSetNetworkIdCanMigrate                Hooking::set_network_id_can_migrate;
fpGetNetworkTime                        Hooking::get_network_time;
fpDecorSetInt                           Hooking::decor_set_int;
fpDecorRegister                         Hooking::decor_register;
fpChatMessage                           Hooking::get_message;
fpGetSender                             Hooking::get_sender;
CReplayInterface*		                Hooking::m_replayIntf;
fpIncrementStatHook                     Hooking::increment_stat;
fpCreateAmbientPickup                   Hooking::create_ambient_pickup;
fpIntegrityCheck                        Hooking::integrity_check;
fpSetMobileRadioEnabledDuringGameplay   Hooking::set_mobile_radio_enabled_during_gameplay;
fpIsEntityUpsideDown                    Hooking::is_entity_upsidedown;
fpRequestIpl                            Hooking::request_ipl;
fpIsIplActive                           Hooking::is_ipl_active;
fpNetworkSessionKickPlayer              Hooking::network_session_kick_player;
fpNetworkShopCheckoutStart              Hooking::network_shop_checkout_start;
fpGetPlayerMaxArmour                    Hooking::get_player_max_armour;
fpGetEntityAttachedTo                   Hooking::get_entity_attached_to;
fpSetEntityCollision                    Hooking::set_entity_collision;
fpStatSetDate                           Hooking::stat_set_date;
fpStatGetInt                            Hooking::stat_get_int;
fpAddTextCompSubstrPlayerName	        Hooking::add_text_comp_substr_playername;
fpEndTextCmdDisplayText	                Hooking::end_text_command_display_text;
fpBeginTextCmdDisplayText	            Hooking::begin_text_command_display_text;
fpSendMessage                           Hooking::send_message;
fpClearPedBloodDamage                   Hooking::clear_ped_blood_damage;
fpSetVehicleOnGroundProperly            Hooking::set_vehicle_on_ground_properly;
fpSetVehicleNumberplateText             Hooking::set_vehicle_numberplate_text;
fpIsThisModelAPlane                     Hooking::is_this_model_a_plane;
fpIsThisModelAHeli                      Hooking::is_this_model_a_heli;
fpSetHeliBladesFullSpeed                Hooking::set_heli_blades_full_speed;
fpEndTextCommandGetWidth                Hooking::end_text_command_get_width;
fpRequestAnimDict                       Hooking::request_anim_dict;
fpHasAnimDictLoaded                     Hooking::has_anim_dict_loaded;
fpDrawNotification                      Hooking::draw_notification;
fpDrawNotification2                     Hooking::draw_notification_2;
fpPickupRewardMoneyIsApplicableToPlayer Hooking::pickup_is_applicable_to_player;
fpSetVehicleEngineOn                    Hooking::set_vehicle_engine_on;
fpSetVehicleUndriveable                 Hooking::set_vehicle_undriveable;
fpSetVehicleDriveable                   Hooking::set_vehicle_driveable;
fpGetDisplayNameFromVehicle             Hooking::get_display_name_from_vehicle;
fpToggleVehicleMod                      Hooking::toggle_vehicle_mod;
fpNetworkShopBeginService               Hooking::network_shop_begin_service;
fpGiveDelayedWeaponToPed                Hooking::give_delayed_weapon_to_ped;
fpRemoveAllPedWeapons                   Hooking::remove_all_ped_weapons;
fpRemoveWeaponFromPed                   Hooking::remove_weapon_from_ped;
fpGetPedInVehicleSeat                   Hooking::get_ped_in_vehicle_seat;
fpIsAimCamActive                        Hooking::is_aim_cam_active;
fpDrawRect                              Hooking::draw_rect;
fpDrawLine                              Hooking::draw_line;
fpGetGameplayCamRot                     Hooking::get_gameplay_cam_rot;
fpGetGameplayCamCoord                   Hooking::get_gameplay_cam_coord;
fpNetworkGetNetworkIdFromEntity         Hooking::get_network_id_from_entity;
fpNetworkCreateSynchronisedScene        Hooking::create_synchronised_scene;
fpNetworkAddPedToSynchronisedScene      Hooking::add_ped_to_synchronised_scene;
fpNetworkStartSynchronisedScene         Hooking::start_synchronised_scene;
fpIsVehicleDrivable                     Hooking::is_vehicle_driveable;
fpGetPlayerRadioStationIndex            Hooking::get_player_radio_station_index;
fpGetRadioStationName                   Hooking::get_radio_station_name;
fpSetVehicleForwardSpeed                Hooking::set_vehicle_forward_speed;
fpSetVehicleFixed                       Hooking::set_vehicle_fixed;
fpSetVehicleDeformationFixed            Hooking::set_vehicle_deformation_fixed;
fpIsVehicleSeatFree                     Hooking::is_vehicle_seat_free;
fpSetVehicleNumberPlateIndex            Hooking::set_vehicle_number_plate_index;
fpSetVehicleWheelType                   Hooking::set_vehicle_wheel_type;
fpGetNumVehicleMod                      Hooking::get_num_vehicle_mod;
fpSetNotificationTextEntry              Hooking::set_notification_text_entry;
fpUpdateOnscreenKeyboard                Hooking::update_onscreen_keyboard;
fpSetLocalPlayerVisibleLocally          Hooking::set_local_player_visible_locally;
fpAiTaskWanderStandard                  Hooking::ai_task_wander_standart;
fpAiTaskPlayAnim                        Hooking::ai_task_play_anim;
fpIsModelInCdimage                      Hooking::is_model_in_cdimage;
fpIsModelValid                          Hooking::is_model_valid;
fpIsModelAVehicle                       Hooking::is_model_a_vehicle;
fpRequestModel                          Hooking::request_model;
fpHasModelLoaded                        Hooking::has_model_loaded;
fpGetPedLastWeaponImpactCoord           Hooking::get_ped_last_weapon_impact_coord;
fpStartRayCast                          Hooking::start_ray_cast;
fpGetRayCast                            Hooking::get_ray_cast;
fpNetworkSetInSpectatorMode             Hooking::set_in_spectator_mode;
fpSetPedCombatAbility                   Hooking::set_ped_combat_ability;
fpAiTaskCombatPed                       Hooking::ai_task_combat_ped;
fpApplyVehicleColors                    Hooking::apply_vehicle_colors;
fpSetPlayerVisibleLocally               Hooking::set_player_visible_locally;
fpSetModelAsNoLongerNeeded              Hooking::set_model_as_no_longer_needed;
fpCreateObject                          Hooking::create_object;
fpSetOverrideWeather                    Hooking::set_override_weather;
fpGetCurrentPedWeapon                   Hooking::get_current_ped_weapon;
fpGetTextScreenLineCount                Hooking::get_text_screen_line_count;
fpRequestScaleformMovie                 Hooking::request_scaleform_movie;
fpDrawScaleformMovie                    Hooking::draw_scaleform_movie;
fpEndScaleformMovieMethod               Hooking::end_scaleform_movie_method;
fpIsDisabledControlPressed              Hooking::is_disabled_control_pressed;
fpIsPlayerFriend                        Hooking::is_player_friend;
fpGetLabelText                          Hooking::GetLabelText = nullptr;
fpGetScriptHandlerIfNetworked           Hooking::GetScriptHandlerIfNetworked = nullptr;
fpGetScriptHandler                      Hooking::GetScriptHandler = nullptr;

CViewPort*				Hooking::m_viewPort;
screenReso*				Hooking::m_resolution;
void*					Hooking::m_objectHashTable;
void*					Hooking::m_objectHashTableSectionEnd;
void*					Hooking::m_onlineName;
CTextInfo*				Hooking::m_textInfo;
char*					Hooking::m_onscreenKeyboardResult;
clockTime*				Hooking::m_clockTime;
uint64_t*				Hooking::m_networkTime;
MemoryPool**			Hooking::m_pedPool;
void*					Hooking::m_gameInfo;
CPlayers*				Hooking::m_players;
MemoryPool**			Hooking::m_entityPool;

static eGameState* 											m_gameState;
static uint64_t												m_worldPtr;
static BlipList*											m_blipList;
static Hooking::NativeRegistrationNew**						m_registrationTable;
static std::unordered_map<uint64_t, Hooking::NativeHandler>	m_handlerCache;
static std::vector<LPVOID>									m_hookedNative;
static __int64**                                            m_globalPtr;

const int EVENT_COUNT = 78;
static std::vector<void*> EventPtr;
static char EventRestore[EVENT_COUNT] = {};

bool twoBytes::empty()
{
	bool	r = true;
	for (int i = 0; i < 2; ++i)
		if (this->byte[i] != 0)
		{
			r = false;
			break;
		}
	return r;
}

bool threeBytes::empty()
{
	bool	r = true;
	for (int i = 0; i < 3; ++i)
		if (this->byte[i] != 0)
		{
			r = false;
			break;
		}
	return r;
}

/* Start Hooking */

void Hooking::Start(HMODULE hmoduleDLL)
{
	std::shared_ptr<HotkeyScript> ptr_hotkey = std::make_shared<HotkeyScript>();
	std::shared_ptr<UpdateScript> ptr_update = std::make_shared<UpdateScript>();
	std::shared_ptr<DisplayScript> ptr_display = std::make_shared<DisplayScript>();
	std::shared_ptr<ControlScript> ptr_control = std::make_shared<ControlScript>();

	Thread::AddScript(ptr_control);
	Thread::AddScript(ptr_update);
	Thread::AddScript(ptr_hotkey);
	Thread::AddScript(ptr_display);

	Log::Msg("Started Hooking");
	if ((int)hmoduleDLL < 0) {
		Log::Msg("Module Address: 0x%i", (int)hmoduleDLL * -1);
	}
	else {
		Log::Msg("Module Address: 0x%i", (int)hmoduleDLL);
	}
	//nt_query_mem = GetProcAddress(LoadLibrary((LPCWSTR)"ntdll.dll"), "NtQueryVirtualMemory");
	_hmoduleDLL = hmoduleDLL;
	scriptDLL = hmoduleDLL;
	Log::Init(hmoduleDLL);
	FindPatterns();
	if (!InitializeHooks()) Cleanup();
}
BOOL Hooking::InitializeHooks()
{
	BOOL returnVal = TRUE;

	if (!iHook.Initialize()) {

		Log::Error("Failed to initialize InputHook");
		returnVal = FALSE;
	}

	if (MH_Initialize() != MH_OK) {
		Log::Error("MinHook failed to initialize");
		returnVal = FALSE;
	}

	if (!HookNatives()) { //if (!MAIN_HOOK_CONTROLLER())

		Log::Error("Failed to initialize NativeHooks");
		returnVal = FALSE;
	}

	return returnVal;
}

template <typename T>
bool Native(DWORD64 hash, LPVOID hookFunction, T** trampoline)
{
	if (*reinterpret_cast<LPVOID*>(trampoline) != NULL)
		return true;
	auto originalFunction = Hooking::GetNativeHandler(hash);
	if (originalFunction != 0) {
		MH_STATUS createHookStatus = MH_CreateHook(originalFunction, hookFunction, reinterpret_cast<LPVOID*>(trampoline));
		if (((createHookStatus == MH_OK) || (createHookStatus == MH_ERROR_ALREADY_CREATED)) && (MH_EnableHook(originalFunction) == MH_OK))
		{
			m_hookedNative.push_back((LPVOID)originalFunction);
			DEBUGMSG("Hooked Native 0x%#p", hash);
			return true;
		}
	}

	return false;
}

uint64_t CMetaData::m_begin = 0;
uint64_t CMetaData::m_end = 0;
DWORD CMetaData::m_size = 0;

uint64_t CMetaData::begin()
{
	return m_begin;
}
uint64_t CMetaData::end()
{
	return m_end;
}
DWORD CMetaData::size()
{
	return m_size;
}

void CMetaData::init()
{
	if (m_begin && m_size)
		return;

	m_begin = (uint64_t)GetModuleHandleA(nullptr);
	const IMAGE_DOS_HEADER*	headerDos = (const IMAGE_DOS_HEADER*)m_begin;
	const IMAGE_NT_HEADERS*	headerNt = (const IMAGE_NT_HEADERS64*)((const BYTE*)headerDos + headerDos->e_lfanew);
	m_size = headerNt->OptionalHeader.SizeOfCode;
	m_end = m_begin + m_size;
	return;
}
fpIsDLCPresent	OG_IS_DLC_PRESENT = nullptr;
BOOL __cdecl HK_IS_DLC_PRESENT(uint32_t dlchash)
{
	static uint64_t	last = 0;
	uint64_t		cur = *Hooking::m_frameCount;
	if (last != cur)
	{
		last = cur;
		Hooking::onTickInit();
	}
	if (Hooking::rdev && dlchash == 2532323046) return true;
	return OG_IS_DLC_PRESENT(dlchash);
}

fpGetLabelText ogGetLabelText = nullptr;
const char* __cdecl hkGetLabelText(void *this_, const char *label)
{
	if (std::strcmp(label, "HUD_JOINING") == 0)
	{
		return Hooking::loading_text;
	}

	/*if (std::strcmp(label, "HUD_TRANSP") == 0) 
	{
		return Hooking::loading_text;
	}*/

	return ogGetLabelText(this_, label);
}

fpEventHandler OG_EVENT_HANDLER = nullptr;
bool __cdecl HK_EVENT_HANDLER(__int64 eventName, __int64 player, __int64 status, unsigned __int16 eventId, int unk, int eventHash, __int64 data1, __int64 data2) {
	
	/*if (player != PLAYER::PLAYER_ID() && player != PLAYER::PLAYER_PED_ID()) {
		if (Hooking::e_weather_time) {
			if (eventId == GAME_WEATHER_EVENT) {
				if (Hooking::e_notify) {
					ostringstream oss; oss << "~r~" << PLAYER::GET_PLAYER_NAME(Features::index_to_id(player)) << " tried to change the weather.";
					notifyMap(oss.str());
				}
				
				if (Hooking::e_redirect) {
					Hooking::set_session_weather(1, 13, 76, 0);
				}
				return false;
			}
			if (eventId == GAME_CLOCK_EVENT) {
				if (Hooking::e_notify) {
					ostringstream oss; oss << "~r~" << PLAYER::GET_PLAYER_NAME(Features::index_to_id(player)) << " tried to change the time.";
					notifyMap(oss.str());
				}
				
				if (Hooking::e_redirect) {
					
				}
				return false;
			}
		}

		if (Hooking::e_control) {
			if (eventId == REQUEST_CONTROL_EVENT || eventId == GIVE_CONTROL_EVENT || eventId == VEHICLE_COMPONENT_CONTROL_EVENT) {
				if (Hooking::e_notify) {
					ostringstream oss; oss << "~r~" << PLAYER::GET_PLAYER_NAME(Features::index_to_id(player)) << " tried to control you.";
					notifyMap(oss.str());
				}
				
				if (Hooking::e_redirect) {
					RequestControlOfEnt(player);
				}
				return false;
			}
		}

		if (Hooking::e_pickup) {
			if (eventId == REQUEST_PICKUP_EVENT || eventId == REQUEST_MAP_PICKUP_EVENT) {
				if (Hooking::e_notify) {
					ostringstream oss; oss << "~r~" << PLAYER::GET_PLAYER_NAME(Features::index_to_id(player)) << " tried to drop stuff.";
					notifyMap(oss.str());
				}
				
				if (Hooking::e_redirect) {
					Features::customDrop(player);
				}
				return false;
			}
		}

		if (Hooking::e_weapon) {
			if (eventId == GIVE_WEAPON_EVENT) {
				if (Hooking::e_notify) {
					ostringstream oss; oss << "~r~" << PLAYER::GET_PLAYER_NAME(Features::index_to_id(player)) << " tried to give you weapons.";
					notifyMap(oss.str());
				}
				
				if (Hooking::e_redirect) {
					
				}
				return false;
			}
			if (eventId == REMOVE_WEAPON_EVENT || eventId == REMOVE_ALL_WEAPONS_EVENT) {
				if (Hooking::e_notify) {
					ostringstream oss; oss << "~r~" << PLAYER::GET_PLAYER_NAME(Features::index_to_id(player)) << " tried to remove your weapons.";
					notifyMap(oss.str());
				}
				
				if (Hooking::e_redirect) {
					WEAPON::REMOVE_ALL_PED_WEAPONS(player, true);
					WEAPON::REMOVE_ALL_PED_WEAPONS(player, false);
				}
				return false;
			}
		}

		if (Hooking::e_wanted) {
			if (eventId == ALTER_WANTED_LEVEL_EVENT) {
				if (Hooking::e_notify) {
					ostringstream oss; oss << "~r~" << PLAYER::GET_PLAYER_NAME(Features::index_to_id(player)) << " tried to change your wanted level.";
					notifyMap(oss.str());
				}
				
				if (Hooking::e_redirect) {
					Features::giveWanted(player);
				}
				return false;
			}
		}

		if (Hooking::e_ptfx) {
			if (eventId == NETWORK_PTFX_EVENT) {
				if (Hooking::e_notify) {
					ostringstream oss; oss << "~r~" << PLAYER::GET_PLAYER_NAME(Features::index_to_id(player)) << " tried to show particles.";
					notifyMap(oss.str());
				}
				
				if (Hooking::e_redirect) {

				}
				return false;
			}
		}

		if (Hooking::e_stat) {
			if (eventId == NETWORK_BANK_REQUEST_EVENT || eventId == NETWORK_INCREMENT_STAT_EVENT) {
				if (Hooking::e_notify) {
					ostringstream oss; oss << "~r~" << PLAYER::GET_PLAYER_NAME(Features::index_to_id(player)) << " tried to change your stats.";
					notifyMap(oss.str());
				}
				
				if (Hooking::e_redirect) {

				}
				return false;
			}
		}

		if (Hooking::e_report) {
			if (eventId == PLAYER_CARD_STAT_EVENT || eventId == REPORT_MYSELF_EVENT || eventId == REPORT_CASH_SPAWN_EVENT) {
				if (Hooking::e_notify) {
					ostringstream oss; oss << "~r~" << PLAYER::GET_PLAYER_NAME(Features::index_to_id(player)) << " tried to report you.";
					notifyMap(oss.str());
				}
				
				if (Hooking::e_redirect) {

				}
				return false;
			}
		}

		if (Hooking::e_kick) {
			globalHandle(1377446).At(594).As<int>() = 594; //SP kick
			globalHandle(1377446).At(595).As<int>() = 595; //kick
			globalHandle(1382674).At(584).As<int>() = 584; //superkick IV
			if (eventId == REMOTE_SCRIPT_LEAVE_EVENT || eventId == KICK_VOTES_EVENT) {
				if (Hooking::e_notify) {
					ostringstream oss; oss << "~r~" << PLAYER::GET_PLAYER_NAME(Features::index_to_id(player)) << " tried to kick you.";
					notifyMap(oss.str());
				}
				
				if (Hooking::e_redirect) {
					Features::kick2(Features::index_to_id(player));
				}
				return false;
			}
		}

		if (Hooking::e_explosion) {
			if (eventId == FIRE_EVENT || eventId == EXPLOSION_EVENT || eventId == REQUEST_PHONE_EXPLOSION_EVENT || eventId == BLOW_UP_VEHICLE_EVENT) {
				if (Hooking::e_notify) {
					ostringstream oss; oss << "~r~" << PLAYER::GET_PLAYER_NAME(Features::index_to_id(player)) << " tried to explode you.";
					notifyMap(oss.str());
				}
				
				if (Hooking::e_redirect) {
					Vector3 crd = coordsOf(player);
					FIRE::ADD_EXPLOSION(crd.x, crd.y, crd.z, 0, 5.0f, true, false, 0.1f);
				}
				return false;
			}
		}

		if (Hooking::e_freeze) {
			if (eventId == RAGDOLL_REQUEST_EVENT || eventId == INCIDENT_ENTITY_EVENT || eventId == CLEAR_AREA_EVENT || eventId == CLEAR_RECTANGLE_AREA_EVENT || eventId == NETWORK_CLEAR_PED_TASKS_EVENT || eventId == NETWORK_SOUND_CAR_HORN_EVENT || eventId == NETWORK_PLAY_SOUND_EVENT || eventId == NETWORK_STOP_SOUND_EVENT || eventId == NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT) {
				if (Hooking::e_notify) {
					ostringstream oss; oss << "~r~" << PLAYER::GET_PLAYER_NAME(Features::index_to_id(player)) << " tried to freeze you.";
					notifyMap(oss.str());
				}
				
				if (Hooking::e_redirect) {
					AI::CLEAR_PED_TASKS_IMMEDIATELY(player);
					AI::CLEAR_PED_TASKS(player);
					AI::CLEAR_PED_SECONDARY_TASK(player);
				}
				return false;
			}
		}

		if (Hooking::event_handler_on) {
			for (__int16 i = 0; i < 78; i++) {
				if (eventId == i) {
					ostringstream oss; oss << "~r~" << Features::event_id_to_string(eventName) << " blocked from " << PLAYER::GET_PLAYER_NAME(Features::index_to_id(player));
					notifyMap(oss.str());
					return false;
				}
			}
		}
	}*/
	
    DWORD numArgs = *reinterpret_cast<DWORD*>(eventName + 0x224);
	__int64* args = reinterpret_cast<__int64*>(eventName + 0x70);
	BYTE senderID = *reinterpret_cast<BYTE*>(player + 0x2D);
	__int64 receiverID = args[2];
	char* evName = reinterpret_cast<char*>(*reinterpret_cast<__int64*>(eventName + 0x8 * eventId + 0x3AE58));
	char* plName = PLAYER::GET_PLAYER_NAME(senderID);

	if (Hooking::event_handler_on) {

		ostringstream oss; oss << evName << " sent by " << plName;
		notifyMap(oss.str());
		return false;

		//ostringstream oss; oss << evName << " sent by " << plName;
		//notifyMap(oss.str());
		//return false;

		/*if (strcmp(evName, "EXPLOSION_EVENT") == 0) {
			ostringstream oss; oss << plName << " tried to explode you!";
			notifyMap(oss.str());
			return false;
		}

		if (strcmp(evName, "NETWORK_CLEAR_PED_TASKS_EVENT") == 0) {
			ostringstream oss; oss << plName << " tried to freeze you!";
			notifyMap(oss.str());
			return false;
		}*/
	}

	return OG_EVENT_HANDLER(eventName, player, status, eventId, unk, eventHash, data1, data2);
}

/*auto numOfArgs = *reinterpret_cast<DWORD*>(a1 + 0x224); //IDA: Line 10
	auto current_args = reinterpret_cast<__int64*>(a1 + 0x70); //IDA: Line 17
	auto eventSenderID = *reinterpret_cast<BYTE*>(a2 + 0x2D);
	const auto receiver_id = current_args[1];

	if (Hooking::event_handler_on) {

	}

	return OG_EVENT_HANDLER(a1, a2);*/

fpStatSetInt OG_STAT_SET_INT = nullptr;
bool Hooking::reportNotification = false;
bool __cdecl HK_STAT_SET_INT(Hash statName, int value, bool save)
{
	switch (statName)
	{
	case 0x9C6A0C42: //MPPLY_GRIEFING
	case 0x62EB8C5A: //MPPLY_VC_ANNOYINGME
	case 0x0E7072CD: //MPPLY_VC_HATE
	case 0x762F9994: //MPPLY_TC_ANNOYINGME
	case 0xB722D6C0: //MPPLY_TC_HATE
	case 0x3CDB43E2: //MPPLY_OFFENSIVE_LANGUAGE
	case 0xE8FB6DD5: //MPPLY_OFFENSIVE_TAGPLATE
	case 0xF3DE4879: //MPPLY_OFFENSIVE_UGC
	case 0xAA238FF0: //MPPLY_BAD_CREW_NAME
	case 0x03511A79: //MPPLY_BAD_CREW_MOTTO
	case 0x3B566D5C: //MPPLY_BAD_CREW_STATUS
	case 0x368F6FD9: //MPPLY_BAD_CREW_EMBLEM
	case 0xCBFD04A4: //MPPLY_GAME_EXPLOITS
	case 0x9F79BA0B: //MPPLY_EXPLOITS
	{
		notifyMap("Blocked bad stat: 0x%08X Value: %i", statName, value);
		Log::Msg("Blocked bad stat: 0x%08X Value: %i", statName, value);
		return false;
	}
	}
	return OG_STAT_SET_INT(statName, value, save);
} //Report

Hooking::NativeHandler ORIG_WAIT = NULL;
void* __cdecl MY_WAIT(NativeContext *cxt)
{
	static int lastThread = 0;
	int threadId = SCRIPT::GET_ID_OF_THIS_THREAD();
	if (!lastThread)
	{
		char* name = SCRIPT::_GET_NAME_OF_THREAD(threadId);
		if (strcmp(name, "main_persistent") == 0)
		{
			lastThread = threadId;
			Log::Msg("Hooked Script NAME: %s ID: %i", name, threadId);
		}
	}
	if (threadId == lastThread) Hooking::onTickInit();
	ORIG_WAIT(cxt);
	return cxt;
}

Hooking::NativeHandler  ORIG_NETWORK_SESSION_KICK_PLAYER = NULL;
void *__cdecl MY_NETWORK_SESSION_KICK_PLAYER(NativeContext* cxt)
{
	Player player = cxt->GetArgument<int>(0);
	if (player == PLAYER::PLAYER_ID())
	{
		ORIG_NETWORK_SESSION_KICK_PLAYER(cxt);
	}
	return nullptr;
}


Hooking::NativeHandler  ORIG_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE = NULL;
void *__cdecl MY_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(NativeContext* cxt)
{
	Player player = cxt->GetArgument<int>(0);
	if (player == PLAYER::PLAYER_ID())
	{
		ORIG_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(cxt);
	}
	return nullptr;
}

Hooking::NativeHandler  ORIG_ATTACH_ENTITY_TO_ENTITY = NULL;
void *__cdecl MY_ATTACH_ENTITY_TO_ENTITY(NativeContext* cxt)
{
	Player player = cxt->GetArgument<int>(0);
	if (player == PLAYER::PLAYER_ID())
	{
		ORIG_ATTACH_ENTITY_TO_ENTITY(cxt);
	}
	return nullptr;
}

Hooking::NativeHandler ORIG_CLEAR_PED_TASKS_IMMEDIATELY = NULL;
void *__cdecl MY_CLEAR_PED_TASKS_IMMEDIATELY(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLEAR_PED_TASKS_IMMEDIATELY(cxt);
	}

	return nullptr;
}

Hooking::NativeHandler ORIG_CLEAR_PED_TASKS = NULL;
void *__cdecl MY_CLEAR_PED_TASKS(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLEAR_PED_TASKS(cxt);
	}

	return nullptr;
}

Hooking::NativeHandler ORIG_CLEAR_PED_SECONDARY_TASK = NULL;
void *__cdecl MY_CLEAR_PED_SECONDARY_TASK(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLEAR_PED_SECONDARY_TASK(cxt);
	}
	return nullptr;
}

Hooking::NativeHandler ORIG_CLONE_PED = NULL;
void *__cdecl MY_CLONE_PED(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLONE_PED(cxt);
	}
	return nullptr;
}

void notifyCommand(Player player, char* command) {
	ostringstream txt; txt << "Command '" << command << "' used by " << PLAYER::GET_PLAYER_NAME(player);
	UI::SET_TEXT_OUTLINE();
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)txt.str().c_str());
	UI::_DRAW_NOTIFICATION(TRUE, FALSE);
}

fpChatMessage OG_GET_MESSAGE = nullptr;
void __cdecl HK_GET_MESSAGE(__int64 a1, __int64 a2, __int64 a3, char *message) {
	/*if (Features::GodMode) {
		Player sender = Hooking::get_sender(a1, a2, a3); // + 0xC8;
		//int sender = Memory::get_value<int>({ (DWORD)Hooking::get_sender(a3, a2, a3), 0xC8 });
		Log::Msg(std::to_string(sender).c_str());
	}*/
	if (strcmp(message, "!snow on") == 0) {
		Hooking::set_session_weather(1, 13, 76, 0);
	}
	if (strcmp(message, "!snow off") == 0) {
		Hooking::set_session_weather(1, 0, 76, 0);
	}
	if (strcmp(message, "!cancer on") == 0) {
		Features::spamTime = true;
	}
	if (strcmp(message, "!cancer off") == 0) {
		Features::spamTime = false;
	}
	if (strcmp(message, "!time day") == 0) {
		Features::set_network_time(11, 0, 0);
	}
	if (strcmp(message, "!time night") == 0) {
		Features::set_network_time(22, 0, 0);
	}

	/*if (strcmp(message, "!dschihad") == 0) {
		for (int i = 0; i < 33; i++) {
			if (Features::exclude(i)) {
				unsigned int Bit = (1 << i);
				uint64_t rteleport[9] = { 1000837481, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 0, -1, 1, 0, 0, 0, 0 }; //TODO: fix!
				Hooking::trigger_script_event(1, rteleport, 9, Bit);
			}
		}
	}*/

	/*for (int i = 0; i < 656; i++) {
		std::string base_cmd = "!spawn vehicle " + Features::VEHICLE_NAMES[i];
		if (strcmp(message, base_cmd.c_str()) == 0) {
			DWORD model = $(Features::VEHICLE_NAMES[i]);
			if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_A_VEHICLE(model)) {
				if (!STREAMING::HAS_MODEL_LOADED(model)) {
					STREAMING::REQUEST_MODEL(model);
					while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
				}				
				Vector3 coords = coordsOf(PLAYER::PLAYER_PED_ID());
				Vehicle veh = VEHICLE::CREATE_VEHICLE(model, coords.x, coords.y, coords.z, 0, 1, 1);
				VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
				VEHICLE::SET_VEHICLE_IS_STOLEN(veh, 0);
			}
		}
	}*/

	return OG_GET_MESSAGE(a1, a2, a3, message);
}

fpGetScriptHandlerIfNetworked ogGetScriptHandlerIfNetworked = nullptr;
void *hkGetScriptHandlerIfNetworked()
{
	return Hooking::GetScriptHandler();
} //OBJECT_BYPASS

fpIntegrityCheck OG_INTEGRITY_CHECK = nullptr;
bool __cdecl HK_INTEGRITY_CHECK() {
	if (Hooking::patch_checker) {
		return 1;
	}
	return OG_INTEGRITY_CHECK();
}

//MAIN HOOK KEK

fpIsEntityUpsideDown OG_IS_ENTITY_UPSIDEDOWN = nullptr;
bool __cdecl HK_IS_ENTITY_UPSIDEDOWN(Cam cam) {
	static uint64_t	last = 0;
	uint64_t		cur = *Hooking::m_frameCount;
	if (last != cur)
	{
		last = cur;
		Hooking::onTickInit();
	}
	return OG_IS_ENTITY_UPSIDEDOWN(cam);
}

template <typename HookType, typename returnType>
bool createHook(HookType target, std::function<void()> hook) {
	HookType OG_HOOK = nullptr;
	struct CHK {
		static returnType HK_HOOK() {
			hook();
			return OG_HOOK();
		}
	};
	MH_STATUS status;
	status = MH_CreateHook(target, CHK::HK_HOOK, (void**)&OG_HOOK);
	if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(target) != MH_OK)
		return false;
	Hooking::m_hooks.push_back(target);
	return true;
}

static std::size_t get_module_size(HMODULE hmod)
{
	auto dosHeader = PIMAGE_DOS_HEADER(hmod);
	auto ntHeader = PIMAGE_NT_HEADERS(PBYTE(hmod) + dosHeader->e_lfanew);

	return ntHeader->OptionalHeader.SizeOfImage;
}
fpNtQueryVirtualMemory ogNtQueryVirtualMemory = nullptr;
int hkNtQueryVirtualMemory(HANDLE ProcessHandle, PVOID BaseAddress, int MemoryInformationClass, PVOID MemoryInformation, SIZE_T MemoryInformationLength, PSIZE_T ReturnLength)
{
	if (MemoryInformationClass == 0
		&& ProcessHandle == GetCurrentProcess()
		&& std::uintptr_t(BaseAddress) >= std::uintptr_t(_hmoduleDLL)
		&& std::uintptr_t(BaseAddress) <= std::uintptr_t(_hmoduleDLL) + get_module_size(_hmoduleDLL))
	{
		return 0xC000000D;
	}

	return static_cast<decltype(&hkNtQueryVirtualMemory)>(ogNtQueryVirtualMemory)
		(ProcessHandle, BaseAddress, MemoryInformationClass, MemoryInformation, MemoryInformationLength, ReturnLength);
}
fpNtQueryVirtualMemory Hooking::NtQueryVirtualMemory = nullptr;

bool detourHook(LPVOID target, LPVOID hook, LPVOID orig) {
	MH_STATUS status;
	status = MH_CreateHook(target, hook, (void**)&orig);
	if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(target) != MH_OK)
		return false;
	Hooking::m_hooks.push_back(target);
	return true;
}

fpPickupRewardMoneyIsApplicableToPlayer OG_PICKUP_REWARD = nullptr;
bool HK_PICKUP_REWARD(void *thisptr, void *unk, void *ped)
{
	if (Features::moneyDropProtection)
	{
		return false;
	}

	return OG_PICKUP_REWARD(thisptr, unk, ped);
}

void* m_OriginalGetEventData = nullptr;
void* m_OriginalStatsSetInt = nullptr; //Report

//RID
bool Hooking::rid_join = false;
fpIsPlayerFriend OG_IS_PLAYER_FRIEND = nullptr;
BOOL HK_IS_PLAYER_FRIEND(int *handle) {
	if (Hooking::rid_join) return true;

	return OG_IS_PLAYER_FRIEND(handle);
}

bool Hooking::HookNatives()
{
	MH_STATUS status;

	if (enable_coloading) {
		if (Hooking::found_idp) {
			status = MH_CreateHook(Hooking::is_DLC_present, HK_IS_DLC_PRESENT, (void**)&OG_IS_DLC_PRESENT);
			if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::is_DLC_present) != MH_OK)
				return false;
			Hooking::m_hooks.push_back(Hooking::is_DLC_present);
			Log::Msg("Main Hook: IDP");
		}
		else {
			status = MH_CreateHook(Hooking::is_entity_upsidedown, HK_IS_ENTITY_UPSIDEDOWN, (void**)&OG_IS_ENTITY_UPSIDEDOWN);
			if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::is_entity_upsidedown) != MH_OK)
				return false;
			Hooking::m_hooks.push_back(Hooking::is_entity_upsidedown);
			Log::Msg("Main Hook: DCE");
		}

		/*if (Hooking::found_ssi) {
			status = MH_CreateHook(Hooking::stat_set_int, HK_STAT_SET_INT, (void**)&OG_STAT_SET_INT);
			if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::stat_set_int) != MH_OK)
				return false;
			Hooking::m_hooks.push_back(Hooking::stat_set_int);
		}*/

		/*if (Hooking::found_sge) {
			status = MH_CreateHook(Hooking::event_handler, HK_EVENT_HANDLER, (void**)&OG_EVENT_HANDLER);
			if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::event_handler) != MH_OK)
				return false;
			Hooking::m_hooks.push_back(Hooking::event_handler);
		}*/

		/*if (Hooking::found_gcm) {
			status = MH_CreateHook(Hooking::get_message, HK_GET_MESSAGE, (void**)&OG_GET_MESSAGE);
			if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::get_message) != MH_OK)
				return false;
			Hooking::m_hooks.push_back(Hooking::get_message);
		}*/

		if (Hooking::found_glt) {
			status = MH_CreateHook(Hooking::GetLabelText, hkGetLabelText, (void**)&ogGetLabelText);
			if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::GetLabelText) != MH_OK)
				return false;
			Hooking::m_hooks.push_back(Hooking::GetLabelText);
		}

		if (Hooking::found_gsh) {
			status = MH_CreateHook(Hooking::GetScriptHandlerIfNetworked, hkGetScriptHandlerIfNetworked, (void**)&ogGetScriptHandlerIfNetworked);
			if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::GetScriptHandlerIfNetworked) != MH_OK)
				return false;
			Hooking::m_hooks.push_back(Hooking::GetScriptHandlerIfNetworked);
		}

		if (Hooking::found_ged) {
			status = MH_CreateHook(Hooking::get_event_data, &Hooking::GED, &m_OriginalGetEventData);
			if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::get_event_data) != MH_OK)
				return false;
			Hooking::m_hooks.push_back(Hooking::get_event_data);
		}

		if (Hooking::found_nts) {
			status = MH_CreateHook(Hooking::NtQueryVirtualMemory, hkNtQueryVirtualMemory, (void**)&ogNtQueryVirtualMemory);
			if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::NtQueryVirtualMemory) != MH_OK)
				return false;
			Hooking::m_hooks.push_back(Hooking::NtQueryVirtualMemory);
		}

		if (Hooking::found_prw) {
			status = MH_CreateHook(Hooking::pickup_is_applicable_to_player, HK_PICKUP_REWARD, (void**)&OG_PICKUP_REWARD);
			if (status != MH_OK || MH_EnableHook(Hooking::pickup_is_applicable_to_player) != MH_OK)
				return false;
			Hooking::m_hooks.push_back(Hooking::pickup_is_applicable_to_player);
		}

	}
	else {

		status = MH_CreateHook(Hooking::is_DLC_present, HK_IS_DLC_PRESENT, (void**)&OG_IS_DLC_PRESENT);
		if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::is_DLC_present) != MH_OK)
			return false;
		Hooking::m_hooks.push_back(Hooking::is_DLC_present);
		Log::Msg("Main Hook: IDP");

		/*status = MH_CreateHook(Hooking::is_entity_upsidedown, HK_IS_ENTITY_UPSIDEDOWN, (void**)&OG_IS_ENTITY_UPSIDEDOWN);
		if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::is_entity_upsidedown) != MH_OK)
			return false;
		Hooking::m_hooks.push_back(Hooking::is_entity_upsidedown);
		Log::Msg("Main Hook: DCE");*/

		/*status = MH_CreateHook(Hooking::stat_set_int, HK_STAT_SET_INT, (void**)&OG_STAT_SET_INT);
		if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::stat_set_int) != MH_OK)
			return false;
		Hooking::m_hooks.push_back(Hooking::stat_set_int);*/

		/*status = MH_CreateHook(Hooking::event_handler, HK_EVENT_HANDLER, (void**)&OG_EVENT_HANDLER);
		if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::event_handler) != MH_OK)
			return false;
		Hooking::m_hooks.push_back(Hooking::event_handler);*/

		/*status = MH_CreateHook(Hooking::get_message, HK_GET_MESSAGE, (void**)&OG_GET_MESSAGE);
		if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::get_message) != MH_OK)
			return false;
		Hooking::m_hooks.push_back(Hooking::get_message);*/

		status = MH_CreateHook(Hooking::GetLabelText, hkGetLabelText, (void**)&ogGetLabelText);
		if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::GetLabelText) != MH_OK)
			return false;
		Hooking::m_hooks.push_back(Hooking::GetLabelText);

		status = MH_CreateHook(Hooking::GetScriptHandlerIfNetworked, hkGetScriptHandlerIfNetworked, (void**)&ogGetScriptHandlerIfNetworked);
		if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::GetScriptHandlerIfNetworked) != MH_OK)
			return false;
		Hooking::m_hooks.push_back(Hooking::GetScriptHandlerIfNetworked);

		status = MH_CreateHook(Hooking::get_event_data, &Hooking::GED, &m_OriginalGetEventData);
		if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::get_event_data) != MH_OK)
			return false;
		Hooking::m_hooks.push_back(Hooking::get_event_data);

		status = MH_CreateHook(Hooking::NtQueryVirtualMemory, hkNtQueryVirtualMemory, (void**)&ogNtQueryVirtualMemory);
		if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::NtQueryVirtualMemory) != MH_OK)
			return false;
		Hooking::m_hooks.push_back(Hooking::NtQueryVirtualMemory);

		status = MH_CreateHook(Hooking::pickup_is_applicable_to_player, HK_PICKUP_REWARD, (void**)&OG_PICKUP_REWARD);
		if (status != MH_OK || MH_EnableHook(Hooking::pickup_is_applicable_to_player) != MH_OK)
			return false;
		Hooking::m_hooks.push_back(Hooking::pickup_is_applicable_to_player);

	}

	return true;
}


void __stdcall ScriptFunction(LPVOID lpParameter)
{
	try
	{
		ScriptMain();
	}
	catch (...)
	{
		Log::Fatal("Config Error");
	}
}

void Hooking::onTickInit()
{
	mainFiber = IsThreadAFiber() ? GetCurrentFiber() : ConvertThreadToFiber(nullptr);

	if (timeGetTime() < wakeAt)
		return;

	static HANDLE scriptFiber;
	if (scriptFiber)
		SwitchToFiber(scriptFiber);
	else
		scriptFiber = CreateFiber(NULL, ScriptFunction, nullptr);
}

void Hooking::FailPatterns(const char* name)
{
	char buf[4096];
	sprintf_s(buf, "finding %s", name);
	Log::Error(buf);
	Cleanup();
}

/*
//CPatternResult
*/

CPatternResult::CPatternResult(void* pVoid) :
	m_pVoid(pVoid)
{}
CPatternResult::CPatternResult(void* pVoid, void* pBegin, void* pEnd) :
	m_pVoid(pVoid),
	m_pBegin(pBegin),
	m_pEnd(pEnd)
{}
CPatternResult::~CPatternResult() {}

/*
//CPattern Public
*/

CPattern::CPattern(char* szByte, char* szMask) :
	m_szByte(szByte),
	m_szMask(szMask),
	m_bSet(false)
{}
CPattern::~CPattern() {}

CPattern&	CPattern::find(int i, uint64_t startAddress)
{
	match(i, startAddress, false);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPattern&	CPattern::virtual_find(int i, uint64_t startAddress)
{
	match(i, startAddress, true);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPatternResult	CPattern::get(int i)
{
	if (m_result.size() > i)
		return m_result[i];
	return nullptr;
}

/*
//CPattern Private
*/
bool	CPattern::match(int i, uint64_t startAddress, bool virt)
{
	if (m_bSet)
		return false;
	uint64_t	begin = 0;
	uint64_t	end = 0;
	if (!virt)
	{
		CMetaData::init();
		begin = CMetaData::begin() + startAddress;
		end = CMetaData::end();
		if (begin >= end)
			return false;
	}
	int		j = 0;
	do
	{
		if (virt)
			begin = virtual_find_pattern(startAddress, (BYTE*)m_szByte, m_szMask) + 1;
		else
			begin = find_pattern(begin, end, (BYTE*)m_szByte, m_szMask) + 1;
		if (begin == NULL)
			break;
		j++;
	} while (j < i);

	m_bSet = true;
	return true;
}

bool	CPattern::byte_compare(const BYTE* pData, const BYTE* btMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++btMask)
		if (*szMask == 'x' && *pData != *btMask)
			break;
	if ((*szMask) != 0)
		return false;
	return true;
}


uint64_t	CPattern::find_pattern(uint64_t address, uint64_t end, BYTE *btMask, char *szMask)
{
	size_t len = strlen(szMask) + 1;
	for (uint64_t i = 0; i < (end - address - len); i++)
	{
		BYTE*	ptr = (BYTE*)(address + i);
		if (byte_compare(ptr, btMask, szMask))
		{
			m_result.push_back(CPatternResult((void*)(address + i)));
			return address + i;
		}
	}
	return NULL;
}

uint64_t	CPattern::virtual_find_pattern(uint64_t address, BYTE *btMask, char *szMask)
{
	MEMORY_BASIC_INFORMATION mbi;
	char*	pStart = nullptr;
	char*	pEnd = nullptr;
	char*	res = nullptr;
	size_t	maskLen = strlen(szMask);

	while (res == nullptr && sizeof(mbi) == VirtualQuery(pEnd, &mbi, sizeof(mbi)))
	{
		pStart = pEnd;
		pEnd += mbi.RegionSize;
		if (mbi.Protect != PAGE_READWRITE || mbi.State != MEM_COMMIT)
			continue;

		for (int i = 0; pStart < pEnd - maskLen && res == nullptr; ++pStart)
		{
			if (byte_compare((BYTE*)pStart, btMask, szMask))
			{
				m_result.push_back(CPatternResult((void*)pStart, mbi.BaseAddress, pEnd));
				res = pStart;
			}
		}

		mbi = {};
	}
	return (uint64_t)res;
}

void	failPat(const char* name)
{
	Log::Fatal("Failed to find %s pattern.", name);
	exit(0);
}

void Hooking::ownedExplosionBypass(bool toggle)
{
	constexpr twoBytes patched = { 0x39, 0xDB };
	constexpr twoBytes restore = { 0x3B, 0xF8 };
	if (m_ownedExplosionBypass == nullptr) return;
	*m_ownedExplosionBypass = toggle ? patched : restore;
} //OWNED_EXPLOSION

bool Hooking::GED(int eventGroup, int eventIndex, uint64_t* argStruct, int argStructSize)
{
	auto result = static_cast<decltype(&GED)>(m_OriginalGetEventData)(eventGroup, eventIndex, argStruct, argStructSize);

	if (result && Features::antiKick) {
		return false;
	}

	if (result && blockall) {
		char* name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		char buf[30];
		char id[30];
		char sender[30];

		if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(argStruct[1]) != PLAYER::PLAYER_PED_ID() || PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(argStruct[1]) != PLAYER::PLAYER_ID()) {
			unsigned int Bit = (1 << argStruct[1]);
			if (redirect) {
				Hooking::trigger_script_event(1, argStruct, argStructSize, Bit);
			}
			snprintf(id, sizeof(id), "%i", argStruct[0]);
			snprintf(sender, sizeof(sender), "%s", name);
			if (notify) {
				switch (argStruct[0]) {
				case 360381720: notifyMap("~r~%s tried to CEO ban you.", sender); break;
				case -1190833098: notifyMap("~r~%s tried to CEO kick you.", sender); break;
				case -1571039706: notifyMap("~r~%s tried to send you to a mission.", sender); break;
				case 1000837481: notifyMap("~r~%s tried to teleport you.", sender); break;
				case 4119492672: notifyMap("~r~%s tried to invite spam you.", sender); break;
				case -1920290846: notifyMap("~r~%s tried to send an error to you.", sender); break;
				case -181444979: notifyMap("~r~%s tried to show you a banner.", sender); break;
				case -2105858993: notifyMap("~r~%s tried to kick you from the club.", sender); break;
				case 713068249: notifyMap("~r~%s tried to show a notification.", sender); break;
				case 325218053: notifyMap("~r~%s tried to kick you from the vehicle.", sender); break;

				case 2077565911: notifyMap("~r~%s tried to kick you.", sender); break;
				case 4156321: notifyMap("~r~%s tried to kick you.", sender); break;
				case -1662909539: notifyMap("~r~%s tried to kick you.", sender); break;
				case 256346004: notifyMap("~r~%s tried to kick you.", sender); break;
				case -15432926: notifyMap("~r~%s tried to kick you.", sender); break;
				case -1243184386: notifyMap("~r~%s tried to kick you.", sender); break;
				case 1642479322: notifyMap("~r~%s tried to kick you.", sender); break;
				case 27391769: notifyMap("~r~%s tried to kick you.", sender); break;
				case -2136787743: notifyMap("~r~%s tried to kick you.", sender); break;
				case -1289983205: notifyMap("~r~%s tried to kick you.", sender); break;
				case 1586576930: notifyMap("~r~%s tried to kick you.", sender); break;
				case 1093247513: notifyMap("~r~%s tried to kick you.", sender); break;
				case 2021867503: notifyMap("~r~%s tried to kick you.", sender); break;
				case -1184085326: notifyMap("~r~%s tried to kick you.", sender); break;
				case -1996885757: notifyMap("~r~%s tried to kick you.", sender); break;
				case 1178932519: notifyMap("~r~%s tried to kick you.", sender); break;
				case 813647057: notifyMap("~r~%s tried to kick you.", sender); break;
				case -1835749229: notifyMap("~r~%s tried to superkick IV you.", sender); break;
				case -120668417: notifyMap("~r~%s tried to superkick III you.", sender); break;
				case 994306218: notifyMap("~r~%s tried to superkick II you.", sender); break;
				case 2055958901: notifyMap("~r~%s tried to superkick I you.", sender); break;
				case 769347061: notifyMap("~r~%s tried to kick you.", sender); break;
				case 999090520: notifyMap("~r~%s tried to kick you to singleplayer.", sender); break;

				//default: notifyMap("~r~Event %s blocked from %s.", id, sender); break;
				}
				if (logger) {
					Log::Msg("===============================");
					Log::Msg("Blocked event sent by %s", name);
					Log::Msg("Script event group: %i", eventGroup);
					Log::Msg("Script event index: %i", eventIndex);
					Log::Msg("Script event argcount: %i", argStructSize);
					for (std::uint32_t i = 0; i < argStructSize; ++i) {
						Log::Msg("Script event args[%u] : %u", i, argStruct[i]);
					}
				}
			}
		}
		return false;
	}

	else if (result && protect && 
		argStruct[0] == -181444979 | 
		argStruct[0] == 769347061 | 
		argStruct[0] == 1000837481 | 
		argStruct[0] == 4119492672 | 
		argStruct[0] == 769347061 | 
		argStruct[0] == -1190833098 | 
		argStruct[0] == -1920290846 | 
		argStruct[0] == 360381720 | 
		argStruct[0] == -1571039706 | 
		argStruct[0] == 994306218 | 
		argStruct[0] == -1662909539 | 
		argStruct[0] == -120668417 | 
		argStruct[0] == -1835749229 | 
		argStruct[0] == 2055958901 | 
		argStruct[0] == 994306218 | 
		argStruct[0] == 2077565911 | 
		argStruct[0] == 4156321 | 
		argStruct[0] == -1662909539 | 
		argStruct[0] == 256346004 | 
		argStruct[0] == -15432926 | 
		argStruct[0] == -1243184386 | 
		argStruct[0] == 1642479322 | 
		argStruct[0] == 27391769 | 
		argStruct[0] == -2136787743 | 
		argStruct[0] == -1289983205 | 
		argStruct[0] == 1586576930 | 
		argStruct[0] == 1093247513 | 
		argStruct[0] == 2021867503 | 
		argStruct[0] == -1184085326 | 
		argStruct[0] == -1996885757 | 
		argStruct[0] == 1178932519 | 
		argStruct[0] == 813647057
		) {
		char* name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		char buf[30];
		char id[30];
		char sender[30];

		if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(argStruct[1]) != PLAYER::PLAYER_PED_ID() || PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(argStruct[1]) != PLAYER::PLAYER_ID()) {
			unsigned int Bit = (1 << argStruct[1]);
			if (redirect) {
				Hooking::trigger_script_event(1, argStruct, argStructSize, Bit);
			}
			snprintf(id, sizeof(id), "%i", argStruct[0]);
			snprintf(sender, sizeof(sender), "%s", name);
			if (notify) {				
				switch (argStruct[0]) {				
				case 360381720: notifyMap("~r~%s tried to CEO ban you.", sender); break;
				case -1190833098: notifyMap("~r~%s tried to CEO kick you.", sender); break;
				case -1571039706: notifyMap("~r~%s tried to send you to a mission.", sender); break;
				case 1000837481: notifyMap("~r~%s tried to teleport you.", sender); break;
				case 4119492672: notifyMap("~r~%s tried to invite spam you.", sender); break;
				case -1920290846: notifyMap("~r~%s tried to send an error to you.", sender); break;
				case -181444979: notifyMap("~r~%s tried to show you a banner.", sender); break;
				case -2105858993: notifyMap("~r~%s tried to kick you from the club.", sender); break;
				case 713068249: notifyMap("~r~%s tried to show a notification.", sender); break;
				case 325218053: notifyMap("~r~%s tried to kick you from the vehicle.", sender); break;
				case 2077565911: notifyMap("~r~%s tried to kick you.", sender); break;
				case 4156321: notifyMap("~r~%s tried to kick you.", sender); break;
				case -1662909539: notifyMap("~r~%s tried to kick you.", sender); break;
				case 256346004: notifyMap("~r~%s tried to kick you.", sender); break;
				case -15432926: notifyMap("~r~%s tried to kick you.", sender); break;
				case -1243184386: notifyMap("~r~%s tried to kick you.", sender); break;
				case 1642479322: notifyMap("~r~%s tried to kick you.", sender); break;
				case 27391769: notifyMap("~r~%s tried to kick you.", sender); break;
				case -2136787743: notifyMap("~r~%s tried to kick you.", sender); break;
				case -1289983205: notifyMap("~r~%s tried to kick you.", sender); break;
				case 1586576930: notifyMap("~r~%s tried to kick you.", sender); break;
				case 1093247513: notifyMap("~r~%s tried to kick you.", sender); break;
				case 2021867503: notifyMap("~r~%s tried to kick you.", sender); break;
				case -1184085326: notifyMap("~r~%s tried to kick you.", sender); break;
				case -1996885757: notifyMap("~r~%s tried to kick you.", sender); break;
				case 1178932519: notifyMap("~r~%s tried to kick you.", sender); break;
				case 813647057: notifyMap("~r~%s tried to kick you.", sender); break;
				case -1835749229: notifyMap("~r~%s tried to superkick IV you.", sender); break;
				case -120668417: notifyMap("~r~%s tried to superkick III you.", sender); break;
				case 994306218: notifyMap("~r~%s tried to superkick II you.", sender); break;
				case 2055958901: notifyMap("~r~%s tried to superkick I you.", sender); break;
				case 769347061: notifyMap("~r~%s tried to kick you.", sender); break;
				case 999090520: notifyMap("~r~%s tried to kick you to singleplayer.", sender); break;

				//default: notifyMap("~r~Event %s blocked from %s.", id, sender); break;
				}
				if (logger) {
					Log::Msg("===============================");
					Log::Msg("Blocked event sent by %s", name);
					Log::Msg("Script event group: %i", eventGroup);
					Log::Msg("Script event index: %i", eventIndex);
					Log::Msg("Script event argcount: %i", argStructSize);
					for (std::uint32_t i = 0; i < argStructSize; ++i) {
						Log::Msg("Script event args[%u] : %u", i, argStruct[i]);
					}
				}
			}			
		}
		return false;
	}

	else if (result && dump)
	{
		Log::Msg("===============================");
		Log::Msg(PLAYER::GET_PLAYER_NAME(argStruct[1]));
		Log::Msg("Script event group: %i", eventGroup);
		Log::Msg("Script event index: %i", eventIndex);
		Log::Msg("Script event argcount: %i", argStructSize);
		for (std::uint32_t i = 0; i < argStructSize; ++i) {
			Log::Msg("Script event args[%u] : %u", i, argStruct[i]);
		}

		return result;
	}

	/*else if (result && smart_protex)
	{
		char* pname = PLAYER::GET_PLAYER_NAME(argStruct[1]);
		const char* invalid[] = { "**INVALID**", "**invalid**", "**Invalid**" };
		if (pname != invalid[0] && pname != invalid[1] && pname != invalid[2] && pname != PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())) {
			Features::write2("X-Folder/script_events.txt", std::to_string(argStruct[0]));
			Log::Msg("Added event to blacklist: %u", argStruct[0]);
		}
	}*/

	else if (result && smart_pro) {
		if (Features::CheckWord("X-Folder/script_events.txt", (char*)std::to_string(argStruct[0]).c_str())) {
			char* name = PLAYER::GET_PLAYER_NAME(argStruct[1]);
			char buf[30];
			char id[30];
			char sender[30];
			unsigned int Bit = (1 << argStruct[1]);
			if (redirect) {
				//Hooking::trigger_script_event(1, argStruct, argStructSize, Bit);
			}
			snprintf(id, sizeof(id), "%i", argStruct[0]);
			snprintf(sender, sizeof(sender), "%s", name);
			if (notify) {
				notifyMap("~r~Blacklisted event %s blocked from %s.", id, sender);
				Log::Msg("===============================");
				Log::Msg("Blocked event sent by %s", name);
				Log::Msg("Script event group: %i", eventGroup);
				Log::Msg("Script event index: %i", eventIndex);
				Log::Msg("Script event argcount: %i", argStructSize);
				for (std::uint32_t i = 0; i < argStructSize; ++i) {
					Log::Msg("Script event args[%u] : %u", i, argStruct[i]);
				}
			}
			return false;
		}
		else return result;
	}

	return result;
}

template <typename T>
void	setPat
(
	char*	    name,
	char*		pat,
	char*		mask,
	T**			out,
	bool		rel,
	int			offset = 0,
	int			deref = 0,
	int			skip = 0
)
{
	T*	ptr = nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	if (rel)
		ptr = pattern.get(skip).get_rel<T>(offset);
	else
		ptr = pattern.get(skip).get<T>(offset);

	while (true)
	{
		if (ptr == nullptr) {
			//failPat(name);		
			if (enable_coloading) {
				Log::Msg("Skipped %s pattern", name);
			}
			else {
				failPat(name);
			}
		}			

		if (deref <= 0)
			break;
		ptr = *(T**)ptr;
		--deref;
	}

	*out = ptr;
	return;
}

template <typename T>
void	setFn
(
	char*	    name,
	char*		pat,
	char*		mask,
	T*			out,
	int			skip = 0
)
{
	char*	ptr = nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	ptr = pattern.get(skip).get<char>(0);

	if (ptr == nullptr) {
		//failPat(name);
		if (enable_coloading) {
			Log::Msg("Skipped %s pattern", name);
		}
		else {
			failPat(name);
		}
	}
	else {
		Hooking::foundPtr(name);
	}

	*out = (T)ptr;
	return;
}

void HookMsg(std::string txt, bool hooked = false) {
	hooked ? Log::Msg("Found %s -> Hooked", txt) : Log::Msg("Found %s", txt);
}

//Add if-checker to native hooks
bool Hooking::found_idp = false;
bool Hooking::found_dce = false;
bool Hooking::found_ssi = false;
bool Hooking::found_sge = false;
bool Hooking::found_gcm = false;
bool Hooking::found_glt = false;
bool Hooking::found_gsh = false;
bool Hooking::found_ged = false;
bool Hooking::found_nts = false;
bool Hooking::found_prw = false;

void Hooking::foundPtr(char *name) {
	char* hptr[] = { 
		"is_dlc_present", 
		"does_cam_exist", 
		"stat_set_int", 
		"get_event_data", 
		"scripted_game_event", 
		"get_label_text", 
		"get_network_script_handler",
		"get_msg",
		"nt_status",
		"pickup_reward"
	};

	if (strcmp(name, hptr[0]) == 0) {
		found_idp = true;
	}

	if (strcmp(name, hptr[1]) == 0) {
		found_dce = true;
	}

	if (strcmp(name, hptr[2]) == 0) {
		found_ssi = true;
	}

	if (strcmp(name, hptr[3]) == 0) {
		found_ged = true;
	}

	if (strcmp(name, hptr[4]) == 0) {
		found_sge = true;
	}

	if (strcmp(name, hptr[5]) == 0) {
		found_glt = true;
	}

	if (strcmp(name, hptr[6]) == 0) {
		found_gsh = true;
	}

	if (strcmp(name, hptr[7]) == 0) {
		found_gcm = true;
	}

	if (strcmp(name, hptr[8]) == 0) {
		found_nts = true;
	}

	if (strcmp(name, hptr[9]) == 0) {
		found_prw = true;
	}

}

void Hooking::FindPatterns()
{
	HANDLE steam = GetModuleHandleA("steam_api64.dll");

	auto p_activeThread = pattern("E8 ? ? ? ? 48 8B 88 10 01 00 00");
	auto p_blipList = pattern("4C 8D 05 ? ? ? ? 0F B7 C1");
	auto p_fixVector3Result = pattern("83 79 18 00 48 8B D1 74 4A FF 4A 18");
	auto p_gameLegals = pattern("72 1F E8 ? ? ? ? 8B 0D");
	auto p_gameLogos = pattern("70 6C 61 74 66 6F 72 6D 3A");
	auto p_gameState = pattern("83 3D ? ? ? ? ? 8A D9 74 0A");
	auto p_modelCheck = pattern("48 85 C0 0F 84 ? ? ? ? 8B 48 50");
	auto p_nativeTable = pattern("76 32 48 8B 53 40 48 8D 0D");
	auto p_worldPtr = pattern("48 8B 05 ? ? ? ? 45 ? ? ? ? 48 8B 48 08 48 85 C9 74 07");
	auto p_globalPtr = pattern("4C 8D 05 ? ? ? ? 4D 8B 08 4D 85 C9 74 11");
	auto p_eventHook = pattern("48 83 EC 28 E8 ? ? ? ? 48 8B 0D ? ? ? ? 4C 8D 0D ? ? ? ? 4C 8D 05 ? ? ? ? BA 03");
	auto p_chatnameaddr = pattern("48 8B 05 ? ? ? ? C3 8A D1");

	HookMsg("AT");
	HookMsg("BL");
	HookMsg("FVR");
	HookMsg("GLE");
	HookMsg("GLO");
	HookMsg("MC");
	HookMsg("NT");
	HookMsg("WPT");
	HookMsg("GPT");
	HookMsg("EHK");
	HookMsg("GB"); //Gamebuild
	HookMsg("CNA", true); //Chatname ptr
	HookMsg("ICHK", true); //Integrity Check bypass

	char * c_location = nullptr;
	void * v_location = nullptr;

	setPat<uint64_t>("frame count",
		"\x8B\x15\x00\x00\x00\x00\x41\xFF\xCF",
		"xx????xxx",
		&Hooking::m_frameCount,
		true,
		2);
	HookMsg("FC", true);

	setFn<fpIsDLCPresent>("is_dlc_present",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x81\xF9\x00\x00\x00\x00",
		"xxxx?xxxxxxx????",
		&Hooking::is_DLC_present);
	HookMsg("IDP", true);

	setFn<fpGetScriptHandlerIfNetworked>("get_network_script_handler",
		"\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x12\x48\x8B\x10\x48\x8B\xC8",
		"xxxxxxx????xxxxxxxxxxxxxx",
		&Hooking::GetScriptHandlerIfNetworked);
	HookMsg("GSHIN", true);

	setFn<fpGetScriptHandler>("get_script_handler",
		"\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x33\xC9\x48\x85\xC0\x74\x0C\xE8\x00\x00\x00\x00\x48\x8B\x88\x00\x00\x00\x00",
		"xxxxx????xxxxxxxx????xxx????",
		&Hooking::GetScriptHandler);
	HookMsg("GSH");

	setFn<fpIsEntityUpsideDown>("does_cam_exist",
		"\x40\x53\x48\x83\xEC\x20\x33\xDB\x85\xC9\x78\x10",
		"xxxxxxxxxxxx",
		&Hooking::is_entity_upsidedown);
	HookMsg("DCE", true);

	setPat<twoBytes>("owned explosion bypass",
		"\x3B\xF8\x40\x0F\x94\xC7",
		"xxxxxx",
		&Hooking::m_ownedExplosionBypass,
		false);
	HookMsg("OEB", true);

	setFn<TriggerScriptEvent>("trigger_script_event",
		"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x81\xEC\x00\x00\x00\x00\x45\x8B\xF0\x41\x8B\xF9",
		"xxxxxxxxxxxxxxxxxxxxxxxx????xxxxxx",
		&Hooking::trigger_script_event);
	HookMsg("TSE");

	setFn<SetSessionWeather>("set_session_weather",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30\x40\x8A\xE9",
		"xxxx?xxxx?xxxx?xxxxxxxx",
		&Hooking::set_session_weather);
	HookMsg("SLW");

	/*setFn<fpStatSetInt>("stat_set_int",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x89\x54\x24\x10\x55\x57\x41\x57",
		"xxxx?xxxx?xxxxxxxx",
		&Hooking::stat_set_int);
	HookMsg("SSI", true);*/

	setFn<fpStatSetBool>("stat_set_bool",
		"\x48\x89\x5C\x24\x00\x88\x54\x24\x10\x57\x48\x83\xEC\x40",
		"xxxx?xxxxxxxxx",
		&Hooking::stat_set_bool);
	HookMsg("SSB");

	setFn<fpStatSetFloat>("stat_set_float",
		"\x48\x89\x5C\x24\x00\xF3\x0F\x11\x4C\x24\x00\x57\x48\x83\xEC\x40",
		"xxxx?xxxxx?xxxxx",
		&Hooking::stat_set_float);
	HookMsg("SSF");

	setFn<GetEventData>("get_script_event_data",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x49\x8B\xF8\x4C\x8D\x05\x00\x00\x00\x00",
		"xxxx?xxxxxxxxxxx????",
		&Hooking::get_script_event_data);
	HookMsg("GSED");

	setFn<fpGetEventData>("get_event_data",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x49\x8B\xF8\x4C\x8D\x05\x00\x00\x00\x00",
		"xxxx?xxxxxxxxxxx????",
		&Hooking::get_event_data);
	HookMsg("GED", true);

	setFn<addOwnedExplosion>("add_owned_explosion",
		"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x70\x20\x55\x48\x8D\x68\xB9\x48\x81\xEC\x00\x00\x00\x00\x0F\x29\x70\xE8\x41\x8B\xD8",
		"xxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxxxx",
		&Hooking::add_owned_explosion);
	HookMsg("AOE");

	setFn<fpGetPlayerAddress>("get_player_address",
		"\x40\x53\x48\x83\xEC\x20\x33\xDB\x38\x1D\x00\x00\x00\x00\x74\x1C",
		"xxxxxxxxxx????xx",
		&Hooking::get_player_address);
	HookMsg("GPA");

	setFn<fpAddressToEntity>("address_to_entity",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x15\x00\x00\x00\x00\x48\x8B\xF9\x48\x83\xC1\x10\x33\xDB",
		"xxxx?xxxx?xxxxxxx????xxxxxxxxx",
		&Hooking::address_to_entity);
	HookMsg("ATO");

	setPat<clockTime>("clock_time",
		"\x48\x8D\x0D\x00\x00\x00\x00\x8B\xFA\xE8\x00\x00\x00\x00\x44\x8D\x0C\x5B",
		"xxx????xxx????xxxx",
		&Hooking::ClockTime,
		true, 3);
	HookMsg("CT");

	setFn<fpSetSessionTime>("session_time_set",
		"\x48\x89\x5C\x24\x08\x57\x48\x83\xEC\x20\x8B\xF9\x48\x8B\x0D\x00\x00\x00\x00\x48\x8B\xDA\x33\xD2\xE9\x00\x00\x00\x00",
		"xxxxxxxxxxxxxxx????xxxxxx????",
		&Hooking::set_session_time);
	HookMsg("STS");

	setFn<fpSetEntityMaxHealth>("set_entity_max_health",
		"\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x19\x4C\x8B\x00\x8B\x15\x00\x00\x00\x00\x48\x8B\xC8\x41\xFF\x50\x08\x84\xC0\x74\x05\x48\x8B\xC3\xEB\x02\x33\xC0\x48\x83\xC4\x20\x5B\xC3\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x56\x57",
		"xxxxxxx????xxxxxxxxxx?xx????xxxxxxxxxxxxxxxxxxxxxxxxxxxx?xxxx?xx",
		&Hooking::set_entity_max_health);
	HookMsg("SEMH");

	setFn<fpCreateVehicle>("create_vehicle",
		"\x48\x89\x5C\x24\x00\x55\x56\x57\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8B\xEC\x48\x83\xEC\x50\xF3\x0F\x10\x02",
		"xxxx?xxxxxxxxxxxxxxxxxxxxxx",
		&Hooking::create_vehicle);
	HookMsg("CV");

	setFn<fpClearPedTasksImmediately>("clear_ped_tasks_immediately",
		"\x40\x53\x48\x83\xEC\x30\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x0F\x84",
		"xxxxxxx????xxxxxxxx",
		&Hooking::clear_ped_tasks_immediately);
	HookMsg("CPTI");

	setFn<fpGetNumberOfEvents>("get_number_of_events",
		"\x48\x83\xEC\x28\x33\xD2\x85\xC9",
		"xxxxxxxx",
		&Hooking::get_number_of_events);
	HookMsg("GNOE");

	/*setFn<fpNetworkIsSessionStarted>("is_session_started",
		"\x48\x8B\x0D\x00\x00\x00\x00\x33\xC0\x48\x85\xC9\x74\x0E\x83\xB9\x00\x00\x00\x00\x00\x75\x05",
		"xxx????xxxxxxxxx?????xx",
		&Hooking::is_session_started);
	HookMsg("ISS");*/

	setFn<fpNetworkRequestControlOfNetworkId>("request_control_of_network_id",
		"\x40\x53\x48\x83\xEC\x20\x8B\xD9\xE8\x00\x00\x00\x00\x8B\xD3\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x2C",
		"xxxxxxxxx????xxxxxx????xxxxx",
		&Hooking::request_control_of_network_id);
	HookMsg("RCONI");

	setFn<fpNetworkRequestControlOfEntity>("request_control_of_entity",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xD9\xE8\x00\x00\x00\x00\x84\xC0",
		"xxxx?xxxxxxxx????xx",
		&Hooking::request_control_of_entity);
	HookMsg("RCOE");

	setFn<fpNetworkHasControlOfEntity>("has_control_of_entity",
		"\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x1F\x48\x8B\x88\x00\x00\x00\x00\x48\x85\xC9\x74\x0F",
		"xxxxx????xxxxxxxx????xxxxx",
		&Hooking::has_control_of_entity);
	HookMsg("HCOE");

	setFn<fpSetNetworkIdCanMigrate>("set_network_id_can_migrate",
		"\x85\xC9\x0F\x8E\x00\x00\x00\x00\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8A\xDA",
		"xxxx????xxxx?xxxxxxx",
		&Hooking::set_network_id_can_migrate);
	HookMsg("SNICM");

	setFn<fpGetNetworkTime>("get_network_time",
		"\x40\x53\x48\x83\xEC\x20\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x84\xC0\x74\x19",
		"xxxxxxxxx????x????xxxx",
		&Hooking::get_network_time);
	HookMsg("GNT");

	setFn<fpDecorSetInt>("decor_set_int",
		"\x48\x89\x5C\x24\x00\x44\x89\x44\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x22\x48\x8B\xD7\x33\xC9\xE8\x00\x00\x00\x00\x4C\x8D\x44\x24\x00\x48\x8D\x54\x24\x00\x48\x8B\xCB\x89\x44\x24\x48\xE8\x00\x00\x00\x00\xB0\x01",
		"xxxx?xxxx?xxxxxxxxx????xxxxxxxxxxxxxx????xxxx?xxxx?xxxxxxxx????xx",
		&Hooking::decor_set_int);
	HookMsg("DSI");

	setFn<fpDecorRegister>("decor_register",
		"\x40\x53\x48\x83\xEC\x20\x80\x3D\x00\x00\x00\x00\x00\x8B\xDA\x75\x29",
		"xxxxxxxx?????xxxx",
		&Hooking::decor_register);
	HookMsg("DR");

	setFn<fpChatMessage>("get_msg",
		"\x4D\x85\xC9\x0F\x84\x00\x00\x00\x00\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x48\x20",
		"xxxxx????xxxxxxxxxxxxxxxxxxx",
		&Hooking::get_message);
	HookMsg("GCM", true);

	setFn<fpGetSender>("get_sender",
		"\xE8\x00\x00\x00\x00\x8A\x40\x2D",
		"x????xxx",
		&Hooking::get_sender);
	HookMsg("GCS");

	/*setFn<fpGetPlayerName>("get_player_name",
		"\x40\x53\x48\x83\xEC\x20\x80\x3D\x00\x00\x00\x00\x00\x8B\xD9\x74\x22",
		"xxxxxxxx?????xxxx",
		&Hooking::GPN);
	HookMsg("GPN");
*/
	setPat<CReplayInterface>("replay interface",
		"\x48\x8D\x0D\x00\x00\x00\x00\x48\x8B\xD7\xE8\x00\x00\x00\x00\x48\x8D\x0D\x00\x00\x00\x00\x8A\xD8\xE8\x00\x00\x00\x00\x84\xDB\x75\x13\x48\x8D\x0D\x00\x00\x00\x00",
		"xxx????xxxx????xxx????xxx????xxxxxxx????",
		&Hooking::m_replayIntf,
		true, 3, 1);
	HookMsg("RPIF");

	setFn<fpIncrementStatHook>("increment_stat",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x55\x57\x41\x55\x41\x56\x41\x57\x48\x8B\xEC\x48\x83\xEC\x60\x8B\x79\x30",
		"xxxx?xxxx?xxxxxxxxxxxxxxxxxx",
		&Hooking::increment_stat);
	HookMsg("INST");

	setFn<fpCreateAmbientPickup>("create_ambient_pickup",
		"\x48\x8B\xC4\x48\x89\x58\x10\x48\x89\x70\x18\x48\x89\x78\x20\x55\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8D\x68\xC1\x48\x81\xEC\x00\x00\x00\x00\x45\x8B\xF9\x41\x8B\xF0\x4C\x8B\xEA\xE8\x00\x00\x00\x00\x0F\xB7\x0D\x00\x00\x00\x00\x33\xFF\x44\x8B\xC7\x44\x8B\xD7\x44\x8B\xE0\x85\xC9\x7E\x1C\x48\x8B\x1D\x00\x00\x00\x00",
		"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxxxxxxx????xxx????xxxxxxxxxxxxxxxxxx????",
		&Hooking::create_ambient_pickup);
	HookMsg("CAP");

	setFn<fpIntegrityCheck>("integrity_check",
		"\x40\x55\x53\x56\x57\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8D\x6C\x24\x00\x48\x81\xEC\x00\x00\x00\x00\x48\x8B\x05\x00\x00\x00\x00",
		"xxxxxxxxxxxxxxxxx?xxx????xxx????",
		&Hooking::integrity_check);
	HookMsg("ITC", true);

	setFn<fpSetMobileRadioEnabledDuringGameplay>("set_mobile_radio",
		"\x40\x53\x48\x83\xEC\x20\x8A\xD9\x48\x8D\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8D\x0D\x00\x00\x00\x00\x8B\xD0\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x10",
		"xxxxxxxxxxx????x????xxx????xxx????xxxxx",
		&Hooking::set_mobile_radio_enabled_during_gameplay);
	HookMsg("SMREDG");

	setFn<fpGetLabelText>("get_label_text",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\xDA\x48\x8B\xF9\x48\x85\xD2\x75\x44\xE8",
		"xxxx?xxxxxxxxxxxxxxxxx",
		&Hooking::GetLabelText);
	HookMsg("GLT", true);

	setFn<fpRequestIpl>("request_ipl",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\x05\x00\x00\x00\x00\x48\x8B\xF9\x4C\x8B\xC1\x48\x8D\x54\x24\x00\x48\x8D\x0D\x00\x00\x00\x00\xFF\x50\x10\x8B\x18",
		"xxxx?xxxxxxxx????xxxxxxxxxx?xxx????xxxxx",
		&Hooking::request_ipl);
	HookMsg("RIPL");

	setFn<fpIsIplActive>("is_ipl_active",
		"\x48\x83\xEC\x28\x48\x8B\x05\x00\x00\x00\x00\x4C\x8B\xC1",
		"xxxxxxx????xxx",
		&Hooking::is_ipl_active);
	HookMsg("IIAC");

	setFn<fpNetworkShopCheckoutStart>("network_shop_checkout_start",
		"\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x33\xC9\x48\x85\xC0\x74\x0C",
		"xxxxx????xxxxxxx",
		&Hooking::network_shop_checkout_start);
	HookMsg("NSCS");

	setFn<fpGetPlayerMaxArmour>("get_player_max_armour",
		"\x40\x53\x48\x83\xEC\x20\x33\xDB\x38\x1D\x00\x00\x00\x00\x74\x1C",
		"xxxxxxxxxx????xx",
		&Hooking::get_player_max_armour);
	HookMsg("GPMA");

	setFn<fpGetEntityAttachedTo>("get_entity_attached_to",
		"\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x19\x4C\x8B\x00\x8B\x15\x00\x00\x00\x00\x48\x8B\xC8\x41\xFF\x50\x08\x84\xC0\x74\x05\x48\x8B\xC3\xEB\x02\x33\xC0\x48\x83\xC4\x20\x5B\xC3\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8",
		"xxxxxxx????xxxxxxxxxx?xx????xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx????xxx",
		&Hooking::get_entity_attached_to);
	HookMsg("GEAT");

	setFn<fpSetEntityCollision>("set_entity_collision",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF1\x41\x8A\xE8\x40\x8A\xFA",
		"xxxx?xxxx?xxxx?xxxxxxxxxxxxxx",
		&Hooking::set_entity_collision);
	HookMsg("SEC");

	setFn<fpNetworkSessionKickPlayer>("network_session_kick_player",
		"\x48\x83\xEC\x38\xB2\x01\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x21",
		"xxxxxxx????xxxxx",
		&Hooking::network_session_kick_player);
	HookMsg("NSKP");

	setFn<fpEventHandler>("scripted_game_event",
		"\x66\x41\x83\xF9\x00\x0F\x83\x00\x00\x00\x00",
		"xxxx?xx????",
		&Hooking::event_handler);
	HookMsg("SGE", true);

	setFn<fpStatSetDate>("stat_set_date",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x60\x48\x8B\xDA\x8B\xF9",
		"xxxx?xxxx?xxxxxxxxxx",
		&Hooking::stat_set_date);
	HookMsg("SSD");

	setFn<fpStatGetInt>("stat_get_int",
		"\x48\x8B\xC4\x48\x89\x58\x10\x48\x89\x70\x18\x57\x48\x83\xEC\x30\x48\x8B\xF2",
		"xxxxxxxxxxxxxxxxxxx",
		&Hooking::stat_get_int);
	HookMsg("SGI");

	setFn<fpAddTextCompSubstrPlayerName>("add_text_comp_substr_playername",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x05\x00\x00\x00\x00\x4C\x8B\xD1",
		"xxxx?xxxx?xxxx?xxxxxxx????xxx",
		&Hooking::add_text_comp_substr_playername);
	HookMsg("ATCSP");
	
	setFn<fpEndTextCmdDisplayText>("end_text_command_display_text",
		"\x40\x53\x48\x83\xEC\x40\x0F\x29\x74\x24\x00\x0F\x29\x7C\x24\x00\x41\x8B\xD8",
		"xxxxxxxxxx?xxxx?xxx",
		&Hooking::end_text_command_display_text);
	HookMsg("ETCDT");
	
	setFn<fpBeginTextCmdDisplayText>("begin_text_command_display_text",
		"\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x33\xC9\x48\x85\xC0",
		"xxxxx????x????xxxxx",
		&Hooking::begin_text_command_display_text);
	HookMsg("BTCDT");

	setFn<fpSendMessage>("send_message",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x48\x8B\xF9\x48\x8D\x4C\x24\x00\x48\x8B\xDA\xE8\x00\x00\x00\x00\x48\x8D\x4C\x24\x00\x41\xB8\x00\x00\x00\x00\x48\x8B\xD3\xE8\x00\x00\x00\x00\x84\xC0\x74\x14\x48\x8B\x0D\x00\x00\x00\x00\x4C\x8D\x44\x24\x00\x48\x8B\xD7\xE8\x00\x00\x00\x00\x32\xC0\x48\x8B\x5C\x24\x00",
		"xxxx?xxxxxxxxxxxx?xxxx????xxxx?xx????xxxx????xxxxxxx????xxxx?xxxx????xxxxxx?",
		&Hooking::send_message);
	HookMsg("SMSG");

	setFn<fpClearPedBloodDamage>("clear_ped_blood_damage",
		"\x40\x53\x48\x83\xEC\x20\x8A\x91\x00\x00\x00\x00\x48\x8B\xD9\x80\xFA\xFF\x74\x51",
		"xxxxxxxx????xxxxxxxx",
		&Hooking::clear_ped_blood_damage);
	HookMsg("CPBD");

	setFn<fpSetVehicleOnGroundProperly>("set_vehicle_on_ground_properly",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x0F\x29\x74\x24\x00\x0F\x28\xF1\xE8\x00\x00\x00\x00\x48\x8B\xD8",
		"xxxx?xxxxxxxxx?xxxx????xxx",
		&Hooking::set_vehicle_on_ground_properly);
	HookMsg("SVOGP");

	setFn<fpSetVehicleNumberplateText>("set_vehicle_numberplate_text",
		"\x40\x53\x48\x83\xEC\x20\x48\x8B\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x10\x48\x8B\x48\x48",
		"xxxxxxxxxx????xxxxxxxxx",
		&Hooking::set_vehicle_numberplate_text);
	HookMsg("SVNT");

	setFn<fpIsThisModelAPlane>("is_this_model_a_plane",
		"\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x85\xC0\x74\x1D\x8A\x80\x00\x00\x00\x00\x24\x1F\x3C\x05\x75\x11\xBA",
		"xxxxxxxxxx?xxxxx?????x????xxxxxxxxxx????xxxxxxx",
		&Hooking::is_this_model_a_plane);
	HookMsg("ITMAP");

	setFn<fpIsThisModelAHeli>("is_this_model_a_heli",
		"\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x85\xC0\x74\x1E\x8A\x80\x00\x00\x00\x00\x24\x1F\x3C\x05\x75\x12\x83\xB9\x00\x00\x00\x00\x08",
		"xxxxxxxxxx?xxxxx?????x????xxxxxxxxxx????xxxxxxxx????x",
		&Hooking::is_this_model_a_heli);
	HookMsg("ITMAH");

	setFn<fpSetHeliBladesFullSpeed>("set_heli_blades_full_speed",
		"\x40\x53\x48\x83\xEC\x30\x0F\x29\x74\x24\x00\x0F\x28\xF1\x0F\x2F\x35",
		"xxxxxxxxxx?xxxxxx",
		&Hooking::set_heli_blades_full_speed);
	HookMsg("SHBFS");

	setFn<fpEndTextCommandGetWidth>("end_text_command_get_width",
		"\x40\x53\x48\x81\xEC\x00\x00\x00\x00\x83\x3D\x00\x00\x00\x00\x00\x8A\xD9\x0F\x57\xC0",
		"xxxxx????xx?????xxxxx",
		&Hooking::end_text_command_get_width);
	HookMsg("ETCGW");

	setFn<fpRequestAnimDict>("request_anim_dict",
		"\x48\x83\xEC\x58\x48\x8B\xD1\x33\xC9",
		"xxxxxxxxx",
		&Hooking::request_anim_dict);
	HookMsg("RAD");

	setFn<fpHasAnimDictLoaded>("has_anim_dict_loaded",
		"\x48\x83\xEC\x28\x48\x8B\xD1\x33\xC9\xE8\x00\x00\x00\x00\x48\x8D\x54\x24\x00\x48\x8D\x4C\x24\x00\x89\x44\x24\x40",
		"xxxxxxxxxx????xxxx?xxxx?xxxx",
		&Hooking::has_anim_dict_loaded);
	HookMsg("HADL");

	setFn<fpDrawNotification>("draw_notification",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x81\xEC\x00\x00\x00\x00\x83\x3D\x00\x00\x00\x00\x00\x41\x8A\xD8",
		"xxxx?xxxx?xxxx????xx?????xxx",
		&Hooking::draw_notification);
	HookMsg("DNO");

	setFn<fpDrawNotification2>("draw_notification_2",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x40\x8A\xFA\x40\x8A\xF1",
		"xxxx?xxxx?xxxxxxxxxx",
		&Hooking::draw_notification_2);
	HookMsg("DNOT");

	setFn<fpPickupRewardMoneyIsApplicableToPlayer>("pickup_reward",
		"\x49\x8B\x80\x00\x00\x00\x00\x48\x85\xC0\x74\x0C\xF6\x80\x00\x00\x00\x00\x00\x75\x03",
		"xxx????xxxxxxx?????xx",
		&Hooking::pickup_is_applicable_to_player);
	HookMsg("PRW", true);

	setFn<fpSetVehicleMod>("set_vehicle_mod",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x56\x57\x41\x56\x48\x83\xEC\x30\x41\x8A\xE9",
		"xxxx?xxxx?xxxxxxxxxxx",
		&Hooking::set_vehicle_mod);
	HookMsg("SVMD");

	setFn<fpToggleVehicleMod>("toggle_vehicle_mod",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF8\x8B\xDA\x83\xFA\x0A",
		"xxxx?xxxxxxxxxxxxx",
		&Hooking::toggle_vehicle_mod);
	HookMsg("TVMD");

	setFn<fpSetVehicleEngineOn>("set_vehicle_engine_on",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xE9\x41\x8A\xF8",
		"xxxx?xxxx?xxxx?xxxxxxxxxxx",
		&Hooking::set_vehicle_engine_on);
	HookMsg("SVEO");

	setFn<fpSetVehicleUndriveable>("set_vehicle_undriveable",
		"\x40\x53\x48\x83\xEC\x20\x8A\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x20\x84\xDB",
		"xxxxxxxxx????xxxxxxx",
		&Hooking::set_vehicle_undriveable);
	HookMsg("SVUD");

	setFn<fpSetVehicleDriveable>("set_vehicle_driveable",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x40\x8A\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x36",
		"xxxx?xxxxxxxxx????xxxxxxxx",
		&Hooking::set_vehicle_driveable);
	HookMsg("SVDB");

	setFn<fpGetDisplayNameFromVehicle>("get_display_name_from_vehicle",
		"\x48\x83\xEC\x28\x48\x8D\x54\x24\x00\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x16",
		"xxxxxxxx?xxx?????x????xxxxx",
		&Hooking::get_display_name_from_vehicle);
	HookMsg("GDNFV");

	setPat<threeBytes>("infinite ammo",
		"\x41\x2B\xD1\xE8",
		"xxxx",
		&Hooking::infinite_ammo,
		false);
	HookMsg("IAM");

	setPat<threeBytes>("no reload",
		"\x41\x2B\xC9\x3B\xC8\x0F",
		"xxxxxx",
		&Hooking::no_reload,
		false);
	HookMsg("NRL");

	setFn<fpGetPedInVehicleSeat>("get_ped_in_vehicle_seat",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xE8\x8D\x72\x01",
		"xxxx?xxxx?xxxx?xxxxxxxxxxx",
		&Hooking::get_ped_in_vehicle_seat);
	HookMsg("GPIVS");

	setFn<fpIsAimCamActive>("is_aim_cam_active",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x33\xD2\x48\x8B\xC8\x48\x8B\xF8",
		"xxxx?xxxxxx????xxxxxxxx",
		&Hooking::is_aim_cam_active);
	HookMsg("IACA");

	setFn<fpDrawRect>("draw_rect",
		"\x48\x8B\xC4\x48\x89\x58\x08\x57\x48\x83\xEC\x70\x48\x63\x0D\x00\x00\x00\x00\x0F",
		"xxxxxxxxxxxxxxx????x",
		&Hooking::draw_rect);
	HookMsg("DRCT");

	setFn<fpDrawLine>("draw_line",
		"\x40\x53\x48\x83\xEC\x40\xF3\x0F\x10\x09\xF3\x0F\x10\x41\x00\xF3\x0F\x10\x51\x00\x45\x8B\xD0\xBB",
		"xxxxxxxxxxxxxx?xxxx?xxxx",
		&Hooking::draw_line,
		1);
	HookMsg("DLN");

	setFn<fpGetGameplayCamRot>("get_gameplay_cam_rot",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x8B\xDA\x48\x8B\xF9\xE8\x00\x00\x00\x00\x48\x8D\x4C\x24\x00\x48\x8D\x90\x00\x00\x00\x00",
		"xxxx?xxxxxxxxxxx????xxxx?xxx????",
		&Hooking::get_gameplay_cam_rot);
	HookMsg("GGCR");

	setFn<fpGetGameplayCamCoord>("get_gameplay_cam_coord",
		"\x40\x53\x48\x83\xEC\x20\x48\x8B\xD9\xE8\x00\x00\x00\x00\x8B\x90\x00\x00\x00\x00",
		"xxxxxxxxxx????xx????",
		&Hooking::get_gameplay_cam_coord);
	HookMsg("GGCC");

	setFn<fpGiveDelayedWeaponToPed>("give_delayed_weapon_to_ped",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30\x41\x8A\xE9\x41\x8B\xF0\x8B\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x63",
		"xxxx?xxxx?xxxx?xxxxxxxxxxxxxx????xxxxxxxx",
		&Hooking::give_delayed_weapon_to_ped);
	HookMsg("GDWTP");

	setFn<fpRemoveAllPedWeapons>("remove_all_ped_weapons",
		"\x48\x83\xEC\x28\x8B\x05\x00\x00\x00\x00\x89\x05\x00\x00\x00\x00\xE8",
		"xxxxxx????xx????x",
		&Hooking::remove_all_ped_weapons);
	HookMsg("RAPW");

	setFn<fpRemoveWeaponFromPed>("remove_weapon_from_ped",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xFA\xE8\x00\x00\x00\x00\x33\xDB",
		"xxxx?xxxxxxxx????xx",
		&Hooking::remove_weapon_from_ped);
	HookMsg("RWFP");

	setFn<fpGetPlayerRadioStationIndex>("get_player_radio_station_index",
		"\x48\x83\xEC\x28\x48\x8D\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x0C",
		"xxxxxxx????x????xxxxx",
		&Hooking::get_player_radio_station_index);
	HookMsg("GPRSI");

	setFn<fpGetRadioStationName>("get_radio_station_name",
		"\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x0D\x48\x8B\x80",
		"xxxxx????xxxxxxxx",
		&Hooking::get_radio_station_name);
	HookMsg("GRSN");

	setFn<fpNetworkGetNetworkIdFromEntity>("network_get_network_id_from_entity",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x33\xDB\x48\x8B\xF8\x48\x85\xC0\x74\x16",
		"xxxx?xxxxxx????xxxxxxxxxx",
		&Hooking::get_network_id_from_entity);
	HookMsg("NGNIFE");

	setFn<fpNetworkCreateSynchronisedScene>("network_create_synchronised_scene",
		"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x48\x8D\x68\xC1",
		"xxxxxxxxxxxxxxxxxxxx",
		&Hooking::create_synchronised_scene);
	HookMsg("NCSS");

	setFn<fpNetworkAddPedToSynchronisedScene>("network_add_ped_to_synchronised_scene",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x50\x49\x8B\xD9",
		"xxxx?xxxx?xxxxxxxx",
		&Hooking::add_ped_to_synchronised_scene);
	HookMsg("NAPTSS");

	setFn<fpNetworkStartSynchronisedScene>("network_start_synchronised_scene",
		"\x40\x53\x48\x81\xEC\x00\x00\x00\x00\x8B\xD9\x44\x8B\xC1\x48\x8D\x15\x00\x00\x00\x00\x48\x8D\x4C\x24\x00\xE8\x00\x00\x00\x00\x85\xDB\x78\x12",
		"xxxxx????xxxxxxxx????xxxx?x????xxxx",
		&Hooking::start_synchronised_scene);
	HookMsg("NSSS");

	setFn<fpIsVehicleDrivable>("is_vehicle_drivable",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x40\x8A\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x36",
		"xxxx?xxxxxxxxx????xxxxxxxx",
		&Hooking::is_vehicle_driveable);
	HookMsg("IVD");

	setFn<fpSetVehicleForwardSpeed>("set_vehicle_forward_speed",
		"\x40\x53\x48\x83\xEC\x40\x0F\x29\x74\x24\x00\x48\x8B\xD9\x0F\x28\xF1\xE8\x00\x00\x00\x00\x48\x8B\x03",
		"xxxxxxxxxx?xxxxxxx????xxx",
		&Hooking::set_vehicle_forward_speed);
	HookMsg("SVFS");

	setFn<fpSetVehicleFixed>("set_vehicle_fixed",
		"\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x28\x4C\x8B\x10",
		"xxxxxxx????xxxxxxxxxxx",
		&Hooking::set_vehicle_fixed);
	HookMsg("SVFX");

	setFn<fpSetVehicleDeformationFixed>("set_vehicle_deformation_fixed",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x40\x48\x83\xB9\x00\x00\x00\x00\x00\x48\x8B\xD9",
		"xxxx?xxxxxxxx?????xxx",
		&Hooking::set_vehicle_deformation_fixed);
	HookMsg("SVDFX");

	setFn<fpIsVehicleSeatFree>("is_vehicle_seat_free",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x41\x56\x41\x57\x48\x83\xEC\x20\x45\x8A\xF8",
		"xxxx?xxxx?xxxx?xxxxxxxxxxxx",
		&Hooking::is_vehicle_seat_free);
	HookMsg("IVSF");

	setFn<fpSetVehicleNumberPlateIndex>("set_vehicle_number_plate_index",
		"\x83\xFA\xFF\x0F\x8C\x00\x00\x00\x00\x48\x8B",
		"xxxxx????xx",
		&Hooking::set_vehicle_number_plate_index);
	HookMsg("SVNPI");

	setFn<fpSetVehicleWheelType>("set_vehicle_wheel_type",
		"\x40\x53\x48\x83\xEC\x20\x8B\xDA\xE8\x00\x00\x00\x00\x4C\x8B\xC0",
		"xxxxxxxxx????xxx",
		&Hooking::set_vehicle_wheel_type);
	HookMsg("SVWHT");

	setFn<fpGetNumVehicleMod>("get_num_vehicle_mod",
		"\x40\x53\x48\x83\xEC\x20\x8B\xDA\x83\xFA\x0A\x7E\x10\x8D\x42\xF5\x83\xF8\x0D\x77\x05\x83\xC3\x19\xEB\x03\x83\xEB\x0E\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x2C",
		"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxx",
		&Hooking::get_num_vehicle_mod);
	HookMsg("GNVM");

	setFn<fpDrawNotification>("draw_notification",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x81\xEC\x00\x00\x00\x00\x83\x3D\x00\x00\x00\x00\x00\x41\x8A\xD8",
		"xxxx?xxxx?xxxx????xx?????xxx",
		&Hooking::draw_notification);
	HookMsg("DRNO");

	setFn<fpSetLocalPlayerVisibleLocally>("set_local_player_visible_locally",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x40\x8A\xF9\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x6D",
		"xxxx?xxxxxxxxx????xxxxxxxx",
		&Hooking::set_local_player_visible_locally);
	HookMsg("SLPVL");

	setFn<fpAiTaskWanderStandard>("ai_task_wander_standard",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x60\x0F\x28\xC1",
		"xxxx?xxxx?xxxxxxxx",
		&Hooking::ai_task_wander_standart);
	HookMsg("ATWS");

	setFn<fpAiTaskPlayAnim>("ai_task_play_anim",
		"\x48\x81\xEC\x00\x00\x00\x00\x44\x8B\x8C\x24",
		"xxx????xxxx",
		&Hooking::ai_task_play_anim);
	HookMsg("ATPA");

	setFn<fpIsModelInCdimage>("is_model_in_cdimage",
		"\x48\x83\xEC\x28\x8B\x44\x24\x38\x48\x8D\x54\x24\x00\xC7\x44\x24\x00\x00\x00\x00\x00\x0D\x00\x00\x00\x00\x25\x00\x00\x00\x00\x89\x44\x24\x38\xE8\x00\x00\x00\x00\x0F\xB7\x44\x24\x00\x66\x89\x44\x24\x00\x8B\x44\x24\x38\x0D\x00\x00\x00\x00\x0F\xBA\xF0\x1C\x89\x44\x24\x38",
		"xxxxxxxxxxxx?xxx?????x????x????xxxxx????xxxx?xxxx?xxxxx????xxxxxxxx",
		&Hooking::is_model_in_cdimage);
	HookMsg("IMICDI");

	setFn<fpIsModelValid>("is_model_valid",
		"\x48\x83\xEC\x28\x8B\x44\x24\x38\x48\x8D\x54\x24\x00\xC7\x44\x24\x00\x00\x00\x00\x00\x0D\x00\x00\x00\x00\x25\x00\x00\x00\x00\x89\x44\x24\x38\xE8\x00\x00\x00\x00\x0F\xB7\x44\x24\x00\x66\x89\x44\x24\x00\x8B\x44\x24\x38\x0D\x00\x00\x00\x00\x0F\xBA\xF0\x1C\x0F\xB7\xC8",
		"xxxxxxxxxxxx?xxx?????x????x????xxxxx????xxxx?xxxx?xxxxx????xxxxxxx",
		&Hooking::is_model_valid);
	HookMsg("IMVD");

	setFn<fpIsModelAVehicle>("is_model_a_vehicle",
		"\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x85\xC0",
		"xxxxxxxxxx?xxxxx?????x????xxx",
		&Hooking::is_model_a_vehicle);
	HookMsg("IMAV");

	setFn<fpRequestModel>("request_model",
		"\x48\x89\x5C\x24\x00\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x50\x8B\x45\x18",
		"xxxx?xxxx?xxxxxxxxxxx",
		&Hooking::request_model);
	HookMsg("RQMD");

	setFn<fpHasModelLoaded>("has_model_loaded",
		"\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x20\x8B\x45\x18\xBF",
		"xxxx?xxxxxxxxxxxx",
		&Hooking::has_model_loaded);
	HookMsg("HMDL");

	setFn<fpGetPedLastWeaponImpactCoord>("get_ped_last_weapon_impact",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x33\xDB\x48\x8B\xFA\x48\x89\x5A\x04",
		"xxxx?xxxxxxxxxxxxxx",
		&Hooking::get_ped_last_weapon_impact_coord);
	HookMsg("GPLWIC");

	setFn<fpStartRayCast>("start_ray_cast",
		"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x70\x20\x55\x48\x8D\xA8\x00\x00\x00\x00\x48\x81\xEC\x00\x00\x00\x00\x33\xDB\x45\x8B\xF0\x48\x8B\xFA\x48\x8B\xF1\x8B\xC3\x45\x85\xC9\x74\x08\x41\x8B\xC9\xE8\x00\x00\x00\x00\xF3\x0F\x10\x1F",
		"xxxxxxxxxxxxxxxxxxxxxxx????xxx????xxxxxxxxxxxxxxxxxxxxxx????xxxx",
		&Hooking::start_ray_cast);
	HookMsg("SRC");

	setFn<fpGetRayCast>("get_ray_cast",
		"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x41\x56\x41\x57\x48\x8D\x68\xB1\x48\x81\xEC\x00\x00\x00\x00\x33\xDB",
		"xxxxxxxxxxxxxxxxxxxxxxxxxxx????xx",
		&Hooking::get_ray_cast);
	HookMsg("GRCR");

	setFn<fpNetworkSetInSpectatorMode>("network_set_in_spectator_mode",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF8\x84\xC9",
		"xxxx?xxxxxxxxxx",
		&Hooking::set_in_spectator_mode);
	HookMsg("NSISM");

	setFn<fpSetPedCombatAbility>("set_ped_combat_ability",
		"\x48\x81\xC1\x00\x00\x00\x00\x41\xB8\x00\x00\x00\x00\x48\x8B\x01\x48\x85\xC0\x74\x06",
		"xxx????xx????xxxxxxxx",
		&Hooking::set_ped_combat_ability);
	HookMsg("SPCA");

	setFn<fpAiTaskCombatPed>("ai_task_combat_ped",
		"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x83\xEC\x30\x8B\xF9",
		"xxxxxxxxxxxxxxxxxxxxxxxxxxx",
		&Hooking::ai_task_combat_ped);
	HookMsg("ATCP");

	setFn<fpApplyVehicleColors>("apply_vehicle_colors",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\x41\x48\x48\x8B\xD9\x40\x8A\xFA",
		"xxxx?xxxxxxxxxxxxxxx",
		&Hooking::apply_vehicle_colors);
	HookMsg("AVCLR");

	setFn<fpSetPlayerVisibleLocally>("set_player_visible_locally",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x40\x8A\xFA\xB2\x01\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x0D\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x8B\xD8\xEB\x02\x33\xDB\x48\x85\xDB\x74\x64",
		"xxxx?xxxxxxxxxxx????xxxxxxxxx????xxxxxxxxxxxx",
		&Hooking::set_player_visible_locally);
	HookMsg("SPVL");

	setFn<fpSetModelAsNoLongerNeeded>("set_model_as_no_longer_needed",
		"\x40\x53\x48\x83\xEC\x30\x48\x8D\x54\x24\x00\x8B\xD9",
		"xxxxxxxxxx?xx",
		&Hooking::set_model_as_no_longer_needed);
	HookMsg("SMANLN");

	setFn<fpSetVehicleEngineOn>("set_vehicle_engine_on",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xE9\x41\x8A\xF8",
		"xxxx?xxxx?xxxx?xxxxxxxxxxx",
		&Hooking::set_vehicle_engine_on);
	HookMsg("SVEO");

	setFn<fpSetEntityCollision>("set_entity_collision",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF1\x41\x8A\xE8\x40\x8A\xFA",
		"xxxx?xxxx?xxxx?xxxxxxxxxxxxxx",
		&Hooking::set_entity_collision);
	HookMsg("SECL");

	setPat<CPlayers>("player list",
		"\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x8B\xCF",
		"xxx????x????xxxx????xxx",
		&Hooking::m_players,
		true,
		3);
	HookMsg("PLLST");

	setPat<MemoryPool*>("entity pool",
		"\x4C\x8B\x0D\x00\x00\x00\x00\x44\x8B\xC1\x49\x8B\x41\x08",
		"xxx????xxxxxxx",
		&Hooking::m_entityPool,
		true,
		3);
	HookMsg("ENPL");

	setPat<MemoryPool*>("ped pool",
		"\x48\x8B\x05\x00\x00\x00\x00\x41\x0F\xBF\xC8\x0F\xBF\x40\x10",
		"xxx????xxxxxxxx",
		&Hooking::m_pedPool,
		true,
		3);
	HookMsg("PDPL");

	/*setPat<CViewPort>("viewport",
		"\x48\x8B\x15\x00\x00\x00\x00\x48\x8D\x2D\x00\x00\x00\x00\x48\x8B\xCD",
		"xxx????xxx????xxx",
		&Hooking::m_viewPort,
		true,
		3,
		1);
	HookMsg("VPRT");
*/
	setPat<screenReso>("resolution",
		"\x8B\x0D\x00\x00\x00\x00\x49\x8D\x56\x28",
		"xx????xxxx",
		&Hooking::m_resolution,
		true,
		2);
	HookMsg("RSLT");

	setPat<CTextInfo>("text info",
		"\x48\x8D\x05\x00\x00\x00\x00\x48\x89\x44\x24\x00\x8B\x05\x00\x00\x00\x00\x89\x44\x24\x28",
		"xxx????xxxx?xx????xxxx",
		&Hooking::m_textInfo,
		true,
		3);
	HookMsg("TXTCL");

	setPat<uint64_t>("network time",
		"\x8B\x0D\x00\x00\x00\x00\x3B\xCB\x0F\x47\xCB",
		"xx????xxxxx",
		&Hooking::m_networkTime,
		true,
		2);
	HookMsg("NTWTM");

	setPat<void>("game info",
		"\x48\x8D\x0D\x00\x00\x00\x00\x41\xB0\x01\x33\xD2\x88\x1D",
		"xxx????xxxxxxx",
		&Hooking::m_gameInfo,
		true,
		3);
	HookMsg("GMIN", true);

	setFn<fpCreateObject>("create_object",
		"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x60\x20\x55\x41\x55\x41\x56\x48\x8D\x68\xD9",
		"xxxxxxxxxxxxxxxxxxxxxxxxxxxx",
		&Hooking::create_object);
	HookMsg("CREOB");

	setFn<fpSetOverrideWeather>("set_override_weather",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x1D\x00\x00\x00\x00\x8B\xF1",
		"xxxx?xxxx?xxxxxxx????xx",
		&Hooking::set_override_weather);
	HookMsg("SOVW");

	setFn<fpGetCurrentPedWeapon>("get_current_ped_weapon",
		"\x40\x53\x48\x83\xEC\x20\x48\x8B\xDA\xE8\x00\x00\x00\x00\x33\xC9",
		"xxxxxxxxxx????xx",
		&Hooking::get_current_ped_weapon);
	HookMsg("GCPW");

	setFn<fpGetTextScreenLineCount>("get_text_screen_line_count",
		"\x48\x8B\xC4\x48\x81\xEC\x00\x00\x00\x00\x0F\x29\x70\xE8\x0F\x29\x78\xD8\x33\xC0",
		"xxxxxx????xxxxxxxxxx",
		&Hooking::get_text_screen_line_count);
	HookMsg("GTSLC");

	setFn<fpRequestScaleformMovie>("request_scaleform_movie",
		"\x48\x8B\xC4\x48\x89\x58\x10\x48\x89\x70\x18\x48\x89\x78\x20\x55\x48\x8D\x68\xA1\x48\x81\xEC\x00\x00\x00\x00\xF3\x0F\x10\x45\x00",
		"xxxxxxxxxxxxxxxxxxxxxxx????xxxx?",
		&Hooking::request_scaleform_movie);
	HookMsg("RSCMV");

	setFn<fpDrawScaleformMovie>("draw_scaleform_movie",
		"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x57\x48\x81\xEC\x00\x00\x00\x00\x0F\x29\x70\xE8\x0F\x29\x78\xD8\x44\x0F\x29\x40\x00\x48\x63\xF9",
		"xxxxxxxxxxxxxxxxxxx????xxxxxxxxxxxx?xxx",
		&Hooking::draw_scaleform_movie);
	HookMsg("DSCMV");

	setFn<fpEndScaleformMovieMethod>("end_scaleform_movie_method",
		"\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x19\x4C\x8B\x00\x8B\x15\x00\x00\x00\x00\x48\x8B\xC8\x41\xFF\x50\x08\x84\xC0\x74\x05\x48\x8B\xC3\xEB\x02\x33\xC0\x48\x83\xC4\x20\x5B\xC3\x48\x89\x5C\x24\x00\x45\x33\xC9",
		"xxxxxxx????xxxxxxxxxx?xx????xxxxxxxxxxxxxxxxxxxxxxxxxxxx?xxx",
		&Hooking::end_scaleform_movie_method);
	HookMsg("ESCMVM");

	setFn<fpIsDisabledControlPressed>("is_disabled_control_pressed",
		"\x40\x53\x48\x83\xEC\x20\x48\x8B\x05\x00\x00\x00\x00\x8B\xDA\x48\x85\xC0\x74\x10\x80\x78\x14\x00\x75\x06\x83\x78\x04\x00\x74\x04\x32\xC0\xEB\x4F\x48\x8B\x05\x00\x00\x00\x00\x48\x89\x44\x24\x00\x48\xC1\xE8\x20\x83\xC8\x08\x89\x44\x24\x44\x85\xC9\x75\x09\x33\xC9",
		"xxxxxxxxx????xxxxxxxxxx?xxxxx?xxxxxxxxx????xxxx?xxxxxxxxxxxxxxxxx",
		&Hooking::is_disabled_control_pressed);
	HookMsg("IDCP");

	setFn<fpIsPlayerFriend>("is_player_friend",
		"\x0F\xB6\xD0\x48\x8B\x03\x89\x10\x48\x83\xC4\x20\x48\x8D\x64\x24\x08\x48\x8B\x5C\x24\xF8\x48\x8D\x64\x24\x08\x00\x00\x00\x00",
		"xxxxxxxxxxxxxxxxxxxxxxxxxxx????",
		&Hooking::is_player_friend);
	HookMsg("IPF");

	/*setFn<fpNetworkShopBeginService>("network_shop_begin_service",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x41\x56\x41\x57\x48\x83\xEC\x50\x45\x8B\xF1",
		"xxxx?xxxx?xxxx?xxxxxxxxxxxx",
		&Hooking::network_shop_begin_service);
	HookMsg("NSBS");*/

	Hooking::NtQueryVirtualMemory = (fpNtQueryVirtualMemory)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "NtQueryVirtualMemory");
	if (Hooking::NtQueryVirtualMemory != nullptr) {
		Hooking::foundPtr("nt_status");
	}
	HookMsg("NTVM", true);

	Sleep(5000);

	Log::Msg("Getting Game State");
	c_location = p_gameState.count(1).get(0).get<char>(2);
	c_location == nullptr ? FailPatterns("gameState") : m_gameState = reinterpret_cast<decltype(m_gameState)>(c_location + *(int32_t*)c_location + 5);

	Log::Msg("Getting vector3 result fixer func");
	v_location = p_fixVector3Result.count(1).get(0).get<void>(0);
	if (v_location != nullptr) scrNativeCallContext::SetVectorResults = (void(*)(scrNativeCallContext*))(v_location);

	Log::Msg("Getting native registration table");
	c_location = p_nativeTable.count(1).get(0).get<char>(9);
	c_location == nullptr ? FailPatterns("native registration table") : m_registrationTable = reinterpret_cast<decltype(m_registrationTable)>(c_location + *(int32_t*)c_location + 4);

	Log::Msg("Getting World Pointer");
	c_location = p_worldPtr.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("world Pointer") : m_worldPtr = reinterpret_cast<uint64_t>(c_location) + *reinterpret_cast<int*>(reinterpret_cast<uint64_t>(c_location) + 3) + 7;

	Log::Msg("Getting Blip List");
	c_location = p_blipList.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("blip List") : m_blipList = (BlipList*)(c_location + *reinterpret_cast<int*>(c_location + 3) + 7);

	/*Log::Msg("Bypassing Object restrictions");
	CPattern pattern_modelCheck("\x48\x85\xC0\x0F\x84\x00\x00\x00\x00\x8B\x48\x50", "xxxxx????xxx");
	m_model_bypass = pattern_modelCheck.find(0).get(0).get<char>(0);
	Log::Msg("Hooking Model Check Bypass...");
	if (nullptr != m_model_bypass)
	{
		memcpy_s(model_bypass, sizeof(model_bypass), m_model_bypass, sizeof(model_bypass));
		memset(m_model_bypass, NOP, sizeof(model_bypass));
		Log::Msg("Hooking Model Check Bypass completed sucessfull!");
	}
	else
	{
		Log::Msg("Error in finding the Model Check Bypass");
	}*/
	//DETECTED?

	auto pattern_int_checker = Memory::pattern("80 3D ? ? ? ? ? 0F 85 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 08 48 39 0D ? ? ? ? 0F 85");
	m_int_checker = pattern_int_checker.count(1).get(0).get<std::uint8_t>(0);
	if (m_int_checker == nullptr) {
		Log::Error("Failed to find Integrity Checker");
	}
	else {
		og_int_checker = m_int_checker[0];
		memcpy_s(int_check, sizeof(int_check), m_int_checker, sizeof(int_check));
		m_int_checker[0] = 0xC3;
		memset(m_int_checker, NOP, sizeof(int_check));
		FlushInstructionCache(GetCurrentProcess(), m_int_checker, 8);
	}

	Log::Msg("Getting active script thread");
	c_location = p_activeThread.count(1).get(0).get<char>(1);
	c_location == nullptr ? FailPatterns("Active Script Thread") : GetActiveThread = reinterpret_cast<decltype(GetActiveThread)>(c_location + *(int32_t*)c_location + 4);

	Log::Msg("Getting World Pointer");
	c_location = p_globalPtr.count(1).get(0).get<char>(0);
	__int64 patternAddr = NULL;
	c_location == nullptr ? FailPatterns("globalTable") : patternAddr = reinterpret_cast<decltype(patternAddr)>(c_location);
	m_globalPtr = (__int64**)(patternAddr + *(int*)(patternAddr + 3) + 7);

	Log::Msg("Getting Event Hook");
	if ((c_location = p_eventHook.count(1).get(0).get<char>(0)))
	{
		int i = 0, j = 0, matches = 0, found = 0;
		char* pattern = "\x4C\x8D\x05";
		while (found != EVENT_COUNT)
		{
			if (c_location[i] == pattern[j])
			{
				if (++matches == 3)
				{
					EventPtr.push_back((void*)(reinterpret_cast<uint64_t>(c_location + i - j) + *reinterpret_cast<int*>(c_location + i + 1) + 7));
					found++;
					j = matches = 0;
				}
				j++;
			}
			else
			{
				matches = j = 0;
			}
			i++;
		}
	}

	Log::Msg("Initializing natives");
	CrossMapping::initNativeMap();

	Log::Msg("Checking if GTA V is ready");
	while (*m_gameState != GameStatePlaying) {
		Sleep(200);
	}

	/*setPat<void>("name_changer",
		"\x48\x8B\x05\x00\x00\x00\x00\xC3\x8A\xD1",
		"xxx????xxx",
		&Hooking::mon,
		true, 3, 1);*/

	Log::Msg("GTA V ready");
	//CrossMapping::dumpNativeMappingCache();
}

static Hooking::NativeHandler _Handler(uint64_t origHash)
{
	uint64_t newHash = CrossMapping::MapNative(origHash);
	if (newHash == 0)
	{
		return nullptr;
	}

	Hooking::NativeRegistrationNew * table = m_registrationTable[newHash & 0xFF];

	for (; table; table = table->getNextRegistration())
	{
		for (uint32_t i = 0; i < table->getNumEntries(); i++)
		{
			if (newHash == table->getHash(i))
			{
				return table->handlers[i];
			}
		}
	}
	return nullptr;
}

Hooking::NativeHandler Hooking::GetNativeHandler(uint64_t origHash)
{
	auto& handler = m_handlerCache[origHash];

	if (handler == nullptr)
	{
		handler = _Handler(origHash);
	}

	return handler;
}

eGameState Hooking::GetGameState()
{
	return *m_gameState;
}

uint64_t Hooking::getWorldPtr()
{
	return m_worldPtr;
}
void WAIT(DWORD ms)
{
	wakeAt = timeGetTime() + ms;
	SwitchToFiber(mainFiber);
}

void Hooking::Cleanup()
{
	Log::Msg("Cleaning up hooks");
	ownedExplosionBypass(false);
	Log::Msg("Disabled OE bypass");
	/*if (m_object_spawn != nullptr)
		memcpy_s(m_object_spawn, sizeof(object_spawn), object_spawn, sizeof(object_spawn));
	Log::Msg("m_object_spawn mem nop fixed.");*/
	/*if (m_model_bypass != nullptr)
		memcpy_s(m_model_bypass, sizeof(m_model_bypass), model_bypass, sizeof(m_model_bypass));
	Log::Msg("MMB mem nop fixed");*/
	if (m_int_checker != nullptr) {
		memcpy_s(m_int_checker, sizeof(int_check), int_check, sizeof(int_check));
		m_int_checker[0] = og_int_checker;
	}
	iHook.keyboardHandlerUnregister(OnKeyboardMessage);
	iHook.Remove();
	Log::Msg("iHK removed");
	bool b = (MH_DisableHook(&ResetWriteWatch) != MH_OK && MH_RemoveHook(&ResetWriteWatch) != MH_OK);
	Log::Msg("ResetWriteWatch completed");
	//b = (MH_DisableHook(Hooking::is_DLC_present) != MH_OK && MH_RemoveHook(Hooking::is_DLC_present) != MH_OK);
	//Log::Msg("is_DLC_present Disabled and Removed.");
	for (int i = 0; i < m_hookedNative.size(); i++)
		b = (MH_DisableHook(m_hookedNative[i]) != MH_OK && MH_RemoveHook(m_hookedNative[i]) != MH_OK);
	Log::Msg("Disabled all hooked natives");
	MH_Uninitialize();
	Log::Msg("Uninitialize finished");
}

void Hooking::defuseEvent(RockstarEvent e, bool toggle)
{
	static const unsigned char retn = 0xC3;
	char* p = (char*)EventPtr[e];
	if (toggle)
	{
		if (EventRestore[e] == 0)
			EventRestore[e] = p[0];
		*p = retn;
	}
	else
	{
		if (EventRestore[e] != 0)
			*p = EventRestore[e];
	}
}

void Hooking::settime(int Hours, int Minutes, int Seconds) {

	static auto pizza = reinterpret_cast<void(*)(int, int, int)>(pattern("80 3D ? ? ? ? ? 75 37 8B 05 ? ? ? ? C6").count(1).get(0).get<void>(0));
	pizza(Hours, Minutes, Seconds);
}

__int64** Hooking::getGlobalPtr()
{
	return m_globalPtr;
}

__int64* Hooking::getGlobalPtr1(int index)
{
	return &Hooking::getGlobalPtr()[index >> 18 & 0x3F][index & 0x3FFFF];
}

BlipList* Hooking::GetBlipList()
{
	return m_blipList;
}

Ped Hooking::get_player_ped(Player player) {
	const auto Address = Hooking::get_player_address(player);
	if (Address) {
		return Hooking::address_to_entity(Address);
	}
	return NULL;
}

__int64* Hooking::getTunable(int Tunable) {
	return globalHandle(262145).At(Tunable).Get<__int64>();
}

void Hooking::setTunable(int Tunable, __int64 value) {
	globalHandle(262145).At(Tunable).As<__int64>() = value;
}

