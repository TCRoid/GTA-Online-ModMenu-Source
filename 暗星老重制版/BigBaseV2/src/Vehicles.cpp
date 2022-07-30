#include "vehicles.h"
#include "natives.hpp"
#include "gta_util.hpp"
#include "script.hpp"
#include"util/util.hpp"
static const char* car_classes[] = {
	"Boats", "Comercial", "Compacts", "Coupes", "Cycles",
	"Emergency", "Helicopters", "Industrial", "Military", "Motorcycles", "Muscle",
	"OffRoad", "Planes", "Sedans", "Service", "Sports", "Sports Classics",
	"Super", "SUVs", "Trailer", "Trains", "Utility", "Vans", "DLC: Import/Export",
	"DLC: Gunrunning", "DLC: Smuggler's Run", "DLC: Doomsday Heist", "DLC: Super Sport Series",
	"DLC: After Hours", "DLC: Arena War", "DLC: Diamond Casino"
};

static const char* Import_Export[] = {
	"buffalo4","granger2","iwagen","patriot3","astron","deity",
"ignus","jubilee","reever","shinobi","Sugoi","zeno","baller7",
"champion","cinquemila","comet7"
};

static const char* haidao[] = {
	"alkonost","avisa","brioso2","dinghy5","italirsx"
	,"kosatka","longfin","manchez2","patrolboat","seasparrow3",
	"slamtruck","squaddie","toreador","verus","vetir",
	"veto","veto2","weevil","winky"
};

static const char* Gunrunning[] = {
	"XA21", "CADDY3", "VAGNER", "PHANTOM3", "NIGHTSHARK", "CHEETAH2", "TORERO", "HAULER2", "TECHNICAL3", "INSURGENT3", "APC", "TAMPA3", "DUNE3",
	 "TRAILERSMALL2", "HALFTRACK", "ARDENT", "OPPRESSOR"
};

static const char* Smugglers_Run[] = {
	"ALPHAZ1", "VISIONE", "STARLING", "TULA", "HAVOK", "MICROLIGHT", "MOLOTOK", "RETINUE", "ROGUE", "HOWARD", "PYRO", "CYCLONE", "RAPIDGT3",
	 "HUNTER", "MOGUL", "BOMBUSHKA", "NOKOTA", "VIGILANTE", "SEABREEZE"
};

static const char* Doomsday_Heist[] = {
	"AKULA", "BARRAGE", "CHERNOBOG", "RAIDEN", "YOSEMITE", "DELUXO", "AVENGER", "AVENGER2", "THRUSTER", "PARIAH", "STROMBERG", "COMET4", "COMET5", "RIOT2",
	 "KHANJALI", "SC1", "VOLATOL", "HERMES", "SAVESTRA", "RIATA", "STREITER", "KAMACHO", "GT500", "Z190", "VISERIS", "AUTARCH",  "NEON", "REVOLTER", "SENTINEL3", "HUSTLER"
};

static const char* Super_Sport_Series[] = {
	"CARACARA", "CHEBUREK", "DOMINATOR3", "ELLIE", "ENTITY2", "FAGALOA", "AVENGER", "FLASHGT", "GB200", "HOTRING", "ISSI3", "JESTER3", "MICHELLI",
	 "SEASPARROW", "TEZERACT", "TAIPAN", "TYRANT"
};

static const char* After_Hours[] = {
	"BLIMP3", "FREECRAWLER", "MENACER", "OPPRESSOR2", "PATRIOT2", "SCRAMJET", "STAFFORD", "STRIKEFORCE", "SWINGER", "TERBYTE"
};

static const char* Arena_War[] = {
	"BRUISER", "BRUISER2", "BRUISER3", "BRUTUS", "BRUTUS2", "BRUTUS3", "CERBERUS", "CERBERUS2", "CERBERUS3", "CLIQUE", "DEATHBIKE", "DEATHBIKE2", "DEATHBIKE3",
	 "DEVESTE", "DEVIANT", "DOMINATOR4", "DOMINATOR5", "DOMINATOR6", "IMPALER", "IMPALER2", "IMPALER3", "IMPALER4", "IMPERATOR", "IMPERATOR2", "IMPERATOR3", "ISSI4", "ISSI5", "ISSI6",
	 "ITALIGTO", "MONSTER3", "MONSTER4", "MONSTER5", "RCBANDITO", "SCARAB", "SCARAB2", "SCARAB3", "SCHLAGEN", "SLAMVAN4", "SLAMVAN5", "SLAMVAN6", "TULIP", "VAMOS",
	 "ZR380", "ZR3802", "ZR3803"
};

