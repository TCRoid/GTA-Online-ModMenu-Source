#pragma once

namespace Features {
	
	void UpdateLoop();
	
	extern int TimePD;
	extern int TimePD1;
	extern int TimePD2;
	extern int TimePD3;
	extern int TimePD4;
	extern int TimePD5;
	extern int TimePD6;
	extern int TimePD7;
	extern int TimePD8;
	extern int TimePD9;
	extern int TimePD10;
	extern int TimePD11;
	extern int TimePD12;
	extern int TimePD13;
	extern int TimePD14;
	extern int TimePD15;
	extern int TimePD16;
	extern int TimePD17;
	extern int TimePD18;
	extern int TimePD19;

	extern int carCounter;
	extern int things[999];
	extern char* selectedthing;

	extern bool DIGun;
	void digun(bool toggle);

	extern bool infammo;
	void Infammo(bool toggle);

	extern bool playerinvisibility2;
	void Invisibility2(bool toggle);

	extern bool teleportgun;
	void Teleportgun(bool toggle);

	extern bool osk;
	void OSK(bool toggle);

	extern bool Superjump;
	void superjump(bool toggle);

	extern bool GodMode;
	void godmode(bool toggle);

	void Teleport_to_marker();

	extern bool neverwanted;
	void NeverWanted(bool toggle);

	extern bool selfdrop;
	void Selfdrop(bool toggle, int delay, Hash item, int value);

	extern bool playerinvisibility;
	void Invisibility(bool toggle);

	extern bool moneygun;
	void MoneyGun(bool t);

	extern int playerWantedLevel;
	void ChangeWanted(int level);

	extern bool antifog;
	void Antifog(bool t);

	void ceoban(int player);

	void ceokick(int player);

	void kick(int player);

	void sp_kick(int player);

	void forceMission(int player);

	void infiniteLoading(int player);

	void sound(int player);

	void remoteTP(int player, int TPid);

	void remoteBan(int player);

	void inviteSpam(int player, int a);
	void inviteSpamEvery(int a);
	extern int inviteSS;
	extern bool iLoopBoolall;
	extern bool iLoopBool[35];
	void inviteLoop(Player p, int a);
	void inviteLoopAll(bool t, int a);

	void remoteCrash(Player p);

	//PROTEX
	extern bool antitse;
	void antiTSE(bool t);

	extern bool antiweatherTime;
	void antiWeatherTime(bool t);

	extern bool antiEvery;
	void AntiEverything(bool t);

	extern bool antiControl;
	void AntiControl(bool t);

	extern bool antiPickup;
	void AntiPickup(bool t);

	extern bool antiWeapon;
	void AntiWeapon(bool t);

	extern bool antiExplosion;
	void AntiExplosion(bool t);

	extern bool antiStars;
	void AntiStars(bool t);

	extern bool antiReport;
	void AntiReport(bool t);

	extern bool antiKick;
	void AntiKick(bool t);

	extern bool antiFreeze;
	void AntiFreeze(bool t);

	extern bool antiSound;
	void AntiSound(bool t);

	extern bool antiStat;
	void AntiStat(bool t);

	extern bool Features::antiPickup;
	void Features::AntiPickup(bool t);

	extern bool antiPtfx;
	void AntiPtfx(bool t);

	extern bool antiAttachment;
	void AntiAttachment(bool t);
	//END PROTEX

	//BYPASS REQUIRED
	//void blamePlayer(int selectedPed, char* Name);

	extern bool spawnincar;
	extern bool spawnmaxed;
	extern int pricustomred;
	extern int pricustomgreen;
	extern int pricustomblue;
	extern int seccustomred;
	extern int seccustomgreen;
	extern int seccustomblue;
	extern bool setcustompricolour;
	extern bool setcustomseccolour;
	extern bool spawnwithblip;
	extern void spawn_vehicle(std::string vehicle);

	extern bool drunk;
	void Drunk(bool t);

	extern bool unlimitedorbitalcannon;
	void UnlimitedORbitalCannon(bool t);

	extern bool orbool;
	void OffRadar(bool toggle);

	void setName(std::string name);

	extern bool fastRun;
	void runFast(bool toggle);

	extern bool Rainb;
	void Rainbow(bool toggle);

