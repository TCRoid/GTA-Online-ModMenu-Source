#include "features.h"
#include "script.h"
#include "nativeFuncs.h"
#include "pointers.h"
#include "gta_util.h"
#include "script_global.h"
#include "gui.h"
#include "vehicles.h"

using namespace std::chrono_literals;


namespace Memory {
	template <typename T>
	T get_value(std::vector<DWORD> offsets) {

		uintptr_t Addr = get_multilayer_pointer((uintptr_t)g_pointers->m_worldPtr, offsets);
		if (Addr == NULL) {
			return NULL;
		}

		return *((T*)Addr);
	}

	template <typename T>
	void set_value(std::vector<DWORD> offsets, T value) {
		uintptr_t Addr = get_multilayer_pointer((uintptr_t)g_pointers->m_worldPtr, offsets);
		if (Addr == NULL) {
			return;
		}

		*reinterpret_cast<T*>(Addr) = value;
	}
}

void features::scriptInit()
{
	ProtectionCallback();
}

void features::script_func()
{
	scriptInit();
	while (true)
	{
		run_tick();
		script::get_current()->yield(5ms);
	}
}


void CalcAngle(float* src, float* dst, float* angles)
{
	double delta[3] = { (src[0] - dst[0]), (src[1] - dst[1]), (src[2] - dst[2]) };
	double hyp = sqrt(delta[0] * delta[0] + delta[1] * delta[1]);
	angles[0] = (float)(asinf(delta[2] / hyp) * 57.295779513082f);
	angles[1] = (float)(atanf(delta[1] / delta[0]) * 57.295779513082f);
	angles[2] = 0.0f;
	if (delta[0] >= 0.0) { angles[1] += 180.0f; }
}

void features::run_tick()
{
	updateLocalData();
	updatePlayerData();
	updatePeds();

	selfOptins();
	weaponOptions();
	vehicleOptions();
	autoTpWaypoint();
	worldOptions();
	miscOptions();
	antiAttach();
	//NightClub ata();
}

void features::updateLocalData()
{
	localData.factory = *g_pointers->m_ped_factory;
	localData.currWepaon = localData.factory->m_local_ped->pCWeaponManager->currentWeapon;
	localData.maxhealth = localData.factory->m_local_ped->fHealthMax;
	localData.health = localData.factory->m_local_ped->fHealth;
	localData.localPed = PLAYER::PLAYER_PED_ID();
	localData.visualPos = localData.factory->m_local_ped->v3VisualPos;
	localData.localId = PLAYER::PLAYER_ID();
	localData.alive = !PLAYER::IS_PLAYER_DEAD(localData.localId);
	if (localData.IsInVehicle = PED::IS_PED_IN_ANY_VEHICLE(localData.localPed, FALSE))
		localData.vehicle = PED::GET_VEHICLE_PED_IS_IN(localData.localPed, FALSE);
	localData.teamId = PLAYER::GET_PLAYER_TEAM(PLAYER::PLAYER_ID());
	isTeamGameModeRunning = gta_util::find_script_thread(rage::joaat("fm_deathmatch_controler")) != nullptr;
	localData.connectedPlayers = NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS();
}

void features::updatePlayerData()
{
	for (int i = 0; i < 32; i++)
	{
		//if (*g_pointers->m_is_session_started)
		{
			if (playerData[i].IsConnected = NETWORK::NETWORK_IS_PLAYER_CONNECTED(i))
			{
				if (playerData[i].netPlayer = (CNetGamePlayer*)g_pointers->m_getNetPlayer(i))
				{
					if (playerData[i].IsValid = playerData[i].netPlayer->is_valid())
					{
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)))
						{
							if (playerData[i].netPlayer->get_net_data() != NULL)
							{
								if (playerData[i].netPlayer->get_net_data()->pCPed != NULL)
								{
									playerData[i].netData = playerData[i].netPlayer->get_net_data();
									playerData[i].cPed = playerData[i].netPlayer->get_net_data()->pCPed;

									playerData[i].IsHost = playerData[i].netPlayer->is_host();
									playerData[i].IsScriptHost = (NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i);
									if (bMiscAutoFriends)
										playerData[i].IsFriend = isFriend(i);
									playerData[i].online_ip = playerData[i].netPlayer->get_net_data()->m_online_ip;
									playerData[i].online_port = playerData[i].netPlayer->get_net_data()->m_online_port;
									playerData[i].rockstar_id = playerData[i].netPlayer->get_net_data()->m_rockstar_id;

									playerData[i].playerName = playerData[i].netPlayer->get_name();
									playerData[i].playerId = i;
									playerData[i].playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);

									playerData[i].alive = !PLAYER::IS_PLAYER_DEAD(i);
									playerData[i].wantedLevel = playerData[i].netPlayer->get_net_data()->m_wanted_level;
									playerData[i].IsInVehicle = PED::IS_PED_IN_ANY_VEHICLE(playerData[i].playerPed, FALSE);
									playerData[i].IsInInterrior = INTERIOR::GET_INTERIOR_FROM_ENTITY(playerData[i].playerPed) != NULL;
									playerData[i].teamId = PLAYER::GET_PLAYER_TEAM(i);
									if (bMiscAutoTeams)
										playerData[i].IsTeam = (playerData[i].teamId == localData.teamId) && isTeamGameModeRunning;
									playerData[i].godmode = ((playerData[i].netPlayer->get_net_data()->pCPed->btGodMode == 0x01) && !playerData[i].IsInInterrior);
									playerData[i].health = playerData[i].netPlayer->get_net_data()->pCPed->fHealth;
									playerData[i].maxHealth = playerData[i].netPlayer->get_net_data()->pCPed->fHealthMax;
									playerData[i].armour = PED::GET_PED_ARMOUR(playerData[i].playerPed);
									playerData[i].maxArmour = PLAYER::GET_PLAYER_MAX_ARMOUR(i);
									playerData[i].position = playerData[i].netPlayer->get_net_data()->pCPed->v3VisualPos;
									playerData[i].distance = GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(localData.visualPos.x, localData.visualPos.y, localData.visualPos.z, playerData[i].position.x, playerData[i].position.y, playerData[i].position.z, TRUE);
									playerData[i].speed = ENTITY::GET_ENTITY_SPEED(playerData[i].IsInVehicle ? PED::GET_VEHICLE_PED_IS_IN(playerData[i].playerPed, FALSE) : playerData[i].playerPed);
									playerData[i].heading = ENTITY::GET_ENTITY_HEADING(playerData[i].playerPed);

									playerData[i].wallet = *script_global::script_global(1590446).at(i, 871).at(211).at(3).as<int64_t*>();
									playerData[i].level = *script_global::script_global(1590446).at(i, 871).at(211).at(6).as<int32_t*>();
									playerData[i].ratio = *script_global::script_global(1590446).at(i, 871).at(211).at(26).as<float*>();
									playerData[i].kills = *script_global::script_global(1590446).at(i, 871).at(211).at(28).as<int32_t*>();
									playerData[i].deaths = *script_global::script_global(1590446).at(i, 871).at(211).at(29).as<int32_t*>();
									playerData[i].totalCash = *script_global::script_global(1590446).at(i, 871).at(211).at(56).as<int64_t*>();

									if (ESPSkeleton)
									{
										playerData[i].head = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_Head)); // kopf
										playerData[i].neck = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_Neck_1)); // genick
										playerData[i].stomach = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_Spine1)); // Bauch
										playerData[i].pelvis = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_Pelvis)); // Becken
										playerData[i].lThigh = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_L_Thigh)); // links schenkel
										playerData[i].rThigh = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_R_Thigh));  // rechts schenkel
										playerData[i].lCalf = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_L_Calf)); // links Knie
										playerData[i].rCalf = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_R_Calf)); // rechts Knie
										playerData[i].lFoot = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_L_Foot));  // links Ferse
										playerData[i].rFoot = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_R_Foot));  // rechts Ferse

										playerData[i].lClavicle = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_L_Clavicle));  // links Schlüsselbein
										playerData[i].rClavicle = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_R_Clavicle)); // rechts Schlüsselbein
										playerData[i].lUpperArm = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_L_UpperArm));
										playerData[i].rUpperArm = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_R_UpperArm));
										playerData[i].lForeArm = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_L_Forearm));
										playerData[i].rForeArm = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_R_Forearm));
										playerData[i].lHand = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_L_Hand));
										playerData[i].rHand = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_R_Hand));
									}						
								}
							}
						}
					}
				}
						
			}
			else
			{
				playerData[i].IsValid = false;
			}
		}
	}
}

void features::selfOptins()
{
	if (!PLAYER::IS_PLAYER_DEAD(PLAYER::PLAYER_ID()))
	{
		SelfGodMode();
		SelfNoRagdoll();
		SelfInivisible();
		SelfSeatbelt();
		SelfStamina();
		SelfFastRun();
		SelfFastSwim();
		SelfNeverWanted();
		SelfAlwaysWanted();
		SelfFakeWantedLevel();
		SelfHealthRechargeMultiplier();
		SelfPTFX();
		SelfOffRadar();
		SelfTinyPlayer();
		SelfInstantBST();
		SelfNoClip();
	}
}

void features::weaponOptions()
{
	if (!PLAYER::IS_PLAYER_DEAD(PLAYER::PLAYER_ID()))
	{
		frameFlags();
		WeaponImpacts();
		WeaponMods();
		WeaponGravityGun();
		WeaponDeleteGun();
		WeaponVehicleGun();
		WeaponAimer();
		WeaponRapidFire();
		WeaponInfinityAmmo();
	}
}

void features::vehicleOptions()
{
	vehicleDespawnBypass();


	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
	{	
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), FALSE);	
		g_vehicles.refreshVehicle(&g_vehicles.currVeh, veh);
		CarGodmode(veh);
		hornBoost(veh);
		VehiclePTFX(veh);
		DriveOnWater(veh);
		bulletProofTyres(veh);
		randomParts(veh);
		randomLivery(veh);
		flashWheels(veh);
		rainbowcar(veh);
		flashvehicle(veh);
		rainbowNeonKits(veh);
		FlashNeonKits(veh);
		rainbowTyresmoke(veh);
		flashTyresmoke(veh);
		flashHeadlights(veh);
		engineAlwayson(veh);
		stick_to_ground(veh);
		//groupup(veh);
		policemode();
		autoRepair();
	}
	setCarInvisible();
}

void features::teleportOptions()
{
	if (!PLAYER::IS_PLAYER_DEAD(PLAYER::PLAYER_ID()))
	{
		autoTpWaypoint();
	}
}

void features::worldOptions()
{
	clock_hours = TIME::GET_CLOCK_HOURS();
	clock_minutes = TIME::GET_CLOCK_MINUTES();
	clock_seconds = TIME::GET_CLOCK_SECONDS();
	if (!freezeTime)
	{
		clock_hours_freeze = 0;
		clock_minutes_freeze = 0;
		clock_seconds_freeze = 0;
	}

	if (timeCycleModifer != 0)
	{
		features::bProtectionClock = false;

		static bool timer_reset = true;
		static std::chrono::system_clock::time_point timer_Start;

		if (timer_reset)
		{
			timer_Start = std::chrono::system_clock::now();
			timer_reset = false;
		}

		std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - timer_Start;
		if (elapsed_seconds.count() >= (float)TIME::GET_MILLISECONDS_PER_GAME_MINUTE() / 60.f / 1000.f)
		{
			clock_seconds += timeCycleModifer;		

			TIME::SET_CLOCK_TIME(features::clock_hours, features::clock_minutes, features::clock_seconds);

			if (features::sync_time_with_network)
				if (*g_pointers->m_is_session_started)
				{
					NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(features::clock_hours, features::clock_minutes, features::clock_seconds);
					g_pointers->m_setSessionTime(1, 0);
				}

			timer_reset = true;
		}
	}

	if (freezeTime)
	{
		features::bProtectionClock = false;

		if (clock_hours_freeze == 0)
		{
			clock_hours_freeze = clock_hours;
			clock_minutes_freeze = clock_minutes;
			clock_seconds_freeze = clock_seconds;
		}

		static bool timer_reset = true;
		static std::chrono::system_clock::time_point timer_Start;

		if (timer_reset)
		{
			timer_Start = std::chrono::system_clock::now();
			timer_reset = false;
		}

		std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - timer_Start;
		if (elapsed_seconds.count() > 1.f)
		{
			TIME::SET_CLOCK_TIME(features::clock_hours_freeze, features::clock_minutes_freeze, features::clock_seconds_freeze);

			if (features::sync_time_with_network)
				if (*g_pointers->m_is_session_started)
				{
					NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(features::clock_hours_freeze, features::clock_minutes_freeze, features::clock_seconds_freeze);
					g_pointers->m_setSessionTime(1, 0);
				}

			timer_reset = true;
		}	
	}
}

void features::miscOptions()
{
	if (!PLAYER::IS_PLAYER_DEAD(PLAYER::PLAYER_ID()))
	{
		nearbyVehicleOptions();
		MiscDisablePhone();
		MiscDisableHud();
		//MiscSetAllPedsFlee();
	}
}

void features::MiscDisableHud()
{
	if (bMiscDisableHud)
		UI::HIDE_HUD_AND_RADAR_THIS_FRAME();
}