static const char* Diamond_Casino[] = {
	"CARACARA2", "DYNASTY", "EMERUS",
	"GAUNTLET3", "GAUNTLET4", "HELLION", "ISSI7",
	"JUGULAR", "KRIEGER", "LOCUST", "NEBULA",
	"NEO", "NOVAK", "PARAGON", "PARAGON2",
	"PEYOTE2", "RROCKET", "S80",
	"THRAX", "ZION3", "ZORRUSSO"
};

static const char* Diamond_Casino_Heist[] = {
	"FORMULA", "FORMULA2", "FURIA", "IMORGON",
	"KOMODA", "REBLA", "STRYDER", "VSTR",
	"ASBO", "EVERON", "KANJO", "OUTLAW",
	"RETINUE2", "SUGOI", "SULTAN2",
	"VAGRANT", "YOSEMITE2", "JB7002",
	"MINITANK", "ZHABA"
};

static const char* Boats1[] = {
	"DINGHY", "DINGHY2", "DINGHY3", "JETMAX",
	"MARQUIS", "PREDATOR", "SEASHARK", "SEASHARK2", "SEASHARK3",
	"SPEEDER", "SPEEDER2", "SQUALO", "SUBMERSIBLE", "SUBMERSIBLE2",
	"SUNTRAP", "TORO", "TORO2", "TROPIC", "TROPIC2",
	"TUG"
};
static const char* Commercial1[] = {
	"BENSON", "BIFF", "HAULER", "HAULER2", "MULE", "MULE2",
	"MULE3", "MULE4", "PACKER", "PHANTOM","PHANTOM2", "PHANTOM3", "POUNDER", "POUNDER2", "STOCKADE",
	"STOCKADE3", "TERBYTE", "CERBERUS", "CERBERUS2", "CERBERUS3",
};
static const char* Compacts1[] = {
	"BLISTA", "BLISTA2", "BLISTA3", "BRIOSO", "DILETTANTE", "DILETTANTE2",
	"PANTO", "PRAIRIE", "RHAPSODY", "ISSI2", "ISSI3", "ISSI4", "ISSI5", "ISSI6", "ISSI7"
};
static const char* Coupes1[] = {
	"COGCABRIO", "EXEMPLAR", "F620", "FELON", "FELON2",
	"JACKAL", "ORACLE", "ORACLE2", "SENTINEL", "SENTINEL2",
	"WINDSOR", "WINDSOR2", "ZION", "ZION2"
};
static const char* Cycles1[] = {
	"BMX", "CRUISER", "FIXTER", "SCORCHER", "TRIBIKE",
	"TRIBIKE2", "TRIBIKE3"
};
static const char* Emergency1[] = {
	"AMBULANCE", "FBI", "FBI2", "FIRETRUK",
	"POLICE", "POLICE2", "POLICE3",
	"POLICE4", "POLICEOLD1", "POLICEOLD2", "POLICET", "POLICEB",
	"PBUS", "PRANGER", "LGUARD",
	"SHERIFF", "SHERIFF2", "RIOT", "RIOT2"
};
static const char* Helicopters1[] = {
	"ANNIHILATOR", "BUZZARD", "BUZZARD2",
	"CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER",
	"FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT",
	"SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE",
	"VALKYRIE2", "VOLATUS", "HAVOK", "MICROLIGHT", "HUNTER", "AKULA",
	"AVENGER", "AVENGER2", "SEASPARROW"
};
static const char* Industrial1[] = {
	"BULLDOZER", "CUTTER", "DUMP", "FLATBED", "GUARDIAN",
	"HANDLER", "MIXER", "MIXER2", "RUBBLE", "TIPTRUCK",
	"TIPTRUCK2"
};
static const char* Military1[] = {
	"BARRACKS", "BARRACKS2", "CRUSADER", "RHINO",  "APC",
	"HALFTRACK", "BARRAGE", "CHERNOBOG", "KHANJALI", "SCARAB", "SCARAB2", "SCARAB3",
	"THRUSTER"
};
static const char* Motorcycles1[] = {
	"AKUMA", "AVARUS", "BAGGER", "BATI", "BATI2",
	"BF400", "CARBONRS", "CHIMERA", "CLIFFHANGER", "DAEMON",
	"DAEMON2", "DEFILER", "DOUBLE", "ENDURO", "ESSKEY",
	"FAGGIO", "FAGGIO2", "FAGGIO3", "GARGOYLE", "HAKUCHOU",
	"HAKUCHOU2", "HEXER", "INNOVATION", "LECTRO", "MANCHEZ",
	"NEMESIS", "NIGHTBLADE", "PCJ", "RATBIKE", "RUFFIAN",
	"SANCHEZ", "SANCHEZ2", "SANCTUS", "SHOTARO", "SOVEREIGN",
	"THRUST", "VADER", "VINDICATOR", "VORTEX", "WOLFSBANE",
	"ZOMBIEA", "ZOMBIEB", "DIABLOUS", "DIABLOUS2", "FCR",
	"FCR2", "OPPRESSOR", "OPPRESSOR2", "DEATHBIKE", "DEATHBIKE2", "DEATHBIKE3", "RROCKET"
};
static const char* Muscle1[] = {
	"BLADE", "BUCCANEER", "BUCCANEER2", "CHINO", "CHINO2",
	"COQUETTE3", "DOMINATOR", "DOMINATOR2", "DOMINATOR3", "DOMINATOR4", "DOMINATOR5", "DOMINATOR6", "DUKES", "DUKES2",
	"GAUNTLET", "GAUNTLET2", "FACTION", "FACTION2", "FACTION3",
	"HOTKNIFE", "LURCHER", "MOONBEAM", "MOONBEAM2", "NIGHTSHADE",
	"PHOENIX", "PICADOR", "RATLOADER", "RATLOADER2", "RUINER", "RUINER2", "RUINER3",
	"SABREGT", "SABREGT2", "SLAMVAN", "SLAMVAN2", "SLAMVAN3",
	"STALION", "STALION2", "TAMPA", "TAMPA3", "VIGERO", "VIRGO",
	"VIRGO2", "VIRGO3", "VOODOO", "VOODOO2", "ELLIE",
	"CLIQUE", "DEVIANT", "IMPALER", "IMPALER2", "IMPALER3", "IMPALER4",
	"IMPERATOR", "IMPERATOR2", "IMPERATOR3", "SLAMVAN4", "SLAMVAN5", "SLAMVAN6",
	"TULIP", "VAMOS","GAUNTLET3", "GAUNTLET4", "YOSEMITE"
};
static const char* OffRoad1[] = {
	"BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3",
	"BLAZER4", "BLAZER5", "BODHI2", "BRAWLER", "DLOADER", "DUBSTA3",
	"DUNE", "DUNE2", "DUNE3", "DUNE4", "DUNE5", "INSURGENT", "INSURGENT2", "INSURGENT3", "KALAHARI",
	"MARSHALL", "MESA3", "MONSTER", "MONSTER3", "MONSTER4", "MONSTER5", "RANCHERXL", "RANCHERXL2",
	"REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL", "TECHNICAL2", "TECHNICAL3", "NIGHTSHARK",
	"TROPHYTRUCK", "TROPHYTRUCK2",
	"COMET4", "RIATA", "KAMACHO", "CARACARA","CARACARA2", "FREECRAWLER", "MENACER",
	"BRUISER", "BRUISER2", "BRUISER3", "BRUTUS", "BRUTUS2", "BRUTUS3", "RCBANDITO", "HELLION"
};
static const char* Planes1[] = {
	"BESRA", "BLIMP", "BLIMP2", "BLIMP3", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
	"HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
	"MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
	"TITAN", "VELUM", "VELUM2", "VESTRA", "ALPHAZ1",
	"STARLING", "TULA", "MOLOTOK", "ROGUE", "HOWARD", "PYRO",
	"MOGUL", "BOMBUSHKA", "NOKOTA", "SEABREEZE", "VOLATOL",
	"STRIKEFORCE"
};
static const char* Sedans1[] = {
	"ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552",
	"COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3",
	"FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2",
	"PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO",
	"SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM",
	"STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARRENER",
	"WASHINGTON", "REVOLTER", "STAFFORD"
};
static const char* Service1[] = {
	"AIRBUS", "BRICKADE", "BUS", "PBUS2", "COACH", "RALLYTRUCK",
	"RENTALBUS", "TAXI", "TOURBUS", "TRASH", "TRASH2",
	"WASTELANDER"
};
static const char* Sports1[] = {
	"ALPHA", "BANSHEE", "BESTIAGTS",
	"BUFFALO", "BUFFALO2", "BUFFALO3", "CARBONIZZARE", "COMET2",  "COMET3", "COMET5",
	"COQUETTE", "ELEGY", "ELEGY2", "FELTZER2", "FUROREGT", "FUSILADE",
	"FUTO", "JESTER", "JESTER2", "JESTER3", "KHAMELION", "KURUMA",
	"KURUMA2", "LYNX", "MASSACRO", "MASSACRO2", "NINEF",
	"NINEF2", "OMNIS", "PENUMBRA", "RAPIDGT", "RAPIDGT2", "RAPIDGT3",
	"RAPTOR", "SCHAFTER3", "SCHAFTER4", "SCHWARZER", "SEVEN70", "STREITER",
	"SULTAN", "SURANO", "SPECTER", "SPECTER2", "TAMPA2", "TROPOS", "VERLIERER2",
	"RUSTON", "RAIDEN", "PARIAH",  "NEON", "FLASHGT", "GB200",
	"HOTRING", "SCHLAGEN", "ZR380", "ZR3802", "ZR3803", "JUGULAR", "LOCUST", "NEBULA",
	"PARAGON", "PARAGON2"
};
static const char* SportsClassics1[] = {
	"BTYPE", "BTYPE2", "BTYPE3", "CASCO", "COQUETTE2",
	"FELTZER3", "JB700", "MAMBA", "MANANA", "MONROE",
	"PEYOTE", "PEYOTE2", "PIGALLE", "STINGER", "STINGERGT", "CHEETAH2", "TORERO", "TORNADO",
	"TORNADO2", "TORNADO3", "TORNADO4", "TORNADO5", "TORNADO6", "ZION3", "RETINUE", "SAVESTRA",
	"ZTYPE", "INFERNUS2", "TURISMO2", "DELUXO", "STROMBERG", "ARDENT",
	"HERMES", "GT500", "Z190", "VISERIS", "SENTINEL3", "HUSTLER", "CHEBUREK",
	"MICHELLI", "FAGALOA", "SWINGER", "DYNASTY"
};
static const char* Super1[] = {
	"ADDER", "BANSHEE2", "BULLET", "CHEETAH", "ENTITYXF",
	"FMJ", "SHEAVA", "INFERNUS", "NERO", "NERO2","OSIRIS", "LE7B",
	"ITALIGTB", "ITALIGTB2", "PFISTER811", "PROTOTIPO", "REAPER", "SULTANRS", "T20",
	"TEMPESTA", "TURISMOR", "TYRUS", "VACCA", "VOLTIC", "VOLTIC2", "ZENTORNO", "PENETRATOR", "GP1",
	"XA21", "VAGNER", "VIGILANTE", "VISIONE", "CYCLONE", "SC1", "AUTARCH", "ENTITY2",
	"TEZERACT", "TAIPAN", "TYRANT", "SCRAMJET", "DEVESTE", "ITALIGTO", "EMERUS", "KRIEGER",
	 "S80","THRAX", "ZORRUSSO"
};
static const char* SUVs1[] = {
	"BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5",
	"BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER",
	"DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY",
	"HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2",
	"PATRIOT", "PATRIOT2", "RADI", "ROCOTO", "SEMINOLE", "SERRANO",
	"XLS", "XLS2", "NOVAK"
};
static const char* Trailer1[] = {
	"ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER",
	"CABLECAR","DOCKTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER",
	"TR2", "TR3", "TR4", "TRFLAT", "TVTrailer", "Tanker", "Tanker2", "TrailerLogs",
	"TrailerSmall", "TRAILERSMALL2", "Trailers", "Trailers2", "Trailers3"
};
static const char* Trains1[] = {
	"FREIGHT", "FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2",
	"FREIGHTGRAIN", "METROTRAIN", "TANKERCAR"
};
static const char* Utility1[] = {
	"AIRTUG", "CADDY", "CADDY2", "CADDY3", "DOCKTUG", "FORKLIFT",
	"MOWER", "RIPLEY", "SADLER", "SADLER2", "SCRAP",
	"TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3",
	"UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3"
};
static const char* Vans1[] = {
	"BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE",
	"BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BURRITO", "BURRITO2",
	"BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO",
	"GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2", "PARADISE",
	"PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3",
	"SPEEDO", "SPEEDO2", "SPEEDO4", "SURFER", "SURFER2", "TACO",
	"YOUGA", "YOUGA2"
};