	extern bool Rneon;
	void RainbowNeon(bool toggle);

	extern bool Rcolor;
	void RainbowColor(bool toggle);

	extern int Levels[8000];
	void SetRank(int rpvalue);

	extern int drivespeed;
	extern int drivestyle;

	void flipup();

	//void BypassOnlineVehicleKick();

	extern bool moneydrop[35];
	void Moneydrop(Player player);

	extern int MoneyItem;

	extern bool screenfx;
	void ScreenFX(bool toggle, char *effect);

	void trapcage(Ped ped);

	extern bool betiny;
	void TinyPlayer(bool toggle);

	extern bool moongrav;
	void MoonGrav(bool t);

	extern bool Gravity;
	void GravityGun(bool toggle);

	extern bool selftenkped;
	void selfTenKPedMoney(bool toggle);

	extern bool explogun;
	void ExploGun(bool t);

	extern bool freezed[35];
	void Freezer(Player target);

	extern bool playernoragdoll;
	void NoRagdoll(bool toggle);

	extern bool RPLoop;
	extern int RPLoopDelay;
	void rpLoop();

	Vehicle SpawnVehicle(char* modelg, Vector3 coords, bool tpinto = 0, float heading = 0.0f);

	Object SpawnObject(char* name, Vector3 coords);
	void AttachThingToThing(Any p0, Any p1, float x = 0, float y = 0, float z = 0, float rx = 0, float ry = 0, float rz = 0);

	extern bool boostbool;
	void carboost(bool toggle);

	extern Vector3 location;
	extern bool blackhole;
	extern int holePED;
	void hole(bool toggle);

	extern bool cargodmodebool;
	void cargodmode();

	void maxvehicle1();

	void maxvehicle2(Player playa);

	extern bool vehjump;
	void VehJump(bool toggle);

	extern bool dowbool;
	void DriveOnWater(bool toggle);

	void cargodmode2(Player playa);

	void AirStrike1(Player playa);

	void AirStrike2(Vector3 coords);

	extern bool tpbool;
	void tpHotkey(bool t, int key);

	extern bool rapidfirer;
	void rapidmaker(bool t);

	void kicknibba(Player playa);

	void sendMessage(char* pic, int icon, char* sender, char* subtitle, char* clantag);

	extern bool agbool;
	void airstrikeGun(bool t);

	extern float locX;
	extern float locY;
	extern float locZ;
	extern bool blockX;
	extern bool blockY;
	extern bool blockZ;
	void Attachment(char* p0);
	void moveStuff(float ox, float oy, float oz);
	void updateCoords();

	int spawnStuff(char* name, Vector3 coords);

	void attachCar(Player pimmel);

	extern int handy;
	void setPhone(int index);

	extern bool talkbool1;
	void talkStuff1(bool t);

	extern bool talkbool2;
	void talkStuff2(bool t);

	void vehControl(Player p);

	extern bool carinvisbool;
	void carinvis(bool t);

	extern bool dumpBool;
	extern bool msgBool;
	extern int evIndex;
	uint64_t dumpEvent(bool t);
	void logEvent(bool msg);
	//extern int i2_index;
	//uint64_t i2_arg(int p);
	//void testEvents(int index);

	void sendToRoller(Player p);

	void chesesGlitch(Player penis);

	extern bool otr2bool;
	void otr2(bool t);

	extern bool fakedropbool;
	void fakedrop(bool t, Player player);

	extern bool thunderbool;
	void thunder(bool t);

	extern bool nightvisionbool;
	void nightvision(bool t);

	extern bool SEbool;
	int SE();

	extern char* friendTag[33];
	bool isFriend(Player p);

	void bounty(Player p, int a);

	extern int attachobj[100];
	extern int nuattach;
	void attachobjects2(char* object);

	extern int attachobj3[100];
	extern int nuattach3;
	void attachobjects3(char* object);

	//void RequestControlOfid(Entity netid);

	void semigod();

	void TSE(int input, int player);
	void TSEall(int input);

	extern bool mobRadio;
	void mobileRadio(bool t);

	bool devMode();

	void changeClothes(char* family, int model, int texture);

	void beachFire(Player p);

	void beachFireEmUp();

	extern bool spectate[35];
	void specter(Player target);