void features::ProtectionCallback()
{
	defuseEvent(KICK_VOTES_EVENT, bProtectionVoteKick);
	defuseEvent(GAME_WEATHER_EVENT, bProtectionWeather);
	defuseEvent(GAME_CLOCK_EVENT, bProtectionClock);
	defuseEvent(NETWORK_CLEAR_PED_TASKS_EVENT, bProtectionFreeze);
	defuseEvent(GIVE_PED_SCRIPTED_TASK_EVENT, bProtectionFreeze);
	defuseEvent(GIVE_PED_SEQUENCE_TASK_EVENT, bProtectionFreeze);
	defuseEvent(REQUEST_CONTROL_EVENT, bProtectionRequestControl);
	defuseEvent(EXPLOSION_EVENT, bProtectionExplosion);
	defuseEvent(FIRE_EVENT, bProtectionFire);
	defuseEvent(NETWORK_PTFX_EVENT, bProtectionPTFX);
}

void features::antiAttach()
{
	if (bProtectionAntiAttach)
	{
		static bool timer_reset = true;
		static std::chrono::system_clock::time_point timer_Start;

		if (timer_reset)
		{
			timer_Start = std::chrono::system_clock::now();
			timer_reset = false;
		}

		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - timer_Start;
		double seconds_passed = elapsed_seconds.count();

		if (seconds_passed > 0.2f)
		{
			CReplayInterface* replayIntf = *g_pointers->m_replayIntf;
			CObjectInterface* objIF = replayIntf->pCObjectInterface;
			CVehicleInterface* vehIF = replayIntf->pCVehicleInterface;

			static bool objectcheck = true;
			if (objectcheck)
			{
				int	numObj = objIF->iMaxObjects;
				for (int i = 0; i < numObj; ++i)
				{
					CObject* pObj = objIF->get_object(i);
					if (pObj == nullptr)
						continue;
					Object obj = g_pointers->m_ptr_to_handle(pObj);


					if (ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(obj, PLAYER::PLAYER_PED_ID()))
					{
						RequestControlOfEnt(obj);
						ENTITY::DETACH_ENTITY(obj, false, TRUE);
						ENTITY::SET_ENTITY_VISIBLE(obj, false, false);
						NETWORK::_NETWORK_SET_ENTITY_VISIBLE_TO_NETWORK(obj, false);
						ENTITY::SET_ENTITY_AS_MISSION_ENTITY(obj, 1, 1);
						ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&obj);
						ENTITY::DELETE_ENTITY(&obj);
					}
				}
				objectcheck = false;
			}
			else
			{
				int	numeh = vehIF->iMaxVehicles;
				for (int i = 0; i < numeh; ++i)
				{
					CVehicle* pVeh = vehIF->get_vehicle(i);
					if (pVeh == nullptr)
						continue;
					Vehicle veh = g_pointers->m_ptr_to_handle(pVeh);


					if (ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(veh, PLAYER::PLAYER_PED_ID()))
					{
						RequestControlOfEnt(veh);
						ENTITY::DETACH_ENTITY(veh, false, TRUE);
						ENTITY::SET_ENTITY_VISIBLE(veh, false, false);
						NETWORK::_NETWORK_SET_ENTITY_VISIBLE_TO_NETWORK(veh, false);
						ENTITY::SET_ENTITY_AS_MISSION_ENTITY(veh, 1, 1);
						ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&veh);
						ENTITY::DELETE_ENTITY(&veh);
						ENTITY::SET_ENTITY_COORDS(veh, 6400.f, 6400.f, 0.f, false, false, false, false);
					}
				}
				objectcheck = true;
			}
		
			timer_reset = true;
		}	
	}
}

void features::ProtectionsReset()
{
	defuseEvent(KICK_VOTES_EVENT, false);
	defuseEvent(GAME_WEATHER_EVENT, false);
	defuseEvent(GAME_CLOCK_EVENT, false);
	defuseEvent(NETWORK_CLEAR_PED_TASKS_EVENT, false);
	defuseEvent(GIVE_PED_SCRIPTED_TASK_EVENT, false);
	defuseEvent(GIVE_PED_SEQUENCE_TASK_EVENT, false);
	defuseEvent(REQUEST_CONTROL_EVENT, false);
	defuseEvent(EXPLOSION_EVENT, false);
	defuseEvent(FIRE_EVENT, false);
	defuseEvent(NETWORK_PTFX_EVENT, false);
}


void features::NightClubdata()
{
	if (loopNightclubCash)
	{
		int64_t* tmp = (int64_t*)(g_pointers->m_tunablePtr + 0x8);
		if (tmp != NULL)
		{
			*(int*)(*tmp + 0x2DB40) = 210000; // 100 %
			*(int*)(*tmp + 0x2DB38) = 210000; // 90-99%
			maxSafeMoney = *script_global::script_global(262145).at(23525).as<int*>() = 210000;
			currentSafeMoney = *script_global::script_global(1590446).at(PLAYER::PLAYER_ID()).at(273).at(318).at(5).as<int*>();
			//currentSafeMoney = *script_global::script_global(1589819).at(PLAYER::PLAYER_ID(), 818).at(273).at(316).at(5).as<int*>(); //old

			STATS::STAT_SET_INT(RAGE_JOAAT("MP0_CLUB_POPULARITY"), 1000, TRUE);
			STATS::STAT_SET_INT(RAGE_JOAAT("MP1_CLUB_POPULARITY"), 1000, TRUE);
			STATS::STAT_SET_INT(RAGE_JOAAT("MP0_CLUB_PAY_TIME_LEFT"), 1, TRUE);
			STATS::STAT_SET_INT(RAGE_JOAAT("MP1_CLUB_PAY_TIME_LEFT"), 1, TRUE);
		}
	}
}

void features::stealthMoney()
{
	gta_util::execute_as_script(RAGE_JOAAT("shop_controller"), []
		{
			DWORD transId = -1;
			g_pointers->m_transactionPreparer(*g_pointers->transHelper, &transId, -1135378931, 2919510285, -1216489292, 1445302971, 600000, 4);
			int64_t a3 = NULL;
			g_pointers->m_transactionProcessor(*g_pointers->transHelper, transId, a3);
		
			/*	DWORD transId = -1;
			g_pointers->m_transactionPreparer(*g_pointers->transHelper, &transId, -1135378931, 2919510285, -293060240, 1445302971, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(220000, 240000), 4);
			int64_t a3 = NULL;
			g_pointers->m_transactionProcessor(*g_pointers->transHelper, transId, a3);*/		
		});
}

void features::vehicleDespawnBypass()
{
	*script_global::script_global(4268190).as<BOOL*>() = features::bvehicleDespawnBypass;
}




void features::hornBoost(Vehicle veh)
{
	if (bHornBoost)
	{
		if (PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER::PLAYER_ID()))
		{
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(veh))
			{
				float speed = ENTITY::GET_ENTITY_SPEED(veh);
				speed += speed * 0.05f;
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, speed);
			}
		}
	}
}

void features::VehiclePTFX(Vehicle veh)
{
	static bool timer_reset = true;
	static std::chrono::system_clock::time_point timer_Start;

	if (timer_reset)
	{
		timer_Start = std::chrono::system_clock::now();
		timer_reset = false;
	}

	std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - timer_Start;
	if (elapsed_seconds.count() > 0.3f)
	{
		if (VehiclePTFXName != std::string("None"))
		{
			static std::string wheelBoneNames[]{
				"wheel_lm1",
				"wheel_lm2",
				"wheel_lm3",
				"wheel_lr",
				"wheel_rf",
				"wheel_rm1",
				"wheel_rm2",
				"wheel_rm3",
				"wheel_rr",
			};
				

			STREAMING::REQUEST_NAMED_PTFX_ASSET(VehiclePTFXCall.c_str());
			for (std::string str : wheelBoneNames)
			{
				int boneId = ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(veh, str.c_str());
				if (boneId != -1)
				{
					Vector3 vec = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(veh, boneId);
					printf("%.1f %.1f %.1f", vec.x, vec.y, vec.z);
					GRAPHICS::USE_PARTICLE_FX_ASSET(VehiclePTFXCall.c_str());
					//GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(VehiclePTFXCall.c_str(), veh, vec.x, vec.y, vec.z, 0.0, 0.0, 0.f, 1.0, false, false, false);			
					GRAPHICS::START_PARTICLE_FX_NON_LOOPED_AT_COORD(VehiclePTFXCall.c_str(), vec.x, vec.y, vec.z, 0, 0, 0, 5.5f, 0, 0, 0);
					//GRAPHICS::_START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE_2(VehiclePTFXName.c_str(), veh, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, boneId, 1.0f, false, false, false);
				}				
			}
		}
		timer_reset = true;
	}
}

void features::CarGodmode(Vehicle veh)
{
	static Vehicle lastCar = NULL;
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false))
	{
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);

		if (vehicle != lastCar && (lastCar != NULL))
		{
			ENTITY::SET_ENTITY_INVINCIBLE(lastCar, false);
			ENTITY::SET_ENTITY_PROOFS(lastCar, false, false, false, false, false, false, false, false);
			VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_DAMAGE(lastCar, false);
			VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(lastCar, false);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(lastCar, true);
			VEHICLE::SET_VEHICLE_CAN_BREAK(lastCar, true);
			VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE(lastCar, true);
			VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(lastCar, true);
			//VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(lastCar, true);
			//VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(lastCar, true);
		}

		if (bVehicleGodMode)
		{
			VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, false);
			VEHICLE::SET_VEHICLE_ENVEFF_SCALE(vehicle, 0.f);
			VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
			VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 0.f);

		}
		ENTITY::SET_ENTITY_INVINCIBLE(vehicle, bVehicleGodMode);
		ENTITY::SET_ENTITY_PROOFS(vehicle, bVehicleGodMode ? bVehicleGodMode : -1, bVehicleGodMode, bVehicleGodMode, bVehicleGodMode, bVehicleGodMode, bVehicleGodMode, bVehicleGodMode, bVehicleGodMode);

		VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_DAMAGE(vehicle, bVehicleGodMode);
		VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(vehicle, bVehicleGodMode);

		VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(vehicle, !bVehicleGodMode);
		VEHICLE::SET_VEHICLE_CAN_BREAK(vehicle, !bVehicleGodMode);

		VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE(vehicle, !bVehicleGodMode);
		VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(vehicle, !bVehicleGodMode);

		lastCar = vehicle;
	}
}

void features::bulletProofTyres(Vehicle veh)
{
	if (bVehicleBulletProoftyres)
	{
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, !bVehicleBulletProoftyres);
		VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(veh, !bVehicleBulletProoftyres);
	}
}

void features::setCarInvisible()
{
	static Vehicle veh;
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
	{
		if (bVehicleInvisible)
		{
			veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			ENTITY::SET_ENTITY_VISIBLE(veh, !bVehicleInvisible, 0);
			NETWORK::_NETWORK_SET_ENTITY_VISIBLE_TO_NETWORK(veh, !bVehicleInvisible);
		}
	}
	else
	{
		//e = PLAYER::GET_PLAYERS_LAST_VEHICLE();
		ENTITY::SET_ENTITY_VISIBLE(veh, true, 0);
		NETWORK::_NETWORK_SET_ENTITY_VISIBLE_TO_NETWORK(veh, true);
	}
}

void features::DriveOnWater(Vehicle veh) {

	if (bDriveOnWater)
	{
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);
		DWORD model = ENTITY::GET_ENTITY_MODEL(veh);
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
		float height = 0;
		WATER::_SET_CURRENT_INTENSITY(height);
		if ((!(VEHICLE::IS_THIS_MODEL_A_PLANE(ENTITY::GET_ENTITY_MODEL(veh))) && !(VEHICLE::IS_THIS_MODEL_A_HELI(ENTITY::GET_ENTITY_MODEL(veh)))) && WATER::GET_WATER_HEIGHT_NO_WAVES(pos.x, pos.y, pos.z, &height)) {
			Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, GAMEPLAY::GET_HASH_KEY("prop_container_ld2"), 0, 0, 1);
			if (ENTITY::DOES_ENTITY_EXIST(container) && height > -50.0f) {
				Vector3 pRot = ENTITY::GET_ENTITY_ROTATION(playerPed, 0);
				if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 1)) pRot = ENTITY::GET_ENTITY_ROTATION(veh, 0);
				RequestControlOfEnt(container);
				ENTITY::SET_ENTITY_COORDS(container, pos.x, pos.y, height - 1.5f, 0, 0, 0, 1);
				ENTITY::SET_ENTITY_ROTATION(container, 0, 0, pRot.z, 0, 1);
				Vector3 containerCoords = ENTITY::GET_ENTITY_COORDS(container, 1);
				if (pos.z < containerCoords.z) {
					if (!PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0)) {
						ENTITY::SET_ENTITY_COORDS(playerPed, pos.x, pos.y, containerCoords.z + 2.0f, 0, 0, 0, 1);
					}
					else {
						RequestControlOfEnt(veh);
						Vector3 vehc = ENTITY::GET_ENTITY_COORDS(veh, 1);
						ENTITY::SET_ENTITY_COORDS(veh, vehc.x, vehc.y, containerCoords.z + 2.0f, 0, 0, 0, 1);
					}
				}
			}
			else {
				Hash model = GAMEPLAY::GET_HASH_KEY("prop_container_ld2");
				STREAMING::REQUEST_MODEL(model);
				while (!STREAMING::HAS_MODEL_LOADED(model)) script::get_current()->yield();
				container = OBJECT::CREATE_OBJECT(model, pos.x, pos.y, pos.z, 1, 1, 0);
				RequestControlOfEnt(container);
				ENTITY::FREEZE_ENTITY_POSITION(container, 1);
				ENTITY::SET_ENTITY_ALPHA(container, 0, 1);
				ENTITY::SET_ENTITY_VISIBLE(container, 0, 0);
			}
		}
		else {
			Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, GAMEPLAY::GET_HASH_KEY("prop_container_ld2"), 0, 0, 1);
			if (ENTITY::DOES_ENTITY_EXIST(container)) {
				RequestControlOfEnt(container);
				ENTITY::SET_ENTITY_COORDS(container, 0, 0, -1000.0f, 0, 0, 0, 1);
				script::get_current()->yield(10ms);
				ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&container);
				ENTITY::DELETE_ENTITY(&container);
				WATER::_RESET_CURRENT_INTENSITY();
			}
		}
	}
}

