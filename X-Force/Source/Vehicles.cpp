#include "stdafx.h"

static char* Veh::arenawar[] = { "bruiser", "bruiser2", "bruiser3", "brutus", "brutus2",
"brutus3", "cerberus", "cerberus2", "cerberus3", "clique", "deathbike", "deathbike2",
"deathbike3", "deveste", "deviant", "dominator4", "dominator5", "dominator6",
"impaler", "impaler2", "impaler3", "issi4", "issi5", "issi6", "italigto", "monster3",
"monster4", "monster5", "rcbandito", "scarab", "scarab2", "scarab3", "schlagen", "slamvan4",
"slamvan5", "slamvan6", "toros", "tulip", "vamos", "zr380", "zr3802", "zr3803" };

void Veh::iArenawar() {
	switch (Menu::Settings::currentOption) {
	case 1: Menu::Vehicle("mba_vehicles", "bruiser_c_1"); break;
	case 2: Menu::Vehicle("mba_vehicles", "bruiser_c_2"); break;
	case 3: Menu::Vehicle("mba_vehicles", "bruiser_c_3"); break;
	case 4: Menu::Vehicle("mba_vehicles", "brutus1_b"); break;
	case 5: Menu::Vehicle("mba_vehicles", "brutus2_b"); break;
	case 6: Menu::Vehicle("mba_vehicles", "brutus3_b"); break;
	case 7: Menu::Vehicle("mba_vehicles", "cerberus1"); break;
	case 8: Menu::Vehicle("mba_vehicles", "cerberus2"); break;
	case 9: Menu::Vehicle("mba_vehicles", "cerberus3"); break;
	case 10: Menu::Vehicle("lgm_dlc_arena", "clique"); break;
	case 11: Menu::Vehicle("mba_vehicles", "deathbike_c_1"); break;
	case 12: Menu::Vehicle("mba_vehicles", "deathbike_c_2"); break;
	case 13: Menu::Vehicle("mba_vehicles", "deathbike_c_3"); break;
	case 14: Menu::Vehicle("lgm_dlc_arena", "deveste"); break;
	case 15: Menu::Vehicle("lgm_dlc_arena", "deviant"); break;
	case 16: Menu::Vehicle("mba_vehicles", "dominato_c_1"); break;
	case 17: Menu::Vehicle("mba_vehicles", "dominato_c_2"); break;
	case 18: Menu::Vehicle("mba_vehicles", "dominato_c_3"); break;
	case 19: Menu::Vehicle("mba_vehicles", "impaler_c_1"); break;
	case 20: Menu::Vehicle("mba_vehicles", "impaler_c_2"); break;
	case 21: Menu::Vehicle("mba_vehicles", "impaler_c_3"); break;
	//case 22: Menu::Vehicle("mba_vehicles", "issi_c_1"); break;
	//case 23: Menu::Vehicle("mba_vehicles", "issi_c_2"); break;
	//case 24: Menu::Vehicle("mba_vehicles", "issi_c_3"); break;
	case 25: Menu::Vehicle("lgm_dlc_arena", "italigto"); break;
	case 26: Menu::Vehicle("mba_vehicles", "monster_c_1"); break;
	case 27: Menu::Vehicle("mba_vehicles", "monster_c_2"); break;
	case 28: Menu::Vehicle("mba_vehicles", "monster_c_3"); break;
	case 29: Menu::Vehicle("sssa_dlc_arena", "rcbandito"); break;
	case 30: Menu::Vehicle("mba_vehicles", "scarab1_b"); break;
	case 31: Menu::Vehicle("mba_vehicles", "scarab2_b"); break;
	case 32: Menu::Vehicle("mba_vehicles", "scarab3_b"); break;
	case 33: Menu::Vehicle("lgm_dlc_arena", "schlagen"); break;
	case 34: Menu::Vehicle("mba_vehicles", "slamvan_c_1"); break;
	case 35: Menu::Vehicle("mba_vehicles", "slamvan_c_2"); break;
	case 36: Menu::Vehicle("mba_vehicles", "slamvan_c_3"); break;
	case 37: Menu::Vehicle("lgm_dlc_arena", "toros"); break;
	case 38: Menu::Vehicle("sssa_dlc_arena", "tulip"); break;
	case 39: Menu::Vehicle("sssa_dlc_arena", "vamos"); break;
	case 40: Menu::Vehicle("mba_vehicles", "zr3801_b"); break;
	case 41: Menu::Vehicle("mba_vehicles", "zr3802_b"); break;
	case 42: Menu::Vehicle("mba_vehicles", "zr3803_b"); break;
	}
}

