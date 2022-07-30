#include "stdafx.h"

Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer));

Vehicle create_veh(Player plr, Hash hash) {
	STREAMING::REQUEST_MODEL(hash);
	Vehicle veh = VEHICLE::CREATE_VEHICLE(hash, pos.x, pos.y, -255.0f, heading, 1, 0);
	DECORATOR::DECOR_SET_INT(veh, "MPBitset", (1 << 10));
	return veh;
}

Object create_obj(Player plr, Hash hash) {
	STREAMING::REQUEST_MODEL(hash);
	Object obj = OBJECT::CREATE_OBJECT(hash, pos.x, pos.y, -255.0f, 1, 1, 0);
	return obj;
}

void gasCylinderMK2(Player plr, bool spawnincar) {
	int veh = create_veh(plr, $("oppressor2"));
	ENTITY::SET_ENTITY_ALPHA(veh, 1, 1);
	int obj = create_obj(plr, $("prop_gascyl_02a"));
	ENTITY::ATTACH_ENTITY_TO_ENTITY(obj, veh, 0, 0, 0.25f, 0, 91.f, 0, 0, 0, 0, 1, 0, 0, 1);

	if (spawnincar)
	{
		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
	}
}

void moddedvehBigOrangeDick(Player plr, bool spawnincar) {
	int playerVeh = create_veh(plr, 0x50B0215A); //VEHICLE_FLATBED
	VEHICLE::SET_VEHICLE_COLOURS(playerVeh, 64, 40);
    VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(playerVeh, "B I G");
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(playerVeh, 1);
	Object spawnedOrange = create_obj(plr, 0x8DA1C0E);
	ENTITY::ATTACH_ENTITY_TO_ENTITY(spawnedOrange, playerVeh, 0, 0, -0.690002, 2.089998, 0, 0, 90, false, false, true, false, 0, true); //1
	//ENTITY::SET_ENTITY_COLLISION(spawnedOrange, TRUE, TRUE);
	spawnedOrange = create_obj(plr, 0x8DA1C0E);
	ENTITY::ATTACH_ENTITY_TO_ENTITY(spawnedOrange, playerVeh, 0, 0, -6, 2.08998, 0, -22, 90, false, false, true, false, 0, true); //2
	spawnedOrange = create_obj(plr, 0x8DA1C0E);
	ENTITY::ATTACH_ENTITY_TO_ENTITY(spawnedOrange, playerVeh, 0, 0, -3.35, 2.500000, 0, -11, 90, false, false, true, false, 0, true); //3
	spawnedOrange = create_obj(plr, 0x8DA1C0E);
	ENTITY::ATTACH_ENTITY_TO_ENTITY(spawnedOrange, playerVeh, 0, -0.5, -3.35, 3, 0, -11, 90, false, false, true, false, 0, true); //4
	spawnedOrange = create_obj(plr, 0x8DA1C0E);
	ENTITY::ATTACH_ENTITY_TO_ENTITY(spawnedOrange, playerVeh, 0, -1, -3.35, 3.5, 0, -11, 90, false, false, true, false, 0, true); //5
	spawnedOrange = create_obj(plr, 0x8DA1C0E);
	ENTITY::ATTACH_ENTITY_TO_ENTITY(spawnedOrange, playerVeh, 0, -1.5, -3.35, 4.25, 43, -11, 90, false, false, true, false, 0, true); //6
	spawnedOrange = create_obj(plr, 0x8DA1C0E);
	ENTITY::ATTACH_ENTITY_TO_ENTITY(spawnedOrange, playerVeh, 0, -2, -3.35, 5, 23.25, -11, 90, false, false, true, false, 0, true); //7
	spawnedOrange = create_obj(plr, 0x8DA1C0E);
	ENTITY::ATTACH_ENTITY_TO_ENTITY(spawnedOrange, playerVeh, 0, -2.5, -3.35, 5.75, 31.25, -11, 90, false, false, true, false, 0, true); //8
	spawnedOrange = create_obj(plr, 0x8DA1C0E);
	ENTITY::ATTACH_ENTITY_TO_ENTITY(spawnedOrange, playerVeh, 0, -3, -3.35, 6.25, 18.5, -11, 90, false, false, true, false, 0, true); //9
	spawnedOrange = create_obj(plr, 0x8DA1C0E);
	ENTITY::ATTACH_ENTITY_TO_ENTITY(spawnedOrange, playerVeh, 0, -3.5, -3.35, 6.5, 18.5, -11, 90, false, false, true, false, 0, true); //11
	spawnedOrange = create_obj(plr, 0x8DA1C0E);
	ENTITY::ATTACH_ENTITY_TO_ENTITY(spawnedOrange, playerVeh, 0, -4.5, -3.35, 7, 18.5, -11, 90, false, false, true, false, 0, true); //12
	spawnedOrange = create_obj(plr, 0x8DA1C0E);
	ENTITY::ATTACH_ENTITY_TO_ENTITY(spawnedOrange, playerVeh, 0, -6.25, -3.35, 7.5, 9.25, -11, 90, false, false, true, false, 0, true); //13

	if (spawnincar)
		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), playerVeh, -1);
}

void moddedVeh6x6Monster(int plr, bool spawnincar) {
	Vector3 a; a.x = 0, a.y = 0, a.z = 0.03f;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	int hash = $("dune2");
	int hash2 = $("t20");
	int hash3 = $("monster");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	STREAMING::REQUEST_MODEL(hash3);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3)) {
		int Object1 = create_veh(plr, hash);
		int Object2 = create_veh(plr, hash);
		int Object3 = create_veh(plr, hash);
		int Object4 = create_veh(plr, hash);
		int Object5 = create_veh(plr, hash);
		if (ENTITY::DOES_ENTITY_EXIST(Object1) && ENTITY::DOES_ENTITY_EXIST(Object2) && ENTITY::DOES_ENTITY_EXIST(Object3) && ENTITY::DOES_ENTITY_EXIST(Object4) && ENTITY::DOES_ENTITY_EXIST(Object5)) {
			int Vehicle = create_veh(plr, hash2);
			if (ENTITY::DOES_ENTITY_EXIST(Vehicle)) {
				ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(Object2, Vehicle, 0, a.x - 0.1f, a.y, a.z, b.x, b.y + 41.1f, b.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(Object3, Vehicle, 0, a.x + 0.1f, a.y, a.z, b.x, b.y - 41.4f, b.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(Object4, Vehicle, 0, a.x + 1.41f, a.y, a.z - 0.2f, b.x - 179.99f, b.y, b.z, 0, 1, 0, 0, 2, 1);
				ENTITY::ATTACH_ENTITY_TO_ENTITY(Object5, Vehicle, 0, a.x - 1.41f, a.y, a.z - 0.2f, b.x - 179.99f, b.y, b.z, 0, 1, 0, 0, 2, 1);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 255, 255, 255);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 255, 255, 255);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object1, 255, 255, 255);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object1, 255, 255, 255);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object4, 255, 255, 255);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object4, 255, 255, 255);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object5, 255, 255, 255);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object5, 255, 255, 255);

				if (spawnincar)
					PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			}
		}
	}
}