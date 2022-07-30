#pragma once
#include "stdafx.h"
#include "reclass.h"

using fpNtQueryVirtualMemory = void*;
struct clockTime { int hour, minute, second; };
typedef void*(__cdecl* fpGetScriptHandlerIfNetworked)();
typedef void*(__cdecl* fpGetScriptHandler)();
typedef const char*(__cdecl* fpGetLabelText)(void* this_, const char *label);
typedef void(__cdecl* fpSetSessionTime)(int, int);
typedef BOOL(__cdecl* fpIsEntityUpsideDown)(Cam cam);
typedef BOOL(__cdecl* fpSetName)();
typedef BOOL(__cdecl* fpIsDLCPresent)(uint32_t dlchash);
typedef uint32_t*(*__cdecl fpFileRegister)(int*, const char*, bool, const char*, bool);
typedef int(__cdecl* TriggerScriptEvent)(int unk0, uint64_t* args, int argCount, int bitFlags);
typedef void(__cdecl* SetSessionWeather)(int eventGroup, int weatherID, int a3, _int64 alwaysZero);
typedef BOOL(__cdecl* GetEventData)(int eventGroup, int eventIndex, uint64_t* argStruct, int argStructSize);
typedef BOOL(__cdecl* fpStatSetInt)(Hash statname, int value, bool save);
typedef BOOL(__cdecl* fpStatSetBool)(Hash statname, bool value, bool save);
typedef BOOL(__cdecl* fpStatSetFloat)(Hash statname, float value, bool save);
typedef char*(__cdecl* fpGetPlayerName)(Player p);
typedef void(__cdecl* addOwnedExplosion)(Ped ped, Vector3 pos, int type, float dmgScale, bool isAudible, bool isInvis, float fCamShake);
typedef BOOL(__cdecl* fpGetEventData)(int eventGroup, int eventIndex, uint64_t* argStruct, int argStructSize);
typedef BOOL(__cdecl* fpSetLobbyTime)(int hours, int minutes, int seconds);
typedef void(__cdecl* fpGetChatMessage)(__int64 p0, __int64 p1, __int64 p2, char* msg);
typedef __int64(__cdecl* fpGetPlayerAddress)(Player player);
typedef Entity(__cdecl* fpAddressToEntity)(__int64 address);
typedef void(__cdecl* fpSetEntityMaxHealth)(Entity entity, int value);
typedef Vehicle(__cdecl* fpCreateVehicle)(Hash model, Vector3 pos, float heading, BOOL networked, BOOL unk2);
typedef BOOL(__cdecl* fpSetVehicleMod)(Vehicle vehicle, int modType, int modIndex, BOOL customTires);
typedef void(__cdecl* fpClearPedTasksImmediately)(Ped ped);
typedef int(__cdecl* fpGetNumberOfEvents)(BOOL p0);
typedef BOOL(__cdecl* fpNetworkIsSessionStarted)();
typedef BOOL(__cdecl* fpNetworkRequestControlOfNetworkId)(int netId);
typedef BOOL(__cdecl* fpNetworkRequestControlOfEntity)(Entity entity);
typedef BOOL(__cdecl* fpNetworkHasControlOfEntity)(Entity entity);
typedef void(__cdecl* fpSetNetworkIdCanMigrate)(int netId, BOOL toggle);
typedef int(__cdecl* fpGetNetworkTime)();
typedef BOOL(__cdecl* fpDecorSetInt)(Entity entity, char* propertyName, int value);
typedef void(__cdecl* fpDecorRegister)(char* propertyName, int type);
typedef void(__cdecl* fpChatMessage)(__int64 a1, __int64 a2, __int64 a3, char *message);
typedef __int64(__cdecl* fpGetSender)(__int64 a1, __int64 a2, __int64 a3);
typedef BOOL(__cdecl* fpIncrementStatHook)(__int64 a1, __int64 a2, float a3);
typedef BOOL(__cdecl* fpCreateAmbientPickup)(DWORD pickupHash, Vector3 pos, int unk0, int value, DWORD modelHash, bool unk1, bool unk2);
typedef BOOL(__cdecl* fpIntegrityCheck)();
typedef void(__cdecl* fpSetMobileRadioEnabledDuringGameplay)(bool toggle);
typedef void(__cdecl* fpRequestIpl)(char * ipl);
typedef BOOL(__cdecl* fpIsIplActive)(char * ipl);
typedef void(__cdecl* fpNetworkSessionKickPlayer)(Player player, bool unk);
typedef BOOL(__cdecl* fpNetworkShopCheckoutStart)(Any p0);
typedef int(__cdecl* fpGetPlayerMaxArmour)(Player player);
typedef Entity(__cdecl* fpGetEntityAttachedTo)(Entity entity);
typedef BOOL(__cdecl* fpSetEntityCollision)(Entity entity, BOOL toggle, BOOL keepPhysics);
typedef BOOL(__cdecl* fpEventHandler)(__int64 eventName, __int64 player, __int64 status, unsigned __int16 eventId, int unk, int eventHash, __int64 data1, __int64 data2);
typedef BOOL(__cdecl* fpStatSetDate)(DWORD hash, DWORD* value, int size, BOOL save);
typedef BOOL(__cdecl* fpStatGetInt)(DWORD hash, int* out, int unk0);
typedef BOOL(__cdecl* fpSendMessage)(char* message, int* networkHandle);
typedef BOOL(__cdecl* fpAddTextCompSubstrPlayerName)(char *text);
typedef BOOL(__cdecl* fpEndTextCmdDisplayText)(float x, float y);
typedef BOOL(__cdecl* fpBeginTextCmdDisplayText)(char *text);
typedef void(__cdecl* fpClearPedBloodDamage)(Ped ped, char* damagePack, float damage, float mult);
typedef void(__cdecl* fpSetVehicleOnGroundProperly)(Vehicle vehicle);
typedef void(__cdecl* fpSetVehicleNumberplateText)(Vehicle vehicle, char* plateText);
typedef BOOL(__cdecl* fpIsThisModelAPlane)(Hash model);
typedef BOOL(__cdecl* fpIsThisModelAHeli)(Hash model);
typedef void(__cdecl* fpSetHeliBladesFullSpeed)(Vehicle vehicle);
typedef float(__cdecl* fpEndTextCommandGetWidth)(bool p0);
typedef BOOL(__cdecl* fpRequestAnimDict)(char* dict);
typedef BOOL(__cdecl* fpHasAnimDictLoaded)(char* dict);
typedef BOOL(__cdecl* fpDrawNotification)(BOOL blink, BOOL p1);
typedef int(__cdecl* fpDrawNotification2)(bool blink, bool p1);
typedef BOOL(__cdecl* fpPickupRewardMoneyIsApplicableToPlayer)(void *thisptr, void *unk, void *ped);
typedef void(__cdecl* fpSetVehicleEngineOn)(Vehicle vehicle, BOOL value, BOOL instantly, BOOL otherwise);
typedef void(__cdecl* fpSetVehicleUndriveable)(Vehicle vehicle, BOOL toggle);
typedef BOOL(__cdecl* fpSetVehicleDriveable)(Vehicle vehicle, BOOL p1);
typedef char* (__cdecl* fpGetDisplayNameFromVehicle)(Hash modelHash);
typedef BOOL(__cdecl* fpToggleVehicleMod)(Vehicle vehicle, int modType, BOOL toggle);
typedef BOOL(__cdecl* fpNetworkShopBeginService)(Any* p0, Any p1, Any p2, Any p3, Any p4, Any p5);
typedef void(__cdecl* fpGiveDelayedWeaponToPed)(Ped ped, Hash weapon, int ammo, bool equip);
typedef void(__cdecl* fpRemoveAllPedWeapons)(Ped ped, bool unk);
typedef void(__cdecl* fpRemoveWeaponFromPed)(Ped ped, Hash weapon);
typedef Ped(__cdecl* fpGetPedInVehicleSeat)(Vehicle vehicle, int index);
typedef BOOL(__cdecl* fpIsAimCamActive)();
typedef void(__cdecl* fpDrawRect)(float x, float y, float width, float height, int r, int g, int b, int a);
typedef void(__cdecl* fpDrawLine)(Vector3 pos1, Vector3 pos2, int r, int g, int b, int a);
typedef Vector3(__cdecl* fpGetGameplayCamRot)(Vector3 out, uint32_t unk1);
typedef Vector3(__cdecl* fpGetGameplayCamCoord)(Vector3 out);
typedef int(__cdecl* fpNetworkGetNetworkIdFromEntity)(Entity entity);
typedef int(__cdecl* fpNetworkCreateSynchronisedScene)(Vector3 pos, Vector3 rot, int unk0, int unk1, int unk2, float unk3, float unk4, float unk5);
typedef int(__cdecl* fpNetworkAddPedToSynchronisedScene)(Ped ped, int scene, char* dict, char* anim, float speed, float speedMult, int duration, int flag, float playRate, int unk1, int unk2);
typedef int(__cdecl* fpNetworkStartSynchronisedScene)(int scene);
typedef BOOL(__cdecl* fpIsVehicleDrivable)(Vehicle vehicle, bool unk0);
typedef int(__cdecl* fpGetPlayerRadioStationIndex)();
typedef char*(__cdecl* fpGetRadioStationName)(int id);
typedef BOOL(__cdecl* fpSetVehicleForwardSpeed)(CVehicle* pVeh, float speed);
typedef void(__cdecl* fpSetVehicleFixed)(Vehicle vehicle);
typedef void(__cdecl* fpSetVehicleDeformationFixed)(CVehicle* pVehicle);
typedef BOOL(__cdecl* fpIsVehicleSeatFree)(Vehicle vehicle, int seatId, bool unk0);
typedef void(__cdecl* fpSetVehicleNumberPlateIndex)(CVehicle* vehicle, int plateId);
typedef BOOL(__cdecl* fpSetVehicleWheelType)(Vehicle vehicle, int wheelType);
typedef int(__cdecl* fpGetNumVehicleMod)(Vehicle vehicle, int modType);
typedef BOOL(__cdecl* fpSetNotificationTextEntry)(char* text);
typedef BOOL(__cdecl* fpUpdateOnscreenKeyboard)();
typedef BOOL(__cdecl* fpSetLocalPlayerVisibleLocally)(bool unk0);
typedef BOOL(__cdecl* fpAiTaskWanderStandard)(Ped ped, float unk0, bool unk1);
typedef BOOL(__cdecl* fpAiTaskPlayAnim)(Ped ped, char* dict, char* anim, float speed, float speedMult, int duration, int flg, float playRate, bool unk0, BOOL lockX, BOOL lockY, BOOL lockZ, bool unk1);
typedef BOOL(__cdecl* fpIsModelInCdimage)(DWORD hash);
typedef BOOL(__cdecl* fpIsModelValid)(DWORD hash);
typedef BOOL(__cdecl* fpIsModelAVehicle)(DWORD hash);
typedef BOOL(__cdecl* fpRequestModel)(DWORD hash);
typedef BOOL(__cdecl* fpHasModelLoaded)(DWORD hash);
typedef BOOL(__cdecl* fpGetPedLastWeaponImpactCoord)(Ped ped, Vector3* out);
typedef int(__cdecl* fpStartRayCast)(Vector3 pos1, Vector3 pos2, int flags, Entity entity, bool unk0);
typedef int(__cdecl* fpGetRayCast)(int handle, BOOL* hit, Vector3 end, Vector3 surface, Hash* material, Entity* entity);
typedef BOOL(__cdecl* fpNetworkSetInSpectatorMode)(bool toggle, Ped ped);
typedef BOOL(__cdecl* fpSetPedCombatAbility)(CPed* pPed, BYTE ability);
typedef BOOL(__cdecl* fpAiTaskCombatPed)(Ped ped, Ped target, int unk0, int unk1);
typedef BOOL(__cdecl* fpApplyVehicleColors)(CVehicle* vehicle, bool unk0);
typedef BOOL(__cdecl* fpSetPlayerVisibleLocally)(Player player, bool toggle);
typedef BOOL(__cdecl* fpSetModelAsNoLongerNeeded)(DWORD hash);
typedef Object(__cdecl* fpCreateObject)(Object modelHash, float x, float y, float z, BOOL isNetwork, BOOL thisScriptCheck, BOOL dynamic);
typedef void(__cdecl* fpSetOverrideWeather)(char* weatherType);
typedef BOOL(__cdecl* fpGetCurrentPedWeapon)(Ped ped, Hash* weaponHash, BOOL p2);
typedef int(__cdecl* fpGetTextScreenLineCount)(float x, float y);
typedef int(__cdecl* fpRequestScaleformMovie)(char* scaleformName);
typedef void(__cdecl* fpDrawScaleformMovie)(int scaleformHandle, float x, float y, float width, float height, int red, int green, int blue, int alpha, int unk);
typedef void(__cdecl* fpEndScaleformMovieMethod)();
typedef BOOL(__cdecl* fpIsDisabledControlPressed)(int inputGroup, int control);
typedef BOOL(__cdecl* fpIsPlayerFriend)(int *handle);