static char* Veh::afterhrs[] = { "stafford", "scramjet", "strikeforce", "terbyte",
"pbus2", "oppressor2", "pounder2", "speedo4", "freecrawler", "mule4", "menacer", "blimp3", "swinger", "patriot2" };

void Veh::iAfterhours() {
	switch (Menu::Settings::currentOption) {
	case 1: Menu::Vehicle("lgm_dlc_battle", "stafford"); break;
	case 2: Menu::Vehicle("candc_battle", "scramjet"); break;
	case 3: Menu::Vehicle("candc_battle", "strikeforce"); break;
	case 4: Menu::Vehicle("candc_hacker", "banner0"); break;
	case 5: Menu::Vehicle("sssa_dlc_battle", "pbus2"); break;
	case 6: Menu::Vehicle("candc_battle", "oppressor2"); break;
	case 7: Menu::Vehicle("candc_battle", "pounder2"); break;
	//case 8: break;
	case 9: Menu::Vehicle("lgm_dlc_battle", "freecrawler"); break;
	case 10: Menu::Vehicle("candc_battle", "mule4"); break;
	case 11: Menu::Vehicle("candc_battle", "menacer"); break;
	case 12: Menu::Vehicle("elt_dlc_battle", "blimp3"); break;
	case 13: Menu::Vehicle("lgm_dlc_battle", "swinger"); break;
	//case 14: break;
	}
}

static char* Veh::SOUTHERNSAN[] = {
	"caracara", "cheburek", "dominator3", "ellie", "entity2", "fagaloa", "flashgt",
	"gb200", "hotring", "issi3", "jester3", "michelli", "seasparrow", "taipan", "tezeract",
	"tyrant"
};

void Veh::iSouthern() {
	switch (Menu::Settings::currentOption) {
	case 1: Menu::Vehicle("candc_assault", "caracara"); break;
		//DO IT!
	}
}

static char* Veh::Doomsday1[] = {
	"autarch", "avenger", "barrage", "chernobog", "comet4", "comet5",
	"deluxo", "gt500", "hermes", "hustler", "kamacho","khanjali",
	"neon", "pariah", "raiden", "revolter", "riata", "riot2", "savestra",
	"sc1", "sentinel3", "streiter", "stromberg", "thruster", "viseris",
	"volatol", "yosemite", "z190"
};