std::string getModCategoryName(int i)
{
	switch (i)
	{
	case 0:
		return "Spoiler";
	case 1:
		return "Front Bumper";
	case 2:
		return "Rear Bumper";
	case 3:
		return "Side Skirts";
	case 4:
		return "Exhaust";
	case 5:
		return "Rollcage";
	case 6:
		return "Grille";
	case 7:
		return "Bonnet";
	case 8:
		return "Fenders and Arches";
	case 9:
		return "Fenders";
	case 10:
		return "Roof";
	case 11:
		return "Engine";
	case 12:
		return "Brakes";
	case 13:
		return "Transmission";
	case 14:
		return "Horn";
	case 15:
		return "Suspension";
	case 16:
		return "Armor";
	case 22:
		return "Headlights";
	case 23:
		return "Wheels"; // front
	case 24:
		return "Wheels2"; // rear
	case 25:
		return "Plate Holders";
	case 26:
		return "Vanity Plates";
	case 27:
		return "Interior Trim";
	case 28:
		return "Ornaments";
	case 29:
		return "Interior Dash";
	case 30:
		return "Dials";
	case 31:
		return "Door Speakers";
	case 32:
		return "Leather Seats";
	case 33:
		return "Steering Wheels";
	case 34:
		return "Column Shifters";
	case 35:
		return "Plaques";
	case 36:
		return "ICE";
	case 37:
		return "Speakers";
	case 38:
		return "Hydraulics";
	case 39:
		return "Engine Block";
	case 40:
		return "Air Filters";
	case 41:
		return "Strut Braces";
	case 42:
		return "Arch Covers";
	case 43:
		return "Aerials";
	case 44:
		return "Exterior Trim";
	case 45:
		return "Tank";
	case 46:
		return "Windows";
	case 48:
		return "Livery";
		/*case SPECIAL_ID_FOR_WHEEL_CATEGORY:
			return "Wheel Category";
		case SPECIAL_ID_FOR_WHEEL_SELECTION:
			return "Wheel Choice";
		case SPECIAL_ID_FOR_WINDOW_TINT:
			return "Window Tint";
		case SPECIAL_ID_FOR_LICENSE_PLATES:
			return "License Plates";*/
	default:
		return std::to_string(i);
	}
}