struct twoBytes
{
	BYTE byte[2];

	bool empty();
};

struct threeBytes
{
	BYTE byte[3];

	bool empty();
};

class Hooking
{

private:
	static BOOL InitializeHooks();
	static void FindPatterns();
	static void FailPatterns(const char* name);

public:
	static std::vector<LPVOID>                     m_hooks;
	static uint64_t*                               m_frameCount;
	static fpIsDLCPresent                          is_DLC_present;
	static TriggerScriptEvent        	           trigger_script_event;
	static SetSessionWeather                       set_session_weather;
	static fpStatSetInt			                   stat_set_int;
	static fpStatSetFloat                          stat_set_float;
	static fpStatSetBool                           stat_set_bool;
	static GetEventData                            get_script_event_data;
	static twoBytes*   		                       m_ownedExplosionBypass;
	static BYTE*                                   m_ownedExplosionBypass2;
	static addOwnedExplosion                       add_owned_explosion;
	static fpGetLabelText                          GetLabelText;
	static fpSetEntityMaxHealth                    set_entity_max_health;
	static fpCreateVehicle                         create_vehicle;
	static fpSetVehicleMod				           set_vehicle_mod;
	static fpClearPedTasksImmediately              clear_ped_tasks_immediately;
	static fpGetNumberOfEvents                     get_number_of_events;
	static fpNetworkIsSessionStarted               is_session_started;
	static fpNetworkRequestControlOfNetworkId      request_control_of_network_id;
	static fpNetworkRequestControlOfEntity         request_control_of_entity;
	static fpNetworkHasControlOfEntity             has_control_of_entity;
	static fpSetNetworkIdCanMigrate                set_network_id_can_migrate;
	static fpGetNetworkTime                        get_network_time;
	static fpDecorSetInt                           decor_set_int;
	static fpDecorRegister                         decor_register;
	static fpIntegrityCheck                        integrity_check;
	static fpSetMobileRadioEnabledDuringGameplay   set_mobile_radio_enabled_during_gameplay;
	static fpGetPlayerName                         GPN;
	static HMODULE                                 scriptDLL;
	static fpGetEventData                          get_event_data;
	static fpSetLobbyTime                          set_lobby_time;
	static fpGetChatMessage                        get_chat_message;
	static fpGetPlayerAddress                      get_player_address;
	static fpAddressToEntity                       address_to_entity;
	static fpEventHandler                          event_handler;
	static fpSetName                               set_name_kek;
	static CReplayInterface*                       m_replayIntf;
	static clockTime*                              ClockTime;
	static fpSetSessionTime                        set_session_time;
	static fpChatMessage                           get_message;
	static fpGetSender                             get_sender;
	static fpIncrementStatHook                     increment_stat;
	static fpCreateAmbientPickup                   create_ambient_pickup;
	static fpGetScriptHandlerIfNetworked           GetScriptHandlerIfNetworked;
	static fpGetScriptHandler                      GetScriptHandler;
	static fpIsEntityUpsideDown                    is_entity_upsidedown;
	static fpRequestIpl                            request_ipl;
	static fpIsIplActive                           is_ipl_active;
	static fpNetworkSessionKickPlayer              network_session_kick_player;
	static fpNetworkShopCheckoutStart              network_shop_checkout_start;
	static fpGetPlayerMaxArmour                    get_player_max_armour;
	static fpGetEntityAttachedTo                   get_entity_attached_to;
	static fpSetEntityCollision                    set_entity_collision;
	static fpStatSetDate                           stat_set_date;
	static fpStatGetInt                            stat_get_int;
	static fpAddTextCompSubstrPlayerName	       add_text_comp_substr_playername;
	static fpEndTextCmdDisplayText	               end_text_command_display_text;
	static fpBeginTextCmdDisplayText	           begin_text_command_display_text;
	static fpSendMessage                           send_message;
	static fpClearPedBloodDamage                   clear_ped_blood_damage;
	static fpSetVehicleOnGroundProperly            set_vehicle_on_ground_properly;
	static fpSetVehicleNumberplateText             set_vehicle_numberplate_text;
	static fpIsThisModelAPlane                     is_this_model_a_plane;
	static fpIsThisModelAHeli                      is_this_model_a_heli;
	static fpSetHeliBladesFullSpeed                set_heli_blades_full_speed;
	static fpEndTextCommandGetWidth                end_text_command_get_width;
	static fpRequestAnimDict                       request_anim_dict;
	static fpHasAnimDictLoaded                     has_anim_dict_loaded;
	static fpDrawNotification                      draw_notification;
	static fpDrawNotification2                     draw_notification_2;
	static fpNtQueryVirtualMemory                  NtQueryVirtualMemory;
	static fpPickupRewardMoneyIsApplicableToPlayer pickup_is_applicable_to_player;
	static fpSetVehicleEngineOn                    set_vehicle_engine_on;
	static fpSetVehicleUndriveable                 set_vehicle_undriveable;
	static fpSetVehicleDriveable                   set_vehicle_driveable;
	static fpGetDisplayNameFromVehicle             get_display_name_from_vehicle;
	static fpToggleVehicleMod                      toggle_vehicle_mod;
	static fpNetworkShopBeginService               network_shop_begin_service;
	static fpGiveDelayedWeaponToPed                give_delayed_weapon_to_ped;
	static fpRemoveAllPedWeapons                   remove_all_ped_weapons;
	static fpRemoveWeaponFromPed                   remove_weapon_from_ped;
	static fpGetPedInVehicleSeat                   get_ped_in_vehicle_seat;
	static fpIsAimCamActive                        is_aim_cam_active;
	static fpDrawRect                              draw_rect;
	static fpDrawLine                              draw_line;
	static fpGetGameplayCamRot                     get_gameplay_cam_rot;
	static fpGetGameplayCamCoord                   get_gameplay_cam_coord;
	static fpNetworkGetNetworkIdFromEntity         get_network_id_from_entity;
	static fpNetworkCreateSynchronisedScene        create_synchronised_scene;
	static fpNetworkAddPedToSynchronisedScene      add_ped_to_synchronised_scene;
	static fpNetworkStartSynchronisedScene         start_synchronised_scene;
	static fpIsVehicleDrivable                     is_vehicle_driveable;
	static threeBytes*                             infinite_ammo;
	static threeBytes*                             no_reload;
	static fpGetPlayerRadioStationIndex            get_player_radio_station_index;
	static fpGetRadioStationName                   get_radio_station_name;
	static fpSetVehicleForwardSpeed				   set_vehicle_forward_speed;
	static fpSetVehicleFixed                       set_vehicle_fixed;
	static fpSetVehicleDeformationFixed            set_vehicle_deformation_fixed;
	static fpIsVehicleSeatFree                     is_vehicle_seat_free;
	static fpSetVehicleNumberPlateIndex            set_vehicle_number_plate_index;
	static fpSetVehicleWheelType                   set_vehicle_wheel_type;
	static fpGetNumVehicleMod                      get_num_vehicle_mod;
	static fpSetNotificationTextEntry              set_notification_text_entry;
	static fpUpdateOnscreenKeyboard                update_onscreen_keyboard;
	static fpSetLocalPlayerVisibleLocally          set_local_player_visible_locally;
	static fpAiTaskWanderStandard                  ai_task_wander_standart;
	static fpAiTaskPlayAnim                        ai_task_play_anim;
	static fpIsModelInCdimage                      is_model_in_cdimage;
	static fpIsModelValid                          is_model_valid;
	static fpIsModelAVehicle                       is_model_a_vehicle;
	static fpRequestModel                          request_model;
	static fpHasModelLoaded                        has_model_loaded;
	static fpGetPedLastWeaponImpactCoord           get_ped_last_weapon_impact_coord;
	static fpStartRayCast                          start_ray_cast;
	static fpGetRayCast                            get_ray_cast;
	static fpNetworkSetInSpectatorMode             set_in_spectator_mode;
	static fpSetPedCombatAbility                   set_ped_combat_ability;
	static fpAiTaskCombatPed                       ai_task_combat_ped;
	static fpApplyVehicleColors                    apply_vehicle_colors;
	static fpSetPlayerVisibleLocally               set_player_visible_locally;
	static fpSetModelAsNoLongerNeeded              set_model_as_no_longer_needed;
	static fpCreateObject						   create_object;
	static fpSetOverrideWeather 			       set_override_weather;
	static fpGetCurrentPedWeapon 				   get_current_ped_weapon;
	static fpGetTextScreenLineCount			       get_text_screen_line_count;
	static fpRequestScaleformMovie 			       request_scaleform_movie;
	static fpDrawScaleformMovie 			       draw_scaleform_movie;
	static fpEndScaleformMovieMethod 		   	   end_scaleform_movie_method;
	static fpIsDisabledControlPressed 			   is_disabled_control_pressed;
	static fpIsPlayerFriend                        is_player_friend;
	static void*                                   mon;
	static char*                                   loading_text;
	static bool                                    patch_checker;
	static bool                                    e_weather_time;
	static bool                                    e_control;
	static bool                                    e_explosion;
	static bool                                    e_pickup;
	static bool                                    e_weapon;
	static bool                                    e_wanted;
	static bool                                    e_report;
	static bool                                    e_kick;
	static bool                                    e_freeze;
	static bool                                    e_stat;
	static bool                                    e_ptfx;
	static bool                                    e_redirect;
	static bool                                    e_notify;
	static bool                                    rdev;
	static bool                                    event_handler_on;
	static bool                                    protect;
	static bool                                    dump;
	static bool                                    notify;
	static bool                                    redirect;
	static bool                                    reportNotification;
	static bool                                    blockall;
	static bool                                    smart_protex;
	static bool                                    smart_pro;
	static bool                                    logger;
	static bool                                    rid_join;