void Veh::iDoomsday() {
	switch (Menu::Settings::currentOption) {
	case 1: Menu::Vehicle("lgm_dlc_xmas2017", "autarch"); break;
	case 2: Menu::Vehicle("candc_chopper", "banner_0"); break;
	case 3: Menu::Vehicle("candc_xmas2017", "barrage"); break;
	case 4: Menu::Vehicle("candc_xmas2017", "chernobog"); break;
	case 5: Menu::Vehicle("lgm_dlc_xmas2017", "comet4"); break;
	case 6: Menu::Vehicle("lgm_dlc_xmas2017", "comet5"); break;
	case 7: Menu::Vehicle("candc_xmas2017", "deluxo"); break;
	case 8: Menu::Vehicle("lgm_dlc_xmas2017", "gt500"); break;
	//case 9: break;
	case 10: Menu::Vehicle("lgm_dlc_xmas2017", "hustler"); break;
	//case 11: break;
	case 12: Menu::Vehicle("candc_xmas2017", "khanjali"); break;
	case 13: Menu::Vehicle("lgm_dlc_xmas2017", "neon"); break;
	case 14: Menu::Vehicle("lgm_dlc_xmas2017", "pariah"); break;
	case 15: Menu::Vehicle("lgm_dlc_xmas2017", "raiden"); break;
	case 16: Menu::Vehicle("lgm_dlc_xmas2017", "revolter"); break;
	//case 17: break;
	case 18: Menu::Vehicle("candec_xmas2017", "riot2"); break;
	case 19: Menu::Vehicle("lgm_dlc_xmas2017", "savestra"); break;
	case 20: Menu::Vehicle("lgm_dlc_xmas2017", "sc1"); break;
	//case 21: break;
	case 22: Menu::Vehicle("lgm_dlc_xmas2017", "streiter"); break;
	case 23: Menu::Vehicle("candec_xmas2017", "stromberg"); break;
	case 24: Menu::Vehicle("candec_xmas2017", "thruster"); break;
	case 25: Menu::Vehicle("lgm_dlc_xmas2017", "viseris"); break;
	case 26: Menu::Vehicle("candec_xmas2017", "volatol"); break;
	//case 27: break;
	case 28: Menu::Vehicle("lgm_dlc_xmas2017", "z190"); break;
	}
}

static char* Veh::SMUGLERSRUN1[] = {
	"havok", "rapidgt3", "retinue", "vigilante", "visione", "cyclone", "ALPHAZ1",
	"BOMBUSHKA", "HOWARD", "HUNTER", "MICROLIGHT", "MOGUL", "MOLOTOK", "NOKOTA", "PYRO",
	"ROGUE", "SEABREEZE", "STARLING", "TULA"
};

void Veh::iSmugglers() {
	switch (Menu::Settings::currentOption) {
	case 1: Menu::Vehicle("elt_dlc_smuggler", "havok"); break;
	case 2: Menu::Vehicle("lgm_dlc_smuggler", "rapidgt3"); break;
	case 3: Menu::Vehicle("sssa_dlc_smuggler", "retinue"); break;
	case 4: Menu::Vehicle("candc_smuggler", "vigilante"); break;
	case 5: Menu::Vehicle("lgm_dlc_smuggler", "visione"); break;
	case 6: Menu::Vehicle("lgm_dlc_smuggler", "cyclone"); break;
	case 7: Menu::Vehicle("elt_dlc_smuggler", "alphaz1"); break;
	case 8: Menu::Vehicle("candc_smuggler", "bombushka"); break;
	case 9: Menu::Vehicle("elt_dlc_smuggler", "howard"); break;
	case 10: Menu::Vehicle("candc_smuggler", "hunter"); break;
	case 11: Menu::Vehicle("elt_dlc_smuggler", "microlight"); break;
	case 12: Menu::Vehicle("candc_smuggler", "mogul"); break;
	case 13: Menu::Vehicle("candc_smuggler", "molotok"); break;
	case 14: Menu::Vehicle("candc_smuggler", "nokota"); break;
	case 15: Menu::Vehicle("candc_smuggler", "pyro"); break;
	case 16: Menu::Vehicle("candc_smuggler", "rogue"); break;
	case 17: Menu::Vehicle("elt_dlc_smuggler", "seabreeze"); break;
	case 18: Menu::Vehicle("candc_smuggler", "starling"); break;
	case 19: Menu::Vehicle("candc_smuggler", "tula"); break;
	}
}

static char* Veh::GUNRUNNING1[] = {
	"APC", "ARDENT", "CADDY3", "CHEETAH2", "DUNE3", "HALFTRACK", "HAULER2",
	"INSUGENT3", "NIGHTSHARK", "OPPRESSOR", "PHANTOM3", "TAMPA3", "TECHNICAL3",
	"TORENO", "TRAILERLARGE", "TRAILERS4", "TRAILERSMALL2", "VAGNER", "XA21"
};

