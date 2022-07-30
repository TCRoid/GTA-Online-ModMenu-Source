#pragma once
#include "common.h"
#include "player.h"
#include "natives.h"
#include "memory.h"
#include "structs.h"
#include "pointers.h"

struct tLocalData {
	CPedFactory* factory{};
	CWeapon* currWepaon{};
	rage::vector3 visualPos{};
	bool IsInVehicle{};
	Vehicle vehicle;
	bool alive{};
	Player localId{};
	Ped localPed{};
	float health{};
	float maxhealth{};
	int32_t teamId{};
	int32_t connectedPlayers{};
};

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

struct tNearbyPeds {
	Ped ped;
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

namespace features {

	///////////////// data /////////////////////
	inline tLocalData localData;
	inline tPlayerData playerData[32];
	inline bool isTeamGameModeRunning{};
	inline std::vector<tPlayerData> nearbyPeds;
	inline rage::joaat_t lastSelectedVehicleHash{ rage::joaat("FURIA") };


	////////
	inline bool bProtectionShowNotifications{ true };
	inline bool bProtectionShowAsCheraxUser{ true };

	inline bool bProtectionRockstarDev{ true };
	inline bool bProtectionReportBlocker{ true };

	inline bool bProtectionVoteKick{ true };
	inline bool bProtectionWeather{ true };
	inline bool bProtectionClock{ true };
	inline bool bProtectionFreeze{ true };
	inline bool bProtectionRequestControl{ true };
	inline bool bProtectionExplosion{ false };
	inline bool bProtectionFire{ false };
	inline bool bProtectionPTFX{ false };
	
	inline bool bProtectionAntiAttach{ false };

	inline bool bProtectionNonHostKick{ true };
	inline bool bProtectionTeleport{ true };

	////////
	inline bool drawHeader = true;
	inline bool drawCurrentTime = true;
	inline bool drawFPS = true;
	inline bool drawWatermark = true;

	inline bool showSessionHost = false;
	inline bool showPlayerCount = false;

	inline int ESPPedRange = 100;
	inline int ESPRange = 2500;
	inline bool ESPonEnemies = true;
	inline bool ESPonTeam = true;
	inline bool ESPonFriends = true;
	inline bool ESPonNPCs = true;
	inline bool ESPonCops = true;
	inline bool ESPonYou = false;

	inline bool ESP2DBoxes{};
	inline bool ESP3DBoxes{};
	inline bool ESPSkeleton{};
	inline bool ESPRotation{};
	inline bool ESPTracers{};
	inline bool ESPHealthbar{};
	inline bool ESPArmorbar{};
	inline bool ESPName{};
	inline bool ESPDistance{};
	////////
	
	///////////////// main script:: /////////////////////
	void scriptInit();
	void script_func();
	void run_tick();

	///////////////// main functions:: /////////////////////
	void updateLocalData();
	void updatePlayerData();

	void selfOptins();
	void weaponOptions();
	void vehicleOptions();
	void teleportOptions();
	void worldOptions();
	void miscOptions();
	void ProtectionCallback();
	void ProtectionsReset();
	void antiAttach();
	///////////////// functions:: /////////////////////
	inline int maxSafeMoney{};
	inline int currentSafeMoney{};
	inline bool loopNightclubCash{};
	void NightClubdata();
	////////
	void stealthMoney();
	////////
	inline bool bvehicleDespawnBypass{ true };
	inline bool bSpawnWithMaxUpgrades{};
	inline bool bSpawnWithEngineOn{};
	inline bool bSpawnInVehicle{};
	inline bool bSpawnWithCarGodMode{};
	inline bool bSpawnWithEffect{};
	inline bool bSpawnCleanVehicle{};
	inline bool bSpawnDeleteOld{};
	inline bool bSpawnClearArea{};
	inline bool bPreviewVehicle{ true };
	void vehicleDespawnBypass();
	Vehicle spawnVehicle(rage::joaat_t hash);

	void att_ped_to_veh(Hash model, Vehicle vehicle, const Vector3& offset, const Vector3& rotation, bool invis = false, bool piggyback = false);
	void att_obj_to_veh(Hash model, Vehicle vehicle, float X, float Y, float Z, float Pitch, float Roll, float Yaw, bool invis, int boneIndex = -1, bool dynamic = false, bool collisionEnabled = false, bool destroyVar = true);
	void att_veh_to_veh(Hash model, Vehicle vehicle, int primColour, int secColour, float X, float Y, float Z, float Pitch, float Roll, float Yaw, bool invis, int boneIndex = -1, bool collisionEnabled = false);

	inline bool	bFlashVehicle{};
	inline bool	bRainbowVehicle{};
	inline bool	bRainbowNeonKits{};
	inline bool	bFlashNeonKits{};
	inline bool	bRainbowTyresmoke{};
	inline bool	bFlashTyresmoke{};
	inline bool	bFlashHeadlights{};
	inline bool	bFlashWheels{};
	inline bool	bFlashLivery{};
	inline bool	bFlashParts{};