	static MemoryPool**			                   m_entityPool;
	static CViewPort*				               m_viewPort;
	static screenReso*				               m_resolution;
	static void*					               m_objectHashTable;
	static void*					               m_objectHashTableSectionEnd;
	static void*					               m_onlineName;
	static CTextInfo*				               m_textInfo;
	static char*					               m_onscreenKeyboardResult;
	static clockTime*				               m_clockTime;
	static uint64_t*				               m_networkTime;
	static MemoryPool**				               m_pedPool;
	static 	void*					               m_gameInfo;
	static CPlayers*				               m_players;
	
	static void Start(HMODULE hmoduleDLL);
	static void Cleanup();
	static BlipList* GetBlipList();
	static eGameState GetGameState();
	static uint64_t getWorldPtr();
	static void onTickInit();
	static bool HookNatives();
	static __int64** getGlobalPtr();
	static __int64* getGlobalPtr1(int index);
	static __int64* getTunable(int Tunable);
	static void setTunable(int Tunable, __int64 value);
	static void defuseEvent(RockstarEvent e, bool toggle);
	static void settime(int Hours, int Minutes, int Seconds);
	static void ownedExplosionBypass(bool toggle); //OWNED_EXPLOSION
	static bool GED(int eventGroup, int eventIndex, uint64_t* argStruct, int argStructSize);
	static Ped get_player_ped(Player player);
	static bool found_idp;
	static bool found_dce;
	static bool found_ssi;
	static bool found_sge;
	static bool found_gcm;
	static bool found_glt;
	static bool found_gsh;
	static bool found_ged;
	static bool found_nts;
	static bool found_prw;
	static void foundPtr(char *name);