	extern char* enemyWeapon;
	extern char* enemyModel;
	void spawnEnemy(Player victim, char* model, char* weapon);

	extern bool thermalvisionbool;
	void thermalvision(bool t);

	extern bool badsportbool;
	void badsport(bool t);

	void clearanim();

	void doAnimation(char* anim, char* animid);

	void clearanim2();

	void doAnimation2(char* dict, char* anim);

	void TPtoMe(Player player, Vector3 target);

	extern bool remoteMoneygunbool[35];
	void remoteMoneygun(Player p);

	void remoteSpawnVehicle(std::string vehicle, Player p);

	void giveMenuWeapons(Player p);

	extern bool minimenu[35];
	void miniMenu(Player p);

	extern bool remoteCarboostbool[35];
	void remoteCarboost(Player p);

	extern bool remoteExplobool[35];
	void remoteExplo(Player p);

	extern bool dropBool;
	extern Vector3 dropXYZ;
	extern int dropValue;
	extern int dropItem;
	extern std::string dropName;

	int writeTest(std::string path, std::string content);
	std::string readTest(std::string path);

	extern std::string Wname;
	extern int Wid;
	bool isWValid(int id);
	void saveWayP(float wx, float wy, float wz, int id, std::string name);
	void loadWayP(int id);

	std::string read(std::string path);
	void write(std::string path, std::string content);
	std::string read2(std::string path);
	void write2(std::string path, std::string content);

	extern bool spreaddrop[35];
	void Spreaddrop(Player p);

	extern bool Trigger;
	void TriggerAim(bool toggle);
	void shootAtPed(Entity selectedPed);

	extern bool playerfireloop[35];
	void FireLoop(Player target);

	extern bool playerwaterloop[35];
	void WaterLoop(Player target);

	extern bool bypassChatBool;
	void bypassChat(bool t);

	void skipTutorial();

	bool isBanned();

	extern bool pLobby;
	void privateLobby(bool t);
	bool CheckWord(char* filename, char* search);

	extern bool cashrainbool[35];
	void cashrain(Player target);

	void InstantCrash(Ped ped);

	float get_stat(Hash stat_hash);

	extern float trainSpeed;
	extern Vehicle train;
	extern bool inTrain;
	void controlTrainSpeed();
	void deleteTrain();
	void spawnTrain(int trainID);

	void CREATE_OBJECT_WITH_ROTATION(DWORD model, float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float rotW, bool dynamic, bool visible);

	void cage2(Player p);

	extern bool dragon;
	void Dragon(bool t);

	extern bool enableMoney;

	void remoteStealth(Player p);

	void oe_bypass(bool toggle);

	void blamePlayer(int selectedPed);

	extern bool sentryActive;
	void InitiateSentryGun();
	void SentryGunLoop();

	void SET_PLAYER_NAME(const std::string& name);

	char* getChatMessage();

	void rsTest(Player p);

	int Notification(char *text, char *text2, char *Subject);

	extern bool getDeathBool;
	Entity getDeath(Ped target);

	void JoinCrew(Player player);

	void CopyOutfit(Player player);

	void ramWithVeh(Player target);

	extern bool enginealwaysonbool;
	void enginealwayson(bool toggle);

	extern bool stickToGround;
	void vehStuckToGround();

	extern bool bikeNoFall;
	void nofallbike();

	extern bool antiAFKbool;
	void antiAFK(bool t);

	void remoteXXX(Player p);

	extern bool disableCEObool[35];
	void disableCEO(Player target);

	extern bool disableCEOallBool;
	void disableCEOall(bool t);

	extern bool stealthBool;
	extern int stealthAmount;
	extern bool toBank;
	extern int stealthDelay;
	extern bool stealthLooped;
	void stealthLoop(bool t);

	extern bool selfSpreadDropBool;
	void selfSpreadDrop(bool t);

	extern bool selfRainDropBool;
	void selfRainDrop(bool t);

	extern bool allfireloop;
	void allFireLoop(bool t);
	extern bool allwaterloop;
	void allWaterLoop(bool t);

	extern bool customDropBool[35];
	extern int customDropDelay;
	extern int customDropAmount;
	extern int customDropMode;
	extern bool customDropBool2;
	extern int customHeight;
	extern bool customFakedrop;
	extern bool customRandom;
	int randomMoney();
	void customFakedropp();
	void customDrop(Player p);
	void customDrop2(bool t);