void Veh::iGunrunning() {
	switch (Menu::Settings::currentOption) {
	case 1: Menu::Vehicle("candc_gunrunning", "apc"); break;
	case 2: Menu::Vehicle("candc_gunrunning", "ardent"); break;
	//case 3: break;
	case 4: Menu::Vehicle("lgm_dlc_gunrunning", "cheetah2"); break;
	case 5: Menu::Vehicle("candc_gunrunning", "dune3"); break;
	case 6: Menu::Vehicle("candc_gunrunning", "halftrack"); break;
	case 7: Menu::Vehicle("candc_truck", "cab_1"); break;
	//case 8: break;
	case 9: Menu::Vehicle("candc_gunrunning", "nightshark"); break;
	case 10: Menu::Vehicle("candc_gunrunning", "oppressor"); break;
	case 11: Menu::Vehicle("candc_truck", "cab_0"); break;
	case 12: Menu::Vehicle("candc_gunrunning", "tampa3"); break;
	//case 13: break;
	case 14: Menu::Vehicle("lgm_dlc_gunrunning", "torero"); break;
	//case 15: break;
	//case 16: break;
	case 17: Menu::Vehicle("candc_gunrunning", "trsmall2"); break;
	case 18: Menu::Vehicle("lgm_dlc_gunrunning", "vagner"); break;
	case 19: Menu::Vehicle("lgm_dlc_gunrunning", "xa21"); break;
	}
}

static char* Veh::CUNNINGSTUNTS1[] = {
	"BF400", "BRIOSO", "CLIFFHANGER", "CONTENDER", "GARGOYLE", "LE7B", "LYNX",
	"OMNIS", "RALLYTRUCK", "SHEAVA", "TAMPA2", "TROPHYTRUCK", "TROPHYTRUCK2",
	"TROPOS", "TYRUS"
};

static char* Veh::IMPORTEXPORT1[] = {
	"BLAZER5", "BOXVILLE5", "COMET3", "DIABLOUS", "DIABLOUS2", "DUNE4", "DUNE5",
	"ELEGY", "FCR", "FCR2", "ITALIGTB", "ITALIGTB2", "NERO", "NERO2", "PENETRATOR",
	"PHANTOM2", "RUINER2", "SPECTER", "SPECTER2", "TECHNICAL2", "TEMPESTA", "VOLTIC2",
	"WASTELANDER"
};

static char* Veh::Boats1[] = {
	"DINGHY", "DINGHY2", "DINGHY3", "DINGHY4", "JETMAX",
	"MARQUIS", "PREDATOR", "SEASHARK", "SEASHARK2", "SEASHARK3",
	"SPEEDER", "SPEEDER2", "SQUALO", "SUBMERSIBLE", "SUBMERSIBLE2",
	"SUNTRAP", "TORO", "TORO2", "TROPIC", "TROPIC2",
	"TUG"
};

static char* Veh::Commercial1[] = {
	"BENSON", "BIFF", "HAULER", "MULE", "MULE2",
	"MULE3", "PACKER", "PHANTOM", "POUNDER", "STOCKADE",
	"STOCKADE3"
};

static char* Veh::Compacts1[] = {
	"BLISTA", "BRIOSO", "DILETTANTE", "DILETTANTE2", "ISSI2",
	"PANTO", "PRAIRIE", "RHAPSODY"
};

static char* Veh::Coupes1[] = {
	"COGCABRIO", "EXEMPLAR", "F620", "FELON", "FELON2",
	"JACKAL", "ORACLE", "ORACLE2", "SENTINEL", "SENTINEL2",
	"WINDSOR", "WINDSOR2", "ZION", "ZION2"
};

static char* Veh::Cycles1[] = {
	"BMX", "CRUISER", "FIXTER", "SCORCHER", "TRIBIKE",
	"TRIBIKE2", "TRIBIKE3"
};

static char* Veh::Emergency1[] = {
	"AMBULANCE", "FBI", "FBI2", "FIRETRUK", "LGUARD",
	"PBUS", "PRANGER", "POLICE", "POLICE2", "POLICE3",
	"POLICE4", "POLICEB", "POLICEOLD1", "POLICEOLD2", "POLICET",
	"SHERIFF", "SHERIFF2", "RIOT"
};

