#pragma once

#include "common.hpp"
#include "natives.hpp"
#include "imgui.h"
#include "gta\replay.hpp"
#include "gta\ped_factory.hpp"

inline int playerRID[32];

struct tPlayerData {
	BOOL IsConnected{};
	BOOL IsValid{};
	BOOL IsHost{};
	BOOL IsScriptHost{};
	BOOL IsFriend{};
	BOOL IsModder{};
	BOOL IsTeam{};
	BOOL IsNPC{};
	BOOL IsCop{};

	CNetGamePlayer* netPlayer{};
	rage::netPlayerData* netData{};
	CPed* cPed{};

	rage::netAddress online_ip{};
	uint16_t online_port{};
	uint64_t rockstar_id{};
	uint32_t host_token{};

	std::string playerName{};
	Player playerId{ -1 };
	Ped playerPed{};

	BOOL alive{};
	BOOL godmode{};
	BOOL IsInVehicle{};
	BOOL IsInInterrior{};
	float health{};
	float maxHealth{};
	float armour{};
	float maxArmour{};
	int32_t teamId{};
	int32_t wantedLevel{};
	int64_t wallet{};
	int64_t level{};
	float ratio{};
	int32_t kills{};
	int32_t deaths{};
	int64_t totalCash{};

	float speed{};
	float distance{};
	float heading{};
	rage::vector3 position{};


	Vector3 head{};
	Vector3 neck{};
	Vector3 stomach{};
	Vector3 pelvis{};
	Vector3 lThigh{};
	Vector3 rThigh{};
	Vector3 lCalf{};
	Vector3 rCalf{};
	Vector3 lFoot{};
	Vector3 rFoot{};
	Vector3 lClavicle{};
	Vector3 rClavicle{};
	Vector3 lUpperArm{};
	Vector3 rUpperArm{};
	Vector3 lForeArm{};
	Vector3 rForeArm{};
	Vector3 lHand{};
	Vector3 rHand{};
};

inline tPlayerData PlayerData[32];

class base_tab
{
public:
	static void render_base_tab();
};