std::string getHornTitle(int index)
{
	if (index == 0)
	{
		return "Truck Horn";
	}
	else if (index == 1)
	{
		return "Cop Horn";
	}
	else if (index == 2)
	{
		return "Clown Horn";
	}
	else if (index == 3)
	{
		return "Musical Horn 1";
	}
	else if (index == 4)
	{
		return "Musical Horn 2";
	}
	else if (index == 5)
	{
		return "Musical Horn 3";
	}
	else if (index == 6)
	{
		return "Musical Horn 4";
	}
	else if (index == 7)
	{
		return "Musical Horn 5";
	}
	else if (index == 8)
	{
		return "Sad Trombone";
	}
	else if (index == 9)
	{
		return "Classical Horn 1";
	}
	else if (index == 10)
	{
		return "Classical Horn 2";
	}
	else if (index == 11)
	{
		return "Classical Horn 3";
	}
	else if (index == 12)
	{
		return "Classical Horn 4";
	}
	else if (index == 13)
	{
		return "Classical Horn 5";
	}
	else if (index == 14)
	{
		return "Classical Horn 6";
	}
	else if (index == 15)
	{
		return "Classical Horn 7";
	}
	else if (index == 16)
	{
		return "Scale - Do";
	}
	else if (index == 17)
	{
		return "Scale - Re";
	}
	else if (index == 18)
	{
		return "Scale - Mi";
	}
	else if (index == 19)
	{
		return "Scale - Fa";
	}
	else if (index == 20)
	{
		return "Scale - Sol";
	}
	else if (index == 21)
	{
		return "Scale - La";
	}
	else if (index == 22)
	{
		return "Scale - Ti";
	}
	else if (index == 23)
	{
		return "Scale - Do";
	}
	else if (index == 24)
	{
		return "Jazz Horn 1";
	}
	else if (index == 25)
	{
		return "Jazz Horn 2";
	}
	else if (index == 26)
	{
		return "Jazz Horn 3";
	}
	else if (index == 27)
	{
		return "Jazz Horn Loop";
	}
	else if (index == 28)
	{
		return "Star Spangled Banner 1";
	}
	else if (index == 29)
	{
		return "Star Spangled Banner 2";
	}
	else if (index == 30)
	{
		return "Star Spangled Banner 3";
	}
	else if (index == 31)
	{
		return "Star Spangled Banner 4";
	}
	else if (index == 32)
	{
		return "Classical Horn 8 Loop";
	}
	else if (index == 33)
	{
		return "Classical Horn 9 Loop";
	}
	else if (index == 34)
	{
		return "Classical Horn 10 Loop";
	}
	else if (index == 35)
	{
		return "Classical Horn 8";
	}
	else if (index == 36)
	{
		return "Classical Horn 9";
	}
	else if (index == 37)
	{
		return "Classical Horn 10";
	}
	else if (index == 38)
	{
		return "Funeral Loop";
	}
	else if (index == 39)
	{
		return "Funeral";
	}
	else if (index == 40)
	{
		return "Spooky Loop";
	}
	else if (index == 41)
	{
		return "Spooky";
	}
	else if (index == 42)
	{
		return "San Andreas Loop";
	}
	else if (index == 43)
	{
		return "San Andreas";
	}
	else if (index == 44)
	{
		return "Liberty City Loop";
	}
	else if (index == 45)
	{
		return "Liberty City";
	}
	/*	else if (index == 46)
		{
			return "Festive 1 Loop";
		}
		else if (index == 47)
		{
			return "Festive 1";
		}
		else if (index == 48)
		{
			return "Festive 2 Loop";
		}
		else if (index == 49)
		{
			return "Festive 2";
		}
		else if (index == 50)
		{
			return "Festive 3 Loop";
		}
		else if (index == 51)
		{
			return "Festive 3";
		}
	*/
	return "Unknown Horn";
}