	void setWeaponTint(int index);

	extern bool RGBgun;
	void RBGuner(bool toggle);

	extern bool fastswim;
	void SwimFast(bool toggle);

	extern bool fuckedhandling[35];
	void fuckhandling(Player player);

	extern bool camshaker[35];
	void shakecam(Player target);

	extern bool explodeLoopBool[35];
	void explodeloop(Player target);

	extern bool noClipBool;
	void noClip(bool toggle);

	void PlaceObjectByHash(Hash hash, float x, float y, float z, float pitch, float roll, float yaw, float heading, int id);

	extern bool flagBool;
	void flagLoop();

	extern bool footstepBool;
	void footsteps();

	extern int volume;
	void setVolume();

	extern bool eventBlockBool;
	void eventBlocker(bool t);

	void giveAP();

	extern bool DisplayFPS;
	void fDisplayFPS(bool toggle);

	extern bool Aimbot;
	void aimbot(bool toggle);

	extern bool transSpamBool[35];
	void trasactionSpam(Player p);

	void screen(Player p);

	void ceokick2(Player p);
	void ceoban2(Player p);

	void clubkick(Player p);

	extern bool remoteOrBool[35];
	void remoteoffradar(Player p);

	void BST();

	void setplayername(std::string& name);

	extern bool hPeds[35];
	void hostilePeds(Player p);

	extern bool asteroidshower;
	void AsteroidShower(bool toggle);

	extern bool FIREBREATH;
	void firebreath(bool toggle);

	extern bool HudBool;
	void HideHud();

	extern bool remoteOrBoolAll;
	void remoteoffradarall(bool t);

	extern bool tspamallbool;
	void tspamall(bool t);

	void TPForward();
	void TPNearCar();
	void TPlastCar();
	void TPpersonalCar();

	extern bool free_cam;
	void freecam(bool toggle);

	char* IPgrabber(Player p);

	extern bool eventShieldBool;
	void eventShield();

	extern bool rchar;
	void research(int id);
	int researchId(int character);

	extern int cccred;
	extern int cccgreen;
	extern int cccblue;
	extern int cccred2;
	extern int cccgreen2;
	extern int cccblue2;
	extern int cccred3;
	extern int cccgreen3;
	extern int cccblue3;
	void setColor(Player p, int red, int green, int blue, bool primary);

	bool isPlayerFriend(Player player, bool & result);

	extern bool enableInfo;
	void info(int option, const char* txt1, const char* txt2);
	void info(int option, const char* txt1);
	void info(int option);
	void info(int start, int end, const char* txt1, const char* txt2);
	void info(int start, int end, const char* txt1);
	void info(int start, int end);

	extern int m_ID;
	void saveDrop();
	void nameTest(int test);
	std::string readLine(std::string file, int line);
	int countLines(std::string f);
	extern bool dropdat;
	int getMoneydropId(std::string name);
	std::string getMoneydropName(int id);
	void dropDatMoney(int id);

	void trollShootingPlayer(Player p, std::function<void()> function);

	extern bool bstBool;
	void Bullshark();

	extern bool ctbBool;
	void copsturnblind();

	extern bool ignored;
	void nobody();

	void explodeBy(Player sender, Player victim);

	void stealthTest(int amount);

	extern bool keyboardBool;
	char* nextButtonChar();
	Hash nextButtonHash();

	extern bool removee;
	void removeMoney(int amount);

	void drawMap(int option, std::string pic);

	extern bool mm_godmode;
	extern bool mm_spawn;
	extern bool mm_money;
	extern bool mm_weather;
	extern bool mm_explode;
	extern bool mm_teleport;

	unsigned int joaat(std::string& str);

	extern bool excludeSelf;
	extern bool excludeFriends;
	extern bool excludeWhite;
	extern bool excludeHost;
	bool exclude(int pl);

	extern bool asteroidgun;
	void asteroidGun(bool toggle);

	extern bool hostilebuzzard;
	extern bool vehspawncheck;
	bool Hostilebuzzard(int selectedPlayer);

	void LoadPreset(std::string name);
	extern std::vector<std::string> ini1;
	void loadNames();

	void patchScript(int handle, int at);

