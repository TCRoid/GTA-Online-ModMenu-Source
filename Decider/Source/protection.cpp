#include "stdafx.h"
#include "Hooking.h"
#include "list.h"
#include "menu.h"
#include "protection.h"
#include <vcruntime.h>
feat::feat() {}
feat::~feat() {}
void blockScriptEvents(bool feature,std::ptrdiff_t index)
{
	if (!feature == false)
	{
		globalHandle(1394274).At(index).As<int>() = 0;
		return;
	}
	if (globalHandle(1394274).At(index).As<int>() != 1)
		globalHandle(1394274).At(index).As<int>() = 1;

	return;
}

void AntiCeoKick(bool t)
{
	blockScriptEvents(t, 587);
	return;
}

void AntiSPKick(bool t)
{
	constexpr ptrdiff_t offests[] = { 6,16,20,341,383,632,647,651,657,658,752 };
	for (auto index : offests) {
		globalHandle(1394274).At(index).As<int>() = 0;
	}
	return;
	for (auto index : offests) {
		if (globalHandle(1394274).At(index).As<int>() != 1)
			globalHandle(1394274).At(index).As<int>() = 1;
	}

	return;
}

void AntiApartmentTP(bool t)
{
	blockScriptEvents(t, 550);
	return;
}

void AntiRemoteBounty(bool t)
{
	blockScriptEvents(t, 74);
	return;
}

void antiRemoteVehicleKick(bool t)
{
	blockScriptEvents(t, 64);
	return;
}

void antiRemoteForceMission(bool t)
{
	blockScriptEvents(t, 742);
	return;
}

void AntiReport(bool t) {
	Hooking::defuseEvent(PLAYER_CARD_STAT_EVENT, true);
	Hooking::defuseEvent(REPORT_MYSELF_EVENT, true);
	Hooking::defuseEvent(REPORT_CASH_SPAWN_EVENT, true);
	globalHandle(1388057).At(0).As<int>() = 0;
	globalHandle(1388059).At(0).As<int>() = 0;
	globalHandle(1388060).At(0).As<int>() = 0;
	globalHandle(1388062).At(0).As<int>() = 0;
	globalHandle(1388063).At(0).As<int>() = 0;
}

void AntiKick(bool t) {
		Hooking::defuseEvent(REMOTE_SCRIPT_LEAVE_EVENT, true);
		Hooking::defuseEvent(KICK_VOTES_EVENT, true);
		Hooking::defuseEvent(SCRIPTED_GAME_EVENT, true);
		Hooking::defuseEvent(REMOTE_SCRIPT_LEAVE_EVENT, true);
		globalHandle(1377446).At(594).As<int>() = 594; //SP kick
		globalHandle(1377446).At(595).As<int>() = 595; //kick
		globalHandle(1382674).At(584).As<int>() = 584;;
}

void AntiFreeze(bool t) {
		Hooking::defuseEvent(NETWORK_CLEAR_PED_TASKS_EVENT, true);
		Hooking::defuseEvent(RAGDOLL_REQUEST_EVENT, true);
		Hooking::defuseEvent(INCIDENT_ENTITY_EVENT, true);
		Hooking::defuseEvent(REQUEST_CONTROL_EVENT, true);
		Hooking::defuseEvent(NETWORK_CLEAR_PED_TASKS_EVENT, true);
		Hooking::defuseEvent(NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT, true);
}

void AntiAttachment(bool toggle)
{
	Hooking::defuseEvent(REQUEST_DETACHMENT_EVENT, true);

	for (int i = 0; i < 5; i++) {
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		GAMEPLAY::CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 2, 0);
		GAMEPLAY::CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 2, 0);
		GAMEPLAY::CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 2, 0, 0, 0, 0, 0);
		for (int i = 0; i < 136; i++) {
			Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 4.0, GAMEPLAY::GET_HASH_KEY(objects[i]), 0, 0, 1);
			if (ENTITY::DOES_ENTITY_EXIST(obj) && ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(obj, PLAYER::PLAYER_PED_ID())) {
				RequestControlOfEnt(obj);
				int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(obj);
				NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
				request_control_id(netID);
				ENTITY::DETACH_ENTITY(obj, 1, 1);
				ENTITY::DELETE_ENTITY(&obj);
			}
		}
	}
}