void features::randomParts(Vehicle veh)
{
	if (bFlashParts)
	{
		static bool timer_reset = true;
		static std::chrono::system_clock::time_point timer_Start;

		if (timer_reset)
		{
			timer_Start = std::chrono::system_clock::now();
			timer_reset = false;
		}

		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - timer_Start;
		double seconds_passed = elapsed_seconds.count();

		if (seconds_passed > (float)fFlashDelay / 1000.f)
		{
			for (int i = 0; i < 49; i++)
			{
				if (!g_vehicles.currVeh.mods[i].name.empty())
				{
					if (i > 15 && i < 25)
						continue;

					if (i == 48 || i == 11 || i == 12 || i == 13)
						continue;

					int maxcount = (g_vehicles.currVeh.mods[i].options - 1);
					int tmp = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-1, maxcount);
					VEHICLE::SET_VEHICLE_MOD(veh, i, tmp, g_vehicles.currVeh.other.isCustomTyre);
				}
			}
			timer_reset = true;
		}
	}
}

void features::randomLivery(Vehicle veh)
{
	if (bFlashLivery)
	{
		static bool timer_reset = true;
		static std::chrono::system_clock::time_point timer_Start;

		if (timer_reset)
		{
			timer_Start = std::chrono::system_clock::now();
			timer_reset = false;
		}

		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - timer_Start;
		double seconds_passed = elapsed_seconds.count();

		if (seconds_passed > (float)fFlashDelay / 1000.f)
		{
			int tmp = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-1, (g_vehicles.currVeh.mods[48].options - 1));
			VEHICLE::SET_VEHICLE_MOD(veh, 48, tmp, g_vehicles.currVeh.other.isCustomTyre);

			timer_reset = true;
		}
	}
}

void features::flashWheels(Vehicle veh)
{
	if (bFlashWheels)
	{
		static bool timer_reset = true;
		static std::chrono::system_clock::time_point timer_Start;

		if (timer_reset)
		{
			timer_Start = std::chrono::system_clock::now();
			timer_reset = false;
		}

		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - timer_Start;
		double seconds_passed = elapsed_seconds.count();

		if (seconds_passed > (float)fFlashDelay / 1000.f)
		{
			int tmp = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 41);	
			VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, g_vehicles.currVeh.colours.pearlescent, PAINTS_WHEELS.at(tmp).mainValue);
			timer_reset = true;
		}
	}
}

void features::flashvehicle(Vehicle veh)
{
	if (bFlashVehicle)
	{
		static bool timer_reset = true;
		static std::chrono::system_clock::time_point timer_Start;

		if (timer_reset)
		{
			timer_Start = std::chrono::system_clock::now();
			timer_reset = false;
		}

		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - timer_Start;
		double seconds_passed = elapsed_seconds.count();

		if (seconds_passed > (float)fFlashDelay / 1000.f)
		{
			{
				int r = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255);
				int g = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255);
				int b = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, r, g, b);
			}

			{
				int r = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255);
				int g = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255);
				int b = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, r, g, b);
			}

			timer_reset = true;
		}

	}
}

void features::rainbowcar(Vehicle veh)
{
	if (bRainbowVehicle)
	{
		static bool timer_reset = true;
		static std::chrono::system_clock::time_point timer_Start;

		if (timer_reset)
		{
			timer_Start = std::chrono::system_clock::now();
			timer_reset = false;
		}

		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - timer_Start;
		double seconds_passed = elapsed_seconds.count();

		if (seconds_passed > (float)fSmoothDelay / 1000.f)
		{

			static int i = 0;
			static int s = 180;
			int* rgb;
			int* rgb2;
			rgb = g_gui.hsi_to_rgb(i, 1, 1);
			rgb2 = g_gui.hsi_to_rgb(s, 1, 1);

			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, rgb[0], rgb[1], rgb[2]);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, rgb2[0], rgb2[1], rgb2[2]);
			i++;
			s++;
			if (i > 360)
				i = 0;
			if (s > 360)
				s = 0;

			timer_reset = true;
		}
	}
}

void features::rainbowNeonKits(Vehicle veh)
{
	if (bRainbowNeonKits)
	{
		static bool timer_reset = true;
		static std::chrono::system_clock::time_point timer_Start;

		if (timer_reset)
		{
			timer_Start = std::chrono::system_clock::now();
			timer_reset = false;
		}

		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - timer_Start;
		double seconds_passed = elapsed_seconds.count();

		if (seconds_passed > (float)fSmoothDelay / 1000.f)
		{

			static int i = 0;

			int* rgb;

			rgb = g_gui.hsi_to_rgb(i, 1, 1);

			bool toggleAll = true;
			for (int i = 0; i < 4; i++)
			{
				if (g_vehicles.currVeh.togglemods.neonLights[i])
					toggleAll = false;
			}
			if (toggleAll)
			{
				for (int i = 0; i < 4; i++)
					VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, i, TRUE);
			}

			VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, rgb[0], rgb[1], rgb[2]);

			i++;

			if (i > 360)
				i = 0;


			timer_reset = true;
		}
	}
}

void features::FlashNeonKits(Vehicle veh)
{
	if (bFlashNeonKits)
	{
		static bool timer_reset = true;
		static std::chrono::system_clock::time_point timer_Start;

		if (timer_reset)
		{
			timer_Start = std::chrono::system_clock::now();
			timer_reset = false;
		}

		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - timer_Start;
		double seconds_passed = elapsed_seconds.count();

		if (seconds_passed > (float)fFlashDelay / 1000.f)
		{
			bool toggleAll = true;
			for (int i = 0; i < 4; i++)
			{
				if (g_vehicles.currVeh.togglemods.neonLights[i])
					toggleAll = false;
			}
			if (toggleAll)
			{
				for (int i = 0; i < 4; i++)
					VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, i, TRUE);
			}

			int r = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255);
			int g = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255);
			int b = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255);
			VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, r, g, b);

			timer_reset = true;
		}
	}
}

void features::rainbowTyresmoke(Vehicle veh)
{
	if (bRainbowTyresmoke)
	{
		static bool timer_reset = true;
		static std::chrono::system_clock::time_point timer_Start;

		if (timer_reset)
		{
			timer_Start = std::chrono::system_clock::now();
			timer_reset = false;
		}

		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - timer_Start;
		double seconds_passed = elapsed_seconds.count();

		if (seconds_passed > (float)fSmoothDelay / 1000.f)
		{
			static int i = 0;

			int* rgb;

			rgb = g_gui.hsi_to_rgb(i, 1, 1);

			VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, TRUE);
			VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, rgb[0], rgb[1], rgb[2]);

			i++;
			if (i > 360)
				i = 0;


			timer_reset = true;
		}
	}
}

void features::flashTyresmoke(Vehicle veh)
{
	if (bFlashTyresmoke)
	{
		static bool timer_reset = true;
		static std::chrono::system_clock::time_point timer_Start;

		if (timer_reset)
		{
			timer_Start = std::chrono::system_clock::now();
			timer_reset = false;
		}

		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - timer_Start;
		double seconds_passed = elapsed_seconds.count();

		if (seconds_passed > (float)fFlashDelay / 1000.f)
		{
			VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, TRUE);

			int r = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255);
			int g = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255);
			int b = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255);
			VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, r, g, b);

			timer_reset = true;
		}
	}
}

void features::flashHeadlights(Vehicle veh)
{
	if (bFlashHeadlights)
	{
		static bool timer_reset = true;
		static std::chrono::system_clock::time_point timer_Start;

		if (timer_reset)
		{
			timer_Start = std::chrono::system_clock::now();
			timer_reset = false;
		}

		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - timer_Start;
		double seconds_passed = elapsed_seconds.count();

		if (seconds_passed > (float)fFlashDelay / 1000.f)
		{
			VEHICLE::TOGGLE_VEHICLE_MOD(veh, 22, TRUE);

			static int lastColor;
			int tries = 0;
			int newColor = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-1, 12);
			while (newColor == lastColor && tries < 2)
			{
				newColor = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-1, 12);
				tries++;
			}

			VEHICLE::_SET_VEHICLE_HEADLIGHTS_COLOUR(veh, newColor);
			lastColor = newColor;

			timer_reset = true;
		}
	}
}

void features::engineAlwayson(Vehicle veh)
{
	if (bEngineAlwaysOn)
	{
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, TRUE, TRUE, FALSE);
		VEHICLE::SET_VEHICLE_LIGHTS(veh, 0);
		VEHICLE::_SET_VEHICLE_LIGHTS_MODE(veh, 2);
	}
}

void features::repairCar(bool loop)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
	{
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);

		RequestControlOfEnt(vehicle);
		if (loop ? (ENTITY::GET_ENTITY_SPEED(vehicle) < 30): 1)
		{
			VEHICLE::SET_VEHICLE_FIXED(vehicle);
			if (VEHICLE::_IS_VEHICLE_DAMAGED(vehicle))
			{
				for (int i = 0; i < 10; i++)
				{
					VEHICLE::SET_VEHICLE_TYRE_FIXED(vehicle, i);
				}
			}
		}
	}
}

void features::autoRepair()
{
	if (bAutoRepairCar)
	{
		static bool timer_reset = true;
		static std::chrono::system_clock::time_point timer_Start;

		if (timer_reset)
		{
			timer_Start = std::chrono::system_clock::now();
			timer_reset = false;
		}

		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - timer_Start;
		double seconds_passed = elapsed_seconds.count();

		if (seconds_passed > 0.5f)
		{
			repairCar(true);
			timer_reset = true;
		}
	}
}



void features::stick_to_ground(Vehicle veh)
{
	if (bSticktoground)
	{
		if (ENTITY::IS_ENTITY_IN_AIR(veh))
		{
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		}
	}
}

void features::instantbreak()
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
	{
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		RequestControlOfEnt(vehicle);
		VEHICLE::SET_VEHICLE_FORWARD_SPEED(vehicle, 0);
	}
}

void features::flipup()
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
	{
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(vehicle);
	}
}

void features::policemode()
{
	if (bPolicemode)
	{
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Vehicle* vehs = new Vehicle[ArrSize];
		vehs[0] = ElementAmount;
		int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

		for (int i = 0; i < VehFound; i++)
		{
			int OffsetID = i * 2 + 2;
			if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
			{
				RequestControlOfEnt(vehs[OffsetID]);
				Ped ped = VEHICLE::GET_PED_IN_VEHICLE_SEAT(vehs[OffsetID], -1);
				//if (ENTITY::GET_ENTITY_SPEED(vehs[OffsetID]) > 5)
				AI::TASK_VEHICLE_TEMP_ACTION(ped, vehs[OffsetID], 26, 500); //26 // 10
			//else
			//	AI::TASK_VEHICLE_TEMP_ACTION(ped, vehs[OffsetID], 8, 500); //26 // 10
			}
		}
		delete vehs;
	}
}

void features::groupup(Vehicle veh)
{
	if (bGroupUp)
	{
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Vehicle* vehs = new Vehicle[ArrSize];
		vehs[0] = ElementAmount;
		int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

		for (int i = 0; i < VehFound; i++)
		{
			int OffsetID = i * 2 + 2;
			if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
			{
				RequestControlOfEnt(vehs[OffsetID]);
				Ped ped = VEHICLE::GET_PED_IN_VEHICLE_SEAT(vehs[OffsetID], -1);
				//	AI::CLEAR_PED_TASKS_IMMEDIATELY(ped);
				AI::TASK_VEHICLE_ESCORT(ped, vehs[OffsetID], veh, -1, ENTITY::GET_ENTITY_SPEED(veh), 786603, 15, -1, 10); //262144
			}
		}
		delete vehs;
	}
}