static char* Veh::Helicopters1[] = {
	"ANNIHILATOR", "BLIMP", "BLIMP2", "BUZZARD", "BUZZARD2",
	"CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER",
	"FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT",
	"SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE",
	"VALKYRIE2", "VOLATUS"
};

static char* Veh::Industrial1[] = {
	"BULLDOZER", "CUTTER", "DUMP", "FLATBED", "GUARDIAN",
	"HANDLER", "MIXER", "MIXER2", "RUBBLE", "TIPTRUCK",
	"TIPTRUCK2"
};

static char* Veh::Military1[] = {
	"BARRACKS", "BARRACKS2", "BARRACKS3", "CRUSADER", "RHINO"
};

static char* Veh::Motorcycles1[] = {
	"AKUMA", "AVARUS", "BAGGER", "BATI", "BATI2",
	"BF400", "CARBONRS", "CHIMERA", "CLIFFHANGER", "DAEMON",
	"DAEMON2", "DEFILER", "DOUBLE", "ENDURO", "ESSKEY",
	"FAGGIO", "FAGGIO2", "FAGGIO3", "GARGOYLE", "HAKUCHOU",
	"HAKUCHOU2", "HEXER", "INNOVATION", "LECTRO", "MANCHEZ",
	"NEMESIS", "NIGHTBLADE", "PCJ", "RATBIKE", "RUFFIAN",
	"SANCHEZ", "SANCHEZ2", "SANCTUS", "SHOTARO", "SOVEREIGN",
	"THRUST", "VADER", "VINDICATOR", "VORTEX", "WOLFSBANE",
	"ZOMBIEA", "ZOMBIEB", "DIABLOUS", "DIABLOUS2", "FCR",
	"FCR2", "OPPRESSOR"
};

static char* Veh::Muscle1[] = {
	"BLADE", "BUCCANEER", "BUCCANEER2", "CHINO", "CHINO2",
	"COQUETTE3", "DOMINATOR", "DOMINATOR2", "DUKES", "DUKES2",
	"GAUNTLET", "GAUNTLET2", "FACTION", "FACTION2", "FACTION3",
	"HOTKNIFE", "LURCHER", "MOONBEAM", "MOONBEAM2", "NIGHTSHADE",
	"PHOENIX", "PICADOR", "RATLOADER", "RATLOADER2", "RUINER", "RUINER2", "RUINER3",
	"SABREGT", "SABREGT2", "SLAMVAN", "SLAMVAN2", "SLAMVAN3",
	"STALION", "STALION2", "TAMPA", "VIGERO", "VIRGO",
	"VIRGO2", "VIRGO3", "VOODOO", "VOODOO2"
};

static char* Veh::OffRoad1[] = {
	"BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3",
	"BLAZER4", "BODHI2", "BRAWLER", "DLOADER", "DUBSTA3",
	"DUNE", "DUNE2", "INSURGENT", "INSURGENT2", "KALAHARI",
	"MARSHALL", "MESA3", "MONSTER", "RANCHERXL", "RANCHERXL2",
	"REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL",
	"TROPHYTRUCK", "TROPHYTRUCK2", "TECHNICAL2", "DUNE4", "DUNE5",
	"BLAZER5"
};

static char* Veh::Planes1[] = {
	"BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
	"HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
	"MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
	"TITAN", "VELUM", "VELUM2", "VESTRA"
};

static char* Veh::Sedans1[] = {
	"ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552",
	"COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3",
	"FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2",
	"PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO",
	"SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM",
	"STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARR"
};

static char* Veh::Sports1[] = {
	"ALPHA", "BANSHEE", "BESTIAGTS", "BLISTA2", "BLISTA3",
	"BUFFALO", "BUFFALO2", "BUFFALO3", "CARBONIZZARE", "COMET2",
	"COQUETTE", "ELEGY", "ELEGY2", "FELTZER2", "FUROREGT", "FUSILADE",
	"FUTO", "JESTER", "JESTER2", "KHAMELION", "KURUMA",
	"KURUMA2", "LYNX", "MASSACRO", "MASSACRO2", "NINEF",
	"NINEF2", "OMNIS", "PENUMBRA", "RAPIDGT", "RAPIDGT2",
	"RAPTOR", "SCHAFTER3", "SCHAFTER4", "SCHWARTZER", "SEVEN70",
	"SULTAN", "SURANO", "SPECTER", "SPECTER2", "TAMPA2", "TROPOS", "VERLIERER2",
	"RUINER2", "PHANTOM2", "RUSTON"
};