	inline bool	bEngineAlwaysOn{};
	inline bool	bAutoRepairCar{};
	inline bool	bPolicemode{};
	inline bool	bGroupUp{};
	inline bool	bSticktoground{};
	inline bool bDriveOnWater{};
	inline bool bHornBoost{};
	inline bool bVehicleInvisible{};
	inline bool bVehicleBulletProoftyres{};
	inline bool bVehicleGodMode{};

	inline int fFlashDelay{ 400 };
	inline int fSmoothDelay{ 65 };
	void hornBoost(Vehicle veh);
	void VehiclePTFX(Vehicle veh);
	void CarGodmode(Vehicle veh);
	void bulletProofTyres(Vehicle veh);
	void setCarInvisible();
	void DriveOnWater(Vehicle veh);
	void randomParts(Vehicle veh);
	void randomLivery(Vehicle veh);
	void flashWheels(Vehicle veh);
	void flashvehicle(Vehicle veh);
	void rainbowcar(Vehicle veh);
	void rainbowNeonKits(Vehicle veh);
	void FlashNeonKits(Vehicle veh);
	void rainbowTyresmoke(Vehicle veh);
	void flashTyresmoke(Vehicle veh);
	void flashHeadlights(Vehicle veh);
	void engineAlwayson(Vehicle veh);
	void stick_to_ground(Vehicle veh);
	void groupup(Vehicle veh);
	void repairCar(bool loop);
	void policemode();
	void autoRepair();
	void instantbreak();
	void flipup();

	////////////////////////////////

	void teleport_to_coords(Entity e, Vector3 coords);
	Vector3 get_blip_marker();
	Vector3 get_blip_objective2();
	Vector3 get_blip_vehicle2();
	CBlip* get_blip_objective();
	void teleport_to_objective();
	CBlip* get_blip_vehicle();
	void teleport_to_personal_vehicle();
	inline bool bAutoTeleport{ true };
	inline bool bAutoRestoreOriginalIpls{ true };
	void autoTpWaypoint();

	////////////////////////////////
	inline bool bSelfgodMode{};
	inline bool bSelfNoRagdoll{};
	inline bool bSelfInvisible{};
	inline bool bSelfSeatbelt{};
	inline bool bSelfStamina{};
	inline bool bSelfRunMultiplier{};
	inline bool bSelfSwimMultiplier{};
	inline bool bSelfSuperJump{};
	inline bool bSelfNeverWanted{};
	inline bool bSelfAlwaysWanted{};
	inline bool bSelfTinyPlayer{};
	inline bool bSelfFireBreath{};
	inline bool bSelfOffRadar{};
	inline bool bSelfInstantBST{};
	inline bool bSelfNoClip{};
	
	inline float fSelfRunMultiplier{ 2.f};
	inline float fSelfSwimMultiplier{ 2.f};
	inline float fSelfHealthRechargeMultiplier{ 1.f };
	inline int iSelfFakeWantedLevel{};

	inline std::string PTFXDisplayName{ "None" };
	inline std::string PTFXName{ "None" };
	inline std::string PTFXCall{ "None" };

	inline std::string VehiclePTFXDisplayName{ "None" };
	inline std::string VehiclePTFXName{ "None" };
	inline std::string VehiclePTFXCall{ "None" };

	void SelfGodMode();
	void SelfNoRagdoll();
	void SelfInivisible();
	void SelfSeatbelt();
	void SelfStamina();
	void SelfFastRun();
	void SelfFastSwim();
	void SelfNeverWanted();
	void SelfAlwaysWanted();
	void SelfFakeWantedLevel();
	void SelfHealthRechargeMultiplier();
	void SelfTinyPlayer();
	void SelfPTFX();
	void SelfOffRadar();
	void SelfInstantBST();
	void SelfNoClip();
	///////////	///////////	///////////
	inline int bMiscRockstarID{};
	inline char bMiscUsername[32];
	inline bool bMiscJoinRid{};

	inline bool bMiscsSetAllRandomPedsFlee{};
	inline bool bMiscAutoTeams{ true };
	inline bool bMiscAutoFriends{ true };

	inline bool bMiscUpgradeNearbyVehicles{};
	inline bool bMiscExplodeNearbyVehicles{};
	inline bool bMiscDeleteNearbyVehicles{};

	inline bool bMiscDestroyPhone{};
	inline bool bMiscDisableHud{};
	inline bool bMiscCrosshair{};

	void MiscDisableHud();
	void MiscSetAllPedsFlee();
	void setSpoofName(const std::string& name);
	void nearbyVehicleOptions();
	void MiscDisablePhone();
	void MiscSpawnBodyGuard();

	///
	inline bool bWeaponDeadlyExplosions{ true };
	inline bool bWeaponExplosiveAmmo{};
	inline bool bWeaponExplosiveMelee{};
	inline bool bWeaponFireAmmo{};
	inline bool bWeaponFireWorkImpact{}; 
	inline bool bWeaponGrenadeImpact{};
	inline bool bWeaponRocketImpact{};
	inline bool bWeaponTankShellImpact{};
	inline bool bWeaponMolotovImpact{};
	inline bool bWeaponFlareImpact{};
	inline bool bWeaponSmokeImpact{};
	inline bool bWeaponFlameImpact{};