Vehicle features::spawnVehicle(rage::joaat_t hash)
{
	Hash model = hash;

	if (STREAMING::IS_MODEL_VALID(model))
	{
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) script::get_current()->yield();
		Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
		float forward = 5.f;
		float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
		float xVector = forward * sin(degToRad(heading)) * -1.f;
		float yVector = forward * cos(degToRad(heading));

		if (features::bSpawnInVehicle)
			if (VEHICLE::IS_THIS_MODEL_A_HELI(model) || VEHICLE::IS_THIS_MODEL_A_PLANE(model))
				ourCoords.z += 50.f;

		if (bSpawnDeleteOld || bSpawnClearArea)
		{
			if (localData.IsInVehicle)
			{
				AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
				RequestControlOfEnt(localData.vehicle);
				ENTITY::SET_ENTITY_COORDS(localData.vehicle, 6400.f, 6400.f, 0.f, false, false, false, false);
			}
		}
	
		if (bSpawnClearArea)
		{
			GAMEPLAY::CLEAR_AREA_OF_VEHICLES(ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z, 10, false, false, false, false, false);
			GAMEPLAY::CLEAR_AREA_OF_OBJECTS(ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z, 10, 0);
		}

		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z, heading, true, true);

		if (*g_pointers->m_is_session_started)
		{
			DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
		}

		RequestControlOfEnt(veh);

		if (features::bSpawnWithEngineOn)
			VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);

		if (features::bSpawnInVehicle)
		{
			if (VEHICLE::IS_THIS_MODEL_A_HELI(model) || VEHICLE::IS_THIS_MODEL_A_PLANE(model))
				VEHICLE::SET_HELI_BLADES_FULL_SPEED(veh);

			if (VEHICLE::IS_THIS_MODEL_A_PLANE(model))
			{
				VEHICLE::_SET_VEHICLE_JET_ENGINE_ON(veh, true);
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 40);
			}
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		}
		else
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);

		if (features::bSpawnWithMaxUpgrades)
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			for (int i = 0; i < 49; i++)
			{
				if (i > 16 && i < 23)
					continue;

				VEHICLE::SET_VEHICLE_MOD(veh, i, VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) - 1, false);
			}
		}

		if (features::bSpawnWithCarGodMode)
		{
			ENTITY::SET_ENTITY_INVINCIBLE(veh, true);
			ENTITY::SET_ENTITY_PROOFS(veh, true, true, true, true, true, true, true, true);
			VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_DAMAGE(veh, true);
			VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(veh, true);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(veh, false);
			VEHICLE::SET_VEHICLE_CAN_BREAK(veh, false);
			VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE(veh, false);
			VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(veh, false);
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, false);
			VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(veh, false);
		}

		if (features::bSpawnCleanVehicle)
			VEHICLE::SET_VEHICLE_DIRT_LEVEL(veh, 0.f);

		if (features::bSpawnWithEffect)
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			script::get_current()->yield(100ms);
			GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", veh, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, false, false, false);
		}

	
		script::get_current()->yield(50ms);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);

		return veh;
	}
	return NULL;
}

void features::att_ped_to_veh(Hash model, Vehicle vehicle, const Vector3& offset, const Vector3& rotation, bool invis, bool piggyback)
{
	if (ENTITY::DOES_ENTITY_EXIST(vehicle))
	{
		STREAMING::REQUEST_MODEL(model);
		int i = 0;
		while (!STREAMING::HAS_MODEL_LOADED(model))
		{
			if (i == 1000)
			{
				printf("Failed to load model hash 0x%X\n", model);
				break;
			}
			script::get_current()->yield(25ms);
			i += 25;
		}
		

		if (invis && ENTITY::IS_ENTITY_VISIBLE(vehicle))
		{	
			ENTITY::SET_ENTITY_VISIBLE(vehicle, false, false);
			NETWORK::_NETWORK_SET_ENTITY_VISIBLE_TO_NETWORK(vehicle, false);
		}

		Ped ped = PED::CREATE_PED(4, model, 0.0f, 0.0f, 0.0f, ENTITY::GET_ENTITY_HEADING(vehicle), 1, 1);
		NETWORK::PED_TO_NET(ped);
		ENTITY::SET_ENTITY_LOD_DIST(ped, 696969);
		ENTITY::ATTACH_ENTITY_TO_ENTITY(ped, vehicle, -1, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 180.0f, 0, 0, 0, 0, 2, 1);
		ENTITY::DETACH_ENTITY(ped, 1, 1);
		ENTITY::ATTACH_ENTITY_TO_ENTITY(ped, vehicle, -1, offset.x, offset.y, offset.z, rotation.x, rotation.y, rotation.z, 0, 0, 0, 0, 2, 1);
		PED::SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(ped, 1);
		if (piggyback)
		{
			ENTITY::ATTACH_ENTITY_TO_ENTITY(ped, vehicle, -1, 0.0f, -0.3f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 2, 1);
			STREAMING::REQUEST_ANIM_DICT("mini@prostitutes@sexnorm_veh");
			script::get_current()->yield(50ms);
			AI::TASK_PLAY_ANIM(ped, "mini@prostitutes@sexnorm_veh", "bj_loop_male", 8.f, 0.f, -1, 9, 0, 0, 0, 0);
		}
		else
			AI::TASK_STAND_STILL(ped, -1);
		ENTITY::SET_ENTITY_INVINCIBLE(ped, TRUE);
		ENTITY::SET_PED_AS_NO_LONGER_NEEDED(&ped);
	}
}

void features::att_obj_to_veh(Hash model, Vehicle vehicle, float X, float Y, float Z, float Pitch, float Roll, float Yaw, bool invis, int boneIndex, bool dynamic, bool collisionEnabled, bool destroyVar)
{
	if (ENTITY::DOES_ENTITY_EXIST(vehicle))
	{
		STREAMING::REQUEST_MODEL(model);
		int i = 0;
		while (!STREAMING::HAS_MODEL_LOADED(model))
		{
			if (i == 1000)
			{
				printf("Failed to load model hash 0x%X\n", model);
				break;
			}
			script::get_current()->yield(25ms);
			i += 25;
		}

		Vehicle object = OBJECT::CREATE_OBJECT(model, 0.0f, 0.0f, 0.0f, 1, 1, dynamic);
		ENTITY::SET_ENTITY_LOD_DIST(object, 1000000);

		if (invis)
		{
			if (VEHICLE::IS_THIS_MODEL_A_BIKE(model) || VEHICLE::IS_THIS_MODEL_A_BICYCLE(model))
			{
				ENTITY::SET_ENTITY_ALPHA(vehicle, 0, 0);
			}
			else if (ENTITY::IS_ENTITY_VISIBLE(vehicle))
			{
				ENTITY::SET_ENTITY_VISIBLE(vehicle, false, false);
				NETWORK::_NETWORK_SET_ENTITY_VISIBLE_TO_NETWORK(vehicle, false);
			}
		}

		ENTITY::ATTACH_ENTITY_TO_ENTITY(object, vehicle, -1, X, Y, Z, Pitch, Roll, Yaw, 0, 0, 0, 0, 2, 1);
		ENTITY::SET_ENTITY_LIGHTS(object, 0);
		if (collisionEnabled)  ENTITY::SET_ENTITY_COLLISION(object, collisionEnabled, TRUE);
		if (destroyVar) ENTITY::SET_OBJECT_AS_NO_LONGER_NEEDED(&object);
	}

}

void features::att_veh_to_veh(Hash model, Vehicle vehicle, int primColour, int secColour, float X, float Y, float Z, float Pitch, float Roll, float Yaw, bool invis, int boneIndex, bool collisionEnabled)
{
	if (ENTITY::DOES_ENTITY_EXIST(vehicle))
	{
		STREAMING::REQUEST_MODEL(model);
		int i = 0;
		while (!STREAMING::HAS_MODEL_LOADED(model))
		{
			if (i == 1000)
			{
				printf("Failed to load model hash 0x%X\n", model);
				break;
			}
			script::get_current()->yield(25ms);
			i += 25;
		}

		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, 0.0f, 0.0f, 0.0f, 0.0f, 1, 1);
		ENTITY::SET_ENTITY_LOD_DIST(veh, 1000000);

		
		if (invis)
		{
			if (VEHICLE::IS_THIS_MODEL_A_BIKE(model) || VEHICLE::IS_THIS_MODEL_A_BICYCLE(model))
			{
				ENTITY::SET_ENTITY_ALPHA(vehicle, 0, 0);
			}
			else if (ENTITY::IS_ENTITY_VISIBLE(vehicle))
			{
				ENTITY::SET_ENTITY_VISIBLE(vehicle, false, false);
				NETWORK::_NETWORK_SET_ENTITY_VISIBLE_TO_NETWORK(vehicle, false);

				/*GTAped sped;
				for (int i = -1; i <= ((int)(VEHICLE::GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(veh)) - 2); i++)
				{
					if (VEHICLE::IS_VEHICLE_SEAT_FREE(veh, i)) continue;
					sped.Handle() = VEHICLE::GET_PED_IN_VEHICLE_SEAT(veh, i);
					sped.RequestControl();
					sped.SetVisible(true);
				}*/
			}
		}

		ENTITY::ATTACH_ENTITY_TO_ENTITY(veh, vehicle, -1, X, Y, Z, Pitch, Roll, Yaw, 0, 0, 0, 0, 2, 1);
		ENTITY::SET_ENTITY_LIGHTS(veh, 0);
		VEHICLE::SET_VEHICLE_COLOURS(veh, primColour, secColour);
		if (collisionEnabled)  ENTITY::SET_ENTITY_COLLISION(veh, collisionEnabled, TRUE);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}

}

void features::teleport_to_coords(Entity e, Vector3 coords)
{
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, coords.z, 0, 0, 1);
	script::get_current()->yield();
}

Vector3 features::get_blip_marker()
{
	static Vector3 zero;
	Vector3 coords;

	bool blipFound = false;
	// search for marker blip
	int blipIterator = UI::_GET_BLIP_INFO_ID_ITERATOR();
	for (Blip i = UI::GET_FIRST_BLIP_INFO_ID(blipIterator); UI::DOES_BLIP_EXIST(i) != 0; i = UI::GET_NEXT_BLIP_INFO_ID(blipIterator))
	{
		if (UI::GET_BLIP_INFO_ID_TYPE(i) == 4)
		{
			coords = UI::GET_BLIP_INFO_ID_COORD(i);
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

Vector3 features::get_blip_objective2()
{
	static Vector3 zero;
	Vector3 coords;

	bool blipFound = false;
	int blipIterator = UI::_GET_BLIP_INFO_ID_ITERATOR();
	for (Blip i = UI::GET_FIRST_BLIP_INFO_ID(blipIterator); UI::DOES_BLIP_EXIST(i) != 0; i = UI::GET_NEXT_BLIP_INFO_ID(blipIterator))
	{
		int type = UI::GET_BLIP_INFO_ID_TYPE(i);
		int colour = UI::GET_BLIP_COLOUR(i);
		int sprite = UI::GET_BLIP_SPRITE(i);
		
		if ((colour != ColorYellowMission || sprite != SpriteStandard) && (colour != ColorYellow || sprite != SpriteStandard) && (colour != ColorWhite || sprite != SpriteRaceFinish) && (colour != ColorGreen || sprite != SpriteStandard) && (sprite != SpriteCrateDrop))
			continue;
			
		coords = UI::GET_BLIP_INFO_ID_COORD(i);
		blipFound = true;
	}
	if (blipFound)
	{
		return coords;
	}

	return zero;
}

Vector3 features::get_blip_vehicle2()
{
	static Vector3 zero;
	Vector3 coords;

	bool blipFound = false;
	int blipIterator = UI::_GET_BLIP_INFO_ID_ITERATOR();
	for (Blip i = UI::GET_FIRST_BLIP_INFO_ID(blipIterator); UI::DOES_BLIP_EXIST(i) != 0; i = UI::GET_NEXT_BLIP_INFO_ID(blipIterator))
	{
		int type = UI::GET_BLIP_INFO_ID_TYPE(i);
		int colour = UI::GET_BLIP_COLOUR(i);
		int sprite = UI::GET_BLIP_SPRITE(i);
		coords = UI::GET_BLIP_INFO_ID_COORD(i);

		//if (VEHICLE::IS_ANY_VEHICLE_NEAR_POINT(coords.x, coords.y, coords.z, 20000))
		{
			printf("type %d colour %d sprite %d\n", type, colour, sprite);
		}


		/*if (colour != ColorVehicle && sprite != SpritePersonalVehicleCar && sprite != SpritePersonalVehicleBike)
			continue;	*/

	}
	if (blipFound)
	{
		return coords;
	}

	return zero;
}

CBlip* features::get_blip_objective()
{
	CBlip* r = nullptr;
	for (int i = 0; i < 0x400; i++)
	{
		if (CBlipList* blipList = g_pointers->m_blitList)
		{
			if (CBlip* blip = blipList->m_Blips[i])
			{
				auto colour = blip->dwColor;
				auto icon = blip->iIcon;

				if ((colour == ColorYellowMission && icon == SpriteStandard) ||
					(colour == ColorYellowMission2 && icon == SpriteStandard) ||
					(colour == ColorYellow && icon == SpriteStandard) ||
					(colour == ColorWhite && icon == SpriteRaceFinish) ||
					(colour == ColorGreen && icon == SpriteStandard) ||
					(colour == ColorBlue && icon == SpriteStandard) ||
					(icon == SpriteCrateDrop))

				{				
					r = blip;
					break;
				}
			}		
		}
		
	}
	return r;
}

void features::teleport_to_objective()
{
	CBlip* blip = get_blip_objective();
	//Vector3 coords = get_blip_objective2();
	if (blip == nullptr)
		notifyAboveMap("Objective not found.", 0);
	else
	{
		Vector3 coords{ blip->x ,blip->y, blip->z };
		Entity e = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
		if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
			e = PED::GET_VEHICLE_PED_IS_USING(e);
				
		bool groundFound = false;
		static float groundCheckHeight[] =
		{ 100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
		for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
		{
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, groundCheckHeight[i], 0, 0, 1);
			script::get_current()->yield(100ms);
			if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0))
			{
				groundFound = true;
				coords.z += 3.0;
				break;
			}
		}
		if (!groundFound)
		{
			coords.z = 1000.0;
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xFBAB5776, 1, 0);
		}

		features::teleport_to_coords(e, coords);
	}
}

