#include "stdafx.h"

Player GET_PLAYER_PED(Player player) {
	return PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
}

void SET_PLAYER_INVINCIBLE(Player player, bool toggle) {
	BYTE Setter = (toggle) ? 1 : 0;
	BYTE Current = Memory::get_value<BYTE>({ 0x08, 0x189 });
	if (Current != Setter)
		Memory::set_value({ 0x08, 0x189 }, Setter);
}

void TRIGGER_SCRIPT_EVENT(int eventGroup, Any *args, int argCount, Any bit) {
	Hooking::trigger_script_event(eventGroup, (uint64_t*)args, argCount, bit);
}

bool IS_PED_SHOOTING(Ped ped) {
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(ped, 1);
	return PED::IS_PED_SHOOTING_IN_AREA(ped, coords.x, coords.y, coords.z, coords.x, coords.y, coords.z, true, true);
}

bool IS_PLAYER_FREE_AIMING_AT_ENTITY(Player player, Entity entity) {
	Entity target;
	PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(player, &target);
	if (target == entity) {
		return true;
	}
	else {
		return false;
	}
}

bool IS_PLAYER_FREE_AIMING(Player player) {
	return GetAsyncKeyState(VK_RBUTTON);
}