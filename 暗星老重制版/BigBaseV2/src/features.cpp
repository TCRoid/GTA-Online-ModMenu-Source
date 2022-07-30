#include "common.hpp"
#include "features.hpp"
#include "logger.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "imgui.h"
#include "fiber_pool.hpp"
#include "gta_util.hpp"
#include "ImGuiBitfield.h"
#include "common.hpp"
#include "../src/gta/blip.hpp"
#include"memory/native_memory.hpp"
#include"memory/all.hpp"
#include"offset.hpp"
#include"lists.hpp"
#include"util/util.hpp"

namespace big
{
	void features::tpToVector3(Vector3 coords)
	{
		Ped ped = PLAYER::PLAYER_PED_ID();
		if (PED::IS_PED_IN_ANY_VEHICLE(ped, 0))
		{
			ped = PED::GET_VEHICLE_PED_IS_USING(ped);
		}
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(ped, coords.x, coords.y, coords.z, 0, 0, 1);
	}

	void features::DoScenario(char* anim, char* animid)
	{
		STREAMING::REQUEST_ANIM_DICT(anim);
		while (!STREAMING::HAS_ANIM_DICT_LOADED((anim))) script::get_current()->yield();
		TASK::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
		TASK::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), anim, animid, 8.0f, 0.0f, -1, 1, 0, 0, 0, 0);
	}

	void features::pedStpme()
	{
		Vector3 myPos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;
		Ped* peds = new Ped[ArrSize];
		peds[0] = ElementAmount;
		int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);
		for (int i = 0; i < PedFound; i++)
		{
			int OffsetID = i * 2 + 2;
			if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
			{
				util::requestControlOfEnt(peds[OffsetID]);
				ENTITY::SET_ENTITY_COORDS(peds[OffsetID], myPos.x, myPos.y, myPos.z, false, false, false, false);
			}
		}
		delete[] peds;
	}

	void features::updateNearbyPeds(Ped playerPed, int count)
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
			rage::CReplayInterface* replayIntf = *g_pointers->m_replay_interface;
			rage::CPedInterface* pedIF = replayIntf->m_ped_interface;
			int	numPed = pedIF->m_max_peds;
			for (int i = 0; i < numPed; ++i)
			{
				rage::CPed* pPed = pedIF->get_ped(i);
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
				if (!ENTITY::DOES_ENTITY_EXIST(*it) || ENTITY::IS_ENTITY_DEAD(*it, 0) || (PLAYER::PLAYER_PED_ID() == *it))
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
		updateNearbyPeds(localData.localPed, 20);

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
					nearbyPeds.at(i).distance = MISC::GET_DISTANCE_BETWEEN_COORDS(localData.visualPos.x, localData.visualPos.y, localData.visualPos.z, data.position.x, data.position.y, data.position.z, TRUE);
					nearbyPeds.at(i).heading = ENTITY::GET_ENTITY_HEADING(ped);

					nearbyPeds.at(i).head = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_Head)); // kopf
					nearbyPeds.at(i).lFoot = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Foot));  // links Ferse
					nearbyPeds.at(i).rFoot = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Foot));  // rechts Ferse

					nearbyPeds.at(i).neck = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_Neck_1)); // genick
					nearbyPeds.at(i).stomach = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_Spine1)); // Bauch
					nearbyPeds.at(i).pelvis = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_Pelvis)); // Becken
					nearbyPeds.at(i).lThigh = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Thigh)); // links schenkel
					nearbyPeds.at(i).rThigh = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Thigh));  // rechts schenkel
					nearbyPeds.at(i).lCalf = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Calf)); // links Knie
					nearbyPeds.at(i).rCalf = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Calf)); // rechts Knie

					nearbyPeds.at(i).lClavicle = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Clavicle));  // links Schl黶selbein
					nearbyPeds.at(i).rClavicle = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Clavicle)); // rechts Schl黶selbein
					nearbyPeds.at(i).lUpperArm = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_UpperArm));
					nearbyPeds.at(i).rUpperArm = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_UpperArm));
					nearbyPeds.at(i).lForeArm = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Forearm));
					nearbyPeds.at(i).rForeArm = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Forearm));
					nearbyPeds.at(i).lHand = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Hand));
					nearbyPeds.at(i).rHand = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Hand));

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
				data.distance = MISC::GET_DISTANCE_BETWEEN_COORDS(localData.visualPos.x, localData.visualPos.y, localData.visualPos.z, data.position.x, data.position.y, data.position.z, TRUE);
				data.heading = ENTITY::GET_ENTITY_HEADING(ped);

				data.head = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_Head)); // kopf
				data.lFoot = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Foot));  // links Ferse
				data.rFoot = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Foot));  // rechts Ferse
				if (0)
				{
					data.neck = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_Neck_1)); // genick
					data.stomach = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_Spine1)); // Bauch
					data.pelvis = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_Pelvis)); // Becken
					data.lThigh = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Thigh)); // links schenkel
					data.rThigh = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Thigh));  // rechts schenkel
					data.lCalf = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Calf)); // links Knie
					data.rCalf = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Calf)); // rechts Knie

					data.lClavicle = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_L_Clavicle));  // links Schl黶selbein
					data.rClavicle = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(ped, PED::GET_PED_BONE_INDEX(ped, SKEL_R_Clavicle)); // rechts Schl黶selbein
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

	void features::playerModelCrashAll()
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		std::vector<Hash> crashPedHash = { 2627665880 ,1885233650 };
		Vector3 originalCoord = ENTITY::GET_ENTITY_COORDS(playerPed, false);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, -76.101f, -819.124f, 326.175f, 0, 0, 1);
		for (size_t i = 0; i < 20; i++)
		{
			for (Hash pedHash : crashPedHash)
			{
				features::changePlayerModel(pedHash);
				ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 0, 1);
				script::get_current()->yield(100ms);
				PED::RESURRECT_PED(playerPed);
				script::get_current()->yield(300ms);
			}
		}
		features::teleportToCoords(playerPed, originalCoord);
	}

	void features::deleteNearbyPeds()
	{
		const int ElementAmount = 20;
		const int ArrSize = ElementAmount * 2 + 2;
		Ped* peds = new Ped[ArrSize];
		peds[0] = ElementAmount;
		int pedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, 10);

		for (int i = 0; i < pedFound; i++)
		{
			int OffsetID = i * 2 + 2;

			util::requestControlOfEnt(peds[OffsetID]);
			ENTITY::SET_ENTITY_COORDS(peds[OffsetID], 6400.f, 6400.f, 0.f, false, false, false, false);
		}
		delete[] peds;
	}

	void features::killNearbyPeds()
	{
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Ped* peds = new Ped[ArrSize];
		peds[0] = ElementAmount;

		int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

		for (int i = 0; i < PedFound; i++)
		{
			int OffsetID = i * 2 + 2;
			util::requestControlOfEnt(peds[OffsetID]);
			if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID] && !PED::IS_PED_A_PLAYER(peds[OffsetID]))
			{
				PED::APPLY_DAMAGE_TO_PED(peds[OffsetID], 1000, false, 1);
			}
		}
	}

	void features::upgradeNearbyVehicles()
	{
		const int ElementAmount = 20;
		const int ArrSize = ElementAmount * 2 + 2;

		Vehicle* vehs = new Vehicle[ArrSize];
		vehs[0] = ElementAmount;
		int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

		for (int i = 0; i < VehFound; i++)
		{
			int OffsetID = i * 2 + 2;
			if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
			{
				util::requestControlOfEnt(vehs[OffsetID]);
				VEHICLE::SET_VEHICLE_MOD_KIT(vehs[OffsetID], 0);
				for (int i = 0; i < 50; i++)
				{
					VEHICLE::SET_VEHICLE_MOD(vehs[OffsetID], i, VEHICLE::GET_NUM_VEHICLE_MODS(vehs[OffsetID], i) - 1, false);
				}
			}
		}
		delete[] vehs;
	}

	void features::deleteNearbyVehicles()
	{
		const int ElementAmount = 20;
		const int ArrSize = ElementAmount * 2 + 2;

		Vehicle* vehs = new Vehicle[ArrSize];
		vehs[0] = ElementAmount;
		int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

		for (int i = 0; i < VehFound; i++)
		{
			int OffsetID = i * 2 + 2;
			if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
			{
				util::requestControlOfEnt(vehs[OffsetID]);
				ENTITY::SET_ENTITY_COORDS(vehs[OffsetID], 6400.f, 6400.f, 0.f, false, false, false, false);
			}
		}
		delete[] vehs;
	}

	DWORD64 features::turntablePoint = 0;
	void features::turntableInit()
	{
		try
		{
			memory::pattern_batch batch;
			batch.add("turntableInit", "FF 00 00 00 00 95 ? ? ? ? ? 00 00 C1 3F F0 BC ? ? ? ? 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 D2 E0 7B DE", [](memory::handle ptr)
				{
					features::turntablePoint = ptr.as<DWORD64>();
					char Str[32];
					sprintf(Str, "%I64x", features::turntablePoint);
					g_gui.SendNotification("初始化成功", Str);
				});
			batch.run(memory::module(nullptr));
		}
		catch (const std::runtime_error& e)
		{
			g_gui.SendNotification("初始化失败", "请手动转一次，不要离开名钻");
		}
	}

	void features::getTurntable(int value)
	{
		if (features::turntablePoint == 0)
		{
			g_gui.SendNotification("获取奖品失败", "请手动抽奖后进行初始化");
		}
		else
		{
			auto ptr = features::turntablePoint - 0x13 - 0xF8;
			auto ptr1 = features::turntablePoint - 0x13;
			memcpy((void*)ptr, &value, sizeof(value));
			int v = 11;
			memcpy((void*)ptr1, &v, sizeof(value));
			g_gui.SendNotification("转盘抽奖", "获取转盘奖品成功！");

			//	HWND hWindow = FindWindow(L"grcWindow", NULL);
			//	DWORD dwPID = 0;
			//	GetWindowThreadProcessId(hWindow, &dwPID);
			//HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, 1, dwPID);
			//unsigned long long firstvalue = 0;
			//WriteProcessMemory(hProcess, (void*)(ptr), &value, sizeof(unsigned long long), NULL);
			//WriteProcessMemory(hProcess, (void*)(ptr1), &v, sizeof(unsigned long long), NULL);
		}
	}

	void features::exitCar()
	{
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Ped* peds = new Ped[ArrSize];
		peds[0] = ElementAmount;

		int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

		for (int i = 0; i < PedFound; i++)
		{
			int OffsetID = i * 2 + 2;
			util::requestControlOfEnt(peds[OffsetID]);
			if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
			{
				TASK::TASK_LEAVE_ANY_VEHICLE(peds[OffsetID], true, true);
			}
		}
	}

	void features::explodeNearbyVehicles()
	{
		const int ElementAmount = 20;
		const int ArrSize = ElementAmount * 2 + 2;

		Vehicle* vehs = new Vehicle[ArrSize];
		vehs[0] = ElementAmount;
		int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);
		for (int i = 0; i < VehFound; i++)
		{
			int OffsetID = i * 2 + 2;
			if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
			{
				util::requestControlOfEnt(vehs[OffsetID]);
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(vehs[OffsetID], false);
				FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0, 1000.f, true, false, 0.f, false);
			}
		}
		delete[] vehs;
	}

	void features::teleportToObjective()
	{
		rage::Blip_t* blip = util::getBlipObjective();
		if (blip == nullptr)
			g_gui.SendNotification("传送", "没有找到任务点");

		else
		{
			Entity e = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
			if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
			{
				e = PED::GET_VEHICLE_PED_IS_USING(e);
			}
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, blip->m_x, blip->m_y, blip->m_z + 0.5f, 0, 0, 1);
		}
	}

	void features::aboveMap(const char* text)
	{
		HUD::SET_TEXT_OUTLINE();
		HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
		HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
		HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(false, false);
	}

	void features::mapAndLog(const char* log)
	{
		LOG(INFO) << log;
		features::aboveMap(log);
	}

	void features::playerSpecate()
	{
		if (!g_settings.selected_player.is_online || !g_settings.player.spectating)
		{
			if (g_settings.player.spectating) g_settings.player.spectating = false;
			HUD::SET_MINIMAP_IN_SPECTATOR_MODE(false, -1);
			return;
		}

		Ped target = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_settings.selected_player.id);
		HUD::SET_MINIMAP_IN_SPECTATOR_MODE(true, target);
	}

	void features::attachEntity(Entity ent)
	{
		util::requestControlOfEnt(ent);
		ENTITY::SET_ENTITY_VISIBLE(ent, false, 0);
		ENTITY::SET_ENTITY_INVINCIBLE(ent, true);
		ENTITY::ATTACH_ENTITY_TO_ENTITY(ent, PLAYER::PLAYER_PED_ID(), 0, 0, 0, -10, 0, 0, 0, 1, true, false, false, 0, true);
	}

	void features::attachEntity(char* str, Player player)
	{
		Hash hash = MISC::GET_HASH_KEY(str);
		if (STREAMING::IS_MODEL_VALID(hash))
		{
			while (!STREAMING::HAS_MODEL_LOADED(hash))
			{
				STREAMING::REQUEST_MODEL(hash);
				script::get_current()->yield();
			}
		}
		else
		{
			g_gui.SendNotification("套模失败", "错误的模型！");
			return;
		}
		*(unsigned short*)g_pointers->m_model_spawn_bypass = 0x9090;
		Vehicle object = OBJECT::CREATE_OBJECT(hash, 0.0f, 0.0f, 0.0f, 1, 1, 1);
		*(unsigned short*)g_pointers->m_model_spawn_bypass = 0x0574;
		ENTITY::SET_ENTITY_LOD_DIST(object, 1000000);
		ENTITY::ATTACH_ENTITY_TO_ENTITY(object, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), SKEL_Neck_1, 0, 0, 0, 0, 0, 0, false, false, false, true, 2, true);
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

	void features::updateLocalData()
	{
		localData.factory = *g_pointers->m_ped_factory;
		localData.currWeapon = localData.factory->m_local_ped->m_weapon_manager->m_weapon_info;
		localData.maxhealth = localData.factory->m_local_ped->m_maxhealth;
		localData.health = localData.factory->m_local_ped->m_health;
		localData.localPed = PLAYER::PLAYER_PED_ID();
		localData.visualPos = localData.factory->m_local_ped->m_navigation->m_position;
		localData.localId = PLAYER::PLAYER_ID();
		localData.alive = !PLAYER::IS_PLAYER_DEAD(localData.localId);
		if (localData.IsInVehicle = PED::IS_PED_IN_ANY_VEHICLE(localData.localPed, FALSE))
			localData.vehicle = PED::GET_VEHICLE_PED_IS_IN(localData.localPed, FALSE);
		localData.teamId = PLAYER::GET_PLAYER_TEAM(PLAYER::PLAYER_ID());
		localData.connectedPlayers = NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS();
		localData.IsHost = NETWORK::NETWORK_IS_HOST();
		localData.IsScriptHost = (NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == localData.localId);
	}

	void features::updatePlayerData()
	{
		for (int i = 0; i < 32; i++)
		{
			if (*g_pointers->m_is_session_started)
			{
				if (playerData[i].IsConnected = NETWORK::NETWORK_IS_PLAYER_CONNECTED(i))
				{
					if (playerData[i].netPlayer = g_pointers->m_get_net_game_player(i))
					{
						if (playerData[i].IsValid = playerData[i].netPlayer->is_valid())
						{
							if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)))
							{
								if (playerData[i].netPlayer->get_net_data() != NULL)
								{
									if (playerData[i].netPlayer->m_player_info->m_ped != NULL)
									{
										playerData[i].netData = playerData[i].netPlayer->get_net_data();
										playerData[i].cped = playerData[i].netPlayer->m_player_info->m_ped;

										playerData[i].IsHost = playerData[i].netPlayer->is_host();
										playerData[i].IsScriptHost = (NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i);

										playerData[i].IsFriend = isFriend(i);

										playerData[i].online_ip = playerData[i].netPlayer->get_net_data()->m_external_ip;
										playerData[i].online_port = playerData[i].netPlayer->get_net_data()->m_external_port;
										playerData[i].rockstar_id = playerData[i].netPlayer->get_net_data()->m_rockstar_id;

										playerData[i].playerName = playerData[i].netPlayer->get_name();
										playerData[i].playerId = i;
										playerData[i].playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);

										playerData[i].alive = !(PLAYER::IS_PLAYER_DEAD(i));
										playerData[i].wantedLevel = playerData[i].netPlayer->m_player_info->m_wanted_level;
										playerData[i].IsInVehicle = PED::IS_PED_IN_ANY_VEHICLE(playerData[i].playerPed, FALSE);
										playerData[i].IsInInterrior = INTERIOR::GET_INTERIOR_FROM_ENTITY(playerData[i].playerPed) != NULL;
										playerData[i].teamId = PLAYER::GET_PLAYER_TEAM(i);

										playerData[i].IsTeam = (playerData[i].teamId == localData.teamId);

										//playerData[i].godmode = ((playerData[i].netPlayer->m_player_info->m_ped->m_godmode == 0x01) && !playerData[i].IsInInterrior);
										playerData[i].health = static_cast<int>(playerData[i].netPlayer->m_player_info->m_ped->m_health);
										playerData[i].maxHealth = static_cast<int>(playerData[i].netPlayer->m_player_info->m_ped->m_maxhealth);
										playerData[i].armour = playerData[i].netPlayer->m_player_info->m_ped->m_armor;
										playerData[i].maxArmour = PLAYER::GET_PLAYER_MAX_ARMOUR(i);
										playerData[i].position = playerData[i].netPlayer->m_player_info->m_ped->m_navigation->m_position;
										playerData[i].distance = MISC::GET_DISTANCE_BETWEEN_COORDS(localData.visualPos.x, localData.visualPos.y, localData.visualPos.z, playerData[i].position.x, playerData[i].position.y, playerData[i].position.z, TRUE);
										playerData[i].speed = ENTITY::GET_ENTITY_SPEED(playerData[i].IsInVehicle ? PED::GET_VEHICLE_PED_IS_IN(playerData[i].playerPed, FALSE) : playerData[i].playerPed);
										playerData[i].heading = ENTITY::GET_ENTITY_HEADING(playerData[i].playerPed);

										playerData[i].wallet = *script_global(PLAYER_INFO_).at(g_settings.SelectedPlayer, 888).at(205).at(3).as<int*>();
										playerData[i].level = *script_global(1590908 + 1).at(i, 888).at(205).at(5).as<int32_t*>();
										playerData[i].ratio = *script_global(PLAYER_INFO_).at(g_settings.SelectedPlayer, 888).at(205).at(26).as<float*>(); //done
										playerData[i].kills = *script_global(PLAYER_INFO_).at(g_settings.SelectedPlayer, 888).at(205).at(28).as<int*>(); //done
										playerData[i].deaths = *script_global(PLAYER_INFO_).at(g_settings.SelectedPlayer, 888).at(205).at(29).as<int*>(); //done
										playerData[i].totalCash = *script_global(PLAYER_INFO_).at(g_settings.SelectedPlayer, 888).at(205).at(56).as<int*>();

										if (true)
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

											playerData[i].lClavicle = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_L_Clavicle));  // links Schl黶selbein
											playerData[i].rClavicle = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerData[i].playerPed, PED::GET_PED_BONE_INDEX(playerData[i].playerPed, SKEL_R_Clavicle)); // rechts Schl黶selbein
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
			else
			{
				playerData[i].IsValid = false;
			}
		}
	}

	void features::updatePlayers()
	{
		for (Player i = 0; i < 32; i++)
		{
			CPlayer& player = g_settings.players[i];

			if (NETWORK::NETWORK_IS_PLAYER_ACTIVE(i))
			{
				strcpy(g_settings.players[i].name, PLAYER::GET_PLAYER_NAME(i));

				player.net_player = g_pointers->m_get_net_game_player(i);

				if (player.is_online)
					continue;

				player.id = i;
				player.is_online = true;

				int iNetworkHandle[13];
				NETWORK::NETWORK_HANDLE_FROM_PLAYER(i, iNetworkHandle, 13);
				bool is_friend = NETWORK::NETWORK_IS_HANDLE_VALID(&iNetworkHandle[0], 13) && NETWORK::NETWORK_IS_FRIEND(&iNetworkHandle[0]);

				if (is_friend)
				{
					player.is_friend = true;

					g_settings.friend_count++;
				}
				else g_settings.player_count++;

				/*char msg[64];

				strcpy(msg, "<C>");
				strcat(msg, player.name);
				strcat(msg, "</C>");
				strcat(msg, " 加入了战局.");

				aboveMap(msg);*/
			}
			else if (player.is_online)
			{
				if (player.is_friend) g_settings.friend_count--;
				else g_settings.player_count--;

				player.is_friend = false;
				player.is_online = false;
			}

			script::get_current()->yield();
		}

		//if (g_settings.window.player) // update selected player only while the player menu is open
		//	g_settings.selected_player = g_settings.players[g_settings.selected_player.id];
	}

	void features::HelpMarker(const char* desc)
	{
		ImGui::TextDisabled("(?)");
		if (ImGui::IsItemHovered())
		{
			ImGui::BeginTooltip();
			ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
			ImGui::TextUnformatted(TRANSLATES(desc));
			ImGui::PopTextWrapPos();
			ImGui::EndTooltip();
		}
	}

	void features::explodeNearbyPeds()
	{
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;
		Ped* peds = new Ped[ArrSize];
		peds[0] = ElementAmount;
		int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);
		for (int i = 0; i < PedFound; i++)
		{
			int OffsetID = i * 2 + 2;
			if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
			{
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(peds[OffsetID], false);
				FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 0, 1000.f, true, false, 0.f, 0);
			}
		}
		delete[] peds;
	}

	void features::writeFlameFlag(uint32_t Flag)
	{
		uint32_t* currentValue = &gta_util::get_local_playerinfo()->m_frame_flags;
		*currentValue = *currentValue |= Flag;
	}

	void features::removeFlameFlag(uint32_t Flag)
	{
		uint32_t* currentValue = &gta_util::get_local_playerinfo()->m_frame_flags;
		*currentValue = *currentValue &= ~(1 << Flag);
	}

	void features::joinType(SessionType session)
	{
		if (session.id == eSessionType::LEAVE_ONLINE)
			*script_global(1574587).at(2).as<int*>() = -1;
		else
			*script_global(1575004).as<int*>() = (int)session.id;

		*script_global(1574587).as<int*>() = 1;
		script::get_current()->yield(200ms);
		*script_global(1574587).as<int*>() = 0;
	}

	void features::getAllWeapon(Player player)
	{
		Ped mubiaoped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
		for (unsigned long hWeapon : weapon::allWeapons) {
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(mubiaoped, hWeapon, 9999, true);
		}
	}

	void features::getFullAmmo(Player player) {
		Ped mubiaoped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
		for (unsigned long hWeapon : weapon::allWeapons) {
			WEAPON::SET_PED_AMMO(mubiaoped, hWeapon, 9999, 1);
		}
	}

	void features::removeAllWeapon(Player player)
	{
		for (unsigned long hWeapon : weapon::allWeapons)
		{
			WEAPON::REMOVE_WEAPON_FROM_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), hWeapon);
		}
	}

	void features::teleportToCoords(Entity e, Vector3 coords)
	{
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, coords.z, 0, 0, 1);
		script::get_current()->yield();
	}

	void features::tpToWaypoint()
	{
		Entity ent = PLAYER::PLAYER_PED_ID();
		if (PED::IS_PED_IN_ANY_VEHICLE(ent, FALSE))
			ent = PED::GET_VEHICLE_PED_IS_IN(ent, FALSE);
		Vector3 coords = util::getBlipMarker();

		if (coords.x != 0 || coords.y != 0)
		{
			bool groundFound = false;
			static float groundCheckHeight[] =
			{ 100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
			for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
			{
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(ent, coords.x, coords.y, groundCheckHeight[i], 0, 0, 1);
				script::get_current()->yield(75ms);
				if (MISC::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0, 0))
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
			features::teleportToCoords(ent, coords);
			HUD::SET_WAYPOINT_OFF();
		}
		else
			g_gui.SendNotification("传送", "没有找到标记点");
	}

	void features::changePlayerModel(Hash hash)
	{
		if (STREAMING::IS_MODEL_IN_CDIMAGE(hash) && STREAMING::IS_MODEL_VALID(hash))
		{
			STREAMING::REQUEST_MODEL(hash);
			while (!STREAMING::HAS_MODEL_LOADED(hash)) script::get_current()->yield();
			PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), hash);
			PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			ENTITY::SET_ENTITY_MAX_HEALTH(PLAYER::PLAYER_PED_ID(), 328);
			ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 328, 1);
		}
	}

	Vehicle features::spawnVehicle(Hash hash)
	{
		static Vehicle lastCar = NULL;

		if (STREAMING::IS_MODEL_VALID(hash))
		{
			while (!STREAMING::HAS_MODEL_LOADED(hash))
			{
				STREAMING::REQUEST_MODEL(hash);
				script::get_current()->yield();
			}
		}
		else
		{
			g_gui.SendNotification("载具", StringToChar("车辆:" + std::to_string(hash) + "模型无效"));
			return 0;
		}

		Ped ped = PLAYER::PLAYER_PED_ID();

		if (g_settings.player.spectating)
		{
			ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_settings.SelectedPlayer);
		}

		auto pos = ENTITY::GET_ENTITY_COORDS(ped, true);

		float forward = 5.f;
		float heading = ENTITY::GET_ENTITY_HEADING(ped);
		float xVector = forward * sin(heading * 3.141592653589793f / 180.f) * -1.f;
		float yVector = forward * cos(heading * 3.141592653589793f / 180.f);
		*(unsigned short*)g_pointers->m_model_spawn_bypass = 0x9090;
		Vehicle vehicle = VEHICLE::CREATE_VEHICLE(hash, pos.x + xVector, pos.y + yVector, pos.z, 0.f, TRUE, FALSE, FALSE);
		*(unsigned short*)g_pointers->m_model_spawn_bypass = 0x0574;
		if (vehicle != lastCar && lastCar != NULL)
		{
			if (g_settings.options["spwancardel"])
			{
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(lastCar, true, true);
				VEHICLE::DELETE_VEHICLE(&lastCar);
			}
		}

		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
		util::requestControlOfEnt(vehicle);

		bool cargod = g_settings.options["spwancargod"];

		if (cargod)
		{
			VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, false);
			VEHICLE::SET_VEHICLE_ENVEFF_SCALE(vehicle, 0.f);
			VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
			VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 0.f);
			ENTITY::SET_ENTITY_INVINCIBLE(vehicle, cargod);
			ENTITY::SET_ENTITY_PROOFS(vehicle, cargod ? cargod : -1, cargod, cargod, cargod, cargod, cargod, cargod, cargod);

			VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_DAMAGE(vehicle, cargod);
			VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(vehicle, cargod);

			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(vehicle, !cargod);
			VEHICLE::SET_VEHICLE_CAN_BREAK(vehicle, !cargod);

			VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE(vehicle, !cargod);
			VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(vehicle, !cargod);
		}

		if (g_settings.options["spwancarmax"])
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
			for (int i = 0; i < 50; i++)
			{
				VEHICLE::SET_VEHICLE_MOD(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
			}
		}
		if (g_settings.options["spwancarin"])
		{
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), vehicle, -1);
		}
		VEHICLE::SET_VEHICLE_ENGINE_ON(vehicle, true, true, true);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "DarkStar");
		/*if (NETWORK::NETWORK_IS_SESSION_STARTED())*/

		DECORATOR::DECOR_SET_INT(vehicle, "MPBitset", 0);
		ENTITY::_SET_ENTITY_SOMETHING(vehicle, TRUE);
		// True means it can be deleted by the engine when switching lobbies etc, false means the script is expected to clean it up.
		auto networkId = NETWORK::VEH_TO_NET(vehicle);
		/*NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(vehicle);*/
		NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);

		lastCar = vehicle;
		return vehicle;
	}

	Vehicle features::spawnVehicle(const char* carname)
	{
		static Vehicle lastCar = NULL;
		Hash hash = MISC::GET_HASH_KEY(carname);
		*(unsigned short*)g_pointers->m_model_spawn_bypass = 0x9090;

		STREAMING::REQUEST_MODEL(hash);

		if (STREAMING::IS_MODEL_VALID(hash))
		{
			while (!STREAMING::HAS_MODEL_LOADED(hash))
			{
				STREAMING::REQUEST_MODEL(hash);
				script::get_current()->yield();
			}
		}
		else
		{
			g_gui.SendNotification("载具", StringToChar("车辆:" + std::to_string(hash) + "模型无效"));
			return 0;
		}

		Ped ped = PLAYER::PLAYER_PED_ID();

		if (g_settings.player.spectating)
		{
			ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_settings.SelectedPlayer);
		}

		auto pos = ENTITY::GET_ENTITY_COORDS(ped, true);

		float forward = 5.f;
		float heading = ENTITY::GET_ENTITY_HEADING(ped);
		float xVector = forward * sin(heading * 3.141592653589793f / 180.f) * -1.f;
		float yVector = forward * cos(heading * 3.141592653589793f / 180.f);

		Vehicle vehicle = VEHICLE::CREATE_VEHICLE(hash, pos.x + xVector, pos.y + yVector, pos.z, 0.f, TRUE, FALSE, FALSE);

		if (vehicle != lastCar && lastCar != NULL)
		{
			if (g_settings.options["spwancardel"])
			{
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(lastCar, true, true);
				VEHICLE::DELETE_VEHICLE(&lastCar);
			}
		}
		*(unsigned short*)g_pointers->m_model_spawn_bypass = 0x0574;

		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
		util::requestControlOfEnt(vehicle);

		bool cargod = g_settings.options["spwancargod"];

		if (cargod)
		{
			VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, false);
			VEHICLE::SET_VEHICLE_ENVEFF_SCALE(vehicle, 0.f);
			VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
			VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 0.f);
			ENTITY::SET_ENTITY_INVINCIBLE(vehicle, cargod);
			ENTITY::SET_ENTITY_PROOFS(vehicle, cargod ? cargod : -1, cargod, cargod, cargod, cargod, cargod, cargod, cargod);

			VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_DAMAGE(vehicle, cargod);
			VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(vehicle, cargod);

			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(vehicle, !cargod);
			VEHICLE::SET_VEHICLE_CAN_BREAK(vehicle, !cargod);

			VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE(vehicle, !cargod);
			VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(vehicle, !cargod);
		}

		if (g_settings.options["spwancarmax"])
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
			for (int i = 0; i < 50; i++)
			{
				VEHICLE::SET_VEHICLE_MOD(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
			}
		}
		if (g_settings.options["spwancarin"])
		{
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), vehicle, -1);
		}
		VEHICLE::SET_VEHICLE_ENGINE_ON(vehicle, true, true, true);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "DarkStar");
		/*if (NETWORK::NETWORK_IS_SESSION_STARTED())*/

		DECORATOR::DECOR_SET_INT(vehicle, "MPBitset", 0);
		ENTITY::_SET_ENTITY_SOMETHING(vehicle, TRUE);
		// True means it can be deleted by the engine when switching lobbies etc, false means the script is expected to clean it up.
		auto networkId = NETWORK::VEH_TO_NET(vehicle);
		/*NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(vehicle);*/
		NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);

		lastCar = vehicle;
		return vehicle;
	}

	void features::run_tick()
	{
		if (g_settings.options["flycar"])
		{
			int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);

			if (veh)
			{
				if (VEHICLE::IS_THIS_MODEL_A_CAR(ENTITY::GET_ENTITY_MODEL(veh)) || VEHICLE::IS_THIS_MODEL_A_BOAT(ENTITY::GET_ENTITY_MODEL(veh)))
				{
					if (PAD::IS_DISABLED_CONTROL_PRESSED(2, INPUT_VEH_FLY_THROTTLE_UP))
					{
						float Speed = ENTITY::GET_ENTITY_SPEED(veh) + 0.4f;
						VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, Speed);
					}

					if (PAD::IS_DISABLED_CONTROL_PRESSED(2, INPUT_VEH_FLY_YAW_LEFT) && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(veh)))
					{
						Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(veh, 2);
						Rot.z = Rot.z + 1.0f;
						ENTITY::SET_ENTITY_ROTATION(veh, Rot.x, Rot.y, Rot.z, 2, 1);
					}

					if (PAD::IS_DISABLED_CONTROL_PRESSED(2, INPUT_VEH_FLY_YAW_RIGHT) && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(veh)))
					{
						Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(veh, 2);
						Rot.z = Rot.z - 1.0f;
						ENTITY::SET_ENTITY_ROTATION(veh, Rot.x, Rot.y, Rot.z, 2, 1);
					}
				}
			}
		}

		if (g_settings.options["caihongzaiju"])
		{
			static rage::RGB primary{ 255, 0, 0 };
			QUEUE_JOB_BEGIN_CLAUSE()
			{
				Vehicle VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				util::requestControlOfEnt(VehID);
				VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(VehID, MISC::GET_RANDOM_INT_IN_RANGE(0, 255), MISC::GET_RANDOM_INT_IN_RANGE(0, 255), MISC::GET_RANDOM_INT_IN_RANGE(0, 255));
				if (primary.r > 0 && primary.b == 0)
				{
					primary.r--;
					primary.g++;
				}
				if (primary.g > 0 && primary.r == 0)
				{
					primary.g--;
					primary.b++;
				}
				if (primary.b > 0 && primary.g == 0)
				{
					primary.r++;
					primary.b--;
				}
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(VehID, primary.r, primary.g, primary.b);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(VehID, primary.r, primary.g, primary.b);

				VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 1);
				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 0, 1);
				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 1, 1);
				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 2, 1);
				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 3, 1);
				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 4, 1);
				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 5, 1);
				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 6, 1);
				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 7, 1);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, primary.r, primary.g, primary.b);
			}QUEUE_JOB_END_CLAUSE
		}

		if (g_settings.options["jiaosudu"])
		{
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			if (IsKeyPressed(VK_NUMPAD9))
			{
				NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
				if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(veh))
				{
					float speed = ENTITY::GET_ENTITY_SPEED(veh);
					speed += speed * (1.f / 100);
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, speed);
				}
			}
			if (IsKeyPressed(VK_NUMPAD3))
			{
				util::requestControlOfEnt(veh);
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 0);
				memory::set_value<float>({ 0x08,0xD30,0x320 }, 0);
			}
		}

		if (g_settings.options["wuxiandanqi"])
		{
			memory::set_value<float>({ 0x08,0xD30,0x320 }, 5);
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
			{
				if (IsKeyPressed(VK_SPACE))
				{
					memory::set_value<float>({ 0x08,0xD30,0x320 }, 0);
				}
			}
		}

		if (g_settings.options["anquandai"])
		{
			PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID(), 0);
			memory::set_value<BYTE>({ 0x8,0x145C }, -55);
		}

		if (g_settings.options["cargod bool"])
		{
			memory::set_value<int>({ 0x08, 0xD30,0x189 }, 1);
		}

		QUEUE_JOB_BEGIN_CLAUSE()
		{
			features::playerSpecate();
		}QUEUE_JOB_END_CLAUSE

			QUEUE_JOB_BEGIN_CLAUSE()
		{
			features::updatePlayers();
		}QUEUE_JOB_END_CLAUSE

			QUEUE_JOB_BEGIN_CLAUSE()
		{
			features::updatePlayerData();
		}QUEUE_JOB_END_CLAUSE

			QUEUE_JOB_BEGIN_CLAUSE()
		{
			features::updateLocalData();
		}QUEUE_JOB_END_CLAUSE
			QUEUE_JOB_BEGIN_CLAUSE()
		{
			g_local_player = gta_util::get_local_ped();
		}QUEUE_JOB_END_CLAUSE

			if (g_settings.options["god bool"])
			{
				ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), 1);
			}
		if (g_settings.options["hgod bool"])
		{
			ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), ENTITY::GET_ENTITY_MAX_HEALTH(PLAYER::PLAYER_PED_ID()), 0);
		}
		if (g_settings.options["Never Wanted bool"])
		{
			PLAYER::SET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID(), 0, 1);
			PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(PLAYER::PLAYER_ID(), 1);
			PLAYER::SET_MAX_WANTED_LEVEL(0);
			//g_settings.translates["wantedlevel"] = 0;
		}
		if (g_settings.options["plwushi bool"])
		{
			PLAYER::SET_POLICE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), 1);
			PLAYER::SET_EVERYONE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), 1);
			PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(PLAYER::PLAYER_ID(), 0);
			PLAYER::SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS(PLAYER::PLAYER_ID(), 1);
		}
		if (g_settings.options["notili bool"])
		{
			memory::set_value<float>({ 0x08, 0x10C8,0xCF4 }, 100);
		}
		if (g_settings.options["nobo"])
		{
			PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), false);
			PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), false);
			PLAYER::GIVE_PLAYER_RAGDOLL_CONTROL(PLAYER::PLAYER_ID(), false);
			PED::SET_PED_RAGDOLL_ON_COLLISION(PLAYER::PLAYER_PED_ID(), false);
		}
		if (g_settings.options["yinshen"])
		{
			ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), 0, 0);
			NETWORK::_NETWORK_SET_ENTITY_INVISIBLE_TO_NETWORK(PLAYER::PLAYER_PED_ID(), 0);
		}
		if (g_settings.options["chaojitiao"])
		{
			MISC::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());
		}
		if (g_settings.options["renjianzhengfa"])
		{
			*script_global(2689156).at(PLAYER::GET_PLAYER_INDEX(), 453).at(209).as<int*>() = 1;
			*script_global(2703656 + 70).as<int*>() = NETWORK::GET_NETWORK_TIME() + 1;
		}
		if (g_settings.options["xianshiwanjia"])
		{
			*script_global(2689156).at(PLAYER::GET_PLAYER_INDEX(), 449).at(212).as<int*>() = 1; //Updated
			*script_global(2703656 + 71).as<int*>() = NETWORK::GET_NETWORK_TIME(); //Updated
		}
		if (g_settings.options["afk"])
		{
			if (*script_global(1644209).at(1165).as<int*>() != -1)
				*script_global(1644209).at(1165).as<int*>() = -1;
			if (*script_global(1644209).at(1149).as<int*>() != -1)
				*script_global(1644209).at(1149).as<int*>() = -1;
		}
		if (g_settings.options["notili"])
		{
			memory::set_value<float>({ 0x08, 0x10C8,0xCF4 }, 100);
		}
		if (g_settings.options["chuanqiang"])
		{
			memory::set_value<float>({ 0x8,0x30,0x10,0x20,0x70,0x0,0x2C }, -1);
		}
		if (g_settings.options["baozhazidan"])
		{
			QUEUE_JOB_BEGIN_CLAUSE()
			{
				features::writeFlameFlag(eFrameFlagExplosiveAmmo);
			}QUEUE_JOB_END_CLAUSE
		}
		if (g_settings.options["wuxianzidan"])
		{
			QUEUE_JOB_BEGIN_CLAUSE()
			{
				WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), 1);
			}QUEUE_JOB_END_CLAUSE
		}
		if (g_settings.options["miaosha"])
		{
			QUEUE_JOB_BEGIN_CLAUSE()
			{
				if (GetAsyncKeyState(VK_LBUTTON) || PAD::IS_CONTROL_PRESSED(2, INPUT_ATTACK))
				{
					Entity ent;
					if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &ent))
					{
						util::requestControlOfEnt(ent);
						PED::APPLY_DAMAGE_TO_PED(ent, 9999999, false, 1);
					}
				}
			}QUEUE_JOB_END_CLAUSE
		}
		if (g_settings.options["kuaishe"])
		{
			QUEUE_JOB_BEGIN_CLAUSE()
			{
				Player playerPed = PLAYER::PLAYER_PED_ID();
				if (!PED::IS_PED_IN_ANY_VEHICLE(playerPed, 1)) {
					PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_ID(), 1);
					Vector3 gameplayCam = CAM::GET_FINAL_RENDERED_CAM_COORD();
					Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
					Vector3 gameplayCamDirection = util::wRotationToDirection(gameplayCamRot);
					Vector3 startCoords = util::waddVector(gameplayCam, (util::wmultiplyVector(gameplayCamDirection, 1.0f)));
					Vector3 endCoords = util::waddVector(startCoords, util::wmultiplyVector(gameplayCamDirection, 500.0f));
					Hash weaponhash;
					WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &weaponhash, 1);
					if (PAD::IS_CONTROL_PRESSED(2, 208) || (GetKeyState(VK_LBUTTON) & 0x8000)) {
						PED::SET_PED_SHOOTS_AT_COORD(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::GET_PLAYER_INDEX()), endCoords.x, endCoords.y, endCoords.z, true);
						MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 50, 1, weaponhash, playerPed, 1, 1, 0xbf800000);
					}
				}
			}QUEUE_JOB_END_CLAUSE
		}
		if (g_settings.options["superrun"])
		{
			QUEUE_JOB_BEGIN_CLAUSE()
			{
				if (GetAsyncKeyState(0x57))
				{
					Ped ped = PLAYER::PLAYER_PED_ID();
					Vector3 offset = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(ped, 0, 0.6, 0);
					ENTITY::APPLY_FORCE_TO_ENTITY(ped, 1, 0.0f, 1.3, 0, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
					PLAYER::SET_PLAYER_SPRINT(PLAYER::PLAYER_ID(), 1);
					PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(PLAYER::PLAYER_ID(), 1.3);
				}
			}QUEUE_JOB_END_CLAUSE
		}
		if (g_settings.options["ziyoucam"])
		{
			auto ped = PLAYER::PLAYER_PED_ID();
			if (PED::IS_PED_IN_ANY_VEHICLE(ped, 0))
			{
				ped = PED::GET_VEHICLE_PED_IS_USING(ped);
			}
			ENTITY::SET_ENTITY_VISIBLE(ped, 0, 0);
			NETWORK::_NETWORK_SET_ENTITY_INVISIBLE_TO_NETWORK(ped, 0);

			auto startDist = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
			auto pos = ENTITY::GET_ENTITY_COORDS(ped, false);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(ped, pos.x, pos.y, pos.z, false, false, false);
			if (GetAsyncKeyState(0x57) || PAD::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269)) {
				//startDist +=0.3f;//错误
				Vector3 coords = util::add(&ENTITY::GET_ENTITY_COORDS(ped, 1), &util::multiply(&util::rottt_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), (float)startDist));

				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(ped, coords.x, coords.y, coords.z, false, false, false);
			}
		}
		if (g_settings.options["chaorentiao"])
		{
			QUEUE_JOB_BEGIN_CLAUSE()
			{
				if (GetAsyncKeyState(VK_SPACE))
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), 1, 1, 0, 10, 0, 0, 0, 1, true, true, true, true, true);
				}
				Hash hash = MISC::GET_HASH_KEY("GADGET_PARACHUTE");
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), hash, 1, 1);

				if (ENTITY::IS_ENTITY_IN_AIR(PLAYER::PLAYER_PED_ID()) && !PED::IS_PED_RAGDOLL(PLAYER::PLAYER_PED_ID()))
				{
					if (GetAsyncKeyState(0x57)) // W key
					{
						util::applyForceToEntity(PLAYER::PLAYER_PED_ID(), 3, 0, 0);
					}

					if (GetAsyncKeyState(0x53)) // S key
					{
						util::applyForceToEntity(PLAYER::PLAYER_PED_ID(), 3, 6, 0);
					}
				}
			}QUEUE_JOB_END_CLAUSE
		}

		if (g_settings.options["qzzou"])
		{
			QUEUE_JOB_BEGIN_CLAUSE()
			{
				Ped playerPed = PLAYER::PLAYER_PED_ID();

				char* prop = "p_oil_slick_01";
				Hash ObjHash = MISC::GET_HASH_KEY(prop);
				Vector3 PlayerCoord = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
				Object WalkOnAir = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(PlayerCoord.x, PlayerCoord.y, PlayerCoord.z, 100, ObjHash, 1, 0, 1);
				float zPlane;

				if ((!ENTITY::DOES_ENTITY_EXIST(WalkOnAir)) && (g_settings.options["qzzou"]))
				{
					Object WalkOnAir = util::createObject(prop, PlayerCoord);
					ENTITY::FREEZE_ENTITY_POSITION(WalkOnAir, 1);
					ENTITY::SET_ENTITY_VISIBLE(WalkOnAir, 0, 0);
				}
				else if ((ENTITY::DOES_ENTITY_EXIST(WalkOnAir)) && (g_settings.options["qzzou"]))
				{
					float Normal = 1.0225;
					float Down = 1.60;
					float Up = 0.40;
					float Vehicular = 50.0;

					if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
					{
						zPlane = PlayerCoord.z - Vehicular;
					}
					else if (GetAsyncKeyState(0x5A) || (PAD::IS_DISABLED_CONTROL_PRESSED(2, INPUT_SCRIPT_LS)))      //Down Z and L3
					{
						zPlane = PlayerCoord.z - Down;
					}
					else if (GetAsyncKeyState(0x51) || (PAD::IS_DISABLED_CONTROL_PRESSED(2, INPUT_SCRIPT_RS)))      //Up Q and R3
					{
						zPlane = PlayerCoord.z - Up;
					}
					else
					{
						zPlane = PlayerCoord.z - Normal;
					}

					Vector3 Coord = util::CombineVector(PlayerCoord.x, PlayerCoord.y, zPlane);
					ENTITY::SET_ENTITY_COORDS(WalkOnAir, Coord.x, Coord.y, Coord.z, 1, 0, 0, 1);
				}
			}QUEUE_JOB_END_CLAUSE
		}
	}

	void features::script_func()
	{
		while (true)
		{
			TRY_CLAUSE
			{
				run_tick();
			}
				EXCEPT_CLAUSE
				script::get_current()->yield();
		}
	}
}