CBlip* features::get_blip_vehicle()
{
	CBlip* r = nullptr;
	for (int i = 0; i < 0x400; i++)
	{
		if (CBlipList* blipList = g_pointers->m_blitList)
		{
			CBlip* blip = blipList->m_Blips[i];

			if (!blip)
				continue;

			if (blip->dwColor != ColorVehicle && blip->iIcon != SpritePersonalVehicleCar && blip->iIcon != SpritePersonalVehicleBike)
				continue;

			r = blip;
			break;

		}
	}
	return r;
}

void features::teleport_to_personal_vehicle()
{
	CBlip* blip = get_blip_vehicle();
	if (blip == nullptr)
		notifyAboveMap("Personal vehicle not found.", 0);
	else
	{
		Vector3 coords{ blip->x ,blip->y, blip->z };
		Entity e = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
		if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
			e = PED::GET_VEHICLE_PED_IS_USING(e);

		bool groundFound = false;
		static float groundCheckHeight[] =
		{ 100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
		for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
		{
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, groundCheckHeight[i], 0, 0, 1);
			script::get_current()->yield(100ms);
			if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0))
			{
				groundFound = true;
				coords.z += 3.0;
				break;
			}
		}
		if (!groundFound)
		{
			coords.z = 1000.0;
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xFBAB5776, 1, 0);
		}
		features::teleport_to_coords(e, coords);
	}		
}

void features::autoTpWaypoint()
{
	if (bAutoTeleport)
	{
		Vector3 coords = get_blip_marker();

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
			if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0))
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
		features::teleport_to_coords(e, coords);
		UI::SET_WAYPOINT_OFF();
	}
}

void features::SelfGodMode()
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	ENTITY::SET_ENTITY_INVINCIBLE(playerPed, bSelfgodMode);
	ENTITY::SET_ENTITY_PROOFS(playerPed, bSelfgodMode, (bSelfgodMode || bSelfFireBreath), bSelfgodMode, (bSelfNoRagdoll || bSelfNoClip), bSelfgodMode, bSelfgodMode, bSelfgodMode, bSelfgodMode);
}

void features::SelfNoRagdoll()
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	PED::SET_PED_CAN_RAGDOLL(playerPed, !bSelfNoRagdoll);
	PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(playerPed, !bSelfNoRagdoll);
	//PED::SET_PED_RAGDOLL_ON_COLLISION(PLAYER::PLAYER_PED_ID(), !bNoRagdoll);
	//PED::SET_PED_TO_RAGDOLL_WITH_FALL()
}

void features::SelfInivisible()
{
	ENTITY::SET_ENTITY_VISIBLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), !bSelfInvisible, 0);
	NETWORK::_NETWORK_SET_ENTITY_VISIBLE_TO_NETWORK(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), !bSelfInvisible);
}

void features::SelfSeatbelt()
{
	localData.factory->m_local_ped->btSeatBelt = bSelfSeatbelt ? 0xC9 : 0xC8;
}

void features::SelfStamina()
{
	if (bSelfStamina)
		localData.factory->m_local_ped->pCPlayerInfo->fStamina = localData.factory->m_local_ped->pCPlayerInfo->fMaxStamina;
}

void features::SelfFastRun()
{
	static float oVal = NULL;
	if (!oVal)
		oVal = localData.factory->m_local_ped->pCPlayerInfo->fRunSpeed;
	localData.factory->m_local_ped->pCPlayerInfo->fRunSpeed = bSelfRunMultiplier ? fSelfRunMultiplier : oVal;
}

void features::SelfFastSwim()
{
	static float oVal = NULL;
	if (!oVal)
		oVal = localData.factory->m_local_ped->pCPlayerInfo->fSwimSpeed;
	localData.factory->m_local_ped->pCPlayerInfo->fSwimSpeed = bSelfSwimMultiplier ? fSelfSwimMultiplier : oVal;
}

void features::SelfNeverWanted()
{
	if (bSelfNeverWanted)
		localData.factory->m_local_ped->pCPlayerInfo->m_wanted_level = 0;
}

void features::SelfAlwaysWanted()
{
	if (bSelfAlwaysWanted)
		localData.factory->m_local_ped->pCPlayerInfo->m_wanted_level = 5;
}

void features::SelfFakeWantedLevel()
{
	GAMEPLAY::SET_FAKE_WANTED_LEVEL(iSelfFakeWantedLevel);
}

void features::SelfHealthRechargeMultiplier()
{
	PLAYER::SET_PLAYER_HEALTH_RECHARGE_MULTIPLIER(PLAYER::PLAYER_ID(), fSelfHealthRechargeMultiplier);
}


void features::MiscSetAllPedsFlee()
{
	if (bMiscsSetAllRandomPedsFlee)
		PLAYER::SET_ALL_RANDOM_PEDS_FLEE_THIS_FRAME(PLAYER::PLAYER_ID());
}

static std::vector<DWORD64> nameAddresses;
std::vector<DWORD64> getNameAddresses()
{
	return nameAddresses;
}

void allocateNameAddresses() {

	if (nameAddresses.empty())
	{
		std::string currentMask;
		const char* playerName = g_pointers->m_getPlayerName(PLAYER::PLAYER_ID());
		for (uint8_t i = 0; i < strlen(playerName); i++) currentMask += "x";
		const char* mask = currentMask.c_str();

		for (DWORD64 address : Memory::get_string_addresses(playerName)) {
			nameAddresses.push_back((address));
		}
	}
}

void features::setSpoofName(const std::string& name)
{
	allocateNameAddresses();
	size_t newLen = name.size() + 1;
	if (newLen <= 1 || newLen > 20)
		return;

	char buffer[0x20] = {};
	char* playerName = (char*)g_pointers->m_getPlayerName(PLAYER::PLAYER_ID()) + 0x5C;
	size_t curLen = strlen(playerName) + 1;

	strncpy_s(buffer, playerName, curLen);

	for (uint32_t i = 0, found = 0, match = 0; found < 4; ++playerName)
	{
		if (*playerName != buffer[i])
			goto LABEL_RESET;

		if (++match < curLen)
		{
			++i;
			continue;
		}

		strncpy_s(playerName - i, newLen, &name[0], newLen);
		++found;

	LABEL_RESET:
		i = match = 0;
	}

	CPedFactory* factory = *g_pointers->m_ped_factory;
	strncpy(factory->m_local_ped->pCPlayerInfo->m_name, name.c_str(), newLen);

	for (DWORD64 Address : getNameAddresses()) {
		strncpy((char*)Address, &name[0], newLen);
	}
}

void features::nearbyVehicleOptions()
{
	if (bMiscUpgradeNearbyVehicles || bMiscExplodeNearbyVehicles || bMiscDeleteNearbyVehicles)
	{
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Vehicle* vehs = new Vehicle[ArrSize];
		vehs[0] = ElementAmount;
		int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

		for (int i = 0; i < VehFound; i++)
		{
			int OffsetID = i * 2 + 2;
			if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
			{
				RequestControlOfEnt(vehs[OffsetID]);

				if (bMiscUpgradeNearbyVehicles)
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(vehs[OffsetID], 0);
					for (int i = 0; i < 50; i++)
					{
						VEHICLE::SET_VEHICLE_MOD(vehs[OffsetID], i, VEHICLE::GET_NUM_VEHICLE_MODS(vehs[OffsetID], i) - 1, false);
					}
				}

				if (bMiscExplodeNearbyVehicles)
				{
					Vector3 coords = ENTITY::GET_ENTITY_COORDS(vehs[OffsetID], false);
					FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0, 1000.f, true, false, 0.f, false);
				}

				if (bMiscDeleteNearbyVehicles)
					ENTITY::SET_ENTITY_COORDS(vehs[OffsetID], 6400.f, 6400.f, 0.f, false, false, false, false);
			
			}
		}
		delete vehs;
	}
}

void features::MiscDisablePhone()
{
	MOBILE::_DISABLE_PHONE_THIS_FRAME(bMiscDestroyPhone);
}

void features::MiscSpawnBodyGuard()
{
	Entity Myped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(Myped, 1);
	coords.z += 1.5;

	int spawn = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(1, 8);
	switch (spawn)
	{
	case 1:
		coords.x += 2;
		break;
	case 2:
		coords.x += 2;
		coords.y += 2;
		break;
	case 3:
		coords.y += 2;
		break;
	case 4:
		coords.y += 2;
		coords.x -= 2;
		break;
	case 5:
		coords.x -= 2;
		break;
	case 6:
		coords.x -= 2;
		coords.y -= 2;
		break;
	case 7:
		coords.y -= 2;
		break;
	case 8:
		coords.x += 2;
		coords.y -= 2;
		break;
	}

	int group = PED::GET_PED_GROUP_INDEX(Myped);
	Ped ped = PED::CREATE_RANDOM_PED(coords.x, coords.y, coords.z);

	if (bSpawnWithEffect)
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", ped, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
	}

	PED::SET_PED_AS_GROUP_MEMBER(ped, group);
	PED::SET_PED_CAN_SWITCH_WEAPON(ped, false);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(ped, 0x22d8fe39, 9999, 1);
	PED::SET_PED_COMBAT_ABILITY(ped, 2); //0 poor, 1 average, 2 prof*/
	AI::TASK_FOLLOW_TO_OFFSET_OF_ENTITY(ped, Myped, 0, 0, 0, 1, 0, 3.5f, 1);
}

void features::frameFlags()
{
	int64_t flags = 0 << 11;
	flags |= 0 << 12;
	flags |= 0 << 13;
	flags |= 0 << 14;

	bWeaponExplosiveAmmo ? (flags |= 1 << 11) : NULL;
	bWeaponFireAmmo ? (flags |= 1 << 12) : NULL;
	bWeaponExplosiveMelee ? (flags |= 1 << 13) : NULL;
	bSelfSuperJump ? (flags |= 1 << 14) : NULL;
	
	if (bWeaponExplosiveAmmo || bWeaponFireAmmo || bWeaponExplosiveMelee || bSelfSuperJump)
		localData.factory->m_local_ped->pCPlayerInfo->m_frameflags |= flags;
}

void features::WeaponImpacts()
{
	Vector3 coords;
	if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(localData.localPed, &coords) && WEAPON::IS_PED_ARMED(PLAYER::PLAYER_PED_ID(), 7) && WEAPON::IS_PED_ARMED(PLAYER::PLAYER_PED_ID(), 6))
	{
		if (bWeaponFireWorkImpact)
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET("proj_xmas_firework");
			GRAPHICS::USE_PARTICLE_FX_ASSET("proj_xmas_firework");
			static bool firework = false;
			if (!firework)
			{
				GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_AT_COORD("scr_firework_xmas_spiral_burst_rgw", coords.x, coords.y, coords.z, 0.0, 0.0, 0.0, 1.0, false, false, false);
				firework = true;
			}
			else
			{
				GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_AT_COORD("scr_firework_xmas_burst_rgw", coords.x, coords.y, coords.z, 0.0, 0.0, 0.0, 1.0, false, false, false);
				firework = false;
			}

		}

		if (bWeaponTeleportGun)
		{
			Entity Myped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
			if (PED::IS_PED_IN_ANY_VEHICLE(Myped, 0))
			{
				Myped = PED::GET_VEHICLE_PED_IS_USING(Myped);
			}
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Myped, coords.x, coords.y, coords.z + 1.0f, 0, 0, 1);
		}

		if (bWeaponMoneyGun)
		{
			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("prop_money_bag_01"));
			while (!STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("prop_money_bag_01")))	script::get_current()->yield();
			{
				OBJECT::CREATE_AMBIENT_PICKUP(GAMEPLAY::GET_HASH_KEY("pickup_money_case"), coords.x, coords.y, coords.z + 0.2f, 0.0, 2000, GAMEPLAY::GET_HASH_KEY("prop_money_bag_01"), false, true);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("prop_money_bag_01"));
			}
		}

		if (bWeaponBlockGun)
		{
			// hei_prop_heist_wooden_box
			Hash model = rage::joaat("prop_box_wood07a");
			if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_VALID(model))
			{
				STREAMING::REQUEST_MODEL(model);
				while (!STREAMING::HAS_MODEL_LOADED(model)) script::get_current()->yield();
				Object obj = OBJECT::CREATE_OBJECT(model, coords.x, coords.y, coords.z, true, false, true);
				features::RequestControlOfEnt(obj);
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(obj, true, true);
				ENTITY::SET_ENTITY_LOD_DIST(obj, 500);
				OBJECT::PLACE_OBJECT_ON_GROUND_PROPERLY(obj);			

				//ENTITY::SET_ENTITY_QUATERNION(obj, rotX, rotY, rotZ, rotW);						
				//::SET_ENTITY_DYNAMIC(obj, true);
				//ENTITY::SET_ENTITY_PROOFS(obj, true, true, true, true, true, true, true, true);
				//ENTITY::SET_ENTITY_INVINCIBLE(obj, true);

				script::get_current()->yield(50ms);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
			}		
		}

		if (bWeaponFlameImpact)
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, ExplosionTypeFlame, 5.f, true, false, 0.f, bWeaponDeadlyExplosions ? false : true);
		
		if (bWeaponSmokeImpact)
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, ExplosionTypeSmokeGL, 5.f, true, false, 0.f, bWeaponDeadlyExplosions ? false : true);

		if (bWeaponFlareImpact)
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, ExplosionTypeFlare, 5.f, true, false, 0.f, bWeaponDeadlyExplosions ? false : true);

		if (bWeaponMolotovImpact)
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, ExplosionTypeMolotov, 5.f, true, false, 0.f, bWeaponDeadlyExplosions ? false : true);

		if (bWeaponGrenadeImpact)
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, ExplosionTypeGrenade, 5.f, true, false, -1.f, bWeaponDeadlyExplosions ? false : true);

		if (bWeaponRocketImpact)
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, ExplosionTypeRocket, 5.f, true, false, -1.f, bWeaponDeadlyExplosions ? false : true);

		if (bWeaponTankShellImpact)
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, ExplosionTypeTankShell, 5.f, true, false, -1.f, bWeaponDeadlyExplosions ? false : true);
	}
}

