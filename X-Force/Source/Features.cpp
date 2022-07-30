#include "stdafx.h"

bool Features::enableMoney = true;

#define PROP_MONEY_PAPERCASE_01 -1803909274
#define PROP_MONEY_PAPERBAG_01 -1666779307
#define PROP_MONEY_BAG_01 0x113FD533
#define PICKUP_MONEY_CASE 0x1E9A99F8 
int Features::MoneyItem = 0;
int Features::inviteSS = 1;

char *call1o;
char *call2o;
char *nameo;
Ped PTLoopPed;

int Features::carCounter = 0;
int Features::things[999] = {};
char* Features::selectedthing = NULL;

int Features::TimePD;
int Features::TimePD1;
int Features::TimePD2;
int Features::TimePD3;
int Features::TimePD4;
int Features::TimePD5;
int Features::TimePD6;
int Features::TimePD7;
int Features::TimePD8;
int Features::TimePD9;
int Features::TimePD10;
int Features::TimePD11;
int Features::TimePD12;
int Features::TimePD13;
int Features::TimePD14;
int Features::TimePD15;
int Features::TimePD16;
int Features::TimePD17;
int Features::TimePD18;
int Features::TimePD19;

int Features::Online::tpplayer = 0;
int Features::Online::selectedPlayer = 0;
int Features::drivespeed = 60;
int Features::drivestyle = 1;

void Features::UpdateLoop()
{

	//Features::updateCoords();

	betiny ? TinyPlayer(true) : NULL;

	DIGun ? digun(true) : NULL;

	infammo ? Infammo(true) : NULL;

	Superjump ? superjump(true) : NULL;

	GodMode ? godmode(true) : NULL;

	osk ? OSK(true) : NULL;

	Gravity ? GravityGun(true) : NULL;

	neverwanted ? NeverWanted(true) : NULL;

	playerinvisibility2 ? Invisibility2(true) : NULL;

	moneygun ? MoneyGun(true) : NULL;

	selfdrop ? Selfdrop(true, 1, Features::MoneyItem, 2500) : NULL;

	orbool ? OffRadar(true) : NULL;

	unlimitedorbitalcannon ? UnlimitedORbitalCannon(true) : NULL;

	teleportgun ? Teleportgun(true) : NULL;

	moongrav ? MoonGrav(true) : NULL;

	RPLoop ? rpLoop() : NULL;

	playernoragdoll ? NoRagdoll(true) : NULL;

	fakedropbool ? fakedrop(true, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer)) : NULL;

	selftenkped ? selfTenKPedMoney(true) : NULL;

	Rneon ? RainbowNeon(true) : NULL;

	Rainb ? Rainbow(true) : NULL;

	Rcolor ? RainbowColor(true) : NULL;

	drunk ? Drunk(true) : NULL;

	antifog ? Antifog(true) : NULL;

	antitse ? antiTSE(true) : NULL;

	antiEvery ? AntiEverything(true) : NULL;

	antiweatherTime ? antiWeatherTime(true) : NULL;

	antiReport ? AntiReport(true) : NULL;

	antiStat ? AntiStat(true) : NULL;

	antiControl ? AntiControl(true) : NULL;

	antiPickup ? AntiPickup(true) : NULL;

	antiWeapon ? AntiWeapon(true) : NULL;

	antiExplosion ? AntiExplosion(true) : NULL;

	antiStars ? AntiStars(true) : NULL;

	antiKick ? AntiKick(true) : NULL;

	antiFreeze ? AntiFreeze(true) : NULL;

	antiSound ? AntiSound(true) : NULL;

	antiPtfx ? AntiPtfx(true) : NULL;

	antiAttachment ? AntiAttachment(true) : NULL;

	boostbool ? carboost(true) : NULL;

	blackhole ? hole(true) : NULL;

	explogun ? ExploGun(true) : NULL;

	vehjump ? VehJump(true) : NULL;

	dowbool ? DriveOnWater(true) : NULL;

	tpbool ? tpHotkey(true, Features::keyz[Features::keyIndex2]) : NULL;

	rapidfirer ? rapidmaker(true) : NULL;

	agbool ? airstrikeGun(true) : NULL;

	carinvisbool ? carinvis(true) : NULL;

	otr2bool ? otr2(true) : NULL;

	thunderbool ? thunder(true) : NULL;

	talkbool1 ? talkStuff1(true) : NULL;

	talkbool2 ? talkStuff2(true) : NULL;

	ESP::NameESP ? ESP::NameTagESP(true) : NULL;

	badsportbool ? badsport(true) : NULL;

	iLoopBoolall ? inviteLoopAll(true, Features::inviteSS) : NULL;

	dumpBool ? logEvent(msgBool) : NULL;

	Trigger ? TriggerAim(true) : NULL;

	bypassChatBool ? bypassChat(true) : NULL;

	pLobby ? privateLobby(true) : NULL;

	inTrain ? controlTrainSpeed() : NULL;

	dragon ? Dragon(true) : NULL;

	sentryActive ? SentryGunLoop() : NULL;

	getDeathBool ? getDeath(Features::Online::selectedPlayer) : NULL;

	enginealwaysonbool ? enginealwayson(true) : NULL;

	stickToGround ? vehStuckToGround() : NULL;

	bikeNoFall ? nofallbike() : NULL;

	antiAFKbool ? antiAFK(true) : NULL;

	disableCEOallBool ? disableCEOall(true) : NULL;

	stealthBool ? stealthLoop(true) : NULL;

	selfSpreadDropBool ? selfSpreadDrop(true) : NULL;

	selfRainDropBool ? selfRainDrop(true) : NULL;

	allfireloop ? allFireLoop(true) : NULL;

	allwaterloop ? allWaterLoop(true) : NULL;

	customDropBool2 ? customDrop2(true) : NULL;

	RGBgun ? RBGuner(true) : NULL;

	fastswim ? SwimFast(true) : NULL;

	noClipBool ? noClip(true) : NULL;

	flagBool ? flagLoop() : NULL;

	footstepBool ? footsteps() : NULL;

	eventBlockBool ? eventBlocker(true) : NULL;

	DisplayFPS ? fDisplayFPS(true) : NULL;

	Aimbot ? aimbot(true) : NULL;

	asteroidshower ? AsteroidShower(true) : NULL;

	FIREBREATH ? firebreath(true) : NULL;

	HudBool ? HideHud() : NULL;

	remoteOrBoolAll ? remoteoffradarall(true) : NULL;

	tspamallbool ? tspamall(true) : NULL;

	free_cam ? freecam(true) : NULL;

	customFakedrop ? customFakedropp() : NULL;

	customRandom ? randomMoney() : NULL;

	eventShieldBool ? eventShield() : NULL;

	bstBool ? Bullshark() : NULL;

	ctbBool ? copsturnblind() : NULL;

	ignored ? nobody() : NULL;

	Cursor::cursorOn ? Cursor::cursor() : NULL;

	asteroidgun ? asteroidGun(true) : NULL;

	catgun ? catGun() : NULL;

	GravGun ? GravGunFunction(true) : NULL;

	ujump ? ultraJump() : NULL;

	antiBlame ? blameProtex() : NULL;

	kkkbool ? ktest() : NULL;

	useFakeRank ? fakeRank() : NULL;

	karmaOn ? karmaa() : NULL;

	portalGunOn ? portalGun() : NULL;

	sync ? syncTime() : NULL;

	pauseTimeBool ? pauseTime(true) : NULL;

	joinMsg ? joinMessage() : NULL;

	srank1 ? specialRank1() : NULL;

	srank2 ? specialRank2() : NULL;

	invis3 ? Invis3(true) : NULL;

	showAmount ? showDroppedMoney() : NULL;

	showAmount2 ? showDroppedMoney() : NULL;

	guntestbool ? gunAimTest() : NULL;

	mgun ? Mcgun() : NULL;

	ShootMini ? ShootMiniGun(true) : NULL;

	ShootBall ? ShootBalls(true) : NULL;

	ShootT ? ShootTanks(true) : NULL;

	ShootR ? ShootRocket(true) : NULL;

	carRPG ? shootRPGCar(true) : NULL;

	llcar ? LLCar(true) : NULL;

	ggcar ? GGCar(true) : NULL;

	ShootTankR ? ShootTankRounds(true) : NULL;

	wwcar ? WWCar(true) : NULL;

	cccar ? CCCar(true) : NULL;

	ttcar ? TTCar(true) : NULL;

	ttcarflare ? TTCarflare(true) : NULL;

	qqcarxdsa ? QQCarsd(true) : NULL;

	qqcar ? QQCar(true) : NULL;

	vbypass1 ? vbypass(true) : NULL;

	vbypass2 ? vbypass(false) : NULL;

	cargobob_active ? cargobobMagnet() : NULL;

	chatmsgbool ? chatMsg() : NULL;

	enableXscript ? x_script() : NULL;

	weatherBool ? weatherGun() : NULL;

	Triggerbot ? TriggerBot(true) : NULL;

	displaySniper ? sniper() : NULL;

	delgun ? DelGun() : NULL;

	devDisabled ? setMaxPlayers(4, 0) : NULL;

	maxPlayers ? setMaxPlayers(-1, playerCount) : NULL;

	adolf ? hitlerGun() : NULL;

	gravvv ? DoGravityGunTick() : NULL;

	aimbotOn ? aimbot() : NULL;

	antitp ? antiTP(true) : NULL;

	anticl ? antiClear(true) : NULL;

	antico ? antiClone(true) : NULL;

	anticr ? antiCrash(true) : NULL;

	antivf ? antiVehFreeze(true) : NULL;

	kickGunBool ? kickGun() : NULL;

	otrd ? otrdeath() : NULL;

	ffs1 ? frameFlag(true, false, false) : NULL;

	ffs2 ? frameFlag(false, true, false) : NULL;

	ffs3 ? frameFlag(false, false, true) : NULL;

	Fmoney2 ? fmoney2() : NULL;

	Speedometer ? speedometer(unitt, numberplateSp) : NULL;

	antiinv ? AntiInvite() : NULL;

	cartoongunOn ? cartoongun() : NULL;

	semiOn ? semigodmode() : NULL;

	enableKillSwitch ? killSwitch(VK_KEY_K) : NULL;

	disablephone ? disablePhone() : NULL;

	setmulti ? SetMultipliers() : NULL;

	fcbool ? FlyingCarLoop() : NULL;

	flybool ? playerflyer() : NULL;

	supermanOn ? Superman(true) : NULL;

	ptfxself ? PTFXCALLO(call1o, call2o, nameo, PLAYER::PLAYER_ID()) : NULL;

	pedswap ? swapgun() : NULL;

	VALKYIREROCKET ? valkyirerocket(true) : NULL;

	bomber ? bomber_mode() : NULL;

	ride_container ? container_rider() : NULL;

	ROPEGUN ? ropegun() : NULL;

	CARTOONGUN ? cartoongun2() : NULL;

	leagun ? leaWgun() : NULL;

	spamTime ? timespam() : NULL;

	sync2 ? syncTime2() : NULL;

	meme ? memes(memeId) : NULL;

	sp_level ? spoofLevel() : NULL;

	sp_wmoney ? spoofWalletMoney() : NULL;

	sp_bmoney ? spoofBankMoney() : NULL;

	sp_kd ? spoofKD() : NULL;

	sp_kills ? spoofKills() : NULL;

	sp_deaths ? spoofDeaths() : NULL;

	remoteGunOn ? shootRemotes() : NULL;

	exp_loop ? waypointExplosion() : NULL;

	nightvisionbool ? nightvision(true) : NULL;

	thermalvisionbool ? thermalvision(true) : NULL;

	mobRadio ? mobileRadio(true) : NULL;

	meowBool ? meowGun() : NULL;

	blameGunOn ? blameGun() : NULL;

	weatherSpamBool ? weatherSpam() : NULL;

	killSpooferOn ? killSpoofer() : NULL;

	cinButtonOff ? disableCinematicButton() : NULL;

	freeaimtest ? freeAimTest() : NULL;

	turn_on_blacklist ? blacklistLoop() : NULL;

	remoteClearWantedAll ? remoteCWAll() : NULL;

	remoteBribeAll ? remoteBAAll : NULL;

	remoteOffRadarAll ? remoteOffTheRadarAll() : NULL;

	disableAllVehBool ? disableAllVehicles() : NULL;

	freezeAllCamsBool ? freezeAllCams() : NULL;

	noclip22bool ? noclip22(true) : NULL;

	advancedExpGun ? gunExplosion() : NULL;

	modelSwapCompletelyOn ? modelSwapLoop() : NULL;

	//playerinvisibility ? Invisibility(true) : NULL;

	for (int ix = 0; ix < 33; ix++) {
		if (freezed[ix])
		{
			Freezer(ix);
		}
		if (spectate[ix])
		{
			specter(ix);
		}
		if (ESP::esper)
		{
			ESP::esp(ix);
		}
		if (ESP::esp2b)
		{
			ESP::esp2(ix);
		}
		if (minimenu[ix])
		{
			miniMenu(ix);
		}
		if (remoteMoneygunbool[ix])
		{
			remoteMoneygun(ix);
		}
		if (remoteCarboostbool[ix])
		{
			remoteCarboost(ix);
		}
		if (remoteExplobool[ix])
		{
			remoteExplo(ix);
		}
		if (moneydrop[ix])
		{
			Moneydrop(ix);
		}
		if (spreaddrop[ix]) 
		{
			Spreaddrop(ix);
		}
		if (iLoopBool[ix])
		{
			inviteLoop(ix, Features::inviteSS);
		}
		if (playerfireloop[ix]) 
		{
			FireLoop(ix);
		}
		if (playerwaterloop[ix])
		{
			WaterLoop(ix);
		}
		if (cashrainbool[ix])
		{
			cashrain(ix);
		}
		if (disableCEObool[ix])
		{
			disableCEO(ix);
		}
		if (customDropBool[ix])
		{
			customDrop(ix);
		}
		if (fuckedhandling[ix])
		{
			fuckhandling(ix);
		}
		if (camshaker[ix])
		{
			shakecam(ix);
		}
		if (explodeLoopBool[ix])
		{
			explodeloop(ix);
		}
		if (transSpamBool[ix])
		{
			trasactionSpam(ix);
		}
		if (remoteOrBool[ix])
		{
			remoteoffradar(ix);
		}
		if (hPeds[ix])
		{
			hostilePeds(ix);
		}
		if (ESP::esp222bool[ix])
		{
			ESP::esp222(ix);
		}
		if (ESP::esp22bool[ix])
		{
			ESP::esp22(ix);
		}
		if (ESP::ntesp2bool[ix])
		{
			ESP::NameTagESP2(ix);
		}
		if (blameBool[ix])
		{
			blamee(ix);
		}
		if (remoterp[ix])
		{
			remoteRP(ix);
		}
		if (playerKarma[ix])
		{
			playerKarmaa(ix);
		}
		if (gentleKbool[ix])
		{
			Features::gentleKick(ix);
		}
		if (camforwbool[ix])
		{
			Features::rotateCam(ix);
		}
		if (glitch[ix])
		{
			glitchPlayer(ix);
		}
		if (playerAsteroidBool[ix])
		{
			playerAsteroidGun(ix);
		}
		if (playerWeatherBool[ix])
		{
			playerWeatherGun(ix);
		}
		if (rhornboost[ix])
		{
			HornBoostLoop(ix);
		}
		if (nostars[ix])
		{
			RemoteNeverWanted(ix);
		}
		if (carcontrol[ix])
		{
			controlCar(ix);
		}
		if (Fmoney[ix])
		{
			fmoney(ix);
		}
		if (playerKKKgun[ix])
		{
			playerkickGun(ix);
		}
		if (pussy1[ix])
		{
			passiveKiller(ix);
		}
		if (killernpc[ix])
		{
			killerNPCs(ix);
		}
		if (ptfxplayer[ix])
		{
			PTFXCALLO(call1o, call2o, nameo, ix);
		}
		if (remoteCWbool[ix])
		{
			remoteClearWanted(ix);
		}
		if (remoteBAbool[ix])
		{
			remoteBribeAuthorities(ix);
		}
		if (remoteORbool[ix])
		{
			remoteOffTheRadar(ix);
		}
		if (killShooting[ix])
		{
			killTryhard(ix, 0);
		}
		if (killAiming[ix])
		{
			killTryhard(ix, 1);
		}
		if (killSniper[ix])
		{
			killTryhard(ix, 2);
		}
		if (player_exp_loop[ix])
		{
			playerExplosion(ix);
		}
	}

}

//Self Features
bool is_ped_shooting(Ped ped) {
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(ped, 1);
	return PED::IS_PED_SHOOTING_IN_AREA(ped, coords.x, coords.y, coords.z, coords.x, coords.y, coords.z, true, true);
}

bool Features::Superjump = false;
void Features::superjump(bool toggle)
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());
	GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(playerPed);
}

bool Features::betiny = false;
void Features::TinyPlayer(bool toggle)
{
	PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), 223, toggle);
}

bool Features::GodMode = false;
void Features::godmode(bool toggle)
{
		BYTE Setter = (GodMode) ? 1 : 0;
		BYTE Current = Memory::get_value<BYTE>({ 0x08, 0x189 });
		if (Current != Setter)
			Memory::set_value({ 0x08, 0x189 }, Setter);
}

bool Features::mobRadio = false;
void Features::mobileRadio(bool t) {
	int station = AUDIO::GET_PLAYER_RADIO_STATION_INDEX();
	if (t == false)
	{
		Hooking::set_mobile_radio_enabled_during_gameplay(false);
		AUDIO::SET_MOBILE_PHONE_RADIO_STATE(0);
	}
	else
	{
		Hooking::set_mobile_radio_enabled_during_gameplay(true);
		AUDIO::SET_MOBILE_PHONE_RADIO_STATE(1);
		AUDIO::SET_RADIO_TO_STATION_INDEX(station);
	}
}

int Features::handy = -1;
void Features::setPhone(int index) {
	switch (index) {
	case -1:
		//nothing :P
		break;
	case 0: 
		MOBILE::CREATE_MOBILE_PHONE(0);
		break;
	case 1:
		MOBILE::CREATE_MOBILE_PHONE(1);
		break;
	case 2:
		MOBILE::CREATE_MOBILE_PHONE(2);
		break;
	case 3:
		MOBILE::CREATE_MOBILE_PHONE(4);
		break;
	}
}

bool Features::neverwanted = false;
void Features::NeverWanted(bool toggle)
{
	if (neverwanted == TRUE)
	{
		PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
		PLAYER::SET_MAX_WANTED_LEVEL(0);// cannot get over 0
		GAMEPLAY::SET_FAKE_WANTED_LEVEL(0);
	}
	if (neverwanted == FALSE)
	{
		PLAYER::SET_MAX_WANTED_LEVEL(5);
	}
}

bool Features::playernoragdoll = false;
void Features::NoRagdoll(bool toggle)
{
	PED::SET_PED_RAGDOLL_ON_COLLISION(PLAYER::PLAYER_PED_ID(), !toggle);
	PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), !toggle);
	PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), !toggle);
}

int Features::playerWantedLevel = 0;
void Features::ChangeWanted(int level) {
	Memory::set_value<int>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_WANTED }, Features::playerWantedLevel);
}

bool Features::playerinvisibility = false;
void Features::Invisibility(bool toggle)
{
	if (playerinvisibility)
	{
		ENTITY::SET_ENTITY_VISIBLE1(PLAYER::PLAYER_PED_ID(), false, 0);
	}
	else
	{
		ENTITY::SET_ENTITY_VISIBLE1(PLAYER::PLAYER_PED_ID(), true, 0);
	}
}

bool Features::playerinvisibility2 = false;
void Features::Invisibility2(bool toggle)
{
	if (toggle)
	{
		NETWORK::SET_LOCAL_PLAYER_INVISIBLE_LOCALLY(false);
		ENTITY::SET_ENTITY_VISIBLE1(PLAYER::PLAYER_PED_ID(), false, 0);
	}
	else
	{
		ENTITY::SET_ENTITY_VISIBLE1(PLAYER::PLAYER_PED_ID(), true, 0);
		NETWORK::SET_LOCAL_PLAYER_VISIBLE_LOCALLY(true);
	}
}

void Features::setName(std::string name) {
	//GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD;
	//Hooking::setPlayerName(name);
}

bool Features::screenfx = false;
void Features::ScreenFX(bool toggle, char *effect) {
	if (toggle) {
		GRAPHICS::_START_SCREEN_EFFECT(effect, 0, true);
	}
	else {
		GRAPHICS::_STOP_SCREEN_EFFECT(effect);
	}
}

bool Features::unlimitedorbitalcannon = false;
void Features::UnlimitedORbitalCannon(bool t)
{
	if (t == true)
	{
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ORBITAL_CANNON_COOLDOWN"), 0, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ORBITAL_CANNON_COOLDOWN"), 0, 0);
	}
}

bool Features::orbool = false;
void Features::OffRadar(bool toggle)
{
	globalHandle(2423801).At(PLAYER::PLAYER_ID(), 413).At(200).As<int>() = 1;
	globalHandle(2437022).At(70).As<int>() = NETWORK::GET_NETWORK_TIME() + 5000;
	//Global_2423801[PLAYER::PLAYER_ID() /*413*/].f_200
	//Global_2437022.f_70
}

bool Features::otr2bool = false;
void Features::otr2(bool t) {
	if (t) {
		Features::GodMode = true;
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_ENTITY_HEALTH }, 0);
	}
	else {
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_ENTITY_HEALTH }, 100);
	}
}

bool Features::fastRun = false;
void Features::runFast(bool toggle)
{
	if (!fastRun)
	{
		Memory::set_value<float>({ 0x08, 0x10B8, 0x14C }, 1);
	}
	else
	{
		Memory::set_value<float>({ 0x08, 0x10B8, 0x14C }, 2.0f);
	}
}

bool Features::thunderbool = false;
void Features::thunder(bool t) {
	GAMEPLAY::_CREATE_LIGHTNING_THUNDER();
}

bool Features::nightvisionbool = false;
void Features::nightvision(bool t) {
	if (t) {
		GRAPHICS::SET_NIGHTVISION(true);
	}
	else {
		GRAPHICS::SET_NIGHTVISION(false);
	}
}
bool Features::thermalvisionbool = false;
void Features::thermalvision(bool t) {
	if (t) {
		GRAPHICS::SET_SEETHROUGH(true);
	}
	else {
		GRAPHICS::SET_SEETHROUGH(false);
	}
}

Hash moneyModel(int id) {
	switch (id) {
	case 0: return -1666779307; break; //Paperbag
	case 1: return -1803909274; break; //Paperbag2
	case 2: return 0x113FD533; break; //Moneybag
	case 3: return 1803116220; break; //Alien egg
	case 4: return -708789241; break; //Guitar
	case 5: return 1522853652; break; //Grave
	case 6: return -463441113; break; //Dildo
	case 7: return -144591170; break; //Dummy
	case 8: return -930879665; break; //Toilet
	case 9: return -1688127; break; //Weed
	case 10: return -492435441; break; //Oil
	case 11: return GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp"); break; //EMP
	case 12: return GAMEPLAY::GET_HASH_KEY("prop_juicestand"); break; //Ball
	case 13: return GAMEPLAY::GET_HASH_KEY("prop_weed_01"); break; //Weed2
	case 14: return GAMEPLAY::GET_HASH_KEY("p_v_43_safe_s"); break; //Safe
	case 15: return GAMEPLAY::GET_HASH_KEY("p_spinning_anus_s"); break; //UFO
	case 16: return GAMEPLAY::GET_HASH_KEY("prop_xmas_tree_int"); break; //Xmas tree
	case 17: return GAMEPLAY::GET_HASH_KEY("prop_air_bigradar"); break; //Radar
	case 18: return GAMEPLAY::GET_HASH_KEY("prop_cs_duffel_01b"); break; //Duffel
	case 19: return GAMEPLAY::GET_HASH_KEY("PROP_MP_RAMP_03"); break; //Ramp
	case 20: return GAMEPLAY::GET_HASH_KEY("PROP_MP_NUM_1"); break; //1
	case 21: return GAMEPLAY::GET_HASH_KEY("PROP_MP_NUM_2"); break; //2
	case 22: return GAMEPLAY::GET_HASH_KEY("PROP_MP_NUM_3"); break; //3
	case 23: return GAMEPLAY::GET_HASH_KEY("prop_dummy_plane"); break; //Plane
	case 24: return GAMEPLAY::GET_HASH_KEY("prop_anim_cash_pile_02"); break; //Cash pile
	case 25: return GAMEPLAY::GET_HASH_KEY("prop_amb_donut"); break; //Donut
	case 26: return GAMEPLAY::GET_HASH_KEY("prop_Ld_ferris_wheel"); break; //Ferris wheel
	}
}

//TP

/*int Features::Online::selectedPlayer = 0;
void Features::Online::TPtoPlayer(Player player) {

	Entity handle;
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), false);
	PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : handle = PLAYER::PLAYER_PED_ID();
	ENTITY::SET_ENTITY_COORDS(handle, coords.x, coords.y, coords.z, false, false, false, false);
}*/

bool Features::tpbool = true;
void Features::tpHotkey(bool t, int key) {
	if (t && GetAsyncKeyState(key)) {
		Features::Teleport_to_marker();
	}
}

void Features::Teleport_to_marker()
{
	Vector3 coords = get_blip_marker();

	if (coords.x == 0 && coords.y == 0)
	{
		//notifyMap("No Waypoint has been set!", 0);
		return;
	}

	// get entity to teleport
	Entity e = PLAYER::PLAYER_PED_ID();
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
		WAIT(100);
		if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0))
		{
			groundFound = true;
			coords.z += 3.0;
			break;
		}
	}
	// if ground not found then set Z in air and give player a parachute
	if (!groundFound) {
		coords.z = 1000.0;
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xFBAB5776, 1, 0);
	}
	//do it
	teleport_to_coords(e, coords);
}

bool Features::moongrav = false;
void Features::MoonGrav(bool t)
{
	if (t == true)
	{
		GAMEPLAY::SET_GRAVITY_LEVEL(2);
	}
	else
	{
		GAMEPLAY::SET_GRAVITY_LEVEL(0);
	}
}

bool Features::drunk;
void Features::Drunk(bool t)
{
	AUDIO::SET_PED_IS_DRUNK(PLAYER::PLAYER_PED_ID(), t);
}

//Weapon options

bool Features::DIGun = false;
void Features::digun(bool toggle)
{
	//V 1.0
	/*Entity VehID;
	Ped driver;

	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &VehID))
	{
		driver = VEHICLE::GET_PED_IN_VEHICLE_SEAT(VehID, -1);
		if (ENTITY::IS_ENTITY_A_VEHICLE(VehID) && (ENTITY::IS_ENTITY_DEAD(VehID) && (ENTITY::IS_ENTITY_IN_AIR(VehID))))
		{
			RequestControlOfEnt(VehID);
			RequestControlOfEnt(driver);
		}
		AI::CLEAR_PED_TASKS_IMMEDIATELY(driver);
		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), VehID, -1);
	}*/

	//V 2.0
	/*Entity EntityTarget;
	Vehicle Veh;
	Entity VehID;
	Ped driver;
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	Vector3 dir = rot_to_direction(&rot);
	Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	float spawnDistance = get_distance(&camPosition, &playerPosition);
	spawnDistance += 5;
	Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));

	Player tempPed = PLAYER::PLAYER_ID();
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget) && IsKeyPressed(VK_LBUTTON))
		{
			player = VEHICLE::GET_PED_IN_VEHICLE_SEAT(Veh, -1);
			if (ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget) && (ENTITY::IS_ENTITY_DEAD(VehID) && (ENTITY::IS_ENTITY_IN_AIR(VehID))))
			{
				RequestControlOfEnt(VehID);
				RequestControlOfEnt(driver);
			}
			AI::CLEAR_PED_TASKS_IMMEDIATELY(driver);
			PED::SET_PED_INTO_VEHICLE(playerPed, EntityTarget, -1);
		}*/
	Vector3 iCoord;
	if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &iCoord))
	{
		int VehID = VEHICLE::GET_CLOSEST_VEHICLE(iCoord.x, iCoord.y, iCoord.z, 7.0f, 0, 70);
		int driver = VEHICLE::GET_PED_IN_VEHICLE_SEAT(VehID, -1);
		RequestControlOfEnt(VehID);
		RequestControlOfEnt(driver);

		AI::CLEAR_PED_TASKS_IMMEDIATELY(driver);

		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), VehID, -1);
	}
}

/*Vector3 iCoord;
	if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &iCoord))
	{
		int VehID = VEHICLE::GET_CLOSEST_VEHICLE(iCoord.x, iCoord.y, iCoord.z, 7.0f, 0, 70);
		int driver = VEHICLE::GET_PED_IN_VEHICLE_SEAT(VehID, -1);
		if (PLAYER::IS_PLAYER_ONLINE()) {
			RequestControlOfEnt(VehID);
			RequestControlOfEnt(driver);
		}

		AI::CLEAR_PED_TASKS_IMMEDIATELY(driver);

		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), VehID, -1);
	}*/

bool Features::explogun = false;
void Features::ExploGun(bool t)
{
	Vector3 iCoord;
	if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &iCoord))
	{
		FIRE::ADD_EXPLOSION(iCoord.x, iCoord.y, iCoord.z, 25, 10000.0f, true, false, 0);
	}
}

bool Features::agbool = false;
void Features::airstrikeGun(bool t)
{
	Vector3 iCoord;
	if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &iCoord))
	{
		Features::AirStrike2(iCoord);
	}
}

void RequestControl(Entity input)
{
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(input);

	int tick = 0;
	while (tick <= 50)
	{
		if (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(input))
			WAIT(0);
		else
			return;
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(input);
		tick++;
	}
}

bool Features::Gravity = false;
bool grav_target_locked = false;
void Features::GravityGun(bool toggle) {

	Entity EntityTarget;
	DWORD equippedWeapon;
	WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &equippedWeapon, 1);
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	Vector3 dir = rot_to_direction(&rot);
	Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	float spawnDistance = get_distance(&camPosition, &playerPosition);
	spawnDistance += 6;
	Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));


	Player tempPed = PLAYER::PLAYER_ID();

	if (grav_target_locked)
	{
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget) && GetAsyncKeyState(VK_RBUTTON))
		{
			Vector3 EntityTargetPos = ENTITY::GET_ENTITY_COORDS(EntityTarget, 0);
			PLAYER::DISABLE_PLAYER_FIRING(tempPed, true);
			if (ENTITY::IS_ENTITY_A_PED(EntityTarget) && PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1))
			{
				EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
			}

			RequestControl(EntityTarget);

			if (ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget))
				ENTITY::SET_ENTITY_HEADING(
					EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));
			ENTITY::SET_ENTITY_DYNAMIC(tempPed, true);
			ENTITY::SET_ENTITY_ROTATION(tempPed, CAM::GET_GAMEPLAY_CAM_ROT(2).x, CAM::GET_GAMEPLAY_CAM_ROT(2).y, CAM::GET_GAMEPLAY_CAM_ROT(2).z, 2, 1);
			//ENTITY::SET_ENTITY_ROTATION(tempPed, RotationToDirection, 20.0f, 20.0f, 20.0f, 10);
			ENTITY::SET_ENTITY_ALPHA(tempPed, 255, false);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(EntityTarget, spawnPosition.x, spawnPosition.y, spawnPosition.z, 0, 0, 0);

			if (GetAsyncKeyState(VK_LBUTTON))
			{
				ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));
				ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 10000.0f, dir.y * 10000.0f, dir.z * 10000.0f, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);
				grav_target_locked = false;
				PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
			}
		}
	}
	if (!PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
	{
		grav_target_locked = true;
		PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
	}

}

bool Features::teleportgun = false;
void Features::Teleportgun(bool toggle)
{
	if (toggle == true)
	{
		if (is_ped_shooting(PLAYER::PLAYER_PED_ID()))
		{
			float Loc[6];
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD1(PLAYER::PLAYER_PED_ID(), Loc);
			ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), Loc[0], Loc[2], Loc[4], 1, 1, 0, 0);
		}
	}
}

bool Features::infammo = false;
void Features::Infammo(bool toggle)
{
	if (toggle == true)
	{
		WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), true);
	}
	else {
		WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), false);
	}
}

bool Features::osk = false;
void Features::OSK(bool toggle)
{
	if (!osk) {
		Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_BULLET_DMG }, 1.f);
	}
	else {
		Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_BULLET_DMG }, 10000.0f);
	}
}

bool Features::moneygun = false;
void Features::MoneyGun(bool t)
{
	if (t == true)
	{
		if (is_ped_shooting(PLAYER::PLAYER_PED_ID()))
		{
			float loc[6];
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD1(PLAYER::PLAYER_PED_ID(), loc);
			int amount = 2500;

			if ((timeGetTime() - Features::TimePD1) > 100)
			{
				STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
				if (!STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem))) {
					WAIT(0);
				}
				else {
					OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, loc[0], loc[2], loc[4], 0, amount, moneyModel(Features::MoneyItem), FALSE, TRUE);
					Features::droppedMoneyCounter += Features::customDropAmount;
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));

					Features::TimePD1 = timeGetTime();
				}
			}
		}
	}
}

double DegreeToRadian(double n) {
	return n * 0.017453292519943295;
}
Vector3 RotationToDirection(Vector3 rot) {
	double num = DegreeToRadian(rot.z);
	double num2 = DegreeToRadian(rot.x);
	double val = cos(num2);
	double num3 = abs(val);
	rot.x = (float)(-(float)sin(num) * num3);
	rot.y = (float)(cos(num) * num3);
	rot.z = (float)sin(num2);
	return rot;
}
Vector3 multiplyVector(Vector3 vector, float inc) {
	vector.x *= inc;
	vector.y *= inc;
	vector.z *= inc;
	vector._paddingx *= inc;
	vector._paddingy *= inc;
	vector._paddingz *= inc;
	return vector;
}
Vector3 addVector(Vector3 vector, Vector3 vector2) {
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	vector._paddingx += vector2._paddingx;
	vector._paddingy += vector2._paddingy;
	vector._paddingz += vector2._paddingz;
	return vector;
}
bool Features::rapidfirer = false;
void Features::rapidmaker(bool t) {
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
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 50, 1, weaponhash, playerPed, 1, 1, 0xbf800000);
		}
	}
}


//PROTECTION
bool Features::antifog = false;
void Features::Antifog(bool t) {
	   //const auto address = Pattern::Scan(Info::g_MainModuleInfo, "48 8B 0D ? ? ? ? E8 ? ? ? ? 48 8D 0D ? ? ? ? 89");
	  // const auto list = *reinterpret_cast<__int64 *>(address + *reinterpret_cast<int *>(address + 3) + 7);
	 //  *reinterpret_cast<__int64 *>(*reinterpret_cast<__int64 *>(list + 8) + (8 * (0xB07F4711 % *reinterpret_cast<WORD *>(list + 16)))) = 0;
}

bool Features::antitse = false;
void Features::antiTSE(bool t) {
	globalHandle(1382674).At(610).As<int>() = 610; //SP kick
	globalHandle(1382674).At(609).As<int>() = 609; //kick
	globalHandle(1382674).At(536).As<int>() = 536; //ceo kick
	globalHandle(1382674).At(558).As<int>() = 558; //ceo ban
	globalHandle(1377446).At(486).As<int>() = 486; //TP
	globalHandle(1382674).At(499).As<int>() = 499; //TP
	globalHandle(1382674).At(532).As<int>() = 532; //ceo kick 2
	globalHandle(1382674).At(295).As<int>() = 295; //mission
	globalHandle(1382674).At(350).As<int>() = 350; //transaction
	globalHandle(1382674).At(0).As<int>() = 0; //notification
	globalHandle(1382674).At(61).As<int>() = 61; //gentle kick
	globalHandle(1382674).At(584).As<int>() = 584; //kick 2
	globalHandle(1382674).At(2).As<int>() = 2; //rotate cam
	globalHandle(1382674).At(490).As<int>() = 490; //clearwanted
	globalHandle(1382674).At(545).As<int>() = 545; //bribe cops
	globalHandle(1382674).At(433).As<int>() = 433; //insurance
	globalHandle(1382674).At(492).As<int>() = 492; //offradar
	globalHandle(1382674).At(609).As<int>() = 609; //Non-Host kick
	globalHandle(1382674).At(608).As<int>() = 608; //SP kick
	globalHandle(1382674).At(16).As<int>() = 16; //Superkick XXI
	globalHandle(1382674).At(21).As<int>() = 21; //Superkick XX
	globalHandle(1382674).At(677).As<int>() = 677; //Superkick XIX
	globalHandle(1382674).At(601).As<int>() = 601; //Superkick XVIII
	globalHandle(1382674).At(23).As<int>() = 23; //Superkick XVII
	globalHandle(1382674).At(24).As<int>() = 24; //Superkick XVI
	globalHandle(1382674).At(582).As<int>() = 582; //Superkick XV
	globalHandle(1382674).At(599).As<int>() = 599; //Superkick XIV
	globalHandle(1382674).At(577).As<int>() = 577; //Superkick XIII
	globalHandle(1382674).At(576).As<int>() = 576; //Superkick XII
	globalHandle(1382674).At(532).As<int>() = 532; //Superkick XI
	globalHandle(1382674).At(688).As<int>() = 688; //Superkick X
	globalHandle(1382674).At(455).As<int>() = 455; //Superkick IX
	globalHandle(1382674).At(449).As<int>() = 449; //Superkick VIII
	globalHandle(1382674).At(336).As<int>() = 336; //Superkick VII
	globalHandle(1382674).At(294).As<int>() = 294; //Superkick VI
	globalHandle(1382674).At(694).As<int>() = 694; //Superkick V
	globalHandle(1382674).At(602).As<int>() = 602; //Superkick IV
	globalHandle(1382674).At(584).As<int>() = 584; //Superkick III
	globalHandle(1382674).At(610).As<int>() = 610; //Superkick II
	globalHandle(1382674).At(693).As<int>() = 693; //Superkick I
}

bool Features::antiweatherTime = false;
void Features::antiWeatherTime(bool t) {
	Hooking::defuseEvent(GAME_CLOCK_EVENT, t);
	Hooking::defuseEvent(GAME_WEATHER_EVENT, t);
}

bool Features::antiEvery = false;
void Features::AntiEverything(bool t) {
	Hooking::defuseEvent(SCRIPT_ARRAY_DATA_VERIFY_EVENT, t);
	Hooking::defuseEvent(REQUEST_CONTROL_EVENT, t);
	Hooking::defuseEvent(GIVE_CONTROL_EVENT, t);
	Hooking::defuseEvent(WEAPON_DAMAGE_EVENT, t);
	Hooking::defuseEvent(REQUEST_PICKUP_EVENT, t);
	Hooking::defuseEvent(REQUEST_MAP_PICKUP_EVENT, t);
	Hooking::defuseEvent(GAME_CLOCK_EVENT, t);
	Hooking::defuseEvent(GAME_WEATHER_EVENT, t);
	Hooking::defuseEvent(RESPAWN_PLAYER_PED_EVENT, t);
	Hooking::defuseEvent(GIVE_WEAPON_EVENT, t);
	Hooking::defuseEvent(REMOVE_WEAPON_EVENT, t);
	Hooking::defuseEvent(REMOVE_ALL_WEAPONS_EVENT, t);
	Hooking::defuseEvent(REMOVE_ALL_WEAPONS_EVENT, t);
	Hooking::defuseEvent(REMOVE_ALL_WEAPONS_EVENT, t);
	Hooking::defuseEvent(VEHICLE_COMPONENT_CONTROL_EVENT, t);
	Hooking::defuseEvent(FIRE_EVENT, t);
	Hooking::defuseEvent(EXPLOSION_EVENT, t);
	Hooking::defuseEvent(START_PROJECTILE_EVENT, t);
	Hooking::defuseEvent(ALTER_WANTED_LEVEL_EVENT, t);
	Hooking::defuseEvent(CHANGE_RADIO_STATION_EVENT, t);
	Hooking::defuseEvent(RAGDOLL_REQUEST_EVENT, t);
	Hooking::defuseEvent(PLAYER_TAUNT_EVENT, t);
	Hooking::defuseEvent(PLAYER_CARD_STAT_EVENT, t);
	Hooking::defuseEvent(DOOR_BREAK_EVENT, t);
	Hooking::defuseEvent(SCRIPTED_GAME_EVENT, t);
	Hooking::defuseEvent(REMOTE_SCRIPT_INFO_EVENT, t);
	Hooking::defuseEvent(REMOTE_SCRIPT_LEAVE_EVENT, t);
	Hooking::defuseEvent(MARK_AS_NO_LONGER_NEEDED_EVENT, t);
	Hooking::defuseEvent(CONVERT_TO_SCRIPT_ENTITY_EVENT, t);
	Hooking::defuseEvent(SCRIPT_WORLD_STATE_EVENT, t);
	Hooking::defuseEvent(INCIDENT_ENTITY_EVENT, t);
	Hooking::defuseEvent(CLEAR_AREA_EVENT, t);
	Hooking::defuseEvent(CLEAR_RECTANGLE_AREA_EVENT, t);
	Hooking::defuseEvent(NETWORK_REQUEST_SYNCED_SCENE_EVENT, t);
	Hooking::defuseEvent(NETWORK_START_SYNCED_SCENE_EVENT, t);
	Hooking::defuseEvent(NETWORK_UPDATE_SYNCED_SCENE_EVENT, t);
	Hooking::defuseEvent(NETWORK_STOP_SYNCED_SCENE_EVENT, t);
	Hooking::defuseEvent(GIVE_PED_SCRIPTED_TASK_EVENT, t);
	Hooking::defuseEvent(GIVE_PED_SEQUENCE_TASK_EVENT, t);
	Hooking::defuseEvent(NETWORK_CLEAR_PED_TASKS_EVENT, t);
	Hooking::defuseEvent(NETWORK_START_PED_ARREST_EVENT, t);
	Hooking::defuseEvent(NETWORK_START_PED_UNCUFF_EVENT, t);
	Hooking::defuseEvent(NETWORK_SOUND_CAR_HORN_EVENT, t);
	Hooking::defuseEvent(NETWORK_ENTITY_AREA_STATUS_EVENT, t);
	Hooking::defuseEvent(NETWORK_GARAGE_OCCUPIED_STATUS_EVENT, t);
	Hooking::defuseEvent(PED_CONVERSATION_LINE_EVENT, t);
	Hooking::defuseEvent(SCRIPT_ENTITY_STATE_CHANGE_EVENT, t);
	Hooking::defuseEvent(NETWORK_PLAY_SOUND_EVENT, t);
	Hooking::defuseEvent(NETWORK_STOP_SOUND_EVENT, t);
	Hooking::defuseEvent(NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT, t);
	Hooking::defuseEvent(NETWORK_BANK_REQUEST_EVENT, t);
	Hooking::defuseEvent(REQUEST_DOOR_EVENT, t);
	Hooking::defuseEvent(NETWORK_TRAIN_REQUEST_EVENT, t);
	Hooking::defuseEvent(NETWORK_TRAIN_REPORT_EVENT, t);
	Hooking::defuseEvent(NETWORK_INCREMENT_STAT_EVENT, t);
	Hooking::defuseEvent(MODIFY_VEHICLE_LOCK_WORD_STATE_DATA, t);
	Hooking::defuseEvent(REQUEST_PHONE_EXPLOSION_EVENT, t);
	Hooking::defuseEvent(REQUEST_DETACHMENT_EVENT, t);
	Hooking::defuseEvent(KICK_VOTES_EVENT, t);
	Hooking::defuseEvent(GIVE_PICKUP_REWARDS_EVENT, t);
	Hooking::defuseEvent(NETWORK_CRC_HASH_CHECK_EVENT, t);
	Hooking::defuseEvent(BLOW_UP_VEHICLE_EVENT, t);
	Hooking::defuseEvent(NETWORK_SPECIAL_FIRE_EQUIPPED_WEAPON, t);
	Hooking::defuseEvent(NETWORK_RESPONDED_TO_THREAT_EVENT, t);
	Hooking::defuseEvent(NETWORK_SHOUT_TARGET_POSITION, t);
	Hooking::defuseEvent(PICKUP_DESTROYED_EVENT, t);
	Hooking::defuseEvent(UPDATE_PLAYER_SCARS_EVENT, t);
	Hooking::defuseEvent(NETWORK_CHECK_EXE_SIZE_EVENT, t);
	Hooking::defuseEvent(NETWORK_PTFX_EVENT, t);
	Hooking::defuseEvent(NETWORK_PED_SEEN_DEAD_PED_EVENT, t);
	Hooking::defuseEvent(REMOVE_STICKY_BOMB_EVENT, t);
	Hooking::defuseEvent(NETWORK_CHECK_CODE_CRCS_EVENT, t);
	Hooking::defuseEvent(INFORM_SILENCED_GUNSHOT_EVENT, t);
	Hooking::defuseEvent(PED_PLAY_PAIN_EVENT, t);
	Hooking::defuseEvent(CACHE_PLAYER_HEAD_BLEND_DATA_EVENT, t);
	Hooking::defuseEvent(REMOVE_PED_FROM_PEDGROUP_EVENT, t);
	Hooking::defuseEvent(REPORT_MYSELF_EVENT, t);
	Hooking::defuseEvent(REPORT_CASH_SPAWN_EVENT, t);
	Hooking::defuseEvent(ACTIVATE_VEHICLE_SPECIAL_ABILITY_EVENT, t);
	Hooking::defuseEvent(NETWORK_CHECK_CATALOG_CRC, t);
}

bool Features::antiControl = false;
void Features::AntiControl(bool t) {
	Hooking::defuseEvent(REQUEST_CONTROL_EVENT, t);
	Hooking::defuseEvent(GIVE_CONTROL_EVENT, t);
	Hooking::defuseEvent(VEHICLE_COMPONENT_CONTROL_EVENT, t);
}

bool Features::antiPickup = false;
void Features::AntiPickup(bool t) {
	Hooking::defuseEvent(REQUEST_PICKUP_EVENT, t);
	Hooking::defuseEvent(REQUEST_MAP_PICKUP_EVENT, t);
}

bool Features::antiWeapon = false;
void Features::AntiWeapon(bool t) {
	Hooking::defuseEvent(GIVE_WEAPON_EVENT, t);
	Hooking::defuseEvent(REMOVE_WEAPON_EVENT, t);
	Hooking::defuseEvent(REMOVE_ALL_WEAPONS_EVENT, t);
}

bool Features::antiExplosion = false;
void Features::AntiExplosion(bool t) {
	Hooking::defuseEvent(FIRE_EVENT, t);
	Hooking::defuseEvent(EXPLOSION_EVENT, t);
	Hooking::defuseEvent(REQUEST_PHONE_EXPLOSION_EVENT, t);
	Hooking::defuseEvent(BLOW_UP_VEHICLE_EVENT, t);
}

bool Features::antiStars = false;
void Features::AntiStars(bool t) {
	Hooking::defuseEvent(ALTER_WANTED_LEVEL_EVENT, t);
}

bool Features::antiReport = false;
void Features::AntiReport(bool t) {
	//Hooking::defuseEvent(PLAYER_CARD_STAT_EVENT, t);
	Hooking::defuseEvent(REPORT_MYSELF_EVENT, t);
	Hooking::defuseEvent(REPORT_CASH_SPAWN_EVENT, t);
}

bool Features::antiKick = false;
void Features::AntiKick(bool t) {
	//Hooking::defuseEvent(REMOTE_SCRIPT_LEAVE_EVENT, t);
	Hooking::defuseEvent(KICK_VOTES_EVENT, t);
	globalHandle(1377446).At(594).As<int>() = 594; //SP kick
	globalHandle(1377446).At(595).As<int>() = 595; //kick
	globalHandle(1382674).At(584).As<int>() = 584;
}

bool Features::antiFreeze = false;
void Features::AntiFreeze(bool t) {
	Hooking::defuseEvent(RAGDOLL_REQUEST_EVENT, t);
	Hooking::defuseEvent(INCIDENT_ENTITY_EVENT, t);
	Hooking::defuseEvent(CLEAR_AREA_EVENT, t);
	Hooking::defuseEvent(CLEAR_RECTANGLE_AREA_EVENT, t);
	Hooking::defuseEvent(NETWORK_CLEAR_PED_TASKS_EVENT, t);
	Hooking::defuseEvent(NETWORK_SOUND_CAR_HORN_EVENT, t);
	Hooking::defuseEvent(NETWORK_PLAY_SOUND_EVENT, t);
	Hooking::defuseEvent(NETWORK_STOP_SOUND_EVENT, t);
	Hooking::defuseEvent(NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT, t);
}

bool Features::antiSound = false;
void Features::AntiSound(bool t) {
	Hooking::defuseEvent(NETWORK_SOUND_CAR_HORN_EVENT, t);
	Hooking::defuseEvent(NETWORK_PLAY_SOUND_EVENT, t);
	Hooking::defuseEvent(NETWORK_STOP_SOUND_EVENT, t);
	Hooking::defuseEvent(NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT, t);
}

bool Features::antiStat = false;
void Features::AntiStat(bool t) {
	Hooking::defuseEvent(NETWORK_BANK_REQUEST_EVENT, t);
	Hooking::defuseEvent(NETWORK_INCREMENT_STAT_EVENT, t);
}

bool Features::antiPtfx = false;
void Features::AntiPtfx(bool t) {
	Hooking::defuseEvent(NETWORK_PTFX_EVENT, t);
}

bool Features::antiAttachment = false;
void Features::AntiAttachment(bool t) {
	Hooking::defuseEvent(REQUEST_DETACHMENT_EVENT, t);
	char* objects[136] = { "prop_bskball_01", "PROP_MP_RAMP_03", "PROP_MP_RAMP_02", "PROP_MP_RAMP_01", "PROP_JETSKI_RAMP_01", "PROP_WATER_RAMP_03", "PROP_VEND_SNAK_01", "PROP_TRI_START_BANNER", "PROP_TRI_FINISH_BANNER", "PROP_TEMP_BLOCK_BLOCKER", "PROP_SLUICEGATEL", "PROP_SKIP_08A", "PROP_SAM_01", "PROP_RUB_CONT_01B", "PROP_ROADCONE01A", "PROP_MP_ARROW_BARRIER_01", "PROP_HOTEL_CLOCK_01", "PROP_LIFEBLURB_02", "PROP_COFFIN_02B", "PROP_MP_NUM_1", "PROP_MP_NUM_2", "PROP_MP_NUM_3", "PROP_MP_NUM_4", "PROP_MP_NUM_5", "PROP_MP_NUM_6", "PROP_MP_NUM_7", "PROP_MP_NUM_8", "PROP_MP_NUM_9", "prop_xmas_tree_int", "prop_bumper_car_01", "prop_beer_neon_01", "prop_space_rifle", "prop_dummy_01", "prop_rub_trolley01a", "prop_wheelchair_01_s", "PROP_CS_KATANA_01", "PROP_CS_DILDO_01", "prop_armchair_01", "prop_bin_04a", "prop_chair_01a", "prop_dog_cage_01", "prop_dummy_plane", "prop_golf_bag_01", "prop_arcade_01", "hei_prop_heist_emp", "prop_alien_egg_01", "prop_air_towbar_01", "hei_prop_heist_tug", "prop_air_luggtrolley", "PROP_CUP_SAUCER_01", "prop_wheelchair_01", "prop_ld_toilet_01", "prop_acc_guitar_01", "prop_bank_vaultdoor", "p_v_43_safe_s", "p_spinning_anus_s", "prop_can_canoe", "prop_air_woodsteps", "Prop_weed_01", "prop_a_trailer_door_01", "prop_apple_box_01", "prop_air_fueltrail1", "prop_barrel_02a", "prop_barrel_float_1", "prop_barrier_wat_03b", "prop_air_fueltrail2", "prop_air_propeller01", "prop_windmill_01", "prop_Ld_ferris_wheel", "p_tram_crash_s", "p_oil_slick_01", "p_ld_stinger_s", "p_ld_soc_ball_01", "prop_juicestand", "p_oil_pjack_01_s", "prop_barbell_01", "prop_barbell_100kg", "p_parachute1_s", "p_cablecar_s", "prop_beach_fire", "prop_lev_des_barge_02", "prop_lev_des_barge_01", "prop_a_base_bars_01", "prop_beach_bars_01", "prop_air_bigradar", "prop_weed_pallet", "prop_artifact_01", "prop_attache_case_01", "prop_large_gold", "prop_roller_car_01", "prop_water_corpse_01", "prop_water_corpse_02", "prop_dummy_01", "prop_atm_01", "hei_prop_carrier_docklight_01", "hei_prop_carrier_liferafts", "hei_prop_carrier_ord_03", "hei_prop_carrier_defense_02", "hei_prop_carrier_defense_01", "hei_prop_carrier_radar_1", "hei_prop_carrier_radar_2", "hei_prop_hei_bust_01", "hei_prop_wall_alarm_on", "hei_prop_wall_light_10a_cr", "prop_afsign_amun", "prop_afsign_vbike", "prop_aircon_l_01", "prop_aircon_l_02", "prop_aircon_l_03", "prop_aircon_l_04", "prop_airhockey_01", "prop_air_bagloader", "prop_air_blastfence_01", "prop_air_blastfence_02", "prop_air_cargo_01a", "prop_air_chock_01", "prop_air_chock_03", "prop_air_gasbogey_01", "prop_air_generator_03", "prop_air_stair_02", "prop_amb_40oz_02", "prop_amb_40oz_03", "prop_amb_beer_bottle", "prop_amb_donut", "prop_amb_handbag_01", "prop_amp_01", "prop_anim_cash_pile_02", "prop_asteroid_01", "prop_arm_wrestle_01", "prop_ballistic_shield", "prop_bank_shutter", "prop_barier_conc_02b", "prop_barier_conc_05a", "prop_barrel_01a", "prop_bar_stool_01", "prop_basejump_target_01" };
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
			RequestControlOfid(netID);
			ENTITY::DETACH_ENTITY(obj, 1, 1);
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(obj)) {
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(obj, 1, 1);
				ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&obj);
				ENTITY::DELETE_ENTITY(&obj);
			}
		}
	}
}

//REMOTE
//New data type: uint64_t; Old data type: int (hooking.h)
void Features::TSE(int input, int player) {
	unsigned int Bit = (1 << Features::Online::selectedPlayer);
	uint64_t EvEnT[4] = { input, player, 0, 0 };
	Hooking::trigger_script_event(1, EvEnT, 4, Bit);
}

void Features::TSEall(int input) {
	for (int i = 0; i < 33; i++) {
		if (Features::exclude(i)) {
			unsigned int Bit = (1 << i);
			uint64_t EvEnT[4] = { input, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 0, 0 };
			Hooking::trigger_script_event(1, EvEnT, 4, Bit);
		}
	}
}

void Features::ceoban(int player) {
	unsigned int Bit = (1 << player);
	uint64_t playerCeoBan[4] = { 360381720, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), 0, 0 }; //OLD: 1318668309; player; 0; 0x35
	Hooking::trigger_script_event(1, playerCeoBan, 4, Bit);
}

void Features::ceokick(int player) {
	unsigned int Bit = (1 << player);
	uint64_t ceokick[4] = { -1190833098, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), 0, 6 }; //OLD: 585981075; player; 0; 0x35
	Hooking::trigger_script_event(1, ceokick, 4, Bit);
}

void Features::kick(int player) {
	unsigned int Bit = (1 << Features::Online::selectedPlayer);
	uint64_t kick[4] = { 769347061, player, 0, 0 }; //OLD: 1394869423
	Hooking::trigger_script_event(1, kick, 4, Bit);
}

void Features::sp_kick(int player) {
	unsigned int Bit = (1 << Features::Online::selectedPlayer);
	uint64_t sp_crash[4] = { 999090520, player, 0, 0 }; //OLD: 2101106911; player; 0; 0
	Hooking::trigger_script_event(1, sp_crash, 4, Bit);
}

void Features::forceMission(int player) {
	unsigned int Bit = (1 << Features::Online::selectedPlayer);
	uint64_t send_to_mission[9] = { -1571039706, player, 0, 0, 0, -1, 1, 1, 0 }; //TODO: fix!; OLD: 18446744071959282160
	Hooking::trigger_script_event(1, send_to_mission, 9, Bit); //par2 = 4: Show message
}

void Features::infiniteLoading(int player) {
	unsigned int Bit = (1 << player);
	uint64_t infiniteload[9] = { 1000837481, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), 0, -1, 1, 115, 0, 0, 0 }; //OLD: -328868154, player, 0, -1, 1, 115, 0, 0, 0
	Hooking::trigger_script_event(1, infiniteload, 4, Bit);
}

void Features::sound(int player) {
	unsigned int Bit = (1 << Features::Online::selectedPlayer);
	uint64_t soundspam[4] = { 4119492672, player, 0, 1 };
	Hooking::trigger_script_event(1, soundspam, 4, Bit);
}

void Features::remoteTP(int player, int TPid) {
	//TPid = 1 - 115
	unsigned int Bit = (1 << player);
	uint64_t rteleport[9] = { 1000837481, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), 0, -1, 1, TPid, 0, 0, 0 }; //TODO: fix!
	Hooking::trigger_script_event(1, rteleport, 9, Bit);
}

void Features::remoteBan(int player) {
	unsigned int Bit = (1 << Features::Online::selectedPlayer);
	auto var0 = globalHandle(1625435 + 1 + Features::Online::selectedPlayer * 560 + 491).As<std::uint64_t>();
	auto var1 = globalHandle(1643357 + 9).As<std::uint64_t>();
	uint64_t argss[8] = { -1920290846, player, 10000, 0, 0, var0, var1, var1 };
	Hooking::trigger_script_event(1, argss, 8, Bit);
	uint64_t args[3] = { -120668417, player, 48 };
	Hooking::trigger_script_event(1, args, 3, Bit);
	Features::remoteXXX(player);
	SUPERKICK(Features::Online::selectedPlayer);
}

void Features::inviteSpam(int player, int a) {
	unsigned int Bit = (1 << Features::Online::selectedPlayer);
	uint64_t invite[3] = { 4119492672, player, a };
	Hooking::trigger_script_event(1, invite, 4, Bit);
}

void Features::inviteSpamEvery(int a) {
	for (int i = 0; i < 33; i++) {
		unsigned int Bit = (1 << i);
		uint64_t EvEnT[3] = { 4119492672, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), a };
		Hooking::trigger_script_event(1, EvEnT, 4, Bit);
	}
}

bool Features::iLoopBool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::inviteLoop(Player p, int a) {
	unsigned int Bit = (1 << p);
	uint64_t invite[3] = { 4119492672, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), a };
	Hooking::trigger_script_event(1, invite, 4, Bit);
}

bool Features::iLoopBoolall = false;
void Features::inviteLoopAll(bool t, int a) {
	for (int i = 0; i < 33; i++) {
		if (Features::exclude(i)) {
			unsigned int Bit = (1 << i);
			uint64_t invite[3] = { 4119492672, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), a };
			Hooking::trigger_script_event(1, invite, 4, Bit);
		}
	}
}

void Features::sendToRoller(Player p) {
	unsigned int Bit = (1 << p);
	uint64_t coaster[2] = { 298543124, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p) };
	Hooking::trigger_script_event(1, coaster, 2, Bit);
}

void Features::remoteCrash(Player p) {
	unsigned int Bit = (1 << p);
	uint64_t crash[4] = { 994306218, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0, 0 }; //UNTESTED
	Hooking::trigger_script_event(1, crash, 4, Bit);
} 

void Features::remoteStealth(Player p) { //DOESN'T WORK
	unsigned int Bit = (1 << p);
	uint64_t stealth[9] = { 325218053, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0, 1, 0, 1, 4294967295, 0, 63781 };
	Hooking::trigger_script_event(1, stealth, 9, Bit);
}

void Features::remoteXXX(Player p) {	
	unsigned int Bit = (1 << p);
	Player q = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);	
	uint64_t e1[4] = { -1765004803, q, 0, 6169 };
	uint64_t e2[3] = { 256098994, q, -1 };
	uint64_t e3[5] = { -1033806317, q, 2069146067, 206700458, 50142 };
	uint64_t e4[4] = { -1068974025, q, 0, 8445 };
	uint64_t e5[2] = { -1068974025, q };
	uint64_t e6[4] = { 604911516, q, 0, 6720 };
	uint64_t e7[10] = { -1177364063, q, 5, -1002277638, 1134468592, 1130250744, -1002277246, 1134500793, 1130250744, -1002278993 };
	uint64_t e8[4] = { 1402398442, q, 0, 1383 };
	uint64_t e9[4] = { -784649388, q, 0, 6666 };
	uint64_t e10[4] = { -784649388, q, 0, 1230 };
	uint64_t e11[5] = { -1033806317, q, -420911112, -276983856, 29033 };
	uint64_t e12[4] = { 566035618, q, 313864371, 1172 };
	uint64_t e13[4] = { 566035618, q, -250676059, 5200 };
	uint64_t e14[5] = { 1965110671, q, q, 0, 45 };
	uint64_t e15[4] = { -1765004803, q, 0, 9352 };
	uint64_t e16[4] = { -784649388, q, 0, 8054 };
	uint64_t e17[4] = { 566035618, q, 507139867, 8015 };
	uint64_t e18[4] = { 713068249, q, -1476055326, 500 };
	uint64_t e19[4] = { 1746709519, q, 0, 1246 };
	uint64_t e20[4] = { -1883549171, q, 0, 2374 };
	uint64_t e21[5] = { 1965110671, q, q, 1, 35 };
	uint64_t e22[5] = { 959496411, q, q, 0, 45 };
	uint64_t e23[4] = { 1613784162, q, 0, 5628 };
	uint64_t e24[2] = { -402989740, q };
	uint64_t e25[4] = { 566035618, q, -250676059, 7638 };
	uint64_t e26[4] = { -1883549171, q, 0, 881 };
	uint64_t e27[4] = { -784649388, q, 0, 3315 };
	uint64_t e28[4] = { 566035618, q, 507139867, 5961 };
	Hooking::trigger_script_event(1, e1, 4, Bit);
	Hooking::trigger_script_event(1, e2, 4, Bit);
	Hooking::trigger_script_event(1, e3, 4, Bit);
	Hooking::trigger_script_event(1, e4, 4, Bit);
	Hooking::trigger_script_event(1, e5, 4, Bit);
	Hooking::trigger_script_event(1, e6, 4, Bit);
	Hooking::trigger_script_event(1, e7, 4, Bit);
	Hooking::trigger_script_event(1, e8, 4, Bit);
	Hooking::trigger_script_event(1, e9, 4, Bit);
	Hooking::trigger_script_event(1, e10, 4, Bit);
	Hooking::trigger_script_event(1, e11, 4, Bit);
	Hooking::trigger_script_event(1, e12, 4, Bit);
	Hooking::trigger_script_event(1, e13, 4, Bit);
	Hooking::trigger_script_event(1, e14, 4, Bit);
	Hooking::trigger_script_event(1, e15, 4, Bit);
	Hooking::trigger_script_event(1, e16, 4, Bit);
	Hooking::trigger_script_event(1, e17, 4, Bit);
	Hooking::trigger_script_event(1, e18, 4, Bit);
	Hooking::trigger_script_event(1, e19, 4, Bit);
	Hooking::trigger_script_event(1, e20, 4, Bit);
	Hooking::trigger_script_event(1, e21, 4, Bit);
	Hooking::trigger_script_event(1, e22, 4, Bit);
	Hooking::trigger_script_event(1, e23, 4, Bit);
	Hooking::trigger_script_event(1, e24, 4, Bit);
	Hooking::trigger_script_event(1, e25, 4, Bit);
	Hooking::trigger_script_event(1, e26, 4, Bit);
	Hooking::trigger_script_event(1, e27, 4, Bit);
	Hooking::trigger_script_event(1, e28, 4, Bit);
}

bool Features::disableCEObool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::disableCEO(Player target) {
	unsigned int Bit = (1 << target);
	uint64_t ceokick[4] = { -1190833098, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), 0, 6 };
	Hooking::trigger_script_event(1, ceokick, 4, Bit);
	uint64_t ceoban[4] = { 360381720, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), 0, 0 };
	Hooking::trigger_script_event(1, ceoban, 4, Bit);
}

bool Features::disableCEOallBool = false;
void Features::disableCEOall(bool t) {
	for (int i = 0; i < 33; i++) {
		if (Features::exclude(i)) {
			unsigned int Bit = (1 << i);
			uint64_t ceokick[4] = { -1190833098, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 0, 6 };
			Hooking::trigger_script_event(1, ceokick, 4, Bit);
			uint64_t ceoban[4] = { 360381720, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 0, 0 };
			Hooking::trigger_script_event(1, ceoban, 4, Bit);
		}
	}
}

bool Features::transSpamBool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::trasactionSpam(Player p) {
	unsigned int Bit = (1 << p);
	auto var0 = globalHandle(1625435 + 1 + p * 560 + 491).As<std::uint64_t>();
	auto var1 = globalHandle(1643357 + 9).As<std::uint64_t>();
	//uint64_t transaction[10] = { -313275313, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), INT_MAX , 10000, 1, -1135378931, -1985150258, 0, 1474183246, 1445302971 };
	uint64_t transaction[8] = { -1920290846, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 10000, 0, 0, var0, var1, var1 };
	Hooking::trigger_script_event(1, transaction, 8, Bit);
}

void Features::screen(Player p) {
	unsigned int Bit = (1 << p);
	uint64_t banner[4] = { -181444979, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0, 0 };
	Hooking::trigger_script_event(1, banner, 4, Bit);
} //TO DO: Fix

void Features::ceokick2(Player p) {
	unsigned int Bit = (1 << p);
	uint64_t ceokick[4] = { -1190833098, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 1, 5 };
	Hooking::trigger_script_event(1, ceokick, 4, Bit);
}

void Features::ceoban2(Player p) {
	unsigned int Bit = (1 << p);
	uint64_t ceoban[4] = { 360381720, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 1, 5 };
	Hooking::trigger_script_event(1, ceoban, 4, Bit);
}

void Features::clubkick(Player p) {
	unsigned int Bit = (1 << p);
	uint64_t ckick[4] = { -2105858993, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0, 0 };
	Hooking::trigger_script_event(1, ckick, 4, Bit);
}

bool Features::remoteOrBool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::remoteoffradar(Player p) {
	globalHandle(2423801).At(p, 413).At(200).As<int>() = 1;
	globalHandle(2437022).At(70).As<int>() = NETWORK::GET_NETWORK_TIME();
}

bool Features::remoteOrBoolAll = false;
void Features::remoteoffradarall(bool t) {
	for (int i = 0; i < 33; i++) {
		if (Features::exclude(i)) {
			globalHandle(2423801).At(i, 413).At(200).As<int>() = 1;
			globalHandle(2437022).At(70).As<int>() = NETWORK::GET_NETWORK_TIME();
		}
	}
}

bool Features::tspamallbool = false;
void Features::tspamall(bool t) {
	for (int i = 0; i < 33; i++) {
		if (Features::exclude(i)) {
			unsigned int Bit = (1 << i);
			auto var0 = globalHandle(1625435 + 1 + i * 560 + 491).As<std::uint64_t>();
			auto var1 = globalHandle(1643357 + 9).As<std::uint64_t>();
			//uint64_t transaction[10] = { -313275313, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), INT_MAX , 10000, 1, -1135378931, -1985150258, 0, 1474183246, 1445302971 };
			uint64_t transaction[8] = { -1920290846, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 10000, 0, 0, var0, var1, var1 };
			Hooking::trigger_script_event(1, transaction, 8, Bit);
		}
	}
}

void Features::remoteSpectateMsg(Player p) {
	Ped player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	unsigned int Bit = (1 << p);
	auto var0 = globalHandle(2437022).At(70).As<std::uint64_t>();
	auto var1 = NETWORK::GET_NETWORK_TIME();
	uint64_t spectate[7] = { 1344161996, player, var0, var1, 1, 1, 0 };
	Hooking::trigger_script_event(1, spectate, 7, Bit);
}

//Index:
//0: banked
//1: removed
//2: stolen
void Features::remoteMoneyMsg(Player p, int index, int amount) {
	uint64_t mode = -1550586884;
	Ped player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	if (index == 0) {
		mode = -1550586884;
	}
	else if (index == 1) {
		mode = 2110027654;
	}
	else if (index == 2) {
		mode = -1432462772;
	}
	unsigned int Bit = (1 << p);
	uint64_t args[4] = { 713068249, player, mode, amount };
	Hooking::trigger_script_event(1, args, 4, Bit);
}

bool Features::gentleKbool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::gentleKick(Player p) {
	Ped player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	unsigned int Bit = (1 << p);
	uint64_t args[2] = { 325218053, player };
	Hooking::trigger_script_event(1, args, 2, Bit);
}

void Features::banner2(Player p) {
	Ped player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	unsigned int Bit = (1 << p);
	uint64_t args[3] = { 713068249, player, 1009196241 };
	Hooking::trigger_script_event(1, args, 3, Bit);
}

void Features::kick2(Player p) {
	Ped player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	unsigned int Bit = (1 << p);
	uint64_t args[3] = { -120668417, player, 48 };
	Hooking::trigger_script_event(1, args, 3, Bit);
}

bool Features::camforwbool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::rotateCam(Player p) {
	Ped player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	unsigned int Bit = (1 << p);
	uint64_t args[3] = { 566035618, player, -1432407380 };
	Hooking::trigger_script_event(1, args, 3, Bit);
}

void Features::notification(Player p, int id) {
	uint64_t nID = 1009196241;
	switch (id) {
	case 0: nID = 1009196241; break; //Same as banner 2
	case 1: nID = 650772739; break;
	case 2: nID = -89603292; break;
	case 3: nID = -1476055326; break;
	case 4: nID = 1723217930; break;
	case 5: nID = -210487359; break;
	case 6: nID = -957727376; break;
	case 7: nID = 1369534593; break;
	case 8: nID = -53425260; break;
	case 9: nID = 554851531; break;
	case 10: nID = -130461309; break;
	}
	Ped player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	unsigned int Bit = (1 << p);
	uint64_t args[3] = { 713068249, player, nID };
	Hooking::trigger_script_event(1, args, 3, Bit);
}

void Features::rsTest(Player p) {
	Ped q = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	unsigned int Bit = (1 << p);
	uint64_t s1[8] = { 1342896039, q, 1142131160, 1169240025, 1144753664, 1121711964, -1903012613, -582214453 };
	Hooking::trigger_script_event(1, s1, 4, Bit);
	uint64_t s2[5] = { -1033806317, q, -566387422, 1307743691, 18858 };
	Hooking::trigger_script_event(1, s2, 4, Bit);
	uint64_t s3[4] = { 1613784162, q, 0, 6693 };
	Hooking::trigger_script_event(1, s3, 4, Bit);
	uint64_t s4[4] = { -784649388, q, 0, 5197 };
	Hooking::trigger_script_event(1, s4, 4, Bit);
	uint64_t s5[4] = { 1402398442, q, 0, 3676 };
	Hooking::trigger_script_event(1, s5, 4, Bit);
	uint64_t s6[4] = { -1883549171, q, 0, 9332 };
	Hooking::trigger_script_event(1, s6, 4, Bit);
	uint64_t s7[10] = { -1177364063, q, 5, 1108842688, -1003554390, 1110236589, 1113347048, -1004371543, 1106642187, 1083876224 };
	Hooking::trigger_script_event(1, s7, 4, Bit);
	uint64_t s8[2] = { -928998106, q };
	Hooking::trigger_script_event(1, s8, 4, Bit);
	uint64_t s9[4] = { 1613784162, q, 0, 2253 };
	Hooking::trigger_script_event(1, s9, 4, Bit);
	uint64_t s10[4] = { -1068974025, q, 0, 6043 };
	Hooking::trigger_script_event(1, s10, 4, Bit);
	uint64_t s11[5] = { -13491081, q, 1, 4, 1590023940 };
	Hooking::trigger_script_event(1, s11, 4, Bit);
	uint64_t s12[4] = { -1765004803, q, 0, 7911 };
	Hooking::trigger_script_event(1, s12, 4, Bit);
	uint64_t s13[5] = { 1965110671, q, q, 0, 26 };
	Hooking::trigger_script_event(1, s13, 4, Bit);
	uint64_t s14[2] = { 2115490621, q };
	Hooking::trigger_script_event(1, s14, 4, Bit);
	uint64_t s15[7] = { -1943214963, q, 2074274, 0, 0, 33, 1 };
	Hooking::trigger_script_event(1, s15, 4, Bit);
	uint64_t s16[4] = { 1402398442, q, 0, 6433 };
	Hooking::trigger_script_event(1, s16, 4, Bit);
	uint64_t s17[4] = { 1402398442, q, 0, 8359 };
	Hooking::trigger_script_event(1, s17, 4, Bit);
	uint64_t s18[5] = { 959496411, q, q, 0, 26 };
	Hooking::trigger_script_event(1, s18, 4, Bit);
	uint64_t s19[10] = { 1655324708, q, 0, 63, 0, -1002212455, 1134875516, 1126105521, 1279612788, 1378708272 };
	Hooking::trigger_script_event(1, s19, 4, Bit);
}


char* Features::getChatMessage() {
	//uint64_t sig = Pattern::Scan(Info::g_MainModuleInfo, "48 8B C4 48 89 58 08 48 89 78 10 55 48 8D 68 A1 48 81 EC ? 01 ? ? 48 8B B9 10 02 ? ?");
	//char* result = *reinterpret_cast<char**>(sig);
	char* result = "";
	return result;
}

//int eventGroup, int eventIndex, int *argStruct, int argStructSize
bool Features::dumpBool = false;
bool Features::msgBool = false;
int Features::evIndex = 10;

bool eventData(int eventGroup, int eventIndex, uint64_t* argv, unsigned int argc)
{
	auto result = Hooking::get_script_event_data(eventGroup, eventIndex, argv, argc);

	if (result)
	{
		Log::Msg("Script event group: %i", eventGroup);
		Log::Msg("Script event index: %i", eventIndex);
		Log::Msg("Script event argcount: %i", argc);
		Log::Msg(PLAYER::GET_PLAYER_NAME(argv[1]));
		for (unsigned int i = 0; i < argc; ++i) {
			Log::Msg("Script Event Args[%i]: %i", i, argv[i]);
		}
		Log::Msg("_____________________");
	}

	return result;
}

uint64_t Features::dumpEvent(bool t) {
	uint64_t Var0[10];
	if (eventData(1, 0, Var0, 10)) {
		for (int i = 0; i < 10; i++) {
			return Var0[i];
		}
	}
}

void Features::logEvent(bool msg) {
	int result1 = Features::dumpEvent(true);
	std::string result2 = std::to_string(result1);
	//Log::Msg(result2.c_str());
	if (msg) {
		notifyMap(result2.c_str());
	}
}
//Money after mission: 325218053; func_13744

//Mission: -1571039706, func_13651 (leck mich)

//uint64_t invite[3] = { 4119492672, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), [x] };
//x = 1: Yacht
//x = 2: Office
//x = 3: Clubhouse
//x = 6: Garage
//x = 7: Tuner
//x = 8: Apartment

//VEHICLE

void Features::vehControl(Player p) {
	Player victim = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
		RequestControlOfEnt(PED::GET_VEHICLE_PED_IS_USING(victim));
		RequestControlOfEnt(victim);
		//Features::spawnincar = true;
		//Features::cargodmodebool = true;
		//Features::playerinvisibility = true;
		Features::orbool = true;
		//Features::spawn_vehicle("deluxo");
		//ENTITY::SET_ENTITY_VISIBLE(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), false);
		Features::Online::TeleportToPlayer(victim);
		attachCar(victim);
		VEHICLE::SET_VEHICLE_DOORS_LOCKED_FOR_ALL_PLAYERS(PED::GET_VEHICLE_PED_IS_USING(victim), true);
		Features::fastRun = true;
}

bool Features::carinvisbool = false;
void Features::carinvis(bool t) {
	if (t) {
		ENTITY::SET_ENTITY_VISIBLE(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), false);
	}
	else {
		ENTITY::SET_ENTITY_VISIBLE(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), true);
	}
}

bool Features::boostbool = false;
void Features::carboost(bool toggle) {
	if (PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER::PLAYER_ID()))
	{
		Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
		if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Veh))
		{
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, Features::hornboostSpeed);
			GRAPHICS::_START_SCREEN_EFFECT("RaceTurbo", 0, true);
		}
	}
	else {
		GRAPHICS::_STOP_SCREEN_EFFECT("RaceTurbo");
	}
}

bool Features::remoteCarboostbool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::remoteCarboost(Player p) {
	if (PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p)))
	{
		Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), false);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
		if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Veh))
		{
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, 50);
		}
	}
}

void Features::flipup()
{
	VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false));
}

/*void Features::BypassOnlineVehicleKick()
{
	Player player = PLAYER::PLAYER_ID();
	int var;
	DECORATOR::DECOR_REGISTER("Player_Vehicle", 3);
	DECORATOR::DECOR_REGISTER("Veh_Modded_By_Player", 3);
	DECORATOR::DECOR_SET_INT(vehicle, "Player_Vehicle", NETWORK::_NETWORK_HASH_FROM_PLAYER_HANDLE(player));
	DECORATOR::DECOR_SET_INT(vehicle, "Veh_Modded_By_Player", GAMEPLAY::GET_HASH_KEY(PLAYER::GET_PLAYER_NAME(player)));
	DECORATOR::DECOR_SET_INT(vehicle, "Not_Allow_As_Saved_Veh", 0);
	if (DECORATOR::DECOR_EXIST_ON(vehicle, "MPBitset"))
		var = DECORATOR::DECOR_GET_INT(vehicle, "MPBitset");
	GAMEPLAY::SET_BIT(&var, 3);
	DECORATOR::DECOR_SET_INT(vehicle, "MPBitset", var);
	VEHICLE::SET_VEHICLE_IS_STOLEN(vehicle, false);
}*/

bool Features::spawnincar = true;
bool Features::spawnmaxed = true;
int Features::pricustomred;
int Features::pricustomgreen;
int Features::pricustomblue;
int Features::seccustomred;
int Features::seccustomgreen;
int Features::seccustomblue;
bool Features::setcustompricolour;
bool Features::setcustomseccolour;
bool Features::spawnwithblip = false;
void Features::spawn_vehicle(std::string vehicle)
{
	//Features::fuck_me_sideways(1);
	Hash model = GAMEPLAY::GET_HASH_KEY((char*)_strdup(vehicle.c_str()));
	if (STREAMING::IS_MODEL_VALID(model))
	{
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
		float forward = 5.f;
		float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
		float xVector = forward * sin(degToRad(heading)) * -1.f;
		float yVector = forward * cos(degToRad(heading));
		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z, heading, true, true);

		spawned[spawnIndex] = veh;
		spawnedHash[spawnIndex] = GAMEPLAY::GET_HASH_KEY((char*)vehicle.c_str());
		spawnIndex++;
		
		Vehicle VEHICLE1 = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true);
		Vector3 coords1 = ENTITY::GET_ENTITY_COORDS(VEHICLE1, false);

		RequestControlOfEnt(veh);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
		auto networkId = NETWORK::VEH_TO_NET(veh);
		ENTITY::_SET_ENTITY_SOMETHING(veh, true);
		if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(veh))
			NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);
		if (spawnincar)
		{
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		}
		if (spawnmaxed)
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			for (int i = 0; i < 50; i++)
			{
				VEHICLE::SET_VEHICLE_MOD(veh, i, VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) - 1, false);
			}
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, "X-Force");
		}
		if (Features::setcustompricolour)
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, Features::pricustomred, Features::pricustomgreen, Features::pricustomblue);
		}
		if (Features::setcustomseccolour)
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, Features::seccustomred, Features::seccustomgreen, Features::seccustomblue);
		}
		if (spawnwithblip)
		{
			UI::SET_BLIP_COLOUR(225, 67);
			UI::SET_BLIP_COORDS(225, coords1.x, coords1.y, coords1.z);
		}
		if (cargodmodebool) {
			Features::cargodmode3(veh);
		}
		WAIT(150);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}
}

int r = 255, g = 0, b = 0;
void RGBFade()
{
	if (r > 0 && b == 0) {
		r--;
		g++;
	}
	if (g > 0 && r == 0) {
		g--;
		b++;
	}
	if (b > 0 && g == 0) {
		r++;
		b--;
	}
}
bool Features::Rainb = false;
void Features::Rainbow(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (Rainbow)
	{
		RGBFade();
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		DWORD model = ENTITY::GET_ENTITY_MODEL(veh);

		if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, r, g, b);
		}
	}
}
bool Features::Rcolor = false;
void Features::RainbowColor(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (toggle)
	{
		RGBFade();
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		DWORD model = ENTITY::GET_ENTITY_MODEL(veh);

		if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, r, g, b);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, r, g, b);
		}
	}
}
bool Features::Rneon = false;
void Features::RainbowNeon(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (RainbowNeon)
	{
		RGBFade();
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		DWORD model = ENTITY::GET_ENTITY_MODEL(veh);

		if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			if (VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 0) && VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 1) && VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 2) && VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 3))
			{
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, r, g, b);
			}
			else
			{
				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, 1);
				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, 1);
				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, 1);
				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, 1);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, r, g, b);
			}
		}
	}
}

bool Features::cargodmodebool = true;
void Features::cargodmode()
{

		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::SET_ENTITY_INVINCIBLE(vehicle, Features::cargodmodebool);
		ENTITY::SET_ENTITY_PROOFS(vehicle, Features::cargodmodebool, Features::cargodmodebool, Features::cargodmodebool, Features::cargodmodebool, Features::cargodmodebool, Features::cargodmodebool, Features::cargodmodebool, Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, false);
		VEHICLE::SET_VEHICLE_ENVEFF_SCALE(vehicle, 0.f);
		VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_DAMAGE(vehicle, Features::cargodmodebool);
		VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(vehicle, Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(vehicle, !Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_CAN_BREAK(vehicle, !Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE(vehicle, !Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(vehicle, !Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, !Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(vehicle, !Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_FIXED(vehicle);
		VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, true);
		VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
		VEHICLE::SET_VEHICLE_ENVEFF_SCALE(vehicle, 0.f);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 0.f);
		VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
		if (VEHICLE::_IS_VEHICLE_DAMAGED(vehicle))
		{
			for (int i = 0; i < 10; i++)
			{
				try {
					VEHICLE::SET_VEHICLE_TYRE_FIXED(vehicle, i);
				}
				catch (...) {
					return;
				}
			}
		}
}

void Features::cargodmode2(Player playa)
{

	if (PED::IS_PED_IN_ANY_VEHICLE(playa, false))
	{
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(playa, false);
		ENTITY::SET_ENTITY_INVINCIBLE(vehicle, Features::cargodmodebool);
		ENTITY::SET_ENTITY_PROOFS(vehicle, Features::cargodmodebool, Features::cargodmodebool, Features::cargodmodebool, Features::cargodmodebool, Features::cargodmodebool, Features::cargodmodebool, Features::cargodmodebool, Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, false);
		VEHICLE::SET_VEHICLE_ENVEFF_SCALE(vehicle, 0.f);
		VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_DAMAGE(vehicle, Features::cargodmodebool);
		VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(vehicle, Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(vehicle, !Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_CAN_BREAK(vehicle, !Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE(vehicle, !Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(vehicle, !Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, !Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(vehicle, !Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_FIXED(vehicle);
		VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, true);
		VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
		VEHICLE::SET_VEHICLE_ENVEFF_SCALE(vehicle, 0.f);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 0.f);
		VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
		if (VEHICLE::_IS_VEHICLE_DAMAGED(vehicle))
		{
			for (int i = 0; i < 10; i++)
			{
				try {
					VEHICLE::SET_VEHICLE_TYRE_FIXED(vehicle, i);
				}
				catch (...) {
					return;
				}
			}
		}
	}
}

void Features::maxvehicle1()
{
	Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
	VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
	for (int i = 0; i < 50; i++)
	{
		VEHICLE::SET_VEHICLE_MOD(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
	}
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "X-Force");
}

void Features::maxvehicle2(Player playa)
{
	Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(playa, false);
	VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
	for (int i = 0; i < 50; i++)
	{
		VEHICLE::SET_VEHICLE_MOD(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
	}
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "X-Force");
}

bool Features::vehjump = false;
void Features::VehJump(bool toggle)
{
	if (GetAsyncKeyState(VK_SPACE) && PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1)) {
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0 + ENTITY::GET_ENTITY_FORWARD_X(veh), 0 + ENTITY::GET_ENTITY_FORWARD_Y(veh), 7, 0, 0, 0, 1, 0, 1, 1, 1, 1);
	}
}

bool Features::dowbool = false;
void Features::DriveOnWater(bool toggle) {
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	DWORD model = ENTITY::GET_ENTITY_MODEL(veh);
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
	float height = 0;
	WATER::_SET_WAVES_INTENSITY(height);
	if ((!(VEHICLE::IS_THIS_MODEL_A_PLANE(ENTITY::GET_ENTITY_MODEL(veh)))) && WATER::GET_WATER_HEIGHT_NO_WAVES(pos.x, pos.y, pos.z, &height)) {
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
			while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
			container = OBJECT::CREATE_OBJECT(model, pos.x, pos.y, pos.z, 1, 1, 0);
			RequestControlOfEnt(container);
			ENTITY::FREEZE_ENTITY_POSITION(container, 1);
			ENTITY::SET_ENTITY_ALPHA(container, 0, 1);
			ENTITY::SET_ENTITY_VISIBLE(container, 0);
		}
	}
	else {
		Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, GAMEPLAY::GET_HASH_KEY("prop_container_ld2"), 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(container)) {
			RequestControlOfEnt(container);
			ENTITY::SET_ENTITY_COORDS(container, 0, 0, -1000.0f, 0, 0, 0, 1);
			WAIT(10);
			ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&container);
			ENTITY::DELETE_ENTITY(&container);
			WATER::_RESET_WAVES_INTENSITY();
		}
	}
}

//PLAYER
/*bool Features::godmodeRem[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::remGod(Player p) {
	Player godus = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	RequestControlOfEnt(godus);
	ENTITY::SET_ENTITY_PROOFS(godus, true, true, true, true, true, true, true, true);
	ENTITY::SET_ENTITY_PROOFS(godus, true, true, true, true, true, true, false, true);
}*/
//Causes kick?

/*bool Features::karmaa[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::karma(Player p) {
	Player krishna = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	RequestControlOfEnt(krishna);
	if (PLAYER::IS_PLAYER_DEAD(krishna)) {
		Player killer = PED::GET_PED_SOURCE_OF_DEATH(krishna);
		RequestControlOfEnt(killer);
		for (int i = 0; i < 10; i++) {
			FIRE::ADD_EXPLOSION(coordsOf(killer).x, coordsOf(killer).y, coordsOf(killer).z, 5, 10.0f, true, false, false);
		}
	}
}*/
//Causes kick?

void Features::chesesGlitch(Player penis) {
	for (int i = 0; i < 10; i++) {
		RequestControlOfEnt(PED::GET_VEHICLE_PED_IS_USING(penis));
		RequestControlOfEnt(penis);
		AttachThingToThing(PED::GET_VEHICLE_PED_IS_USING(penis), PLAYER::PLAYER_PED_ID(), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	}
	Sleep(5000);
	Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_ENTITY_HEALTH }, 0);
}

//UNTESTED
bool Features::talkbool1 = false;
void Features::talkStuff1(bool t) {
	for (int i = 0; i < 33; i++) {
		if (Features::exclude(i)) {
			Player playa = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			if (NETWORK::NETWORK_IS_PLAYER_TALKING(playa)) {
				Vector3 victimCoords = ENTITY::GET_ENTITY_COORDS(playa, 0);
				for (int j = 0; j < 10; j++) {
					FIRE::ADD_EXPLOSION(victimCoords.x, victimCoords.y, victimCoords.z, 37, 5.0f, true, false, false);
				}
			}
		}
	}
}

bool Features::talkbool2 = false;
void Features::talkStuff2(bool t) {
	for (int i = 0; i < 33; i++) {
		if (Features::exclude(i)) {
			Player playa = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			if (NETWORK::NETWORK_IS_PLAYER_TALKING(playa)) {
				Vector3 victimCoords = ENTITY::GET_ENTITY_COORDS(playa, 0);
				Features::kick(playa);
			}
		}
	}
}

void Features::kicknibba(Player playa) {
	NETWORK::NETWORK_SESSION_KICK_PLAYER(playa);
}

bool Features::freezed[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::Freezer(Player target) {
	Ped vic = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
	AI::CLEAR_PED_TASKS_IMMEDIATELY(vic);
	AI::CLEAR_PED_TASKS(vic);
	AI::CLEAR_PED_SECONDARY_TASK(vic);
}

bool Features::spectate[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::specter(Player target)
{
	if (Features::spectate[target] == true) {
		NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(Features::spectate[target], PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target));
	}
	else if (Features::spectate[target] == false) {
		NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(true, PLAYER::PLAYER_PED_ID());
	}
}

void Features::AirStrike1(Player playa)
{
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(playa, 0);
	GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y, coords.z + 5, coords.x, coords.y, coords.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), PLAYER::PLAYER_PED_ID(), 1, 1, 100);
	GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y + 5, coords.z + 5, coords.x, coords.y, coords.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), PLAYER::PLAYER_PED_ID(), 1, 1, 130);
	GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x + 3, coords.y, coords.z + 5, coords.x, coords.y, coords.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), PLAYER::PLAYER_PED_ID(), 1, 1, 80);
	GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x - 5, coords.y, coords.z + 5, coords.x, coords.y, coords.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), PLAYER::PLAYER_PED_ID(), 1, 1, 110);
	GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y - 2, coords.z + 5, coords.x, coords.y, coords.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), PLAYER::PLAYER_PED_ID(), 1, 1, 150);
}

void Features::AirStrike2(Vector3 coords) {
	GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y, coords.z + 5, coords.x, coords.y, coords.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), PLAYER::PLAYER_PED_ID(), 1, 1, 100);
	GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y + 5, coords.z + 5, coords.x, coords.y, coords.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), PLAYER::PLAYER_PED_ID(), 1, 1, 130);
	GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x + 3, coords.y, coords.z + 5, coords.x, coords.y, coords.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), PLAYER::PLAYER_PED_ID(), 1, 1, 80);
	GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x - 5, coords.y, coords.z + 5, coords.x, coords.y, coords.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), PLAYER::PLAYER_PED_ID(), 1, 1, 110);
	GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y - 2, coords.z + 5, coords.x, coords.y, coords.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), PLAYER::PLAYER_PED_ID(), 1, 1, 150);
}

/*void Features::blamePlayer(int selectedPed)
{
	for (int i = 0; i < 32; i++)
	{
			FIRE::ADD_OWNED_EXPLOSION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPed), coordsOf(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)).x, coordsOf(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)).y, coordsOf(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)).z, 37, 5.0f, true, false, 0.1f);
	}
}*/

//int delay; Hash item; DOES NOTHING
bool Features::moneydrop[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::Moneydrop(Player player) {
	Player p = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
	if ((timeGetTime() - Features::TimePD2) > 400) // Time between drops
	{
		STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
		if (!STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem))) {
			WAIT(0);
		}
		else {
			OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, coordsOf(p).x, coordsOf(p).y, coordsOf(p).z, 1, 2500, moneyModel(Features::MoneyItem), false, true);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));

			Features::TimePD2 = timeGetTime();
		}
	}
}

bool Features::spreaddrop[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::Spreaddrop(Player player) {
	Player p = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
	if ((timeGetTime() - Features::TimePD11) > 300) // Time between drops
	{
		float dx = coordsOf(p).x;
		float dy = coordsOf(p).y;
		float dz = coordsOf(p).z;
		float randX = rndInt(-2, 2);
		float randY = rndInt(-2, 2);
		float randZ = rndInt(-2, 2);
		float offsetX = dx + randX;
		float offsetY = dy + randY;
		float offsetZ = dz + randZ;
		STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
		if (!STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem))) {
			WAIT(0);
		}
		else {
			OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, offsetX, offsetY, offsetZ, 1, 2500, moneyModel(Features::MoneyItem), false, true);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));

			Features::TimePD11 = timeGetTime();
		}
	}
}

void Features::trapcage(Ped ped)
{
	Vector3 remotePos = ENTITY::GET_ENTITY_COORDS(ped, 0);
	Object obj = OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY("prop_gold_cont_01"), remotePos.x, remotePos.y, remotePos.z - 1.f, true, false, false);
}

bool Features::fakedropbool = false;
void Features::fakedrop(bool t, Player player) {
		if ((timeGetTime() - Features::TimePD3) > 400) // Time between drops
		{
			STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
			if (!STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem))) {
				WAIT(0);
			}
			else {
				OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, coordsOf(player).x, coordsOf(player).y, coordsOf(player).z, 1, 1, moneyModel(Features::MoneyItem), false, true);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));

				Features::TimePD3 = timeGetTime();
			}
		}
}

//RECOVERY
bool Features::selfdrop = false;
void Features::Selfdrop(bool toggle, int delay, Hash item, int value) {
	//OBJECT::CREATE_AMBIENT_PICKUP(item, coordsOf(PLAYER::PLAYER_PED_ID()).x, coordsOf(PLAYER::PLAYER_PED_ID()).y, coordsOf(PLAYER::PLAYER_PED_ID()).z, 0, value, item, false, true);
	//Features::Moneydrop(PLAYER::PLAYER_PED_ID());
	//WAIT(delay * 1000);
	Player p = PLAYER::PLAYER_PED_ID();
	if ((timeGetTime() - Features::TimePD8) > 400) // Time between drops
	{
		STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
		if (!STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem))) {
			WAIT(0);
		}
		else {
			OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, coordsOf(p).x, coordsOf(p).y, coordsOf(p).z, 1, 2500, moneyModel(Features::MoneyItem), false, true);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));

			Features::TimePD8 = timeGetTime();
		}
	}
}

void Features::SetRank(int rpvalue)
{
	if (rpvalue > 8000)
	{
		rpvalue = 8000;
	}

	if (rpvalue < 0)
	{
		rpvalue = 1;
	}

	//STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), Features::Levels[rpvalue], 0);
	//STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_XP_FM"), Features::Levels[rpvalue], 0);
	STATS::STAT_SET_INT($("MP0_CHAR_SET_RP_GIFT_ADMIN"), Features::Levels[rpvalue-1], 1);
	STATS::STAT_SET_INT($("MP1_CHAR_SET_RP_GIFT_ADMIN"), Features::Levels[rpvalue-1], 1);

}

int Features::Levels[8000] = { 0, 800, 2100, 3800, 6100, 9500, 12500, 16000, 19800, 24000, 28500, 33400, 38700, 44200, 50200, 56400, 63000, 69900, 77100, 84700, 92500, 100700, 109200, 118000, 127100, 136500, 146200,
156200, 166500, 177100, 188000, 199200, 210700, 222400, 234500, 246800, 259400, 272300, 285500, 299000, 312700, 326800, 341000, 355600, 370500, 385600, 401000, 416600, 432600, 448800, 465200, 482000, 499000,
516300, 533800, 551600, 569600, 588000, 606500, 625400, 644500, 663800, 683400, 703300, 723400, 743800, 764500, 785400, 806500, 827900, 849600, 871500, 893600, 916000, 938700, 961600, 984700, 1008100, 1031800,
1055700, 1079800, 1104200, 1128800, 1153700, 1178800, 1204200, 1229800, 1255600, 1281700, 1308100, 1334600, 1361400, 1388500, 1415800, 1443300, 1471100, 1499100, 1527300, 1555800, 1584350, 1612950, 1641600,
1670300, 1699050, 1727850, 1756700, 1785600, 1814550, 1843550, 1872600, 1901700, 1930850, 1960050, 1989300, 2018600, 2047950, 2077350, 2106800, 2136300, 2165850, 2195450, 2225100, 2254800, 2284550, 2314350,
2344200, 2374100, 2404050, 2434050, 2464100, 2494200, 2524350, 2554550, 2584800, 2615100, 2645450, 2675850, 2706300, 2736800, 2767350, 2797950, 2828600, 2859300, 2890050, 2920850, 2951700, 2982600, 3013550,
3044550, 3075600, 3106700, 3137850, 3169050, 3200300, 3231600, 3262950, 3294350, 3325800, 3357300, 3388850, 3420450, 3452100, 3483800, 3515550, 3547350, 3579200, 3611100, 3643050, 3675050, 3707100, 3739200,
3771350, 3803550, 3835800, 3868100, 3900450, 3932850, 3965300, 3997800, 4030350, 4062950, 4095600, 4128300, 4161050, 4193850, 4226700, 4259600, 4292550, 4325550, 4358600, 4391700, 4424850, 4458050, 4491300,
4524600, 4557950, 4591350, 4624800, 4658300, 4691850, 4725450, 4759100, 4792800, 4826550, 4860350, 4894200, 4928100, 4962050, 4996050, 5030100, 5064200, 5098350, 5132550, 5166800, 5201100, 5235450, 5269850,
5304300, 5338800, 5373350, 5407950, 5442600, 5477300, 5512050, 5546850, 5581700, 5616600, 5651550, 5686550, 5721600, 5756700, 5791850, 5827050, 5862300, 5897600, 5932950, 5968350, 6003800, 6039300, 6074850,
6110450, 6146100, 6181800, 6217550, 6253350, 6289200, 6325100, 6361050, 6397050, 6433100, 6469200, 6505350, 6541550, 6577800, 6614100, 6650450, 6686850, 6723300, 6759800, 6796350, 6832950, 6869600, 6906300,
6943050, 6979850, 7016700, 7053600, 7090550, 7127550, 7164600, 7201700, 7238850, 7276050, 7313300, 7350600, 7387950, 7425350, 7462800, 7500300, 7537850, 7575450, 7613100, 7650800, 7688550, 7726350, 7764200,
7802100, 7840050, 7878050, 7916100, 7954200, 7992350, 8030550, 8068800, 8107100, 8145450, 8183850, 8222300, 8260800, 8299350, 8337950, 8376600, 8415300, 8454050, 8492850, 8531700, 8570600, 8609550, 8648550,
8687600, 8726700, 8765850, 8805050, 8844300, 8883600, 8922950, 8962350, 9001800, 9041300, 9080850, 9120450, 9160100, 9199800, 9239550, 9279350, 9319200, 9359100, 9399050, 9439050, 9479100, 9519200, 9559350,
9599550, 9639800, 9680100, 9720450, 9760850, 9801300, 9841800, 9882350, 9922950, 9963600, 10004300, 10045050, 10085850, 10126700, 10167600, 10208550, 10249550, 10290600, 10331700, 10372850, 10414050, 10455300,
10496600, 10537950, 10579350, 10620800, 10662300, 10703850, 10745450, 10787100, 10828800, 10870550, 10912350, 10954200, 10996100, 11038050, 11080050, 11122100, 11164200, 11206350, 11248550, 11290800, 11333100,
11375450, 11417850, 11460300, 11502800, 11545350, 11587950, 11630600, 11673300, 11716050, 11758850, 11801700, 11844600, 11887550, 11930550, 11973600, 12016700, 12059850, 12103050, 12146300, 12189600, 12232950,
12276350, 12319800, 12363300, 12406850, 12450450, 12494100, 12537800, 12581550, 12625350, 12669200, 12713100, 12757050, 12801050, 12845100, 12889200, 12933350, 12977550, 13021800, 13066100, 13110450, 13154850,
13199300, 13243800, 13288350, 13332950, 13377600, 13422300, 13467050, 13511850, 13556700, 13601600, 13646550, 13691550, 13736600, 13781700, 13826850, 13872050, 13917300, 13962600, 14007950, 14053350, 14098800,
14144300, 14189850, 14235450, 14281100, 14326800, 14372550, 14418350, 14464200, 14510100, 14556050, 14602050, 14648100, 14694200, 14740350, 14786550, 14832800, 14879100, 14925450, 14971850, 15018300, 15064800,
15111350, 15157950, 15204600, 15251300, 15298050, 15344850, 15391700, 15438600, 15485550, 15532550, 15579600, 15626700, 15673850, 15721050, 15768300, 15815600, 15862950, 15910350, 15957800, 16005300, 16052850,
16100450, 16148100, 16195800, 16243550, 16291350, 16339200, 16387100, 16435050, 16483050, 16531100, 16579200, 16627350, 16675550, 16723800, 16772100, 16820450, 16868850, 16917300, 16965800, 17014350, 17062950,
17111600, 17160300, 17209050, 17257850, 17306700, 17355600, 17404550, 17453550, 17502600, 17551700, 17600850, 17650050, 17699300, 17748600, 17797950, 17847350, 17896800, 17946300, 17995850, 18045450, 18095100,
18144800, 18194550, 18244350, 18294200, 18344100, 18394050, 18444050, 18494100, 18544200, 18594350, 18644550, 18694800, 18745100, 18795450, 18845850, 18896300, 18946800, 18997350, 19047950, 19098600, 19149300,
19200050, 19250850, 19301700, 19352600, 19403550, 19454550, 19505600, 19556700, 19607850, 19659050, 19710300, 19761600, 19812950, 19864350, 19915800, 19967300, 20018850, 20070450, 20122100, 20173800, 20225550,
20277350, 20329200, 20381100, 20433050, 20485050, 20537100, 20589200, 20641350, 20693550, 20745800, 20798100, 20850450, 20902850, 20955300, 21007800, 21060350, 21112950, 21165600, 21218300, 21271050, 21323850,
21376700, 21429600, 21482550, 21535550, 21588600, 21641700, 21694850, 21748050, 21801300, 21854600, 21907950, 21961350, 22014800, 22068300, 22121850, 22175450, 22229100, 22282800, 22336550, 22390350, 22444200,
22498100, 22552050, 22606050, 22660100, 22714200, 22768350, 22822550, 22876800, 22931100, 22985450, 23039850, 23094300, 23148800, 23203350, 23257950, 23312600, 23367300, 23422050, 23476850, 23531700, 23586600,
23641550, 23696550, 23751600, 23806700, 23861850, 23917050, 23972300, 24027600, 24082950, 24138350, 24193800, 24249300, 24304850, 24360450, 24416100, 24471800, 24527550, 24583350, 24639200, 24695100, 24751050,
24807050, 24863100, 24919200, 24975350, 25031550, 25087800, 25144100, 25200450, 25256850, 25313300, 25369800, 25426350, 25482950, 25539600, 25596300, 25653050, 25709850, 25766700, 25823600, 25880550, 25937550,
25994600, 26051700, 26108850, 26166050, 26223300, 26280600, 26337950, 26395350, 26452800, 26510300, 26567850, 26625450, 26683100, 26740800, 26798550, 26856350, 26914200, 26972100, 27030050, 27088050, 27146100,
27204200, 27262350, 27320550, 27378800, 27437100, 27495450, 27553850, 27612300, 27670800, 27729350, 27787950, 27846600, 27905300, 27964050, 28022850, 28081700, 28140600, 28199550, 28258550, 28317600, 28376700,
28435850, 28495050, 28554300, 28613600, 28672950, 28732350, 28791800, 28851300, 28910850, 28970450, 29030100, 29089800, 29149550, 29209350, 29269200, 29329100, 29389050, 29449050, 29509100, 29569200, 29629350,
29689550, 29749800, 29810100, 29870450, 29930850, 29991300, 30051800, 30112350, 30172950, 30233600, 30294300, 30355050, 30415850, 30476700, 30537600, 30598550, 30659550, 30720600, 30781700, 30842850, 30904050,
30965300, 31026600, 31087950, 31149350, 31210800, 31272300, 31333850, 31395450, 31457100, 31518800, 31580550, 31642350, 31704200, 31766100, 31828050, 31890050, 31952100, 32014200, 32076350, 32138550, 32200800,
32263100, 32325450, 32387850, 32450300, 32512800, 32575350, 32637950, 32700600, 32763300, 32826050, 32888850, 32951700, 33014600, 33077550, 33140550, 33203600, 33266700, 33329850, 33393050, 33456300, 33519600,
33582950, 33646350, 33709800, 33773300, 33836850, 33900450, 33964100, 34027800, 34091550, 34155350, 34219200, 34283100, 34347050, 34411050, 34475100, 34539200, 34603350, 34667550, 34731800, 34796100, 34860450,
34924850, 34989300, 35053800, 35118350, 35182950, 35247600, 35312300, 35377050, 35441850, 35506700, 35571600, 35636550, 35701550, 35766600, 35831700, 35896850, 35962050, 36027300, 36092600, 36157950, 36223350,
36288800, 36354300, 36419850, 36485450, 36551100, 36616800, 36682550, 36748350, 36814200, 36880100, 36946050, 37012050, 37078100, 37144200, 37210350, 37276550, 37342800, 37409100, 37475450, 37541850, 37608300,
37674800, 37741350, 37807950, 37874600, 37941300, 38008050, 38074850, 38141700, 38208600, 38275550, 38342550, 38409600, 38476700, 38543850, 38611050, 38678300, 38745600, 38812950, 38880350, 38947800, 39015300,
39082850, 39150450, 39218100, 39285800, 39353550, 39421350, 39489200, 39557100, 39625050, 39693050, 39761100, 39829200, 39897350, 39965550, 40033800, 40102100, 40170450, 40238850, 40307300, 40375800, 40444350,
40512950, 40581600, 40650300, 40719050, 40787850, 40856700, 40925600, 40994550, 41063550, 41132600, 41201700, 41270850, 41340050, 41409300, 41478600, 41547950, 41617350, 41686800, 41756300, 41825850, 41895450,
41965100, 42034800, 42104550, 42174350, 42244200, 42314100, 42384050, 42454050, 42524100, 42594200, 42664350, 42734550, 42804800, 42875100, 42945450, 43015850, 43086300, 43156800, 43227350, 43297950, 43368600,
43439300, 43510050, 43580850, 43651700, 43722600, 43793550, 43864550, 43935600, 44006700, 44077850, 44149050, 44220300, 44291600, 44362950, 44434350, 44505800, 44577300, 44648850, 44720450, 44792100, 44863800,
44935550, 45007350, 45079200, 45151100, 45223050, 45295050, 45367100, 45439200, 45511350, 45583550, 45655800, 45728100, 45800450, 45872850, 45945300, 46017800, 46090350, 46162950, 46235600, 46308300, 46381050,
46453850, 46526700, 46599600, 46672550, 46745550, 46818600, 46891700, 46964850, 47038050, 47111300, 47184600, 47257950, 47331350, 47404800, 47478300, 47551850, 47625450, 47699100, 47772800, 47846550, 47920350,
47994200, 48068100, 48142050, 48216050, 48290100, 48364200, 48438350, 48512550, 48586800, 48661100, 48735450, 48809850, 48884300, 48958800, 49033350, 49107950, 49182600, 49257300, 49332050, 49406850, 49481700,
49556600, 49631550, 49706550, 49781600, 49856700, 49931850, 50007050, 50082300, 50157600, 50232950, 50308350, 50383800, 50459300, 50534850, 50610450, 50686100, 50761800, 50837550, 50913350, 50989200, 51065100,
51141050, 51217050, 51293100, 51369200, 51445350, 51521550, 51597800, 51674100, 51750450, 51826850, 51903300, 51979800, 52056350, 52132950, 52209600, 52286300, 52363050, 52439850, 52516700, 52593600, 52670550,
52747550, 52824600, 52901700, 52978850, 53056050, 53133300, 53210600, 53287950, 53365350, 53442800, 53520300, 53597850, 53675450, 53753100, 53830800, 53908550, 53986350, 54064200, 54142100, 54220050, 54298050,
54376100, 54454200, 54532350, 54610550, 54688800, 54767100, 54845450, 54923850, 55002300, 55080800, 55159350, 55237950, 55316600, 55395300, 55474050, 55552850, 55631700, 55710600, 55789550, 55868550, 55947600,
56026700, 56105850, 56185050, 56264300, 56343600, 56422950, 56502350, 56581800, 56661300, 56740850, 56820450, 56900100, 56979800, 57059550, 57139350, 57219200, 57299100, 57379050, 57459050, 57539100, 57619200,
57699350, 57779550, 57859800, 57940100, 58020450, 58100850, 58181300, 58261800, 58342350, 58422950, 58503600, 58584300, 58665050, 58745850, 58826700, 58907600, 58988550, 59069550, 59150600, 59231700, 59312850,
59394050, 59475300, 59556600, 59637950, 59719350, 59800800, 59882300, 59963850, 60045450, 60127100, 60208800, 60290550, 60372350, 60454200, 60536100, 60618050, 60700050, 60782100, 60864200, 60946350, 61028550,
61110800, 61193100, 61275450, 61357850, 61440300, 61522800, 61605350, 61687950, 61770600, 61853300, 61936050, 62018850, 62101700, 62184600, 62267550, 62350550, 62433600, 62516700, 62599850, 62683050, 62766300,
62849600, 62932950, 63016350, 63099800, 63183300, 63266850, 63350450, 63434100, 63517800, 63601550, 63685350, 63769200, 63853100, 63937050, 64021050, 64105100, 64189200, 64273350, 64357550, 64441800, 64526100,
64610450, 64694850, 64779300, 64863800, 64948350, 65032950, 65117600, 65202300, 65287050, 65371850, 65456700, 65541600, 65626550, 65711550, 65796600, 65881700, 65966850, 66052050, 66137300, 66222600, 66307950,
66393350, 66478800, 66564300, 66649850, 66735450, 66821100, 66906800, 66992550, 67078350, 67164200, 67250100, 67336050, 67422050, 67508100, 67594200, 67680350, 67766550, 67852800, 67939100, 68025450, 68111850,
68198300, 68284800, 68371350, 68457950, 68544600, 68631300, 68718050, 68804850, 68891700, 68978600, 69065550, 69152550, 69239600, 69326700, 69413850, 69501050, 69588300, 69675600, 69762950, 69850350, 69937800,
70025300, 70112850, 70200450, 70288100, 70375800, 70463550, 70551350, 70639200, 70727100, 70815050, 70903050, 70991100, 71079200, 71167350, 71255550, 71343800, 71432100, 71520450, 71608850, 71697300, 71785800,
71874350, 71962950, 72051600, 72140300, 72229050, 72317850, 72406700, 72495600, 72584550, 72673550, 72762600, 72851700, 72940850, 73030050, 73119300, 73208600, 73297950, 73387350, 73476800, 73566300, 73655850,
73745450, 73835100, 73924800, 74014550, 74104350, 74194200, 74284100, 74374050, 74464050, 74554100, 74644200, 74734350, 74824550, 74914800, 75005100, 75095450, 75185850, 75276300, 75366800, 75457350, 75547950,
75638600, 75729300, 75820050, 75910850, 76001700, 76092600, 76183550, 76274550, 76365600, 76456700, 76547850, 76639050, 76730300, 76821600, 76912950, 77004350, 77095800, 77187300, 77278850, 77370450, 77462100,
77553800, 77645550, 77737350, 77829200, 77921100, 78013050, 78105050, 78197100, 78289200, 78381350, 78473550, 78565800, 78658100, 78750450, 78842850, 78935300, 79027800, 79120350, 79212950, 79305600, 79398300,
79491050, 79583850, 79676700, 79769600, 79862550, 79955550, 80048600, 80141700, 80234850, 80328050, 80421300, 80514600, 80607950, 80701350, 80794800, 80888300, 80981850, 81075450, 81169100, 81262800, 81356550,
81450350, 81544200, 81638100, 81732050, 81826050, 81920100, 82014200, 82108350, 82202550, 82296800, 82391100, 82485450, 82579850, 82674300, 82768800, 82863350, 82957950, 83052600, 83147300, 83242050, 83336850,
83431700, 83526600, 83621550, 83716550, 83811600, 83906700, 84001850, 84097050, 84192300, 84287600, 84382950, 84478350, 84573800, 84669300, 84764850, 84860450, 84956100, 85051800, 85147550, 85243350, 85339200,
85435100, 85531050, 85627050, 85723100, 85819200, 85915350, 86011550, 86107800, 86204100, 86300450, 86396850, 86493300, 86589800, 86686350, 86782950, 86879600, 86976300, 87073050, 87169850, 87266700, 87363600,
87460550, 87557550, 87654600, 87751700, 87848850, 87946050, 88043300, 88140600, 88237950, 88335350, 88432800, 88530300, 88627850, 88725450, 88823100, 88920800, 89018550, 89116350, 89214200, 89312100, 89410050,
89508050, 89606100, 89704200, 89802350, 89900550, 89998800, 90097100, 90195450, 90293850, 90392300, 90490800, 90589350, 90687950, 90786600, 90885300, 90984050, 91082850, 91181700, 91280600, 91379550, 91478550,
91577600, 91676700, 91775850, 91875050, 91974300, 92073600, 92172950, 92272350, 92371800, 92471300, 92570850, 92670450, 92770100, 92869800, 92969550, 93069350, 93169200, 93269100, 93369050, 93469050, 93569100,
93669200, 93769350, 93869550, 93969800, 94070100, 94170450, 94270850, 94371300, 94471800, 94572350, 94672950, 94773600, 94874300, 94975050, 95075850, 95176700, 95277600, 95378550, 95479550, 95580600, 95681700,
95782850, 95884050, 95985300, 96086600, 96187950, 96289350, 96390800, 96492300, 96593850, 96695450, 96797100, 96898800, 97000550, 97102350, 97204200, 97306100, 97408050, 97510050, 97612100, 97714200, 97816350,
97918550, 98020800, 98123100, 98225450, 98327850, 98430300, 98532800, 98635350, 98737950, 98840600, 98943300, 99046050, 99148850, 99251700, 99354600, 99457550, 99560550, 99663600, 99766700, 99869850, 99973050,
100076300, 100179600, 100282950, 100386350, 100489800, 100593300, 100696850, 100800450, 100904100, 101007800, 101111550, 101215350, 101319200, 101423100, 101527050, 101631050, 101735100, 101839200, 101943350,
102047550, 102151800, 102256100, 102360450, 102464850, 102569300, 102673800, 102778350, 102882950, 102987600, 103092300, 103197050, 103301850, 103406700, 103511600, 103616550, 103721550, 103826600, 103931700,
104036850, 104142050, 104247300, 104352600, 104457950, 104563350, 104668800, 104774300, 104879850, 104985450, 105091100, 105196800, 105302550, 105408350, 105514200, 105620100, 105726050, 105832050, 105938100,
106044200, 106150350, 106256550, 106362800, 106469100, 106575450, 106681850, 106788300, 106894800, 107001350, 107107950, 107214600, 107321300, 107428050, 107534850, 107641700, 107748600, 107855550, 107962550,
108069600, 108176700, 108283850, 108391050, 108498300, 108605600, 108712950, 108820350, 108927800, 109035300, 109142850, 109250450, 109358100, 109465800, 109573550, 109681350, 109789200, 109897100, 110005050,
110113050, 110221100, 110329200, 110437350, 110545550, 110653800, 110762100, 110870450, 110978850, 111087300, 111195800, 111304350, 111412950, 111521600, 111630300, 111739050, 111847850, 111956700, 112065600,
112174550, 112283550, 112392600, 112501700, 112610850, 112720050, 112829300, 112938600, 113047950, 113157350, 113266800, 113376300, 113485850, 113595450, 113705100, 113814800, 113924550, 114034350, 114144200,
114254100, 114364050, 114474050, 114584100, 114694200, 114804350, 114914550, 115024800, 115135100, 115245450, 115355850, 115466300, 115576800, 115687350, 115797950, 115908600, 116019300, 116130050, 116240850,
116351700, 116462600, 116573550, 116684550, 116795600, 116906700, 117017850, 117129050, 117240300, 117351600, 117462950, 117574350, 117685800, 117797300, 117908850, 118020450, 118132100, 118243800, 118355550,
118467350, 118579200, 118691100, 118803050, 118915050, 119027100, 119139200, 119251350, 119363550, 119475800, 119588100, 119700450, 119812850, 119925300, 120037800, 120150350, 120262950, 120375600, 120488300,
120601050, 120713850, 120826700, 120939600, 121052550, 121165550, 121278600, 121391700, 121504850, 121618050, 121731300, 121844600, 121957950, 122071350, 122184800, 122298300, 122411850, 122525450, 122639100,
122752800, 122866550, 122980350, 123094200, 123208100, 123322050, 123436050, 123550100, 123664200, 123778350, 123892550, 124006800, 124121100, 124235450, 124349850, 124464300, 124578800, 124693350, 124807950,
124922600, 125037300, 125152050, 125266850, 125381700, 125496600, 125611550, 125726550, 125841600, 125956700, 126071850, 126187050, 126302300, 126417600, 126532950, 126648350, 126763800, 126879300, 126994850,
127110450, 127226100, 127341800, 127457550, 127573350, 127689200, 127805100, 127921050, 128037050, 128153100, 128269200, 128385350, 128501550, 128617800, 128734100, 128850450, 128966850, 129083300, 129199800,
129316350, 129432950, 129549600, 129666300, 129783050, 129899850, 130016700, 130133600, 130250550, 130367550, 130484600, 130601700, 130718850, 130836050, 130953300, 131070600, 131187950, 131305350, 131422800,
131540300, 131657850, 131775450, 131893100, 132010800, 132128550, 132246350, 132364200, 132482100, 132600050, 132718050, 132836100, 132954200, 133072350, 133190550, 133308800, 133427100, 133545450, 133663850,
133782300, 133900800, 134019350, 134137950, 134256600, 134375300, 134494050, 134612850, 134731700, 134850600, 134969550, 135088550, 135207600, 135326700, 135445850, 135565050, 135684300, 135803600, 135922950,
136042350, 136161800, 136281300, 136400850, 136520450, 136640100, 136759800, 136879550, 136999350, 137119200, 137239100, 137359050, 137479050, 137599100, 137719200, 137839350, 137959550, 138079800, 138200100,
138320450, 138440850, 138561300, 138681800, 138802350, 138922950, 139043600, 139164300, 139285050, 139405850, 139526700, 139647600, 139768550, 139889550, 140010600, 140131700, 140252850, 140374050, 140495300,
140616600, 140737950, 140859350, 140980800, 141102300, 141223850, 141345450, 141467100, 141588800, 141710550, 141832350, 141954200, 142076100, 142198050, 142320050, 142442100, 142564200, 142686350, 142808550,
142930800, 143053100, 143175450, 143297850, 143420300, 143542800, 143665350, 143787950, 143910600, 144033300, 144156050, 144278850, 144401700, 144524600, 144647550, 144770550, 144893600, 145016700, 145139850,
145263050, 145386300, 145509600, 145632950, 145756350, 145879800, 146003300, 146126850, 146250450, 146374100, 146497800, 146621550, 146745350, 146869200, 146993100, 147117050, 147241050, 147365100, 147489200,
147613350, 147737550, 147861800, 147986100, 148110450, 148234850, 148359300, 148483800, 148608350, 148732950, 148857600, 148982300, 149107050, 149231850, 149356700, 149481600, 149606550, 149731550, 149856600,
149981700, 150106850, 150232050, 150357300, 150482600, 150607950, 150733350, 150858800, 150984300, 151109850, 151235450, 151361100, 151486800, 151612550, 151738350, 151864200, 151990100, 152116050, 152242050,
152368100, 152494200, 152620350, 152746550, 152872800, 152999100, 153125450, 153251850, 153378300, 153504800, 153631350, 153757950, 153884600, 154011300, 154138050, 154264850, 154391700, 154518600, 154645550,
154772550, 154899600, 155026700, 155153850, 155281050, 155408300, 155535600, 155662950, 155790350, 155917800, 156045300, 156172850, 156300450, 156428100, 156555800, 156683550, 156811350, 156939200, 157067100,
157195050, 157323050, 157451100, 157579200, 157707350, 157835550, 157963800, 158092100, 158220450, 158348850, 158477300, 158605800, 158734350, 158862950, 158991600, 159120300, 159249050, 159377850, 159506700,
159635600, 159764550, 159893550, 160022600, 160151700, 160280850, 160410050, 160539300, 160668600, 160797950, 160927350, 161056800, 161186300, 161315850, 161445450, 161575100, 161704800, 161834550, 161964350,
162094200, 162224100, 162354050, 162484050, 162614100, 162744200, 162874350, 163004550, 163134800, 163265100, 163395450, 163525850, 163656300, 163786800, 163917350, 164047950, 164178600, 164309300, 164440050,
164570850, 164701700, 164832600, 164963550, 165094550, 165225600, 165356700, 165487850, 165619050, 165750300, 165881600, 166012950, 166144350, 166275800, 166407300, 166538850, 166670450, 166802100, 166933800,
167065550, 167197350, 167329200, 167461100, 167593050, 167725050, 167857100, 167989200, 168121350, 168253550, 168385800, 168518100, 168650450, 168782850, 168915300, 169047800, 169180350, 169312950, 169445600,
169578300, 169711050, 169843850, 169976700, 170109600, 170242550, 170375550, 170508600, 170641700, 170774850, 170908050, 171041300, 171174600, 171307950, 171441350, 171574800, 171708300, 171841850, 171975450,
172109100, 172242800, 172376550, 172510350, 172644200, 172778100, 172912050, 173046050, 173180100, 173314200, 173448350, 173582550, 173716800, 173851100, 173985450, 174119850, 174254300, 174388800, 174523350,
174657950, 174792600, 174927300, 175062050, 175196850, 175331700, 175466600, 175601550, 175736550, 175871600, 176006700, 176141850, 176277050, 176412300, 176547600, 176682950, 176818350, 176953800, 177089300,
177224850, 177360450, 177496100, 177631800, 177767550, 177903350, 178039200, 178175100, 178311050, 178447050, 178583100, 178719200, 178855350, 178991550, 179127800, 179264100, 179400450, 179536850, 179673300,
179809800, 179946350, 180082950, 180219600, 180356300, 180493050, 180629850, 180766700, 180903600, 181040550, 181177550, 181314600, 181451700, 181588850, 181726050, 181863300, 182000600, 182137950, 182275350,
182412800, 182550300, 182687850, 182825450, 182963100, 183100800, 183238550, 183376350, 183514200, 183652100, 183790050, 183928050, 184066100, 184204200, 184342350, 184480550, 184618800, 184757100, 184895450,
185033850, 185172300, 185310800, 185449350, 185587950, 185726600, 185865300, 186004050, 186142850, 186281700, 186420600, 186559550, 186698550, 186837600, 186976700, 187115850, 187255050, 187394300, 187533600,
187672950, 187812350, 187951800, 188091300, 188230850, 188370450, 188510100, 188649800, 188789550, 188929350, 189069200, 189209100, 189349050, 189489050, 189629100, 189769200, 189909350, 190049550, 190189800,
190330100, 190470450, 190610850, 190751300, 190891800, 191032350, 191172950, 191313600, 191454300, 191595050, 191735850, 191876700, 192017600, 192158550, 192299550, 192440600, 192581700, 192722850, 192864050,
193005300, 193146600, 193287950, 193429350, 193570800, 193712300, 193853850, 193995450, 194137100, 194278800, 194420550, 194562350, 194704200, 194846100, 194988050, 195130050, 195272100, 195414200, 195556350,
195698550, 195840800, 195983100, 196125450, 196267850, 196410300, 196552800, 196695350, 196837950, 196980600, 197123300, 197266050, 197408850, 197551700, 197694600, 197837550, 197980550, 198123600, 198266700,
198409850, 198553050, 198696300, 198839600, 198982950, 199126350, 199269800, 199413300, 199556850, 199700450, 199844100, 199987800, 200131550, 200275350, 200419200, 200563100, 200707050, 200851050, 200995100,
201139200, 201283350, 201427550, 201571800, 201716100, 201860450, 202004850, 202149300, 202293800, 202438350, 202582950, 202727600, 202872300, 203017050, 203161850, 203306700, 203451600, 203596550, 203741550,
203886600, 204031700, 204176850, 204322050, 204467300, 204612600, 204757950, 204903350, 205048800, 205194300, 205339850, 205485450, 205631100, 205776800, 205922550, 206068350, 206214200, 206360100, 206506050,
206652050, 206798100, 206944200, 207090350, 207236550, 207382800, 207529100, 207675450, 207821850, 207968300, 208114800, 208261350, 208407950, 208554600, 208701300, 208848050, 208994850, 209141700, 209288600,
209435550, 209582550, 209729600, 209876700, 210023850, 210171050, 210318300, 210465600, 210612950, 210760350, 210907800, 211055300, 211202850, 211350450, 211498100, 211645800, 211793550, 211941350, 212089200,
212237100, 212385050, 212533050, 212681100, 212829200, 212977350, 213125550, 213273800, 213422100, 213570450, 213718850, 213867300, 214015800, 214164350, 214312950, 214461600, 214610300, 214759050, 214907850,
215056700, 215205600, 215354550, 215503550, 215652600, 215801700, 215950850, 216100050, 216249300, 216398600, 216547950, 216697350, 216846800, 216996300, 217145850, 217295450, 217445100, 217594800, 217744550,
217894350, 218044200, 218194100, 218344050, 218494050, 218644100, 218794200, 218944350, 219094550, 219244800, 219395100, 219545450, 219695850, 219846300, 219996800, 220147350, 220297950, 220448600, 220599300,
220750050, 220900850, 221051700, 221202600, 221353550, 221504550, 221655600, 221806700, 221957850, 222109050, 222260300, 222411600, 222562950, 222714350, 222865800, 223017300, 223168850, 223320450, 223472100,
223623800, 223775550, 223927350, 224079200, 224231100, 224383050, 224535050, 224687100, 224839200, 224991350, 225143550, 225295800, 225448100, 225600450, 225752850, 225905300, 226057800, 226210350, 226362950,
226515600, 226668300, 226821050, 226973850, 227126700, 227279600, 227432550, 227585550, 227738600, 227891700, 228044850, 228198050, 228351300, 228504600, 228657950, 228811350, 228964800, 229118300, 229271850,
229425450, 229579100, 229732800, 229886550, 230040350, 230194200, 230348100, 230502050, 230656050, 230810100, 230964200, 231118350, 231272550, 231426800, 231581100, 231735450, 231889850, 232044300, 232198800,
232353350, 232507950, 232662600, 232817300, 232972050, 233126850, 233281700, 233436600, 233591550, 233746550, 233901600, 234056700, 234211850, 234367050, 234522300, 234677600, 234832950, 234988350, 235143800,
235299300, 235454850, 235610450, 235766100, 235921800, 236077550, 236233350, 236389200, 236545100, 236701050, 236857050, 237013100, 237169200, 237325350, 237481550, 237637800, 237794100, 237950450, 238106850,
238263300, 238419800, 238576350, 238732950, 238889600, 239046300, 239203050, 239359850, 239516700, 239673600, 239830550, 239987550, 240144600, 240301700, 240458850, 240616050, 240773300, 240930600, 241087950,
241245350, 241402800, 241560300, 241717850, 241875450, 242033100, 242190800, 242348550, 242506350, 242664200, 242822100, 242980050, 243138050, 243296100, 243454200, 243612350, 243770550, 243928800, 244087100,
244245450, 244403850, 244562300, 244720800, 244879350, 245037950, 245196600, 245355300, 245514050, 245672850, 245831700, 245990600, 246149550, 246308550, 246467600, 246626700, 246785850, 246945050, 247104300,
247263600, 247422950, 247582350, 247741800, 247901300, 248060850, 248220450, 248380100, 248539800, 248699550, 248859350, 249019200, 249179100, 249339050, 249499050, 249659100, 249819200, 249979350, 250139550,
250299800, 250460100, 250620450, 250780850, 250941300, 251101800, 251262350, 251422950, 251583600, 251744300, 251905050, 252065850, 252226700, 252387600, 252548550, 252709550, 252870600, 253031700, 253192850,
253354050, 253515300, 253676600, 253837950, 253999350, 254160800, 254322300, 254483850, 254645450, 254807100, 254968800, 255130550, 255292350, 255454200, 255616100, 255778050, 255940050, 256102100, 256264200,
256426350, 256588550, 256750800, 256913100, 257075450, 257237850, 257400300, 257562800, 257725350, 257887950, 258050600, 258213300, 258376050, 258538850, 258701700, 258864600, 259027550, 259190550, 259353600,
259516700, 259679850, 259843050, 260006300, 260169600, 260332950, 260496350, 260659800, 260823300, 260986850, 261150450, 261314100, 261477800, 261641550, 261805350, 261969200, 262133100, 262297050, 262461050,
262625100, 262789200, 262953350, 263117550, 263281800, 263446100, 263610450, 263774850, 263939300, 264103800, 264268350, 264432950, 264597600, 264762300, 264927050, 265091850, 265256700, 265421600, 265586550,
265751550, 265916600, 266081700, 266246850, 266412050, 266577300, 266742600, 266907950, 267073350, 267238800, 267404300, 267569850, 267735450, 267901100, 268066800, 268232550, 268398350, 268564200, 268730100,
268896050, 269062050, 269228100, 269394200, 269560350, 269726550, 269892800, 270059100, 270225450, 270391850, 270558300, 270724800, 270891350, 271057950, 271224600, 271391300, 271558050, 271724850, 271891700,
272058600, 272225550, 272392550, 272559600, 272726700, 272893850, 273061050, 273228300, 273395600, 273562950, 273730350, 273897800, 274065300, 274232850, 274400450, 274568100, 274735800, 274903550, 275071350,
275239200, 275407100, 275575050, 275743050, 275911100, 276079200, 276247350, 276415550, 276583800, 276752100, 276920450, 277088850, 277257300, 277425800, 277594350, 277762950, 277931600, 278100300, 278269050,
278437850, 278606700, 278775600, 278944550, 279113550, 279282600, 279451700, 279620850, 279790050, 279959300, 280128600, 280297950, 280467350, 280636800, 280806300, 280975850, 281145450, 281315100, 281484800,
281654550, 281824350, 281994200, 282164100, 282334050, 282504050, 282674100, 282844200, 283014350, 283184550, 283354800, 283525100, 283695450, 283865850, 284036300, 284206800, 284377350, 284547950, 284718600,
284889300, 285060050, 285230850, 285401700, 285572600, 285743550, 285914550, 286085600, 286256700, 286427850, 286599050, 286770300, 286941600, 287112950, 287284350, 287455800, 287627300, 287798850, 287970450,
288142100, 288313800, 288485550, 288657350, 288829200, 289001100, 289173050, 289345050, 289517100, 289689200, 289861350, 290033550, 290205800, 290378100, 290550450, 290722850, 290895300, 291067800, 291240350,
291412950, 291585600, 291758300, 291931050, 292103850, 292276700, 292449600, 292622550, 292795550, 292968600, 293141700, 293314850, 293488050, 293661300, 293834600, 294007950, 294181350, 294354800, 294528300,
294701850, 294875450, 295049100, 295222800, 295396550, 295570350, 295744200, 295918100, 296092050, 296266050, 296440100, 296614200, 296788350, 296962550, 297136800, 297311100, 297485450, 297659850, 297834300,
298008800, 298183350, 298357950, 298532600, 298707300, 298882050, 299056850, 299231700, 299406600, 299581550, 299756550, 299931600, 300106700, 300281850, 300457050, 300632300, 300807600, 300982950, 301158350,
301333800, 301509300, 301684850, 301860450, 302036100, 302211800, 302387550, 302563350, 302739200, 302915100, 303091050, 303267050, 303443100, 303619200, 303795350, 303971550, 304147800, 304324100, 304500450,
304676850, 304853300, 305029800, 305206350, 305382950, 305559600, 305736300, 305913050, 306089850, 306266700, 306443600, 306620550, 306797550, 306974600, 307151700, 307328850, 307506050, 307683300, 307860600,
308037950, 308215350, 308392800, 308570300, 308747850, 308925450, 309103100, 309280800, 309458550, 309636350, 309814200, 309992100, 310170050, 310348050, 310526100, 310704200, 310882350, 311060550, 311238800,
311417100, 311595450, 311773850, 311952300, 312130800, 312309350, 312487950, 312666600, 312845300, 313024050, 313202850, 313381700, 313560600, 313739550, 313918550, 314097600, 314276700, 314455850, 314635050,
314814300, 314993600, 315172950, 315352350, 315531800, 315711300, 315890850, 316070450, 316250100, 316429800, 316609550, 316789350, 316969200, 317149100, 317329050, 317509050, 317689100, 317869200, 318049350,
318229550, 318409800, 318590100, 318770450, 318950850, 319131300, 319311800, 319492350, 319672950, 319853600, 320034300, 320215050, 320395850, 320576700, 320757600, 320938550, 321119550, 321300600, 321481700,
321662850, 321844050, 322025300, 322206600, 322387950, 322569350, 322750800, 322932300, 323113850, 323295450, 323477100, 323658800, 323840550, 324022350, 324204200, 324386100, 324568050, 324750050, 324932100,
325114200, 325296350, 325478550, 325660800, 325843100, 326025450, 326207850, 326390300, 326572800, 326755350, 326937950, 327120600, 327303300, 327486050, 327668850, 327851700, 328034600, 328217550, 328400550,
328583600, 328766700, 328949850, 329133050, 329316300, 329499600, 329682950, 329866350, 330049800, 330233300, 330416850, 330600450, 330784100, 330967800, 331151550, 331335350, 331519200, 331703100, 331887050,
332071050, 332255100, 332439200, 332623350, 332807550, 332991800, 333176100, 333360450, 333544850, 333729300, 333913800, 334098350, 334282950, 334467600, 334652300, 334837050, 335021850, 335206700, 335391600,
335576550, 335761550, 335946600, 336131700, 336316850, 336502050, 336687300, 336872600, 337057950, 337243350, 337428800, 337614300, 337799850, 337985450, 338171100, 338356800, 338542550, 338728350, 338914200,
339100100, 339286050, 339472050, 339658100, 339844200, 340030350, 340216550, 340402800, 340589100, 340775450, 340961850, 341148300, 341334800, 341521350, 341707950, 341894600, 342081300, 342268050, 342454850,
342641700, 342828600, 343015550, 343202550, 343389600, 343576700, 343763850, 343951050, 344138300, 344325600, 344512950, 344700350, 344887800, 345075300, 345262850, 345450450, 345638100, 345825800, 346013550,
346201350, 346389200, 346577100, 346765050, 346953050, 347141100, 347329200, 347517350, 347705550, 347893800, 348082100, 348270450, 348458850, 348647300, 348835800, 349024350, 349212950, 349401600, 349590300,
349779050, 349967850, 350156700, 350345600, 350534550, 350723550, 350912600, 351101700, 351290850, 351480050, 351669300, 351858600, 352047950, 352237350, 352426800, 352616300, 352805850, 352995450, 353185100,
353374800, 353564550, 353754350, 353944200, 354134100, 354324050, 354514050, 354704100, 354894200, 355084350, 355274550, 355464800, 355655100, 355845450, 356035850, 356226300, 356416800, 356607350, 356797950,
356988600, 357179300, 357370050, 357560850, 357751700, 357942600, 358133550, 358324550, 358515600, 358706700, 358897850, 359089050, 359280300, 359471600, 359662950, 359854350, 360045800, 360237300, 360428850,
360620450, 360812100, 361003800, 361195550, 361387350, 361579200, 361771100, 361963050, 362155050, 362347100, 362539200, 362731350, 362923550, 363115800, 363308100, 363500450, 363692850, 363885300, 364077800,
364270350, 364462950, 364655600, 364848300, 365041050, 365233850, 365426700, 365619600, 365812550, 366005550, 366198600, 366391700, 366584850, 366778050, 366971300, 367164600, 367357950, 367551350, 367744800,
367938300, 368131850, 368325450, 368519100, 368712800, 368906550, 369100350, 369294200, 369488100, 369682050, 369876050, 370070100, 370264200, 370458350, 370652550, 370846800, 371041100, 371235450, 371429850,
371624300, 371818800, 372013350, 372207950, 372402600, 372597300, 372792050, 372986850, 373181700, 373376600, 373571550, 373766550, 373961600, 374156700, 374351850, 374547050, 374742300, 374937600, 375132950,
375328350, 375523800, 375719300, 375914850, 376110450, 376306100, 376501800, 376697550, 376893350, 377089200, 377285100, 377481050, 377677050, 377873100, 378069200, 378265350, 378461550, 378657800, 378854100,
379050450, 379246850, 379443300, 379639800, 379836350, 380032950, 380229600, 380426300, 380623050, 380819850, 381016700, 381213600, 381410550, 381607550, 381804600, 382001700, 382198850, 382396050, 382593300,
382790600, 382987950, 383185350, 383382800, 383580300, 383777850, 383975450, 384173100, 384370800, 384568550, 384766350, 384964200, 385162100, 385360050, 385558050, 385756100, 385954200, 386152350, 386350550,
386548800, 386747100, 386945450, 387143850, 387342300, 387540800, 387739350, 387937950, 388136600, 388335300, 388534050, 388732850, 388931700, 389130600, 389329550, 389528550, 389727600, 389926700, 390125850,
390325050, 390524300, 390723600, 390922950, 391122350, 391321800, 391521300, 391720850, 391920450, 392120100, 392319800, 392519550, 392719350, 392919200, 393119100, 393319050, 393519050, 393719100, 393919200,
394119350, 394319550, 394519800, 394720100, 394920450, 395120850, 395321300, 395521800, 395722350, 395922950, 396123600, 396324300, 396525050, 396725850, 396926700, 397127600, 397328550, 397529550, 397730600,
397931700, 398132850, 398334050, 398535300, 398736600, 398937950, 399139350, 399340800, 399542300, 399743850, 399945450, 400147100, 400348800, 400550550, 400752350, 400954200, 401156100, 401358050, 401560050,
401762100, 401964200, 402166350, 402368550, 402570800, 402773100, 402975450, 403177850, 403380300, 403582800, 403785350, 403987950, 404190600, 404393300, 404596050, 404798850, 405001700, 405204600, 405407550,
405610550, 405813600, 406016700, 406219850, 406423050, 406626300, 406829600, 407032950, 407236350, 407439800, 407643300, 407846850, 408050450, 408254100, 408457800, 408661550, 408865350, 409069200, 409273100,
409477050, 409681050, 409885100, 410089200, 410293350, 410497550, 410701800, 410906100, 411110450, 411314850, 411519300, 411723800, 411928350, 412132950, 412337600, 412542300, 412747050, 412951850, 413156700,
413361600, 413566550, 413771550, 413976600, 414181700, 414386850, 414592050, 414797300, 415002600, 415207950, 415413350, 415618800, 415824300, 416029850, 416235450, 416441100, 416646800, 416852550, 417058350,
417264200, 417470100, 417676050, 417882050, 418088100, 418294200, 418500350, 418706550, 418912800, 419119100, 419325450, 419531850, 419738300, 419944800, 420151350, 420357950, 420564600, 420771300, 420978050,
421184850, 421391700, 421598600, 421805550, 422012550, 422219600, 422426700, 422633850, 422841050, 423048300, 423255600, 423462950, 423670350, 423877800, 424085300, 424292850, 424500450, 424708100, 424915800,
425123550, 425331350, 425539200, 425747100, 425955050, 426163050, 426371100, 426579200, 426787350, 426995550, 427203800, 427412100, 427620450, 427828850, 428037300, 428245800, 428454350, 428662950, 428871600,
429080300, 429289050, 429497850, 429706700, 429915600, 430124550, 430333550, 430542600, 430751700, 430960850, 431170050, 431379300, 431588600, 431797950, 432007350, 432216800, 432426300, 432635850, 432845450,
433055100, 433264800, 433474550, 433684350, 433894200, 434104100, 434314050, 434524050, 434734100, 434944200, 435154350, 435364550, 435574800, 435785100, 435995450, 436205850, 436416300, 436626800, 436837350,
437047950, 437258600, 437469300, 437680050, 437890850, 438101700, 438312600, 438523550, 438734550, 438945600, 439156700, 439367850, 439579050, 439790300, 440001600, 440212950, 440424350, 440635800, 440847300,
441058850, 441270450, 441482100, 441693800, 441905550, 442117350, 442329200, 442541100, 442753050, 442965050, 443177100, 443389200, 443601350, 443813550, 444025800, 444238100, 444450450, 444662850, 444875300,
445087800, 445300350, 445512950, 445725600, 445938300, 446151050, 446363850, 446576700, 446789600, 447002550, 447215550, 447428600, 447641700, 447854850, 448068050, 448281300, 448494600, 448707950, 448921350,
449134800, 449348300, 449561850, 449775450, 449989100, 450202800, 450416550, 450630350, 450844200, 451058100, 451272050, 451486050, 451700100, 451914200, 452128350, 452342550, 452556800, 452771100, 452985450,
453199850, 453414300, 453628800, 453843350, 454057950, 454272600, 454487300, 454702050, 454916850, 455131700, 455346600, 455561550, 455776550, 455991600, 456206700, 456421850, 456637050, 456852300, 457067600,
457282950, 457498350, 457713800, 457929300, 458144850, 458360450, 458576100, 458791800, 459007550, 459223350, 459439200, 459655100, 459871050, 460087050, 460303100, 460519200, 460735350, 460951550, 461167800,
461384100, 461600450, 461816850, 462033300, 462249800, 462466350, 462682950, 462899600, 463116300, 463333050, 463549850, 463766700, 463983600, 464200550, 464417550, 464634600, 464851700, 465068850, 465286050,
465503300, 465720600, 465937950, 466155350, 466372800, 466590300, 466807850, 467025450, 467243100, 467460800, 467678550, 467896350, 468114200, 468332100, 468550050, 468768050, 468986100, 469204200, 469422350,
469640550, 469858800, 470077100, 470295450, 470513850, 470732300, 470950800, 471169350, 471387950, 471606600, 471825300, 472044050, 472262850, 472481700, 472700600, 472919550, 473138550, 473357600, 473576700,
473795850, 474015050, 474234300, 474453600, 474672950, 474892350, 475111800, 475331300, 475550850, 475770450, 475990100, 476209800, 476429550, 476649350, 476869200, 477089100, 477309050, 477529050, 477749100,
477969200, 478189350, 478409550, 478629800, 478850100, 479070450, 479290850, 479511300, 479731800, 479952350, 480172950, 480393600, 480614300, 480835050, 481055850, 481276700, 481497600, 481718550, 481939550, 482160600, 482381700, 482602850, 482824050, 483045300, 483266600, 483487950, 483709350, 483930800, 484152300, 484373850, 484595450, 484817100, 485038800, 485260550, 485482350, 485704200, 485926100, 486148050, 486370050, 486592100, 486814200, 487036350, 487258550, 487480800, 487703100, 487925450, 488147850, 488370300, 488592800, 488815350, 489037950, 489260600, 489483300, 489706050, 489928850, 490151700, 490374600, 490597550, 490820550, 491043600, 491266700, 491489850, 491713050, 491936300, 492159600, 492382950, 492606350, 492829800, 493053300, 493276850, 493500450, 493724100, 493947800, 494171550, 494395350, 494619200, 494843100, 495067050, 495291050, 495515100, 495739200, 495963350, 496187550, 496411800, 496636100, 496860450, 497084850, 497309300, 497533800, 497758350, 497982950, 498207600, 498432300, 498657050, 498881850, 499106700, 499331600, 499556550, 499781550, 500006600, 500231700, 500456850, 500682050, 500907300, 501132600, 501357950, 501583350, 501808800, 502034300, 502259850, 502485450, 502711100, 502936800, 503162550, 503388350, 503614200, 503840100, 504066050, 504292050, 504518100, 504744200, 504970350, 505196550, 505422800, 505649100, 505875450, 506101850, 506328300, 506554800, 506781350, 507007950, 507234600, 507461300, 507688050, 507914850, 508141700, 508368600, 508595550, 508822550, 509049600, 509276700, 509503850, 509731050, 509958300, 510185600, 510412950, 510640350, 510867800, 511095300, 511322850, 511550450, 511778100, 512005800, 512233550, 512461350, 512689200, 512917100, 513145050, 513373050, 513601100, 513829200, 514057350, 514285550, 514513800, 514742100, 514970450, 515198850, 515427300, 515655800, 515884350, 516112950, 516341600, 516570300, 516799050, 517027850, 517256700, 517485600, 517714550, 517943550, 518172600, 518401700, 518630850, 518860050, 519089300, 519318600, 519547950, 519777350, 520006800, 520236300, 520465850, 520695450, 520925100, 521154800, 521384550, 521614350, 521844200, 522074100, 522304050, 522534050, 522764100, 522994200, 523224350, 523454550, 523684800, 523915100, 524145450, 524375850, 524606300, 524836800, 525067350, 525297950, 525528600, 525759300, 525990050, 526220850, 526451700, 526682600, 526913550, 527144550, 527375600, 527606700, 527837850, 528069050, 528300300, 528531600, 528762950, 528994350, 529225800, 529457300, 529688850, 529920450, 530152100, 530383800, 530615550, 530847350, 531079200, 531311100, 531543050, 531775050, 532007100, 532239200, 532471350, 532703550, 532935800, 533168100, 533400450, 533632850, 533865300, 534097800, 534330350, 534562950, 534795600, 535028300, 535261050, 535493850, 535726700, 535959600, 536192550, 536425550, 536658600, 536891700, 537124850, 537358050, 537591300, 537824600, 538057950, 538291350, 538524800, 538758300, 538991850, 539225450, 539459100, 539692800, 539926550, 540160350, 540394200, 540628100, 540862050, 541096050, 541330100, 541564200, 541798350, 542032550, 542266800, 542501100, 542735450, 542969850, 543204300, 543438800, 543673350, 543907950, 544142600, 544377300, 544612050, 544846850, 545081700, 545316600, 545551550, 545786550, 546021600, 546256700, 546491850, 546727050, 546962300, 547197600, 547432950, 547668350, 547903800, 548139300, 548374850, 548610450, 548846100, 549081800, 549317550, 549553350, 549789200, 550025100, 550261050, 550497050, 550733100, 550969200, 551205350, 551441550, 551677800, 551914100, 552150450, 552386850, 552623300, 552859800, 553096350, 553332950, 553569600, 553806300, 554043050, 554279850, 554516700, 554753600, 554990550, 555227550, 555464600, 555701700, 555938850, 556176050, 556413300, 556650600, 556887950, 557125350, 557362800, 557600300, 557837850, 558075450, 558313100, 558550800, 558788550, 559026350, 559264200, 559502100, 559740050, 559978050, 560216100, 560454200, 560692350, 560930550, 561168800, 561407100, 561645450, 561883850, 562122300, 562360800, 562599350, 562837950, 563076600, 563315300, 563554050, 563792850, 564031700, 564270600, 564509550, 564748550, 564987600, 565226700, 565465850, 565705050, 565944300, 566183600, 566422950, 566662350, 566901800, 567141300, 567380850, 567620450, 567860100, 568099800, 568339550, 568579350, 568819200, 569059100, 569299050, 569539050, 569779100, 570019200, 570259350, 570499550, 570739800, 570980100, 571220450, 571460850, 571701300, 571941800, 572182350, 572422950, 572663600, 572904300, 573145050, 573385850, 573626700, 573867600, 574108550, 574349550, 574590600, 574831700, 575072850, 575314050, 575555300, 575796600, 576037950, 576279350, 576520800, 576762300, 577003850, 577245450, 577487100, 577728800, 577970550, 578212350, 578454200, 578696100, 578938050, 579180050, 579422100, 579664200, 579906350, 580148550, 580390800, 580633100, 580875450, 581117850, 581360300, 581602800, 581845350, 582087950, 582330600, 582573300, 582816050, 583058850, 583301700, 583544600, 583787550, 584030550, 584273600, 584516700, 584759850, 585003050, 585246300, 585489600, 585732950, 585976350, 586219800, 586463300, 586706850, 586950450, 587194100, 587437800, 587681550, 587925350, 588169200, 588413100, 588657050, 588901050, 589145100, 589389200, 589633350, 589877550, 590121800, 590366100, 590610450, 590854850, 591099300, 591343800, 591588350, 591832950, 592077600, 592322300, 592567050, 592811850, 593056700, 593301600, 593546550, 593791550, 594036600, 594281700, 594526850, 594772050, 595017300, 595262600, 595507950, 595753350, 595998800, 596244300, 596489850, 596735450, 596981100, 597226800, 597472550, 597718350, 597964200, 598210100, 598456050, 598702050, 598948100, 599194200, 599440350, 599686550, 599932800, 600179100, 600425450, 600671850, 600918300, 601164800, 601411350, 601657950, 601904600, 602151300, 602398050, 602644850, 602891700, 603138600, 603385550, 603632550, 603879600, 604126700, 604373850, 604621050, 604868300, 605115600, 605362950, 605610350, 605857800, 606105300, 606352850, 606600450, 606848100, 607095800, 607343550, 607591350, 607839200, 608087100, 608335050, 608583050, 608831100, 609079200, 609327350, 609575550, 609823800, 610072100, 610320450, 610568850, 610817300, 611065800, 611314350, 611562950, 611811600, 612060300, 612309050, 612557850, 612806700, 613055600, 613304550, 613553550, 613802600, 614051700, 614300850, 614550050, 614799300, 615048600, 615297950, 615547350, 615796800, 616046300, 616295850, 616545450, 616795100, 617044800, 617294550, 617544350, 617794200, 618044100, 618294050, 618544050, 618794100, 619044200, 619294350, 619544550, 619794800, 620045100, 620295450, 620545850, 620796300, 621046800, 621297350, 621547950, 621798600, 622049300, 622300050, 622550850, 622801700, 623052600, 623303550, 623554550, 623805600, 624056700, 624307850, 624559050, 624810300, 625061600, 625312950, 625564350, 625815800, 626067300, 626318850, 626570450, 626822100, 627073800, 627325550, 627577350, 627829200, 628081100, 628333050, 628585050, 628837100, 629089200, 629341350, 629593550, 629845800, 630098100, 630350450, 630602850, 630855300, 631107800, 631360350, 631612950, 631865600, 632118300, 632371050, 632623850, 632876700, 633129600, 633382550, 633635550, 633888600, 634141700, 634394850, 634648050, 634901300, 635154600, 635407950, 635661350, 635914800, 636168300, 636421850, 636675450, 636929100, 637182800, 637436550, 637690350, 637944200, 638198100, 638452050, 638706050, 638960100, 639214200, 639468350, 639722550, 639976800, 640231100, 640485450, 640739850, 640994300, 641248800, 641503350, 641757950, 642012600, 642267300, 642522050, 642776850, 643031700, 643286600, 643541550, 643796550, 644051600, 644306700, 644561850, 644817050, 645072300, 645327600, 645582950, 645838350, 646093800, 646349300, 646604850, 646860450, 647116100, 647371800, 647627550, 647883350, 648139200, 648395100, 648651050, 648907050, 649163100, 649419200, 649675350, 649931550, 650187800, 650444100, 650700450, 650956850, 651213300, 651469800, 651726350, 651982950, 652239600, 652496300, 652753050, 653009850, 653266700, 653523600, 653780550, 654037550, 654294600, 654551700, 654808850, 655066050, 655323300, 655580600, 655837950, 656095350, 656352800, 656610300, 656867850, 657125450, 657383100, 657640800, 657898550, 658156350, 658414200, 658672100, 658930050, 659188050, 659446100, 659704200, 659962350, 660220550, 660478800, 660737100, 660995450, 661253850, 661512300, 661770800, 662029350, 662287950, 662546600, 662805300, 663064050, 663322850, 663581700, 663840600, 664099550, 664358550, 664617600, 664876700, 665135850, 665395050, 665654300, 665913600, 666172950, 666432350, 666691800, 666951300, 667210850, 667470450, 667730100, 667989800, 668249550, 668509350, 668769200, 669029100, 669289050, 669549050, 669809100, 670069200, 670329350, 670589550, 670849800, 671110100, 671370450, 671630850, 671891300, 672151800, 672412350, 672672950, 672933600, 673194300, 673455050, 673715850, 673976700, 674237600, 674498550, 674759550, 675020600, 675281700, 675542850, 675804050, 676065300, 676326600, 676587950, 676849350, 677110800, 677372300, 677633850, 677895450, 678157100, 678418800, 678680550, 678942350, 679204200, 679466100, 679728050, 679990050, 680252100, 680514200, 680776350, 681038550, 681300800, 681563100, 681825450, 682087850, 682350300, 682612800, 682875350, 683137950, 683400600, 683663300, 683926050, 684188850, 684451700, 684714600, 684977550, 685240550, 685503600, 685766700, 686029850, 686293050, 686556300, 686819600, 687082950, 687346350, 687609800, 687873300, 688136850, 688400450, 688664100, 688927800, 689191550, 689455350, 689719200, 689983100, 690247050, 690511050, 690775100, 691039200, 691303350, 691567550, 691831800, 692096100, 692360450, 692624850, 692889300, 693153800, 693418350, 693682950, 693947600, 694212300, 694477050, 694741850, 695006700, 695271600, 695536550, 695801550, 696066600, 696331700, 696596850, 696862050, 697127300, 697392600, 697657950, 697923350, 698188800, 698454300, 698719850, 698985450, 699251100, 699516800, 699782550, 700048350, 700314200, 700580100, 700846050, 701112050, 701378100, 701644200, 701910350, 702176550, 702442800, 702709100, 702975450, 703241850, 703508300, 703774800, 704041350, 704307950, 704574600, 704841300, 705108050, 705374850, 705641700, 705908600, 706175550, 706442550, 706709600, 706976700, 707243850, 707511050, 707778300, 708045600, 708312950, 708580350, 708847800, 709115300, 709382850, 709650450, 709918100, 710185800, 710453550, 710721350, 710989200, 711257100, 711525050, 711793050, 712061100, 712329200, 712597350, 712865550, 713133800, 713402100, 713670450, 713938850, 714207300, 714475800, 714744350, 715012950, 715281600, 715550300, 715819050, 716087850, 716356700, 716625600, 716894550, 717163550, 717432600, 717701700, 717970850, 718240050, 718509300, 718778600, 719047950, 719317350, 719586800, 719856300, 720125850, 720395450, 720665100, 720934800, 721204550, 721474350, 721744200, 722014100, 722284050, 722554050, 722824100, 723094200, 723364350, 723634550, 723904800, 724175100, 724445450, 724715850, 724986300, 725256800, 725527350, 725797950, 726068600, 726339300, 726610050, 726880850, 727151700, 727422600, 727693550, 727964550, 728235600, 728506700, 728777850, 729049050, 729320300, 729591600, 729862950, 730134350, 730405800, 730677300, 730948850, 731220450, 731492100, 731763800, 732035550, 732307350, 732579200, 732851100, 733123050, 733395050, 733667100, 733939200, 734211350, 734483550, 734755800, 735028100, 735300450, 735572850, 735845300, 736117800, 736390350, 736662950, 736935600, 737208300, 737481050, 737753850, 738026700, 738299600, 738572550, 738845550, 739118600, 739391700, 739664850, 739938050, 740211300, 740484600, 740757950, 741031350, 741304800, 741578300, 741851850, 742125450, 742399100, 742672800, 742946550, 743220350, 743494200, 743768100, 744042050, 744316050, 744590100, 744864200, 745138350, 745412550, 745686800, 745961100, 746235450, 746509850, 746784300, 747058800, 747333350, 747607950, 747882600, 748157300, 748432050, 748706850, 748981700, 749256600, 749531550, 749806550, 750081600, 750356700, 750631850, 750907050, 751182300, 751457600, 751732950, 752008350, 752283800, 752559300, 752834850, 753110450, 753386100, 753661800, 753937550, 754213350, 754489200, 754765100, 755041050, 755317050, 755593100, 755869200, 756145350, 756421550, 756697800, 756974100, 757250450, 757526850, 757803300, 758079800, 758356350, 758632950, 758909600, 759186300, 759463050, 759739850, 760016700, 760293600, 760570550, 760847550, 761124600, 761401700, 761678850, 761956050, 762233300, 762510600, 762787950, 763065350, 763342800, 763620300, 763897850, 764175450, 764453100, 764730800, 765008550, 765286350, 765564200, 765842100, 766120050, 766398050, 766676100, 766954200, 767232350, 767510550, 767788800, 768067100, 768345450, 768623850, 768902300, 769180800, 769459350, 769737950, 770016600, 770295300, 770574050, 770852850, 771131700, 771410600, 771689550, 771968550, 772247600, 772526700, 772805850, 773085050, 773364300, 773643600, 773922950, 774202350, 774481800, 774761300, 775040850, 775320450, 775600100, 775879800, 776159550, 776439350, 776719200, 776999100, 777279050, 777559050, 777839100, 778119200, 778399350, 778679550, 778959800, 779240100, 779520450, 779800850, 780081300, 780361800, 780642350, 780922950, 781203600, 781484300, 781765050, 782045850, 782326700, 782607600, 782888550, 783169550, 783450600, 783731700, 784012850, 784294050, 784575300, 784856600, 785137950, 785419350, 785700800, 785982300, 786263850, 786545450, 786827100, 787108800, 787390550, 787672350, 787954200, 788236100, 788518050, 788800050, 789082100, 789364200, 789646350, 789928550, 790210800, 790493100, 790775450, 791057850, 791340300, 791622800, 791905350, 792187950, 792470600, 792753300, 793036050, 793318850, 793601700, 793884600, 794167550, 794450550, 794733600, 795016700, 795299850, 795583050, 795866300, 796149600, 796432950, 796716350, 796999800, 797283300, 797566850, 797850450, 798134100, 798417800, 798701550, 798985350, 799269200, 799553100, 799837050, 800121050, 800405100, 800689200, 800973350, 801257550, 801541800, 801826100, 802110450, 802394850, 802679300, 802963800, 803248350, 803532950, 803817600, 804102300, 804387050, 804671850, 804956700, 805241600, 805526550, 805811550, 806096600, 806381700, 806666850, 806952050, 807237300, 807522600, 807807950, 808093350, 808378800, 808664300, 808949850, 809235450, 809521100, 809806800, 810092550, 810378350, 810664200, 810950100, 811236050, 811522050, 811808100, 812094200, 812380350, 812666550, 812952800, 813239100, 813525450, 813811850, 814098300, 814384800, 814671350, 814957950, 815244600, 815531300, 815818050, 816104850, 816391700, 816678600, 816965550, 817252550, 817539600, 817826700, 818113850, 818401050, 818688300, 818975600, 819262950, 819550350, 819837800, 820125300, 820412850, 820700450, 820988100, 821275800, 821563550, 821851350, 822139200, 822427100, 822715050, 823003050, 823291100, 823579200, 823867350, 824155550, 824443800, 824732100, 825020450, 825308850, 825597300, 825885800, 826174350, 826462950, 826751600, 827040300, 827329050, 827617850, 827906700, 828195600, 828484550, 828773550, 829062600, 829351700, 829640850, 829930050, 830219300, 830508600, 830797950, 831087350, 831376800, 831666300, 831955850, 832245450, 832535100, 832824800, 833114550, 833404350, 833694200, 833984100, 834274050, 834564050, 834854100, 835144200, 835434350, 835724550, 836014800, 836305100, 836595450, 836885850, 837176300, 837466800, 837757350, 838047950, 838338600, 838629300, 838920050, 839210850, 839501700, 839792600, 840083550, 840374550, 840665600, 840956700, 841247850, 841539050, 841830300, 842121600, 842412950, 842704350, 842995800, 843287300, 843578850, 843870450, 844162100, 844453800, 844745550, 845037350, 845329200, 845621100, 845913050, 846205050, 846497100, 846789200, 847081350, 847373550, 847665800, 847958100, 848250450, 848542850, 848835300, 849127800, 849420350, 849712950, 850005600, 850298300, 850591050, 850883850, 851176700, 851469600, 851762550, 852055550, 852348600, 852641700, 852934850, 853228050, 853521300, 853814600, 854107950, 854401350, 854694800, 854988300, 855281850, 855575450, 855869100, 856162800, 856456550, 856750350, 857044200, 857338100, 857632050, 857926050, 858220100, 858514200, 858808350, 859102550, 859396800, 859691100, 859985450, 860279850, 860574300, 860868800, 861163350, 861457950, 861752600, 862047300, 862342050, 862636850, 862931700, 863226600, 863521550, 863816550, 864111600, 864406700, 864701850, 864997050, 865292300, 865587600, 865882950, 866178350, 866473800, 866769300, 867064850, 867360450, 867656100, 867951800, 868247550, 868543350, 868839200, 869135100, 869431050, 869727050, 870023100, 870319200, 870615350, 870911550, 871207800, 871504100, 871800450, 872096850, 872393300, 872689800, 872986350, 873282950, 873579600, 873876300, 874173050, 874469850, 874766700, 875063600, 875360550, 875657550, 875954600, 876251700, 876548850, 876846050, 877143300, 877440600, 877737950, 878035350, 878332800, 878630300, 878927850, 879225450, 879523100, 879820800, 880118550, 880416350, 880714200, 881012100, 881310050, 881608050, 881906100, 882204200, 882502350, 882800550, 883098800, 883397100, 883695450, 883993850, 884292300, 884590800, 884889350, 885187950, 885486600, 885785300, 886084050, 886382850, 886681700, 886980600, 887279550, 887578550, 887877600, 888176700, 888475850, 888775050, 889074300, 889373600, 889672950, 889972350, 890271800, 890571300, 890870850, 891170450, 891470100, 891769800, 892069550, 892369350, 892669200, 892969100, 893269050, 893569050, 893869100, 894169200, 894469350, 894769550, 895069800, 895370100, 895670450, 895970850, 896271300, 896571800, 896872350, 897172950, 897473600, 897774300, 898075050, 898375850, 898676700, 898977600, 899278550, 899579550, 899880600, 900181700, 900482850, 900784050, 901085300, 901386600, 901687950, 901989350, 902290800, 902592300, 902893850, 903195450, 903497100, 903798800, 904100550, 904402350, 904704200, 905006100, 905308050, 905610050, 905912100, 906214200, 906516350, 906818550, 907120800, 907423100, 907725450, 908027850, 908330300, 908632800, 908935350, 909237950, 909540600, 909843300, 910146050, 910448850, 910751700, 911054600, 911357550, 911660550, 911963600, 912266700, 912569850, 912873050, 913176300, 913479600, 913782950, 914086350, 914389800, 914693300, 914996850, 915300450, 915604100, 915907800, 916211550, 916515350, 916819200, 917123100, 917427050, 917731050, 918035100, 918339200, 918643350, 918947550, 919251800, 919556100, 919860450, 920164850, 920469300, 920773800, 921078350, 921382950, 921687600, 921992300, 922297050, 922601850, 922906700, 923211600, 923516550, 923821550, 924126600, 924431700, 924736850, 925042050, 925347300, 925652600, 925957950, 926263350, 926568800, 926874300, 927179850, 927485450, 927791100, 928096800, 928402550, 928708350, 929014200, 929320100, 929626050, 929932050, 930238100, 930544200, 930850350, 931156550, 931462800, 931769100, 932075450, 932381850, 932688300, 932994800, 933301350, 933607950, 933914600, 934221300, 934528050, 934834850, 935141700, 935448600, 935755550, 936062550, 936369600, 936676700, 936983850, 937291050, 937598300, 937905600, 938212950, 938520350, 938827800, 939135300, 939442850, 939750450, 940058100, 940365800, 940673550, 940981350, 941289200, 941597100, 941905050, 942213050, 942521100, 942829200, 943137350, 943445550, 943753800, 944062100, 944370450, 944678850, 944987300, 945295800, 945604350, 945912950, 946221600, 946530300, 946839050, 947147850, 947456700, 947765600, 948074550, 948383550, 948692600, 949001700, 949310850, 949620050, 949929300, 950238600, 950547950, 950857350, 951166800, 951476300, 951785850, 952095450, 952405100, 952714800, 953024550, 953334350, 953644200, 953954100, 954264050, 954574050, 954884100, 955194200, 955504350, 955814550, 956124800, 956435100, 956745450, 957055850, 957366300, 957676800, 957987350, 958297950, 958608600, 958919300, 959230050, 959540850, 959851700, 960162600, 960473550, 960784550, 961095600, 961406700, 961717850, 962029050, 962340300, 962651600, 962962950, 963274350, 963585800, 963897300, 964208850, 964520450, 964832100, 965143800, 965455550, 965767350, 966079200, 966391100, 966703050, 967015050, 967327100, 967639200, 967951350, 968263550, 968575800, 968888100, 969200450, 969512850, 969825300, 970137800, 970450350, 970762950, 971075600, 971388300, 971701050, 972013850, 972326700, 972639600, 972952550, 973265550, 973578600, 973891700, 974204850, 974518050, 974831300, 975144600, 975457950, 975771350, 976084800, 976398300, 976711850, 977025450, 977339100, 977652800, 977966550, 978280350, 978594200, 978908100, 979222050, 979536050, 979850100, 980164200, 980478350, 980792550, 981106800, 981421100, 981735450, 982049850, 982364300, 982678800, 982993350, 983307950, 983622600, 983937300, 984252050, 984566850, 984881700, 985196600, 985511550, 985826550, 986141600, 986456700, 986771850, 987087050, 987402300, 987717600, 988032950, 988348350, 988663800, 988979300, 989294850, 989610450, 989926100, 990241800, 990557550, 990873350, 991189200, 991505100, 991821050, 992137050, 992453100, 992769200, 993085350, 993401550, 993717800, 994034100, 994350450, 994666850, 994983300, 995299800, 995616350, 995932950, 996249600, 996566300, 996883050, 997199850, 997516700, 997833600, 998150550, 998467550, 998784600, 999101700, 999418850, 999736050, 1000053300, 1000370600, 1000687950, 1001005350, 1001322800, 1001640300, 1001957850, 1002275450, 1002593100, 1002910800, 1003228550, 1003546350, 1003864200, 1004182100, 1004500050, 1004818050, 1005136100, 1005454200, 1005772350, 1006090550, 1006408800, 1006727100, 1007045450, 1007363850, 1007682300, 1008000800, 1008319350, 1008637950, 1008956600, 1009275300, 1009594050, 1009912850, 1010231700, 1010550600, 1010869550, 1011188550, 1011507600, 1011826700, 1012145850, 1012465050, 1012784300, 1013103600, 1013422950, 1013742350, 1014061800, 1014381300, 1014700850, 1015020450, 1015340100, 1015659800, 1015979550, 1016299350, 1016619200, 1016939100, 1017259050, 1017579050, 1017899100, 1018219200, 1018539350, 1018859550, 1019179800, 1019500100, 1019820450, 1020140850, 1020461300, 1020781800, 1021102350, 1021422950, 1021743600, 1022064300, 1022385050, 1022705850, 1023026700, 1023347600, 1023668550, 1023989550, 1024310600, 1024631700, 1024952850, 1025274050, 1025595300, 1025916600, 1026237950, 1026559350, 1026880800, 1027202300, 1027523850, 1027845450, 1028167100, 1028488800, 1028810550, 1029132350, 1029454200, 1029776100, 1030098050, 1030420050, 1030742100, 1031064200, 1031386350, 1031708550, 1032030800, 1032353100, 1032675450, 1032997850, 1033320300, 1033642800, 1033965350, 1034287950, 1034610600, 1034933300, 1035256050, 1035578850, 1035901700, 1036224600, 1036547550, 1036870550, 1037193600, 1037516700, 1037839850, 1038163050, 1038486300, 1038809600, 1039132950, 1039456350, 1039779800, 1040103300, 1040426850, 1040750450, 1041074100, 1041397800, 1041721550, 1042045350, 1042369200, 1042693100, 1043017050, 1043341050, 1043665100, 1043989200, 1044313350, 1044637550, 1044961800, 1045286100, 1045610450, 1045934850, 1046259300, 1046583800, 1046908350, 1047232950, 1047557600, 1047882300, 1048207050, 1048531850, 1048856700, 1049181600, 1049506550, 1049831550, 1050156600, 1050481700, 1050806850, 1051132050, 1051457300, 1051782600, 1052107950, 1052433350, 1052758800, 1053084300, 1053409850, 1053735450, 1054061100, 1054386800, 1054712550, 1055038350, 1055364200, 1055690100, 1056016050, 1056342050, 1056668100, 1056994200, 1057320350, 1057646550, 1057972800, 1058299100, 1058625450, 1058951850, 1059278300, 1059604800, 1059931350, 1060257950, 1060584600, 1060911300, 1061238050, 1061564850, 1061891700, 1062218600, 1062545550, 1062872550, 1063199600, 1063526700, 1063853850, 1064181050, 1064508300, 1064835600, 1065162950, 1065490350, 1065817800, 1066145300, 1066472850, 1066800450, 1067128100, 1067455800, 1067783550, 1068111350, 1068439200, 1068767100, 1069095050, 1069423050, 1069751100, 1070079200, 1070407350, 1070735550, 1071063800, 1071392100, 1071720450, 1072048850, 1072377300, 1072705800, 1073034350, 1073362950, 1073691600, 1074020300, 1074349050, 1074677850, 1075006700, 1075335600, 1075664550, 1075993550, 1076322600, 1076651700, 1076980850, 1077310050, 1077639300, 1077968600, 1078297950, 1078627350, 1078956800, 1079286300, 1079615850, 1079945450, 1080275100, 1080604800, 1080934550, 1081264350, 1081594200, 1081924100, 1082254050, 1082584050, 1082914100, 1083244200, 1083574350, 1083904550, 1084234800, 1084565100, 1084895450, 1085225850, 1085556300, 1085886800, 1086217350, 1086547950, 1086878600, 1087209300, 1087540050, 1087870850, 1088201700, 1088532600, 1088863550, 1089194550, 1089525600, 1089856700, 1090187850, 1090519050, 1090850300, 1091181600, 1091512950, 1091844350, 1092175800, 1092507300, 1092838850, 1093170450, 1093502100, 1093833800, 1094165550, 1094497350, 1094829200, 1095161100, 1095493050, 1095825050, 1096157100, 1096489200, 1096821350, 1097153550, 1097485800, 1097818100, 1098150450, 1098482850, 1098815300, 1099147800, 1099480350, 1099812950, 1100145600, 1100478300, 1100811050, 1101143850, 1101476700, 1101809600, 1102142550, 1102475550, 1102808600, 1103141700, 1103474850, 1103808050, 1104141300, 1104474600, 1104807950, 1105141350, 1105474800, 1105808300, 1106141850, 1106475450, 1106809100, 1107142800, 1107476550, 1107810350, 1108144200, 1108478100, 1108812050, 1109146050, 1109480100, 1109814200, 1110148350, 1110482550, 1110816800, 1111151100, 1111485450, 1111819850, 1112154300, 1112488800, 1112823350, 1113157950, 1113492600, 1113827300, 1114162050, 1114496850, 1114831700, 1115166600, 1115501550, 1115836550, 1116171600, 1116506700, 1116841850, 1117177050, 1117512300, 1117847600, 1118182950, 1118518350, 1118853800, 1119189300, 1119524850, 1119860450, 1120196100, 1120531800, 1120867550, 1121203350, 1121539200, 1121875100, 1122211050, 1122547050, 1122883100, 1123219200, 1123555350, 1123891550, 1124227800, 1124564100, 1124900450, 1125236850, 1125573300, 1125909800, 1126246350, 1126582950, 1126919600, 1127256300, 1127593050, 1127929850, 1128266700, 1128603600, 1128940550, 1129277550, 1129614600, 1129951700, 1130288850, 1130626050, 1130963300, 1131300600, 1131637950, 1131975350, 1132312800, 1132650300, 1132987850, 1133325450, 1133663100, 1134000800, 1134338550, 1134676350, 1135014200, 1135352100, 1135690050, 1136028050, 1136366100, 1136704200, 1137042350, 1137380550, 1137718800, 1138057100, 1138395450, 1138733850, 1139072300, 1139410800, 1139749350, 1140087950, 1140426600, 1140765300, 1141104050, 1141442850, 1141781700, 1142120600, 1142459550, 1142798550, 1143137600, 1143476700, 1143815850, 1144155050, 1144494300, 1144833600, 1145172950, 1145512350, 1145851800, 1146191300, 1146530850, 1146870450, 1147210100, 1147549800, 1147889550, 1148229350, 1148569200, 1148909100, 1149249050, 1149589050, 1149929100, 1150269200, 1150609350, 1150949550, 1151289800, 1151630100, 1151970450, 1152310850, 1152651300, 1152991800, 1153332350, 1153672950, 1154013600, 1154354300, 1154695050, 1155035850, 1155376700, 1155717600, 1156058550, 1156399550, 1156740600, 1157081700, 1157422850, 1157764050, 1158105300, 1158446600, 1158787950, 1159129350, 1159470800, 1159812300, 1160153850, 1160495450, 1160837100, 1161178800, 1161520550, 1161862350, 1162204200, 1162546100, 1162888050, 1163230050, 1163572100, 1163914200, 1164256350, 1164598550, 1164940800, 1165283100, 1165625450, 1165967850, 1166310300, 1166652800, 1166995350, 1167337950, 1167680600, 1168023300, 1168366050, 1168708850, 1169051700, 1169394600, 1169737550, 1170080550, 1170423600, 1170766700, 1171109850, 1171453050, 1171796300, 1172139600, 1172482950, 1172826350, 1173169800, 1173513300, 1173856850, 1174200450, 1174544100, 1174887800, 1175231550, 1175575350, 1175919200, 1176263100, 1176607050, 1176951050, 1177295100, 1177639200, 1177983350, 1178327550, 1178671800, 1179016100, 1179360450, 1179704850, 1180049300, 1180393800, 1180738350, 1181082950, 1181427600, 1181772300, 1182117050, 1182461850, 1182806700, 1183151600, 1183496550, 1183841550, 1184186600, 1184531700, 1184876850, 1185222050, 1185567300, 1185912600, 1186257950, 1186603350, 1186948800, 1187294300, 1187639850, 1187985450, 1188331100, 1188676800, 1189022550, 1189368350, 1189714200, 1190060100, 1190406050, 1190752050, 1191098100, 1191444200, 1191790350, 1192136550, 1192482800, 1192829100, 1193175450, 1193521850, 1193868300, 1194214800, 1194561350, 1194907950, 1195254600, 1195601300, 1195948050, 1196294850, 1196641700, 1196988600, 1197335550, 1197682550, 1198029600, 1198376700, 1198723850, 1199071050, 1199418300, 1199765600, 1200112950, 1200460350, 1200807800, 1201155300, 1201502850, 1201850450, 1202198100, 1202545800, 1202893550, 1203241350, 1203589200, 1203937100, 1204285050, 1204633050, 1204981100, 1205329200, 1205677350, 1206025550, 1206373800, 1206722100, 1207070450, 1207418850, 1207767300, 1208115800, 1208464350, 1208812950, 1209161600, 1209510300, 1209859050, 1210207850, 1210556700, 1210905600, 1211254550, 1211603550, 1211952600, 1212301700, 1212650850, 1213000050, 1213349300, 1213698600, 1214047950, 1214397350, 1214746800, 1215096300, 1215445850, 1215795450, 1216145100, 1216494800, 1216844550, 1217194350, 1217544200, 1217894100, 1218244050, 1218594050, 1218944100, 1219294200, 1219644350, 1219994550, 1220344800, 1220695100, 1221045450, 1221395850, 1221746300, 1222096800, 1222447350, 1222797950, 1223148600, 1223499300, 1223850050, 1224200850, 1224551700, 1224902600, 1225253550, 1225604550, 1225955600, 1226306700, 1226657850, 1227009050, 1227360300, 1227711600, 1228062950, 1228414350, 1228765800, 1229117300, 1229468850, 1229820450, 1230172100, 1230523800, 1230875550, 1231227350, 1231579200, 1231931100, 1232283050, 1232635050, 1232987100, 1233339200, 1233691350, 1234043550, 1234395800, 1234748100, 1235100450, 1235452850, 1235805300, 1236157800, 1236510350, 1236862950, 1237215600, 1237568300, 1237921050, 1238273850, 1238626700, 1238979600, 1239332550, 1239685550, 1240038600, 1240391700, 1240744850, 1241098050, 1241451300, 1241804600, 1242157950, 1242511350, 1242864800, 1243218300, 1243571850, 1243925450, 1244279100, 1244632800, 1244986550, 1245340350, 1245694200, 1246048100, 1246402050, 1246756050, 1247110100, 1247464200, 1247818350, 1248172550, 1248526800, 1248881100, 1249235450, 1249589850, 1249944300, 1250298800, 1250653350, 1251007950, 1251362600, 1251717300, 1252072050, 1252426850, 1252781700, 1253136600, 1253491550, 1253846550, 1254201600, 1254556700, 1254911850, 1255267050, 1255622300, 1255977600, 1256332950, 1256688350, 1257043800, 1257399300, 1257754850, 1258110450, 1258466100, 1258821800, 1259177550, 1259533350, 1259889200, 1260245100, 1260601050, 1260957050, 1261313100, 1261669200, 1262025350, 1262381550, 1262737800, 1263094100, 1263450450, 1263806850, 1264163300, 1264519800, 1264876350, 1265232950, 1265589600, 1265946300, 1266303050, 1266659850, 1267016700, 1267373600, 1267730550, 1268087550, 1268444600, 1268801700, 1269158850, 1269516050, 1269873300, 1270230600, 1270587950, 1270945350, 1271302800, 1271660300, 1272017850, 1272375450, 1272733100, 1273090800, 1273448550, 1273806350, 1274164200, 1274522100, 1274880050, 1275238050, 1275596100, 1275954200, 1276312350, 1276670550, 1277028800, 1277387100, 1277745450, 1278103850, 1278462300, 1278820800, 1279179350, 1279537950, 1279896600, 1280255300, 1280614050, 1280972850, 1281331700, 1281690600, 1282049550, 1282408550, 1282767600, 1283126700, 1283485850, 1283845050, 1284204300, 1284563600, 1284922950, 1285282350, 1285641800, 1286001300, 1286360850, 1286720450, 1287080100, 1287439800, 1287799550, 1288159350, 1288519200, 1288879100, 1289239050, 1289599050, 1289959100, 1290319200, 1290679350, 1291039550, 1291399800, 1291760100, 1292120450, 1292480850, 1292841300, 1293201800, 1293562350, 1293922950, 1294283600, 1294644300, 1295005050, 1295365850, 1295726700, 1296087600, 1296448550, 1296809550, 1297170600, 1297531700, 1297892850, 1298254050, 1298615300, 1298976600, 1299337950, 1299699350, 1300060800, 1300422300, 1300783850, 1301145450, 1301507100, 1301868800, 1302230550, 1302592350, 1302954200, 1303316100, 1303678050, 1304040050, 1304402100, 1304764200, 1305126350, 1305488550, 1305850800, 1306213100, 1306575450, 1306937850, 1307300300, 1307662800, 1308025350, 1308387950, 1308750600, 1309113300, 1309476050, 1309838850, 1310201700, 1310564600, 1310927550, 1311290550, 1311653600, 1312016700, 1312379850, 1312743050, 1313106300, 1313469600, 1313832950, 1314196350, 1314559800, 1314923300, 1315286850, 1315650450, 1316014100, 1316377800, 1316741550, 1317105350, 1317469200, 1317833100, 1318197050, 1318561050, 1318925100, 1319289200, 1319653350, 1320017550, 1320381800, 1320746100, 1321110450, 1321474850, 1321839300, 1322203800, 1322568350, 1322932950, 1323297600, 1323662300, 1324027050, 1324391850, 1324756700, 1325121600, 1325486550, 1325851550, 1326216600, 1326581700, 1326946850, 1327312050, 1327677300, 1328042600, 1328407950, 1328773350, 1329138800, 1329504300, 1329869850, 1330235450, 1330601100, 1330966800, 1331332550, 1331698350, 1332064200, 1332430100, 1332796050, 1333162050, 1333528100, 1333894200, 1334260350, 1334626550, 1334992800, 1335359100, 1335725450, 1336091850, 1336458300, 1336824800, 1337191350, 1337557950, 1337924600, 1338291300, 1338658050, 1339024850, 1339391700, 1339758600, 1340125550, 1340492550, 1340859600, 1341226700, 1341593850, 1341961050, 1342328300, 1342695600, 1343062950, 1343430350, 1343797800, 1344165300, 1344532850, 1344900450, 1345268100, 1345635800, 1346003550, 1346371350, 1346739200, 1347107100, 1347475050, 1347843050, 1348211100, 1348579200, 1348947350, 1349315550, 1349683800, 1350052100, 1350420450, 1350788850, 1351157300, 1351525800, 1351894350, 1352262950, 1352631600, 1353000300, 1353369050, 1353737850, 1354106700, 1354475600, 1354844550, 1355213550, 1355582600, 1355951700, 1356320850, 1356690050, 1357059300, 1357428600, 1357797950, 1358167350, 1358536800, 1358906300, 1359275850, 1359645450, 1360015100, 1360384800, 1360754550, 1361124350, 1361494200, 1361864100, 1362234050, 1362604050, 1362974100, 1363344200, 1363714350, 1364084550, 1364454800, 1364825100, 1365195450, 1365565850, 1365936300, 1366306800, 1366677350, 1367047950, 1367418600, 1367789300, 1368160050, 1368530850, 1368901700, 1369272600, 1369643550, 1370014550, 1370385600, 1370756700, 1371127850, 1371499050, 1371870300, 1372241600, 1372612950, 1372984350, 1373355800, 1373727300, 1374098850, 1374470450, 1374842100, 1375213800, 1375585550, 1375957350, 1376329200, 1376701100, 1377073050, 1377445050, 1377817100, 1378189200, 1378561350, 1378933550, 1379305800, 1379678100, 1380050450, 1380422850, 1380795300, 1381167800, 1381540350, 1381912950, 1382285600, 1382658300, 1383031050, 1383403850, 1383776700, 1384149600, 1384522550, 1384895550, 1385268600, 1385641700, 1386014850, 1386388050, 1386761300, 1387134600, 1387507950, 1387881350, 1388254800, 1388628300, 1389001850, 1389375450, 1389749100, 1390122800, 1390496550, 1390870350, 1391244200, 1391618100, 1391992050, 1392366050, 1392740100, 1393114200, 1393488350, 1393862550, 1394236800, 1394611100, 1394985450, 1395359850, 1395734300, 1396108800, 1396483350, 1396857950, 1397232600, 1397607300, 1397982050, 1398356850, 1398731700, 1399106600, 1399481550, 1399856550, 1400231600, 1400606700, 1400981850, 1401357050, 1401732300, 1402107600, 1402482950, 1402858350, 1403233800, 1403609300, 1403984850, 1404360450, 1404736100, 1405111800, 1405487550, 1405863350, 1406239200, 1406615100, 1406991050, 1407367050, 1407743100, 1408119200, 1408495350, 1408871550, 1409247800, 1409624100, 1410000450, 1410376850, 1410753300, 1411129800, 1411506350, 1411882950, 1412259600, 1412636300, 1413013050, 1413389850, 1413766700, 1414143600, 1414520550, 1414897550, 1415274600, 1415651700, 1416028850, 1416406050, 1416783300, 1417160600, 1417537950, 1417915350, 1418292800, 1418670300, 1419047850, 1419425450, 1419803100, 1420180800, 1420558550, 1420936350, 1421314200, 1421692100, 1422070050, 1422448050, 1422826100, 1423204200, 1423582350, 1423960550, 1424338800, 1424717100, 1425095450, 1425473850, 1425852300, 1426230800, 1426609350, 1426987950, 1427366600, 1427745300, 1428124050, 1428502850, 1428881700, 1429260600, 1429639550, 1430018550, 1430397600, 1430776700, 1431155850, 1431535050, 1431914300, 1432293600, 1432672950, 1433052350, 1433431800, 1433811300, 1434190850, 1434570450, 1434950100, 1435329800, 1435709550, 1436089350, 1436469200, 1436849100, 1437229050, 1437609050, 1437989100, 1438369200, 1438749350, 1439129550, 1439509800, 1439890100, 1440270450, 1440650850, 1441031300, 1441411800, 1441792350, 1442172950, 1442553600, 1442934300, 1443315050, 1443695850, 1444076700, 1444457600, 1444838550, 1445219550, 1445600600, 1445981700, 1446362850, 1446744050, 1447125300, 1447506600, 1447887950, 1448269350, 1448650800, 1449032300, 1449413850, 1449795450, 1450177100, 1450558800, 1450940550, 1451322350, 1451704200, 1452086100, 1452468050, 1452850050, 1453232100, 1453614200, 1453996350, 1454378550, 1454760800, 1455143100, 1455525450, 1455907850, 1456290300, 1456672800, 1457055350, 1457437950, 1457820600, 1458203300, 1458586050, 1458968850, 1459351700, 1459734600, 1460117550, 1460500550, 1460883600, 1461266700, 1461649850, 1462033050, 1462416300, 1462799600, 1463182950, 1463566350, 1463949800, 1464333300, 1464716850, 1465100450, 1465484100, 1465867800, 1466251550, 1466635350, 1467019200, 1467403100, 1467787050, 1468171050, 1468555100, 1468939200, 1469323350, 1469707550, 1470091800, 1470476100, 1470860450, 1471244850, 1471629300, 1472013800, 1472398350, 1472782950, 1473167600, 1473552300, 1473937050, 1474321850, 1474706700, 1475091600, 1475476550, 1475861550, 1476246600, 1476631700, 1477016850, 1477402050, 1477787300, 1478172600, 1478557950, 1478943350, 1479328800, 1479714300, 1480099850, 1480485450, 1480871100, 1481256800, 1481642550, 1482028350, 1482414200, 1482800100, 1483186050, 1483572050, 1483958100, 1484344200, 1484730350, 1485116550, 1485502800, 1485889100, 1486275450, 1486661850, 1487048300, 1487434800, 1487821350, 1488207950, 1488594600, 1488981300, 1489368050, 1489754850, 1490141700, 1490528600, 1490915550, 1491302550, 1491689600, 1492076700, 1492463850, 1492851050, 1493238300, 1493625600, 1494012950, 1494400350, 1494787800, 1495175300, 1495562850, 1495950450, 1496338100, 1496725800, 1497113550, 1497501350, 1497889200, 1498277100, 1498665050, 1499053050, 1499441100, 1499829200, 1500217350, 1500605550, 1500993800, 1501382100, 1501770450, 1502158850, 1502547300, 1502935800, 1503324350, 1503712950, 1504101600, 1504490300, 1504879050, 1505267850, 1505656700, 1506045600, 1506434550, 1506823550, 1507212600, 1507601700, 1507990850, 1508380050, 1508769300, 1509158600, 1509547950, 1509937350, 1510326800, 1510716300, 1511105850, 1511495450, 1511885100, 1512274800, 1512664550, 1513054350, 1513444200, 1513834100, 1514224050, 1514614050, 1515004100, 1515394200, 1515784350, 1516174550, 1516564800, 1516955100, 1517345450, 1517735850, 1518126300, 1518516800, 1518907350, 1519297950, 1519688600, 1520079300, 1520470050, 1520860850, 1521251700, 1521642600, 1522033550, 1522424550, 1522815600, 1523206700, 1523597850, 1523989050, 1524380300, 1524771600, 1525162950, 1525554350, 1525945800, 1526337300, 1526728850, 1527120450, 1527512100, 1527903800, 1528295550, 1528687350, 1529079200, 1529471100, 1529863050, 1530255050, 1530647100, 1531039200, 1531431350, 1531823550, 1532215800, 1532608100, 1533000450, 1533392850, 1533785300, 1534177800, 1534570350, 1534962950, 1535355600, 1535748300, 1536141050, 1536533850, 1536926700, 1537319600, 1537712550, 1538105550, 1538498600, 1538891700, 1539284850, 1539678050, 1540071300, 1540464600, 1540857950, 1541251350, 1541644800, 1542038300, 1542431850, 1542825450, 1543219100, 1543612800, 1544006550, 1544400350, 1544794200, 1545188100, 1545582050, 1545976050, 1546370100, 1546764200, 1547158350, 1547552550, 1547946800, 1548341100, 1548735450, 1549129850, 1549524300, 1549918800, 1550313350, 1550707950, 1551102600, 1551497300, 1551892050, 1552286850, 1552681700, 1553076600, 1553471550, 1553866550, 1554261600, 1554656700, 1555051850, 1555447050, 1555842300, 1556237600, 1556632950, 1557028350, 1557423800, 1557819300, 1558214850, 1558610450, 1559006100, 1559401800, 1559797550, 1560193350, 1560589200, 1560985100, 1561381050, 1561777050, 1562173100, 1562569200, 1562965350, 1563361550, 1563757800, 1564154100, 1564550450, 1564946850, 1565343300, 1565739800, 1566136350, 1566532950, 1566929600, 1567326300, 1567723050, 1568119850, 1568516700, 1568913600, 1569310550, 1569707550, 1570104600, 1570501700, 1570898850, 1571296050, 1571693300, 1572090600, 1572487950, 1572885350, 1573282800, 1573680300, 1574077850, 1574475450, 1574873100, 1575270800, 1575668550, 1576066350, 1576464200, 1576862100, 1577260050, 1577658050, 1578056100, 1578454200, 1578852350, 1579250550, 1579648800, 1580047100, 1580445450, 1580843850, 1581242300, 1581640800, 1582039350, 1582437950, 1582836600, 1583235300, 1583634050, 1584032850, 1584431700, 1584830600, 1585229550, 1585628550, 1586027600, 1586426700, 1586825850, 1587225050, 1587624300, 1588023600, 1588422950, 1588822350, 1589221800, 1589621300, 1590020850, 1590420450, 1590820100, 1591219800, 1591619550, 1592019350, 1592419200, 1592819100, 1593219050, 1593619050, 1594019100, 1594419200, 1594819350, 1595219550, 1595619800, 1596020100, 1596420450, 1596820850, 1597221300, 1597621800, 1598022350, 1598422950, 1598823600, 1599224300, 1599625050, 1600025850, 1600426700, 1600827600, 1601228550, 1601629550, 1602030600, 1602431700, 1602832850, 1603234050, 1603635300, 1604036600, 1604437950, 1604839350, 1605240800, 1605642300, 1606043850, 1606445450, 1606847100, 1607248800, 1607650550, 1608052350, 1608454200, 1608856100, 1609258050, 1609660050, 1610062100, 1610464200, 1610866350, 1611268550, 1611670800, 1612073100, 1612475450, 1612877850, 1613280300, 1613682800, 1614085350, 1614487950, 1614890600, 1615293300, 1615696050, 1616098850, 1616501700, 1616904600, 1617307550, 1617710550, 1618113600, 1618516700, 1618919850, 1619323050, 1619726300, 1620129600, 1620532950, 1620936350, 1621339800, 1621743300, 1622146850, 1622550450, 1622954100, 1623357800, 1623761550, 1624165350, 1624569200, 1624973100, 1625377050, 1625781050, 1626185100, 1626589200, 1626993350, 1627397550, 1627801800, 1628206100, 1628610450, 1629014850, 1629419300, 1629823800, 1630228350, 1630632950, 1631037600, 1631442300, 1631847050, 1632251850, 1632656700, 1633061600, 1633466550, 1633871550, 1634276600, 1634681700, 1635086850, 1635492050, 1635897300, 1636302600, 1636707950, 1637113350, 1637518800, 1637924300, 1638329850, 1638735450, 1639141100, 1639546800, 1639952550, 1640358350, 1640764200, 1641170100, 1641576050, 1641982050, 1642388100, 1642794200, 1643200350, 1643606550, 1644012800, 1644419100, 1644825450, 1645231850, 1645638300, 1646044800, 1646451350, 1646857950, 1647264600, 1647671300, 1648078050, 1648484850, 1648891700, 1649298600, 1649705550, 1650112550, 1650519600, 1650926700, 1651333850, 1651741050, 1652148300, 1652555600, 1652962950, 1653370350, 1653777800, 1654185300, 1654592850, 1655000450, 1655408100, 1655815800, 1656223550, 1656631350, 1657039200, 1657447100, 1657855050, 1658263050, 1658671100, 1659079200, 1659487350, 1659895550, 1660303800, 1660712100, 1661120450, 1661528850, 1661937300, 1662345800, 1662754350, 1663162950, 1663571600, 1663980300, 1664389050, 1664797850, 1665206700, 1665615600, 1666024550, 1666433550, 1666842600, 1667251700, 1667660850, 1668070050, 1668479300, 1668888600, 1669297950, 1669707350, 1670116800, 1670526300, 1670935850, 1671345450, 1671755100, 1672164800, 1672574550, 1672984350, 1673394200, 1673804100, 1674214050, 1674624050, 1675034100, 1675444200, 1675854350, 1676264550, 1676674800, 1677085100, 1677495450, 1677905850, 1678316300, 1678726800, 1679137350, 1679547950, 1679958600, 1680369300, 1680780050, 1681190850, 1681601700, 1682012600, 1682423550, 1682834550, 1683245600, 1683656700, 1684067850, 1684479050, 1684890300, 1685301600, 1685712950, 1686124350, 1686535800, 1686947300, 1687358850, 1687770450, 1688182100, 1688593800, 1689005550, 1689417350, 1689829200, 1690241100, 1690653050, 1691065050, 1691477100, 1691889200, 1692301350, 1692713550, 1693125800, 1693538100, 1693950450, 1694362850, 1694775300, 1695187800, 1695600350, 1696012950, 1696425600, 1696838300, 1697251050, 1697663850, 1698076700, 1698489600, 1698902550, 1699315550, 1699728600, 1700141700, 1700554850, 1700968050, 1701381300, 1701794600, 1702207950, 1702621350, 1703034800, 1703448300, 1703861850, 1704275450, 1704689100, 1705102800, 1705516550, 1705930350, 1706344200, 1706758100, 1707172050, 1707586050, 1708000100, 1708414200, 1708828350, 1709242550, 1709656800, 1710071100, 1710485450, 1710899850, 1711314300, 1711728800, 1712143350, 1712557950, 1712972600, 1713387300, 1713802050, 1714216850, 1714631700, 1715046600, 1715461550, 1715876550, 1716291600, 1716706700, 1717121850, 1717537050, 1717952300, 1718367600, 1718782950, 1719198350, 1719613800, 1720029300, 1720444850, 1720860450, 1721276100, 1721691800, 1722107550, 1722523350, 1722939200, 1723355100, 1723771050, 1724187050, 1724603100, 1725019200, 1725435350, 1725851550, 1726267800, 1726684100, 1727100450, 1727516850, 1727933300, 1728349800, 1728766350, 1729182950, 1729599600, 1730016300, 1730433050, 1730849850, 1731266700, 1731683600, 1732100550, 1732517550, 1732934600, 1733351700, 1733768850, 1734186050, 1734603300, 1735020600, 1735437950, 1735855350, 1736272800, 1736690300, 1737107850, 1737525450, 1737943100, 1738360800, 1738778550, 1739196350, 1739614200, 1740032100, 1740450050, 1740868050, 1741286100, 1741704200, 1742122350, 1742540550, 1742958800, 1743377100, 1743795450, 1744213850, 1744632300, 1745050800, 1745469350, 1745887950, 1746306600, 1746725300, 1747144050, 1747562850, 1747981700, 1748400600, 1748819550, 1749238550, 1749657600, 1750076700, 1750495850, 1750915050, 1751334300, 1751753600, 1752172950, 1752592350, 1753011800, 1753431300, 1753850850, 1754270450, 1754690100, 1755109800, 1755529550, 1755949350, 1756369200, 1756789100, 1757209050, 1757629050, 1758049100, 1758469200, 1758889350, 1759309550, 1759729800, 1760150100, 1760570450, 1760990850, 1761411300, 1761831800, 1762252350, 1762672950, 1763093600, 1763514300, 1763935050, 1764355850, 1764776700, 1765197600, 1765618550, 1766039550, 1766460600, 1766881700, 1767302850, 1767724050, 1768145300, 1768566600, 1768987950, 1769409350, 1769830800, 1770252300, 1770673850, 1771095450, 1771517100, 1771938800, 1772360550, 1772782350, 1773204200, 1773626100, 1774048050, 1774470050, 1774892100, 1775314200, 1775736350, 1776158550, 1776580800, 1777003100, 1777425450, 1777847850, 1778270300, 1778692800, 1779115350, 1779537950, 1779960600, 1780383300, 1780806050, 1781228850, 1781651700, 1782074600, 1782497550, 1782920550, 1783343600, 1783766700, 1784189850, 1784613050, 1785036300, 1785459600, 1785882950, 1786306350, 1786729800, 1787153300, 1787576850 };

bool Features::RPLoop = false;
int Features::RPLoopDelay = 7;
int Rptick2 = 0;
int Rptick = 0;
void Features::rpLoop() {
	Rptick++;
	if (Rptick > Features::RPLoopDelay) {
		Memory::set_value<int>({ (2 * 4 * 2) / 2, 4 * 1000 + 280, 500 * 4 - 70 + 70 + 72 }, 3);
		Rptick2++;
		if (Rptick2 > Features::RPLoopDelay) {
			Memory::set_value<int>({ (2 * 4 * 2) / 2, 4 * 1000 + 280, 500 * 4 - 70 + 70 + 72 }, 0);
			Rptick = 0;
			Rptick2 = 0;
		}
	}
}

bool Features::selftenkped = false;
void Features::selfTenKPedMoney(bool toggle)
{
	/*bool on;
	if (PLAYER::IS_PLAYER_ONLINE()) {
		on = true;
	}
	else {
		on = false;
	}*/
	if ((timeGetTime() - Features::TimePD3) > 400) {
		Ped ClonedPedMoney = PED::CLONE_PED(PLAYER::PLAYER_ID(), 1, 1, 1);
		//ENTITY::SET_ENTITY_VISIBLE(ClonedPedMoney, false);
		PED::SET_PED_MONEY(ClonedPedMoney, 10000);
		ENTITY::SET_ENTITY_HEALTH(ClonedPedMoney, -1);
		Features::TimePD3 = timeGetTime();
	}
}

void Features::Online::TeleportToPlayer(Player player) {

	Entity handle;
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(player, false);
	PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : handle = PLAYER::PLAYER_PED_ID();
	ENTITY::SET_ENTITY_COORDS(handle, coords.x, coords.y, coords.z, false, false, false, false);
}

void Features::Online::TeleportIntoVehicle(Player player) {
	if (PED::IS_PED_IN_ANY_VEHICLE(player, false))
	{
		Vehicle selectedVehicle = PED::GET_VEHICLE_PED_IS_USING(player);
		int numSeats = VEHICLE::GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(selectedVehicle);
		for (int i = numSeats; i >= -1; i--)
		{
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), selectedVehicle, i);
		}
	}
}

Object Features::SpawnObject(char* name, Vector3 coords) {
	//Features::fuck_me_sideways(1);
	Object ob = GAMEPLAY::GET_HASH_KEY(name);
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	STREAMING::REQUEST_MODEL(ob);
	while (!STREAMING::HAS_MODEL_LOADED(ob)) WAIT(0);
	    Object obj = OBJECT::CREATE_OBJECT(ob, pos.x, pos.y, pos.z, true, 1, 0);
	    return obj;
	//	Object obj = CREATE_OBJECT_NO_OFFSET(GET_HASH_KEY(name), coords.x, coords.y, coords.z, 1, 0, 0);
}

Vehicle Features::SpawnVehicle(char* modelg, Vector3 coords, bool tpinto, float heading) {
	//Features::fuck_me_sideways(1);
	DWORD model = GAMEPLAY::GET_HASH_KEY(modelg);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_A_VEHICLE(model)) {
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, coords.x, coords.y, coords.z, heading, 1, 1);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		VEHICLE::SET_VEHICLE_IS_STOLEN(veh, 0);
		return veh;
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}
}

bool Features::blackhole = false;
Vector3 Features::location = { 0, 0, 0 };
int Features::holePED = 0;
void Features::hole(bool toggle) {
	if (toggle) {
			const int ElementAmount = 100;
			const int ArrSize = ElementAmount * 2 + 2;

			Ped *peds = new Ped[ArrSize];
			peds[0] = ElementAmount;

			int PedFound = PED::GET_PED_NEARBY_PEDS(Features::holePED, peds, -1);

			for (int i = 0; i < PedFound; i++)
			{
				int OffsetID = i * 2 + 2;
				/*if (peds[OffsetID] != PLAYER::PLAYER_PED_ID() && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(peds[OffsetID]) == false)
				{
					RequestControlOfEnt(peds[OffsetID]);
				}*/

				//ENTITY::APPLY_FORCE_TO_ENTITY(peds[OffsetID], 5, Features::location.x, Features::location.y, Features::location.z, 0, 0, 0, 0, 1, 1, 1, 0, 1);
				ENTITY::APPLY_FORCE_TO_ENTITY(peds[OffsetID], 1, Features::location.x, Features::location.y, Features::location.z, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);
			}
	}
}

void Features::sendMessage(char* pic, int icon, char* sender, char* subtitle, char* clantag) {
	/*
	picNames:
	pastebin.com/XdpJVbHz

	iconTypes:
    1 : Chat Box
    2 : Email
    3 : Add Friend Request
    4 : Nothing
    5 : Nothing
    6 : Nothing
    7 : Right Jumping Arrow
    8 : RP Icon
    9 : $ Icon

	"sender" is the very top header. This can be any old string.
    "subject" is the header under the sender.
	"duration" is a multiplier, so 1.0 is normal, 2.0 is twice as long (very slow), and 0.5 is half as long.
	"clanTag" shows a crew tag in the "sender" header, after the text. You need to use 3 underscores as padding. Maximum length of this field seems to be 7. (e.g. "MK" becomes "___MK", "ACE" becomes "___ACE", etc.)
	iconType2 is a mirror of iconType. It shows in the "subject" line, right under the original iconType.
	"p9" is the color of the sender's MP name. In the scripts it is set to one of the pre-defined colors HUD_COLOUR_G1 (192) .. HUD_COLOUR_G15 (206)
	*/
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2(pic, pic, false, icon, sender, subtitle, 10, clantag, icon);
}

void Features::AttachThingToThing(Any p0, Any p1, float x, float y, float z, float rx, float ry, float rz) {
	//ATTACH_ENTITY_TO_ENTITY(p0, p1, 0, -0.5f, -0.2f, -0.1f, 0.0f, 0.0f, 180.0f, 1, 0, 0, 2, 1, 1);
	ENTITY::ATTACH_ENTITY_TO_ENTITY(p0, p1, 0, x, y, z, rx, ry, rz, 1, 0, 0, 2, 1, 1);
}

int Features::spawnStuff(char* name, Vector3 coords) {
	//Features::fuck_me_sideways(1);
	Any output = NULL;
	DWORD model = GAMEPLAY::GET_HASH_KEY(name);
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		if (STREAMING::IS_MODEL_A_VEHICLE(model)) {
			output = VEHICLE::CREATE_VEHICLE(model, coords.x, coords.y, coords.z, 0, 1, 1);
		}
		else {
			output = OBJECT::CREATE_OBJECT(model, coords.x, coords.y, coords.z, true, 1, 0);
		}
		//Vehicle veh = VEHICLE::CREATE_VEHICLE(model, coords.x, coords.y, coords.z, heading, 1, 1);
		return output;
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
}

float Features::locX = 0;
float Features::locY = 0;
float Features::locZ = 0;
bool Features::blockX = false;
bool Features::blockY = false;
bool Features::blockZ = false;

void Features::Attachment(char* p0) {	
	int thing1 = Features::spawnStuff(p0, coordsOf(PLAYER::PLAYER_PED_ID()));
	Vehicle thing2 = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	Features::AttachThingToThing(thing1, thing2, Features::locX, Features::locY, Features::locZ, 0.0f, 0.0f, 0.0f);
	Features::things[Features::carCounter] = thing1;
	Features::carCounter += 1;
}

void Features::moveStuff(float ox, float oy, float oz) {
	Vehicle thing2 = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	if (Features::locX > 999 || Features::locX < -999) {
		Features::blockX = true;
	}
	else {
		Features::blockX = false;
	}
	if (Features::locY > 999 || Features::locY < -999) {
		Features::blockY = true;
	}
	else {
		Features::blockY = false;
	}
	if (Features::locZ > 999 || Features::locZ < -999) {
		Features::blockZ = true;
	}
	else {
		Features::blockZ = false;
	}
	if (!Features::blockX) {
		Features::locX += ox;
		Features::AttachThingToThing(Features::things[Features::carCounter], thing2, locX, locY, locZ, 0.0f, 0.0f, 0.0f);
	}
	if (!Features::blockY) {
		Features::locY += oy;
		Features::AttachThingToThing(Features::things[Features::carCounter], thing2, locX, locY, locZ, 0.0f, 0.0f, 0.0f);
	}
	if (!Features::blockZ) {
		Features::locZ += oz;
		Features::AttachThingToThing(Features::things[Features::carCounter], thing2, locX, locY, locZ, 0.0f, 0.0f, 0.0f);
	}
}

void Features::updateCoords() {
	Vector3 ec = coordsOf(PLAYER::PLAYER_PED_ID());
	int nx = ec.x + Features::locX;
	int ny = ec.y + Features::locY;
	int nz = ec.z + Features::locZ;
	ENTITY::SET_ENTITY_COORDS(Features::things[Features::carCounter], nx, ny, nz, false, false, false, false);
}

void Features::attachCar(Player pimmel) {
	RequestControlOfEnt(PED::GET_VEHICLE_PED_IS_USING(pimmel));
	RequestControlOfEnt(pimmel);
	AttachThingToThing(PED::GET_VEHICLE_PED_IS_USING(pimmel), PLAYER::PLAYER_PED_ID(), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
}

bool Features::SEbool = false;
int Features::SE()
{
	int* args = 0;
	int ArgsStruct[3];
	//Hooking::get_script_event_data(1, 0, args, 2);
	if (args > 0)
	{
		//Hooking::get_script_event_data(1, 0, &ArgsStruct[3], 3); // &ArgsStruct gave an error 
		return ArgsStruct[3];
	}
	Log::Msg("Event Data: " + ArgsStruct[0] + ArgsStruct[1] + ArgsStruct[2] + ArgsStruct[3]);
	return 0;
}

char* Features::friendTag[33] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
bool Features::isFriend(Player p) {
	int handle[26];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(p, &handle[0], 13);
	return NETWORK::NETWORK_IS_HANDLE_VALID(&handle[0], 13) && NETWORK::NETWORK_IS_FRIEND(&handle[0]);
}

void Features::bounty(Player p, int a) {
	NETWORKCASH::NETWORK_BUY_BOUNTY(a, p, false, true);
}

/*void Features::RequestControlOfid(Entity netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}*/

int Features::attachobj[100];
int Features::nuattach = 1;
void Features::attachobjects2(char* object)
{
	bool custom = false;
	int hash = 0;
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true);
	hash = GAMEPLAY::GET_HASH_KEY(object);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(hash))
	{
		if (STREAMING::IS_MODEL_VALID(hash))
		{
			STREAMING::REQUEST_MODEL(hash);
			if (STREAMING::HAS_MODEL_LOADED(hash))
			{
				Features::attachobj[Features::nuattach] = OBJECT::CREATE_OBJECT(hash, pos.x, pos.y, pos.z, 1, 1, 1);
				if (ENTITY::DOES_ENTITY_EXIST(Features::attachobj[Features::nuattach]))
				{
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Features::attachobj[Features::nuattach], PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 31086, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
					nuattach++;
					if (nuattach >= 101) { nuattach = 1; }
				}
			}
		}
	}
}

int Features::attachobj3[100];
int Features::nuattach3 = 1;
void Features::attachobjects3(char* object)
{
	bool custom = false;
	int hash = 0;
	for (int i = 0; i < 33; i++) {
		if (Features::exclude(i)) {
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), true);
			hash = GAMEPLAY::GET_HASH_KEY(object);
			if (STREAMING::IS_MODEL_IN_CDIMAGE(hash))
			{
				if (STREAMING::IS_MODEL_VALID(hash))
				{
					STREAMING::REQUEST_MODEL(hash);
					if (STREAMING::HAS_MODEL_LOADED(hash))
					{
						Features::attachobj3[Features::nuattach3] = OBJECT::CREATE_OBJECT(hash, pos.x, pos.y, pos.z, 1, 1, 1);
						if (ENTITY::DOES_ENTITY_EXIST(Features::attachobj3[Features::nuattach3]))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Features::attachobj3[Features::nuattach3], PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 31086, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
							nuattach3++;
							if (nuattach3 >= 101) { nuattach3 = 1; }
						}
					}
				}
			}
		}
	}
}

void Features::semigod() {
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_juicestand");
	int attacc = 0;
	if (STREAMING::IS_MODEL_IN_CDIMAGE(hash))
	{
		if (STREAMING::IS_MODEL_VALID(hash))
		{
			STREAMING::REQUEST_MODEL(hash);
			if (STREAMING::HAS_MODEL_LOADED(hash))
			{
				attacc = OBJECT::CREATE_OBJECT(hash, pos.x, pos.y, pos.z, 1, 1, 1);
				if (ENTITY::DOES_ENTITY_EXIST(attacc))
				{
					ENTITY::ATTACH_ENTITY_TO_ENTITY(attacc, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 31086, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
					ENTITY::SET_ENTITY_VISIBLE(attacc, false);
				}
			}
		}
	}
}

bool Features::devMode() {
	return DLC2::IS_DLC_PRESENT(-1762644250);
}

bool cstrcmp(const char* s1, const char* s2)
{
	while (*s1 && (*s1 == *s2))
		s1++, s2++;
	if (*(const unsigned char*)s1 - *(const unsigned char*)s2 == 0)
		return true;
	else
		return false;
}
int fam;
void Features::changeClothes(char* family, int model, int texture)
{
	if (cstrcmp(family, "HATS") || cstrcmp(family, "GLASSES") || cstrcmp(family, "EARS"))
	{
		if (cstrcmp(family, "HATS"))
			fam = 0;
		else if (cstrcmp(family, "GLASSES"))
			fam = 1;
		else if (cstrcmp(family, "EARS"))
			fam = 2;
		PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), fam, model - 1, texture, 1);
	}
	else
	{
		if (cstrcmp(family, "FACE"))
			fam = 0;
		else if (cstrcmp(family, "MASK"))
			fam = 1;
		else if (cstrcmp(family, "HAIR"))
			fam = 2;
		else if (cstrcmp(family, "TORSO"))
			fam = 3;
		else if (cstrcmp(family, "LEGS"))
			fam = 4;
		else if (cstrcmp(family, "HANDS"))
			fam = 5;
		else if (cstrcmp(family, "SHOES"))
			fam = 6;
		else if (cstrcmp(family, "SPECIAL1"))
			fam = 7;
		else if (cstrcmp(family, "SPECIAL2"))
			fam = 8;
		else if (cstrcmp(family, "SPECIAL3"))
			fam = 9;
		else if (cstrcmp(family, "TEXTURE"))
			fam = 10;
		else if (cstrcmp(family, "TORSO2"))
			fam = 11;
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), fam, model, texture, 0);
	}
}

void Features::beachFireEmUp()
{ // prop_beach_fire
	for (int i = 0; i < 32; i++)
	{
		if (Features::exclude(i)) {
			Player playerHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			Hash beach_fire = GAMEPLAY::GET_HASH_KEY("prop_beach_fire");
			STREAMING::REQUEST_MODEL(beach_fire);
			while (!STREAMING::HAS_MODEL_LOADED(beach_fire)) WAIT(0);
			Object object = OBJECT::CREATE_OBJECT(beach_fire, 0, 0, 0, true, true, false);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object, playerHandle, 31086, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(beach_fire);
		}
	}
}

void Features::beachFire(Player p)
{ // prop_beach_fire
		Player playerHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
		Hash beach_fire = GAMEPLAY::GET_HASH_KEY("prop_beach_fire");
		STREAMING::REQUEST_MODEL(beach_fire);
		while (!STREAMING::HAS_MODEL_LOADED(beach_fire)) WAIT(0);
		Object object = OBJECT::CREATE_OBJECT(beach_fire, 0, 0, 0, true, true, false);
		ENTITY::ATTACH_ENTITY_TO_ENTITY(object, playerHandle, 31086, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(beach_fire);
}

char* Features::enemyWeapon = NULL;
char* Features::enemyModel = NULL;
void Features::spawnEnemy(Player victim, char* model, char* weapon) {
	//Features::fuck_me_sideways(1);
	Player vic = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(victim);
	int enemyarray[1000];
	int enemyindex = 1;
	if (!ENTITY::DOES_ENTITY_EXIST(vic)) return;
	Hash gun = GAMEPLAY::GET_HASH_KEY(weapon);
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(vic, 1);
	Hash pedm = GAMEPLAY::GET_HASH_KEY(model);
	STREAMING::REQUEST_MODEL(pedm);
	while (!STREAMING::HAS_MODEL_LOADED(pedm))
		WAIT(0);
	enemyarray[enemyindex] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
	ENTITY::SET_ENTITY_INVINCIBLE(enemyarray[enemyindex], false);
	PED::SET_PED_COMBAT_ABILITY(enemyarray[enemyindex], 100);
	WEAPON::GIVE_WEAPON_TO_PED(enemyarray[enemyindex], gun, gun, 9999, 9999);
	PED::SET_PED_CAN_SWITCH_WEAPON(enemyarray[enemyindex], true);
	AI::TASK_COMBAT_PED(enemyarray[enemyindex], vic, 1, 1);
	PED::SET_PED_ALERTNESS(enemyarray[enemyindex], 1000);
	PED::SET_PED_COMBAT_RANGE(enemyarray[enemyindex], 1000);
	enemyindex++;
}

bool Features::ESP::esper = false;
int Features::ESP::red = 255;
int Features::ESP::green = 0;
int Features::ESP::blue = 0;
void Features::ESP::esp(Player target)
{
	if (target != PLAYER::PLAYER_ID() && ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target)))
	{
		Vector3 locationOne = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
		Vector3 locationTwo = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
		GRAPHICS::DRAW_LINE(locationOne.x, locationOne.y, locationOne.z, locationTwo.x, locationTwo.y, locationTwo.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
	}
}
bool Features::ESP::esp2b = false;
void Features::ESP::esp2(Player target)
{
	if (target != PLAYER::PLAYER_PED_ID() && ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target)))
	{
		Vector3 entitylocation = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
		Vector3 top1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 top2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 top3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 top4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 bottom1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
		Vector3 bottom2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
		Vector3 bottom3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };
		Vector3 bottom4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };

		GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top2world.x, top2world.y, top2world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, top4world.x, top4world.y, top4world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, top3world.x, top3world.y, top3world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top3world.x, top3world.y, top3world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);

		GRAPHICS::DRAW_LINE(bottom1world.x, bottom1world.y, bottom1world.z, bottom2world.x, bottom2world.y, bottom2world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		GRAPHICS::DRAW_LINE(bottom2world.x, bottom2world.y, bottom2world.z, bottom4world.x, bottom4world.y, bottom4world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom4world.x, bottom4world.y, bottom4world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom1world.x, bottom1world.y, bottom1world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);

		GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, bottom1world.x, bottom1world.y, bottom1world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, bottom2world.x, bottom2world.y, bottom2world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		GRAPHICS::DRAW_LINE(top3world.x, top3world.y, top3world.z, bottom3world.x, bottom3world.y, bottom3world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, bottom4world.x, bottom4world.y, bottom4world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
	}
}
bool Features::ESP::NameESP = false;
void Features::ESP::NameTagESP(bool toggle)
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	for (int i = 0; i < 32; i++)
	{
		Player playerHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
		Vector3 handleCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerHandle, 0, 0, 0);
		Vector3 playerCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
		char* Name = PLAYER::GET_PLAYER_NAME(PLAYER::INT_TO_PLAYERINDEX(i));

		if (ENTITY::DOES_ENTITY_EXIST(playerHandle))
		{
			float x1;
			float y1;

			BOOL screenCoords = GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(handleCoords.x, handleCoords.y, handleCoords.z, &x1, &y1);

			std::string playerName = PLAYER::GET_PLAYER_NAME(PLAYER::INT_TO_PLAYERINDEX(i));

			std::string nameSetupRed = "~HUD_COLOUR_RED~" + playerName;
			std::string nameSetupGreen = "~HUD_COLOUR_GREEN~" + playerName;

			char* playerInfoRed = new char[nameSetupRed.length() + 1];
			char* playerInfoGreen = new char[nameSetupGreen.length() + 1];

			std::strcpy(playerInfoRed, nameSetupRed.c_str());
			std::strcpy(playerInfoGreen, nameSetupGreen.c_str());

			UI::SET_TEXT_FONT(7);
			UI::SET_TEXT_SCALE(0.0, 0.40);
			UI::SET_TEXT_COLOUR(Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
			UI::SET_TEXT_CENTRE(0);
			UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
			UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
			UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
			if (ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(playerPed, playerHandle, 17))
			{
				UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(playerInfoGreen);
			}
			else
			{
				UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(playerInfoRed);
			}
			UI::END_TEXT_COMMAND_DISPLAY_TEXT(x1, y1);
			UI::SET_TEXT_OUTLINE();
			UI::SET_TEXT_DROPSHADOW(5, 0, 78, 255, 255);
		}
	}
}

bool Features::badsportbool = false;
void Features::badsport(bool t) {
	Features::changeClothes("HATS", 2, 0);
}

void Features::clearanim()
{
	AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());

}

void Features::doAnimation(char* anim, char* animid)
{
	int pPlayer = PLAYER::PLAYER_PED_ID();
	RequestNetworkControl(pPlayer);
	STREAMING::REQUEST_ANIM_DICT(anim);
	if (STREAMING::HAS_ANIM_DICT_LOADED((anim)))
	{
		AI::TASK_PLAY_ANIM(pPlayer, anim, animid, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
	}
}

void Features::clearanim2()
{
	AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer));

}

void Features::doAnimation2(char* dict, char* anim) {
	Ped targ_ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(targ_ped, 1);
	int sceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(coords.x, coords.y, coords.z, 0, 0, 0, 2, 0, 1, 1.0f, 0.0f, 1.0f);
	STREAMING::REQUEST_ANIM_DICT(dict);
	if (STREAMING::HAS_ANIM_DICT_LOADED(dict))
	{
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(targ_ped, 1);
		int sceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(coords.x, coords.y, coords.z, 0, 0, 0, 2, 0, 1, 1.0f, 0.0f, 1.0f);
		NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(targ_ped, sceneID, dict, anim, 8.0f, -8.0f, 269, 0, 100.0f, 0);
		NETWORK::NETWORK_START_SYNCHRONISED_SCENE(sceneID);
	}
}

void Features::TPtoMe(Player player, Vector3 target)
{
	for (int iz = 0; iz < 2; iz++)
	{
		Ped destPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
		Vector3 ourLoc = target;
		AI::CLEAR_PED_TASKS_IMMEDIATELY(destPed);
		int netScene = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(ourLoc.x, ourLoc.y, ourLoc.z, 0.f, 0.f, 0.f, 0, 0, 0, 0.f, 0.f, 0.f);
		NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(destPed, netScene, "amb@code_human_cower@female@base", "base", 8.f, -8.f, 2, 0, 100.f, 0);
		NETWORK::NETWORK_START_SYNCHRONISED_SCENE(netScene);
		WAIT(150);
		AI::CLEAR_PED_TASKS_IMMEDIATELY(destPed);
		NETWORK::NETWORK_STOP_SYNCHRONISED_SCENE(netScene);
	}
}

void Features::remoteSpawnVehicle(std::string vehicle, Player p)
{
	//Features::fuck_me_sideways(1);
	int playa = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	Hash model = GAMEPLAY::GET_HASH_KEY((char*)_strdup(vehicle.c_str()));
	if (STREAMING::IS_MODEL_VALID(model))
	{
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);

		float forward = 5.f;
		float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
		float xVector = forward * sin(degToRad(heading)) * -1.f;
		float yVector = forward * cos(degToRad(heading));
		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, coordsOf(playa).x + xVector, coordsOf(playa).y + yVector, coordsOf(playa).z, heading, true, true);

		spawned[spawnIndex] = veh;
		spawnedHash[spawnIndex] = GAMEPLAY::GET_HASH_KEY((char*)vehicle.c_str());
		spawnIndex++;

		Vehicle VEHICLE1 = PED::GET_VEHICLE_PED_IS_IN(playa, true);
		Vector3 coords1 = ENTITY::GET_ENTITY_COORDS(VEHICLE1, false);

		RequestControlOfEnt(veh);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
		auto networkId = NETWORK::VEH_TO_NET(veh);
		ENTITY::_SET_ENTITY_SOMETHING(veh, true);
		if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(veh))
			NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);
		if (spawnincar)
		{
			PED::SET_PED_INTO_VEHICLE(playa, veh, -1);
		}
		if (spawnmaxed)
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			for (int i = 0; i < 50; i++)
			{
				VEHICLE::SET_VEHICLE_MOD(veh, i, VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) - 1, false);
			}
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, "X-Force");
		}
		if (Features::setcustompricolour)
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, Features::pricustomred, Features::pricustomgreen, Features::pricustomblue);
		}
		if (Features::setcustomseccolour)
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, Features::seccustomred, Features::seccustomgreen, Features::seccustomblue);
		}
		if (spawnwithblip)
		{
			UI::SET_BLIP_COLOUR(225, 67);
			UI::SET_BLIP_COORDS(225, coords1.x, coords1.y, coords1.z);
		}
		if (cargodmodebool) {
			Features::cargodmode3(veh);
		}
		WAIT(150);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}
}

void Features::giveMenuWeapons(Player p) {
	WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), true);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 2725352035, 9999, 1);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0x13532244, 9999, 0);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0x1D073A89, 9999, 0);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0x7846A318, 9999, 0);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0xE284C527, 9999, 0);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0x9D61E50F, 9999, 0);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0xB1CA77B1, 9999, 0);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0xBFD21232, 9999, 0);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0x083839C4, 9999, 0);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0x060EC506, 9999, 0);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0xBFEFFF6D, 9999, 0);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0x83BF0278, 9999, 0);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0xAF113F99, 9999, 0);
}

bool Features::minimenu[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

bool Features::mm_godmode = false;
bool Features::mm_spawn = false;
bool Features::mm_money = false;
bool Features::mm_weather = false;
bool Features::mm_explode = false;
bool Features::mm_teleport = false;

void Features::miniMenu(Player p) {
	Hash weaponHash;
	if (WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), &weaponHash, 1)) {
		if (weaponHash == 2725352035) {
			//"Unarmed";
		}
		else if (weaponHash == 0x678B81B1) {
			//"Nightstick";
		}
		else if (weaponHash == 0x4E875F73) {
			//"Hammer";
		}
		else if (weaponHash == 0x958A4A8F) {
			//"Bat";
		}
		else if (weaponHash == 0x440E4788) {
			//"GolfClub";
		}
		else if (weaponHash == 0x84BD7BFD) {
			//"Crowbar";
		}
		else if (weaponHash == 0x1B06D571) {
			//"Pistol";
		}
		else if (weaponHash == 0x5EF9FEC4) {
			//"Combat Pistol";
		}
		else if (weaponHash == 0x22D8FE39) {
			//"AP Pistol";
		}
		else if (weaponHash == 0x99AEEB3B) {
			//"Pistol 50";
		}
		else if (weaponHash == 0x13532244 && mm_godmode) {
			//"Micro SMG";
			if (is_ped_shooting(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p))) {
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), true);
				int hash = GAMEPLAY::GET_HASH_KEY("prop_juicestand");
				int attacc = 0;
				if (STREAMING::IS_MODEL_IN_CDIMAGE(hash))
				{
					if (STREAMING::IS_MODEL_VALID(hash))
					{
						STREAMING::REQUEST_MODEL(hash);
						if (STREAMING::HAS_MODEL_LOADED(hash))
						{
							attacc = OBJECT::CREATE_OBJECT(hash, pos.x, pos.y, pos.z, 1, 1, 1);
							if (ENTITY::DOES_ENTITY_EXIST(attacc))
							{
								ENTITY::ATTACH_ENTITY_TO_ENTITY(attacc, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 31086, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
								ENTITY::SET_ENTITY_VISIBLE(attacc, false);
							}
						}
					}
				}
			}
		}
		else if (weaponHash == 0x2BE6766B) {
			//"SMG";
		}
		else if (weaponHash == 0xEFE7E2DF) {
			//"Assault SMG";
		}
		else if (weaponHash == 0xBFEFFF6D && mm_teleport) {
			//"Assault Riffle";
			if (is_ped_shooting(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p))) {
				Features::remoteTP(p, 1);
			}
		}
		else if (weaponHash == 0x83BF0278 && mm_teleport) {
			//"Carbine Riffle";
			if (is_ped_shooting(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p))) {
				Features::remoteTP(p, 15);
			}
		}
		else if (weaponHash == 0xAF113F99 && mm_teleport) {
			//"Advanced Riffle";
			if (is_ped_shooting(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p))) {
				Features::remoteTP(p, 19);
			}
		}
		else if (weaponHash == 0x9D07F764) {
			//"MG";
		}
		else if (weaponHash == 0x7FD62962) {
			//"Combat MG";
		}
		else if (weaponHash == 0x1D073A89 && mm_spawn) {
			//"Pump Shotgun";
			if (is_ped_shooting(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p))) {
				Features::remoteSpawnVehicle("KURUMA2", p);
			}
		}
		else if (weaponHash == 0x7846A318 && mm_spawn) {
			//"Sawed-Off Shotgun";
			if (is_ped_shooting(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p))) {
				Features::remoteSpawnVehicle("khanjali", p);
			}
		}
		else if (weaponHash == 0xE284C527 && mm_spawn) {
			//"Assault Shotgun";
			if (is_ped_shooting(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p))) {
				Features::remoteSpawnVehicle("oppressor2", p);
			}
		}
		else if (weaponHash == 0x9D61E50F && mm_spawn) {
			//"Bullpup Shotgun";
			if (is_ped_shooting(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p))) {
				Features::remoteSpawnVehicle("TUG", p);
			}
		}
		else if (weaponHash == 0x3656C8C1) {
			//"Stun Gun";
		}
		else if (weaponHash == 0x05FC3C11) {
			//"Sniper Rifle";
		}
		else if (weaponHash == 0x0C472FE2) {
			//"Heavy Sniper";
		}
		else if (weaponHash == 0xA284510B) {
			//"Grenade Launcher";
		}
		else if (weaponHash == 0xB1CA77B1 && Features::enableMoney && mm_money) {
			//"RPG";
			if ((timeGetTime() - Features::TimePD5) > 400) // Time between drops
			{
				STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
				if (!STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem))) {
					WAIT(0);
				}
				else {
					OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, coordsOf(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p)).x, coordsOf(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p)).y, coordsOf(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p)).z, 1, 2500, moneyModel(Features::MoneyItem), false, true);
					Features::droppedMoneyCounter += Features::customDropAmount;
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));

					Features::TimePD5 = timeGetTime();
				}
			}
		}
		else if (weaponHash == 0x42BF8A85) {
			//"Minigun";
		}
		else if (weaponHash == 0x93E220BD) {
			//"Grenade";
		}
		else if (weaponHash == 0x2C3731D9) {
			//"Sticky Bomb";
		}
		else if (weaponHash == 0xFDBC8A50) {
			//"Smoke Grenade";
		}
		else if (weaponHash == 0xA0973D5E) {
			//"BZGas";
		}
		else if (weaponHash == 0x24B17070) {
			//"Molotov";
		}
		else if (weaponHash == 0x060EC506 && mm_explode) {
			//"Fire Extinguisher";
			if (is_ped_shooting(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p))) {
				for (int i = 0; i < 33; i++)
				{
					if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID()) continue;
					{
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
						FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 29, 1000.f, true, false, 100.f);
					}
				}
			}
		}
		else if (weaponHash == 0x34A67B97) {
			//"Petrol Can";
		}
		else if (weaponHash == 0xFDBADCED) {
			//"Digital scanner";
		}
		else if (weaponHash == 0x88C78EB7) {
			//"Briefcase";
		}
		else if (weaponHash == 0x23C9F95C) {
			//"Ball";
		}
		else if (weaponHash == 0x497FACC3) {
			//"Flare";
		}
		else if (weaponHash == 0xF9E6AA4B) {
			//"Bottle";
		}
		else if (weaponHash == 0x61012683) {
			//"Gusenberg";
		}
		else if (weaponHash == 0xC0A3098D) {
			//"Special Carabine";
		}
		else if (weaponHash == 0xD205520E) {
			//"Heavy Pistol";
		}
		else if (weaponHash == 0xBFD21232 && mm_weather) {
			//"SNS Pistol";
			if (is_ped_shooting(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p))) {
				Hooking::set_session_weather(1, 0, 76, 0);
			}
		}
		else if (weaponHash == 0x7F229F94) {
			//"Bullpup Rifle";
		}
		else if (weaponHash == 0x92A27487) {
			//"Dagger";
		}
		else if (weaponHash == 0x083839C4 && mm_weather) {
			//"Vintage Pistol";
			if (is_ped_shooting(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p))) {
				Hooking::set_session_weather(1, 13, 76, 0);
			}
		}
		else if (weaponHash == 0x7F7497E5) {
			//"Firework";
		}
		else if (weaponHash == 0xA89CB99E) {
			//"Musket";
		}
		else if (weaponHash == 0x3AABBBAA) {
			//"Heavy Shotgun";
		}
		else if (weaponHash == 0xC734385A) {
			//"Marksman Rifle";
		}
		else if (weaponHash == 0x63AB0442) {
			//"Homing Launcher";
		}
		else if (weaponHash == 0xAB564B93) {
			//"Proximity Mine";
		}
		else if (weaponHash == 0x787F0BB) {
			//"Snowball";
		}
		else if (weaponHash == 0x47757124) {
			//"Flare Gun";
		}
		else if (weaponHash == 0x0A3D4D34) {
			//weaponName = "Combat PDW";
		}
		else if (weaponHash == 0xDC4DB296) {
			//weaponName = "Marksman Pistol";
		}
		else if (weaponHash == 0x6D544C99) {
			//weaponName = "Railgun";
		}
	}
}

bool Features::remoteMoneygunbool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::remoteMoneygun(Player p) {
	if (is_ped_shooting(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p)))
	{
			float loc[6];
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD1(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), loc);
			int amount = 2500;

			if ((timeGetTime() - Features::TimePD6) > 100)
			{
				STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
				if (!STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem))) {
					WAIT(0);
				}
				else {
					OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, loc[0], loc[2], loc[4], 0, amount, moneyModel(Features::MoneyItem), FALSE, TRUE);
					Features::droppedMoneyCounter += amount;
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));

					Features::TimePD6 = timeGetTime();
				}
			}
	}
}

bool Features::remoteExplobool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::remoteExplo(Player p) {
	Vector3 iCoord;
	if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), &iCoord))
	{
		FIRE::ADD_EXPLOSION(iCoord.x, iCoord.y, iCoord.z, 25, 10000.0f, true, false, 0);
	}
}

bool Features::dropBool = false;
Vector3 Features::dropXYZ = { 0,0,0 };
int Features::dropValue = 0;
int Features::dropItem = 0;
std::string SP = "menu/moneydrops/";
std::string Features::dropName = "";
/*void loadDrop(int id) {
	switch (id) {
	case 0:
		if ((timeGetTime() - Features::TimePD7) > 400) // Time between drops
		{
			STREAMING::REQUEST_MODEL(moneyModel(atoi(readMoney(SP + "md0/item.txt").c_str())));
			if (!STREAMING::HAS_MODEL_LOADED(moneyModel(atoi(readMoney(SP + "md0/item.txt").c_str())))) {
				WAIT(0);
			}
			else {
				OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, atoi(readMoney(SP + "md0/coords/x.txt").c_str()), atoi(readMoney(SP + "md0/coords/y.txt").c_str()), atoi(readMoney(SP + "md0/coords/z.txt").c_str()), 1, atoi(readMoney(SP + "md0/value.txt").c_str()), moneyModel(atoi(readMoney(SP + "md0/item.txt").c_str())), false, true);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));

				Features::TimePD7 = timeGetTime();
			}
		}
		break;
	case 1:
		if ((timeGetTime() - Features::TimePD7) > 400) // Time between drops
		{
			STREAMING::REQUEST_MODEL(moneyModel(atoi(readMoney(SP + "md1/item.txt").c_str())));
			if (!STREAMING::HAS_MODEL_LOADED(moneyModel(atoi(readMoney(SP + "md1/item.txt").c_str())))) {
				WAIT(0);
			}
			else {
				OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, atoi(readMoney(SP + "md1/coords/x.txt").c_str()), atoi(readMoney(SP + "md1/coords/y.txt").c_str()), atoi(readMoney(SP + "md1/coords/z.txt").c_str()), 1, atoi(readMoney(SP + "md1/value.txt").c_str()), moneyModel(atoi(readMoney(SP + "md1/item.txt").c_str())), false, true);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));

				Features::TimePD7 = timeGetTime();
			}
		}
		break;
	}
}*/
void saveDrop(int id) {

}

int writeMoney(std::string path, std::string content) {
	ofstream file;
	file.open(path);
	file << content + "\n";
	file.close();
	return 0;
}
std::string readMoney(std::string path) {
	std::string line;
	ifstream file(path);
	if (file.is_open()) {
		while (getline(file, line)) {
			return line;
		}
		file.close();
	}
}

std::string Features::readTest(std::string path) {
	std::string line;
	ifstream file(path);
	if (file.is_open()) {
		while (getline(file, line)) {
			return line;
		}
		file.close();
	}
}

int Features::writeTest(std::string path, std::string content) {
	ofstream file;
	file.open(path);
	file << content + "\n";
	file.close();
	return 0;
}

Vector3 get_coords_infront_player(float dist)
{
	Vector3 r = coordsOf(PLAYER::PLAYER_PED_ID());
	float	heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
	r.x += dist * sin(DegreeToRadian(heading)) * -1,
		r.y += dist * cos(DegreeToRadian(heading));
	return r;
}
bool spawn_object(Hash model, Object* objOut)
{
	Vector3		pos = get_coords_infront_player(10.f);
	Ped		playerPed = PLAYER::PLAYER_PED_ID();

	if (!STREAMING::IS_MODEL_IN_CDIMAGE(model))
		return true;
	STREAMING::REQUEST_MODEL(model);
	if (!STREAMING::HAS_MODEL_LOADED(model))
		return false;
	Object	obj;
	OBJECT::CREATE_OBJECT(model, pos.x, pos.y, pos.z, true, false, false);

	STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);

	//if (objOut != nullptr)
	//	*objOut = obj;
	return true;
}
//BLACKHOLE {INSERT HERE}

std::string Features::Wname = "";
int Features::Wid = 0;

void Features::saveWayP(float wx, float wy, float wz, int id, std::string name) {
	std::string fname = "";
	ofstream file;
	
	switch (id) {
	case 0: fname = "X-Folder/waypoints/w0"; break;
	case 1: fname = "X-Folder/waypoints/w1"; break;
	case 2: fname = "X-Folder/waypoints/w2"; break;
	case 3: fname = "X-Folder/waypoints/w3"; break;
	case 4: fname = "X-Folder/waypoints/w4"; break;
	case 5: fname = "X-Folder/waypoints/w5"; break;
	case 6: fname = "X-Folder/waypoints/w6"; break;
	case 7: fname = "X-Folder/waypoints/w7"; break;
	case 8: fname = "X-Folder/waypoints/w8"; break;
	case 9: fname = "X-Folder/waypoints/w9"; break;
	}
	std::string f1 = fname + "/name.txt";
	file.open(f1);
	file << name + "\n";
	file.close();
	std::string f2 = fname + "/x.txt";
	file.open(f2);
	file << std::to_string(wx) + "\n";
	file.close();
	std::string f3 = fname + "/y.txt";
	file.open(f3);
	file << std::to_string(wy) + "\n";
	file.close();
	std::string f4 = fname + "/z.txt";
	file.open(f4);
	file << std::to_string(wz) + "\n";
	file.close();
}

bool Features::isWValid(int id) {
	std::string fname = "";
	std::string output = "";
	switch (id) {
	case 0: fname = "X-Folder/waypoints/w0"; break;
	case 1: fname = "X-Folder/waypoints/w1"; break;
	case 2: fname = "X-Folder/waypoints/w2"; break;
	case 3: fname = "X-Folder/waypoints/w3"; break;
	case 4: fname = "X-Folder/waypoints/w4"; break;
	case 5: fname = "X-Folder/waypoints/w5"; break;
	case 6: fname = "X-Folder/waypoints/w6"; break;
	case 7: fname = "X-Folder/waypoints/w7"; break;
	case 8: fname = "X-Folder/waypoints/w8"; break;
	case 9: fname = "X-Folder/waypoints/w9"; break;
	}
	std::string out = fname + "/name.txt";
	std::string line1;
	ifstream file1(out);
	if (file1.is_open()) {
		while (getline(file1, line1)) {
			output = line1;
		}
		file1.close();
	}
	if (output == "") {
		return false;
	}
	else {
		return true;
	}
}

void Features::loadWayP(int id) {
	std::string fname = "";
	Entity handle;
	float wx = 0;
	float wy = 0;
	float wz = 0;
	switch (id) {
	case 0: fname = "X-Folder/waypoints/w0"; break;
	case 1: fname = "X-Folder/waypoints/w1"; break;
	case 2: fname = "X-Folder/waypoints/w2"; break;
	case 3: fname = "X-Folder/waypoints/w3"; break;
	case 4: fname = "X-Folder/waypoints/w4"; break;
	case 5: fname = "X-Folder/waypoints/w5"; break;
	case 6: fname = "X-Folder/waypoints/w6"; break;
	case 7: fname = "X-Folder/waypoints/w7"; break;
	case 8: fname = "X-Folder/waypoints/w8"; break;
	case 9: fname = "X-Folder/waypoints/w9"; break;
	}
	std::string s1 = fname + "/x.txt";
	std::string s2 = fname + "/y.txt";
	std::string s3 = fname + "/z.txt";

	std::string line1;
	ifstream file1(s1);
	if (file1.is_open()) {
		while (getline(file1, line1)) {
			stringstream sstr;
			sstr << line1;
			sstr >> wx;
		}
		file1.close();
	}

	std::string line2;
	ifstream file2(s2);
	if (file2.is_open()) {
		while (getline(file2, line2)) {
			stringstream sstr;
			sstr << line2;
			sstr >> wy;
		}
		file2.close();
	}

	std::string line3;
	ifstream file3(s3);
	if (file3.is_open()) {
		while (getline(file3, line3)) {
			stringstream sstr;
			sstr << line3;
			sstr >> wz;
		}
		file3.close();
	}
	//notifyMap(std::to_string(wx) + "; " + std::to_string(wy) + "; " + std::to_string(wz));
	//ENTITY::SET_ENTITY_COORDS_NO_OFFSET(PLAYER::PLAYER_PED_ID(), wx, wy, wz, 0, 0, 1);
	PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : handle = PLAYER::PLAYER_PED_ID();
	ENTITY::SET_ENTITY_COORDS(handle, wx, wy, wz, false, false, false, false);
}

bool Features::Trigger = false;
void Features::TriggerAim(bool toggle)
{
	Entity AimedAtEntity;
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_PED_ID(), &AimedAtEntity))
	{
		if (ENTITY::IS_ENTITY_A_PED(AimedAtEntity) && !ENTITY::IS_ENTITY_DEAD(AimedAtEntity) && /*PED::IS_PED_A_PLAYER(AimedAtEntity) &&*/ ENTITY::GET_ENTITY_ALPHA(AimedAtEntity) == 255)
		{
			Features::shootAtPed(AimedAtEntity);
		}
	}
}
void Features::shootAtPed(Entity selectedPed)
{
	Vector3 Mouth = PED::GET_PED_BONE_COORDS(selectedPed, SKEL_Head, 0.1f, 0.0f, 0.0f);
	PED::SET_PED_SHOOTS_AT_COORD(PLAYER::PLAYER_PED_ID(), Mouth.x, Mouth.y, Mouth.z, true);
}

bool Features::playerfireloop[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::FireLoop(Player target)
{
	Player selectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
	Vector3 Pos = coordsOf(selectedPlayer);
	FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 12, 5, true, 0, 0);
}
bool Features::playerwaterloop[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::WaterLoop(Player target)
{
	Player selectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
	Vector3 Pos = coordsOf(selectedPlayer);
	FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 13, 5, true, 0, 0);
}

bool Features::bypassChatBool = false;
void Features::bypassChat(bool t) {
	NETWORK::NETWORK_OVERRIDE_RECEIVE_RESTRICTIONS(PLAYER::PLAYER_PED_ID(), true);
	NETWORK::NETWORK_OVERRIDE_CHAT_RESTRICTIONS(PLAYER::PLAYER_PED_ID(), true);
}

void Features::skipTutorial() {
	if (NETWORK::NETWORK_IS_IN_TUTORIAL_SESSION()) {
		NETWORK::NETWORK_END_TUTORIAL_SESSION();
	}
}

float Features::get_stat(Hash stat_hash) {
	float stat;
	STATS::STAT_GET_FLOAT(stat_hash, &stat, 0);
	return stat;
}

bool reportCalculator() {
	float rresult;
	float cresult;
	float rStrength = Features::get_stat(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_REPORT_STRENGTH"));
	float cStrength = Features::get_stat(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_COMMEND_STRENGTH"));
	float commends1 = Features::get_stat(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_FRIENDLY"));
	float commends2 = Features::get_stat(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_HELPFUL"));
	float gReports = Features::get_stat(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_GRIEFING"));
	float lReports = Features::get_stat(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OFFENSIVE_LANGUAGE"));
	float uReports = Features::get_stat(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OFFENSIVE_UGC"));
	float hReports = Features::get_stat(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_VC_HATE"));
	float eReports = Features::get_stat(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_GAME_EXPLOITS"));
	float punished = Features::get_stat(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_ISPUNISHED"));
	rresult = (gReports + (lReports / 2) + (uReports / 2) + (hReports / 2) + eReports) / 5;
	cresult = (commends1 + commends2) / 2;
	if (rresult / cresult > 20 || punished > 64) {
		return true;
	}
	else {
		return false;
	}
}

bool Features::isBanned() {
	bool reported = reportCalculator();
	bool scBanned = NETWORK::_IS_SOCIALCLUB_BANNED();
	bool rBanned = NETWORK::_IS_ROCKSTAR_BANNED();
	bool canPlay = NETWORK::_CAN_PLAY_ONLINE();
	if (reported || scBanned || rBanned || !canPlay) {
		return true;
	}
	else {
		return false;
	}
}

std::string Features::read(std::string path) {
	std::string line;
	ifstream file(path);
	if (file.is_open()) {
		while (getline(file, line)) {
			return line;
		}
		file.close();
	}
}

void Features::write(std::string path, std::string content) {
	ofstream file;
	file.open(path);
	file << content + "\n";
	file.close();
}

std::string Features::read2(std::string path) {
	std::string line;
	ifstream file(path);
	if (file.is_open()) {
		for (line; getline(file, line);) {
			return line;
		}
		file.close();
	}
}

void Features::write2(std::string path, std::string content) {
	std::ofstream file;
	file.open(path, std::ios::out | std::ios::app);
	file.exceptions(file.exceptions() | std::ios::failbit | std::ifstream::badbit);

	file << content << std::endl;
}

bool Features::CheckWord(char* filename, char* search)
{
	bool out;
	ifstream fileInput;
	int offset;
	string line;
	fileInput.open(filename);
	if (fileInput.is_open()) {
		for (unsigned int curLine = 0; getline(fileInput, line); curLine++) {
			if (line.find(search) != string::npos) {
				out = true;
				break;
			}
			else {
				out = false;
			}
		}
		fileInput.close();
	}
	return out;
}

bool Features::pLobby = false;
void Features::privateLobby(bool t) {
	for (int i = 0; i < 33; i++) {
		if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) != PLAYER::PLAYER_PED_ID() && !Features::CheckWord("X-Folder/friends/friend.txt", PLAYER::GET_PLAYER_NAME(i))) {
			unsigned int Bit = (1 << i);
			uint64_t kick[4] = { 769347061, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 0, 0 };
			Hooking::trigger_script_event(1, kick, 4, Bit);
		}
	}
}

bool Features::cashrainbool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::cashrain(Player target)
{
	STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
	Vector3 pp = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), 0.0, 0.0, 10.0);
	int offset1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);
	int offset2 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);

	STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
	while (!STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem)))
		WAIT(0);
	if (STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem)))
	{
		int amount = 2500;
		OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, pp.x + offset1, pp.y + offset2, pp.z, 0, amount, moneyModel(Features::MoneyItem), false, true);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));
	}
}

void Features::InstantCrash(Ped ped)
{
	Object* objects;
	Player v = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(ped);
	Vector3 playerPosition = coordsOf(v);
	Vector3 safeCoords = { 1741.4960f, 3269.2570f, 41.6014f };
	Hash modelHashes[32] = { 0x9CF21E0F /* i'm just starting baby */,
		0x34315488,
		0x6A27FEB1, 0xCB2ACC8,
		0xC6899CDE, 0xD14B5BA3,
		0xD9F4474C, 0x32A9996C,
		0x69D4F974, 0xCAFC1EC3,
		0x79B41171, 0x1075651,
		0xC07792D4, 0x781E451D,
		0x762657C6, 0xC2E75A21,
		0xC3C00861, 0x81FB3FF0,
		0x45EF7804, 0xE65EC0E4,
		0xE764D794, 0xFBF7D21F,
		0xE1AEB708, 0xA5E3D471,
		0xD971BBAE, 0xCF7A9A9D,
		0xC2CC99D8, 0x8FB233A4,
		0x24E08E1F, 0x337B2B54,
		0xB9402F87, 0x4F2526DA
	};
	teleport_to_coords(PLAYER::PLAYER_PED_ID(), safeCoords);
	// Teleport yourself or him to the ocean before doing this.

	for (int i = 0; i < 33; i++) {
		objects[i] = OBJECT::CREATE_OBJECT(modelHashes[i], playerPosition.x, playerPosition.y, playerPosition.z, 1, 1, 1);
	}	
		// Cleanup
	for (int j = 0; j < 32; j++) {
		OBJECT::DELETE_OBJECT(objects);
	}
}

bool Features::inTrain = false;
float Features::trainSpeed = 0.0f;
Vehicle Features::train;
int ttimer;
void Features::controlTrainSpeed() {
	if (GAMEPLAY::GET_GAME_TIMER() >= ttimer)
	{
		VEHICLE::SET_TRAIN_SPEED(Features::train, Features::trainSpeed);
		ttimer = GAMEPLAY::GET_GAME_TIMER() + 10;
	}

	if (CONTROLS::IS_CONTROL_PRESSED(2, eControl::ControlMoveUpOnly)) //forward
	{
		Features::trainSpeed += 0.1f;

	}
	else if (CONTROLS::IS_CONTROL_PRESSED(2, eControl::ControlMoveDownOnly))
	{
		if (Features::trainSpeed - 0.1f >= 0.0f)
		{
			Features::trainSpeed -= 0.1f;
		}
	}
}

void Features::spawnTrain(int trainID) {
	Hash cablecar = GAMEPLAY::GET_HASH_KEY("cablecar");
	Hash metrotrain = GAMEPLAY::GET_HASH_KEY("metrotrain");
	Hash freight = GAMEPLAY::GET_HASH_KEY("freight");
	Hash freightcar = GAMEPLAY::GET_HASH_KEY("freightcar");
	Hash freightgrain = GAMEPLAY::GET_HASH_KEY("freightgrain");
	Hash freightcont1 = GAMEPLAY::GET_HASH_KEY("freightcont1");
	Hash freightcont2 = GAMEPLAY::GET_HASH_KEY("freightcont2");
	Hash freighttrailer = GAMEPLAY::GET_HASH_KEY("freighttrailer");

	STREAMING::REQUEST_MODEL(cablecar);
	STREAMING::REQUEST_MODEL(metrotrain);
	STREAMING::REQUEST_MODEL(freight);
	STREAMING::REQUEST_MODEL(freightcar);
	STREAMING::REQUEST_MODEL(freightgrain);
	STREAMING::REQUEST_MODEL(freightcont1);
	STREAMING::REQUEST_MODEL(freightcont2);
	STREAMING::REQUEST_MODEL(freighttrailer);

	while (!STREAMING::HAS_MODEL_LOADED(cablecar)) WAIT(0);
	while (!STREAMING::HAS_MODEL_LOADED(metrotrain)) WAIT(0);
	while (!STREAMING::HAS_MODEL_LOADED(freight)) WAIT(0);
	while (!STREAMING::HAS_MODEL_LOADED(freightcar)) WAIT(0);
	while (!STREAMING::HAS_MODEL_LOADED(freightgrain)) WAIT(0);
	while (!STREAMING::HAS_MODEL_LOADED(freightcont1)) WAIT(0);
	while (!STREAMING::HAS_MODEL_LOADED(freightcont2)) WAIT(0);
	while (!STREAMING::HAS_MODEL_LOADED(freighttrailer)) WAIT(0);

	Vector3 c = coordsOf(PLAYER::PLAYER_PED_ID());
	Features::train = VEHICLE::CREATE_MISSION_TRAIN(trainID, c.x, c.y, c.z, 1);
	VEHICLE::SET_VEHICLE_UNDRIVEABLE(Features::train, false);
	AI::TASK_WARP_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Features::train, -1);
	Features::inTrain = true;
}

void Features::deleteTrain() {
	VEHICLE::DELETE_MISSION_TRAIN(&Features::train);
	Features::trainSpeed = 0.0f;
	Features::inTrain = false;
}

void Features::CREATE_OBJECT_WITH_ROTATION(DWORD model, float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float rotW, bool dynamic, bool visible)
{
	if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_VALID(model))
	{
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		Object obj = OBJECT::CREATE_OBJECT(model, posX, posY, posZ, true, false, dynamic);
		ENTITY::SET_ENTITY_QUATERNION(obj, rotX, rotY, rotZ, rotW);
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(obj, true, true);
		ENTITY::SET_ENTITY_DYNAMIC(obj, false);
		if (!visible)
		{
			ENTITY::SET_ENTITY_VISIBLE(obj, false);
		}
		ENTITY::SET_ENTITY_PROOFS(obj, true, true, true, true, true, true, true, true);
		ENTITY::SET_ENTITY_INVINCIBLE(obj, true);
		WAIT(500);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}
}

void Features::cage2(Player p) {
	Ped penis = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	if (PED::IS_PED_IN_ANY_VEHICLE(penis, 0))
	{
		AI::CLEAR_PED_TASKS_IMMEDIATELY(penis);
		WAIT(10);
	}
	AI::CLEAR_PED_TASKS_IMMEDIATELY(penis);
	Vector3 xyz = coordsOf(penis);
	Features::CREATE_OBJECT_WITH_ROTATION(206865238, xyz.x - 1.39f, xyz.y - 1.87f, xyz.z - 1.0f, 0.0f, 0.0f, -0.66576f, 0.746166f, false, true);
	Features::CREATE_OBJECT_WITH_ROTATION(206865238, xyz.x + 1.51f, xyz.y + 1.94f, xyz.z - 1.0f, 0.0f, 0.0f, 0.75172f, 0.659482f, false, true);
}

bool Features::dragon = false;
void Features::Dragon(bool t)
{
	Vector3 Mouth = PED::GET_PED_BONE_COORDS(PLAYER::PLAYER_PED_ID(), 39317, 0.1f, 0.0f, 0.0f);
	FIRE::ADD_EXPLOSION(Mouth.x, Mouth.y, Mouth.z, 28, 1.0f, true, false, 0.0f);
	FIRE::ADD_EXPLOSION(Mouth.x, Mouth.y, Mouth.z, 27, 1.0f, true, false, 0.0f);
}

void Features::oe_bypass(bool toggle) {
	/*static DWORD64 dwAddOwnedExplosionBypass = Pattern::Scan(Info::g_MainModuleInfo, "0F 85 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 48 08 E8"); //heres the pattern scanner or user ur own https://github.com/mcheijink/s0beit-ftf/blob/00f979e6b96947343aca69ac7893a75dd698d7a3/m0d-s0beit-v/Pattern.h
	static DWORD64 dwAddOwnedExplosionBypass2 = Pattern::Scan(Info::g_MainModuleInfo, "74 0F 48 8D 4C 24 ? 45 33 C0");
	
	if (toggle) {
		*(PWORD)dwAddOwnedExplosionBypass = 0xE990;
		*(PWORD)dwAddOwnedExplosionBypass2 = 0x9090;
	}
	else {
		*(PWORD)dwAddOwnedExplosionBypass = 0x850F;
		*(PWORD)dwAddOwnedExplosionBypass2 = 0x0F74;
	}*/
}

void Features::blamePlayer(int selectedPed)
{
	Features::oe_bypass(true);
	for (int i = 0; i < 33; i++)
	{
		FIRE::ADD_OWNED_EXPLOSION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPed), coordsOf(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)).x, coordsOf(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)).y, coordsOf(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)).z, 37, 5.0f, true, false, 0.1f);
	}
	Features::oe_bypass(false);
}

//Hooking.h
//StatSetInt: new params
//OLD: Hash dlchash


float GetPointToPointRotation(Vector3 Source, Vector3 Target)
{
	return GAMEPLAY::ATAN2((Target.y - Source.y), (Target.x - Source.x));
}

int Timer;
Object sentry;
bool Features::sentryActive = false;
void Features::InitiateSentryGun()
{
	spawn_object($("p_rcss_folded"), &sentry);
	int Timeout = 500;
	Timer = GAMEPLAY::GET_GAME_TIMER() + Timeout;
}

void Features::SentryGunLoop()
{
	int TargetID = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(ENTITY::GET_NEAREST_PLAYER_TO_ENTITY(sentry));
	if (TargetID == PLAYER::PLAYER_PED_ID())
	{
	}
	else
	{
		//Rotate and draw
		float Rotation = GetPointToPointRotation(coordsOf(sentry), coordsOf(TargetID)) + 90;
		ENTITY::SET_ENTITY_ROTATION(sentry, 0, 0, Rotation, 1, true);
		Hash weaponID = 0xB1CA77B1;
		Vector3 sCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(sentry, 0, -0.2, 0.57);
		Vector3 tCoords = coordsOf(TargetID);
		GRAPHICS::DRAW_LINE(sCoords.x, sCoords.y, sCoords.z, tCoords.x, tCoords.y, tCoords.z, 255, 0, 0, 0);

		//Time to Kill
		if (GAMEPLAY::GET_GAME_TIMER() >= Timer)
		{
			Vector3 sCoords2 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(sentry, 0, -0.8, 0.6);
			Vector3 tCoords2 = coordsOf(TargetID);
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(sCoords2.x, sCoords2.y, sCoords2.z, tCoords2.x, tCoords2.y, tCoords2.z, 250, 0, weaponID, PLAYER::PLAYER_PED_ID(), 1, 0, 1.0f);

			Timer = GAMEPLAY::GET_GAME_TIMER() + 500; //500 Milisec between shots
		}
	}    
}

void Features::SET_PLAYER_NAME(const std::string& name)
{
	/*const auto address = nullptr;//Pattern::Scan(Info::g_MainModuleInfo, "48 8B 05 ? ? ? ? C3 8A D1");
	const auto NAME = address + *reinterpret_cast<int*>(address + 3) + 7;
	size_t size = name.size();
	if (size++ <= 0)
		return;
	char* chatName = (char*)NAME + 0x5c;
	size_t strLen = strlen(chatName) + 1;
	char buffer[32];
	memset(buffer, 0, sizeof(buffer));
	strncpy_s(buffer, chatName, strLen);
	for (int matches = 0, i = 0, j = 0, found = 0; found != 6; i++)
	{
		if (chatName[i] != buffer[j])
		{
			matches = j = 0;
			continue;
		}
		if (++matches == strLen)
		{
			strncpy_s(chatName + i - j, size, &name[0], size);
			j = matches = 0;
			found++;
		}
		j++;
	}*/
}

std::string& replace(std::string& s, const std::string& from, const std::string& to)
{
	if (!from.empty())
		for (size_t pos = 0; (pos = s.find(from, pos)) != std::string::npos; pos += to.size())
			s.replace(pos, from.size(), to);
	return s;
}

bool ConvertSig(std::string IDA, std::string* SigOut, std::string* MaskOut) {
	std::string Sig, Mask, temp;
	std::string Byte; Byte += (char)92; Byte += "x";

	//"AA BB CC DD EE FF ?? 01 02"
	for (std::string::iterator e = IDA.begin(); e != IDA.end(); e++) {
		if (*e != '?' && *e != ' ') {
			temp += Byte + *e;
			e++;
			temp += *e;
			Sig += (char)temp.c_str();
			Mask += 'x';
		}
		else if (*e == '?') {
			temp += Byte + "00";
			e++;
			Sig += (char)temp.c_str();
			if (*e == '?')
				Mask += '?';
			else
				e--;
		}
	}

	if (Sig.size() <= 0 || Mask.size() <= 0) {
		return false;
	}
	else {
		if (!SigOut || !MaskOut) {
			return false;
		}
		else {
			*SigOut = Sig;
			*MaskOut = Mask;
			return true;
		}
	}
}

void convertSigs(std::string input) {
	std::string sig;
	std::string mask;
	if (ConvertSig(input, &sig, &mask)) {
		Log::Msg(sig.c_str());
		Log::Msg(mask.c_str());
	}
}

int Features::Notification(char *text, char *text2, char *Subject)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG("CHAR_LIFEINVADER ", "CHAR_LIFEINVADER ", false, 7, text2, Subject, 0.1, "___ABCD");
	return UI::_DRAW_NOTIFICATION(1, 1);
}

bool Features::getDeathBool = false;
Entity Features::getDeath(Ped target) {
	Ped p = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
	if (ENTITY::IS_ENTITY_DEAD(p)) {
		Entity killer = PED::GET_PED_SOURCE_OF_DEATH(p);
		return killer;
		notifyMap(std::to_string(killer).c_str());
	}
}

void Features::JoinCrew(Player player) {
	int clanId;
	int desc;
	NETWORK::NETWORK_CLAN_PLAYER_GET_DESC(&desc, 35, &clanId);
	NETWORK::NETWORK_CLAN_JOIN(clanId);
}

void Features::CopyOutfit(Player player)
{
	for (int i = 0; i < 12; i++)
	{
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), i, PED::GET_PED_DRAWABLE_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), i), PED::GET_PED_TEXTURE_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), i), PED::GET_PED_PALETTE_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), i));
		for (int i = 0; i < 2; i++) {
			WAIT(0);
		}
	}
}

void Features::ramWithVeh(Player target)
{
	//Features::fuck_me_sideways(1);
	Hash model = $("trophytruck2");
	if (STREAMING::IS_MODEL_VALID(model))
	{
		for (int i = 0; i < 3; i++)
		{
			STREAMING::REQUEST_MODEL(model);
			while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
			Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
			float forward = 10.f;
			float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target));
			float xVector = forward * sin(degToRad(heading)) * -1.f;
			float yVector = forward * cos(degToRad(heading));
			Vehicle veh = VEHICLE::CREATE_VEHICLE(model, ourCoords.x - xVector, ourCoords.y - yVector, ourCoords.z, heading, true, true);
			RequestControlOfEnt(veh);
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 250);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
		}
	}
}

bool Features::enginealwaysonbool = false;
void Features::enginealwayson(bool toggle)
{
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
	VEHICLE::SET_VEHICLE_ENGINE_ON(veh, Features::enginealwaysonbool, Features::enginealwaysonbool, Features::enginealwaysonbool);
	VEHICLE::SET_VEHICLE_LIGHTS(veh, 0);
	VEHICLE::_SET_VEHICLE_LIGHTS_MODE(veh, 2);
}

void Features::Online::TeleportVehicleToMe(Player player) {
	int CurrentPlayersVehicle = PED::GET_VEHICLE_PED_IS_USING(player);
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
	if (CurrentPlayersVehicle) {
		RequestControlOfEnt(CurrentPlayersVehicle);
		ENTITY::SET_ENTITY_COORDS(CurrentPlayersVehicle, MyCoords.x, MyCoords.y, MyCoords.z + 1.0f, false, false, false, false);
	}
}

bool Features::stickToGround = false;
void Features::vehStuckToGround() {
	VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
}

bool Features::bikeNoFall = false;
void Features::nofallbike() {
	PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID(), bikeNoFall);
}

/*	if (Menu::Option("Add Ramp")) {
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
		{
			Vector3 Him = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
			int VehicleID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true);
			STREAMING::REQUEST_MODEL(0xB157C9E4);
			if (STREAMING::HAS_MODEL_LOADED(0xB157C9E4))
			{
				Entity My_Objects = OBJECT::CREATE_OBJECT(0xB157C9E4, Him.x, Him.y, Him.z, 1, 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(My_Objects))
				{
					ENTITY::SET_ENTITY_COLLISION(My_Objects, true, true);
					ENTITY::SET_ENTITY_ALPHA(My_Objects, 120, false);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(My_Objects, VehicleID, 0, 0, 6.3, -0.3, 13.5, 0, 177.5, 0, 0, true, 0, 2, 1);
				}
			}
		}
		else { IconNotification("You Are Not In Car!", "Evolution", "Ramp"); }
	}
	if (Menu::Option("Set Custom Plate")) {
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		RequestControlOfEnt(veh);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, CharKeyboard());
	}*/

//ADD RAMP
//No bike fall
//Custom plate
//Stick to ground
//TP car to me
//Disable Organizations

bool Features::antiAFKbool = false;
void Features::antiAFK(bool t) {
	globalHandle(1368245).At(1165).As<int>() = -1;
	globalHandle(1368245).At(1149).As<int>() = -1;
}

bool Features::stealthBool = false;
int Features::stealthAmount = 10000000;
bool Features::toBank = true;
int Features::stealthDelay = 600;
bool Features::stealthLooped = true;
void Features::stealthLoop(bool t) {
	if ((timeGetTime() - Features::TimePD10) > Features::stealthDelay) {
		if (Features::stealthAmount < 10000001) {
			Any var0 = rndInt(0, INT_MAX);
			UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, Features::removee ? -1359375127 : 312105838, Features::removee ? 537254313 : 1445302971, Features::stealthAmount, Features::toBank ? 4 : 1);
			UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);
			Features::removee ? Features::stealthMoneyCounter -= Features::stealthAmount : Features::stealthMoneyCounter += Features::stealthAmount;
		}
		/*else {
			Any var0 = rndInt(INT_MIN, INT_MAX);
			UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, Features::removee ? -1359375127 : -1586170317, Features::removee ? 537254313 : 1445302971, Features::stealthAmount, Features::toBank ? 4 : 1);
			UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);
			Features::removee ? Features::stealthMoneyCounter -= Features::stealthAmount : Features::stealthMoneyCounter += Features::stealthAmount;
		}*/
		Features::TimePD10 = timeGetTime();
	}
}

bool Features::selfSpreadDropBool = false;
void Features::selfSpreadDrop(bool t) {
	Player p = PLAYER::PLAYER_PED_ID();
	if ((timeGetTime() - Features::TimePD11) > 300) // Time between drops
	{
		float dx = coordsOf(p).x;
		float dy = coordsOf(p).y;
		float dz = coordsOf(p).z;
		float randX = rndInt(-2, 2);
		float randY = rndInt(-2, 2);
		float randZ = rndInt(-2, 2);
		float offsetX = dx + randX;
		float offsetY = dy + randY;
		float offsetZ = dz + randZ;
		STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
		if (!STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem))) {
			WAIT(0);
		}
		else {
			OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, offsetX, offsetY, offsetZ, 1, 2500, moneyModel(Features::MoneyItem), false, true);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));

			Features::TimePD11 = timeGetTime();
		}
	}
}

bool Features::selfRainDropBool = false;
void Features::selfRainDrop(bool t) {
	STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
	Vector3 pp = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 0.0, 10.0);
	int offset1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);
	int offset2 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);

	STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
	while (!STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem)))
		WAIT(0);
	if (STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem)))
	{
		int amount = 2500;
		OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, pp.x + offset1, pp.y + offset2, pp.z, 0, amount, moneyModel(Features::MoneyItem), false, true);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));
	}
}

bool Features::allfireloop = false;
void Features::allFireLoop(bool t)
{
	for (int i = 0; i < 33; i++) {
		if (Features::exclude(i)) {
			Player selectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			Vector3 Pos = coordsOf(selectedPlayer);
			FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 12, 5, true, 0, 0);
		}
	}
}
bool Features::allwaterloop = false;
void Features::allWaterLoop(bool t)
{
	for (int i = 0; i < 33; i++) {
		if (Features::exclude(i)) {
			Player selectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			Vector3 Pos = coordsOf(selectedPlayer);
			FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 13, 5, true, 0, 0);
		}
	}
}

bool Features::customDropBool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int Features::customDropDelay = 400;
int Features::customDropAmount = 2500;
int Features::customDropMode = 0; //0: normal; 1: spread; 2: rain;
bool Features::customDropBool2 = false;

int Features::customHeight = 0;
bool Features::customFakedrop = false;
bool Features::customRandom = false;

int Features::randomMoney() {
	int rnd = rndInt(1, 2500);
	Features::customDropAmount = rnd;
	return rnd;
}

void Features::customFakedropp() {
	Features::customDropAmount = 0;
}

void Features::customDrop2(bool t) {
	Player target = PLAYER::PLAYER_PED_ID();
	if (Features::customDropMode == 0) {
		if ((timeGetTime() - Features::TimePD13) > Features::customDropDelay) // Time between drops
		{
			STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
			if (!STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem))) {
				WAIT(0);
			}
			else {
				OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, coordsOf(target).x, coordsOf(target).y, coordsOf(target).z + Features::customHeight, 1, Features::customDropAmount, moneyModel(Features::MoneyItem), false, true);
				Features::droppedMoneyCounter += Features::customDropAmount;
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));

				Features::TimePD13 = timeGetTime();
			}
		}
	}
	if (Features::customDropMode == 1) {
		if ((timeGetTime() - Features::TimePD13) > Features::customDropDelay) // Time between drops
		{
			float dx = coordsOf(target).x;
			float dy = coordsOf(target).y;
			float dz = coordsOf(target).z;
			float randX = rndInt(-2, 2);
			float randY = rndInt(-2, 2);
			float randZ = rndInt(-2, 2);
			float offsetX = dx + randX;
			float offsetY = dy + randY;
			float offsetZ = dz + randZ;
			STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
			if (!STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem))) {
				WAIT(0);
			}
			else {
				OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, offsetX, offsetY, offsetZ + Features::customHeight, 1, Features::customDropAmount, moneyModel(Features::MoneyItem), false, true);
				Features::droppedMoneyCounter += Features::customDropAmount;
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));

				Features::TimePD13 = timeGetTime();
			}
		}
	}
	if (Features::customDropMode == 2) {
		STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
		Vector3 pp = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(target, 0.0, 0.0, 10.0);
		int offset1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);
		int offset2 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);

		STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
		while (!STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem)))
			WAIT(0);
		if (STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem)))
		{
			int amount = Features::customDropAmount;
			OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, pp.x + offset1, pp.y + offset2, pp.z, 0, amount, moneyModel(Features::MoneyItem), false, true);
			Features::droppedMoneyCounter += Features::customDropAmount;
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));
		}
	}
}

void Features::customDrop(Player p) {
	Player target = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	if (Features::customDropMode == 0) {
		if ((timeGetTime() - Features::TimePD12) > Features::customDropDelay) // Time between drops
		{
			STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
			if (!STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem))) {
				WAIT(0);
			}
			else {
				OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, coordsOf(target).x, coordsOf(target).y, coordsOf(target).z + Features::customHeight, 1, Features::customDropAmount, moneyModel(Features::MoneyItem), false, true);
				Features::droppedMoneyCounter += Features::customDropAmount;
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));

				Features::TimePD12 = timeGetTime();
			}
		}
	}
	if (Features::customDropMode == 1) {
		if ((timeGetTime() - Features::TimePD12) > Features::customDropDelay) // Time between drops
		{
			float dx = coordsOf(target).x;
			float dy = coordsOf(target).y;
			float dz = coordsOf(target).z;
			float randX = rndInt(-2, 2);
			float randY = rndInt(-2, 2);
			float randZ = rndInt(-2, 2);
			float offsetX = dx + randX;
			float offsetY = dy + randY;
			float offsetZ = dz + randZ;
			STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
			if (!STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem))) {
				WAIT(0);
			}
			else {
				OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, offsetX, offsetY, offsetZ + Features::customHeight, 1, Features::customDropAmount, moneyModel(Features::MoneyItem), false, true);
				Features::droppedMoneyCounter += Features::customDropAmount;
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));

				Features::TimePD12 = timeGetTime();
			}
		}
	}
	if (Features::customDropMode == 2) {
		STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
		Vector3 pp = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(target, 0.0, 0.0, 10.0);
		int offset1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);
		int offset2 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);

		STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
		while (!STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem)))
			WAIT(0);
		if (STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem)))
		{
			int amount = Features::customDropAmount;
			OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, pp.x + offset1, pp.y + offset2, pp.z, 0, amount, moneyModel(Features::MoneyItem), false, true);
			Features::droppedMoneyCounter += Features::customDropAmount;
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));
		}
	}
}

void Features::setWeaponTint(int index) {
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	static LPCSTR weaponNames[] = {
		"WEAPON_KNIFE", "WEAPON_NIGHTSTICK", "WEAPON_HAMMER", "WEAPON_BAT", "WEAPON_GOLFCLUB", "WEAPON_CROWBAR",
		"WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_APPISTOL", "WEAPON_PISTOL50", "WEAPON_MICROSMG", "WEAPON_SMG",
		"WEAPON_ASSAULTSMG", "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE", "WEAPON_MG",
		"WEAPON_COMBATMG", "WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN", "WEAPON_ASSAULTSHOTGUN", "WEAPON_BULLPUPSHOTGUN",
		"WEAPON_STUNGUN", "WEAPON_SNIPERRIFLE", "WEAPON_HEAVYSNIPER", "WEAPON_GRENADELAUNCHER", "WEAPON_GRENADELAUNCHER_SMOKE",
		"WEAPON_RPG", "WEAPON_MINIGUN", "WEAPON_GRENADE", "WEAPON_STICKYBOMB", "WEAPON_SMOKEGRENADE", "WEAPON_BZGAS",
		"WEAPON_MOLOTOV", "WEAPON_FIREEXTINGUISHER", "WEAPON_PETROLCAN",
		"WEAPON_SNSPISTOL", "WEAPON_SPECIALCARBINE", "WEAPON_HEAVYPISTOL", "WEAPON_BULLPUPRIFLE", "WEAPON_HOMINGLAUNCHER",
		"WEAPON_PROXMINE", "WEAPON_SNOWBALL", "WEAPON_VINTAGEPISTOL", "WEAPON_DAGGER", "WEAPON_FIREWORK", "WEAPON_MUSKET",
		"WEAPON_MARKSMANRIFLE", "WEAPON_HEAVYSHOTGUN", "WEAPON_GUSENBERG", "WEAPON_HATCHET", "WEAPON_RAILGUN", "WEAPON_FLAREGUN",
		"WEAPON_KNUCKLE", "GADGET_NIGHTVISION", "GADGET_PARACHUTE", "WEAPON_MARKSMANPISTOL", "", ""
	};
	for (int i = 0; i < sizeof(weaponNames) / sizeof(weaponNames[0]); i++)
	{
		if (WEAPON::HAS_PED_GOT_WEAPON(playerPed, GAMEPLAY::GET_HASH_KEY((char *)weaponNames[i]), 0))
		{
			WEAPON::SET_PED_WEAPON_TINT_INDEX(playerPed, GAMEPLAY::GET_HASH_KEY((char *)weaponNames[i]), index);
		}
	}
}

bool Features::RGBgun = false;
void Features::RBGuner(bool toggle) {
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	static LPCSTR weaponNames[] = {
		"WEAPON_KNIFE", "WEAPON_NIGHTSTICK", "WEAPON_HAMMER", "WEAPON_BAT", "WEAPON_GOLFCLUB", "WEAPON_CROWBAR",
		"WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_APPISTOL", "WEAPON_PISTOL50", "WEAPON_MICROSMG", "WEAPON_SMG",
		"WEAPON_ASSAULTSMG", "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE", "WEAPON_MG",
		"WEAPON_COMBATMG", "WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN", "WEAPON_ASSAULTSHOTGUN", "WEAPON_BULLPUPSHOTGUN",
		"WEAPON_STUNGUN", "WEAPON_SNIPERRIFLE", "WEAPON_HEAVYSNIPER", "WEAPON_GRENADELAUNCHER", "WEAPON_GRENADELAUNCHER_SMOKE",
		"WEAPON_RPG", "WEAPON_MINIGUN", "WEAPON_GRENADE", "WEAPON_STICKYBOMB", "WEAPON_SMOKEGRENADE", "WEAPON_BZGAS",
		"WEAPON_MOLOTOV", "WEAPON_FIREEXTINGUISHER", "WEAPON_PETROLCAN",
		"WEAPON_SNSPISTOL", "WEAPON_SPECIALCARBINE", "WEAPON_HEAVYPISTOL", "WEAPON_BULLPUPRIFLE", "WEAPON_HOMINGLAUNCHER",
		"WEAPON_PROXMINE", "WEAPON_SNOWBALL", "WEAPON_VINTAGEPISTOL", "WEAPON_DAGGER", "WEAPON_FIREWORK", "WEAPON_MUSKET",
		"WEAPON_MARKSMANRIFLE", "WEAPON_HEAVYSHOTGUN", "WEAPON_GUSENBERG", "WEAPON_HATCHET", "WEAPON_RAILGUN", "WEAPON_FLAREGUN",
		"WEAPON_KNUCKLE", "GADGET_NIGHTVISION", "GADGET_PARACHUTE", "WEAPON_MARKSMANPISTOL", "", ""
	};
	for (int i = 0; i < sizeof(weaponNames) / sizeof(weaponNames[0]); i++)
	{
		if (WEAPON::HAS_PED_GOT_WEAPON(playerPed, GAMEPLAY::GET_HASH_KEY((char *)weaponNames[i]), 0))
		{
			WEAPON::SET_PED_WEAPON_TINT_INDEX(playerPed, GAMEPLAY::GET_HASH_KEY((char *)weaponNames[i]), rand() % 8);
		}
	}
}

bool Features::fastswim = false;
void Features::SwimFast(bool toggle)
{
	if (!fastswim)
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_SWIM_SPD }, 1);
	}
	else
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_SWIM_SPD }, 2.5);
	}
}

bool Features::fuckedhandling[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::fuckhandling(Player player)
{
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), false);
	RequestControlOfEnt(veh);
	VEHICLE::SET_VEHICLE_STEER_BIAS(veh, Features::fuckedhandling[player] ? 1.0f : 0.0f);
}

bool Features::camshaker[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::shakecam(Player target)
{
	Vector3 targetCords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
	FIRE::ADD_EXPLOSION(targetCords.x, targetCords.y, targetCords.z, 4, 0.f, false, true, 1000.f);
}

bool Features::explodeLoopBool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::explodeloop(Player target)
{
	Vector3 targetCords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
	FIRE::ADD_EXPLOSION(targetCords.x, targetCords.y, targetCords.z, 0, 0.0f, true, false, 10.0f);
}

Object mapMods[250];
int mapModsIndex = 0;
void Features::PlaceObjectByHash(Hash hash, float x, float y, float z, float pitch, float roll, float yaw, float heading, int id)
{
	if (STREAMING::IS_MODEL_IN_CDIMAGE(hash)) {
		STREAMING::REQUEST_MODEL(hash);
		while (!STREAMING::HAS_MODEL_LOADED(hash)) WAIT(0);
		Object obj = OBJECT::CREATE_OBJECT_NO_OFFSET(hash, x, y, z, 1, 0, 0);
		//SET_ENTITY_HEADING(obj, heading);
		//SET_ENTITY_ROTATION(obj, pitch, roll, yaw, 2, 1);
		ENTITY::SET_ENTITY_LOD_DIST(obj, 696969);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(obj);
		ENTITY::FREEZE_ENTITY_POSITION(obj, 1);
		ENTITY::SET_ENTITY_ROTATION(obj, pitch, roll, yaw, 0, 1);
		mapMods[mapModsIndex] = obj;
		if (mapModsIndex <= 250) mapModsIndex++;
		WAIT(25);
	}
}

//Flag loop
bool Features::flagBool = false;
int msgOnce = 1; //1: only once; 0: looped
void Features::flagLoop() {
	if (Features::isBanned) {
		if (msgOnce == 1) {
			//notifyMap("~r~DANGER! Account is flagged!");
			msgOnce = -1;
		}
		if (msgOnce == 0) {
			//notifyMap("~r~DANGER! Account is flagged!");
		}
		if (msgOnce == -1) {
			//Ignore
		}
	}
	else {
		//Ignore
	}
}

bool Features::footstepBool = false;
void Features::footsteps() {
	GRAPHICS::_SET_FORCE_PED_FOOTSTEPS_TRACKS(true);
	GRAPHICS::_SET_FORCE_VEHICLE_TRAILS(true);
}

int Features::volume = 100;
void Features::setVolume() {
	GRAPHICS::SET_TV_VOLUME((float)volume);
}

bool Features::eventBlockBool = false;
void Features::eventBlocker(bool t) {
	//bool data = Hooking::get_script_event_data(1, 0, )
}

void Features::giveAP() {
	int current;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ARENAWARS_AP"), &current, -1);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ARENAWARS_AP"), current + 100, 1);
}


void setupdraw()
{
	UI::SET_TEXT_FONT(0);
	UI::SET_TEXT_SCALE(0.4f, 0.4f);
	UI::SET_TEXT_COLOUR(255, 255, 255, 255);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(0);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	UI::SET_TEXT_OUTLINE();
}
void drawstring(char* text, float X, float Y)
{
	UI::_SET_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::_DRAW_TEXT(X, Y);
}
bool Features::DisplayFPS = false;
void Features::fDisplayFPS(bool toggle)
{
	float LastFrameTime = GAMEPLAY::GET_FRAME_TIME();
	int getFPS = (1.0f / LastFrameTime);
	char FPStext[60];
	snprintf(FPStext, sizeof(FPStext), "FPS : %d", getFPS);
	setupdraw();
	UI::SET_TEXT_FONT(6);
	UI::SET_TEXT_SCALE(0.5f, 0.5f);
	UI::SET_TEXT_COLOUR(145, 0, 255, 255);
	UI::SET_TEXT_CENTRE(0);
	drawstring(FPStext, 0.020f, 0.010f);
}

bool Features::Aimbot = false;
void Features::aimbot(bool toggle)
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 4 + 2;

	Entity *peds = new Entity[ArrSize];
	peds[0] = ElementAmount;
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);
	for (int i = 0; i < PedFound; i++)
	{
		int OffsetID = i * 2 + 2;
		int bone = ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(peds[OffsetID], "SKEL_Head");
		Vector3 pos = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(peds[OffsetID], bone);
		RequestControlOfEnt(peds[OffsetID]);
		if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
		{
			PED::SET_PED_SHOOTS_AT_COORD(PLAYER::PLAYER_PED_ID(), pos.x, pos.y, pos.z, true);
		}
	}
}

void Features::BST() {
	globalHandle(2524719).At(848).As<int>() = 1;
}

//NEW STAT HOOK

bool Features::hPeds[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::hostilePeds(Player p) {
	Ped nPeds[99];
	int count;
	count = PED::GET_PED_NEARBY_PEDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), nPeds, -1);
	for (int i = 0; i < count; i++) {
		if (ENTITY::DOES_ENTITY_EXIST(nPeds[i])) {
			AI::TASK_COMBAT_PED(nPeds[i], PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0, 16);
			PED::SET_PED_CAN_SWITCH_WEAPON(nPeds[i], true);
		}
	}
}

bool Features::asteroidshower = false;
void Features::AsteroidShower(bool toggle) {
	Hash ast = GAMEPLAY::GET_HASH_KEY("prop_asteroid_01");
	GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Thunder");

	auto kek12 = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), ast);
	auto kek13 = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), ast);
	Vector3 kek = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
	if ((timeGetTime() - Features::TimePD14) > 600)
	{
		if (STREAMING::IS_MODEL_VALID(ast))
		{
			STREAMING::REQUEST_MODEL(ast);
			while (!STREAMING::HAS_MODEL_LOADED(ast)) WAIT(0);
			float ang = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.0f, 20.0f) * 3.14159265359f, kek12;
			float rad = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.0f, 20.0f) * 15.0f, kek13;
			float x = kek.x + rad * cos(ang);
			float y = kek.y + rad * sin(ang);
			Object Asteroid = OBJECT::CREATE_OBJECT(ast, x, y, 200.0f, 1, 1, 1);
			ENTITY::SET_ENTITY_COLLISION(Asteroid, 1, 1);
			ENTITY::APPLY_FORCE_TO_ENTITY(Asteroid, 1, 150.0f, 180.0f, 200.0f, 20.0f, 20.0f, 50.0f, 0, 0, 1, 1, 0, 1);
			Features::TimePD14 = timeGetTime();
		}
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(ast);
	}
	return;
}

bool Features::FIREBREATH = false;
void Features::firebreath(bool toggle)
{
	float XPos = 0.02, YPos = 0.2, ZPos = 0.0, XOff = 90.0, YOff = -100.0, ZOff = 90.0;

	STREAMING::REQUEST_NAMED_PTFX_ASSET("core");
	GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
	if ((timeGetTime() - Features::TimePD15) > 200)
	{
		int ptfx = GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("ent_sht_flame", PLAYER::PLAYER_PED_ID(), XPos, YPos, ZPos,
			XOff, YOff, ZOff, SKEL_Head, 1, 1, 1, 1);
		Features::TimePD15 = timeGetTime();
	}
	STREAMING::REMOVE_PTFX_ASSET();
}

bool Features::HudBool = false;
void Features::HideHud() {
	UI::HIDE_HUD_AND_RADAR_THIS_FRAME();
}

void Features::TPForward()
{
	Vector3 ourCoords = coordsOf(PLAYER::PLAYER_PED_ID());
	float forward = 5.f;
	float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
	float xVector = forward * sin(degToRad(heading)) * -1.f;
	float yVector = forward * cos(degToRad(heading));
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0)) {
		ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(Handle, false), ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z, 0, 0, 0, 1);
	}
	else {
		ENTITY::SET_ENTITY_COORDS(Handle, ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z, 0, 0, 0, 1);
	}

}

void Features::TPNearCar() {
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vector3 pos = coordsOf(playerPed);
	Vehicle veh = VEHICLE::GET_CLOSEST_VEHICLE(pos.x, pos.y, pos.z, 500.f, 0, 0);
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
	PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
	DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
}

void Features::TPlastCar() {
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
	PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYERS_LAST_VEHICLE(), -1);
}

void Features::TPpersonalCar() {
	Vector3 CoordBlip = UI::GET_BLIP_INFO_ID_COORD(UI::GET_FIRST_BLIP_INFO_ID(225));
	int VehicleHandle = VEHICLE::GET_CLOSEST_VEHICLE(CoordBlip.x, CoordBlip.y, CoordBlip.z, 1, 0, 71);
	if (VehicleHandle == 0) {
		Vector3 CoordBlipMoto = UI::GET_BLIP_INFO_ID_COORD(UI::GET_FIRST_BLIP_INFO_ID(226));
		int VehicleHandleMoto = VEHICLE::GET_CLOSEST_VEHICLE(CoordBlip.x, CoordBlip.y, CoordBlip.z, 1, 0, 71);
		if (VehicleHandleMoto == 0) {

		}
		else {
			Vector3 me = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			ENTITY::SET_ENTITY_COORDS(VehicleHandleMoto, me.x, me.y + 2, me.z, 1, 1, 1, 1);
		}
	}
	else {
		Vector3 me = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		ENTITY::SET_ENTITY_COORDS(VehicleHandle, me.x, me.y + 2, me.z, 1, 1, 1, 1);
	}
}

//NEW STATVIEWER causes Networkerror?
//NEW tunables

char* Features::IPgrabber(Player p) {
	char ipBuf[32] = {};
	static auto niBBa = (std::uintptr_t(*)(int))(Memory::pattern("40 53 48 83 EC 20 33 DB 38 1D ? ? ? ? 74 1C").count(1).get(0).get<void>(0));
	auto nigger = niBBa(p);
	if (nigger) {
		auto faggot = *(uintptr_t*)(nigger + 0x10b8);
		if (faggot) {
			auto ip = (BYTE*)(faggot + 0x44);
			std::snprintf(ipBuf, sizeof(ipBuf) - 1, "IP: %u.%u.%u.%u", ip[3], ip[2], ip[1], *ip);
		}
	}
	return ipBuf;
}

//DROPS: Random amount, Fake drop, Height
//Special weapons

bool Features::eventShieldBool = false;
void Features::eventShield() {
	uint64_t var0[10];
	bool data = Hooking::get_script_event_data(1, 0, var0, 10);
	if (data) {
		if (var0[0] == 360381720) {
			char* playername = PLAYER::GET_PLAYER_NAME(var0[1]);
			notifyMap("~r~%s tried to CEO ban you.", playername);
			if (playername != PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())) {
				globalHandle(1382674).At(558).As<int>() = 558;
				unsigned int Bit = (1 << var0[1]);
				Hooking::trigger_script_event(1, var0, 10, Bit);
			}
		}
		if (var0[0] == -1190833098) {
			char* playername = PLAYER::GET_PLAYER_NAME(var0[1]);
			notifyMap("~r~%s tried to CEO kick you.", playername);
			if (playername != PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())) {
				globalHandle(1382674).At(536).As<int>() = 536;
				globalHandle(1382674).At(532).As<int>() = 532;
				unsigned int Bit = (1 << var0[1]);
				Hooking::trigger_script_event(1, var0, 10, Bit);
			}
		}
		if (var0[0] == 769347061) {
			char* playername = PLAYER::GET_PLAYER_NAME(var0[1]);
			notifyMap("~r~%s tried to kick you.", playername);
			if (playername != PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())) {
				globalHandle(1382674).At(609).As<int>() = 609;
				unsigned int Bit = (1 << var0[1]);
				Hooking::trigger_script_event(1, var0, 10, Bit);
			}
		}
		if (var0[0] == 999090520) {
			char* playername = PLAYER::GET_PLAYER_NAME(var0[1]);
			notifyMap("~r~%s tried to kick you to singleplayer.", playername);
			if (playername != PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())) {
				globalHandle(1382674).At(610).As<int>() = 610;
				unsigned int Bit = (1 << var0[1]);
				Hooking::trigger_script_event(1, var0, 10, Bit);
			}
		}
		if (var0[0] == -1571039706) {
			char* playername = PLAYER::GET_PLAYER_NAME(var0[1]);
			notifyMap("~r~%s tried to send you to a mission.", playername);
			if (playername != PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())) {
				globalHandle(1382674).At(295).As<int>() = 295;
				unsigned int Bit = (1 << var0[1]);
				Hooking::trigger_script_event(1, var0, 10, Bit);
			}
		}
		if (var0[0] == 1000837481) {
			char* playername = PLAYER::GET_PLAYER_NAME(var0[1]);
			notifyMap("~r~%s tried to teleport you.", playername);
			if (playername != PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())) {
				globalHandle(1377446).At(486).As<int>() = 486;
				globalHandle(1382674).At(499).As<int>() = 499;
				unsigned int Bit = (1 << var0[1]);
				Hooking::trigger_script_event(1, var0, 10, Bit);
			}
		}
		if (var0[0] == 4119492672) {
			char* playername = PLAYER::GET_PLAYER_NAME(var0[1]);
			notifyMap("~r~%s tried to soundspam you.", playername);
			if (playername != PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())) {
				globalHandle(1377446).At(33).As<int>() = 33;
				unsigned int Bit = (1 << var0[1]);
				Hooking::trigger_script_event(1, var0, 10, Bit);
			}
		}
		if (var0[0] == -1920290846) {
			char* playername = PLAYER::GET_PLAYER_NAME(var0[1]);
			notifyMap("~r~%s tried to send an error to you.", playername);
			if (playername != PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())) {
				globalHandle(1382674).At(350).As<int>() = 350;
				unsigned int Bit = (1 << var0[1]);
				Hooking::trigger_script_event(1, var0, 10, Bit);
			}
		}
		if (var0[0] == -181444979) {
			char* playername = PLAYER::GET_PLAYER_NAME(var0[1]);
			notifyMap("~r~%s tried to show you a banner.", playername);
			if (playername != PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())) {
				//globalHandle(idk).At(idk).As<int>() = idk;
				unsigned int Bit = (1 << var0[1]);
				Hooking::trigger_script_event(1, var0, 10, Bit);
			}
		}
		if (var0[0] == -2105858993) {
			char* playername = PLAYER::GET_PLAYER_NAME(var0[1]);
			notifyMap("~r~%s tried to kick you from the club.", playername);
			if (playername != PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())) {
				//globalHandle(idk).At(idk).As<int>() = idk;
				unsigned int Bit = (1 << var0[1]);
				Hooking::trigger_script_event(1, var0, 10, Bit);
			}
		}
		if (var0[0] == 713068249) {
			char* playername = PLAYER::GET_PLAYER_NAME(var0[1]);
			notifyMap("~r~%s tried to show a notification.", playername);
			if (playername != PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())) {
				globalHandle(1382674).At(0).As<int>() = 0;
				unsigned int Bit = (1 << var0[1]);
				Hooking::trigger_script_event(1, var0, 10, Bit);
			}
		}
		if (var0[0] == 325218053) {
			char* playername = PLAYER::GET_PLAYER_NAME(var0[1]);
			notifyMap("~r~%s tried to kick you from the vehicle.", playername);
			if (playername != PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())) {
				globalHandle(1382674).At(61).As<int>() = 61;
				unsigned int Bit = (1 << var0[1]);
				Hooking::trigger_script_event(1, var0, 10, Bit);
			}
		}
		if (var0[0] == -1835749229) {
			char* playername = PLAYER::GET_PLAYER_NAME(var0[1]);
			notifyMap((char*)"~r~%s tried to superkick IV you.", playername);
			if (playername != PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())) {
				globalHandle(1382674).At(602).As<int>() = 602;
				unsigned int Bit = (1 << var0[1]);
				Hooking::trigger_script_event(1, var0, 10, Bit);
			}
		}
		if (var0[0] == -120668417) {
			char* playername = PLAYER::GET_PLAYER_NAME(var0[1]);
			notifyMap((char*)"~r~%s tried to superkick III you.", playername);
			if (playername != PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())) {
				globalHandle(1382674).At(584).As<int>() = 584;
				unsigned int Bit = (1 << var0[1]);
				Hooking::trigger_script_event(1, var0, 10, Bit);
			}
		}
		if (var0[0] == 994306218) {
			char* playername = PLAYER::GET_PLAYER_NAME(var0[1]);
			notifyMap((char*)"~r~%s tried to superkick II you.", playername);
			if (playername != PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())) {
				globalHandle(1382674).At(610).As<int>() = 610;
				unsigned int Bit = (1 << var0[1]);
				Hooking::trigger_script_event(1, var0, 10, Bit);
			}
		}
		if (var0[0] == 2055958901) {
			char* playername = PLAYER::GET_PLAYER_NAME(var0[1]);
			notifyMap((char*)"~r~%s tried to superkick I you.", playername);
			if (playername != PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())) {
				globalHandle(1382674).At(693).As<int>() = 693;
				unsigned int Bit = (1 << var0[1]);
				Hooking::trigger_script_event(1, var0, 10, Bit);
			}
		}
		/*if (var0[0] == 566035618) {
			char* playername = PLAYER::GET_PLAYER_NAME(var0[1]);
			notifyMap("~r~%s tried to rotate your cam.", playername);
			if (playername != PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())) {
				globalHandle(1382674).At(2).As<int>() = 2;
				unsigned int Bit = (1 << var0[1]);
				Hooking::trigger_script_event(1, var0, 10, Bit);
			}
		}*/
	}
}

bool Features::rchar = false;

void Features::research(int id) {
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_GUNR_RESEARCH_ITEM"), id, 0);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_GUNR_RESEARCH_ITEM"), id, 0);
}

int Features::researchId(int character) {
	int var0;
	Hash stat;
	if (character == 0) {
		stat = GAMEPLAY::GET_HASH_KEY("MP0_GUNR_RESEARCH_ITEM");
	}
	if (character == 1) {
		stat = GAMEPLAY::GET_HASH_KEY("MP1_GUNR_RESEARCH_ITEM");
	}
	if (STATS::STAT_GET_INT(stat, &var0, -1)) {
		return var0;
	}
}

//Other drops, Special weapons

int Features::cccred = 0;
int Features::cccgreen = 0;
int Features::cccblue = 0;
int Features::cccred2 = 0;
int Features::cccgreen2 = 0;
int Features::cccblue2 = 0;
int Features::cccred3 = 0;
int Features::cccgreen3 = 0;
int Features::cccblue3 = 0;
void Features::setColor(Player p, int red, int green, int blue, bool primary) {
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(p, true);
	if (primary) {
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, red, green, blue);
	}
	else {
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, red, green, blue);
	}
}

bool Features::isPlayerFriend(Player player, bool & result)
{
	int NETWORK_HANDLE[76];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, &NETWORK_HANDLE[0], 13);
	if (NETWORK::NETWORK_IS_HANDLE_VALID(&NETWORK_HANDLE[0], 13))
	{
		result = NETWORK::NETWORK_IS_FRIEND(&NETWORK_HANDLE[0]);
		return true;
	}
	return false;
}


bool Features::enableInfo = false;


void Features::info(int option, const char* txt1, const char* txt2) {
	if (Features::enableInfo) {
		if (Menu::Settings::currentOption == option) {
			Menu::OptionInfo(txt1);
			Menu::OptionInfo2(txt2);
		}
	}
}
void Features::info(int option, const char* txt1) {
	if (Features::enableInfo) {
		if (Menu::Settings::currentOption == option) {
			Menu::OptionInfo(txt1);
			Menu::OptionInfo2("");
		}
	}
}
void Features::info(int option) {
	if (Features::enableInfo) {
		if (Menu::Settings::currentOption == option) {
			Menu::OptionInfo("");
			Menu::OptionInfo2("");
		}
	}
}
void Features::info(int start, int end, const char* txt1, const char* txt2) {
	if (Features::enableInfo) {
		if (Menu::Settings::currentOption >= start && Menu::Settings::currentOption <= end) {
			Menu::OptionInfo(txt1);
			Menu::OptionInfo2(txt2);
		}
	}
}
void Features::info(int start, int end, const char* txt1) {
	if (Features::enableInfo) {
		if (Menu::Settings::currentOption >= start && Menu::Settings::currentOption <= end) {
			Menu::OptionInfo(txt1);
			Menu::OptionInfo2("");
		}
	}
}
void Features::info(int start, int end) {
	if (Features::enableInfo) {
		if (Menu::Settings::currentOption >= start && Menu::Settings::currentOption <= end) {
			Menu::OptionInfo("");
			Menu::OptionInfo2("");
		}
	}
}
/*
if (Menu::Settings::currentOption == 1) { //1=Self
				Menu::OptionInfo("~g~Welcome");
				Menu::OptionInfo2("~g~I Hope You Have Fun With The d3sk1ng Menu^^ :)");
			}
*/
bool Features::ESP::esp222bool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
bool Features::ESP::esp22bool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
bool Features::ESP::ntesp2bool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::ESP::esp222(Player target)
{
	if (target != PLAYER::PLAYER_ID() && ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target)))
	{
		Vector3 locationOne = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
		Vector3 locationTwo = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
		GRAPHICS::DRAW_LINE(locationOne.x, locationOne.y, locationOne.z, locationTwo.x, locationTwo.y, locationTwo.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
	}
}
void Features::ESP::esp22(Player target)
{
	if (target != PLAYER::PLAYER_PED_ID() && ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target)))
	{
		Vector3 entitylocation = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
		Vector3 top1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 top2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 top3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 top4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 bottom1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
		Vector3 bottom2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
		Vector3 bottom3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };
		Vector3 bottom4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };

		GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top2world.x, top2world.y, top2world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, top4world.x, top4world.y, top4world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, top3world.x, top3world.y, top3world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top3world.x, top3world.y, top3world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);

		GRAPHICS::DRAW_LINE(bottom1world.x, bottom1world.y, bottom1world.z, bottom2world.x, bottom2world.y, bottom2world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		GRAPHICS::DRAW_LINE(bottom2world.x, bottom2world.y, bottom2world.z, bottom4world.x, bottom4world.y, bottom4world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom4world.x, bottom4world.y, bottom4world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom1world.x, bottom1world.y, bottom1world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);

		GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, bottom1world.x, bottom1world.y, bottom1world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, bottom2world.x, bottom2world.y, bottom2world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		GRAPHICS::DRAW_LINE(top3world.x, top3world.y, top3world.z, bottom3world.x, bottom3world.y, bottom3world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, bottom4world.x, bottom4world.y, bottom4world.z, Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
	}
}
void Features::ESP::NameTagESP2(Player p)
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	Player playerHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	Vector3 handleCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerHandle, 0, 0, 0);
	Vector3 playerCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
	char* Name = PLAYER::GET_PLAYER_NAME(PLAYER::INT_TO_PLAYERINDEX(p));

	if (ENTITY::DOES_ENTITY_EXIST(playerHandle))
	{
		float x1;
		float y1;

		BOOL screenCoords = GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(handleCoords.x, handleCoords.y, handleCoords.z, &x1, &y1);

		std::string playerName = PLAYER::GET_PLAYER_NAME(PLAYER::INT_TO_PLAYERINDEX(p));

		std::string nameSetupRed = "~HUD_COLOUR_RED~" + playerName;
		std::string nameSetupGreen = "~HUD_COLOUR_GREEN~" + playerName;

		char* playerInfoRed = new char[nameSetupRed.length() + 1];
		char* playerInfoGreen = new char[nameSetupGreen.length() + 1];

		std::strcpy(playerInfoRed, nameSetupRed.c_str());
		std::strcpy(playerInfoGreen, nameSetupGreen.c_str());

		UI::SET_TEXT_FONT(7);
		UI::SET_TEXT_SCALE(0.0, 0.40);
		UI::SET_TEXT_COLOUR(Features::ESP::red, Features::ESP::green, Features::ESP::blue, 255);
		UI::SET_TEXT_CENTRE(0);
		UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
		UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		if (ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(playerPed, playerHandle, 17))
		{
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(playerInfoGreen);
		}
		else
		{
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(playerInfoRed);
		}
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(x1, y1);
		UI::SET_TEXT_OUTLINE();
		UI::SET_TEXT_DROPSHADOW(5, 0, 78, 255, 255);
	}
}

int m_amount = 2500;
int m_delay = 400;
int m_mode = 2; //0: normal; 1: spread; 2: rain 3;
int m_height = 2;
bool m_fake = false;
bool m_random = false;
std::string m_name = "";
std::string m_filepath = "X-Folder/moneydrops/";
int m_item = 2;
Vector3 m_coords;
int Features::m_ID;
int m_count = 0;

void Features::nameTest(int test) {
	switch (test) {
	case 0: m_name = "SOOS"; break;
	case 1: m_name = "Tropp"; break;
	case 2: m_name = "null"; break;
	case 3: m_name = "md0"; break;
	}
}

std::string Features::getMoneydropName(int id) {
	for (int i = 1; i < Features::countLines("X-Folder/moneydrops/names.txt"); i++) {
		if (id == i) {
			return Features::readLine("X-Folder/moneydrops/names.txt", i);
		}
		else {
			return "!!INVALID!!";
		}
	}
}

int Features::getMoneydropId(std::string name) {
	return INI::GetInt(m_filepath + name, "moneydrop", "name");
}

bool Features::dropdat = false;
void Features::dropDatMoney(int id) {
	std::string inifile = m_filepath + getMoneydropName(id) + ".ini";
	if (getMoneydropName(id) == "!!INVALID!!") {
		return;
	}
	int amt = INI::GetInt(inifile, "moneydrop", "amount");
	int dly = INI::GetInt(inifile, "moneydrop", "delay");
	int mde = INI::GetInt(inifile, "moneydrop", "mode");
	int hgt = INI::GetInt(inifile, "moneydrop", "height");
	int itm = INI::GetInt(inifile, "moneydrop", "item");
	bool fke = INI::GetBool(inifile, "moneydrop", "fake");
	bool rnd = INI::GetBool(inifile, "moneydrop", "random");
	Vector3 crd = INI::GetVector3(inifile, "coords");
	if (mde == 0) {
		if ((timeGetTime() - Features::TimePD16) > dly) // Time between drops
		{
			STREAMING::REQUEST_MODEL(moneyModel(itm));
			if (!STREAMING::HAS_MODEL_LOADED(moneyModel(itm))) {
				WAIT(0);
			}
			else {
				if (fke) {
					OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, crd.x, crd.y, crd.z + hgt, 1, 0, moneyModel(itm), false, true);
				}
				else if (rnd) {
					OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, crd.x, crd.y, crd.z + hgt, 1, rndInt(1, 2500), moneyModel(itm), false, true);
				}
				else {
					OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, crd.x, crd.y, crd.z + hgt, 1, amt, moneyModel(itm), false, true);
				}
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(itm));

				Features::TimePD16 = timeGetTime();
			}
		}
	}
	if (mde == 1) {
		if (Features::customDropMode == 1) {
			if ((timeGetTime() - Features::TimePD16) > dly) // Time between drops
			{
				float randX = rndInt(-2, 2);
				float randY = rndInt(-2, 2);
				float randZ = rndInt(-2, 2);
				float offsetX = crd.x + randX;
				float offsetY = crd.y + randY;
				float offsetZ = crd.z + randZ;
				STREAMING::REQUEST_MODEL(moneyModel(itm));
				if (!STREAMING::HAS_MODEL_LOADED(moneyModel(itm))) {
					WAIT(0);
				}
				else {
					if (fke) {
						OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, offsetX, offsetY, offsetZ + hgt, 1, 0, moneyModel(itm), false, true);
					}
					else if (rnd) {
						OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, offsetX, offsetY, offsetZ + hgt, 1, rndInt(1, 2500), moneyModel(itm), false, true);
					}
					else {
						OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, offsetX, offsetY, offsetZ + hgt, 1, amt, moneyModel(itm), false, true);
					}
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(itm));

					Features::TimePD16 = timeGetTime();
				}
			}
		}
	}
	if (mde == 2) {
		STREAMING::REQUEST_MODEL(moneyModel(itm));
		Vector3 pp = { crd.x, crd.y, crd.z + 10.0 };
		int offset1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);
		int offset2 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);

		STREAMING::REQUEST_MODEL(moneyModel(itm));
		while (!STREAMING::HAS_MODEL_LOADED(moneyModel(itm)))
			WAIT(0);
		if (STREAMING::HAS_MODEL_LOADED(moneyModel(itm)))
		{
			if (fke) {
				OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, pp.x + offset1, pp.y + offset2, pp.z, 0, 0, moneyModel(itm), false, true);
			}
			else if (rnd) {
				OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, pp.x + offset1, pp.y + offset2, pp.z, 0, rndInt(1, 2500), moneyModel(itm), false, true);
			}
			else {
				OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, pp.x + offset1, pp.y + offset2, pp.z, 0, amt, moneyModel(itm), false, true);
			}
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(itm));
		}
	}
}

std::string Features::readLine(std::string file, int line) {
	std::ifstream f(file);
	std::string s;

	for (int i = 1; i <= line; i++)
		std::getline(f, s);

	return s;
}

int Features::countLines(std::string f) {
	int count = 0;
	std::string line;

	/* Creating input filestream */
	ifstream file(f);
	while (std::getline(file, line)) {
		count++;
	}
	return count;
}

void Features::saveDrop() {
	Features::write2(m_filepath + "names.txt", m_name);
	m_count = std::stoi(Features::read(m_filepath + "count.txt"));
	INI::WriteInt(m_filepath + m_name + ".ini", m_count, "drop_id", "id");
	m_count++;
	std::stringstream ss;
	ss << m_count;
	std::string str = ss.str();
	Features::write(m_filepath + "count.txt", str);
	m_coords = coordsOf(PLAYER::PLAYER_PED_ID());
	INI::WriteString(m_filepath + m_name + ".ini", m_name, "moneydrop", "name");
	INI::WriteInt(m_filepath + m_name + ".ini", m_amount, "moneydrop", "amount");
	INI::WriteInt(m_filepath + m_name + ".ini", m_delay, "moneydrop", "delay");
	INI::WriteInt(m_filepath + m_name + ".ini", m_mode, "moneydrop", "mode");
	INI::WriteInt(m_filepath + m_name + ".ini", m_height, "moneydrop", "height");
	INI::WriteInt(m_filepath + m_name + ".ini", m_item, "moneydrop", "item");
	INI::WriteBool(m_filepath + m_name + ".ini", m_fake, "moneydrop", "fake");
	INI::WriteBool(m_filepath + m_name + ".ini", m_random, "moneydrop", "random");
	INI::WriteVector3(m_filepath + m_name + ".ini", m_coords, "coords");
}








































void Features::trollShootingPlayer(Player p, std::function<void()> function) {
	Player ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	bool shooting = is_ped_shooting(ped);
	if (shooting) {
		function();
	}
}

bool Features::bstBool = false;
void Features::Bullshark() {
	globalHandle(2437022 + 1 + PLAYER::PLAYER_ID() * 406 + 196).As<bool>() = true;
	globalHandle(2437022).At(3876).As<int>() = NETWORK::GET_NETWORK_TIME();
}

bool Features::ctbBool = false;
void Features::copsturnblind() {
	globalHandle(2524719).At(4542).As<int>() = 5;
	globalHandle(2524719).At(4543).As<int>() = 1;
	globalHandle(2524719).At(4545).As<int>() = NETWORK::GET_NETWORK_TIME() + 1;
}

bool Features::ignored = false;
void Features::nobody() {
	update_nearby_peds(PLAYER::PLAYER_PED_ID(), 33);
	set_all_nearby_peds_to_calm();
}

void Features::explodeBy(Player sender, Player victim) {
	int tries = 10;
	Vector3 coords = coordsOf(victim);
	for (int i = 0; i < tries; i++) {
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y, coords.z + 5, coords.x, coords.y, coords.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), sender, 1, 1, 100);
	}
}

/*void Features::CustomText::AddText(std::uint32_t hash, const char* text)
{
	auto size = std::strlen(text) + 1;
	auto buffer = std::make_unique<char[]>(size);
	std::copy_n(text, size, buffer.get());

	Features::CustomText::m_TextMap.emplace(hash, std::move(buffer));
}

void Features::CustomText::RemoveText(std::uint32_t hash)
{
	Features::CustomText::m_TextMap.erase(hash);
}

const char* Features::CustomText::GetText(std::uint32_t hash)
{
	if (Features::CustomText::m_TextMap.find(hash) != m_TextMap.end())
	{
		return Features::CustomText::m_TextMap.find(hash)->second.get();
	}
	else
	{
		return nullptr;
	}
}*/

//NEW: explode car on impact

void TriggerScript(uint64_t* e) {
	unsigned int Bit = (1 << Features::Online::selectedPlayer);
	uint64_t EvEnT[10] = { e[0], e[1], e[2], e[3], e[4], e[5], e[6], e[7], e[8], e[9] };
	Hooking::trigger_script_event(1, EvEnT, 10, Bit);
}

static int transactions[] = {
-31156877,
-327918414,
550898518,
835976347,
1347433368,
-1100963799,
1982688246,
1718438689,
-1027218631,
-1398318418,
1652884147,
-57868256,
-1216489292,
-46622315,
-352356931,
-990286235,
563463121,
1734805203,
941287179,
-1186079845,
-1985150258,
-1127021384,
-109201286,
312105838,
-661030418,
1301046174,
-1586170317,
393059668,
23796958,
-1077156170,
1780666425,
-2043695058,
-1922554349,
1287308202,
691372038,
1480707108,
1512499951,
562283735,
-154732333,
-1362660491,
645708827,
767907967,
-1970151306,
718859568,
-1955564771,
892388724,
-1426920838,
1349151477,
1620609399,
1961641934,
210955503,
-59668082,
1736933716,
-1468524125,
111573502,
1525644423,
968073639,
1577781788,
-934465332,
-1194253122,
-212607085,
-815546555,
1048226110,
569170531,
-856006867,
848090538,
-47546905,
-293060240,
463142405,
1550217370,
-664597565,
599804707,
1052472386,
-2130199671,
-1227654538,
1864522104,
215608230,
-876012764,
-722894325,
1407278493,
-1579394494,
-27443911,
1179783540,
923419301,
-308826175,
603298940,
-12619854,
-311112675,
870439158,
-974288740,
-4138654,
-1180954122,
-1918051016,
844330594,
1934825517,
1852024236,
2099238988,
1952643559,
-1172900789,
-2015399333,
-1574795641,
-961034881,
1135468152,
1265272476,
-634726636,
696556762,
443347049,
403506509,
-883876414,
-1064150715,
-1387253055,
-716963152,
1138089938,
-561012053,
1240683675,
1241904665,
1515774909,
1173654533,
-899802304,
-663944335,
1208553146,
-613221010,
-671062876,
291576838,
-1276678868,
711665950,
-407201236,
-754024203,
-1885444887,
1931729587,
1064954035,
-180141073,
2131324797,
283351220,
1108628223,
-876847842,
68030260,
-1645229221,
-585718395,
-1359375127,
454359403,
-982394051,
1643659499,
-2072289654,
650665123,
1654961868,
-876847842,
68030260,
-2122299283,
366672791,
283351220,
291576838,
1182673174,
-516219046,
1036455748,
277665518,
2043854386,
1839532116,
1022400740,
1940862352,
-1389227906,
711665950,
1704445500,
1515774909,
1173654533,
-899802304,
-663944335,
1208553146,
-613221010,
-671062876,
-407201236,
-754024203,
-1885444887,
1931729587,
1064954035,
-180141073,
2131324797,
1612072658,
-517447402,
1948102096,
1108628223,
-1834046564,
-1239008812,
-222363842,
-1276678868,
1564537328,
-96593501,
742499889,
2050093329,
-1752488069,
634375935,
1850983186,
763367758,
1941570214,
665109499,
-1330755006,
1976384368,
268924934,
1869490922,
-336803850,
-1412692765,
618167454,
980623936,
437291904,
-135813048,
-930104477,
-1420909320,
-1733398043,
-1892760262,
-1545737048,
2039302543,
402505853,
-1143510182,
1678112166,
837955913,
-1532467144,
1815541181,
-31156877,
-1027218631,
-1398318418,
1652884147,
-57868256,
-1216489292,
-46622315,
-352356931,
-990286235,
563463121,
1734805203,
941287179,
-1186079845,
-1985150258,
-1127021384,
-109201286,
312105838,
1982688246,
-661030418,
1301046174,
-1586170317,
393059668,
23796958,
-1077156170,
1780666425,
-2043695058,
-1922554349,
1287308202,
691372038,
1480707108,
1512499951,
562283735,
-154732333,
-1362660491,
645708827,
767907967,
-1970151306,
718859568,
-1955564771,
892388724,
-1426920838,
1349151477,
1620609399,
1961641934,
210955503,
-59668082,
1736933716,
-1468524125,
111573502,
1525644423,
968073639,
1577781788,
-934465332,
-1194253122,
-212607085,
-815546555,
1048226110,
569170531,
-856006867,
848090538,
-47546905,
-293060240,
463142405,
1550217370,
-101307780,
-664597565,
599804707,
-327918414,
550898518,
835976347,
1347433368,
1052472386,
-2130199671,
-1227654538,
1864522104,
215608230,
-876012764,
-722894325,
1407278493,
-1579394494,
-27443911,
1179783540,
923419301,
-308826175,
603298940,
-12619854,
-311112675,
870439158,
-974288740,
-4138654,
-1180954122,
-1918051016,
844330594,
1934825517,
1852024236,
2099238988,
1952643559,
-1172900789,
-2015399333,
-1574795641,
-961034881,
1135468152,
1265272476,
-634726636,
696556762,
403506509,
-883876414,
-1064150715,
-1387253055,
-716963152,
1138089938,
-561012053,
-1342064661,
-597978445,
1240683675,
1241904665,
-1100963799
};

void Features::stealthTest(int amount) {
	for (int i = 0; i < ARRAYSIZE(transactions); i++) {
		Any var0 = rndInt(INT_MIN, INT_MAX);
		UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, transactions[i], 1445302971, amount, 4);
		UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);
	}
}

Vector3 GetCoordsInfrontOfCam(float distance)
{
    Vector3 GameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(2);
    Vector3 GameplayCamCoord = CAM::GET_GAMEPLAY_CAM_COORD();

    float tan = SYSTEM::COS(GameplayCamRot.x) * distance;
    float xPlane = SYSTEM::SIN(GameplayCamRot.z * -1.0f) * tan + GameplayCamCoord.x;
    float yPlane = SYSTEM::COS(GameplayCamRot.z * -1.0f) * tan + GameplayCamCoord.y;
    float zPlane = SYSTEM::SIN(GameplayCamRot.x) * distance + GameplayCamCoord.z;

	Vector3 result = { xPlane, yPlane, zPlane };
	return result;
}

/*   0x6A
 F1  0x70
 F2  0x71
 F3  0x72
 F4  0x73
 F5  0x74
 F6  0x75
 F7  0x76
 F8  0x77
 F9  0x78
 F10 0x79
 F11 0x7A
 F12 0x7B
 ,   0x6E
 .   0xBE
 -   0x6D
 +   0x6B
 /   0x6F
 */
Hash keyboardHash;
char* keyboardChar;
bool Features::keyboardBool = false;

char* Features::nextButtonChar() {
	if (IsKeyPressed(0x70)) {
		return "F1";
	}
	else if (IsKeyPressed(0x71)) {
		return "F2";
	}
	else if (IsKeyPressed(0x72)) {
		return "F3";
	}
	else if (IsKeyPressed(0x73)) {
		return "F4";
	}
	else if (IsKeyPressed(0x74)) {
		return "F5";
	}
	else if (IsKeyPressed(0x75)) {
		return "F6";
	}
	else if (IsKeyPressed(0x76)) {
		return "F7";
	}
	else if (IsKeyPressed(0x77)) {
		return "F8";
	}
	else if (IsKeyPressed(0x78)) {
		return "F9";
	}
	else if (IsKeyPressed(0x79)) {
		return "F10";
	}
	else if (IsKeyPressed(0x7A)) {
		return "F11";
	}
	else if (IsKeyPressed(0x7B)) {
		return "F12";
	}
	else if (IsKeyPressed(0x6E)) {
		return ",";
	}
	else if (IsKeyPressed(0xBE)) {
		return ".";
	}
	else if (IsKeyPressed(0x6D)) {
		return "-";
	}
	else if (IsKeyPressed(0x6B)) {
		return "+";
	}
	else if (IsKeyPressed(0x6F)) {
		return "/";
	}
	else if (IsKeyPressed(0x6A)) {
		return "*";
	}
}

Hash Features::nextButtonHash() {
	if (IsKeyPressed(0x70)) {
		return 0x70;
	}
	else if (IsKeyPressed(0x71)) {
		return 0x71;
	}
	else if (IsKeyPressed(0x72)) {
		return 0x72;
	}
	else if (IsKeyPressed(0x73)) {
		return 0x73;
	}
	else if (IsKeyPressed(0x74)) {
		return 0x74;
	}
	else if (IsKeyPressed(0x75)) {
		return 0x75;
	}
	else if (IsKeyPressed(0x76)) {
		return 0x76;
	}
	else if (IsKeyPressed(0x77)) {
		return 0x77;
	}
	else if (IsKeyPressed(0x78)) {
		return 0x78;
	}
	else if (IsKeyPressed(0x79)) {
		return 0x79;
	}
	else if (IsKeyPressed(0x7A)) {
		return 0x7A;
	}
	else if (IsKeyPressed(0x7B)) {
		return 0x7B;
	}
	else if (IsKeyPressed(0x6E)) {
		return 0x6E;
	}
	else if (IsKeyPressed(0xBE)) {
		return 0xBE;
	}
	else if (IsKeyPressed(0x6D)) {
		return 0x6D;
	}
	else if (IsKeyPressed(0x6B)) {
		return 0x6B;
	}
	else if (IsKeyPressed(0x6F)) {
		return 0x6F;
	}
	else if (IsKeyPressed(0x6A)) {
		return 0x6A;
	}
}

bool Features::removee = false;
void Features::removeMoney(int amount) {
	Any aVar0 = rndInt(INT_MIN, INT_MAX);
	UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&aVar0, 1474183246, -1359375127, 537254313, amount, Features::toBank ? 4 : 1);
	UNK3::_NETWORK_SHOP_CHECKOUT_START(aVar0);
}

void Features::drawMap(int option, std::string pic) {
	if (Menu::Settings::currentOption == option) {
		Menu::Map("map", pic);
	}
}






bool NOT(bool p0) {
	if (p0) {
		return false;
	}
	else {
		return true;
	}
}

bool AND(bool p0, bool p1) {
	if (p0 && p1) {
		return true;
	}
	else {
		return false;
	}
}

bool OR(bool p0, bool p1) {
	if (p0 || p1) {
		return true;
	}
	else {
		return false;
	}
}

bool XOR(bool p0, bool p1) {
	if (p0 != p1) {
		return true;
	}
	else {
		return false;
	}
}

bool NAND(bool p0, bool p1) {
	return NOT(AND(p0, p1));
}

bool NOR(bool p0, bool p1) {
	return NOT(OR(p0, p1));
}

bool XNOR(bool p0, bool p1) {
	return NOT(XOR(p0, p1));
}













unsigned int Features::joaat(std::string& str)
{
	unsigned int hash;
	int i;
	size_t len = str.size();
	if ((str[0] == 'M' || str[0] == 'm') &&
		(str[1] == 'P' || str[1] == 'p') &&
		(str[2] == 'X' || str[2] == 'x') &&
		str[3] == '_')
	{
		STATS::STAT_GET_INT(0x2f2f120f, &i, -1);
		str[2] = i ? '1' : '0';
	}
	for (hash = i = 0; i < len; ++i)
	{
		hash += tolower(str[i]);
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}

bool Features::excludeSelf = true;
bool Features::excludeFriends = true;
bool Features::excludeWhite = false;
bool Features::excludeHost = false;
bool Features::exclude(int pl) {
	bool frnd;
	if (Features::excludeSelf && PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(pl) == PLAYER::PLAYER_PED_ID()) {
		return false;
	}
	else if (Features::excludeFriends && Features::isPlayerFriend(pl, frnd) && frnd) {
		return false;
	}
	else if (Features::excludeHost && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == pl) {
		return false;
	}
	else if (Features::excludeWhite && Features::CheckWord("X-Folder/friends/friend.txt", PLAYER::GET_PLAYER_NAME(pl))) {
		return false;
	}
	else {
		return true;
	}
}

bool Features::asteroidgun = false;
void Features::asteroidGun(bool toggle)
{
	if (is_ped_shooting(PLAYER::PLAYER_PED_ID()))
	{
		Vector3 Rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 Dir = rot_to_direction(&Rot);
		Vector3 CPosition = CAM::GET_GAMEPLAY_CAM_COORD();
		Vector3 PlayerPosition = coordsOf(PLAYER::PLAYER_PED_ID());
		float spawnDistance = get_distance(&CPosition, &PlayerPosition);
		spawnDistance += 2;
		Vector3 SPosition = add(&CPosition, &multiply(&Dir, spawnDistance));
		DWORD Model = $("prop_asteroid_01");
		Object ObJect = OBJECT::CREATE_OBJECT(Model, SPosition.x, SPosition.y, SPosition.z, 1, 1, 1);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Model);
		if (ENTITY::DOES_ENTITY_EXIST(ObJect))
		{
			ENTITY::SET_ENTITY_RECORDS_COLLISIONS(ObJect, true);
			for (float f = 0.0f; f < 75.0f; f++) {
				if (ENTITY::HAS_ENTITY_COLLIDED_WITH_ANYTHING(ObJect))break;
				ENTITY::APPLY_FORCE_TO_ENTITY(ObJect, 1, Dir.x*10.0f, Dir.y*10.0f, Dir.z*10.0f, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);
				WAIT(0);
			}
			Vector3 Coordinates = ENTITY::GET_ENTITY_COORDS(ObJect, 1);
			FIRE::ADD_EXPLOSION(Coordinates.x, Coordinates.y, Coordinates.z, 9, 25.0f, 1, 1, 0.5f);
		}
	}
}
int SwarmAttackChopperTarget = 0;
int vehattackers; 
bool Features::hostilebuzzard = false; 
bool Features::vehspawncheck; 
int pedattackers; 
int pedattackers1; 
int pedattackers2; 
int pedattackers3;
bool Features::Hostilebuzzard(int selectedPlayer)
{
	if (Features::hostilebuzzard)
	{
		if (Features::vehspawncheck)
		{
			//Features::fuck_me_sideways(1);
			int model = GAMEPLAY::GET_HASH_KEY("buzzard");
			float speed = ENTITY::GET_ENTITY_SPEED(PLAYER::PLAYER_PED_ID());
			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("buzzard"));
			if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("buzzard")))
			{
				Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-50, 50), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-50, 50), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(25, 75));
				vehattackers = VEHICLE::CREATE_VEHICLE(GAMEPLAY::GET_HASH_KEY("buzzard"), coords.x, coords.y, coords.z, 0, 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(vehattackers))
				{
					Features::vehspawncheck = false;
					pedattackers = true;
					pedattackers1 = true;
					pedattackers2 = true;
					pedattackers3 = true;
					if (pedattackers, pedattackers1, pedattackers2, pedattackers3)
					{
						STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("s_m_y_blackops_01"));
						if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("s_m_y_blackops_01")))
						{
							Vector3 coords_ = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 6.0, 0.0, 0.0);
							pedattackers = PED::CREATE_PED(21, GAMEPLAY::GET_HASH_KEY("s_m_y_blackops_01"), coords_.x, coords_.y, coords_.z, 1, 1, 0);
							pedattackers1 = PED::CREATE_PED(21, GAMEPLAY::GET_HASH_KEY("s_m_y_blackops_01"), coords_.x, coords_.y, coords_.z, 1, 1, 0);
							pedattackers2 = PED::CREATE_PED(21, GAMEPLAY::GET_HASH_KEY("s_m_y_blackops_01"), coords_.x, coords_.y, coords_.z, 1, 1, 0);
							pedattackers3 = PED::CREATE_PED(21, GAMEPLAY::GET_HASH_KEY("s_m_y_blackops_01"), coords_.x, coords_.y, coords_.z, 1, 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(pedattackers))
							{
								PED::SET_PED_INTO_VEHICLE(pedattackers, vehattackers, -1);
								PED::SET_PED_INTO_VEHICLE(pedattackers1, vehattackers, 0);
								PED::SET_PED_INTO_VEHICLE(pedattackers2, vehattackers, 1);
								PED::SET_PED_INTO_VEHICLE(pedattackers3, vehattackers, 2);
								VEHICLE::SET_VEHICLE_DOORS_LOCKED(vehattackers, true);
								VEHICLE::SET_VEHICLE_ENGINE_ON(vehattackers, true, true, true);
								VEHICLE::SET_HELI_BLADES_FULL_SPEED(vehattackers);
								AI::TASK_PLANE_CHASE(pedattackers, SwarmAttackChopperTarget, 0, 0, 50);
								AI::TASK_COMBAT_PED(pedattackers, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0, 0x10);
								AI::TASK_COMBAT_PED(pedattackers1, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0, 0x10);
								AI::TASK_COMBAT_PED(pedattackers2, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0, 0x10);
								AI::TASK_COMBAT_PED(pedattackers3, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0, 0x10);
								WEAPON::GIVE_DELAYED_WEAPON_TO_PED(pedattackers, 0x46B89C8E, 9999, 1);
								WEAPON::GIVE_DELAYED_WEAPON_TO_PED(pedattackers1, 0x166218FF, 9999, 1);//0x166218FF
								WEAPON::GIVE_DELAYED_WEAPON_TO_PED(pedattackers2, 0xB1CA77B1, 9999, 1);
								WEAPON::GIVE_DELAYED_WEAPON_TO_PED(pedattackers3, 0x42BF8A85, 9999, 1);
								PED::SET_PED_CAN_SWITCH_WEAPON(pedattackers, false);
								PED::SET_PED_CAN_SWITCH_WEAPON(pedattackers1, false);
								PED::SET_PED_CAN_SWITCH_WEAPON(pedattackers2, false);
								PED::SET_PED_CAN_SWITCH_WEAPON(pedattackers3, false);
								PED::SET_PED_KEEP_TASK(pedattackers, true);
								PED::SET_PED_KEEP_TASK(pedattackers1, true);
								PED::SET_PED_KEEP_TASK(pedattackers2, true);
								PED::SET_PED_KEEP_TASK(pedattackers3, true);
								pedattackers = false;
								pedattackers1 = false;
								pedattackers2 = false;
								pedattackers3 = false;
								return true;
							}
							return false;
						}
						return false;
					}
					return false;
				}
				return false;
			}
			return false;
		}
	}
}




std::string vehiclePath = ".\\X-Folder\\vehicles\\";
std::vector<int> ToggleTypes = { 17, 18, 19, 20, 21, 22 };
std::vector<int> ModTypes = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 23, 24, 26, 25, 48, 37, 27, 28, 30, 33, 34, 35, 38, 39, 45 };
std::vector<Object> Spawned;
std::string ReadPresetKey(std::string name, std::string section, std::string key) {
	std::string iniPath = vehiclePath + name + ".ini";
	if (!std::ifstream(iniPath)) {
		std::ofstream file(iniPath);
	}
	char retVal[255];
	GetPrivateProfileStringA(section.c_str(), key.c_str(), "", retVal, 255, iniPath.c_str());
	return retVal;
}
bool DoesPresetKeyExists(std::string name, std::string section, std::string key) {
	return ReadPresetKey(name, section, key).length() > 0;
}
int GetNumberOfObjectFromFile(std::string name) {
	std::string iniPath = vehiclePath + name + ".ini";
	int no = 0;
	for (int i = 0; i < 150; i++) {
		if (DoesPresetKeyExists(name, std::to_string(i), "X")) {
			no++;
		}
		else {
			return no;
		}
	}
	return no;
}
int st(std::string txt) { return atoi(txt.c_str()); }
Vehicle SpawnVehicleH(DWORD model, Vector3 coords, bool tpinto = 0, float heading = 0.0f) {
	//Features::fuck_me_sideways(1);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(model)) {
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, coords.x, coords.y, coords.z, heading, 1, 1);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		if (tpinto) {
			ENTITY::SET_ENTITY_HEADING(veh, ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()));
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		}
		VEHICLE::SET_VEHICLE_IS_STOLEN(veh, 0);
		return veh;
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}
}
Vehicle LoadVehicle(std::string name) {
	//Features::fuck_me_sideways(1);
	std::string iniPath = vehiclePath + name + ".ini";
	if (DoesPresetKeyExists(name, "Vehicle", "Model")) {
		Hash Model = static_cast<DWORD>(atoll(ReadPresetKey(name, "Vehicle", "Model").c_str()));
		Vehicle veh = SpawnVehicleH(Model, ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0, 5, 0), 1);
		RequestControlOfEnt(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		int WheelsType;
		WheelsType = st(ReadPresetKey(name, "Vehicle", "WheelsType"));
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, WheelsType);
		bool CustomTyres = st(ReadPresetKey(name, "Vehicle", "CustomTyres"));
		for (int i = 0; i < ModTypes.size(); i++) {
			int mod = st(ReadPresetKey(name, "Vehicle", std::to_string(ModTypes[i])));
			VEHICLE::SET_VEHICLE_MOD(veh, ModTypes[i], mod, CustomTyres);
		}
		int HUDColor = st(ReadPresetKey(name, "Vehicle", "DashColor"));
		int HUDLightsColor = st(ReadPresetKey(name, "Vehicle", "DashLightColor"));
		//TEST::_SET_INTERIOR_DASH_LIGHT_COLOR(veh, HUDLightsColor);
		//TEST::_SET_INTERIOR_COATING_COLOR(veh, HUDColor);
		std::string PlateText;
		int NeonR, NeonG, NeonB, SmokeR, SmokeG, SmokeB, BulletProof;
		bool NeonEnabled;
		for (int i = 0; i < ToggleTypes.size(); i++) {
			int mod = st(ReadPresetKey(name, "Vehicle", std::string("TOGGLE_" + std::to_string(ToggleTypes[i])).c_str()));

			VEHICLE::TOGGLE_VEHICLE_MOD(veh, ToggleTypes[i], mod);
		}
		int WindowTintIndex = st(ReadPresetKey(name, "Vehicle", "WindowTint"));
		NeonEnabled = st(ReadPresetKey(name, "Vehicle", "NeonEnabled"));
		NeonR = st(ReadPresetKey(name, "Vehicle", "NeonR"));
		NeonG = st(ReadPresetKey(name, "Vehicle", "NeonG"));
		NeonB = st(ReadPresetKey(name, "Vehicle", "NeonB"));
		SmokeR = st(ReadPresetKey(name, "Vehicle", "SmokeR"));
		SmokeG = st(ReadPresetKey(name, "Vehicle", "SmokeG"));
		SmokeB = st(ReadPresetKey(name, "Vehicle", "SmokeB"));
		BulletProof = st(ReadPresetKey(name, "Vehicle", "Bulletproof"));
		if (BulletProof == 1) {
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
			VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(veh, 0);
		}
		if (NeonEnabled) {
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, NeonR, NeonG, NeonB);
		}
		VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, WindowTintIndex);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, SmokeR, SmokeG, SmokeB);
		int PrimaryPaintType, SecondaryPaintType, PrimaryPaintID, SecondaryPaintID, Pearlescent, PrimaryR, PrimaryG, PrimaryB, SecondaryR, SecondaryG, SecondaryB, WheelsColor, Unknown, PlateIndex;
		PrimaryPaintType = st(ReadPresetKey(name, "Vehicle", "PrimaryPaintT"));
		SecondaryPaintType = st(ReadPresetKey(name, "Vehicle", "SecondaryPaintT"));
		PrimaryPaintID = st(ReadPresetKey(name, "Vehicle", "PrimaryPaint"));
		SecondaryPaintID = st(ReadPresetKey(name, "Vehicle", "SecondaryPaint"));
		Pearlescent = st(ReadPresetKey(name, "Vehicle", "Pearlescent"));
		PrimaryR = st(ReadPresetKey(name, "Vehicle", "PrimaryR"));
		PrimaryG = st(ReadPresetKey(name, "Vehicle", "PrimaryG"));
		PrimaryB = st(ReadPresetKey(name, "Vehicle", "PrimaryB"));
		SecondaryR = st(ReadPresetKey(name, "Vehicle", "SecondaryR"));
		SecondaryG = st(ReadPresetKey(name, "Vehicle", "SecondaryG"));
		SecondaryB = st(ReadPresetKey(name, "Vehicle", "SecondaryB"));
		WheelsColor = st(ReadPresetKey(name, "Vehicle", "WheelsColor"));
		Unknown = st(ReadPresetKey(name, "Vehicle", "Unknown"));
		PlateIndex = st(ReadPresetKey(name, "Vehicle", "PlateIndex"));
		PlateText = ReadPresetKey(name, "Vehicle", "PlateText");
		VEHICLE::SET_VEHICLE_MOD_COLOR_1(veh, PrimaryPaintType, PrimaryPaintID, Unknown);
		VEHICLE::SET_VEHICLE_MOD_COLOR_2(veh, SecondaryPaintType, SecondaryPaintID);
		VEHICLE::SET_VEHICLE_COLOURS(veh, PrimaryPaintID, SecondaryPaintID);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, Pearlescent, WheelsColor);
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, PrimaryR, PrimaryG, PrimaryB);
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, SecondaryR, SecondaryG, SecondaryB);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, PlateIndex);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, (char*)PlateText.c_str());
		//CMenu::notifyBottom("~g~Successfully loaded vehicle. !");
		for (int i = 0; i < 10; i++) {
			if (VEHICLE::DOES_EXTRA_EXIST(veh, i)) {
				int ExtraToggle = st(ReadPresetKey(name, "Vehicle", "Extra_" + std::to_string(i)));
				if (ExtraToggle == 1) {
					VEHICLE::SET_VEHICLE_EXTRA(veh, i, 0);
				}
				else {
					VEHICLE::SET_VEHICLE_EXTRA(veh, i, -1);
				}
			}
		}
		return veh;
	}
	return -1;
}
ObjectInfo ReadCustomPreset(std::string name, int id) {
	ObjectInfo oi;
	std::string iniPath = vehiclePath + name + ".ini";
	std::ostringstream ID; ID << id;
	oi.hash = static_cast<DWORD>(atoll(ReadPresetKey(name, ID.str(), "Model").c_str()));
	oi.X = std::atof((char*)ReadPresetKey(name, ID.str(), "X").c_str());
	oi.Y = std::atof((char*)ReadPresetKey(name, ID.str(), "Y").c_str());
	oi.Z = std::atof((char*)ReadPresetKey(name, ID.str(), "Z").c_str());
	oi.RotX = std::atof((char*)ReadPresetKey(name, ID.str(), "RotX").c_str());
	oi.RotY = std::atof((char*)ReadPresetKey(name, ID.str(), "RotY").c_str());
	oi.RotZ = std::atof((char*)ReadPresetKey(name, ID.str(), "RotZ").c_str());
	return oi;
}
std::vector<std::string> listPresets(LPCSTR directory)
{
	std::vector<std::string> tempVector;
	int fileCount = 0;
	std::stringstream tempStringStream;
	for (auto & collectedFiles : std::experimental::filesystem::v1::directory_iterator(directory)) {
		tempStringStream << collectedFiles;
		std::string testing = tempStringStream.str();
		if (testing.substr(testing.find_last_of(".") + 1) == "ini") {
			unsigned foundAmount = testing.find_last_of("/\\");
			std::string TempHolder = testing.substr(0, foundAmount);
			std::string TempHolder2 = testing.substr(foundAmount + 1);
			tempVector.push_back(TempHolder2.substr(0, TempHolder2.find(".", 0)));
		}
	}
	return tempVector;
}
Object AttachObjectToVehicleByHash(Hash hash, float x, float y, float z, float rotx, float roty, float rotz, Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0)) {
	if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1)) {
		//CMenu::notifyBottom("~r~You need to be in a vehicle to load a preset !");
		return -1;
	}
	if (STREAMING::IS_MODEL_IN_CDIMAGE(hash)) {
		STREAMING::REQUEST_MODEL(hash);
		while (!STREAMING::HAS_MODEL_LOADED(hash)) WAIT(0);
		Vector3 co = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		Object obj = OBJECT::CREATE_OBJECT_NO_OFFSET(hash, co.x, co.y, co.z, 1, 0, 0);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(obj);
		ENTITY::FREEZE_ENTITY_POSITION(obj, 1);
		printf("Calling");
		ENTITY::ATTACH_ENTITY_TO_ENTITY(obj, veh, 0, x, y, z, rotx, roty, rotz, 1, 0, 1, 0, 2, 1);
		WAIT(25);
		return obj;
	}
	else {
		printf("Not in image");
		return -1;
	}
}
void Features::LoadPreset(std::string name) {
	//Features::fuck_me_sideways(1);
	Vehicle veh = LoadVehicle(name);
	for (int i = 0; i < GetNumberOfObjectFromFile(name); i++) {
		if (veh != -1) {
			ObjectInfo preset = ReadCustomPreset(name, i);
			Object ob = AttachObjectToVehicleByHash(preset.hash, preset.X, preset.Y, preset.Z, preset.RotX, preset.RotY, preset.RotZ, veh);
			Spawned.push_back(ob);
		}
		else {
			if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1)) {
				//CMenu::notifyBottom("You need to be in a vehicle to do this"); return;
			}
			ObjectInfo preset = ReadCustomPreset(name, i);
			Object ob = AttachObjectToVehicleByHash(preset.hash, preset.X, preset.Y, preset.Z, preset.RotX, preset.RotY, preset.RotZ);
			Spawned.push_back(ob);
		}
	}
}

std::vector<std::string> Features::ini1;

bool getFileContent(std::string fileName, std::vector<std::string> & vecOfStrs)
{

	// Open the File
	std::ifstream in(fileName.c_str());

	// Check if object is valid
	if (!in)
	{
		std::cerr << "Cannot open the File : " << fileName << std::endl;
		return false;
	}

	std::string str;
	// Read the next line from File untill it reaches the end.
	while (std::getline(in, str))
	{
		// Line contains string of length > 0 then save it in vector
		if (str.size() > 0)
			vecOfStrs.push_back(str);
	}
	//Close The File
	in.close();
	return true;
}

void Features::loadNames() {

	// Get the contents of file in a vector
	bool result = getFileContent("X-Folder/vehicles/#NAMES#.txt", Features::ini1);

	/*if (result)
	{
		// Print the vector contents
		for (std::string & line : Features::ini1)
			std::cout << line << std::endl;
	}*/
}

void Features::patchScript(int handle, int at) {
	globalHandle(handle).At(at).As<int>() = at;
}


int Features::bankAmount = 10000000;

void Features::deposit(int amount) { //In bank
	Any var0 = 312105838;
	/*UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, -1586170317, 1445302971, amount, 4);
	UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);
	UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, -1359375127, 537254313, amount, 1);
	UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);*/
	int iVar0;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_LAST_MP_CHAR"), &iVar0, 1);
	UNK3::_NETWORK_TRANSFER_WALLET_TO_BANK(iVar0, amount);
	UNK3::_NETWORK_SHOP_CASH_TRANSFER_SET_TELEMETRY_NONCE_SEED();
}

void Features::withdraw(int amount) { //In wallet
	/*Any var0 = 312105838;
	UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, -1586170317, 1445302971, amount, 1);
	UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);
	UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, -1359375127, 537254313, amount, 4);
	UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);*/
	int iVar0;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_LAST_MP_CHAR"), &iVar0, 1);
	UNK3::_NETWORK_TRANSFER_BANK_TO_WALLET(iVar0, amount);
	UNK3::_NETWORK_SHOP_CASH_TRANSFER_SET_TELEMETRY_NONCE_SEED();
}













void drawText(char * text, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool center)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 0);
	UI::SET_TEXT_OUTLINE();
	UI::SET_TEXT_EDGE(1, 0, 0, 0, 0);
	UI::_SET_TEXT_ENTRY("STRING");
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text);
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DRAW_TEXT(x, y);
}

int bannerTextRed = 255;
int bannerTextGreen = 255;
int bannerTextBlue = 255;
int bannerTextOpacity = 255;

int TunablePointer = 0x83DDD934;
bool Write_Global(int a_uiGlobalID, int a_uiValue)
{
	int Ptr = *(int*)((TunablePointer - 0x04) + (((a_uiGlobalID / 0x40000) & 0x3F) * 4));
	if (Ptr != 0)
	{
		*(int*)(Ptr + ((a_uiGlobalID % 0x40000) * 4)) = a_uiValue;
		return true;
	}
	return false;
}

int Read_Global(int a_uiGlobalID)
{
	int Ptr = *(int*)((TunablePointer - 0x04) + (((a_uiGlobalID / 0x40000) & 0x3F) * 4));
	if (Ptr != 0)
		return *(int*)(Ptr + ((a_uiGlobalID % 0x40000) * 4));
	return 0;
}

char *ItoS(int num)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%i", num);
	return buf;
}
char f_out[64];
char *x_fs(float c)
{
	sprintf(f_out, "%f", c);
	return f_out;
}

float ItoF(int input)
{
	float Output = *(float *)&input;
	return Output;
}

float Get3DDistance(Vector3 a, Vector3 b) {
	float x = pow((a.x - b.x), 2);
	float y = pow((a.y - b.y), 2);
	float z = pow((a.z - b.z), 2);
	return sqrt(x + y + z);
}

void Features::LoadInfoplayer(char* playerName, Player p) {

	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);

	RequestControlOfEnt(ped);

	int rp = globalHandle(1589747).At(p, 790).At(211).At(5).As<int>(); //F
	int lvl = globalHandle(1589747).At(p, 790).At(211).At(6).As<int>(); //F
	int money = globalHandle(1589747).At(p, 790).At(211).At(3).As<int>(); //F
	int kills = globalHandle(1589747).At(p, 790).At(211).At(28).As<int>(); //F
	int deaths = globalHandle(1589747).At(p, 790).At(211).At(29).As<int>(); //F
	float kd = globalHandle(1589747).At(p, 790).At(211).At(26).As<float>(); //F
	int isOtr = globalHandle(2423801).At(p, 413).At(200).As<int>(); //F

	int handle = globalHandle(1589747).At(p, 790).At(211).At(56).As<int>();
	int handle2 = globalHandle(1589747).At(p, 790).At(211).At(3).As<int>();
	int bankMoney = handle - handle2;

	//Coords
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p); //F
	Vector3 position;
	position = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
	char Coord_buf[100]; sprintf_s(Coord_buf, sizeof(Coord_buf), "Coords: %.3f, %.3f, %.3f", position.x, position.y, position.z, ENTITY::GET_ENTITY_HEADING(playerPed));
	//Health
	float health = ENTITY::GET_ENTITY_HEALTH(ped);
	float maxHealth = ENTITY::GET_ENTITY_MAX_HEALTH(ped);
	float healthPercent = health * 100 / maxHealth;
	ostringstream Health; Health << "Health:~s~ " << healthPercent;
	//Armor
	float armor = PED::GET_PED_ARMOUR(ped);
	float maxArmor = PLAYER::GET_PLAYER_MAX_ARMOUR(p);
	float armorPercent = armor * 100 / maxArmor;
	ostringstream Armor; Armor << "Armor:~s~ " << armorPercent;
	//Alive
	bool alive = !PED::IS_PED_DEAD_OR_DYING(ped, 1);
	char* aliveStatus;
	if (alive) aliveStatus = "~g~Yes"; else aliveStatus = "~r~No";
	ostringstream Alive; Alive << "Alive:~s~ " << aliveStatus;
	//Invincibility
	bool isInvincibility = !PLAYER::GET_PLAYER_INVINCIBLE(ped);
	char *Invincibilitytext = "";
	if (isInvincibility == true) { Invincibilitytext = "Invincibility: ~r~No"; }
	else { Invincibilitytext = "Invincibility: ~g~Yes"; }
	//InVehicle ?
	bool inVehicle = PED::IS_PED_IN_ANY_VEHICLE(ped, 0);
	ostringstream VehicleModel; VehicleModel << "Vehicle:~s~ ";
	ostringstream Speed; Speed << "Speed:~s~ ";
	ostringstream IsInAVehicle; IsInAVehicle << "In Vehicle:~s~ ";
	if (inVehicle) {
		IsInAVehicle << "~g~Yes";
		Hash vehHash = ENTITY::GET_ENTITY_MODEL(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
		VehicleModel << UI::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(vehHash));
		float vehSpeed = ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
		float vehSpeedConverted;
		vehSpeedConverted = round(vehSpeed * 1.6);
		Speed << vehSpeedConverted << " KM/H";
	}
	else {
		IsInAVehicle << "~r~No";
		float speed = round(ENTITY::GET_ENTITY_SPEED(ped) * 100) / 100;
		Speed << speed << " M/S";
		VehicleModel << "--------";
	}
	//WantedLevel
	ostringstream WantedLevel; WantedLevel << "Wanted Level:~s~ " << PLAYER::GET_PLAYER_WANTED_LEVEL(p);
	//Weapon
	ostringstream Weapon; Weapon << "Weapon: ~s~";
	Hash weaponHash;
	if (WEAPON::GET_CURRENT_PED_WEAPON(ped, &weaponHash, 1)) {
		char* weaponName;
		if (weaponHash == 2725352035) {
			weaponName = "Unarmed";
		}
		else if (weaponHash == 2578778090) {
			weaponName = "Knife";
		}
		else if (weaponHash == 0x678B81B1) {
			weaponName = "Nightstick";
		}
		else if (weaponHash == 0x4E875F73) {
			weaponName = "Hammer";
		}
		else if (weaponHash == 0x958A4A8F) {
			weaponName = "Bat";
		}
		else if (weaponHash == 0x440E4788) {
			weaponName = "GolfClub";
		}
		else if (weaponHash == 0x84BD7BFD) {
			weaponName = "Crowbar";
		}
		else if (weaponHash == 0x1B06D571) {
			weaponName = "Pistol";
		}
		else if (weaponHash == 0x5EF9FEC4) {
			weaponName = "Combat Pistol";
		}
		else if (weaponHash == 0x22D8FE39) {
			weaponName = "AP Pistol";
		}
		else if (weaponHash == 0x99AEEB3B) {
			weaponName = "Pistol 50";
		}
		else if (weaponHash == 0x13532244) {
			weaponName = "Micro SMG";
		}
		else if (weaponHash == 0x2BE6766B) {
			weaponName = "SMG";
		}
		else if (weaponHash == 0xEFE7E2DF) {
			weaponName = "Assault SMG";
		}
		else if (weaponHash == 0xBFEFFF6D) {
			weaponName = "Assault Riffle";
		}
		else if (weaponHash == 0x83BF0278) {
			weaponName = "Carbine Riffle";
		}
		else if (weaponHash == 0xAF113F99) {
			weaponName = "Advanced Riffle";
		}
		else if (weaponHash == 0x9D07F764) {
			weaponName = "MG";
		}
		else if (weaponHash == 0x7FD62962) {
			weaponName = "Combat MG";
		}
		else if (weaponHash == 0x1D073A89) {
			weaponName = "Pump Shotgun";
		}
		else if (weaponHash == 0x7846A318) {
			weaponName = "Sawed-Off Shotgun";
		}
		else if (weaponHash == 0xE284C527) {
			weaponName = "Assault Shotgun";
		}
		else if (weaponHash == 0x9D61E50F) {
			weaponName = "Bullpup Shotgun";
		}
		else if (weaponHash == 0x3656C8C1) {
			weaponName = "Stun Gun";
		}
		else if (weaponHash == 0x05FC3C11) {
			weaponName = "Sniper Rifle";
		}
		else if (weaponHash == 0x0C472FE2) {
			weaponName = "Heavy Sniper";
		}
		else if (weaponHash == 0xA284510B) {
			weaponName = "Grenade Launcher";
		}
		else if (weaponHash == 0x4DD2DC56) {
			weaponName = "Smoke Grenade Launcher";
		}
		else if (weaponHash == 0xB1CA77B1) {
			weaponName = "RPG";
		}
		else if (weaponHash == 0x42BF8A85) {
			weaponName = "Minigun";
		}
		else if (weaponHash == 0x93E220BD) {
			weaponName = "Grenade";
		}
		else if (weaponHash == 0x2C3731D9) {
			weaponName = "Sticky Bomb";
		}
		else if (weaponHash == 0xFDBC8A50) {
			weaponName = "Smoke Grenade";
		}
		else if (weaponHash == 0xA0973D5E) {
			weaponName = "BZGas";
		}
		else if (weaponHash == 0x24B17070) {
			weaponName = "Molotov";
		}
		else if (weaponHash == 0x060EC506) {
			weaponName = "Fire Extinguisher";
		}
		else if (weaponHash == 0x34A67B97) {
			weaponName = "Petrol Can";
		}
		else if (weaponHash == 0xFDBADCED) {
			weaponName = "Digital scanner";
		}
		else if (weaponHash == 0x88C78EB7) {
			weaponName = "Briefcase";
		}
		else if (weaponHash == 0x23C9F95C) {
			weaponName = "Ball";
		}
		else if (weaponHash == 0x497FACC3) {
			weaponName = "Flare";
		}
		else if (weaponHash == 0xF9E6AA4B) {
			weaponName = "Bottle";
		}
		else if (weaponHash == 0x61012683) {
			weaponName = "Gusenberg";
		}
		else if (weaponHash == 0xC0A3098D) {
			weaponName = "Special Carabine";
		}
		else if (weaponHash == 0xD205520E) {
			weaponName = "Heavy Pistol";
		}
		else if (weaponHash == 0xBFD21232) {
			weaponName = "SNS Pistol";
		}
		else if (weaponHash == 0x7F229F94) {
			weaponName = "Bullpup Rifle";
		}
		else if (weaponHash == 0x92A27487) {
			weaponName = "Dagger";
		}
		else if (weaponHash == 0x083839C4) {
			weaponName = "Vintage Pistol";
		}
		else if (weaponHash == 0x7F7497E5) {
			weaponName = "Firework";
		}
		else if (weaponHash == 0xA89CB99E) {
			weaponName = "Musket";
		}
		else if (weaponHash == 0x3AABBBAA) {
			weaponName = "Heavy Shotgun";
		}
		else if (weaponHash == 0xC734385A) {
			weaponName = "Marksman Rifle";
		}
		else if (weaponHash == 0x63AB0442) {
			weaponName = "Homing Launcher";
		}
		else if (weaponHash == 0xAB564B93) {
			weaponName = "Proximity Mine";
		}
		else if (weaponHash == 0x787F0BB) {
			weaponName = "Snowball";
		}
		else if (weaponHash == 0x47757124) {
			weaponName = "Flare Gun";
		}
		else if (weaponHash == 0xE232C28C) {
			weaponName = "Garbage Bag";
		}
		else if (weaponHash == 0xD04C944D) {
			weaponName = "Handcuffs";
		}
		else if (weaponHash == 0x0A3D4D34) {
			weaponName = "Combat PDW";
		}
		else if (weaponHash == 0xDC4DB296) {
			weaponName = "Marksman Pistol";
		}
		else if (weaponHash == 0xD8DF3C3C) {
			weaponName = "Brass Knuckles";
		}
		else if (weaponHash == 0x6D544C99) {
			weaponName = "Railgun";
		}
		else {
			weaponName = "Unarmed";
		}
		Weapon << weaponName;


	}
	else Weapon << "Unarmed";
	Vector3 myCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(ped, 1);
	ostringstream Zone; Zone << "Zone: ~s~" << UI::_GET_LABEL_TEXT(ZONE::GET_NAME_OF_ZONE(coords.x, coords.y, coords.z));
	Hash streetName, crossingRoad;
	PATHFIND::GET_STREET_NAME_AT_COORD(coords.x, coords.y, coords.z, &streetName, &crossingRoad);
	ostringstream Street; Street << "Street: ~s~" << UI::GET_STREET_NAME_FROM_HASH_KEY(streetName);
	float distance = Get3DDistance(coords, myCoords);
	ostringstream Distance; Distance << "Distance: ~s~";

	if (distance > 1000) {
		distance = round((distance / 1000) * 100) / 100;
		Distance << distance << " Kilometers";
	}
	else {
		distance = round(distance * 1000) / 100;
		Distance << distance << " Meters";
	}
	//IP
	struct IPAddress
	{
		union
		{
			struct
			{
				std::uint8_t four;
				std::uint8_t three;
				std::uint8_t two;
				std::uint8_t one;
			} fields;

			std::uint32_t packed;
		};
	};

	std::string port_str;
	char ipBuf[32] = {};
	static auto IPadre = (std::uintptr_t(*)(int))(Memory::pattern("40 53 48 83 EC 20 33 DB 38 1D ? ? ? ? 74 1C").count(1).get(0).get<void>(0));
	auto ipadre_ = IPadre(p);

	if (!NETWORK::NETWORK_IS_PLAYER_CONNECTED(p)) {

		for (int i = 0; i < 3; i++)
		{
			if (ipadre_)
			{
				auto faggot = *(uintptr_t*)(ipadre_ + 0x10b8);
				if (faggot)
				{


					auto ip = (BYTE*)(faggot + 0x44);
					std::snprintf(ipBuf, sizeof(ipBuf) - 1, "~w~IP: ~r~Hidden", i);
				}
			}

		}
		port_str = "~r~Hidden";

	}
	else {

		if (ipadre_)
		{
			auto faggot = *(uintptr_t*)(ipadre_ + 0x10b8);
			if (faggot)
			{
				auto ip = (BYTE*)(faggot + 0x44);
				std::snprintf(ipBuf, sizeof(ipBuf) - 1, "~w~IP: %u.%u.%u.%u", ip[3], ip[2], ip[1], *ip);

			}
		}

		auto port = reinterpret_cast<uint16_t*>(ipadre_ + 0x38);
		char buffer[5 + 1];
		std::snprintf(buffer, sizeof(buffer), "%i", *port);
		port_str = buffer;

	}

	std::string sotr;
	if (isOtr) {
		sotr = "~g~Yes";
	}
	else {
		sotr = "~r~No";
	}

	char* rockstarID;
	int NETWORK_HANDLE[76];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(p, &NETWORK_HANDLE[0], 13);
	if (NETWORK::NETWORK_IS_HANDLE_VALID(&NETWORK_HANDLE[0], 13)) {
		rockstarID = NETWORK::NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(&NETWORK_HANDLE[0]);
	}
	else {
		rockstarID = "~r~Unknown";
	}

	//std::string isModder = "~r~No";
	
	/*DWORD playerPtr = Hooking::get_player_address(p);
	bool is_in_godmode = Memory::get_value<bool>({ playerPtr, 0x189 });

	if (is_in_godmode || bankMoney > 30000000 || money > 30000000) {
		isModder = "~g~Yes";
	}
	else {
		isModder = "~r~No";
	}*/

	ostringstream totalrp; totalrp << "RP:~s~ " << rp;
	ostringstream rplevel; rplevel << "Level:~s~ " << lvl;
	ostringstream richness; richness << "Wallet Money:~s~ " << money;
	ostringstream killer; killer << "Kills:~s~ " << kills;
	ostringstream yoink; yoink << "Deaths:~s~ " << deaths;
	ostringstream clingclang; clingclang << "K/D:~s~ " << kd;
	ostringstream tiptoe; tiptoe << "Off radar:~s~ " << sotr;
	ostringstream nigger; nigger << "Banked Money:~s~ " << bankMoney;
	ostringstream kys; kys << "Port:~s~ " << port_str;
	ostringstream ridkek; ridkek << "Rockstar ID:~s~ " << rockstarID;
	//ostringstream NigNog; NigNog << "Modder:~s~ " << isModder;

	Menu::PlayerInfoTitle(playerName);
	Menu::PlayerInfoLine((char*)Health.str().c_str(), 0);
	Menu::PlayerInfoLine((char*)Armor.str().c_str(), 1);
	Menu::PlayerInfoLine((char*)Alive.str().c_str(), 2);
	Menu::PlayerInfoLine((char*)IsInAVehicle.str().c_str(), 3);
	Menu::PlayerInfoLine((char*)VehicleModel.str().c_str(), 4);
	Menu::PlayerInfoLine((char*)Speed.str().c_str(), 5);
	Menu::PlayerInfoLine((char*)WantedLevel.str().c_str(), 6);
	Menu::PlayerInfoLine((char*)Weapon.str().c_str(), 7);
	Menu::PlayerInfoLine((char*)Zone.str().c_str(), 8);
	Menu::PlayerInfoLine((char*)Street.str().c_str(), 9);
	Menu::PlayerInfoLine((char*)Distance.str().c_str(), 10);
	Menu::PlayerInfoLine(ipBuf, 11);
	Menu::PlayerInfoLine((char*)kys.str().c_str(), 12);
	Menu::PlayerInfoLine(Coord_buf, 13);
	Menu::PlayerInfoLine(Invincibilitytext, 14);
	Menu::PlayerInfoLine((char*)totalrp.str().c_str(), 15);
	Menu::PlayerInfoLine((char*)rplevel.str().c_str(), 16);
	Menu::PlayerInfoLine((char*)richness.str().c_str(), 17);
	Menu::PlayerInfoLine((char*)nigger.str().c_str(), 18);
	Menu::PlayerInfoLine((char*)killer.str().c_str(), 19);
	Menu::PlayerInfoLine((char*)yoink.str().c_str(), 20);
	Menu::PlayerInfoLine((char*)clingclang.str().c_str(), 21);
	Menu::PlayerInfoLine((char*)tiptoe.str().c_str(), 22);
	Menu::PlayerInfoLine((char*)ridkek.str().c_str(), 23);
	//Menu::PlayerInfoLine((char*)NigNog.str().c_str(), 21);
}

void Features::grabDatIP(Player p) {
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	char ipBuf[32] = {};
	static auto IPadre = (std::uintptr_t(*)(int))(Memory::pattern("40 53 48 83 EC 20 33 DB 38 1D ? ? ? ? 74 1C").count(1).get(0).get<void>(0));
	auto ipadre_ = IPadre(p);
	std::string port_str;

	if (NETWORK::NETWORK_IS_PLAYER_CONNECTED(p)) {
		if (ipadre_) {
			auto faggot = *(uintptr_t*)(ipadre_ + 0x10b8);
			if (faggot) {
				auto ip = (BYTE*)(faggot + 0x44);
				std::snprintf(ipBuf, sizeof(ipBuf) - 1, "%u.%u.%u.%u", ip[3], ip[2], ip[1], *ip);
			}
		}
		auto port = reinterpret_cast<uint16_t*>(ipadre_ + 0x38);
		char buffer[5 + 1];
		std::snprintf(buffer, sizeof(buffer), "%i", *port);
		port_str = buffer;
	}
	else {
		std::snprintf(ipBuf, sizeof(ipBuf) - 1, "Unknown");
		port_str = "Unknown";
	}
	std::string content = (std::string)PLAYER::GET_PLAYER_NAME(p) + ": " + ipBuf + ": " + port_str;
	Features::write2("X-Folder/IP.txt", content);
}

void Features::flushMoney() {
	Any var0 = 312105838;
	int money = globalHandle(1589747).At(PLAYER::PLAYER_ID(), 790).At(211).At(3).As<int>();
	while (money > 14999999) {
		UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, -1359375127, 537254313, 15000000, Features::toBank ? 4 : 1);
		UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);
	}
	while (money < 15000000) {
		UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, -1359375127, 537254313, money, Features::toBank ? 4 : 1);
		UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);
	}
}

bool dragonkicker = false;
void kickDragonius() {
	for (int i = 0; i < 33; i++) {
		if (PLAYER::GET_PLAYER_NAME(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)) == "_Dragon_Master_") {
			unsigned int Bit = (1 << i);
			uint64_t kickDragon[4] = { 999090520, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 0, 0 };
			Hooking::trigger_script_event(1, kickDragon, 4, Bit);
		}
	}
}

void Features::saveToINI() {
	std::string config = "X-Folder/title/config.ini";
	INI::WriteString(config, Menu::Settings::ytdtheme, "theme", "image");
	INI::WriteString(config, Menu::Settings::menuname, "theme", "name");
	INI::WriteRGBA(config, Menu::Settings::scroller, "scroller");
	INI::WriteFloat(config, Menu::Settings::menuX, "theme", "menux");
	INI::WriteInt(config, Menu::Settings::keyPressDelay2, "delay", "scroll");
	INI::WriteInt(config, Menu::Settings::keyPressDelay3, "delay", "int");
	INI::WriteString(config, Menu::Settings::toggleYTD, "toggle", "ytd");
	INI::WriteString(config, Menu::Settings::toggleON, "toggle", "on");
	INI::WriteString(config, Menu::Settings::toggleOFF, "toggle", "off");
	INI::WriteRGBA(config, { Menu::Settings::optionText.r, Menu::Settings::optionText.g, Menu::Settings::optionText.b, Menu::Settings::optionText.a }, "text");
	INI::WriteInt(config, Menu::Settings::optionText.f, "text", "F");
	INI::WriteRGBA(config, Menu::Settings::infocolor, "info");
	INI::WriteBool(config, Menu::Settings::showGlobe, "theme", "globe");
	INI::WriteBool(config, Menu::Settings::lightning, "theme", "lightning");
	INI::WriteBool(config, Menu::Settings::evolve, "theme", "evolve");
    INI::WriteFloat(config, Menu::Settings::menuY, "theme", "menuy");
	INI::WriteBool(config, Features::show_tips, "theme", "instructions");
	INI::WriteBool(config, Menu::Settings::phantom, "theme", "phantom");
	INI::WriteFloat(config, Menu::Settings::menuWidth, "theme", "menuw");
	INI::WriteBool(config, Menu::Settings::enable_scrollbar, "theme", "scrollbar");
	INI::WriteBool(config, Menu::Settings::c_enable, "theme", "custom");
	INI::WriteInt(config, Menu::Settings::c_frames, "theme", "frames");
	INI::WriteString(config, Menu::Settings::c_name, "theme", "file");
	INI::WriteString(config, Menu::Settings::c_pict, "theme", "texture");
	INI::WriteBool(config, Menu::Settings::c_animation, "theme", "animated");
	INI::WriteBool(config, Menu::Settings::enable_smooth, "scroller", "smooth");
	INI::WriteFloat(config, Menu::Settings::ScrollerSpeed, "delay", "smooth");
	INI::WriteInt(config, Menu::Settings::openKey, "keys", "open");
	INI::WriteBool(config, Menu::Settings::city, "theme", "city");
	//INI::WriteString(config, Menu::Settings::menuend, "theme", "end");
}

void Features::loadFromINI() {
	std::string config = "X-Folder/title/config.ini";
	Menu::Settings::c_enable = INI::GetBool(config, "theme", "custom");
	Menu::Settings::c_frames = INI::GetInt(config, "theme", "frames");
	Menu::Settings::c_name = INI::GetString(config, "theme", "file");
	Menu::Settings::c_pict = INI::GetString(config, "theme", "texture");
	Menu::Settings::c_animation = INI::GetBool(config, "theme", "animated");
	Menu::Settings::ytdtheme = INI::GetChar(config, "theme", "image");
	Menu::Settings::menuname = INI::GetChar(config, "theme", "name");
	Menu::Settings::scroller = INI::GetRGBA(config, "scroller");
	Menu::Settings::enable_scrollbar = INI::GetBool(config, "theme", "scrollbar");
	Menu::Settings::menuX = INI::GetFloat(config, "theme", "menux");
	Menu::Settings::keyPressDelay2 = INI::GetInt(config, "delay", "scroll");
	Menu::Settings::keyPressDelay3 = INI::GetInt(config, "delay", "int");
	Menu::Settings::toggleYTD = INI::GetString(config, "toggle", "ytd");
	Menu::Settings::toggleON = INI::GetString(config, "toggle", "on");
	Menu::Settings::toggleOFF = INI::GetString(config, "toggle", "off");
	Menu::Settings::optionText.f = INI::GetInt(config, "text", "F");
	Menu::Settings::optionText.r = INI::GetInt(config, "text", "R");
	Menu::Settings::optionText.g = INI::GetInt(config, "text", "G");
	Menu::Settings::optionText.b = INI::GetInt(config, "text", "B");
	Menu::Settings::optionText.a = INI::GetInt(config, "text", "A");
	Menu::Settings::infocolor = INI::GetRGBA(config, "info");
	Menu::Settings::showGlobe = INI::GetBool(config, "theme", "globe");
	Menu::Settings::lightning = INI::GetBool(config, "theme", "lightning");
	Menu::Settings::evolve = INI::GetBool(config, "theme", "evolve");
	Features::show_tips = INI::GetBool(config, "theme", "instructions");
	Menu::Settings::phantom = INI::GetBool(config, "theme", "phantom");
	Menu::Settings::menuWidth = INI::GetFloat(config, "theme", "menuw");
	Menu::Settings::enable_smooth = INI::GetBool(config, "scroller", "smooth");
	Menu::Settings::ScrollerSpeed = INI::GetFloat(config, "delay", "smooth");
	Menu::Settings::openKey = INI::GetInt(config, "keys", "open");
	Menu::Settings::city = INI::GetBool(config, "theme", "city");
	//Menu::Settings::menuY = INI::GetBool(config, "theme", "menuy");
	//Menu::Settings::menuend = INI::GetString(config, "theme", "end");
}

bool Features::catgun = false;
void Features::catGun()
{
	if (is_ped_shooting(PLAYER::PLAYER_PED_ID()))
	{
		DWORD vehmodel = 1462895032;
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);		

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(PLAYER::PLAYER_PED_ID());
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(PLAYER::PLAYER_PED_ID(), 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = OBJECT::CREATE_OBJECT(vehmodel, startCoords.x, startCoords.y, startCoords.z, 1, 1, 1);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(vehmodel);
	}
}


bool Features::GravGun = false;

void GET_CAMERA_DIRECTION(float *dirX, float *dirY, float *dirZ)
{
	float tX, tZ, num;
	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);

	tZ = rot.z * 0.0174532924f;
	tX = rot.x * 0.0174532924f;
	num = abs(cos(tX));

	*dirX = (-sin(tZ)) * num;
	*dirY = (cos(tZ)) * num;
	*dirZ = sin(tX);
}

int entdistance = 4;
bool disallowNewEntity;
Entity gravityentity;
Entity shotentity;
Vehicle gravityvehicle;
//bool grav_target_locked;


float cycle() {
	float ss = 0.0f;
	while (true) {
		ss += 1.0f;
		if (ss > 4.0f) { ss = 0.0f; }
		return ss;
	}
	return 0.0f;
}

float distanceIndex = 10.0f;
void Features::GravGunFunction(bool toggle)
{
	/*Entity EntityTarget;
	DWORD equippedWeapon;
	WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &equippedWeapon, 1);
	Player tempPed = PLAYER::PLAYER_ID();
	Vector3 rot = CAM::_GET_GAMEPLAY_CAM_ROT(0);
	Vector3 dir = rot_to_direction(&rot);
	Vector3 camPosition = CAM::_GET_GAMEPLAY_CAM_COORDS();
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	float spawnDistance = get_distance(&camPosition, &playerPosition);
	spawnDistance += 9;
	Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));

	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
	{
		grav_target_locked = true;
		PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);

	}
	if (grav_target_locked)
	{
		if (GetAsyncKeyState(VK_RBUTTON))
		{
			Vector3 EntityTargetPos = ENTITY::GET_ENTITY_COORDS(EntityTarget, 1);
			ENTITY::SET_ENTITY_HAS_GRAVITY(EntityTarget, 1);
			ENTITY::SET_ENTITY_DYNAMIC(EntityTarget, 1);
			Vector3 Rotation = multiply(&ENTITY::GET_ENTITY_ROTATION(EntityTarget, 1), cycle());

			PLAYER::DISABLE_PLAYER_FIRING(tempPed, true);
			if (ENTITY::IS_ENTITY_A_PED(EntityTarget) && PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1))
			{
				EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
			}
			RequestControlOfEnt(EntityTarget);

			if (ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget))
			{
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(EntityTarget, spawnPosition.x, spawnPosition.y, spawnPosition.z, 1, 1, 1);
			}
			Rotation = multiply(&Rotation, cycle());
			ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, EntityTargetPos.x, EntityTargetPos.y, EntityTargetPos.z, Rotation.x, Rotation.y, Rotation.z, 0, 0, 1, 0, 0, 1);

			if (GetAsyncKeyState(VK_LBUTTON))
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 10000.0f, dir.y * 10000.0f, dir.z * 10000.0f, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);
				grav_target_locked = false;
				EntityTarget = NULL;
				PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
			}
		}
	}*/
	Entity EntityTarget;
	DWORD equippedWeapon;
	
	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	Vector3 dir = rot_to_direction(&rot);
	Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	float spawnDistance = get_distance(&camPosition, &playerPosition);
	spawnDistance += distanceIndex;
	Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));

	Player tempPed = PLAYER::PLAYER_ID();
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
		{
			grav_target_locked = true;
			PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
		}
		if (grav_target_locked)
		{
			//PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(tempPed, &EntityTarget);
			if (GetAsyncKeyState(VK_RBUTTON))
			{
				if (distanceIndex > 2.0f) {
					distanceIndex -= 0.04f;
				}
				ENTITY::SET_ENTITY_HAS_GRAVITY(EntityTarget, 1);
				ENTITY::SET_ENTITY_DYNAMIC(EntityTarget, 1);
				//PLAYER::DISABLE_PLAYER_FIRING(tempPed, true);
				if (ENTITY::IS_ENTITY_A_PED(EntityTarget) && PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1))
				{
					EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
				}

				RequestControlOfEnt(EntityTarget);

				if (ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget))
				{
					ENTITY::SET_ENTITY_COORDS_NO_OFFSET(EntityTarget, spawnPosition.x, spawnPosition.y, spawnPosition.z, 0, 0, 0);
				}
				ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 0, rot.x, rot.y, rot.z, spawnPosition.x, spawnPosition.y, spawnPosition.z, 0, 0, 1, 0, 0, 1);

				if (GetAsyncKeyState(VK_LBUTTON))
				{
					distanceIndex = 10.0f;
					ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));
					ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 10000.0f, dir.y * 10000.0f, dir.z * 10000.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 0, 1);
					grav_target_locked = false;
					EntityTarget = NULL;
					PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
				}
			}
			else {
				distanceIndex = 10.0f;
			}
		}
		else {
			distanceIndex = 10.0f;
		}
}

bool Features::ujump = false;
void Features::ultraJump() {
	Player playerPed = PLAYER::PLAYER_PED_ID();
	GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(playerPed);
	WEAPON::REMOVE_WEAPON_FROM_PED(playerPed, GAMEPLAY::GET_HASH_KEY("GADGET_PARACHUTE"));
	if (PED::IS_PED_JUMPING(playerPed) && IsKeyPressed(VK_SPACE))
	{
		PED::SET_PED_RAGDOLL_ON_COLLISION(PLAYER::PLAYER_PED_ID(), false);
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), false);
		PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(playerPed, true, 0, 0, 5, 0, 0, 0, true, true, true, true, false, true);
	}
	else {
		PED::SET_PED_RAGDOLL_ON_COLLISION(PLAYER::PLAYER_PED_ID(), true);
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), true);
		PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), true);
	}
}

void Features::blamee(Player p) {
	Player victim = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	Hooking::ownedExplosionBypass(true);
	for (int i = 0; i < 33; i++) {
		Player pl = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
		Vector3 crd = coordsOf(pl);
		if (pl != victim) {
			//FIRE::ADD_OWNED_EXPLOSION(victim, crd.x, crd.y, crd.z, EXP_TAG_GRENADE, 5.0f, true, false, 0.1f);
			Hooking::add_owned_explosion(victim, crd, EXP_TAG_GRENADE, 5.0f, true, false, 0.1f);
		}
	}
	Hooking::ownedExplosionBypass(false);
}

void Features::g_hud() {
	Hooking::ownedExplosionBypass(true);
	for (int i = 0; i < 33; i++) {
		Player nigNog = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
		for (int j = 0; j < 33; j++) {
			Vector3 crd = coordsOf(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(j));
			if (Features::exclude(i)) {
				//FIRE::ADD_OWNED_EXPLOSION(nigNog, crd.x, crd.y, crd.z, EXP_TAG_GRENADE, 5.0f, true, false, 0.1f);
				Hooking::add_owned_explosion(nigNog, crd, EXP_TAG_GRENADE, 5.0f, true, false, 0.1f);
			}						
		}
	}
	Hooking::ownedExplosionBypass(false);
}


//DO IT!
void Features::blameBy(Player killer, Player victim) {
	Ped p1 = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(killer);
	Ped p2 = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(victim);
	Hooking::ownedExplosionBypass(true);
	Vector3 crd = coordsOf(p2);
	//FIRE::ADD_OWNED_EXPLOSION(p1, crd.x, crd.y, crd.z, EXP_TAG_GRENADE, 5.0f, true, false, 0.1f);
	Hooking::add_owned_explosion(p1, crd, EXP_TAG_GRENADE, 5.0f, true, false, 0.1f);
	Hooking::ownedExplosionBypass(false);
}

bool Features::blameBool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

bool Features::newEventBlocker() {
	uint64_t var0[10];
	bool var1 = Hooking::GED(1, 0, var0, 10);
	return var1;
}

bool Features::antiBlame = false;
void Features::blameProtex() {
	NETWORK::NETWORK_SET_FRIENDLY_FIRE_OPTION(true);
	PED::SET_CAN_ATTACK_FRIENDLY(PLAYER::PLAYER_PED_ID(), true, true);
}

void Features::giveWanted(Player p) {
	Ped playa = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	const int maxPeds = 10;
	Ped ClonedPed[maxPeds];
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vector3 coords = coordsOf(playa);
	Hooking::ownedExplosionBypass(true);
	for (int i = 0; i < maxPeds; i++)
	{
		ClonedPed[i] = PED::CLONE_PED(playa, ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()), 1, 1);
		ENTITY::SET_ENTITY_COORDS(ClonedPed[i], coords.x, coords.y, coords.z + 25, 0, 0, 0, 1);
		PED::SET_PED_AS_COP(ClonedPed[i], true);
		WAIT(20);
		Vector3 cloneCoord = ENTITY::GET_ENTITY_COORDS(ClonedPed[i], 0);
		ENTITY::SET_ENTITY_VISIBLE(ClonedPed[i], false);
		//FIRE::ADD_OWNED_EXPLOSION(playa, cloneCoord.x, cloneCoord.y, cloneCoord.z, 9, 5.0f, 0, 1, 0.0f);
		Hooking::add_owned_explosion(playa, cloneCoord, 9, 5.0f, 0, 1, 0.0f);
		WAIT(20);
		PED::DELETE_PED(&ClonedPed[i]);
	}
	Hooking::ownedExplosionBypass(false);
}

int fake_rank = 0;
void Features::spoofRank(int fakerank) {
	globalHandle(1589747).At(PLAYER::PLAYER_ID(), 790).At(211).At(6).As<int>() = fakerank;
	fake_rank = fakerank;
}

bool Features::useFakeRank = false;
void Features::fakeRank() {
	globalHandle(1589747).At(PLAYER::PLAYER_ID(), 790).At(211).At(6).As<int>() = fake_rank;
}

bool Features::kkkbool = false;
void Features::ktest() {
	Ped killa = PED::GET_PED_SOURCE_OF_DEATH(PLAYER::PLAYER_PED_ID());
	if (killa != NULL && killa != PLAYER::PLAYER_PED_ID()) {
		//ostringstream heil_hitler; heil_hitler << "Killer:~s~ " << killa;
		//notifyMap((char*)heil_hitler.str().c_str());
		Vector3 coords = coordsOf(killa);
		//FIRE::ADD_OWNED_EXPLOSION(killa, crd.x, crd.y, crd.z, EXP_TAG_GRENADE, 5.0f, true, false, 0.1f);
		//Hooking::add_owned_explosion(killa, crd, EXP_TAG_GRENADE, 5.0f, true, false, 0.1f);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y, coords.z + 5, coords.x, coords.y, coords.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), PLAYER::PLAYER_PED_ID(), 1, 1, 100);
		killa = NULL;
	}
}

bool Features::karmaOn = false;
void Features::karmaa() {
	Entity target;
	Ped local = PLAYER::PLAYER_PED_ID();
	for (int i = 0; i < 33; i++) {
		Ped player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
		if (player != PLAYER::PLAYER_PED_ID()) {
			PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(player, &target);
			if (target == PLAYER::PLAYER_ID()) {
				notifyMap(std::to_string(player));
			}
		}
	}
}

int Features::remoteLevel = 0;
bool Features::remoterp[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::remoteRP(Player p) {
	globalHandle(1589747).At(p, 790).At(211).At(6).As<int>() = remoteLevel;
}

void Features::money(Player p) {
	unsigned int Bit = (1 << p);
	Ped q = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	uint64_t args[34] = { 4294967295, q, 0, 4750, 0, 254804227, 2099511296, 2112084576, 2112093544, 3962174592, 2093721054, 2112109984, 2099537076, 0, 2112109992, 2093716680, 32, 2122755136, 892810276, 0, 519042345, 519042000, 0, 1, 2097082519, 0, 2122755136, 519042000, 2122755136, 3485527744, 2162720, 3962862080, 2090873791, 4750 };
	Hooking::trigger_script_event(1, args, 34, Bit);
}

bool coordsSet = false;
bool Features::portalGunOn = false;
void Features::portalGun() {
	Vector3 waypointCoords = get_blip_marker();
	Vector3 portalCoords;
	if (is_ped_shooting(PLAYER::PLAYER_PED_ID()) && !coordsSet) {
		WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &portalCoords);
		coordsSet = true;
	}
	if (coordsSet && get_distance(&coordsOf(PLAYER::PLAYER_PED_ID()), &portalCoords) < 3) {
		teleport_to_coords(PLAYER::PLAYER_PED_ID(), waypointCoords);
		coordsSet = false;
	}
}



void Features::NameChanger()
{
	std::string str;
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", "", "", "", "", 21);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) str = "";
	str = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
	if (str != "!!INVALID!!" && str != "")
	{
		Features::setplayername(str);
	}
}

bool Features::playerKarma[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::playerKarmaa(Player p) {
	Ped killa = PED::GET_PED_SOURCE_OF_DEATH(p);
	if (killa != NULL && killa != PLAYER::PLAYER_PED_ID() && killa != PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p)) {
		Vector3 coords = coordsOf(killa);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y, coords.z + 5, coords.x, coords.y, coords.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), PLAYER::PLAYER_PED_ID(), 1, 1, 100);
		killa = NULL;
	}
}

bool Features::sync = false;
void Features::syncTime() {
	time_t now = time(0);
	tm t;
	localtime_s(&t, &now);
	Hooking::settime(t.tm_hour, t.tm_min, t.tm_sec);
}

bool Features::pauseTimeBool = false;
void Features::pauseTime(bool toggle)
{
	TIME::PAUSE_CLOCK(toggle);
}

bool Features::joinMsg = false;
void Features::joinMessage() {
	for (int i = 0; i < 33; i++) {
		if (!NETWORK::NETWORK_IS_PLAYER_CONNECTED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)) && ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
			notifyMap("%s is joining", PLAYER::GET_PLAYER_NAME(i));
		}
	}
}

bool Features::srank1 = false;
void Features::specialRank1() {
	if ((timeGetTime() - Features::TimePD17) > 100) {
		fake_rank++;
		Features::TimePD17 = timeGetTime();
	}
}

bool Features::srank2 = false;
void Features::specialRank2() {
	if ((timeGetTime() - Features::TimePD17) > 100) {
		fake_rank *= -1;
		Features::TimePD17 = timeGetTime();
	}
}

bool Features::invis3 = false;
void Features::Invis3(bool toggle) {
	NETWORK::SET_PLAYER_VISIBLE_LOCALLY(PLAYER::PLAYER_PED_ID(), true);
	NETWORK::_NETWORK_SET_ENTITY_VISIBLE_TO_NETWORK(PLAYER::PLAYER_PED_ID(), invis3 ? false : true);
	NETWORK::SET_PLAYER_VISIBLE_LOCALLY(PLAYER::PLAYER_PED_ID(), true);
}

long long Features::droppedMoneyCounter = 0;
long long Features::stealthMoneyCounter = 0;
bool Features::showAmount = false;
bool Features::showAmount2 = false;
int Features::danger = -1;
void Features::showDroppedMoney() {
	if (stealthMoneyCounter < 500000001 || droppedMoneyCounter < 2000001) {
		danger = -1;
	}
	else if ((stealthMoneyCounter > 500000000 && droppedMoneyCounter < 1000000001) || (droppedMoneyCounter > 2000000 && droppedMoneyCounter < 4000001)) {
		danger = 0;
	}
	else if (stealthMoneyCounter > 1000000000 || droppedMoneyCounter > 4000000) {
		danger = 1;
	}

	/*if (showAmount && showAmount2) {
		int amount = Features::droppedMoneyCounter + Features::stealthMoneyCounter;
		if (stealthMoneyCounter < 500000001 || droppedMoneyCounter < 2000001) {
			ostringstream droppppppp;
			droppppppp << "~g~Cheated money: " << amount << "$";
			notifyBottom((char*)droppppppp.str().c_str());
		}
		else if ((stealthMoneyCounter > 500000000 && droppedMoneyCounter < 1000000001) || (droppedMoneyCounter > 2000000 && droppedMoneyCounter < 4000001)) {
			ostringstream droppppppp;
			droppppppp << "~y~Cheated money: " << amount << "$";
			notifyBottom((char*)droppppppp.str().c_str());
		}
		else if (stealthMoneyCounter > 1000000000 || droppedMoneyCounter > 4000000) {
			ostringstream droppppppp;
			droppppppp << "~r~Cheated money: " << amount << "$";
			notifyBottom((char*)droppppppp.str().c_str());
		}
	}*/
	else if (showAmount) {
		ostringstream droppppppp;
		if (droppedMoneyCounter < 2000001) {
			droppppppp << "~g~Dropped money: " << Features::droppedMoneyCounter << "$";
			notifyBottom(droppppppp.str());
		}
		else if (droppedMoneyCounter > 2000000 && droppedMoneyCounter < 4000001) {
			droppppppp << "~y~Dropped money: " << Features::droppedMoneyCounter << "$";
			notifyBottom(droppppppp.str());
		}
		else if (droppedMoneyCounter > 4000000) {
			droppppppp << "~r~Dropped money: " << Features::droppedMoneyCounter << "$";
			notifyBottom(droppppppp.str());
		}
	}
	else if (showAmount2) {
		ostringstream droppppppp;
		if (stealthMoneyCounter < 500000001) {
			droppppppp << "~g~Stealthed money: " << Features::stealthMoneyCounter << "$";
			notifyBottom(droppppppp.str());
		}
		else if (stealthMoneyCounter > 500000000 && stealthMoneyCounter < 1000000001) {
			droppppppp << "~y~Stealthed money: " << Features::stealthMoneyCounter << "$";
			notifyBottom(droppppppp.str());
		}
		else if (stealthMoneyCounter > 1000000000) {
			droppppppp << "~r~Stealthed money: " << Features::stealthMoneyCounter << "$";
			notifyBottom(droppppppp.str());
		}
	}
}

bool Features::guntestbool = false;
void Features::gunAimTest() {
	Entity targetVeh;
	Entity targetBumper;
	Player ped = PLAYER::PLAYER_PED_ID();
	Player player = PLAYER::PLAYER_ID();
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(player, &targetVeh)) {
		targetBumper = ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(targetVeh, "bumper_f");
		if (targetVeh == targetBumper) {
			notifyMap("SS");
		}
	}
}

bool Features::mgun = false;
void Features::Mcgun()
{
	float Tmp[6];
	WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), (Vector3*)Tmp);
	if (Tmp[0] != 0 || Tmp[2] != 0 || Tmp[4] != 0) {
		ENTITY::FREEZE_ENTITY_POSITION(OBJECT::CREATE_OBJECT(4146332269, Tmp[0], Tmp[2], Tmp[4], 1, 0, 0), 1);
	}
}

DWORD featureWeaponVehShootLastTime = 0;

bool Features::ShootMini = false;
void Features::ShootMiniGun(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	bool bSelect = GetAsyncKeyState(Features::keyz[Features::keyIndex]); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_PLAYER_BULLET");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}
bool Features::ShootBall = false;
void Features::ShootBalls(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	bool bSelect = GetAsyncKeyState(Features::keyz[Features::keyIndex]); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_BALL");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();


	}
}

bool Features::ShootT = false;
void Features::ShootTanks(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	bool bSelect = GetAsyncKeyState(Features::keyz[Features::keyIndex]); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_FIREWORK");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}
bool Features::ShootR = false;
void Features::ShootRocket(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	bool bSelect = GetAsyncKeyState(Features::keyz[Features::keyIndex]); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_VEHICLE_ROCKET");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}




bool Features::carRPG = false;
void Features::shootRPGCar(bool toggle) {
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;

	bool bSelect = GetAsyncKeyState(Features::keyz[Features::keyIndex]); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_VEHICLE_ROCKET");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 0, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 0, weaponAssetRocket, playerPed, 1, 0, -1.0);

		featureWeaponVehShootLastTime = GetTickCount();


	}
}

bool Features::llcar = false;
void Features::LLCar(bool toggle) {
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;

	bool bSelect = GetAsyncKeyState(Features::keyz[Features::keyIndex]); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_ENEMY_LASER");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 0, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 0, weaponAssetRocket, playerPed, 1, 0, -1.0);

		featureWeaponVehShootLastTime = GetTickCount();


	}
}

bool Features::ShootTankR = false;
void Features::ShootTankRounds(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	bool bSelect = GetAsyncKeyState(Features::keyz[Features::keyIndex]); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_TANK");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}

bool Features::ggcar = false;
void Features::GGCar(bool toggle) {
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;

	bool bSelect = GetAsyncKeyState(Features::keyz[Features::keyIndex]); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_PLAYER_LASER");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 0, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 0, weaponAssetRocket, playerPed, 1, 0, -1.0);

		featureWeaponVehShootLastTime = GetTickCount();


	}
}


bool Features::wwcar = false;
void Features::WWCar(bool toggle) {
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;

	bool bSelect = GetAsyncKeyState(Features::keyz[Features::keyIndex]); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_PLANE_ROCKET");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 0, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 0, weaponAssetRocket, playerPed, 1, 0, -1.0);

		featureWeaponVehShootLastTime = GetTickCount();


	}
}

bool Features::cccar = false;
void Features::CCCar(bool toggle) {
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;

	bool bSelect = GetAsyncKeyState(Features::keyz[Features::keyIndex]); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_CANNON_BLAZER");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 0, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 0, weaponAssetRocket, playerPed, 1, 0, -1.0);

		featureWeaponVehShootLastTime = GetTickCount();


	}
}

bool Features::ttcar = false;
void Features::TTCar(bool toggle) {
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;

	bool bSelect = GetAsyncKeyState(Features::keyz[Features::keyIndex]); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_TURRET_BOXVILLE");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 0, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 0, weaponAssetRocket, playerPed, 1, 0, -1.0);

		featureWeaponVehShootLastTime = GetTickCount();


	}
}

bool Features::ttcarflare = false;
void Features::TTCarflare(bool toggle) {
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;

	bool bSelect = GetAsyncKeyState(Features::keyz[Features::keyIndex]); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_FLARE");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 0, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 0, weaponAssetRocket, playerPed, 1, 0, -1.0);

		featureWeaponVehShootLastTime = GetTickCount();


	}
}



bool Features::qqcarxdsa = false;
void Features::QQCarsd(bool toggle) {
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;

	bool bSelect = GetAsyncKeyState(Features::keyz[Features::keyIndex]); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_MOLOTOV");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 0, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 0, weaponAssetRocket, playerPed, 1, 0, -1.0);

		featureWeaponVehShootLastTime = GetTickCount();


	}
}

bool Features::qqcar = false;
void Features::QQCar(bool toggle) {
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;

	bool bSelect = GetAsyncKeyState(Features::keyz[Features::keyIndex]); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_RUINER_BULLET");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 0, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 0, weaponAssetRocket, playerPed, 1, 0, -1.0);

		featureWeaponVehShootLastTime = GetTickCount();


	}
}

bool Features::vbypass1 = false;
bool Features::vbypass2 = false;
void Features::vbypass(bool toggle) {
	NETWORK::NETWORK_SET_THIS_SCRIPT_IS_NETWORK_SCRIPT(32, toggle, PLAYER::PLAYER_ID());
	NETWORK::NETWORK_SET_THIS_SCRIPT_IS_NETWORK_SCRIPT(32, toggle, PLAYER::PLAYER_PED_ID());
}
bool Features::glitch[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::glitchPlayer(Player p) {
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), true));
	if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), true)))
	{
		ENTITY::APPLY_FORCE_TO_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), true), 1, 0, 0, 20, 0, 0, 0, 1, false, true, true, true, true);
	}
}

void Features::unlockSpecialMission() {
	globalHandle(262145).At(24692).As<int>() = 1;
}

bool Features::playerAsteroidBool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::playerAsteroidGun(Player p)
{
	if (is_ped_shooting(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p)))
	{
		Vector3 Rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 Dir = rot_to_direction(&Rot);
		Vector3 CPosition = CAM::GET_GAMEPLAY_CAM_COORD();
		Vector3 PlayerPosition = coordsOf(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p));
		float spawnDistance = get_distance(&CPosition, &PlayerPosition);
		spawnDistance += 2;
		Vector3 SPosition = add(&CPosition, &multiply(&Dir, spawnDistance));
		DWORD Model = $("prop_asteroid_01");
		Object ObJect = OBJECT::CREATE_OBJECT(Model, SPosition.x, SPosition.y, SPosition.z, 1, 1, 1);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Model);
		if (ENTITY::DOES_ENTITY_EXIST(ObJect))
		{
			ENTITY::SET_ENTITY_RECORDS_COLLISIONS(ObJect, true);
			for (float f = 0.0f; f < 75.0f; f++) {
				if (ENTITY::HAS_ENTITY_COLLIDED_WITH_ANYTHING(ObJect))break;
				ENTITY::APPLY_FORCE_TO_ENTITY(ObJect, 1, Dir.x*10.0f, Dir.y*10.0f, Dir.z*10.0f, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);
				WAIT(0);
			}
			Vector3 Coordinates = ENTITY::GET_ENTITY_COORDS(ObJect, 1);
			FIRE::ADD_EXPLOSION(Coordinates.x, Coordinates.y, Coordinates.z, 9, 25.0f, 1, 1, 0.5f);
		}
	}
}

void Features::stealCar(Player p) {
	Vehicle veh;
	Player player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	if (PED::IS_PED_IN_ANY_VEHICLE(player, 0))
	{
		veh = PED::GET_VEHICLE_PED_IS_USING(player);
		RequestControlOfEnt(veh);
		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -2);
		AI::CLEAR_PED_TASKS_IMMEDIATELY(player);
		AI::CLEAR_PED_TASKS(player);
		AI::CLEAR_PED_SECONDARY_TASK(player);
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
			veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		}
	}
}

/*
#define VK_NUMPAD1        0x61
#define VK_NUMPAD3        0x63
#define VK_NUMPAD7        0x67
#define VK_NUMPAD9        0x69
#define VK_ADD            0x6B
#define VK_SUBTRACT       0x6D
#define VK_DECIMAL        0x6E
#define VK_DIVIDE         0x6F
#define VK_F1             0x70
#define VK_F2             0x71
#define VK_F3             0x72
#define VK_F4             0x73
#define VK_F5             0x74
#define VK_F6             0x75
#define VK_F7             0x76
#define VK_F8             0x77
#define VK_F9             0x78
#define VK_F10            0x79
#define VK_F11            0x7A
#define VK_F12            0x7B
*/

enum keys
{
	NUM1 = 0x61,
	NUM3 = 0x63,
	NUM7 = 0x67,
	NUM9 = 0x69,
	PLUS = 0x6B,
	MINUS = 0x6D,
	DIVIDE = 0x6F,
	MULTIPLY = 0x6A,
	COMMA = 0x6E,
	F1 = 0x70,
	F2 = 0x71,
	F3 = 0x72,
	F4 = 0x73,
	F5 = 0x74,
	F6 = 0x75,
	F7 = 0x76,
	F8 = 0x77,
	F9 = 0x78,
	F10 = 0x79,
	F11 = 0x7A,
	F12 = 0x7B,
};

//TP hotkey
//Shoot hotkey
//NEW REMOTE EVENTS!!!
//Legacy event protex
//Block all script events
//Glitch player
//Change gender
//Player info: Is off radar

//weapon menu
//take weapons
//changed host kick
//Give normal weapons
//Give mk2 weapons
//Cargobob mods
//Infocolor

int Features::keyIndex = 5;
int Features::keyIndex2 = 4;
std::vector<std::string> Features::keynames = { "1", "3", "7", "9", "+", "-", "/", "*", ".", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12" };
int Features::keyz[21] = { NUM1, NUM3, NUM7, NUM9, PLUS, MINUS, DIVIDE, MULTIPLY, COMMA, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12 };

int Features::cargobob_strength = 1;
bool Features::cargobob_active = false;
void Features::cargobobMagnet() {
	Vehicle veh;
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) { veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()); }
	VEHICLE::_SET_CARGOBOB_PICKUP_MAGNET_ACTIVE(veh, Features::cargobob_active);
}

std::string Features::testText;

std::string Features::_encrypt(std::string msg, std::string key)
{
	// Make sure the key is at least as long as the message
	std::string tmp(key);
	while (key.size() < msg.size())
		key += tmp;

	// And now for the encryption part
	for (std::string::size_type i = 0; i < msg.size(); ++i)
		msg[i] ^= key[i];
	return msg;
}
std::string Features::_decrypt(std::string msg, std::string key)
{
	return _encrypt(msg, key); // lol
}

//Spawnmanager
int Features::spawnIndex = 0;
Vehicle Features::spawned[9999];
Hash Features::spawnedHash[9999];
int Features::selectedVehicle;

void Features::cargodmode3(Vehicle veh)
{
	Vehicle vehicle = veh;
	ENTITY::SET_ENTITY_INVINCIBLE(vehicle, true);
	ENTITY::SET_ENTITY_PROOFS(vehicle, true, true, true, true, true, true, true, true);
	VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, false);
	VEHICLE::SET_VEHICLE_ENVEFF_SCALE(vehicle, 0.f);
	VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_DAMAGE(vehicle, true);
	VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(vehicle, true);
	VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
	VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(vehicle, !true);
	VEHICLE::SET_VEHICLE_CAN_BREAK(vehicle, !true);
	VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
	VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE(vehicle, !true);
	VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(vehicle, !true);
	VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
	VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, !true);
	VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(vehicle, !true);
	VEHICLE::SET_VEHICLE_FIXED(vehicle);
	VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, true);
	VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
	VEHICLE::SET_VEHICLE_ENVEFF_SCALE(vehicle, 0.f);
	VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 0.f);
	VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
	VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
	VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
	if (VEHICLE::_IS_VEHICLE_DAMAGED(vehicle))
	{
		for (int i = 0; i < 10; i++)
		{
			try {
				VEHICLE::SET_VEHICLE_TYRE_FIXED(vehicle, i);
			}
			catch (...) {
				return;
			}
		}
	}
}

//TO DO: blameBy(Player p0, Player p1);
//TO DO: fix bank
//TO DO: new keybinds
//TO DO: Implement COLOR SELECTOR 2 (save & load)

//spawn saver added to spawn_vehicle() and remoteSpawnVehicle

void Auth::newAuthEntry(std::string entry, std::string key, std::string path) {
	std::string cipher = Features::_encrypt(entry, key);
	std::ofstream file;
	file.open(path, std::ios::out | std::ios::app);
	file.exceptions(file.exceptions() | std::ios::failbit | std::ifstream::badbit);

	file << cipher << "#";
}

bool Auth::AuthChecker(std::string entry, std::string key, std::string path) {
	std::string decipher;
	decipher = Features::_decrypt(entry, key);
	return Features::CheckWord((char*)path.c_str(), (char*)decipher.c_str());
}

char* Auth::kekKeyboard(char* windowName, int maxInput, char* defaultText) {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, windowName, "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return "";
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}

//XXXXX-XXXXX-XXXXX

bool Auth::logIn() {
	std::string key;
	key = kekKeyboard("Enter key:", 17, "");
	return AuthChecker(key, "soosenbinder", "X-Folder/kek.x");
}

int Features::iDontKnowAName = 0;
bool Features::stillDontKnowAName = false;
void Features::fuck_me_sideways(int iPar0) {
	//I will litterally drink my own piss if this works xd
	//if (!NETWORK::NETWORK_GET_THIS_SCRIPT_IS_NETWORK_SCRIPT()) {
		NETWORK::NETWORK_SET_THIS_SCRIPT_IS_NETWORK_SCRIPT(32, 0, -1);
		NETWORK::NETWORK_GET_SCRIPT_STATUS();
	//}
} 

bool Features::checkMenu = false;
bool Features::checkUser = false;

void Features::menuChecker() {
	for (int i = 0; i < 33; i++) {
		unsigned int Bit = (1 << i);
		uint64_t EvEnT[2] = { 12345678987654321, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) };
		Hooking::trigger_script_event(1, EvEnT, 2, Bit);
	}
}

char* Features::menuChecker2() {
	uint64_t Var0[10];
	auto result = Hooking::get_script_event_data(1, 0, Var0, 10);
	if (result && Var0[0] == 12345678987654321)
	{
		return PLAYER::GET_PLAYER_NAME(Var0[1]);
	}
}

bool Features::disableXuser = true;

bool Features::isXuser(Player p) {
	if (!disableXuser) {
		Features::menuChecker();
		char* playername = Features::menuChecker2();
		char* currentPlayer = PLAYER::GET_PLAYER_NAME(p);
		if (playername == currentPlayer) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Features::chatmsgbool = false;
void Features::chatMsg() {
	__int64 var0, var1, var2;
	char* msg;
	Hooking::get_chat_message(0, 0, 0, msg);
	
	if (msg != "") {
		std::string str(msg);
		notifyMap(str);
	}
	/*ostringstream ss; ss << var0 << " " << var1 << " " << var2 << " " << msg;
	Log::Msg((char*)ss.str().c_str());*/
}

bool Features::enableXscript = false;
void Features::x_script() {
	XScript::XscriptMain();
}

int weatherID = 0;

bool Features::weatherBool = false;
void Features::weatherGun() {
	if (is_ped_shooting(PLAYER::PLAYER_PED_ID())) {
		if (weatherID < 15) {
			weatherID++;
		}
		else {
			weatherID = 0;
		}
		Hooking::set_session_weather(1, weatherID, 76, 0);
	}
}

bool Features::playerWeatherBool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::playerWeatherGun(Player p) {
	if (is_ped_shooting(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p))) {
		if (weatherID < 15) {
			weatherID++;
		}
		else {
			weatherID = 0;
		}
		Hooking::set_session_weather(1, weatherID, 76, 0);
	}
}

//Sharkcard shop
//X-Scripts

bool Features::Triggerbot = false;
void Features::TriggerBot(bool toggle)
{
	Entity AimedAtEntity;
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &AimedAtEntity))
	{
		if (ENTITY::IS_ENTITY_A_PED(AimedAtEntity) && !ENTITY::IS_ENTITY_DEAD(AimedAtEntity) && PED::IS_PED_A_PLAYER(AimedAtEntity) && ENTITY::GET_ENTITY_ALPHA(AimedAtEntity) == 255)
		{
			Vector3 Mouth = PED::GET_PED_BONE_COORDS(AimedAtEntity, SKEL_Head, 0.1f, 0.0f, 0.0f);
			PED::SET_PED_SHOOTS_AT_COORD(PLAYER::PLAYER_PED_ID(), Mouth.x, Mouth.y, Mouth.z, true);
		}
	}
}

bool Features::displaySniper = false;
void Features::sniper() {
	CAM::DISPLAY_SNIPER_SCOPE_THIS_FRAME();
}

void Features::test_tse(Player p, int ev) {
	unsigned int Bit = (1 << p); 
	Player q = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	switch (ev) {
	case 0:
	{
		uint64_t args[5] = { 3261160979, q, 2601952180, 198525071, 59309 };
		Hooking::trigger_script_event(1, args, 5, Bit);
	}
	break;
	case 1:
	{
		uint64_t args[4] = { 2194772643, q, 0, 9074 };
		Hooking::trigger_script_event(1, args, 4, Bit);
	}
	break;
	case 2:
	{
		uint64_t args[4] = { 2023259876, q, 0, 2002 };
		Hooking::trigger_script_event(1, args, 4, Bit);
	}
	break;
	case 3:
	{
		uint64_t args[4] = { 566035618, q, 0, 9454 };
		Hooking::trigger_script_event(1, args, 4, Bit);
	}
	break;
	case 4:
	{
		uint64_t args[4] = { 1613784162, q, 0, 7422 };
		Hooking::trigger_script_event(1, args, 4, Bit);
	}
	break;
	case 5:
	{
		uint64_t args[56] = { 1613784162, q, 0, 7422 };
		Hooking::trigger_script_event(1, args, 56, Bit);
	}
	break;
	}
}

bool Features::delgun = false;
void Features::DelGun() {

	Entity del_entity;
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &del_entity))

	if (ENTITY::DOES_ENTITY_EXIST(del_entity) && NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(del_entity) && is_ped_shooting(PLAYER::PLAYER_PED_ID()))
	{
		Vector3 tmp = ENTITY::GET_ENTITY_COORDS(del_entity, 1);
		ENTITY::DETACH_ENTITY(del_entity, 1, 1);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(del_entity, 0, 0, 0, 0, 0, 0);
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(del_entity, 0, 1);
		ENTITY::DELETE_ENTITY(&del_entity);
	}
}

bool Features::maxPlayers = false;
bool Features::devDisabled = false;
int Features::playerCount = 30;
void Features::setMaxPlayers(int playerType, int playerCount) {
	int type; //0: Player; 4: Spectator; 8: Unk;
	if (playerType == -1) {
		type = 0;
	}
	else if (playerType == 0) {
		type = 4;
	}
	else if (playerType == 1) {
		type = 8;
	}
	else if (playerType == 2) {
		type = 0;
		NETWORK::_NETWORK_SESSION_SET_MAX_PLAYERS(4, playerCount);
	}
	else if (playerType == 3) {
		type = 0;
		NETWORK::_NETWORK_SESSION_SET_MAX_PLAYERS(8, playerCount);
	}
	else if (playerType == 4) {
		type = 4;
		NETWORK::_NETWORK_SESSION_SET_MAX_PLAYERS(8, playerCount);
	}
	NETWORK::_NETWORK_SESSION_SET_MAX_PLAYERS(type, playerCount);
}
//Disable R* Dev slots
//Set max players

void Features::merryweather(char* type) {
	if (type == "AMMO") {
		globalHandle(2524719).At(822).As<int>() = 1;
	}
	else if (type == "BOAT") {
		globalHandle(2524719).At(823).As<int>() = 1;
	}
	else if (type == "HELI") {
		globalHandle(2524719).At(824).As<int>() = 1;
	}
	else if (type == "AIRSTRIKE") {
		globalHandle(2524719).At(4376).As<int>() = 1;
	}
}

bool Features::adolf = false;
void Features::hitlerGun() {
	Vector3 Tmp;
	Hash hh = 1742463912;
	WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &Tmp);
	if (Tmp.x != 0 || Tmp.y != 0 || Tmp.z != 0) {
		Features::CREATE_OBJECT_WITH_ROTATION(hh, Tmp.x - 0.25f, Tmp.y, Tmp.z + 5.699999f, -90.0f, 0.0f, 90.0f, 0.0f, false, true);
		Features::CREATE_OBJECT_WITH_ROTATION(hh, Tmp.x + 2.4f, Tmp.y, Tmp.z + 3.599999f, 0.0f, 0.0f, 90.0f, 0.0f, false, true);
		Features::CREATE_OBJECT_WITH_ROTATION(hh, Tmp.x + 0.2f, Tmp.y, Tmp.z + 0.9f, 90.0f, 0.0f, 90.0f, 0.0f, false, true);
		Features::CREATE_OBJECT_WITH_ROTATION(hh, Tmp.x - 2.3f, Tmp.y, Tmp.z + 1.1f, 0.0f, 0.0f, 90.0f, 0.0f, false, true);
		Features::CREATE_OBJECT_WITH_ROTATION(hh, Tmp.x - 2.2f, Tmp.y, Tmp.z + 3.290001f, 90.0f, 0.0f, 90.0f, 0.0f, false, true);
		Features::CREATE_OBJECT_WITH_ROTATION(hh, Tmp.x + 0.3f, Tmp.y, Tmp.z + 3.290001f, 90.0f, 0.0f, 90.0f, 0.0f, false, true);
		Features::CREATE_OBJECT_WITH_ROTATION(hh, Tmp.x, Tmp.y, Tmp.z + 3.5f, 0.0f, 0.0f, 90.0f, 0.0f, false, true);
		Features::CREATE_OBJECT_WITH_ROTATION(hh, Tmp.x, Tmp.y, Tmp.z + 1.1f, 0.0f, 0.0f, 90.0f, 0.0f, false, true);
	}
}


#include <xtree>
bool bEnabled = false;
bool bGunActive = true;
bool bMultipleEntities = true;
float distanceFromCam = 0;
float shootForce = 69.0f;
std::set<Entity> entityArray;
void set_forge_gun_dist(float& distance)
{
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_LOOK_BEHIND, TRUE);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_WEAPON_WHEEL_NEXT, TRUE);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_WEAPON_WHEEL_PREV, TRUE);
	if (!CONTROLS::_IS_INPUT_DISABLED(2))
	{
		if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RS)) distance += 0.166f;
		if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_LS))
		{
			if (distance > 3.0f) distance -= 0.166f;
			auto ped = PLAYER::PLAYER_PED_ID();
			if (PED::GET_PED_STEALTH_MOVEMENT(ped)) PED::SET_PED_STEALTH_MOVEMENT(ped, 0, 0);
			if (PED::GET_PED_COMBAT_MOVEMENT(ped)) PED::SET_PED_COMBAT_MOVEMENT(ped, 0);
		}
	}
	else
	{
		if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_CURSOR_SCROLL_UP)) distance += 0.32f;
		if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_CURSOR_SCROLL_DOWN))
		{
			if (distance > 3.0f) distance -= 0.32f;
		}
	}

	CONTROLS::ENABLE_CONTROL_ACTION(2, INPUT_WEAPON_WHEEL_NEXT, TRUE);
	CONTROLS::ENABLE_CONTROL_ACTION(2, INPUT_WEAPON_WHEEL_PREV, TRUE);
}
void oscillate(Entity e, const Vector3& position, float angleFreq, float dampRatio) {
	Vector3 one, two, three;
	float angle = (angleFreq * angleFreq);
	one.x = (position.x - coordsOf(e).x) * angle;
	one.y = (position.y - coordsOf(e).y) * angle;
	one.z = (position.z - coordsOf(e).z) * angle;
	two.x = 2.0f * angleFreq * dampRatio * ENTITY::GET_ENTITY_VELOCITY(e).x;
	two.y = 2.0f * angleFreq * dampRatio * ENTITY::GET_ENTITY_VELOCITY(e).y;
	two.z = (2.0f * angleFreq * dampRatio * ENTITY::GET_ENTITY_VELOCITY(e).z) + 0.1f;
	three.x = one.x - two.x;
	three.y = one.y - two.y;
	three.z = one.z - two.z;
	ENTITY::APPLY_FORCE_TO_ENTITY(e, static_cast<int>(3), three.x, three.y, three.z, 0.0f, 0.0f, 0.0f, false, false, true, true, false, true);
}
bool RequestControl3(Entity e)
{
	if (!NETWORK::NETWORK_IS_IN_SESSION() || NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(e) != 0)
		return true;
	NETWORK::SET_NETWORK_ID_CAN_MIGRATE(NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(e), true);
	return NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(e) != 0;
}
float DistanceTo2(const Vector3& pos1, const Vector3& position)
{
	Vector3 result;
	result.x = position.x - pos1.x;
	result.y = position.y - pos1.y;
	result.z = position.z - pos1.z;
	return static_cast<float>(sqrt((result.x*result.x) + (result.y*result.y) + (result.z*result.z)));
}
static Vector3 RotationToDirection2(const Vector3& rotation)
{
	Vector3 result;
	float retz = rotation.z * 0.0174532924F; // Degree to radian
	float retx = rotation.x * 0.0174532924F;
	float absx = abs(cos(retx));
	result.x = -sin(retz) * absx;
	result.y = cos(retz) * absx;
	result.z = sin(retx);
	return result;
}

bool StoreEntities()
{
	Player player = PLAYER::PLAYER_ID();
	Entity myPed = PLAYER::PLAYER_PED_ID();
	int type;

	if (entityArray.empty())
	{
		//Entity& aimedEntity = EntityFromAimCamRay();
		Entity aimedEntity;
		PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(myPed, &aimedEntity);
		if (!aimedEntity)
			return false;

		type = ENTITY::GET_ENTITY_TYPE(aimedEntity);
		ENTITY::FREEZE_ENTITY_POSITION(aimedEntity, false);
		entityArray.insert(aimedEntity);
	}
	return true;
}
/*Entity& EntityFromAimCamRay()
{
	Player myPlayer = PLAYER::PLAYER_ID();
	Entity myPed = PLAYER::PLAYER_PED_ID();
	//GTAentity myWeapEnt = GET_CURRENT_PED_WEAPON_ENTITY_INDEX(myPed.Handle());

	Entity aimedEntity = AimedEntity();
	if (aimedEntity)
		return aimedEntity;

	Vector3& camCoord = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 hitCoord;
	hitCoord.x = (DirectionFromScreenCentre_get().x * 1000.0f) + camCoord.x;
	hitCoord.y = (DirectionFromScreenCentre_get().y * 1000.0f) + camCoord.y;
	hitCoord.z = (DirectionFromScreenCentre_get().z * 1000.0f) + camCoord.z;

	RaycastResult ray = RaycastResult::Raycast(camCoord, hitCoord, IntersectOptions::Everything, myPed);

	return ray.HitEntity();
}
Vector3 DirectionFromScreenCentre_get()
{
	Vector3& position = CAM::GET_GAMEPLAY_CAM_COORD();
	VECTOR2 tittenfick = { 0.0f, 0.0f };
	Vector3& world = ScreenToWorld(tittenfick);
	Vector3 yoink;
	yoink.x = world.x - position.x;
	yoink.y = world.y - position.y;
	yoink.z = world.z - position.z;
	return Normalize(yoink);
}
Vector3 ScreenToWorld(const VECTOR2& screenCoord)
{
	// Credit to Guadmaz
	Vector3& camRot = GameplayCamera::Rotation_get();
	Vector3& camPos = GameplayCamera::Position_get();

	VECTOR2 vector2;
	VECTOR2 vector21;
	Vector3& direction = Vector3::RotationToDirection(camRot);
	Vector3 vector3 = camRot + Vector3(10.f, 0.f, 0.f);
	Vector3 vector31 = camRot + Vector3(-10.f, 0.f, 0.f);
	Vector3 vector32 = camRot + Vector3(0.f, 0.f, -10.f);
	Vector3 direction1 = Vector3::RotationToDirection(camRot + Vector3(0.f, 0.f, 10.f)) - Vector3::RotationToDirection(vector32);
	Vector3 direction2 = Vector3::RotationToDirection(vector3) - Vector3::RotationToDirection(vector31);
	float rad = -DegreeToRadian(camRot.y);
	Vector3 vector33 = (direction1 * cos(rad)) - (direction2 * sin(rad));
	Vector3 vector34 = (direction1 * sin(rad)) + (direction2 * cos(rad));
	if (!WorldToScreenRel(((camPos + (direction * 10.f)) + vector33) + vector34, vector2))
	{
		return camPos + (direction * 10.f);
	}
	if (!WorldToScreenRel(camPos + (direction * 10.f), vector21))
	{
		return camPos + (direction * 10.f);
	}
	if (abs(vector2.x - vector21.x) < 0.001f || abs(vector2.y - vector21.y) < 0.001f)
	{
		return camPos + (direction * 10.f);
	}
	float x = (screenCoord.x - vector21.x) / (vector2.x - vector21.x);
	float y = (screenCoord.y - vector21.y) / (vector2.y - vector21.y);
	return ((camPos + (direction * 10.f)) + (vector33 * x)) + (vector34 * y);
}
Vector3 Normalize(Vector3 xd)
{
	float length = static_cast<float>(sqrt((xd.x*xd.x) + (xd.y*xd.y) + (xd.z*xd.z)));;
	if (length == 0.0f)
		return;
	float num = 1.0f / length;
	xd.x *= num;
	xd.y *= num;
	xd.z *= num;
	return xd;
}
Entity AimedEntity()
{
	Entity target;
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &target))
	{
		if (ENTITY::IS_ENTITY_A_PED(target))
		{
			if (PED::IS_PED_SITTING_IN_ANY_VEHICLE(target))
				return PED::GET_VEHICLE_PED_IS_IN(target, 0);
		}
		return target;
	}
	return 0;
} */
enum class EntityType : UINT8
{
	ALL/*Not really*/, PED, VEHICLE, PROP
};
bool Features::gravvv = false;
void Features::DoGravityGunTick()
{
	Player player = PLAYER::PLAYER_ID();
	Ped ped = PLAYER::PLAYER_PED_ID();

	if (GetAsyncKeyState(VK_RBUTTON) || PLAYER::IS_PLAYER_TARGETTING_ANYTHING(player))
	{
		if (bGunActive && StoreEntities())
		{
			Vector3& camPos = CAM::GET_GAMEPLAY_CAM_COORD();
			Entity firstEntity = *std::next(entityArray.begin(), 0);

			if (distanceFromCam == 0) distanceFromCam = DistanceTo2(camPos, coordsOf(firstEntity));

			set_forge_gun_dist(distanceFromCam);

			Vector3 kek = { (RotationToDirection2(CAM::GET_GAMEPLAY_CAM_ROT(2)).x * distanceFromCam), (RotationToDirection2(CAM::GET_GAMEPLAY_CAM_ROT(2)).y * distanceFromCam), (RotationToDirection2(CAM::GET_GAMEPLAY_CAM_ROT(2)).z * distanceFromCam) };
			Vector3 targetPos = { camPos.x * kek.x, camPos.y * kek.y, camPos.z * kek.z };

			if (entityArray.size() == 1)
			{
				Entity entity = *entityArray.begin();
				RequestControl3(entity);
				oscillate(entity, targetPos, 0.395f, 0.1f);
			}
			else
			{
				for (Entity entity : entityArray)
				{
					RequestControl3(entity);
					oscillate(entity, targetPos, 0.5f, 0.3f);
				}
			}

			if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, INPUT_ATTACK))
			{
				Vector3 force = { RotationToDirection2(CAM::GET_GAMEPLAY_CAM_ROT(2)).x * shootForce, RotationToDirection2(CAM::GET_GAMEPLAY_CAM_ROT(2)).y * shootForce, RotationToDirection2(CAM::GET_GAMEPLAY_CAM_ROT(2)).z * shootForce };

				for (Entity entity : entityArray)
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(entity, static_cast<int>(1), force.x, force.y,force.z, 0, 0, 0, false, false, true, true, false, true);
				}

				entityArray.clear();
				distanceFromCam = 0;
				bGunActive = false;
			}
		}
	}
	else
	{
		if (!entityArray.empty())
			entityArray.clear();
		distanceFromCam = 0;
		bGunActive = true;
	}

}
//FUll stat editor

void Features::sendPlayerMsg(Player p, char* msg) {
	int handle[26];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(p, &handle[0], 13);
	if (NETWORK::NETWORK_IS_HANDLE_VALID(&handle[0], 13)) {
		NETWORK::NETWORK_SEND_TEXT_MESSAGE(msg, &handle[0]);
	}
}

bool Features::aimbotOn = false;
void Features::aimbot() {
	Player playerPed = PLAYER::PLAYER_PED_ID();
	for (int i = 0; i < 32; i++)
	{
		Player playerHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
		char* Name = PLAYER::GET_PLAYER_NAME(PLAYER::INT_TO_PLAYERINDEX(i));
		if (ENTITY::DOES_ENTITY_EXIST(playerHandle))
		{
			if (playerHandle == playerPed) continue;
			{
				if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID())
					&& ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(playerPed, playerHandle, 17)
					&& !PED::IS_PED_RUNNING_RAGDOLL_TASK(playerHandle)
					&& ENTITY::GET_ENTITY_ALPHA(playerHandle) == 255)
				{
					if (GetAsyncKeyState(VK_LBUTTON))
					{
						Vector3 Mouth = PED::GET_PED_BONE_COORDS(playerHandle, SKEL_Head, 0.1f, 0.0f, 0.0f);
						PED::SET_PED_SHOOTS_AT_COORD(PLAYER::PLAYER_PED_ID(), Mouth.x, Mouth.y, Mouth.z, true);
					}
				}
			}
		}
	}
}

bool Features::rhornboost[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::HornBoostLoop(Player player)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), false))
	{
		if (AUDIO::IS_HORN_ACTIVE(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), false)))
			ENTITY::APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), false), 1, 0.f, 150.f, 0.f, TRUE, TRUE, TRUE, TRUE);
	}
}

bool Features::nostars[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::RemoteNeverWanted(Player player)
{
	unsigned int Bit = (1 << player);
	auto var0 = globalHandle(1625435 + 1 + player * 560 + 491).As<std::uint64_t>();
	auto var1 = NETWORK::GET_NETWORK_TIME();
	auto var2 = NETWORK::GET_NETWORK_TIME()/* + (60000 * 59) + 1*/;
	uint64_t args[7] = { 1475266103, player, var2, var1, 1, 1, var0 };
	Hooking::trigger_script_event(1, args, 7, Bit);
}

double timer() {
	std::clock_t start;
	double duration;

	start = std::clock();

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	return duration;
}

bool ranOut() {
	return timer() < 0;
}

bool Features::carcontrol[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::controlCar(Player player) {
	Ped p = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
	Vehicle v = PED::GET_VEHICLE_PED_IS_IN(p, true);

	Vector3 right = { 40.0f, 10.0f, 0.0f };
	Vector3 left = { -40.0f, 10.0f, 0.0f };
	Vector3 forw = { 0.0f, 100.0f, 0.0f };
	Vector3 backw = { 0.0f, -100.0f, 0.0f };
	Vector3 jump = { 0.0f, 0.0f, 7.0f };
	int keys[] = { VK_KEY_W, VK_KEY_A, VK_KEY_S, VK_KEY_D, VK_SPACE };

	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(v);
	if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(v)) {
		if (IsKeyPressed(keys[0])) {
			ENTITY::APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(v, 1, forw.x, forw.y, forw.z, TRUE, TRUE, TRUE, TRUE);
		}
		if (IsKeyPressed(keys[1])) {
			ENTITY::APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(v, 0, left.x, left.y, left.z, TRUE, TRUE, TRUE, TRUE);
		}
		if (IsKeyPressed(keys[2])) {
			ENTITY::APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(v, 1, backw.x, backw.y, backw.z, TRUE, TRUE, TRUE, TRUE);
		}
		if (IsKeyPressed(keys[3])) {
			ENTITY::APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(v, 0, right.x, right.y, right.z, TRUE, TRUE, TRUE, TRUE);
		}
		if (IsKeyPressed(keys[4])) {
			ENTITY::APPLY_FORCE_TO_ENTITY(v, 1, 0 + ENTITY::GET_ENTITY_FORWARD_X(v), 0 + ENTITY::GET_ENTITY_FORWARD_Y(v), 7, 0, 0, 0, 1, 0, 1, 1, 1, 1);
		}
	}
}

//Event protex:
//smart_protex: add new events
//smart_pro: turn smart protex on
//logger: log events


void Features::namech(const std::string& name) {
	/*size_t newLen = name.size() + 1;
	if (newLen <= 1 || newLen > 20)
		return;
	char    buffer[0x20] = {};
	char*    pSearch = (char*)Hooking::m_onlineName + 0x5C;
	size_t    curLen = strlen(pSearch) + 1;
	strncpy_s(buffer, pSearch, curLen);
	for (uint32_t i = 0, found = 0, match = 0; found < 4; ++pSearch)
	{
		if (*pSearch != buffer[i])
			goto LABEL_RESET;
		if (++match < curLen)
		{
			++i;
			continue;
		}
		strncpy_s(pSearch - i, newLen, &name[0], newLen);
		++found;
	LABEL_RESET:
		i = match = 0;
	}
	strncpy(Hooking::get_player_name(PLAYER::PLAYER_ID()), &name[0], newLen);*/
}

bool Features::antitp = false;
bool Features::anticl = false;
bool Features::anticr = false;
bool Features::antico = false;
bool Features::antivf = false;

void Features::antiTP(bool t) {
	Hooking::defuseEvent(NETWORK_REQUEST_SYNCED_SCENE_EVENT, t);
	Hooking::defuseEvent(NETWORK_UPDATE_SYNCED_SCENE_EVENT, t);
	Hooking::defuseEvent(NETWORK_START_SYNCED_SCENE_EVENT, t);
	globalHandle(1377446).At(486).As<int>() = 486; //TP
	globalHandle(1382674).At(499).As<int>() = 499; //TP
}

void Features::antiClear(bool t) {
	Hooking::defuseEvent(CLEAR_AREA_EVENT, t);
}

void Features::antiCrash(bool t) {
	Hash crashModelHashes[] = { 0xceea3f4b, 0x2592b5cf, 0x9cf21e0f, 0xc1ce1183, 0x49863e9c, 0xcd93a7db, 0x82cac433, 0x74f24de,  0x1c725a1,  0x81fb3ff0,
	0x79b41171, 0x781e451d, 0xa5e3d471, 0x6a27feb1, 0x861d914d, 0x8c049d17, 0xffba70aa, 0xe65ec0e4, 0xc3c00861, 0x5f5dd65c,
	0xc07792d4, 0x53cfe80a, 0xd9f4474c, 0xcb2acc8,  0xc6899cde, 0xd14b5ba3, 0x32a9996c, 0x69d4f974, 0xc2e75a21, 0x1075651,
	0xe1aeb708, 0xcbbb6c39, 0x6fa03a5e, 0xcf7a9a9d, 0x34315488, 0x45ef7804, 0xac3de147, 0xcafc1ec3, 0xd971bbae, 0xe764d794,
	0xf51f7309, 0x1e78c9d,  0xa49658fc, 0x4f2526da, 0x576ab4f6, 0xd20b1778, 0x54bc1cd8, 0xce109c5c, 0xe049c0ce, 0x78de93d1,
	0xe5b89d31, 0x5850e7b3, 0x6aed0e4b, 0xc50a4285, 0xb648a502, 0x5e497511, 0x47c14801, 0xfd8bb397, 0xef541728, 0xc2cc99d8,
	0x8fb233a4, 0x24e08e1f, 0x337b2b54, 0x7367d224, 0x919d9255, 0x4484243f, 0x3c91d42d, 0x3353525a, 0xc175f658, 0x762657c6,
	0x94ac15b3, 0x28014a56, 0xe0a8bfc9, 0x3a559c31, 0x5fc8a70,  0x3b545487, 0xb9402f87
	};

	Player player = PLAYER::PLAYER_ID();
	Vector3 coords = coordsOf(player);
	Ped clone;
	PED::GET_CLOSEST_PED(coords.x, coords.y, coords.z, 4.0, 0, 1, &clone, 0, 0, -1);
	if (ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(clone, PLAYER::PLAYER_PED_ID())) {
		RequestControlOfEnt(clone);
		int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(clone);
		RequestControlOfid(netID);
		NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
		ENTITY::DETACH_ENTITY(clone, 1, 1);
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(clone, 1, 1);
		ENTITY::DELETE_ENTITY(&clone);
		ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&clone);
		ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), coords.x, coords.y, coords.z - 1000, 0, 0, 0, 1);
	}

	for each(Hash h in crashModelHashes) {
		if (OBJECT::IS_OBJECT_NEAR_POINT(h, coords.x, coords.y, coords.z, 2.0f)) {
			Object a = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 2.0f, h, false, true, true);
			RequestControlOfEnt(a);
			int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(a);
			RequestControlOfid(netID);
			NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
			ENTITY::DETACH_ENTITY(a, 1, 1);
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(clone, 1, 1);
			ENTITY::DELETE_ENTITY(&a);
			ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&a);
			ENTITY::SET_ENTITY_COORDS(player, coords.x, coords.y, coords.z - 1000, 0, 0, 0, 1);
		}
	}
}

void Features::antiClone(bool t) {
	if (!CUTSCENE::IS_CUTSCENE_ACTIVE() && !CUTSCENE::IS_CUTSCENE_PLAYING() && !STREAMING::IS_NETWORK_LOADING_SCENE() && !NETWORK::NETWORK_IS_IN_MP_CUTSCENE() && !INTERIOR::IS_INTERIOR_SCENE())
	{
		Ped Closest;
		Vector3 MyPos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
		if (PED::GET_CLOSEST_PED(MyPos.x, MyPos.y, MyPos.z, 5, true, true, &Closest, false, true, -1))
		{
			if (ENTITY::GET_ENTITY_MODEL(Closest) == ENTITY::GET_ENTITY_MODEL(PLAYER::PLAYER_PED_ID()))
			{
				if (!PED::IS_PED_A_PLAYER(Closest))
				{
					if (ENTITY::DOES_ENTITY_EXIST(Closest))
					{
						if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Closest))
						{
							if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Closest))
							{
								ENTITY::DETACH_ENTITY(Closest, 1, 1);
								ENTITY::SET_ENTITY_COORDS(Closest, 6000.0, 6000.0, 6000.0, true, false, false, true);
								ENTITY::SET_ENTITY_AS_MISSION_ENTITY(Closest, 1, 1);
								PED::DELETE_PED(&Closest);
								ENTITY::DELETE_ENTITY(&Closest);
							}
						}
					}
				}
			}
		}
	}
}

int VehicleFreezeProtectionDelay = 0;
void Features::antiVehFreeze(bool t) {
	/*if (VehicleFreezeProtectionDelay < GAMEPLAY::GET_GAME_TIMER())
	{
		const int numElements = 10;
		const int arrSize = numElements + 1;  //Start at index 2, and the odd elements are padding
		int vehs[arrSize];
		vehs[0] = numElements;
		int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);
		for (int i = 0; i < count; ++i)
		{
			int offsettedID = i + 1;
			if (ENTITY::DOES_ENTITY_EXIST(vehs[offsettedID]))
			{
				bool Contin = true;
				if (t)
				{
					if (!(ENTITY::IS_ENTITY_ATTACHED(vehs[offsettedID]) && ENTITY::GET_ENTITY_ATTACHED_TO(vehs[offsettedID]) == PLAYER::PLAYER_PED_ID()))
						Contin = false;
				}
				if (Contin)
				{
					if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(vehs[offsettedID]) && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehs[offsettedID]))
					{
						ENTITY::SET_ENTITY_AS_MISSION_ENTITY(vehs[offsettedID], 0, 1);
						ENTITY::DELETE_ENTITY(&vehs[offsettedID]);

					}
				}
			}
		}
		VehicleFreezeProtectionDelay = GAMEPLAY::GET_GAME_TIMER() + 500;
	}*/
}

#pragma region cursor
bool Cursor::cursorOn = false;
//The main function of the cursor
void Cursor::cursor() {
	if (cursorOn) {
		//Disable controls
		CONTROLS::DISABLE_ALL_CONTROL_ACTIONS(0);
		CONTROLS::DISABLE_ALL_CONTROL_ACTIONS(1);
		CONTROLS::DISABLE_ALL_CONTROL_ACTIONS(2);
		//Show the cursor
		UI::_SET_CURSOR_SPRITE(5);
		UI::_SHOW_CURSOR_THIS_FRAME();
		if (Cursor::insideMenu()) {
			Cursor::moveScroller();
			//If you click on an option
			if (GetAsyncKeyState(VK_LBUTTON)) {
				Menu::Settings::selectPressed = true;
			}
			else {
				Menu::Settings::selectPressed = false;
			}
		}
		/*else {
			if (GetAsyncKeyState(VK_LBUTTON)) {
				Menu::Settings::cursorMenuX = Cursor::cursorPos().x;
				Menu::Settings::menuX = ((float)Cursor::cursorPos().x / 100) / 15;
			}
		}*/
	}
	else {
		CONTROLS::ENABLE_ALL_CONTROL_ACTIONS(0);
		CONTROLS::ENABLE_ALL_CONTROL_ACTIONS(1);
		CONTROLS::ENABLE_ALL_CONTROL_ACTIONS(2);
	}
}

//Get the position of the cursor
POINT Cursor::cursorPos() {
	POINT pt;
	if (GetCursorPos(&pt) && Cursor::cursorOn) {
		return pt;
	}
	else {
		POINT fail = { 0, 0 };
		return fail;
	}
}

//Checks if the cursor is inside the menu
bool Cursor::insideMenu() {
	if (Cursor::cursorOn) {
		float cx = (float)Cursor::cursorPos().x;
		float cy = (float)Cursor::cursorPos().y;
		//The cursor position gets calculated differently than the menu position
		//MenuPosition = (CursorPosition / 100) / 15
		//CursorPosition = (MenuPosition * 100) * 15
		float m1 = ((Menu::Settings::menuX * 100) * 15) - 155;
		float m2 = ((Menu::Settings::menuX * 100) * 15) + 180;
		//m1 = left menu border, m2 = right menu border
		if (cx > m1 && cx < m2 && cy > Cursor::getMenuTop()) {
			return true;
		}
		else {
			return false;
		}
	}
}

//The Y-coord of the menu top
float Cursor::getMenuTop() {
	return 146;
}

//The height of one option
float Cursor::getOptionHeight() {
	return 31.193;
}

//Returns the height of n options
int optionHeight(int op) {
	return Cursor::getMenuTop() + (Cursor::getOptionHeight() * op);
}

//Returns the number of the option that the cursor is on
int Cursor::onOption() {
	float cy = (float)Cursor::cursorPos().y;
	int count = Menu::Settings::optionCount;
	if (Cursor::insideMenu()) {
		for (int i = 0; i < 16; i++) {
			if (cy > optionHeight(i) && cy < optionHeight(i + 1)) {
				return i + 1;
			}
		}
	}
	else {
		return -1;
	}
}

//Gets the options that are currently onscreen
void Cursor::getOnscreenOptions(int &start, int &end) {
	int count = Menu::Settings::optionCount;
	int current = Menu::Settings::currentOption;
	if (count < 17) {
		start = 1;
		end = count;
	}
	else {
		if (current < 17) {
			start = 1;
			end = 16;
		}
		else {
			start = current - 15;
			end = current;
		}
	}
}

//Moves the scroller
void Cursor::moveScroller() {
	//Saves the options that are onscreen in an array
	int onscreen[16]/* = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }*/;
	int unused;
	Cursor::getOnscreenOptions(onscreen[0], unused);
	for (int i = 1; i < ARRAYSIZE(onscreen); i++) {
		onscreen[i] = onscreen[i - 1] + 1;
	}
	//Breaks if an option-check is applied? if (onscreen[15] < Menu::Settings::optionCount)
	//Sets the scroller to the specific option
	//Cursor::onOption() ranges from 1 to 16; selects the index of the onscreen options
	Menu::Settings::currentOption = onscreen[Cursor::onOption() - 1];
}

//Excludes
//Remote tp
//Moneydrop
//Remove money
//Better outfit changer
//Player info
//Random weather
//Minimenu-TP
#pragma endregion

//Ride submenu
//Globe
//Report display
//IP display

int Features::wantedstars = 0;
void Features::setWanted(int stars) {
	switch (stars) {
	case 0: Memory::set_value<int>({ (2 * 4 * 2) / 2, 4 * 1000 + 280, 500 * 4 - 70 + 70 + 72 }, 0); GAMEPLAY::SET_FAKE_WANTED_LEVEL(0); break;
	case 1: Memory::set_value<int>({ (2 * 4 * 2) / 2, 4 * 1000 + 280, 500 * 4 - 70 + 70 + 72 }, 1); GAMEPLAY::SET_FAKE_WANTED_LEVEL(0); break;
	case 2: Memory::set_value<int>({ (2 * 4 * 2) / 2, 4 * 1000 + 280, 500 * 4 - 70 + 70 + 72 }, 2); GAMEPLAY::SET_FAKE_WANTED_LEVEL(0); break;
	case 3: Memory::set_value<int>({ (2 * 4 * 2) / 2, 4 * 1000 + 280, 500 * 4 - 70 + 70 + 72 }, 3); GAMEPLAY::SET_FAKE_WANTED_LEVEL(0); break;
	case 4: Memory::set_value<int>({ (2 * 4 * 2) / 2, 4 * 1000 + 280, 500 * 4 - 70 + 70 + 72 }, 4); GAMEPLAY::SET_FAKE_WANTED_LEVEL(0); break;
	case 5: Memory::set_value<int>({ (2 * 4 * 2) / 2, 4 * 1000 + 280, 500 * 4 - 70 + 70 + 72 }, 5); GAMEPLAY::SET_FAKE_WANTED_LEVEL(0); break;
	case 6: GAMEPLAY::SET_FAKE_WANTED_LEVEL(6); break;
	}
} //8 4280 2072

bool Features::otrd = false;
void Features::otrdeath()
{
	Memory::set_value<float>({ 0x8, 0x2A0 }, 0.0f);
}

bool Features::kickGunBool = false;
void Features::kickGun() {
	Entity AimedAtEntity;
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &AimedAtEntity) && IsKeyPressed(VK_LBUTTON)) {
		if (PED::IS_PED_A_PLAYER(AimedAtEntity)) {
			//notifyMap(PLAYER::GET_PLAYER_NAME(AimedAtEntity));
			for (int i = 0; i < 33; i++) {
				if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == AimedAtEntity) {
					uint64_t args[3] = { -120668417, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 48 };
					Hooking::trigger_script_event(1, args, 3, (1 << i));
				}
			}
		}
	}
}

int menuType = 0;
std::string menuTypes[] = { "DEMO", "NORMAL", "PREMIUM", "DEV" };

void setMenuType(const std::string handle) {
	if (handle == menuTypes[0]) {
		menuType = 0;
	}
	else if (handle == menuTypes[1]) {
		menuType = 1;
	}
	else if (handle == menuTypes[2]) {
		menuType = 2;
	}
	else if (handle == menuTypes[3]) {
		menuType = 3;
	}
	else {
		menuType = -1;
	}
}

void getMenuType(std::string name, int id) {
	name = menuTypes[menuType];
	id = menuType;
}

void Features::notify(char* txt, char* sender, char* subject, char* clan, char* icon, bool flash, int iconType1, int iconType2) {
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(txt);
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2(icon, icon, flash, iconType1, sender, subject, 1, clan, iconType2);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);
/*
List of picNames: pastebin.com/XdpJVbHz
flash is a bool for fading in.
iconTypes:
1 : Chat Box
2 : Email
3 : Add Friend Request
4 : Nothing
5 : Nothing
6 : Nothing
7 : Right Jumping Arrow
8 : RP Icon
9 : $ Icon

"sender" is the very top header. This can be any old string.
"subject" is the header under the sender.
"duration" is a multiplier, so 1.0 is normal, 2.0 is twice as long (very slow), and 0.5 is half as long.
"clanTag" shows a crew tag in the "sender" header, after the text. You need to use 3 underscores as padding. Maximum length of this field seems to be 7. (e.g. "MK" becomes "___MK", "ACE" becomes "___ACE", etc.)
iconType2 is a mirror of iconType. It shows in the "subject" line, right under the original iconType.
"p9" is the color of the sender's MP name. In the scripts it is set to one of the pre-defined colors HUD_COLOUR_G1 (192) .. HUD_COLOUR_G15 (206)
*/
}

void Features::cleaner(Player Ped) {
	PED::CLEAR_PED_BLOOD_DAMAGE(Ped); 
	PED::RESET_PED_VISIBLE_DAMAGE(Ped);
}

bool Features::ffs1 = false;
bool Features::ffs2 = false;
bool Features::ffs3 = false;
void Features::frameFlag(bool explogun, bool firegun, bool explomelee) {
	std::vector<DWORD> base = { 0x08, 0x10B8, 0x1F8 };
	auto explo = 0x800u;
	auto fire = 0x1000u;
	auto exmelee = 0x2000u;
	if (explogun) { Memory::set_value<int>(base, explo); }     //Explosive ammo
	if (firegun) { Memory::set_value<int>(base, fire); }       //Fire ammo
	if (explomelee) { Memory::set_value<int>(base, exmelee); } //Explosive melee
}

bool Features::Fmoney[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::fmoney(Player p) {
	if (is_ped_shooting(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p)))
	{
		float loc[6];
		WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD1(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), loc);

		if ((timeGetTime() - Features::TimePD19) > 100)
		{
			STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
			if (!STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem))) {
				WAIT(0);
			}
			else {
				OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, loc[0], loc[2], loc[4], 0, 0, moneyModel(Features::MoneyItem), FALSE, TRUE);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));
				Features::TimePD19 = timeGetTime();
			}
		}
	}
}

bool Features::Fmoney2 = false;
void Features::fmoney2() {
	if (is_ped_shooting(PLAYER::PLAYER_PED_ID()))
	{
		float loc[6];
		WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD1(PLAYER::PLAYER_PED_ID(), loc);

		if ((timeGetTime() - Features::TimePD19) > 100)
		{
			STREAMING::REQUEST_MODEL(moneyModel(Features::MoneyItem));
			if (!STREAMING::HAS_MODEL_LOADED(moneyModel(Features::MoneyItem))) {
				WAIT(0);
			}
			else {
				OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, loc[0], loc[2], loc[4], 0, 0, moneyModel(Features::MoneyItem), FALSE, TRUE);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(moneyModel(Features::MoneyItem));
				Features::TimePD19 = timeGetTime();
			}
		}
	}
}

//ROCKSTAR DEV MODE!

bool Features::Speedometer = false;
bool Features::numberplateSp = false;
char* Features::unitt = "KM/H";
void Features::speedometer(char* mode, bool plate) {
	Ped ped = PLAYER::PLAYER_PED_ID();

	bool inVehicle = PED::IS_PED_IN_ANY_VEHICLE(ped, 0);
	std::ostringstream Speed1; Speed1 << "Speed:~s~ ";
	std::ostringstream Speed2; Speed2 << "Speed:~s~ ";
	std::ostringstream Speed3; Speed3 << "Speed:~s~ ";
	if (inVehicle) {
		float vehSpeed = ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
		float vehSpeedMS = round(vehSpeed);
		float vehSpeedConverted;
		float vehSpeedMPH;
		vehSpeedConverted = round(vehSpeed *3.6);
		vehSpeedMPH = round((vehSpeedConverted / 2) / 0.8);

		Speed1 << vehSpeedConverted << " KM/H";		
		Speed2 << vehSpeedMS << " M/S";
		Speed3 << vehSpeedMPH << " MPH";		
		if (!plate) {
			if (mode == "KM/H") {
				Menu::Speedometer((char*)Speed1.str().c_str());
			}
			else if (mode == "M/S") {
				Menu::Speedometer((char*)Speed2.str().c_str());
			}
			else if (mode == "MPH") {
				Menu::Speedometer((char*)Speed3.str().c_str());
			}
		}
		else {		
			if (mode == "KM/H") {
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(ped, 0), (char*)std::to_string(vehSpeedConverted).c_str());
			}
			else if (mode == "M/S") {			
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(ped, 0), (char*)std::to_string(vehSpeedMS).c_str());
			}
			else if (mode == "MPH") {
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(ped, 0), (char*)std::to_string(vehSpeedMPH).c_str());
			}
		}
	}
}

bool Features::antiinv = false;
void Features::AntiInvite() {
	if (antiinv) {
		NETWORK::NETWORK_BLOCK_INVITES(1);
	} else NETWORK::NETWORK_BLOCK_INVITES(0);
}

bool Features::playerKKKgun[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::playerkickGun(Player p) {
	Entity AimedAtEntity;
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), &AimedAtEntity) && is_ped_shooting(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p))) {
		if (PED::IS_PED_A_PLAYER(AimedAtEntity)) {
			//notifyMap(PLAYER::GET_PLAYER_NAME(AimedAtEntity));
			for (int i = 0; i < 33; i++) {
				if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == AimedAtEntity) {
					uint64_t args[3] = { -120668417, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 48 };
					Hooking::trigger_script_event(1, args, 3, (1 << i));
				}
			}
		}
	}
}

//Refill health
//Max armor
//Reset player
//Player alpha
//Slow motion
//Full stat editor
//Minor spawner tweaks
//DLC spawner
//Show game version



















/*void bunkerMoney(int money) {
	DWORD STptr = 0x2D0F2C8;
	DWORD SCptr = 0x2D09BE8;
	DWORD bunkerOffset[2] = { 0x1180, 0x4128 };
	DWORD ptr;
	GetModuleHandleA("steam_api64.dll") ? ptr = Memory::get_value<DWORD>({ (DWORD)Memory::get_base(), STptr }) : ptr = Memory::get_value<DWORD>({ (DWORD)Memory::get_base(), SCptr });
	Memory::set_value<DWORD[]>({ ptr }, bunkerOffset);
	WriteProcessMemory("GTA5.exe", Memory::get_base(), (BYTE)money, 4);
}*/

void Features::setplayername(std::string& name)
{
	/*size_t newLen = name.size() + 1;
	if (newLen <= 1 || newLen > 20)
		return;
	char    buffer[0x20] = {};
	char*    pSearch = (char*)Hooking::m_onlineName + 0x5C;
	//char*     pSearch = Memory::get_value<char*>({ 0x7C });
	size_t    curLen = strlen(pSearch) + 1;
	strncpy_s(buffer, pSearch, curLen);
	for (uint32_t i = 0, found = 0, match = 0; found < 4; ++pSearch)
	{
		if (*pSearch != buffer[i])
			goto LABEL_RESET;
		if (++match < curLen)
		{
			++i;
			continue;
		}
		strncpy_s(pSearch - i, newLen, &name[0], newLen);
		++found;
	LABEL_RESET:
		i = match = 0;
	}
	strncpy(PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID()), &name[0], newLen);*/
	size_t newLen = name.size() + 1;
	if (newLen <= 1 || newLen > 20)
		return;
	char    buffer[0x20] = {};
	char*    pSearch = (char*)0x7C + 0x5C;
	size_t    curLen = strlen(pSearch) + 1;
	strncpy_s(buffer, pSearch, curLen);
	for (uint32_t i = 0, found = 0, match = 0; found < 4; ++pSearch)
	{
		if (*pSearch != buffer[i])
			goto LABEL_RESET;
		if (++match < curLen)
		{
			++i;
			continue;
		}
		strncpy_s(pSearch - i, newLen, &name[0], newLen);
		++found;
	LABEL_RESET:
		i = match = 0;
	}
	//strncpy(Hooking::get_player_name(PLAYER::PLAYER_ID()), &name[0], newLen);
}

bool Features::cartoongunOn = false;
void Features::cartoongun() {
	Vector3 coords;
	if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &coords)) {
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		while (!STREAMING::HAS_NAMED_PTFX_ASSET_LOADED("scr_rcbarry2")) WAIT(0);

		Vector3 minV, maxV;
		Hash weapHash;

		Entity weap = WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID());
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &weapHash, 1);

		GAMEPLAY::GET_MODEL_DIMENSIONS(weapHash, &minV, &maxV);
		Vector3 pos = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(weap, (minV.x - maxV.x) / 2.0f + 0.7f, 0, 0);
		Vector3 rot = ENTITY::GET_ENTITY_ROTATION(weap, 2);
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_rcbarry2");

		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_AT_COORD("muz_clown"/*dict*/, pos.x, pos.y, pos.z, rot.x, rot.y, rot.z, 0.9f, 0, 0, 0);
	}
}

bool Features::semiOn = false;
void Features::semigodmode() {
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_ENTITY_HEALTH }, ENTITY::GET_ENTITY_MAX_HEALTH(playerPed));
}

Player Features::index_to_id(Ped playerPedScriptIndex) {
	for (int i = 0; i < 33; i++) {
		if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == playerPedScriptIndex) {
			return i;
		}
	}
}

std::string Features::event_id_to_string(__int64 e) {
	switch (e) {
	case SCRIPT_ARRAY_DATA_VERIFY_EVENT: return "SCRIPT_ARRAY_DATA_VERIFY_EVENT";
	case REQUEST_CONTROL_EVENT: return "REQUEST_CONTROL_EVENT";
	case GIVE_CONTROL_EVENT: return "GIVE_CONTROL_EVENT";
	case WEAPON_DAMAGE_EVENT: return "WEAPON_DAMAGE_EVENT";
	case REQUEST_PICKUP_EVENT: return "REQUEST_PICKUP_EVENT";
	case REQUEST_MAP_PICKUP_EVENT: return "REQUEST_MAP_PICKUP_EVENT";
	case GAME_CLOCK_EVENT: return "GAME_CLOCK_EVENT";
	case GAME_WEATHER_EVENT: return "GAME_WEATHER_EVENT";
	case RESPAWN_PLAYER_PED_EVENT: return "RESPAWN_PLAYER_PED_EVENT";
	case GIVE_WEAPON_EVENT: return "GIVE_WEAPON_EVENT";
	case REMOVE_WEAPON_EVENT: return "REMOVE_WEAPON_EVENT";
	case REMOVE_ALL_WEAPONS_EVENT: return "REMOVE_ALL_WEAPONS_EVENT";
	case VEHICLE_COMPONENT_CONTROL_EVENT: return "VEHICLE_COMPONENT_CONTROL_EVENT";
	case FIRE_EVENT: return "FIRE_EVENT";
	case EXPLOSION_EVENT: return "EXPLOSION_EVENT";
	case START_PROJECTILE_EVENT: return "START_PROJECTILE_EVENT";
	case ALTER_WANTED_LEVEL_EVENT: return "ALTER_WANTED_LEVEL_EVENT";
	case CHANGE_RADIO_STATION_EVENT: return "CHANGE_RADIO_STATION_EVENT";
	case RAGDOLL_REQUEST_EVENT: return "RAGDOLL_REQUEST_EVENT";
	case PLAYER_TAUNT_EVENT: return "PLAYER_TAUNT_EVENT";
	case PLAYER_CARD_STAT_EVENT: return "PLAYER_CARD_STAT_EVENT";
	case DOOR_BREAK_EVENT: return "DOOR_BREAK_EVENT";
	case SCRIPTED_GAME_EVENT: return "SCRIPTED_GAME_EVENT";
	case REMOTE_SCRIPT_INFO_EVENT: return "REMOTE_SCRIPT_INFO_EVENT";
	case REMOTE_SCRIPT_LEAVE_EVENT: return "REMOTE_SCRIPT_LEAVE_EVENT";
	case MARK_AS_NO_LONGER_NEEDED_EVENT: return "MARK_AS_NO_LONGER_NEEDED_EVENT";
	case CONVERT_TO_SCRIPT_ENTITY_EVENT: return "CONVERT_TO_SCRIPT_ENTITY_EVENT";
	case SCRIPT_WORLD_STATE_EVENT: return "SCRIPT_WORLD_STATE_EVENT";
	case INCIDENT_ENTITY_EVENT: return "INCIDENT_ENTITY_EVENT";
	case CLEAR_AREA_EVENT: return "CLEAR_AREA_EVENT";
	case CLEAR_RECTANGLE_AREA_EVENT: return "CLEAR_RECTANGLE_AREA_EVENT";
	case NETWORK_REQUEST_SYNCED_SCENE_EVENT: return "NETWORK_REQUEST_SYNCED_SCENE_EVENT";
	case NETWORK_START_SYNCED_SCENE_EVENT: return "NETWORK_START_SYNCED_SCENE_EVENT";
	case NETWORK_UPDATE_SYNCED_SCENE_EVENT: return "NETWORK_UPDATE_SYNCED_SCENE_EVENT";
	case NETWORK_STOP_SYNCED_SCENE_EVENT: return "NETWORK_STOP_SYNCED_SCENE_EVENT";
	case GIVE_PED_SCRIPTED_TASK_EVENT: return "GIVE_PED_SCRIPTED_TASK_EVENT";
	case GIVE_PED_SEQUENCE_TASK_EVENT: return "GIVE_PED_SEQUENCE_TASK_EVENT";
	case NETWORK_CLEAR_PED_TASKS_EVENT: return "NETWORK_CLEAR_PED_TASKS_EVENT";
	case NETWORK_START_PED_ARREST_EVENT: return "NETWORK_START_PED_ARREST_EVENT";
	case NETWORK_START_PED_UNCUFF_EVENT: return "NETWORK_START_PED_UNCUFF_EVENT";
	case NETWORK_SOUND_CAR_HORN_EVENT: return "NETWORK_SOUND_CAR_HORN_EVENT";
	case NETWORK_ENTITY_AREA_STATUS_EVENT: return "NETWORK_ENTITY_AREA_STATUS_EVENT";
	case NETWORK_GARAGE_OCCUPIED_STATUS_EVENT: return "NETWORK_GARAGE_OCCUPIED_STATUS_EVENT";
	case PED_CONVERSATION_LINE_EVENT: return "PED_CONVERSATION_LINE_EVENT";
	case SCRIPT_ENTITY_STATE_CHANGE_EVENT: return "SCRIPT_ENTITY_STATE_CHANGE_EVENT";
	case NETWORK_PLAY_SOUND_EVENT: return "NETWORK_PLAY_SOUND_EVENT";
	case NETWORK_STOP_SOUND_EVENT: return "NETWORK_STOP_SOUND_EVENT";
	case NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT: return "NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT";
	case NETWORK_BANK_REQUEST_EVENT: return "NETWORK_BANK_REQUEST_EVENT";
	case REQUEST_DOOR_EVENT: return "REQUEST_DOOR_EVENT";
	case NETWORK_TRAIN_REQUEST_EVENT: return "NETWORK_TRAIN_REQUEST_EVENT";
	case NETWORK_TRAIN_REPORT_EVENT: return "NETWORK_TRAIN_REPORT_EVENT";
	case NETWORK_INCREMENT_STAT_EVENT: return "NETWORK_INCREMENT_STAT_EVENT";
	case MODIFY_VEHICLE_LOCK_WORD_STATE_DATA: return "MODIFY_VEHICLE_LOCK_WORD_STATE_DATA";
	case REQUEST_PHONE_EXPLOSION_EVENT: return "REQUEST_PHONE_EXPLOSION_EVENT";
	case REQUEST_DETACHMENT_EVENT: return "REQUEST_DETACHMENT_EVENT";
	case KICK_VOTES_EVENT: return "KICK_VOTES_EVENT";
	case GIVE_PICKUP_REWARDS_EVENT: return "GIVE_PICKUP_REWARDS_EVENT";
	case NETWORK_CRC_HASH_CHECK_EVENT: return "NETWORK_CRC_HASH_CHECK_EVENT";
	case BLOW_UP_VEHICLE_EVENT: return "BLOW_UP_VEHICLE_EVENT";
	case NETWORK_SPECIAL_FIRE_EQUIPPED_WEAPON: return "NETWORK_SPECIAL_FIRE_EQUIPPED_WEAPON";
	case NETWORK_RESPONDED_TO_THREAT_EVENT: return "NETWORK_RESPONDED_TO_THREAT_EVENT";
	case NETWORK_SHOUT_TARGET_POSITION: return "NETWORK_SHOUT_TARGET_POSITION";
	case PICKUP_DESTROYED_EVENT: return "PICKUP_DESTROYED_EVENT";
	case UPDATE_PLAYER_SCARS_EVENT: return "UPDATE_PLAYER_SCARS_EVENT";
	case NETWORK_CHECK_EXE_SIZE_EVENT: return "NETWORK_CHECK_EXE_SIZE_EVENT";
	case NETWORK_PTFX_EVENT: return "NETWORK_PTFX_EVENT";
	case NETWORK_PED_SEEN_DEAD_PED_EVENT: return "NETWORK_PED_SEEN_DEAD_PED_EVENT";
	case REMOVE_STICKY_BOMB_EVENT: return "REMOVE_STICKY_BOMB_EVENT";
	case NETWORK_CHECK_CODE_CRCS_EVENT: return "NETWORK_CHECK_CODE_CRCS_EVENT";
	case INFORM_SILENCED_GUNSHOT_EVENT: return "INFORM_SILENCED_GUNSHOT_EVENT";
	case PED_PLAY_PAIN_EVENT: return "PED_PLAY_PAIN_EVENT";
	case CACHE_PLAYER_HEAD_BLEND_DATA_EVENT: return "CACHE_PLAYER_HEAD_BLEND_DATA_EVENT";
	case REMOVE_PED_FROM_PEDGROUP_EVENT: return "REMOVE_PED_FROM_PEDGROUP_EVENT";
	case REPORT_MYSELF_EVENT: return "REPORT_MYSELF_EVENT";
	case REPORT_CASH_SPAWN_EVENT: return "REPORT_CASH_SPAWN_EVENT";
	case ACTIVATE_VEHICLE_SPECIAL_ABILITY_EVENT: return "ACTIVATE_VEHICLE_SPECIAL_ABILITY_EVENT";
	case NETWORK_CHECK_CATALOG_CRC: return "NETWORK_CHECK_CATALOG_CRC";
	}
}

bool Features::blockEvent(__int64 id, __int64 blocked) {
	if (id == blocked) {
		return false;
	}
}

//Fix vehicle

void TRIGGER_NETWORK_EVENT(RockstarEvent e, Player player) {
	Player p = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
	if (e == SCRIPT_ARRAY_DATA_VERIFY_EVENT) {
		//idk
	}
	else if (e == REQUEST_CONTROL_EVENT) {
		RequestControlOfEnt(p);
	}
	else if (e == GIVE_CONTROL_EVENT) {
		RequestControlOfEnt(p);
	}
	/*
	WEAPON_DAMAGE_EVENT,
	REQUEST_PICKUP_EVENT,
	REQUEST_MAP_PICKUP_EVENT,
	GAME_CLOCK_EVENT,
	GAME_WEATHER_EVENT,
	RESPAWN_PLAYER_PED_EVENT,
	GIVE_WEAPON_EVENT,
	REMOVE_WEAPON_EVENT,
	REMOVE_ALL_WEAPONS_EVENT,
	VEHICLE_COMPONENT_CONTROL_EVENT,
	FIRE_EVENT,
	EXPLOSION_EVENT,
	START_PROJECTILE_EVENT,
	ALTER_WANTED_LEVEL_EVENT,
	CHANGE_RADIO_STATION_EVENT,
	RAGDOLL_REQUEST_EVENT,
	PLAYER_TAUNT_EVENT,
	PLAYER_CARD_STAT_EVENT,
	DOOR_BREAK_EVENT,
	SCRIPTED_GAME_EVENT,
	REMOTE_SCRIPT_INFO_EVENT,
	REMOTE_SCRIPT_LEAVE_EVENT,
	MARK_AS_NO_LONGER_NEEDED_EVENT,
	CONVERT_TO_SCRIPT_ENTITY_EVENT,
	SCRIPT_WORLD_STATE_EVENT,
	INCIDENT_ENTITY_EVENT,
	CLEAR_AREA_EVENT,
	CLEAR_RECTANGLE_AREA_EVENT,
	NETWORK_REQUEST_SYNCED_SCENE_EVENT,
	NETWORK_START_SYNCED_SCENE_EVENT,
	NETWORK_UPDATE_SYNCED_SCENE_EVENT,
	NETWORK_STOP_SYNCED_SCENE_EVENT,
	GIVE_PED_SCRIPTED_TASK_EVENT,
	GIVE_PED_SEQUENCE_TASK_EVENT,
	NETWORK_CLEAR_PED_TASKS_EVENT,
	NETWORK_START_PED_ARREST_EVENT,
	NETWORK_START_PED_UNCUFF_EVENT,
	NETWORK_SOUND_CAR_HORN_EVENT,
	NETWORK_ENTITY_AREA_STATUS_EVENT,
	NETWORK_GARAGE_OCCUPIED_STATUS_EVENT,
	PED_CONVERSATION_LINE_EVENT,
	SCRIPT_ENTITY_STATE_CHANGE_EVENT,
	NETWORK_PLAY_SOUND_EVENT,
	NETWORK_STOP_SOUND_EVENT,
	NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT,
	NETWORK_BANK_REQUEST_EVENT,
	REQUEST_DOOR_EVENT,
	NETWORK_TRAIN_REQUEST_EVENT,
	NETWORK_TRAIN_REPORT_EVENT,
	NETWORK_INCREMENT_STAT_EVENT,
	MODIFY_VEHICLE_LOCK_WORD_STATE_DATA,
	REQUEST_PHONE_EXPLOSION_EVENT,
	REQUEST_DETACHMENT_EVENT,
	KICK_VOTES_EVENT,
	GIVE_PICKUP_REWARDS_EVENT,
	NETWORK_CRC_HASH_CHECK_EVENT,
	BLOW_UP_VEHICLE_EVENT,
	NETWORK_SPECIAL_FIRE_EQUIPPED_WEAPON,
	NETWORK_RESPONDED_TO_THREAT_EVENT,
	NETWORK_SHOUT_TARGET_POSITION,
	PICKUP_DESTROYED_EVENT,
	UPDATE_PLAYER_SCARS_EVENT,
	NETWORK_CHECK_EXE_SIZE_EVENT,
	NETWORK_PTFX_EVENT,
	NETWORK_PED_SEEN_DEAD_PED_EVENT,
	REMOVE_STICKY_BOMB_EVENT,
	NETWORK_CHECK_CODE_CRCS_EVENT,
	INFORM_SILENCED_GUNSHOT_EVENT,
	PED_PLAY_PAIN_EVENT,
	CACHE_PLAYER_HEAD_BLEND_DATA_EVENT,
	REMOVE_PED_FROM_PEDGROUP_EVENT,
	REPORT_MYSELF_EVENT,
	REPORT_CASH_SPAWN_EVENT,
	ACTIVATE_VEHICLE_SPECIAL_ABILITY_EVENT,
	NETWORK_CHECK_CATALOG_CRC,
	*/
}

bool Features::enableKillSwitch = false;
void Features::killSwitch(int button) {
	if(IsKeyPressed(button)) {
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_ENTITY_HEALTH }, 0.0f);
	}
}

bool Features::disablephone = false;
void Features::disablePhone() {
	MOBILE::DESTROY_MOBILE_PHONE();
}

bool Features::setmulti = false;
float Features::accelerationmultiplier = 0;
float Features::brakesmultiplier = 0;
float Features::suspensionseight = 0;
void Features::SetMultipliers() {

	if (accelerationmultiplier != 0) {
		Vehicle pedVeh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

		if (ENTITY::DOES_ENTITY_EXIST(pedVeh)) {
			if (GetAsyncKeyState('W') || CONTROLS::IS_CONTROL_PRESSED(2, INPUT_FRONTEND_RT)) {
				if (VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(pedVeh))
					ENTITY::APPLY_FORCE_TO_ENTITY(pedVeh, true, 0, accelerationmultiplier / 10, 0, 0, 0, 0, true, true, true, true, false, true);
			}
		}
	}
	if (brakesmultiplier != 0) {

		Vehicle pedVeh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

		if (ENTITY::DOES_ENTITY_EXIST(pedVeh)) {
			if (GetAsyncKeyState('S') || CONTROLS::IS_CONTROL_PRESSED(2, INPUT_FRONTEND_LT)) {
				if (VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(pedVeh))
					ENTITY::APPLY_FORCE_TO_ENTITY(pedVeh, true, 0, ((brakesmultiplier / 10)* -1), 0, 0, 0, 0, true, true, true, true, false, true);
			}
		}

	}

	if (suspensionseight != 0) {

		Vehicle pedVeh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
		if (ENTITY::DOES_ENTITY_EXIST(pedVeh)) {
			ENTITY::APPLY_FORCE_TO_ENTITY(pedVeh, true, 0, 0, -suspensionseight / 10, 0, 0, 0, true, true, true, true, false, true);
		}
	}
}

bool Features::fcbool = false;
void Features::FlyingCarLoop()
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
	{
		int Vehid = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		ENTITY::APPLY_FORCE_TO_ENTITY(Vehid, 1, 0, 0, 20, 0, 0, 0, 1, false, true, true, true, true);
		if (CONTROLS::IS_CONTROL_PRESSED(2, 67) == true) //Forward
		{
			float Speed = ENTITY::GET_ENTITY_SPEED(Vehid) + 0.5;
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(Vehid, 25);

		}

		if ((CONTROLS::IS_CONTROL_PRESSED(2, 196) == true) && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(Vehid))) //Left
		{
			Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(Vehid, 2);
			Rot.z = Rot.z + 1.0;
			ENTITY::SET_ENTITY_ROTATION(Vehid, Rot.x, Rot.y, Rot.z, 2, 1);
		}

		if ((CONTROLS::IS_CONTROL_PRESSED(2, 197) == true) && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(Vehid))) //Right
		{
			Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(Vehid, 2);
			Rot.z = Rot.z - 1.0;
			ENTITY::SET_ENTITY_ROTATION(Vehid, Rot.x, Rot.y, Rot.z, 2, 1);
		}
	}
}

void Features::bountykek(Player p) {
	unsigned int Bit = (1 << p);
	//uint64_t args[6] = { -1177364063, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 5, -999497575, 1170203377, 1076363264 };
	auto var0 = globalHandle(2097152).At(0, 12745).At(12327).At(14).As<uint64_t>();
	uint64_t args[7] = { -679747935, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0, var0, 0, 1 };
	Hooking::trigger_script_event(1, args, 7, Bit);
}

bool Features::pussy1[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
bool Features::pussy2[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::passiveKiller(Player player) {
	Object bfa;
	Ped p = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
	int alpha = ENTITY::GET_ENTITY_ALPHA(p);
	if (pussy2[player] && alpha < 200) {
		if (bfa != NULL && !ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(bfa, p)) {
			pussy2[player] = false;
		}
		if (bfa == NULL) {
			pussy2[player] = false;
		}
	}
	if (alpha < 200 && !pussy2[player]) {
		Hash beach_fire = GAMEPLAY::GET_HASH_KEY("prop_beach_fire");
		STREAMING::REQUEST_MODEL(beach_fire);
		while (!STREAMING::HAS_MODEL_LOADED(beach_fire)) WAIT(0);
		Object object = OBJECT::CREATE_OBJECT(beach_fire, 0, 0, 0, true, true, false);
		bfa = object;
		ENTITY::ATTACH_ENTITY_TO_ENTITY(object, p, 31086, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(beach_fire);
		pussy2[player] = true;
	}
}

void Features::makePedHostile(Ped Ped, int Target, bool choporswat = false, bool isClone = false)
{
	if (choporswat)
	{
		AI::TASK_COMBAT_PED(Ped, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Target), 0, 16);
		PED::SET_PED_CAN_SWITCH_WEAPON(Ped, true);
	}
	else
	{
		if (isClone)
		{
			int Hash = ENTITY::GET_ENTITY_MODEL(Ped);
			if (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Ped))
				while (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Ped));

			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(Ped, 1, 1);
			PED::DELETE_PED(&Ped);

			STREAMING::REQUEST_MODEL(Hash);
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Target), 1);
			if (STREAMING::HAS_MODEL_LOADED(Hash))
			{
				int newPed = PED::CREATE_PED(21, Hash, coords.x, coords.y, coords.z, 0, 1, 0);
				if (ENTITY::GET_ENTITY_HEALTH(newPed) == ENTITY::GET_ENTITY_MAX_HEALTH(newPed))
				{
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Hash);
					RequestNetworkControl(newPed);
					AI::TASK_COMBAT_PED(newPed, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Target), 0, 16);
					PED::SET_PED_CAN_SWITCH_WEAPON(Ped, true);
				}
			}
		}
		else
		{
			int TargetHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Target);
			AI::TASK_COMBAT_PED(Ped, TargetHandle, 0, 16);
		}
	}
}

Ped* Features::nearbyPeds(Player player) {
	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Ped ped[arrSize];
	Ped output[arrSize];
	ped[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), ped, 1);
	if (ped != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
			{
				RequestNetworkControl(ped[offsettedID]);

				Vector3 Pos = ENTITY::GET_ENTITY_COORDS(ped[offsettedID], true);
				output[offsettedID] = ped[offsettedID];
			}
		}
	}
	return output;
}

bool Features::deleteObject(Object object) {
	if (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(object))
		while (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(object));

	ENTITY::SET_ENTITY_AS_MISSION_ENTITY(object, 1, 1);
	PED::DELETE_PED(&object);

	if (ENTITY::DOES_ENTITY_EXIST(object)) {
		return false;
	}
	else return true;
}

bool Features::killernpc[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::killerNPCs(Player target) {
	Ped* nearby = Features::nearbyPeds(target);
	for (int i = 0; i < sizeof(nearby); i++) {
		Features::makePedHostile(nearby[i], target, false, false);
	}
}

//Delete vehicle

void Features::setHornboostSpeed(int speed) {
	Features::hornboostSpeed = speed + 49;
}
int Features::hornboostInput = 1;
int Features::hornboostSpeed = 50;

//TO DO: Fix killer NPCs
//TO DO: Fix namechanger
//TO DO: Fix passive killer

/*
void sub_523a() {
	DECORATOR::DECOR_REGISTER("Player_Vehicle", 3);
	DECORATOR::DECOR_REGISTER("PV_Slot", 3);
	DECORATOR::DECOR_REGISTER("Previous_Owner", 3);
	DECORATOR::DECOR_REGISTER("Sprayed_Vehicle_Decorator", 2);
	DECORATOR::DECOR_REGISTER("Sprayed_Vehicle_Timer_Dec", 5);
	DECORATOR::DECOR_REGISTER("Vehicle_Reward", 3);
	DECORATOR::DECOR_REGISTER("Vehicle_Reward_Teams", 3);
	DECORATOR::DECOR_REGISTER("Skill_Blocker", 2);
	DECORATOR::DECOR_REGISTER("TargetPlayerForTeam", 3);
	DECORATOR::DECOR_REGISTER("XP_Blocker", 2);
	DECORATOR::DECOR_REGISTER("CrowdControlSetUp", 3);
	DECORATOR::DECOR_REGISTER("Bought_Drugs", 2);
	DECORATOR::DECOR_REGISTER("HeroinInPossession", 1);
	DECORATOR::DECOR_REGISTER("CokeInPossession", 1);
	DECORATOR::DECOR_REGISTER("WeedInPossession", 1);
	DECORATOR::DECOR_REGISTER("MethInPossession", 1);
	DECORATOR::DECOR_REGISTER("bombdec", 3);
	DECORATOR::DECOR_REGISTER("bombdec1", 3);
	DECORATOR::DECOR_REGISTER("bombowner", 3);
	DECORATOR::DECOR_REGISTER("noPlateScan", 2);
	DECORATOR::DECOR_REGISTER("prisonBreakBoss", 2);
	DECORATOR::DECOR_REGISTER("cashondeadbody", 3);
	DECORATOR::DECOR_REGISTER("MissionType", 3);
	DECORATOR::DECOR_REGISTER("MatchId", 3);
	DECORATOR::DECOR_REGISTER("TeamId", 3);
	DECORATOR::DECOR_REGISTER("Not_Allow_As_Saved_Veh", 3);
	DECORATOR::DECOR_REGISTER("Veh_Modded_By_Player", 3);
	DECORATOR::DECOR_REGISTER("MPBitset", 3);
	DECORATOR::DECOR_REGISTER("MC_EntityID", 3);
	DECORATOR::DECOR_REGISTER("MC_ChasePedID", 3);
	DECORATOR::DECOR_REGISTER("MC_Team0_VehDeliveredRules", 3);
	DECORATOR::DECOR_REGISTER("MC_Team1_VehDeliveredRules", 3);
	DECORATOR::DECOR_REGISTER("MC_Team2_VehDeliveredRules", 3);
	DECORATOR::DECOR_REGISTER("MC_Team3_VehDeliveredRules", 3);
	DECORATOR::DECOR_REGISTER("AttributeDamage", 3);
	DECORATOR::DECOR_REGISTER("GangBackup", 3);
	DECORATOR::DECOR_REGISTER("CreatedByPegasus", 2);
	DECORATOR::DECOR_REGISTER("BeforeCorona_0", 2);
}

-----------------------------------------------------------------------
Defines type of property for property name.

1 - float,
2 - bool,
3 - int
5 - time
*/

void Features::giveVehicle(Player p, char* veh) {
	Player player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	Vehicle vehicle = Features::SpawnVehicle(veh, coordsOf(player), false, 0.0f);
	DECORATOR::DECOR_REGISTER("Player_Vehicle", 3);
	DECORATOR::DECOR_REGISTER("Veh_Modded_By_Player", 3);
	DECORATOR::DECOR_REGISTER("Previous_Owner", 3);
	DECORATOR::DECOR_SET_INT(vehicle, "Player_Vehicle", NETWORK::_NETWORK_HASH_FROM_PLAYER_HANDLE(p));
	DECORATOR::DECOR_SET_INT(vehicle, "Previous_Owner", GAMEPLAY::GET_HASH_KEY(PLAYER::GET_PLAYER_NAME(p)));
	DECORATOR::DECOR_SET_INT(vehicle, "Veh_Modded_By_Player", GAMEPLAY::GET_HASH_KEY(PLAYER::GET_PLAYER_NAME(p)));
	DECORATOR::DECOR_SET_INT(vehicle, "Not_Allow_As_Saved_Veh", 0);
	VEHICLE::SET_VEHICLE_IS_STOLEN(vehicle, false);
}

bool Features::flybool = false;
void Features::playerflyer() {

	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, false);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	if (GetAsyncKeyState(VK_KEY_S) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 268)) {
		float fivef = .5f;
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		float xVec = fivef * sin(degToRad(heading)) * -1.0f;
		float yVec = fivef * cos(degToRad(heading));
		ENTITY::SET_ENTITY_HEADING(playerPed, heading);

		pos.x -= xVec, pos.y -= yVec;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	}
	if (GetAsyncKeyState(VK_KEY_W) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269)) {
		float fivef = .5f;
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		float xVec = fivef * sin(degToRad(heading)) * -1.0f;
		float yVec = fivef * cos(degToRad(heading));
		ENTITY::SET_ENTITY_HEADING(playerPed, heading);

		pos.x += xVec, pos.y += yVec;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	}
	if (GetAsyncKeyState(VK_KEY_A) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 266)) {
		float fivef = .5f;
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		ENTITY::SET_ENTITY_HEADING(playerPed, heading + 0.5f);
	}
	if (GetAsyncKeyState(VK_KEY_D) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 271)) {
		float fivef = .5f;
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		ENTITY::SET_ENTITY_HEADING(playerPed, heading - 0.5f);
	}
	if (GetAsyncKeyState(VK_SHIFT) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, ControlFrontendRb)) {
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		ENTITY::SET_ENTITY_HEADING(playerPed, heading);

		pos.z -= 0.5;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	}
	if (GetAsyncKeyState(VK_SPACE) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, ControlFrontendLb)) {
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		ENTITY::SET_ENTITY_HEADING(playerPed, heading);

		pos.z += 0.5;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	}
}

bool Features::supermanOn = false;
void Features::Superman(bool toggle)
{
	if (toggle == true) {
		Hash hash = GAMEPLAY::GET_HASH_KEY("GADGET_PARACHUTE");
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), hash, 1, 1);
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), true);
		PED::SET_PED_TO_RAGDOLL_WITH_FALL(PLAYER::PLAYER_PED_ID(), 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);

		if (ENTITY::IS_ENTITY_IN_AIR(PLAYER::PLAYER_PED_ID()) && !PED::IS_PED_RAGDOLL(PLAYER::PLAYER_PED_ID()))
		{
			if (GetAsyncKeyState(0x57)) // W key
			{
				ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 0, 6, 0);
			}

			if (GetAsyncKeyState(0x53)) // S key
			{
				ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 0, -6, 0);
			}
			if (GetAsyncKeyState(VK_SPACE)) //VK_SHIFT
			{
				ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 0, 0, 6);
			}
		}
	}
	else {
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), false);
	}
}

//Alien invasion

//Cage stunt object

//Cage cable car

bool Features::ptfxself = false;
bool Features::ptfxplayer[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::PTFXCALLO(char *call1, char *call2, char *name, Player target)
{
	Ped user = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);

	call1o = call1;
	call2o = call2;
	nameo = name;
	PTLoopPed = user;

	STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
	GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(call2);
	GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(name, user, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
}

bool Features::pedswap = false;
void Features::swapgun() {
	Entity EntityTarget;
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget) && GetAsyncKeyState(VK_LBUTTON)) {
		if (ENTITY::IS_ENTITY_A_PED(EntityTarget)) {
			Hash model = ENTITY::GET_ENTITY_MODEL(EntityTarget);
			if (STREAMING::IS_MODEL_VALID(model)) {
				STREAMING::REQUEST_MODEL(model);
				while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
				PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
				PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
			}		
		}
	}
}


bool Features::VALKYIREROCKET = false;
void Features::valkyirerocket(bool toggle)
{
	static std::int32_t rocket, cam;
	static std::uint8_t y;
	static float bar;
	static bool init;
	if (is_ped_shooting(PLAYER::PLAYER_PED_ID())) {
		if (!init) init = true;
	}
	if (init) {
		if (!ENTITY::DOES_ENTITY_EXIST(rocket)) {
			auto weapon = WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID());
			auto c = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(weapon, 0.f, 1.f, 0.f);
			rocket = OBJECT::CREATE_OBJECT($("w_lr_rpg_rocket"), c.x, c.y, c.z, 1, 1, 0);
			CAM::DESTROY_ALL_CAMS(true);
			cam = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 1);
			CAM::ATTACH_CAM_TO_ENTITY(cam, rocket, 0.f, 0.f, 0.f, 1);
			CAM::RENDER_SCRIPT_CAMS(1, true, 700, 1, 1);
			CAM::SET_CAM_ACTIVE(cam, 1);
			ENTITY::SET_ENTITY_VISIBLE(rocket, 0);
			bar = .5f; y = 255;
		}
		else {
			CAM::SET_CAM_ROT(cam, CAM::GET_GAMEPLAY_CAM_ROT(0).x, CAM::GET_GAMEPLAY_CAM_ROT(0).y, CAM::GET_GAMEPLAY_CAM_ROT(0).z, 0);
			ENTITY::SET_ENTITY_ROTATION(rocket, CAM::GET_GAMEPLAY_CAM_ROT(0).x, CAM::GET_GAMEPLAY_CAM_ROT(0).y, CAM::GET_GAMEPLAY_CAM_ROT(0).z, 0, 1);

			auto c = add(&ENTITY::GET_ENTITY_COORDS(rocket, 1), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), .8f));
			ENTITY::SET_ENTITY_COORDS(rocket, c.x, c.y, c.z, 0, 0, 0, 0);

			UI::HIDE_HUD_AND_RADAR_THIS_FRAME();
			PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 1);
			ENTITY::FREEZE_ENTITY_POSITION(PLAYER::PLAYER_PED_ID(), 1);
			UI::_BLOCK_WEAPON_WHEEL_THIS_FRAME();

			GRAPHICS::DRAW_RECT(0.5f, 0.5f - 0.025f, 0.050f, 0.002f, 255, 255, 255, 255);
			GRAPHICS::DRAW_RECT(0.5f, 0.5f + 0.025f, 0.050f, 0.002f, 255, 255, 255, 255);
			GRAPHICS::DRAW_RECT(0.5f - 0.025f, 0.5f, 0.002f, 0.050f, 255, 255, 255, 255);
			GRAPHICS::DRAW_RECT(0.5f + 0.025f, 0.5f, 0.002f, 0.050f, 255, 255, 255, 255);
			GRAPHICS::DRAW_RECT(0.5f + 0.05f, 0.5f, 0.050f, 0.002f, 255, 255, 255, 255);
			GRAPHICS::DRAW_RECT(0.5f - 0.05f, 0.5f, 0.050f, 0.002f, 255, 255, 255, 255);
			GRAPHICS::DRAW_RECT(0.5f, 0.5f + 0.05f, 0.002f, 0.050f, 255, 255, 255, 255);
			GRAPHICS::DRAW_RECT(0.5f, 0.5f - 0.05f, 0.002f, 0.050f, 255, 255, 255, 255);
			GRAPHICS::SET_TIMECYCLE_MODIFIER("CAMERA_secuirity");

			GRAPHICS::DRAW_RECT(0.25f, 0.5f, 0.03f, 0.5f, 255, 255, 255, 255);
			static auto ticker = GetTickCount();
			if (GetTickCount() - ticker >= 100) {
				bar -= .01f; y -= 4; ticker = GetTickCount();
			}
			GRAPHICS::DRAW_RECT(0.25f, 0.75f - (bar / 2), 0.03f, bar, 255, y, 0, 255);

			float groundZ;
			GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(ENTITY::GET_ENTITY_COORDS(rocket, 1).x, ENTITY::GET_ENTITY_COORDS(rocket, 1).y, ENTITY::GET_ENTITY_COORDS(rocket, 1).z, &groundZ, 0);
			if (ENTITY::HAS_ENTITY_COLLIDED_WITH_ANYTHING(rocket) ||
				(std::abs(ENTITY::GET_ENTITY_COORDS(rocket, 1).z - groundZ) < .5f) ||
				bar <= 0.01) {
				auto impact_coord = ENTITY::GET_ENTITY_COORDS(rocket, 1); ENTITY::FREEZE_ENTITY_POSITION(PLAYER::PLAYER_PED_ID(), 0);
				FIRE::ADD_EXPLOSION(impact_coord.x, impact_coord.y, impact_coord.z, 0, 10.f, 1, 0, .4f);
				ENTITY::DELETE_ENTITY(&rocket);
				rocket = 0;
				PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 0);
				CAM::RENDER_SCRIPT_CAMS(0, true, 700, 1, 1);
				CAM::DESTROY_CAM(cam, 1);
				GRAPHICS::SET_TIMECYCLE_MODIFIER("DEFAULT");
				init = false;
			}
		}
	}
	if (!VALKYIREROCKET) {
		CAM::DESTROY_CAM(cam, 1);
		PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 0);
		rocket = 0;
		bar = .5f;
		y = 255;
		ENTITY::FREEZE_ENTITY_POSITION(PLAYER::PLAYER_PED_ID(), 0);
	}
}

void Features::removeLoading() {
	if (UI::_IS_LOADING_PROMPT_BEING_DISPLAYED()) {
		UI::_REMOVE_LOADING_PROMPT();
	}
}

//THEMES
//Self info

void Features::wait(int milliseconds)
{
	clock_t time_end;
	time_end = clock() + milliseconds * CLOCKS_PER_SEC / 1000;
	while (clock() < time_end) {}
}

int bomber_ting;
Vector3 bomb_coords;
bool bomber_cooldown;
bool bomber_countdown;
bool Features::bomber = false;
void Features::bomber_mode() {
	if (PED::IS_PED_IN_ANY_HELI(PLAYER::PLAYER_PED_ID()) || PED::IS_PED_IN_ANY_PLANE(PLAYER::PLAYER_PED_ID())) {
		Vector3 c = ENTITY::GET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 1);
		GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(c.x, c.y, c.z, &c.z, 0);
		if (!bomber_countdown)
			bomb_coords = c;
		GRAPHICS::DRAW_MARKER(6, bomb_coords.x, bomb_coords.y, bomb_coords.z, 0.f, 0.f, 0.f, 90.f, 0.f, 0.f, 15.f, 15.f, 15.f, 255, 0, 0, 150, 0, 0, 0, 0, NULL, NULL, 0);

		static auto ticker = GetTickCount();
		if (bomber_cooldown) {
			if ((GetTickCount() - ticker) >= 3500) {
				bomber_cooldown = false;
				ticker = GetTickCount();
			}
		}

		static auto ticcker = GetTickCount();
		if (bomber_countdown) {
			if ((GetTickCount() - ticcker) >= 1500) {
				FIRE::ADD_EXPLOSION(bomb_coords.x, bomb_coords.y, bomb_coords.z, ExplosionTypeBlimp, 10.f, true, false, 0.f);
				//notifyBottom("~g~Completed.");
				bomber_ting = 0;
				bomber_countdown = false;
				ticcker = GetTickCount();
			}
		}

		if (IsKeyPressed(VK_SPACE) && !bomber_cooldown) {
			ticcker = GetTickCount();
			ticker = GetTickCount();
			//notifyBottom("~s~Wait...");
			bomb_coords = c;
			bomber_countdown = true;
			bomber_cooldown = true;
		}
	}
}

bool Features::ride_container = false;
void Features::container_rider() {
	static Object container;
	auto selfVeh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	Vector3 min, max;
	Vector3 cmin, cmax;
	Vector3 c = ENTITY::GET_ENTITY_COORDS(selfVeh, 1);

	GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(selfVeh), &min, &max);
	GAMEPLAY::GET_MODEL_DIMENSIONS($("prop_container_01a"), &cmin, &cmax);

	if (!PED::IS_PED_ON_ANY_BIKE(PLAYER::PLAYER_PED_ID())) {
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
			//notifyBottom("~r~Container rider requires a bike.");
			return;
		}
	}

	if (!STREAMING::HAS_MODEL_LOADED($("prop_container_01a")))
		STREAMING::REQUEST_MODEL($("prop_container_01a"));

	if (!ENTITY::DOES_ENTITY_EXIST(container) || !VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(selfVeh)) {
		static auto tickeer = GetTickCount();
		if ((GetTickCount() - tickeer) >= 1000) {
			if (CONTROLS::IS_CONTROL_PRESSED(2, INPUT_VEH_FLY_PITCH_UP_ONLY)) {
				tickeer = GetTickCount();
				ENTITY::APPLY_FORCE_TO_ENTITY(selfVeh, 0, 0, 0, 1.5, 0, 0, 0, 0, 1, 1, 1, 0, 1);
			}
		}
		static auto ticker = GetTickCount();
		if (ENTITY::DOES_ENTITY_EXIST(container)) {
			RequestControlOfEnt(container);
			ENTITY::SET_ENTITY_COORDS(container, 0.f, 0.f, 0.f, 1, 1, 1, 0);
			ENTITY::DELETE_ENTITY(&container);
			OBJECT::DELETE_OBJECT(&container);
		}
		container = OBJECT::CREATE_OBJECT($("prop_container_01a"), c.x, c.y, c.z - ((max.z / 2) + cmax.z), 1, 1, 0);
		ENTITY::SET_ENTITY_ROTATION(container, ENTITY::GET_ENTITY_PITCH(selfVeh), 0.f, ENTITY::GET_ENTITY_HEADING(selfVeh), 0, 0);
	}
}

Entity rope_ent0;
Object first_rope;
bool attached_first;
Ped myped;
Entity ENT, ENT2, TargettedEntity, TargettedEntity2;
Vector3 shootcoords;
Object ropes;
Vector3 handcoords;
int teleportActiveLineIndex = 0, bone = 0, onec = 0, MaxRadius = 8, MarkerRed = 255, markergreen = 60, markerblue = 0;
bool attach5 = false;
bool Features::ROPEGUN = false;
static float dist(Vector3 p1, Vector3 p2)
{
	float x = p1.x - p2.x;
	float y = p1.y - p2.y;
	float z = p1.z - p2.z;
	return SYSTEM::SQRT(x*x + y * y + z * z);
}
void Features::ropegun() {
	/*
	auto camCoords = CAM::GET_GAMEPLAY_CAM_COORD();
	auto farCoords = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), 100.f));
	BOOL hit; Vector3 endCoords; Vector3 surfaceNormal; Entity ent = 0;
	PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &ent);
	auto ray = WORLDPROBE::_START_SHAPE_TEST_RAY(camCoords.x, camCoords.y, camCoords.z, farCoords.x, farCoords.y, farCoords.z, -1, PLAYER::PLAYER_PED_ID(), 7);
	WORLDPROBE::GET_SHAPE_TEST_RESULT(ray, &hit, &endCoords, &surfaceNormal, &ent);
	notifyMap(("Entity: " + std::to_string(ent) + " Ray: " + std::to_string(ray) + " Hit: " + std::to_string(hit)).c_str());
	if (CONTROLS::IS_CONTROL_PRESSED(2, INPUT_AIM) || IsKeyPressed(VK_RBUTTON)) {
		if (ENTITY::DOES_ENTITY_EXIST(ent) && (ENTITY::IS_ENTITY_A_PED(ent) || ENTITY::IS_ENTITY_A_VEHICLE(ent) || ENTITY::IS_ENTITY_AN_OBJECT(ent))) {
			if (is_ped_shooting(PLAYER::PLAYER_PED_ID())) {
				ROPE::ROPE_LOAD_TEXTURES();
				auto pweapon = WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID());
				auto pwep_coord = ENTITY::GET_ENTITY_COORDS(pweapon, 1);
				if (!attached_first) {
					first_rope = ROPE::ADD_ROPE(pwep_coord.x, pwep_coord.y, pwep_coord.z, 0, 0, 0,
						distanceBetween(ENTITY::GET_ENTITY_COORDS(ent, 1), pwep_coord), 1, 300, 0.5f, 0.5f, false, true, true, 1.0f, false, 0);
					Vector3 c0 = pwep_coord;
					Vector3 c1 = ENTITY::GET_ENTITY_COORDS(ent, 1);
					ROPE::ATTACH_ENTITIES_TO_ROPE(first_rope, pweapon, ent, c0.x, c0.y, c0.z, c1.x, c1.y, c1.z, distanceBetween(ENTITY::GET_ENTITY_COORDS(ent, 1), pwep_coord) + 40.f, 0, 0, NULL, NULL);
					ROPE::ACTIVATE_PHYSICS(first_rope);
					rope_ent0 = ent;
					attached_first = true;
				}
				else {
					ROPE::DELETE_ROPE(&first_rope);
					Vector3 c0 = ENTITY::GET_ENTITY_COORDS(rope_ent0, 1);
					Vector3 c1 = ENTITY::GET_ENTITY_COORDS(ent, 1);
					first_rope = ROPE::ADD_ROPE(pwep_coord.x, pwep_coord.y, pwep_coord.z, 0, 0, 0,
						distanceBetween(ENTITY::GET_ENTITY_COORDS(rope_ent0, 1), ENTITY::GET_ENTITY_COORDS(ent, 1)), 1, 300, 0.5f, 0.5f, false, true, true, 1.0f, false, 0);
					ROPE::ACTIVATE_PHYSICS(first_rope);
					ROPE::ATTACH_ENTITIES_TO_ROPE(first_rope, rope_ent0, ent, c0.x, c0.y, c0.z, c1.x, c1.y, c1.z, distanceBetween(ENTITY::GET_ENTITY_COORDS(rope_ent0, 1), ENTITY::GET_ENTITY_COORDS(ent, 1)), 0, 0, NULL, NULL);
					first_rope = NULL;
					attached_first = false;
				}
			}
		}
	}
	else { ROPE::DELETE_ROPE(&first_rope); attached_first = false; }*/

	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &ENT))
	{
		myped = PLAYER::PLAYER_PED_ID();
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(myped, &shootcoords))
		{
			if (ENT != 0)
			{
				if (!attach5)
				{
					bone = PED::GET_PED_BONE_INDEX(myped, 28422);
					handcoords = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(myped, bone);

					Vector3 coords1 = ENTITY::GET_ENTITY_COORDS(ENT, true);

					ropes = ROPE::ADD_ROPE(handcoords.x, handcoords.y, handcoords.z, shootcoords.x, shootcoords.y, shootcoords.z, dist(handcoords, coords1) + 3.0f, 1, 300, 0.5f, 0.5f, false, true, true, 1.0f, false, 0);
					ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&ropes);

					ROPE::ACTIVATE_PHYSICS(ropes);

					ROPE::ROPE_LOAD_TEXTURES();
					if (ROPE::ROPE_ARE_TEXTURES_LOADED())
					{

					}
					ENT2 = ENT;
					attach5 = true;
				}
				else
				{
					Vector3 coords1 = ENTITY::GET_ENTITY_COORDS(ENT, true);
					Vector3 coords2 = ENTITY::GET_ENTITY_COORDS(ENT2, true);
					float speed = ENTITY::GET_ENTITY_SPEED(ENT2);

					if (speed < 3.0f)
					{
						ROPE::ATTACH_ENTITIES_TO_ROPE(ropes, ENT, ENT2, coords1.x, coords1.y, coords1.z, coords2.x, coords2.y, coords2.z, dist(coords1, coords2) + 1.0f, false, false, 0, 0);
					}
					else

					{
						ROPE::ATTACH_ENTITIES_TO_ROPE(ropes, ENT, ENT2, coords1.x, coords1.y, coords1.z, coords2.x, coords2.y, coords2.z, dist(coords1, coords2) + 3.3f, false, false, 0, 0);
					}
					attach5 = false;
				}
			}
		}
	}
}

bool Features::CARTOONGUN = false;
void Features::cartoongun2()
{
	if (is_ped_shooting(PLAYER::PLAYER_PED_ID())) {
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		while (!STREAMING::HAS_NAMED_PTFX_ASSET_LOADED("scr_rcbarry2")) WAIT(0);

		auto w = WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID());
		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(WEAPON::GET_SELECTED_PED_WEAPON(PLAYER::PLAYER_PED_ID()), &v0, &v1);
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_rcbarry2");
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_ENTITY_2("muz_clown", w, (v0.x - v1.x) / 2.0f + 0.7f, 0.f, 0.f, 0.f, 180.f, 0.f, 1.f, 1, 1, 1);
	}
}

Vector3 add3(Vector3* vectorA, Vector3* vectorB)
{
	Vector3 result;
	result.x = vectorA->x;
	result.y = vectorA->y;
	result.z = vectorA->z;

	result.x += vectorB->x;
	result.y += vectorB->y;
	result.z += vectorB->z;

	return result;
}
Vector3 multiply3(Vector3* vector, float x)
{
	Vector3 result;
	result.x = vector->x;
	result.y = vector->y;
	result.z = vector->z;

	result.x *= x;
	result.y *= x;
	result.z *= x;

	return result;
}
Vector3 rotDirection(Vector3* rot)
{
	float radianz = rot->z * 0.0174532924f;
	float radianx = rot->x * 0.0174532924f;
	float num = std::abs((float)std::cos((double)radianx));

	Vector3 dir;

	dir.x = (float)((double)((float)(-(float)std::sin((double)radianz))) * (double)num);
	dir.y = (float)((double)((float)std::cos((double)radianz)) * (double)num);
	dir.z = (float)std::sin((double)radianx);

	return dir;
}
bool Features::leagun = false;
void Features::leaWgun() {

	Ped playerPed = PLAYER::PLAYER_PED_ID();
	float startDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	float endDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	startDistance += 5.25;
	endDistance += 1000.0;
	if (is_ped_shooting(playerPed) && PED::GET_PED_CONFIG_FLAG(playerPed, 58, 1))
	{
		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_ENEMY_LASER");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).z, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).z, 250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
	}
}

//Walk style chooser

//Legacy protex

//New protex

void Features::CloneVehicle(Player p)
{
	int model = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 1);
	STREAMING::REQUEST_MODEL(VEHICLE::GET_VEHICLE_LAYOUT_HASH(model));
	if (!STREAMING::HAS_MODEL_LOADED(VEHICLE::GET_VEHICLE_LAYOUT_HASH(model))) {
		WAIT(0);
	}
	else {
		if (STREAMING::IS_MODEL_A_VEHICLE(VEHICLE::GET_VEHICLE_LAYOUT_HASH(model)))
		{
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 1);
			Vehicle veh = VEHICLE::CREATE_VEHICLE(VEHICLE::GET_VEHICLE_LAYOUT_HASH(model), coords.x, coords.y, coords.z, 1.0f, 1, 1);
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
			spawned[spawnIndex] = veh;
			spawnedHash[spawnIndex] = model;
			spawnIndex++;
		}
	}
}

//TO DO: FIX!

bool Features::vehicleNames = false;

bool Features::meme = false;
int Features::memeId = 2;
std::string memee = "";
void Features::memes(int memeId) {
	switch (memeId) {
	case 0: memee = "kkk"; break;
	case 1: memee = "martin"; break;
	case 2: memee = "kek"; break;
	case 3: memee = "thibault"; break;
	case 4: memee = "verti"; break;
	default: memee = ""; break;
	}
	Menu::Drawing::Spriter("customheader", memee, Menu::Settings::menuX + 0.3f, 0.2f, 0.11f, 0.15f, 0, 255, 255, 255, 255);
}

void Features::set_network_time(int h, int m, int s) {
	Hooking::ClockTime->hour = h;
	Hooking::ClockTime->minute = m;
	Hooking::ClockTime->second = s;
	Hooking::set_session_time(4, 0);
}

bool Features::spamTime = false;
bool tstimer = false;
void Features::timespam() {
	if (!tstimer) {
		Features::set_network_time(12, 0, 0);
		tstimer = true;
	}
	else {
		Features::set_network_time(23, 0, 0);
		tstimer = false;
	}
}

bool Features::sync2 = false;
void Features::syncTime2() {
	time_t now = time(0);
	tm t;
	localtime_s(&t, &now);
	Features::set_network_time(t.tm_hour, t.tm_min, t.tm_sec);
}

/*
1 = Superkick I
2 = Superkick II
3 = Superkick III
4 = Superkick IV
5 = Non-Host kick
6 = SP kick
*/
void Features::kickPlayer(Player p, int kickType) {
	Ped player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	unsigned int Bit = (1 << p);
	if (kickType == 1) {
		uint64_t args[4] = { 2055958901, player, 5, 0 };
		Hooking::trigger_script_event(1, args, 4, Bit);
	}
	else if (kickType == 2) {
		uint64_t args[4] = { 994306218, player, 5, 0 };
		Hooking::trigger_script_event(1, args, 4, Bit);
	}
	else if (kickType == 3) {
		uint64_t args[3] = { -120668417, player, 48 };
		Hooking::trigger_script_event(1, args, 3, Bit);
	}
	else if (kickType == 4) {
		uint64_t args[4] = { -1835749229, player, -1, 0 };
		Hooking::trigger_script_event(1, args, 4, Bit);
	}
	else if (kickType == 5) {
		uint64_t args[2] = { 2077565911, player };
		Hooking::trigger_script_event(1, args, 2, Bit);
	}
	else if (kickType == 6) {
		uint64_t args[2] = { 4156321, player };
		Hooking::trigger_script_event(1, args, 2, Bit);
	}
	else if (kickType == 7) {
		uint64_t args[2] = { -1662909539, player };
		Hooking::trigger_script_event(1, args, 2, Bit);
	}
	else if (kickType == 8) {
		uint64_t args[2] = { 256346004, player };
		Hooking::trigger_script_event(1, args, 2, Bit);
	}
	else if (kickType == 9) {
		uint64_t args[2] = { -15432926, player };
		Hooking::trigger_script_event(1, args, 2, Bit);
	}
	else if (kickType == 10) {
		uint64_t args[2] = { -1243184386, player };
		Hooking::trigger_script_event(1, args, 2, Bit);
	}
	else if (kickType == 11) {
		uint64_t args[2] = { 1642479322, player };
		Hooking::trigger_script_event(1, args, 2, Bit);
	}
	else if (kickType == 12) {
		uint64_t args[2] = { 27391769, player };
		Hooking::trigger_script_event(1, args, 2, Bit);
	}
	else if (kickType == 13) {
		uint64_t args[2] = { -2136787743, player };
		Hooking::trigger_script_event(1, args, 2, Bit);
	}
	else if (kickType == 14) {
		uint64_t args[2] = { -1289983205, player };
		Hooking::trigger_script_event(1, args, 2, Bit);
	}
	else if (kickType == 15) {
		uint64_t args[2] = { 1586576930, player };
		Hooking::trigger_script_event(1, args, 2, Bit);
	}
	else if (kickType == 16) {
		uint64_t args[2] = { 1093247513, player };
		Hooking::trigger_script_event(1, args, 2, Bit);
	}
	else if (kickType == 17) {
		uint64_t args[2] = { 2021867503, player };
		Hooking::trigger_script_event(1, args, 2, Bit);
	}
	else if (kickType == 18) {
		uint64_t args[2] = { -1184085326, player };
		Hooking::trigger_script_event(1, args, 2, Bit);
	}
	else if (kickType == 19) {
		uint64_t args[2] = { -1996885757, player };
		Hooking::trigger_script_event(1, args, 2, Bit);
	}
	else if (kickType == 20) {
		uint64_t args[2] = { 1178932519, player };
		Hooking::trigger_script_event(1, args, 2, Bit);
	}
	else if (kickType == 21) {
		uint64_t args[2] = { 813647057, player };
		Hooking::trigger_script_event(1, args, 2, Bit);
	}
	else if (kickType == 22) {
		uint64_t args[4] = { 769347061, player, 0, 0 };
		Hooking::trigger_script_event(1, args, 4, Bit);
	}
	else if (kickType == 23) {
		uint64_t args[4] = { 999090520, player, 0, 0 };
		Hooking::trigger_script_event(1, args, 4, Bit);
	}

	/*
	2077565911              globalHandle(1382674).At(16).As<int>() = 16;
	4156321                 globalHandle(1382674).At(21).As<int>() = 21;
	-1662909539             globalHandle(1382674).At(677).As<int>() = 677;
	256346004               globalHandle(1382674).At(601).As<int>() = 601;
	-15432926               globalHandle(1382674).At(23).As<int>() = 23;
	-1243184386             globalHandle(1382674).At(24).As<int>() = 24;
	1642479322              globalHandle(1382674).At(582).As<int>() = 582;
	27391769                globalHandle(1382674).At(599).As<int>() = 599;
	-2136787743             globalHandle(1382674).At(577).As<int>() = 577;
	-1289983205             globalHandle(1382674).At(576).As<int>() = 576;
	1586576930              globalHandle(1382674).At(532).As<int>() = 532;
	1093247513              globalHandle(1382674).At(688).As<int>() = 688;
	2021867503              globalHandle(1382674).At(455).As<int>() = 455;
	-1184085326             globalHandle(1382674).At(449).As<int>() = 449;
	-1996885757             globalHandle(1382674).At(336).As<int>() = 336;
	1178932519              globalHandle(1382674).At(294).As<int>() = 294;
	813647057               globalHandle(1382674).At(694).As<int>() = 694;
	*/
}

//Wave intensity

//Rain intensity

//Wind speed

//Wind direction

//Minimap zoom

std::string Features::VEHICLE_NAMES[656] = {
	"DINGHY", "DINGHY2", "DINGHY3", "DINGHY4", "JETMAX",
	"MARQUIS", "PREDATOR", "SEASHARK", "SEASHARK2", "SEASHARK3",
	"SPEEDER", "SPEEDER2", "SQUALO", "SUBMERSIBLE", "SUBMERSIBLE2",
	"SUNTRAP", "TORO", "TORO2", "TROPIC", "TROPIC2",
	"TUG", "BENSON", "BIFF", "HAULER", "MULE", "MULE2",
	"MULE3", "PACKER", "PHANTOM", "POUNDER", "STOCKADE",
	"STOCKADE3", "cerberus", "cerberus2", "cerberus3",
	"BLISTA", "BRIOSO", "DILETTANTE", "DILETTANTE2", "ISSI2",
	"PANTO", "PRAIRIE", "RHAPSODY", "issi3", "issi4", "issi5",
	"issi6", "COGCABRIO", "EXEMPLAR", "F620", "FELON", "FELON2",
	"JACKAL", "ORACLE", "ORACLE2", "SENTINEL", "SENTINEL2",
	"WINDSOR", "WINDSOR2", "ZION", "ZION2", "sentinel3",
	"BMX", "CRUISER", "FIXTER", "SCORCHER", "TRIBIKE",
	"TRIBIKE2", "TRIBIKE3", "ANNIHILATOR", "BLIMP", "BLIMP2", "BUZZARD", "BUZZARD2",
	"CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER",
	"FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT",
	"SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE",
	"VALKYRIE2", "VOLATUS", "HUNTER", "havok", "blimp3", "seasparrow",
	"AMBULANCE", "FBI", "FBI2", "FIRETRUK", "LGUARD",
	"PBUS", "PRANGER", "POLICE", "POLICE2", "POLICE3",
	"POLICE4", "POLICEB", "POLICEOLD1", "POLICEOLD2", "POLICET",
	"SHERIFF", "SHERIFF2", "RIOT", "riot2", "BULLDOZER", "CUTTER", "DUMP",
	"FLATBED", "GUARDIAN", "HANDLER", "MIXER", "MIXER2", "RUBBLE", "TIPTRUCK",
	"TIPTRUCK2", "BARRACKS", "BARRACKS2", "BARRACKS3", "CRUSADER", "RHINO",
	"APC", "DUNE3", "HALFTRACK", "chernobog", "khanjali",
	"scarab", "scarab2", "scarab3", "thruster", "AKUMA", "AVARUS",  "BF400",
	"CARBONRS", "CHIMERA", "CLIFFHANGER", "DAEMON",
	"DAEMON2", "DEFILER", "DOUBLE", "ENDURO", "ESSKEY",
	"FAGGIO", "FAGGIO2", "FAGGIO3", "GARGOYLE", "HAKUCHOU",
	"HAKUCHOU2", "HEXER", "INNOVATION", "LECTRO", "MANCHEZ",
	"NEMESIS", "NIGHTBLADE", "PCJ", "RATBIKE", "RUFFIAN",
	"SANCHEZ", "SANCHEZ2", "SANCTUS", "SHOTARO", "SOVEREIGN",
	"THRUST", "VADER", "VINDICATOR", "VORTEX", "WOLFSBANE",
	"ZOMBIEA", "ZOMBIEB", "DIABLOUS", "DIABLOUS2", "FCR",
	"FCR2", "OPPRESSOR", "oppressor2", "deathbike", "deathbike2",
	"deathbike3", "BTYPE", "BTYPE2", "BTYPE3", "CASCO", "COQUETTE2",
	"FELTZER3", "JB700", "MAMBA", "MANANA", "MONROE",
	"PEYOTE", "PIGALLE", "STINGER", "STINGERGT", "TORNADO",
	"TORNADO2", "TORNADO3", "TORNADO4", "TORNADO5", "TORNADO6",
	"ZTYPE", "INFERNUS2", "TURISMO2", "rapidgt3", "retinue",
	"swinger", "ARDENT", "TORERO", "fagaloa", "flashgt",
	"michelli", "deluxo", "stromberg", "savestra", "viseris",
	"gt500", "z190", "BLADE", "BUCCANEER", "BUCCANEER2", "CHINO", "CHINO2",
	"COQUETTE3", "DOMINATOR", "DOMINATOR2", "DUKES", "DUKES2",
	"GAUNTLET", "GAUNTLET2", "FACTION", "FACTION2", "FACTION3",
	"HOTKNIFE", "LURCHER", "MOONBEAM", "MOONBEAM2", "NIGHTSHADE",
	"PHOENIX", "PICADOR", "RATLOADER", "RATLOADER2", "RUINER", "RUINER2", "RUINER3",
	"SABREGT", "SABREGT2", "SLAMVAN", "SLAMVAN2", "SLAMVAN3",
	"STALION", "STALION2", "TAMPA", "VIGERO", "VIRGO",
	"VIRGO2", "VIRGO3", "VOODOO", "VOODOO2", "TAMPA3", "hermes", "dominator3",
	"dominator4", "dominator5", "dominator6", "slamvan4", "slamvan5", "slamvan6",
	"ellie", "impaler", "impaler2", "impaler3", "clique", "deviant", "tulip", "vamos",
	"hustler", "yosemite", "BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3",
	"BLAZER4", "BODHI2", "BRAWLER", "DLOADER", "DUBSTA3",
	"DUNE", "DUNE2", "INSURGENT", "INSURGENT2", "KALAHARI",
	"MARSHALL", "MESA3", "MONSTER", "RANCHERXL", "RANCHERXL2",
	"REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL",
	"TROPHYTRUCK", "TROPHYTRUCK2", "TECHNICAL2", "DUNE4", "DUNE5",
	"BLAZER5", "TECHNICAL3", "INSURGENT3", "NIGHTSHARK", "freecrawler",
	"menacer", "patriot2", "barrage", "monster3",
	"monster4", "monster5", "bruiser", "bruiser2", "bruiser3",
	"brutus", "brutus2", "brutus3", "kamacho", "riata",
	"BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
	"HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
	"MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
	"TITAN", "VELUM", "VELUM2", "VESTRA", "BOMBUSHKA",
	"MOLOTOK", "NOKOTA", "PYRO", "ROGUE", "SEABREEZE",
	"HOWARD", "MICROLIGHT", "TULA", "MOGUL", "STARLING",
	"ALPHAZ1", "strikeforce", "avenger", "volatol",
	"ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552",
	"COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3",
	"FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2",
	"PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO",
	"SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM",
	"STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARR", "stafford",
	"cheburek", "ALPHA", "BANSHEE", "BESTIAGTS", "BLISTA2", "BLISTA3",
	"BUFFALO", "BUFFALO2", "BUFFALO3", "CARBONIZZARE", "COMET2",
	"COQUETTE", "ELEGY", "ELEGY2", "FELTZER2", "FUROREGT", "FUSILADE",
	"FUTO", "JESTER", "JESTER2", "KHAMELION", "KURUMA",
	"KURUMA2", "LYNX", "MASSACRO", "MASSACRO2", "NINEF",
	"NINEF2", "OMNIS", "PENUMBRA", "RAPIDGT", "RAPIDGT2",
	"RAPTOR", "SCHAFTER3", "SCHAFTER4", "SCHWARTZER", "SEVEN70",
	"SULTAN", "SURANO", "SPECTER", "SPECTER2", "TAMPA2", "TROPOS", "VERLIERER2",
	"RUINER2", "PHANTOM2", "RUSTON", "comet4", "comet5", "jester3", "gb200",
	"hotring", "zr380", "zr3802", "zr3803", "schlagen", "italigto", "neon",
	"pariah", "raiden", "revolter", "ADDER", "BANSHEE2", "BULLET", "CHEETAH", "ENTITYXF",
	"FMJ", "SHEAVA", "INFERNUS", "NERO", "NERO2","OSIRIS", "LE7B",
	"ITALIGTB", "ITALIGTB2", "PFISTER811", "PROTOTIPO", "REAPER", "SULTANRS", "T20",
	"TEMPESTA", "TURISMOR", "TYRUS", "VACCA", "VOLTIC", "ZENTORNO", "VOLTIC2", "PENETRATOR", "GP1",
	"vigilante", "visione", "cyclone", "scramjet", "CHEETAH2", "VAGNER", "XA21", "autarch", "entity2",
	"taipan", "tezeract", "tyrant", "deveste", "sc1",
	"BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5",
	"BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER",
	"DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY",
	"HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2",
	"PATRIOT", "RADI", "ROCOTO", "SEMINOLE", "SERRANO",
	"XLS", "XLS2", "streiter", "toros", "CABLECAR", "FREIGHT",
	"FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2",
	"FREIGHTGRAIN", "METROTRAIN", "TANKERCAR",
	"ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER",
	"DOCKTRAILER", "FREIGHTTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER",
	"TANKER", "TANKER2", "TR2", "TR3", "TR4",
	"TRAILERLOGS", "TRAILERS", "TRAILERS2", "TRAILERS3", "TRAILERSMALL",
	"TRFLAT", "TVTRAILER", "TRAILERLARGE", "TRAILERS4", "TRAILERSMALL2",
	"AIRBUS", "BRICKADE", "BUS", "COACH", "RALLYTRUCK",
	"RENTALBUS", "TAXI", "TOURBUS", "TRASH", "TRASH2",
	"WASTELANDER", "pbus2", "AIRTUG", "CADDY", "CADDY2", "DOCKTUG", "FORKLIFT",
	"MOWER", "RIPLEY", "SADLER", "SADLER2", "SCRAP",
	"TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3",
	"UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3", "CADDY3",
	"rcbandito", "BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE",
	"BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BURRITO", "BURRITO2",
	"BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO",
	"GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2", "PARADISE",
	"PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3",
	"SPEEDO", "SPEEDO2", "SURFER", "SURFER2", "TACO",
	"YOUGA", "YOUGA2", "boxville", "stockade", "stockade2", "tiptruck", "tiptruck2",
	"cutter", "handler", "docktug", "dump", "biff", "hauler", "phantom",
	"rubble", "mule", "mixer", "mixer2", "flatbed", "packer", "pounder",
	"benson", "scrap", "phantom2", "hauler2", "phantom3", "pounder2",
	"speedo4", "mule4", "terbyte", "caracara"
};

void Features::SUPERKICK(Player p) {
	Ped player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	unsigned int Bit = (1 << p);

	uint64_t kicks[][4] = { 
		{ 2055958901, player, 5, 0 }, 
		{ 994306218, player, 5, 0 }, 
		{ -120668417, player, 48, 0 }, 
		{ -1835749229, player, -1, 0 },
		{ 2077565911, player, 0, 0 },
		{ 4156321, player, 0, 0 },
		{ -1662909539, player, 0, 0 },
		{ 256346004, player, 0, 0 },
		{ -15432926, player, 0, 0 },
		{ -1243184386, player, 0, 0 },
		{ 1642479322, player, 0, 0 },
		{ 27391769, player, 0, 0 },
		{ -2136787743, player, 0, 0 },
		{ -1289983205, player, 0, 0 },
		{ 1586576930, player, 0, 0 },
		{ 1093247513, player, 0, 0 },
		{ 2021867503, player, 0, 0 },
		{ -1184085326, player, 0, 0 },
		{ -1996885757, player, 0, 0 },
		{ 1178932519, player, 0, 0 },
		{ 813647057, player, 0, 0 },
		{ 769347061, player, 0, 0 },
		{ 999090520, player, 0, 0 }
	};

	uint64_t args1[4] = { 2055958901, player, 5, 0 };
	uint64_t args2[4] = { 994306218, player, 5, 0 };
	uint64_t args3[3] = { -120668417, player, 48 };
	uint64_t args4[4] = { -1835749229, player, -1, 0 };
	uint64_t args5[2] = { 2077565911, player };
	uint64_t args6[2] = { 4156321, player };
	uint64_t args7[2] = { -1662909539, player };
	uint64_t args8[2] = { 256346004, player };
	uint64_t args9[2] = { -15432926, player };
	uint64_t args10[2] = { -1243184386, player };
	uint64_t args11[2] = { 1642479322, player };
	uint64_t args12[2] = { 27391769, player };
	uint64_t args13[2] = { -2136787743, player };
	uint64_t args14[2] = { -1289983205, player };
	uint64_t args15[2] = { 1586576930, player };
	uint64_t args16[2] = { 1093247513, player };
	uint64_t args17[2] = { 2021867503, player };
	uint64_t args18[2] = { -1184085326, player };
	uint64_t args19[2] = { -1996885757, player };
	uint64_t args20[2] = { 1178932519, player };
	uint64_t args21[2] = { 813647057, player };
	uint64_t args22[4] = { 769347061, player, 0, 0 };
	uint64_t args23[4] = { 999090520, player, 0, 0 };

	Hooking::trigger_script_event(1, args1, 4, Bit);
	Hooking::trigger_script_event(1, args2, 4, Bit);	
	Hooking::trigger_script_event(1, args3, 3, Bit);	
	Hooking::trigger_script_event(1, args4, 4, Bit);	
	Hooking::trigger_script_event(1, args5, 2, Bit);	
	Hooking::trigger_script_event(1, args6, 2, Bit);	
	Hooking::trigger_script_event(1, args7, 2, Bit);	
	Hooking::trigger_script_event(1, args8, 2, Bit);	
	Hooking::trigger_script_event(1, args9, 2, Bit);	
	Hooking::trigger_script_event(1, args10, 2, Bit);	
	Hooking::trigger_script_event(1, args11, 2, Bit);
	Hooking::trigger_script_event(1, args12, 2, Bit);	
	Hooking::trigger_script_event(1, args13, 2, Bit);
	Hooking::trigger_script_event(1, args14, 2, Bit);	
	Hooking::trigger_script_event(1, args15, 2, Bit);
	Hooking::trigger_script_event(1, args16, 2, Bit);	
	Hooking::trigger_script_event(1, args17, 2, Bit);
	Hooking::trigger_script_event(1, args18, 2, Bit);
	Hooking::trigger_script_event(1, args19, 2, Bit);
	Hooking::trigger_script_event(1, args20, 2, Bit);
	Hooking::trigger_script_event(1, args21, 2, Bit);
	Hooking::trigger_script_event(1, args22, 4, Bit);
	Hooking::trigger_script_event(1, args23, 4, Bit);
}


//Show instructions
bool Features::show_tips = true;

//Loading text
//Custom text

void Features::setplayername666(std::string& name)
{
	size_t newLen = name.size() + 1;
	if (newLen <= 1 || newLen > 20)
		return;
	char    buffer[0x20] = {};
	char*    pSearch = (char*)Hooking::mon + 0x5C;
	size_t    curLen = strlen(pSearch) + 1;
	strncpy_s(buffer, pSearch, curLen);
	for (uint32_t i = 0, found = 0, match = 0; found < 4; ++pSearch)
	{
		if (*pSearch != buffer[i])
			goto LABEL_RESET;
		if (++match < curLen)
		{
			++i;
			continue;
		}
		strncpy_s(pSearch - i, newLen, &name[0], newLen);
		++found;
	LABEL_RESET:
		i = match = 0;
	}
	strncpy(Hooking::GPN(PLAYER::PLAYER_ID()), &name[0], newLen);
}

char* CharKeyboard1(char* windowName = "", int maxInput = 21, char* defaultText = "")
{
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return "";
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}

std::string get_ingame_keyboard_result()
{
	std::string    r = "!!INVALID!!";
	if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD())
	{
		char* pCh = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
		if (pCh != nullptr)
			r = pCh;
	}
	return r;
}

void Features::NameChangerybold()
{
	CharKeyboard1("", 21, "");
	std::string str = get_ingame_keyboard_result();
	if (str != "!!INVALID!!" && str != "")
	{
		setplayername666(str);
	}
}

void Features::saveName() {
	std::string config = "X-Folder/title/config.ini";
	INI::WriteBool(config, true, "name", "saved");
	if (INI::GetBool(config, "name", "saved") == true) {
		INI::WriteChar(config, PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID()), "name", "playername");
	}
}

void Features::loadName() {
	std::string config = "X-Folder/title/config.ini";
	if (INI::GetBool(config, "name", "saved") == true) {
		ostringstream namee; namee << INI::GetChar(config, "name", "playername");
		Features::setplayername666(namee.str());
	}
}

void Features::resetName() {
	std::string config = "X-Folder/title/config.ini";
	INI::WriteBool(config, false, "name", "saved");
	INI::WriteChar(config, "", "name", "playername");
}

bool Features::sp_level = false;
bool Features::sp_wmoney = false;
bool Features::sp_bmoney = false;
bool Features::sp_kd = false;
bool Features::sp_kills = false;
bool Features::sp_deaths = false;

void Features::spoofLevel() {
	globalHandle(1589747).At(PLAYER::PLAYER_ID(), 790).At(211).At(6).As<int>() = rndInt(0, 8000);
}

void Features::spoofWalletMoney() {
	globalHandle(1589747).At(PLAYER::PLAYER_ID(), 790).At(211).At(3).As<int>() = rndInt(0, 1000000);
}

void Features::spoofBankMoney() {
	globalHandle(1589747).At(PLAYER::PLAYER_ID(), 790).At(211).At(56).As<int>() = rndInt(0, 2147483647);
}

void Features::spoofKD() {
	globalHandle(1589747).At(PLAYER::PLAYER_ID(), 790).At(211).At(26).As<float>() = rndInt(0, 1000000);
}

void Features::spoofKills() {
	globalHandle(1589747).At(PLAYER::PLAYER_ID(), 790).At(211).At(28).As<int>() = rndInt(0, 1000000);
}

void Features::spoofDeaths() {
	globalHandle(1589747).At(PLAYER::PLAYER_ID(), 790).At(211).At(29).As<int>() = rndInt(0, 1000000);
}


//4.1

int Features::remoteGunId = 0;
uint64_t Features::remoteGunEvent[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
bool Features::remoteGunOn = false;
bool Features::remoteGunSomething = false;
bool Features::remoteGunKek = false;
void Features::remoteGun(uint64_t evId, uint64_t args[8], bool a3, bool a4) {
	Entity AimedAtEntity;
	uint64_t arg3 = args[0];
	uint64_t arg6 = args[3];
	uint64_t arg7 = args[4];
	uint64_t arg8 = args[5];
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &AimedAtEntity) && IsKeyPressed(VK_LBUTTON)) {
		if (PED::IS_PED_A_PLAYER(AimedAtEntity)) {
			for (int i = 0; i < 33; i++) {
				if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == AimedAtEntity) {
					unsigned int Bit = (1 << i);

					if (a3) {
						arg6 = globalHandle(1625435 + 1 + i * 560 + 491).As<std::uint64_t>();
						arg7 = globalHandle(1643357 + 9).As<std::uint64_t>();
						arg8 = globalHandle(1643357 + 9).As<std::uint64_t>();
					}
					else {
						arg6 = args[3];
						arg7 = args[4];
						arg8 = args[5];
					}

					if (a4) {
						arg3 = globalHandle(1625435).At(i, 560).At(491).As<std::uint64_t>();
					}
					else {
						arg3 = args[0];
					}

					uint64_t evvv[10] = { 
						evId, 
						PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 
						arg3, 
						args[1], 
						args[2], 
						arg6, 
						arg7, 
						arg8, 
						args[6], 
						args[7] 
					};
					Hooking::trigger_script_event(1, evvv, 10, Bit);
				}
			}
		}
	}
}

void Features::shootRemotes() {
	uint64_t currentArgs[8] = {
		remoteGunEvent[1],
		remoteGunEvent[2],
		remoteGunEvent[3],
		remoteGunEvent[4],
		remoteGunEvent[5],
		remoteGunEvent[6],
		remoteGunEvent[7],
		remoteGunEvent[8]
	};
	if (remoteGunEvent[0] != 0) {
		Features::remoteGun(remoteGunEvent[0], currentArgs, Features::remoteGunSomething, Features::remoteGunKek);
	}
}

//4.1 stuff

bool Features::requestModel(Hash model) {
	STREAMING::REQUEST_MODEL(model);
	while (!STREAMING::HAS_MODEL_LOADED(model)) {
		WAIT(0);
	}	
	return STREAMING::HAS_MODEL_LOADED(model);
}

bool Features::requestModel(std::string model) {
	return requestModel($(model));
}

bool Features::requestModel(char* model) {
	return requestModel(GAMEPLAY::GET_HASH_KEY(model));
}

bool Features::meowBool = false;
void Features::meowGun() {
	if (is_ped_shooting(PLAYER::PLAYER_PED_ID()))
	{
		Vector3 impact;
		DWORD meow = 1462895032;
		STREAMING::REQUEST_MODEL(meow);
		while (!STREAMING::HAS_MODEL_LOADED(meow)) WAIT(0);		
		WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &impact);
		PED::CREATE_PED(PED_TYPE_ANIMAL, meow, impact.x, impact.y, impact.z + 0.1f, 0, 1, 1);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(meow);
	}
}

int betrag(int value) {
	int retVal;
	value < 0 ? retVal = -value : retVal = value;
	return retVal;
}

void Features::kekbounty(Player p) {
	unsigned int Bit = (1 << p);
	uint64_t args[22] = { 1808125173, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 1, 1, 1000, 789142565, 0, 2074542339, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3465936598, 4024822600 };
	Hooking::trigger_script_event(1, args, 22, Bit);
}

bool Features::is_player_valid1(Ped ped) {
	for (int i = 0; i < 33; i++) {
		if (ped == PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)) {
			char* pname = PLAYER::GET_PLAYER_NAME(i);
			if (pname != "**Invalid**" && 
				pname != "**invalid**" && 
				pname != "**INVALID**") 
			{
				return true;
			}
		}
	}
	return false;
}

bool Features::is_player_valid2(Player player) {
	char* pname = PLAYER::GET_PLAYER_NAME(player);
	if (pname != "**Invalid**" &&
		pname != "**invalid**" &&
		pname != "**INVALID**")
	{
		return true;
	}
	return false;
}

const char* Features::translate(std::string key) {
	std::string trans = "X-Folder/translations/English.ini";
	std::string output = INI::GetString(trans, "0", key);
	return output.c_str();
}

void Features::stealthMoney(int amount) {
	if (Features::stealthAmount < 10000001) {
		Any var0 = rndInt(0, INT_MAX);
		UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, Features::removee ? -1359375127 : 312105838, Features::removee ? 537254313 : 1445302971, amount, Features::toBank ? 4 : 1);
		UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);
		Features::removee ? Features::stealthMoneyCounter -= amount : Features::stealthMoneyCounter += amount;
		Log::Msg("Generated %i Dollars with the Hash 0x%i", amount, (int)var0);
	}
}

void Features::million(int millions) {
	int money = 0;
	if (millions < 11) {
		money = millions * 1000000;
		Features::stealthMoney(money);
	}
}

bool Features::blameGunOn = false;
void Features::blameGun() {
	Entity AimedAtEntity;
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &AimedAtEntity) && IsKeyPressed(VK_LBUTTON)) {
		if (PED::IS_PED_A_PLAYER(AimedAtEntity)) {
			Hooking::ownedExplosionBypass(true);
			for (int i = 0; i < 33; i++) {
				if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) != AimedAtEntity && PLAYER::PLAYER_ID() != i) {
					Hooking::add_owned_explosion(AimedAtEntity, coordsOf(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)), EXP_TAG_GRENADE, 5.0f, true, false, 0.1f);
				}
			}
			Hooking::ownedExplosionBypass(false);
		}
	}
}

void Features::sendToMission(Player p) {
	unsigned int Bit = (1 << p);
	uint64_t mission[4] = { -15432926, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p), 0, 0 };
	Hooking::trigger_script_event(1, mission, 4, Bit);
}

int weatherNiggerID = 0;
int wTimer = timeGetTime();
int wSpeed = 10000;
bool Features::weatherSpamBool = false;
void Features::weatherSpam() {
	if ((timeGetTime() - wTimer) > wSpeed) {
		Hooking::set_session_weather(1, weatherNiggerID, 76, 0);
		if (weatherNiggerID < 15) {
			weatherNiggerID += 1;
		}
		else {
			weatherNiggerID = 0;
		}
		wTimer = timeGetTime();
	}
}

void Features::Online::teleportVehToWayp(Player player) {
	int CurrentPlayersVehicle = PED::GET_VEHICLE_PED_IS_USING(player);
	Vector3 coords = get_blip_marker();
	bool groundFound = false;
	static float groundCheckHeight[] =
	{ 100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
	for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
	{
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
	}
	if (CurrentPlayersVehicle) {
		RequestControlOfEnt(CurrentPlayersVehicle);
		ENTITY::SET_ENTITY_COORDS(CurrentPlayersVehicle, coords.x, coords.y, coords.z + 1.0f, false, false, false, false);
	}
}

//+ Menu Width
bool Features::killSpooferOn = false;
Player Features::spoofKiller = 0;
void Features::killSpoofer() {
	Entity AimedAtEntity;
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &AimedAtEntity) && IsKeyPressed(VK_LBUTTON)) {
		if (PED::IS_PED_A_PLAYER(AimedAtEntity)) {
			Hooking::ownedExplosionBypass(true);
			Hooking::add_owned_explosion(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(spoofKiller), coordsOf(AimedAtEntity), EXP_TAG_GRENADE, 5.0f, false, true, 0.0f);
			Hooking::ownedExplosionBypass(false);
		}
	}
}

void Features::teleport_to_objective()
{
	Entity e;
	Vector3 wayp;
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, FALSE))
		e = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	else e = playerPed;
	bool blipFound = false;
	if (ENTITY::IS_ENTITY_A_VEHICLE(e)) RequestControlOfEnt(e);
	for (int i = 0; i <= 1000; i++)
	{
		int blipIterator = UI::IS_WAYPOINT_ACTIVE() ? UI::_GET_BLIP_INFO_ID_ITERATOR() : SpriteStandard;
		//This is for the race 
		for (Blip i = UI::GET_FIRST_BLIP_INFO_ID(blipIterator);
			UI::DOES_BLIP_EXIST(i) != 0; i = UI::GET_NEXT_BLIP_INFO_ID(blipIterator)) {
			if (UI::GET_BLIP_INFO_ID_TYPE(i) == 4 && UI::GET_BLIP_COLOUR(i) == 5 != ColorBlue
				&& UI::IS_BLIP_ON_MINIMAP(i) == 1) {
				wayp = UI::GET_BLIP_INFO_ID_COORD(i);
				blipFound = true;
				//notifyMap("color is: %d, type is: %d", UI::GET_BLIP_COLOUR(i), UI::GET_BLIP_INFO_ID_TYPE(i));
				teleport_to_coords(e, wayp);
			}
			bool groundFound = false;
			static float groundCheckHeight[] =
			{ 100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
			for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
			{
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, wayp.x, wayp.y, groundCheckHeight[i], 0, 0, 1);
				WAIT(1);
				if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(wayp.x, wayp.y, groundCheckHeight[i], &wayp.z, 0))
				{
					groundFound = true;
					wayp.z += 3.0;
					break;
				}
			}
			// if ground not found then set Z in air and give player a parachute
			if (!groundFound)
			{
				wayp.z = 1000.0;
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xFBAB5776, 1, 0);
			}
		}
		break;
	}
	if (!blipFound) {
		Blip i = UI::GET_FIRST_BLIP_INFO_ID(SpriteRaceFinish);
		if (UI::DOES_BLIP_EXIST(i) != 0) {
			wayp = UI::GET_BLIP_INFO_ID_COORD(i);
			blipFound = true;
			notifyMap("color is: %d, type is: %d",
				UI::GET_BLIP_COLOUR(i), UI::GET_BLIP_INFO_ID_TYPE(i));
		}
	}
	blipFound ? teleport_to_coords(e, wayp) : NULL;
}

bool Features::cinButtonOff = false;
void Features::disableCinematicButton() {
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(!Features::cinButtonOff);
}

int Features::kek_texture = 0;
int Features::kek_id = 0;
void Features::kekekekek(int id, int tex, bool male) {
	if (male) {
		switch (id) {
		case 0: Features::changeClothes("LEGS", 0, tex); break;
		case 1: Features::changeClothes("LEGS", 4, tex); break;
		case 2: Features::changeClothes("LEGS", 7, tex); break;
		case 3: Features::changeClothes("LEGS", 9, tex); break;
		case 4: Features::changeClothes("LEGS", 10, tex); break;
		case 5: Features::changeClothes("LEGS", 13, tex); break;
		case 6: Features::changeClothes("LEGS", 15, tex); break;
		case 7: Features::changeClothes("LEGS", 19, tex); break;
		case 8: Features::changeClothes("LEGS", 20, tex); break;
		case 9: Features::changeClothes("LEGS", 22, tex); break;
		case 10: Features::changeClothes("LEGS", 23, tex); break;
		case 11: Features::changeClothes("LEGS", 24, tex); break;
		case 12: Features::changeClothes("LEGS", 25, tex); break;
		case 13: Features::changeClothes("LEGS", 26, tex); break;
		case 14: Features::changeClothes("LEGS", 28, tex); break;
		case 15: Features::changeClothes("LEGS", 31, tex); break;
		case 16: Features::changeClothes("LEGS", 33, 0); break;
		case 17: Features::changeClothes("LEGS", 34, 0); break;
		case 18: Features::changeClothes("LEGS", 35, 0); break;
		case 19: Features::changeClothes("LEGS", 37, tex); break;
		case 20: Features::changeClothes("LEGS", 46, tex); break;
		case 21: Features::changeClothes("LEGS", 47, tex); break;
		case 22: Features::changeClothes("LEGS", 48, tex); break;
		case 23: Features::changeClothes("LEGS", 49, tex); break;
		case 24: Features::changeClothes("LEGS", 50, tex); break;
		case 25: Features::changeClothes("LEGS", 52, tex); break;
		case 26: Features::changeClothes("LEGS", 59, tex); break;
		case 27: Features::changeClothes("LEGS", 60, tex); break;
		case 28: Features::changeClothes("LEGS", 62, tex); break;
		case 29: Features::changeClothes("LEGS", 75, tex); break;
		case 30: Features::changeClothes("LEGS", 76, tex); break;
		case 31: Features::changeClothes("LEGS", 86, tex); break;
		case 32: Features::changeClothes("LEGS", 87, tex); break;
		case 33: Features::changeClothes("LEGS", 88, tex); break;
		case 34: Features::changeClothes("LEGS", 96, tex); break;
		case 35: Features::changeClothes("LEGS", 102, tex); break;
		case 36: Features::changeClothes("LEGS", 103, tex); break;
		case 37: Features::changeClothes("LEGS", 104, 0); Features::changeClothes("SPECIAL2", 0, 0); break;
		case 38: Features::changeClothes("SPECIAL2", 58, 0); break;
		case 39: Features::changeClothes("SPECIAL2", 122, 0); break;
		case 40: Features::changeClothes("SPECIAL2", 129, 0); break;
		}
	}
	else {
		switch (id) {
		case 0: Features::changeClothes("LEGS", 3, tex); break;
		case 1: Features::changeClothes("LEGS", 30, tex); break;
		case 2: Features::changeClothes("LEGS", 32, 0); break;
		case 3: Features::changeClothes("LEGS", 33, 0); break;
		case 4: Features::changeClothes("LEGS", 34, 0); break;
		case 5: Features::changeClothes("LEGS", 41, tex); break;
		case 6: Features::changeClothes("LEGS", 48, tex); break;
		case 7: Features::changeClothes("LEGS", 49, tex); break;
		case 8: Features::changeClothes("LEGS", 61, tex); break;
		case 9: Features::changeClothes("LEGS", 89, tex); break;
		case 10: Features::changeClothes("LEGS", 90, tex); break;
		case 11: Features::changeClothes("LEGS", 91, tex); break;
		case 12: Features::changeClothes("LEGS", 99, tex); break;
		case 13: Features::changeClothes("LEGS", 102, 0); break;
		case 14: Features::changeClothes("LEGS", 109, tex); break;
		case 15: Features::changeClothes("LEGS", 110, tex); break;
		case 16: Features::changeClothes("LEGS", 111, 0); Features::changeClothes("SPECIAL2", 0, 0); break;
		case 18: Features::changeClothes("SPECIAL2", 35, 0); break;
		case 19: Features::changeClothes("SPECIAL2", 152, 0); break;
		case 20: Features::changeClothes("SPECIAL2", 159, 0); break;
		}
	}
}

int Features::kek_id_2 = 0;
int Features::kek_texture_2 = 0;
void Features::kkeekkeekk(int id, int tex, bool male) {
	if (male) {
		switch (id) {
		case 0: Features::kekekekek(0, tex, true); break;
		case 1: Features::kekekekek(1, tex, true); break;
		case 2: Features::kekekekek(2, tex, true); break;
		case 3: Features::kekekekek(3, tex, true); break;
		case 4: Features::kekekekek(5, tex, true); break;
		case 5: Features::kekekekek(10, tex, true); break;
		case 6: Features::kekekekek(11, tex, true); break;
		case 7: Features::kekekekek(13, tex, true); break;
		case 8: Features::kekekekek(15, tex, true); break;
		case 9: Features::kekekekek(16, tex, true); break;
		case 10: Features::kekekekek(17, tex, true); break;
		case 11: Features::kekekekek(19, tex, true); break;
		case 12: Features::kekekekek(20, tex, true); break;
		case 13: Features::kekekekek(21, tex, true); break;
		case 14: Features::kekekekek(23, tex, true); break;
		case 15: Features::kekekekek(29, tex, true); break;
		case 16: Features::kekekekek(30, tex, true); break;
		case 17: Features::kekekekek(31, tex, true); break;
		case 18: Features::kekekekek(32, tex, true); Features::changeClothes("SPECIAL2", 0, 0); break;
		case 19: Features::kekekekek(38, tex, true); break;
		case 20: Features::kekekekek(39, tex, true); break;
		case 21: Features::kekekekek(40, tex, true); break;
		}
	}
	else {
		switch (id) {
		case 0: Features::kekekekek(0, tex, false); break;
		case 1: Features::kekekekek(1, tex, false); break;
		case 2: Features::kekekekek(2, tex, false); break;
		case 3: Features::kekekekek(3, tex, false); break;
		case 4: Features::kekekekek(5, tex, false); break;
		case 5: Features::kekekekek(6, tex, false); break;
		case 6: Features::kekekekek(8, tex, false); break;
		case 7: Features::kekekekek(9, tex, false); break;
		case 8: Features::kekekekek(10, tex, false); Features::changeClothes("SPECIAL2", 0, 0); break;
		case 9: Features::kekekekek(18, tex, false); break;
		case 10: Features::kekekekek(19, tex, false); break;
		case 11: Features::kekekekek(20, tex, false); break;
		}
	}
}

Player Features::griefKillerID = 0;
void Features::kill_player_by_player(Player killer, Player victim) {
	Ped ped1 = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(killer);
	Ped ped2 = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(victim);
	Vector3 coords = coordsOf(ped2);
	if (killer != victim) {
		Hooking::ownedExplosionBypass(true);
		Hooking::add_owned_explosion(ped1, coords, EXP_TAG_GRENADE, 5.0f, false, true, 0.0f);
		Hooking::ownedExplosionBypass(false);
	}
}

Ped Features::player_index_from_name(char* name) {
	for (int i = 0; i < 33; i++) {
		if (strcmp(PLAYER::GET_PLAYER_NAME(i), name) == 0) {
			return PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			break;
		}
	}
	return -1;
}

Player Features::player_id_from_name(char* name) {
	for (int i = 0; i < 33; i++) {
		if (strcmp(PLAYER::GET_PLAYER_NAME(i), name) == 0) {
			return i;
			break;
		}
	}
	return -1;
}


int Features::selectedBlacklist = 0;
int Features::blacklistID = 0;
std::vector<std::string> Features::blacklist_names;
Blacklisted Features::b_player[999];

Player Features::player_id_from_blacklist(int bID) {
	std::vector<std::string> strVec;
	XScript::getFileContent("X-Folder/friends/blacklist.txt", strVec);
	for (int i = 0; i < strVec.size(); i++) {
		if (i == bID) {
			return Features::player_id_from_name((char*)strVec[i].c_str());
			break;
		}
	}
	return -1;
}

int Features::blacklist_from_player_id(Player pID) {
	for (int i = 0; i < Features::blacklist_names.size(); i++) {
		if (strcmp((char*)Features::blacklist_names[i].c_str(), PLAYER::GET_PLAYER_NAME(pID)) == 0) {
			return i;
			break;
		}
	}
	return -1;
}

void Features::addToBlacklist(Player p) {
	Features::write2("X-Folder/friends/blacklist.txt", PLAYER::GET_PLAYER_NAME(p));
	INI::WriteInt("X-Folder/friends/blacklist_cfg.ini", 1, PLAYER::GET_PLAYER_NAME(p), "init");
	INI::WriteInt("X-Folder/friends/blacklist_cfg.ini", 0, PLAYER::GET_PLAYER_NAME(p), "kick");
	INI::WriteInt("X-Folder/friends/blacklist_cfg.ini", 0, PLAYER::GET_PLAYER_NAME(p), "warn");
	INI::WriteInt("X-Folder/friends/blacklist_cfg.ini", 0, PLAYER::GET_PLAYER_NAME(p), "freeze");
	INI::WriteInt("X-Folder/friends/blacklist_cfg.ini", 0, PLAYER::GET_PLAYER_NAME(p), "blame");
	INI::WriteInt("X-Folder/friends/blacklist_cfg.ini", 0, PLAYER::GET_PLAYER_NAME(p), "explode");
}

void Features::loadBlacklistOptions(Player p, int bID) {
	if (INI::GetInt("X-Folder/friends/blacklist_cfg.ini", PLAYER::GET_PLAYER_NAME(p), "init") == 1) {
		b_player[bID].kick = INI::GetBool("X-Folder/friends/blacklist_cfg.ini", PLAYER::GET_PLAYER_NAME(p), "kick");
		b_player[bID].warn = INI::GetBool("X-Folder/friends/blacklist_cfg.ini", PLAYER::GET_PLAYER_NAME(p), "warn");
		b_player[bID].freeze = INI::GetBool("X-Folder/friends/blacklist_cfg.ini", PLAYER::GET_PLAYER_NAME(p), "freeze");
		b_player[bID].blame = INI::GetBool("X-Folder/friends/blacklist_cfg.ini", PLAYER::GET_PLAYER_NAME(p), "blame");
		b_player[bID].explode = INI::GetBool("X-Folder/friends/blacklist_cfg.ini", PLAYER::GET_PLAYER_NAME(p), "explode");
	}
}

void Features::loadBlacklistOptions2(char* pname, int bID) {
	if (INI::GetInt("X-Folder/friends/blacklist_cfg.ini", pname, "init") == 1) {
		b_player[bID].kick = INI::GetBool("X-Folder/friends/blacklist_cfg.ini", pname, "kick");
		b_player[bID].warn = INI::GetBool("X-Folder/friends/blacklist_cfg.ini", pname, "warn");
		b_player[bID].freeze = INI::GetBool("X-Folder/friends/blacklist_cfg.ini", pname, "freeze");
		b_player[bID].blame = INI::GetBool("X-Folder/friends/blacklist_cfg.ini", pname, "blame");
		b_player[bID].explode = INI::GetBool("X-Folder/friends/blacklist_cfg.ini", pname, "explode");
	}
}

bool Features::turn_on_blacklist = false;
void Features::blacklistLoop() {
	/*for (int i = 0; i < 999; i++) {
		Player p = player_id_from_blacklist(i);
		if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p) != PLAYER::PLAYER_PED_ID() && Features::CheckWord("X-Folder/friends/blacklist.txt", PLAYER::GET_PLAYER_NAME(p))) {
			
			if (b_player[i].kick) {
				Features::SUPERKICK(p);
			}

			if (b_player[i].warn) {
				ostringstream ss; ss << "~r~" << PLAYER::GET_PLAYER_NAME(p) << " is in your Session!";
				notifyMap(ss.str());
			}

			if (b_player[i].freeze) {
				Features::Freezer(p);
			}

			if (b_player[i].blame) {
				Features::blamee(p);
			}

			if (b_player[i].explode) {
				Features::explodeloop(p);
			}

		}
	}*/
	for (int i = 0; i < 33; i++) {
		if (Features::CheckWord("X-Folder/friends/blacklist.txt", PLAYER::GET_PLAYER_NAME(i)) && ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
			int bid = Features::blacklist_from_player_id(i);
			if (bid != -1) {
				Ped pl = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);

				if (b_player[bid].kick) {
					uint64_t args[3] = { -120668417, pl, 48 };
					Hooking::trigger_script_event(1, args, 3, (1 << i));
				}

				if (b_player[bid].warn) {
					ostringstream ss; ss << "~r~" << PLAYER::GET_PLAYER_NAME(i) << " is in your Session!";
					notifyMap(ss.str());
				}

				if (b_player[bid].freeze) {
					AI::CLEAR_PED_TASKS_IMMEDIATELY(pl);
					AI::CLEAR_PED_TASKS(pl);
					AI::CLEAR_PED_SECONDARY_TASK(pl);
				}

				if (b_player[bid].blame) {
					Features::blamee(i);
				}

				if (b_player[bid].explode) {
					Vector3 targetCords = ENTITY::GET_ENTITY_COORDS(pl, false);
					FIRE::ADD_EXPLOSION(targetCords.x, targetCords.y, targetCords.z, 0, 100.0f, true, false, 1.0f);
				}
			}
		}
	}
}

bool Features::isRockstarDev(Player p) {
	bool dev1 = NETWORK::NETWORK_PLAYER_IS_ROCKSTAR_DEV(p);
	bool dev2 = NETWORK::NETWORK_PLAYER_IS_ROCKSTAR_DEV(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p));
	if (dev1 || dev2) {
		return true;
	}
	return false;
}

//Menu version
//smooth scroller
//smooth sc switch
//sm sc delay
//Scrollbar switch
//Custom Header Submenu
//Close displays
//Displays to config

/*
Rockstar Staff
Warn me
Exit GTA Online
Exit GTAV

Player
Kick
Warn me
Freeze
Blame
Explode
Remove from blacklist
Join R* ID
*/

void Features::add_owned_explosion(Ped ped, float x, float y, float z, int type, float dmg, bool audible, bool invisible, float shake) {
	Vector3 coords;
	coords.x = x;
	coords.y = y;
	coords.z = z;
	Hooking::ownedExplosionBypass(true);
	Hooking::add_owned_explosion(ped, coords, type, dmg, audible, invisible, shake);
	Hooking::ownedExplosionBypass(false);
}

//Info: R* ID
//Info: Port

//4.2 stuff?

bool Features::moneyDropProtection = false;

bool Features::staff_ = false;
void Features::unlockStaff() {
	char* failkek = "erubaegjearrjnvetr";
	char* password = "alex22ist22";
	char* result = failkek;
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", "", "", "", "", 21);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) {
		result = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
	}
	if (result != failkek && result == password) {
		notifyMap("~g~Staff Version unlocked!");
		staff_ = true;
	}
	else {
		notifyMap("~r~Unlock failed!");
		WAIT(1000 * 2);
		exit(0);
	}
}

bool Features::is_player_free_aiming_at_entity(Player player, Entity entity) {
	Entity ent;
	bool entFound = PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(player, &ent);
	if (entFound && ent == entity) {
		return true;
	}
	return false;
}

bool Features::freeaimtest = false;
void Features::freeAimTest() {
	if (Features::is_player_free_aiming_at_entity(Features::Online::selectedPlayer, PLAYER::PLAYER_PED_ID()) ||
		Features::is_player_free_aiming_at_entity(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), PLAYER::PLAYER_PED_ID())) {
		notifyMap("~r~Soos");
	}
}

bool Features::is_player_shooting_at_player(Player player, Player target) {
	Ped p = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
	bool freeAiming = is_player_free_aiming_at_entity(player, p);
	bool shooting = is_ped_shooting(ped);
	if (freeAiming && shooting) {
		return true;
	}
	return false;
}

bool Features::remoteClearWantedAll = false;
bool Features::remoteBribeAll = false;
bool Features::remoteOffRadarAll = false;
bool Features::remoteCWbool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
bool Features::remoteBAbool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
bool Features::remoteORbool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

void Features::remoteBlackscreen3(Player p) {
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	unsigned int Bit = (1 << p);
	uint64_t args[9] = { 1000837481, ped, 4, 4566469881341411328, 4528819783743622349, 0, 1, 1, 1062333317 };
	Hooking::trigger_script_event(1, args, 9, Bit);
}

void Features::remoteClearWanted(Player p) {
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	unsigned int Bit = (1 << p);
	int handle = globalHandle(1625435).At(p, 560).At(491).As<int>();
	uint64_t args[3] = { 1475266103, ped, handle };
	Hooking::trigger_script_event(1, args, 3, Bit);
}

void Features::remoteBribeAuthorities(Player p) {
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	unsigned int Bit = (1 << p);
	int var0 = globalHandle(2524719).At(4545).As<int>();
	int var1 = NETWORK::GET_NETWORK_TIME();
	int var2 = globalHandle(1625435).At(p, 560).At(491).As<int>();
	uint64_t args[7] = { 1555129594, ped, var0, 0, var1, 0, var2 };
	Hooking::trigger_script_event(1, args, 7, Bit);
}

void Features::remoteInsuranceMsg(Player p) {
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	unsigned int Bit = (1 << p);
	uint64_t args[3] = { 380155193, ped, 1000000000 };
	Hooking::trigger_script_event(1, args, 3, Bit);
}

void Features::remoteSpectateMsg2(Player p) {
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	unsigned int Bit = (1 << p);
	uint64_t args[14] = { 713068249, ped, 1583919327 };
	Hooking::trigger_script_event(1, args, 14, Bit);
}

void Features::remoteOffTheRadar(Player p) {
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	unsigned int Bit = (1 << p);
	int var0 = NETWORK::GET_NETWORK_TIME();
	int var1 = var0 + (60000 * 59) + 1;
	int var2 = globalHandle(1625435 + 1 + p * 560 + 491).As<std::uint64_t>();
	uint64_t args[7] = { 1344161996, ped, var1, var0, 1, 1, var2 };
	Hooking::trigger_script_event(1, args, 7, Bit);
}

void Features::remoteSendCops() {
	Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
	Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(iPed, 0);
	if (!ENTITY::DOES_ENTITY_EXIST(iPed)) return;
	Hash guysex = GAMEPLAY::GET_HASH_KEY("s_m_y_cop_01");
	STREAMING::REQUEST_MODEL(guysex);
	while (!STREAMING::HAS_MODEL_LOADED(guysex))
		WAIT(0);
	int createdGuySex = PED::CREATE_PED(26, guysex, pCoords.x, pCoords.y, pCoords.z, 1, 1, 0);
	ENTITY::SET_ENTITY_INVINCIBLE(createdGuySex, false);
	int vehmodel = GAMEPLAY::GET_HASH_KEY("POLICE3");
	STREAMING::REQUEST_MODEL(vehmodel);
	while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
	Vehicle veh = VEHICLE::CREATE_VEHICLE(vehmodel, pCoords.x, pCoords.y, pCoords.z, 0.0, 1, 1);
	VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
	Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL");
	WEAPON::GIVE_WEAPON_TO_PED(createdGuySex, railgun, railgun, 9999, 9999);
	PED::SET_PED_INTO_VEHICLE(createdGuySex, veh, -1);
	AI::TASK_COMBAT_PED(createdGuySex, iPed, 1, 1);
	ENTITY::SET_ENTITY_INVINCIBLE(createdGuySex, false);
	PED::SET_PED_COMBAT_ABILITY(createdGuySex, 100);
	PED::SET_PED_CAN_SWITCH_WEAPON(createdGuySex, true);
	AI::TASK_COMBAT_PED(createdGuySex, iPed, 1, 1);
	PED::SET_PED_AS_ENEMY(createdGuySex, 1);
	PED::SET_PED_COMBAT_RANGE(createdGuySex, 1000);
	PED::SET_PED_KEEP_TASK(createdGuySex, true);
	PED::SET_PED_AS_COP(createdGuySex, 1000);
	PED::SET_PED_ALERTNESS(createdGuySex, 1000);
}

void Features::remoteOffTheRadarAll() {
	for (int i = 0; i < 33; i++) {
		if (Features::exclude(i)) {
			remoteOffTheRadar(i);
		}
	}
}

void Features::remoteBAAll() {
	for (int i = 0; i < 33; i++) {
		if (Features::exclude(i)) {
			remoteBribeAuthorities(i);
		}
	}
}

void Features::remoteCWAll() {
	for (int i = 0; i < 33; i++) {
		if (Features::exclude(i)) {
			remoteClearWanted(i);
		}
	}
}

bool Features::disableAllVehBool = false;
void Features::disableAllVehicles() {
	for (int i = 0; i < 33; i++) {
		if (Features::exclude(i)) {
			Features::gentleKick(i);
		}
	}
}

bool Features::freezeAllCamsBool = false;
void Features::freezeAllCams() {
	for (int i = 0; i < 33; i++) {
		if (Features::exclude(i)) {
			Features::rotateCam(i);
		}
	}
}

//Set open key
//coloading
//hook status

bool Features::get_flag(Player player, PedConfigFlags flag) {
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
	return PED::GET_PED_CONFIG_FLAG(ped, flag, true);
}

void Features::set_flag(Player player, PedConfigFlags flag, bool value) {
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
	PED::SET_PED_CONFIG_FLAG(ped, flag, value);
}

bool Features::free_cam = false;
void Features::freecam(bool toggle)
{
	static bool lock;
	static std::int32_t cam;
	static float dist;
	auto rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	auto coord = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 p_coord = { 0,0,0 };
	if (!CAM::DOES_CAM_EXIST(cam)) {
		cam = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 1);
		CAM::SET_CAM_ROT(cam, rot.x, rot.y, rot.z, 0);
		CAM::SET_CAM_COORD(cam, coord.x, coord.y, coord.z);
	}
	if (!toggle)
	{
		CAM::RENDER_SCRIPT_CAMS(false, true, 700, 1, 1);
		CAM::SET_CAM_ACTIVE(cam, 0);
		CAM::DESTROY_CAM(cam, true);
		PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 0);
	}
	ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), !Features::noclipinvis);
	CAM::RENDER_SCRIPT_CAMS(true, true, 700, 1, 1);
	CAM::SET_CAM_ACTIVE(cam, 1);
	CAM::SET_CAM_ROT(cam, rot.x, rot.y, rot.z, 0);

	p_coord = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);

	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(PLAYER::PLAYER_PED_ID(), p_coord.x, p_coord.y, p_coord.z, 0, 0, 0);
	PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 1);
	UI::HIDE_HUD_AND_RADAR_THIS_FRAME();

	auto speed = .5f * Features::noclipspeed;
	if (IsKeyPressed(VK_SHIFT) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, ControlFrontendRb))
	{
		speed += .5f * Features::noclipspeed;
	}

	auto c = add(&CAM::GET_CAM_COORD(cam), &multiply(&rot_to_direction(&rot), speed));

	if (IsKeyPressed(VK_KEY_S) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 268))
	{
		speed /= -1;
		CAM::SET_CAM_COORD(cam, c.x, c.y, c.z);
	}

	if (IsKeyPressed(VK_KEY_W) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269))
	{
		CAM::SET_CAM_COORD(cam, c.x, c.y, c.z);
	}

	if (Features::noclipattackmode) {
		if (IsKeyPressed(VK_RBUTTON) || IsKeyPressed(VK_LBUTTON)) {
			Features::add_owned_explosion(PLAYER::PLAYER_PED_ID(), c.x, c.y, c.z, 0, 5.0f, true, false, 0.1f);
		}
	}
}

bool Features::noClipBool = false;
void Features::noClip(bool toggle) {
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (vehiclenoclip && PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
		playerPed = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	}
	else {
		playerPed = PLAYER::PLAYER_PED_ID();
	}
	ENTITY::SET_ENTITY_VISIBLE(playerPed, !Features::noclipinvis);
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, false);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	if (GetAsyncKeyState(VK_KEY_S) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 268)) {
		float fivef = .5f * Features::noclipspeed;
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		float xVec = fivef * sin(degToRad(heading)) * -1.0f;
		float yVec = fivef * cos(degToRad(heading));
		ENTITY::SET_ENTITY_HEADING(playerPed, heading);

		pos.x -= xVec, pos.y -= yVec;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	}
	if (GetAsyncKeyState(VK_KEY_W) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269)) {
		float fivef = .5f * Features::noclipspeed;
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		float xVec = fivef * sin(degToRad(heading)) * -1.0f;
		float yVec = fivef * cos(degToRad(heading));
		ENTITY::SET_ENTITY_HEADING(playerPed, heading);

		pos.x += xVec, pos.y += yVec;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	}
	if (GetAsyncKeyState(VK_KEY_A) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 266)) {
		float fivef = .5f * Features::noclipspeed;
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		ENTITY::SET_ENTITY_HEADING(playerPed, heading + 0.5f * Features::noclipspeed);
	}
	if (GetAsyncKeyState(VK_KEY_D) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 271)) {
		float fivef = .5f * Features::noclipspeed;
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		ENTITY::SET_ENTITY_HEADING(playerPed, heading - 0.5f * Features::noclipspeed);
	}
	if (GetAsyncKeyState(VK_SHIFT) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, ControlFrontendRb)) {
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		ENTITY::SET_ENTITY_HEADING(playerPed, heading);

		pos.z -= 0.5 * Features::noclipspeed;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	}
	if (GetAsyncKeyState(VK_SPACE) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, ControlFrontendLb)) {
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		ENTITY::SET_ENTITY_HEADING(playerPed, heading);

		pos.z += 0.5 * Features::noclipspeed;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	}

	if (Features::noclipattackmode) {
		ENTITY::SET_ENTITY_INVINCIBLE(playerPed, toggle);
		if (IsKeyPressed(VK_RBUTTON) || IsKeyPressed(VK_LBUTTON)) {
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(playerPed, false);
			Features::add_owned_explosion(PLAYER::PLAYER_PED_ID(), coords.x, coords.y, coords.z, 0, 5.0f, true, false, 0.1f);
		}
	}
}

bool Features::noclip22bool = false;
void Features::noclip22(bool toggle) {
	Entity handle = PLAYER::PLAYER_PED_ID();
	if (vehiclenoclip && PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
		handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	}
	else {
		handle = PLAYER::PLAYER_PED_ID();
	}
	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	ENTITY::SET_ENTITY_VISIBLE(handle, !Features::noclipinvis);
	static bool lock;
	static std::int32_t cam;
	static float dist;
	auto coord = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 p_coord = { 0,0,0 };
	if (!CAM::DOES_CAM_EXIST(cam)) {
		cam = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 1);
		CAM::SET_CAM_ROT(cam, rot.x, rot.y, rot.z, 0);
		CAM::SET_CAM_COORD(cam, coord.x, coord.y, coord.z);
	}
	if (!toggle)
	{
		CAM::RENDER_SCRIPT_CAMS(false, true, 700, 1, 1);
		CAM::SET_CAM_ACTIVE(cam, 0);
		CAM::DESTROY_CAM(cam, true);
		PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 0);
	}

	CAM::RENDER_SCRIPT_CAMS(true, true, 700, 1, 1);
	CAM::SET_CAM_ACTIVE(cam, 1);
	CAM::SET_CAM_ROT(cam, rot.x, rot.y, rot.z, 0);

	p_coord = ENTITY::GET_ENTITY_COORDS(handle, 1);

	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(handle, p_coord.x, p_coord.y, p_coord.z, 0, 0, 0);
	//PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 1);
	UI::HIDE_HUD_AND_RADAR_THIS_FRAME();

	auto speed = .5f * Features::noclipspeed;
	if (IsKeyPressed(VK_SHIFT) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, ControlFrontendRb))
	{
		speed += .5f * Features::noclipspeed;
	}

	if (IsKeyPressed(VK_KEY_S) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 268))
	{
		speed /= -1;
		auto c = add(&CAM::GET_CAM_COORD(cam), &multiply(&rot_to_direction(&rot), speed));
		CAM::SET_CAM_COORD(cam, c.x, c.y, c.z);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(handle, c.x, c.y, c.z - 1.0f, false, false, false);
	}

	if (IsKeyPressed(VK_KEY_W) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269))
	{
		auto c = add(&CAM::GET_CAM_COORD(cam), &multiply(&rot_to_direction(&rot), speed));
		CAM::SET_CAM_COORD(cam, c.x, c.y, c.z);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(handle, c.x, c.y, c.z - 1.0f, false, false, false);
	}

	if (Features::noclipattackmode) {
		ENTITY::SET_ENTITY_INVINCIBLE(handle, toggle);
		if (IsKeyPressed(VK_RBUTTON) || IsKeyPressed(VK_LBUTTON)) {
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(handle, false);
			Features::add_owned_explosion(PLAYER::PLAYER_PED_ID(), coords.x, coords.y, coords.z, 0, 5.0f, true, false, 0.1f);
		}
	}
}

bool Features::vehiclenoclip = true;
bool Features::noclipattackmode = true;
bool Features::noclipinvis = false;
float Features::noclipspeed = 1.0f;
int Features::noclipspeed2 = 10;
//Attack mode
//Vehnoclip
//v1
//v2
//Submenu
//Explosion xyz offset

std::vector<std::string> Features::exp_losions = {
"Grenade",
"Grenade Launcher",
"Sticky Bomb",
"Molotov",
"Rocket",
"Tank Shell",
"Octane",
"Car",
"Plane",
"Petrol",
"Bike",
"Steam",
"Flame 1",
"Water",
"Gas 1",
"Boat",
"Ship",
"Truck",
"Bullet",
"Smoke Grenade 1",
"Smoke Grenade 2",
"BZ Gas",
"Flare",
"Gas 2",
"Fire Extinguisher",
"Programmable AR",
"Train",
"Barrel",
"Propane",
"Blimp 1",
"Flame 2",
"Tanker",
"Plane Rocket",
"Vehicle Bullet",
"Gas 3",
"Bird Shit",
"Railgun",
"Blimp 2",
"Firework",
"Snowball",
"Proxymity Mine",
"Valkyrie Cannon",
"Air Defense",
"Pipe Bomb",
"Vehicle Mine",
"Explosive Ammo",
"APC Shell",
"Bomb Cluster",
"Bomb Gas",
"Bomb Fire",
"Bomb",
"Torpedo",
"Underwater Torpedo",
"Bombushka Cannon",
"Cluster",
"Barrage",
"Hunter Cannon",
"Rogue Cannon",
"Underwater Mine",
"Orbital Cannon",
"Wide Bomb",
"Explosive Shotgun",
"Oppressor MKII Cannon"
};

float Features::exp_offset_x_ = 0.0f;
float Features::exp_offset_y_ = 0.0f;
float Features::exp_offset_z_ = 0.0f;
int Features::exp_offset_x = 0;
int Features::exp_offset_y = 0;
int Features::exp_offset_z = 0;

Vector3 Features::exp_coords;
int Features::exp_type = 0;
int Features::exp_owner = NULL;
float Features::exp_damage = 1.0f;
float Features::exp_shake = 0.0f;
bool Features::exp_audio = true;
bool Features::exp_visible = true;
bool Features::exp_owned = false;
bool Features::exp_loop = false;
void Features::explode(Vector3 coords, int type, float dmg, bool audio, bool visible, float shake, bool owned, Player owner) {
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(owner);
	bool invisible_ex = false;
	if (visible) {
		invisible_ex = false;
	}
	else {
		invisible_ex = true;
	}
	if (owned) {
		Hooking::ownedExplosionBypass(true);
		Hooking::add_owned_explosion(ped, coords, type, dmg, audio, invisible_ex, shake);
		Hooking::ownedExplosionBypass(false);
	}
	else {
		FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, type, dmg, audio, invisible_ex, shake);
	}
}

bool Features::player_exp_loop[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::playerExplosion(Player p) {
	Vector3 coords = coordsOf(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p));
	coords.x += Features::exp_offset_x_;
	coords.y += Features::exp_offset_y_;
	coords.z += Features::exp_offset_z_;
	Features::explode(coords, Features::exp_type, Features::exp_damage, Features::exp_audio, Features::exp_visible, Features::exp_shake, Features::exp_owned, Features::exp_owner);
}

void Features::waypointExplosion() {
	Vector3 coords = get_blip_marker();
	bool groundFound = false;
	static float groundCheckHeight[] =
	{ 100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
	for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
	{
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
	}

	coords.x += Features::exp_offset_x_;
	coords.y += Features::exp_offset_y_;
	coords.z += Features::exp_offset_z_;
	Features::explode(coords, Features::exp_type, Features::exp_damage, Features::exp_audio, Features::exp_visible, Features::exp_shake, Features::exp_owned, Features::exp_owner);
}

char* Features::get_exp_name(int type) {
	switch (type) {
	case EXP_TAG_GRENADE: return "Grenade";
	case EXP_TAG_GRENADELAUNCHER: return "Grenade Launcher";
	case EXP_TAG_STICKYBOMB: return "Sticky Bomb";
	case EXP_TAG_MOLOTOV: return "Molotov";
	case EXP_TAG_ROCKET: return "Rocket";
	case EXP_TAG_TANKSHELL: return "Tank Shell";
	case EXP_TAG_HI_OCTANE: return "Octane";
	case EXP_TAG_CAR: return "Car";
	case EXP_TAG_PLANE: return "Plane";
	case EXP_TAG_PETROL_PUMP: return "Petrol";
	case EXP_TAG_BIKE: return "Bike";
	case EXP_TAG_DIR_STEAM: return "Steam";
	case EXP_TAG_DIR_FLAME: return "Flame 1";
	case EXP_TAG_DIR_WATER_HYDRANT: return "Water";
	case EXP_TAG_DIR_GAS_CANISTER: return "Gas 1";
	case EXP_TAG_BOAT: return "Boat";
	case EXP_TAG_SHIP_DESTROY: return "Ship";
	case EXP_TAG_TRUCK: return "Truck";
	case EXP_TAG_BULLET: return "Bullet";
	case EXP_TAG_SMOKEGRENADELAUNCHER: return "Smoke Grenade 1";
	case EXP_TAG_SMOKEGRENADE: return "Smoke Grenade 2";
	case EXP_TAG_BZGAS: return "BZ Gas";
	case EXP_TAG_FLARE: return "Flare";
	case EXP_TAG_GAS_CANISTER: return "Gas 2";
	case EXP_TAG_EXTINGUISHER: return "Fire Extinguisher";
	case EXP_TAG_PROGRAMMABLEAR: return "Programmable AR";
	case EXP_TAG_TRAIN: return "Train";
	case EXP_TAG_BARREL: return "Barrel";
	case EXP_TAG_PROPANE: return "Propane";
	case EXP_TAG_BLIMP: return "Blimp 1";
	case EXP_TAG_DIR_FLAME_EXPLODE: return "Flame 2";
	case EXP_TAG_TANKER: return "Tanker";
	case EXP_TAG_PLANE_ROCKET: return "Plane Rocket";
	case EXP_TAG_VEHICLE_BULLET: return "Vehicle Bullet";
	case EXP_TAG_GAS_TANK: return "Gas 3";
	case EXP_TAG_BIRD_CRAP: return "Bird Shit";
	case EXP_TAG_RAILGUN: return "Railgun";
	case EXP_TAG_BLIMP2: return "Blimp 2";
	case EXP_TAG_FIREWORK: return "Firework";
	case EXP_TAG_SNOWBALL: return "Snowball";
	case EXP_TAG_PROXMINE: return "Proxymity Mine";
	case EXP_TAG_VALKYRIE_CANNON: return "Valkyrie Cannon";
	case EXP_TAG_AIR_DEFENCE: return "Air Defense";
	case EXP_TAG_PIPEBOMB: return "Pipe Bomb";
	case EXP_TAG_VEHICLEMINE: return "Vehicle Mine";
	case EXP_TAG_EXPLOSIVEAMMO: return "Explosive Ammo";
	case EXP_TAG_APCSHELL: return "APC Shell";
	case EXP_TAG_BOMB_CLUSTER: return "Bomb Cluster";
	case EXP_TAG_BOMB_GAS: return "Bomb Gas";
	case EXP_TAG_BOMB_INCENDIARY: return "Bomb Fire";
	case EXP_TAG_BOMB_STANDARD: return "Bomb";
	case EXP_TAG_TORPEDO: return "Torpedo";
	case EXP_TAG_TORPEDO_UNDERWATER: return "Underwater Torpedo";
	case EXP_TAG_BOMBUSHKA_CANNON: return "Bombushka Cannon";
	case EXP_TAG_BOMB_CLUSTER_SECONDARY: return "Cluster";
	case EXP_TAG_HUNTER_BARRAGE: return "Barrage";
	case EXP_TAG_HUNTER_CANNON: return "Hunter Cannon";
	case EXP_TAG_ROGUE_CANNON: return "Rogue Cannon";
	case EXP_TAG_MINE_UNDERWATER: return "Underwater Mine";
	case EXP_TAG_ORBITAL_CANNON: return "Orbital Cannon";
	case EXP_TAG_BOMB_STANDARD_WIDE: return "Wide Bomb";
	case EXP_TAG_EXPLOSIVEAMMO_SHOTGUN: return "Explosive Shotgun";
	case EXP_TAG_OPPRESSOR2_CANNON: return "Oppressor MKII Cannon";
	}
}

//Player exp submenu

bool Features::advancedExpGun = false;
void Features::gunExplosion() {
	Vector3 coords;
	if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &coords)) {
		coords.x += Features::exp_offset_x_;
		coords.y += Features::exp_offset_y_;
		coords.z += Features::exp_offset_z_;
		Features::explode(coords, Features::exp_type, Features::exp_damage, Features::exp_audio, Features::exp_visible, Features::exp_shake, Features::exp_owned, Features::exp_owner);
	}
}

//Modelswap
int Features::modelID = 0;
char* Features::modelName = "";
int Features::modelID2 = 0;
char* Features::modelName2 = "";
float Features::ms_radius = 30.0f;
Hash Features::s_oldModel[999];
Hash Features::s_newModel[999];
int Features::s_model_ptr = 0;
bool Features::modelSwapOn[999] = { false };
bool Features::modelSwapCompletelyOn = false;

void Features::modelSwapLoop() {
	for (int i = 0; i < s_model_ptr; i++) {
		modelSwapOn[i] ? createMsLoop(i) : NULL;
	}
}

void Features::initModelSwap() {
	for (int i = 0; i < 999; i++) {
		s_oldModel[i] = -1;
		s_newModel[i] = -1;
		modelSwapOn[i] = false;
	}
}

void Features::createModelSwap(char *old_, char *new_) {
	Hash old__ = GAMEPLAY::GET_HASH_KEY(old_);
	Hash new__ = GAMEPLAY::GET_HASH_KEY(new_);
	s_oldModel[s_model_ptr] = old__;
	s_newModel[s_model_ptr] = new__;
	s_model_ptr += 1;
	Vector3 c = coordsOf(PLAYER::PLAYER_PED_ID());
	ENTITY::CREATE_MODEL_SWAP(c.x, c.y, c.z, ms_radius, old__, new__, true);
}

void Features::createModelSwap(Hash old_, Hash new_) {
	s_oldModel[s_model_ptr] = old_;
	s_newModel[s_model_ptr] = new_;
	s_model_ptr += 1;
	Vector3 c = coordsOf(PLAYER::PLAYER_PED_ID());
	ENTITY::CREATE_MODEL_SWAP(c.x, c.y, c.z, ms_radius, old_, new_, true);
}

void Features::createMsLoop(int index) {
	Vector3 c = coordsOf(PLAYER::PLAYER_PED_ID());
	ENTITY::CREATE_MODEL_SWAP(c.x, c.y, c.z, Features::ms_radius, Features::s_oldModel[index], Features::s_newModel[index], true);
}

void Features::removeModelSwap(char *old_) {
	Hash old__ = GAMEPLAY::GET_HASH_KEY(old_);
	int index = -1;
	for (int i = 0; i < ARRAYSIZE(s_oldModel); i++) {
		if (s_oldModel[i] == old__) {
			index = i;
			break;
		}
	}
	Vector3 c = coordsOf(PLAYER::PLAYER_PED_ID());
	ENTITY::REMOVE_MODEL_SWAP(c.x, c.y, c.z, ms_radius, s_oldModel[index], s_newModel[index], true);
	modelSwapOn[index] = false;
}

void Features::removeModelSwap(Hash old_) {
	int index = -1;
	for (int i = 0; i < ARRAYSIZE(s_oldModel); i++) {
		if (s_oldModel[i] == old_) {
			index = i;
			break;
		}
	}
	Vector3 c = coordsOf(PLAYER::PLAYER_PED_ID());
	ENTITY::REMOVE_MODEL_SWAP(c.x, c.y, c.z, ms_radius, s_oldModel[index], s_newModel[index], true);
	modelSwapOn[index] = false;
}


char *Features::v_display(char *vehicle) {
	Hash vehhash;
	char* display;
	char* label;

	vehhash = GAMEPLAY::GET_HASH_KEY(vehicle);
	display = VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(vehhash);
	label = UI::_GET_LABEL_TEXT(display);

	return label;
}

void Features::new15Stealth() {
	Features::stealthMoney(10000000);
	Features::stealthMoney(5000000);
}

void Features::tenMillionStealth(int ten_mil) {
	for (int i = 0; i < ten_mil; i++) {
		Features::stealthMoney(10000000);
	}
}

void Features::hundredMillionStealth() {
	tenMillionStealth(10);
}

//TO DO: Add new remotes to legacy notify protex / GED hook protex / remote gun / remote player options (only bools + test) / remote all
//TO DO: add 713068249 to event protex (All notification stuff) (I need an argchecker)
/*
1475266103 //clear wanted
1555129594 //bribe
380155193 //insurance
1344161996 //off radar
*/




























bool Features::niggerHotkey = false;

/*
TO DO:
- Fix Namechanger Config
- Fix Waypoint System
- Fix Clone Vehicle
- Fix Flush Money
- Add Black Hole
- Add Karma for other Players
- Add Moneygun Submenu

SUGGESIONS:
- Better Gravity Gun
- Seperate Kicks
- Vehicle Previews
- Control Player Vehicle
- Change Menu-End
- Bennys Wheels
- Explosion Submenu
- Save Option F11
- Hotkeys F12
- Info Box
- Weapons in Interior
- More Crashes
- IP Grabber Copy to Clipboard
- Max Nightclub Popularity (Recovery)
- Remote Bounty
- Bounty Value Editor
- Disable Player Vehicle Collision
- Clone Crash
- Radiation Lag
- Radiation Crash
- Modloader
- More Vehicle Mods
*/


void no_reload_toggle(bool toggle)
{
	static threeBytes	restore = { 0 };
	Hooking::NOPE<threeBytes>(Hooking::no_reload, restore, toggle);
}

void infinite_ammo_toggle(bool toggle)
{
	static threeBytes	restore = { 0 };
	Hooking::NOPE<threeBytes>(Hooking::infinite_ammo, restore, toggle);
}


struct ptr_test {
	ptr_test() {}
	~ptr_test() {}
	void kektest() { Log::Msg("kek"); }
};

void ptrtestkek() {
	std::unique_ptr<ptr_test> kkk(new ptr_test);

	kkk->kektest();

	auto hookek = new Hooking;

	hookek->foundPtr("");
}

bool Features::killShooting[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
bool Features::killAiming[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
bool Features::killSniper[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

void Features::killTryhard(Player p, int flags) {
	bool freeaiming = Features::get_flag(p, IS_AIMING);
	bool sniper = Features::get_flag(p, IS_SNIPER_SCOPE_ACTIVE);
	bool shooting = Features::get_flag(p, IS_SHOOTING);
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	if (flags == 0 && shooting) {
		Hooking::ownedExplosionBypass(true);
		Hooking::add_owned_explosion(ped, coordsOf(ped), EXP_TAG_GRENADE, 5.0f, false, true, 0.0f);
		Hooking::ownedExplosionBypass(false);
	}
	else if (flags == 1 && freeaiming) {
		Hooking::ownedExplosionBypass(true);
		Hooking::add_owned_explosion(ped, coordsOf(ped), EXP_TAG_GRENADE, 5.0f, false, true, 0.0f);
		Hooking::ownedExplosionBypass(false);
	}
	else if (flags == 2 && sniper) {
		Hooking::ownedExplosionBypass(true);
		Hooking::add_owned_explosion(ped, coordsOf(ped), EXP_TAG_GRENADE, 5.0f, false, true, 0.0f);
		Hooking::ownedExplosionBypass(false);
	}
}

void Features::toClipboard(const std::string &s) {
	HWND hwnd = GetDesktopWindow();
	OpenClipboard(hwnd);
	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size() + 1);
	if (!hg) {
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg), s.c_str(), s.size() + 1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}

std::vector<std::string> Features::get_files(const std::string& dir)
{
	std::vector<std::string> out;
	std::experimental::filesystem::path p(dir);
	std::experimental::filesystem::directory_iterator start(p);
	std::experimental::filesystem::directory_iterator end;
	std::transform(start, end, std::back_inserter(out), path_leaf_string());
	return out;
}

void filetest() {
	std::vector<std::string> fvec = Features::get_files("X-Folder/scripts");
	for (int i = 0; i < sizeof(fvec); i++) {
		Log::Msg(fvec[i].c_str());
	}
}

bool Features::is_player_in_interior(Player player)
{
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
	int currentInterior = INTERIOR::GET_INTERIOR_FROM_ENTITY(ped);
	return INTERIOR::IS_VALID_INTERIOR(currentInterior);
}


bool Features::isPlayerModder(Player p) {
	int modderValue = 0;
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	bool hasGodmode = PLAYER::GET_PLAYER_INVINCIBLE(ped);
	bool inHouse = Features::is_player_in_interior(p);
	int alpha = ENTITY::GET_ENTITY_ALPHA(ped);
	int level = globalHandle(1589747).At(p, 790).At(211).At(6).As<int>();
	int kills = globalHandle(1589747).At(p, 790).At(211).At(28).As<int>();
	int deaths = globalHandle(1589747).At(p, 790).At(211).At(29).As<int>();
	float kd = globalHandle(1589747).At(p, 790).At(211).At(26).As<float>();
	int total_money = globalHandle(1589747).At(p, 790).At(211).At(56).As<int>();
	int wallet_money = globalHandle(1589747).At(p, 790).At(211).At(3).As<int>();
	int bank_money = total_money - wallet_money;
	Hash player_model = ENTITY::GET_ENTITY_MODEL(ped);

	int max_legit_money = 8000000;
	int max_legit_level = 666;
	int max_legit_deaths = 1000000;
	int max_legit_kills = 1000000;
	float max_legit_kd = 6.0f;
	Hash legit_model[] = {
		GAMEPLAY::GET_HASH_KEY("mp_m_freemode_01"),
		GAMEPLAY::GET_HASH_KEY("mp_f_freemode_01")
	};

	if (player_model != legit_model[0] && player_model != legit_model[1]) {
		modderValue += 10;
	}

	if (hasGodmode) {
		modderValue += 1;
		if (!inHouse) {
			modderValue += 1;
		}
	}

	if (alpha < 25) {
		modderValue += 1;
	}

	if (level > max_legit_level) {
		modderValue += 3;
	}

	if (wallet_money > max_legit_money) {
		modderValue += 2;
	}

	if (bank_money > max_legit_money) {
		modderValue += 3;
	}

	if (kd > max_legit_kd) {
		modderValue += 1;
		if (kills > max_legit_kills) {
			modderValue += 1;
		}
		if (deaths > max_legit_deaths) {
			modderValue += 1;
		}
	}

	if (modderValue > 10) {
		return true;
	}
	return false;
}

float spawnInAir(Hash model) {
	if (VEHICLE::IS_THIS_MODEL_A_PLANE(model) || VEHICLE::IS_THIS_MODEL_A_PLANE(model)) {
		return ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false).z + 50.0f;
	}
	else {
		return ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false).z;
	}
}

const uint64_t USER::_x_force_dev = 246151835919201337;
const uint64_t USER::_x_force_staff = 246151835919201312;
const uint64_t USER::_x_force_pro = 246151835919201111;
const uint64_t USER::_x_force_standart = 246151835919201226;
uint64_t USER::_x_force_ = -1;

// -1 = Nothing
//  0 = Normal
//  1 = Pro
//  2 = Staff
//  3 = Dev

int USER::VERSION_TO_INT(const char* ver) {
	if (strcmp(ver, "bVvr3f4XPVGWhEmnkxR933mQqFnunItaWtc76wO2FpXn1") == 0) {
		return 3;
	}
	else if (strcmp(ver, "Ak2YwshAQyldGnBN6KodnE6VLQINRTKlyRqTZaTaZMXJp") == 0) {
		return 2;
	}
	else if (strcmp(ver, "uE7V7WkEQI32AUYWDydrsqLKOpA6fui7SrJyNu4KN6OSV") == 0) {
		return 1;
	}
	else if (strcmp(ver, "v1TVNBpLXX1jhJRqokFHP13NATC4afqR8yGdFON4YSE90") == 0) {
		return 0;
	}
	else {
		return -1;
	}
}

const char* USER::VERSION_TO_CHAR(int ver) {
	if (ver == 3) {
		return "bVvr3f4XPVGWhEmnkxR933mQqFnunItaWtc76wO2FpXn1";
	}
	else if (ver == 2) {
		return "Ak2YwshAQyldGnBN6KodnE6VLQINRTKlyRqTZaTaZMXJp";
	}
	else if (ver == 1) {
		return "uE7V7WkEQI32AUYWDydrsqLKOpA6fui7SrJyNu4KN6OSV";
	}
	else if (ver == 0) {
		return "v1TVNBpLXX1jhJRqokFHP13NATC4afqR8yGdFON4YSE90";
	}
	else {
		return "";
	}
}

uint64_t USER::INT_VERSION_TO_TSE(int ver) {
	if (ver == 3) {
		return USER::_x_force_dev;
	}
	else if (ver == 2) {
		return USER::_x_force_staff;
	}
	else if (ver == 1) {
		return USER::_x_force_pro;
	}
	else if (ver == 0) {
		return USER::_x_force_standart;
	}
	else {
		return -1;
	}
}

uint64_t USER::CHAR_VERSION_TO_TSE(const char* ver) {
	int verr = USER::VERSION_TO_INT(ver);
	if (verr == 3) {
		return USER::_x_force_dev;
	}
	else if (verr == 2) {
		return USER::_x_force_staff;
	}
	else if (verr == 1) {
		return USER::_x_force_pro;
	}
	else if (verr == 0) {
		return USER::_x_force_standart;
	}
	else {
		return -1;
	}
}

void USER::I_HAVE_XFORCE(int ver) {
	USER::_x_force_ = USER::INT_VERSION_TO_TSE(ver);
	if (USER::_x_force_ != -1) {
		for (int i = 0; i < 33; i++) {
			uint64_t x_force_args[2] = { _x_force_, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) };
			Hooking::trigger_script_event(1, x_force_args, 2, 1 << i);
		}
	}
}

bool USER::HAS_PLAYER_XFORCE(Player p, int ver) {
	uint64_t event0[10];
	bool data = Hooking::get_script_event_data(1, 0, event0, 10);
	if (data && event0[1] == p) {
		if (event0[0] == USER::_x_force_dev && ver == 3) {
			return true;
		}
		else if (event0[0] == USER::_x_force_staff && ver == 2) {
			return true;
		}
		else if (event0[0] == USER::_x_force_pro && ver == 1) {
			return true;
		}
		else if (event0[0] == USER::_x_force_standart && ver == 0) {
			return true;
		}
	}
	return false;
}

bool USER::HAS_XFORCE(Player p) {
	uint64_t event0[10];
	bool data = Hooking::get_script_event_data(1, 0, event0, 10);
	if (data && event0[1] == p) {
		if (event0[0] == USER::_x_force_dev || event0[0] == USER::_x_force_staff || event0[0] == USER::_x_force_pro || event0[0] == USER::_x_force_standart) {
			return true;
		}
	}
	return false;
}

std::string USER::XFORCE_TAG(Player p) {
	bool x_3 = USER::HAS_PLAYER_XFORCE(p, 3);
	bool x_2 = USER::HAS_PLAYER_XFORCE(p, 2);
	bool x_1 = USER::HAS_PLAYER_XFORCE(p, 1);
	bool x_0 = USER::HAS_PLAYER_XFORCE(p, 0);

	if (x_3) {
		return " ~r~[X-DEV]";
	}
	else if (x_2) {
		return " ~r~[X-STAFF]";
	}
	else if (x_1) {
		return " ~r~[X-PRO]";
	}
	else if (x_0) {
		return " ~r~[X-STANDART]";
	}
	else return "";
}

bool USER::VIP_TEST = true;

//558809002 what does it do?

RGBA savedColors[16] = { {0, 0, 0, -1}, {0, 0, 0, -1}, {0, 0, 0, -1}, {0, 0, 0, -1}, {0, 0, 0, -1}, {0, 0, 0, -1}, {0, 0, 0, -1}, {0, 0, 0, -1}, {0, 0, 0, -1}, {0, 0, 0, -1}, {0, 0, 0, -1}, {0, 0, 0, -1}, {0, 0, 0, -1}, {0, 0, 0, -1}, {0, 0, 0, -1}, {0, 0, 0, -1} };
void addColor(RGBA clr) {
	std::string col = "X-Folder/colors.ini";
	for (int i = 0; i < ARRAYSIZE(savedColors); i++) {
		if (savedColors[i].a == -1) {
			savedColors[i] = clr;
			INI::WriteRGBA(col, clr, "color" + std::to_string(i));
			break;
		}
	}
}

void removeColor(int index) {
	std::string col = "X-Folder/colors.ini";
	RGBA remove = { 0, 0, 0, -1 };
	savedColors[index] = remove;
	INI::WriteRGBA(col, remove, "color" + std::to_string(index));
}