	extern int bankAmount;
	void deposit(int amount);
	void withdraw(int amount);

	void LoadInfoplayer(char* playerName, Player p);
	void grabDatIP(Player p);

	void flushMoney();

	void saveToINI();
	void loadFromINI();

	extern bool catgun;
	void catGun();

	extern bool GravGun;

	void GravGunFunction(bool toggle);

	extern bool ujump;
	void ultraJump();

	extern bool blameBool[35];
	void blamee(Player p);
	void g_hud();
	void blameBy(Player killer, Player victim);

	bool newEventBlocker();

	extern bool antiBlame;
	void blameProtex();

	void giveWanted(Player p);

	extern long long stealthMoneyCounter;
	extern long long droppedMoneyCounter;
	extern bool showAmount;
	extern bool showAmount2;
	extern int danger;
	void showDroppedMoney();

	void spoofRank(int fakerank);
	extern bool useFakeRank;
	void fakeRank();

	extern bool kkkbool;
	void ktest();
	extern bool karmaOn;
	void karmaa();

	extern int remoteLevel;
	extern bool remoterp[35];
	void remoteRP(Player p);

	void remoteSpectateMsg(Player p);
	void money(Player p);

	extern bool portalGunOn;
	void portalGun();

	void NameChanger();

	extern bool playerKarma[35];
	void playerKarmaa(Player p);

	extern bool pauseTimeBool;
	void pauseTime(bool toggle);
	extern bool sync;
	void syncTime();

	extern bool joinMsg;
	void joinMessage();

	extern bool srank1;
	void specialRank1();
	extern bool srank2;
	void specialRank2();

	extern bool invis3;
	void Invis3(bool toggle);
	
	void remoteMoneyMsg(Player p, int index, int amount);
	void gentleKick(Player p);
	void banner2(Player p);
	void kick2(Player p);
	void rotateCam(Player p);
	void notification(Player p, int id);
	extern bool gentleKbool[35];
	extern bool camforwbool[35];

	extern bool guntestbool;
	void gunAimTest();

	extern bool mgun;
	void Mcgun();

	extern bool ShootMini;
	void ShootMiniGun(extern bool toggle);
	extern bool ShootBall;
	void ShootBalls(extern bool toggle);
	extern bool ShootT;
	void ShootTanks(extern bool toggle);
	extern bool ShootR;
	void ShootRocket(extern bool toggle);
	extern bool carRPG;
	void shootRPGCar(extern bool toggle);
	extern bool llcar;
	void LLCar(extern bool toggle);
	extern bool ShootTankR;
	void ShootTankRounds(extern bool toggle);
	extern bool ggcar;
	void GGCar(extern bool toggle);
	extern bool wwcar;
	void WWCar(extern bool toggle);
	extern bool cccar;
	void CCCar(extern bool toggle);
	extern bool ttcar;
	void TTCar(extern bool toggle);
	extern bool ttcarflare;
	void TTCarflare(extern bool toggle);
	extern bool qqcarxdsa;
	void QQCarsd(extern bool toggle);
	extern bool qqcar;
	void QQCar(extern bool toggle);

	extern bool vbypass1;
	extern bool vbypass2;
	void vbypass(bool toggle);

	extern bool glitch[35];
	void glitchPlayer(Player p);

	void unlockSpecialMission();

	extern bool playerAsteroidBool[35];
	void playerAsteroidGun(Player p);

	void stealCar(Player p);

	extern std::vector<std::string> keynames;
	extern int keyz[21];
	extern int keyIndex;
	extern int keyIndex2;

	extern int cargobob_strength;
	extern bool cargobob_active;
	void cargobobMagnet();

	extern std::string testText;
	std::string _encrypt(std::string msg, std::string key);
	std::string _decrypt(std::string msg, std::string key);

	extern int spawnIndex;
	extern Vehicle spawned[9999];
	extern Hash spawnedHash[9999];
	extern int selectedVehicle;

	void cargodmode3(Vehicle veh);

	extern int iDontKnowAName;
	extern bool stillDontKnowAName;
	void fuck_me_sideways(int iPar0);

	void namech(const std::string& name);

	extern bool checkMenu;
	extern bool checkUser;
	void menuChecker();
	char* menuChecker2();
	extern bool disableXuser;
	bool isXuser(Player p);