std::string getNormalItemTitle(Vehicle veh, int category, int index)
{
	//Engine stuff is EMS Upgrade, Level 1-4
	//Brakes/trans are stock, street, sports, race
	//Susp is stock,lowered,street,sport,competition
	//Armor is none, 20, 40, 60, 80, 100%

	std::string modItemNameStr;

	if (index == -1)
	{
		if (category == 16)
		{
			modItemNameStr = "No Armor";
		}
		else
		{
			std::ostringstream ss;
			ss << "Stock " << getModCategoryName(category);
			modItemNameStr = ss.str();
		}
	}
	else if (category == 11) //Engine
	{
		std::ostringstream ss;
		ss << "EMS Upgrade, Level " << (index + 1);
		modItemNameStr = ss.str();
	}
	else if (category == 12 || category == 13) //brakes, trans
	{
		std::ostringstream ss;
		ss << BRAKES_AND_TRANS_PREFIXES[index];
		if (category == 12)
		{
			ss << " Brakes";
		}
		else
		{
			ss << " Transmission";
		}
		modItemNameStr = ss.str();
	}
	else if (category == 14) //horn
	{
		modItemNameStr = getHornTitle(index);
	}
	else if (category == 15) //suspension
	{
		std::ostringstream ss;
		ss << SUSP_PREFIXES[index] << " Suspension";
		modItemNameStr = ss.str();
	}
	else if (category == 16) //Armor
	{
		std::ostringstream ss;
		ss << ((index + 1) * 20) << "% Armor";
		modItemNameStr = ss.str();
	}
	else
	{
		const char* modItemNameChr = VEHICLE::GET_MOD_TEXT_LABEL(veh, category, index);
		bool foundName = false;
		if (modItemNameChr != NULL && strlen(modItemNameChr) > 0)
		{
			const char* modItemNameTxt = HUD::_GET_LABEL_TEXT(modItemNameChr);
			if (modItemNameTxt != NULL)
			{
				modItemNameStr = std::string(modItemNameTxt) + "##" + std::to_string(index);
				foundName = true;
			}
		}

		if (!foundName)
		{
			std::ostringstream ss;
			ss << getModCategoryName(category) << " Item " << (index + 1);
			modItemNameStr = ss.str();
		}
	}

	return modItemNameStr;
}