void features::WeaponRapidFire()
{
	if (bWeaponRapidFire)
	{
		Player playerPed = PLAYER::PLAYER_PED_ID();
		if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1)) {
			PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
			Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
			Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
			Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 1.0f)));
			Vector3 endCoords = addVector(startCoords, multiplyVector(gameplayCamDirection, 500.0f));
			Hash weaponhash;
			WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &weaponhash, 1);
			if (CONTROLS::IS_CONTROL_PRESSED(2, 208) || (GetKeyState(VK_LBUTTON) & 0x8000)) {
				if (!g_gui.m_opened)
					GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 50, 1, weaponhash, playerPed, 1, 1, 0xbf800000);
			}
		}
	}
}

void features::WeaponInfinityAmmo()
{
	if (bWeaponInfinityAmmo)
	{
		Ped PLayPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
		Hash cur;
		if (WEAPON::GET_CURRENT_PED_WEAPON(PLayPed, &cur, 1))
		{
			if (WEAPON::IS_WEAPON_VALID(cur))
			{
				int maxAmmo;
				if (WEAPON::GET_MAX_AMMO(PLayPed, cur, &maxAmmo))
				{
					WEAPON::SET_PED_AMMO(PLayPed, cur, maxAmmo);

					maxAmmo = WEAPON::GET_MAX_AMMO_IN_CLIP(PLayPed, cur, 1);
					if (maxAmmo > 0)
						WEAPON::SET_AMMO_IN_CLIP(PLayPed, cur, maxAmmo);
				}
			}
		}
	}
}


float GravityGunGoto(float aimX, float entityX)
{
	static float GravityGunVeloPos;
	if (aimX > 0 && entityX > 0)
	{
		GravityGunVeloPos = aimX - (entityX);
	}

	if (aimX < 0 && entityX < 0)
	{
		GravityGunVeloPos = aimX - (entityX);
	}

	if (aimX > 0 && entityX < 0)
	{
		GravityGunVeloPos = aimX + (entityX);
	}

	if (aimX < 0 && entityX > 0)
	{
		GravityGunVeloPos = aimX + (entityX);
	}

	return GravityGunVeloPos;
}

void features::WeaponGravityGun()
{
	if (bWeaponGravityGun)
	{
		static Entity currEnt{NULL};
		static Entity lastEnt{NULL};
		static int zoom = 10;

		if (GetAsyncKeyState(VK_RBUTTON) || CONTROLS::IS_CONTROL_PRESSED(2, ControlAim))
		{
			if ((currEnt == NULL) || (lastEnt == currEnt))
				PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &currEnt);
			else
			{
				Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
				Vector3 dir = rot_to_direction(&rot);
				Vector3 spawnPosition = addVector(CAM::GET_GAMEPLAY_CAM_COORD(), multiplyVector(dir, zoom));
				RequestControlOfEnt(currEnt);

				Vector3 getcoors = ENTITY::GET_ENTITY_COORDS(currEnt, 0);
				float getaimcoorsX = GravityGunGoto(spawnPosition.x, getcoors.x);
				float getaimcoorsY = GravityGunGoto(spawnPosition.y, getcoors.y);
				float getaimcoorsZ = GravityGunGoto(spawnPosition.z, getcoors.z);
				ENTITY::SET_ENTITY_VELOCITY(currEnt, getaimcoorsX * 2.0, getaimcoorsY * 2.0, getaimcoorsZ * 2.0);

				if (GetAsyncKeyState(VK_LBUTTON) || CONTROLS::IS_CONTROL_PRESSED(2, INPUT_ATTACK))
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(currEnt, 1, dir.x * 10000.0f, dir.y * 10000.0f, dir.z * 10000.0f, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);
					PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_ID(), false);
					lastEnt = currEnt;
				}
				if (GetAsyncKeyState(0x45) || CONTROLS::IS_CONTROL_PRESSED(2, INPUT_DUCK))
				{
					ENTITY::SET_ENTITY_HEADING(currEnt, ENTITY::GET_ENTITY_HEADING(currEnt) - 5);
				}
				if (GetAsyncKeyState(0x51) || CONTROLS::IS_CONTROL_PRESSED(2, INPUT_VEH_HORN))
				{
					ENTITY::SET_ENTITY_HEADING(currEnt, ENTITY::GET_ENTITY_HEADING(currEnt) + 5);
				}
				if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_PREV_WEAPON))
				{
					zoom += 1;
				}
				if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_NEXT_WEAPON))
				{
					zoom -= 1;
				}
			}

		}
		else
		{
			currEnt = NULL;
			lastEnt = NULL;
			zoom = 10;
		}
	}
}


void features::WeaponDeleteGun()
{
	if (bWeaponDeleteGun)
	{
		if (GetAsyncKeyState(VK_LBUTTON) || CONTROLS::IS_CONTROL_PRESSED(2, INPUT_ATTACK))
		{
			Entity ent;
			if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &ent))
			{
				if (ENTITY::DOES_ENTITY_EXIST(ent)) {

					RequestControlOfEnt(ent);

					ENTITY::SET_ENTITY_COORDS(ent, 6400.f, 6400.f, 0.f, false, false, false, false);
					//ENTITY::SET_ENTITY_VISIBLE(ent, FALSE, false);
					//NETWORK::_NETWORK_SET_ENTITY_VISIBLE_TO_NETWORK(ent, FALSE);
					ENTITY::SET_ENTITY_AS_MISSION_ENTITY(ent, 1, 1);
					ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&ent);
					ENTITY::DELETE_ENTITY(&ent);

				}
			}
		}
	}
}

void features::WeaponVehicleGun()
{
	if (bWeaponVehicleGun)
	{
		if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
		{
			Player playerPed = PLAYER::PLAYER_PED_ID();
			if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1))
			{
				PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
				Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
				Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
				Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 5.0f)));

				Hash model = lastSelectedVehicleHash;
				if (STREAMING::IS_MODEL_VALID(model))
				{
					STREAMING::REQUEST_MODEL(model);
					while (!STREAMING::HAS_MODEL_LOADED(model)) script::get_current()->yield();
					float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
					Vehicle veh = VEHICLE::CREATE_VEHICLE(model, startCoords.x, startCoords.y, startCoords.z, heading, true, true);
					RequestControlOfEnt(veh);
					VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);

					if (*g_pointers->m_is_session_started)
					{
						DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
					}

					if (bSpawnWithMaxUpgrades)
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
						for (int i = 0; i < 50; i++)
						{
							VEHICLE::SET_VEHICLE_MOD(veh, i, VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) - 1, false);
						}
					}
					VEHICLE::SET_VEHICLE_DIRT_LEVEL(veh, 0.f);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);

					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(veh) == FALSE)
					{
						RequestControlOfEnt(veh);
					}
					ENTITY::SET_ENTITY_COORDS_NO_OFFSET(veh, startCoords.x, startCoords.y, startCoords.z, TRUE, TRUE, TRUE);
					ENTITY::SET_ENTITY_ROTATION(veh, gameplayCamRot.x, gameplayCamRot.y, gameplayCamRot.z, 0, TRUE);
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 100.f);
				}
			}
		}
	}
}


void features::WeaponMods()
{
	// fists 2725352035
	static struct tWeapon {
		int32_t nameHash;
		float fBulletDamage;
		float fWeaponSpread;
		float fWeaponRecoil;
		float fWeaponRange;
		float fReloadSpeed;
		float fForceOnPed;
		float fForceOnVehicle; 
		float fForceOnHeli;
	};
	static std::vector<tWeapon> weaponList;

	if (localData.currWepaon == nullptr)
		return;

	bool found = false;
	tWeapon oWeapon;
	for (tWeapon weapon : weaponList)
	{
		if (weapon.nameHash == localData.currWepaon->nameHash)
		{
			oWeapon = weapon;
			found = true;
			break;
		}
	}

	if (!found)
	{
		weaponList.push_back({
			localData.currWepaon->nameHash,
			localData.currWepaon->fBulletDamage,
			localData.currWepaon->fWeaponSpread,
			localData.currWepaon->fWeaponRecoil,
			localData.currWepaon->fWeaponRange,
			localData.currWepaon->fReloadSpeed,
			localData.currWepaon->fForceOnPed,
			localData.currWepaon->fForceOnVehicle,
			localData.currWepaon->fForceOnHeli,
			});
	}
	else
	{
		{
			if (bMeleeOneHitKill)
				localData.factory->m_local_ped->pCPlayerInfo->fMeleeDamageMP = 100.f;		
			else		
				localData.factory->m_local_ped->pCPlayerInfo->fMeleeDamageMP = 1.f;

			if (bMeleeMegaKnockback)
				localData.factory->m_local_ped->pCPlayerInfo->fMeleeKnockbackMP = 1000.f;
			else
				localData.factory->m_local_ped->pCPlayerInfo->fMeleeKnockbackMP = bMeleeOneHitKill ? 5.f : 1.f;
		}

		{
			if (bWeaponInstantReload)
				localData.currWepaon->fReloadSpeed = oWeapon.fReloadSpeed * 10.f;
			else if (bWeaponEnableCustomReload)
				localData.currWepaon->fReloadSpeed = oWeapon.fReloadSpeed * fWeaponCustomReload;
			else
				localData.currWepaon->fReloadSpeed = oWeapon.fReloadSpeed;
		}

		{
			if (bWeaponOneShotKill)
			{
				localData.currWepaon->fBulletDamage = oWeapon.fBulletDamage;
				localData.factory->m_local_ped->pCPlayerInfo->fWeaponDamgeMP = 100.f;
			}			
			else if (bWeaponRubberBullets)
			{
				localData.currWepaon->fBulletDamage = oWeapon.fBulletDamage;
				localData.factory->m_local_ped->pCPlayerInfo->fWeaponDamgeMP = 0.f;
			}
			else if (bWeaponEnableCustomBulletDamage)
			{
				localData.currWepaon->fBulletDamage = fWeaponCustomBulletDamage;
				localData.factory->m_local_ped->pCPlayerInfo->fWeaponDamgeMP = 1.f;
			}
			else
			{
				localData.currWepaon->fBulletDamage = oWeapon.fBulletDamage;
				localData.factory->m_local_ped->pCPlayerInfo->fWeaponDamgeMP = 1.f;
			}
		}

		{
			if (bWeaponUnlimitedRange && bWeaponTeleportGun)
				localData.currWepaon->fWeaponRange = 2000.f;
			else if (bWeaponEnableCustomRange)
				localData.currWepaon->fWeaponRange = fWeaponCustomRange;
			else
				localData.currWepaon->fWeaponRange = oWeapon.fWeaponRange;
		}

		{
			if (bWeaponNoSpread)
				localData.currWepaon->fWeaponSpread = 0.f;
			else if (bWeaponEnableCustomSpread)
				localData.currWepaon->fWeaponSpread = fWeaponCustomSpread;
			else
				localData.currWepaon->fWeaponSpread = oWeapon.fWeaponSpread;
		}

		{
			if (bWeaponNoRecoil)
				localData.currWepaon->fWeaponRecoil = 0.f;
			else if (bWeaponEnableCustomRecoil)
				localData.currWepaon->fWeaponRecoil = fWeaponCustomRecoil;
			else
				localData.currWepaon->fWeaponRecoil = oWeapon.fWeaponRecoil;
		}

		{
			if (bWeaponForceOnPed)
				localData.currWepaon->fForceOnPed = oWeapon.fForceOnPed * fWeaponForceOnPed;
			else
				localData.currWepaon->fForceOnPed = oWeapon.fForceOnPed;

			if (bWeaponForceOnVehicle)
				localData.currWepaon->fForceOnVehicle = oWeapon.fForceOnVehicle * fWeaponForceOnVehicle;
			else
				localData.currWepaon->fForceOnVehicle = oWeapon.fForceOnVehicle;

			if (bWeaponForceOnHeli)
				localData.currWepaon->fForceOnHeli = oWeapon.fForceOnHeli * fWeaponForceOnHeli;
			else
				localData.currWepaon->fForceOnHeli = oWeapon.fForceOnHeli;
		}
	
	}
}