static char* Veh::SportsClassics1[] = {
	"BTYPE", "BTYPE2", "BTYPE3", "CASCO", "COQUETTE2",
	"FELTZER3", "JB700", "MAMBA", "MANANA", "MONROE",
	"PEYOTE", "PIGALLE", "STINGER", "STINGERGT", "TORNADO",
	"TORNADO2", "TORNADO3", "TORNADO4", "TORNADO5", "TORNADO6",
	"ZTYPE", "INFERNUS2", "TURISMO2",
};

static char* Veh::Super1[] = {
	"ADDER", "BANSHEE2", "BULLET", "CHEETAH", "ENTITYXF",
	"FMJ", "SHEAVA", "INFERNUS", "NERO", "NERO2","OSIRIS", "LE7B",
	"ITALIGTB", "ITALIGTB2", "PFISTER811", "PROTOTIPO", "REAPER", "SULTANRS", "T20",
	"TEMPESTA", "TURISMOR", "TYRUS", "VACCA", "VOLTIC", "ZENTORNO", "VOLTIC2", "PENETRATOR", "GP1"
};

static char* Veh::SUVs1[] = {
	"BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5",
	"BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER",
	"DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY",
	"HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2",
	"PATRIOT", "RADI", "ROCOTO", "SEMINOLE", "SERRANO",
	"XLS", "XLS2"
};

static char* Veh::Trailer1[] = {
	"ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER",
	"DOCKTRAILER", "FREIGHTTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER",
	"TANKER", "TANKER2", "TR2", "TR3", "TR4",
	"TRAILERLOGS", "TRAILERS", "TRAILERS2", "TRAILERS3", "TRAILERSMALL",
	"TRFLAT", "TVTRAILER"
};

static char* Veh::Trains1[] = {
	"CABLECAR", "FREIGHT", "FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2",
	"FREIGHTGRAIN", "METROTRAIN", "TANKERCAR"
};

static char* Veh::Utility1[] = {
	"AIRTUG", "CADDY", "CADDY2", "DOCKTUG", "FORKLIFT",
	"MOWER", "RIPLEY", "SADLER", "SADLER2", "SCRAP",
	"TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3",
	"UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3"
};

static char* Veh::Vans1[] = {
	"BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE",
	"BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BURRITO", "BURRITO2",
	"BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO",
	"GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2", "PARADISE",
	"PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3",
	"SPEEDO", "SPEEDO2", "SURFER", "SURFER2", "TACO",
	"YOUGA", "YOUGA2"
};

static char* Veh::trucks1[] = {
	"boxville","stockade","stockade2","tiptruck","tiptruck2",
	"cutter","handler","docktug","dump","biff","hauler","phantom",
	"rubble","mule","mixer","mixer2","flatbed","packer","pounder",
	"benson","scrap","phanotm2","hauler2","phantom3",
};

static char* subbs[] = {
	"arenawar0",
	"afterhours0",
	"san",
	"Doomsday",
	"SmuglerRun1",
	"GunRunning1",
	"ImportEx1",
	"CunningStunts1",
	"Supers",
	"Sports",
	"SportClassic",
	"Offroad",
	"Sedans",
	"Coupes",
	"Muscle",
	"Boats",
	"Commercial",
	"Compacts",
	"Cycles",
	"Emergency",
	"Helicopters",
	"Industrial",
	"Military",
	"Motorcycles",
	"Planes",
	"Service",
	"SUV",
	"Trailer",
	"Trains",
	"Utility",
	"Vans",
	"trucks"
};