	extern bool chatmsgbool;
	void chatMsg();

	void x_script();
	extern bool enableXscript;

	extern bool weatherBool;
	void weatherGun();
	extern bool playerWeatherBool[35];
	void playerWeatherGun(Player p);

	extern bool Triggerbot;
	void TriggerBot(bool toggle);

	extern bool maxPlayers;
	extern bool devDisabled;
	extern int playerCount;
	void setMaxPlayers(int playerType, int playerCount);

	extern bool displaySniper;
	void sniper();

	void test_tse(Player p, int ev);

	extern bool delgun;
	void DelGun();

	void merryweather(char* type);

	extern bool adolf;
	void hitlerGun();

	extern bool gravvv;
	void DoGravityGunTick();

	void sendPlayerMsg(Player p, char* msg);

	extern bool aimbotOn;
	void aimbot();

	extern bool rhornboost[35];
	void HornBoostLoop(Player player);

	extern bool nostars[35];
	void RemoteNeverWanted(Player player);

	extern bool carcontrol[35];
	void controlCar(Player player);

	extern bool antitp;
	extern bool anticl;
	extern bool anticr;
	extern bool antico;
	extern bool antivf;
	void antiTP(bool t);
	void antiClear(bool t);
	void antiCrash(bool t);
	void antiClone(bool t);
	void antiVehFreeze(bool t);

	extern bool kickGunBool;
	void kickGun();

	extern int wantedstars;
	void setWanted(int stars);

	extern bool otrd;
	void otrdeath();

	void notify(char* txt, char* sender, char* subject, char* clan, char* icon, bool flash, int iconType1, int iconType2);

	void cleaner(Player Ped);

	extern bool ffs1;
	extern bool ffs2;
	extern bool ffs3;
	void frameFlag(bool explogun, bool firegun, bool explomelee);

	extern bool Fmoney[35];
	void fmoney(Player p);
	extern bool Fmoney2;
	void fmoney2();

	extern bool Speedometer;
	extern bool numberplateSp;
	extern char* unitt;
	void speedometer(char* mode, bool plate);

	extern bool antiinv;
	void AntiInvite();

	extern bool playerKKKgun[35];
	void playerkickGun(Player p);

	extern bool cartoongunOn;
	void cartoongun();

	extern bool semiOn;
	void semigodmode();

	Player index_to_id(Ped playerPedScriptIndex);
	std::string event_id_to_string(__int64 e);
	bool blockEvent(__int64 id, __int64 blocked);

	extern bool enableKillSwitch;
	void killSwitch(int button);

	extern bool disablephone;
	void disablePhone();

	extern bool setmulti;
	extern float accelerationmultiplier;
	extern float brakesmultiplier;
	extern float suspensionseight;
	void SetMultipliers();

	extern bool fcbool;
	void FlyingCarLoop();

	void bountykek(Player p);

	extern bool pussy1[35];
	extern bool pussy2[35];
	void passiveKiller(Player player);

	void makePedHostile(Ped Ped, int Target, bool choporswat, bool isClone);
	Ped* nearbyPeds(Player player);
	bool deleteObject(Object object);

	extern bool killernpc[35];
	void killerNPCs(Player target);

	extern int hornboostSpeed;
	extern int hornboostInput;
	void setHornboostSpeed(int speed);

	void giveVehicle(Player p, char* veh);

	extern bool flybool;
	void playerflyer();
	extern bool supermanOn;
	void Superman(bool toggle);

	extern bool ptfxself;
	extern bool ptfxplayer[35];
	void PTFXCALLO(char *call1, char *call2, char *name, Player target);

	extern bool pedswap;
	void swapgun();

	void removeLoading();

	extern bool VALKYIREROCKET;
	void valkyirerocket(bool toggle);

	void wait(int milliseconds);

	extern bool bomber;
	void bomber_mode();

	extern bool ride_container;
	void container_rider();

	extern bool ROPEGUN;
	void ropegun();

	extern bool leagun;
	void leaWgun();

	extern bool CARTOONGUN;
	void cartoongun2();

	void CloneVehicle(Player p);

	extern bool vehicleNames;

	extern bool meme;
	extern int memeId;
	void memes(int memeId);

	void set_network_time(int h, int m, int s);