	inline bool bWeaponMoneyGun{};
	inline bool bWeaponTeleportGun{};
	inline bool bWeaponGravityGun{};
	inline bool bWeaponDeleteGun{};
	inline bool bWeaponVehicleGun{};
	inline bool bWeaponBlockGun{};

	inline bool bWeaponRapidFire{};
	inline bool bWeaponInfinityAmmo{};

	void WeaponGravityGun();
	void WeaponDeleteGun();
	void WeaponVehicleGun();
	void frameFlags(); // self & weapon
	void WeaponImpacts();
	void WeaponRapidFire();
	void WeaponInfinityAmmo();

	inline bool bWeaponOneShotKill{};
	inline bool bWeaponRubberBullets{};
	inline bool bMeleeOneHitKill{};
	inline bool bMeleeMegaKnockback{};
	inline bool bWeaponInstantReload{};

	inline bool bWeaponEnableCustomReload{};
	inline float fWeaponCustomReload{ 5.f };

	inline bool bWeaponEnableCustomBulletDamage{};
	inline float fWeaponCustomBulletDamage{ 50.f };

	inline bool bWeaponForceOnPed{};
	inline float fWeaponForceOnPed{ 3.f };

	inline bool bWeaponForceOnVehicle{};
	inline float fWeaponForceOnVehicle{ 3.f };

	inline bool bWeaponForceOnHeli{};
	inline float fWeaponForceOnHeli{ 3.f };

	inline bool bWeaponNoRecoil{};
	inline bool bWeaponEnableCustomRecoil{};
	inline float fWeaponCustomRecoil{ 3.f };

	inline bool bWeaponNoSpread{};
	inline bool bWeaponEnableCustomSpread{};
	inline float fWeaponCustomSpread{ 3.f };

	inline bool bWeaponUnlimitedRange{};
	inline bool bWeaponEnableCustomRange{};
	inline float fWeaponCustomRange{ 200.f };

	void WeaponMods();

	inline rage::vector2 AimbotMoveMouse{};
	inline Vector3 AimbotPos{};

	inline float fAimerMaxRange{ 200.f };
	inline bool bAimerEnableSmoothAim;
	inline float fAimerSmoothSpeed{ 10 };
	inline float fAimerMaxFov{ 200.f };

	inline bool bWeaponAimbot{};
	inline bool bWeaponTriggerbot{};

	inline bool bAimbotAutoShoot{};
	inline bool bAimbotShootAtPlayers{};
	inline bool bAimbotShootAtAlly{};
	inline bool bAimbotShootAtNPCs{};
	inline bool bAimbotShootAtCops{};
	inline bool bAimbotShootAtEnemies{};
	inline bool bAimbotpSilentAim{};
	inline int bAimBotBone{ SKEL_Head };

	void WeaponAimer();
	///////////////////////////

	inline bool sync_time_with_network{ true };
	inline bool sync_weather_with_network{ true };
	inline bool freezeTime{ false };
	inline int32_t timeCycleModifer{};

	inline int32_t clock_hours{};
	inline int32_t clock_minutes{};
	inline int32_t clock_seconds{};

	inline int32_t clock_hours_freeze{};
	inline int32_t clock_minutes_freeze{};
	inline int32_t clock_seconds_freeze{};

	///////////////// helper functions:: /////////////////////
	bool isFriend(Player index);
	void RequestControlOfid(Entity netid);
	void RequestControlOfEnt(Entity entity);
	void defuseEvent(eRockstarEvent e, bool b);
	inline std::set<Ped> lastSeenNearbyPeds;
	void update_nearby_peds(Ped playerPed, int count);
	void updatePeds();
	void notifyAboveMap(std::string msg, BOOL blink);
	Vector3 rot_to_direction(Vector3* rot);
	double DegreeToRadian(double n);
	Vector3 RotationToDirection(Vector3 rot);
	Vector3 multiplyVector(Vector3 vector, float inc);
	Vector3 addVector(Vector3 vector, Vector3 vector2);
	Vector3 subVector(Vector3 vector, Vector3 vector2);
	void CalcAngle(float* src, float* dst, float* angles);
	Vector3 calcAngles(Vector3 src, Vector3 dst);
	float degToRad(float degs);
	float get_distance(Vector3* pointA, Vector3* pointB);
	float get_magnitude(Vector3 vec3);
	std::string currentTime();

	uintptr_t	get_address_of_item_in_pool(MemoryPool* pool, int handle);

	template <typename rT>
	rT* handle_to_ptr(int handle)
	{
		uintptr_t	ptr = get_address_of_item_in_pool(*g_pointers->m_entityPool, handle);
		if (ptr == 0)
			return nullptr;
		return *reinterpret_cast<rT**>(ptr + 8);
	}
}	