	template <typename T>
	static void NOPE(T* address, T& restore, bool toggle)
	{
		if (toggle)
		{
			if (restore.empty())
				restore = *address;
			memset(address, '\x90', sizeof(T));
		}
		else if (!restore.empty())
			memcpy_s(address, sizeof(address), restore.byte, sizeof(T));
	}

	//static bool SetStatsIntHook(Hash statName, int value);

	// Native function handler type
	typedef void(__cdecl * NativeHandler)(scrNativeCallContext * context);

	struct NativeRegistrationNew
	{
		uint64_t nextRegistration1;
		uint64_t nextRegistration2;
		Hooking::NativeHandler handlers[7];
		uint32_t numEntries1;
		uint32_t numEntries2;
		uint64_t hashes;

		inline NativeRegistrationNew* getNextRegistration()
		{
			uintptr_t result;
			auto v5 = reinterpret_cast<uintptr_t>(&nextRegistration1);
			auto v12 = 2i64;
			auto v13 = v5 ^ nextRegistration2;
			auto v14 = (char *)&result - v5;
			do
			{
				*(DWORD*)&v14[v5] = v13 ^ *(DWORD*)v5;
				v5 += 4i64;
				--v12;
			} while (v12);

			return reinterpret_cast<NativeRegistrationNew*>(result);
		}