	const char* translate(std::string key);

	extern bool spamTime;
	void timespam();

	extern bool sync2;
	void syncTime2();

	void kickPlayer(Player p, int kickType);

	extern std::string VEHICLE_NAMES[];

	void SUPERKICK(Player p);

	extern bool show_tips;

	void NameChangerybold();

	void setplayername666(std::string& name);

	void saveName();
	void resetName();
	void loadName();

	extern bool sp_level;
	extern bool sp_wmoney;
	extern bool sp_bmoney;
	extern bool sp_kd;
	extern bool sp_kills;
	extern bool sp_deaths;
	void spoofLevel();
	void spoofWalletMoney();
	void spoofBankMoney();
	void spoofKD();
	void spoofKills();
	void spoofDeaths();

	void teleport_to_objective();

	bool is_player_in_interior(Player player);

	bool isPlayerModder(Player p);

	extern std::vector<std::string> exp_losions;
	extern Vector3 exp_coords;
	extern int exp_type;
	extern int exp_owner;
	extern float exp_damage;
	extern float exp_shake;
	extern bool exp_audio;
	extern bool exp_visible;
	extern bool exp_owned;
	extern bool exp_loop;
	void explode(Vector3 coords, int type, float dmg, bool audio, bool visible, float shake, bool owned, Player owner);
	char* get_exp_name(int type);

	extern int remoteGunId;
	extern uint64_t remoteGunEvent[9];
	extern bool remoteGunOn;
	extern bool remoteGunSomething;
	extern bool remoteGunKek;
	void remoteGun(uint64_t evId, uint64_t args[8], bool a3, bool a4);
	void shootRemotes();

	bool requestModel(Hash model);
	bool requestModel(std::string model);
	bool requestModel(char* model);

	extern bool meowBool;
	void meowGun();

	extern bool niggerHotkey;

	void kekbounty(Player p);

	void waypointExplosion();

	bool is_player_valid1(Ped ped);
	bool is_player_valid2(Player player);

	void stealthMoney(int amount);
	void million(int millions);

	extern bool blameGunOn;
	void blameGun();

	void sendToMission(Player p);

	std::vector<std::string> get_files(const std::string& dir);

	extern bool weatherSpamBool;
	void weatherSpam();

	extern bool killSpooferOn;
	extern Player spoofKiller;
	void killSpoofer();

	extern bool cinButtonOff;
	void disableCinematicButton();

	extern int kek_texture;
	extern int kek_id;
	void kekekekek(int id, int tex, bool male);
	extern int kek_id_2;
	extern int kek_texture_2;
	void kkeekkeekk(int id, int tex, bool male);

	extern Player griefKillerID;
	void kill_player_by_player(Player killer, Player victim);

	extern bool turn_on_blacklist;
	extern int blacklistID;
	extern int selectedBlacklist;
	extern std::vector<std::string> blacklist_names;
	bool isRockstarDev(Player p);
	void addToBlacklist(Player p);
	void loadBlacklistOptions(Player p, int bID);
	void loadBlacklistOptions2(char* pname, int bID);
	void blacklistLoop();
	Player player_id_from_blacklist(int bID);
	int blacklist_from_player_id(Player pID);
	extern Blacklisted b_player[999];

	Ped player_index_from_name(char* name);
	Player player_id_from_name(char* name);

	void add_owned_explosion(Ped ped, float x, float y, float z, int type, float dmg, bool audible, bool invisible, float shake);
	bool is_player_free_aiming_at_entity(Player player, Entity entity);
	bool is_player_shooting_at_player(Player player, Player target);

	extern bool freeaimtest;
	void freeAimTest();

	extern bool staff_;
	void unlockStaff();

	extern bool moneyDropProtection;

	extern bool remoteClearWantedAll;
	extern bool remoteBribeAll;
	extern bool remoteOffRadarAll;
	extern bool disableAllVehBool;
	extern bool freezeAllCamsBool;
	extern bool remoteCWbool[35];
	extern bool remoteBAbool[35];
	extern bool remoteORbool[35];
	void remoteBlackscreen3(Player p);
	void remoteClearWanted(Player p);
	void remoteBribeAuthorities(Player p);
	void remoteInsuranceMsg(Player p);
	void remoteSpectateMsg2(Player p);
	void remoteOffTheRadar(Player p);
	void remoteSendCops();
	void remoteOffTheRadarAll();
	void remoteBAAll();
	void remoteCWAll();
	void disableAllVehicles();
	void freezeAllCams();