void AntiExplosion(bool t) {
		Hooking::defuseEvent(FIRE_EVENT, true);
		Hooking::defuseEvent(EXPLOSION_EVENT, true);
		Hooking::defuseEvent(REQUEST_PHONE_EXPLOSION_EVENT, true);
		Hooking::defuseEvent(BLOW_UP_VEHICLE_EVENT, true);
}

void AntiSound(bool t) {
		Hooking::defuseEvent(NETWORK_SOUND_CAR_HORN_EVENT, true);
		Hooking::defuseEvent(NETWORK_PLAY_SOUND_EVENT, true);
		Hooking::defuseEvent(NETWORK_STOP_SOUND_EVENT, true);
		Hooking::defuseEvent(NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT, true);
		Hooking::defuseEvent(CHANGE_RADIO_STATION_EVENT, true);
}

void AntiStars(bool t) {
		Hooking::defuseEvent(ALTER_WANTED_LEVEL_EVENT, true);
}

void AntiStat(bool t) {
		Hooking::defuseEvent(NETWORK_BANK_REQUEST_EVENT, true);
		Hooking::defuseEvent(NETWORK_INCREMENT_STAT_EVENT, true);
}

void AntiGiveWeapon (bool t)
{
		Hooking::defuseEvent(GIVE_WEAPON_EVENT, true);
}

void AntiRemoveWeapon(bool t)
{
		Hooking::defuseEvent(REMOVE_WEAPON_EVENT, true);
		Hooking::defuseEvent(REMOVE_ALL_WEAPONS_EVENT, true);
}

void AntiFire(bool t)
{
		Hooking::defuseEvent(FIRE_EVENT, true);
}

void AntiDrop(bool t)
{
		Hooking::defuseEvent(REQUEST_PICKUP_EVENT, true);
}

void AntiPTFX(bool t)
{
		Hooking::defuseEvent(NETWORK_PTFX_EVENT, true);
}

void AntiInvite(bool t)
{
		Hooking::defuseEvent(NETWORK_REQUEST_SYNCED_SCENE_EVENT, true);
		Hooking::defuseEvent(NETWORK_UPDATE_SYNCED_SCENE_EVENT, true);
		Hooking::defuseEvent(NETWORK_START_SYNCED_SCENE_EVENT, true);
}