void features::WeaponAimer()
{
	if (!g_gui.m_opened)
	{
		if (!ENTITY::IS_ENTITY_DEAD(PLAYER::PLAYER_PED_ID()))
		{
			if(localData.IsInVehicle ? 1 : (WEAPON::IS_PED_ARMED(PLAYER::PLAYER_PED_ID(), 7) && WEAPON::IS_PED_ARMED(PLAYER::PLAYER_PED_ID(), 6)))
			{
				int smallest_Distance = fAimerMaxRange;	
				float fov = fAimerMaxFov;
						
				if (bWeaponTriggerbot)
				{
					Entity AimedAtEntity;
					if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &AimedAtEntity))
					{
						if (ENTITY::IS_ENTITY_A_PED(AimedAtEntity) && !ENTITY::IS_ENTITY_DEAD(AimedAtEntity))
						{
							//if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1))
							{
								bool triggered = false;
								bool human = false;

								tPlayerData data;
								for (tPlayerData dat : playerData)
								{
									if (dat.playerPed == AimedAtEntity)
									{
										human = true;
										data = dat;
									}									
								}

								for (tPlayerData dat : nearbyPeds)
								{
									if (dat.playerPed == AimedAtEntity)
										data = dat;
								}

								if (human)
								{
									if (data.IsFriend ||(data.IsTeam && isTeamGameModeRunning))
									{
										if (bAimbotShootAtAlly)
											triggered = true;
									}
									else if (bAimbotShootAtPlayers)
										triggered = true;
								}
								else
								{
									int realtionShip = PED::GET_RELATIONSHIP_BETWEEN_PEDS(data.playerPed, PLAYER::PLAYER_PED_ID());
									if (data.IsCop && bAimbotShootAtCops)
									{
										triggered = true;
									}
									else if ((realtionShip == 4) || (realtionShip == 5))
									{
										if (bAimbotShootAtEnemies)
											triggered = true;
									}
									else if (bAimbotShootAtNPCs & !data.IsCop)
									{
										triggered = true;
									}
								}

					
								if (triggered)
								{
									INPUT click;
									click.type = INPUT_MOUSE;
									click.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE;
									SendInput(1, &click, sizeof(click));

									/*PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 1);
									Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
									Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
									Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
									Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 1.0f)));
									Vector3 endCoords = addVector(startCoords, multiplyVector(gameplayCamDirection, 500.0f));
									PED::SET_PED_SHOOTS_AT_COORD(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), endCoords.x, endCoords.y, endCoords.z, true);*/
								}						
							}
						}
					}
				}

				if (bWeaponAimbot)
				{
					if (!PLAYER::IS_PLAYER_DEAD(PLAYER::PLAYER_ID()))
					{
						for (tPlayerData data : playerData)
						{
							if (data.playerId != localData.localId)
							{
								if (data.IsFriend || (data.IsTeam && isTeamGameModeRunning))
								{
									if (bAimbotShootAtAlly)
										goto shootPlayers;
								}
								else if (bAimbotShootAtPlayers)
								{
								shootPlayers:
									if (data.alive)
									{
										if (ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(PLAYER::PLAYER_PED_ID(), data.playerPed, 17))
										{
											if (bAimbotpSilentAim)
											{
												if (data.distance < smallest_Distance)
												{
													smallest_Distance = data.distance;
													AimbotPos = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(data.playerPed, PED::GET_PED_BONE_INDEX(data.playerPed, bAimBotBone));
												}
											}
											else
											{
												AimbotPos = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(data.playerPed, PED::GET_PED_BONE_INDEX(data.playerPed, bAimBotBone));
												if ((AimbotPos.x != 0) && (AimbotPos.y != 0) && (AimbotPos.z != 0))
												{
													float screen_x, screen_y;
													GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(AimbotPos.x, AimbotPos.y, AimbotPos.z, &screen_x, &screen_y);
													if ((screen_x >= 0) && (screen_y >= 0))
													{
														auto& io = ImGui::GetIO();
														ImVec2 center(io.DisplaySize.x / 2.f, io.DisplaySize.y / 2.f);

														screen_x *= io.DisplaySize.x;
														screen_y *= io.DisplaySize.y;


														float move_x, move_y;

														if (screen_x > center.x)
														{
															move_x = -(center.x - screen_x);
															if (move_x + center.x > center.x * 2) move_x = 0;
														}
														else {
															move_x = screen_x - center.x;
															if (move_x + center.x < 0) move_x = 0;
														}


														if (screen_y > center.y)
														{
															move_y = -(center.y - screen_y);
															if (move_y + center.y > center.y * 2) move_y = 0;
														}
														else {
															move_y = screen_y - center.y;
															if (move_y + center.y < 0) move_y = 0;
														}

														if (sqrt(pow(move_x, 2) + pow(move_y, 2)) < fov)
														{
															fov = sqrt(pow(move_x, 2) + pow(move_y, 2));
															AimbotMoveMouse.x = move_x;
															AimbotMoveMouse.y = move_y;
														}
													}
												}
											}
										}
									}
								}
							}
						}

						for (tPlayerData data : nearbyPeds)
						{

							if (ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(PLAYER::PLAYER_PED_ID(), data.playerPed, 17))
							{
								Vector3 coords = ENTITY::GET_ENTITY_COORDS(data.playerPed, 1);
								int dist = data.distance;

								int relationShip = PED::GET_RELATIONSHIP_BETWEEN_PEDS(data.playerPed, PLAYER::PLAYER_PED_ID());

								if (data.IsCop && bAimbotShootAtCops)
								{
									goto shootNPC;
								}
								if ((relationShip == 4) || (relationShip == 5))
								{
									if (bAimbotShootAtEnemies)
										goto shootNPC;
								}
								else if (bAimbotShootAtNPCs & !data.IsCop)
								{
								shootNPC:
									if (bAimbotpSilentAim)
									{
										if (dist < smallest_Distance)
										{
											smallest_Distance = dist;
											AimbotPos = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(data.playerPed, PED::GET_PED_BONE_INDEX(data.playerPed, bAimBotBone));
										}
									}
									else
									{
										AimbotPos = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(data.playerPed, PED::GET_PED_BONE_INDEX(data.playerPed, bAimBotBone));
										if ((AimbotPos.x != 0) && (AimbotPos.y != 0) && (AimbotPos.z != 0))
										{
											float screen_x, screen_y;
											GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(AimbotPos.x, AimbotPos.y, AimbotPos.z, &screen_x, &screen_y);
											if ((screen_x >= 0) && (screen_y >= 0))
											{
												auto& io = ImGui::GetIO();
												ImVec2 center(io.DisplaySize.x / 2.f, io.DisplaySize.y / 2.f);

												screen_x *= io.DisplaySize.x;
												screen_y *= io.DisplaySize.y;

												
												float move_x, move_y;

												if (screen_x > center.x)
												{
													move_x = -(center.x - screen_x);
													if (move_x + center.x > center.x * 2) move_x = 0;
												}
												else {
													move_x = screen_x - center.x;
													if (move_x + center.x < 0) move_x = 0;
												}


												if (screen_y > center.y)
												{
													move_y = -(center.y - screen_y);
													if (move_y + center.y > center.y * 2) move_y = 0;
												}
												else {
													move_y = screen_y - center.y;
													if (move_y + center.y < 0) move_y = 0;
												}

												if (sqrt(pow(move_x, 2) + pow(move_y, 2)) < fov)
												{
													fov = sqrt(pow(move_x, 2) + pow(move_y, 2));
													AimbotMoveMouse.x = move_x;
													AimbotMoveMouse.y = move_y;
												}
											}
										}										
									}
								}
							}
						}

						if (bAimbotAutoShoot)
						{
							if (bAimbotpSilentAim)
							{
								if ((AimbotPos.x != 0) && (AimbotPos.y != 0) && (AimbotPos.z != 0))
								{
									PED::SET_PED_SHOOTS_AT_COORD(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), AimbotPos.x, AimbotPos.y, AimbotPos.z, true);
								}
							}
							else
							{							
								if ((AimbotMoveMouse.x != 0) && (AimbotMoveMouse.y != 0))
								{
									INPUT move;
									move.type = INPUT_MOUSE;
									move.mi.dwFlags = MOUSEEVENTF_MOVE;
									move.mi.dx = AimbotMoveMouse.x / (bAimerEnableSmoothAim ? fAimerSmoothSpeed : 1);
									move.mi.dy = AimbotMoveMouse.y / (bAimerEnableSmoothAim ? fAimerSmoothSpeed : 1);
									SendInput(1, &move, sizeof(move));

									if (sqrt(pow(AimbotMoveMouse.x, 2) + pow(AimbotMoveMouse.y, 2)) < 2)
									{
										INPUT click;
										click.type = INPUT_MOUSE;
										click.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE;
										SendInput(1, &click, sizeof(click));
									}

									AimbotMoveMouse.x = 0;
									AimbotMoveMouse.y = 0;
								}
							}										
						}
						else
						{
							if (bAimbotpSilentAim)
							{
								if (CONTROLS::IS_CONTROL_PRESSED(2, 208) || (GetKeyState(VK_LBUTTON) & 0x8000)) {
									if ((AimbotPos.x != 0) && (AimbotPos.y != 0) && (AimbotPos.z != 0))
										PED::SET_PED_SHOOTS_AT_COORD(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), AimbotPos.x, AimbotPos.y, AimbotPos.z, true);
								}
							}
							else
							{
								if (CONTROLS::GET_DISABLED_CONTROL_NORMAL(0, INPUT_AIM))
								{
									static bool timer_reset = true;
									static std::chrono::system_clock::time_point timer_Start;

									if (timer_reset)
									{
										timer_Start = std::chrono::system_clock::now();
										timer_reset = false;
									}
					
									std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - timer_Start;
									if (elapsed_seconds.count() > 0.02f)
									{
										INPUT move;
										move.type = INPUT_MOUSE;
										move.mi.dwFlags = MOUSEEVENTF_MOVE;

										if (sqrt(pow(AimbotMoveMouse.x, 2) + pow(AimbotMoveMouse.y, 2)) < 2)
										{
											move.mi.dx = AimbotMoveMouse.x / 1.7f;
											move.mi.dy = AimbotMoveMouse.y / 1.75;
											//SendInput(1, &move, sizeof(move));
										}
										else
										{
											move.mi.dx = AimbotMoveMouse.x / (bAimerEnableSmoothAim ? fAimerSmoothSpeed : 1);
											move.mi.dy = AimbotMoveMouse.y / (bAimerEnableSmoothAim ? fAimerSmoothSpeed : 1);
											SendInput(1, &move, sizeof(move));
										}		
										
										AimbotMoveMouse.x = 0;
										AimbotMoveMouse.y = 0;

										timer_reset = true;
									}
								}
							}				
						}	
					}
				}
			}
		}
	}
}

void features::SelfTinyPlayer()
{
	PED::SET_PED_CONFIG_FLAG(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 223, bSelfTinyPlayer);
}

void features::SelfPTFX()
{
	static bool timer_reset = true;
	static std::chrono::system_clock::time_point timer_Start;

	if (timer_reset)
	{
		timer_Start = std::chrono::system_clock::now();
		timer_reset = false;
	}

	std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - timer_Start;
	if (elapsed_seconds.count() > 0.3f)
	{
		if (PTFXName != std::string("None"))
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET(PTFXCall.c_str());
			GRAPHICS::USE_PARTICLE_FX_ASSET(PTFXCall.c_str());
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(PTFXName.c_str(), PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
			//GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_ENTITY(g_gui.PtfxName, PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
		}

		if (bSelfFireBreath)
		{
			float XPos = 0.02, YPos = 0.2, ZPos = 0.0, XOff = 90.0, YOff = -100.0, ZOff = 90.0;
			STREAMING::REQUEST_NAMED_PTFX_ASSET("core");
			GRAPHICS::USE_PARTICLE_FX_ASSET("core");
			int ptfx = GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("ent_sht_flame", PLAYER::PLAYER_PED_ID(), XPos, YPos, ZPos, XOff, YOff, ZOff, 0x796e, 1, 1, 1, 1);
			STREAMING::REMOVE_PTFX_ASSET();
		}

		timer_reset = true;
	}
}

void features::SelfOffRadar()
{
	*script_global::script_global(2424073).at(PLAYER::PLAYER_ID(), 421).at(200).as<bool*>() = bSelfOffRadar;
	if (bSelfOffRadar)
		*script_global::script_global(2437549).at(70).as<int32_t*>() = NETWORK::GET_NETWORK_TIME();
}

void features::SelfInstantBST()
{
	if (bSelfInstantBST)
		*script_global::script_global(2437549).at(3880).as<int32_t*>() = 3;
}

void features::SelfNoClip()
{
	if (bSelfNoClip)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, false);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		if (GetAsyncKeyState(0x57) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 268)) {
			float fivef = .5f;
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			float xVec = fivef * sin(degToRad(heading)) * -1.0f;
			float yVec = fivef * cos(degToRad(heading));
			ENTITY::SET_ENTITY_HEADING(playerPed, heading);

			pos.x -= xVec, pos.y -= yVec;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		}
		if (GetAsyncKeyState(0x53) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269)) {
			float fivef = .5f;
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			float xVec = fivef * sin(degToRad(heading)) * -1.0f;
			float yVec = fivef * cos(degToRad(heading));
			ENTITY::SET_ENTITY_HEADING(playerPed, heading);

			pos.x += xVec, pos.y += yVec;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		}
		if (GetAsyncKeyState(0x41) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 266)) {
			float fivef = .5f;
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			ENTITY::SET_ENTITY_HEADING(playerPed, heading + 1.f);
		}
		if (GetAsyncKeyState(0x44) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 271)) {
			float fivef = .5f;
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			ENTITY::SET_ENTITY_HEADING(playerPed, heading - 1.f);
		}
		if (GetAsyncKeyState(VK_SHIFT) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 206)) {
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			ENTITY::SET_ENTITY_HEADING(playerPed, heading);

			pos.z -= 0.1;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		}
		if (GetAsyncKeyState(VK_SPACE) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 205)) {
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			ENTITY::SET_ENTITY_HEADING(playerPed, heading);

			pos.z += 0.1;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		}
	}
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