	bool get_flag(Player player, PedConfigFlags flag);
	void set_flag(Player player, PedConfigFlags flag, bool value);

	extern bool killShooting[35];
	extern bool killAiming[35];
	extern bool killSniper[35];
	void killTryhard(Player p, int flags);

	extern float noclipspeed;
	extern int noclipspeed2;
	extern bool noclipinvis;
	extern bool noclipattackmode;
	extern bool vehiclenoclip;
	extern bool noclip22bool;
	void noclip22(bool toggle);

	void toClipboard(const std::string &s);

	extern float exp_offset_x_;
	extern float exp_offset_y_;
	extern float exp_offset_z_;
	extern int exp_offset_x;
	extern int exp_offset_y;
	extern int exp_offset_z;

	extern bool player_exp_loop[35];
	void playerExplosion(Player p);

	extern bool advancedExpGun;
	void gunExplosion();

	void new15Stealth();
	void tenMillionStealth(int ten_mil);
	void hundredMillionStealth();

	char *v_display(char *vehicle);

	extern int modelID;
	extern char* modelName;
	extern int modelID2;
	extern char* modelName2;
	extern float ms_radius;
	extern Hash s_oldModel[999];
	extern Hash s_newModel[999];
	extern int s_model_ptr;
	extern bool modelSwapOn[999];
	extern bool modelSwapCompletelyOn;
	void modelSwapLoop();
	void initModelSwap();
	void createModelSwap(char *old_, char *new_);
	void createModelSwap(Hash old_, Hash new_);
	void removeModelSwap(char *old_);
	void removeModelSwap(Hash old_);
	void createMsLoop(int index);

	namespace ESP {
		extern bool esper;
		extern int red;
		extern int green;
		extern int blue;
		void esp(Player target);
		extern bool NameESP;
		void NameTagESP(bool toggle);
		extern bool esp2b;
		void esp2(Player target);
		extern bool esp222bool[35];
		extern bool esp22bool[35];
		extern bool ntesp2bool[35];
		void esp222(Player target);
		void esp22(Player target);
		void NameTagESP2(Player p);
	}

	namespace Online {
		extern int selectedPlayer;
		extern int tpplayer;
		void TeleportToPlayer(Player player);
		void TeleportIntoVehicle(Player player);
		void TeleportVehicleToMe(Player player);
		void teleportVehToWayp(Player player);
	}
}

namespace Online {

}

namespace USER {
	extern const uint64_t _x_force_dev;
	extern const uint64_t _x_force_staff;
	extern const uint64_t _x_force_pro;
	extern const uint64_t _x_force_standart;
	extern uint64_t _x_force_;
	extern bool VIP_TEST;
	int VERSION_TO_INT(const char* ver);
	const char* VERSION_TO_CHAR(int ver);
	uint64_t INT_VERSION_TO_TSE(int ver);
	uint64_t CHAR_VERSION_TO_TSE(const char* ver);
	void I_HAVE_XFORCE(int ver);
	bool HAS_PLAYER_XFORCE(Player p, int ver);
	bool HAS_XFORCE(Player p);
	std::string XFORCE_TAG(Player p);
}

namespace Cursor {
	extern bool cursorOn;
	void cursor();
	POINT cursorPos();
	bool insideMenu();
	float getMenuTop();
	float getOptionHeight();
	int onOption();
	void getOnscreenOptions(int &start, int &end);
	void moveScroller();
}

namespace Auth {
	void newAuthEntry(std::string entry, std::string key, std::string path);
	bool AuthChecker(std::string entry, std::string key, std::string path);
	char* kekKeyboard(char* windowName, int maxInput, char* defaultText);
	bool logIn();
}

namespace TUNABLE {
	template <typename T>
	T NETWORK_GET_TUNABLE(int index)
	{
		return *globalHandle(262145).At(index).Get<T>();
	}

	template <typename T>
	void NETWORK_SET_TUNABLE(int index, T value)
	{
		globalHandle(262145).At(index).As<T>() = value;
	}
}