		inline uint32_t getNumEntries()
		{
			return ((uintptr_t)&numEntries1) ^ numEntries1 ^ numEntries2;
		}

		inline uint64_t getHash(uint32_t index)
		{

			auto naddr = 16 * index + reinterpret_cast<uintptr_t>(&nextRegistration1) + 0x54;
			auto v8 = 2i64;
			uint64_t nResult;
			auto v11 = (char *)&nResult - naddr;
			auto v10 = naddr ^  *(DWORD*)(naddr + 8);
			do
			{
				*(DWORD *)&v11[naddr] = v10 ^ *(DWORD*)(naddr);
				naddr += 4i64;
				--v8;
			} while (v8);

			return nResult;
		}
	};
	static NativeHandler GetNativeHandler(uint64_t origHash);
};

void WAIT(DWORD ms);


enum eThreadState
{
	ThreadStateIdle = 0x0,
	ThreadStateRunning = 0x1,
	ThreadStateKilled = 0x2,
	ThreadState3 = 0x3,
	ThreadState4 = 0x4,
};

struct scrThreadContext
{
	int ThreadID;
	int ScriptHash;
	eThreadState State;
	int _IP;
	int FrameSP;
	int _SPP;
	float TimerA;
	float TimerB;
	int TimerC;
	int _mUnk1;
	int _mUnk2;
	int _f2C;
	int _f30;
	int _f34;
	int _f38;
	int _f3C;
	int _f40;
	int _f44;
	int _f48;
	int _f4C;
	int _f50;
	int pad1;
	int pad2;
	int pad3;
	int _set1;
	int pad[17];
};