void BlockAllNetEvents(bool t)
{
		Hooking::defuseEvent(SCRIPT_ARRAY_DATA_VERIFY_EVENT, true);
		Hooking::defuseEvent(REQUEST_CONTROL_EVENT, true);
		Hooking::defuseEvent(GIVE_CONTROL_EVENT, true);
		Hooking::defuseEvent(WEAPON_DAMAGE_EVENT, true);
		Hooking::defuseEvent(REQUEST_PICKUP_EVENT, true);
		Hooking::defuseEvent(REQUEST_MAP_PICKUP_EVENT, true);
		Hooking::defuseEvent(RESPAWN_PLAYER_PED_EVENT, true);
		Hooking::defuseEvent(GIVE_WEAPON_EVENT, true);
		Hooking::defuseEvent(REMOVE_WEAPON_EVENT, true);
		Hooking::defuseEvent(REMOVE_ALL_WEAPONS_EVENT, true);
		Hooking::defuseEvent(VEHICLE_COMPONENT_CONTROL_EVENT, true);
		Hooking::defuseEvent(FIRE_EVENT, true);
		Hooking::defuseEvent(EXPLOSION_EVENT, true);
		Hooking::defuseEvent(START_PROJECTILE_EVENT, true);
		Hooking::defuseEvent(ALTER_WANTED_LEVEL_EVENT, true);
		Hooking::defuseEvent(CHANGE_RADIO_STATION_EVENT, true);
		Hooking::defuseEvent(RAGDOLL_REQUEST_EVENT, true);
		Hooking::defuseEvent(PLAYER_TAUNT_EVENT, true);
		Hooking::defuseEvent(PLAYER_CARD_STAT_EVENT, true);
		Hooking::defuseEvent(DOOR_BREAK_EVENT, true);
		Hooking::defuseEvent(SCRIPTED_GAME_EVENT, true);
		Hooking::defuseEvent(REMOTE_SCRIPT_INFO_EVENT, true);
		Hooking::defuseEvent(REMOTE_SCRIPT_LEAVE_EVENT, true);
		Hooking::defuseEvent(MARK_AS_NO_LONGER_NEEDED_EVENT, true);
		Hooking::defuseEvent(CONVERT_TO_SCRIPT_ENTITY_EVENT, true);
		Hooking::defuseEvent(SCRIPT_WORLD_STATE_EVENT, true);
		Hooking::defuseEvent(INCIDENT_ENTITY_EVENT, true);
		Hooking::defuseEvent(CLEAR_AREA_EVENT, true);
		Hooking::defuseEvent(CLEAR_RECTANGLE_AREA_EVENT, true);
		Hooking::defuseEvent(NETWORK_REQUEST_SYNCED_SCENE_EVENT, true);
		Hooking::defuseEvent(NETWORK_START_SYNCED_SCENE_EVENT, true);
		Hooking::defuseEvent(NETWORK_UPDATE_SYNCED_SCENE_EVENT, true);
		Hooking::defuseEvent(NETWORK_STOP_SYNCED_SCENE_EVENT, true);
		Hooking::defuseEvent(GIVE_PED_SCRIPTED_TASK_EVENT, true);
		Hooking::defuseEvent(GIVE_PED_SEQUENCE_TASK_EVENT, true);
		Hooking::defuseEvent(NETWORK_CLEAR_PED_TASKS_EVENT, true);
		Hooking::defuseEvent(NETWORK_START_PED_ARREST_EVENT, true);
		Hooking::defuseEvent(NETWORK_START_PED_UNCUFF_EVENT, true);
		Hooking::defuseEvent(NETWORK_SOUND_CAR_HORN_EVENT, true);
		Hooking::defuseEvent(NETWORK_ENTITY_AREA_STATUS_EVENT, true);
		Hooking::defuseEvent(NETWORK_GARAGE_OCCUPIED_STATUS_EVENT, true);
		Hooking::defuseEvent(PED_CONVERSATION_LINE_EVENT, true);
		Hooking::defuseEvent(SCRIPT_ENTITY_STATE_CHANGE_EVENT, true);
		Hooking::defuseEvent(NETWORK_PLAY_SOUND_EVENT, true);
		Hooking::defuseEvent(NETWORK_STOP_SOUND_EVENT, true);
		Hooking::defuseEvent(NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT, true);
		Hooking::defuseEvent(NETWORK_BANK_REQUEST_EVENT, true);
		Hooking::defuseEvent(REQUEST_DOOR_EVENT, true);
		Hooking::defuseEvent(NETWORK_TRAIN_REQUEST_EVENT, true);
		Hooking::defuseEvent(NETWORK_TRAIN_REPORT_EVENT, true);
		Hooking::defuseEvent(NETWORK_INCREMENT_STAT_EVENT, true);
		Hooking::defuseEvent(MODIFY_VEHICLE_LOCK_WORD_STATE_DATA, true);
		Hooking::defuseEvent(REQUEST_PHONE_EXPLOSION_EVENT, true);
		Hooking::defuseEvent(REQUEST_DETACHMENT_EVENT, true);
		Hooking::defuseEvent(KICK_VOTES_EVENT, true);
		Hooking::defuseEvent(GIVE_PICKUP_REWARDS_EVENT, true);
		Hooking::defuseEvent(NETWORK_CRC_HASH_CHECK_EVENT, true);
		Hooking::defuseEvent(BLOW_UP_VEHICLE_EVENT, true);
		Hooking::defuseEvent(NETWORK_SPECIAL_FIRE_EQUIPPED_WEAPON, true);
		Hooking::defuseEvent(NETWORK_RESPONDED_TO_THREAT_EVENT, true);
		Hooking::defuseEvent(NETWORK_SHOUT_TARGET_POSITION, true);
		Hooking::defuseEvent(PICKUP_DESTROYED_EVENT, true);
		Hooking::defuseEvent(UPDATE_PLAYER_SCARS_EVENT, true);
		Hooking::defuseEvent(NETWORK_CHECK_EXE_SIZE_EVENT, true);
		Hooking::defuseEvent(NETWORK_PTFX_EVENT, true);
		Hooking::defuseEvent(NETWORK_PED_SEEN_DEAD_PED_EVENT, true);
		Hooking::defuseEvent(REMOVE_STICKY_BOMB_EVENT, true);
		Hooking::defuseEvent(NETWORK_CHECK_CODE_CRCS_EVENT, true);
		Hooking::defuseEvent(INFORM_SILENCED_GUNSHOT_EVENT, true);
		Hooking::defuseEvent(PED_PLAY_PAIN_EVENT, true);
		Hooking::defuseEvent(CACHE_PLAYER_HEAD_BLEND_DATA_EVENT, true);
		Hooking::defuseEvent(REMOVE_PED_FROM_PEDGROUP_EVENT, true);
		Hooking::defuseEvent(REPORT_MYSELF_EVENT, true);
		Hooking::defuseEvent(REPORT_CASH_SPAWN_EVENT, true);
		Hooking::defuseEvent(ACTIVATE_VEHICLE_SPECIAL_ABILITY_EVENT, true);
		Hooking::defuseEvent(NETWORK_CHECK_CATALOG_CRC, true);
}