void features::RequestControlOfid(Entity netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}

void features::RequestControlOfEnt(Entity entity)
{
	int tick = 0;
	while (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(entity) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(entity);
		tick++;
	}
	if (NETWORK::NETWORK_IS_SESSION_STARTED())
	{
		int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(entity);
		RequestControlOfid(netID);
		NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
	}
}

void features::defuseEvent(eRockstarEvent e, bool b)
{
	static const BYTE	ret = 0xC3;
	BYTE* ptr = (BYTE*)g_pointers->EventPtr[e];
	if (b)
	{
		if (g_pointers->EventRestore[e] == 0)
			g_pointers->EventRestore[e] = ptr[0];
		*ptr = ret;
	}
	else if (g_pointers->EventRestore[e] != 0)
		*ptr = g_pointers->EventRestore[e];
}


void features::update_nearby_peds(Ped playerPed, int count)
{
	static bool timer_reset = true;
	static std::chrono::system_clock::time_point timer_Start;

	if (timer_reset)
	{
		timer_Start = std::chrono::system_clock::now();
		timer_reset = false;
	}

	std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - timer_Start;
	if (elapsed_seconds.count() >= 0.05f)
	{
		CReplayInterface* replayIntf = *g_pointers->m_replayIntf;
		CPedInterface* pedIF = replayIntf->pCPedInterface;
		int	numPed = pedIF->iMaxPeds;
		for (int i = 0; i < numPed; ++i)
		{
			CPed* pPed = pedIF->get_ped(i);
			if (pPed == nullptr)
				continue;
			Ped ped = g_pointers->m_ptr_to_handle(pPed);
			if (ped == playerPed)
				continue;
			if (PED::IS_PED_DEAD_OR_DYING(ped, FALSE))
				continue;
			if (PED::IS_PED_A_PLAYER(ped))
				continue;

			bool inSet = lastSeenNearbyPeds.find(ped) != lastSeenNearbyPeds.end();
			if (!inSet)
			{
				lastSeenNearbyPeds.insert(ped);
			}
		}


		std::set<Ped>::iterator it;
		for (it = lastSeenNearbyPeds.begin(); it != lastSeenNearbyPeds.end();)
		{
			if (!ENTITY::DOES_ENTITY_EXIST(*it) || ENTITY::IS_ENTITY_DEAD(*it) || (PLAYER::PLAYER_PED_ID() == *it))
			{
				lastSeenNearbyPeds.erase(it++);
			}
			else
			{
				++it;
			}
		}

		int i = 0;
		for (tPlayerData data : nearbyPeds)
		{
			bool found = false;
			for (Ped ped : lastSeenNearbyPeds)
			{
				if (data.playerPed == ped)
				{
					found = true;
					break;
				}
			}
			if (!found)
			{
				nearbyPeds.erase(nearbyPeds.begin() + i);
				break;
			}
			i++;
		}


		timer_reset = true;
	}
}

void features::updatePeds()
{
	update_nearby_peds(localData.localPed, 20);

	for (Ped ped : lastSeenNearbyPeds)
	{
		bool found = false;
	
		int i = 0;
		for (tPlayerData data : nearbyPeds)
		{
			if (data.playerPed == ped)
			{
				found = true;
				nearbyPeds.at(i).health = ENTITY::GET_ENTITY_HEALTH(ped);
				nearbyPeds.at(i).maxHealth = ENTITY::GET_ENTITY_MAX_HEALTH(ped);
				nearbyPeds.at(i).IsInVehicle = PED::IS_PED_IN_ANY_VEHICLE(ped, FALSE);

				Vector3 coords = ENTITY::GET_ENTITY_COORDS(ped, TRUE);
				nearbyPeds.at(i).position = { coords.x, coords.y, coords.z };
				nearbyPeds.at(i).distance = GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(localData.visualPos.x, localData.visualPos.y, localData.visualPos.z, data.position.x, data.position.y, data.position.z, TRUE);
				nearbyPeds.at(i).heading = ENTITY::GET_ENTITY_HEADING(ped);

				nearbyPeds.at(i).head = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_Head)); // kopf
				nearbyPeds.at(i).lFoot = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Foot));  // links Ferse
				nearbyPeds.at(i).rFoot = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Foot));  // rechts Ferse
				if (ESPSkeleton)
				{			
					nearbyPeds.at(i).neck = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_Neck_1)); // genick
					nearbyPeds.at(i).stomach = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_Spine1)); // Bauch
					nearbyPeds.at(i).pelvis = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_Pelvis)); // Becken
					nearbyPeds.at(i).lThigh = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Thigh)); // links schenkel
					nearbyPeds.at(i).rThigh = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Thigh));  // rechts schenkel
					nearbyPeds.at(i).lCalf = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Calf)); // links Knie
					nearbyPeds.at(i).rCalf = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Calf)); // rechts Knie			

					nearbyPeds.at(i).lClavicle = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Clavicle));  // links Schlüsselbein
					nearbyPeds.at(i).rClavicle = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Clavicle)); // rechts Schlüsselbein
					nearbyPeds.at(i).lUpperArm = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_UpperArm));
					nearbyPeds.at(i).rUpperArm = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_UpperArm));
					nearbyPeds.at(i).lForeArm = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Forearm));
					nearbyPeds.at(i).rForeArm = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Forearm));
					nearbyPeds.at(i).lHand = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Hand));
					nearbyPeds.at(i).rHand = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Hand));
				}
				break;
			}
			i++;
		}

		tPlayerData data;
		if (!found)
		{
			data.playerPed = ped;
			
			data.alive = true;
			data.IsNPC = true;
			data.IsCop = false;
			data.playerName = "NPC";
			int pedType = PED::GET_PED_TYPE(ped);
			switch (pedType)
			{
			case 4:
				if (PED::IS_PED_MODEL(ped, rage::joaat("s_m_y_ranger_01")))
				{
					data.playerName = "Ranger";
					data.IsCop = true;
				}
				break;

			case 5:
				if (PED::IS_PED_MODEL(ped, rage::joaat("s_f_y_ranger_01")))
				{
					data.playerName = "Ranger";
					data.IsCop = true;
				}
				break;

			case 6:
				if (PED::IS_PED_MODEL(ped, rage::joaat("s_m_y_uscg_01")))
				{
					data.playerName = "US Coast Guard";
				}
				else
				{
					data.playerName = "Cop";
					data.IsCop = true;
				}
				break;

			case 20:
				data.playerName = "Paramedic";
				break;

			case 21:
				data.playerName = "LSFD";
				break;

			case 27:
				data.playerName = "SWAT";
				data.IsCop = true;
				break;

			case 28:
				data.playerName = "Animal";
				break;

			case 29:
				data.playerName = "Army";
				data.IsCop = true;
				break;
			}

			data.health = ENTITY::GET_ENTITY_HEALTH(ped);
			data.maxHealth = ENTITY::GET_ENTITY_MAX_HEALTH(ped);
			data.IsInVehicle = PED::IS_PED_IN_ANY_VEHICLE(ped, FALSE);

			Vector3 coords = ENTITY::GET_ENTITY_COORDS(ped, TRUE);
			data.position = { coords.x, coords.y, coords.z };
			data.distance = GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(localData.visualPos.x, localData.visualPos.y, localData.visualPos.z, data.position.x, data.position.y, data.position.z, TRUE);
			data.heading = ENTITY::GET_ENTITY_HEADING(ped);

			data.head = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_Head)); // kopf
			data.lFoot = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Foot));  // links Ferse
			data.rFoot = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Foot));  // rechts Ferse
			if (ESPSkeleton)
			{		
				data.neck = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_Neck_1)); // genick
				data.stomach = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_Spine1)); // Bauch
				data.pelvis = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_Pelvis)); // Becken
				data.lThigh = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Thigh)); // links schenkel
				data.rThigh = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Thigh));  // rechts schenkel
				data.lCalf = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Calf)); // links Knie
				data.rCalf = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Calf)); // rechts Knie			

				data.lClavicle = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Clavicle));  // links Schlüsselbein
				data.rClavicle = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Clavicle)); // rechts Schlüsselbein
				data.lUpperArm = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_UpperArm));
				data.rUpperArm = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_UpperArm));
				data.lForeArm = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Forearm));
				data.rForeArm = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Forearm));
				data.lHand = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Hand));
				data.rHand = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Hand));
			}

			nearbyPeds.push_back(data);
		}
	}
}

void features::notifyAboveMap(std::string msg, BOOL blink) {

	UI::SET_TEXT_OUTLINE();
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(&msg[0u]);
	UI::_DRAW_NOTIFICATION(blink, FALSE);
}

//VECTOR AND FLOAT FUNCTIONS
Vector3 features::rot_to_direction(Vector3* rot) {
	float radiansZ = rot->z * 0.0174532924f;
	float radiansX = rot->x * 0.0174532924f;
	float num = abs((float)cos((double)radiansX));
	Vector3 dir;
	dir.x = (float)((double)((float)(-(float)sin((double)radiansZ))) * (double)num);
	dir.y = (float)((double)((float)cos((double)radiansZ)) * (double)num);
	dir.z = (float)sin((double)radiansX);
	return dir;
}


double features::DegreeToRadian(double n) {
	return n * 0.017453292519943295;
}

Vector3 features::RotationToDirection(Vector3 rot) {
	double num = DegreeToRadian(rot.z);
	double num2 = DegreeToRadian(rot.x);
	double val = cos(num2);
	double num3 = abs(val);
	rot.x = (float)(-(float)sin(num) * num3);
	rot.y = (float)(cos(num) * num3);
	rot.z = (float)sin(num2);
	return rot;

}

Vector3 features::multiplyVector(Vector3 vector, float inc) {
	vector.x *= inc;
	vector.y *= inc;
	vector.z *= inc;
	vector._paddingx *= inc;
	vector._paddingy *= inc;
	vector._paddingz *= inc;
	return vector;
}

Vector3 features::addVector(Vector3 vector, Vector3 vector2)
{
	return { vector.x += vector2.x, vector._paddingx += vector2._paddingx, vector.y += vector2.y, vector._paddingy += vector2._paddingy, vector.z += vector2.z, vector._paddingz += vector2._paddingz };
}

Vector3 features::subVector(Vector3 vector, Vector3 vector2)
{
	return { vector.x -= vector2.x, vector._paddingx -= vector2._paddingx, vector.y -= vector2.y, vector._paddingy -= vector2._paddingy, vector.z -= vector2.z, vector._paddingz -= vector2._paddingz };
}


void features::CalcAngle(float* src, float* dst, float* angles)
{
	double delta[3] = { (src[0] - dst[0]), (src[1] - dst[1]), (src[2] - dst[2]) };
	double hyp = sqrt(delta[0] * delta[0] + delta[1] * delta[1]);
	angles[0] = (float)(asinf(delta[2] / hyp) * 57.295779513082f);
	angles[1] = (float)(atanf(delta[1] / delta[0]) * 57.295779513082f);
	angles[2] = 0.0f;
	if (delta[0] >= 0.0) { angles[1] += 180.0f; }
}

Vector3 features::calcAngles(Vector3 localEye, Vector3 aimpos)
{
	Vector3 relative = subVector(aimpos, localEye);
	float yaw = atan(relative.y / relative.x);
	float pitch = acos(relative.z / get_magnitude(relative));
	return { yaw, NULL, pitch, NULL, 0.f, NULL };
}

float features::degToRad(float degs)
{
	return degs * 3.141592653589793f / 180.f;
}


float features::get_distance(Vector3* pointA, Vector3* pointB) {
	float a_x = pointA->x;
	float a_y = pointA->y;
	float a_z = pointA->z;
	float b_x = pointB->x;
	float b_y = pointB->y;
	float b_z = pointB->z;
	double x_ba = (double)(b_x - a_x);
	double y_ba = (double)(b_y - a_y);
	double z_ba = (double)(b_z - a_z);
	double y_2 = y_ba * y_ba;
	double x_2 = x_ba * x_ba;
	double sum_2 = y_2 + x_2;
	return(float)sqrt(sum_2 + z_ba);
}

float features::get_magnitude(Vector3 vec3)
{
	float magnitude = sqrt(pow(vec3.x,2) + pow(vec3.y, 2) + pow(vec3.z, 2));
	return magnitude;
}

std::string features::currentTime()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	localtime_s(&tstruct, &now);
	strftime(buf, sizeof(buf), "%X", &tstruct);
	return buf;
}

uintptr_t features::get_address_of_item_in_pool(MemoryPool* pool, int handle)
{
	if (pool == nullptr)
		return 0;

	int index = handle >> 8;
	int flag = pool->BoolAdr[index];

	if (flag & 0x80 || flag != (handle & 0xFF))
		return 0;

	return pool->ListAddr + index * pool->ItemSize;
}
