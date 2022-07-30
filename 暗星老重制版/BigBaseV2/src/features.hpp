#pragma once
#include "common.hpp"
#include "CWeaponInfo.hpp"
#include "CPed.hpp"
enum class eSessionType
{
	JOIN_PUBLIC,
	NEW_PUBLIC,
	CLOSED_CREW,
	CREW,
	CLOSED_FRIENDS = 6,
	FIND_FRIEND = 9,
	SOLO,
	INVITE_ONLY,
	JOIN_CREW,
	LEAVE_ONLINE = -1
};

struct SessionType {
	eSessionType id;
	const char name[22];
};

const SessionType sessions[] = {
	{ eSessionType::JOIN_PUBLIC,	"加入公开战局" },
	{ eSessionType::NEW_PUBLIC,		"创建公开战局" },
	{ eSessionType::CLOSED_CREW,	"创建帮会战局" },
	{ eSessionType::CREW,			"寻找帮会战局" },
	{ eSessionType::CLOSED_FRIENDS,	"创建好友战局" },
	{ eSessionType::FIND_FRIEND,	"寻找好友战局" },
	{ eSessionType::SOLO,			"创建单人战局" },
	{ eSessionType::INVITE_ONLY,	"创建邀请战局" },
	{ eSessionType::JOIN_CREW,		"加入帮会战局" },
	{ eSessionType::LEAVE_ONLINE,	"离开线上模式" }
};
namespace big
{
	struct tLocalData
	{
		CPedFactory* factory{};
		CWeaponInfo* currWeapon{};
		rage::fvector3 visualPos{};
		bool IsInVehicle{};
		Vehicle vehicle;
		bool alive{};
		Player localId{};
		Ped localPed{};
		float health{};
		float maxhealth{};
		int32_t teamId{};
		int32_t connectedPlayers{};
		bool IsHost{};
		bool IsScriptHost{};
	};

	struct tPlayerData
	{
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
		CPed* cped{};

		rage::netAddress online_ip{};
		uint16_t online_port{};
		uint64_t rockstar_id{};

		std::string playerName{};
		Player playerId{ -1 };
		Ped playerPed{};

		BOOL alive{};
		BOOL godmode{};
		BOOL IsInVehicle{};
		BOOL IsInInterrior{};
		int health{};
		int maxHealth{};
		float armour{};
		int maxArmour{};
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
		rage::fvector3 position{};

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

	struct tNearbyPeds {
		Ped ped;
		float distance{};
		float heading{};
		Vector3 position{};

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
}
namespace big::features
{
	void run_tick();
	void script_func();
	void explodeNearbyPeds();

	void teleportToObjective();
	void joinType(SessionType session);
	void HelpMarker(const char* desc);
	void writeFlameFlag(uint32_t Flag);
	void removeFlameFlag(uint32_t Flag);
	void getAllWeapon(Player player);
	void getFullAmmo(Player player);
	void removeAllWeapon(Player player);
	void updatePlayers();//更新玩家
	void updateLocalData();
	void DrawLine(ImVec2 a, ImVec2 b);

	void updatePlayerData();
	bool isFriend(Player index);
	void playerSpecate();
	void mapAndLog(const char* log);
	void aboveMap(const char* text);
	void killNearbyPeds();
	void deleteNearbyPeds();
	void pedStpme();
	void explodeNearbyVehicles();
	void deleteNearbyVehicles();
	void upgradeNearbyVehicles();
	void exitCar();
	void turntableInit();

	Vehicle spawnVehicle(const char* carname);
	Vehicle spawnVehicle(Hash hash);
	void tpToWaypoint();
	void teleportToCoords(Entity e, Vector3 coords);
	void attachEntity(char* str, Player player);
	void attachEntity(Entity ent);
	void changePlayerModel(Hash hash);
	void getTurntable(int value);
	ImVec2 WorldToScreen(Vector3 pos);
	void DoScenario(char* anim, char* animid);
	void tpToVector3(Vector3 coords);
	void updateNearbyPeds(Ped playerPed, int count);
	void updatePeds();

	void playerModelCrashAll();

	static int wantervalue = 0;
	static float runSpeed = 1.f;
	static float swimSpeed = 1.f;
	static float sneakSpeed = 1.f;

	extern DWORD64 turntablePoint;

	inline tLocalData localData;
	inline tPlayerData playerData[32];

	inline std::vector<tPlayerData> nearbyPeds;
	inline std::set<Ped> lastSeenNearbyPeds;

	inline int bMiscRockstarID{};
	inline bool bMiscJoinRid{};
}