void Vehicles::initialize()
{
	std::vector<std::string> buffer;

	{
		VehicleClass vehClass;
		vehClass.className = "船";
		for (const char* str : Boats1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "小型车辆";
		for (const char* str : Compacts1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "轿跑车";
		for (const char* str : Coupes1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "自行车";
		for (const char* str : Cycles1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "警用车辆";
		for (const char* str : Emergency1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "直升机";
		for (const char* str : Helicopters1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "工业车辆";
		for (const char* str : Industrial1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "军用车辆";
		for (const char* str : Military1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "摩托车";
		for (const char* str : Motorcycles1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "肌肉车";
		for (const char* str : Muscle1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "越野车";
		for (const char* str : OffRoad1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "飞机";
		for (const char* str : Planes1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "轿车";
		for (const char* str : Sedans1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "公共服务车";
		for (const char* str : Service1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "跑车";
		for (const char* str : Sports1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "经典跑车";
		for (const char* str : SportsClassics1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "超级跑车";
		for (const char* str : Super1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "SUV";
		for (const char* str : SUVs1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "拖车";
		for (const char* str : Trailer1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "火车";
		for (const char* str : Trains1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "公共事业车";
		for (const char* str : Utility1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "货车";
		for (const char* str : Vans1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "商业车辆";
		for (const char* str : Commercial1)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "军火霸业DLC";
		for (const char* str : Gunrunning)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "走私大暴走DLC";
		for (const char* str : Smugglers_Run)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "末日豪劫";
		for (const char* str : Doomsday_Heist)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "南圣安地列斯超级赛";
		for (const char* str : Super_Sport_Series)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "夜总会";
		for (const char* str : After_Hours)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "竞技场之战DLC";
		for (const char* str : Arena_War)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "名钻赌场DLC";
		for (const char* str : Diamond_Casino)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "名钻赌场豪劫DLC";
		for (const char* str : Diamond_Casino_Heist)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "佩里克岛DLC";
		for (const char* str : haidao)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}

	{
		VehicleClass vehClass;
		vehClass.className = "事务所DLC";
		for (const char* str : Import_Export)
		{
			std::string tmp(str);
			buffer.push_back(tmp);
			std::sort(buffer.begin(), buffer.end());
		}
		for (std::string str : buffer)
		{
			VehiclePack pack;
			pack.name = str.c_str();
			pack.hash = rage::joaat(pack.name);
			pack.labelText = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(pack.hash));
			vehClass.vehicles.push_back(pack);
		}
		classes.push_back(vehClass);
		buffer.clear();
	}
}

using namespace big;
void Vehicles::refreshVehicle(VehicleData* vehData, Vehicle veh)
{
	if (ENTITY::DOES_ENTITY_EXIST(veh))
	{
		util::requestControlOfEnt(veh);

		vehData->handle = veh;
		vehData->model = ENTITY::GET_ENTITY_MODEL(veh);
		vehData->displayName = HUD::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(vehData->model));
		vehData->isBike = VEHICLE::IS_THIS_MODEL_A_BIKE(vehData->model);

		if (!writeData)
		{
			static bool timer_reset = true;
			static std::chrono::system_clock::time_point timer_Start;

			if (timer_reset)
			{
				timer_Start = std::chrono::system_clock::now();
				timer_reset = false;
			}

			std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - timer_Start;
			if (elapsed_seconds.count() >= 0.05)
			{
				if (VEHICLE::GET_VEHICLE_MOD_KIT(veh) != 0)
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);

				for (int i = 0; i < 49; i++)
				{
					if (i > 16 && i < 23)
						continue;

					if (i == 47)
						continue;

					vehData->mods[i].name = getModCategoryName(i);
					vehData->mods[i].category = i;
					vehData->mods[i].options = VEHICLE::GET_NUM_VEHICLE_MODS(veh, i);
					vehData->mods[i].index = VEHICLE::GET_VEHICLE_MOD(veh, i);
					vehData->mods[i].itemName = getNormalItemTitle(veh, i, vehData->mods[i].index);

					if (vehData->lastSelectedCategory == i)
					{
						static int lastCategory = -1;
						if ((lastCategory != vehData->lastSelectedCategory) || vehData->lastSelectedModNames.empty())
						{
							lastCategory = vehData->lastSelectedCategory;
							vehData->lastSelectedModNames.clear();
							int maxcount = (vehData->mods[i].options - 1);
							for (int j = -1; j <= maxcount; j++)
							{
								vehData->lastSelectedModNames.push_back(getNormalItemTitle(veh, i, j));
							}
							vehData->isRefreshed = true;
						}
					}
				}

				vehData->other.plateTextIndex = VEHICLE::GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh);
				vehData->other.plateText = VEHICLE::GET_VEHICLE_NUMBER_PLATE_TEXT(veh);
				vehData->other.wheeltype = VEHICLE::GET_VEHICLE_WHEEL_TYPE(veh);
				vehData->other.isCustomTyre = vehData->mods[23].index != 0; // vehData->other.wheeltype != -1;

				vehData->togglemods.turbo = VEHICLE::IS_TOGGLE_MOD_ON(veh, 18); // turbo
				vehData->togglemods.tyreSmoke = VEHICLE::IS_TOGGLE_MOD_ON(veh, 20); // tyre smoke
				vehData->togglemods.xenonHeadLights = VEHICLE::IS_TOGGLE_MOD_ON(veh, 22); // xenon lights
				for (int i = 0; i < 4; i++)
					vehData->togglemods.neonLights[i] = VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, i); // left // right // front // back

				VEHICLE::GET_VEHICLE_COLOURS(veh, &vehData->colours.primary, &vehData->colours.secondary);
				//VEHICLE::GET_VEHICLE_MOD_COLOR_1(veh, &vehData->colours.primaryPaintType, &vehData->colours.primary, &vehData->colours.pearlescent);
				//VEHICLE::GET_VEHICLE_MOD_COLOR_2(veh, &vehData->colours.secondaryPaintType, &vehData->colours.secondary);
				vehData->colours.isPrimaryCustom = VEHICLE::GET_IS_VEHICLE_PRIMARY_COLOUR_CUSTOM(veh);
				vehData->colours.isSecondaryCustom = VEHICLE::GET_IS_VEHICLE_SECONDARY_COLOUR_CUSTOM(veh);
				VEHICLE::GET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, &vehData->colours.customPrimary.R, &vehData->colours.customPrimary.G, &vehData->colours.customPrimary.B);
				VEHICLE::GET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, &vehData->colours.customSecondary.R, &vehData->colours.customSecondary.G, &vehData->colours.customSecondary.B);

				vehData->colours.headlights = VEHICLE::_GET_VEHICLE_XENON_LIGHTS_COLOR(veh);
				vehData->colours.windowTint = VEHICLE::GET_VEHICLE_WINDOW_TINT(veh);
				VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &vehData->colours.pearlescent, &vehData->colours.wheels);
				VEHICLE::GET_VEHICLE_TYRE_SMOKE_COLOR(veh, &vehData->colours.tyreSmoke.R, &vehData->colours.tyreSmoke.G, &vehData->colours.tyreSmoke.B);
				VEHICLE::_GET_VEHICLE_NEON_LIGHTS_COLOUR(veh, &vehData->colours.neonLights.R, &vehData->colours.neonLights.G, &vehData->colours.neonLights.B);

				bool found = false;
				for (tPaintTypes paint : ePaintTypes)
				{
					for (PaintColour col : paint.colors)
					{
						if (vehData->colours.isPrimaryCustom)
							vehData->colours.primaryName = "Custom";
						else if (vehData->colours.primary == col.mainValue)
							vehData->colours.primaryName = col.name;

						if (vehData->colours.isSecondaryCustom)
							vehData->colours.secondaryName = "Custom";
						else if (vehData->colours.secondary == col.mainValue)
							vehData->colours.secondaryName = col.name;

						if (paint.paintType == 2)
							if (vehData->colours.pearlescent == col.pearlAddition)
							{
								found = true;
								vehData->colours.pearlescentName = col.name;
							}
					}
				}

				if (!found)
				{
					vehData->colours.pearlescentName = std::to_string(vehData->colours.pearlescent);
				}

				for (PaintColour col : PAINTS_Headlights)
				{
					if (!vehData->togglemods.xenonHeadLights)
					{
						vehData->colours.headlightsName = "Not Enabled";
						break;
					}

					if (vehData->colours.headlights == col.mainValue)
					{
						vehData->colours.headlightsName = col.name;
						break;
					}
				}

				found = false;
				for (PaintColour col : PAINTS_WHEELS)
				{
					if (!vehData->other.isCustomTyre) //if (vehData->colours.headlights == 255)
					{
						found = true;
						vehData->colours.headlightsName = "Not Enabled";
						break;
					}

					if (vehData->colours.wheels == col.mainValue)
					{
						found = true;
						vehData->colours.wheelName = col.name;
						break;
					}
				}

				if (!found)
				{
					vehData->colours.wheelName = std::to_string(vehData->colours.wheels);
				}

				found = false;
				for (PaintColour col : PAINTS_WindowTints)
				{
					if (vehData->colours.windowTint == col.mainValue || vehData->colours.windowTint == col.pearlAddition)
					{
						found = true;
						vehData->colours.windowTintName = col.name;
						break;
					}
				}

				if (!found)
				{
					vehData->colours.windowTintName = std::to_string(vehData->colours.windowTint);
				}

				found = false;
				for (tWheelTypes type : eWheelTypes)
				{
					if (vehData->other.wheeltype == type.wheelType)
					{
						found = true;
						vehData->other.wheelTypeName = type.displayName;
						break;
					}
				}

				if (!found)
				{
					vehData->other.wheelTypeName = std::to_string(vehData->other.wheeltype);
				}

				found = false;
				int i = 0;
				for (std::string str : PLATE_NAMES)
				{
					if (vehData->other.plateTextIndex == i)
					{
						found = true;
						vehData->other.plateTextIndexName = str;
						break;
					}
					i++;
				}

				if (!found)
				{
					vehData->other.plateTextIndexName = std::to_string(vehData->other.plateTextIndex);
				}

				timer_reset = true;
			}
		}
		else
		{
			if (VEHICLE::GET_VEHICLE_MOD_KIT(veh) != 0)
				VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);

			for (int i = 0; i < 49; i++)
				VEHICLE::SET_VEHICLE_MOD(veh, i, vehData->mods[i].index, vehData->other.isCustomTyre);

			VEHICLE::TOGGLE_VEHICLE_MOD(veh, 18, vehData->togglemods.turbo); // turbo
			VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, vehData->togglemods.tyreSmoke); // tyre smoke
			VEHICLE::TOGGLE_VEHICLE_MOD(veh, 22, vehData->togglemods.xenonHeadLights); // xenon lights
			for (int i = 0; i < 4; i++)
				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, i, vehData->togglemods.neonLights[i]); // left // right // front // back

			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, vehData->other.plateTextIndex);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, vehData->other.plateText.c_str());
			VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, vehData->other.wheeltype);

			VEHICLE::SET_VEHICLE_MOD_COLOR_1(veh, 0, 0, 0);
			VEHICLE::SET_VEHICLE_MOD_COLOR_2(veh, 0, 0);
			VEHICLE::SET_VEHICLE_COLOURS(veh, vehData->colours.primary, vehData->colours.secondary);

			if (vehData->colours.isPrimaryCustom)
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, vehData->colours.customPrimary.R, vehData->colours.customPrimary.G, vehData->colours.customPrimary.B);
			else
				VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh);
			if (vehData->colours.isSecondaryCustom)
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, vehData->colours.customSecondary.R, vehData->colours.customSecondary.G, vehData->colours.customSecondary.B);
			else
				VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh);

			VEHICLE::_SET_VEHICLE_XENON_LIGHTS_COLOR(veh, vehData->colours.headlights);
			VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, vehData->colours.windowTint);
			VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, vehData->colours.pearlescent, vehData->colours.wheels);
			VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, vehData->colours.tyreSmoke.R, vehData->colours.tyreSmoke.G, vehData->colours.tyreSmoke.B);
			VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, vehData->colours.neonLights.R, vehData->colours.neonLights.G, vehData->colours.neonLights.B);

			writeData = false;
		}
	}
}