struct scrThread
{
	void *vTable;
	scrThreadContext m_ctx;
	void *m_pStack;
	void *pad;
	void *pad2;
	const char *m_pszExitMessage;
};

struct ScriptThread : scrThread
{
	const char Name[64];
	void *m_pScriptHandler;
	const char gta_pad2[40];
	const char flag1;
	const char m_networkFlag;
	bool bool1;
	bool bool2;
	bool bool3;
	bool bool4;
	bool bool5;
	bool bool6;
	bool bool7;
	bool bool8;
	bool bool9;
	bool bool10;
	bool bool11;
	bool bool12;
	const char gta_pad3[10];
};

/*
//CPatternResult
*/

class CPatternResult
{
public:
	CPatternResult(void* pVoid);
	CPatternResult(void* pVoid, void* pBegin, void* pEnd);
	~CPatternResult();

	template <typename rT>
	rT*	get(int offset = 0)
	{
		rT*	ret = nullptr;
		if (m_pVoid != nullptr)
			ret = reinterpret_cast<rT*>(reinterpret_cast<char*>(m_pVoid) + offset);
		return ret;
	}

	template <typename rT>
	rT* get_rel(int offset = 0)
	{
		rT*		result = nullptr;
		int32_t	rel;
		char*	ptr = get<char>(offset);

		if (ptr == nullptr)
			goto LABEL_RETURN;

		rel = *(int32_t*)ptr;
		result = reinterpret_cast<rT*>(ptr + rel + sizeof(rel));

	LABEL_RETURN:
		return result;
	}