void AntiVoteKick(bool t)
{
		Hooking::defuseEvent(KICK_VOTES_EVENT, true);
}

void AntiRequestControl(bool t)
{
		Hooking::defuseEvent(REQUEST_CONTROL_EVENT, true);
		Hooking::defuseEvent(RAGDOLL_REQUEST_EVENT, true);
		Hooking::defuseEvent(NETWORK_TRAIN_REQUEST_EVENT, true);
}

void AntiCage(bool toggle)
{
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
	Object obj1 = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 10.0f, 206865238, 0, 0, 1);
	Object obj2 = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 10.0f, GAMEPLAY::GET_HASH_KEY("prop_gascage01"), 0, 0, 1);
	std::vector<Hash> cage = { 959275690 };
	Object obj4 = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 10.0f, -512634970, 0, 0, 1);
	if (ENTITY::DOES_ENTITY_EXIST(obj1)) {
		RequestControlOfEnt(obj1);
		int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(obj1);
	    NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
		request_control_id(netID);
		ENTITY::DELETE_ENTITY(&obj1);
		OBJECT::DELETE_OBJECT(&obj1);
	}
	if (ENTITY::DOES_ENTITY_EXIST(obj2)) {
		RequestControlOfEnt(obj2);
     	int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(obj2);
		NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
		request_control_id(netID);
		ENTITY::DELETE_ENTITY(&obj2);
		OBJECT::DELETE_OBJECT(&obj2);
	}
	cage.clear();
	if (ENTITY::DOES_ENTITY_EXIST(obj4)) {
		RequestControlOfEnt(obj4);
		int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(obj4);
		NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
		request_control_id(netID);
		ENTITY::DELETE_ENTITY(&obj4);
		OBJECT::DELETE_OBJECT(&obj4);
	}
}

void AntiCargonplane(bool toggle)
{
	std::vector<Hash> cargoplane = { 0x15F27762 };
	cargoplane.clear();
}

void BlockAllEntity(bool toggle)
{
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 1);
	GAMEPLAY::CLEAR_AREA(coords.x, coords.y, coords.z, 100.0f, true, false, false, false);
	GAMEPLAY::_CLEAR_AREA_OF_EVERYTHING(coords.x, coords.y, coords.z, 100.0f, false, false, false, false);
	GAMEPLAY::CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 100.0f, 2);
	GAMEPLAY::CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 100.0f, 2);
	GAMEPLAY::CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 100.0f, false, false, false, false, false);
}

void BlockObjectCrash(bool toggle)
{
	blacklistedObjects.clear();
}

void BlockPedCrash(bool toggle)
{	
	PedProtex.clear();
}

void BlockVehicleCrash(bool toggle)
{
    blacklistveh.clear();
}