	template <typename rT>
	rT*	section_begin()
	{
		return reinterpret_cast<rT*>(m_pBegin);
	}

	template <typename rT>
	rT*	section_end()
	{
		return reinterpret_cast<rT*>(m_pEnd);
	}

protected:
	void*	m_pVoid = nullptr;
	void*	m_pBegin = nullptr;
	void*	m_pEnd = nullptr;
};

class CMetaData
{
public:
	static uint64_t	begin();
	static uint64_t	end();
	static DWORD	size();
	static void		init();
private:
	static uint64_t	m_begin;
	static uint64_t	m_end;
	static DWORD	m_size;
};

/*
//CPattern
*/

typedef	std::vector<CPatternResult>	vec_result;
class CPattern
{
public:
	CPattern(char* szByte, char* szMask);
	~CPattern();

	CPattern&		find(int i = 0, uint64_t startAddress = 0);		//scans for i patterns
	CPattern&		virtual_find(int i = 0, uint64_t startAddress = 0);
	CPatternResult	get(int i);				//returns result i

protected:
	char*			m_szByte;
	char*			m_szMask;
	bool			m_bSet;
	vec_result		m_result;

	bool		match(int i = 0, uint64_t startAddress = 0, bool virt = false);
	bool		byte_compare(const BYTE* pData, const BYTE* btMask, const char* szMask);
	uint64_t	find_pattern(uint64_t i64Address, uint64_t end, BYTE *btMask, char *szMask);
	uint64_t	virtual_find_pattern(uint64_t address, BYTE *btMask, char *szMask);
};