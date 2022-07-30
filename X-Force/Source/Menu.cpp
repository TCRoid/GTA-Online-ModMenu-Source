#pragma once
#include "stdafx.h"

#pragma region long_stuff
Vehicle veh;
Object latestObj;
uint64_t var0[10];

bool fromCol = false;
bool TestBool = false;
bool firsttime = true;
bool firsttime2 = true;
bool freezespawned = false;
int rockstarindex = 0;
int selectedPlayer;
//char* menuname = "";
char *S_effect = NULL;

int inipos = 0;

bool weapons_sorted = false;

int colorTick = 0;

int menyooX = 17;
int menyooY = 4;

std::vector<char*> gender = { "Male", "Female" };
int genderPos;

int timeH = 0;
int timeM = 0;
int timeS = 0;

char* statName;
int vectorPos;
int intValue;
float floatValue;
bool boolValue;
std::vector<char*> statDataTypes = { "int", "float", "bool" };
bool saveValue = true;

int Face_ = 0;
int Glasses_ = 0;
int Ears_ = 0;
int Torso_ = 0;
int Torso2_ = 0;
int Legs_ = 0;
int Hands_ = 0;
int Watches_ = 0;
int Special1_ = 0;
int Special2_ = 0;
int Special3_ = 0;
int Texture_ = 0;

int FaceTex_ = 0;
int GlassesTex_ = 0;
int EarsTex_ = 0;
int TorsoTex_ = 0;
int Torso2Tex_ = 0;
int LegsTex_ = 0;
int HandsTex_ = 0;
int WatchesTex_ = 0;
int Special1Tex_ = 0;
int Special2Tex_ = 0;
int Special3Tex_ = 0;

bool patch1 = false;
bool patch2 = false;
bool patch3 = false;
bool patch4 = false;
bool patch5 = false;
bool patch6 = false;
bool patch7 = false;
bool patch8 = false;
bool patch9 = false;
bool patch10 = false;
bool patch11 = false;
bool patch12 = false;
bool patch13 = false;
bool patch14 = false;
bool patch15 = false;
bool patch16 = false;
bool patch17 = false;
bool patch18 = false;
bool patch19 = false;
bool patch20 = false;
bool patch21 = false;
bool patch22 = false;
bool patch23 = false;
bool patch24 = false;
bool patch25 = false;
bool patch26 = false;
bool patch27 = false;
bool patch28 = false;
bool patch29 = false;
bool patch30 = false;
bool patch31 = false;
bool patch32 = false;
bool patch33 = false;
bool patch34 = false;
bool patch35 = false;
bool patch36 = false;
bool patch37 = false;
bool patch38 = false;
bool patch39 = false;
bool patch40 = false;
bool patch41 = false;
bool patch42 = false;
bool patch43 = false;
bool patch44 = false;
bool patch45 = false;
bool patch46 = false;
bool patch47 = false;
bool patch48 = false;
bool patch49 = false;
bool patch50 = false;
bool patch51 = false;
bool patch52 = false;
bool patch53 = false;
bool patch54 = false;
bool patch55 = false;
bool patch56 = false;
bool patch57 = false;
bool patch58 = false;
bool patch59 = false;
bool patch60 = false;
bool patch61 = false;
bool patch62 = false;
bool patch63 = false;
bool patch64 = false;
bool patch65 = false;
bool patch66 = false;
bool patch67 = false;
bool patch68 = false;
bool patch69 = false;
bool patch70 = false;
bool patch71 = false;
bool patch72 = false;
bool patch73 = false;
bool patch74 = false;
bool patch75 = false;
bool patch76 = false;
bool patch77 = false;
bool patch78 = false;
bool patch79 = false;
bool patch80 = false;
bool patch81 = false;
bool patch82 = false;
bool patch83 = false;
bool patch84 = false;
bool patch85 = false;
bool patch86 = false;
bool patch87 = false;
bool patch88 = false;
bool patch89 = false;
bool patch90 = false;

int r_amount = 1000000;


void notifyleft(char* msg)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(msg);
	UI::_DRAW_NOTIFICATION(2000, 1);
}

Vector3 TPCoords;
void TPto(Vector3 Coords)
{
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
	{
		ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(Handle, false), Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
	}
	else
		ENTITY::SET_ENTITY_COORDS(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
}

static char* Boats1[] = {
	"DINGHY", "DINGHY2", "DINGHY3", "DINGHY4", "JETMAX",
	"MARQUIS", "PREDATOR", "SEASHARK", "SEASHARK2", "SEASHARK3",
	"SPEEDER", "SPEEDER2", "SQUALO", "SUBMERSIBLE", "SUBMERSIBLE2",
	"SUNTRAP", "TORO", "TORO2", "TROPIC", "TROPIC2",
	"TUG"
};
static char* Commercial1[] = {
	"BENSON", "BIFF", "HAULER", "MULE", "MULE2",
	"MULE3", "PACKER", "PHANTOM", "POUNDER", "STOCKADE",
	"STOCKADE3", "cerberus", "cerberus2", "cerberus3"
};
static char* Compacts1[] = {
	"BLISTA", "BRIOSO", "DILETTANTE", "DILETTANTE2", "ISSI2",
	"PANTO", "PRAIRIE", "RHAPSODY", "issi3", "issi4", "issi5", 
	"issi6"
};
static char* Coupes1[] = {
	"COGCABRIO", "EXEMPLAR", "F620", "FELON", "FELON2",
	"JACKAL", "ORACLE", "ORACLE2", "SENTINEL", "SENTINEL2",
	"WINDSOR", "WINDSOR2", "ZION", "ZION2", "sentinel3"
};
static char* Cycles1[] = {
	"BMX", "CRUISER", "FIXTER", "SCORCHER", "TRIBIKE",
	"TRIBIKE2", "TRIBIKE3"
};
static char* Emergency1[] = {
	"AMBULANCE", "FBI", "FBI2", "FIRETRUK", "LGUARD",
	"PBUS", "PRANGER", "POLICE", "POLICE2", "POLICE3",
	"POLICE4", "POLICEB", "POLICEOLD1", "POLICEOLD2", "POLICET",
	"SHERIFF", "SHERIFF2", "RIOT", "riot2"
};
static char* Helicopters1[] = {
	"ANNIHILATOR", "BLIMP", "BLIMP2", "BUZZARD", "BUZZARD2",
	"CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER",
	"FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT",
	"SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE",
	"VALKYRIE2", "VOLATUS", "HUNTER", "havok", "blimp3", "seasparrow"
};
static char* Industrial1[] = {
	"BULLDOZER", "CUTTER", "DUMP", "FLATBED", "GUARDIAN",
	"HANDLER", "MIXER", "MIXER2", "RUBBLE", "TIPTRUCK",
	"TIPTRUCK2"
};
static char* Military1[] = {
	"BARRACKS", "BARRACKS2", "BARRACKS3", "CRUSADER", "RHINO", 
	"APC", "DUNE3", "HALFTRACK", "chernobog", "khanjali",
	"scarab", "scarab2", "scarab3", "thruster"
};
static char* Motorcycles1[] = {
	"AKUMA", "AVARUS", "BAGGER", "BATI", "BATI2",
	"BF400", "CARBONRS", "CHIMERA", "CLIFFHANGER", "DAEMON",
	"DAEMON2", "DEFILER", "DOUBLE", "ENDURO", "ESSKEY",
	"FAGGIO", "FAGGIO2", "FAGGIO3", "GARGOYLE", "HAKUCHOU",
	"HAKUCHOU2", "HEXER", "INNOVATION", "LECTRO", "MANCHEZ",
	"NEMESIS", "NIGHTBLADE", "PCJ", "RATBIKE", "RUFFIAN",
	"SANCHEZ", "SANCHEZ2", "SANCTUS", "SHOTARO", "SOVEREIGN",
	"THRUST", "VADER", "VINDICATOR", "VORTEX", "WOLFSBANE",
	"ZOMBIEA", "ZOMBIEB", "DIABLOUS", "DIABLOUS2", "FCR",
	"FCR2", "OPPRESSOR", "oppressor2", "deathbike", "deathbike2",
	"deathbike3"
};
static char* Muscle1[] = {
	"BLADE", "BUCCANEER", "BUCCANEER2", "CHINO", "CHINO2",
	"COQUETTE3", "DOMINATOR", "DOMINATOR2", "DUKES", "DUKES2",
	"GAUNTLET", "GAUNTLET2", "FACTION", "FACTION2", "FACTION3",
	"HOTKNIFE", "LURCHER", "MOONBEAM", "MOONBEAM2", "NIGHTSHADE",
	"PHOENIX", "PICADOR", "RATLOADER", "RATLOADER2", "RUINER", "RUINER2", "RUINER3",
	"SABREGT", "SABREGT2", "SLAMVAN", "SLAMVAN2", "SLAMVAN3",
	"STALION", "STALION2", "TAMPA", "VIGERO", "VIRGO",
	"VIRGO2", "VIRGO3", "VOODOO", "VOODOO2", "TAMPA3", "hermes", "dominator3",
	"dominator4", "dominator5", "dominator6", "slamvan4", "slamvan5", "slamvan6",
	"ellie", "impaler", "impaler2", "impaler3", "clique", "deviant", "tulip", "vamos",
	"hustler", "yosemite"
};
static char* OffRoad1[] = {
	"BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3",
	"BLAZER4", "BODHI2", "BRAWLER", "DLOADER", "DUBSTA3",
	"DUNE", "DUNE2", "INSURGENT", "INSURGENT2", "KALAHARI",
	"MARSHALL", "MESA3", "MONSTER", "RANCHERXL", "RANCHERXL2",
	"REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL",
	"TROPHYTRUCK", "TROPHYTRUCK2", "TECHNICAL2", "DUNE4", "DUNE5",
	"BLAZER5", "TECHNICAL3", "INSURGENT3", "NIGHTSHARK", "freecrawler",
	"menacer", "patriot2", "barrage", "monster3",
	"monster4", "monster5", "bruiser", "bruiser2", "bruiser3",
	"brutus", "brutus2", "brutus3", "kamacho", "riata"
};
static char* Planes1[] = {
	"BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
	"HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
	"MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
	"TITAN", "VELUM", "VELUM2", "VESTRA", "BOMBUSHKA",
	"MOLOTOK", "NOKOTA", "PYRO", "ROGUE", "SEABREEZE",
	"HOWARD", "MICROLIGHT", "TULA", "MOGUL", "STARLING",
	"ALPHAZ1", "strikeforce", "avenger", "volatol"
};
static char* Sedans1[] = {
	"ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552",
	"COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3",
	"FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2",
	"PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO",
	"SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM",
	"STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARR", "stafford",
	"cheburek"
};
static char* Sports1[] = {
	"ALPHA", "BANSHEE", "BESTIAGTS", "BLISTA2", "BLISTA3",
	"BUFFALO", "BUFFALO2", "BUFFALO3", "CARBONIZZARE", "COMET2",
	"COQUETTE", "ELEGY", "ELEGY2", "FELTZER2", "FUROREGT", "FUSILADE",
	"FUTO", "JESTER", "JESTER2", "KHAMELION", "KURUMA",
	"KURUMA2", "LYNX", "MASSACRO", "MASSACRO2", "NINEF",
	"NINEF2", "OMNIS", "PENUMBRA", "RAPIDGT", "RAPIDGT2",
	"RAPTOR", "SCHAFTER3", "SCHAFTER4", "SCHWARTZER", "SEVEN70",
	"SULTAN", "SURANO", "SPECTER", "SPECTER2", "TAMPA2", "TROPOS", "VERLIERER2",
	"RUINER2", "PHANTOM2", "RUSTON", "comet4", "comet5", "jester3", "gb200", 
	"hotring", "zr380", "zr3802", "zr3803", "schlagen", "italigto", "neon", 
	"pariah", "raiden", "revolter"
};
static char* SportsClassics1[] = {
	"BTYPE", "BTYPE2", "BTYPE3", "CASCO", "COQUETTE2",
	"FELTZER3", "JB700", "MAMBA", "MANANA", "MONROE",
	"PEYOTE", "PIGALLE", "STINGER", "STINGERGT", "TORNADO",
	"TORNADO2", "TORNADO3", "TORNADO4", "TORNADO5", "TORNADO6",
	"ZTYPE", "INFERNUS2", "TURISMO2", "rapidgt3", "retinue",
	"swinger", "ARDENT", "TORERO", "fagaloa", "flashgt",
	"michelli", "deluxo", "stromberg", "savestra", "viseris",
	"gt500", "z190"
};
static char* Super1[] = {
	"ADDER", "BANSHEE2", "BULLET", "CHEETAH", "ENTITYXF",
	"FMJ", "SHEAVA", "INFERNUS", "NERO", "NERO2","OSIRIS", "LE7B",
	"ITALIGTB", "ITALIGTB2", "PFISTER811", "PROTOTIPO", "REAPER", "SULTANRS", "T20",
	"TEMPESTA", "TURISMOR", "TYRUS", "VACCA", "VOLTIC", "ZENTORNO", "VOLTIC2", "PENETRATOR", "GP1",
	"vigilante", "visione", "cyclone", "scramjet", "CHEETAH2", "VAGNER", "XA21", "autarch", "entity2",
	"taipan", "tezeract", "tyrant", "deveste", "sc1"
};
static char* SUVs1[] = {
	"BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5",
	"BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER",
	"DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY",
	"HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2",
	"PATRIOT", "RADI", "ROCOTO", "SEMINOLE", "SERRANO",
	"XLS", "XLS2", "streiter", "toros"
};
static char* Trailer1[] = {
	"ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER",
	"DOCKTRAILER", "FREIGHTTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER",
	"TANKER", "TANKER2", "TR2", "TR3", "TR4",
	"TRAILERLOGS", "TRAILERS", "TRAILERS2", "TRAILERS3", "TRAILERSMALL",
	"TRFLAT", "TVTRAILER", "TRAILERLARGE", "TRAILERS4", "TRAILERSMALL2"
};
static char* Trains1[] = {
	"CABLECAR", "FREIGHT", "FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2",
	"FREIGHTGRAIN", "METROTRAIN", "TANKERCAR"
};
static char* Utility1[] = {
	"AIRTUG", "CADDY", "CADDY2", "DOCKTUG", "FORKLIFT",
	"MOWER", "RIPLEY", "SADLER", "SADLER2", "SCRAP",
	"TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3",
	"UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3", "CADDY3",
	"rcbandito"
};
static char* Vans1[] = {
	"BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE",
	"BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BURRITO", "BURRITO2",
	"BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO",
	"GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2", "PARADISE",
	"PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3",
	"SPEEDO", "SPEEDO2", "SURFER", "SURFER2", "TACO",
	"YOUGA", "YOUGA2"
};
static char* Service1[] = {
	"AIRBUS", "BRICKADE", "BUS", "COACH", "RALLYTRUCK",
	"RENTALBUS", "TAXI", "TOURBUS", "TRASH", "TRASH2",
	"WASTELANDER", "pbus2"
};
static char* trucks1[] = {
	"boxville","stockade","stockade2","tiptruck","tiptruck2",
	"cutter","handler","docktug","dump","biff","hauler","phantom",
	"rubble","mule","mixer","mixer2","flatbed","packer","pounder",
	"benson","scrap","phantom2","hauler2","phantom3","pounder2", 
	"speedo4","mule4","terbyte","caracara"
};




static char* beachbum[] = {
	"BIFTA", "KALAHARI", "PARADISE"
};

static char* valetinesmassacre[] = {
	"BTYPE"
};

static char* business[] = {
	"ALPHA", "JESTER", "TURISMOR", "VESTRA"
};

static char* highlife[] = {
	"THRUST", "ZENTORNO", "MASSACRO", "HUNTLEY"
};

static char* notahipster[] = {
	"PIGALLE", "BLADE", "RHAPSODY", "WARR",
	"GLENDALE", "PANTO", "DUBSTA3"
};

static char* independence[] = {
	"SOVEREIGN", "MONSTER"
};

static char* saflightschool[] = {
	"BESRA", "MILJET", "SWIFT", "COQUETTE2"
};

static char* lastteamstanding[] = {
	"HAKUCHOU", "INNOVATION", "FUROREGT"
};

static char* festive2014[] = {
	"SLAMVAN", "RATLOADER", "MASSACRO2",
	"JESTER2"
};

static char* heist[] = {
	"ENDURO", "GUARDIAN", "KURUMA", "KURUMA2",
	"CASCO", "VELUM2", "HYDRA", "INSURGENT",
	"INSURGENT2", "VALKYRIE", "MULE2", "TECHNICAL2",
	"BOXVILLE", "BOXVILLE2", "BOXVILLE3", "GBURRITO",
	"GBURRITO2", "SAVAGE", "LECTRO", "TRASH2",
	"TANKERCAR", "BARRACKS2"
};

static char* illgg[] = {
	"OSIRIS", "VIRGO", "WINDSOR", "STINGERGT",
	"LUXOR2", "SWIFT2", "BRAWLER", "CHINO",
	"COQUETTE3", "T20", "TORO", "TORO2",
	"VINDICATOR"
};

static char* lowriders[] = {
	"BUCCANEER2", "CHINO2", "FACTION", "FACTION2",
	"MOONBEAM", "MOONBEAM2", "PRIMO2", "VOODOO2"
};

static char* halloween[] = {
	"BTYPE2", "LURCHER"
};

static char* executives[] = {
	"SUPERVOLITO", "SUPERVOLITO2", "LIMO2",
	"SCHAFTER3", "SCHAFTER4", "SCHAFTER5",
	"SCHAFTER6", "NIGHTSHADE", "MAMBA",
	"VERLIERER2", "COGNOSCENTI", "COGNOSCENTI2",
	"COG55", "COG552", "BALLER3", "BALLER4", "BALLER5",
	"BALLER6", "DINGHY2", "DINGHY3", "DINGHY4",
	"SEASHARK2", "SEASHARK3", "SPEEDER2", "TROPIC2",
	"TORO2"
};

static char* festive2015[] = {
	"TAMPA"
};

static char* dropzone[] = {
	"BANSHEE2", "SULTANRS"
};

static char* bemyvalentine[] = {
	"BTYPE3"
};

static char* customclassics[] = {
	"VIRGO2", "VIRGO3", "SLAMVAN2", "FACTION3",
	"TORNADO2", "MINIVAN2", "SABREGT2"
};

static char* financefelony[] = {
	"XLS", "XLS2", "RUMPO2", "NIMBUS", "TUG",
	"VOLATUS", "WINDSOR2", "BESTIAGTS",
	"BRICKADE", "REAPER", "FMJ"
};

static char* CUNNINGSTUNTS1[] = {
	"BF400", "BRIOSO", "CLIFFHANGER", "CONTENDER", "GARGOYLE", "LE7B", "LYNX",
	"OMNIS", "RALLYTRUCK", "SHEAVA", "TAMPA2", "TROPHYTRUCK", "TROPHYTRUCK2",
	"TROPOS", "TYRUS"
};

static char* bikers[] = {
	"AVARUS", "MANCHEZ", "CHIMERA", "BLAZER2", "FAGGIO2", "FAGGIO3",
	"DEFILER", "HAKUCHOU2", "NIGHTBLADE", "RATBIKE", "WOLFSBANE",
	"ZOMBIEB", "VORTEX", "SANCTUS", "TORNADO3", "SHOTARO", "ESSKEY",
	"YOUGA2"
};

static char* IMPORTEXPORT1[] = {
	"BLAZER5", "BOXVILLE5", "COMET3", "DIABLOUS", "DIABLOUS2", "DUNE4", "DUNE5",
	"ELEGY", "FCR", "FCR2", "ITALIGTB", "ITALIGTB2", "NERO", "NERO2", "PENETRATOR",
	"PHANTOM2", "RUINER2", "SPECTER", "SPECTER2", "TECHNICAL2", "TEMPESTA", "VOLTIC2",
	"WASTELANDER"
};

static char* specialvcircuit[] = {
	"GP1", "RUSTON", "INFERNUS2", "TURISMO2"
};

static char* GUNRUNNING1[] = {
	"APC", "ARDENT", "CADDY3", "CHEETAH2", "DUNE3", "HALFTRACK", "HAULER2",
	"INSUGENT3", "NIGHTSHARK", "OPPRESSOR", "PHANTOM3", "TAMPA3", "TECHNICAL3",
	"TORERO", "TRAILERLARGE", "TRAILERS4", "TRAILERSMALL2", "VAGNER", "XA21"
};

static char* SMUGLERSRUN1[] = {
	"havok", "rapidgt3", "retinue", "vigilante", "visione", "cyclone", "ALPHAZ1",
	"BOMBUSHKA", "HOWARD", "HUNTER", "MICROLIGHT", "MOGUL", "MOLOTOK", "NOKOTA", "PYRO",
	"ROGUE", "SEABREEZE", "STARLING", "TULA"
};

static char* Doomsday1[] = {
	"autarch", "avenger", "barrage", "chernobog", "comet4", "comet5",
	"deluxo", "gt500", "hermes", "hustler", "kamacho","khanjali",
	"neon", "pariah", "raiden", "revolter", "riata", "riot2", "savestra",
	"sc1", "sentinel3", "streiter", "stromberg", "thruster", "viseris",
	"volatol", "yosemite", "z190"
};

static char* SOUTHERNSAN[] = {
	"caracara", "cheburek", "dominator3", "ellie", "entity2", "fagaloa", "flashgt",
	"gb200", "hotring", "issi3", "jester3", "michelli", "seasparrow", "taipan", "tezeract",
	"tyrant"
};

static char* afterhrs[] = {
	"stafford", "scramjet", "strikeforce", "terbyte",
	"pbus2", "oppressor2", "pounder2", "speedo4",
	"freecrawler", "mule4", "menacer", "blimp3",
	"swinger", "patriot2"
};

static char* arenawar[] = {
	"bruiser", "bruiser2", "bruiser3", "brutus", "brutus2",
	"brutus3", "cerberus", "cerberus2", "cerberus3", "clique",
	"deathbike", "deathbike2", "deathbike3", "deveste", "deviant",
	"dominator4", "dominator5", "dominator6", "impaler", "impaler2",
	"impaler3", "issi4", "issi5", "issi6", "italigto", "monster3",
	"monster4", "monster5", "rcbandito", "scarab", "scarab2", "scarab3",
	"schlagen", "slamvan4", "slamvan5", "slamvan6", "toros", "tulip",
	"vamos", "zr380", "zr3802", "zr3803"
};

static char* dlcnames[] = {
	"Beach bum", "Valentines massacre", "Business", "High life", "Hipster",
	"Independence day", "Flight school", "Last team standing", "Festive 2014",
	"Heists", "Ill-gotton-gains", "Lowrider", "Halloween 2015", "Executives",
	"Festive 2015", "Drop zone", "Be my valentine", "Custom classics", "Finance and felony",
	"Cunning stunts", "Bikers", "Import export", "Special vehicle circuit", "Gunrunning", 
	"Smugglers run", "Doomsday", "Southern san andreas", "Afterhours", "Arena war"
};

static char* dlcnames2[] = {
	"Beach bum ~r~[1.06]", "Valentines massacre ~r~[1.10]", "Business ~r~[1.11]", 
	"High life ~r~[1.13]", "Hipster ~r~[1.14]", "Independence day ~r~[1.15]", 
	"Flight school ~r~[1.16]", "Last team standing ~r~[1.17]", "Festive 2014 ~r~[1.19]",
	"Heists ~r~[1.21]", "Ill-gotton-gains ~r~[1.27]", "Lowrider ~r~[1.30]", 
	"Halloween 2015 ~r~[1.30]", "Executives ~r~[1.31]", "Festive 2015 ~r~[1.32]", 
	"Drop zone ~r~[1.32]", "Be my valentine ~r~[1.32]", "Custom classics ~r~[1.33]", 
	"Finance and felony ~r~[1.34]", "Cunning stunts ~r~[1.35]", "Bikers ~r~[1.36]", 
	"Import export ~r~[1.37]", "Special vehicle circuit ~r~[1.38]", "Gunrunning  ~r~[1.40]",
	"Smugglers run  ~r~[1.41]", "Doomsday ~r~[1.42]", "Southern san andreas ~r~[1.43]", 
	"Afterhours ~r~[1.44]", "Arena war ~r~[1.46]"
};



int walk_style_choose = 0;
std::vector<char*> walkNames{
	"Generic Male",
	"Generic Female",
	"Cop",
	"Gangster",
	"Hipster",
	"Hobo",
	"Obese",
	"Lester",
	"Drunk",
	"Moderate Drunk",
	"Very Drunk",
	"Sexy",
	"Alien",
	"Buisness",
	"Casual",
	"Clipboard",
	"Coward",
	"Burning",
	"Flee",
	"Hiking",
	"Hurry",
	"Injured",
	"Intimidation",
	"Muscular",
	"Quick",
	"Sad",
	"Shady",
	"Shocked",
	"Arrogant",
	"Handbag Walk",
	"Heels",
	"Thug",
};
std::vector<char*> walkDicts{
	"move_m@generic",
	"move_f@generic",
	"move_cop@action",
	"move_m@gangster@generic",
	"move_m@hipster@a",
	"move_m@hobo@a",
	"move_m@fat@a",
	"move_lester_CaneUp",
	"move_m@drunk@a",
	"move_m@drunk@moderatedrunk",
	"move_m@drunk@verydrunk",
	"move_f@sexy@a",
	"move_m@alien",
	"move_m@business@a",
	"move_m@casual@a",
	"move_m@clipboard",
	"move_m@coward",
	"move_m@fire",
	"move_m@flee@a",
	"move_m@hiking",
	"move_m@hurry@a",
	"move_injured_generic",
	"move_m@intimidation@1h",
	"move_m@muscle@a",
	"move_m@quick",
	"move_m@sad@a",
	"move_m@shadyped@a",
	"move_m@shocked@a",
	"move_f@arrogant@a",
	"move_f@handbag",
	"move_f@heels@c",
	"move_p_m_one",
};



static char* pedModels[] = {
	"A_C_Boar","A_C_Chickenhawk","A_C_Chimp","A_C_Chop","A_C_Cormorant","A_C_Cow","A_C_Coyote","A_C_Crow","A_C_Deer","A_C_Fish","A_C_Hen","A_C_Husky","A_C_MtLion","A_C_Pig","A_C_Pigeon","A_C_Rat","A_C_Retriever",
	"A_C_Rhesus","A_C_Rottweiler","A_C_Seagull","A_C_SharkTiger","A_C_shepherd","A_F_M_Beach_01","A_F_M_BevHills_01","A_F_M_BevHills_02","A_F_M_BodyBuild_01","A_F_M_Business_02","A_F_M_Downtown_01","A_F_M_EastSA_01",
	"A_F_M_EastSA_02","A_F_M_FatBla_01","A_F_M_FatCult_01","A_F_M_FatWhite_01","A_F_M_KTown_01","A_F_M_KTown_02","A_F_M_ProlHost_01","A_F_M_Salton_01","A_F_M_SkidRow_01","A_F_M_SouCentMC_01","A_F_M_SouCent_01","A_F_M_SouCent_02",
	"A_F_M_Tourist_01","A_F_M_TrampBeac_01","A_F_M_Tramp_01","A_F_O_GenStreet_01","A_F_O_Indian_01","A_F_O_KTown_01","A_F_O_Salton_01","A_F_O_SouCent_01","A_F_O_SouCent_02","A_F_Y_Beach_01","A_F_Y_BevHills_01","A_F_Y_BevHills_02",
	"A_F_Y_BevHills_03","A_F_Y_BevHills_04","A_F_Y_Business_01","A_F_Y_Business_02","A_F_Y_Business_03","A_F_Y_Business_04","A_F_Y_EastSA_01","A_F_Y_EastSA_02","A_F_Y_EastSA_03","A_F_Y_Epsilon_01","A_F_Y_Fitness_01",
	"A_F_Y_Fitness_02","A_F_Y_GenHot_01","A_F_Y_Golfer_01","A_F_Y_Hiker_01","A_F_Y_Hippie_01","A_F_Y_Hipster_01","A_F_Y_Hipster_02","A_F_Y_Hipster_03","A_F_Y_Hipster_04","A_F_Y_Indian_01","A_F_Y_Juggalo_01","A_F_Y_Runner_01",
	"A_F_Y_RurMeth_01","A_F_Y_SCDressy_01","A_F_Y_Skater_01","A_F_Y_SouCent_01","A_F_Y_SouCent_02","A_F_Y_SouCent_03","A_F_Y_Tennis_01","A_F_Y_Topless_01","A_F_Y_Tourist_01","A_F_Y_Tourist_02","A_F_Y_Vinewood_01",
	"A_F_Y_Vinewood_02","A_F_Y_Vinewood_03","A_F_Y_Vinewood_04","A_F_Y_Yoga_01","A_M_M_ACult_01","A_M_M_AfriAmer_01","A_M_M_Beach_01","A_M_M_Beach_02","A_M_M_BevHills_01","A_M_M_BevHills_02","A_M_M_Business_01",
	"A_M_M_EastSA_01","A_M_M_EastSA_02","A_M_M_Farmer_01","A_M_M_FatLatin_01","A_M_M_GenFat_01","A_M_M_GenFat_02","A_M_M_Golfer_01","A_M_M_HasJew_01","A_M_M_Hillbilly_01","A_M_M_Hillbilly_02","A_M_M_Indian_01",
	"A_M_M_KTown_01","A_M_M_Malibu_01","A_M_M_MexCntry_01","A_M_M_MexLabor_01","A_M_M_OG_Boss_01","A_M_M_Paparazzi_01","A_M_M_Polynesian_01","A_M_M_ProlHost_01","A_M_M_RurMeth_01","A_M_M_Salton_01","A_M_M_Salton_02",
	"A_M_M_Salton_03","A_M_M_Salton_04","A_M_M_Skater_01","A_M_M_Skidrow_01","A_M_M_SoCenLat_01","A_M_M_SouCent_01","A_M_M_SouCent_02","A_M_M_SouCent_03","A_M_M_SouCent_04","A_M_M_StLat_02","A_M_M_Tennis_01",
	"A_M_M_Tourist_01","A_M_M_TrampBeac_01","A_M_M_Tramp_01","A_M_M_TranVest_01","A_M_M_TranVest_02","A_M_O_ACult_01","A_M_O_ACult_02","A_M_O_Beach_01","A_M_O_GenStreet_01","A_M_O_KTown_01","A_M_O_Salton_01",
	"A_M_O_SouCent_01","A_M_O_SouCent_02","A_M_O_SouCent_03","A_M_O_Tramp_01","A_M_Y_ACult_01","A_M_Y_ACult_02","A_M_Y_BeachVesp_01","A_M_Y_BeachVesp_02","A_M_Y_Beach_01","A_M_Y_Beach_02","A_M_Y_Beach_03","A_M_Y_BevHills_01",
	"A_M_Y_BevHills_02","A_M_Y_BreakDance_01","A_M_Y_BusiCas_01","A_M_Y_Business_01","A_M_Y_Business_02","A_M_Y_Business_03","A_M_Y_Cyclist_01","A_M_Y_DHill_01","A_M_Y_Downtown_01","A_M_Y_EastSA_01","A_M_Y_EastSA_02",
	"A_M_Y_Epsilon_01","A_M_Y_Epsilon_02","A_M_Y_Gay_01","A_M_Y_Gay_02","A_M_Y_GenStreet_01","A_M_Y_GenStreet_02","A_M_Y_Golfer_01","A_M_Y_HasJew_01","A_M_Y_Hiker_01","A_M_Y_Hippy_01","A_M_Y_Hipster_01","A_M_Y_Hipster_02",
	"A_M_Y_Hipster_03","A_M_Y_Indian_01","A_M_Y_Jetski_01","A_M_Y_Juggalo_01","A_M_Y_KTown_01","A_M_Y_KTown_02","A_M_Y_Latino_01","A_M_Y_MethHead_01","A_M_Y_MexThug_01","A_M_Y_MotoX_01","A_M_Y_MotoX_02","A_M_Y_MusclBeac_01",
	"A_M_Y_MusclBeac_02","A_M_Y_Polynesian_01","A_M_Y_RoadCyc_01","A_M_Y_Runner_01","A_M_Y_Runner_02","A_M_Y_Salton_01","A_M_Y_Skater_01","A_M_Y_Skater_02","A_M_Y_SouCent_01","A_M_Y_SouCent_02","A_M_Y_SouCent_03","A_M_Y_SouCent_04",
	"A_M_Y_StBla_01","A_M_Y_StBla_02","A_M_Y_StLat_01","A_M_Y_StWhi_01","A_M_Y_StWhi_02","A_M_Y_Sunbathe_01","A_M_Y_Surfer_01","A_M_Y_VinDouche_01","A_M_Y_Vinewood_01","A_M_Y_Vinewood_02","A_M_Y_Vinewood_03","A_M_Y_Vinewood_04",
	"A_M_Y_Yoga_01","CSB_Abigail","CSB_Anita","CSB_Anton","CSB_BallasOG","CSB_Bride","CSB_BurgerDrug","CSB_Car3guy1","CSB_Car3guy2","CSB_Chef","CSB_Chin_goon","CSB_Cletus","CSB_Cop","CSB_Customer","CSB_Denise_friend",
	"CSB_FOS_rep","CSB_G","CSB_Groom","CSB_Grove_str_dlr","CSB_Hao","CSB_Hugh","CSB_Imran","CSB_Janitor","CSB_Maude","CSB_MWeather","CSB_Ortega","CSB_Oscar","CSB_PornDudes","CSB_PrologueDriver","CSB_ProlSec","CSB_Ramp_gang",
	"CSB_Ramp_hic","CSB_Ramp_hipster","CSB_Ramp_marine","CSB_Ramp_mex","CSB_Reporter","CSB_RoccoPelosi","CSB_Screen_Writer","CSB_Stripper_01","CSB_Stripper_02","CSB_Tonya","CSB_TrafficWarden","CS_AmandaTownley","CS_Andreas",
	"cs_ashley","CS_Bankman","CS_Barry","CS_Beverly","CS_Brad","CS_BradCadaver","CS_Carbuyer","CS_Casey","CS_ChengSr","CS_ChrisFormage","CS_Clay","CS_Dale","CS_DaveNorton","cs_debra","cs_denise","CS_Devin","CS_Dom","CS_Dreyfuss",
	"CS_DrFriedlander","CS_Fabien","CS_FBISuit_01","CS_Floyd","CS_Guadalope","cs_gurk","CS_Hunter","CS_Janet","CS_JewelAss","CS_JimmyBoston","CS_JimmyDiSanto","CS_JoeMinuteMan","CS_JohnnyKlebitz","CS_Josef","CS_Josh","CS_LamarDavis",
	"CS_Lazlow","CS_LesterCrest","CS_LifeInvad_01","CS_Magenta","CS_Manuel","CS_Marnie","CS_MartinMadrazo","CS_MaryAnn","CS_Michelle","CS_Milton","CS_Molly","CS_MovPremF_01","CS_MovPremMale","CS_MRK","CS_MrsPhillips","CS_MRS_Thornhill",
	"CS_Natalia","CS_NervousRon","CS_Nigel","CS_Old_Man1A","CS_Old_Man2","CS_Omega","CS_Orleans","CS_Paper","CS_Patricia","CS_Priest","CS_ProlSec_02","CS_RussianDrunk","CS_SiemonYetarian","CS_Solomon","CS_SteveHains","CS_Stretch",
	"CS_Tanisha","CS_TaoCheng","CS_TaosTranslator","CS_TennisCoach","CS_Terry","CS_Tom","CS_TomEpsilon","CS_TracyDiSanto","CS_Wade","CS_Zimbor","G_F_Y_ballas_01","G_F_Y_Families_01","G_F_Y_Lost_01","G_F_Y_Vagos_01","G_M_M_ArmBoss_01",
	"G_M_M_ArmGoon_01","G_M_M_ArmLieut_01","G_M_M_ChemWork_01","G_M_M_ChiBoss_01","G_M_M_ChiCold_01","G_M_M_ChiGoon_01","G_M_M_ChiGoon_02","G_M_M_KorBoss_01","G_M_M_MexBoss_01","G_M_M_MexBoss_02","G_M_Y_ArmGoon_02","G_M_Y_Azteca_01",
	"G_M_Y_BallaEast_01","G_M_Y_BallaOrig_01","G_M_Y_BallaSout_01","G_M_Y_FamCA_01","G_M_Y_FamDNF_01","G_M_Y_FamFor_01","G_M_Y_Korean_01","G_M_Y_Korean_02","G_M_Y_KorLieut_01","G_M_Y_Lost_01","G_M_Y_Lost_02","G_M_Y_Lost_03",
	"G_M_Y_MexGang_01","G_M_Y_MexGoon_01","G_M_Y_MexGoon_02","G_M_Y_MexGoon_03","G_M_Y_PoloGoon_01","G_M_Y_PoloGoon_02","G_M_Y_SalvaBoss_01","G_M_Y_SalvaGoon_01","G_M_Y_SalvaGoon_02","G_M_Y_SalvaGoon_03","G_M_Y_StrPunk_01","G_M_Y_StrPunk_02",
	"HC_Driver","HC_Gunman","HC_Hacker","IG_Abigail","IG_AmandaTownley","IG_Andreas","IG_Ashley","IG_BallasOG","IG_Bankman","IG_Barry","IG_BestMen","IG_Beverly","IG_Brad","IG_Bride","IG_Car3guy1","IG_Car3guy2","IG_Casey",
	"IG_Chef","IG_ChengSr","IG_ChrisFormage","IG_Clay","IG_ClayPain","IG_Cletus","IG_Dale","IG_DaveNorton","IG_Denise","IG_Devin","IG_Dom","IG_Dreyfuss","IG_DrFriedlander","IG_Fabien","IG_FBISuit_01","IG_Floyd","IG_Groom",
	"IG_Hao","IG_Hunter","IG_Janet","ig_JAY_Norris","IG_JewelAss","IG_JimmyBoston","IG_JimmyDiSanto","IG_JoeMinuteMan","ig_JohnnyKlebitz","IG_Josef","IG_Josh","IG_KerryMcIntosh","IG_LamarDavis","IG_Lazlow","IG_LesterCrest",
	"IG_LifeInvad_01","IG_LifeInvad_02","IG_Magenta","IG_Manuel","IG_Marnie","IG_MaryAnn","IG_Maude","IG_Michelle","IG_Milton","IG_Molly","IG_MRK","IG_MrsPhillips","IG_MRS_Thornhill","IG_Natalia","IG_NervousRon","IG_Nigel",
	"IG_Old_Man1A","IG_Old_Man2","IG_Omega","IG_ONeil","IG_Orleans","IG_Ortega","IG_Paper","IG_Patricia","IG_Priest","IG_ProlSec_02","IG_Ramp_Gang","IG_Ramp_Hic","IG_Ramp_Hipster","IG_Ramp_Mex","IG_RoccoPelosi","IG_RussianDrunk",
	"IG_Screen_Writer","IG_SiemonYetarian","IG_Solomon","IG_SteveHains","IG_Stretch","IG_Talina","IG_Tanisha","IG_TaoCheng","IG_TaosTranslator","ig_TennisCoach","IG_Terry","IG_TomEpsilon","IG_Tonya","IG_TracyDiSanto","IG_TrafficWarden",
	"IG_TylerDix","IG_Wade","IG_Zimbor","MP_F_DeadHooker","MP_F_Freemode_01","MP_F_Misty_01","MP_F_StripperLite","MP_G_M_Pros_01","MP_HeadTargets","MP_M_Claude_01","MP_M_ExArmy_01","MP_M_FamDD_01","MP_M_FIBSec_01","MP_M_Freemode_01",
	"MP_M_Marston_01","MP_M_Niko_01","MP_M_ShopKeep_01","MP_S_M_Armoured_01","Player_One","Player_Two","Player_Zero","slod_human","slod_large_quadped","slod_small_quadped","S_F_M_Fembarber","S_F_M_Maid_01","S_F_M_Shop_HIGH",
	"S_F_M_SweatShop_01","S_F_Y_AirHostess_01","S_F_Y_Bartender_01","S_F_Y_Baywatch_01","S_F_Y_Cop_01","S_F_Y_Factory_01","S_F_Y_Hooker_01","S_F_Y_Hooker_02","S_F_Y_Hooker_03","S_F_Y_Migrant_01","S_F_Y_MovPrem_01","S_F_Y_Ranger_01",
	"S_F_Y_Scrubs_01","S_F_Y_Sheriff_01","S_F_Y_Shop_LOW","S_F_Y_Shop_MID","S_F_Y_StripperLite","S_F_Y_Stripper_01","S_F_Y_Stripper_02","S_F_Y_SweatShop_01","S_M_M_AmmuCountry","S_M_M_Armoured_01","S_M_M_Armoured_02","S_M_M_AutoShop_01",
	"S_M_M_AutoShop_02","S_M_M_Bouncer_01","S_M_M_ChemSec_01","S_M_M_CIASec_01","S_M_M_CntryBar_01","S_M_M_DockWork_01","S_M_M_Doctor_01","S_M_M_FIBOffice_01","S_M_M_FIBOffice_02","S_M_M_Gaffer_01","S_M_M_Gardener_01","S_M_M_GenTransport",
	"S_M_M_HairDress_01","S_M_M_HighSec_01","S_M_M_HighSec_02","S_M_M_Janitor","S_M_M_LatHandy_01","S_M_M_LifeInvad_01","S_M_M_Linecook","S_M_M_LSMetro_01","S_M_M_Mariachi_01","S_M_M_Marine_01","S_M_M_Marine_02","S_M_M_Migrant_01",
	"S_M_M_MovAlien_01","S_M_M_MovPrem_01","S_M_M_MovSpace_01","S_M_M_Paramedic_01","S_M_M_Pilot_01","S_M_M_Pilot_02","S_M_M_Postal_01","S_M_M_Postal_02","S_M_M_PrisGuard_01","S_M_M_Scientist_01","S_M_M_Security_01","S_M_M_SnowCop_01",
	"S_M_M_StrPerf_01","S_M_M_StrPreach_01","S_M_M_StrVend_01","S_M_M_Trucker_01","S_M_M_UPS_01","S_M_M_UPS_02","S_M_O_Busker_01","S_M_Y_AirWorker","S_M_Y_AmmuCity_01","S_M_Y_ArmyMech_01","S_M_Y_Autopsy_01","S_M_Y_Barman_01","S_M_Y_BayWatch_01",
	"S_M_Y_BlackOps_01","S_M_Y_BlackOps_02","S_M_Y_BlackOps_03","S_M_Y_BusBoy_01","S_M_Y_Chef_01","S_M_Y_Clown_01","S_M_Y_Construct_01","S_M_Y_Construct_02","S_M_Y_Cop_01","S_M_Y_Dealer_01","S_M_Y_DevinSec_01","S_M_Y_DockWork_01","S_M_Y_Doorman_01",
	"S_M_Y_DWService_01","S_M_Y_DWService_02","S_M_Y_Factory_01","S_M_Y_Fireman_01","S_M_Y_Garbage","S_M_Y_Grip_01","S_M_Y_HwayCop_01","S_M_Y_Marine_01","S_M_Y_Marine_02","S_M_Y_Marine_03","S_M_Y_Mime","S_M_Y_PestCont_01",
	"S_M_Y_Pilot_01","S_M_Y_PrisMuscl_01","S_M_Y_Prisoner_01","S_M_Y_Ranger_01","S_M_Y_Robber_01","S_M_Y_Sheriff_01","S_M_Y_Shop_MASK","S_M_Y_StrVend_01","S_M_Y_Swat_01","S_M_Y_USCG_01","S_M_Y_Valet_01","S_M_Y_Waiter_01",
	"S_M_Y_WinClean_01","S_M_Y_XMech_01","S_M_Y_XMech_02","U_F_M_Corpse_01","U_F_M_Miranda","U_F_M_ProMourn_01","U_F_O_MovieStar","U_F_O_ProlHost_01","U_F_Y_BikerChic","U_F_Y_COMJane","U_F_Y_corpse_01","U_F_Y_corpse_02",
	"U_F_Y_HotPosh_01","U_F_Y_JewelAss_01","U_F_Y_Mistress","U_F_Y_PoppyMich","U_F_Y_Princess","U_F_Y_SpyActress","U_M_M_Aldinapoli","U_M_M_BankMan","U_M_M_BikeHire_01","U_M_M_FIBArchitect","U_M_M_FilmDirector","U_M_M_GlenStank_01",
	"U_M_M_Griff_01","U_M_M_Jesus_01","U_M_M_JewelSec_01","U_M_M_JewelThief","U_M_M_MarkFost","U_M_M_PartyTarget","U_M_M_ProlSec_01","U_M_M_ProMourn_01","U_M_M_RivalPap","U_M_M_SpyActor","U_M_M_WillyFist","U_M_O_FinGuru_01",
	"U_M_O_TapHillBilly","U_M_O_Tramp_01","U_M_Y_Abner","U_M_Y_AntonB",	"U_M_Y_BabyD","U_M_Y_Baygor","U_M_Y_BurgerDrug_01","U_M_Y_Chip","U_M_Y_Cyclist_01","U_M_Y_FIBMugger_01","U_M_Y_Guido_01","U_M_Y_GunVend_01","U_M_Y_Hippie_01",
	"U_M_Y_ImpoRage","U_M_Y_Justin","U_M_Y_Mani","U_M_Y_MilitaryBum","U_M_Y_Paparazzi","U_M_Y_Party_01","U_M_Y_Pogo_01","U_M_Y_Prisoner_01","U_M_Y_ProlDriver_01","U_M_Y_RSRanger_01","U_M_Y_SBike","U_M_Y_StagGrm_01","U_M_Y_Tattoo_01",
	"U_M_Y_Zombie_01",
};
static char* objects1[] = {
	"PROP_MP_RAMP_03","prop_a4_pile_01","prop_a4_sheet_01","prop_a4_sheet_02","prop_a4_sheet_03","prop_a4_sheet_04","prop_a4_sheet_05","prop_aerial_01b","prop_aerial_01a","prop_acc_guitar_01_d1","prop_acc_guitar_01","prop_abat_slide","prop_abat_roller_static",
	"prop_aircon_l_01","prop_aircon_l_02","prop_aircon_l_03","prop_aircon_l_04","prop_aircon_m_09","prop_aircon_s_01a","prop_aircon_s_07b","prop_aircon_s_07a","prop_aircon_s_06a","prop_aircon_s_05a","prop_aircon_s_04a","prop_aircon_s_03b","prop_aircon_s_03a","prop_aircon_s_02b","prop_aircon_s_02a","prop_aiprort_sign_01","prop_aiprort_sign_02","prop_agave_02","prop_agave_01","prop_afsign_vbike","prop_afsign_amun","prop_aerial_01d","prop_aerial_01c",
	"prop_air_cargo_04c","prop_air_cargo_04b","prop_air_cargo_04a","prop_air_cargo_03a","prop_air_cargo_02b","prop_air_cargo_02a","prop_air_cargo_01c","prop_air_cargo_01b","prop_air_cargo_01a","prop_air_cargoloader_01","prop_air_bridge01","prop_air_bridge02","prop_air_blastfence_01","prop_air_blastfence_02","prop_air_bigradar_slod","prop_air_bigradar_l1","prop_air_bigradar_l2","prop_air_bench_01","prop_air_bench_02","prop_air_barrier","prop_air_bagloader2","prop_air_bagloader","prop_airhockey_01",
	"prop_air_stair_01","prop_air_radar_01","prop_air_propeller01","prop_air_monhut_02","prop_air_monhut_03","prop_air_monhut_01","prop_air_mast_02","prop_air_mast_01","prop_air_luggtrolley","prop_air_lights_01a","prop_air_lights_01b","prop_air_lights_03a","prop_air_hoc_paddle_01","prop_air_hoc_paddle_02","prop_air_generator_03","prop_air_generator_01","prop_air_gasbogey_01","prop_air_fueltrail2","prop_air_fueltrail1","prop_air_chock_04","prop_air_chock_03","prop_air_chock_01",
	"prop_amb_ciggy_01","prop_amb_beer_bottle","prop_amb_40oz_02","prop_amb_40oz_03","prop_amanda_note_01b","prop_amanda_note_01","prop_aloevera_01","prop_alien_egg_01","prop_alarm_01","prop_alarm_02","prop_air_woodsteps","prop_air_windsock_base","prop_air_watertank1","prop_air_watertank2","prop_air_trailer_4c","prop_air_trailer_4b","prop_air_trailer_4a","prop_air_towbar_03","prop_air_towbar_02","prop_air_towbar_01","prop_air_stair_04b","prop_air_stair_04a","prop_air_stair_03","prop_air_stair_02",
	"prop_artgallery_dr","prop_artgallery_dl","prop_artgallery_02_dr","prop_artgallery_02_dl","prop_arm_wrestle_01","prop_arm_gate_l","prop_armour_pickup","prop_armenian_gate","prop_armchair_01","prop_arc_blueprints_01","prop_arcade_01","prop_arcade_02","prop_apple_box_01","prop_apple_box_02","prop_anim_cash_pile_02","prop_anim_cash_pile_01","prop_anim_cash_note_b","prop_anim_cash_note","prop_am_box_wood_01","prop_amp_01","prop_amb_phone","prop_amb_handbag_01","prop_amb_donut",
	"prop_barbell_60kg","prop_barbell_50kg","prop_barbell_40kg","prop_barbell_30kg","prop_barbell_20kg","prop_barbell_10kg","prop_barbell_100kg","prop_barbell_02","prop_barbell_01","prop_bank_vaultdoor","prop_bank_shutter","prop_bandsaw_01","prop_ballistic_shield_lod1","prop_ballistic_shield","prop_bahammenu","prop_a_trailer_door_01","prop_a_base_bars_01","prop_aviators_01","prop_attache_case_01","prop_atm_03","prop_atm_02","prop_asteroid_01","prop_ashtray_01","prop_artifact_01",
	"prop_barrel_float_2","prop_barrel_float_1","prop_barrel_03d","prop_barrel_03a","prop_barrel_02b","prop_barrel_02a","prop_barrel_01a","prop_barrachneon","prop_barn_door_r","prop_barn_door_l","prop_barier_conc_05b","prop_barier_conc_05a","prop_barier_conc_04a","prop_barier_conc_03a","prop_barier_conc_02c","prop_barier_conc_02b","prop_barier_conc_01c","prop_barier_conc_01b","prop_barbell_80kg",
	"prop_bar_pump_06","prop_bar_pump_05","prop_bar_pump_04","prop_bar_napkindisp","prop_bar_napkindisp","prop_bar_ice_01","prop_bar_fridge_04","prop_bar_fridge_03","prop_bar_fridge_02","prop_bar_fridge_01","prop_bar_cooler_03","prop_bar_cooler_01","prop_bar_coastmount","prop_bar_coastdusc","prop_bar_coastchamp","prop_bar_coastbarr","prop_barry_table_detail","prop_barrier_work01c","prop_barrier_wat_03b","prop_barrier_wat_01a","prop_barriercrash_04","prop_barriercrash_03",
	"prop_beachbag_combo_01","prop_beachbag_06","prop_beachbag_05","prop_beachbag_04","prop_beachbag_03","prop_beachbag_02","prop_beachbag_01","prop_bbq_3","prop_bbq_2","prop_bball_arcade_01","prop_battery_02","prop_battery_01","prop_bath_dirt_01","prop_basketball_net","prop_basejump_target_01","prop_bar_stool_01","prop_bar_sink_01","prop_bar_pump_10","prop_bar_pump_09","prop_bar_pump_08","prop_bar_pump_07",
	"prop_beach_punchbag","prop_beach_sculp_01","prop_beach_rings_01","prop_beach_lotion_03","prop_beach_lotion_02","prop_beach_lotion_01","prop_beach_lg_surf","prop_beach_lg_stretch","prop_beach_lg_float","prop_beach_fire","prop_beach_dip_bars_02","prop_beach_dip_bars_01","prop_beach_bbq","prop_beach_bars_02","prop_beach_bars_01","prop_beachflag_le","prop_beachball_02","prop_beachbag_combo_02",
	"prop_bench_01c","prop_bench_01b","prop_beggers_sign_04","prop_beggers_sign_03","prop_beggers_sign_02","prop_beggers_sign_01","prop_beer_neon_04","prop_beer_neon_03","prop_beer_neon_02","prop_beer_neon_01","prop_beer_box_01","prop_beer_bison","prop_beerneon","prop_beach_volball02","prop_beach_volball01","prop_beach_towel_02",
	"prop_big_bag_01","prop_bhhotel_door_r","prop_bhhotel_door_l","prop_bh1_48_gate_1","prop_bh1_48_backdoor_r","prop_bh1_48_backdoor_l","prop_bh1_44_door_01r","prop_bh1_44_door_01l","prop_bh1_16_display","prop_bh1_09_mp_r","prop_bh1_09_mp_l","prop_bh1_09_mp_gar","prop_bh1_08_mp_gar","prop_bh1_03_gate_r","prop_beware_dog_sign","prop_beware_dog_sign","prop_beta_tape","prop_bench_09","prop_bench_05","prop_bench_04",
	"prop_billboard_13","prop_billboard_12","prop_billboard_11","prop_billboard_10","prop_billboard_09wall","prop_billboard_09","prop_billboard_08","prop_billboard_07","prop_billboard_06","prop_billboard_05","prop_billboard_04","prop_billboard_03","prop_billboard_02","prop_billboard_01","prop_bikini_disp_06","prop_bikini_disp_05","prop_bikini_disp_04","prop_bikini_disp_03","prop_bikini_disp_02","prop_bikini_disp_01","prop_bikerack_2","prop_big_sh*t_02","prop_big_sh*t_01","prop_big_bag_01",
	"prop_bin_beach_01d","prop_bin_14b","prop_bin_14a","prop_bin_13a","prop_bin_12a","prop_bin_11b","prop_bin_11a","prop_bin_10b","prop_bin_10a","prop_bin_04a","prop_binoc_01","prop_billb_frame04b","prop_billb_frame04a","prop_billb_frame03c","prop_billb_frame03b","prop_billb_frame03a","prop_billb_frame02b","prop_billb_frame02a","prop_billb_frame01b","prop_billb_frame01a","prop_billboard_16","prop_billboard_14","prop_billboard_14",
	"prop_bodyarmour_03","prop_bodyarmour_02","prop_bmu_track03","prop_bmu_track02","prop_bmu_track01","prop_bmu_02_ld_sup","prop_bmu_02_ld_cab","prop_bmu_02_ld","prop_bmu_02","prop_bmu_01_b","prop_bmu_01","prop_blox_spray","prop_bleachers_05","prop_bleachers_04","prop_bleachers_03","prop_bleachers_02","prop_bleachers_01","prop_blackjack_01","prop_bison_winch","prop_biotech_store","prop_biolab_g_door","prop_bin_delpiero_b","prop_bin_delpiero",
	"prop_box_ammo02a","prop_box_ammo01a","prop_boxpile_10b","prop_boxpile_10a","prop_boxing_glove_01","prop_boxcar5_handle","prop_bowl_crisps","prop_bowling_pin","prop_bowling_ball","prop_bottle_cap_01","prop_boombox_01","prop_boogieboard_10","prop_boogieboard_09","prop_boogieboard_08","prop_boogieboard_07","prop_boogieboard_06","prop_boogieboard_05","prop_boogieboard_04","prop_boogieboard_03","prop_boogieboard_02","prop_boogieboard_01","prop_boogbd_stack_02","prop_boogbd_stack_01","prop_bong_01","prop_bongos_01","prop_bonesaw","prop_bomb_01_s","prop_bomb_01","prop_bollard_03a","prop_bollard_01c","prop_bollard_01b	","prop_bollard_01a","prop_bodyarmour_06","prop_bodyarmour_05","prop_bodyarmour_04",
	"prop_bush_ivy_01_2m","prop_bush_ivy_01_1m","prop_bush_grape_01","prop_bush_dead_02","prop_burto_gate_01","prop_bumper_car_01","prop_bumper_06","prop_bumper_05","prop_bumper_04","prop_bumper_03","prop_bumper_02","prop_bumper_01","prop_buck_spade_10	","prop_buck_spade_09","prop_buck_spade_08","prop_buck_spade_07","prop_buck_spade_06","prop_buck_spade_05","prop_buck_spade_04","prop_buck_spade_03","prop_buck_spade_02","prop_buck_spade_01","prop_bucket_02a","prop_bucket_01b","prop_bucket_01a","prop_buckets_02","prop_bs_map_door_01","prop_bskball_01","prop_broom_unit_01","prop_broken_cell_gate_01","prop_broken_cboard_p1","prop_broken_cboard_p1","prop_bread_rack_02","prop_bread_rack_01","prop_breadbin_01","prop_box_wood08a","prop_box_wood05b","prop_box_wood05a","prop_box_tea01a","prop_box_guncase_03a","prop_box_guncase_02a","prop_box_guncase_01a","prop_box_ammo07b","prop_box_ammo07a","prop_box_ammo05b","prop_box_ammo04a","prop_box_ammo03a_set2","prop_box_ammo03a_set",
	"prop_byard_chains01","prop_byard_boat02","prop_byard_boat01","prop_byard_block_01","prop_byard_bench02","prop_byard_bench01","prop_busker_hat_01","prop_bush_ornament_04","prop_bush_ornament_03","prop_bush_ornament_02","prop_bush_ornament_01","prop_bush_neat_08","prop_bush_neat_07","prop_bush_neat_06","prop_bush_neat_05","prop_bush_neat_04","prop_bush_neat_03","prop_bush_neat_02","prop_bush_neat_01","prop_bush_med_07","prop_bush_med_06","prop_bush_med_05","prop_bush_med_03","prop_bush_med_02","prop_bush_med_01","prop_bush_lrg_04d","prop_bush_lrg_04c","prop_bush_lrg_04b","prop_bush_lrg_03b","prop_bush_lrg_03","prop_bush_lrg_02b","prop_bush_lrg_02","prop_bush_lrg_01e","prop_bush_lrg_01d","prop_bush_lrg_01c","prop_bush_ivy_02_top","prop_bush_ivy_02_top","prop_bush_ivy_02_top","prop_bush_ivy_02_r","prop_bush_ivy_02_pot","prop_bush_ivy_02_l","prop_bush_ivy_02_2m","prop_bush_ivy_02_1m","prop_bush_ivy_01_top","prop_bush_ivy_01_r","prop_bush_ivy_01_pot","prop_bush_ivy_01_l","prop_bush_ivy_01_bk",
	"prop_cabinet_02b","prop_cabinet_01b","prop_cabinet_01","prop_c4_final_green","prop_c4_final","prop_b_board_blank","prop_byard_trailer02","prop_byard_trailer01","prop_byard_tank_01","prop_byard_steps_01","prop_byard_sleeper02","prop_byard_sleeper01","prop_byard_scfhold01","prop_byard_rowboat5","prop_byard_rowboat4","prop_byard_rowboat3","prop_byard_rowboat2","prop_byard_rowboat1","prop_byard_rampold","prop_byard_ramp","prop_byard_rack","prop_byard_pulley01","prop_byard_planks01","prop_byard_pipe_01","prop_byard_pipes01","prop_byard_phone","prop_byard_net02","prop_byard_motor_03","prop_byard_motor_02","prop_byard_motor_01","prop_byard_machine03","prop_byard_machine02","prop_byard_machine01","prop_byard_ladder01","prop_byard_hoses02","prop_byard_hoses01","prop_byard_hoist_2","prop_byard_hoist","prop_byard_float_02b","prop_byard_float_02","prop_byard_float_01b","prop_byard_float_01","prop_byard_floatpile","prop_byard_elecbox04","prop_byard_elecbox03","prop_byard_elecbox02","prop_byard_elecbox01","prop_byard_dingy",
	"prop_carcreeper","prop_cap_row_02b","prop_cap_row_02","prop_cap_row_01b","prop_cap_row_01","prop_cap_01b","prop_cap_01","prop_can_canoe","prop_candy_pqs","prop_camera_strap","prop_cable_hook_01","prop_cablespool_06","prop_cablespool_05","prop_cablespool_04","prop_cablespool_03","prop_cablespool_02","prop_cablespool_01b","prop_cablespool_01a",
	"prop_car_door_04","prop_car_door_03","prop_car_door_02","prop_car_door_01","prop_car_bonnet_02","prop_car_bonnet_01","prop_car_battery_01","prop_carwash_roller_vert","prop_carwash_roller_horz","prop_cartwheel_01","prop_carrier_bag_01_lod","prop_carrier_bag_01","prop_carjack_l2","prop_carjack","prop_cargo_int",
	"prop_casino_door_01l","prop_cash_trolly","prop_cash_pile_02","prop_cash_pile_01","prop_cash_note_01","prop_cash_envelope_01","prop_cash_dep_bag_01","prop_cash_crate_01","prop_cash_case_02","prop_cash_case_01","prop_casey_sec_id","prop_car_seat","prop_car_ignition","prop_car_exhaust_01","prop_car_engine_01",
	"prop_ceramic_jug_01","prop_cementmixer_02a","prop_cementmixer_01a","prop_cctv_unit_05","prop_cctv_unit_02","prop_cctv_unit_01","prop_cctv_cont_06","prop_cctv_cont_05","prop_cctv_cont_04","prop_cctv_cont_03","prop_cctv_cont_01","prop_cctv_02_sm","prop_cat_tail_01","prop_cattlecrush","prop_casino_door_01r	",
	"prop_chair_01a","prop_ch3_04_door_02","prop_ch3_04_door_01r","prop_ch3_04_door_01l","prop_ch3_01_trlrdoor_r","prop_ch3_01_trlrdoor_l","prop_ch2_09c_garage_door","prop_ch2_09b_door","prop_ch2_07b_20_g_door","prop_ch2_05d_g_door","prop_ch1_07_door_02r","prop_ch1_07_door_02l","prop_ch1_07_door_01r","prop_ch1_07_door_01l","prop_ceramic_jug_cork",
	"prop_chall_lamp_02","prop_chall_lamp_01n","prop_chair_pile_01","prop_chair_pile_01","prop_chair_10","prop_chair_09","prop_chair_08","prop_chair_07","prop_chair_06","prop_chair_05","prop_chair_04b","prop_chair_04a","prop_chair_03","prop_chair_02","prop_chair_01b",
	"prop_cigar_02","prop_cigar_01","prop_ch_025c_g_door_01","prop_choc_pq","prop_choc_meto","prop_choc_ego","prop_chip_fryer","prop_chickencoop_a","prop_cherenneon","prop_chem_vial_02b","prop_chem_vial_02","prop_chem_grill_bit","prop_chem_grill","prop_cheetah_covered","prop_chateau_chair_01",
	"prop_coathook_01","prop_cntrdoor_ld_r","prop_cntrdoor_ld_l","prop_clown_chair","prop_clothes_tub_01","prop_clothes_rail_2b","prop_clothes_rail_03","prop_clothes_rail_02","prop_clippers_01","prop_cliff_paper","prop_cleaver","prop_clapper_brd_01","prop_cigar_pack_02","prop_cigar_pack_01","prop_cigar_03",
	"prop_cone_float_1","prop_conc_sacks_02a","prop_com_ls_door_01","prop_com_gar_door_01","prop_compressor_03","prop_compressor_02","prop_compressor_01","prop_coke_block_half_b","prop_coke_block_half_a","prop_coke_block_01","prop_coffin_02b","prop_coffin_02","prop_coffee_mac_02","prop_coffee_cup_trailer","prop_cockneon",
	"prop_const_fence01b","prop_const_fence01a","prop_construcionlamp_01","prop_console_01","prop_conslift_steps","prop_conslift_rail2","prop_conslift_rail","prop_conslift_lift","prop_conslift_door","prop_conslift_cage","prop_conslift_brace","prop_conslift_base","prop_consign_02a","prop_consign_01c","prop_conschute",
	"prop_container_01h","prop_container_01g","prop_container_01f","prop_container_01d","prop_container_01d","prop_container_01c","prop_container_01b","prop_container_01a","prop_cons_ply02","prop_cons_ply01","prop_cons_plank","prop_cons_crate","prop_const_fence03b","prop_const_fence02b","prop_const_fence02a",
	"prop_container_old1","prop_container_ld2","prop_container_ld","prop_container_hole","prop_container_door_mb_r","prop_container_door_mb_l","prop_container_05mb","prop_container_04mb","prop_container_04a","prop_container_03_ld","prop_container_03mb","prop_container_03b","prop_container_03a","prop_container_02a","prop_container_01h",
	"prop_coral_grass_02","prop_coral_grass_01","prop_coral_flat_clam","prop_coral_flat_brainy","prop_coral_flat_02","prop_coral_flat_01_l1","prop_coral_flat_01","prop_coral_bush_01","prop_copper_pan","prop_copier_01","prop_cooker_03","prop_cont_chiller_01","prop_control_rm_door_01","prop_controller_01","prop_contnr_pile_01a",
	"prop_coral_spikey_01","prop_coral_pillar_02","prop_coral_pillar_01","prop_coral_kelp_04_l1","prop_coral_kelp_04","prop_coral_kelp_03_l1","prop_coral_kelp_03d","prop_coral_kelp_03c","prop_coral_kelp_03b","prop_coral_kelp_03a","prop_coral_kelp_03","prop_coral_kelp_02_l1","prop_coral_kelp_02","prop_coral_kelp_01_l1","prop_coral_kelp_01",
	"prop_couch_sm_02","prop_couch_sm1_07","prop_couch_sm1_07","prop_couch_lg_08","prop_couch_lg_07","prop_couch_lg_06","prop_couch_lg_05","prop_couch_lg_02","prop_couch_04","prop_couch_03","prop_couch_01","prop_cork_board","prop_cora_clam_01","prop_coral_sweed_04","prop_coral_sweed_03","prop_coral_sweed_01","prop_coral_sweed_01","prop_coral_stone_04","prop_coral_stone_03",
	"prop_creosote_b_01","prop_crate_float_1","prop_crate_11d","prop_crate_11c","prop_crate_11b","prop_crate_11a","prop_crate_10a","prop_crate_09a","prop_crate_08a","prop_crate_02a","prop_crate_01a","prop_cratepile_07a_l1","prop_crashed_heli","prop_cranial_saw","prop_crane_01_truck2","prop_crane_01_truck1","prop_couch_sm_07","prop_couch_sm_06","prop_couch_sm_05",
	"prop_cs_bar","prop_cs_bandana","prop_cs_ashtray","prop_cs_amanda_shoe","prop_cs_aircon_fan","prop_cs_aircon_01","prop_cs_abattoir_switch","prop_cs_30m_rope","prop_cs_20m_rope","prop_cs6_03_door_r","prop_cs6_03_door_l","prop_cs4_11_door","prop_cs4_10_tr_gd_01","prop_cs4_05_tdoor","prop_cs1_14b_traind_dam","prop_cs1_14b_traind","prop_crosssaw_01","prop_crisp_small","prop_crisp",
	"prop_cs_bowie_knife","prop_cs_bottle_opener","prop_cs_book_01","prop_cs_bin_03","prop_cs_bin_02","prop_cs_bin_01_skinned","prop_cs_bin_01_lid","prop_cs_bin_01","prop_cs_binder_01","prop_cs_beer_bot_test","prop_cs_beer_bot_40oz_03","prop_cs_beer_bot_40oz_02","prop_cs_beer_bot_40oz","prop_cs_beer_bot_03","prop_cs_beer_bot_02","prop_cs_beer_bot_01lod","prop_cs_beer_bot_01b","prop_cs_beer_bot_01","prop_cs_beachtowel_01",
	"prop_cs_cont_latch","prop_cs_coke_line","prop_cs_clothes_box","prop_cs_ciggy_01b","prop_cs_ciggy_01","prop_cs_cctv","prop_cs_cctv","prop_cs_cash_note_01","prop_cs_cardbox_01","prop_cs_business_card","prop_cs_burger_01","prop_cs_bucket_s_lod","prop_cs_bucket_s","prop_cs_bs_cup","prop_cs_brain_chunk","prop_cs_box_step","prop_cs_box_clothes","prop_cs_bowl_01b","prop_cs_bowl_01",
	"prop_cs_dumpster_01a","prop_cs_duffel_01b","prop_cs_duffel_01","prop_cs_dog_lead_c","prop_cs_dog_lead_b","prop_cs_dog_lead_a","prop_cs_dog_lead_3b","prop_cs_dog_lead_3a","prop_cs_dog_lead_2c","prop_cs_dog_lead_2b","prop_cs_dog_lead_2a","prop_cs_documents_01","prop_cs_dildo_01","prop_cs_diaphram","prop_cs_cuffs_01","prop_cs_crisps_01","prop_cs_creeper_01","prop_cs_credit_card","prop_cs_crackpipe",
	"prop_cs_gascutter_2","prop_cs_gascutter_1","prop_cs_fuel_nozle","prop_cs_fuel_hose","prop_cs_fridge_door","prop_cs_fridge","prop_cs_freightdoor_r1","prop_cs_freightdoor_l1","prop_cs_frank_photo","prop_cs_fork","prop_cs_folding_chair_01","prop_cs_film_reel_01","prop_cs_fertilizer","prop_cs_envolope_01","prop_cs_dvd_player","prop_cs_dvd_case","prop_cs_dvd","prop_cs_dumpster_lidr","prop_cs_dumpster_lidl",
	"prop_cs_katana_01","prop_cs_ironing_board","prop_cs_ilev_blind_01","prop_cs_ice_locker_door_r","prop_cs_ice_locker_door_l","prop_cs_ice_locker","prop_cs_h_bag_strap_01","prop_cs_hotdog_02","prop_cs_hotdog_01","prop_cs_heist_rope_b","prop_cs_heist_rope","prop_cs_heist_bag_strap_01","prop_cs_heist_bag_02","prop_cs_heist_bag_01","prop_cs_hand_radio","prop_cs_gunrack","prop_cs_gravyard_gate_r","prop_cs_gravyard_gate_l","prop_cs_glass_scrap",
	"prop_cs_mopbucket_01","prop_cs_mini_tv","prop_cs_milk_01","prop_cs_meth_pipe","prop_cs_marker_01","prop_cs_magazine","prop_cs_lipstick","prop_cs_lester_crate","prop_cs_leg_chain_01","prop_cs_leaf","prop_cs_lazlow_shirt_01b","prop_cs_lazlow_shirt_01","prop_cs_lazlow_ponytail","prop_cs_kitchen_cab_rd","prop_cs_kitchen_cab_ld","prop_cs_kitchen_cab_l2","prop_cs_keys_01","prop_cs_keyboard_01","prop_cs_katana_01",
	"prop_cs_petrol_can","prop_cs_pebble_02","prop_cs_pebble","prop_cs_para_ropes","prop_cs_para_ropebit","prop_cs_paper_cup","prop_cs_panties_03","prop_cs_panties_02","prop_cs_panties","prop_cs_panel_01","prop_cs_pamphlet_01","prop_cs_padlock","prop_cs_package_01","prop_cs_overalls_01","prop_cs_office_chair","prop_cs_newspaper","prop_cs_nail_file","prop_cs_mouse_01","prop_cs_mop_s",
	"prop_cs_rage_statue_p1","prop_cs_protest_sign_04b","prop_cs_protest_sign_04a","prop_cs_protest_sign_03","prop_cs_protest_sign_02b","prop_cs_protest_sign_01","prop_cs_protest_sign_01","prop_cs_power_cord","prop_cs_power_cell","prop_cs_pour_tube","prop_cs_police_torch","prop_cs_polaroid","prop_cs_plate_01","prop_cs_plant_01","prop_cs_planning_photo","prop_cs_plane_int_01","prop_cs_pills","prop_cs_photoframe_01","prop_cs_phone_01",
	"prop_cs_shot_glass","prop_cs_shopping_bag","prop_cs_shirt_01","prop_cs_sheers","prop_cs_server_drive","prop_cs_script_bottle_01","prop_cs_script_bottle","prop_cs_scissors","prop_cs_sc1_11_gate","prop_cs_saucer_01","prop_cs_sack_01","prop_cs_r_business_card","prop_cs_rub_box_02","prop_cs_rub_box_01","prop_cs_rub_binbag_01","prop_cs_rope_tie_01","prop_cs_rolled_paper","prop_cs_remote_01","prop_cs_rage_statue_p2",
	"prop_cs_trolley_01","prop_cs_toaster","prop_cs_tablet_02","prop_cs_tablet","prop_cs_swipe_card","prop_cs_sub_rope_01","prop_cs_sub_hook_01","prop_cs_street_card_02","prop_cs_street_card_01","prop_cs_street_binbag_01","prop_cs_stock_book","prop_cs_steak","prop_cs_spray_can","prop_cs_sol_glasses","prop_cs_sm_27_gate","prop_cs_sink_filler_03","prop_cs_sink_filler_02","prop_cs_sink_filler","prop_cs_shot_glass",
	"prop_damdoor_01","prop_curl_bar_01","prop_cup_saucer_01","prop_cuff_keys_01","prop_cub_lifeblurb","prop_cub_door_lifeblurb","prop_cs_wrench","prop_cs_whiskey_bot_stop","prop_cs_whiskey_bottle","prop_cs_walking_stick","prop_cs_walkie_talkie","prop_cs_vial_01","prop_cs_vent_cover","prop_cs_valve","prop_cs_t_shirt_pile","prop_cs_tv_stand","prop_cs_tshirt_ball_01","prop_cs_truck_ladder","prop_cs_trowel",
	"prop_distantcar_day","prop_disp_razor_01","prop_disp_cabinet_01","prop_disp_cabinet_002","prop_display_unit_02","prop_display_unit_01","prop_direct_chair_02","prop_direct_chair_01","prop_diggerbkt_01","prop_devin_rope_01","prop_devin_box_01","prop_detergent_01b","prop_detergent_01a","prop_desert_iron_01","prop_defilied_ragdoll_01","prop_dart_bd_cab_01","prop_dart_bd_01","prop_dart_2","prop_dart_1",

	"","","","","","","","","","","","","","","","","","","",
};//1014
static char* objects2[] = {
	"prop_a4_pile_01",
	"prop_a4_sheet_01",
	"prop_a4_sheet_02",
	"prop_a4_sheet_03",
	"prop_a4_sheet_04",
	"prop_a4_sheet_05",
	"prop_abat_roller_static",
	"prop_abat_slide",
	"prop_acc_guitar_01",
	"prop_acc_guitar_01_d1",
	"prop_aerial_01a",
	"prop_aerial_01b",
	"prop_aerial_01c",
	"prop_aerial_01d",
	"prop_afsign_amun",
	"prop_afsign_vbike",
	"prop_agave_01",
	"prop_agave_02",
	"prop_aiprort_sign_01",
	"prop_aiprort_sign_02",
	"prop_aircon_l_01",
	"prop_aircon_l_02",
	"prop_aircon_l_03",
	"prop_aircon_l_04",
	"prop_aircon_m_09",
	"prop_aircon_s_01a",
	"prop_aircon_s_02a",
	"prop_aircon_s_02b",
	"prop_aircon_s_03a",
	"prop_aircon_s_03b",
	"prop_aircon_s_04a",
	"prop_aircon_s_05a",
	"prop_aircon_s_06a",
	"prop_aircon_s_07a",
	"prop_aircon_s_07b",
	"prop_airhockey_01",
	"prop_air_bagloader",
	"prop_air_bagloader2",
	"prop_air_barrier",
	"prop_air_bench_01",
	"prop_air_bench_02",
	"prop_air_bigradar_l1",
	"prop_air_bigradar_l2",
	"prop_air_bigradar_slod",
	"prop_air_blastfence_01",
	"prop_air_blastfence_02",
	"prop_air_bridge01",
	"prop_air_bridge02",
	"prop_air_cargoloader_01",
	"prop_air_cargo_01a",
	"prop_air_cargo_01b",
	"prop_air_cargo_01c",
	"prop_air_cargo_02a",
	"prop_air_cargo_02b",
	"prop_air_cargo_03a",
	"prop_air_cargo_04a",
	"prop_air_cargo_04b",
	"prop_air_cargo_04c",
	"prop_air_chock_01",
	"prop_air_chock_03",
	"prop_air_chock_04",
	"prop_air_fueltrail1",
	"prop_air_fueltrail2",
	"prop_air_gasbogey_01",
	"prop_air_generator_01",
	"prop_air_generator_03",
	"prop_air_hoc_paddle_01",
	"prop_air_hoc_paddle_02",
	"prop_air_lights_01a",
	"prop_air_lights_01b",
	"prop_air_lights_03a",
	"prop_air_luggtrolley",
	"prop_air_mast_01",
	"prop_air_mast_02",
	"prop_air_monhut_01",
	"prop_air_monhut_02",
	"prop_air_monhut_03",
	"prop_air_propeller01",
	"prop_air_radar_01",
	"prop_air_stair_01",
	"prop_air_stair_02",
	"prop_air_stair_03",
	"prop_air_stair_04a",
	"prop_air_stair_04b",
	"prop_air_towbar_01",
	"prop_air_towbar_02",
	"prop_air_towbar_03",
	"prop_air_trailer_4a",
	"prop_air_trailer_4b",
	"prop_air_trailer_4c",
	"prop_air_watertank1",
	"prop_air_watertank2",
	"prop_air_windsock_base",
	"prop_air_woodsteps",
	"prop_alarm_01",
	"prop_alarm_02",
	"prop_alien_egg_01",
	"prop_aloevera_01",
	"prop_amanda_note_01",
	"prop_amanda_note_01b",
	"prop_amb_40oz_02",
	"prop_amb_40oz_03",
	"prop_amb_beer_bottle",
	"prop_amb_ciggy_01",
	"prop_amb_donut",
	"prop_amb_handbag_01",
	"prop_amb_phone",
	"prop_amp_01",
	"prop_am_box_wood_01",
	"prop_anim_cash_note",
	"prop_anim_cash_note_b",
	"prop_anim_cash_pile_01",
	"prop_anim_cash_pile_02",
	"prop_apple_box_01",
	"prop_apple_box_02",
	"prop_arcade_01",
	"prop_arcade_02",
	"prop_arc_blueprints_01",
	"prop_armchair_01",
	"prop_armenian_gate",
	"prop_armour_pickup",
	"prop_arm_gate_l",
	"prop_arm_wrestle_01",
	"prop_artgallery_02_dl",
	"prop_artgallery_02_dr",
	"prop_artgallery_dl",
	"prop_artgallery_dr",
	"prop_artifact_01",
	"prop_ashtray_01",
	"prop_asteroid_01",
	"prop_atm_02",
	"prop_atm_03",
	"prop_attache_case_01",
	"prop_aviators_01",
	"prop_a_base_bars_01",
	"prop_a_trailer_door_01",
	"prop_bahammenu",
	"prop_ballistic_shield",
	"prop_ballistic_shield_lod1",
	"prop_bandsaw_01",
	"prop_bank_shutter",
	"prop_bank_vaultdoor",
	"prop_barbell_01",
	"prop_barbell_02",
	"prop_barbell_100kg",
	"prop_barbell_10kg",
	"prop_barbell_20kg",
	"prop_barbell_30kg",
	"prop_barbell_40kg",
	"prop_barbell_50kg",
	"prop_barbell_60kg",
	"prop_barbell_80kg",
	"prop_barier_conc_01b",
	"prop_barier_conc_01c",
	"prop_barier_conc_02b",
	"prop_barier_conc_02c",
	"prop_barier_conc_03a",
	"prop_barier_conc_04a",
	"prop_barier_conc_05a",
	"prop_barier_conc_05b",
	"prop_barn_door_l",
	"prop_barn_door_r",
	"prop_barrachneon",
	"prop_barrel_01a",
	"prop_barrel_02a",
	"prop_barrel_02b",
	"prop_barrel_03a",
	"prop_barrel_03d",
	"prop_barrel_float_1",
	"prop_barrel_float_2",
	"prop_barriercrash_03",
	"prop_barriercrash_04",
	"prop_barrier_wat_01a",
	"prop_barrier_wat_03b",
	"prop_barrier_work01c",
	"prop_barry_table_detail",
	"prop_bar_coastbarr",
	"prop_bar_coastchamp",
	"prop_bar_coastdusc",
	"prop_bar_coastmount",
	"prop_bar_cooler_01",
	"prop_bar_cooler_03",
	"prop_bar_fridge_01",
	"prop_bar_fridge_02",
	"prop_bar_fridge_03",
	"prop_bar_fridge_04",
	"prop_bar_ice_01",
	"prop_bar_napkindisp",
	"prop_bar_pump_01",
	"prop_bar_pump_04",
	"prop_bar_pump_05",
	"prop_bar_pump_06",
	"prop_bar_pump_07",
	"prop_bar_pump_08",
	"prop_bar_pump_09",
	"prop_bar_pump_10",
	"prop_bar_sink_01",
	"prop_bar_stool_01",
	"prop_basejump_target_01",
	"prop_basketball_net",
	"prop_bath_dirt_01",
	"prop_battery_01",
	"prop_battery_02",
	"prop_bball_arcade_01",
	"prop_bbq_2",
	"prop_bbq_3",
	"prop_beachbag_01",
	"prop_beachbag_02",
	"prop_beachbag_03",
	"prop_beachbag_04",
	"prop_beachbag_05",
	"prop_beachbag_06",
	"prop_beachbag_combo_01",
	"prop_beachbag_combo_02",
	"prop_beachball_02",
	"prop_beachflag_le",
	"prop_beach_bars_01",
	"prop_beach_bars_02",
	"prop_beach_bbq",
	"prop_beach_dip_bars_01",
	"prop_beach_dip_bars_02",
	"prop_beach_fire",
	"prop_beach_lg_float",
	"prop_beach_lg_stretch",
	"prop_beach_lg_surf",
	"prop_beach_lotion_01",
	"prop_beach_lotion_02",
	"prop_beach_lotion_03",
	"prop_beach_punchbag",
	"prop_beach_rings_01",
	"prop_beach_sculp_01",
	"prop_beach_towel_02",
	"prop_beach_volball01",
	"prop_beach_volball02",
	"prop_beerneon",
	"prop_beer_bison",
	"prop_beer_box_01",
	"prop_beer_neon_01",
	"prop_beer_neon_02",
	"prop_beer_neon_03",
	"prop_beer_neon_04",
	"prop_beggers_sign_01",
	"prop_beggers_sign_02",
	"prop_beggers_sign_03",
	"prop_beggers_sign_04",
	"prop_bench_01b",
	"prop_bench_01c",
	"prop_bench_04",
	"prop_bench_05",
	"prop_bench_09",
	"prop_beta_tape",
	"prop_beware_dog_sign",
	"prop_bh1_03_gate_l",
	"prop_bh1_03_gate_r",
	"prop_bh1_08_mp_gar",
	"prop_bh1_09_mp_gar",
	"prop_bh1_09_mp_l",
	"prop_bh1_09_mp_r",
	"prop_bh1_16_display",
	"prop_bh1_44_door_01l",
	"prop_bh1_44_door_01r",
	"prop_bh1_48_backdoor_l",
	"prop_bh1_48_backdoor_r",
	"prop_bh1_48_gate_1",
	"prop_bhhotel_door_l",
	"prop_bhhotel_door_r",
	"prop_big_bag_01",
	"prop_big_clock_01",
	"prop_big_shit_01",
	"prop_big_shit_02",
	"prop_bikerack_2",
	"prop_bikini_disp_01",
	"prop_bikini_disp_02",
	"prop_bikini_disp_03",
	"prop_bikini_disp_04",
	"prop_bikini_disp_05",
	"prop_bikini_disp_06",
	"prop_billboard_01",
	"prop_billboard_02",
	"prop_billboard_03",
	"prop_billboard_04",
	"prop_billboard_05",
	"prop_billboard_06",
	"prop_billboard_07",
	"prop_billboard_08",
	"prop_billboard_09",
	"prop_billboard_09wall",
	"prop_billboard_10",
	"prop_billboard_11",
	"prop_billboard_12",
	"prop_billboard_13",
	"prop_billboard_14",
	"prop_billboard_15",
	"prop_billboard_16",
	"prop_billb_frame01a",
	"prop_billb_frame01b",
	"prop_billb_frame02a",
	"prop_billb_frame02b",
	"prop_billb_frame03a",
	"prop_billb_frame03b",
	"prop_billb_frame03c",
	"prop_billb_frame04a",
	"prop_billb_frame04b",
	"prop_binoc_01",
	"prop_bin_04a",
	"prop_bin_10a",
	"prop_bin_10b",
	"prop_bin_11a",
	"prop_bin_11b",
	"prop_bin_12a",
	"prop_bin_13a",
	"prop_bin_14a",
	"prop_bin_14b",
	"prop_bin_beach_01d",
	"prop_bin_delpiero",
	"prop_bin_delpiero_b",
	"prop_biolab_g_door",
	"prop_biotech_store",
	"prop_bison_winch",
	"prop_blackjack_01",
	"prop_bleachers_01",
	"prop_bleachers_02",
	"prop_bleachers_03",
	"prop_bleachers_04",
	"prop_bleachers_05",
	"prop_blox_spray",
	"prop_bmu_01",
	"prop_bmu_01_b",
	"prop_bmu_02",
	"prop_bmu_02_ld",
	"prop_bmu_02_ld_cab",
	"prop_bmu_02_ld_sup",
	"prop_bmu_track01",
	"prop_bmu_track02",
	"prop_bmu_track03",
	"prop_bodyarmour_02",
	"prop_bodyarmour_03",
	"prop_bodyarmour_04",
	"prop_bodyarmour_05",
	"prop_bodyarmour_06",
	"prop_bollard_01a",
	"prop_bollard_01b",
	"prop_bollard_01c",
	"prop_bollard_03a",
	"prop_bomb_01",
	"prop_bomb_01_s",
	"prop_bonesaw",
	"prop_bongos_01",
	"prop_bong_01",
	"prop_boogbd_stack_01",
	"prop_boogbd_stack_02",
	"prop_boogieboard_01",
	"prop_boogieboard_02",
	"prop_boogieboard_03",
	"prop_boogieboard_04",
	"prop_boogieboard_05",
	"prop_boogieboard_06",
	"prop_boogieboard_07",
	"prop_boogieboard_08",
	"prop_boogieboard_09",
	"prop_boogieboard_10",
	"prop_boombox_01",
	"prop_bottle_cap_01",
	"prop_bowling_ball",
	"prop_bowling_pin",
	"prop_bowl_crisps",
	"prop_boxcar5_handle",
	"prop_boxing_glove_01",
	"prop_boxpile_10a",
	"prop_boxpile_10b",
	"prop_box_ammo01a",
	"prop_box_ammo02a",
	"prop_box_ammo03a_set",
	"prop_box_ammo03a_set2",
	"prop_box_ammo04a",
	"prop_box_ammo05b",
	"prop_box_ammo07a",
	"prop_box_ammo07b",
	"prop_box_guncase_01a",
	"prop_box_guncase_02a",
	"prop_box_guncase_03a",
	"prop_box_tea01a",
	"prop_box_wood05a",
	"prop_box_wood05b",
	"prop_box_wood08a",
	"prop_breadbin_01",
	"prop_bread_rack_01",
	"prop_bread_rack_02",
	"prop_broken_cboard_p1",
	"prop_broken_cboard_p2",
	"prop_broken_cell_gate_01",
	"prop_broom_unit_01",
	"prop_bskball_01",
	"prop_bs_map_door_01",
	"prop_buckets_02",
	"prop_bucket_01a",
	"prop_bucket_01b",
	"prop_bucket_02a",
	"prop_buck_spade_01",
	"prop_buck_spade_02",
	"prop_buck_spade_03",
	"prop_buck_spade_04",
	"prop_buck_spade_05",
	"prop_buck_spade_06",
	"prop_buck_spade_07",
	"prop_buck_spade_08",
	"prop_buck_spade_09",
	"prop_buck_spade_10",
	"prop_bumper_01",
	"prop_bumper_02",
	"prop_bumper_03",
	"prop_bumper_04",
	"prop_bumper_05",
	"prop_bumper_06",
	"prop_bumper_car_01",
	"prop_burto_gate_01",
	"prop_bush_dead_02",
	"prop_bush_grape_01",
	"prop_bush_ivy_01_1m",
	"prop_bush_ivy_01_2m",
	"prop_bush_ivy_01_bk",
	"prop_bush_ivy_01_l",
	"prop_bush_ivy_01_pot",
	"prop_bush_ivy_01_r",
	"prop_bush_ivy_01_top",
	"prop_bush_ivy_02_1m",
	"prop_bush_ivy_02_2m",
	"prop_bush_ivy_02_l",
	"prop_bush_ivy_02_pot",
	"prop_bush_ivy_02_r",
	"prop_bush_ivy_02_top",
	"prop_bush_lrg_01",
	"prop_bush_lrg_01b",
	"prop_bush_lrg_01c",
	"prop_bush_lrg_01d",
	"prop_bush_lrg_01e",
	"prop_bush_lrg_02",
	"prop_bush_lrg_02b",
	"prop_bush_lrg_03",
	"prop_bush_lrg_03b",
	"prop_bush_lrg_04b",
	"prop_bush_lrg_04c",
	"prop_bush_lrg_04d",
	"prop_bush_med_01",
	"prop_bush_med_02",
	"prop_bush_med_03",
	"prop_bush_med_05",
	"prop_bush_med_06",
	"prop_bush_med_07",
	"prop_bush_neat_01",
	"prop_bush_neat_02",
	"prop_bush_neat_03",
	"prop_bush_neat_04",
	"prop_bush_neat_05",
	"prop_bush_neat_06",
	"prop_bush_neat_07",
	"prop_bush_neat_08",
	"prop_bush_ornament_01",
	"prop_bush_ornament_02",
	"prop_bush_ornament_03",
	"prop_bush_ornament_04",
	"prop_busker_hat_01",
	"prop_byard_bench01",
	"prop_byard_bench02",
	"prop_byard_block_01",
	"prop_byard_boat01",
	"prop_byard_boat02",
	"prop_byard_chains01",
	"prop_byard_dingy",
	"prop_byard_elecbox01",
	"prop_byard_elecbox02",
	"prop_byard_elecbox03",
	"prop_byard_elecbox04",
	"prop_byard_floatpile",
	"prop_byard_float_01",
	"prop_byard_float_01b",
	"prop_byard_float_02",
	"prop_byard_float_02b",
	"prop_byard_hoist",
	"prop_byard_hoist_2",
	"prop_byard_hoses01",
	"prop_byard_hoses02",
	"prop_byard_ladder01",
	"prop_byard_machine01",
	"prop_byard_machine02",
	"prop_byard_machine03",
	"prop_byard_motor_01",
	"prop_byard_motor_02",
	"prop_byard_motor_03",
	"prop_byard_net02",
	"prop_byard_phone",
	"prop_byard_pipes01",
	"prop_byard_pipe_01",
	"prop_byard_planks01",
	"prop_byard_pulley01",
	"prop_byard_rack",
	"prop_byard_ramp",
	"prop_byard_rampold",
	"prop_byard_rowboat1",
	"prop_byard_rowboat2",
	"prop_byard_rowboat3",
	"prop_byard_rowboat4",
	"prop_byard_rowboat5",
	"prop_byard_scfhold01",
	"prop_byard_sleeper01",
	"prop_byard_sleeper02",
	"prop_byard_steps_01",
	"prop_byard_tank_01",
	"prop_byard_trailer01",
	"prop_byard_trailer02",
	"prop_b_board_blank",
	"prop_c4_final",
	"prop_c4_final_green",
	"prop_cabinet_01",
	"prop_cabinet_01b",
	"prop_cabinet_02b",
	"prop_cablespool_01a",
	"prop_cablespool_01b",
	"prop_cablespool_02",
	"prop_cablespool_03",
	"prop_cablespool_04",
	"prop_cablespool_05",
	"prop_cablespool_06",
	"prop_cable_hook_01",
	"prop_camera_strap",
	"prop_candy_pqs",
	"prop_can_canoe",
	"prop_cap_01",
	"prop_cap_01b",
	"prop_cap_row_01",
	"prop_cap_row_01b",
	"prop_cap_row_02",
	"prop_cap_row_02b",
	"prop_carcreeper",
	"prop_cargo_int",
	"prop_carjack",
	"prop_carjack_l2",
	"prop_carrier_bag_01",
	"prop_carrier_bag_01_lod",
	"prop_cartwheel_01",
	"prop_carwash_roller_horz",
	"prop_carwash_roller_vert",
	"prop_car_battery_01",
	"prop_car_bonnet_01",
	"prop_car_bonnet_02",
	"prop_car_door_01",
	"prop_car_door_02",
	"prop_car_door_03",
	"prop_car_door_04",
	"prop_car_engine_01",
	"prop_car_exhaust_01",
	"prop_car_ignition",
	"prop_car_seat",
	"prop_casey_sec_id",
	"prop_cash_case_01",
	"prop_cash_case_02",
	"prop_cash_crate_01",
	"prop_cash_dep_bag_01",
	"prop_cash_envelope_01",
	"prop_cash_note_01",
	"prop_cash_pile_01",
	"prop_cash_pile_02",
	"prop_cash_trolly",
	"prop_casino_door_01l",
	"prop_casino_door_01r",
	"prop_cattlecrush",
	"prop_cat_tail_01",
	"prop_cctv_02_sm",
	"prop_cctv_cont_01",
	"prop_cctv_cont_03",
	"prop_cctv_cont_04",
	"prop_cctv_cont_05",
	"prop_cctv_cont_06",
	"prop_cctv_unit_01",
	"prop_cctv_unit_02",
	"prop_cctv_unit_05",
	"prop_cementmixer_01a",
	"prop_cementmixer_02a",
	"prop_ceramic_jug_01",
	"prop_ceramic_jug_cork",
	"prop_ch1_07_door_01l",
	"prop_ch1_07_door_01r",
	"prop_ch1_07_door_02l",
	"prop_ch1_07_door_02r",
	"prop_ch2_05d_g_door",
	"prop_ch2_07b_20_g_door",
	"prop_ch2_09b_door",
	"prop_ch2_09c_garage_door",
	"prop_ch3_01_trlrdoor_l",
	"prop_ch3_01_trlrdoor_r",
	"prop_ch3_04_door_01l",
	"prop_ch3_04_door_01r",
	"prop_ch3_04_door_02",
	"prop_chair_01a",
	"prop_chair_01b",
	"prop_chair_02",
	"prop_chair_03",
	"prop_chair_04a",
	"prop_chair_04b",
	"prop_chair_05",
	"prop_chair_06",
	"prop_chair_07",
	"prop_chair_08",
	"prop_chair_09",
	"prop_chair_10",
	"prop_chair_pile_01",
	"prop_chall_lamp_01",
	"prop_chall_lamp_01n",
	"prop_chall_lamp_02",
	"prop_chateau_chair_01",
	"prop_cheetah_covered",
	"prop_chem_grill",
	"prop_chem_grill_bit",
	"prop_chem_vial_02",
	"prop_chem_vial_02b",
	"prop_cherenneon",
	"prop_chickencoop_a",
	"prop_chip_fryer",
	"prop_choc_ego",
	"prop_choc_meto",
	"prop_choc_pq",
	"prop_ch_025c_g_door_01",
	"prop_cigar_01",
	"prop_cigar_02",
	"prop_cigar_03",
	"prop_cigar_pack_01",
	"prop_cigar_pack_02",
	"prop_clapper_brd_01",
	"prop_cleaver",
	"prop_cliff_paper",
	"prop_clippers_01",
	"prop_clothes_rail_02",
	"prop_clothes_rail_03",
	"prop_clothes_rail_2b",
	"prop_clothes_tub_01",
	"prop_clown_chair",
	"prop_cntrdoor_ld_l",
	"prop_cntrdoor_ld_r",
	"prop_coathook_01",
	"prop_cockneon",
	"prop_coffee_cup_trailer",
	"prop_coffee_mac_02",
	"prop_coffin_02",
	"prop_coffin_02b",
	"prop_coke_block_01",
	"prop_coke_block_half_a",
	"prop_coke_block_half_b",
	"prop_compressor_01",
	"prop_compressor_02",
	"prop_compressor_03",
	"prop_com_gar_door_01",
	"prop_com_ls_door_01",
	"prop_conc_sacks_02a",
	"prop_cone_float_1",
	"prop_conschute",
	"prop_consign_01c",
	"prop_consign_02a",
	"prop_conslift_base",
	"prop_conslift_brace",
	"prop_conslift_cage",
	"prop_conslift_door",
	"prop_conslift_lift",
	"prop_conslift_rail",
	"prop_conslift_rail2",
	"prop_conslift_steps",
	"prop_console_01",
	"prop_construcionlamp_01",
	"prop_const_fence01a",
	"prop_const_fence01b",
	"prop_const_fence02a",
	"prop_const_fence02b",
	"prop_const_fence03b",
	"prop_cons_crate",
	"prop_cons_plank",
	"prop_cons_ply01",
	"prop_cons_ply02",
	"prop_container_01a",
	"prop_container_01b",
	"prop_container_01c",
	"prop_container_01d",
	"prop_container_01e",
	"prop_container_01f",
	"prop_container_01g",
	"prop_container_01h",
	"prop_container_01mb",
	"prop_container_02a",
	"prop_container_03a",
	"prop_container_03b",
	"prop_container_03mb",
	"prop_container_03_ld",
	"prop_container_04a",
	"prop_container_04mb",
	"prop_container_05mb",
	"prop_container_door_mb_l",
	"prop_container_door_mb_r",
	"prop_container_hole",
	"prop_container_ld",
	"prop_container_ld2",
	"prop_container_old1",
	"prop_contnr_pile_01a",
	"prop_controller_01",
	"prop_control_rm_door_01",
	"prop_cont_chiller_01",
	"prop_cooker_03",
	"prop_copier_01",
	"prop_copper_pan",
	"prop_coral_bush_01",
	"prop_coral_flat_01",
	"prop_coral_flat_01_l1",
	"prop_coral_flat_02",
	"prop_coral_flat_brainy",
	"prop_coral_flat_clam",
	"prop_coral_grass_01",
	"prop_coral_grass_02",
	"prop_coral_kelp_01",
	"prop_coral_kelp_01_l1",
	"prop_coral_kelp_02",
	"prop_coral_kelp_02_l1",
	"prop_coral_kelp_03",
	"prop_coral_kelp_03a",
	"prop_coral_kelp_03b",
	"prop_coral_kelp_03c",
	"prop_coral_kelp_03d",
	"prop_coral_kelp_03_l1",
	"prop_coral_kelp_04",
	"prop_coral_kelp_04_l1",
	"prop_coral_pillar_01",
	"prop_coral_pillar_02",
	"prop_coral_spikey_01",
	"prop_coral_stone_03",
	"prop_coral_stone_04",
	"prop_coral_sweed_01",
	"prop_coral_sweed_02",
	"prop_coral_sweed_03",
	"prop_coral_sweed_04",
	"prop_cora_clam_01",
	"prop_cork_board",
	"prop_couch_01",
	"prop_couch_03",
	"prop_couch_04",
	"prop_couch_lg_02",
	"prop_couch_lg_05",
	"prop_couch_lg_06",
	"prop_couch_lg_07",
	"prop_couch_lg_08",
	"prop_couch_sm1_07",
	"prop_couch_sm2_07",
	"prop_couch_sm_02",
	"prop_couch_sm_05",
	"prop_couch_sm_06",
	"prop_couch_sm_07",
	"prop_crane_01_truck1",
	"prop_crane_01_truck2",
	"prop_cranial_saw",
	"prop_crashed_heli",
	"prop_cratepile_07a_l1",
	"prop_crate_01a",
	"prop_crate_02a",
	"prop_crate_08a",
	"prop_crate_09a",
	"prop_crate_10a",
	"prop_crate_11a",
	"prop_crate_11b",
	"prop_crate_11c",
	"prop_crate_11d",
	"prop_crate_float_1",
	"prop_creosote_b_01",
	"prop_crisp",
	"prop_crisp_small",
	"prop_crosssaw_01",
	"prop_cs1_14b_traind",
	"prop_cs1_14b_traind_dam",
	"prop_cs4_05_tdoor",
	"prop_cs4_10_tr_gd_01",
	"prop_cs4_11_door",
	"prop_cs6_03_door_l",
	"prop_cs6_03_door_r",
	"prop_cs_20m_rope",
	"prop_cs_30m_rope",
	"prop_cs_abattoir_switch",
	"prop_cs_aircon_01",
	"prop_cs_aircon_fan",
	"prop_cs_amanda_shoe",
	"prop_cs_ashtray",
	"prop_cs_bandana",
	"prop_cs_bar",
	"prop_cs_beachtowel_01",
	"prop_cs_beer_bot_01",
	"prop_cs_beer_bot_01b",
	"prop_cs_beer_bot_01lod",
	"prop_cs_beer_bot_02",
	"prop_cs_beer_bot_03",
	"prop_cs_beer_bot_40oz",
	"prop_cs_beer_bot_40oz_02",
	"prop_cs_beer_bot_40oz_03",
	"prop_cs_beer_bot_test",
	"prop_cs_binder_01",
	"prop_cs_bin_01",
	"prop_cs_bin_01_lid",
	"prop_cs_bin_01_skinned",
	"prop_cs_bin_02",
	"prop_cs_bin_03",
	"prop_cs_book_01",
	"prop_cs_bottle_opener",
	"prop_cs_bowie_knife",
	"prop_cs_bowl_01",
	"prop_cs_bowl_01b",
	"prop_cs_box_clothes",
	"prop_cs_box_step",
	"prop_cs_brain_chunk",
	"prop_cs_bs_cup",
	"prop_cs_bucket_s",
	"prop_cs_bucket_s_lod",
	"prop_cs_burger_01",
	"prop_cs_business_card",
	"prop_cs_cardbox_01",
	"prop_cs_cash_note_01",
	"prop_cs_cctv",
	"prop_cs_champ_flute",
	"prop_cs_ciggy_01",
	"prop_cs_ciggy_01b",
	"prop_cs_clothes_box",
	"prop_cs_coke_line",
	"prop_cs_cont_latch",
	"prop_cs_crackpipe",
	"prop_cs_credit_card",
	"prop_cs_creeper_01",
	"prop_cs_crisps_01",
	"prop_cs_cuffs_01",
	"prop_cs_diaphram",
	"prop_cs_dildo_01",
	"prop_cs_documents_01",
	"prop_cs_dog_lead_2a",
	"prop_cs_dog_lead_2b",
	"prop_cs_dog_lead_2c",
	"prop_cs_dog_lead_3a",
	"prop_cs_dog_lead_3b",
	"prop_cs_dog_lead_a",
	"prop_cs_dog_lead_b",
	"prop_cs_dog_lead_c",
	"prop_cs_duffel_01",
	"prop_cs_duffel_01b",
	"prop_cs_dumpster_01a",
	"prop_cs_dumpster_lidl",
	"prop_cs_dumpster_lidr",
	"prop_cs_dvd",
	"prop_cs_dvd_case",
	"prop_cs_dvd_player",
	"prop_cs_envolope_01",
	"prop_cs_fertilizer",
	"prop_cs_film_reel_01",
	"prop_cs_folding_chair_01",
	"prop_cs_fork",
	"prop_cs_frank_photo",
	"prop_cs_freightdoor_l1",
	"prop_cs_freightdoor_r1",
	"prop_cs_fridge",
	"prop_cs_fridge_door",
	"prop_cs_fuel_hose",
	"prop_cs_fuel_nozle",
	"prop_cs_gascutter_1",
	"prop_cs_gascutter_2",
	"prop_cs_glass_scrap",
	"prop_cs_gravyard_gate_l",
	"prop_cs_gravyard_gate_r",
	"prop_cs_gunrack",
	"prop_cs_hand_radio",
	"prop_cs_heist_bag_01",
	"prop_cs_heist_bag_02",
	"prop_cs_heist_bag_strap_01",
	"prop_cs_heist_rope",
	"prop_cs_heist_rope_b",
	"prop_cs_hotdog_01",
	"prop_cs_hotdog_02",
	"prop_cs_h_bag_strap_01",
	"prop_cs_ice_locker",
	"prop_cs_ice_locker_door_l",
	"prop_cs_ice_locker_door_r",
	"prop_cs_ilev_blind_01",
	"prop_cs_ironing_board",
	"prop_cs_katana_01",
	"prop_cs_kettle_01",
	"prop_cs_keyboard_01",
	"prop_cs_keys_01",
	"prop_cs_kitchen_cab_l2",
	"prop_cs_kitchen_cab_ld",
	"prop_cs_kitchen_cab_rd",
	"prop_cs_lazlow_ponytail",
	"prop_cs_lazlow_shirt_01",
	"prop_cs_lazlow_shirt_01b",
	"prop_cs_leaf",
	"prop_cs_leg_chain_01",
	"prop_cs_lester_crate",
	"prop_cs_lipstick",
	"prop_cs_magazine",
	"prop_cs_marker_01",
	"prop_cs_meth_pipe",
	"prop_cs_milk_01",
	"prop_cs_mini_tv",
	"prop_cs_mopbucket_01",
	"prop_cs_mop_s",
	"prop_cs_mouse_01",
	"prop_cs_nail_file",
	"prop_cs_newspaper",
	"prop_cs_office_chair",
	"prop_cs_overalls_01",
	"prop_cs_package_01",
	"prop_cs_padlock",
	"prop_cs_pamphlet_01",
	"prop_cs_panel_01",
	"prop_cs_panties",
	"prop_cs_panties_02",
	"prop_cs_panties_03",
	"prop_cs_paper_cup",
	"prop_cs_para_ropebit",
	"prop_cs_para_ropes",
	"prop_cs_pebble",
	"prop_cs_pebble_02",
	"prop_cs_petrol_can",
	"prop_cs_phone_01",
	"prop_cs_photoframe_01",
	"prop_cs_pills",
	"prop_cs_plane_int_01",
	"prop_cs_planning_photo",
	"prop_cs_plant_01",
	"prop_cs_plate_01",
	"prop_cs_polaroid",
	"prop_cs_police_torch",
	"prop_cs_pour_tube",
	"prop_cs_power_cell",
	"prop_cs_power_cord",
	"prop_cs_protest_sign_01",
	"prop_cs_protest_sign_02",
	"prop_cs_protest_sign_02b",
	"prop_cs_protest_sign_03",
	"prop_cs_protest_sign_04a",
	"prop_cs_protest_sign_04b",
	"prop_cs_rage_statue_p1",
	"prop_cs_rage_statue_p2",
	"prop_cs_remote_01",
	"prop_cs_rolled_paper",
	"prop_cs_rope_tie_01",
	"prop_cs_rub_binbag_01",
	"prop_cs_rub_box_01",
	"prop_cs_rub_box_02",
	"prop_cs_r_business_card",
	"prop_cs_sack_01",
	"prop_cs_saucer_01",
	"prop_cs_sc1_11_gate",
	"prop_cs_scissors",
	"prop_cs_script_bottle",
	"prop_cs_script_bottle_01",
	"prop_cs_server_drive",
	"prop_cs_sheers",
	"prop_cs_shirt_01",
	"prop_cs_shopping_bag",
	"prop_cs_shot_glass",
	"prop_cs_silver_tray",
	"prop_cs_sink_filler",
	"prop_cs_sink_filler_02",
	"prop_cs_sink_filler_03",
	"prop_cs_sm_27_gate",
	"prop_cs_sol_glasses",
	"prop_cs_spray_can",
	"prop_cs_steak",
	"prop_cs_stock_book",
	"prop_cs_street_binbag_01",
	"prop_cs_street_card_01",
	"prop_cs_street_card_02",
	"prop_cs_sub_hook_01",
	"prop_cs_sub_rope_01",
	"prop_cs_swipe_card",
	"prop_cs_tablet",
	"prop_cs_tablet_02",
	"prop_cs_toaster",
	"prop_cs_trolley_01",
	"prop_cs_trowel",
	"prop_cs_truck_ladder",
	"prop_cs_tshirt_ball_01",
	"prop_cs_tv_stand",
	"prop_cs_t_shirt_pile",
	"prop_cs_valve",
	"prop_cs_vent_cover",
	"prop_cs_vial_01",
	"prop_cs_walkie_talkie",
	"prop_cs_walking_stick",
	"prop_cs_whiskey_bottle",
	"prop_cs_whiskey_bot_stop",
	"prop_cs_wrench",
	"prop_cub_door_lifeblurb",
	"prop_cub_lifeblurb",
	"prop_cuff_keys_01",
	"prop_cup_saucer_01",
	"prop_curl_bar_01",
	"prop_damdoor_01",
	"prop_dart_1",
	"prop_dart_2",
	"prop_dart_bd_01",
	"prop_dart_bd_cab_01",
	"prop_defilied_ragdoll_01",
	"prop_desert_iron_01",
	"prop_detergent_01a",
	"prop_detergent_01b",
	"prop_devin_box_01",
	"prop_devin_rope_01",
	"prop_diggerbkt_01",
	"prop_direct_chair_01",
	"prop_direct_chair_02",
	"prop_display_unit_01",
	"prop_display_unit_02",
	"prop_disp_cabinet_002",
	"prop_disp_cabinet_01",
	"prop_disp_razor_01",
	"prop_distantcar_day",
	"prop_distantcar_night",
	"prop_distantcar_truck",
	"prop_dj_deck_01",
	"prop_dj_deck_02",
	"prop_dock_bouy_1",
	"prop_dock_bouy_2",
	"prop_dock_bouy_3",
	"prop_dock_bouy_5",
	"prop_dock_crane_01",
	"prop_dock_crane_02",
	"prop_dock_crane_02_cab",
	"prop_dock_crane_02_hook",
	"prop_dock_crane_02_ld",
	"prop_dock_crane_04",
	"prop_dock_crane_lift",
	"prop_dock_float_1",
	"prop_dock_float_1b",
	"prop_dock_moor_01",
	"prop_dock_moor_04",
	"prop_dock_moor_05",
	"prop_dock_moor_06",
	"prop_dock_moor_07",
	"prop_dock_ropefloat",
	"prop_dock_ropetyre1",
	"prop_dock_ropetyre2",
	"prop_dock_ropetyre3",
	"prop_dock_rtg_01",
	"prop_dock_rtg_ld",
	"prop_dock_shippad",
	"prop_dock_sign_01",
	"prop_dock_woodpole1",
	"prop_dock_woodpole2",
	"prop_dock_woodpole3",
	"prop_dock_woodpole4",
	"prop_dock_woodpole5",
	"prop_dog_cage_01",
	"prop_dog_cage_02",
	"prop_dolly_01",
	"prop_dolly_02",
	"prop_donut_01",
	"prop_donut_02",
	"prop_donut_02b",
	"prop_door_01",
	"prop_door_balcony_frame",
	"prop_door_balcony_left",
	"prop_door_balcony_right",
	"prop_door_bell_01",
	"prop_double_grid_line",
	"prop_dress_disp_01",
	"prop_dress_disp_02",
	"prop_dress_disp_03",
	"prop_dress_disp_04",
	"prop_drop_armscrate_01",
	"prop_drop_armscrate_01b",
	"prop_drop_crate_01",
	"prop_drop_crate_01_set",
	"prop_drop_crate_01_set2",
	"prop_drug_burner",
	"prop_drug_package",
	"prop_drug_package_02",
	"prop_drywallpile_01",
	"prop_drywallpile_02",
	"prop_dt1_13_groundlight",
	"prop_dt1_13_walllightsource",
	"prop_dt1_20_mp_door_l",
	"prop_dt1_20_mp_door_r",
	"prop_dt1_20_mp_gar",
	"prop_ducktape_01",
	"prop_dummy_01",
	"prop_dummy_car",
	"prop_dummy_light",
	"prop_dummy_plane",
	"prop_dumpster_3a",
	"prop_dumpster_3step",
	"prop_dumpster_4a",
	"prop_dumpster_4b",
	"prop_d_balcony_l_light",
	"prop_d_balcony_r_light",
	"prop_ear_defenders_01",
	"prop_ecg_01",
	"prop_ecg_01_cable_01",
	"prop_ecg_01_cable_02",
	"prop_ecola_can",
	"prop_egg_clock_01",
	"prop_ejector_seat_01",
	"prop_elecbox_03a",
	"prop_elecbox_10",
	"prop_elecbox_12",
	"prop_elecbox_13",
	"prop_elecbox_14",
	"prop_elecbox_15",
	"prop_elecbox_16",
	"prop_elecbox_17",
	"prop_elecbox_18",
	"prop_elecbox_19",
	"prop_elecbox_20",
	"prop_elecbox_21",
	"prop_elecbox_22",
	"prop_elecbox_23",
	"prop_elecbox_24",
	"prop_elecbox_24b",
	"prop_elecbox_25",
	"prop_el_guitar_01",
	"prop_el_guitar_02",
	"prop_el_guitar_03",
	"prop_employee_month_01",
	"prop_employee_month_02",
	"prop_energy_drink",
	"prop_entityxf_covered",
	"prop_epsilon_door_l",
	"prop_epsilon_door_r",
	"prop_etricmotor_01",
	"prop_exer_bike_01",
	"prop_faceoffice_door_l",
	"prop_faceoffice_door_r",
	"prop_face_rag_01",
	"prop_facgate_01",
	"prop_facgate_01b",
	"prop_facgate_02pole",
	"prop_facgate_02_l",
	"prop_facgate_03post",
	"prop_facgate_03_l",
	"prop_facgate_03_ld_l",
	"prop_facgate_03_ld_r",
	"prop_facgate_03_r",
	"prop_facgate_04_l",
	"prop_facgate_04_r",
	"prop_facgate_05_r",
	"prop_facgate_05_r_dam_l1",
	"prop_facgate_05_r_l1",
	"prop_facgate_06_l",
	"prop_facgate_06_r",
	"prop_facgate_07",
	"prop_facgate_07b",
	"prop_facgate_08",
	"prop_facgate_08_frame",
	"prop_facgate_08_ld2",
	"prop_facgate_id1_27",
	"prop_fac_machine_02",
	"prop_fag_packet_01",
	"prop_fan_01",
	"prop_fan_palm_01a",
	"prop_fax_01",
	"prop_fbi3_coffee_table",
	"prop_fbibombbin",
	"prop_fbibombcupbrd",
	"prop_fbibombfile",
	"prop_fbibombplant",
	"prop_feeder1",
	"prop_feed_sack_01",
	"prop_feed_sack_02",
	"prop_fence_log_01",
	"prop_fence_log_02",
	"prop_ferris_car_01",
	"prop_ferris_car_01_lod1",
	"prop_ff_counter_01",
	"prop_ff_counter_02",
	"prop_ff_counter_03",
	"prop_ff_noodle_01",
	"prop_ff_noodle_02",
	"prop_ff_shelves_01",
	"prop_ff_sink_01",
	"prop_ff_sink_02",
	"prop_fib_badge",
	"prop_fib_broken_window",
	"prop_fib_skylight_piece",
	"prop_film_cam_01",
	"prop_fireescape_01a",
	"prop_fireescape_01b",
	"prop_fireescape_02a",
	"prop_fireescape_02b",
	"prop_fire_driser_1a",
	"prop_fire_driser_1b",
	"prop_fire_driser_2b",
	"prop_fire_driser_3b",
	"prop_fire_driser_4a",
	"prop_fire_driser_4b",
	"prop_fire_hosereel",
	"prop_fishing_rod_01",
	"prop_fishing_rod_02",
	"prop_fish_slice_01",
	"prop_flagpole_1a",
	"prop_flagpole_2a",
	"prop_flagpole_3a",
	"prop_flare_01",
	"prop_flare_01b",
	"prop_flash_unit",
	"prop_flatbed_strap",
	"prop_flatbed_strap_b",
	"prop_flatscreen_overlay",
	"prop_flattrailer_01a",
	"prop_flattruck_01a",
	"prop_fleeca_atm",
	"prop_flight_box_01",
	"prop_flight_box_insert",
	"prop_flight_box_insert2",
	"prop_flipchair_01",
	"prop_floor_duster_01",
	"prop_fncconstruc_02a",
	"prop_fnccorgm_05a",
	"prop_fnccorgm_05b",
	"prop_fnccorgm_06a",
	"prop_fnccorgm_06b",
	"prop_fnclink_01gate1",
	"prop_fnclink_02gate1",
	"prop_fnclink_02gate2",
	"prop_fnclink_02gate5",
	"prop_fnclink_02gate6_l",
	"prop_fnclink_02gate6_r",
	"prop_fnclink_02gate7",
	"prop_fnclink_03gate1",
	"prop_fnclink_03gate2",
	"prop_fnclink_03gate4",
	"prop_fnclink_03gate5",
	"prop_fnclink_04gate1",
	"prop_fnclink_04h_l2",
	"prop_fnclink_06gate2",
	"prop_fnclink_06gate3",
	"prop_fnclink_06gatepost",
	"prop_fnclink_07gate1",
	"prop_fnclink_07gate2",
	"prop_fnclink_07gate3",
	"prop_fnclink_09gate1",
	"prop_fnclink_10a",
	"prop_fnclink_10b",
	"prop_fnclink_10c",
	"prop_fnclink_10d",
	"prop_fnclink_10e",
	"prop_fnclog_01a",
	"prop_fnclog_01b",
	"prop_fncpeir_03a",
	"prop_fncres_02a",
	"prop_fncres_02b",
	"prop_fncres_02c",
	"prop_fncres_02d",
	"prop_fncres_02_gate1",
	"prop_fncres_03gate1",
	"prop_fncres_05c_l1",
	"prop_fncsec_01a",
	"prop_fncsec_01b",
	"prop_fncsec_01crnr",
	"prop_fncsec_01gate",
	"prop_fncsec_01pole",
	"prop_fncsec_02a",
	"prop_fncsec_02pole",
	"prop_fncsec_04a",
	"prop_fncwood_07gate1",
	"prop_fncwood_11a_l1",
	"prop_fncwood_16a",
	"prop_fncwood_16b",
	"prop_fncwood_16c",
	"prop_fncwood_18a",
	"prop_folded_polo_shirt",
	"prop_folder_01",
	"prop_folder_02",
	"prop_food_bin_01",
	"prop_food_bin_02",
	"prop_food_bs_bshelf",
	"prop_food_bs_cups01",
	"prop_food_bs_cups03",
	"prop_food_bs_soda_01",
	"prop_food_bs_soda_02",
	"prop_food_bs_tray_01",
	"prop_food_bs_tray_06",
	"prop_food_burg1",
	"prop_food_burg2",
	"prop_food_cb_bshelf",
	"prop_food_cb_burg01",
	"prop_food_cb_cups01",
	"prop_food_cb_donuts",
	"prop_food_cb_nugets",
	"prop_food_cb_soda_01",
	"prop_food_cb_soda_02",
	"prop_food_cb_tray_01",
	"prop_food_cups1",
	"prop_food_napkin_01",
	"prop_food_napkin_02",
	"prop_food_tray_01",
	"prop_food_van_01",
	"prop_food_van_02",
	"prop_forsalejr2",
	"prop_forsalejr3",
	"prop_forsalejr4",
	"prop_foundation_sponge",
	"prop_fountain1",
	"prop_fountain2",
	"prop_franklin_dl",
	"prop_freeweight_01",
	"prop_freeweight_02",
	"prop_fridge_01",
	"prop_fridge_03",
	"prop_front_seat_01",
	"prop_front_seat_02",
	"prop_front_seat_03",
	"prop_front_seat_04",
	"prop_front_seat_05",
	"prop_front_seat_06",
	"prop_front_seat_07",
	"prop_front_seat_row_01",
	"prop_fruitstand_b_nite",
	"prop_fruit_basket",
	"prop_ftowel_01",
	"prop_ftowel_07",
	"prop_ftowel_08",
	"prop_ftowel_10",
	"prop_f_b_insert_broken",
	"prop_f_duster_01_s",
	"prop_f_duster_02",
	"prop_gaffer_arm_bind",
	"prop_gaffer_arm_bind_cut",
	"prop_gaffer_leg_bind",
	"prop_gaffer_leg_bind_cut",
	"prop_gaffer_tape",
	"prop_gaffer_tape_strip",
	"prop_game_clock_01",
	"prop_game_clock_02",
	"prop_garden_dreamcatch_01",
	"prop_garden_edging_01",
	"prop_garden_edging_02",
	"prop_garden_zapper_01",
	"prop_gardnght_01",
	"prop_gar_door_01",
	"prop_gar_door_02",
	"prop_gar_door_03",
	"prop_gar_door_03_ld",
	"prop_gar_door_04",
	"prop_gar_door_05",
	"prop_gar_door_05_l",
	"prop_gar_door_05_r",
	"prop_gar_door_a_01",
	"prop_gar_door_plug",
	"prop_gascage01",
	"prop_gascyl_ramp_01",
	"prop_gascyl_ramp_door_01",
	"prop_gas_01",
	"prop_gas_02",
	"prop_gas_03",
	"prop_gas_04",
	"prop_gas_05",
	"prop_gas_grenade",
	"prop_gas_mask_hang_01",
	"prop_gatecom_02",
	"prop_gate_airport_01",
	"prop_gate_bridge_ld",
	"prop_gate_cult_01_l",
	"prop_gate_cult_01_r",
	"prop_gate_docks_ld",
	"prop_gate_farm_01a",
	"prop_gate_farm_post",
	"prop_gate_frame_01",
	"prop_gate_frame_02",
	"prop_gate_frame_04",
	"prop_gate_frame_05",
	"prop_gate_frame_06",
	"prop_gate_military_01",
	"prop_gate_prison_01",
	"prop_gate_tep_01_l",
	"prop_gate_tep_01_r",
	"prop_gazebo_03",
	"prop_gd_ch2_08",
	"prop_generator_02a",
	"prop_generator_03a",
	"prop_generator_04",
	"prop_ghettoblast_02",
	"prop_girder_01a",
	"prop_glasscutter_01",
	"prop_glass_suck_holder",
	"prop_glf_roller",
	"prop_glf_spreader",
	"prop_gold_bar",
	"prop_gold_cont_01",
	"prop_gold_cont_01b",
	"prop_gold_trolly",
	"prop_gold_trolly_full",
	"prop_gold_trolly_strap_01",
	"prop_golf_bag_01",
	"prop_golf_bag_01b",
	"prop_golf_bag_01c",
	"prop_golf_ball",
	"prop_golf_ball_p2",
	"prop_golf_ball_p3",
	"prop_golf_ball_p4",
	"prop_golf_ball_tee",
	"prop_golf_driver",
	"prop_golf_iron_01",
	"prop_golf_marker_01",
	"prop_golf_pitcher_01",
	"prop_golf_putter_01",
	"prop_golf_tee",
	"prop_golf_wood_01",
	"prop_grain_hopper",
	"prop_grapes_01",
	"prop_grapes_02",
	"prop_grass_dry_02",
	"prop_grass_dry_03",
	"prop_gravestones_01a",
	"prop_gravestones_02a",
	"prop_gravestones_03a",
	"prop_gravestones_04a",
	"prop_gravestones_05a",
	"prop_gravestones_06a",
	"prop_gravestones_07a",
	"prop_gravestones_08a",
	"prop_gravestones_09a",
	"prop_gravestones_10a",
	"prop_gravetomb_01a",
	"prop_gravetomb_02a",
	"prop_griddle_01",
	"prop_griddle_02",
	"prop_grumandoor_l",
	"prop_grumandoor_r",
	"prop_gshotsensor_01",
	"prop_gun_case_01",
	"prop_gun_case_02",
	"prop_gun_frame",
	"prop_hacky_sack_01",
	"prop_handdry_01",
	"prop_handdry_02",
	"prop_handrake",
	"prop_handtowels",
	"prop_hand_toilet",
	"prop_hanger_door_1",
	"prop_hard_hat_01",
	"prop_hat_box_01",
	"prop_hat_box_02",
	"prop_hat_box_03",
	"prop_hat_box_04",
	"prop_hat_box_05",
	"prop_hat_box_06",
	"prop_haybailer_01",
	"prop_haybale_01",
	"prop_haybale_02",
	"prop_haybale_stack_01",
	"prop_hd_seats_01",
	"prop_headphones_01",
	"prop_headset_01",
	"prop_hedge_trimmer_01",
	"prop_helipad_01",
	"prop_helipad_02",
	"prop_henna_disp_01",
	"prop_henna_disp_02",
	"prop_henna_disp_03",
	"prop_hifi_01",
	"prop_hobo_stove_01",
	"prop_hockey_bag_01",
	"prop_hole_plug_01",
	"prop_holster_01",
	"prop_homeless_matress_01",
	"prop_homeless_matress_02",
	"prop_hose_1",
	"prop_hose_2",
	"prop_hose_3",
	"prop_hose_nozzle",
	"prop_hospitaldoors_start",
	"prop_hospital_door_l",
	"prop_hospital_door_r",
	"prop_hotel_clock_01",
	"prop_hotel_trolley",
	"prop_hottub2",
	"prop_huf_rag_01",
	"prop_huge_display_01",
	"prop_huge_display_02",
	"prop_hunterhide",
	"prop_hw1_03_gardoor_01",
	"prop_hw1_04_door_l1",
	"prop_hw1_04_door_r1",
	"prop_hw1_23_door",
	"prop_hwbowl_pseat_6x1",
	"prop_hwbowl_seat_01",
	"prop_hwbowl_seat_02",
	"prop_hwbowl_seat_03",
	"prop_hwbowl_seat_03b",
	"prop_hwbowl_seat_6x6",
	"prop_hydro_platform_01",
	"prop_ice_box_01",
	"prop_ice_box_01_l1",
	"prop_ice_cube_01",
	"prop_ice_cube_02",
	"prop_ice_cube_03",
	"prop_id2_11_gdoor",
	"prop_id2_20_clock",
	"prop_idol_01",
	"prop_idol_01_error",
	"prop_idol_case",
	"prop_idol_case_01",
	"prop_idol_case_02",
	"prop_id_21_gardoor_01",
	"prop_id_21_gardoor_02",
	"prop_indus_meet_door_l",
	"prop_indus_meet_door_r",
	"prop_ind_barge_01",
	"prop_ind_barge_02",
	"prop_ind_coalcar_01",
	"prop_ind_coalcar_02",
	"prop_ind_coalcar_03",
	"prop_ind_conveyor_01",
	"prop_ind_conveyor_02",
	"prop_ind_conveyor_04",
	"prop_ind_crusher",
	"prop_ind_deiseltank",
	"prop_ind_light_01a",
	"prop_ind_light_01b",
	"prop_ind_light_01c",
	"prop_ind_mech_01c",
	"prop_ind_mech_02a",
	"prop_ind_mech_02b",
	"prop_ind_mech_03a",
	"prop_ind_mech_04a",
	"prop_ind_oldcrane",
	"prop_ind_washer_02",
	"prop_inflatearch_01",
	"prop_inflategate_01",
	"prop_ing_camera_01",
	"prop_ing_crowbar",
	"prop_inhaler_01",
	"prop_int_gate01",
	"prop_in_tray_01",
	"prop_irish_sign_01",
	"prop_irish_sign_02",
	"prop_irish_sign_03",
	"prop_irish_sign_04",
	"prop_irish_sign_05",
	"prop_irish_sign_06",
	"prop_irish_sign_07",
	"prop_irish_sign_08",
	"prop_irish_sign_09",
	"prop_irish_sign_10",
	"prop_irish_sign_11",
	"prop_irish_sign_12",
	"prop_irish_sign_13",
	"prop_iron_01",
	"prop_jb700_covered",
	"prop_jeans_01",
	"prop_jetski_ramp_01",
	"prop_jet_bloodsplat_01",
	"prop_jewel_02a",
	"prop_jewel_02b",
	"prop_jewel_02c",
	"prop_jewel_03a",
	"prop_jewel_03b",
	"prop_jewel_04a",
	"prop_jewel_04b",
	"prop_jewel_pickup_new_01",
	"prop_juice_dispenser",
	"prop_juice_pool_01",
	"prop_jukebox_01",
	"prop_jukebox_02",
	"prop_jyard_block_01a",
	"prop_j_disptray_01",
	"prop_j_disptray_01b",
	"prop_j_disptray_01_dam",
	"prop_j_disptray_02",
	"prop_j_disptray_02_dam",
	"prop_j_disptray_03",
	"prop_j_disptray_03_dam",
	"prop_j_disptray_04",
	"prop_j_disptray_04b",
	"prop_j_disptray_05",
	"prop_j_disptray_05b",
	"prop_j_heist_pic_01",
	"prop_j_heist_pic_02",
	"prop_j_heist_pic_03",
	"prop_j_heist_pic_04",
	"prop_j_neck_disp_01",
	"prop_j_neck_disp_02",
	"prop_j_neck_disp_03",
	"prop_kayak_01",
	"prop_kayak_01b",
	"prop_kebab_grill",
	"prop_keg_01",
	"prop_kettle",
	"prop_kettle_01",
	"prop_keyboard_01a",
	"prop_keyboard_01b",
	"prop_kino_light_01",
	"prop_kino_light_03",
	"prop_kitch_juicer",
	"prop_kitch_pot_fry",
	"prop_kitch_pot_huge",
	"prop_kitch_pot_lrg",
	"prop_kitch_pot_lrg2",
	"prop_kitch_pot_med",
	"prop_kitch_pot_sm",
	"prop_knife",
	"prop_knife_stand",
	"prop_kt1_06_door_l",
	"prop_kt1_06_door_r",
	"prop_kt1_10_mpdoor_l",
	"prop_kt1_10_mpdoor_r",
	"prop_ladel",
	"prop_laptop_02_closed",
	"prop_laptop_jimmy",
	"prop_laptop_lester",
	"prop_laptop_lester2",
	"prop_large_gold",
	"prop_large_gold_alt_a",
	"prop_large_gold_alt_b",
	"prop_large_gold_alt_c",
	"prop_large_gold_empty",
	"prop_lawnmower_01",
	"prop_ld_alarm_01",
	"prop_ld_alarm_01_dam",
	"prop_ld_alarm_alert",
	"prop_ld_ammo_pack_01",
	"prop_ld_ammo_pack_02",
	"prop_ld_ammo_pack_03",
	"prop_ld_armour",
	"prop_ld_balcfnc_01a",
	"prop_ld_balcfnc_02a",
	"prop_ld_balcfnc_02c",
	"prop_ld_bankdoors_02",
	"prop_ld_barrier_01",
	"prop_ld_binbag_01",
	"prop_ld_bomb",
	"prop_ld_bomb_01",
	"prop_ld_bomb_01_open",
	"prop_ld_bomb_anim",
	"prop_ld_cable",
	"prop_ld_cable_tie_01",
	"prop_ld_can_01",
	"prop_ld_case_01",
	"prop_ld_case_01_lod",
	"prop_ld_case_01_s",
	"prop_ld_contact_card",
	"prop_ld_container",
	"prop_ld_contain_dl",
	"prop_ld_contain_dl2",
	"prop_ld_contain_dr",
	"prop_ld_contain_dr2",
	"prop_ld_crate_01",
	"prop_ld_crate_lid_01",
	"prop_ld_crocclips01",
	"prop_ld_crocclips02",
	"prop_ld_dummy_rope",
	"prop_ld_fags_01",
	"prop_ld_fags_02",
	"prop_ld_fan_01",
	"prop_ld_fan_01_old",
	"prop_ld_faucet",
	"prop_ld_ferris_wheel",
	"prop_ld_fireaxe",
	"prop_ld_flow_bottle",
	"prop_ld_fragwall_01a",
	"prop_ld_garaged_01",
	"prop_ld_gold_tooth",
	"prop_ld_greenscreen_01",
	"prop_ld_handbag",
	"prop_ld_handbag_s",
	"prop_ld_hat_01",
	"prop_ld_haybail",
	"prop_ld_hdd_01",
	"prop_ld_health_pack",
	"prop_ld_hook",
	"prop_ld_int_safe_01",
	"prop_ld_jail_door",
	"prop_ld_jeans_01",
	"prop_ld_jeans_02",
	"prop_ld_jerrycan_01",
	"prop_ld_keypad_01",
	"prop_ld_keypad_01b",
	"prop_ld_keypad_01b_lod",
	"prop_ld_lap_top",
	"prop_ld_monitor_01",
	"prop_ld_peep_slider",
	"prop_ld_pipe_single_01",
	"prop_ld_planning_pin_01",
	"prop_ld_planning_pin_02",
	"prop_ld_planning_pin_03",
	"prop_ld_purse_01",
	"prop_ld_purse_01_lod",
	"prop_ld_rail_01",
	"prop_ld_rail_02",
	"prop_ld_rope_t",
	"prop_ld_rubble_01",
	"prop_ld_rubble_02",
	"prop_ld_rubble_03",
	"prop_ld_rubble_04",
	"prop_ld_rub_binbag_01",
	"prop_ld_scrap",
	"prop_ld_shirt_01",
	"prop_ld_shoe_01",
	"prop_ld_shoe_02",
	"prop_ld_shovel",
	"prop_ld_shovel_dirt",
	"prop_ld_snack_01",
	"prop_ld_suitcase_01",
	"prop_ld_suitcase_02",
	"prop_ld_test_01",
	"prop_ld_toilet_01",
	"prop_ld_tooth",
	"prop_ld_tshirt_01",
	"prop_ld_tshirt_02",
	"prop_ld_vault_door",
	"prop_ld_wallet_01",
	"prop_ld_wallet_01_s",
	"prop_ld_wallet_02",
	"prop_ld_wallet_pickup",
	"prop_ld_w_me_machette",
	"prop_leaf_blower_01",
	"prop_lectern_01",
	"prop_letterbox_04",
	"prop_lev_crate_01",
	"prop_lev_des_barge_01",
	"prop_lev_des_barge_02",
	"prop_lifeblurb_01",
	"prop_lifeblurb_01b",
	"prop_lifeblurb_02",
	"prop_lifeblurb_02b",
	"prop_life_ring_02",
	"prop_lift_overlay_01",
	"prop_lift_overlay_02",
	"prop_litter_picker",
	"prop_loggneon",
	"prop_logpile_05",
	"prop_logpile_06",
	"prop_logpile_06b",
	"prop_logpile_07",
	"prop_logpile_07b",
	"prop_log_01",
	"prop_log_02",
	"prop_log_03",
	"prop_loose_rag_01",
	"prop_lrggate_01c_l",
	"prop_lrggate_01c_r",
	"prop_lrggate_01_l",
	"prop_lrggate_01_pst",
	"prop_lrggate_01_r",
	"prop_lrggate_02_ld",
	"prop_lrggate_03a",
	"prop_lrggate_03b",
	"prop_lrggate_03b_ld",
	"prop_lrggate_04a",
	"prop_lrggate_05a",
	"prop_lrggate_06a",
	"prop_luggage_01a",
	"prop_luggage_02a",
	"prop_luggage_03a",
	"prop_luggage_04a",
	"prop_luggage_05a",
	"prop_luggage_06a",
	"prop_luggage_07a",
	"prop_luggage_08a",
	"prop_luggage_09a",
	"prop_magenta_door",
	"prop_makeup_trail_01",
	"prop_makeup_trail_02",
	"prop_map_door_01",
	"prop_mast_01",
	"prop_mat_box",
	"prop_mb_cargo_01a",
	"prop_mb_cargo_02a",
	"prop_mb_cargo_03a",
	"prop_mb_cargo_04a",
	"prop_mb_cargo_04b",
	"prop_mb_crate_01a",
	"prop_mb_crate_01a_set",
	"prop_mb_crate_01b",
	"prop_mb_hesco_06",
	"prop_mb_ordnance_01",
	"prop_mb_ordnance_03",
	"prop_mb_sandblock_01",
	"prop_mb_sandblock_02",
	"prop_mb_sandblock_03",
	"prop_mb_sandblock_04",
	"prop_mb_sandblock_05",
	"prop_medal_01",
	"prop_medstation_02",
	"prop_medstation_03",
	"prop_medstation_04",
	"prop_med_bag_01",
	"prop_med_bag_01b",
	"prop_med_jet_01",
	"prop_megaphone_01",
	"prop_mem_candle_04",
	"prop_mem_candle_05",
	"prop_mem_candle_06",
	"prop_mem_reef_01",
	"prop_mem_reef_02",
	"prop_mem_reef_03",
	"prop_mem_teddy_01",
	"prop_mem_teddy_02",
	"prop_metalfoodjar_01",
	"prop_metal_plates01",
	"prop_metal_plates02",
	"prop_meth_bag_01",
	"prop_michaels_credit_tv",
	"prop_michael_backpack",
	"prop_michael_balaclava",
	"prop_michael_door",
	"prop_michael_sec_id",
	"prop_microphone_02",
	"prop_microwave_1",
	"prop_micro_01",
	"prop_micro_02",
	"prop_micro_cs_01",
	"prop_micro_cs_01_door",
	"prop_military_pickup_01",
	"prop_mil_crate_01",
	"prop_mil_crate_02",
	"prop_minigun_01",
	"prop_mobile_mast_1",
	"prop_mobile_mast_2",
	"prop_money_bag_01",
	"prop_monitor_01c",
	"prop_monitor_01d",
	"prop_monitor_02",
	"prop_monitor_03b",
	"prop_motel_door_09",
	"prop_mouse_01",
	"prop_mouse_01a",
	"prop_mouse_01b",
	"prop_mouse_02",
	"prop_movie_rack",
	"prop_mp3_dock",
	"prop_mp_arrow_barrier_01",
	"prop_mp_barrier_01",
	"prop_mp_barrier_01b",
	"prop_mp_barrier_02",
	"prop_mp_barrier_02b",
	"prop_mp_base_marker",
	"prop_mp_boost_01",
	"prop_mp_cant_place_lrg",
	"prop_mp_cant_place_med",
	"prop_mp_cant_place_sm",
	"prop_mp_cone_01",
	"prop_mp_cone_02",
	"prop_mp_cone_03",
	"prop_mp_cone_04",
	"prop_mp_drug_package",
	"prop_mp_drug_pack_blue",
	"prop_mp_drug_pack_red",
	"prop_mp_icon_shad_lrg",
	"prop_mp_icon_shad_med",
	"prop_mp_icon_shad_sm",
	"prop_mp_max_out_lrg",
	"prop_mp_max_out_med",
	"prop_mp_max_out_sm",
	"prop_mp_num_0",
	"prop_mp_num_1",
	"prop_mp_num_2",
	"prop_mp_num_3",
	"prop_mp_num_4",
	"prop_mp_num_5",
	"prop_mp_num_6",
	"prop_mp_num_7",
	"prop_mp_num_8",
	"prop_mp_num_9",
	"prop_mp_placement",
	"prop_mp_placement_lrg",
	"prop_mp_placement_maxd",
	"prop_mp_placement_med",
	"prop_mp_placement_red",
	"prop_mp_placement_sm",
	"prop_mp_ramp_01",
	"prop_mp_ramp_02",
	"prop_mp_ramp_03",
	"prop_mp_repair",
	"prop_mp_repair_01",
	"prop_mp_respawn_02",
	"prop_mp_rocket_01",
	"prop_mp_spike_01",
	"prop_mr_rasberryclean",
	"prop_mr_raspberry_01",
	"prop_muscle_bench_01",
	"prop_muscle_bench_02",
	"prop_muscle_bench_03",
	"prop_muscle_bench_04",
	"prop_muscle_bench_05",
	"prop_muscle_bench_06",
	"prop_muster_wboard_01",
	"prop_muster_wboard_02",
	"prop_m_pack_int_01",
	"prop_necklace_board",
	"prop_news_disp_02a_s",
	"prop_new_drug_pack_01",
	"prop_nigel_bag_pickup",
	"prop_night_safe_01",
	"prop_notepad_01",
	"prop_notepad_02",
	"prop_novel_01",
	"prop_npc_phone",
	"prop_npc_phone_02",
	"prop_office_alarm_01",
	"prop_office_desk_01",
	"prop_offroad_bale01",
	"prop_offroad_bale02_l1_frag_",
	"prop_offroad_barrel01",
	"prop_offroad_tyres01",
	"prop_off_chair_01",
	"prop_off_chair_03",
	"prop_off_chair_04",
	"prop_off_chair_04b",
	"prop_off_chair_04_s",
	"prop_off_chair_05",
	"prop_off_phone_01",
	"prop_oiltub_01",
	"prop_oiltub_02",
	"prop_oiltub_03",
	"prop_oiltub_05",
	"prop_oiltub_06",
	"prop_oil_derrick_01",
	"prop_oil_guage_01",
	"prop_oil_spool_02",
	"prop_oil_valve_01",
	"prop_oil_valve_02",
	"prop_oil_wellhead_01",
	"prop_oil_wellhead_03",
	"prop_oil_wellhead_04",
	"prop_oil_wellhead_05",
	"prop_oil_wellhead_06",
	"prop_oldplough1",
	"prop_old_boot",
	"prop_old_churn_01",
	"prop_old_churn_02",
	"prop_old_deck_chair",
	"prop_old_deck_chair_02",
	"prop_old_farm_01",
	"prop_old_farm_02",
	"prop_old_wood_chair",
	"prop_old_wood_chair_lod",
	"prop_orang_can_01",
	"prop_outdoor_fan_01",
	"prop_out_door_speaker",
	"prop_overalls_01",
	"prop_owl_totem_01",
	"prop_paints_can01",
	"prop_paints_can02",
	"prop_paints_can03",
	"prop_paints_can04",
	"prop_paints_can05",
	"prop_paints_can06",
	"prop_paints_can07",
	"prop_paint_brush01",
	"prop_paint_brush02",
	"prop_paint_brush03",
	"prop_paint_brush04",
	"prop_paint_brush05",
	"prop_paint_roller",
	"prop_paint_spray01a",
	"prop_paint_spray01b",
	"prop_paint_stepl01",
	"prop_paint_stepl01b",
	"prop_paint_stepl02",
	"prop_paint_tray",
	"prop_paint_wpaper01",
	"prop_pallettruck_01",
	"prop_palm_fan_02_a",
	"prop_palm_fan_02_b",
	"prop_palm_fan_03_a",
	"prop_palm_fan_03_b",
	"prop_palm_fan_03_c",
	"prop_palm_fan_03_d",
	"prop_palm_fan_04_a",
	"prop_palm_fan_04_b",
	"prop_palm_fan_04_c",
	"prop_palm_fan_04_d",
	"prop_palm_huge_01a",
	"prop_palm_huge_01b",
	"prop_palm_med_01a",
	"prop_palm_med_01b",
	"prop_palm_med_01c",
	"prop_palm_med_01d",
	"prop_palm_sm_01a",
	"prop_palm_sm_01d",
	"prop_palm_sm_01e",
	"prop_palm_sm_01f",
	"prop_paper_bag_01",
	"prop_paper_bag_small",
	"prop_paper_ball",
	"prop_paper_box_01",
	"prop_paper_box_02",
	"prop_paper_box_03",
	"prop_paper_box_04",
	"prop_paper_box_05",
	"prop_pap_camera_01",
	"prop_parachute",
	"prop_parapack_01",
	"prop_parasol_01",
	"prop_parasol_01_b",
	"prop_parasol_01_c",
	"prop_parasol_01_down",
	"prop_parasol_02",
	"prop_parasol_02_b",
	"prop_parasol_02_c",
	"prop_parasol_03",
	"prop_parasol_03_b",
	"prop_parasol_03_c",
	"prop_parasol_04e",
	"prop_parasol_04e_lod1",
	"prop_parasol_bh_48",
	"prop_parking_sign_06",
	"prop_parking_sign_07",
	"prop_parking_sign_1",
	"prop_parking_sign_2",
	"prop_parking_wand_01",
	"prop_park_ticket_01",
	"prop_partsbox_01",
	"prop_passport_01",
	"prop_patio_heater_01",
	"prop_patio_lounger1",
	"prop_patio_lounger1b",
	"prop_patio_lounger1_table",
	"prop_patio_lounger_2",
	"prop_patio_lounger_3",
	"prop_patriotneon",
	"prop_paynspray_door_l",
	"prop_paynspray_door_r",
	"prop_pc_01a",
	"prop_pc_02a",
	"prop_peanut_bowl_01",
	"prop_ped_pic_01",
	"prop_ped_pic_01_sm",
	"prop_ped_pic_02",
	"prop_ped_pic_02_sm",
	"prop_ped_pic_03",
	"prop_ped_pic_03_sm",
	"prop_ped_pic_04",
	"prop_ped_pic_04_sm",
	"prop_ped_pic_05",
	"prop_ped_pic_05_sm",
	"prop_ped_pic_06",
	"prop_ped_pic_06_sm",
	"prop_ped_pic_07",
	"prop_ped_pic_07_sm",
	"prop_ped_pic_08",
	"prop_ped_pic_08_sm",
	"prop_pencil_01",
	"prop_pharm_sign_01",
	"prop_phonebox_05a",
	"prop_phone_ing",
	"prop_phone_ing_02",
	"prop_phone_ing_03",
	"prop_phone_overlay_01",
	"prop_phone_overlay_02",
	"prop_phone_overlay_anim",
	"prop_phone_proto",
	"prop_phone_proto_back",
	"prop_phone_proto_battery",
	"prop_picnictable_02",
	"prop_piercing_gun",
	"prop_pier_kiosk_01",
	"prop_pier_kiosk_02",
	"prop_pier_kiosk_03",
	"prop_pile_dirt_01",
	"prop_pile_dirt_02",
	"prop_pile_dirt_03",
	"prop_pile_dirt_04",
	"prop_pile_dirt_06",
	"prop_pile_dirt_07",
	"prop_ping_pong",
	"prop_pipes_01a",
	"prop_pipes_01b",
	"prop_pipes_03b",
	"prop_pipes_04a",
	"prop_pipes_05a",
	"prop_pipes_conc_01",
	"prop_pipes_conc_02",
	"prop_pipe_single_01",
	"prop_pistol_holster",
	"prop_pitcher_01_cs",
	"prop_pizza_box_01",
	"prop_pizza_box_02",
	"prop_pizza_oven_01",
	"prop_planer_01",
	"prop_plant_01a",
	"prop_plant_01b",
	"prop_plant_base_01",
	"prop_plant_base_02",
	"prop_plant_base_03",
	"prop_plant_cane_01a",
	"prop_plant_cane_01b",
	"prop_plant_cane_02a",
	"prop_plant_cane_02b",
	"prop_plant_clover_01",
	"prop_plant_clover_02",
	"prop_plant_fern_01a",
	"prop_plant_fern_01b",
	"prop_plant_fern_02a",
	"prop_plant_fern_02b",
	"prop_plant_fern_02c",
	"prop_plant_flower_01",
	"prop_plant_flower_02",
	"prop_plant_flower_03",
	"prop_plant_flower_04",
	"prop_plant_group_01",
	"prop_plant_group_02",
	"prop_plant_group_03",
	"prop_plant_group_04",
	"prop_plant_group_05",
	"prop_plant_group_05b",
	"prop_plant_group_05c",
	"prop_plant_group_05d",
	"prop_plant_group_06a",
	"prop_plant_group_06b",
	"prop_plant_group_06c",
	"prop_plant_int_02a",
	"prop_plant_int_02b",
	"prop_plant_int_05a",
	"prop_plant_int_05b",
	"prop_plant_int_06a",
	"prop_plant_int_06b",
	"prop_plant_int_06c",
	"prop_plant_paradise",
	"prop_plant_paradise_b",
	"prop_plastic_cup_02",
	"prop_plas_barier_01a",
	"prop_plate_04",
	"prop_plate_stand_01",
	"prop_plate_warmer",
	"prop_player_gasmask",
	"prop_player_phone_01",
	"prop_player_phone_02",
	"prop_pliers_01",
	"prop_plywoodpile_01a",
	"prop_plywoodpile_01b",
	"prop_podium_mic",
	"prop_police_door_l",
	"prop_police_door_l_dam",
	"prop_police_door_r",
	"prop_police_door_r_dam",
	"prop_police_door_surround",
	"prop_police_phone",
	"prop_police_radio_handset",
	"prop_police_radio_main",
	"prop_poly_bag_01",
	"prop_poly_bag_money",
	"prop_poolball_1",
	"prop_poolball_10",
	"prop_poolball_11",
	"prop_poolball_12",
	"prop_poolball_13",
	"prop_poolball_14",
	"prop_poolball_15",
	"prop_poolball_2",
	"prop_poolball_3",
	"prop_poolball_4",
	"prop_poolball_5",
	"prop_poolball_6",
	"prop_poolball_7",
	"prop_poolball_8",
	"prop_poolball_9",
	"prop_poolball_cue",
	"prop_poolskimmer",
	"prop_pooltable_02",
	"prop_pooltable_3b",
	"prop_pool_ball_01",
	"prop_pool_cue",
	"prop_pool_rack_01",
	"prop_pool_rack_02",
	"prop_pool_tri",
	"prop_porn_mag_01",
	"prop_porn_mag_02",
	"prop_porn_mag_03",
	"prop_porn_mag_04",
	"prop_portable_hifi_01",
	"prop_portacabin01",
	"prop_portasteps_01",
	"prop_portasteps_02",
	"prop_postcard_rack",
	"prop_poster_tube_01",
	"prop_poster_tube_02",
	"prop_postit_drive",
	"prop_postit_gun",
	"prop_postit_it",
	"prop_postit_lock",
	"prop_potatodigger",
	"prop_pot_01",
	"prop_pot_02",
	"prop_pot_03",
	"prop_pot_04",
	"prop_pot_05",
	"prop_pot_06",
	"prop_pot_plant_02a",
	"prop_pot_plant_02b",
	"prop_pot_plant_02c",
	"prop_pot_plant_02d",
	"prop_pot_plant_03a",
	"prop_pot_plant_04a",
	"prop_pot_plant_05d_l1",
	"prop_pot_plant_bh1",
	"prop_pot_rack",
	"prop_power_cell",
	"prop_power_cord_01",
	"prop_premier_fence_01",
	"prop_premier_fence_02",
	"prop_printer_01",
	"prop_printer_02",
	"prop_pris_bars_01",
	"prop_pris_bench_01",
	"prop_pris_door_01_l",
	"prop_pris_door_01_r",
	"prop_pris_door_02",
	"prop_pris_door_03",
	"prop_prlg_gravestone_05a_l1",
	"prop_prlg_gravestone_06a",
	"prop_projector_overlay",
	"prop_prologue_phone",
	"prop_prop_tree_01",
	"prop_prop_tree_02",
	"prop_protest_sign_01",
	"prop_protest_table_01",
	"prop_prototype_minibomb",
	"prop_proxy_chateau_table",
	"prop_punch_bag_l",
	"prop_pylon_01",
	"prop_pylon_02",
	"prop_pylon_03",
	"prop_pylon_04",
	"prop_p_jack_03_col",
	"prop_p_spider_01a",
	"prop_p_spider_01c",
	"prop_p_spider_01d",
	"prop_ql_revolving_door",
	"prop_quad_grid_line",
	"prop_radiomast01",
	"prop_radiomast02",
	"prop_rad_waste_barrel_01",
	"prop_ragganeon",
	"prop_rag_01",
	"prop_railsleepers01",
	"prop_railsleepers02",
	"prop_railstack01",
	"prop_railstack02",
	"prop_railstack03",
	"prop_railstack04",
	"prop_railstack05",
	"prop_rail_boxcar",
	"prop_rail_boxcar2",
	"prop_rail_boxcar3",
	"prop_rail_boxcar4",
	"prop_rail_boxcar5",
	"prop_rail_boxcar5_d",
	"prop_rail_buffer_01",
	"prop_rail_buffer_02",
	"prop_rail_controller",
	"prop_rail_crane_01",
	"prop_rail_points01",
	"prop_rail_points02",
	"prop_rail_sigbox01",
	"prop_rail_sigbox02",
	"prop_rail_signals02",
	"prop_rail_tankcar",
	"prop_rail_tankcar2",
	"prop_rail_tankcar3",
	"prop_rail_wellcar",
	"prop_rail_wellcar2",
	"prop_range_target_01",
	"prop_range_target_02",
	"prop_range_target_03",
	"prop_rebar_pile01",
	"prop_recyclebin_02a",
	"prop_recyclebin_02b",
	"prop_recyclebin_02_c",
	"prop_recyclebin_02_d",
	"prop_recyclebin_03_a",
	"prop_recyclebin_04_a",
	"prop_recyclebin_04_b",
	"prop_recyclebin_05_a",
	"prop_ret_door",
	"prop_ret_door_02",
	"prop_ret_door_03",
	"prop_ret_door_04",
	"prop_rf_conc_pillar",
	"prop_riding_crop_01",
	"prop_riot_shield",
	"prop_rio_del_01",
	"prop_roadcone01a",
	"prop_roadcone01b",
	"prop_roadcone01c",
	"prop_roadcone02a",
	"prop_roadcone02b",
	"prop_roadcone02c",
	"prop_roadheader_01",
	"prop_rock_1_a",
	"prop_rock_1_b",
	"prop_rock_1_c",
	"prop_rock_1_d",
	"prop_rock_1_e",
	"prop_rock_1_f",
	"prop_rock_1_g",
	"prop_rock_1_h",
	"prop_rock_1_i",
	"prop_rock_2_a",
	"prop_rock_2_c",
	"prop_rock_2_d",
	"prop_rock_2_f",
	"prop_rock_2_g",
	"prop_rock_3_a",
	"prop_rock_3_b",
	"prop_rock_3_c",
	"prop_rock_3_d",
	"prop_rock_3_e",
	"prop_rock_3_f",
	"prop_rock_3_g",
	"prop_rock_3_h",
	"prop_rock_3_i",
	"prop_rock_3_j",
	"prop_rock_4_c",
	"prop_rock_4_d",
	"prop_rock_chair_01",
	"prop_rolled_sock_01",
	"prop_rolled_sock_02",
	"prop_rolled_yoga_mat",
	"prop_roller_car_01",
	"prop_roller_car_02",
	"prop_ron_door_01",
	"prop_roofpipe_01",
	"prop_roofpipe_02",
	"prop_roofpipe_03",
	"prop_roofpipe_04",
	"prop_roofpipe_05",
	"prop_roofpipe_06",
	"prop_roofvent_011a",
	"prop_roofvent_01a",
	"prop_roofvent_01b",
	"prop_roofvent_02a",
	"prop_roofvent_02b",
	"prop_roofvent_03a",
	"prop_roofvent_04a",
	"prop_roofvent_05a",
	"prop_roofvent_05b",
	"prop_roofvent_07a",
	"prop_roofvent_08a",
	"prop_roofvent_09a",
	"prop_roofvent_10a",
	"prop_roofvent_10b",
	"prop_roofvent_11b",
	"prop_roofvent_11c",
	"prop_roofvent_12a",
	"prop_roofvent_13a",
	"prop_roofvent_15a",
	"prop_roofvent_16a",
	"prop_rope_family_3",
	"prop_rope_hook_01",
	"prop_roundbailer01",
	"prop_roundbailer02",
	"prop_rub_bike_01",
	"prop_rub_bike_02",
	"prop_rub_bike_03",
	"prop_rub_binbag_sd_01",
	"prop_rub_binbag_sd_02",
	"prop_rub_busdoor_01",
	"prop_rub_busdoor_02",
	"prop_rub_buswreck_01",
	"prop_rub_buswreck_03",
	"prop_rub_buswreck_06",
	"prop_rub_cabinet",
	"prop_rub_cabinet01",
	"prop_rub_cabinet02",
	"prop_rub_cabinet03",
	"prop_rub_cage01a",
	"prop_rub_carpart_02",
	"prop_rub_carpart_03",
	"prop_rub_carpart_04",
	"prop_rub_chassis_01",
	"prop_rub_chassis_02",
	"prop_rub_chassis_03",
	"prop_rub_cont_01a",
	"prop_rub_cont_01b",
	"prop_rub_cont_01c",
	"prop_rub_flotsam_01",
	"prop_rub_flotsam_02",
	"prop_rub_flotsam_03",
	"prop_rub_frklft",
	"prop_rub_litter_01",
	"prop_rub_litter_02",
	"prop_rub_litter_03",
	"prop_rub_litter_03b",
	"prop_rub_litter_03c",
	"prop_rub_litter_04",
	"prop_rub_litter_04b",
	"prop_rub_litter_05",
	"prop_rub_litter_06",
	"prop_rub_litter_07",
	"prop_rub_litter_09",
	"prop_rub_litter_8",
	"prop_rub_matress_01",
	"prop_rub_matress_02",
	"prop_rub_matress_03",
	"prop_rub_matress_04",
	"prop_rub_monitor",
	"prop_rub_pile_01",
	"prop_rub_pile_02",
	"prop_rub_planks_01",
	"prop_rub_planks_02",
	"prop_rub_planks_03",
	"prop_rub_planks_04",
	"prop_rub_railwreck_1",
	"prop_rub_railwreck_2",
	"prop_rub_railwreck_3",
	"prop_rub_scrap_02",
	"prop_rub_scrap_03",
	"prop_rub_scrap_04",
	"prop_rub_scrap_05",
	"prop_rub_scrap_06",
	"prop_rub_scrap_07",
	"prop_rub_stool",
	"prop_rub_sunktyre",
	"prop_rub_t34",
	"prop_rub_trainers_01",
	"prop_rub_trolley01a",
	"prop_rub_trolley02a",
	"prop_rub_trolley03a",
	"prop_rub_trukwreck_1",
	"prop_rub_trukwreck_2",
	"prop_rub_tyre_01",
	"prop_rub_tyre_02",
	"prop_rub_tyre_03",
	"prop_rub_tyre_dam1",
	"prop_rub_tyre_dam2",
	"prop_rub_tyre_dam3",
	"prop_rub_washer_01",
	"prop_rub_wheel_01",
	"prop_rub_wheel_02",
	"prop_rub_wreckage_3",
	"prop_rub_wreckage_4",
	"prop_rub_wreckage_5",
	"prop_rub_wreckage_6",
	"prop_rub_wreckage_7",
	"prop_rub_wreckage_8",
	"prop_rub_wreckage_9",
	"prop_rural_windmill_l1",
	"prop_rural_windmill_l2",
	"prop_rus_olive",
	"prop_rus_olive_wint",
	"prop_sacktruck_01",
	"prop_sacktruck_02a",
	"prop_safety_glasses",
	"prop_sam_01",
	"prop_sandwich_01",
	"prop_satdish_2_a",
	"prop_satdish_2_f",
	"prop_satdish_2_g",
	"prop_satdish_3_b",
	"prop_satdish_3_c",
	"prop_satdish_3_d",
	"prop_satdish_l_01",
	"prop_satdish_s_03",
	"prop_satdish_s_05a",
	"prop_satdish_s_05b",
	"prop_sc1_06_gate_l",
	"prop_sc1_06_gate_r",
	"prop_sc1_12_door",
	"prop_sc1_21_g_door_01",
	"prop_scaffold_pole",
	"prop_scafold_01a",
	"prop_scafold_01c",
	"prop_scafold_01f",
	"prop_scafold_02a",
	"prop_scafold_02c",
	"prop_scafold_03a",
	"prop_scafold_03b",
	"prop_scafold_03c",
	"prop_scafold_03f",
	"prop_scafold_04a",
	"prop_scafold_05a",
	"prop_scafold_06a",
	"prop_scafold_06b",
	"prop_scafold_06c",
	"prop_scafold_07a",
	"prop_scafold_08a",
	"prop_scafold_09a",
	"prop_scafold_frame1a",
	"prop_scafold_frame1b",
	"prop_scafold_frame1c",
	"prop_scafold_frame1f",
	"prop_scafold_frame2a",
	"prop_scafold_frame2b",
	"prop_scafold_frame2c",
	"prop_scafold_frame3a",
	"prop_scafold_frame3c",
	"prop_scafold_rail_01",
	"prop_scafold_rail_02",
	"prop_scafold_rail_03",
	"prop_scafold_xbrace",
	"prop_scalpel",
	"prop_scn_police_torch",
	"prop_scourer_01",
	"prop_scrap_2_crate",
	"prop_scrap_win_01",
	"prop_scrim_01",
	"prop_scythemower",
	"prop_section_garage_01",
	"prop_securityvan_lightrig",
	"prop_security_case_01",
	"prop_security_case_02",
	"prop_sec_gate_01b",
	"prop_sec_gate_01c",
	"prop_sec_gate_01d",
	"prop_set_generator_01",
	"prop_sewing_fabric",
	"prop_sewing_machine",
	"prop_sglasses_stand_01",
	"prop_sglasses_stand_02",
	"prop_sglasses_stand_02b",
	"prop_sglasses_stand_03",
	"prop_sglasss_1b_lod",
	"prop_sglasss_1_lod",
	"prop_shamal_crash",
	"prop_shelves_01",
	"prop_shelves_02",
	"prop_shelves_03",
	"prop_shopping_bags01",
	"prop_shopping_bags02",
	"prop_shop_front_door_l",
	"prop_shop_front_door_r",
	"prop_shots_glass_cs",
	"prop_shower_01",
	"prop_shower_rack_01",
	"prop_shower_towel",
	"prop_showroom_door_l",
	"prop_showroom_door_r",
	"prop_showroom_glass_1b",
	"prop_shredder_01",
	"prop_shrub_rake",
	"prop_shuttering01",
	"prop_shuttering02",
	"prop_shuttering03",
	"prop_shuttering04",
	"prop_sh_beer_pissh_01",
	"prop_sh_bong_01",
	"prop_sh_cigar_01",
	"prop_sh_joint_01",
	"prop_sh_mr_rasp_01",
	"prop_sh_shot_glass",
	"prop_sh_tall_glass",
	"prop_sh_tt_fridgedoor",
	"prop_sh_wine_glass",
	"prop_side_lights",
	"prop_side_spreader",
	"prop_sign_airp_01a",
	"prop_sign_airp_02a",
	"prop_sign_airp_02b",
	"prop_sign_big_01",
	"prop_sign_mallet",
	"prop_sign_road_04g_l1",
	"prop_single_grid_line",
	"prop_single_rose",
	"prop_sink_01",
	"prop_sink_02",
	"prop_sink_03",
	"prop_sink_04",
	"prop_sink_05",
	"prop_sink_06",
	"prop_skate_flatramp",
	"prop_skate_funbox",
	"prop_skate_halfpipe",
	"prop_skate_kickers",
	"prop_skate_quartpipe",
	"prop_skate_rail",
	"prop_skate_spiner",
	"prop_skid_chair_01",
	"prop_skid_chair_02",
	"prop_skid_chair_03",
	"prop_skid_sleepbag_1",
	"prop_skid_tent_01",
	"prop_skid_tent_01b",
	"prop_skid_tent_03",
	"prop_skip_01a",
	"prop_skip_02a",
	"prop_skip_03",
	"prop_skip_04",
	"prop_skip_05a",
	"prop_skip_05b",
	"prop_skip_06a",
	"prop_skip_08a",
	"prop_skip_08b",
	"prop_skip_10a",
	"prop_skip_rope_01",
	"prop_skunk_bush_01",
	"prop_skylight_01",
	"prop_skylight_02",
	"prop_skylight_03",
	"prop_skylight_04",
	"prop_skylight_05",
	"prop_skylight_06a",
	"prop_skylight_06b",
	"prop_skylight_06c",
	"prop_sky_cover_01",
	"prop_slacks_01",
	"prop_slacks_02",
	"prop_sluicegate",
	"prop_sluicegatel",
	"prop_sluicegater",
	"prop_slush_dispenser",
	"prop_sm1_11_doorl",
	"prop_sm1_11_doorr",
	"prop_sm1_11_garaged",
	"prop_smg_holster_01",
	"prop_sm_10_mp_door",
	"prop_sm_14_mp_gar",
	"prop_sm_19_clock",
	"prop_sm_27_door",
	"prop_sm_27_gate",
	"prop_sm_27_gate_02",
	"prop_sm_27_gate_03",
	"prop_sm_27_gate_04",
	"prop_sm_locker_door",
	"prop_snow_bailer_01",
	"prop_snow_barrel_pile_03",
	"prop_snow_bench_01",
	"prop_snow_bin_01",
	"prop_snow_bin_02",
	"prop_snow_bush_01_a",
	"prop_snow_bush_02_a",
	"prop_snow_bush_02_b",
	"prop_snow_bush_03",
	"prop_snow_bush_04",
	"prop_snow_bush_04b",
	"prop_snow_cam_03",
	"prop_snow_cam_03a",
	"prop_snow_diggerbkt_01",
	"prop_snow_dumpster_01",
	"prop_snow_elecbox_16",
	"prop_snow_facgate_01",
	"prop_snow_field_01",
	"prop_snow_field_02",
	"prop_snow_field_03",
	"prop_snow_field_04",
	"prop_snow_flower_01",
	"prop_snow_flower_02",
	"prop_snow_fnclink_03crnr2",
	"prop_snow_fnclink_03h",
	"prop_snow_fnclink_03i",
	"prop_snow_fncwood_14a",
	"prop_snow_fncwood_14b",
	"prop_snow_fncwood_14c",
	"prop_snow_fncwood_14d",
	"prop_snow_fncwood_14e",
	"prop_snow_fnc_01",
	"prop_snow_gate_farm_03",
	"prop_snow_grain_01",
	"prop_snow_grass_01",
	"prop_snow_light_01",
	"prop_snow_oldlight_01b",
	"prop_snow_rail_signals02",
	"prop_snow_rub_trukwreck_2",
	"prop_snow_side_spreader_01",
	"prop_snow_streetlight01",
	"prop_snow_streetlight_01_frag_",
	"prop_snow_sub_frame_01a",
	"prop_snow_sub_frame_04b",
	"prop_snow_telegraph_01a",
	"prop_snow_telegraph_02a",
	"prop_snow_telegraph_03",
	"prop_snow_traffic_rail_1a",
	"prop_snow_traffic_rail_1b",
	"prop_snow_trailer01",
	"prop_snow_tree_03_e",
	"prop_snow_tree_03_h",
	"prop_snow_tree_03_i",
	"prop_snow_tree_04_d",
	"prop_snow_tree_04_f",
	"prop_snow_truktrailer_01a",
	"prop_snow_tyre_01",
	"prop_snow_t_ml_01",
	"prop_snow_t_ml_02",
	"prop_snow_t_ml_03",
	"prop_snow_wall_light_15a",
	"prop_snow_watertower01",
	"prop_snow_watertower01_l2",
	"prop_snow_watertower03",
	"prop_snow_woodpile_04a",
	"prop_soap_disp_01",
	"prop_soap_disp_02",
	"prop_solarpanel_01",
	"prop_solarpanel_02",
	"prop_solarpanel_03",
	"prop_sol_chair",
	"prop_space_pistol",
	"prop_space_rifle",
	"prop_speaker_01",
	"prop_speaker_02",
	"prop_speaker_03",
	"prop_speaker_05",
	"prop_speaker_06",
	"prop_speaker_07",
	"prop_speaker_08",
	"prop_speedball_01",
	"prop_sponge_01",
	"prop_sports_clock_01",
	"prop_spot_01",
	"prop_spot_clamp",
	"prop_spot_clamp_02",
	"prop_sprayer",
	"prop_spraygun_01",
	"prop_spray_backpack_01",
	"prop_spray_jackframe",
	"prop_spray_jackleg",
	"prop_sprink_crop_01",
	"prop_sprink_golf_01",
	"prop_sprink_park_01",
	"prop_spycam",
	"prop_squeegee",
	"prop_ss1_05_mp_door",
	"prop_ss1_08_mp_door_l",
	"prop_ss1_08_mp_door_r",
	"prop_ss1_10_door_l",
	"prop_ss1_10_door_r",
	"prop_ss1_14_garage_door",
	"prop_ss1_mpint_door_l",
	"prop_ss1_mpint_door_r",
	"prop_ss1_mpint_garage",
	"prop_ss1_mpint_garage_cl",
	"prop_stag_do_rope",
	"prop_start_finish_line_01",
	"prop_start_grid_01",
	"prop_staticmixer_01",
	"prop_stat_pack_01",
	"prop_steam_basket_01",
	"prop_steam_basket_02",
	"prop_steps_big_01",
	"prop_stickbfly",
	"prop_stickhbird",
	"prop_still",
	"prop_stockade_wheel",
	"prop_stockade_wheel_flat",
	"prop_stool_01",
	"prop_storagetank_01",
	"prop_storagetank_02",
	"prop_storagetank_03",
	"prop_storagetank_03a",
	"prop_storagetank_03b",
	"prop_storagetank_04",
	"prop_storagetank_05",
	"prop_storagetank_06",
	"prop_storagetank_07a",
	"prop_stripmenu",
	"prop_strip_door_01",
	"prop_strip_pole_01",
	"prop_studio_light_02",
	"prop_studio_light_03",
	"prop_sub_chunk_01",
	"prop_sub_cover_01",
	"prop_sub_crane_hook",
	"prop_sub_frame_01a",
	"prop_sub_frame_01b",
	"prop_sub_frame_01c",
	"prop_sub_frame_02a",
	"prop_sub_frame_03a",
	"prop_sub_frame_04a",
	"prop_sub_frame_04b",
	"prop_sub_gantry",
	"prop_sub_release",
	"prop_sub_trans_01a",
	"prop_sub_trans_02a",
	"prop_sub_trans_03a",
	"prop_sub_trans_04a",
	"prop_sub_trans_05b",
	"prop_sub_trans_06b",
	"prop_suitcase_01",
	"prop_suitcase_01b",
	"prop_suitcase_01c",
	"prop_suitcase_01d",
	"prop_suitcase_02",
	"prop_suitcase_03",
	"prop_suitcase_03b",
	"prop_surf_board_ldn_01",
	"prop_surf_board_ldn_02",
	"prop_surf_board_ldn_03",
	"prop_surf_board_ldn_04",
	"prop_syringe_01",
	"prop_s_pine_dead_01",
	"prop_tablesaw_01",
	"prop_tablesmall_01",
	"prop_table_02",
	"prop_table_03b_cs",
	"prop_table_04",
	"prop_table_04_chr",
	"prop_table_05",
	"prop_table_05_chr",
	"prop_table_06",
	"prop_table_06_chr",
	"prop_table_07",
	"prop_table_07_l1",
	"prop_table_08",
	"prop_table_08_chr",
	"prop_table_08_side",
	"prop_table_mic_01",
	"prop_table_para_comb_04",
	"prop_table_tennis",
	"prop_table_ten_bat",
	"prop_taco_01",
	"prop_taco_02",
	"prop_tail_gate_col",
	"prop_tapeplayer_01",
	"prop_target_arm",
	"prop_target_arm_b",
	"prop_target_arm_long",
	"prop_target_arm_sm",
	"prop_target_backboard",
	"prop_target_backboard_b",
	"prop_target_blue",
	"prop_target_blue_arrow",
	"prop_target_bull",
	"prop_target_bull_b",
	"prop_target_comp_metal",
	"prop_target_comp_wood",
	"prop_target_frame_01",
	"prop_target_inner1",
	"prop_target_inner2",
	"prop_target_inner2_b",
	"prop_target_inner3",
	"prop_target_inner3_b",
	"prop_target_inner_b",
	"prop_target_orange_arrow",
	"prop_target_oran_cross",
	"prop_target_ora_purp_01",
	"prop_target_purp_arrow",
	"prop_target_purp_cross",
	"prop_target_red",
	"prop_target_red_arrow",
	"prop_target_red_blue_01",
	"prop_target_red_cross",
	"prop_tarp_strap",
	"prop_taxi_meter_1",
	"prop_taxi_meter_2",
	"prop_tea_trolly",
	"prop_tea_urn",
	"prop_telegraph_01a",
	"prop_telegraph_01b",
	"prop_telegraph_01c",
	"prop_telegraph_01d",
	"prop_telegraph_01e",
	"prop_telegraph_01f",
	"prop_telegraph_01g",
	"prop_telegraph_02a",
	"prop_telegraph_02b",
	"prop_telegraph_03",
	"prop_telegraph_04a",
	"prop_telegraph_04b",
	"prop_telegraph_05a",
	"prop_telegraph_05b",
	"prop_telegraph_05c",
	"prop_telegraph_06a",
	"prop_telegraph_06b",
	"prop_telegraph_06c",
	"prop_telegwall_01a",
	"prop_telegwall_01b",
	"prop_telegwall_02a",
	"prop_telegwall_03a",
	"prop_telegwall_03b",
	"prop_telegwall_04a",
	"prop_telescope",
	"prop_telescope_01",
	"prop_temp_block_blocker",
	"prop_tennis_bag_01",
	"prop_tennis_ball",
	"prop_tennis_ball_lobber",
	"prop_tennis_rack_01",
	"prop_tennis_rack_01b",
	"prop_test_boulder_01",
	"prop_test_boulder_02",
	"prop_test_boulder_03",
	"prop_test_boulder_04",
	"prop_test_elevator",
	"prop_test_elevator_dl",
	"prop_test_elevator_dr",
	"prop_tick",
	"prop_tick_02",
	"prop_till_01_dam",
	"prop_till_02",
	"prop_till_03",
	"prop_time_capsule_01",
	"prop_tint_towel",
	"prop_tint_towels_01",
	"prop_tint_towels_01b",
	"prop_toaster_01",
	"prop_toaster_02",
	"prop_toiletfoot_static",
	"prop_toilet_01",
	"prop_toilet_02",
	"prop_toilet_03",
	"prop_toilet_brush_01",
	"prop_toilet_cube_01",
	"prop_toilet_cube_02",
	"prop_toilet_roll_01",
	"prop_toilet_roll_02",
	"prop_toilet_roll_03",
	"prop_toilet_roll_04",
	"prop_toilet_roll_05",
	"prop_toilet_shamp_01",
	"prop_toilet_shamp_02",
	"prop_toilet_soap_01",
	"prop_toilet_soap_02",
	"prop_toilet_soap_03",
	"prop_toilet_soap_04",
	"prop_toolchest_01",
	"prop_toolchest_02",
	"prop_toolchest_03",
	"prop_toolchest_04",
	"prop_toolchest_05",
	"prop_tool_adjspanner",
	"prop_tool_bench01",
	"prop_tool_bluepnt",
	"prop_tool_box_01",
	"prop_tool_box_02",
	"prop_tool_box_03",
	"prop_tool_box_04",
	"prop_tool_box_05",
	"prop_tool_box_06",
	"prop_tool_box_07",
	"prop_tool_broom",
	"prop_tool_broom2",
	"prop_tool_broom2_l1",
	"prop_tool_cable01",
	"prop_tool_cable02",
	"prop_tool_consaw",
	"prop_tool_drill",
	"prop_tool_fireaxe",
	"prop_tool_hammer",
	"prop_tool_hardhat",
	"prop_tool_jackham",
	"prop_tool_mallet",
	"prop_tool_mopbucket",
	"prop_tool_nailgun",
	"prop_tool_pickaxe",
	"prop_tool_pliers",
	"prop_tool_rake",
	"prop_tool_rake_l1",
	"prop_tool_sawhorse",
	"prop_tool_screwdvr01",
	"prop_tool_screwdvr02",
	"prop_tool_screwdvr03",
	"prop_tool_shovel",
	"prop_tool_shovel006",
	"prop_tool_shovel2",
	"prop_tool_shovel3",
	"prop_tool_shovel4",
	"prop_tool_shovel5",
	"prop_tool_sledgeham",
	"prop_tool_spanner01",
	"prop_tool_spanner02",
	"prop_tool_spanner03",
	"prop_tool_torch",
	"prop_tool_wrench",
	"prop_toothbrush_01",
	"prop_toothb_cup_01",
	"prop_toothpaste_01",
	"prop_tornado_wheel",
	"prop_torture_01",
	"prop_torture_ch_01",
	"prop_tourist_map_01",
	"prop_towel2_01",
	"prop_towel2_02",
	"prop_towel_01",
	"prop_towel_rail_01",
	"prop_towel_rail_02",
	"prop_towel_shelf_01",
	"prop_towel_small_01",
	"prop_towercrane_01a",
	"prop_towercrane_02a",
	"prop_towercrane_02b",
	"prop_towercrane_02c",
	"prop_towercrane_02d",
	"prop_towercrane_02e",
	"prop_towercrane_02el",
	"prop_towercrane_02el2",
	"prop_traffic_rail_1c",
	"prop_traffic_rail_2",
	"prop_trailer01",
	"prop_trailer01_up",
	"prop_trailer_01_new",
	"prop_trailer_door_closed",
	"prop_trailer_door_open",
	"prop_trailer_monitor_01",
	"prop_trailr_base",
	"prop_trailr_base_static",
	"prop_train_ticket_02",
	"prop_tram_pole_double01",
	"prop_tram_pole_double02",
	"prop_tram_pole_double03",
	"prop_tram_pole_roadside",
	"prop_tram_pole_single01",
	"prop_tram_pole_single02",
	"prop_tram_pole_wide01",
	"prop_tree_birch_01",
	"prop_tree_birch_02",
	"prop_tree_birch_03",
	"prop_tree_birch_03b",
	"prop_tree_birch_04",
	"prop_tree_birch_05",
	"prop_tree_cedar_02",
	"prop_tree_cedar_03",
	"prop_tree_cedar_04",
	"prop_tree_cedar_s_01",
	"prop_tree_cedar_s_02",
	"prop_tree_cedar_s_04",
	"prop_tree_cedar_s_05",
	"prop_tree_cedar_s_06",
	"prop_tree_cypress_01",
	"prop_tree_eng_oak_01",
	"prop_tree_eucalip_01",
	"prop_tree_fallen_01",
	"prop_tree_fallen_02",
	"prop_tree_fallen_pine_01",
	"prop_tree_jacada_01",
	"prop_tree_jacada_02",
	"prop_tree_lficus_02",
	"prop_tree_lficus_03",
	"prop_tree_lficus_05",
	"prop_tree_lficus_06",
	"prop_tree_log_01",
	"prop_tree_log_02",
	"prop_tree_maple_02",
	"prop_tree_maple_03",
	"prop_tree_mquite_01",
	"prop_tree_oak_01",
	"prop_tree_olive_01",
	"prop_tree_pine_01",
	"prop_tree_pine_02",
	"prop_tree_stump_01",
	"prop_trevor_rope_01",
	"prop_trev_sec_id",
	"prop_trev_tv_01",
	"prop_triple_grid_line",
	"prop_tri_finish_banner",
	"prop_tri_pod",
	"prop_tri_pod_lod",
	"prop_tri_start_banner",
	"prop_tri_table_01",
	"prop_trough1",
	"prop_truktrailer_01a",
	"prop_tshirt_box_02",
	"prop_tshirt_shelf_1",
	"prop_tshirt_shelf_2",
	"prop_tshirt_shelf_2a",
	"prop_tshirt_shelf_2b",
	"prop_tshirt_shelf_2c",
	"prop_tshirt_stand_01",
	"prop_tshirt_stand_01b",
	"prop_tshirt_stand_02",
	"prop_tshirt_stand_04",
	"prop_tt_screenstatic",
	"prop_tumbler_01",
	"prop_tumbler_01b",
	"prop_tumbler_01_empty",
	"prop_tunnel_liner01",
	"prop_tunnel_liner02",
	"prop_tunnel_liner03",
	"prop_turkey_leg_01",
	"prop_turnstyle_01",
	"prop_tv_02",
	"prop_tv_03_overlay",
	"prop_tv_04",
	"prop_tv_05",
	"prop_tv_06",
	"prop_tv_07",
	"prop_tv_cabinet_03",
	"prop_tv_cabinet_04",
	"prop_tv_cabinet_05",
	"prop_tv_cam_02",
	"prop_tv_flat_01",
	"prop_tv_flat_01_screen",
	"prop_tv_flat_02b",
	"prop_tv_flat_03",
	"prop_tv_flat_03b",
	"prop_tv_flat_michael",
	"prop_tv_test",
	"prop_tyre_rack_01",
	"prop_tyre_spike_01",
	"prop_t_coffe_table",
	"prop_t_shirt_ironing",
	"prop_t_shirt_row_01",
	"prop_t_shirt_row_02",
	"prop_t_shirt_row_02b",
	"prop_t_shirt_row_03",
	"prop_t_shirt_row_04",
	"prop_t_shirt_row_05l",
	"prop_t_shirt_row_05r",
	"prop_t_sofa",
	"prop_t_sofa_02",
	"prop_t_telescope_01b",
	"prop_umpire_01",
	"prop_utensil",
	"prop_valet_03",
	"prop_vault_shutter",
	"prop_vb_34_tencrt_lighting",
	"prop_vcr_01",
	"prop_veg_corn_01",
	"prop_veg_crop_01",
	"prop_veg_crop_02",
	"prop_veg_crop_04",
	"prop_veg_crop_04_leaf",
	"prop_veg_crop_05",
	"prop_veg_crop_06",
	"prop_veg_crop_orange",
	"prop_veg_crop_tr_01",
	"prop_veg_crop_tr_02",
	"prop_veg_grass_01_a",
	"prop_veg_grass_01_b",
	"prop_veg_grass_01_c",
	"prop_veg_grass_01_d",
	"prop_veg_grass_02_a",
	"prop_vehicle_hook",
	"prop_vend_coffe_01",
	"prop_vend_condom_01",
	"prop_vend_fags_01",
	"prop_vend_fridge01",
	"prop_vend_snak_01",
	"prop_venice_board_01",
	"prop_venice_board_02",
	"prop_venice_board_03",
	"prop_venice_counter_01",
	"prop_venice_counter_02",
	"prop_venice_counter_03",
	"prop_venice_counter_04",
	"prop_venice_shop_front_01",
	"prop_venice_sign_09",
	"prop_venice_sign_10",
	"prop_venice_sign_11",
	"prop_venice_sign_12",
	"prop_venice_sign_14",
	"prop_venice_sign_15",
	"prop_venice_sign_16",
	"prop_venice_sign_17",
	"prop_venice_sign_18",
	"prop_ventsystem_01",
	"prop_ventsystem_02",
	"prop_ventsystem_03",
	"prop_ventsystem_04",
	"prop_ven_market_stool",
	"prop_ven_market_table1",
	"prop_ven_shop_1_counter",
	"prop_vertdrill_01",
	"prop_voltmeter_01",
	"prop_v_15_cars_clock",
	"prop_v_5_bclock",
	"prop_v_bmike_01",
	"prop_v_cam_01",
	"prop_v_door_44",
	"prop_v_hook_s",
	"prop_v_m_phone_01",
	"prop_v_m_phone_o1s",
	"prop_v_parachute",
	"prop_waiting_seat_01",
	"prop_wait_bench_01",
	"prop_walllight_ld_01b",
	"prop_wall_light_08a",
	"prop_wall_light_10a",
	"prop_wall_light_10b",
	"prop_wall_light_10c",
	"prop_wall_light_11",
	"prop_wall_light_12",
	"prop_wall_light_17b",
	"prop_wall_light_18a",
	"prop_wall_vent_01",
	"prop_wall_vent_02",
	"prop_wall_vent_03",
	"prop_wall_vent_04",
	"prop_wall_vent_05",
	"prop_wall_vent_06",
	"prop_wardrobe_door_01",
	"prop_warehseshelf01",
	"prop_warehseshelf02",
	"prop_warehseshelf03",
	"prop_warninglight_01",
	"prop_washer_01",
	"prop_washer_02",
	"prop_washer_03",
	"prop_washing_basket_01",
	"prop_watercrate_01",
	"prop_wateringcan",
	"prop_watertower01",
	"prop_watertower02",
	"prop_watertower03",
	"prop_watertower04",
	"prop_waterwheela",
	"prop_waterwheelb",
	"prop_water_bottle",
	"prop_water_bottle_dark",
	"prop_water_corpse_01",
	"prop_water_corpse_02",
	"prop_water_ramp_01",
	"prop_water_ramp_02",
	"prop_water_ramp_03",
	"prop_weed_01",
	"prop_weed_02",
	"prop_weed_block_01",
	"prop_weed_bottle",
	"prop_weed_pallet",
	"prop_weed_tub_01",
	"prop_weed_tub_01b",
	"prop_weight_10k",
	"prop_weight_15k",
	"prop_weight_1_5k",
	"prop_weight_20k",
	"prop_weight_2_5k",
	"prop_weight_5k",
	"prop_weight_rack_01",
	"prop_weight_rack_02",
	"prop_welding_mask_01",
	"prop_weld_torch",
	"prop_wheat_grass_empty",
	"prop_wheat_grass_glass",
	"prop_wheelbarrow01a",
	"prop_wheelbarrow02a",
	"prop_wheelchair_01",
	"prop_wheel_01",
	"prop_wheel_02",
	"prop_wheel_03",
	"prop_wheel_04",
	"prop_wheel_05",
	"prop_wheel_06",
	"prop_wheel_hub_01",
	"prop_wheel_hub_02_lod_02",
	"prop_wheel_rim_01",
	"prop_wheel_rim_02",
	"prop_wheel_rim_03",
	"prop_wheel_rim_04",
	"prop_wheel_rim_05",
	"prop_wheel_tyre",
	"prop_whisk",
	"prop_white_keyboard",
	"prop_winch_hook_long",
	"prop_winch_hook_short",
	"prop_windmill2",
	"prop_windmill_01_l1",
	"prop_windmill_01_slod",
	"prop_windmill_01_slod2",
	"prop_windowbox_a",
	"prop_windowbox_b",
	"prop_windowbox_broken",
	"prop_windowbox_small",
	"prop_win_plug_01",
	"prop_win_plug_01_dam",
	"prop_win_trailer_ld",
	"prop_wok",
	"prop_woodpile_02a",
	"prop_worklight_01a_l1",
	"prop_worklight_03a_l1",
	"prop_worklight_03b_l1",
	"prop_worklight_04a",
	"prop_worklight_04b_l1",
	"prop_worklight_04c_l1",
	"prop_worklight_04d_l1",
	"prop_workwall_01",
	"prop_workwall_02",
	"prop_wreckedcart",
	"prop_wrecked_buzzard",
	"prop_w_board_blank",
	"prop_w_board_blank_2",
	"prop_w_fountain_01",
	"prop_w_r_cedar_01",
	"prop_w_r_cedar_dead",
	"prop_xmas_tree_int",
	"prop_xmas_ext",
	"prop_yacht_lounger",
	"prop_yacht_seat_01",
	"prop_yacht_seat_02",
	"prop_yacht_seat_03",
	"prop_yacht_table_01",
	"prop_yacht_table_02",
	"prop_yacht_table_03",
	"prop_yaught_chair_01",
	"prop_yaught_sofa_01",
	"prop_yell_plastic_target",
	"prop_yoga_mat_01",
	"prop_yoga_mat_02",
	"prop_yoga_mat_03",
	"prop_ztype_covered",
	"p_ing_skiprope_01",
	"p_ing_skiprope_01_s",
	"p_skiprope_r_s",
	"test_prop_gravestones_04a",
	"test_prop_gravestones_05a",
	"test_prop_gravestones_07a",
	"test_prop_gravestones_08a",
	"test_prop_gravestones_09a",
	"test_prop_gravetomb_01a",
	"test_prop_gravetomb_02a",
	"prop_cs_dog_lead_a_s",
	"prop_cs_dog_lead_b_s",
	"prop_welding_mask_01_s",
	"prop_wheelchair_01_s",
	"p_a4_sheets_s",
	"p_amanda_note_01_s",
	"p_armchair_01_s",
	"p_arm_bind_cut_s",
	"p_ashley_neck_01_s",
	"p_banknote_onedollar_s",
	"p_banknote_s",
	"p_binbag_01_s",
	"p_bison_winch_s",
	"p_bloodsplat_s",
	"p_blueprints_01_s",
	"p_brain_chunk_s",
	"p_bs_map_door_01_s",
	"p_cablecar_s",
	"p_cablecar_s_door_l",
	"p_cablecar_s_door_r",
	"p_cash_envelope_01_s",
	"p_cctv_s",
	"p_chem_vial_02b_s",
	"p_clb_officechair_s",
	"p_cletus_necklace_s",
	"p_clothtarp_down_s",
	"p_clothtarp_s",
	"p_clothtarp_up_s",
	"p_controller_01_s",
	"p_crahsed_heli_s",
	"p_cs1_14b_train_s",
	"p_cs1_14b_train_s_col",
	"p_cs1_14b_train_s_colopen",
	"p_csbporndudes_necklace_s",
	"p_csh_strap_01_pro_s",
	"p_csh_strap_01_s",
	"p_csh_strap_03_s",
	"p_cs_15m_rope_s",
	"p_cs_bandana_s",
	"p_cs_beachtowel_01_s",
	"p_cs_beverly_lanyard_s",
	"p_cs_bowl_01b_s",
	"p_cs_ciggy_01b_s",
	"p_cs_clothes_box_s",
	"p_cs_coke_line_s",
	"p_cs_cuffs_02_s",
	"p_cs_duffel_01_s",
	"p_cs_laz_ptail_s",
	"p_cs_leaf_s",
	"p_cs_mp_jet_01_s",
	"p_cs_newspaper_s",
	"p_cs_pamphlet_01_s",
	"p_cs_panties_03_s",
	"p_cs_para_ropebit_s",
	"p_cs_para_ropes_s",
	"p_cs_polaroid_s",
	"p_cs_police_torch_s",
	"p_cs_pour_tube_s",
	"p_cs_power_cord_s",
	"p_cs_rope_tie_01_s",
	"p_cs_sack_01_s",
	"p_cs_saucer_01_s",
	"p_cs_scissors_s",
	"p_cs_script_s",
	"p_cs_shirt_01_s",
	"p_cs_shot_glass_2_s",
	"p_cs_shot_glass_s",
	"p_cs_sub_hook_01_s",
	"p_cs_toaster_s",
	"p_cs_tracy_neck2_s",
	"p_cs_trolley_01_s",
	"p_defilied_ragdoll_01_s",
	"p_devin_box_01_s",
	"p_dinechair_01_s",
	"p_d_scuba_mask_s",
	"p_d_scuba_tank_s",
	"p_ecg_01_cable_01_s",
	"p_fib_rubble_s",
	"p_finale_bld_ground_s",
	"p_finale_bld_pool_s",
	"p_fin_vaultdoor_s",
	"p_flatbed_strap_s",
	"p_folding_chair_01_s",
	"p_gaffer_tape_s",
	"p_gaffer_tape_strip_s",
	"p_gasmask_s",
	"p_gcase_s",
	"p_hand_toilet_s",
	"p_hw1_22_doors_s",
	"p_hw1_22_table_s",
	"p_ice_box_01_s",
	"p_ice_box_proxy_col",
	"p_idol_case_s",
	"p_ilev_p_easychair_s",
	"p_inhaler_01_s",
	"p_jimmyneck_03_s",
	"p_jimmy_necklace_s",
	"p_kitch_juicer_s",
	"p_lamarneck_01_s",
	"p_laptop_02_s",
	"p_large_gold_s",
	"p_lazlow_shirt_s",
	"p_laz_j01_s",
	"p_laz_j02_s",
	"p_ld_cable_tie_01_s",
	"p_ld_crocclips01_s",
	"p_ld_crocclips02_s",
	"p_ld_heist_bag_s_1",
	"p_ld_heist_bag_s_2",
	"p_ld_heist_bag_s_pro",
	"p_ld_heist_bag_s_pro2_s",
	"p_ld_heist_bag_s_pro_o",
	"p_leg_bind_cut_s",
	"p_lestersbed_s",
	"p_lev_sofa_s",
	"p_lifeinv_neck_01_s",
	"p_loose_rag_01_s",
	"p_mbbed_s",
	"p_medal_01_s",
	"p_med_jet_01_s",
	"p_meth_bag_01_s",
	"p_michael_backpack_s",
	"p_michael_scuba_mask_s",
	"p_michael_scuba_tank_s",
	"p_mp_showerdoor_s",
	"p_mrk_harness_s",
	"p_mr_raspberry_01_s",
	"p_novel_01_s",
	"p_omega_neck_01_s",
	"p_omega_neck_02_s",
	"p_orleans_mask_s",
	"p_ortega_necklace_s",
	"p_oscar_necklace_s",
	"p_overalls_02_s",
	"p_pistol_holster_s",
	"p_po1_01_doorm_s",
	"p_police_radio_hset_s",
	"p_poly_bag_01_s",
	"p_pour_wine_s",
	"p_rail_controller_s",
	"p_res_sofa_l_s",
	"p_rpulley_s",
	"p_sec_case_02_s",
	"p_shower_towel_s",
	"p_single_rose_s",
	"p_smg_holster_01_s",
	"p_soloffchair_s",
	"p_spinning_anus_s",
	"p_steve_scuba_hood_s",
	"p_stretch_necklace_s",
	"p_syringe_01_s",
	"p_s_scuba_mask_s",
	"p_s_scuba_tank_s",
	"p_till_01_s",
	"p_tmom_earrings_s",
	"p_tourist_map_01_s",
	"p_trevor_prologe_bally_s",
	"p_trev_rope_01_s",
	"p_trev_ski_mask_s",
	"p_tumbler_01_s",
	"p_tumbler_02_s1",
	"p_tumbler_cs2_s",
	"p_tv_cam_02_s",
	"p_t_shirt_pile_s",
	"p_v_43_safe_s",
	"p_v_ilev_chopshopswitch_s",
	"p_v_med_p_sofa_s",
	"p_v_res_tt_bed_s",
	"p_wade_necklace_s",
	"p_wboard_clth_s",
	"p_weed_bottle_s",
	"p_whiskey_bottle_s",
	"p_winch_long_s",
	"s_prop_hdphones",
	"s_prop_hdphones_1",
	"v_ilev_fib_door1_s",
	"v_res_msonbed_s",
	"v_res_tre_sofa_s",
	"v_tre_sofa_mess_a_s",
	"v_tre_sofa_mess_b_s",
	"v_tre_sofa_mess_c_s",
	"prop_ar_arrow_1",
	"prop_ar_arrow_2",
	"prop_ar_arrow_3",
	"prop_ar_ring_01",
	"prop_mk_arrow_3d",
	"prop_mk_arrow_flat",
	"prop_mk_bike_logo_1",
	"prop_mk_bike_logo_2",
	"prop_mk_boost",
	"prop_mk_cone",
	"prop_mk_cylinder",
	"prop_mk_flag",
	"prop_mk_flag_2",
	"prop_mk_heli",
	"prop_mk_lap",
	"prop_mk_mp_ring_01",
	"prop_mk_mp_ring_01b",
	"prop_mk_num_0",
	"prop_mk_num_1",
	"prop_mk_num_2",
	"prop_mk_num_3",
	"prop_mk_num_4",
	"prop_mk_num_5",
	"prop_mk_num_6",
	"prop_mk_num_7",
	"prop_mk_num_8",
	"prop_mk_num_9",
	"prop_mk_plane",
	"prop_mk_race_chevron_01",
	"prop_mk_race_chevron_02",
	"prop_mk_race_chevron_03",
	"prop_mk_repair",
	"prop_mk_ring",
	"prop_mk_ring_flat",
	"prop_mk_sphere",
	"prop_mk_tri_cycle",
	"prop_mk_tri_run",
	"prop_mk_tri_swim",
	"prop_mp_arrow_ring",
	"prop_mp_halo",
	"prop_mp_halo_lrg",
	"prop_mp_halo_med",
	"prop_mp_halo_point",
	"prop_mp_halo_point_lrg",
	"prop_mp_halo_point_med",
	"prop_mp_halo_point_sm",
	"prop_mp_halo_rotate",
	"prop_mp_halo_rotate_lrg",
	"prop_mp_halo_rotate_med",
	"prop_mp_halo_rotate_sm",
	"prop_mp_halo_sm",
	"prop_mp_pointer_ring",
	"prop_mp_solid_ring",
	"cj_parachute",
	"gb_cap_use",
	"gb_specs_use",
	"cj_proc_tin2",
	"proc_coral_01",
	"proc_fern_02",
	"proc_litter_01",
	"proc_litter_02",
	"proc_mntn_stone01",
	"proc_mntn_stone02",
	"proc_mntn_stone03",
	"proc_searock_01",
	"proc_searock_02",
	"proc_searock_03",
	"proc_sml_stones01",
	"proc_sml_stones02",
	"proc_sml_stones03",
	"proc_trolley_lakebed",
	"prop_bush_gorse_dry",
	"prop_bush_gorse_lush",
	"prop_coral_01",
	"prop_coral_02",
	"prop_coral_03",
	"prop_sapling_01",
	"prop_seabrain_01",
	"prop_seagroup_02",
	"prop_sealife_01",
	"prop_sealife_02",
	"prop_sealife_03",
	"prop_sealife_04",
	"prop_sealife_05",
	"prop_seaweed_01",
	"prop_seaweed_02",
	"prop_starfish_01",
	"prop_starfish_02",
	"prop_starfish_03",
	"prop_aerial_01a",
	"prop_aerial_01b",
	"prop_aerial_01c",
	"prop_aerial_01d",
	"prop_aircon_l_01",
	"prop_aircon_l_02",
	"prop_aircon_l_03",
	"prop_aircon_l_04",
	"prop_aircon_m_09",
	"prop_aircon_s_01a",
	"prop_aircon_s_02a",
	"prop_aircon_s_02b",
	"prop_aircon_s_03a",
	"prop_aircon_s_03b",
	"prop_aircon_s_04a",
	"prop_aircon_s_05a",
	"prop_aircon_s_06a",
	"prop_aircon_s_07a",
	"prop_aircon_s_07b",
	"prop_alarm_01",
	"prop_alarm_02",
	"prop_billb_frame01a",
	"prop_billb_frame01b",
	"prop_billb_frame02a",
	"prop_billb_frame02b",
	"prop_billb_frame03a",
	"prop_billb_frame03b",
	"prop_billb_frame03c",
	"prop_billb_frame04a",
	"prop_billb_frame04b",
	"prop_bmu_01",
	"prop_bmu_01_b",
	"prop_bmu_02",
	"prop_bmu_02_ld",
	"prop_bmu_02_ld_cab",
	"prop_bmu_02_ld_sup",
	"prop_bmu_track01",
	"prop_bmu_track02",
	"prop_bmu_track03",
	"prop_fireescape_01a",
	"prop_fireescape_01b",
	"prop_fireescape_02a",
	"prop_fireescape_02b",
	"prop_flagpole_1a",
	"prop_flagpole_2a",
	"prop_flagpole_3a",
	"prop_helipad_01",
	"prop_helipad_02",
	"prop_radiomast01",
	"prop_radiomast02",
	"prop_roofpipe_01",
	"prop_roofpipe_02",
	"prop_roofpipe_03",
	"prop_roofpipe_04",
	"prop_roofpipe_05",
	"prop_roofpipe_06",
	"prop_roofvent_011a",
	"prop_roofvent_01a",
	"prop_roofvent_01b",
	"prop_roofvent_02a",
	"prop_roofvent_02b",
	"prop_roofvent_03a",
	"prop_roofvent_04a",
	"prop_roofvent_05a",
	"prop_roofvent_05b",
	"prop_roofvent_07a",
	"prop_roofvent_08a",
	"prop_roofvent_09a",
	"prop_roofvent_10a",
	"prop_roofvent_10b",
	"prop_roofvent_11b",
	"prop_roofvent_11c",
	"prop_roofvent_12a",
	"prop_roofvent_13a",
	"prop_roofvent_15a",
	"prop_roofvent_16a",
	"prop_satdish_2_a",
	"prop_satdish_2_f",
	"prop_satdish_2_g",
	"prop_satdish_3_b",
	"prop_satdish_3_c",
	"prop_satdish_3_d",
	"prop_satdish_l_01",
	"prop_satdish_s_03",
	"prop_satdish_s_05a",
	"prop_satdish_s_05b",
	"prop_skylight_01",
	"prop_skylight_02",
	"prop_skylight_03",
	"prop_skylight_04",
	"prop_skylight_05",
	"prop_skylight_06a",
	"prop_skylight_06b",
	"prop_skylight_06c",
	"prop_solarpanel_01",
	"prop_solarpanel_02",
	"prop_solarpanel_03",
	"prop_ventsystem_01",
	"prop_ventsystem_02",
	"prop_ventsystem_03",
	"prop_ventsystem_04",
	"prop_wall_vent_01",
	"prop_wall_vent_02",
	"prop_wall_vent_03",
	"prop_wall_vent_04",
	"prop_wall_vent_05",
	"prop_wall_vent_06",
	"prop_watertower01",
	"prop_watertower02",
	"prop_watertower03",
	"prop_watertower04",
	"prop_bahammenu",
	"prop_barrachneon",
	"prop_bar_coastbarr",
	"prop_bar_coastchamp",
	"prop_bar_coastdusc",
	"prop_bar_coastmount",
	"prop_bar_cooler_01",
	"prop_bar_cooler_03",
	"prop_bar_fridge_01",
	"prop_bar_fridge_02",
	"prop_bar_fridge_03",
	"prop_bar_fridge_04",
	"prop_bar_ice_01",
	"prop_bar_napkindisp",
	"prop_bar_pump_01",
	"prop_bar_pump_04",
	"prop_bar_pump_05",
	"prop_bar_pump_06",
	"prop_bar_pump_07",
	"prop_bar_pump_08",
	"prop_bar_pump_09",
	"prop_bar_pump_10",
	"prop_bar_sink_01",
	"prop_bar_stool_01",
	"prop_beerneon",
	"prop_beer_bison",
	"prop_cherenneon",
	"prop_cockneon",
	"prop_cs_kitchen_cab_l2",
	"prop_cs_kitchen_cab_ld",
	"prop_cs_kitchen_cab_rd",
	"prop_irish_sign_01",
	"prop_irish_sign_02",
	"prop_irish_sign_03",
	"prop_irish_sign_04",
	"prop_irish_sign_05",
	"prop_irish_sign_06",
	"prop_irish_sign_07",
	"prop_irish_sign_08",
	"prop_irish_sign_09",
	"prop_irish_sign_10",
	"prop_irish_sign_11",
	"prop_irish_sign_12",
	"prop_irish_sign_13",
	"prop_loggneon",
	"prop_patriotneon",
	"prop_pitcher_01_cs",
	"prop_ragganeon",
	"prop_shots_glass_cs",
	"prop_stripmenu",
	"prop_bread_rack_01",
	"prop_bread_rack_02",
	"prop_chip_fryer",
	"prop_coffee_mac_02",
	"prop_detergent_01a",
	"prop_detergent_01b",
	"prop_ff_counter_01",
	"prop_ff_counter_02",
	"prop_ff_counter_03",
	"prop_ff_noodle_01",
	"prop_ff_noodle_02",
	"prop_ff_shelves_01",
	"prop_ff_sink_01",
	"prop_ff_sink_02",
	"prop_food_bin_01",
	"prop_food_bin_02",
	"prop_food_bs_bshelf",
	"prop_food_bs_cups01",
	"prop_food_bs_cups03",
	"prop_food_bs_soda_01",
	"prop_food_bs_soda_02",
	"prop_food_bs_tray_01",
	"prop_food_bs_tray_06",
	"prop_food_burg1",
	"prop_food_burg2",
	"prop_food_cb_bshelf",
	"prop_food_cb_burg01",
	"prop_food_cb_cups01",
	"prop_food_cb_donuts",
	"prop_food_cb_nugets",
	"prop_food_cb_soda_01",
	"prop_food_cb_soda_02",
	"prop_food_cb_tray_01",
	"prop_food_cups1",
	"prop_food_napkin_01",
	"prop_food_napkin_02",
	"prop_food_tray_01",
	"prop_griddle_01",
	"prop_griddle_02",
	"prop_handtowels",
	"prop_juice_dispenser",
	"prop_kebab_grill",
	"prop_microwave_1",
	"prop_pizza_oven_01",
	"prop_slush_dispenser",
	"prop_bumper_01",
	"prop_bumper_02",
	"prop_bumper_03",
	"prop_bumper_04",
	"prop_bumper_05",
	"prop_bumper_06",
	"prop_carcreeper",
	"prop_carjack",
	"prop_carjack_l2",
	"prop_car_battery_01",
	"prop_car_bonnet_01",
	"prop_car_bonnet_02",
	"prop_car_door_01",
	"prop_car_door_02",
	"prop_car_door_03",
	"prop_car_door_04",
	"prop_car_engine_01",
	"prop_car_exhaust_01",
	"prop_car_seat",
	"prop_cheetah_covered",
	"prop_compressor_01",
	"prop_compressor_02",
	"prop_compressor_03",
	"prop_entityxf_covered",
	"prop_jb700_covered",
	"prop_spray_jackframe",
	"prop_spray_jackleg",
	"prop_toolchest_01",
	"prop_toolchest_02",
	"prop_toolchest_03",
	"prop_toolchest_04",
	"prop_toolchest_05",
	"prop_wheel_01",
	"prop_wheel_02",
	"prop_wheel_03",
	"prop_wheel_04",
	"prop_wheel_05",
	"prop_wheel_06",
	"prop_wheel_hub_01",
	"prop_wheel_hub_02_lod_02",
	"prop_wheel_rim_01",
	"prop_wheel_rim_02",
	"prop_wheel_rim_03",
	"prop_wheel_rim_04",
	"prop_wheel_rim_05",
	"prop_wheel_tyre",
	"prop_ztype_covered",
	"prop_cabinet_01",
	"prop_cabinet_01b",
	"prop_cabinet_02b",
	"prop_coathook_01",
	"prop_copier_01",
	"prop_fan_01",
	"prop_fax_01",
	"prop_folder_01",
	"prop_folder_02",
	"prop_in_tray_01",
	"prop_office_alarm_01",
	"prop_office_desk_01",
	"prop_off_chair_01",
	"prop_off_chair_03",
	"prop_off_chair_04",
	"prop_off_chair_04b",
	"prop_off_chair_05",
	"prop_off_phone_01",
	"prop_paper_box_01",
	"prop_paper_box_02",
	"prop_paper_box_03",
	"prop_paper_box_04",
	"prop_paper_box_05",
	"prop_printer_01",
	"prop_printer_02",
	"prop_shredder_01",
	"prop_sol_chair",
	"prop_tablesmall_01",
	"prop_waiting_seat_01",
	"prop_wait_bench_01",
	"prop_water_bottle",
	"prop_water_bottle_dark",
	"prop_air_bagloader",
	"prop_air_bagloader2",
	"prop_air_barrier",
	"prop_air_bench_01",
	"prop_air_bench_02",
	"prop_air_bigradar_l1",
	"prop_air_bigradar_l2",
	"prop_air_bigradar_slod",
	"prop_air_blastfence_01",
	"prop_air_blastfence_02",
	"prop_air_bridge01",
	"prop_air_bridge02",
	"prop_air_cargoloader_01",
	"prop_air_cargo_01a",
	"prop_air_cargo_01b",
	"prop_air_cargo_01c",
	"prop_air_cargo_02a",
	"prop_air_cargo_02b",
	"prop_air_cargo_03a",
	"prop_air_cargo_04a",
	"prop_air_cargo_04b",
	"prop_air_cargo_04c",
	"prop_air_chock_01",
	"prop_air_chock_03",
	"prop_air_chock_04",
	"prop_air_fueltrail1",
	"prop_air_fueltrail2",
	"prop_air_gasbogey_01",
	"prop_air_generator_01",
	"prop_air_generator_03",
	"prop_air_lights_01a",
	"prop_air_lights_01b",
	"prop_air_lights_03a",
	"prop_air_luggtrolley",
	"prop_air_mast_01",
	"prop_air_mast_02",
	"prop_air_monhut_01",
	"prop_air_monhut_02",
	"prop_air_monhut_03",
	"prop_air_propeller01",
	"prop_air_radar_01",
	"prop_air_stair_01",
	"prop_air_stair_02",
	"prop_air_stair_03",
	"prop_air_stair_04a",
	"prop_air_stair_04b",
	"prop_air_towbar_01",
	"prop_air_towbar_02",
	"prop_air_towbar_03",
	"prop_air_trailer_4a",
	"prop_air_trailer_4b",
	"prop_air_trailer_4c",
	"prop_air_watertank1",
	"prop_air_watertank2",
	"prop_air_windsock_base",
	"prop_air_woodsteps",
	"prop_luggage_01a",
	"prop_luggage_02a",
	"prop_luggage_03a",
	"prop_luggage_04a",
	"prop_luggage_05a",
	"prop_luggage_06a",
	"prop_luggage_07a",
	"prop_luggage_08a",
	"prop_luggage_09a",
	"prop_mb_cargo_01a",
	"prop_mb_cargo_02a",
	"prop_mb_cargo_03a",
	"prop_mb_cargo_04a",
	"prop_mb_cargo_04b",
	"prop_mb_crate_01a",
	"prop_mb_crate_01b",
	"prop_mb_hesco_06",
	"prop_mb_ordnance_01",
	"prop_mb_ordnance_03",
	"prop_mb_sandblock_01",
	"prop_mb_sandblock_02",
	"prop_mb_sandblock_03",
	"prop_mb_sandblock_04",
	"prop_mb_sandblock_05",
	"prop_boxcar5_handle",
	"prop_byard_bench01",
	"prop_byard_bench02",
	"prop_byard_block_01",
	"prop_byard_boat01",
	"prop_byard_boat02",
	"prop_byard_chains01",
	"prop_byard_dingy",
	"prop_byard_elecbox01",
	"prop_byard_elecbox02",
	"prop_byard_elecbox03",
	"prop_byard_elecbox04",
	"prop_byard_floatpile",
	"prop_byard_float_01",
	"prop_byard_float_01b",
	"prop_byard_float_02",
	"prop_byard_float_02b",
	"prop_byard_hoist",
	"prop_byard_hoist_2",
	"prop_byard_hoses01",
	"prop_byard_hoses02",
	"prop_byard_ladder01",
	"prop_byard_machine01",
	"prop_byard_machine02",
	"prop_byard_machine03",
	"prop_byard_motor_01",
	"prop_byard_motor_02",
	"prop_byard_motor_03",
	"prop_byard_net02",
	"prop_byard_phone",
	"prop_byard_pipes01",
	"prop_byard_pipe_01",
	"prop_byard_planks01",
	"prop_byard_pulley01",
	"prop_byard_rack",
	"prop_byard_ramp",
	"prop_byard_rampold",
	"prop_byard_rowboat1",
	"prop_byard_rowboat2",
	"prop_byard_rowboat3",
	"prop_byard_rowboat4",
	"prop_byard_rowboat5",
	"prop_byard_scfhold01",
	"prop_byard_sleeper01",
	"prop_byard_sleeper02",
	"prop_byard_steps_01",
	"prop_byard_tank_01",
	"prop_byard_trailer01",
	"prop_byard_trailer02",
	"prop_crane_01_truck1",
	"prop_crane_01_truck2",
	"prop_dock_bouy_1",
	"prop_dock_bouy_2",
	"prop_dock_bouy_3",
	"prop_dock_bouy_5",
	"prop_dock_crane_01",
	"prop_dock_crane_02",
	"prop_dock_crane_02_cab",
	"prop_dock_crane_02_hook",
	"prop_dock_crane_02_ld",
	"prop_dock_crane_04",
	"prop_dock_crane_lift",
	"prop_dock_float_1",
	"prop_dock_float_1b",
	"prop_dock_moor_01",
	"prop_dock_moor_04",
	"prop_dock_moor_05",
	"prop_dock_moor_06",
	"prop_dock_moor_07",
	"prop_dock_ropefloat",
	"prop_dock_ropetyre1",
	"prop_dock_ropetyre2",
	"prop_dock_ropetyre3",
	"prop_dock_rtg_01",
	"prop_dock_rtg_ld",
	"prop_dock_shippad",
	"prop_dock_sign_01",
	"prop_dock_woodpole1",
	"prop_dock_woodpole2",
	"prop_dock_woodpole3",
	"prop_dock_woodpole4",
	"prop_dock_woodpole5",
	"prop_ind_barge_01",
	"prop_ind_barge_02",
	"prop_ind_coalcar_01",
	"prop_ind_coalcar_02",
	"prop_ind_coalcar_03",
	"prop_ind_oldcrane",
	"prop_jetski_ramp_01",
	"prop_railsleepers01",
	"prop_railsleepers02",
	"prop_railstack01",
	"prop_railstack02",
	"prop_railstack03",
	"prop_railstack04",
	"prop_railstack05",
	"prop_rail_boxcar",
	"prop_rail_boxcar2",
	"prop_rail_boxcar3",
	"prop_rail_boxcar4",
	"prop_rail_boxcar5",
	"prop_rail_boxcar5_d",
	"prop_rail_buffer_01",
	"prop_rail_buffer_02",
	"prop_rail_crane_01",
	"prop_rail_points01",
	"prop_rail_points02",
	"prop_rail_sigbox01",
	"prop_rail_sigbox02",
	"prop_rail_signals02",
	"prop_rail_tankcar",
	"prop_rail_tankcar2",
	"prop_rail_tankcar3",
	"prop_rail_wellcar",
	"prop_rail_wellcar2",
	"p_dock_rtg_ld_cab",
	"p_dock_rtg_ld_spdr",
	"p_dock_rtg_ld_wheel",
	"prop_fac_machine_02",
	"prop_ind_conveyor_01",
	"prop_ind_conveyor_02",
	"prop_ind_conveyor_04",
	"prop_ind_crusher",
	"prop_ind_deiseltank",
	"prop_ind_mech_01c",
	"prop_ind_mech_02a",
	"prop_ind_mech_02b",
	"prop_ind_mech_03a",
	"prop_ind_mech_04a",
	"prop_jyard_block_01a",
	"prop_oil_derrick_01",
	"prop_oil_guage_01",
	"prop_oil_spool_02",
	"prop_oil_valve_01",
	"prop_oil_valve_02",
	"prop_oil_wellhead_01",
	"prop_oil_wellhead_03",
	"prop_oil_wellhead_04",
	"prop_oil_wellhead_05",
	"prop_oil_wellhead_06",
	"prop_portacabin01",
	"prop_portasteps_01",
	"prop_portasteps_02",
	"prop_pylon_01",
	"prop_pylon_02",
	"prop_pylon_03",
	"prop_pylon_04",
	"prop_sluicegate",
	"prop_sluicegatel",
	"prop_sluicegater",
	"prop_storagetank_01",
	"prop_storagetank_02",
	"prop_storagetank_03",
	"prop_storagetank_03a",
	"prop_storagetank_03b",
	"prop_storagetank_04",
	"prop_storagetank_05",
	"prop_storagetank_06",
	"prop_storagetank_07a",
	"prop_sub_crane_hook",
	"prop_sub_frame_01a",
	"prop_sub_frame_01b",
	"prop_sub_frame_01c",
	"prop_sub_frame_02a",
	"prop_sub_frame_03a",
	"prop_sub_frame_04a",
	"prop_sub_frame_04b",
	"prop_sub_gantry",
	"prop_sub_trans_01a",
	"prop_sub_trans_02a",
	"prop_sub_trans_03a",
	"prop_sub_trans_04a",
	"prop_sub_trans_05b",
	"prop_sub_trans_06b",
	"prop_windmill_01_l1",
	"prop_windmill_01_slod",
	"prop_windmill_01_slod2",
	"prop_acc_guitar_01",
	"prop_acc_guitar_01_d1",
	"prop_alien_egg_01",
	"prop_amb_handbag_01",
	"prop_amb_phone",
	"prop_asteroid_01",
	"prop_attache_case_01",
	"prop_bank_shutter",
	"prop_bank_vaultdoor",
	"prop_barrel_float_1",
	"prop_barrel_float_2",
	"prop_beggers_sign_01",
	"prop_beggers_sign_02",
	"prop_beggers_sign_03",
	"prop_beggers_sign_04",
	"prop_bh1_16_display",
	"prop_big_bag_01",
	"prop_big_clock_01",
	"prop_biotech_store",
	"prop_bomb_01",
	"prop_bonesaw",
	"prop_bskball_01",
	"prop_b_board_blank",
	"prop_cable_hook_01",
	"prop_camera_strap",
	"prop_cash_dep_bag_01",
	"prop_cash_trolly",
	"prop_chem_grill",
	"prop_chem_grill_bit",
	"prop_chem_vial_02",
	"prop_chem_vial_02b",
	"prop_choc_ego",
	"prop_choc_meto",
	"prop_choc_pq",
	"prop_clapper_brd_01",
	"prop_cone_float_1",
	"prop_container_hole",
	"prop_cont_chiller_01",
	"prop_cork_board",
	"prop_cranial_saw",
	"prop_crate_float_1",
	"prop_cs_20m_rope",
	"prop_cs_30m_rope",
	"prop_cs_aircon_01",
	"prop_cs_aircon_fan",
	"prop_cs_ashtray",
	"prop_cs_bin_01",
	"prop_cs_bin_01_lid",
	"prop_cs_bin_02",
	"prop_cs_bin_03",
	"prop_cs_box_clothes",
	"prop_cs_cardbox_01",
	"prop_cs_dumpster_01a",
	"prop_cs_dumpster_lidl",
	"prop_cs_dumpster_lidr",
	"prop_cs_fertilizer",
	"prop_cs_folding_chair_01",
	"prop_cs_fridge",
	"prop_cs_fridge_door",
	"prop_cs_heist_bag_01",
	"prop_cs_heist_bag_02",
	"prop_cs_heist_bag_strap_01",
	"prop_cs_h_bag_strap_01",
	"prop_cs_ice_locker",
	"prop_cs_ice_locker_door_l",
	"prop_cs_ice_locker_door_r",
	"prop_cs_keys_01",
	"prop_cs_leaf",
	"prop_cs_office_chair",
	"prop_cs_package_01",
	"prop_cs_panel_01",
	"prop_cs_panties",
	"prop_cs_panties_02",
	"prop_cs_panties_03",
	"prop_cs_planning_photo",
	"prop_cs_polaroid",
	"prop_cs_remote_01",
	"prop_cs_rope_tie_01",
	"prop_cs_rub_binbag_01",
	"prop_cs_scissors",
	"prop_cs_shopping_bag",
	"prop_cs_spray_can",
	"prop_cs_tablet",
	"prop_cs_tablet_02",
	"prop_cs_vial_01",
	"prop_cs_walking_stick",
	"prop_cub_door_lifeblurb",
	"prop_cub_lifeblurb",
	"prop_cuff_keys_01",
	"prop_defilied_ragdoll_01",
	"prop_drop_armscrate_01",
	"prop_drop_armscrate_01b",
	"prop_dummy_01",
	"prop_dummy_light",
	"prop_dummy_plane",
	"prop_egg_clock_01",
	"prop_ejector_seat_01",
	"prop_el_guitar_01",
	"prop_el_guitar_02",
	"prop_el_guitar_03",
	"prop_fbibombbin",
	"prop_fbibombcupbrd",
	"prop_fbibombfile",
	"prop_fbibombplant",
	"prop_feed_sack_01",
	"prop_feed_sack_02",
	"prop_fib_broken_window",
	"prop_flash_unit",
	"prop_flatbed_strap_b",
	"prop_floor_duster_01",
	"prop_folded_polo_shirt",
	"prop_foundation_sponge",
	"prop_fruit_basket",
	"prop_f_duster_02",
	"prop_gascyl_ramp_01",
	"prop_gascyl_ramp_door_01",
	"prop_gas_grenade",
	"prop_gas_mask_hang_01",
	"prop_gold_bar",
	"prop_gold_trolly",
	"prop_gold_trolly_full",
	"prop_grapes_01",
	"prop_grapes_02",
	"prop_hacky_sack_01",
	"prop_hd_seats_01",
	"prop_hole_plug_01",
	"prop_hotel_clock_01",
	"prop_hotel_trolley",
	"prop_huge_display_01",
	"prop_huge_display_02",
	"prop_idol_01_error",
	"prop_idol_case_01",
	"prop_ing_camera_01",
	"prop_int_gate01",
	"prop_jewel_02a",
	"prop_jewel_02b",
	"prop_jewel_02c",
	"prop_jewel_03a",
	"prop_jewel_03b",
	"prop_jewel_04a",
	"prop_jewel_04b",
	"prop_jewel_pickup_new_01",
	"prop_j_disptray_01",
	"prop_j_disptray_01b",
	"prop_j_disptray_01_dam",
	"prop_j_disptray_02",
	"prop_j_disptray_02_dam",
	"prop_j_disptray_03",
	"prop_j_disptray_03_dam",
	"prop_j_disptray_04",
	"prop_j_disptray_04b",
	"prop_j_disptray_05",
	"prop_j_disptray_05b",
	"prop_j_heist_pic_01",
	"prop_j_heist_pic_02",
	"prop_j_heist_pic_03",
	"prop_j_heist_pic_04",
	"prop_j_neck_disp_01",
	"prop_j_neck_disp_02",
	"prop_j_neck_disp_03",
	"prop_large_gold",
	"prop_large_gold_alt_a",
	"prop_large_gold_alt_b",
	"prop_large_gold_alt_c",
	"prop_large_gold_empty",
	"prop_ld_alarm_01",
	"prop_ld_alarm_01_dam",
	"prop_ld_alarm_alert",
	"prop_ld_armour",
	"prop_ld_binbag_01",
	"prop_ld_bomb",
	"prop_ld_cable",
	"prop_ld_cable_tie_01",
	"prop_ld_case_01",
	"prop_ld_case_01_lod",
	"prop_ld_container",
	"prop_ld_contain_dl",
	"prop_ld_contain_dl2",
	"prop_ld_contain_dr",
	"prop_ld_contain_dr2",
	"prop_ld_crate_01",
	"prop_ld_crate_lid_01",
	"prop_ld_fan_01",
	"prop_ld_fan_01_old",
	"prop_ld_greenscreen_01",
	"prop_ld_handbag",
	"prop_ld_haybail",
	"prop_ld_health_pack",
	"prop_ld_hook",
	"prop_ld_int_safe_01",
	"prop_ld_jerrycan_01",
	"prop_ld_keypad_01",
	"prop_ld_keypad_01b",
	"prop_ld_keypad_01b_lod",
	"prop_ld_lap_top",
	"prop_ld_monitor_01",
	"prop_ld_pipe_single_01",
	"prop_ld_planning_pin_01",
	"prop_ld_planning_pin_02",
	"prop_ld_planning_pin_03",
	"prop_ld_purse_01",
	"prop_ld_purse_01_lod",
	"prop_ld_rope_t",
	"prop_ld_rub_binbag_01",
	"prop_ld_suitcase_01",
	"prop_ld_suitcase_02",
	"prop_ld_toilet_01",
	"prop_ld_vault_door",
	"prop_ld_wallet_01",
	"prop_ld_w_me_machette",
	"prop_lectern_01",
	"prop_lev_crate_01",
	"prop_lifeblurb_01",
	"prop_lifeblurb_01b",
	"prop_lifeblurb_02",
	"prop_lifeblurb_02b",
	"prop_mast_01",
	"prop_medal_01",
	"prop_med_bag_01",
	"prop_med_bag_01b",
	"prop_michael_backpack",
	"prop_mr_rasberryclean",
	"prop_mr_raspberry_01",
	"prop_muster_wboard_01",
	"prop_muster_wboard_02",
	"prop_necklace_board",
	"prop_new_drug_pack_01",
	"prop_night_safe_01",
	"prop_novel_01",
	"prop_npc_phone",
	"prop_npc_phone_02",
	"prop_out_door_speaker",
	"prop_overalls_01",
	"prop_paper_bag_01",
	"prop_paper_bag_small",
	"prop_paper_ball",
	"prop_pap_camera_01",
	"prop_parachute",
	"prop_parapack_01",
	"prop_paynspray_door_l",
	"prop_paynspray_door_r",
	"prop_ped_pic_01",
	"prop_ped_pic_01_sm",
	"prop_ped_pic_02",
	"prop_ped_pic_02_sm",
	"prop_ped_pic_03",
	"prop_ped_pic_03_sm",
	"prop_ped_pic_04",
	"prop_ped_pic_04_sm",
	"prop_ped_pic_05",
	"prop_ped_pic_05_sm",
	"prop_ped_pic_06",
	"prop_ped_pic_06_sm",
	"prop_ped_pic_07",
	"prop_ped_pic_07_sm",
	"prop_ped_pic_08",
	"prop_ped_pic_08_sm",
	"prop_phone_ing",
	"prop_phone_ing_02",
	"prop_phone_ing_03",
	"prop_phone_overlay_01",
	"prop_phone_overlay_02",
	"prop_phone_overlay_anim",
	"prop_phone_proto",
	"prop_phone_proto_back",
	"prop_phone_proto_battery",
	"prop_player_phone_01",
	"prop_player_phone_02",
	"prop_podium_mic",
	"prop_police_phone",
	"prop_poly_bag_01",
	"prop_poly_bag_money",
	"prop_pool_ball_01",
	"prop_postit_drive",
	"prop_postit_gun",
	"prop_postit_it",
	"prop_postit_lock",
	"prop_prologue_phone",
	"prop_protest_sign_01",
	"prop_protest_table_01",
	"prop_prototype_minibomb",
	"prop_rag_01",
	"prop_rf_conc_pillar",
	"prop_riding_crop_01",
	"prop_rock_chair_01",
	"prop_rolled_yoga_mat",
	"prop_rope_hook_01",
	"prop_scalpel",
	"prop_scrap_win_01",
	"prop_security_case_01",
	"prop_security_case_02",
	"prop_shamal_crash",
	"prop_shopping_bags01",
	"prop_shopping_bags02",
	"prop_showroom_glass_1b",
	"prop_side_lights",
	"prop_single_rose",
	"prop_sky_cover_01",
	"prop_sm_19_clock",
	"prop_sm_locker_door",
	"prop_spot_01",
	"prop_spot_clamp",
	"prop_spot_clamp_02",
	"prop_stat_pack_01",
	"prop_strip_pole_01",
	"prop_sub_chunk_01",
	"prop_tail_gate_col",
	"prop_taxi_meter_1",
	"prop_taxi_meter_2",
	"prop_telescope_01",
	"prop_tennis_bag_01",
	"prop_test_elevator",
	"prop_test_elevator_dl",
	"prop_test_elevator_dr",
	"prop_tick",
	"prop_tick_02",
	"prop_toiletfoot_static",
	"prop_torture_ch_01",
	"prop_tri_table_01",
	"prop_tyre_spike_01",
	"prop_t_coffe_table",
	"prop_t_sofa",
	"prop_t_sofa_02",
	"prop_t_telescope_01b",
	"prop_vb_34_tencrt_lighting",
	"prop_vehicle_hook",
	"prop_v_bmike_01",
	"prop_v_cam_01",
	"prop_v_hook_s",
	"prop_v_m_phone_01",
	"prop_v_parachute",
	"prop_water_ramp_01",
	"prop_water_ramp_02",
	"prop_water_ramp_03",
	"prop_wheelchair_01",
	"prop_windowbox_a",
	"prop_windowbox_b",
	"prop_windowbox_broken",
	"prop_windowbox_small",
	"prop_win_trailer_ld",
	"prop_w_board_blank",
	"prop_w_board_blank_2",
	"prop_yoga_mat_01",
	"prop_yoga_mat_02",
	"prop_yoga_mat_03",
	"p_amb_bag_bottle_01",
	"p_amb_brolly_01",
	"p_amb_brolly_01_s",
	"p_amb_clipboard_01",
	"p_amb_coffeecup_01",
	"p_amb_joint_01",
	"p_amb_lap_top_01",
	"p_amb_lap_top_02",
	"p_amb_phone_01",
	"p_car_keys_01",
	"p_counter_01_glass",
	"p_counter_01_glass_plug",
	"p_counter_02_glass",
	"p_counter_03_glass",
	"p_counter_04_glass",
	"p_cs_cam_phone",
	"p_cs_comb_01",
	"p_cs_laptop_02",
	"p_cs_laptop_02_w",
	"p_cs_locker_01",
	"p_cs_locker_02",
	"p_cs_locker_door_01",
	"p_cs_locker_door_01b",
	"p_cs_locker_door_02",
	"p_cs_paper_disp_02",
	"p_cs_paper_disp_1",
	"p_disp_02_door_01",
	"p_ferris_car_01",
	"p_f_duster_handle_01",
	"p_f_duster_head_01",
	"p_ing_skiprope_01",
	"p_int_jewel_mirror",
	"p_int_jewel_plant_01",
	"p_int_jewel_plant_02",
	"p_jewel_necklace_02",
	"p_ld_am_ball_01",
	"p_ld_coffee_vend_01",
	"p_ld_conc_cyl_01",
	"p_ld_frisbee_01",
	"p_ld_heist_bag_01",
	"p_ld_sax",
	"p_ld_soc_ball_01",
	"p_new_j_counter_01",
	"p_new_j_counter_02",
	"p_new_j_counter_03",
	"p_num_plate_01",
	"p_num_plate_02",
	"p_num_plate_03",
	"p_num_plate_04",
	"p_oil_slick_01",
	"p_pharm_unit_01",
	"p_pharm_unit_02",
	"p_planning_board_01",
	"p_planning_board_02",
	"p_planning_board_03",
	"p_planning_board_04",
	"p_secret_weapon_02",
	"p_stinger_02",
	"p_stinger_03",
	"p_stinger_04",
	"p_stinger_piece_01",
	"p_stinger_piece_02",
	"p_watch_01",
	"p_watch_02",
	"p_watch_03",
	"p_watch_04",
	"p_watch_05",
	"p_watch_06",
	"prop_bomb_01_s",
	"prop_cs_bin_01_skinned",
	"prop_cs_bucket_s",
	"prop_cs_bucket_s_lod",
	"prop_cs_mop_s",
	"prop_f_duster_01_s",
	"prop_ld_case_01_s",
	"prop_ld_handbag_s",
	"prop_ld_wallet_01_s",
	"prop_news_disp_02a_s",
	"prop_off_chair_04_s",
	"prop_p_jack_03_col",
	"prop_rub_binbag_sd_01",
	"prop_rub_binbag_sd_02",
	"prop_v_m_phone_o1s",
	"p_abat_roller_1",
	"p_abat_roller_1_col",
	"p_amb_drain_water_double",
	"p_amb_drain_water_longstrip",
	"p_amb_drain_water_single",
	"p_attache_case_01_s",
	"p_balaclavamichael_s",
	"p_barierbase_test_s",
	"p_barier_test_s",
	"p_beefsplitter_s",
	"p_cargo_chute_s",
	"p_cigar_pack_02_s",
	"p_cs_locker_01_s",
	"p_cs_script_bottle_s",
	"p_dock_crane_cable_s",
	"p_dock_crane_cabl_s",
	"p_dock_crane_sld_s",
	"p_dumpster_t",
	"p_fag_packet_01_s",
	"p_ferris_wheel_amo_l",
	"p_ferris_wheel_amo_l2",
	"p_ferris_wheel_amo_p",
	"p_gar_door_01_s",
	"p_gar_door_02_s",
	"p_gar_door_03_s",
	"p_gdoor1colobject_s",
	"p_gdoor1_s",
	"p_ing_skiprope_01_s",
	"p_jewel_necklace01_s",
	"p_jewel_necklace02_s",
	"p_jewel_pickup33_s",
	"p_ld_coffee_vend_s",
	"p_ld_heist_bag_s",
	"p_ld_stinger_s",
	"p_litter_picker_s",
	"p_mast_01_s",
	"p_notepad_01_s",
	"p_oil_pjack_01_amo",
	"p_oil_pjack_01_frg_s",
	"p_oil_pjack_02_amo",
	"p_oil_pjack_02_frg_s",
	"p_oil_pjack_03_amo",
	"p_oil_pjack_03_frg_s",
	"p_pallet_02a_s",
	"p_panties_s",
	"p_parachute1_mp_s",
	"p_parachute1_s",
	"p_parachute1_sp_s",
	"p_parachute_fallen_s",
	"p_parachute_s",
	"p_parachute_s_shop",
	"p_para_broken1_s",
	"p_patio_lounger1_s",
	"p_phonebox_02_s",
	"p_pliers_01_s",
	"p_rcss_folded",
	"p_rcss_s",
	"p_ringbinder_01_s",
	"p_sec_gate_01_s",
	"p_sec_gate_01_s_col",
	"p_shoalfish_s",
	"p_skiprope_r_s",
	"p_sofa_s",
	"p_sub_crane_s",
	"p_sunglass_m_s",
	"p_tennis_bag_01_s",
	"p_tram_crash_s",
	"p_watch_01_s",
	"p_watch_02_s",
	"p_watch_03_s",
	"p_waterboardc_s",
	"p_yacht_chair_01_s",
	"p_yacht_sofa_01_s",
	"p_yoga_mat_01_s",
	"p_yoga_mat_02_s",
	"p_yoga_mat_03_s",
	"pop_v_bank_door_l",
	"pop_v_bank_door_r",
	"prop_abat_roller_static",
	"prop_abat_slide",
	"prop_artgallery_02_dl",
	"prop_artgallery_02_dr",
	"prop_artgallery_dl",
	"prop_artgallery_dr",
	"prop_barn_door_l",
	"prop_barn_door_r",
	"prop_bh1_03_gate_l",
	"prop_bh1_03_gate_r",
	"prop_bh1_08_mp_gar",
	"prop_bh1_09_mp_gar",
	"prop_bh1_09_mp_l",
	"prop_bh1_09_mp_r",
	"prop_bh1_44_door_01l",
	"prop_bh1_44_door_01r",
	"prop_bh1_48_backdoor_l",
	"prop_bh1_48_backdoor_r",
	"prop_bh1_48_gate_1",
	"prop_bhhotel_door_l",
	"prop_bhhotel_door_r",
	"prop_biolab_g_door",
	"prop_broken_cell_gate_01",
	"prop_bs_map_door_01",
	"prop_burto_gate_01",
	"prop_casino_door_01l",
	"prop_casino_door_01r",
	"prop_ch1_07_door_01l",
	"prop_ch1_07_door_01r",
	"prop_ch1_07_door_02l",
	"prop_ch1_07_door_02r",
	"prop_ch2_05d_g_door",
	"prop_ch2_07b_20_g_door",
	"prop_ch2_09b_door",
	"prop_ch2_09c_garage_door",
	"prop_ch3_01_trlrdoor_l",
	"prop_ch3_01_trlrdoor_r",
	"prop_ch3_04_door_01l",
	"prop_ch3_04_door_01r",
	"prop_ch3_04_door_02",
	"prop_ch_025c_g_door_01",
	"prop_com_gar_door_01",
	"prop_com_ls_door_01",
	"prop_control_rm_door_01",
	"prop_cs1_14b_traind",
	"prop_cs1_14b_traind_dam",
	"prop_cs4_05_tdoor",
	"prop_cs4_10_tr_gd_01",
	"prop_cs4_11_door",
	"prop_cs6_03_door_l",
	"prop_cs6_03_door_r",
	"prop_cs_freightdoor_l1",
	"prop_cs_freightdoor_r1",
	"prop_cs_gravyard_gate_l",
	"prop_cs_gravyard_gate_r",
	"prop_cs_sc1_11_gate",
	"prop_cs_sm_27_gate",
	"prop_damdoor_01",
	"prop_door_01",
	"prop_door_balcony_frame",
	"prop_door_balcony_left",
	"prop_door_balcony_right",
	"prop_dt1_20_mp_door_l",
	"prop_dt1_20_mp_door_r",
	"prop_dt1_20_mp_gar",
	"prop_d_balcony_l_light",
	"prop_d_balcony_r_light",
	"prop_epsilon_door_l",
	"prop_epsilon_door_r",
	"prop_faceoffice_door_l",
	"prop_faceoffice_door_r",
	"prop_gar_door_01",
	"prop_gar_door_02",
	"prop_gar_door_03",
	"prop_gar_door_03_ld",
	"prop_gar_door_04",
	"prop_gar_door_05",
	"prop_gar_door_05_l",
	"prop_gar_door_05_r",
	"prop_gar_door_a_01",
	"prop_gar_door_plug",
	"prop_gd_ch2_08",
	"prop_grumandoor_l",
	"prop_grumandoor_r",
	"prop_hanger_door_1",
	"prop_hospitaldoors_start",
	"prop_hospital_door_l",
	"prop_hospital_door_r",
	"prop_hw1_03_gardoor_01",
	"prop_hw1_04_door_l1",
	"prop_hw1_04_door_r1",
	"prop_hw1_23_door",
	"prop_id2_11_gdoor",
	"prop_id_21_gardoor_01",
	"prop_id_21_gardoor_02",
	"prop_indus_meet_door_l",
	"prop_indus_meet_door_r",
	"prop_kt1_06_door_l",
	"prop_kt1_06_door_r",
	"prop_kt1_10_mpdoor_l",
	"prop_kt1_10_mpdoor_r",
	"prop_ld_garaged_01",
	"prop_ld_jail_door",
	"prop_magenta_door",
	"prop_map_door_01",
	"prop_michael_door",
	"prop_motel_door_09",
	"prop_police_door_l",
	"prop_police_door_l_dam",
	"prop_police_door_r",
	"prop_police_door_r_dam",
	"prop_police_door_surround",
	"prop_pris_door_01_l",
	"prop_pris_door_01_r",
	"prop_pris_door_02",
	"prop_pris_door_03",
	"prop_ql_revolving_door",
	"prop_ret_door",
	"prop_ret_door_02",
	"prop_ret_door_03",
	"prop_ret_door_04",
	"prop_ron_door_01",
	"prop_sc1_06_gate_l",
	"prop_sc1_06_gate_r",
	"prop_sc1_12_door",
	"prop_sc1_21_g_door_01",
	"prop_section_garage_01",
	"prop_sec_gate_01b",
	"prop_sec_gate_01c",
	"prop_sec_gate_01d",
	"prop_showroom_door_l",
	"prop_showroom_door_r",
	"prop_sm1_11_doorl",
	"prop_sm1_11_doorr",
	"prop_sm1_11_garaged",
	"prop_sm_10_mp_door",
	"prop_sm_14_mp_gar",
	"prop_sm_27_door",
	"prop_sm_27_gate",
	"prop_sm_27_gate_02",
	"prop_sm_27_gate_03",
	"prop_sm_27_gate_04",
	"prop_ss1_05_mp_door",
	"prop_ss1_08_mp_door_l",
	"prop_ss1_08_mp_door_r",
	"prop_ss1_10_door_l",
	"prop_ss1_10_door_r",
	"prop_ss1_14_garage_door",
	"prop_ss1_mpint_door_l",
	"prop_ss1_mpint_door_r",
	"prop_ss1_mpint_garage",
	"prop_ss1_mpint_garage_cl",
	"prop_strip_door_01",
	"prop_vault_shutter",
	"prop_v_door_44",
	"prop_wardrobe_door_01",
	"prop_win_plug_01",
	"prop_win_plug_01_dam",
	"p_cut_door_01",
	"p_cut_door_02",
	"p_cut_door_03",
	"p_jewel_door_l",
	"p_jewel_door_r1",
	"prop_a4_pile_01",
	"prop_a4_sheet_01",
	"prop_a4_sheet_02",
	"prop_a4_sheet_03",
	"prop_a4_sheet_04",
	"prop_a4_sheet_05",
	"prop_aiprort_sign_01",
	"prop_aiprort_sign_02",
	"prop_amanda_note_01",
	"prop_amanda_note_01b",
	"prop_amb_40oz_02",
	"prop_amb_40oz_03",
	"prop_amb_beer_bottle",
	"prop_amb_ciggy_01",
	"prop_amb_donut",
	"prop_anim_cash_note",
	"prop_anim_cash_note_b",
	"prop_anim_cash_pile_01",
	"prop_anim_cash_pile_02",
	"prop_arc_blueprints_01",
	"prop_armour_pickup",
	"prop_artifact_01",
	"prop_ashtray_01",
	"prop_aviators_01",
	"prop_a_trailer_door_01",
	"prop_ballistic_shield",
	"prop_ballistic_shield_lod1",
	"prop_barry_table_detail",
	"prop_basejump_target_01",
	"prop_battery_01",
	"prop_battery_02",
	"prop_beer_box_01",
	"prop_beta_tape",
	"prop_big_shit_01",
	"prop_big_shit_02",
	"prop_binoc_01",
	"prop_bison_winch",
	"prop_blackjack_01",
	"prop_blox_spray",
	"prop_bodyarmour_02",
	"prop_bodyarmour_03",
	"prop_bodyarmour_04",
	"prop_bodyarmour_05",
	"prop_bodyarmour_06",
	"prop_bongos_01",
	"prop_bong_01",
	"prop_boombox_01",
	"prop_bottle_cap_01",
	"prop_bowl_crisps",
	"prop_broken_cboard_p1",
	"prop_broken_cboard_p2",
	"prop_busker_hat_01",
	"prop_c4_final",
	"prop_c4_final_green",
	"prop_candy_pqs",
	"prop_cargo_int",
	"prop_carrier_bag_01",
	"prop_carrier_bag_01_lod",
	"prop_carwash_roller_horz",
	"prop_carwash_roller_vert",
	"prop_car_ignition",
	"prop_casey_sec_id",
	"prop_cash_case_01",
	"prop_cash_case_02",
	"prop_cash_crate_01",
	"prop_cash_envelope_01",
	"prop_cash_note_01",
	"prop_cash_pile_01",
	"prop_cash_pile_02",
	"prop_ceramic_jug_01",
	"prop_ceramic_jug_cork",
	"prop_cigar_01",
	"prop_cigar_02",
	"prop_cigar_03",
	"prop_cigar_pack_01",
	"prop_cigar_pack_02",
	"prop_cliff_paper",
	"prop_clippers_01",
	"prop_coffee_cup_trailer",
	"prop_coffin_02",
	"prop_coffin_02b",
	"prop_coke_block_01",
	"prop_coke_block_half_a",
	"prop_coke_block_half_b",
	"prop_controller_01",
	"prop_crisp",
	"prop_crisp_small",
	"prop_cs_abattoir_switch",
	"prop_cs_amanda_shoe",
	"prop_cs_bandana",
	"prop_cs_bar",
	"prop_cs_beer_bot_01",
	"prop_cs_beer_bot_01b",
	"prop_cs_beer_bot_01lod",
	"prop_cs_beer_bot_02",
	"prop_cs_beer_bot_03",
	"prop_cs_beer_bot_40oz",
	"prop_cs_beer_bot_40oz_02",
	"prop_cs_beer_bot_40oz_03",
	"prop_cs_beer_bot_test",
	"prop_cs_binder_01",
	"prop_cs_book_01",
	"prop_cs_bottle_opener",
	"prop_cs_bowie_knife",
	"prop_cs_bowl_01",
	"prop_cs_bowl_01b",
	"prop_cs_box_step",
	"prop_cs_brain_chunk",
	"prop_cs_bs_cup",
	"prop_cs_burger_01",
	"prop_cs_business_card",
	"prop_cs_cash_note_01",
	"prop_cs_cctv",
	"prop_cs_champ_flute",
	"prop_cs_ciggy_01",
	"prop_cs_ciggy_01b",
	"prop_cs_clothes_box",
	"prop_cs_coke_line",
	"prop_cs_cont_latch",
	"prop_cs_crackpipe",
	"prop_cs_credit_card",
	"prop_cs_creeper_01",
	"prop_cs_crisps_01",
	"prop_cs_cuffs_01",
	"prop_cs_diaphram",
	"prop_cs_dildo_01",
	"prop_cs_documents_01",
	"prop_cs_dog_lead_2a",
	"prop_cs_dog_lead_2b",
	"prop_cs_dog_lead_2c",
	"prop_cs_dog_lead_3a",
	"prop_cs_dog_lead_3b",
	"prop_cs_dog_lead_a",
	"prop_cs_dog_lead_b",
	"prop_cs_dog_lead_c",
	"prop_cs_duffel_01",
	"prop_cs_duffel_01b",
	"prop_cs_dvd",
	"prop_cs_dvd_case",
	"prop_cs_envolope_01",
	"prop_cs_film_reel_01",
	"prop_cs_fork",
	"prop_cs_frank_photo",
	"prop_cs_fuel_hose",
	"prop_cs_fuel_nozle",
	"prop_cs_gascutter_1",
	"prop_cs_gascutter_2",
	"prop_cs_glass_scrap",
	"prop_cs_gunrack",
	"prop_cs_hand_radio",
	"prop_cs_heist_rope",
	"prop_cs_heist_rope_b",
	"prop_cs_hotdog_01",
	"prop_cs_hotdog_02",
	"prop_cs_ilev_blind_01",
	"prop_cs_ironing_board",
	"prop_cs_katana_01",
	"prop_cs_kettle_01",
	"prop_cs_lazlow_ponytail",
	"prop_cs_lazlow_shirt_01",
	"prop_cs_lazlow_shirt_01b",
	"prop_cs_leg_chain_01",
	"prop_cs_lester_crate",
	"prop_cs_lipstick",
	"prop_cs_magazine",
	"prop_cs_marker_01",
	"prop_cs_meth_pipe",
	"prop_cs_milk_01",
	"prop_cs_mini_tv",
	"prop_cs_mopbucket_01",
	"prop_cs_nail_file",
	"prop_cs_newspaper",
	"prop_cs_overalls_01",
	"prop_cs_padlock",
	"prop_cs_pamphlet_01",
	"prop_cs_paper_cup",
	"prop_cs_para_ropebit",
	"prop_cs_para_ropes",
	"prop_cs_pebble",
	"prop_cs_pebble_02",
	"prop_cs_petrol_can",
	"prop_cs_phone_01",
	"prop_cs_photoframe_01",
	"prop_cs_pills",
	"prop_cs_plane_int_01",
	"prop_cs_plate_01",
	"prop_cs_police_torch",
	"prop_cs_pour_tube",
	"prop_cs_power_cell",
	"prop_cs_power_cord",
	"prop_cs_protest_sign_01",
	"prop_cs_protest_sign_02",
	"prop_cs_protest_sign_02b",
	"prop_cs_protest_sign_03",
	"prop_cs_protest_sign_04a",
	"prop_cs_protest_sign_04b",
	"prop_cs_rage_statue_p1",
	"prop_cs_rage_statue_p2",
	"prop_cs_rolled_paper",
	"prop_cs_rub_box_01",
	"prop_cs_rub_box_02",
	"prop_cs_r_business_card",
	"prop_cs_sack_01",
	"prop_cs_saucer_01",
	"prop_cs_script_bottle",
	"prop_cs_script_bottle_01",
	"prop_cs_server_drive",
	"prop_cs_sheers",
	"prop_cs_shirt_01",
	"prop_cs_shot_glass",
	"prop_cs_silver_tray",
	"prop_cs_sink_filler",
	"prop_cs_sink_filler_02",
	"prop_cs_sink_filler_03",
	"prop_cs_sol_glasses",
	"prop_cs_steak",
	"prop_cs_stock_book",
	"prop_cs_street_binbag_01",
	"prop_cs_street_card_01",
	"prop_cs_street_card_02",
	"prop_cs_sub_hook_01",
	"prop_cs_sub_rope_01",
	"prop_cs_swipe_card",
	"prop_cs_toaster",
	"prop_cs_trolley_01",
	"prop_cs_trowel",
	"prop_cs_truck_ladder",
	"prop_cs_tshirt_ball_01",
	"prop_cs_t_shirt_pile",
	"prop_cs_valve",
	"prop_cs_vent_cover",
	"prop_cs_walkie_talkie",
	"prop_cs_whiskey_bottle",
	"prop_cs_whiskey_bot_stop",
	"prop_cs_wrench",
	"prop_devin_box_01",
	"prop_devin_rope_01",
	"prop_direct_chair_01",
	"prop_direct_chair_02",
	"prop_disp_razor_01",
	"prop_distantcar_day",
	"prop_distantcar_night",
	"prop_distantcar_truck",
	"prop_donut_01",
	"prop_donut_02",
	"prop_donut_02b",
	"prop_door_bell_01",
	"prop_double_grid_line",
	"prop_drug_package",
	"prop_drug_package_02",
	"prop_dummy_car",
	"prop_ear_defenders_01",
	"prop_ecg_01",
	"prop_ecg_01_cable_01",
	"prop_ecg_01_cable_02",
	"prop_ecola_can",
	"prop_employee_month_01",
	"prop_employee_month_02",
	"prop_energy_drink",
	"prop_face_rag_01",
	"prop_fag_packet_01",
	"prop_fbi3_coffee_table",
	"prop_fib_badge",
	"prop_fib_skylight_piece",
	"prop_fishing_rod_01",
	"prop_fishing_rod_02",
	"prop_fish_slice_01",
	"prop_flare_01",
	"prop_flare_01b",
	"prop_flatbed_strap",
	"prop_flight_box_01",
	"prop_flight_box_insert",
	"prop_flight_box_insert2",
	"prop_franklin_dl",
	"prop_f_b_insert_broken",
	"prop_gaffer_arm_bind",
	"prop_gaffer_arm_bind_cut",
	"prop_gaffer_leg_bind",
	"prop_gaffer_leg_bind_cut",
	"prop_gaffer_tape",
	"prop_gaffer_tape_strip",
	"prop_glasscutter_01",
	"prop_glass_suck_holder",
	"prop_gold_cont_01",
	"prop_gold_cont_01b",
	"prop_gold_trolly_strap_01",
	"prop_gun_case_01",
	"prop_gun_case_02",
	"prop_gun_frame",
	"prop_hand_toilet",
	"prop_hard_hat_01",
	"prop_headphones_01",
	"prop_headset_01",
	"prop_hockey_bag_01",
	"prop_holster_01",
	"prop_hose_nozzle",
	"prop_huf_rag_01",
	"prop_ice_cube_01",
	"prop_ice_cube_02",
	"prop_ice_cube_03",
	"prop_id2_20_clock",
	"prop_idol_01",
	"prop_idol_case",
	"prop_idol_case_02",
	"prop_ing_crowbar",
	"prop_inhaler_01",
	"prop_iron_01",
	"prop_jet_bloodsplat_01",
	"prop_juice_pool_01",
	"prop_ld_ammo_pack_01",
	"prop_ld_ammo_pack_02",
	"prop_ld_ammo_pack_03",
	"prop_ld_barrier_01",
	"prop_ld_bomb_01",
	"prop_ld_bomb_01_open",
	"prop_ld_bomb_anim",
	"prop_ld_can_01",
	"prop_ld_contact_card",
	"prop_ld_crocclips01",
	"prop_ld_crocclips02",
	"prop_ld_dummy_rope",
	"prop_ld_fags_01",
	"prop_ld_fags_02",
	"prop_ld_faucet",
	"prop_ld_ferris_wheel",
	"prop_ld_fireaxe",
	"prop_ld_flow_bottle",
	"prop_ld_gold_tooth",
	"prop_ld_hdd_01",
	"prop_ld_peep_slider",
	"prop_ld_rail_01",
	"prop_ld_rail_02",
	"prop_ld_rubble_01",
	"prop_ld_rubble_02",
	"prop_ld_rubble_03",
	"prop_ld_rubble_04",
	"prop_ld_scrap",
	"prop_ld_shovel",
	"prop_ld_shovel_dirt",
	"prop_ld_snack_01",
	"prop_ld_test_01",
	"prop_ld_tooth",
	"prop_ld_wallet_02",
	"prop_ld_wallet_pickup",
	"prop_lev_des_barge_01",
	"prop_lev_des_barge_02",
	"prop_lift_overlay_01",
	"prop_lift_overlay_02",
	"prop_litter_picker",
	"prop_loose_rag_01",
	"prop_med_jet_01",
	"prop_megaphone_01",
	"prop_mem_candle_04",
	"prop_mem_candle_05",
	"prop_mem_candle_06",
	"prop_mem_reef_01",
	"prop_mem_reef_02",
	"prop_mem_reef_03",
	"prop_mem_teddy_01",
	"prop_mem_teddy_02",
	"prop_meth_bag_01",
	"prop_michael_balaclava",
	"prop_michael_sec_id",
	"prop_microphone_02",
	"prop_military_pickup_01",
	"prop_mil_crate_01",
	"prop_mil_crate_02",
	"prop_minigun_01",
	"prop_money_bag_01",
	"prop_mp3_dock",
	"prop_mp_arrow_barrier_01",
	"prop_mp_barrier_01",
	"prop_mp_barrier_01b",
	"prop_mp_barrier_02",
	"prop_mp_barrier_02b",
	"prop_mp_base_marker",
	"prop_mp_boost_01",
	"prop_mp_cant_place_lrg",
	"prop_mp_cant_place_med",
	"prop_mp_cant_place_sm",
	"prop_mp_cone_01",
	"prop_mp_cone_02",
	"prop_mp_cone_03",
	"prop_mp_cone_04",
	"prop_mp_drug_package",
	"prop_mp_drug_pack_blue",
	"prop_mp_drug_pack_red",
	"prop_mp_icon_shad_lrg",
	"prop_mp_icon_shad_med",
	"prop_mp_icon_shad_sm",
	"prop_mp_max_out_lrg",
	"prop_mp_max_out_med",
	"prop_mp_max_out_sm",
	"prop_mp_num_0",
	"prop_mp_num_1",
	"prop_mp_num_2",
	"prop_mp_num_3",
	"prop_mp_num_4",
	"prop_mp_num_5",
	"prop_mp_num_6",
	"prop_mp_num_7",
	"prop_mp_num_8",
	"prop_mp_num_9",
	"prop_mp_placement",
	"prop_mp_placement_lrg",
	"prop_mp_placement_maxd",
	"prop_mp_placement_med",
	"prop_mp_placement_red",
	"prop_mp_placement_sm",
	"prop_mp_ramp_01",
	"prop_mp_ramp_02",
	"prop_mp_ramp_03",
	"prop_mp_repair",
	"prop_mp_repair_01",
	"prop_mp_respawn_02",
	"prop_mp_rocket_01",
	"prop_mp_spike_01",
	"prop_m_pack_int_01",
	"prop_nigel_bag_pickup",
	"prop_notepad_01",
	"prop_notepad_02",
	"prop_old_boot",
	"prop_orang_can_01",
	"prop_parking_wand_01",
	"prop_passport_01",
	"prop_peanut_bowl_01",
	"prop_pencil_01",
	"prop_piercing_gun",
	"prop_ping_pong",
	"prop_pistol_holster",
	"prop_plastic_cup_02",
	"prop_player_gasmask",
	"prop_pliers_01",
	"prop_police_radio_handset",
	"prop_police_radio_main",
	"prop_poster_tube_01",
	"prop_poster_tube_02",
	"prop_power_cell",
	"prop_power_cord_01",
	"prop_premier_fence_01",
	"prop_premier_fence_02",
	"prop_quad_grid_line",
	"prop_rad_waste_barrel_01",
	"prop_rail_controller",
	"prop_range_target_01",
	"prop_range_target_02",
	"prop_range_target_03",
	"prop_riot_shield",
	"prop_rolled_sock_01",
	"prop_rolled_sock_02",
	"prop_rope_family_3",
	"prop_safety_glasses",
	"prop_sam_01",
	"prop_sandwich_01",
	"prop_scaffold_pole",
	"prop_scn_police_torch",
	"prop_scourer_01",
	"prop_scrap_2_crate",
	"prop_sewing_fabric",
	"prop_sewing_machine",
	"prop_shower_towel",
	"prop_sh_beer_pissh_01",
	"prop_sh_bong_01",
	"prop_sh_cigar_01",
	"prop_sh_joint_01",
	"prop_sh_mr_rasp_01",
	"prop_sh_shot_glass",
	"prop_sh_tall_glass",
	"prop_sh_tt_fridgedoor",
	"prop_sh_wine_glass",
	"prop_single_grid_line",
	"prop_smg_holster_01",
	"prop_space_pistol",
	"prop_space_rifle",
	"prop_spycam",
	"prop_squeegee",
	"prop_stag_do_rope",
	"prop_start_finish_line_01",
	"prop_start_grid_01",
	"prop_stockade_wheel",
	"prop_stockade_wheel_flat",
	"prop_sub_cover_01",
	"prop_sub_release",
	"prop_syringe_01",
	"prop_table_mic_01",
	"prop_table_ten_bat",
	"prop_taco_01",
	"prop_taco_02",
	"prop_tapeplayer_01",
	"prop_target_arm",
	"prop_target_arm_b",
	"prop_target_arm_long",
	"prop_target_arm_sm",
	"prop_target_backboard",
	"prop_target_backboard_b",
	"prop_target_blue",
	"prop_target_blue_arrow",
	"prop_target_bull",
	"prop_target_bull_b",
	"prop_target_comp_metal",
	"prop_target_comp_wood",
	"prop_target_frame_01",
	"prop_target_inner1",
	"prop_target_inner2",
	"prop_target_inner2_b",
	"prop_target_inner3",
	"prop_target_inner3_b",
	"prop_target_inner_b",
	"prop_target_orange_arrow",
	"prop_target_oran_cross",
	"prop_target_ora_purp_01",
	"prop_target_purp_arrow",
	"prop_target_purp_cross",
	"prop_target_red",
	"prop_target_red_arrow",
	"prop_target_red_blue_01",
	"prop_target_red_cross",
	"prop_tarp_strap",
	"prop_tea_trolly",
	"prop_temp_block_blocker",
	"prop_tennis_ball",
	"prop_tennis_rack_01",
	"prop_tennis_rack_01b",
	"prop_time_capsule_01",
	"prop_tornado_wheel",
	"prop_torture_01",
	"prop_tourist_map_01",
	"prop_trailer_01_new",
	"prop_trailer_door_closed",
	"prop_trailer_door_open",
	"prop_trevor_rope_01",
	"prop_trev_sec_id",
	"prop_triple_grid_line",
	"prop_tri_finish_banner",
	"prop_tri_start_banner",
	"prop_tumbler_01",
	"prop_tumbler_01b",
	"prop_tumbler_01_empty",
	"prop_turkey_leg_01",
	"prop_tv_cam_02",
	"prop_tv_test",
	"prop_t_shirt_ironing",
	"prop_voltmeter_01",
	"prop_water_corpse_01",
	"prop_water_corpse_02",
	"prop_weed_01",
	"prop_weed_02",
	"prop_weed_block_01",
	"prop_weed_bottle",
	"prop_weed_pallet",
	"prop_weed_tub_01",
	"prop_weed_tub_01b",
	"prop_welding_mask_01",
	"prop_weld_torch",
	"prop_wheat_grass_empty",
	"prop_wheat_grass_glass",
	"prop_winch_hook_long",
	"prop_winch_hook_short",
	"prop_wrecked_buzzard",
	"prop_yacht_lounger",
	"prop_yacht_seat_01",
	"prop_yacht_seat_02",
	"prop_yacht_seat_03",
	"prop_yacht_table_01",
	"prop_yacht_table_02",
	"prop_yacht_table_03",
	"prop_yell_plastic_target",
	"p_amb_bagel_01",
	"p_cs_bbbat_01",
	"p_cs_bottle_01",
	"p_cs_clipboard",
	"p_cs_joint_01",
	"p_cs_joint_02",
	"p_cs_lighter_01",
	"p_cs_papers_01",
	"p_cs_papers_02",
	"p_cs_papers_03",
	"p_ing_bagel_01",
	"p_ing_microphonel_01",
	"p_ld_bs_bag_01",
	"p_ld_id_card_002",
	"p_ld_id_card_01",
	"p_rc_handset",
	"p_whiskey_notop",
	"p_whiskey_notop_empty",
	"prop_crashed_heli",
	"prop_ld_bankdoors_02",
	"prop_ld_fragwall_01a",
	"prop_pipe_single_01",
	"prop_test_boulder_01",
	"prop_test_boulder_02",
	"prop_test_boulder_03",
	"prop_test_boulder_04",
	"prop_trailr_base",
	"prop_trailr_base_static",
	"proc_drkyel001",
	"proc_flower1",
	"proc_flower_wild_04",
	"proc_weeds01a",
	"proc_weeds01b",
	"proc_weeds01c",
	"prop_test_bed",
	"proair_hoc_puck",
	"prop_airhockey_01",
	"prop_air_hoc_paddle_01",
	"prop_air_hoc_paddle_02",
	"prop_arcade_01",
	"prop_arcade_02",
	"prop_ice_box_01",
	"prop_ice_box_01_l1",
	"prop_jukebox_01",
	"prop_jukebox_02",
	"prop_park_ticket_01",
	"prop_pier_kiosk_01",
	"prop_pier_kiosk_02",
	"prop_pier_kiosk_03",
	"prop_pooltable_02",
	"prop_pooltable_3b",
	"prop_pool_cue",
	"prop_pool_rack_01",
	"prop_pool_rack_02",
	"prop_pool_tri",
	"prop_telescope",
	"prop_train_ticket_02",
	"prop_turnstyle_01",
	"prop_vend_coffe_01",
	"prop_vend_condom_01",
	"prop_vend_fags_01",
	"prop_vend_fridge01",
	"prop_vend_snak_01",
	"prop_apple_box_01",
	"prop_apple_box_02",
	"prop_arm_wrestle_01",
	"prop_a_base_bars_01",
	"prop_barbell_01",
	"prop_barbell_02",
	"prop_barbell_100kg",
	"prop_barbell_10kg",
	"prop_barbell_20kg",
	"prop_barbell_30kg",
	"prop_barbell_40kg",
	"prop_barbell_50kg",
	"prop_barbell_60kg",
	"prop_barbell_80kg",
	"prop_basketball_net",
	"prop_bball_arcade_01",
	"prop_beachbag_01",
	"prop_beachbag_02",
	"prop_beachbag_03",
	"prop_beachbag_04",
	"prop_beachbag_05",
	"prop_beachbag_06",
	"prop_beachbag_combo_01",
	"prop_beachbag_combo_02",
	"prop_beachball_02",
	"prop_beachflag_le",
	"prop_beach_bars_01",
	"prop_beach_bars_02",
	"prop_beach_bbq",
	"prop_beach_dip_bars_01",
	"prop_beach_dip_bars_02",
	"prop_beach_fire",
	"prop_beach_lg_float",
	"prop_beach_lg_stretch",
	"prop_beach_lg_surf",
	"prop_beach_lotion_01",
	"prop_beach_lotion_02",
	"prop_beach_lotion_03",
	"prop_beach_punchbag",
	"prop_beach_rings_01",
	"prop_beach_sculp_01",
	"prop_beach_towel_02",
	"prop_beach_volball01",
	"prop_beach_volball02",
	"prop_bikini_disp_01",
	"prop_bikini_disp_02",
	"prop_bikini_disp_03",
	"prop_bikini_disp_04",
	"prop_bikini_disp_05",
	"prop_bikini_disp_06",
	"prop_bleachers_01",
	"prop_bleachers_02",
	"prop_bleachers_03",
	"prop_bleachers_04",
	"prop_bleachers_05",
	"prop_boogbd_stack_01",
	"prop_boogbd_stack_02",
	"prop_boogieboard_01",
	"prop_boogieboard_02",
	"prop_boogieboard_03",
	"prop_boogieboard_04",
	"prop_boogieboard_05",
	"prop_boogieboard_06",
	"prop_boogieboard_07",
	"prop_boogieboard_08",
	"prop_boogieboard_09",
	"prop_boogieboard_10",
	"prop_bowling_ball",
	"prop_bowling_pin",
	"prop_boxing_glove_01",
	"prop_buck_spade_01",
	"prop_buck_spade_02",
	"prop_buck_spade_03",
	"prop_buck_spade_04",
	"prop_buck_spade_05",
	"prop_buck_spade_06",
	"prop_buck_spade_07",
	"prop_buck_spade_08",
	"prop_buck_spade_09",
	"prop_buck_spade_10",
	"prop_bumper_car_01",
	"prop_can_canoe",
	"prop_cap_01",
	"prop_cap_01b",
	"prop_cap_row_01",
	"prop_cap_row_01b",
	"prop_cap_row_02",
	"prop_cap_row_02b",
	"prop_clothes_rail_02",
	"prop_clothes_rail_03",
	"prop_clothes_rail_2b",
	"prop_clothes_tub_01",
	"prop_cs_beachtowel_01",
	"prop_cup_saucer_01",
	"prop_curl_bar_01",
	"prop_dart_1",
	"prop_dart_2",
	"prop_dart_bd_01",
	"prop_dart_bd_cab_01",
	"prop_display_unit_01",
	"prop_display_unit_02",
	"prop_disp_cabinet_002",
	"prop_disp_cabinet_01",
	"prop_dolly_01",
	"prop_dolly_02",
	"prop_dress_disp_01",
	"prop_dress_disp_02",
	"prop_dress_disp_03",
	"prop_dress_disp_04",
	"prop_drug_burner",
	"prop_exer_bike_01",
	"prop_ferris_car_01",
	"prop_ferris_car_01_lod1",
	"prop_film_cam_01",
	"prop_flipchair_01",
	"prop_food_van_01",
	"prop_food_van_02",
	"prop_freeweight_01",
	"prop_freeweight_02",
	"prop_front_seat_01",
	"prop_front_seat_02",
	"prop_front_seat_03",
	"prop_front_seat_04",
	"prop_front_seat_05",
	"prop_front_seat_06",
	"prop_front_seat_07",
	"prop_front_seat_row_01",
	"prop_ftowel_01",
	"prop_ftowel_07",
	"prop_ftowel_08",
	"prop_ftowel_10",
	"prop_game_clock_01",
	"prop_game_clock_02",
	"prop_golf_bag_01",
	"prop_golf_bag_01b",
	"prop_golf_bag_01c",
	"prop_golf_ball",
	"prop_golf_ball_p2",
	"prop_golf_ball_p3",
	"prop_golf_ball_p4",
	"prop_golf_ball_tee",
	"prop_golf_driver",
	"prop_golf_iron_01",
	"prop_golf_marker_01",
	"prop_golf_pitcher_01",
	"prop_golf_putter_01",
	"prop_golf_tee",
	"prop_golf_wood_01",
	"prop_hat_box_01",
	"prop_hat_box_02",
	"prop_hat_box_03",
	"prop_hat_box_04",
	"prop_hat_box_05",
	"prop_hat_box_06",
	"prop_henna_disp_01",
	"prop_henna_disp_02",
	"prop_henna_disp_03",
	"prop_hwbowl_pseat_6x1",
	"prop_hwbowl_seat_01",
	"prop_hwbowl_seat_02",
	"prop_hwbowl_seat_03",
	"prop_hwbowl_seat_03b",
	"prop_hwbowl_seat_6x6",
	"prop_hydro_platform_01",
	"prop_inflatearch_01",
	"prop_inflategate_01",
	"prop_jeans_01",
	"prop_kayak_01",
	"prop_kayak_01b",
	"prop_kino_light_01",
	"prop_kino_light_03",
	"prop_ld_hat_01",
	"prop_ld_jeans_01",
	"prop_ld_jeans_02",
	"prop_ld_shirt_01",
	"prop_ld_shoe_01",
	"prop_ld_shoe_02",
	"prop_ld_tshirt_01",
	"prop_ld_tshirt_02",
	"prop_life_ring_02",
	"prop_makeup_trail_01",
	"prop_makeup_trail_02",
	"prop_mat_box",
	"prop_movie_rack",
	"prop_muscle_bench_01",
	"prop_muscle_bench_02",
	"prop_muscle_bench_03",
	"prop_muscle_bench_04",
	"prop_muscle_bench_05",
	"prop_muscle_bench_06",
	"prop_offroad_bale01",
	"prop_offroad_bale02_l1_frag_",
	"prop_offroad_barrel01",
	"prop_offroad_tyres01",
	"prop_plate_stand_01",
	"prop_poolball_1",
	"prop_poolball_10",
	"prop_poolball_11",
	"prop_poolball_12",
	"prop_poolball_13",
	"prop_poolball_14",
	"prop_poolball_15",
	"prop_poolball_2",
	"prop_poolball_3",
	"prop_poolball_4",
	"prop_poolball_5",
	"prop_poolball_6",
	"prop_poolball_7",
	"prop_poolball_8",
	"prop_poolball_9",
	"prop_poolball_cue",
	"prop_porn_mag_01",
	"prop_porn_mag_02",
	"prop_porn_mag_03",
	"prop_porn_mag_04",
	"prop_postcard_rack",
	"prop_pris_bars_01",
	"prop_pris_bench_01",
	"prop_prop_tree_01",
	"prop_prop_tree_02",
	"prop_punch_bag_l",
	"prop_roller_car_01",
	"prop_roller_car_02",
	"prop_scrim_01",
	"prop_set_generator_01",
	"prop_sglasses_stand_01",
	"prop_sglasses_stand_02",
	"prop_sglasses_stand_02b",
	"prop_sglasses_stand_03",
	"prop_sglasss_1b_lod",
	"prop_sglasss_1_lod",
	"prop_shop_front_door_l",
	"prop_shop_front_door_r",
	"prop_skate_flatramp",
	"prop_skate_funbox",
	"prop_skate_halfpipe",
	"prop_skate_kickers",
	"prop_skate_quartpipe",
	"prop_skate_rail",
	"prop_skate_spiner",
	"prop_skip_rope_01",
	"prop_slacks_01",
	"prop_slacks_02",
	"prop_speedball_01",
	"prop_sports_clock_01",
	"prop_studio_light_02",
	"prop_studio_light_03",
	"prop_suitcase_01",
	"prop_suitcase_01b",
	"prop_suitcase_01c",
	"prop_suitcase_01d",
	"prop_suitcase_02",
	"prop_suitcase_03",
	"prop_suitcase_03b",
	"prop_surf_board_ldn_01",
	"prop_surf_board_ldn_02",
	"prop_surf_board_ldn_03",
	"prop_surf_board_ldn_04",
	"prop_table_tennis",
	"prop_tennis_ball_lobber",
	"prop_tint_towel",
	"prop_tint_towels_01",
	"prop_tint_towels_01b",
	"prop_towel2_01",
	"prop_towel2_02",
	"prop_towel_shelf_01",
	"prop_tri_pod",
	"prop_tri_pod_lod",
	"prop_tshirt_box_02",
	"prop_tshirt_shelf_1",
	"prop_tshirt_shelf_2",
	"prop_tshirt_shelf_2a",
	"prop_tshirt_shelf_2b",
	"prop_tshirt_shelf_2c",
	"prop_tshirt_stand_01",
	"prop_tshirt_stand_01b",
	"prop_tshirt_stand_02",
	"prop_tshirt_stand_04",
	"prop_t_shirt_row_01",
	"prop_t_shirt_row_02",
	"prop_t_shirt_row_02b",
	"prop_t_shirt_row_03",
	"prop_t_shirt_row_04",
	"prop_t_shirt_row_05l",
	"prop_t_shirt_row_05r",
	"prop_venice_board_01",
	"prop_venice_board_02",
	"prop_venice_board_03",
	"prop_venice_counter_01",
	"prop_venice_counter_02",
	"prop_venice_counter_03",
	"prop_venice_counter_04",
	"prop_venice_shop_front_01",
	"prop_venice_sign_09",
	"prop_venice_sign_10",
	"prop_venice_sign_11",
	"prop_venice_sign_12",
	"prop_venice_sign_14",
	"prop_venice_sign_15",
	"prop_venice_sign_16",
	"prop_venice_sign_17",
	"prop_venice_sign_18",
	"prop_ven_market_stool",
	"prop_ven_market_table1",
	"prop_ven_shop_1_counter",
	"prop_v_15_cars_clock",
	"prop_v_5_bclock",
	"prop_weight_10k",
	"prop_weight_15k",
	"prop_weight_1_5k",
	"prop_weight_20k",
	"prop_weight_2_5k",
	"prop_weight_5k",
	"prop_weight_rack_01",
	"prop_weight_rack_02",
	"p_film_set_static_01",
	"prop_bath_dirt_01",
	"prop_broom_unit_01",
	"prop_handdry_01",
	"prop_handdry_02",
	"prop_shower_01",
	"prop_shower_rack_01",
	"prop_sink_01",
	"prop_sink_02",
	"prop_sink_03",
	"prop_sink_04",
	"prop_sink_05",
	"prop_sink_06",
	"prop_soap_disp_01",
	"prop_soap_disp_02",
	"prop_sponge_01",
	"prop_toilet_01",
	"prop_toilet_02",
	"prop_toilet_03",
	"prop_toilet_brush_01",
	"prop_toilet_cube_01",
	"prop_toilet_cube_02",
	"prop_toilet_roll_01",
	"prop_toilet_roll_02",
	"prop_toilet_roll_03",
	"prop_toilet_roll_04",
	"prop_toilet_roll_05",
	"prop_toilet_shamp_01",
	"prop_toilet_shamp_02",
	"prop_toilet_soap_01",
	"prop_toilet_soap_02",
	"prop_toilet_soap_03",
	"prop_toilet_soap_04",
	"prop_toothbrush_01",
	"prop_toothb_cup_01",
	"prop_toothpaste_01",
	"prop_towel_01",
	"prop_towel_rail_01",
	"prop_towel_rail_02",
	"prop_towel_small_01",
	"prop_w_fountain_01",
	"prop_amp_01",
	"prop_cctv_02_sm",
	"prop_cctv_cont_01",
	"prop_cctv_cont_03",
	"prop_cctv_cont_04",
	"prop_cctv_cont_05",
	"prop_cctv_cont_06",
	"prop_cctv_unit_01",
	"prop_cctv_unit_02",
	"prop_cctv_unit_05",
	"prop_console_01",
	"prop_cs_dvd_player",
	"prop_cs_keyboard_01",
	"prop_cs_mouse_01",
	"prop_cs_tv_stand",
	"prop_dj_deck_01",
	"prop_dj_deck_02",
	"prop_flatscreen_overlay",
	"prop_ghettoblast_02",
	"prop_hifi_01",
	"prop_keyboard_01a",
	"prop_keyboard_01b",
	"prop_laptop_02_closed",
	"prop_laptop_jimmy",
	"prop_laptop_lester",
	"prop_laptop_lester2",
	"prop_michaels_credit_tv",
	"prop_monitor_01c",
	"prop_monitor_01d",
	"prop_monitor_02",
	"prop_monitor_03b",
	"prop_mouse_01",
	"prop_mouse_01a",
	"prop_mouse_01b",
	"prop_mouse_02",
	"prop_pc_01a",
	"prop_pc_02a",
	"prop_portable_hifi_01",
	"prop_projector_overlay",
	"prop_speaker_01",
	"prop_speaker_02",
	"prop_speaker_03",
	"prop_speaker_05",
	"prop_speaker_06",
	"prop_speaker_07",
	"prop_speaker_08",
	"prop_till_01_dam",
	"prop_till_02",
	"prop_till_03",
	"prop_trailer_monitor_01",
	"prop_trev_tv_01",
	"prop_tt_screenstatic",
	"prop_tv_02",
	"prop_tv_03_overlay",
	"prop_tv_04",
	"prop_tv_05",
	"prop_tv_06",
	"prop_tv_07",
	"prop_tv_cabinet_03",
	"prop_tv_cabinet_04",
	"prop_tv_cabinet_05",
	"prop_tv_flat_01",
	"prop_tv_flat_01_screen",
	"prop_tv_flat_02b",
	"prop_tv_flat_03",
	"prop_tv_flat_03b",
	"prop_tv_flat_michael",
	"prop_vcr_01",
	"prop_white_keyboard",
	"prop_bbq_2",
	"prop_bbq_3",
	"prop_beware_dog_sign",
	"prop_forsalejr2",
	"prop_forsalejr3",
	"prop_forsalejr4",
	"prop_fountain1",
	"prop_fountain2",
	"prop_garden_dreamcatch_01",
	"prop_garden_edging_01",
	"prop_garden_edging_02",
	"prop_garden_zapper_01",
	"prop_gardnght_01",
	"prop_gazebo_03",
	"prop_glf_roller",
	"prop_glf_spreader",
	"prop_gravestones_01a",
	"prop_gravestones_02a",
	"prop_gravestones_03a",
	"prop_gravestones_04a",
	"prop_gravestones_05a",
	"prop_gravestones_06a",
	"prop_gravestones_07a",
	"prop_gravestones_08a",
	"prop_gravestones_09a",
	"prop_gravestones_10a",
	"prop_gravetomb_01a",
	"prop_gravetomb_02a",
	"prop_hedge_trimmer_01",
	"prop_hose_1",
	"prop_hose_2",
	"prop_hose_3",
	"prop_hottub2",
	"prop_lawnmower_01",
	"prop_leaf_blower_01",
	"prop_letterbox_04",
	"prop_outdoor_fan_01",
	"prop_owl_totem_01",
	"prop_poolskimmer",
	"prop_prlg_gravestone_05a_l1",
	"prop_prlg_gravestone_06a",
	"prop_shrub_rake",
	"prop_sign_mallet",
	"prop_spray_backpack_01",
	"prop_sprink_crop_01",
	"prop_sprink_golf_01",
	"prop_sprink_park_01",
	"prop_stickbfly",
	"prop_stickhbird",
	"prop_wateringcan",
	"prop_windmill2",
	"test_prop_gravestones_04a",
	"test_prop_gravestones_05a",
	"test_prop_gravestones_07a",
	"test_prop_gravestones_08a",
	"test_prop_gravestones_09a",
	"test_prop_gravetomb_01a",
	"test_prop_gravetomb_02a",
	"prop_breadbin_01",
	"prop_cleaver",
	"prop_cooker_03",
	"prop_copper_pan",
	"prop_fridge_01",
	"prop_fridge_03",
	"prop_ind_washer_02",
	"prop_kettle",
	"prop_kettle_01",
	"prop_kitch_juicer",
	"prop_kitch_pot_fry",
	"prop_kitch_pot_huge",
	"prop_kitch_pot_lrg",
	"prop_kitch_pot_lrg2",
	"prop_kitch_pot_med",
	"prop_kitch_pot_sm",
	"prop_knife",
	"prop_knife_stand",
	"prop_ladel",
	"prop_metalfoodjar_01",
	"prop_micro_01",
	"prop_micro_02",
	"prop_micro_cs_01",
	"prop_micro_cs_01_door",
	"prop_plate_04",
	"prop_plate_warmer",
	"prop_pot_01",
	"prop_pot_02",
	"prop_pot_03",
	"prop_pot_04",
	"prop_pot_05",
	"prop_pot_06",
	"prop_pot_rack",
	"prop_steam_basket_01",
	"prop_steam_basket_02",
	"prop_tea_urn",
	"prop_toaster_01",
	"prop_toaster_02",
	"prop_utensil",
	"prop_washer_01",
	"prop_washer_02",
	"prop_washer_03",
	"prop_washing_basket_01",
	"prop_whisk",
	"prop_wok",
	"prop_armchair_01",
	"prop_couch_01",
	"prop_couch_03",
	"prop_couch_04",
	"prop_couch_lg_02",
	"prop_couch_lg_05",
	"prop_couch_lg_06",
	"prop_couch_lg_07",
	"prop_couch_lg_08",
	"prop_couch_sm1_07",
	"prop_couch_sm2_07",
	"prop_couch_sm_02",
	"prop_couch_sm_05",
	"prop_couch_sm_06",
	"prop_couch_sm_07",
	"prop_yaught_chair_01",
	"prop_yaught_sofa_01",
	"prop_bin_04a",
	"prop_bin_10a",
	"prop_bin_10b",
	"prop_bin_11a",
	"prop_bin_11b",
	"prop_bin_12a",
	"prop_bin_13a",
	"prop_bin_14a",
	"prop_bin_14b",
	"prop_bin_beach_01d",
	"prop_bin_delpiero",
	"prop_bin_delpiero_b",
	"prop_dumpster_3a",
	"prop_dumpster_3step",
	"prop_dumpster_4a",
	"prop_dumpster_4b",
	"prop_recyclebin_02a",
	"prop_recyclebin_02b",
	"prop_recyclebin_02_c",
	"prop_recyclebin_02_d",
	"prop_recyclebin_03_a",
	"prop_recyclebin_04_a",
	"prop_recyclebin_04_b",
	"prop_recyclebin_05_a",
	"prop_skip_01a",
	"prop_skip_02a",
	"prop_skip_03",
	"prop_skip_04",
	"prop_skip_05a",
	"prop_skip_05b",
	"prop_skip_06a",
	"prop_skip_08a",
	"prop_skip_08b",
	"prop_skip_10a",
	"prop_bandsaw_01",
	"prop_barier_conc_01b",
	"prop_barier_conc_01c",
	"prop_barier_conc_02b",
	"prop_barier_conc_02c",
	"prop_barier_conc_03a",
	"prop_barier_conc_04a",
	"prop_barier_conc_05a",
	"prop_barier_conc_05b",
	"prop_barriercrash_03",
	"prop_barriercrash_04",
	"prop_barrier_wat_01a",
	"prop_barrier_wat_03b",
	"prop_barrier_work01c",
	"prop_cablespool_01a",
	"prop_cablespool_01b",
	"prop_cablespool_02",
	"prop_cablespool_03",
	"prop_cablespool_04",
	"prop_cablespool_05",
	"prop_cablespool_06",
	"prop_cementmixer_01a",
	"prop_cementmixer_02a",
	"prop_conc_sacks_02a",
	"prop_conschute",
	"prop_consign_01c",
	"prop_consign_02a",
	"prop_conslift_base",
	"prop_conslift_brace",
	"prop_conslift_cage",
	"prop_conslift_door",
	"prop_conslift_lift",
	"prop_conslift_rail",
	"prop_conslift_rail2",
	"prop_conslift_steps",
	"prop_cons_crate",
	"prop_cons_plank",
	"prop_cons_ply01",
	"prop_cons_ply02",
	"prop_crosssaw_01",
	"prop_diggerbkt_01",
	"prop_drywallpile_01",
	"prop_drywallpile_02",
	"prop_ducktape_01",
	"prop_etricmotor_01",
	"prop_generator_02a",
	"prop_generator_03a",
	"prop_generator_04",
	"prop_girder_01a",
	"prop_logpile_05",
	"prop_logpile_06",
	"prop_logpile_06b",
	"prop_logpile_07",
	"prop_logpile_07b",
	"prop_log_01",
	"prop_log_02",
	"prop_log_03",
	"prop_medstation_02",
	"prop_medstation_03",
	"prop_medstation_04",
	"prop_metal_plates01",
	"prop_metal_plates02",
	"prop_oiltub_01",
	"prop_oiltub_02",
	"prop_oiltub_03",
	"prop_oiltub_05",
	"prop_oiltub_06",
	"prop_paints_can01",
	"prop_paints_can02",
	"prop_paints_can03",
	"prop_paints_can04",
	"prop_paints_can05",
	"prop_paints_can06",
	"prop_paints_can07",
	"prop_paint_brush01",
	"prop_paint_brush02",
	"prop_paint_brush03",
	"prop_paint_brush04",
	"prop_paint_brush05",
	"prop_paint_roller",
	"prop_paint_spray01a",
	"prop_paint_spray01b",
	"prop_paint_stepl01",
	"prop_paint_stepl01b",
	"prop_paint_stepl02",
	"prop_paint_tray",
	"prop_paint_wpaper01",
	"prop_partsbox_01",
	"prop_pile_dirt_01",
	"prop_pile_dirt_02",
	"prop_pile_dirt_03",
	"prop_pile_dirt_04",
	"prop_pile_dirt_06",
	"prop_pile_dirt_07",
	"prop_pipes_01a",
	"prop_pipes_01b",
	"prop_pipes_03b",
	"prop_pipes_04a",
	"prop_pipes_05a",
	"prop_pipes_conc_01",
	"prop_pipes_conc_02",
	"prop_planer_01",
	"prop_plas_barier_01a",
	"prop_plywoodpile_01a",
	"prop_plywoodpile_01b",
	"prop_rebar_pile01",
	"prop_roadcone01a",
	"prop_roadcone01b",
	"prop_roadcone01c",
	"prop_roadcone02a",
	"prop_roadcone02b",
	"prop_roadcone02c",
	"prop_roadheader_01",
	"prop_scafold_01a",
	"prop_scafold_01c",
	"prop_scafold_01f",
	"prop_scafold_02a",
	"prop_scafold_02c",
	"prop_scafold_03a",
	"prop_scafold_03b",
	"prop_scafold_03c",
	"prop_scafold_03f",
	"prop_scafold_04a",
	"prop_scafold_05a",
	"prop_scafold_06a",
	"prop_scafold_06b",
	"prop_scafold_06c",
	"prop_scafold_07a",
	"prop_scafold_08a",
	"prop_scafold_09a",
	"prop_scafold_frame1a",
	"prop_scafold_frame1b",
	"prop_scafold_frame1c",
	"prop_scafold_frame1f",
	"prop_scafold_frame2a",
	"prop_scafold_frame2b",
	"prop_scafold_frame2c",
	"prop_scafold_frame3a",
	"prop_scafold_frame3c",
	"prop_scafold_rail_01",
	"prop_scafold_rail_02",
	"prop_scafold_rail_03",
	"prop_scafold_xbrace",
	"prop_shuttering01",
	"prop_shuttering02",
	"prop_shuttering03",
	"prop_shuttering04",
	"prop_spraygun_01",
	"prop_staticmixer_01",
	"prop_steps_big_01",
	"prop_tablesaw_01",
	"prop_tool_adjspanner",
	"prop_tool_bench01",
	"prop_tool_bluepnt",
	"prop_tool_box_01",
	"prop_tool_box_02",
	"prop_tool_box_03",
	"prop_tool_box_04",
	"prop_tool_box_05",
	"prop_tool_box_06",
	"prop_tool_box_07",
	"prop_tool_broom",
	"prop_tool_broom2",
	"prop_tool_broom2_l1",
	"prop_tool_cable01",
	"prop_tool_cable02",
	"prop_tool_consaw",
	"prop_tool_drill",
	"prop_tool_fireaxe",
	"prop_tool_hammer",
	"prop_tool_hardhat",
	"prop_tool_jackham",
	"prop_tool_mallet",
	"prop_tool_mopbucket",
	"prop_tool_nailgun",
	"prop_tool_pickaxe",
	"prop_tool_pliers",
	"prop_tool_rake",
	"prop_tool_rake_l1",
	"prop_tool_sawhorse",
	"prop_tool_screwdvr01",
	"prop_tool_screwdvr02",
	"prop_tool_screwdvr03",
	"prop_tool_shovel",
	"prop_tool_shovel006",
	"prop_tool_shovel2",
	"prop_tool_shovel3",
	"prop_tool_shovel4",
	"prop_tool_shovel5",
	"prop_tool_sledgeham",
	"prop_tool_spanner01",
	"prop_tool_spanner02",
	"prop_tool_spanner03",
	"prop_tool_torch",
	"prop_tool_wrench",
	"prop_towercrane_01a",
	"prop_towercrane_02a",
	"prop_towercrane_02b",
	"prop_towercrane_02c",
	"prop_towercrane_02d",
	"prop_towercrane_02e",
	"prop_towercrane_02el",
	"prop_towercrane_02el2",
	"prop_tunnel_liner01",
	"prop_tunnel_liner02",
	"prop_tunnel_liner03",
	"prop_vertdrill_01",
	"prop_wheelbarrow01a",
	"prop_wheelbarrow02a",
	"prop_woodpile_02a",
	"prop_worklight_01a_l1",
	"prop_worklight_03a_l1",
	"prop_worklight_03b_l1",
	"prop_worklight_04a",
	"prop_worklight_04b_l1",
	"prop_worklight_04c_l1",
	"prop_worklight_04d_l1",
	"prop_workwall_01",
	"prop_workwall_02",
	"prop_armenian_gate",
	"prop_arm_gate_l",
	"prop_const_fence01a",
	"prop_const_fence01b",
	"prop_const_fence02a",
	"prop_const_fence02b",
	"prop_const_fence03b",
	"prop_facgate_01",
	"prop_facgate_01b",
	"prop_facgate_02pole",
	"prop_facgate_02_l",
	"prop_facgate_03post",
	"prop_facgate_03_l",
	"prop_facgate_03_ld_l",
	"prop_facgate_03_ld_r",
	"prop_facgate_03_r",
	"prop_facgate_04_l",
	"prop_facgate_04_r",
	"prop_facgate_05_r",
	"prop_facgate_05_r_dam_l1",
	"prop_facgate_05_r_l1",
	"prop_facgate_06_l",
	"prop_facgate_06_r",
	"prop_facgate_07",
	"prop_facgate_07b",
	"prop_facgate_08",
	"prop_facgate_08_frame",
	"prop_facgate_08_ld2",
	"prop_facgate_id1_27",
	"prop_fence_log_01",
	"prop_fence_log_02",
	"prop_fncconstruc_02a",
	"prop_fnclog_01a",
	"prop_fnclog_01b",
	"prop_fncpeir_03a",
	"prop_fncres_02a",
	"prop_fncres_02b",
	"prop_fncres_02c",
	"prop_fncres_02d",
	"prop_fncres_02_gate1",
	"prop_fncres_03gate1",
	"prop_fncres_05c_l1",
	"prop_fncsec_01a",
	"prop_fncsec_01b",
	"prop_fncsec_01crnr",
	"prop_fncsec_01gate",
	"prop_fncsec_01pole",
	"prop_fncsec_02a",
	"prop_fncsec_02pole",
	"prop_fncwood_07gate1",
	"prop_fncwood_11a_l1",
	"prop_fncwood_16a",
	"prop_fncwood_16b",
	"prop_fncwood_16c",
	"prop_fncwood_18a",
	"prop_gatecom_02",
	"prop_gate_airport_01",
	"prop_gate_cult_01_l",
	"prop_gate_cult_01_r",
	"prop_gate_docks_ld",
	"prop_gate_farm_01a",
	"prop_gate_farm_post",
	"prop_gate_frame_01",
	"prop_gate_frame_02",
	"prop_gate_frame_04",
	"prop_gate_frame_05",
	"prop_gate_frame_06",
	"prop_gate_military_01",
	"prop_gate_prison_01",
	"prop_gate_tep_01_l",
	"prop_gate_tep_01_r",
	"prop_ld_balcfnc_01a",
	"prop_ld_balcfnc_02a",
	"prop_ld_balcfnc_02c",
	"prop_lrggate_01c_l",
	"prop_lrggate_01c_r",
	"prop_lrggate_01_l",
	"prop_lrggate_01_pst",
	"prop_lrggate_01_r",
	"prop_lrggate_02_ld",
	"prop_lrggate_03a",
	"prop_lrggate_03b",
	"prop_lrggate_03b_ld",
	"prop_lrggate_04a",
	"prop_lrggate_05a",
	"prop_lrggate_06a",
	"prop_fnccorgm_05a",
	"prop_fnccorgm_05b",
	"prop_fnccorgm_06a",
	"prop_fnccorgm_06b",
	"prop_fnclink_01gate1",
	"prop_fnclink_02gate1",
	"prop_fnclink_02gate2",
	"prop_fnclink_02gate5",
	"prop_fnclink_02gate6_l",
	"prop_fnclink_02gate6_r",
	"prop_fnclink_02gate7",
	"prop_fnclink_03gate1",
	"prop_fnclink_03gate2",
	"prop_fnclink_03gate4",
	"prop_fnclink_03gate5",
	"prop_fnclink_04gate1",
	"prop_fnclink_04h_l2",
	"prop_fnclink_06gate2",
	"prop_fnclink_06gate3",
	"prop_fnclink_06gatepost",
	"prop_fnclink_07gate1",
	"prop_fnclink_07gate2",
	"prop_fnclink_07gate3",
	"prop_fnclink_09gate1",
	"prop_fnclink_10a",
	"prop_fnclink_10b",
	"prop_fnclink_10c",
	"prop_fnclink_10d",
	"prop_fnclink_10e",
	"prop_fncsec_04a",
	"prop_gate_bridge_ld",
	"prop_hobo_stove_01",
	"prop_homeless_matress_01",
	"prop_homeless_matress_02",
	"prop_pizza_box_01",
	"prop_pizza_box_02",
	"prop_rub_bike_01",
	"prop_rub_bike_02",
	"prop_rub_bike_03",
	"prop_rub_busdoor_01",
	"prop_rub_busdoor_02",
	"prop_rub_buswreck_01",
	"prop_rub_buswreck_03",
	"prop_rub_buswreck_06",
	"prop_rub_cabinet",
	"prop_rub_cabinet01",
	"prop_rub_cabinet02",
	"prop_rub_cabinet03",
	"prop_rub_cage01a",
	"prop_rub_carpart_02",
	"prop_rub_carpart_03",
	"prop_rub_carpart_04",
	"prop_rub_chassis_01",
	"prop_rub_chassis_02",
	"prop_rub_chassis_03",
	"prop_rub_cont_01a",
	"prop_rub_cont_01b",
	"prop_rub_cont_01c",
	"prop_rub_flotsam_01",
	"prop_rub_flotsam_02",
	"prop_rub_flotsam_03",
	"prop_rub_frklft",
	"prop_rub_litter_01",
	"prop_rub_litter_02",
	"prop_rub_litter_03",
	"prop_rub_litter_03b",
	"prop_rub_litter_03c",
	"prop_rub_litter_04",
	"prop_rub_litter_04b",
	"prop_rub_litter_05",
	"prop_rub_litter_06",
	"prop_rub_litter_07",
	"prop_rub_litter_09",
	"prop_rub_litter_8",
	"prop_rub_matress_01",
	"prop_rub_matress_02",
	"prop_rub_matress_03",
	"prop_rub_matress_04",
	"prop_rub_monitor",
	"prop_rub_pile_01",
	"prop_rub_pile_02",
	"prop_rub_planks_01",
	"prop_rub_planks_02",
	"prop_rub_planks_03",
	"prop_rub_planks_04",
	"prop_rub_railwreck_1",
	"prop_rub_railwreck_2",
	"prop_rub_railwreck_3",
	"prop_rub_scrap_02",
	"prop_rub_scrap_03",
	"prop_rub_scrap_04",
	"prop_rub_scrap_05",
	"prop_rub_scrap_06",
	"prop_rub_scrap_07",
	"prop_rub_stool",
	"prop_rub_sunktyre",
	"prop_rub_t34",
	"prop_rub_trainers_01",
	"prop_rub_trolley01a",
	"prop_rub_trolley02a",
	"prop_rub_trolley03a",
	"prop_rub_trukwreck_1",
	"prop_rub_trukwreck_2",
	"prop_rub_tyre_01",
	"prop_rub_tyre_02",
	"prop_rub_tyre_03",
	"prop_rub_tyre_dam1",
	"prop_rub_tyre_dam2",
	"prop_rub_tyre_dam3",
	"prop_rub_washer_01",
	"prop_rub_wheel_01",
	"prop_rub_wheel_02",
	"prop_rub_wreckage_3",
	"prop_rub_wreckage_4",
	"prop_rub_wreckage_5",
	"prop_rub_wreckage_6",
	"prop_rub_wreckage_7",
	"prop_rub_wreckage_8",
	"prop_rub_wreckage_9",
	"prop_skid_chair_01",
	"prop_skid_chair_02",
	"prop_skid_chair_03",
	"prop_skid_sleepbag_1",
	"prop_skid_tent_01",
	"prop_skid_tent_01b",
	"prop_skid_tent_03",
	"prop_still",
	"prop_bench_01b",
	"prop_bench_01c",
	"prop_bench_04",
	"prop_bench_05",
	"prop_bench_09",
	"prop_chair_01a",
	"prop_chair_01b",
	"prop_chair_02",
	"prop_chair_03",
	"prop_chair_04a",
	"prop_chair_04b",
	"prop_chair_05",
	"prop_chair_06",
	"prop_chair_07",
	"prop_chair_08",
	"prop_chair_09",
	"prop_chair_10",
	"prop_chair_pile_01",
	"prop_chateau_chair_01",
	"prop_clown_chair",
	"prop_old_deck_chair",
	"prop_old_deck_chair_02",
	"prop_old_wood_chair",
	"prop_old_wood_chair_lod",
	"prop_parasol_01",
	"prop_parasol_01_b",
	"prop_parasol_01_c",
	"prop_parasol_01_down",
	"prop_parasol_02",
	"prop_parasol_02_b",
	"prop_parasol_02_c",
	"prop_parasol_03",
	"prop_parasol_03_b",
	"prop_parasol_03_c",
	"prop_parasol_04e",
	"prop_parasol_04e_lod1",
	"prop_parasol_bh_48",
	"prop_patio_heater_01",
	"prop_patio_lounger1",
	"prop_patio_lounger1b",
	"prop_patio_lounger1_table",
	"prop_patio_lounger_2",
	"prop_patio_lounger_3",
	"prop_picnictable_02",
	"prop_proxy_chateau_table",
	"prop_stool_01",
	"prop_table_02",
	"prop_table_03b_cs",
	"prop_table_04",
	"prop_table_04_chr",
	"prop_table_05",
	"prop_table_05_chr",
	"prop_table_06",
	"prop_table_06_chr",
	"prop_table_07",
	"prop_table_07_l1",
	"prop_table_08",
	"prop_table_08_chr",
	"prop_table_08_side",
	"prop_table_para_comb_04",
	"prop_umpire_01",
	"prop_afsign_amun",
	"prop_afsign_vbike",
	"prop_beer_neon_01",
	"prop_beer_neon_02",
	"prop_beer_neon_03",
	"prop_beer_neon_04",
	"prop_billboard_01",
	"prop_billboard_02",
	"prop_billboard_03",
	"prop_billboard_04",
	"prop_billboard_05",
	"prop_billboard_06",
	"prop_billboard_07",
	"prop_billboard_08",
	"prop_billboard_09",
	"prop_billboard_09wall",
	"prop_billboard_10",
	"prop_billboard_11",
	"prop_billboard_12",
	"prop_billboard_13",
	"prop_billboard_14",
	"prop_billboard_15",
	"prop_billboard_16",
	"prop_gas_01",
	"prop_gas_02",
	"prop_gas_03",
	"prop_gas_04",
	"prop_gas_05",
	"prop_pharm_sign_01",
	"prop_sign_airp_01a",
	"prop_sign_airp_02a",
	"prop_sign_airp_02b",
	"prop_sign_big_01",
	"prop_sign_road_04g_l1",
	"prop_barrel_01a",
	"prop_barrel_02a",
	"prop_barrel_02b",
	"prop_barrel_03a",
	"prop_barrel_03d",
	"prop_boxpile_10a",
	"prop_boxpile_10b",
	"prop_box_ammo01a",
	"prop_box_ammo02a",
	"prop_box_ammo03a_set",
	"prop_box_ammo03a_set2",
	"prop_box_ammo04a",
	"prop_box_ammo05b",
	"prop_box_ammo07a",
	"prop_box_ammo07b",
	"prop_box_guncase_01a",
	"prop_box_guncase_02a",
	"prop_box_guncase_03a",
	"prop_box_tea01a",
	"prop_box_wood05a",
	"prop_box_wood05b",
	"prop_box_wood08a",
	"prop_buckets_02",
	"prop_bucket_01a",
	"prop_bucket_01b",
	"prop_bucket_02a",
	"prop_cntrdoor_ld_l",
	"prop_cntrdoor_ld_r",
	"prop_container_01a",
	"prop_container_01b",
	"prop_container_01c",
	"prop_container_01d",
	"prop_container_01e",
	"prop_container_01f",
	"prop_container_01g",
	"prop_container_01h",
	"prop_container_01mb",
	"prop_container_02a",
	"prop_container_03a",
	"prop_container_03b",
	"prop_container_03mb",
	"prop_container_03_ld",
	"prop_container_04a",
	"prop_container_04mb",
	"prop_container_05mb",
	"prop_container_door_mb_l",
	"prop_container_door_mb_r",
	"prop_container_ld",
	"prop_container_ld2",
	"prop_container_old1",
	"prop_contnr_pile_01a",
	"prop_cratepile_07a_l1",
	"prop_crate_01a",
	"prop_crate_02a",
	"prop_crate_08a",
	"prop_crate_09a",
	"prop_crate_10a",
	"prop_crate_11a",
	"prop_crate_11b",
	"prop_crate_11c",
	"prop_crate_11d",
	"prop_dog_cage_01",
	"prop_dog_cage_02",
	"prop_drop_crate_01",
	"prop_drop_crate_01_set",
	"prop_drop_crate_01_set2",
	"prop_flattrailer_01a",
	"prop_flattruck_01a",
	"prop_fruitstand_b_nite",
	"prop_gascage01",
	"prop_keg_01",
	"prop_mb_crate_01a_set",
	"prop_pallettruck_01",
	"prop_sacktruck_01",
	"prop_sacktruck_02a",
	"prop_shelves_01",
	"prop_shelves_02",
	"prop_shelves_03",
	"prop_truktrailer_01a",
	"prop_warehseshelf01",
	"prop_warehseshelf02",
	"prop_warehseshelf03",
	"prop_watercrate_01",
	"prop_chall_lamp_01",
	"prop_chall_lamp_01n",
	"prop_chall_lamp_02",
	"prop_construcionlamp_01",
	"prop_dt1_13_groundlight",
	"prop_dt1_13_walllightsource",
	"prop_ind_light_01a",
	"prop_ind_light_01b",
	"prop_ind_light_01c",
	"prop_securityvan_lightrig",
	"prop_traffic_rail_1c",
	"prop_traffic_rail_2",
	"prop_walllight_ld_01b",
	"prop_wall_light_08a",
	"prop_wall_light_10a",
	"prop_wall_light_10b",
	"prop_wall_light_10c",
	"prop_wall_light_11",
	"prop_wall_light_12",
	"prop_wall_light_17b",
	"prop_wall_light_18a",
	"prop_warninglight_01",
	"prop_atm_02",
	"prop_atm_03",
	"prop_bikerack_2",
	"prop_bollard_01a",
	"prop_bollard_01b",
	"prop_bollard_01c",
	"prop_bollard_03a",
	"prop_elecbox_03a",
	"prop_elecbox_10",
	"prop_elecbox_12",
	"prop_elecbox_13",
	"prop_elecbox_14",
	"prop_elecbox_15",
	"prop_elecbox_16",
	"prop_elecbox_17",
	"prop_elecbox_18",
	"prop_elecbox_19",
	"prop_elecbox_20",
	"prop_elecbox_21",
	"prop_elecbox_22",
	"prop_elecbox_23",
	"prop_elecbox_24",
	"prop_elecbox_24b",
	"prop_elecbox_25",
	"prop_fire_driser_1a",
	"prop_fire_driser_1b",
	"prop_fire_driser_2b",
	"prop_fire_driser_3b",
	"prop_fire_driser_4a",
	"prop_fire_driser_4b",
	"prop_fire_hosereel",
	"prop_fleeca_atm",
	"prop_gshotsensor_01",
	"prop_mobile_mast_1",
	"prop_mobile_mast_2",
	"prop_parking_sign_06",
	"prop_parking_sign_07",
	"prop_parking_sign_1",
	"prop_parking_sign_2",
	"prop_phonebox_05a",
	"prop_telegraph_01a",
	"prop_telegraph_01b",
	"prop_telegraph_01c",
	"prop_telegraph_01d",
	"prop_telegraph_01e",
	"prop_telegraph_01f",
	"prop_telegraph_01g",
	"prop_telegraph_02a",
	"prop_telegraph_02b",
	"prop_telegraph_03",
	"prop_telegraph_04a",
	"prop_telegraph_04b",
	"prop_telegraph_05a",
	"prop_telegraph_05b",
	"prop_telegraph_05c",
	"prop_telegraph_06a",
	"prop_telegraph_06b",
	"prop_telegraph_06c",
	"prop_telegwall_01a",
	"prop_telegwall_01b",
	"prop_telegwall_02a",
	"prop_telegwall_03a",
	"prop_telegwall_03b",
	"prop_telegwall_04a",
	"prop_tram_pole_double01",
	"prop_tram_pole_double02",
	"prop_tram_pole_double03",
	"prop_tram_pole_roadside",
	"prop_tram_pole_single01",
	"prop_tram_pole_single02",
	"prop_tram_pole_wide01",
	"prop_tyre_rack_01",
	"prop_valet_03",
	"prop_cartwheel_01",
	"prop_cattlecrush",
	"prop_chickencoop_a",
	"prop_feeder1",
	"prop_grain_hopper",
	"prop_handrake",
	"prop_haybailer_01",
	"prop_haybale_01",
	"prop_haybale_02",
	"prop_haybale_stack_01",
	"prop_hunterhide",
	"prop_oldplough1",
	"prop_old_churn_01",
	"prop_old_churn_02",
	"prop_old_farm_01",
	"prop_old_farm_02",
	"prop_potatodigger",
	"prop_roundbailer01",
	"prop_roundbailer02",
	"prop_rural_windmill_l1",
	"prop_rural_windmill_l2",
	"prop_scythemower",
	"prop_side_spreader",
	"prop_snow_bailer_01",
	"prop_snow_barrel_pile_03",
	"prop_snow_bench_01",
	"prop_snow_bin_01",
	"prop_snow_bin_02",
	"prop_snow_cam_03",
	"prop_snow_cam_03a",
	"prop_snow_diggerbkt_01",
	"prop_snow_dumpster_01",
	"prop_snow_elecbox_16",
	"prop_snow_facgate_01",
	"prop_snow_flower_01",
	"prop_snow_flower_02",
	"prop_snow_fnclink_03crnr2",
	"prop_snow_fnclink_03h",
	"prop_snow_fnclink_03i",
	"prop_snow_fncwood_14a",
	"prop_snow_fncwood_14b",
	"prop_snow_fncwood_14c",
	"prop_snow_fncwood_14d",
	"prop_snow_fncwood_14e",
	"prop_snow_fnc_01",
	"prop_snow_gate_farm_03",
	"prop_snow_grain_01",
	"prop_snow_light_01",
	"prop_snow_oldlight_01b",
	"prop_snow_rail_signals02",
	"prop_snow_rub_trukwreck_2",
	"prop_snow_side_spreader_01",
	"prop_snow_streetlight01",
	"prop_snow_streetlight_01_frag_",
	"prop_snow_sub_frame_01a",
	"prop_snow_sub_frame_04b",
	"prop_snow_telegraph_01a",
	"prop_snow_telegraph_02a",
	"prop_snow_telegraph_03",
	"prop_snow_traffic_rail_1a",
	"prop_snow_traffic_rail_1b",
	"prop_snow_trailer01",
	"prop_snow_truktrailer_01a",
	"prop_snow_tyre_01",
	"prop_snow_wall_light_15a",
	"prop_snow_watertower01",
	"prop_snow_watertower01_l2",
	"prop_snow_watertower03",
	"prop_snow_woodpile_04a",
	"prop_sprayer",
	"prop_trailer01",
	"prop_trailer01_up",
	"prop_trough1",
	"prop_waterwheela",
	"prop_waterwheelb",
	"prop_wreckedcart",
	"prop_am_box_wood_01",
	"prop_bush_ivy_01_1m",
	"prop_bush_ivy_01_2m",
	"prop_bush_ivy_01_bk",
	"prop_bush_ivy_01_l",
	"prop_bush_ivy_01_pot",
	"prop_bush_ivy_01_r",
	"prop_bush_ivy_01_top",
	"prop_bush_ivy_02_1m",
	"prop_bush_ivy_02_2m",
	"prop_bush_ivy_02_l",
	"prop_bush_ivy_02_pot",
	"prop_bush_ivy_02_r",
	"prop_bush_ivy_02_top",
	"prop_bush_lrg_01",
	"prop_bush_lrg_01b",
	"prop_bush_lrg_01c",
	"prop_bush_lrg_01d",
	"prop_bush_lrg_01e",
	"prop_bush_lrg_02",
	"prop_bush_lrg_02b",
	"prop_bush_lrg_03",
	"prop_bush_lrg_03b",
	"prop_bush_lrg_04b",
	"prop_bush_lrg_04c",
	"prop_bush_lrg_04d",
	"prop_bush_med_01",
	"prop_bush_med_02",
	"prop_bush_med_03",
	"prop_bush_med_05",
	"prop_bush_med_06",
	"prop_bush_med_07",
	"prop_bush_neat_01",
	"prop_bush_neat_02",
	"prop_bush_neat_03",
	"prop_bush_neat_04",
	"prop_bush_neat_05",
	"prop_bush_neat_06",
	"prop_bush_neat_07",
	"prop_bush_neat_08",
	"prop_bush_ornament_01",
	"prop_bush_ornament_02",
	"prop_bush_ornament_03",
	"prop_bush_ornament_04",
	"prop_creosote_b_01",
	"prop_desert_iron_01",
	"prop_plant_group_01",
	"prop_plant_group_02",
	"prop_plant_group_03",
	"prop_plant_group_04",
	"prop_plant_group_05",
	"prop_plant_group_05b",
	"prop_plant_group_05c",
	"prop_plant_group_05d",
	"prop_plant_group_06a",
	"prop_plant_group_06b",
	"prop_plant_group_06c",
	"prop_skunk_bush_01",
	"prop_bush_grape_01",
	"prop_coral_bush_01",
	"prop_coral_flat_01",
	"prop_coral_flat_01_l1",
	"prop_coral_flat_02",
	"prop_coral_flat_brainy",
	"prop_coral_flat_clam",
	"prop_coral_grass_01",
	"prop_coral_grass_02",
	"prop_coral_kelp_01",
	"prop_coral_kelp_01_l1",
	"prop_coral_kelp_02",
	"prop_coral_kelp_02_l1",
	"prop_coral_kelp_03",
	"prop_coral_kelp_03a",
	"prop_coral_kelp_03b",
	"prop_coral_kelp_03c",
	"prop_coral_kelp_03d",
	"prop_coral_kelp_03_l1",
	"prop_coral_kelp_04",
	"prop_coral_kelp_04_l1",
	"prop_coral_pillar_01",
	"prop_coral_pillar_02",
	"prop_coral_spikey_01",
	"prop_coral_stone_03",
	"prop_coral_stone_04",
	"prop_coral_sweed_01",
	"prop_coral_sweed_02",
	"prop_coral_sweed_03",
	"prop_coral_sweed_04",
	"prop_cora_clam_01",
	"prop_tree_birch_05",
	"prop_veg_corn_01",
	"prop_veg_crop_01",
	"prop_veg_crop_02",
	"prop_veg_crop_04",
	"prop_veg_crop_04_leaf",
	"prop_veg_crop_05",
	"prop_veg_crop_06",
	"prop_veg_crop_orange",
	"prop_veg_crop_tr_01",
	"prop_veg_crop_tr_02",
	"prop_agave_01",
	"prop_agave_02",
	"prop_aloevera_01",
	"prop_bush_dead_02",
	"prop_cat_tail_01",
	"prop_cs_plant_01",
	"prop_grass_dry_02",
	"prop_grass_dry_03",
	"prop_plant_01a",
	"prop_plant_01b",
	"prop_plant_base_01",
	"prop_plant_base_02",
	"prop_plant_base_03",
	"prop_plant_cane_01a",
	"prop_plant_cane_01b",
	"prop_plant_cane_02a",
	"prop_plant_cane_02b",
	"prop_plant_clover_01",
	"prop_plant_clover_02",
	"prop_plant_fern_01a",
	"prop_plant_fern_01b",
	"prop_plant_fern_02a",
	"prop_plant_fern_02b",
	"prop_plant_fern_02c",
	"prop_plant_flower_01",
	"prop_plant_flower_02",
	"prop_plant_flower_03",
	"prop_plant_flower_04",
	"prop_plant_paradise",
	"prop_plant_paradise_b",
	"prop_p_spider_01a",
	"prop_p_spider_01c",
	"prop_p_spider_01d",
	"prop_veg_grass_01_a",
	"prop_veg_grass_01_b",
	"prop_veg_grass_01_c",
	"prop_veg_grass_01_d",
	"prop_veg_grass_02_a",
	"prop_fan_palm_01a",
	"prop_palm_fan_02_a",
	"prop_palm_fan_02_b",
	"prop_palm_fan_03_a",
	"prop_palm_fan_03_b",
	"prop_palm_fan_03_c",
	"prop_palm_fan_03_d",
	"prop_palm_fan_04_a",
	"prop_palm_fan_04_b",
	"prop_palm_fan_04_c",
	"prop_palm_fan_04_d",
	"prop_palm_huge_01a",
	"prop_palm_huge_01b",
	"prop_palm_med_01a",
	"prop_palm_med_01b",
	"prop_palm_med_01c",
	"prop_palm_med_01d",
	"prop_palm_sm_01a",
	"prop_palm_sm_01d",
	"prop_palm_sm_01e",
	"prop_palm_sm_01f",
	"prop_plant_int_02a",
	"prop_plant_int_02b",
	"prop_plant_int_05a",
	"prop_plant_int_05b",
	"prop_plant_int_06a",
	"prop_plant_int_06b",
	"prop_plant_int_06c",
	"prop_pot_plant_02a",
	"prop_pot_plant_02b",
	"prop_pot_plant_02c",
	"prop_pot_plant_02d",
	"prop_pot_plant_03a",
	"prop_pot_plant_04a",
	"prop_pot_plant_05d_l1",
	"prop_pot_plant_bh1",
	"prop_rock_1_a",
	"prop_rock_1_b",
	"prop_rock_1_c",
	"prop_rock_1_d",
	"prop_rock_1_e",
	"prop_rock_1_f",
	"prop_rock_1_g",
	"prop_rock_1_h",
	"prop_rock_1_i",
	"prop_rock_2_a",
	"prop_rock_2_c",
	"prop_rock_2_d",
	"prop_rock_2_f",
	"prop_rock_2_g",
	"prop_rock_3_a",
	"prop_rock_3_b",
	"prop_rock_3_c",
	"prop_rock_3_d",
	"prop_rock_3_e",
	"prop_rock_3_f",
	"prop_rock_3_g",
	"prop_rock_3_h",
	"prop_rock_3_i",
	"prop_rock_3_j",
	"prop_rock_4_c",
	"prop_rock_4_d",
	"rock_4_cl_2_1",
	"rock_4_cl_2_2",
	"prop_snow_bush_01_a",
	"prop_snow_bush_02_a",
	"prop_snow_bush_02_b",
	"prop_snow_bush_03",
	"prop_snow_bush_04",
	"prop_snow_bush_04b",
	"prop_snow_field_01",
	"prop_snow_field_02",
	"prop_snow_field_03",
	"prop_snow_field_04",
	"prop_snow_grass_01",
	"prop_snow_tree_03_e",
	"prop_snow_tree_03_h",
	"prop_snow_tree_03_i",
	"prop_snow_tree_04_d",
	"prop_snow_tree_04_f",
	"prop_snow_t_ml_01",
	"prop_snow_t_ml_02",
	"prop_snow_t_ml_03",
	"prop_rio_del_01",
	"prop_rus_olive",
	"prop_rus_olive_wint",
	"prop_s_pine_dead_01",
	"prop_tree_birch_01",
	"prop_tree_birch_02",
	"prop_tree_birch_03",
	"prop_tree_birch_03b",
	"prop_tree_birch_04",
	"prop_tree_cedar_02",
	"prop_tree_cedar_03",
	"prop_tree_cedar_04",
	"prop_tree_cedar_s_01",
	"prop_tree_cedar_s_02",
	"prop_tree_cedar_s_04",
	"prop_tree_cedar_s_05",
	"prop_tree_cedar_s_06",
	"prop_tree_cypress_01",
	"prop_tree_eng_oak_01",
	"prop_tree_eucalip_01",
	"prop_tree_fallen_01",
	"prop_tree_fallen_02",
	"prop_tree_fallen_pine_01",
	"prop_tree_jacada_01",
	"prop_tree_jacada_02",
	"prop_tree_lficus_02",
	"prop_tree_lficus_03",
	"prop_tree_lficus_05",
	"prop_tree_lficus_06",
	"prop_tree_log_01",
	"prop_tree_log_02",
	"prop_tree_maple_02",
	"prop_tree_maple_03",
	"prop_tree_mquite_01",
	"prop_tree_oak_01",
	"prop_tree_olive_01",
	"prop_tree_pine_01",
	"prop_tree_pine_02",
	"prop_tree_stump_01",
	"prop_w_r_cedar_01",
	"prop_w_r_cedar_dead",
	"w_am_baseball",
	"w_am_baseball_hi",
	"w_am_brfcase",
	"w_am_case",
	"w_am_digiscanner",
	"w_am_digiscanner_hi",
	"w_am_fire_exting",
	"w_am_flare",
	"w_am_flare_hi",
	"w_am_jerrycan",
	"w_ar_advancedrifle",
	"w_ar_advancedrifle_hi",
	"w_ar_advancedrifle_mag1",
	"w_ar_advancedrifle_mag2",
	"w_ar_assaultrifle",
	"w_ar_assaultrifle_hi",
	"w_ar_assaultrifle_mag1",
	"w_ar_assaultrifle_mag2",
	"w_ar_carbinerifle",
	"w_ar_carbinerifle_hi",
	"w_ar_carbinerifle_mag1",
	"w_ar_carbinerifle_mag2",
	"w_at_ar_afgrip",
	"w_at_ar_afgrip_hi",
	"w_at_ar_flsh",
	"w_at_ar_flsh_hi",
	"w_at_ar_supp",
	"w_at_ar_supp_02",
	"w_at_ar_supp_02_hi",
	"w_at_ar_supp_hi",
	"w_at_pi_flsh",
	"w_at_pi_flsh_hi",
	"w_at_pi_supp",
	"w_at_pi_supp_hi",
	"w_at_railcover_01",
	"w_at_railcover_01_hi",
	"w_at_scope_large",
	"w_at_scope_large_hi",
	"w_at_scope_macro",
	"w_at_scope_macro_hi",
	"w_at_scope_max",
	"w_at_scope_max_hi",
	"w_at_scope_medium",
	"w_at_scope_medium_hi",
	"w_at_scope_small",
	"w_at_scope_small_hi",
	"w_at_sr_supp",
	"w_at_sr_supp_hi",
	"w_ex_grenadefrag",
	"w_ex_grenadefrag_hi",
	"w_ex_grenadesmoke",
	"w_ex_molotov",
	"w_ex_molotov_hi",
	"w_ex_pe",
	"w_ex_pe_hi",
	"w_lr_40mm",
	"w_lr_40mm_pu",
	"w_lr_grenadelauncher",
	"w_lr_grenadelauncher_hi",
	"w_lr_rpg",
	"w_lr_rpg_hi",
	"w_lr_rpg_rocket",
	"w_lr_rpg_rocket_pu",
	"w_me_bat",
	"w_me_crowbar",
	"w_me_gclub",
	"w_me_hammer",
	"w_me_knife_01",
	"w_me_nightstick",
	"w_mg_combatmg",
	"w_mg_combatmg_hi",
	"w_mg_combatmg_mag1",
	"w_mg_combatmg_mag2",
	"w_mg_mg",
	"w_mg_mg_hi",
	"w_mg_mg_mag1",
	"w_mg_mg_mag2",
	"w_mg_minigun",
	"w_mg_minigun_hi",
	"w_pi_appistol",
	"w_pi_appistol_hi",
	"w_pi_appistol_mag1",
	"w_pi_appistol_mag2",
	"w_pi_combatpistol",
	"w_pi_combatpistol_hi",
	"w_pi_combatpistol_mag1",
	"w_pi_combatpistol_mag2",
	"w_pi_pistol",
	"w_pi_pistol50",
	"w_pi_pistol50_hi",
	"w_pi_pistol50_mag1",
	"w_pi_pistol50_mag2",
	"w_pi_pistol_hi",
	"w_pi_pistol_mag1",
	"w_pi_pistol_mag2",
	"w_pi_stungun",
	"w_pi_stungun_hi",
	"w_sb_assaultsmg",
	"w_sb_assaultsmg_hi",
	"w_sb_assaultsmg_mag1",
	"w_sb_assaultsmg_mag2",
	"w_sb_microsmg",
	"w_sb_microsmg_hi",
	"w_sb_microsmg_mag1",
	"w_sb_microsmg_mag2",
	"w_sb_smg",
	"w_sb_smg_hi",
	"w_sb_smg_mag1",
	"w_sb_smg_mag2",
	"w_sg_assaultshotgun",
	"w_sg_assaultshotgun_hi",
	"w_sg_assaultshotgun_mag1",
	"w_sg_assaultshotgun_mag2",
	"w_sg_bullpupshotgun",
	"w_sg_bullpupshotgun_hi",
	"w_sg_pumpshotgun",
	"w_sg_pumpshotgun_hi",
	"w_sg_sawnoff",
	"w_sg_sawnoff_hi",
	"w_sr_heavysniper",
	"w_sr_heavysniper_hi",
	"w_sr_heavysniper_mag1",
	"w_sr_sniperrifle",
	"w_sr_sniperrifle_hi",
	"w_sr_sniperrifle_mag1",
};
struct tunableList
{
	char* label;
	int index;
	int type;
};
static tunableList TunableList[] =
{
	{ "CASH_MULTIPLIER", 0, 1 },
	{ "XP_MULTIPLIER", 1, 1 },
	{ "CHEAT_THRESHOLD", 2, 0 },
	{ "CHEAT_THRESHOLD_NOTCHEATER", 3, 0 },
	{ "CHEAT_RESET_MINUTES", 4, 0 },
	{ "AMOUNT_TO_FORGIVE_BY", 5, 1 },
	{ "KICK_VOTES_NEEDED_RATIO", 6, 1 },
	{ "AMOUNT_TO_FORGIVE_BY_HELPFUL", 7, 1 },
	{ "AMOUNT_TO_FORGIVE_BY_FRIENDLY", 8, 1 },
	{ "AMOUNT_TO_PUNISH_BY_GRIEFING", 9, 1 },
	{ "AMOUNT_TO_PUNISH_BY_OFFENSIVE_LANGUAGE", 10, 1 },
	{ "AMOUNT_TO_PUNISH_BY_OFFENSIVE_TAG", 11, 1 },
	{ "AMOUNT_TO_PUNISH_BY_OFFENSIVE_UGC", 12, 1 },
	{ "AMOUNT_TO_PUNISH_BY_VC_ANNOY", 13, 1 },
	{ "336289304", 14, 0 },
	{ "MP_COUNTDOWN", 15, 0 },
	{ "CRATE_DROP_SPECIAL_WEAPON", 38, 0 },
	{ "CRATE_DROP_SPEICAL_WEAPON_CLIPS", 39, 0 },
	{ "CRATE_DROP_CASH_MIN", 40, 0 },
	{ "CRATE_DROP_CASH_MAX", 41, 0 },
	{ "CRATE_DROP_SPECIAL_CASH", 42, 0 },
	{ "CRATE_DROP_STANDARD_MIN_FREQ", 43, 0 },
	{ "CRATE_DROP_STANDARD_MAX_FREQ", 44, 0 },
	{ "CRATE_DROP_SPECIAL_FREQUENCY", 45, 0 },
	{ "CRATE_DROP_CASH_TOTAL_MAX", 46, 0 },
	{ "SHOP_SALES_ACTIVE", 61, 2 },
	{ "CRATE_DROP_XP", 65, 0 },
	{ "CRATE_DROP_SPECIAL_XP", 66, 0 },
	{ "CRATE_DROP_LOCATION", 67, 0 },
	{ "CRATE_DROP_CLOTHING_MALE", 68, 0 },
	{ "CRATE_DROP_CLOTHING_FEMALE", 69, 0 },
	{ "AUTOMUTE_PERCENT", 70, 1 },
	{ "BADSPORTCHEAT_AUTOMUTE_PERCENT", 71, 1 },
	{ "CARMOD_SHOP_MULTIPLIER", 72, 1 },
	{ "CLOTHES_SHOP_MULTIPLIER", 73, 1 },
	{ "HAIRDO_SHOP_MULTIPLIER", 74, 1 },
	{ "TATTOO_SHOP_MULTIPLIER", 75, 1 },
	{ "WEAPONS_SHOP_MULTIPLIER", 76, 1 },
	{ "PROPERTY_MULTIPLIER", 77, 1 },
	{ "CARS_WEBSITE_MULTIPLIER", 78, 1 },
	{ "PLANES_WEBSITE_MULTIPLIER", 79, 1 },
	{ "HELIS_WEBSITE_MULTIPLIER", 80, 1 },
	{ "BOATS_WEBSITE_MULTIPLIER", 81, 1 },
	{ "BIKES_WEBSITE_MULTIPLIER", 82, 1 },
	{ "KILL_DEATH_CHEAT_THRESH", 83, 1 },
	{ "GOOD_BOY_CASH_AWARD", 84, 0 },
	{ "SPENT_TO_GIVE_RATIO", 85, 1 },
	{ "SPENT_TO_GIVE_RATIO", 85, 1 },
	{ "IDLEKICK_WARNING1", 86, 0 },
	{ "IDLEKICK_WARNING2", 87, 0 },
	{ "IDLEKICK_WARNING3", 88, 0 },
	{ "IDLEKICK_KICK", 89, 0 },
	{ "SCRIPT_MP_TIMEOUT", 90, 0 },
	{ "SOCIAL_CLUB_PRESENCE_UPDATE_TIME", 94, 0 },
	{ "BADSPORT_THRESHOLD", 95, 0 },
	{ "BADSPORT_THRESHOLD_NOTCHEATER", 96, 0 },
	{ "BADSPORT_RESET_MINUTES", 97, 0 },
	{ "AMOUNT_TO_FORGIVE_BADSPORT_BY", 98, 1 },
	{ "CHEAT_TIME_EXPONENTIAL", 99, 0 },
	{ "MAX_BET_LIMIT", 100, 1 },
	{ "MIN_BET_LIMIT", 101, 1 },
	{ "SHORT_ODDS_LIMIT", 102, 1 },
	{ "LONG_ODDS_LIMIT", 103, 1 },
	{ "BOOKIE_RAKE", 104, 1 },
	{ "BOOKIE_RAKE", 104, 1 },
	{ "MAX_HEALTH_MULTIPLIER", 105, 1 },
	{ "MIN_HEALTH_MULTIPLIER", 106, 1 },
	{ "HEALTH_REGEN_RATE_MULTIPLIER", 107, 1 },
	{ "HEALTH_REGEN_MAX_MULTIPLIER", 108, 1 },
	{ "MAX_ARMOR_MULTIPLIER", 110, 1 },
	{ "PSANDQS_HEALTH_REPLENISH_MULTIPLIER", 111, 1 },
	{ "EGOCHASER_HEALTH_REPLENISH_MULTIPLIER", 112, 1 },
	{ "METEORITE_HEALTH_REPLENISH_MULTIPLIER", 113, 1 },
	{ "REDWOOD_HEALTH_DEPLETE_MULTIPLIER", 114, 1 },
	{ "ORANGOTANG_HEALTH_REPLENISH_MULTIPLIER", 115, 1 },
	{ "BOURGEOIX_HEALTH_REPLENISH_MULTIPLIER", 116, 1 },
	{ "SHOP_DISCOUNT_PERCENT", 120, 0 },
	{ "SHOP_GOODBOY_DISCOUNT_PERCENT", 121, 0 },
	{ "SCRIPT_MP_TIMEOUT_SHORT", 122, 0 },
	{ "SCRIPT_MP_TIMEOUT_LONG", 123, 0 },
	{ "MAX_BET_TOTAL_AMOUNT_ON_A_SINGLE_PLAYER", 125, 1 },
	{ "CRATE_DROP_SPECIAL_CRATE_DROP_PERCENTAGE", 126, 0 },
	{ "CRATE_DROP_SPECIAL_CRATE_MIN_PLAYERS", 127, 0 },
	{ "EXPIRED_CHALLENGE_BASIC_XP_REWARD", 128, 0 },
	{ "EXPIRED_CHALLENGE_TURN_OFF_XP_REWARD", 129, 2 },
	{ "AMOUNT_TO_VOTED_OUT", 131, 1 },
	{ "AMOUNT_TO_DESTORYED_PVEHICLE", 132, 1 },
	{ "CRC_DONEPLAYERS_RESET_START", 134, 0 },
	{ "CRC_DONEPLAYERS_RESET_END", 135, 0 },
	{ "CRC_BETWEEN_CHECKS_TIME_START", 136, 0 },
	{ "CRC_BETWEEN_CHECKS_TIME_END", 137, 0 },
	{ "BADSPORT_NUMDAYS_1ST_OFFENCE", 138, 0 },
	{ "BADSPORT_NUMDAYS_2ND_OFFENCE", 139, 0 },
	{ "BADSPORT_NUMDAYS_3RD_OFFENCE", 140, 0 },
	{ "BADSPORT_NUMDAYS_4TH_OFFENCE", 141, 0 },
	{ "BADSPORT_NUMDAYS_5TH_OFFENCE", 142, 0 },
	{ "BADSPORT_NUMDAYS_6TH_OFFENCE", 143, 0 },
	{ "BADSPORT_NUMDAYS_7TH_OFFENCE", 144, 0 },
	{ "BADSPORT_NUMDAYS_8TH_OFFENCE", 145, 0 },
	{ "BADSPORT_NUMDAYS_9TH_OFFENCE", 146, 0 },
	{ "CONTACT_MISSION_INITIAL_DELAY_SECS", 148, 0 },
	{ "CONTACT_MISSION_REGULAR_DELAY_SECS", 149, 0 },
	{ "CONTACT_MISSION_SERVER_DELAY_SECS", 150, 0 },
	{ "ELO_SEASON", 151, 0 },
	{ "BOOKMARK_REFRESH", 152, 0 },
	{ "AI_HEALTH", 153, 1 },
	{ "PASSIVE_DONATE", 154, 0 },
	{ "LOW_APRT_UTIL", 156, 0 },
	{ "MID_APRT_UTIL", 157, 0 },
	{ "HIGH_APRT_UTIL", 158, 0 },
	{ "PHONE_FRIEND_CHARGE", 161, 0 },
	{ "PED_DROP_CASH_MULTIPLIER", 162, 1 },
	{ "IMP_EXP_EARN_CAP", 163, 0 },
	{ "CARMOD_CAR_VAL_SELL_CAP", 164, 0 },
	{ "IMPROMPTU_RACE_CASH_AWARD_CAP", 165, 0 },
	{ "HOLD_UP_CASH_REWARD_CAP", 166, 0 },
	{ "IMPROMPTU_RACE_EXPENSES_MULTIPLIER", 167, 1 },
	{ "IMPROMPTU_RACE_ENTRY_FEE_CAP", 168, 0 },
	{ "IMPROMPTU_DM_ENTRY_MULTIPLIER", 169, 1 },
	{ "HIGH_TUTORIAL_WALLET_CASH", 2330, 0 },
	{ "LOW_TUTORIAL_WALLET_CASH", 2331, 0 },
	{ "HIGH_TUTORIAL_BANK_CASH", 2332, 0 },
	{ "LOW_TUTORIAL_BANK_CASH", 2333, 0 },
	{ "HIGH_PRIORITY_IMPORT_EXPORT_VEHICLE", 2334, 0 },
	{ "BOUNTY_AWARD_LEVEL_1_MODIFIER", 2337, 0 },
	{ "BOUNTY_AWARD_LEVEL_2_MODIFIER", 2338, 0 },
	{ "BOUNTY_AWARD_LEVEL_3_MODIFIER", 2339, 0 },
	{ "BOUNTY_AWARD_LEVEL_4_MODIFIER", 2340, 0 },
	{ "BOUNTY_AWARD_LEVEL_5_MODIFIER", 2341, 0 },
	{ "VEHICLE_RENTAL_PRICE_MODIFIER", 2342, 0 },
	{ "PISTOL_MODIFIER", 2343, 0 },
	{ "COMBAT_PISTOL_MODIFIER", 2344, 0 },
	{ "AP_PISTOL_MODIFIER", 2346, 0 },
	{ "MICRO_SMG_MODIFIER", 2347, 0 },
	{ "SMG_MODIFIER", 2348, 0 },
	{ "ASSAULT_SMG_MODIFIER", 2349, 0 },
	{ "ASSAULT_RIFLE_MODIFIER", 2350, 0 },
	{ "CARBINE_RIFLE_MODIFIER", 2351, 0 },
	{ "HEAVY_RIFLE_MODIFIER", 2352, 0 },
	{ "ADVANCED_RIFLE_MODIFIER", 2353, 0 },
	{ "MG_MODIFIER", 2354, 0 },
	{ "COMBAT_MG_MODIFIER", 2355, 0 },
	{ "ASSAULT_MG_MODIFIER", 2356, 0 },
	{ "PUMP_SHOTGUN_MODIFIER", 2357, 0 },
	{ "SAWEDOFF_SHOTGUN_MODIFIER", 2358, 0 },
	{ "BULLPUP_SHOTGUN_MODIFIER", 2359, 0 },
	{ "ASSAULT_SHOTGUN_MODIFIER", 2360, 0 },
	{ "HEAVY_SNIPER_MODIFIER", 2361, 0 },
	{ "REMOTE_SNIPER_MODIFIER", 2362, 0 },
	{ "SNIPER_RIFLE_MODIFIER", 2363, 0 },
	{ "ASSAULT_SNIPER_MODIFIER", 2364, 0 },
	{ "GRENADE_LAUNCHER_MODIFIER", 2365, 0 },
	{ "RPG_MODIFIER", 2366, 0 },
	{ "MINIGUN_MODIFIER", 2367, 0 },
	{ "TEARGAS_MODIFIER", 2368, 0 },
	{ "JERRYCAN_MODIFIER", 2369, 0 },
	{ "SAWNOFF_SHOTGUN_MODIFIER", 2370, 0 },
	{ "HAMMER_MODIFIER", 2371, 0 },
	{ "PISTOL_AMMO_AMMO_MODIFIER", 2372, 0 },
	{ "COMBAT_PISTOL_AMMO_MODIFIER", 2373, 0 },
	{ "PISTOL50_AMMO_MODIFIER", 2374, 0 },
	{ "AP_PISTOL_AMMO_MODIFIER", 2375, 0 },
	{ "MICRO_SMG_AMMO_MODIFIER", 2376, 0 },
	{ "SMG_AMMO_MODIFIER", 2377, 0 },
	{ "ASSAULT_SMG_AMMO_MODIFIER", 2378, 0 },
	{ "ASSAULT_RIFLE_AMMO_MODIFIER", 2379, 0 },
	{ "CARBINE_RIFLE_AMMO_MODIFIER", 2380, 0 },
	{ "HEAVY_RIFLE_AMMO_MODIFIER", 2381, 0 },
	{ "ADVANCED_RIFLE_AMMO_MODIFIER", 2382, 0 },
	{ "MG_AMMO_MODIFIER", 2383, 0 },
	{ "COMBAT_MG_AMMO_MODIFIER", 2384, 0 },
	{ "ASSAULT_MG_AMMO_MODIFIER", 2385, 0 },
	{ "PUMP_SHOTGUN_AMMO_MODIFIER", 2386, 0 },
	{ "SAWEDOFF_SHOTGUN_AMMO_MODIFIER", 2387, 0 },
	{ "BULLPUP_SHOTGUN_AMMO_MODIFIER", 2388, 0 },
	{ "ASSAULT_SHOTGUN_AMMO_MODIFIER", 2389, 0 },
	{ "HEAVY_SNIPER_AMMO_MODIFIER", 2390, 0 },
	{ "REMOTE_SNIPER_AMMO_MODIFIER", 2391, 0 },
	{ "SNIPER_RIFLE_AMMO_MODIFIER", 2392, 0 },
	{ "ASSAULT_SNIPER_AMMO_MODIFIER", 2393, 0 },
	{ "GRENADE_LAUNCHER_AMMO_MODIFIER", 2394, 0 },
	{ "RPG_AMMO_MODIFIER", 2395, 0 },
	{ "MINIGUN_AMMO_MODIFIER", 2396, 0 },
	{ "STICKYBOMB_MODIFIER", 2397, 0 },
	{ "GRENADE_MODIFIER", 2398, 0 },
	{ "KNIFE_MODIFIER", 2400, 0 },
	{ "MININIGHTSTICK_MODIFIER", 2401, 0 },
	{ "STICKYBOMB_AMMO_MODIFIER", 2403, 0 },
	{ "GRENADE_AMMO_MODIFIER", 2404, 0 },
	{ "TEARGAS_AMMO_MODIFIER", 2405, 0 },
	{ "KNIFE_AMMO_MODIFIER", 2406, 0 },
	{ "NIGHTSTICK_AMMO_MODIFIER", 2407, 0 },
	{ "QUERYING_BOOKMARKS", 2409, 0 },
	{ "PLAYER_HEADSHOP_UPLOAD_TUNABLE", 2410, 0 },
	{ "EARNINGS_IMPORT_EXPORT_MODIFIER", 2411, 1 },
	{ "BOUNTY_MINIMUM_PAYOUT_MODIFIER", 2412, 1 },
	{ "WIN_RACE_MODIFIER", 2413, 1 },
	{ "WIN_DEATHMATCH_MODIFIER", 2414, 1 },
	{ "KILLSTREAK_BONUS_ON_DEATHMATCH_MODIFIER", 2415, 1 },
	{ "KILLSTREAK_BONUS_ON_MISSION_MODIFIER", 2416, 1 },
	{ "HIGH_HOLD_UPS_MODIFIER", 2417, 1 },
	{ "HIGH_LESTER_NPC_TARGET_MODIFIER", 2418, 1 },
	{ "HIGH_ROCKSTAR_MISSIONS_MODIFIER", 2419, 1 },
	{ "HIGH_SELLING_VEHICLES_MAX_VALUE_MODIFIER", 2420, 1 },
	{ "LOW_HOLD_UPS_MODIFIER", 2421, 1 },
	{ "LOW_LESTER_NPC_TARGET_MODIFIER", 2422, 1 },
	{ "LOW_ROCKSTAR_MISSIONS_MODIFIER", 2423, 1 },
	{ "ARMOURED_TRUCK_EARNINGS_MULTIPLIER", 2424, 1 },
	{ "ARMOURED_TRUCK_EARNINGS_MULTIPLIER_LO", 2425, 1 },
	{ "ARMOURED_TRUCK_EARNINGS_MULTIPLIER_HI", 2426, 1 },
	{ "STAMINA_AMOUNT_DRAINED_MODIFIER", 2449, 0 },
	{ "IS_SALE_ON_IN_TATTOO_SHOP", 2450, 2 },
	{ "IS_SALE_ON_IN_MASK_SHOP", 2451, 2 },
	{ "IS_SALE_ON_IN_CLOTHING_SHOP", 2452, 2 },
	{ "IS_SALE_ON_IN_HAIR_SHOP", 2453, 2 },
	{ "IS_SALE_ON_IN_CAR_MOD_SHOP", 2454, 2 },
	{ "MAKEUP_UNLOCKS_BASIC_EXPENDITURE_TUNABLE", 2609, 1 },
	{ "MAKEUP_UNLOCKS_NUDE_EXPENDITURE_TUNABLE", 2610, 1 },
	{ "MAKEUP_UNLOCKS_SMOKY_EXPENDITURE_TUNABLE", 2611, 1 },
	{ "MAKEUP_UNLOCKS_GOTHIC_EXPENDITURE_TUNABLE", 2612, 1 },
	{ "MAKEUP_UNLOCKS_ROCKER_EXPENDITURE_TUNABLE", 2613, 1 },
	{ "MAKEUP_UNLOCKS_PARTYGIRL_EXPENDITURE_TUNABLE", 2614, 1 },
	{ "MAKEUP_UNLOCKS_ARTSY_EXPENDITURE_TUNABLE", 2615, 1 },
	{ "MAKEUP_UNLOCKS_TRAILERPARKPRINCESS_EXPENDITURE_TUNABLE", 2616, 1 },
	{ "MAKEUP_UNLOCKS_SOCCERMOM_EXPENDITURE_TUNABLE", 2617, 1 },
	{ "MAKEUP_UNLOCKS_FEMMEFATALE_EXPENDITURE_TUNABLE", 2618, 1 },
	{ "MAKEUP_UNLOCKS_SERIOUSLYCERISE_EXPENDITURE_TUNABLE", 2619, 1 },
	{ "MAKEUP_UNLOCKS_DISCOTEQUEWRECK_EXPENDITURE_TUNABLE", 2620, 1 },
	{ "MAKEUP_UNLOCKS_BEAUTYSPOT_EXPENDITURE_TUNABLE", 2621, 1 },
	{ "MAKEUP_UNLOCKS_TONEDDOWN_EXPENDITURE_TUNABLE", 2622, 1 },
	{ "MAKEUP_UNLOCKS_CYANSWIPED_EXPENDITURE_TUNABLE", 2623, 1 },
	{ "MAKEUP_UNLOCKS_MORNINGAFTER_EXPENDITURE_TUNABLE", 2624, 1 },
	{ "MAKEUP_UNLOCKS_COVERGIRL_EXPENDITURE_TUNABLE", 2625, 1 },
	{ "MAKEUP_UNLOCKS_KISSMYAXE_EXPENDITURE_TUNABLE", 2626, 1 },
	{ "MAKEUP_UNLOCKS_PANDAPUSSY_EXPENDITURE_TUNABLE", 2627, 1 },
	{ "MAKEUP_UNLOCKS_THEBAT_EXPENDITURE_TUNABLE", 2628, 1 },
	{ "MAKEUP_UNLOCKS_SKULLINSCARLET_EXPENDITURE_TUNABLE", 2629, 1 },
	{ "MAKEUP_UNLOCKS_SERPENTINE_EXPENDITURE_TUNABLE", 2630, 1 },
	{ "MAKEUP_UNLOCKS_THEVELDT_EXPENDITURE_TUNABLE", 2631, 1 },
	{ "MAKEUP_UNLOCKS_THEJOCK_EXPENDITURE_TUNABLE", 2632, 1 },
	{ "MAKEUP_UNLOCKS_LOSSANTOSCORKERS_EXPENDITURE_TUNABLE", 2633, 1 },
	{ "MAKEUP_UNLOCKS_LOSSANTOSPANIC_EXPENDITURE_TUNABLE", 2634, 1 },
	{ "MAKEUP_UNLOCKS_LIBERTYCITYSWINGERS_EXPENDITURE_TUNABLE", 2635, 1 },
	{ "MAKEUP_UNLOCKS_TRIBALLINES_EXPENDITURE_TUNABLE", 2636, 1 },
	{ "MAKEUP_UNLOCKS_TRIBALSWIRLS_EXPENDITURE_TUNABLE", 2637, 1 },
	{ "MAKEUP_UNLOCKS_TRIBALORANGE_EXPENDITURE_TUNABLE", 2638, 1 },
	{ "MAKEUP_UNLOCKS_TRIBALRED_EXPENDITURE_TUNABLE", 2639, 1 },
	{ "MAKEUP_UNLOCKS_TRAPPEDINABOX_EXPENDITURE_TUNABLE", 2640, 1 },
	{ "MAKEUP_UNLOCKS_CLOWNING_EXPENDITURE_TUNABLE", 2641, 1 },
	{ "MAKEUP_UNLOCKS_GUYLINER_EXPENDITURE_TUNABLE", 2642, 1 },
	{ "BEARD_UNLOCKS_CLEANSHAVEN_EXPENDITURE_TUNABLE", 2643, 1 },
	{ "BEARD_UNLOCKS_LIGHTSTUBBLE_EXPENDITURE_TUNABLE", 2644, 1 },
	{ "BEARD_UNLOCKS_BALBO_EXPENDITURE_TUNABLE", 2645, 1 },
	{ "BEARD_UNLOCKS_CIRCLEBEARD_EXPENDITURE_TUNABLE", 2646, 1 },
	{ "BEARD_UNLOCKS_GOATEE_EXPENDITURE_TUNABLE", 2647, 1 },
	{ "BEARD_UNLOCKS_CHIN_EXPENDITURE_TUNABLE", 2648, 1 },
	{ "BEARD_UNLOCKS_SOULPATCH_EXPENDITURE_TUNABLE", 2649, 1 },
	{ "BEARD_UNLOCKS_PENCILCHINSTRAP_EXPENDITURE_TUNABLE", 2650, 1 },
	{ "BEARD_UNLOCKS_LIGHTBEARD_EXPENDITURE_TUNABLE", 2651, 1 },
	{ "BEARD_UNLOCKS_MUSKETEER_EXPENDITURE_TUNABLE", 2652, 1 },
	{ "BEARD_UNLOCKS_MOUSTACHE_EXPENDITURE_TUNABLE", 2653, 1 },
	{ "BEARD_UNLOCKS_HEAVYBEARD_EXPENDITURE_TUNABLE", 2654, 1 },
	{ "BEARD_UNLOCKS_STUBBLE_EXPENDITURE_TUNABLE", 2655, 1 },
	{ "BEARD_UNLOCKS_CIRCLEBEARD2_EXPENDITURE_TUNABLE", 2656, 1 },
	{ "BEARD_UNLOCKS_HORSESHOEANDSIDEBURNS_EXPENDITURE_TUNABLE", 2657, 1 },
	{ "BEARD_UNLOCKS_PENCILMOUSTACHEANDMUTTONCHOPS_EXPENDITURE_TUNABLE", 2658, 1 },
	{ "BEARD_UNLOCKS_PENCILMOUSTACHEANDCHINSTRAP_EXPENDITURE_TUNABLE", 2659, 1 },
	{ "BEARD_UNLOCKS_BALBOANDDESIGNSIDEBURNS_EXPENDITURE_TUNABLE", 2660, 1 },
	{ "BEARD_UNLOCKS_MUTTONCHOPS_EXPENDITURE_TUNABLE", 2661, 1 },
	{ "BEARD_UNLOCKS_FULLBEARD_EXPENDITURE_TUNABLE", 2662, 1 },
	{ "PLAYERKIT_FM_PARACHUTE_EXPENDITURE_TUNABLE", 2663, 1 },
	{ "PLAYERKIT_FM_PARASMOKE_RED_EXPENDITURE_TUNABLE", 2664, 1 },
	{ "PLAYERKIT_FM_PARASMOKE_ORANGE_EXPENDITURE_TUNABLE", 2665, 1 },
	{ "PLAYERKIT_FM_PARASMOKE_YELLOW_EXPENDITURE_TUNABLE", 2666, 1 },
	{ "PLAYERKIT_FM_THERMALVISION_EXPENDITURE_TUNABLE", 2667, 1 },
	{ "PLAYERKIT_FM_PARASMOKE_BLACK_EXPENDITURE_TUNABLE", 2668, 1 },
	{ "PLAYERKIT_FM_PARASMOKE_BLUE_EXPENDITURE_TUNABLE", 2669, 1 },
	{ "PLAYERKIT_FM_RAINBOW_PARACHUTE_EXPENDITURE_TUNABLE", 2670, 1 },
	{ "PLAYERKIT_FM_RED_PARACHUTE_EXPENDITURE_TUNABLE", 2671, 1 },
	{ "PLAYERKIT_FM_YELLOWWHITEBLUE_PARACHUTE_EXPENDITURE_TUNABLE", 2672, 1 },
	{ "PLAYERKIT_FM_WHITEREDBROWN_PARACHUTE_EXPENDITURE_TUNABLE", 2673, 1 },
	{ "PLAYERKIT_FM_BLUEWHITERED_PARACHUTE_EXPENDITURE_TUNABLE", 2674, 1 },
	{ "PLAYERKIT_FM_BLUE_PARACHUTE_EXPENDITURE_TUNABLE", 2675, 1 },
	{ "PLAYERKIT_FM_BLACK_PARACHUTE_EXPENDITURE_TUNABLE", 2676, 1 },
	{ "PLAYERKIT_FM_BROWNYELLOW_PARACHUTE_EXPENDITURE_TUNABLE", 2677, 1 },
	{ "PLAYERKIT_GOLD_PISTOL_EXPENDITURE_TUNABLE", 2678, 1 },
	{ "PLAYERKIT_GOLD_CMBTPISTOL_EXPENDITURE_TUNABLE", 2679, 1 },
	{ "PLAYERKIT_GOLD_APPISTOL_EXPENDITURE_TUNABLE", 2680, 1 },
	{ "PLAYERKIT_GOLD_MICROSMG_EXPENDITURE_TUNABLE", 2681, 1 },
	{ "PLAYERKIT_GOLD_SMG_EXPENDITURE_TUNABLE", 2682, 1 },
	{ "PLAYERKIT_GOLD_ASLTRIFLE_EXPENDITURE_TUNABLE", 2683, 1 },
	{ "PLAYERKIT_GOLD_CRBNRIFLE_EXPENDITURE_TUNABLE", 2684, 1 },
	{ "PLAYERKIT_GOLD_ADVRRIFLE_EXPENDITURE_TUNABLE", 2685, 1 },
	{ "PLAYERKIT_GOLD_MG_EXPENDITURE_TUNABLE", 2686, 1 },
	{ "PLAYERKIT_GOLD_CMBTMG_EXPENDITURE_TUNABLE", 2687, 1 },
	{ "PLAYERKIT_GOLD_PUMP_EXPENDITURE_TUNABLE", 2688, 1 },
	{ "PLAYERKIT_GOLD_SAWOFF_EXPENDITURE_TUNABLE", 2689, 1 },
	{ "PLAYERKIT_GOLD_ASLTSHTGN_EXPENDITURE_TUNABLE", 2690, 1 },
	{ "PLAYERKIT_GOLD_RUBBERGUN_EXPENDITURE_TUNABLE", 2691, 1 },
	{ "PLAYERKIT_GOLD_STUNGUN_EXPENDITURE_TUNABLE", 2692, 1 },
	{ "PLAYERKIT_GOLD_SNIPERRFL_EXPENDITURE_TUNABLE", 2693, 1 },
	{ "PLAYERKIT_GOLD_HVYSNIPER_EXPENDITURE_TUNABLE", 2694, 1 },
	{ "PLAYERKIT_GOLD_GRNLAUNCH_EXPENDITURE_TUNABLE", 2695, 1 },
	{ "PLAYERKIT_GOLD_RPG_EXPENDITURE_TUNABLE", 2696, 1 },
	{ "PLAYERKIT_GOLD_MINIGUN_EXPENDITURE_TUNABLE", 2697, 1 },
	{ "PLAYERKIT_PLATINUM_PISTOL_EXPENDITURE_TUNABLE", 2698, 1 },
	{ "PLAYERKIT_PLATINUM_CMBTPISTOL_EXPENDITURE_TUNABLE", 2699, 1 },
	{ "PLAYERKIT_PLATINUM_APPISTOL_EXPENDITURE_TUNABLE", 2700, 1 },
	{ "PLAYERKIT_PLATINUM_MICROSMG_EXPENDITURE_TUNABLE", 2701, 1 },
	{ "PLAYERKIT_PLATINUM_SMG_EXPENDITURE_TUNABLE", 2702, 1 },
	{ "PLAYERKIT_PLATINUM_ASLTRIFLE_EXPENDITURE_TUNABLE", 2703, 1 },
	{ "PLAYERKIT_PLATINUM_CRBNRIFLE_EXPENDITURE_TUNABLE", 2704, 1 },
	{ "PLAYERKIT_PLATINUM_ADVRRIFLE_EXPENDITURE_TUNABLE", 2705, 1 },
	{ "PLAYERKIT_PLATINUM_MG_EXPENDITURE_TUNABLE", 2706, 1 },
	{ "PLAYERKIT_PLATINUM_CMBTMG_EXPENDITURE_TUNABLE", 2707, 1 },
	{ "PLAYERKIT_PLATINUM_PUMP_EXPENDITURE_TUNABLE", 2708, 1 },
	{ "PLAYERKIT_PLATINUM_SAWOFF_EXPENDITURE_TUNABLE", 2709, 1 },
	{ "PLAYERKIT_PLATINUM_ASLTSHTGN_EXPENDITURE_TUNABLE", 2710, 1 },
	{ "PLAYERKIT_PLATINUM_RUBBERGUN_EXPENDITURE_TUNABLE", 2711, 1 },
	{ "PLAYERKIT_PLATINUM_STUNGUN_EXPENDITURE_TUNABLE", 2712, 1 },
	{ "PLAYERKIT_PLATINUM_SNIPERRFL_EXPENDITURE_TUNABLE", 2713, 1 },
	{ "PLAYERKIT_PLATINUM_HVYSNIPER_EXPENDITURE_TUNABLE", 2714, 1 },
	{ "PLAYERKIT_PLATINUM_GRNLAUNCH_EXPENDITURE_TUNABLE", 2715, 1 },
	{ "PLAYERKIT_PLATINUM_RPG_EXPENDITURE_TUNABLE", 2716, 1 },
	{ "PLAYERKIT_PLATINUM_MINIGUN_EXPENDITURE_TUNABLE", 2717, 1 },
	{ "PLAYERKIT_TAN_PISTOL_EXPENDITURE_TUNABLE", 2718, 1 },
	{ "PLAYERKIT_TAN_CMBTPISTOL_EXPENDITURE_TUNABLE", 2719, 1 },
	{ "PLAYERKIT_TAN_APPISTOL_EXPENDITURE_TUNABLE", 2720, 1 },
	{ "PLAYERKIT_TAN_MICROSMG_EXPENDITURE_TUNABLE", 2721, 1 },
	{ "PLAYERKIT_TAN_SMG_EXPENDITURE_TUNABLE", 2722, 1 },
	{ "PLAYERKIT_TAN_ASLTRIFLE_EXPENDITURE_TUNABLE", 2723, 1 },
	{ "PLAYERKIT_TAN_CRBNRIFLE_EXPENDITURE_TUNABLE", 2724, 1 },
	{ "PLAYERKIT_TAN_ADVRRIFLE_EXPENDITURE_TUNABLE", 2725, 1 },
	{ "PLAYERKIT_TAN_MG_EXPENDITURE_TUNABLE", 2726, 1 },
	{ "PLAYERKIT_TAN_CMBTMG_EXPENDITURE_TUNABLE", 2727, 1 },
	{ "PLAYERKIT_TAN_PUMP_EXPENDITURE_TUNABLE", 2728, 1 },
	{ "PLAYERKIT_TAN_SAWOFF_EXPENDITURE_TUNABLE", 2729, 1 },
	{ "PLAYERKIT_TAN_ASLTSHTGN_EXPENDITURE_TUNABLE", 2730, 1 },
	{ "PLAYERKIT_TAN_RUBBERGUN_EXPENDITURE_TUNABLE", 2731, 1 },
	{ "PLAYERKIT_TAN_STUNGUN_EXPENDITURE_TUNABLE", 2732, 1 },
	{ "PLAYERKIT_TAN_SNIPERRFL_EXPENDITURE_TUNABLE", 2733, 1 },
	{ "PLAYERKIT_TAN_HVYSNIPER_EXPENDITURE_TUNABLE", 2734, 1 },
	{ "PLAYERKIT_TAN_GRNLAUNCH_EXPENDITURE_TUNABLE", 2735, 1 },
	{ "PLAYERKIT_TAN_RPG_EXPENDITURE_TUNABLE", 2736, 1 },
	{ "PLAYERKIT_TAN_MINIGUN_EXPENDITURE_TUNABLE", 2737, 1 },
	{ "PLAYERKIT_GREEN_PISTOL_EXPENDITURE_TUNABLE", 2738, 1 },
	{ "PLAYERKIT_GREEN_CMBTPISTOL_EXPENDITURE_TUNABLE", 2739, 1 },
	{ "PLAYERKIT_GREEN_APPISTOL_EXPENDITURE_TUNABLE", 2740, 1 },
	{ "PLAYERKIT_GREEN_MICROSMG_EXPENDITURE_TUNABLE", 2741, 1 },
	{ "PLAYERKIT_GREEN_SMG_EXPENDITURE_TUNABLE", 2742, 1 },
	{ "PLAYERKIT_GREEN_ASLTRIFLE_EXPENDITURE_TUNABLE", 2743, 1 },
	{ "PLAYERKIT_GREEN_CRBNRIFLE_EXPENDITURE_TUNABLE", 2744, 1 },
	{ "PLAYERKIT_GREEN_ADVRRIFLE_EXPENDITURE_TUNABLE", 2745, 1 },
	{ "PLAYERKIT_GREEN_MG_EXPENDITURE_TUNABLE", 2746, 1 },
	{ "PLAYERKIT_GREEN_CMBTMG_EXPENDITURE_TUNABLE", 2747, 1 },
	{ "PLAYERKIT_GREEN_PUMP_EXPENDITURE_TUNABLE", 2748, 1 },
	{ "PLAYERKIT_GREEN_SAWOFF_EXPENDITURE_TUNABLE", 2749, 1 },
	{ "PLAYERKIT_GREEN_ASLTSHTGN_EXPENDITURE_TUNABLE", 2750, 1 },
	{ "PLAYERKIT_GREEN_RUBBERGUN_EXPENDITURE_TUNABLE", 2751, 1 },
	{ "PLAYERKIT_GREEN_STUNGUN_EXPENDITURE_TUNABLE", 2752, 1 },
	{ "PLAYERKIT_GREEN_SNIPERRFL_EXPENDITURE_TUNABLE", 2753, 1 },
	{ "PLAYERKIT_GREEN_HVYSNIPER_EXPENDITURE_TUNABLE", 2754, 1 },
	{ "PLAYERKIT_GREEN_GRNLAUNCH_EXPENDITURE_TUNABLE", 2755, 1 },
	{ "PLAYERKIT_GREEN_RPG_EXPENDITURE_TUNABLE", 2756, 1 },
	{ "PLAYERKIT_GREEN_MINIGUN_EXPENDITURE_TUNABLE", 2757, 1 },
	{ "PLAYERKIT_RED_PISTOL_EXPENDITURE_TUNABLE", 2758, 1 },
	{ "PLAYERKIT_RED_CMBTPISTOL_EXPENDITURE_TUNABLE", 2759, 1 },
	{ "PLAYERKIT_RED_APPISTOL_EXPENDITURE_TUNABLE", 2760, 1 },
	{ "PLAYERKIT_RED_MICROSMG_EXPENDITURE_TUNABLE", 2761, 1 },
	{ "PLAYERKIT_RED_SMG_EXPENDITURE_TUNABLE", 2762, 1 },
	{ "PLAYERKIT_RED_ASLTRIFLE_EXPENDITURE_TUNABLE", 2763, 1 },
	{ "PLAYERKIT_RED_CRBNRIFLE_EXPENDITURE_TUNABLE", 2764, 1 },
	{ "PLAYERKIT_RED_ADVRRIFLE_EXPENDITURE_TUNABLE", 2765, 1 },
	{ "PLAYERKIT_RED_MG_EXPENDITURE_TUNABLE", 2766, 1 },
	{ "PLAYERKIT_RED_CMBTMG_EXPENDITURE_TUNABLE", 2767, 1 },
	{ "PLAYERKIT_RED_PUMP_EXPENDITURE_TUNABLE", 2768, 1 },
	{ "PLAYERKIT_RED_SAWOFF_EXPENDITURE_TUNABLE", 2769, 1 },
	{ "PLAYERKIT_RED_ASLTSHTGN_EXPENDITURE_TUNABLE", 2770, 1 },
	{ "PLAYERKIT_RED_RUBBERGUN_EXPENDITURE_TUNABLE", 2771, 1 },
	{ "PLAYERKIT_RED_STUNGUN_EXPENDITURE_TUNABLE", 2772, 1 },
	{ "PLAYERKIT_RED_SNIPERRFL_EXPENDITURE_TUNABLE", 2773, 1 },
	{ "PLAYERKIT_RED_HVYSNIPER_EXPENDITURE_TUNABLE", 2774, 1 },
	{ "PLAYERKIT_RED_GRNLAUNCH_EXPENDITURE_TUNABLE", 2775, 1 },
	{ "PLAYERKIT_RED_RPG_EXPENDITURE_TUNABLE", 2776, 1 },
	{ "PLAYERKIT_RED_MINIGUN_EXPENDITURE_TUNABLE", 2777, 1 },
	{ "PLAYERKIT_BLUE_PISTOL_EXPENDITURE_TUNABLE", 2778, 1 },
	{ "PLAYERKIT_BLUE_CMBTPISTOL_EXPENDITURE_TUNABLE", 2779, 1 },
	{ "PLAYERKIT_BLUE_APPISTOL_EXPENDITURE_TUNABLE", 2780, 1 },
	{ "PLAYERKIT_BLUE_MICROSMG_EXPENDITURE_TUNABLE", 2781, 1 },
	{ "PLAYERKIT_BLUE_SMG_EXPENDITURE_TUNABLE", 2782, 1 },
	{ "PLAYERKIT_BLUE_ASLTRIFLE_EXPENDITURE_TUNABLE", 2783, 1 },
	{ "PLAYERKIT_BLUE_CRBNRIFLE_EXPENDITURE_TUNABLE", 2784, 1 },
	{ "PLAYERKIT_BLUE_ADVRRIFLE_EXPENDITURE_TUNABLE", 2785, 1 },
	{ "PLAYERKIT_BLUE_MG_EXPENDITURE_TUNABLE", 2786, 1 },
	{ "PLAYERKIT_BLUE_CMBTMG_EXPENDITURE_TUNABLE", 2787, 1 },
	{ "PLAYERKIT_BLUE_PUMP_EXPENDITURE_TUNABLE", 2788, 1 },
	{ "PLAYERKIT_BLUE_SAWOFF_EXPENDITURE_TUNABLE", 2789, 1 },
	{ "PLAYERKIT_BLUE_ASLTSHTGN_EXPENDITURE_TUNABLE", 2790, 1 },
	{ "PLAYERKIT_BLUE_RUBBERGUN_EXPENDITURE_TUNABLE", 2791, 1 },
	{ "PLAYERKIT_BLUE_STUNGUN_EXPENDITURE_TUNABLE", 2792, 1 },
	{ "PLAYERKIT_BLUE_SNIPERRFL_EXPENDITURE_TUNABLE", 2793, 1 },
	{ "PLAYERKIT_BLUE_HVYSNIPER_EXPENDITURE_TUNABLE", 2794, 1 },
	{ "PLAYERKIT_BLUE_GRNLAUNCH_EXPENDITURE_TUNABLE", 2795, 1 },
	{ "PLAYERKIT_BLUE_RPG_EXPENDITURE_TUNABLE", 2796, 1 },
	{ "PLAYERKIT_BLUE_MINIGUN_EXPENDITURE_TUNABLE", 2797, 1 },
	{ "PLAYERKIT_PINK_PISTOL_EXPENDITURE_TUNABLE", 2798, 1 },
	{ "PLAYERKIT_PINK_CMBTPISTOL_EXPENDITURE_TUNABLE", 2799, 1 },
	{ "PLAYERKIT_PINK_APPISTOL_EXPENDITURE_TUNABLE", 2800, 1 },
	{ "PLAYERKIT_PINK_MICROSMG_EXPENDITURE_TUNABLE", 2801, 1 },
	{ "PLAYERKIT_PINK_SMG_EXPENDITURE_TUNABLE", 2802, 1 },
	{ "PLAYERKIT_PINK_ASLTRIFLE_EXPENDITURE_TUNABLE", 2803, 1 },
	{ "PLAYERKIT_PINK_CRBNRIFLE_EXPENDITURE_TUNABLE", 2804, 1 },
	{ "PLAYERKIT_PINK_ADVRRIFLE_EXPENDITURE_TUNABLE", 2805, 1 },
	{ "PLAYERKIT_PINK_MG_EXPENDITURE_TUNABLE", 2806, 1 },
	{ "PLAYERKIT_PINK_CMBTMG_EXPENDITURE_TUNABLE", 2807, 1 },
	{ "PLAYERKIT_PINK_PUMP_EXPENDITURE_TUNABLE", 2808, 1 },
	{ "PLAYERKIT_PINK_SAWOFF_EXPENDITURE_TUNABLE", 2809, 1 },
	{ "PLAYERKIT_PINK_ASLTSHTGN_EXPENDITURE_TUNABLE", 2810, 1 },
	{ "PLAYERKIT_PINK_RUBBERGUN_EXPENDITURE_TUNABLE", 2811, 1 },
	{ "PLAYERKIT_PINK_STUNGUN_EXPENDITURE_TUNABLE", 2812, 1 },
	{ "PLAYERKIT_PINK_SNIPERRFL_EXPENDITURE_TUNABLE", 2813, 1 },
	{ "PLAYERKIT_PINK_HVYSNIPER_EXPENDITURE_TUNABLE", 2814, 1 },
	{ "PLAYERKIT_PINK_GRNLAUNCH_EXPENDITURE_TUNABLE", 2815, 1 },
	{ "PLAYERKIT_PINK_RPG_EXPENDITURE_TUNABLE", 2816, 1 },
	{ "PLAYERKIT_PINK_MINIGUN_EXPENDITURE_TUNABLE", 2817, 1 },
	{ "PLAYERKIT_SUPERLIGHTARMOUR_EXPENDITURE_TUNABLE", 2818, 1 },
	{ "PLAYERKIT_LIGHTARMOUR_EXPENDITURE_TUNABLE", 2819, 1 },
	{ "PLAYERKIT_STANDARDARMOUR_EXPENDITURE_TUNABLE", 2820, 1 },
	{ "PLAYERKIT_HEAVYARMOUR_EXPENDITURE_TUNABLE", 2821, 1 },
	{ "PLAYERKIT_SUPERHEAVYARMOUR_EXPENDITURE_TUNABLE", 2822, 1 },
	{ "PLAYERKIT_GOLD_DLC_ASSAULTSMG_EXPENDITURE_TUNABLE", 2823, 1 },
	{ "PLAYERKIT_PINK_DLC_ASSAULTSMG_EXPENDITURE_TUNABLE", 2824, 1 },
	{ "PLAYERKIT_TAN_DLC_ASSAULTSMG_EXPENDITURE_TUNABLE", 2825, 1 },
	{ "PLAYERKIT_BLUE_DLC_ASSAULTSMG_EXPENDITURE_TUNABLE", 2826, 1 },
	{ "PLAYERKIT_RED_DLC_ASSAULTSMG_EXPENDITURE_TUNABLE", 2827, 1 },
	{ "PLAYERKIT_PLATINUM_DLC_ASSAULTSMG_EXPENDITURE_TUNABLE", 2828, 1 },
	{ "PLAYERKIT_GOLD_DLC_ASSAULTSNIPER_EXPENDITURE_TUNABLE", 2829, 1 },
	{ "PLAYERKIT_PINK_DLC_ASSAULTSNIPER_EXPENDITURE_TUNABLE", 2830, 1 },
	{ "PLAYERKIT_TAN_DLC_ASSAULTSNIPER_EXPENDITURE_TUNABLE", 2831, 1 },
	{ "PLAYERKIT_BLUE_DLC_ASSAULTSNIPER_EXPENDITURE_TUNABLE", 2832, 1 },
	{ "PLAYERKIT_RED_DLC_ASSAULTSNIPER_EXPENDITURE_TUNABLE", 2833, 1 },
	{ "PLAYERKIT_PLATINUM_DLC_ASSAULTSNIPER_EXPENDITURE_TUNABLE", 2834, 1 },
	{ "PLAYERKIT_GOLD_DLC_ASSAULTMG_EXPENDITURE_TUNABLE", 2841, 1 },
	{ "PLAYERKIT_PINK_DLC_ASSAULTMG_EXPENDITURE_TUNABLE", 2842, 1 },
	{ "PLAYERKIT_TAN_DLC_ASSAULTMG_EXPENDITURE_TUNABLE", 2843, 1 },
	{ "PLAYERKIT_BLUE_DLC_ASSAULTMG_EXPENDITURE_TUNABLE", 2844, 1 },
	{ "PLAYERKIT_RED_DLC_ASSAULTMG_EXPENDITURE_TUNABLE", 2845, 1 },
	{ "PLAYERKIT_PLATINUM_DLC_ASSAULTMG_EXPENDITURE_TUNABLE", 2846, 1 },
	{ "PLAYERKIT_GOLD_DLC_HEAVYRIFLE_EXPENDITURE_TUNABLE", 2847, 1 },
	{ "PLAYERKIT_PINK_DLC_HEAVYRIFLE_EXPENDITURE_TUNABLE", 2848, 1 },
	{ "PLAYERKIT_TAN_DLC_HEAVYRIFLE_EXPENDITURE_TUNABLE", 2849, 1 },
	{ "PLAYERKIT_BLUE_DLC_HEAVYRIFLE_EXPENDITURE_TUNABLE", 2850, 1 },
	{ "PLAYERKIT_RED_DLC_HEAVYRIFLE_EXPENDITURE_TUNABLE", 2851, 1 },
	{ "PLAYERKIT_PLATINUM_DLC_HEAVYRIFLE_EXPENDITURE_TUNABLE", 2852, 1 },
	{ "PLAYERKIT_GREEN_DLC_HEAVYRIFLE_EXPENDITURE_TUNABLE", 2853, 1 },
	{ "PLAYERKIT_GREEN_DLC_ASSAULTSMG_EXPENDITURE_TUNABLE", 2854, 1 },
	{ "PLAYERKIT_GREEN_DLC_ASSAULTMG_EXPENDITURE_TUNABLE", 2855, 1 },
	{ "PLAYERKIT_ARMOUR_STORE_L1_RANK_TUNABLE", 2857, 0 },
	{ "PLAYERKIT_ARMOUR_STORE_L2_RANK_TUNABLE", 2858, 0 },
	{ "PLAYERKIT_ARMOUR_STORE_L3_RANK_TUNABLE", 2859, 0 },
	{ "PLAYERKIT_ARMOUR_STORE_L4_RANK_TUNABLE", 2860, 0 },
	{ "PLAYERKIT_ARMOUR_STORE_L5_RANK_TUNABLE", 2861, 0 },
	{ "PLAYERKIT_ARMOUR_STORE_L6_RANK_TUNABLE", 2862, 0 },
	{ "PLAYERKIT_ARMOUR_STORE_L7_RANK_TUNABLE", 2863, 0 },
	{ "PLAYERKIT_ARMOUR_STORE_L8_RANK_TUNABLE", 2864, 0 },
	{ "PLAYERKIT_ARMOUR_STORE_L9_RANK_TUNABLE", 2865, 0 },
	{ "WEAPONADDON_AT_AR_AFGRIP_EXPENDITURE_TUNABLE", 2868, 1 },
	{ "WEAPONADDON_AT_PI_FLSH_EXPENDITURE_TUNABLE", 2869, 1 },
	{ "WEAPONADDON_AT_PI_LASR_EXPENDITURE_TUNABLE", 2870, 1 },
	{ "WEAPONADDON_AT_PI_FLSHLASR_EXPENDITURE_TUNABLE", 2871, 1 },
	{ "WEAPONADDON_AT_AR_FLSH_EXPENDITURE_TUNABLE", 2872, 1 },
	{ "WEAPONADDON_AT_AR_LASR_EXPENDITURE_TUNABLE", 2873, 1 },
	{ "WEAPONADDON_AT_AR_FLSHLASR_EXPENDITURE_TUNABLE", 2874, 1 },
	{ "WEAPONADDON_AT_SCOPE_MACRO_EXPENDITURE_TUNABLE", 2875, 1 },
	{ "WEAPONADDON_AT_SCOPE_SMALL_EXPENDITURE_TUNABLE", 2876, 1 },
	{ "WEAPONADDON_AT_SCOPE_MEDIUM_EXPENDITURE_TUNABLE", 2877, 1 },
	{ "WEAPONADDON_AT_SCOPE_LARGE_EXPENDITURE_TUNABLE", 2878, 1 },
	{ "WEAPONADDON_AT_SCOPE_MAX_EXPENDITURE_TUNABLE", 2879, 1 },
	{ "WEAPONADDON_AT_PI_SUPP_EXPENDITURE_TUNABLE", 2880, 1 },
	{ "WEAPONADDON_AT_AR_SUPP_EXPENDITURE_TUNABLE", 2881, 1 },
	{ "WEAPONADDON_AT_SR_SUPP_EXPENDITURE_TUNABLE", 2883, 1 },
	{ "WEAPONADDON_PISTOL_CLIP_02_EXPENDITURE_TUNABLE", 2884, 1 },
	{ "WEAPONADDON_COMBATPISTOL_CLIP_02_EXPENDITURE_TUNABLE", 2885, 1 },
	{ "WEAPONADDON_PISTOL50_CLIP_02_EXPENDITURE_TUNABLE", 2886, 1 },
	{ "WEAPONADDON_APPISTOL_CLIP_02_EXPENDITURE_TUNABLE", 2887, 1 },
	{ "WEAPONADDON_MICROSMG_CLIP_02_EXPENDITURE_TUNABLE", 2888, 1 },
	{ "WEAPONADDON_SMG_CLIP_02_EXPENDITURE_TUNABLE", 2889, 1 },
	{ "WEAPONADDON_ASSAULTSMG_CLIP_02_EXPENDITURE_TUNABLE", 2890, 1 },
	{ "WEAPONADDON_ASSAULTRIFLE_CLIP_02_EXPENDITURE_TUNABLE", 2891, 1 },
	{ "WEAPONADDON_CARBINERIFLE_CLIP_02_EXPENDITURE_TUNABLE", 2892, 1 },
	{ "WEAPONADDON_ADVANCEDRIFLE_CLIP_02_EXPENDITURE_TUNABLE", 2894, 1 },
	{ "WEAPONADDON_MG_CLIP_02_EXPENDITURE_TUNABLE", 2895, 1 },
	{ "WEAPONADDON_COMBATMG_CLIP_02_EXPENDITURE_TUNABLE", 2896, 1 },
	{ "WEAPONADDON_ASSAULTSHOTGUN_CLIP_02_EXPENDITURE_TUNABLE", 2898, 1 },
	{ "WEAPONADDON_PROGRAMMABLEAR_PROGRAMMABLE_TARGETING_EXPENDITURE_TUNABLE", 2900, 1 },
	{ "TATTOO_MP_FM_HEAD_BANGER_EXPENDITURE_TUNABLE", 2906, 1 },
	{ "TATTOO_MP_FM_SLAYER_EXPENDITURE_TUNABLE", 2907, 1 },
	{ "TATTOO_MP_FM_GANGHIDEOUT_CLEAR_EXPENDITURE_TUNABLE", 2908, 1 },
	{ "TATTOO_MP_FM_ARMOURED_VAN_TAKEDOWN_EXPENDITURE_TUNABLE", 2909, 1 },
	{ "TATTOO_MP_FM_HUSTLER_EXPENDITURE_TUNABLE", 2910, 1 },
	{ "TATTOO_MP_FM_WIN_EVER_MODE_ONCE_EXPENDITURE_TUNABLE", 2911, 1 },
	{ "TATTOO_MP_FM_BOUNTY_KILLER_EXPENDITURE_TUNABLE", 2912, 1 },
	{ "TATTOO_MP_FM_HOLD_WORLD_RECORD_EXPENDITURE_TUNABLE", 2913, 1 },
	{ "TATTOO_MP_FM_FULL_MODDED_EXPENDITURE_TUNABLE", 2914, 1 },
	{ "TATTOO_MP_FM_REVENGE_KILL_EXPENDITURE_TUNABLE", 2915, 1 },
	{ "TATTOO_MP_FM_KILL_3_RACERS_EXPENDITURE_TUNABLE", 2916, 1 },
	{ "TATTOO_MP_FM_REACH_RANK_1_EXPENDITURE_TUNABLE", 2917, 1 },
	{ "TATTOO_MP_FM_REACH_RANK_2_EXPENDITURE_TUNABLE", 2918, 1 },
	{ "TATTOO_MP_FM_REACH_RANK_3_EXPENDITURE_TUNABLE", 2919, 1 },
	{ "TATTOO_MP_FM_FMKILLCHEATER_EXPENDITURE_TUNABLE", 2920, 1 },
	{ "TATTOO_MP_FM_RACES_WON_EXPENDITURE_TUNABLE", 2921, 1 },
	{ "TATTOO_MP_FM_HOLD_UP_SHOPS_1_EXPENDITURE_TUNABLE", 2922, 1 },
	{ "TATTOO_MP_FM_HOLD_UP_SHOPS_2_EXPENDITURE_TUNABLE", 2923, 1 },
	{ "TATTOO_MP_FM_HOLD_UP_SHOPS_3_EXPENDITURE_TUNABLE", 2924, 1 },
	{ "TATTOO_MP_FM_HOLD_UP_SHOPS_4_EXPENDITURE_TUNABLE", 2925, 1 },
	{ "TATTOO_MP_FM_CREW_A_EXPENDITURE_TUNABLE", 2926, 1 },
	{ "TATTOO_MP_FM_CREW_B_EXPENDITURE_TUNABLE", 2927, 1 },
	{ "TATTOO_MP_FM_CREW_C_EXPENDITURE_TUNABLE", 2928, 1 },
	{ "TATTOO_MP_FM_CREW_D_EXPENDITURE_TUNABLE", 2929, 1 },
	{ "TATTOO_MP_FM_11_EXPENDITURE_TUNABLE", 2940, 1 },
	{ "TATTOO_MP_FM_12_EXPENDITURE_TUNABLE", 2941, 1 },
	{ "TATTOO_MP_FM_13_EXPENDITURE_TUNABLE", 2942, 1 },
	{ "TATTOO_MP_FM_14_EXPENDITURE_TUNABLE", 2943, 1 },
	{ "TATTOO_MP_FM_15_EXPENDITURE_TUNABLE", 2944, 1 },
	{ "TATTOO_MP_FM_16_EXPENDITURE_TUNABLE", 2945, 1 },
	{ "TATTOO_MP_FM_17_EXPENDITURE_TUNABLE", 2946, 1 },
	{ "TATTOO_MP_FM_18_EXPENDITURE_TUNABLE", 2947, 1 },
	{ "TATTOO_MP_FM_19_EXPENDITURE_TUNABLE", 2948, 1 },
	{ "TATTOO_MP_FM_20_EXPENDITURE_TUNABLE", 2949, 1 },
	{ "TATTOO_MP_FM_21_EXPENDITURE_TUNABLE", 2950, 1 },
	{ "TATTOO_MP_FM_22_EXPENDITURE_TUNABLE", 2951, 1 },
	{ "TATTOO_MP_FM_23_EXPENDITURE_TUNABLE", 2952, 1 },
	{ "TATTOO_MP_FM_24_EXPENDITURE_TUNABLE", 2953, 1 },
	{ "TATTOO_MP_FM_25_EXPENDITURE_TUNABLE", 2954, 1 },
	{ "TATTOO_MP_FM_26_EXPENDITURE_TUNABLE", 2955, 1 },
	{ "TATTOO_MP_FM_27_EXPENDITURE_TUNABLE", 2956, 1 },
	{ "TATTOO_MP_FM_28_EXPENDITURE_TUNABLE", 2957, 1 },
	{ "TATTOO_MP_FM_29_EXPENDITURE_TUNABLE", 2958, 1 },
	{ "TATTOO_MP_FM_30_EXPENDITURE_TUNABLE", 2959, 1 },
	{ "TATTOO_MP_FM_31_EXPENDITURE_TUNABLE", 2960, 1 },
	{ "TATTOO_MP_FM_32_EXPENDITURE_TUNABLE", 2961, 1 },
	{ "TATTOO_MP_FM_33_EXPENDITURE_TUNABLE", 2962, 1 },
	{ "TATTOO_MP_FM_34_EXPENDITURE_TUNABLE", 2963, 1 },
	{ "TATTOO_MP_FM_35_EXPENDITURE_TUNABLE", 2964, 1 },
	{ "TATTOO_MP_FM_36_EXPENDITURE_TUNABLE", 2965, 1 },
	{ "TATTOO_MP_FM_37_EXPENDITURE_TUNABLE", 2966, 1 },
	{ "TATTOO_MP_FM_38_EXPENDITURE_TUNABLE", 2967, 1 },
	{ "TATTOO_MP_FM_39_EXPENDITURE_TUNABLE", 2968, 1 },
	{ "TATTOO_MP_FM_40_EXPENDITURE_TUNABLE", 2969, 1 },
	{ "TATTOO_MP_FM_41_EXPENDITURE_TUNABLE", 2970, 1 },
	{ "TATTOO_MP_FM_42_EXPENDITURE_TUNABLE", 2971, 1 },
	{ "TATTOO_MP_FM_43_EXPENDITURE_TUNABLE", 2972, 1 },
	{ "TATTOO_MP_FM_44_EXPENDITURE_TUNABLE", 2973, 1 },
	{ "TATTOO_MP_FM_45_EXPENDITURE_TUNABLE", 2974, 1 },
	{ "TATTOO_MP_FM_46_EXPENDITURE_TUNABLE", 2975, 1 },
	{ "TATTOO_MP_FM_47_EXPENDITURE_TUNABLE", 2976, 1 },
	{ "TSHIRT_TRANS_MP_FM_REDSKULL_EXPENDITURE_TUNABLE", 2977, 1 },
	{ "TSHIRT_TRANS_MP_FM_LSBELLE_EXPENDITURE_TUNABLE", 2978, 1 },
	{ "TSHIRT_TRANS_MP_FM_ROCKSTAR_EXPENDITURE_TUNABLE", 2979, 1 },
	{ "CARMOD_UNLOCK_WHEELSHIGHEND_EXPENDITURE_TUNABLE", 2980, 1 },
	{ "CARMOD_UNLOCK_WHEELSSPORT_EXPENDITURE_TUNABLE", 2981, 1 },
	{ "CARMOD_UNLOCK_WHEELSLOWRIDER_EXPENDITURE_TUNABLE", 2982, 1 },
	{ "CARMOD_UNLOCK_WHEELSSUV_EXPENDITURE_TUNABLE", 2983, 1 },
	{ "CARMOD_UNLOCK_WHEELSMUSCLE_EXPENDITURE_TUNABLE", 2984, 1 },
	{ "CARMOD_UNLOCK_WHEELSTUNER_EXPENDITURE_TUNABLE", 2985, 1 },
	{ "CARMOD_UNLOCK_WHEELSOFFROAD_EXPENDITURE_TUNABLE", 2986, 1 },
	{ "CARMOD_UNLOCK_WHEELSBIKE_EXPENDITURE_TUNABLE", 2987, 1 },
	{ "CARMOD_UNLOCK_WHEELCOLOURS_EXPENDITURE_TUNABLE", 2988, 1 },
	{ "CARMOD_UNLOCK_STOCKTIRES_EXPENDITURE_TUNABLE", 2989, 1 },
	{ "CARMOD_UNLOCK_NOARMOUR_EXPENDITURE_TUNABLE", 2990, 1 },
	{ "CARMOD_UNLOCK_STOCKFRONTBUMPER_EXPENDITURE_TUNABLE", 2991, 1 },
	{ "CARMOD_UNLOCK_STOCKREARBUMPER_EXPENDITURE_TUNABLE", 2992, 1 },
	{ "CARMOD_UNLOCK_STOCKCHASSIS_EXPENDITURE_TUNABLE", 2993, 1 },
	{ "CARMOD_UNLOCK_STOCKEXHAUST_EXPENDITURE_TUNABLE", 2994, 1 },
	{ "CARMOD_UNLOCK_STOCKLEFTFENDER_EXPENDITURE_TUNABLE", 2995, 1 },
	{ "CARMOD_UNLOCK_STOCKRIGHTFENDER_EXPENDITURE_TUNABLE", 2996, 1 },
	{ "CARMOD_UNLOCK_STOCKGRILLE_EXPENDITURE_TUNABLE", 2997, 1 },
	{ "CARMOD_UNLOCK_STOCKHOOD_EXPENDITURE_TUNABLE", 2998, 1 },
	{ "CARMOD_UNLOCK_STOCKHORN_EXPENDITURE_TUNABLE", 2999, 1 },
	{ "CARMOD_UNLOCK_STOCKLIGHTS_EXPENDITURE_TUNABLE", 3000, 1 },
	{ "CARMOD_UNLOCK_PLATESBLUEONWHITE1_EXPENDITURE_TUNABLE", 3001, 1 },
	{ "CARMOD_UNLOCK_PLATESBLUEONWHITE2_EXPENDITURE_TUNABLE", 3002, 1 },
	{ "CARMOD_UNLOCK_PLATESBLUEONWHITE3_EXPENDITURE_TUNABLE", 3003, 1 },
	{ "CARMOD_UNLOCK_PLATESYELLOWONBLUE_EXPENDITURE_TUNABLE", 3004, 1 },
	{ "CARMOD_UNLOCK_PLATESYELLOWONBLACK_EXPENDITURE_TUNABLE", 3005, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORCHROME_EXPENDITURE_TUNABLE", 3006, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORCLASSIC_EXPENDITURE_TUNABLE", 3007, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORMATTE_EXPENDITURE_TUNABLE", 3008, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORMETALLIC_EXPENDITURE_TUNABLE", 3009, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORMETALS_EXPENDITURE_TUNABLE", 3010, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORPEARLESCENT_EXPENDITURE_TUNABLE", 3011, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORCREW_EXPENDITURE_TUNABLE", 3012, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORCHROME_EXPENDITURE_TUNABLE", 3013, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORCLASSIC_EXPENDITURE_TUNABLE", 3014, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORMATTE_EXPENDITURE_TUNABLE", 3015, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORMETALLIC_EXPENDITURE_TUNABLE", 3016, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORMETALS_EXPENDITURE_TUNABLE", 3017, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORPEARLESCENT_EXPENDITURE_TUNABLE", 3018, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORCREW_EXPENDITURE_TUNABLE", 3019, 1 },
	{ "CARMOD_UNLOCK_CREWEMBLEM_EXPENDITURE_TUNABLE", 3020, 1 },
	{ "CARMOD_UNLOCK_STOCKROOF_EXPENDITURE_TUNABLE", 3021, 1 },
	{ "CARMOD_UNLOCK_STOCKSKIRT_EXPENDITURE_TUNABLE", 3022, 1 },
	{ "CARMOD_UNLOCK_STOCKSPOILER_EXPENDITURE_TUNABLE", 3023, 1 },
	{ "CARMOD_UNLOCK_STOCKSUSPENSION_EXPENDITURE_TUNABLE", 3024, 1 },
	{ "CARMOD_UNLOCK_TRACKER_EXPENDITURE_TUNABLE", 3025, 1 },
	{ "CARMOD_UNLOCK_STOCKTRANSMISSION_EXPENDITURE_TUNABLE", 3026, 1 },
	{ "CARMOD_UNLOCK_NOTURBO_EXPENDITURE_TUNABLE", 3027, 1 },
	{ "CARMOD_UNLOCK_STOCKWHEELS_EXPENDITURE_TUNABLE", 3028, 1 },
	{ "CARMOD_UNLOCK_CREWSMOKE_EXPENDITURE_TUNABLE", 3029, 1 },
	{ "CARMOD_UNLOCK_WINDOWSNONE_EXPENDITURE_TUNABLE", 3030, 1 },
	{ "CARMOD_UNLOCK_BRAKES_L2_EXPENDITURE_TUNABLE", 3031, 1 },
	{ "CARMOD_UNLOCK_BRAKES_L3_EXPENDITURE_TUNABLE", 3032, 1 },
	{ "CARMOD_UNLOCK_BRAKES_L4_EXPENDITURE_TUNABLE", 3033, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_20_EXPENDITURE_TUNABLE", 3034, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_40_EXPENDITURE_TUNABLE", 3035, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_60_EXPENDITURE_TUNABLE", 3036, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_80_EXPENDITURE_TUNABLE", 3037, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_100_EXPENDITURE_TUNABLE", 3038, 1 },
	{ "CARMOD_UNLOCK_STOCK_BRAKES_EXPENDITURE_TUNABLE", 3039, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L2_EXPENDITURE_TUNABLE", 3040, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L3_EXPENDITURE_TUNABLE", 3041, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L4_EXPENDITURE_TUNABLE", 3042, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L5_EXPENDITURE_TUNABLE", 3043, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L6_EXPENDITURE_TUNABLE", 3044, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L7_EXPENDITURE_TUNABLE", 3045, 1 },
	{ "CARMOD_UNLOCK_CUSTOM_TYRES_EXPENDITURE_TUNABLE", 3046, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L2_EXPENDITURE_TUNABLE", 3047, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L3_EXPENDITURE_TUNABLE", 3048, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L4_EXPENDITURE_TUNABLE", 3049, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L5_EXPENDITURE_TUNABLE", 3050, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L6_EXPENDITURE_TUNABLE", 3051, 1 },
	{ "CARMOD_UNLOCK_GRILL_L2_EXPENDITURE_TUNABLE", 3052, 1 },
	{ "CARMOD_UNLOCK_GRILL_L3_EXPENDITURE_TUNABLE", 3053, 1 },
	{ "CARMOD_UNLOCK_GRILL_L4_EXPENDITURE_TUNABLE", 3054, 1 },
	{ "CARMOD_UNLOCK_GRILL_L5_EXPENDITURE_TUNABLE", 3055, 1 },
	{ "CARMOD_UNLOCK_GRILL_L6_EXPENDITURE_TUNABLE", 3056, 1 },
	{ "CARMOD_UNLOCK_ROOF_L1_EXPENDITURE_TUNABLE", 3057, 1 },
	{ "CARMOD_UNLOCK_ROOF_L2_EXPENDITURE_TUNABLE", 3058, 1 },
	{ "CARMOD_UNLOCK_ROOF_L3_EXPENDITURE_TUNABLE", 3059, 1 },
	{ "CARMOD_UNLOCK_ROOF_L4_EXPENDITURE_TUNABLE", 3060, 1 },
	{ "CARMOD_UNLOCK_ROOF_L5_EXPENDITURE_TUNABLE", 3061, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L1_EXPENDITURE_TUNABLE", 3062, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L2_EXPENDITURE_TUNABLE", 3063, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L3_EXPENDITURE_TUNABLE", 3064, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L4_EXPENDITURE_TUNABLE", 3065, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L5_EXPENDITURE_TUNABLE", 3066, 1 },
	{ "CARMOD_UNLOCK_WHEELS_L4_EXPENDITURE_TUNABLE", 3067, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L2_EXPENDITURE_TUNABLE", 3068, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L3_EXPENDITURE_TUNABLE", 3069, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L4_EXPENDITURE_TUNABLE", 3070, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L5_EXPENDITURE_TUNABLE", 3071, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L2_EXPENDITURE_TUNABLE", 3072, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L3_EXPENDITURE_TUNABLE", 3073, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L4_EXPENDITURE_TUNABLE", 3074, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L5_EXPENDITURE_TUNABLE", 3075, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L2_EXPENDITURE_TUNABLE", 3076, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L3_EXPENDITURE_TUNABLE", 3077, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L4_EXPENDITURE_TUNABLE", 3078, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L5_EXPENDITURE_TUNABLE", 3079, 1 },
	{ "CARMOD_UNLOCK_TIMED_BOMB_EXPENDITURE_TUNABLE", 3080, 1 },
	{ "CARMOD_UNLOCK_IGNITION_BOMB_EXPENDITURE_TUNABLE", 3081, 1 },
	{ "CARMOD_UNLOCK_L_WING_L2_EXPENDITURE_TUNABLE", 3082, 1 },
	{ "CARMOD_UNLOCK_L_WING_L3_EXPENDITURE_TUNABLE", 3083, 1 },
	{ "CARMOD_UNLOCK_L_WING_L4_EXPENDITURE_TUNABLE", 3084, 1 },
	{ "CARMOD_UNLOCK_L_WING_L5_EXPENDITURE_TUNABLE", 3085, 1 },
	{ "CARMOD_UNLOCK_R_WING_L2_EXPENDITURE_TUNABLE", 3086, 1 },
	{ "CARMOD_UNLOCK_BONNET_L2_EXPENDITURE_TUNABLE", 3087, 1 },
	{ "CARMOD_UNLOCK_BONNET_L3_EXPENDITURE_TUNABLE", 3088, 1 },
	{ "CARMOD_UNLOCK_BONNET_L4_EXPENDITURE_TUNABLE", 3089, 1 },
	{ "CARMOD_UNLOCK_BONNET_L5_EXPENDITURE_TUNABLE", 3090, 1 },
	{ "CARMOD_UNLOCK_BONNET_L6_EXPENDITURE_TUNABLE", 3091, 1 },
	{ "CARMOD_UNLOCK_BONNET_L7_EXPENDITURE_TUNABLE", 3092, 1 },
	{ "CARMOD_UNLOCK_HORN_L2_EXPENDITURE_TUNABLE", 3093, 1 },
	{ "CARMOD_UNLOCK_HORN_L3_EXPENDITURE_TUNABLE", 3094, 1 },
	{ "CARMOD_UNLOCK_HORN_L4_EXPENDITURE_TUNABLE", 3095, 1 },
	{ "CARMOD_UNLOCK_HORN_L5_EXPENDITURE_TUNABLE", 3096, 1 },
	{ "CARMOD_UNLOCK_HORN_L6_EXPENDITURE_TUNABLE", 3097, 1 },
	{ "CARMOD_UNLOCK_HORN_L7_EXPENDITURE_TUNABLE", 3098, 1 },
	{ "CARMOD_UNLOCK_HORN_L8_EXPENDITURE_TUNABLE", 3099, 1 },
	{ "CARMOD_UNLOCK_HORN_L9_EXPENDITURE_TUNABLE", 3100, 1 },
	{ "CARMOD_UNLOCK_XENON_LIGHTS_EXPENDITURE_TUNABLE", 3101, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L2_EXPENDITURE_TUNABLE", 3102, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L3_EXPENDITURE_TUNABLE", 3103, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L4_EXPENDITURE_TUNABLE", 3104, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L5_EXPENDITURE_TUNABLE", 3105, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L1_EXPENDITURE_TUNABLE", 3106, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L2_EXPENDITURE_TUNABLE", 3107, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L3_EXPENDITURE_TUNABLE", 3108, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L4_EXPENDITURE_TUNABLE", 3109, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L5_EXPENDITURE_TUNABLE", 3110, 1 },
	{ "CARMOD_UNLOCK_GEAR_BOX_L2_EXPENDITURE_TUNABLE", 3111, 1 },
	{ "CARMOD_UNLOCK_GEAR_BOX_L3_EXPENDITURE_TUNABLE", 3112, 1 },
	{ "CARMOD_UNLOCK_GEAR_BOX_L4_EXPENDITURE_TUNABLE", 3113, 1 },
	{ "CARMOD_UNLOCK_TURBO_EXPENDITURE_TUNABLE", 3114, 1 },
	{ "CARMOD_UNLOCK_BULLET_PROOF_TYRES_EXPENDITURE_TUNABLE", 3115, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_WHITE_EXPENDITURE_TUNABLE", 3116, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_ORANGE_EXPENDITURE_TUNABLE", 3117, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_RED_EXPENDITURE_TUNABLE", 3118, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_YELLOW_EXPENDITURE_TUNABLE", 3119, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_BLUE_EXPENDITURE_TUNABLE", 3120, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_BLACK_EXPENDITURE_TUNABLE", 3121, 1 },
	{ "CARMOD_UNLOCK_LIGHT_SMOKE_WINDOWS_EXPENDITURE_TUNABLE", 3122, 1 },
	{ "CARMOD_UNLOCK_DARK_SMOKE_WINDOWS_EXPENDITURE_TUNABLE", 3123, 1 },
	{ "CARMOD_UNLOCK_LIMO_WINDOWS_EXPENDITURE_TUNABLE", 3124, 1 },
	{ "CARMOD_UNLOCK_WHEELCOLOURS_EXPENDITURE_TUNABLE_SUV", 3125, 1 },
	{ "CARMOD_UNLOCK_STOCKTIRES_EXPENDITURE_TUNABLE_SUV", 3126, 1 },
	{ "CARMOD_UNLOCK_NOARMOUR_EXPENDITURE_TUNABLE_SUV", 3127, 1 },
	{ "CARMOD_UNLOCK_STOCKFRONTBUMPER_EXPENDITURE_TUNABLE_SUV", 3128, 1 },
	{ "CARMOD_UNLOCK_STOCKREARBUMPER_EXPENDITURE_TUNABLE_SUV", 3129, 1 },
	{ "CARMOD_UNLOCK_STOCKCHASSIS_EXPENDITURE_TUNABLE_SUV", 3130, 1 },
	{ "CARMOD_UNLOCK_STOCKEXHAUST_EXPENDITURE_TUNABLE_SUV", 3131, 1 },
	{ "CARMOD_UNLOCK_STOCKLEFTFENDER_EXPENDITURE_TUNABLE_SUV", 3132, 1 },
	{ "CARMOD_UNLOCK_STOCKRIGHTFENDER_EXPENDITURE_TUNABLE_SUV", 3133, 1 },
	{ "CARMOD_UNLOCK_STOCKGRILLE_EXPENDITURE_TUNABLE_SUV", 3134, 1 },
	{ "CARMOD_UNLOCK_STOCKHOOD_EXPENDITURE_TUNABLE_SUV", 3135, 1 },
	{ "CARMOD_UNLOCK_STOCKHORN_EXPENDITURE_TUNABLE_SUV", 3136, 1 },
	{ "CARMOD_UNLOCK_STOCKLIGHTS_EXPENDITURE_TUNABLE_SUV", 3137, 1 },
	{ "CARMOD_UNLOCK_PLATESBLUEONWHITE1_EXPENDITURE_TUNABLE_SUV", 3138, 1 },
	{ "CARMOD_UNLOCK_PLATESBLUEONWHITE2_EXPENDITURE_TUNABLE_SUV", 3139, 1 },
	{ "CARMOD_UNLOCK_PLATESBLUEONWHITE3_EXPENDITURE_TUNABLE_SUV", 3140, 1 },
	{ "CARMOD_UNLOCK_PLATESYELLOWONBLUE_EXPENDITURE_TUNABLE_SUV", 3141, 1 },
	{ "CARMOD_UNLOCK_PLATESYELLOWONBLACK_EXPENDITURE_TUNABLE_SUV", 3142, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORCHROME_EXPENDITURE_TUNABLE_SUV", 3143, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORCLASSIC_EXPENDITURE_TUNABLE_SUV", 3144, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORMATTE_EXPENDITURE_TUNABLE_SUV", 3145, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORMETALLIC_EXPENDITURE_TUNABLE_SUV", 3146, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORMETALS_EXPENDITURE_TUNABLE_SUV", 3147, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORPEARLESCENT_EXPENDITURE_TUNABLE_SUV", 3148, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORCREW_EXPENDITURE_TUNABLE_SUV", 3149, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORCHROME_EXPENDITURE_TUNABLE_SUV", 3150, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORCLASSIC_EXPENDITURE_TUNABLE_SUV", 3151, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORMATTE_EXPENDITURE_TUNABLE_SUV", 3152, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORMETALLIC_EXPENDITURE_TUNABLE_SUV", 3153, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORMETALS_EXPENDITURE_TUNABLE_SUV", 3154, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORPEARLESCENT_EXPENDITURE_TUNABLE_SUV", 3155, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORCREW_EXPENDITURE_TUNABLE_SUV", 3156, 1 },
	{ "CARMOD_UNLOCK_CREWEMBLEM_EXPENDITURE_TUNABLE_SUV", 3157, 1 },
	{ "CARMOD_UNLOCK_STOCKROOF_EXPENDITURE_TUNABLE_SUV", 3158, 1 },
	{ "CARMOD_UNLOCK_STOCKSKIRT_EXPENDITURE_TUNABLE_SUV", 3159, 1 },
	{ "CARMOD_UNLOCK_STOCKSPOILER_EXPENDITURE_TUNABLE_SUV", 3160, 1 },
	{ "CARMOD_UNLOCK_STOCKSUSPENSION_EXPENDITURE_TUNABLE_SUV", 3161, 1 },
	{ "CARMOD_UNLOCK_TRACKER_EXPENDITURE_TUNABLE_SUV", 3162, 1 },
	{ "CARMOD_UNLOCK_STOCKTRANSMISSION_EXPENDITURE_TUNABLE_SUV", 3163, 1 },
	{ "CARMOD_UNLOCK_NOTURBO_EXPENDITURE_TUNABLE_SUV", 3164, 1 },
	{ "CARMOD_UNLOCK_STOCKWHEELS_EXPENDITURE_TUNABLE_SUV", 3165, 1 },
	{ "CARMOD_UNLOCK_CREWSMOKE_EXPENDITURE_TUNABLE_SUV", 3166, 1 },
	{ "CARMOD_UNLOCK_WINDOWSNONE_EXPENDITURE_TUNABLE_SUV", 3167, 1 },
	{ "CARMOD_UNLOCK_BRAKES_L2_EXPENDITURE_TUNABLE_SUV", 3168, 1 },
	{ "CARMOD_UNLOCK_BRAKES_L3_EXPENDITURE_TUNABLE_SUV", 3169, 1 },
	{ "CARMOD_UNLOCK_BRAKES_L4_EXPENDITURE_TUNABLE_SUV", 3170, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_20_EXPENDITURE_TUNABLE_SUV", 3171, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_40_EXPENDITURE_TUNABLE_SUV", 3172, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_60_EXPENDITURE_TUNABLE_SUV", 3173, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_80_EXPENDITURE_TUNABLE_SUV", 3174, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_100_EXPENDITURE_TUNABLE_SUV", 3175, 1 },
	{ "CARMOD_UNLOCK_STOCK_BRAKES_EXPENDITURE_TUNABLE_SUV", 3176, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L2_EXPENDITURE_TUNABLE_SUV", 3177, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L3_EXPENDITURE_TUNABLE_SUV", 3178, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L4_EXPENDITURE_TUNABLE_SUV", 3179, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L5_EXPENDITURE_TUNABLE_SUV", 3180, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L6_EXPENDITURE_TUNABLE_SUV", 3181, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L7_EXPENDITURE_TUNABLE_SUV", 3182, 1 },
	{ "CARMOD_UNLOCK_CUSTOM_TYRES_EXPENDITURE_TUNABLE_SUV", 3183, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L2_EXPENDITURE_TUNABLE_SUV", 3184, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L3_EXPENDITURE_TUNABLE_SUV", 3185, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L4_EXPENDITURE_TUNABLE_SUV", 3186, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L5_EXPENDITURE_TUNABLE_SUV", 3187, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L6_EXPENDITURE_TUNABLE_SUV", 3188, 1 },
	{ "CARMOD_UNLOCK_GRILL_L2_EXPENDITURE_TUNABLE_SUV", 3189, 1 },
	{ "CARMOD_UNLOCK_GRILL_L3_EXPENDITURE_TUNABLE_SUV", 3190, 1 },
	{ "CARMOD_UNLOCK_GRILL_L4_EXPENDITURE_TUNABLE_SUV", 3191, 1 },
	{ "CARMOD_UNLOCK_GRILL_L5_EXPENDITURE_TUNABLE_SUV", 3192, 1 },
	{ "CARMOD_UNLOCK_GRILL_L6_EXPENDITURE_TUNABLE_SUV", 3193, 1 },
	{ "CARMOD_UNLOCK_ROOF_L1_EXPENDITURE_TUNABLE_SUV", 3194, 1 },
	{ "CARMOD_UNLOCK_ROOF_L2_EXPENDITURE_TUNABLE_SUV", 3195, 1 },
	{ "CARMOD_UNLOCK_ROOF_L3_EXPENDITURE_TUNABLE_SUV", 3196, 1 },
	{ "CARMOD_UNLOCK_ROOF_L4_EXPENDITURE_TUNABLE_SUV", 3197, 1 },
	{ "CARMOD_UNLOCK_ROOF_L5_EXPENDITURE_TUNABLE_SUV", 3198, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L1_EXPENDITURE_TUNABLE_SUV", 3199, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L2_EXPENDITURE_TUNABLE_SUV", 3200, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L3_EXPENDITURE_TUNABLE_SUV", 3201, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L4_EXPENDITURE_TUNABLE_SUV", 3202, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L5_EXPENDITURE_TUNABLE_SUV", 3203, 1 },
	{ "CARMOD_UNLOCK_WHEELS_L4_EXPENDITURE_TUNABLE_SUV", 3204, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L2_EXPENDITURE_TUNABLE_SUV", 3205, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L3_EXPENDITURE_TUNABLE_SUV", 3206, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L4_EXPENDITURE_TUNABLE_SUV", 3207, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L5_EXPENDITURE_TUNABLE_SUV", 3208, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L2_EXPENDITURE_TUNABLE_SUV", 3209, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L3_EXPENDITURE_TUNABLE_SUV", 3210, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L4_EXPENDITURE_TUNABLE_SUV", 3211, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L5_EXPENDITURE_TUNABLE_SUV", 3212, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L2_EXPENDITURE_TUNABLE_SUV", 3213, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L3_EXPENDITURE_TUNABLE_SUV", 3214, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L4_EXPENDITURE_TUNABLE_SUV", 3215, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L5_EXPENDITURE_TUNABLE_SUV", 3216, 1 },
	{ "CARMOD_UNLOCK_TIMED_BOMB_EXPENDITURE_TUNABLE_SUV", 3217, 1 },
	{ "CARMOD_UNLOCK_IGNITION_BOMB_EXPENDITURE_TUNABLE_SUV", 3218, 1 },
	{ "CARMOD_UNLOCK_L_WING_L2_EXPENDITURE_TUNABLE_SUV", 3219, 1 },
	{ "CARMOD_UNLOCK_L_WING_L3_EXPENDITURE_TUNABLE_SUV", 3220, 1 },
	{ "CARMOD_UNLOCK_L_WING_L4_EXPENDITURE_TUNABLE_SUV", 3221, 1 },
	{ "CARMOD_UNLOCK_L_WING_L5_EXPENDITURE_TUNABLE_SUV", 3222, 1 },
	{ "CARMOD_UNLOCK_R_WING_L2_EXPENDITURE_TUNABLE_SUV", 3223, 1 },
	{ "CARMOD_UNLOCK_BONNET_L2_EXPENDITURE_TUNABLE_SUV", 3224, 1 },
	{ "CARMOD_UNLOCK_BONNET_L3_EXPENDITURE_TUNABLE_SUV", 3225, 1 },
	{ "CARMOD_UNLOCK_BONNET_L4_EXPENDITURE_TUNABLE_SUV", 3226, 1 },
	{ "CARMOD_UNLOCK_BONNET_L5_EXPENDITURE_TUNABLE_SUV", 3227, 1 },
	{ "CARMOD_UNLOCK_BONNET_L6_EXPENDITURE_TUNABLE_SUV", 3228, 1 },
	{ "CARMOD_UNLOCK_BONNET_L7_EXPENDITURE_TUNABLE_SUV", 3229, 1 },
	{ "CARMOD_UNLOCK_HORN_L2_EXPENDITURE_TUNABLE_SUV", 3230, 1 },
	{ "CARMOD_UNLOCK_HORN_L3_EXPENDITURE_TUNABLE_SUV", 3231, 1 },
	{ "CARMOD_UNLOCK_HORN_L4_EXPENDITURE_TUNABLE_SUV", 3232, 1 },
	{ "CARMOD_UNLOCK_HORN_L5_EXPENDITURE_TUNABLE_SUV", 3233, 1 },
	{ "CARMOD_UNLOCK_HORN_L6_EXPENDITURE_TUNABLE_SUV", 3234, 1 },
	{ "CARMOD_UNLOCK_HORN_L7_EXPENDITURE_TUNABLE_SUV", 3235, 1 },
	{ "CARMOD_UNLOCK_HORN_L8_EXPENDITURE_TUNABLE_SUV", 3236, 1 },
	{ "CARMOD_UNLOCK_HORN_L9_EXPENDITURE_TUNABLE_SUV", 3237, 1 },
	{ "CARMOD_UNLOCK_XENON_LIGHTS_EXPENDITURE_TUNABLE_SUV", 3238, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L2_EXPENDITURE_TUNABLE_SUV", 3239, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L3_EXPENDITURE_TUNABLE_SUV", 3240, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L4_EXPENDITURE_TUNABLE_SUV", 3241, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L5_EXPENDITURE_TUNABLE_SUV", 3242, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L1_EXPENDITURE_TUNABLE_SUV", 3243, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L2_EXPENDITURE_TUNABLE_SUV", 3244, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L3_EXPENDITURE_TUNABLE_SUV", 3245, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L4_EXPENDITURE_TUNABLE_SUV", 3246, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L5_EXPENDITURE_TUNABLE_SUV", 3247, 1 },
	{ "CARMOD_UNLOCK_GEAR_BOX_L2_EXPENDITURE_TUNABLE_SUV", 3248, 1 },
	{ "CARMOD_UNLOCK_GEAR_BOX_L3_EXPENDITURE_TUNABLE_SUV", 3249, 1 },
	{ "CARMOD_UNLOCK_GEAR_BOX_L4_EXPENDITURE_TUNABLE_SUV", 3250, 1 },
	{ "CARMOD_UNLOCK_TURBO_EXPENDITURE_TUNABLE_SUV", 3251, 1 },
	{ "CARMOD_UNLOCK_BULLET_PROOF_TYRES_EXPENDITURE_TUNABLE_SUV", 3252, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_WHITE_EXPENDITURE_TUNABLE_SUV", 3253, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_ORANGE_EXPENDITURE_TUNABLE_SUV", 3254, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_RED_EXPENDITURE_TUNABLE_SUV", 3255, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_YELLOW_EXPENDITURE_TUNABLE_SUV", 3256, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_BLUE_EXPENDITURE_TUNABLE_SUV", 3257, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_BLACK_EXPENDITURE_TUNABLE_SUV", 3258, 1 },
	{ "CARMOD_UNLOCK_LIGHT_SMOKE_WINDOWS_EXPENDITURE_TUNABLE_SUV", 3259, 1 },
	{ "CARMOD_UNLOCK_DARK_SMOKE_WINDOWS_EXPENDITURE_TUNABLE_SUV", 3260, 1 },
	{ "CARMOD_UNLOCK_LIMO_WINDOWS_EXPENDITURE_TUNABLE_SUV", 3261, 1 },
	{ "CARMOD_UNLOCK_WHEELCOLOURS_EXPENDITURE_TUNABLE_SPORT", 3262, 1 },
	{ "CARMOD_UNLOCK_STOCKTIRES_EXPENDITURE_TUNABLE_SPORT", 3263, 1 },
	{ "CARMOD_UNLOCK_NOARMOUR_EXPENDITURE_TUNABLE_SPORT", 3264, 1 },
	{ "CARMOD_UNLOCK_STOCKFRONTBUMPER_EXPENDITURE_TUNABLE_SPORT", 3265, 1 },
	{ "CARMOD_UNLOCK_STOCKREARBUMPER_EXPENDITURE_TUNABLE_SPORT", 3266, 1 },
	{ "CARMOD_UNLOCK_STOCKCHASSIS_EXPENDITURE_TUNABLE_SPORT", 3267, 1 },
	{ "CARMOD_UNLOCK_STOCKEXHAUST_EXPENDITURE_TUNABLE_SPORT", 3268, 1 },
	{ "CARMOD_UNLOCK_STOCKLEFTFENDER_EXPENDITURE_TUNABLE_SPORT", 3269, 1 },
	{ "CARMOD_UNLOCK_STOCKRIGHTFENDER_EXPENDITURE_TUNABLE_SPORT", 3270, 1 },
	{ "CARMOD_UNLOCK_STOCKGRILLE_EXPENDITURE_TUNABLE_SPORT", 3271, 1 },
	{ "CARMOD_UNLOCK_STOCKHOOD_EXPENDITURE_TUNABLE_SPORT", 3272, 1 },
	{ "CARMOD_UNLOCK_STOCKHORN_EXPENDITURE_TUNABLE_SPORT", 3273, 1 },
	{ "CARMOD_UNLOCK_STOCKLIGHTS_EXPENDITURE_TUNABLE_SPORT", 3274, 1 },
	{ "CARMOD_UNLOCK_PLATESBLUEONWHITE1_EXPENDITURE_TUNABLE_SPORT", 3275, 1 },
	{ "CARMOD_UNLOCK_PLATESBLUEONWHITE2_EXPENDITURE_TUNABLE_SPORT", 3276, 1 },
	{ "CARMOD_UNLOCK_PLATESBLUEONWHITE3_EXPENDITURE_TUNABLE_SPORT", 3277, 1 },
	{ "CARMOD_UNLOCK_PLATESYELLOWONBLUE_EXPENDITURE_TUNABLE_SPORT", 3278, 1 },
	{ "CARMOD_UNLOCK_PLATESYELLOWONBLACK_EXPENDITURE_TUNABLE_SPORT", 3279, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORCHROME_EXPENDITURE_TUNABLE_SPORT", 3280, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORCLASSIC_EXPENDITURE_TUNABLE_SPORT", 3281, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORMATTE_EXPENDITURE_TUNABLE_SPORT", 3282, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORMETALLIC_EXPENDITURE_TUNABLE_SPORT", 3283, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORMETALS_EXPENDITURE_TUNABLE_SPORT", 3284, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORPEARLESCENT_EXPENDITURE_TUNABLE_SPORT", 3285, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORCREW_EXPENDITURE_TUNABLE_SPORT", 3286, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORCHROME_EXPENDITURE_TUNABLE_SPORT", 3287, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORCLASSIC_EXPENDITURE_TUNABLE_SPORT", 3288, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORMATTE_EXPENDITURE_TUNABLE_SPORT", 3289, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORMETALLIC_EXPENDITURE_TUNABLE_SPORT", 3290, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORMETALS_EXPENDITURE_TUNABLE_SPORT", 3291, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORPEARLESCENT_EXPENDITURE_TUNABLE_SPORT", 3292, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORCREW_EXPENDITURE_TUNABLE_SPORT", 3293, 1 },
	{ "CARMOD_UNLOCK_CREWEMBLEM_EXPENDITURE_TUNABLE_SPORT", 3294, 1 },
	{ "CARMOD_UNLOCK_STOCKROOF_EXPENDITURE_TUNABLE_SPORT", 3295, 1 },
	{ "CARMOD_UNLOCK_STOCKSKIRT_EXPENDITURE_TUNABLE_SPORT", 3296, 1 },
	{ "CARMOD_UNLOCK_STOCKSPOILER_EXPENDITURE_TUNABLE_SPORT", 3297, 1 },
	{ "CARMOD_UNLOCK_STOCKSUSPENSION_EXPENDITURE_TUNABLE_SPORT", 3298, 1 },
	{ "CARMOD_UNLOCK_TRACKER_EXPENDITURE_TUNABLE_SPORT", 3299, 1 },
	{ "CARMOD_UNLOCK_STOCKTRANSMISSION_EXPENDITURE_TUNABLE_SPORT", 3300, 1 },
	{ "CARMOD_UNLOCK_NOTURBO_EXPENDITURE_TUNABLE_SPORT", 3301, 1 },
	{ "CARMOD_UNLOCK_STOCKWHEELS_EXPENDITURE_TUNABLE_SPORT", 3302, 1 },
	{ "CARMOD_UNLOCK_CREWSMOKE_EXPENDITURE_TUNABLE_SPORT", 3303, 1 },
	{ "CARMOD_UNLOCK_WINDOWSNONE_EXPENDITURE_TUNABLE_SPORT", 3304, 1 },
	{ "CARMOD_UNLOCK_BRAKES_L2_EXPENDITURE_TUNABLE_SPORT", 3305, 1 },
	{ "CARMOD_UNLOCK_BRAKES_L3_EXPENDITURE_TUNABLE_SPORT", 3306, 1 },
	{ "CARMOD_UNLOCK_BRAKES_L4_EXPENDITURE_TUNABLE_SPORT", 3307, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_20_EXPENDITURE_TUNABLE_SPORT", 3308, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_40_EXPENDITURE_TUNABLE_SPORT", 3309, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_60_EXPENDITURE_TUNABLE_SPORT", 3310, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_80_EXPENDITURE_TUNABLE_SPORT", 3311, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_100_EXPENDITURE_TUNABLE_SPORT", 3312, 1 },
	{ "CARMOD_UNLOCK_STOCK_BRAKES_EXPENDITURE_TUNABLE_SPORT", 3313, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L2_EXPENDITURE_TUNABLE_SPORT", 3314, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L3_EXPENDITURE_TUNABLE_SPORT", 3315, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L4_EXPENDITURE_TUNABLE_SPORT", 3316, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L5_EXPENDITURE_TUNABLE_SPORT", 3317, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L6_EXPENDITURE_TUNABLE_SPORT", 3318, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L7_EXPENDITURE_TUNABLE_SPORT", 3319, 1 },
	{ "CARMOD_UNLOCK_CUSTOM_TYRES_EXPENDITURE_TUNABLE_SPORT", 3320, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L2_EXPENDITURE_TUNABLE_SPORT", 3321, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L3_EXPENDITURE_TUNABLE_SPORT", 3322, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L4_EXPENDITURE_TUNABLE_SPORT", 3323, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L5_EXPENDITURE_TUNABLE_SPORT", 3324, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L6_EXPENDITURE_TUNABLE_SPORT", 3325, 1 },
	{ "CARMOD_UNLOCK_GRILL_L2_EXPENDITURE_TUNABLE_SPORT", 3326, 1 },
	{ "CARMOD_UNLOCK_GRILL_L3_EXPENDITURE_TUNABLE_SPORT", 3327, 1 },
	{ "CARMOD_UNLOCK_GRILL_L4_EXPENDITURE_TUNABLE_SPORT", 3328, 1 },
	{ "CARMOD_UNLOCK_GRILL_L5_EXPENDITURE_TUNABLE_SPORT", 3329, 1 },
	{ "CARMOD_UNLOCK_GRILL_L6_EXPENDITURE_TUNABLE_SPORT", 3330, 1 },
	{ "CARMOD_UNLOCK_ROOF_L1_EXPENDITURE_TUNABLE_SPORT", 3331, 1 },
	{ "CARMOD_UNLOCK_ROOF_L2_EXPENDITURE_TUNABLE_SPORT", 3332, 1 },
	{ "CARMOD_UNLOCK_ROOF_L3_EXPENDITURE_TUNABLE_SPORT", 3333, 1 },
	{ "CARMOD_UNLOCK_ROOF_L4_EXPENDITURE_TUNABLE_SPORT", 3334, 1 },
	{ "CARMOD_UNLOCK_ROOF_L5_EXPENDITURE_TUNABLE_SPORT", 3335, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L1_EXPENDITURE_TUNABLE_SPORT", 3336, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L2_EXPENDITURE_TUNABLE_SPORT", 3337, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L3_EXPENDITURE_TUNABLE_SPORT", 3338, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L4_EXPENDITURE_TUNABLE_SPORT", 3339, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L5_EXPENDITURE_TUNABLE_SPORT", 3340, 1 },
	{ "CARMOD_UNLOCK_WHEELS_L4_EXPENDITURE_TUNABLE_SPORT", 3341, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L2_EXPENDITURE_TUNABLE_SPORT", 3342, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L3_EXPENDITURE_TUNABLE_SPORT", 3343, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L4_EXPENDITURE_TUNABLE_SPORT", 3344, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L5_EXPENDITURE_TUNABLE_SPORT", 3345, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L2_EXPENDITURE_TUNABLE_SPORT", 3346, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L3_EXPENDITURE_TUNABLE_SPORT", 3347, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L4_EXPENDITURE_TUNABLE_SPORT", 3348, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L5_EXPENDITURE_TUNABLE_SPORT", 3349, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L2_EXPENDITURE_TUNABLE_SPORT", 3350, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L3_EXPENDITURE_TUNABLE_SPORT", 3351, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L4_EXPENDITURE_TUNABLE_SPORT", 3352, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L5_EXPENDITURE_TUNABLE_SPORT", 3353, 1 },
	{ "CARMOD_UNLOCK_TIMED_BOMB_EXPENDITURE_TUNABLE_SPORT", 3354, 1 },
	{ "CARMOD_UNLOCK_IGNITION_BOMB_EXPENDITURE_TUNABLE_SPORT", 3355, 1 },
	{ "CARMOD_UNLOCK_L_WING_L2_EXPENDITURE_TUNABLE_SPORT", 3356, 1 },
	{ "CARMOD_UNLOCK_L_WING_L3_EXPENDITURE_TUNABLE_SPORT", 3357, 1 },
	{ "CARMOD_UNLOCK_L_WING_L4_EXPENDITURE_TUNABLE_SPORT", 3358, 1 },
	{ "CARMOD_UNLOCK_L_WING_L5_EXPENDITURE_TUNABLE_SPORT", 3359, 1 },
	{ "CARMOD_UNLOCK_R_WING_L2_EXPENDITURE_TUNABLE_SPORT", 3360, 1 },
	{ "CARMOD_UNLOCK_BONNET_L2_EXPENDITURE_TUNABLE_SPORT", 3361, 1 },
	{ "CARMOD_UNLOCK_BONNET_L3_EXPENDITURE_TUNABLE_SPORT", 3362, 1 },
	{ "CARMOD_UNLOCK_BONNET_L4_EXPENDITURE_TUNABLE_SPORT", 3363, 1 },
	{ "CARMOD_UNLOCK_BONNET_L5_EXPENDITURE_TUNABLE_SPORT", 3364, 1 },
	{ "CARMOD_UNLOCK_BONNET_L6_EXPENDITURE_TUNABLE_SPORT", 3365, 1 },
	{ "CARMOD_UNLOCK_BONNET_L7_EXPENDITURE_TUNABLE_SPORT", 3366, 1 },
	{ "CARMOD_UNLOCK_HORN_L2_EXPENDITURE_TUNABLE_SPORT", 3367, 1 },
	{ "CARMOD_UNLOCK_HORN_L3_EXPENDITURE_TUNABLE_SPORT", 3368, 1 },
	{ "CARMOD_UNLOCK_HORN_L4_EXPENDITURE_TUNABLE_SPORT", 3369, 1 },
	{ "CARMOD_UNLOCK_HORN_L5_EXPENDITURE_TUNABLE_SPORT", 3370, 1 },
	{ "CARMOD_UNLOCK_HORN_L6_EXPENDITURE_TUNABLE_SPORT", 3371, 1 },
	{ "CARMOD_UNLOCK_HORN_L7_EXPENDITURE_TUNABLE_SPORT", 3372, 1 },
	{ "CARMOD_UNLOCK_HORN_L8_EXPENDITURE_TUNABLE_SPORT", 3373, 1 },
	{ "CARMOD_UNLOCK_HORN_L9_EXPENDITURE_TUNABLE_SPORT", 3374, 1 },
	{ "CARMOD_UNLOCK_XENON_LIGHTS_EXPENDITURE_TUNABLE_SPORT", 3375, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L2_EXPENDITURE_TUNABLE_SPORT", 3376, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L3_EXPENDITURE_TUNABLE_SPORT", 3377, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L4_EXPENDITURE_TUNABLE_SPORT", 3378, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L5_EXPENDITURE_TUNABLE_SPORT", 3379, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L1_EXPENDITURE_TUNABLE_SPORT", 3380, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L2_EXPENDITURE_TUNABLE_SPORT", 3381, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L3_EXPENDITURE_TUNABLE_SPORT", 3382, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L4_EXPENDITURE_TUNABLE_SPORT", 3383, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L5_EXPENDITURE_TUNABLE_SPORT", 3384, 1 },
	{ "CARMOD_UNLOCK_GEAR_BOX_L2_EXPENDITURE_TUNABLE_SPORT", 3385, 1 },
	{ "CARMOD_UNLOCK_GEAR_BOX_L3_EXPENDITURE_TUNABLE_SPORT", 3386, 1 },
	{ "CARMOD_UNLOCK_GEAR_BOX_L4_EXPENDITURE_TUNABLE_SPORT", 3387, 1 },
	{ "CARMOD_UNLOCK_TURBO_EXPENDITURE_TUNABLE_SPORT", 3388, 1 },
	{ "CARMOD_UNLOCK_BULLET_PROOF_TYRES_EXPENDITURE_TUNABLE_SPORT", 3389, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_WHITE_EXPENDITURE_TUNABLE_SPORT", 3390, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_ORANGE_EXPENDITURE_TUNABLE_SPORT", 3391, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_RED_EXPENDITURE_TUNABLE_SPORT", 3392, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_YELLOW_EXPENDITURE_TUNABLE_SPORT", 3393, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_BLUE_EXPENDITURE_TUNABLE_SPORT", 3394, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_BLACK_EXPENDITURE_TUNABLE_SPORT", 3395, 1 },
	{ "CARMOD_UNLOCK_LIGHT_SMOKE_WINDOWS_EXPENDITURE_TUNABLE_SPORT", 3396, 1 },
	{ "CARMOD_UNLOCK_DARK_SMOKE_WINDOWS_EXPENDITURE_TUNABLE_SPORT", 3397, 1 },
	{ "CARMOD_UNLOCK_LIMO_WINDOWS_EXPENDITURE_TUNABLE_SPORT", 3398, 1 },
	{ "CARMOD_UNLOCK_WHEELCOLOURS_EXPENDITURE_TUNABLE_SPECIAL", 3399, 1 },
	{ "CARMOD_UNLOCK_STOCKTIRES_EXPENDITURE_TUNABLE_SPECIAL", 3400, 1 },
	{ "CARMOD_UNLOCK_NOARMOUR_EXPENDITURE_TUNABLE_SPECIAL", 3401, 1 },
	{ "CARMOD_UNLOCK_STOCKFRONTBUMPER_EXPENDITURE_TUNABLE_SPECIAL", 3402, 1 },
	{ "CARMOD_UNLOCK_STOCKREARBUMPER_EXPENDITURE_TUNABLE_SPECIAL", 3403, 1 },
	{ "CARMOD_UNLOCK_STOCKCHASSIS_EXPENDITURE_TUNABLE_SPECIAL", 3404, 1 },
	{ "CARMOD_UNLOCK_STOCKEXHAUST_EXPENDITURE_TUNABLE_SPECIAL", 3405, 1 },
	{ "CARMOD_UNLOCK_STOCKLEFTFENDER_EXPENDITURE_TUNABLE_SPECIAL", 3406, 1 },
	{ "CARMOD_UNLOCK_STOCKRIGHTFENDER_EXPENDITURE_TUNABLE_SPECIAL", 3407, 1 },
	{ "CARMOD_UNLOCK_STOCKGRILLE_EXPENDITURE_TUNABLE_SPECIAL", 3408, 1 },
	{ "CARMOD_UNLOCK_STOCKHOOD_EXPENDITURE_TUNABLE_SPECIAL", 3409, 1 },
	{ "CARMOD_UNLOCK_STOCKHORN_EXPENDITURE_TUNABLE_SPECIAL", 3410, 1 },
	{ "CARMOD_UNLOCK_STOCKLIGHTS_EXPENDITURE_TUNABLE_SPECIAL", 3411, 1 },
	{ "CARMOD_UNLOCK_PLATESBLUEONWHITE1_EXPENDITURE_TUNABLE_SPECIAL", 3412, 1 },
	{ "CARMOD_UNLOCK_PLATESBLUEONWHITE2_EXPENDITURE_TUNABLE_SPECIAL", 3413, 1 },
	{ "CARMOD_UNLOCK_PLATESBLUEONWHITE3_EXPENDITURE_TUNABLE_SPECIAL", 3414, 1 },
	{ "CARMOD_UNLOCK_PLATESYELLOWONBLUE_EXPENDITURE_TUNABLE_SPECIAL", 3415, 1 },
	{ "CARMOD_UNLOCK_PLATESYELLOWONBLACK_EXPENDITURE_TUNABLE_SPECIAL", 3416, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORCHROME_EXPENDITURE_TUNABLE_SPECIAL", 3417, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORCLASSIC_EXPENDITURE_TUNABLE_SPECIAL", 3418, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORMATTE_EXPENDITURE_TUNABLE_SPECIAL", 3419, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORMETALLIC_EXPENDITURE_TUNABLE_SPECIAL", 3420, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORMETALS_EXPENDITURE_TUNABLE_SPECIAL", 3421, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORPEARLESCENT_EXPENDITURE_TUNABLE_SPECIAL", 3422, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORCREW_EXPENDITURE_TUNABLE_SPECIAL", 3423, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORCHROME_EXPENDITURE_TUNABLE_SPECIAL", 3424, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORCLASSIC_EXPENDITURE_TUNABLE_SPECIAL", 3425, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORMATTE_EXPENDITURE_TUNABLE_SPECIAL", 3426, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORMETALLIC_EXPENDITURE_TUNABLE_SPECIAL", 3427, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORMETALS_EXPENDITURE_TUNABLE_SPECIAL", 3428, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORPEARLESCENT_EXPENDITURE_TUNABLE_SPECIAL", 3429, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORCREW_EXPENDITURE_TUNABLE_SPECIAL", 3430, 1 },
	{ "CARMOD_UNLOCK_CREWEMBLEM_EXPENDITURE_TUNABLE_SPECIAL", 3431, 1 },
	{ "CARMOD_UNLOCK_STOCKROOF_EXPENDITURE_TUNABLE_SPECIAL", 3432, 1 },
	{ "CARMOD_UNLOCK_STOCKSKIRT_EXPENDITURE_TUNABLE_SPECIAL", 3433, 1 },
	{ "CARMOD_UNLOCK_STOCKSPOILER_EXPENDITURE_TUNABLE_SPECIAL", 3434, 1 },
	{ "CARMOD_UNLOCK_STOCKSUSPENSION_EXPENDITURE_TUNABLE_SPECIAL", 3435, 1 },
	{ "CARMOD_UNLOCK_TRACKER_EXPENDITURE_TUNABLE_SPECIAL", 3436, 1 },
	{ "CARMOD_UNLOCK_STOCKTRANSMISSION_EXPENDITURE_TUNABLE_SPECIAL", 3437, 1 },
	{ "CARMOD_UNLOCK_NOTURBO_EXPENDITURE_TUNABLE_SPECIAL", 3438, 1 },
	{ "CARMOD_UNLOCK_STOCKWHEELS_EXPENDITURE_TUNABLE_SPECIAL", 3439, 1 },
	{ "CARMOD_UNLOCK_CREWSMOKE_EXPENDITURE_TUNABLE_SPECIAL", 3440, 1 },
	{ "CARMOD_UNLOCK_WINDOWSNONE_EXPENDITURE_TUNABLE_SPECIAL", 3441, 1 },
	{ "CARMOD_UNLOCK_BRAKES_L2_EXPENDITURE_TUNABLE_SPECIAL", 3442, 1 },
	{ "CARMOD_UNLOCK_BRAKES_L3_EXPENDITURE_TUNABLE_SPECIAL", 3443, 1 },
	{ "CARMOD_UNLOCK_BRAKES_L4_EXPENDITURE_TUNABLE_SPECIAL", 3444, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_20_EXPENDITURE_TUNABLE_SPECIAL", 3445, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_40_EXPENDITURE_TUNABLE_SPECIAL", 3446, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_60_EXPENDITURE_TUNABLE_SPECIAL", 3447, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_80_EXPENDITURE_TUNABLE_SPECIAL", 3448, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_100_EXPENDITURE_TUNABLE_SPECIAL", 3449, 1 },
	{ "CARMOD_UNLOCK_STOCK_BRAKES_EXPENDITURE_TUNABLE_SPECIAL", 3450, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L2_EXPENDITURE_TUNABLE_SPECIAL", 3451, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L3_EXPENDITURE_TUNABLE_SPECIAL", 3452, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L4_EXPENDITURE_TUNABLE_SPECIAL", 3453, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L5_EXPENDITURE_TUNABLE_SPECIAL", 3454, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L6_EXPENDITURE_TUNABLE_SPECIAL", 3455, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L7_EXPENDITURE_TUNABLE_SPECIAL", 3456, 1 },
	{ "CARMOD_UNLOCK_CUSTOM_TYRES_EXPENDITURE_TUNABLE_SPECIAL", 3457, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L2_EXPENDITURE_TUNABLE_SPECIAL", 3458, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L3_EXPENDITURE_TUNABLE_SPECIAL", 3459, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L4_EXPENDITURE_TUNABLE_SPECIAL", 3460, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L5_EXPENDITURE_TUNABLE_SPECIAL", 3461, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L6_EXPENDITURE_TUNABLE_SPECIAL", 3462, 1 },
	{ "CARMOD_UNLOCK_GRILL_L2_EXPENDITURE_TUNABLE_SPECIAL", 3463, 1 },
	{ "CARMOD_UNLOCK_GRILL_L3_EXPENDITURE_TUNABLE_SPECIAL", 3464, 1 },
	{ "CARMOD_UNLOCK_GRILL_L4_EXPENDITURE_TUNABLE_SPECIAL", 3465, 1 },
	{ "CARMOD_UNLOCK_GRILL_L5_EXPENDITURE_TUNABLE_SPECIAL", 3466, 1 },
	{ "CARMOD_UNLOCK_GRILL_L6_EXPENDITURE_TUNABLE_SPECIAL", 3467, 1 },
	{ "CARMOD_UNLOCK_ROOF_L1_EXPENDITURE_TUNABLE_SPECIAL", 3468, 1 },
	{ "CARMOD_UNLOCK_ROOF_L2_EXPENDITURE_TUNABLE_SPECIAL", 3469, 1 },
	{ "CARMOD_UNLOCK_ROOF_L3_EXPENDITURE_TUNABLE_SPECIAL", 3470, 1 },
	{ "CARMOD_UNLOCK_ROOF_L4_EXPENDITURE_TUNABLE_SPECIAL", 3471, 1 },
	{ "CARMOD_UNLOCK_ROOF_L5_EXPENDITURE_TUNABLE_SPECIAL", 3472, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L1_EXPENDITURE_TUNABLE_SPECIAL", 3473, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L2_EXPENDITURE_TUNABLE_SPECIAL", 3474, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L3_EXPENDITURE_TUNABLE_SPECIAL", 3475, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L4_EXPENDITURE_TUNABLE_SPECIAL", 3476, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L5_EXPENDITURE_TUNABLE_SPECIAL", 3477, 1 },
	{ "CARMOD_UNLOCK_WHEELS_L4_EXPENDITURE_TUNABLE_SPECIAL", 3478, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L2_EXPENDITURE_TUNABLE_SPECIAL", 3479, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L3_EXPENDITURE_TUNABLE_SPECIAL", 3480, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L4_EXPENDITURE_TUNABLE_SPECIAL", 3481, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L5_EXPENDITURE_TUNABLE_SPECIAL", 3482, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L2_EXPENDITURE_TUNABLE_SPECIAL", 3483, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L3_EXPENDITURE_TUNABLE_SPECIAL", 3484, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L4_EXPENDITURE_TUNABLE_SPECIAL", 3485, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L5_EXPENDITURE_TUNABLE_SPECIAL", 3486, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L2_EXPENDITURE_TUNABLE_SPECIAL", 3487, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L3_EXPENDITURE_TUNABLE_SPECIAL", 3488, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L4_EXPENDITURE_TUNABLE_SPECIAL", 3489, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L5_EXPENDITURE_TUNABLE_SPECIAL", 3490, 1 },
	{ "CARMOD_UNLOCK_TIMED_BOMB_EXPENDITURE_TUNABLE_SPECIAL", 3491, 1 },
	{ "CARMOD_UNLOCK_IGNITION_BOMB_EXPENDITURE_TUNABLE_SPECIAL", 3492, 1 },
	{ "CARMOD_UNLOCK_L_WING_L2_EXPENDITURE_TUNABLE_SPECIAL", 3493, 1 },
	{ "CARMOD_UNLOCK_L_WING_L3_EXPENDITURE_TUNABLE_SPECIAL", 3494, 1 },
	{ "CARMOD_UNLOCK_L_WING_L4_EXPENDITURE_TUNABLE_SPECIAL", 3495, 1 },
	{ "CARMOD_UNLOCK_L_WING_L5_EXPENDITURE_TUNABLE_SPECIAL", 3496, 1 },
	{ "CARMOD_UNLOCK_R_WING_L2_EXPENDITURE_TUNABLE_SPECIAL", 3497, 1 },
	{ "CARMOD_UNLOCK_BONNET_L2_EXPENDITURE_TUNABLE_SPECIAL", 3498, 1 },
	{ "CARMOD_UNLOCK_BONNET_L3_EXPENDITURE_TUNABLE_SPECIAL", 3499, 1 },
	{ "CARMOD_UNLOCK_BONNET_L4_EXPENDITURE_TUNABLE_SPECIAL", 3500, 1 },
	{ "CARMOD_UNLOCK_BONNET_L5_EXPENDITURE_TUNABLE_SPECIAL", 3501, 1 },
	{ "CARMOD_UNLOCK_BONNET_L6_EXPENDITURE_TUNABLE_SPECIAL", 3502, 1 },
	{ "CARMOD_UNLOCK_BONNET_L7_EXPENDITURE_TUNABLE_SPECIAL", 3503, 1 },
	{ "CARMOD_UNLOCK_HORN_L2_EXPENDITURE_TUNABLE_SPECIAL", 3504, 1 },
	{ "CARMOD_UNLOCK_HORN_L3_EXPENDITURE_TUNABLE_SPECIAL", 3505, 1 },
	{ "CARMOD_UNLOCK_HORN_L4_EXPENDITURE_TUNABLE_SPECIAL", 3506, 1 },
	{ "CARMOD_UNLOCK_HORN_L5_EXPENDITURE_TUNABLE_SPECIAL", 3507, 1 },
	{ "CARMOD_UNLOCK_HORN_L6_EXPENDITURE_TUNABLE_SPECIAL", 3508, 1 },
	{ "CARMOD_UNLOCK_HORN_L7_EXPENDITURE_TUNABLE_SPECIAL", 3509, 1 },
	{ "CARMOD_UNLOCK_HORN_L8_EXPENDITURE_TUNABLE_SPECIAL", 3510, 1 },
	{ "CARMOD_UNLOCK_HORN_L9_EXPENDITURE_TUNABLE_SPECIAL", 3511, 1 },
	{ "CARMOD_UNLOCK_XENON_LIGHTS_EXPENDITURE_TUNABLE_SPECIAL", 3512, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L2_EXPENDITURE_TUNABLE_SPECIAL", 3513, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L3_EXPENDITURE_TUNABLE_SPECIAL", 3514, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L4_EXPENDITURE_TUNABLE_SPECIAL", 3515, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L5_EXPENDITURE_TUNABLE_SPECIAL", 3516, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L1_EXPENDITURE_TUNABLE_SPECIAL", 3517, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L2_EXPENDITURE_TUNABLE_SPECIAL", 3518, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L3_EXPENDITURE_TUNABLE_SPECIAL", 3519, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L4_EXPENDITURE_TUNABLE_SPECIAL", 3520, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L5_EXPENDITURE_TUNABLE_SPECIAL", 3521, 1 },
	{ "CARMOD_UNLOCK_GEAR_BOX_L2_EXPENDITURE_TUNABLE_SPECIAL", 3522, 1 },
	{ "CARMOD_UNLOCK_GEAR_BOX_L3_EXPENDITURE_TUNABLE_SPECIAL", 3523, 1 },
	{ "CARMOD_UNLOCK_GEAR_BOX_L4_EXPENDITURE_TUNABLE_SPECIAL", 3524, 1 },
	{ "CARMOD_UNLOCK_TURBO_EXPENDITURE_TUNABLE_SPECIAL", 3525, 1 },
	{ "CARMOD_UNLOCK_BULLET_PROOF_TYRES_EXPENDITURE_TUNABLE_SPECIAL", 3526, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_WHITE_EXPENDITURE_TUNABLE_SPECIAL", 3527, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_ORANGE_EXPENDITURE_TUNABLE_SPECIAL", 3528, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_RED_EXPENDITURE_TUNABLE_SPECIAL", 3529, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_YELLOW_EXPENDITURE_TUNABLE_SPECIAL", 3530, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_BLUE_EXPENDITURE_TUNABLE_SPECIAL", 3531, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_BLACK_EXPENDITURE_TUNABLE_SPECIAL", 3532, 1 },
	{ "CARMOD_UNLOCK_LIGHT_SMOKE_WINDOWS_EXPENDITURE_TUNABLE_SPECIAL", 3533, 1 },
	{ "CARMOD_UNLOCK_DARK_SMOKE_WINDOWS_EXPENDITURE_TUNABLE_SPECIAL", 3534, 1 },
	{ "CARMOD_UNLOCK_LIMO_WINDOWS_EXPENDITURE_TUNABLE_SPECIAL", 3535, 1 },
	{ "CARMOD_UNLOCK_WHEELCOLOURS_EXPENDITURE_TUNABLE_BIKE", 3536, 1 },
	{ "CARMOD_UNLOCK_STOCKTIRES_EXPENDITURE_TUNABLE_BIKE", 3537, 1 },
	{ "CARMOD_UNLOCK_NOARMOUR_EXPENDITURE_TUNABLE_BIKE", 3538, 1 },
	{ "CARMOD_UNLOCK_STOCKFRONTBUMPER_EXPENDITURE_TUNABLE_BIKE", 3539, 1 },
	{ "CARMOD_UNLOCK_STOCKREARBUMPER_EXPENDITURE_TUNABLE_BIKE", 3540, 1 },
	{ "CARMOD_UNLOCK_STOCKCHASSIS_EXPENDITURE_TUNABLE_BIKE", 3541, 1 },
	{ "CARMOD_UNLOCK_STOCKEXHAUST_EXPENDITURE_TUNABLE_BIKE", 3542, 1 },
	{ "CARMOD_UNLOCK_STOCKLEFTFENDER_EXPENDITURE_TUNABLE_BIKE", 3543, 1 },
	{ "CARMOD_UNLOCK_STOCKRIGHTFENDER_EXPENDITURE_TUNABLE_BIKE", 3544, 1 },
	{ "CARMOD_UNLOCK_STOCKGRILLE_EXPENDITURE_TUNABLE_BIKE", 3545, 1 },
	{ "CARMOD_UNLOCK_STOCKHOOD_EXPENDITURE_TUNABLE_BIKE", 3546, 1 },
	{ "CARMOD_UNLOCK_STOCKHORN_EXPENDITURE_TUNABLE_BIKE", 3547, 1 },
	{ "CARMOD_UNLOCK_STOCKLIGHTS_EXPENDITURE_TUNABLE_BIKE", 3548, 1 },
	{ "CARMOD_UNLOCK_PLATESBLUEONWHITE1_EXPENDITURE_TUNABLE_BIKE", 3549, 1 },
	{ "CARMOD_UNLOCK_PLATESBLUEONWHITE2_EXPENDITURE_TUNABLE_BIKE", 3550, 1 },
	{ "CARMOD_UNLOCK_PLATESBLUEONWHITE3_EXPENDITURE_TUNABLE_BIKE", 3551, 1 },
	{ "CARMOD_UNLOCK_PLATESYELLOWONBLUE_EXPENDITURE_TUNABLE_BIKE", 3552, 1 },
	{ "CARMOD_UNLOCK_PLATESYELLOWONBLACK_EXPENDITURE_TUNABLE_BIKE", 3553, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORCHROME_EXPENDITURE_TUNABLE_BIKE", 3554, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORCLASSIC_EXPENDITURE_TUNABLE_BIKE", 3555, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORMATTE_EXPENDITURE_TUNABLE_BIKE", 3556, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORMETALLIC_EXPENDITURE_TUNABLE_BIKE", 3557, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORMETALS_EXPENDITURE_TUNABLE_BIKE", 3558, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORPEARLESCENT_EXPENDITURE_TUNABLE_BIKE", 3559, 1 },
	{ "CARMOD_UNLOCK_PRIMARYCOLORCREW_EXPENDITURE_TUNABLE_BIKE", 3560, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORCHROME_EXPENDITURE_TUNABLE_BIKE", 3561, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORCLASSIC_EXPENDITURE_TUNABLE_BIKE", 3562, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORMATTE_EXPENDITURE_TUNABLE_BIKE", 3563, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORMETALLIC_EXPENDITURE_TUNABLE_BIKE", 3564, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORMETALS_EXPENDITURE_TUNABLE_BIKE", 3565, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORPEARLESCENT_EXPENDITURE_TUNABLE_BIKE", 3566, 1 },
	{ "CARMOD_UNLOCK_SECONDARYCOLORCREW_EXPENDITURE_TUNABLE_BIKE", 3567, 1 },
	{ "CARMOD_UNLOCK_CREWEMBLEM_EXPENDITURE_TUNABLE_BIKE", 3568, 1 },
	{ "CARMOD_UNLOCK_STOCKROOF_EXPENDITURE_TUNABLE_BIKE", 3569, 1 },
	{ "CARMOD_UNLOCK_STOCKSKIRT_EXPENDITURE_TUNABLE_BIKE", 3570, 1 },
	{ "CARMOD_UNLOCK_STOCKSPOILER_EXPENDITURE_TUNABLE_BIKE", 3571, 1 },
	{ "CARMOD_UNLOCK_STOCKSUSPENSION_EXPENDITURE_TUNABLE_BIKE", 3572, 1 },
	{ "CARMOD_UNLOCK_TRACKER_EXPENDITURE_TUNABLE_BIKE", 3573, 1 },
	{ "CARMOD_UNLOCK_STOCKTRANSMISSION_EXPENDITURE_TUNABLE_BIKE", 3574, 1 },
	{ "CARMOD_UNLOCK_NOTURBO_EXPENDITURE_TUNABLE_BIKE", 3575, 1 },
	{ "CARMOD_UNLOCK_STOCKWHEELS_EXPENDITURE_TUNABLE_BIKE", 3576, 1 },
	{ "CARMOD_UNLOCK_CREWSMOKE_EXPENDITURE_TUNABLE_BIKE", 3577, 1 },
	{ "CARMOD_UNLOCK_WINDOWSNONE_EXPENDITURE_TUNABLE_BIKE", 3578, 1 },
	{ "CARMOD_UNLOCK_BRAKES_L2_EXPENDITURE_TUNABLE_BIKE", 3579, 1 },
	{ "CARMOD_UNLOCK_BRAKES_L3_EXPENDITURE_TUNABLE_BIKE", 3580, 1 },
	{ "CARMOD_UNLOCK_BRAKES_L4_EXPENDITURE_TUNABLE_BIKE", 3581, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_20_EXPENDITURE_TUNABLE_BIKE", 3582, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_40_EXPENDITURE_TUNABLE_BIKE", 3583, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_60_EXPENDITURE_TUNABLE_BIKE", 3584, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_80_EXPENDITURE_TUNABLE_BIKE", 3585, 1 },
	{ "CARMOD_UNLOCK_BODY_ARMOUR_100_EXPENDITURE_TUNABLE_BIKE", 3586, 1 },
	{ "CARMOD_UNLOCK_STOCK_BRAKES_EXPENDITURE_TUNABLE_BIKE", 3587, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L2_EXPENDITURE_TUNABLE_BIKE", 3588, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L3_EXPENDITURE_TUNABLE_BIKE", 3589, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L4_EXPENDITURE_TUNABLE_BIKE", 3590, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L5_EXPENDITURE_TUNABLE_BIKE", 3591, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L6_EXPENDITURE_TUNABLE_BIKE", 3592, 1 },
	{ "CARMOD_UNLOCK_F_BUMPER_L7_EXPENDITURE_TUNABLE_BIKE", 3593, 1 },
	{ "CARMOD_UNLOCK_CUSTOM_TYRES_EXPENDITURE_TUNABLE_BIKE", 3594, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L2_EXPENDITURE_TUNABLE_BIKE", 3595, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L3_EXPENDITURE_TUNABLE_BIKE", 3596, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L4_EXPENDITURE_TUNABLE_BIKE", 3597, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L5_EXPENDITURE_TUNABLE_BIKE", 3598, 1 },
	{ "CARMOD_UNLOCK_EXHAUST_L6_EXPENDITURE_TUNABLE_BIKE", 3599, 1 },
	{ "CARMOD_UNLOCK_GRILL_L2_EXPENDITURE_TUNABLE_BIKE", 3600, 1 },
	{ "CARMOD_UNLOCK_GRILL_L3_EXPENDITURE_TUNABLE_BIKE", 3601, 1 },
	{ "CARMOD_UNLOCK_GRILL_L4_EXPENDITURE_TUNABLE_BIKE", 3602, 1 },
	{ "CARMOD_UNLOCK_GRILL_L5_EXPENDITURE_TUNABLE_BIKE", 3603, 1 },
	{ "CARMOD_UNLOCK_GRILL_L6_EXPENDITURE_TUNABLE_BIKE", 3604, 1 },
	{ "CARMOD_UNLOCK_ROOF_L1_EXPENDITURE_TUNABLE_BIKE", 3605, 1 },
	{ "CARMOD_UNLOCK_ROOF_L2_EXPENDITURE_TUNABLE_BIKE", 3606, 1 },
	{ "CARMOD_UNLOCK_ROOF_L3_EXPENDITURE_TUNABLE_BIKE", 3607, 1 },
	{ "CARMOD_UNLOCK_ROOF_L4_EXPENDITURE_TUNABLE_BIKE", 3608, 1 },
	{ "CARMOD_UNLOCK_ROOF_L5_EXPENDITURE_TUNABLE_BIKE", 3609, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L1_EXPENDITURE_TUNABLE_BIKE", 3610, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L2_EXPENDITURE_TUNABLE_BIKE", 3611, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L3_EXPENDITURE_TUNABLE_BIKE", 3612, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L4_EXPENDITURE_TUNABLE_BIKE", 3613, 1 },
	{ "CARMOD_UNLOCK_SUSPENSION_L5_EXPENDITURE_TUNABLE_BIKE", 3614, 1 },
	{ "CARMOD_UNLOCK_WHEELS_L4_EXPENDITURE_TUNABLE_BIKE", 3615, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L2_EXPENDITURE_TUNABLE_BIKE", 3616, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L3_EXPENDITURE_TUNABLE_BIKE", 3617, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L4_EXPENDITURE_TUNABLE_BIKE", 3618, 1 },
	{ "CARMOD_UNLOCK_R_BUMPER_L5_EXPENDITURE_TUNABLE_BIKE", 3619, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L2_EXPENDITURE_TUNABLE_BIKE", 3620, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L3_EXPENDITURE_TUNABLE_BIKE", 3621, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L4_EXPENDITURE_TUNABLE_BIKE", 3622, 1 },
	{ "CARMOD_UNLOCK_CHASSIS_L5_EXPENDITURE_TUNABLE_BIKE", 3623, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L2_EXPENDITURE_TUNABLE_BIKE", 3624, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L3_EXPENDITURE_TUNABLE_BIKE", 3625, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L4_EXPENDITURE_TUNABLE_BIKE", 3626, 1 },
	{ "CARMOD_UNLOCK_ENGINE_L5_EXPENDITURE_TUNABLE_BIKE", 3627, 1 },
	{ "CARMOD_UNLOCK_TIMED_BOMB_EXPENDITURE_TUNABLE_BIKE", 3628, 1 },
	{ "CARMOD_UNLOCK_IGNITION_BOMB_EXPENDITURE_TUNABLE_BIKE", 3629, 1 },
	{ "CARMOD_UNLOCK_L_WING_L2_EXPENDITURE_TUNABLE_BIKE", 3630, 1 },
	{ "CARMOD_UNLOCK_L_WING_L3_EXPENDITURE_TUNABLE_BIKE", 3631, 1 },
	{ "CARMOD_UNLOCK_L_WING_L4_EXPENDITURE_TUNABLE_BIKE", 3632, 1 },
	{ "CARMOD_UNLOCK_L_WING_L5_EXPENDITURE_TUNABLE_BIKE", 3633, 1 },
	{ "CARMOD_UNLOCK_R_WING_L2_EXPENDITURE_TUNABLE_BIKE", 3634, 1 },
	{ "CARMOD_UNLOCK_BONNET_L2_EXPENDITURE_TUNABLE_BIKE", 3635, 1 },
	{ "CARMOD_UNLOCK_BONNET_L3_EXPENDITURE_TUNABLE_BIKE", 3636, 1 },
	{ "CARMOD_UNLOCK_BONNET_L4_EXPENDITURE_TUNABLE_BIKE", 3637, 1 },
	{ "CARMOD_UNLOCK_BONNET_L5_EXPENDITURE_TUNABLE_BIKE", 3638, 1 },
	{ "CARMOD_UNLOCK_BONNET_L6_EXPENDITURE_TUNABLE_BIKE", 3639, 1 },
	{ "CARMOD_UNLOCK_BONNET_L7_EXPENDITURE_TUNABLE_BIKE", 3640, 1 },
	{ "CARMOD_UNLOCK_HORN_L2_EXPENDITURE_TUNABLE_BIKE", 3641, 1 },
	{ "CARMOD_UNLOCK_HORN_L3_EXPENDITURE_TUNABLE_BIKE", 3642, 1 },
	{ "CARMOD_UNLOCK_HORN_L4_EXPENDITURE_TUNABLE_BIKE", 3643, 1 },
	{ "CARMOD_UNLOCK_HORN_L5_EXPENDITURE_TUNABLE_BIKE", 3644, 1 },
	{ "CARMOD_UNLOCK_HORN_L6_EXPENDITURE_TUNABLE_BIKE", 3645, 1 },
	{ "CARMOD_UNLOCK_HORN_L7_EXPENDITURE_TUNABLE_BIKE", 3646, 1 },
	{ "CARMOD_UNLOCK_HORN_L8_EXPENDITURE_TUNABLE_BIKE", 3647, 1 },
	{ "CARMOD_UNLOCK_HORN_L9_EXPENDITURE_TUNABLE_BIKE", 3648, 1 },
	{ "CARMOD_UNLOCK_XENON_LIGHTS_EXPENDITURE_TUNABLE_BIKE", 3649, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L2_EXPENDITURE_TUNABLE_BIKE", 3650, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L3_EXPENDITURE_TUNABLE_BIKE", 3651, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L4_EXPENDITURE_TUNABLE_BIKE", 3652, 1 },
	{ "CARMOD_UNLOCK_SKIRTS_L5_EXPENDITURE_TUNABLE_BIKE", 3653, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L1_EXPENDITURE_TUNABLE_BIKE", 3654, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L2_EXPENDITURE_TUNABLE_BIKE", 3655, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L3_EXPENDITURE_TUNABLE_BIKE", 3656, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L4_EXPENDITURE_TUNABLE_BIKE", 3657, 1 },
	{ "CARMOD_UNLOCK_SPOILER_L5_EXPENDITURE_TUNABLE_BIKE", 3658, 1 },
	{ "CARMOD_UNLOCK_GEAR_BOX_L2_EXPENDITURE_TUNABLE_BIKE", 3659, 1 },
	{ "CARMOD_UNLOCK_GEAR_BOX_L3_EXPENDITURE_TUNABLE_BIKE", 3660, 1 },
	{ "CARMOD_UNLOCK_GEAR_BOX_L4_EXPENDITURE_TUNABLE_BIKE", 3661, 1 },
	{ "CARMOD_UNLOCK_TURBO_EXPENDITURE_TUNABLE_BIKE", 3662, 1 },
	{ "CARMOD_UNLOCK_BULLET_PROOF_TYRES_EXPENDITURE_TUNABLE_BIKE", 3663, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_WHITE_EXPENDITURE_TUNABLE_BIKE", 3664, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_ORANGE_EXPENDITURE_TUNABLE_BIKE", 3665, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_RED_EXPENDITURE_TUNABLE_BIKE", 3666, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_YELLOW_EXPENDITURE_TUNABLE_BIKE", 3667, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_BLUE_EXPENDITURE_TUNABLE_BIKE", 3668, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_BLACK_EXPENDITURE_TUNABLE_BIKE", 3669, 1 },
	{ "CARMOD_UNLOCK_LIGHT_SMOKE_WINDOWS_EXPENDITURE_TUNABLE_BIKE", 3670, 1 },
	{ "CARMOD_UNLOCK_DARK_SMOKE_WINDOWS_EXPENDITURE_TUNABLE_BIKE", 3671, 1 },
	{ "CARMOD_UNLOCK_LIMO_WINDOWS_EXPENDITURE_TUNABLE_BIKE", 3672, 1 },
	{ "SAT_PURCHASED_VEHICLE_MOD", 3692, 2 },
	{ "SAT_DONE_STUNT_JUMP", 3720, 2 },
	{ "SAT_MADE_MONEY_BETTING", 3724, 2 },
	{ "DISABLE_PV_DUPLICATE_FIX", 3766, 2 },
	{ "CINEMA_EXPENDITURE_MODIFIER", 3948, 0 },
	{ "PROPERTY_HIGH_APT_1_EXPENDITURE_MODIFIER", 3949, 0 },
	{ "PROPERTY_HIGH_APT_2_EXPENDITURE_MODIFIER", 3950, 0 },
	{ "PROPERTY_HIGH_APT_3_EXPENDITURE_MODIFIER", 3951, 0 },
	{ "PROPERTY_HIGH_APT_4_EXPENDITURE_MODIFIER", 3952, 0 },
	{ "PROPERTY_HIGH_APT_5_EXPENDITURE_MODIFIER", 3953, 0 },
	{ "PROPERTY_HIGH_APT_6_EXPENDITURE_MODIFIER", 3954, 0 },
	{ "PROPERTY_HIGH_APT_7_EXPENDITURE_MODIFIER", 3955, 0 },
	{ "PROPERTY_HIGH_APT_8_EXPENDITURE_MODIFIER", 3956, 0 },
	{ "PROPERTY_HIGH_APT_9_EXPENDITURE_MODIFIER", 3957, 0 },
	{ "PROPERTY_HIGH_APT_10_EXPENDITURE_MODIFIER", 3958, 0 },
	{ "PROPERTY_HIGH_APT_11_EXPENDITURE_MODIFIER", 3959, 0 },
	{ "PROPERTY_HIGH_APT_12_EXPENDITURE_MODIFIER", 3960, 0 },
	{ "PROPERTY_HIGH_APT_13_EXPENDITURE_MODIFIER", 3961, 0 },
	{ "PROPERTY_HIGH_APT_14_EXPENDITURE_MODIFIER", 3962, 0 },
	{ "PROPERTY_HIGH_APT_15_EXPENDITURE_MODIFIER", 3963, 0 },
	{ "PROPERTY_HIGH_APT_16_EXPENDITURE_MODIFIER", 3964, 0 },
	{ "PROPERTY_HIGH_APT_17_EXPENDITURE_MODIFIER", 3965, 0 },
	{ "PROPERTY_MEDIUM_APT_1_EXPENDITURE_MODIFIER", 3966, 0 },
	{ "PROPERTY_MEDIUM_APT_2_EXPENDITURE_MODIFIER", 3967, 0 },
	{ "PROPERTY_MEDIUM_APT_3_EXPENDITURE_MODIFIER", 3968, 0 },
	{ "PROPERTY_MEDIUM_APT_4_EXPENDITURE_MODIFIER", 3969, 0 },
	{ "PROPERTY_MEDIUM_APT_5_EXPENDITURE_MODIFIER", 3970, 0 },
	{ "PROPERTY_MEDIUM_APT_6_EXPENDITURE_MODIFIER", 3971, 0 },
	{ "PROPERTY_MEDIUM_APT_7_EXPENDITURE_MODIFIER", 3972, 0 },
	{ "PROPERTY_MEDIUM_APT_8_EXPENDITURE_MODIFIER", 3973, 0 },
	{ "PROPERTY_MEDIUM_APT_9_EXPENDITURE_MODIFIER", 3974, 0 },
	{ "PROPERTY_LOW_APT_1_EXPENDITURE_MODIFIER", 3975, 0 },
	{ "PROPERTY_LOW_APT_2_EXPENDITURE_MODIFIER", 3976, 0 },
	{ "PROPERTY_LOW_APT_3_EXPENDITURE_MODIFIER", 3977, 0 },
	{ "PROPERTY_LOW_APT_4_EXPENDITURE_MODIFIER", 3978, 0 },
	{ "PROPERTY_LOW_APT_5_EXPENDITURE_MODIFIER", 3979, 0 },
	{ "PROPERTY_LOW_APT_6_EXPENDITURE_MODIFIER", 3980, 0 },
	{ "PROPERTY_LOW_APT_7_EXPENDITURE_MODIFIER", 3981, 0 },
	{ "PROPERTY_GARAGE_EAST_LOS_SANTOS_1_EXPENDITURE_MODIFIER", 3982, 0 },
	{ "PROPERTY_GARAGE_EAST_LOS_SANTOS_2_EXPENDITURE_MODIFIER", 3983, 0 },
	{ "PROPERTY_GARAGE_EAST_LOS_SANTOS_3_EXPENDITURE_MODIFIER", 3984, 0 },
	{ "PROPERTY_GARAGE_EAST_LOS_SANTOS_4_EXPENDITURE_MODIFIER", 3985, 0 },
	{ "PROPERTY_GARAGE_EAST_LOS_SANTOS_5_EXPENDITURE_MODIFIER", 3986, 0 },
	{ "PROPERTY_GARAGE_EAST_LOS_SANTOS_6_EXPENDITURE_MODIFIER", 3987, 0 },
	{ "PROPERTY_GARAGE_EAST_LOS_SANTOS_7_EXPENDITURE_MODIFIER", 3988, 0 },
	{ "PROPERTY_GARAGE_EAST_LOS_SANTOS_8_EXPENDITURE_MODIFIER", 3989, 0 },
	{ "PROPERTY_GARAGE_SOUTH_LOS_SANTOS_1_EXPENDITURE_MODIFIER", 3990, 0 },
	{ "PROPERTY_GARAGE_SOUTH_LOS_SANTOS_2_EXPENDITURE_MODIFIER", 3991, 0 },
	{ "PROPERTY_GARAGE_NEW_1_EXPENDITURE_MODIFIER", 3992, 0 },
	{ "PROPERTY_GARAGE_NEW_2_EXPENDITURE_MODIFIER", 3993, 0 },
	{ "PROPERTY_GARAGE_NEW_3_EXPENDITURE_MODIFIER", 3994, 0 },
	{ "PROPERTY_GARAGE_NEW_5_EXPENDITURE_MODIFIER", 3995, 0 },
	{ "PROPERTY_GARAGE_NEW_6_EXPENDITURE_MODIFIER", 3996, 0 },
	{ "PROPERTY_GARAGE_NEW_7_EXPENDITURE_MODIFIER", 3997, 0 },
	{ "PROPERTY_GARAGE_NEW_8_EXPENDITURE_MODIFIER", 3998, 0 },
	{ "PROPERTY_GARAGE_NEW_9_EXPENDITURE_MODIFIER", 3999, 0 },
	{ "PROPERTY_GARAGE_NEW_14_EXPENDITURE_MODIFIER", 4000, 0 },
	{ "PROPERTY_GARAGE_NEW_16_EXPENDITURE_MODIFIER", 4001, 0 },
	{ "PROPERTY_GARAGE_NEW_17_EXPENDITURE_MODIFIER", 4002, 0 },
	{ "PROPERTY_GARAGE_NEW_18_EXPENDITURE_MODIFIER", 4003, 0 },
	{ "PROPERTY_GARAGE_NEW_19_EXPENDITURE_MODIFIER", 4004, 0 },
	{ "PROPERTY_GARAGE_NEW_20_EXPENDITURE_MODIFIER", 4005, 0 },
	{ "PROPERTY_GARAGE_NEW_21_EXPENDITURE_MODIFIER", 4006, 0 },
	{ "PROPERTY_GARAGE_NEW_22_EXPENDITURE_MODIFIER", 4007, 0 },
	{ "PROPERTY_GARAGE_NEW_23_EXPENDITURE_MODIFIER", 4008, 0 },
	{ "ADDER_EXPENDITURE_MODIFIER", 4009, 0 },
	{ "AIRBUS_EXPENDITURE_MODIFIER", 4010, 0 },
	{ "AKUMA_EXPENDITURE_MODIFIER", 4011, 0 },
	{ "ANNIHILATOR_EXPENDITURE_MODIFIER", 4012, 0 },
	{ "BALLER2_EXPENDITURE_MODIFIER", 4013, 0 },
	{ "BARRACKS_EXPENDITURE_MODIFIER", 4014, 0 },
	{ "BATI_EXPENDITURE_MODIFIER", 4015, 0 },
	{ "BATI2_EXPENDITURE_MODIFIER", 4016, 0 },
	{ "BFINJECTION_EXPENDITURE_MODIFIER", 4017, 0 },
	{ "BISON_EXPENDITURE_MODIFIER", 4018, 0 },
	{ "BLAZER_EXPENDITURE_MODIFIER", 4019, 0 },
	{ "BMX_EXPENDITURE_MODIFIER", 4020, 0 },
	{ "BULLET_EXPENDITURE_MODIFIER", 4021, 0 },
	{ "BUS_EXPENDITURE_MODIFIER", 4022, 0 },
	{ "BUZZARD_EXPENDITURE_MODIFIER", 4023, 0 },
	{ "CARBONIZZARE_EXPENDITURE_MODIFIER", 4024, 0 },
	{ "CARBONRS_EXPENDITURE_MODIFIER", 4025, 0 },
	{ "CAVALCADE_EXPENDITURE_MODIFIER", 4026, 0 },
	{ "CHEETAH_EXPENDITURE_MODIFIER", 4027, 0 },
	{ "COACH_EXPENDITURE_MODIFIER", 4028, 0 },
	{ "COGCABRIO_EXPENDITURE_MODIFIER", 4029, 0 },
	{ "COMET2_EXPENDITURE_MODIFIER", 4030, 0 },
	{ "COQUETTE_EXPENDITURE_MODIFIER", 4031, 0 },
	{ "CRUISER_EXPENDITURE_MODIFIER", 4032, 0 },
	{ "CRUSADER_EXPENDITURE_MODIFIER", 4033, 0 },
	{ "CUBAN800_EXPENDITURE_MODIFIER", 4034, 0 },
	{ "DILETTANTE_EXPENDITURE_MODIFIER", 4035, 0 },
	{ "DOUBLE_EXPENDITURE_MODIFIER", 4036, 0 },
	{ "DUMP_EXPENDITURE_MODIFIER", 4037, 0 },
	{ "DUSTER_EXPENDITURE_MODIFIER", 4038, 0 },
	{ "ELEGY2_EXPENDITURE_MODIFIER", 4039, 0 },
	{ "ENTITYXF_EXPENDITURE_MODIFIER", 4040, 0 },
	{ "EXEMPLAR_EXPENDITURE_MODIFIER", 4041, 0 },
	{ "FAGGIO2_EXPENDITURE_MODIFIER", 4042, 0 },
	{ "FELON_EXPENDITURE_MODIFIER", 4043, 0 },
	{ "FELTZER2_EXPENDITURE_MODIFIER", 4044, 0 },
	{ "FROGGER_EXPENDITURE_MODIFIER", 4045, 0 },
	{ "FUGITIVE_EXPENDITURE_MODIFIER", 4046, 0 },
	{ "GAUNTLET_EXPENDITURE_MODIFIER", 4047, 0 },
	{ "HEXER_EXPENDITURE_MODIFIER", 4048, 0 },
	{ "HOTKNIFE_EXPENDITURE_MODIFIER", 4049, 0 },
	{ "INFERNUS_EXPENDITURE_MODIFIER", 4050, 0 },
	{ "ISSI2_EXPENDITURE_MODIFIER", 4051, 0 },
	{ "JB700_EXPENDITURE_MODIFIER", 4052, 0 },
	{ "JETMAX_EXPENDITURE_MODIFIER", 4053, 0 },
	{ "JOURNEY_EXPENDITURE_MODIFIER", 4054, 0 },
	{ "KHAMELION_EXPENDITURE_MODIFIER", 4055, 0 },
	{ "LUXOR_EXPENDITURE_MODIFIER", 4056, 0 },
	{ "MAMMATUS_EXPENDITURE_MODIFIER", 4057, 0 },
	{ "MARQUIS_EXPENDITURE_MODIFIER", 4058, 0 },
	{ "MAVERICK_EXPENDITURE_MODIFIER", 4059, 0 },
	{ "MONROE_EXPENDITURE_MODIFIER", 4060, 0 },
	{ "MULE_EXPENDITURE_MODIFIER", 4061, 0 },
	{ "NINEF_EXPENDITURE_MODIFIER", 4062, 0 },
	{ "NINEF2_EXPENDITURE_MODIFIER", 4063, 0 },
	{ "ORACLE2_EXPENDITURE_MODIFIER", 4064, 0 },
	{ "PCJ_EXPENDITURE_MODIFIER", 4065, 0 },
	{ "RAPIDGT_EXPENDITURE_MODIFIER", 4066, 0 },
	{ "RAPIDGT2_EXPENDITURE_MODIFIER", 4067, 0 },
	{ "RENTALBUS_EXPENDITURE_MODIFIER", 4068, 0 },
	{ "RHINO_EXPENDITURE_MODIFIER", 4069, 0 },
	{ "ROCOTO_EXPENDITURE_MODIFIER", 4070, 0 },
	{ "RUFFIAN_EXPENDITURE_MODIFIER", 4071, 0 },
	{ "SANCHEZ_EXPENDITURE_MODIFIER", 4072, 0 },
	{ "SANDKING_EXPENDITURE_MODIFIER", 4073, 0 },
	{ "SCHWARZER_EXPENDITURE_MODIFIER", 4074, 0 },
	{ "SCORCHER_EXPENDITURE_MODIFIER", 4075, 0 },
	{ "SEASHARK_EXPENDITURE_MODIFIER", 4076, 0 },
	{ "SHAMAL_EXPENDITURE_MODIFIER", 4077, 0 },
	{ "SQUALO_EXPENDITURE_MODIFIER", 4078, 0 },
	{ "STINGER_EXPENDITURE_MODIFIER", 4079, 0 },
	{ "STINGERGT_EXPENDITURE_MODIFIER", 4080, 0 },
	{ "STRETCH_EXPENDITURE_MODIFIER", 4081, 0 },
	{ "STUNT_EXPENDITURE_MODIFIER", 4082, 0 },
	{ "SUNTRAP_EXPENDITURE_MODIFIER", 4083, 0 },
	{ "SUPERD_EXPENDITURE_MODIFIER", 4084, 0 },
	{ "SURANO_EXPENDITURE_MODIFIER", 4085, 0 },
	{ "TITAN_EXPENDITURE_MODIFIER", 4086, 0 },
	{ "TRIBIKE_EXPENDITURE_MODIFIER", 4087, 0 },
	{ "TRIBIKE2_EXPENDITURE_MODIFIER", 4088, 0 },
	{ "TRIBIKE3_EXPENDITURE_MODIFIER", 4089, 0 },
	{ "TROPIC_EXPENDITURE_MODIFIER", 4090, 0 },
	{ "VACCA_EXPENDITURE_MODIFIER", 4091, 0 },
	{ "VADER_EXPENDITURE_MODIFIER", 4092, 0 },
	{ "VELUM_EXPENDITURE_MODIFIER", 4093, 0 },
	{ "VIGERO_EXPENDITURE_MODIFIER", 4094, 0 },
	{ "VOLTIC_EXPENDITURE_MODIFIER", 4095, 0 },
	{ "ZION_EXPENDITURE_MODIFIER", 4096, 0 },
	{ "ZION2_EXPENDITURE_MODIFIER", 4097, 0 },
	{ "ZTYPE_EXPENDITURE_MODIFIER", 4098, 0 },
	{ "ASEA_EXPENDITURE_MODIFIER", 4099, 0 },
	{ "FELON2_EXPENDITURE_MODIFIER", 4100, 0 },
	{ "REQUEST_BRUCIE_BOX_EXPENDITURE_MODIFIER", 4101, 0 },
	{ "REQUEST_LOST_BACKUP1_EXPENDITURE_MODIFIER", 4102, 0 },
	{ "REQUEST_LOST_BACKUP2_EXPENDITURE_MODIFIER", 4103, 0 },
	{ "REQUEST_LOST_BACKUP3_EXPENDITURE_MODIFIER", 4104, 0 },
	{ "REQUEST_VAGOS_BACKUP1_EXPENDITURE_MODIFIER", 4105, 0 },
	{ "REQUEST_VAGOS_BACKUP2_EXPENDITURE_MODIFIER", 4106, 0 },
	{ "REQUEST_VAGOS_BACKUP3_EXPENDITURE_MODIFIER", 4107, 0 },
	{ "REQUEST_FAMILY_BACKUP1_EXPENDITURE_MODIFIER", 4108, 0 },
	{ "REQUEST_FAMILY_BACKUP2_EXPENDITURE_MODIFIER", 4109, 0 },
	{ "REQUEST_FAMILY_BACKUP3_EXPENDITURE_MODIFIER", 4110, 0 },
	{ "REQUEST_THIEF1_EXPENDITURE_MODIFIER", 4111, 0 },
	{ "REQUEST_THIEF2_EXPENDITURE_MODIFIER", 4112, 0 },
	{ "REQUEST_THIEF3_EXPENDITURE_MODIFIER", 4113, 0 },
	{ "REQUEST_OFF_THE_RADAR_EXPENDITURE_MODIFIER", 4114, 0 },
	{ "REQUEST_AMMO_DROP_EXPENDITURE_MODIFIER", 4115, 0 },
	{ "REQUEST_BOAT_PICKUP_EXPENDITURE_MODIFIER", 4116, 0 },
	{ "REQUEST_BACKUP_HELI_EXPENDITURE_MODIFIER", 4117, 0 },
	{ "REQUEST_AIRSTRIKE_EXPENDITURE_MODIFIER", 4118, 0 },
	{ "REQUEST_ARMY_EXPENDITURE_MODIFIER", 4119, 0 },
	{ "REQUEST_HELI_PICKUP_EXPENDITURE_MODIFIER", 4120, 0 },
	{ "REQUEST_REVEAL_PLAYERS_EXPENDITURE_MODIFIER", 4121, 0 },
	{ "REQUEST_LESTER_JOB_EXPENDITURE_MODIFIER", 4122, 0 },
	{ "REQUEST_LAMAR_JOB_EXPENDITURE_MODIFIER", 4123, 0 },
	{ "REQUEST_SIMEON_JOB_EXPENDITURE_MODIFIER", 4124, 0 },
	{ "REQUEST_MARTIN_JOB_EXPENDITURE_MODIFIER", 4125, 0 },
	{ "REQUEST_REMOVE_WANTED_EXPENDITURE_MODIFIER", 4126, 0 },
	{ "REQUEST_PEGASUS_EXPENDITURE_MODIFIER", 4127, 0 },
	{ "REQUEST_LESTER_LOCATE_BOAT_EXPENDITURE_MODIFIER", 4128, 0 },
	{ "REQUEST_LESTER_LOCATE_HELI_EXPENDITURE_MODIFIER", 4129, 0 },
	{ "REQUEST_LESTER_LOCATE_CAR_EXPENDITURE_MODIFIER", 4130, 0 },
	{ "REQUEST_LESTER_LOCATE_PLANE_EXPENDITURE_MODIFIER", 4131, 0 },
	{ "TRANSITION_DELAY_MODIFIER", 4132, 0 },
	{ "TUTORIAL_CORONA_MODIFIER", 4133, 0 },
	{ "TRANSITION_STUCK_LAUNCHING_MODIFIER", 4135, 0 },
	{ "TRANSITION_STUCK_ENTERING_MODIFIER", 4136, 0 },
	{ "TRANSITION_STUCK_BEFORE_LAUNCH_MODIFIER", 4139, 0 },
	{ "EXPENSE_MODIFIER_GOLD_DECO_EARRINGS", 4140, 0 },
	{ "EXPENSE_MODIFIER_GOLD_DECO_EARRINGS", 4140, 0 },
	{ "EXPENSE_MODIFIER_SILVER_DECO_EARRINGS", 4141, 0 },
	{ "EXPENSE_MODIFIER_PEARL_DECO_EARRINGS", 4142, 0 },
	{ "EXPENSE_MODIFIER_COPPER_DECO_EARRINGS", 4143, 0 },
	{ "EXPENSE_MODIFIER_TWO_TONE_DECO_EARRINGS", 4144, 0 },
	{ "EXPENSE_MODIFIER_SAPPHIRE_DECO_EARRINGS", 4145, 0 },
	{ "EXPENSE_MODIFIER_GOLD_HOOP_EARRINGS", 4146, 0 },
	{ "EXPENSE_MODIFIER_SILVER_HOOP_EARRINGS", 4147, 0 },
	{ "EXPENSE_MODIFIER_PINK_HOOP_EARRINGS", 4148, 0 },
	{ "EXPENSE_MODIFIER_COPPER_HOOP_EARRINGS", 4149, 0 },
	{ "EXPENSE_MODIFIER_PURPLE_HOOP_EARRINGS", 4150, 0 },
	{ "EXPENSE_MODIFIER_WHITE_HOOP_EARRINGS", 4151, 0 },
	{ "EXPENSE_MODIFIER_HARSH_SOULS_SWEATBAND", 4152, 0 },
	{ "EXPENSE_MODIFIER_PROLAPS_SWEATBAND", 4153, 0 },
	{ "EXPENSE_MODIFIER_LC_SWEATBAND", 4154, 0 },
	{ "EXPENSE_MODIFIER_AQUA_STRIPED_SWEATBAND", 4155, 0 },
	{ "EXPENSE_MODIFIER_PINK_CHECK_SWEATBAND", 4156, 0 },
	{ "EXPENSE_MODIFIER_SQUEEZERS_SWEATBAND", 4157, 0 },
	{ "EXPENSE_MODIFIER_SILVER_BANGLES", 4158, 0 },
	{ "EXPENSE_MODIFIER_GOLD_BANGLES", 4159, 0 },
	{ "EXPENSE_MODIFIER_WHITE_LEATHER_STRAPS", 4160, 0 },
	{ "EXPENSE_MODIFIER_RAINBOW_LEATHER_STRAPS", 4161, 0 },
	{ "EXPENSE_MODIFIER_ONYX_PENDANT", 4162, 0 },
	{ "EXPENSE_MODIFIER_PEARL_PENDANT", 4163, 0 },
	{ "EXPENSE_MODIFIER_JADE_PENDANT", 4164, 0 },
	{ "EXPENSE_MODIFIER_CARNELIAN_PENDANT", 4165, 0 },
	{ "EXPENSE_MODIFIER_AQUAMARINE_PENDANT", 4166, 0 },
	{ "EXPENSE_MODIFIER_AMETHYST_PENDANT", 4167, 0 },
	{ "EXPENSE_MODIFIER_GOLD_NECKLACE", 4168, 0 },
	{ "EXPENSE_MODIFIER_SILVER_NECKLACE", 4169, 0 },
	{ "EXPENSE_MODIFIER_SCARF", 4170, 0 },
	{ "EXPENSE_MODIFIER_WHITE_TIE", 4171, 0 },
	{ "EXPENSE_MODIFIER_GRAY_TIE", 4172, 0 },
	{ "EXPENSE_MODIFIER_BLACK_TIE", 4173, 0 },
	{ "EXPENSE_MODIFIER_WHITE_SKINNY_TIE", 4174, 0 },
	{ "EXPENSE_MODIFIER_GRAY_SKINNY_TIE", 4175, 0 },
	{ "EXPENSE_MODIFIER_BLACK_SKINNY_TIE", 4176, 0 },
	{ "EXPENSE_MODIFIER_BLACK_BOWTIE", 4177, 0 },
	{ "Discount_Male_Special_Barely_Blue_Shirt", 4178, 0 },
	{ "Discount_Male_Special_Black_Shirt", 4179, 0 },
	{ "Discount_Male_Special_Black_Vest", 4180, 0 },
	{ "Discount_Male_Special_Blue_Check_Shirt", 4181, 0 },
	{ "Discount_Male_Special_Blue_Striped_Shirt", 4182, 0 },
	{ "Discount_Male_Special_Blue_Vest", 4183, 0 },
	{ "Discount_Male_Special_Blue_Woven_Shirt", 4184, 0 },
	{ "Discount_Male_Special_Charcoal_Shirt", 4185, 0 },
	{ "Discount_Male_Special_Dark_Salmon_Shirt", 4186, 0 },
	{ "Discount_Male_Special_Fuchsia_Shirt", 4187, 0 },
	{ "Discount_Male_Special_Gray_Vest", 4188, 0 },
	{ "Discount_Male_Special_Lemon_Shirt", 4189, 0 },
	{ "Discount_Male_Special_Mint_Shirt", 4190, 0 },
	{ "Discount_Male_Special_Ocean_Stripe_Shirt", 4191, 0 },
	{ "Discount_Male_Special_Off_White_Shirt", 4192, 0 },
	{ "Discount_Male_Special_Pale_Blue_Shirt", 4193, 0 },
	{ "Discount_Male_Special_Pale_Olive_Shirt", 4194, 0 },
	{ "Discount_Male_Special_Pink_Check_Shirt", 4195, 0 },
	{ "Discount_Male_Special_Pink_Shirt", 4196, 0 },
	{ "Discount_Male_Special_Pink_Striped_Shirt", 4197, 0 },
	{ "Discount_Male_Special_Salmon_Shirt", 4198, 0 },
	{ "Discount_Male_Special_Silver_Shirt", 4199, 0 },
	{ "Discount_Male_Special_Tan_Shirt", 4200, 0 },
	{ "Discount_Male_Special_White_Shirt", 4201, 0 },
	{ "Discount_Male_Special_White_Tshirt", 4202, 0 },
	{ "XP_TUNABLE_DAILY_DEATHMATCH", 4203, 1 },
	{ "XP_TUNABLE_DAILY_MISSION", 4204, 1 },
	{ "XP_TUNABLE_DAILY_RACE", 4205, 1 },
	{ "XP_TUNABLE_FIRST_WIN_OF_THE_DAY_BONUS", 4206, 1 },
	{ "XP_TUNABLE_PLAY_ONE_OF_EACH_GAME_TYPE_AND_MINIGAME", 4207, 1 },
	{ "XP_TUNABLE_PLAY_TEN_ROCKSTAR_VERIFIED_RACES_MISSIONS_OR_DEATHMATCHES", 4208, 1 },
	{ "XP_TUNABLE_WIN_TEN_RACES_OR_DEATHMATCHES_CREATED_BY_OTHER_PLAYERS", 4209, 1 },
	{ "XP_TUNABLE_PERFORMING_JOBS_WITH_OTHER_PLAYERS", 4210, 1 },
	{ "XP_TUNABLE_COMPLETE_FRIENDS_CREATION", 4211, 1 },
	{ "XP_TUNABLE_PLAY_YOUR_CREATIONS_AGAINST_OTHER_PLAYERS", 4212, 1 },
	{ "XP_TUNABLE_CREATE_ONE_OF_EACH_GAME_TYPE", 4213, 1 },
	{ "XP_TUNABLE_GET_A_THUMBS_UP_FOR_ONE_OF_YOUR_MISSIONS", 4214, 1 },
	{ "XP_TUNABLE_HAVE_ONE_OF_YOUR_CREATIONS_ROCKSTAR_VERIFIES", 4215, 1 },
	{ "XP_TUNABLE_LINK_YOUR_ACCOUNT_TO_THE_SOCIAL_CLUB", 4216, 1 },
	{ "XP_TUNABLE_ALL_RP_WHILE_PLAYING_IN_A_CREW", 4217, 1 },
	{ "XP_TUNABLE_ARMORED_TRUCK", 4218, 1 },
	{ "XP_TUNABLE_BOUNTIES_KILLER", 4219, 1 },
	{ "XP_TUNABLE_BOUNTIES_TARGET", 4220, 1 },
	{ "XP_TUNABLE_CRATE_DROP", 4221, 1 },
	{ "XP_TUNABLE_CRATE_DROP_ENEMY_KILLS", 4222, 1 },
	{ "XP_TUNABLE_GANG_ATTACK", 4223, 1 },
	{ "XP_TUNABLE_GANG_ATTACK_ENEMY_KILLS", 4224, 1 },
	{ "XP_TUNABLE_HOLD_UPS", 4225, 1 },
	{ "1145590141", 4226, 1 },
	{ "XP_TUNABLE_IMPORTEXPORT", 4227, 1 },
	{ "XP_TUNABLE_LESTER_NPC_TARGET", 4228, 1 },
	{ "XP_TUNABLE_MINIGAMES_ARM_WRESTLING", 4229, 1 },
	{ "XP_TUNABLE_MINIGAMES_GOLF", 4230, 1 },
	{ "XP_TUNABLE_MINIGAMES_ALL_GOLF_BONUSES", 4231, 1 },
	{ "XP_TUNABLE_MINIGAMES_SHOOTING_RANGE", 4232, 1 },
	{ "XP_TUNABLE_MINIGAMES_TENNIS_WIN", 4233, 1 },
	{ "XP_TUNABLE_MINIGAMES_TENNIS_TAKING_PART", 4234, 1 },
	{ "XP_TUNABLE_MINIGAMES_TENNIS_GAME", 4235, 1 },
	{ "XP_TUNABLE_MINIGAMES_TENNIS_SET", 4236, 1 },
	{ "XP_TUNABLE_MINIGAMES_TENNIS_RALLY", 4237, 1 },
	{ "XP_TUNABLE_RACE_TO_POINT", 4238, 1 },
	{ "XP_TUNABLE_ROCKSTAR_DEATHMATCH_KILL", 4239, 1 },
	{ "XP_TUNABLE_ROCKSTAR_DEATHMATCH_1ST_PLACE", 4240, 1 },
	{ "XP_TUNABLE_ROCKSTAR_DEATHMATCH_2ND_PLACE", 4241, 1 },
	{ "XP_TUNABLE_ROCKSTAR_DEATHMATCH_3RD_PLACE", 4242, 1 },
	{ "XP_TUNABLE_3_KILLS", 4243, 1 },
	{ "XP_TUNABLE_6_KILLS", 4244, 1 },
	{ "XP_TUNABLE_10_KILLS", 4245, 1 },
	{ "XP_TUNABLE_HEADSHOT", 4246, 1 },
	{ "XP_TUNABLE_END_KILLSTREAK", 4247, 1 },
	{ "XP_TUNABLE_REVENGE_KILLSTREAK", 4248, 1 },
	{ "XP_TUNABLE_KILL_POWER_PLAY_PLAYER", 4249, 1 },
	{ "XP_TUNABLE_PODIUM_FINISH", 4250, 1 },
	{ "XP_TUNABLE_WIN_WITHOUT_DYING", 4251, 1 },
	{ "XP_TUNABLE_ROCKSTAR_DM_POWER_PLAYS", 4252, 1 },
	{ "XP_TUNABLE_ROCKSTAR_DM_FINAL_KILL_BONUS", 4253, 1 },
	{ "XP_TUNABLE_ROCKSTAR_MISSIONS_BONUSES", 4254, 1 },
	{ "XP_TUNABLE_KILL_ALL_ENEMIES_ON_A_MISSION", 4255, 1 },
	{ "XP_TUNABLE_ONLY_KILL_ENEMIES_WITH_HEADSHOTS_INDIVIDUAL", 4256, 1 },
	{ "XP_TUNABLE_ONLY_KILL_ENEMIES_WITH_HEADSHOTS_TEAM", 4257, 1 },
	{ "XP_TUNABLE_NOT_LOSING_ANY_LIVES_BONUS", 4258, 1 },
	{ "XP_TUNABLE_DELIVER_A_PACKAGE_BONUS", 4259, 1 },
	{ "XP_TUNABLE_DIFFICULTY_BONUS", 4260, 1 },
	{ "XP_TUNABLE_LAST_TEAM_STANDING_WINNERS", 4261, 1 },
	{ "XP_TUNABLE_LAST_TEAM_STANDING_LOSERS", 4262, 1 },
	{ "XP_TUNABLE_LAST_TEAM_STANDING_SURVIVOR_BONUS", 4263, 1 },
	{ "XP_TUNABLE_ROCKSTAR_RACES_1ST_PLACE", 4264, 1 },
	{ "XP_TUNABLE_ROCKSTAR_RACES_2ND_PLACE", 4265, 1 },
	{ "XP_TUNABLE_ROCKSTAR_RACES_3RD_PLACE", 4266, 1 },
	{ "XP_TUNABLE_OVERTAKE_ANOTHER_PLAYER_5_TIMES", 4267, 1 },
	{ "XP_TUNABLE_OVERTAKE_ANOTHER_PLAYER_10_TIMES", 4268, 1 },
	{ "XP_TUNABLE_OVERTAKE_ANOTHER_PLAYER_15_TIMES", 4269, 1 },
	{ "XP_TUNABLE_SLIPSTREAM_FOR_5_SECONDS", 4270, 1 },
	{ "XP_TUNABLE_BE_IN_FIRST_PLACE_FOR_A_WHOLE_LAP", 4271, 1 },
	{ "XP_TUNABLE_GO_IN_TO_1ST_PLACE", 4272, 1 },
	{ "XP_TUNABLE_CLEAN_LAP", 4273, 1 },
	{ "XP_TUNABLE_FASTEST_LAP", 4274, 1 },
	{ "XP_TUNABLE_PERSONAL_BEST_LAP", 4275, 1 },
	{ "XP_TUNABLE_FLYING_UNDER_BRIDGES", 4276, 1 },
	{ "XP_TUNABLE_SURVIVAL_WAVE_REACHED", 4277, 1 },
	{ "XP_TUNABLE_SURVIVAL_ENEMY_KILL", 4278, 1 },
	{ "XP_TUNABLE_SURVIVAL_VEHICLE_DESTROYED", 4279, 1 },
	{ "XP_TUNABLE_AWARDS_BRONZE", 4280, 1 },
	{ "XP_TUNABLE_AWARDS_SILVER", 4281, 1 },
	{ "XP_TUNABLE_AWARDS_GOLD", 4282, 1 },
	{ "XP_TUNABLE_AWARDS_PLATINUM", 4283, 1 },
	{ "XP_TUNABLE_BUDDY_IN_CAR_RESPECT_1_BUDDY", 4284, 1 },
	{ "XP_TUNABLE_BUDDY_IN_CAR_RESPECT_2_BUDDIES", 4285, 1 },
	{ "XP_TUNABLE_BUDDY_IN_CAR_RESPECT_3_BUDDIES", 4286, 1 },
	{ "XP_TUNABLE_LOSE_WANTED_LEVEL_1_STAR", 4287, 1 },
	{ "XP_TUNABLE_LOSE_WANTED_LEVEL_2_STAR", 4288, 1 },
	{ "XP_TUNABLE_LOSE_WANTED_LEVEL_3_STAR", 4289, 1 },
	{ "XP_TUNABLE_LOSE_WANTED_LEVEL_4_STAR", 4290, 1 },
	{ "XP_TUNABLE_LOSE_WANTED_LEVEL_5_STAR", 4291, 1 },
	{ "XP_TUNABLE_TIME_WITH_5STAR_WANTED_LEVEL", 4292, 1 },
	{ "XP_TUNABLE_KILL_MUGGERS", 4293, 1 },
	{ "XP_TUNABLE_STUNT_JUMPS", 4294, 1 },
	{ "XP_TUNABLE_COLLECT_MISSION_PACKAGE", 4295, 0 },
	{ "XP_TUNABLE_VOTE_FOR_CONTENT", 4296, 0 },
	{ "XP_TUNABLE_CTF_CASH_REWARD", 4297, 0 },
	{ "XP_TUNABLE_CTF_XP_REWARD_MULTIPLIER", 4298, 1 },
	{ "XP_TUNABLE_KILL_CTF_PED", 4299, 0 },
	{ "XP_TUNABLE_DARTS_BULLSEYE", 4300, 1 },
	{ "XP_TUNABLE_DARTS_LEG_WON", 4301, 1 },
	{ "XP_TUNABLE_DARTS_TAKING_PART", 4302, 1 },
	{ "XP_TUNABLE_DARTS_MATCH_WIN", 4303, 1 },
	{ "XP_MODIFIER_BUDDY_IN_CAR", 4304, 0 },
	{ "XP_TUNABLE_KILLPLAYERMELEEATTACK", 4305, 1 },
	{ "XP_TUNABLE_RUNOVERUSINGVEHICLEDM", 4306, 1 },
	{ "XP_TUNABLE_KILL_2_WITHIN_10_SECONDSDM", 4307, 1 },
	{ "XP_TUNABLE_KILL_FIRST_30_SECONDSDM", 4308, 1 },
	{ "XP_TUNABLE_KILL_CLOSE_TO_DEATHDM", 4309, 1 },
	{ "XP_TUNABLE_LEAST_5_HEADSHOT_KILLSDM", 4310, 1 },
	{ "XP_TUNABLE_FINISH_MORE_KILLS_NO_HEALTH_PACKSDM", 4311, 1 },
	{ "XP_TUNABLE_FINISH_WITH_A_KD_RATIO_OF_AT_LEAST_2DM", 4312, 1 },
	{ "XP_TUNABLE_WIN_USING_ONLY_PISTOLDM", 4313, 1 },
	{ "XP_TUNABLE_FINISH_TOP_3DM", 4314, 1 },
	{ "XP_TUNABLE_GET_A_KILL_STREAKVDM", 4315, 1 },
	{ "XP_TUNABLE_KILL_TWO_ENEMIES_WITHIN_10SEC_OF_EACH_OTHERVDM", 4316, 1 },
	{ "XP_TUNABLE_KILL_ENEMY_WITHIN_THE_60_SECONDSVDM", 4317, 1 },
	{ "XP_TUNABLE_KILLENEMY_WHILE_YOUR_VEHICLE_IS_ON_FIREVDM", 4318, 1 },
	{ "XP_TUNABLE_RECOVER_FROM_DEATHSTREAK_FINISH_WITH_MORE_KILLS_THAN_DEATHSVDM", 4319, 1 },
	{ "XP_TUNABLE_KILLPLAYERWHENDEADVDM", 4320, 1 },
	{ "XP_TUNABLE_FINISHMOREKILLSTHANDEATHSVDM", 4321, 1 },
	{ "XP_TUNABLE_GETFIRSTKILLVDM", 4322, 1 },
	{ "XP_TUNABLE_KILLPOWERPLAYERVDM", 4323, 1 },
	{ "XP_TUNABLE_FINISHVDMINTOP3VDM", 4324, 1 },
	{ "DLC_MALE_BEARDS_CURLY", 4326, 0 },
	{ "DLC_MALE_BEARDS_CURLY_DEEP_STRANGER", 4327, 0 },
	{ "DLC_MALE_BEARDS_HANDLEBAR", 4328, 0 },
	{ "DLC_MALE_BEARDS_FAUSTIC", 4329, 0 },
	{ "DLC_MALE_BEARDS_OTTO_PATCH", 4330, 0 },
	{ "DLC_MALE_BEARDS_OTTO_FULL_STRANGER", 4331, 0 },
	{ "DLC_MALE_BEARDS_LIGHT_FRANZ", 4332, 0 },
	{ "DLC_MALE_BEARDS_LINCOLN_CURTAIN", 4333, 0 },
	{ "DLC_MALE_BEARDS_HAMPSTEAD", 4334, 0 },
	{ "DLC_MALE_BEARDS_AMBROSE", 4335, 0 },
	{ "WEAPONADDON_PISTOL_FLSH_EXPENDITURE_TUNABLE", 4336, 1 },
	{ "WEAPONADDON_PISTOL_SUPP_EXPENDITURE_TUNABLE", 4337, 1 },
	{ "WEAPONADDON_COMBATPISTOL_FLSH_EXPENDITURE_TUNABLE", 4338, 1 },
	{ "WEAPONADDON_COMBATPISTOL_SUPP_EXPENDITURE_TUNABLE", 4339, 1 },
	{ "WEAPONADDON_APPISTOL_FLSH_EXPENDITURE_TUNABLE", 4340, 1 },
	{ "WEAPONADDON_APPISTOL_SUPP_EXPENDITURE_TUNABLE", 4341, 1 },
	{ "WEAPONADDON_DLCPISTOL50_FLSH_EXPENDITURE_TUNABLE", 4342, 1 },
	{ "WEAPONADDON_DLCPISTOL50_SUPP_EXPENDITURE_TUNABLE", 4343, 1 },
	{ "WEAPONADDON_MICROSMG_FLSH_EXPENDITURE_TUNABLE", 4344, 1 },
	{ "WEAPONADDON_MICROSMG_SUPP_EXPENDITURE_TUNABLE", 4345, 1 },
	{ "WEAPONADDON_MICROSMG_SCOPE_EXPENDITURE_TUNABLE", 4346, 1 },
	{ "WEAPONADDON_SMG_FLSH_EXPENDITURE_TUNABLE", 4347, 1 },
	{ "WEAPONADDON_SMG_SUPP_EXPENDITURE_TUNABLE", 4348, 1 },
	{ "WEAPONADDON_SMG_SCOPE_EXPENDITURE_TUNABLE", 4349, 1 },
	{ "WEAPONADDON_ASSSMG_FLSH_EXPENDITURE_TUNABLE", 4350, 1 },
	{ "WEAPONADDON_ASSSMG_SUPP_EXPENDITURE_TUNABLE", 4351, 1 },
	{ "WEAPONADDON_ASSSMG_SCOPE_EXPENDITURE_TUNABLE", 4353, 1 },
	{ "WEAPONADDON_ASSRIFLE_FLSH_EXPENDITURE_TUNABLE", 4354, 1 },
	{ "WEAPONADDON_ASSRIFLE_SUPP_EXPENDITURE_TUNABLE", 4355, 1 },
	{ "WEAPONADDON_ASSRIFLE_SCOPE_EXPENDITURE_TUNABLE", 4356, 1 },
	{ "WEAPONADDON_ASSRIFLE_GRIP_EXPENDITURE_TUNABLE", 4357, 1 },
	{ "WEAPONADDON_DLCHEAVYRIFLE_FLSH_EXPENDITURE_TUNABLE", 4358, 1 },
	{ "WEAPONADDON_DLCHEAVYRIFLE_SUPP_EXPENDITURE_TUNABLE", 4359, 1 },
	{ "WEAPONADDON_DLCHEAVYRIFLE_SCOPE_EXPENDITURE_TUNABLE", 4360, 1 },
	{ "WEAPONADDON_DLCHEAVYRIFLE_GRIP_EXPENDITURE_TUNABLE", 4361, 1 },
	{ "WEAPONADDON_CARBINERRIFLE_FLSH_EXPENDITURE_TUNABLE", 4362, 1 },
	{ "WEAPONADDON_CARBINERRIFLE_SUPP_EXPENDITURE_TUNABLE", 4363, 1 },
	{ "WEAPONADDON_CARBINERRIFLE_SCOPE_EXPENDITURE_TUNABLE", 4364, 1 },
	{ "WEAPONADDON_CARBINERRIFLE_GRIP_EXPENDITURE_TUNABLE", 4365, 1 },
	{ "WEAPONADDON_CARBINERRIFLE_RAILCOVER_EXPENDITURE_TUNABLE", 4366, 1 },
	{ "WEAPONADDON_ADVANCEDRIFLE_FLSH_EXPENDITURE_TUNABLE", 4367, 1 },
	{ "WEAPONADDON_ADVANCEDRIFLE_SUPP_EXPENDITURE_TUNABLE", 4368, 1 },
	{ "WEAPONADDON_ADVANCEDRIFLE_SCOPE_EXPENDITURE_TUNABLE", 4369, 1 },
	{ "WEAPONADDON_MACHINEGUN_SCOPE_EXPENDITURE_TUNABLE", 4370, 1 },
	{ "WEAPONADDON_COMBATMG_FLSH_EXPENDITURE_TUNABLE", 4372, 1 },
	{ "WEAPONADDON_COMBATMG_SUPP_EXPENDITURE_TUNABLE", 4373, 1 },
	{ "WEAPONADDON_PUMPSHOTGUN_FLSH_EXPENDITURE_TUNABLE", 4374, 1 },
	{ "WEAPONADDON_PUMPSHOTGUN_SUPP_EXPENDITURE_TUNABLE", 4375, 1 },
	{ "WEAPONADDON_BULLPUPSHOTGUN_FLSH_EXPENDITURE_TUNABLE", 4376, 1 },
	{ "WEAPONADDON_BULLPUPSHOTGUN_SUPP_EXPENDITURE_TUNABLE", 4377, 1 },
	{ "WEAPONADDON_ASSHOTGUN_GRIP_EXPENDITURE_TUNABLE", 4378, 1 },
	{ "WEAPONADDON_ASSHOTGUN_FLSH_EXPENDITURE_TUNABLE", 4379, 1 },
	{ "WEAPONADDON_ASSHOTGUN_SUPP_EXPENDITURE_TUNABLE", 4380, 1 },
	{ "WEAPONADDON_SNIPER_SCOPE1_EXPENDITURE_TUNABLE", 4381, 1 },
	{ "WEAPONADDON_SNIPER_SCOPE2_EXPENDITURE_TUNABLE", 4382, 1 },
	{ "WEAPONADDON_SNIPER_SUPP_EXPENDITURE_TUNABLE", 4383, 1 },
	{ "WEAPONADDON_HEAVYSNIPER_SCOPE1_EXPENDITURE_TUNABLE", 4384, 1 },
	{ "WEAPONADDON_HEAVYSNIPER_SCOPE2_EXPENDITURE_TUNABLE", 4385, 1 },
	{ "WEAPONADDON_HEAVYSNIPER_SUPP_EXPENDITURE_TUNABLE", 4386, 1 },
	{ "WEAPONADDON_DLCASSSNIPER_SCOPE1_EXPENDITURE_TUNABLE", 4387, 1 },
	{ "WEAPONADDON_DLCASSSNIPER_SCOPE2_EXPENDITURE_TUNABLE", 4388, 1 },
	{ "WEAPONADDON_DLCASSSNIPER_SUPP_EXPENDITURE_TUNABLE", 4389, 1 },
	{ "WEAPONADDON_GRENADELAUNCHER_FLSH_EXPENDITURE_TUNABLE", 4390, 1 },
	{ "WEAPONADDON_GRENADELAUNCHER_SCOPE_EXPENDITURE_TUNABLE", 4391, 1 },
	{ "WEAPONADDON_COMBATMG_GRIP_EXPENDITURE_TUNABLE", 4392, 1 },
	{ "WEAPONADDON_COMBATMG_SCOPE_EXPENDITURE_TUNABLE", 4393, 1 },
	{ "WEAPONADDON_GRENADELAUNCHER_GRIP_EXPENDITURE_TUNABLE", 4394, 1 },
	{ "PLAYERKIT_RED_WEAPON_EXPENDITURE_TUNABLE", 4395, 1 },
	{ "PLAYERKIT_TAN_WEAPON_EXPENDITURE_TUNABLE", 4396, 1 },
	{ "PLAYERKIT_BLUE_WEAPON_EXPENDITURE_TUNABLE", 4397, 1 },
	{ "PLAYERKIT_PLATINUM_WEAPON_EXPENDITURE_TUNABLE", 4398, 1 },
	{ "PLAYERKIT_GREEN_WEAPON_EXPENDITURE_TUNABLE", 4399, 1 },
	{ "PLAYERKIT_PINK_WEAPON_EXPENDITURE_TUNABLE", 4400, 1 },
	{ "PLAYERKIT_GOLD_WEAPON_EXPENDITURE_TUNABLE", 4401, 1 },
	{ "ENTRANCE_FEE_CAR_RACE_EXPENDITURE_TUNABLE", 4434, 0 },
	{ "ENTRANCE_FEE_AIR_RACE_EXPENDITURE_TUNABLE", 4435, 0 },
	{ "ENTRANCE_FEE_SEA_RACE_EXPENDITURE_TUNABLE", 4436, 0 },
	{ "ENTRANCE_FEE_BIKE_RACE_EXPENDITURE_TUNABLE", 4437, 0 },
	{ "ENTRANCE_FEE_SURVIVAL_EXPENDITURE_TUNABLE", 4438, 0 },
	{ "ENTRANCE_FEE_DEATHMATCH_EXPENDITURE_TUNABLE", 4439, 0 },
	{ "ENTRANCE_FEE_PARACHUTING_EXPENDITURE_TUNABLE", 4440, 0 },
	{ "ENTRANCE_FEE_LTS_EXPENDITURE_TUNABLE", 4441, 0 },
	{ "ENTRANCE_FEE_CTF_EXPENDITURE_TUNABLE", 4442, 0 },
	{ "ENTRANCE_FEE_VERSUS_EXPENDITURE_TUNABLE", 4443, 0 },
	{ "CASH_MODIFIER_CRATE_DROP_GANG_ATTACK", 4445, 0 },
	{ "TIMESCALE_RACE_MINUTES_UNDER_1", 4446, 0 },
	{ "TIMESCALE_RACE_UNDER_1MIN_CASH_MOD_PERCENT", 4447, 0 },
	{ "TIMESCALE_RACE_MINUTES_UNDER_2", 4448, 0 },
	{ "TIMESCALE_RACE_UNDER_2MIN_CASH_MOD_PERCENT", 4449, 0 },
	{ "TIMESCALE_RACE_MINUTES_UNDER_3", 4450, 0 },
	{ "TIMESCALE_RACE_UNDER_3MIN_CASH_MOD_PERCENT", 4451, 0 },
	{ "TIMESCALE_RACE_MINUTES_UNDER_4", 4452, 0 },
	{ "TIMESCALE_RACE_UNDER_4MIN_CASH_MOD_PERCENT", 4453, 0 },
	{ "TIMESCALE_DM_MINUTES_UNDER_1", 4454, 0 },
	{ "TIMESCALE_DM_UNDER_1MIN_CASH_MOD_PERCENT", 4455, 0 },
	{ "TIMESCALE_DM_MINUTES_UNDER_2", 4456, 0 },
	{ "TIMESCALE_DM_UNDER_2MIN_CASH_MOD_PERCENT", 4457, 0 },
	{ "TIMESCALE_DM_MINUTES_UNDER_3", 4458, 0 },
	{ "TIMESCALE_DM_UNDER_3MIN_CASH_MOD_PERCENT", 4459, 0 },
	{ "TIMESCALE_DM_MINUTES_UNDER_4", 4460, 0 },
	{ "TIMESCALE_DM_UNDER_4MIN_CASH_MOD_PERCENT", 4461, 0 },
	{ "RACE_PLAYER_MULTIPLIER", 4631, 0 },
	{ "RACE_BASIC", 4632, 0 },
	{ "RACE_MAX_PLAYERS", 4633, 0 },
	{ "RACE_MAX_JOB_DECIDER", 4634, 0 },
	{ "RACE_RANK_CAP", 4635, 0 },
	{ "RACE_RANK_DIVIDER", 4636, 0 },
	{ "RACE_END_MULTIPLIER", 4637, 1 },
	{ "DM_PLAYER_MULTIPLIER", 4638, 0 },
	{ "DM_BASIC", 4639, 0 },
	{ "DM_MAX_PLAYERS", 4640, 0 },
	{ "DM_MAX_JOB_DECIDER", 4641, 0 },
	{ "DM_RANK_CAP", 4642, 0 },
	{ "DM_RANK_DIVIDER", 4643, 0 },
	{ "DM_END_MULTIPLIER", 4644, 1 },
	{ "PARACHUTING_PLAYER_MULTIPLIER", 4645, 0 },
	{ "PARACHUTING_BASIC", 4646, 0 },
	{ "PARACHUTING_MAX_PLAYERS", 4647, 0 },
	{ "PARACHUTING_MAX_JOB_DECIDER", 4648, 0 },
	{ "PARACHUTING_RANK_CAP", 4649, 0 },
	{ "PARACHUTING_RANK_DIVIDER", 4650, 0 },
	{ "PARACHUTING_END_MULTIPLIER", 4651, 1 },
	{ "LTS_PLAYER_MULTIPLIER", 4652, 0 },
	{ "LTS_BASIC", 4653, 0 },
	{ "LTS_MAX_PLAYERS", 4654, 0 },
	{ "LTS_MAX_JOB_DECIDER", 4655, 0 },
	{ "LTS_RANK_CAP", 4656, 0 },
	{ "LTS_RANK_DIVIDER", 4657, 0 },
	{ "LTS_END_MULTIPLIER", 4658, 1 },
	{ "RACE_RP_PLAYER_MULTIPLIER", 4659, 0 },
	{ "RACE_RP_BASIC", 4660, 0 },
	{ "RACE_RP_MIN_PLAYERS", 4661, 0 },
	{ "RACE_RP_MAX_PLAYERS", 4662, 0 },
	{ "RACE_RP_MAX_JOB_DECIDER", 4663, 0 },
	{ "RACE_RP_RANK_CAP", 4664, 0 },
	{ "RACE_RP_RANK_DIVIDER", 4665, 0 },
	{ "RACE_RP_END_DIVIDER", 4666, 1 },
	{ "DM_RP_PLAYER_MULTIPLIER", 4667, 0 },
	{ "DM_RP_BASIC", 4668, 0 },
	{ "DM_RP_MIN_PLAYERS", 4669, 0 },
	{ "DM_RP_MAX_PLAYERS", 4670, 0 },
	{ "DM_RP_MAX_JOB_DECIDER", 4671, 0 },
	{ "DM_RP_RANK_CAP", 4672, 0 },
	{ "DM_RP_RANK_DIVIDER", 4673, 0 },
	{ "DM_RP_END_DIVIDER", 4674, 1 },
	{ "PARACHUTING_RP_PLAYER_MULTIPLIER", 4675, 0 },
	{ "PARACHUTING_RP_BASIC", 4676, 0 },
	{ "PARACHUTING_RP_MIN_PLAYERS", 4677, 0 },
	{ "PARACHUTING_RP_MAX_PLAYERS", 4678, 0 },
	{ "PARACHUTING_RP_MAX_JOB_DECIDER", 4679, 0 },
	{ "PARACHUTING_RP_RANK_CAP", 4680, 0 },
	{ "PARACHUTING_RP_RANK_DIVIDER", 4681, 0 },
	{ "PARACHUTING_RP_END_DIVIDER", 4682, 1 },
	{ "PARACHUTING_RP_POINT_CAP", 4683, 0 },
	{ "PARACHUTING_RP_POINT_MULTIPLIER", 4684, 0 },
	{ "LTS_RP_PLAYER_MULTIPLIER", 4685, 0 },
	{ "LTS_RP_BASIC", 4686, 0 },
	{ "LTS_RP_MIN_PLAYERS", 4687, 0 },
	{ "LTS_RP_MAX_PLAYERS", 4688, 0 },
	{ "LTS_RP_MAX_JOB_DECIDER", 4689, 0 },
	{ "LTS_RP_RANK_CAP", 4690, 0 },
	{ "LTS_RP_RANK_DIVIDER", 4691, 0 },
	{ "LTS_RP_END_DIVIDER", 4692, 1 },
	{ "RACE_RP_TIME_PERIOD_MODIFIER_1", 4693, 0 },
	{ "RACE_PERCENTAGE_RP_REWARD_MODIFIER_1", 4694, 0 },
	{ "RACE_RP_TIME_PERIOD_MODIFIER_2", 4695, 0 },
	{ "RACE_PERCENTAGE_RP_REWARD_MODIFIER_2", 4696, 0 },
	{ "RACE_RP_TIME_PERIOD_MODIFIER_3", 4697, 0 },
	{ "RACE_PERCENTAGE_RP_REWARD_MODIFIER_3", 4698, 0 },
	{ "RACE_RP_TIME_PERIOD_MODIFIER_4", 4699, 0 },
	{ "RACE_PERCENTAGE_RP_REWARD_MODIFIER_4", 4700, 0 },
	{ "DM_RP_TIME_PERIOD_MODIFIER_1", 4701, 0 },
	{ "DM_PERCENTAGE_RP_REWARD_MODIFIER_1", 4702, 0 },
	{ "DM_RP_TIME_PERIOD_MODIFIER_2", 4703, 0 },
	{ "DM_PERCENTAGE_RP_REWARD_MODIFIER_2", 4704, 0 },
	{ "DM_RP_TIME_PERIOD_MODIFIER_3", 4705, 0 },
	{ "DM_PERCENTAGE_RP_REWARD_MODIFIER_3", 4706, 0 },
	{ "DM_RP_TIME_PERIOD_MODIFIER_4", 4707, 0 },
	{ "DM_PERCENTAGE_RP_REWARD_MODIFIER_4", 4708, 0 },
	{ "LTS_RP_TIME_PERIOD_MODIFIER_1", 4709, 0 },
	{ "LTS_PERCENTAGE_RP_REWARD_MODIFIER_1", 4710, 0 },
	{ "LTS_RP_TIME_PERIOD_MODIFIER_2", 4711, 0 },
	{ "LTS_PERCENTAGE_RP_REWARD_MODIFIER_2", 4712, 0 },
	{ "LTS_RP_TIME_PERIOD_MODIFIER_3", 4713, 0 },
	{ "LTS_PERCENTAGE_RP_REWARD_MODIFIER_3", 4714, 0 },
	{ "LTS_RP_TIME_PERIOD_MODIFIER_4", 4715, 0 },
	{ "LTS_PERCENTAGE_RP_REWARD_MODIFIER_4", 4716, 0 },
	{ "PARACHUTING_RP_TIME_PERIOD_MODIFIER_1", 4717, 0 },
	{ "PARACHUTING_PERCENTAGE_RP_REWARD_MODIFIER_1", 4718, 0 },
	{ "PARACHUTING_RP_TIME_PERIOD_MODIFIER_2", 4719, 0 },
	{ "PARACHUTING_PERCENTAGE_RP_REWARD_MODIFIER_2", 4720, 0 },
	{ "PARACHUTING_RP_TIME_PERIOD_MODIFIER_3", 4721, 0 },
	{ "PARACHUTING_PERCENTAGE_RP_REWARD_MODIFIER_3", 4722, 0 },
	{ "PARACHUTING_RP_TIME_PERIOD_MODIFIER_4", 4723, 0 },
	{ "PARACHUTING_PERCENTAGE_RP_REWARD_MODIFIER_4", 4724, 0 },
	{ "LTS_TIME_PERIOD_CASH_REWARD_MODIFIER_1", 4725, 0 },
	{ "LTS_PERCENTAGE_CASH_REWARD_MODIFIER_1", 4726, 0 },
	{ "LTS_TIME_PERIOD_CASH_REWARD_MODIFIER_2", 4727, 0 },
	{ "LTS_PERCENTAGE_CASH_REWARD_MODIFIER_2", 4728, 0 },
	{ "LTS_TIME_PERIOD_CASH_REWARD_MODIFIER_3", 4729, 0 },
	{ "LTS_PERCENTAGE_CASH_REWARD_MODIFIER_3", 4730, 0 },
	{ "LTS_TIME_PERIOD_CASH_REWARD_MODIFIER_4", 4731, 0 },
	{ "LTS_PERCENTAGE_CASH_REWARD_MODIFIER_4", 4732, 0 },
	{ "PARACHUTING_TIME_PERIOD_CASH_REWARD_MODIFIER_1", 4733, 0 },
	{ "PARACHUTING_PERCENTAGE_CASH_REWARD_MODIFIER_1", 4734, 0 },
	{ "PARACHUTING_TIME_PERIOD_CASH_REWARD_MODIFIER_2", 4735, 0 },
	{ "PARACHUTING_PERCENTAGE_CASH_REWARD_MODIFIER_2", 4736, 0 },
	{ "PARACHUTING_TIME_PERIOD_CASH_REWARD_MODIFIER_3", 4737, 0 },
	{ "PARACHUTING_PERCENTAGE_CASH_REWARD_MODIFIER_3", 4738, 0 },
	{ "PARACHUTING_TIME_PERIOD_CASH_REWARD_MODIFIER_4", 4739, 0 },
	{ "PARACHUTING_PERCENTAGE_CASH_REWARD_MODIFIER_4", 4740, 0 },
	{ "DELAY_LOADING_PLAYLIST", 4741, 0 },
	{ "TIMEOUT_GEN_CLONE_PEDS", 4742, 0 },
	{ "TIMEOUT_GEN_QUICK_MATCH_STUCK", 4743, 0 },
	{ "ON_CALL_TIMEOUT_MISSION_STAGE_1", 4748, 0 },
	{ "ON_CALL_TIMEOUT_DEATHMATCH_STAGE_1", 4749, 0 },
	{ "ON_CALL_TIMEOUT_RACE_STAGE_1", 4750, 0 },
	{ "ON_CALL_TIMEOUT_SURVIVAL_STAGE_1", 4751, 0 },
	{ "ON_CALL_TIMEOUT_CTF_STAGE_1", 4752, 0 },
	{ "ON_CALL_TIMEOUT_LTS_STAGE_1", 4753, 0 },
	{ "ON_CALL_TIMEOUT_BASEJUMP_STAGE_1", 4755, 0 },
	{ "ON_CALL_TIMEOUT_CONTACT_STAGE_1", 4756, 0 },
	{ "ON_CALL_TIMEOUT_VS_STAGE_1", 4757, 0 },
	{ "ON_CALL_TIMEOUT_PLAYLIST_STAGE_1", 4758, 0 },
	{ "ON_CALL_TIMEOUT_GOLF_STAGE_1", 4759, 0 },
	{ "ON_CALL_TIMEOUT_MISSION_STAGE_2", 4760, 0 },
	{ "ON_CALL_TIMEOUT_DEATHMATCH_STAGE_2", 4761, 0 },
	{ "ON_CALL_TIMEOUT_RACE_STAGE_2", 4762, 0 },
	{ "ON_CALL_TIMEOUT_SURVIVAL_STAGE_2", 4763, 0 },
	{ "ON_CALL_TIMEOUT_CTF_STAGE_2", 4764, 0 },
	{ "ON_CALL_TIMEOUT_LTS_STAGE_2", 4765, 0 },
	{ "ON_CALL_TIMEOUT_BASEJUMP_STAGE_2", 4767, 0 },
	{ "ON_CALL_TIMEOUT_CONTACT_STAGE_2", 4768, 0 },
	{ "ON_CALL_TIMEOUT_VS_STAGE_2", 4769, 0 },
	{ "ON_CALL_TIMEOUT_PLAYLIST_STAGE_2", 4770, 0 },
	{ "ON_CALL_TIMEOUT_GOLF_STAGE_2", 4771, 0 },
	{ "ON_CALL_TIMEOUT_MISSION_STAGE_3", 4772, 0 },
	{ "ON_CALL_TIMEOUT_DEATHMATCH_STAGE_3", 4773, 0 },
	{ "ON_CALL_TIMEOUT_RACE_STAGE_3", 4774, 0 },
	{ "ON_CALL_TIMEOUT_SURVIVAL_STAGE_3", 4775, 0 },
	{ "ON_CALL_TIMEOUT_CTF_STAGE_3", 4776, 0 },
	{ "ON_CALL_TIMEOUT_LTS_STAGE_3", 4777, 0 },
	{ "ON_CALL_TIMEOUT_BASEJUMP_STAGE_3", 4779, 0 },
	{ "ON_CALL_TIMEOUT_CONTACT_STAGE_3", 4780, 0 },
	{ "ON_CALL_TIMEOUT_VS_STAGE_3", 4781, 0 },
	{ "ON_CALL_TIMEOUT_PLAYLIST_STAGE_3", 4782, 0 },
	{ "ON_CALL_TIMEOUT_GOLF_STAGE_3", 4783, 0 },
	{ "ON_CALL_RATIO_MISSION_STAGE_1", 4784, 1 },
	{ "ON_CALL_RATIO_DEATHMATCH_STAGE_1", 4785, 1 },
	{ "ON_CALL_RATIO_RACE_STAGE_1", 4786, 1 },
	{ "ON_CALL_RATIO_SURVIVAL_STAGE_1", 4787, 1 },
	{ "ON_CALL_RATIO_CTF_STAGE_1", 4788, 1 },
	{ "ON_CALL_RATIO_LTS_STAGE_1", 4789, 1 },
	{ "ON_CALL_RATIO_BASEJUMP_STAGE_1", 4791, 1 },
	{ "ON_CALL_RATIO_CONTACT_STAGE_1", 4792, 1 },
	{ "ON_CALL_RATIO_VS_STAGE_1", 4793, 1 },
	{ "ON_CALL_RATIO_PLAYLIST_STAGE_1", 4794, 1 },
	{ "ON_CALL_RATIO_GOLF_STAGE_1", 4795, 1 },
	{ "ON_CALL_RATIO_MISSION_STAGE_2", 4796, 1 },
	{ "ON_CALL_RATIO_DEATHMATCH_STAGE_2", 4797, 1 },
	{ "ON_CALL_RATIO_RACE_STAGE_2", 4798, 1 },
	{ "ON_CALL_RATIO_SURVIVAL_STAGE_2", 4799, 1 },
	{ "ON_CALL_RATIO_CTF_STAGE_2", 4800, 1 },
	{ "ON_CALL_RATIO_LTS_STAGE_2", 4801, 1 },
	{ "ON_CALL_RATIO_BASEJUMP_STAGE_2", 4803, 1 },
	{ "ON_CALL_RATIO_CONTACT_STAGE_2", 4804, 1 },
	{ "ON_CALL_RATIO_VS_STAGE_2", 4805, 1 },
	{ "ON_CALL_RATIO_PLAYLIST_STAGE_2", 4806, 1 },
	{ "ON_CALL_RATIO_GOLF_STAGE_2", 4807, 1 },
	{ "ON_CALL_RATIO_MISSION_STAGE_3", 4808, 1 },
	{ "ON_CALL_RATIO_DEATHMATCH_STAGE_3", 4809, 1 },
	{ "ON_CALL_RATIO_RACE_STAGE_3", 4810, 1 },
	{ "ON_CALL_RATIO_SURVIVAL_STAGE_3", 4811, 1 },
	{ "ON_CALL_RATIO_CTF_STAGE_3", 4812, 1 },
	{ "ON_CALL_RATIO_LTS_STAGE_3", 4813, 1 },
	{ "ON_CALL_RATIO_BASEJUMP_STAGE_3", 4815, 1 },
	{ "ON_CALL_RATIO_CONTACT_STAGE_3", 4816, 1 },
	{ "ON_CALL_RATIO_VS_STAGE_3", 4817, 1 },
	{ "ON_CALL_RATIO_PLAYLIST_STAGE_3", 4818, 1 },
	{ "ON_CALL_RATIO_GOLF_STAGE_3", 4819, 1 },
	{ "ON_CALL_RATIO_MISSION_STAGE_4", 4820, 1 },
	{ "ON_CALL_RATIO_DEATHMATCH_STAGE_4", 4821, 1 },
	{ "ON_CALL_RATIO_RACE_STAGE_4", 4822, 1 },
	{ "ON_CALL_RATIO_SURVIVAL_STAGE_4", 4823, 1 },
	{ "ON_CALL_RATIO_CTF_STAGE_4", 4824, 1 },
	{ "ON_CALL_RATIO_LTS_STAGE_4", 4825, 1 },
	{ "ON_CALL_RATIO_BASEJUMP_STAGE_4", 4827, 1 },
	{ "ON_CALL_RATIO_CONTACT_STAGE_4", 4828, 1 },
	{ "ON_CALL_RATIO_VS_STAGE_4", 4829, 1 },
	{ "ON_CALL_RATIO_PLAYLIST_STAGE_4", 4830, 1 },
	{ "ON_CALL_RATIO_GOLF_STAGE_4", 4831, 1 },
	{ "TIMEOUT_GEN_ON_CALL_START", 4832, 0 },
	{ "TIMEOUT_ON_CALL_RATIO", 4833, 1 },
	{ "ON_CALL_MAX_QUICKMATCH_ATTEMPTS", 4834, 0 },
	{ "NJVS_SYNC_WINDOW", 4835, 0 },
	{ "ON_CALL_TIMEOUT_HOSTING", 4836, 0 },
	{ "ON_CALL_DISABLE_TIMEOUT_HOSTING", 4838, 2 },
	{ "ON_CALL_MAX_VALIDATE_JOB_RATING", 4839, 0 },
	{ "ON_CALL_RAND_HOST_CHANCE", 4840, 0 },
	{ "ON_CALL_JOB_RATING_THRESHOLD", 4841, 0 },
	{ "MAX_PLAYERS_ON_CALL", 4842, 0 },
	{ "ON_CALL_DISABLED", 4843, 2 },
	{ "ON_CALL_MINI_DISABLED", 4865, 2 },
	{ "RANDOM_BOOT_DISABLED", 4866, 2 },
	{ "HOSPITAL_BILL_MULTIPLIER", 4872, 1 },
	{ "CASH_DROP_MULTIPLIER", 4873, 1 },
	{ "WANTED_LEVEL_BAIL_MULTIPLIER", 4874, 1 },
	{ "OVERWRITE_CLOUD_VS_MISSION_AWARDS", 4875, 2 },
	{ "BODHI2_EXPENDITURE_MODIFIER", 4876, 0 },
	{ "DUNE_EXPENDITURE_MODIFIER", 4877, 0 },
	{ "REBEL_EXPENDITURE_MODIFIER", 4878, 0 },
	{ "SADLER_EXPENDITURE_MODIFIER", 4879, 0 },
	{ "SANCHEZ2_EXPENDITURE_MODIFIER", 4880, 0 },
	{ "SANDKING2_EXPENDITURE_MODIFIER", 4881, 0 },
	{ "RANK_RESTRICTION_CRATE_DROP", 4882, 2 },
	{ "PLAYER_RESTRICTION_CRATE_DROP", 4883, 0 },
	{ "CRATE_DROP_DISABLE_WEAPON_CHECK", 4884, 2 },
	{ "LOCAL_PLAYER_AUTOMUTE_TALKER_LIMIT", 4886, 0 },
	{ "TURN_SNOW_ON_OFF", 4887, 2 },
	{ "TURN_SNAPMATIC_ON_OFF", 4888, 2 },
	{ "BAD_SPORT_QUITTING_PLAYLIST", 4889, 1 },
	{ "BAD_SPORT_QUITTING_EVENT_PLAYLIST", 4890, 1 },
	{ "ELO_BANDING_SPACING", 4891, 0 },
	{ "DISABLE_QUICK_JOB_WITH_FRIENDS", 4892, 2 },
	{ "DISABLE_NJVS_QM", 4893, 2 },
	{ "MAX_CASH_WAGER_FOR_HEAD_TO_HEAD", 4896, 0 },
	{ "MAX_CASH_WAGER_FOR_CREW_CHALLENGES", 4897, 0 },
	{ "TOGGLE_XMAS_CONTENT", 4898, 2 },
	{ "TOGGLE_CREATORS_OFF", 4899, 2 },
	{ "TOGGLE_HEAD_TO_HEAD_OFF", 4900, 2 },
	{ "RP_REWARD_PER_LIKE", 4903, 0 },
	{ "RP_REWARD_LIKE_CAP", 4904, 0 },
	{ "Purchased_car_sale_depreciation", 4905, 1 },
	{ "Purchased_car_mod_sale_discount", 4906, 1 },
	{ "Purchased_car_sale_max_cap", 4907, 0 },
	{ "FM_CORONA_PLAYLIST_CORONA_PLAYLIST_START", 5373, 0 },
	{ "COLLISION_OFF_IN_PREMIUM_RACES", 5405, 2 },
	{ "Discount_male_special_Suit_Vest_Pale_Blue_Vest", 5407, 0 },
	{ "Discount_male_special_Suit_Vest_Olive_Vest", 5408, 0 },
	{ "Discount_male_special_Suit_Vest_Purple_Vest", 5409, 0 },
	{ "Discount_male_special_Suit_Vest_Lobster_Vest", 5410, 0 },
	{ "Discount_male_special_Suit_Vest_Subtle_Blue_Vest", 5411, 0 },
	{ "Discount_male_special_Suit_Vest_Brown_Vest", 5412, 0 },
	{ "Discount_male_special_Suit_Vest_Beige_Plaid_Vest", 5413, 0 },
	{ "Discount_male_special_Suit_Vest_Off_White_Vest", 5414, 0 },
	{ "Discount_male_special_Suit_Vest_Ash_Vest", 5415, 0 },
	{ "Discount_male_special_Suit_Vest_Navy_Plaid_Vest", 5416, 0 },
	{ "Discount_male_special_Suit_Vest_Ash_Plaid_Vest", 5417, 0 },
	{ "Discount_male_special_Suit_Vest_Blue_Plaid_Vest", 5418, 0 },
	{ "Discount_male_special_Suit_Vest_White_Vest", 5419, 0 },
	{ "Discount_male_accessories_Blue_Tie", 5420, 0 },
	{ "Discount_male_accessories_Navy_Tie", 5421, 0 },
	{ "Discount_male_accessories_Red_Tie", 5422, 0 },
	{ "Discount_male_accessories_Green_Tie", 5423, 0 },
	{ "Discount_male_accessories_Orange_Tie", 5424, 0 },
	{ "Discount_male_accessories_Yellow_Tie", 5425, 0 },
	{ "Discount_male_accessories_Purple_Tie", 5426, 0 },
	{ "Discount_male_accessories_Brown_Tie", 5427, 0 },
	{ "Discount_male_accessories_Stone_Tie", 5428, 0 },
	{ "Discount_male_accessories_Two_Tone_Plaid_Tie", 5429, 0 },
	{ "Discount_male_accessories_Tan_Plaid_Tie", 5430, 0 },
	{ "Discount_male_accessories_Gold_Striped_Tie", 5431, 0 },
	{ "Discount_male_accessories_Red_Striped_Tie", 5432, 0 },
	{ "Discount_male_accessories_White_BowTie", 5433, 0 },
	{ "Discount_male_accessories_Gray_BowTie", 5434, 0 },
	{ "Discount_male_accessories_Blue_BowTie", 5435, 0 },
	{ "Discount_male_accessories_Navy_BowTie", 5436, 0 },
	{ "Discount_male_accessories_Red_BowTie", 5437, 0 },
	{ "Discount_male_accessories_Green_BowTie", 5438, 0 },
	{ "Discount_male_accessories_Orange_BowTie", 5439, 0 },
	{ "Discount_male_accessories_Yellow_BowTie", 5440, 0 },
	{ "Discount_male_accessories_Purple_BowTie", 5441, 0 },
	{ "Discount_male_accessories_Brown_BowTie", 5442, 0 },
	{ "Discount_male_accessories_Stone_BowTie", 5443, 0 },
	{ "Discount_male_accessories_Blue_Plaid_BowTie", 5444, 0 },
	{ "Discount_male_accessories_Orange_Plaid_BowTie", 5445, 0 },
	{ "Discount_male_accessories_Earth_BowTie", 5446, 0 },
	{ "Discount_male_accessories_Red_Plaid_BowTie", 5447, 0 },
	{ "Discount_male_accessories_Blue_Skinny_Tie", 5448, 0 },
	{ "Discount_male_accessories_Navy_Skinny_Tie", 5449, 0 },
	{ "Discount_male_accessories_Red_Skinny_Tie", 5450, 0 },
	{ "Discount_male_accessories_Green_Skinny_Tie", 5451, 0 },
	{ "Discount_male_accessories_Orange_Skinny_Tie", 5452, 0 },
	{ "Discount_male_accessories_Yellow_Skinny_Tie", 5453, 0 },
	{ "Discount_male_accessories_Purple_Skinny_Tie", 5454, 0 },
	{ "Discount_male_accessories_Brown_Skinny_Tie", 5455, 0 },
	{ "Discount_male_accessories_Stone_Skinny_Tie", 5456, 0 },
	{ "Discount_male_accessories_Two_Tone_Plaid_Skinny_Tie", 5457, 0 },
	{ "Discount_male_accessories_Tan_Plaid_Skinny_Tie", 5458, 0 },
	{ "Discount_male_accessories_Gold_Striped_Skinny_Tie", 5459, 0 },
	{ "Discount_male_accessories_Red_Striped_Skinny_Tie", 5460, 0 },
	{ "BOOT_BUTTON_QUICK_MATCH_TYPE", 5461, 0 },
	{ "Dicount_female_accessories_Spotted_Bow_Scarf", 5466, 0 },
	{ "Dicount_female_accessories_Floral_Bow_Scarf", 5467, 0 },
	{ "Dicount_female_accessories_Pink_Bow_Scarf", 5468, 0 },
	{ "Dicount_female_accessories_Red_Bow_Scarf", 5469, 0 },
	{ "Dicount_female_accessories_Leopard_Bow_Scarf", 5470, 0 },
	{ "Dicount_female_accessories_White_Bow_Scarf", 5471, 0 },
	{ "BUSINESS_VEHICLES_ALPHA", 5472, 0 },
	{ "BUSINESS_VEHICLES_HUNTLEY", 5473, 0 },
	{ "BUSINESS_VEHICLES_JESTER", 5474, 0 },
	{ "BUSINESS_VEHICLES_MASSACRO", 5475, 0 },
	{ "BUSINESS_VEHICLES_TURISMOR", 5476, 0 },
	{ "business_vehicles_Zentorno", 5477, 0 },
	{ "BUSINESS_VEHICLES_ASTEROPE", 5478, 0 },
	{ "BUSINESS_VEHICLES_BOBCATXL", 5479, 0 },
	{ "BUSINESS_VEHICLES_CAVALCADE2", 5480, 0 },
	{ "BUSINESS_VEHICLES_GRANGER", 5481, 0 },
	{ "BUSINESS_VEHICLES_INGOT", 5482, 0 },
	{ "BUSINESS_VEHICLES_INTRUDER", 5483, 0 },
	{ "BUSINESS_VEHICLES_MINIVAN", 5484, 0 },
	{ "BUSINESS_VEHICLES_PREMIER", 5485, 0 },
	{ "BUSINESS_VEHICLES_RADI", 5486, 0 },
	{ "BUSINESS_VEHICLES_RANCHERXL", 5487, 0 },
	{ "BUSINESS_VEHICLES_STANIER", 5488, 0 },
	{ "BUSINESS_VEHICLES_STRATUM", 5489, 0 },
	{ "BUSINESS_VEHICLES_WASHINGTON", 5490, 0 },
	{ "CAP_MAX_AMOUNT_CASH_TO_SHARE", 5491, 0 },
	{ "CAP_MAX_AMOUNT_CASH_PICKUP", 5492, 0 },
	{ "CAP_MAX_AMOUNT_CASH_RECIEVED", 5493, 0 },
	{ "STRIPBAR_SHOTS_AT_BAR_PRICE_MODIFIER", 5494, 0 },
	{ "STRIPBAR_DANCE_PRICE_MODIFIER", 5495, 0 },
	{ "CRATEDROPLOCATION2", 5496, 0 },
	{ "CRATEDROPLOCATION3", 5497, 0 },
	{ "CRATEDROPLOCATION4", 5498, 0 },
	{ "CRATEDROPLOCATION5", 5499, 0 },
	{ "PARACHUTING_CASH_POINT_MAX_CAP", 5500, 0 },
	{ "PARACHUTING_CASH_POINT_MULTIPLIER", 5501, 0 },
	{ "VALENTINE_MODIFIER_CADDY_SEDAN", 5502, 0 },
	{ "VALENTINE_MODIFIER_CADDY_GUSENBERG", 5503, 0 },
	{ "VALENTINE_MODIFIER_CLOTHING_MULTIPLIER", 5504, 1 },
	{ "VALENTINES_MODIFIER_HAIRCUTS_MULTIPLIER", 5505, 1 },
	{ "TURN_ON_VALENTINES_EVENT", 5506, 2 },
	{ "VALENTINE_MODIFIER_VEHICLE_RATLOADER", 5507, 0 },
	{ "valentine_Gusenberg_WEAPONMOD_EXTENDED_CLIP", 5508, 0 },
	{ "valentine_Gusenberg_AMMO", 5509, 0 },
	{ "MAX_NUMBER_STOLEN_VEHICLES_SOLD_DAILY", 5516, 0 },
	{ "XP_TUNABLE_PARACHUTING_DEAD_CENTRE", 5517, 0 },
	{ "XP_TUNABLE_PARACHUTING_IN_THE_CIRCLE", 5518, 0 },
	{ "XP_TUNABLE_PARACHUTING_CLIP_THE_OUTER_RING", 5519, 0 },
	{ "SURVIVAL_CASH_REWARD", 5520, 0 },
	{ "ROCKSTAR_VERIFIED_RP_BONUS", 5521, 0 },
	{ "IDLE_DM_BOUNTY", 5522, 0 },
	{ "Selling_Stolen_Vehicle_Cap", 5523, 0 },
	{ "Selling_Stolen_Personal_Vehicle_Cap", 5524, 0 },
	{ "Selling_Purchased_Personal_Vehicle_Cap", 5525, 0 },
	{ "Lottery_ticket_cost", 5526, 0 },
	{ "BUSINESS_VEHICLE_VESTRA", 5527, 0 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_PURPLE_EXPENDITURE_TUNABLE_BIKE", 5529, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_GREEN_EXPENDITURE_TUNABLE_BIKE", 5530, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_PURPLE_EXPENDITURE_TUNABLE_SPORT", 5531, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_GREEN_EXPENDITURE_TUNABLE_SPORT", 5532, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_PURPLE_EXPENDITURE_TUNABLE", 5533, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_GREEN_EXPENDITURE_TUNABLE", 5534, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_PURPLE_EXPENDITURE_TUNABLE_SUV", 5535, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_GREEN_EXPENDITURE_TUNABLE_SUV", 5536, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_PURPLE_EXPENDITURE_TUNABLE_SPECIAL", 5537, 1 },
	{ "CARMOD_UNLOCK_TYRE_SMOKE_GREEN_EXPENDITURE_TUNABLE_SPECIAL", 5538, 1 },
	{ "TOGGLE_CTF_CONTENT", 5539, 2 },
	{ "TOGGLE_LTS_CONTENT", 5540, 2 },
	{ "COMMENDREPORT_MAX_STRENGTH", 5541, 0 },
	{ "JOB_RP_CAP", 5542, 0 },
	{ "PLAYER_KILL_RP_DM_CAP", 5543, 0 },
	{ "PLAYER_KILL_RP_RACE_CAP", 5544, 0 },
	{ "PLAYER_KILL_RP_MISSION_CAP", 5545, 0 },
	{ "MISSION_AI_KILL_RP", 5546, 0 },
	{ "MISSION_AI_KILL_AMOUNT_CAP", 5547, 0 },
	{ "RACE_WORLD_RECORD_RP", 5548, 0 },
	{ "KILL_A_MUGGER_RP", 5549, 0 },
	{ "SING_IN_SHOWER_RP", 5550, 0 },
	{ "PLAYLIST_WINNER_RP", 5551, 0 },
	{ "LESTER_BOUNTY_CUT", 5552, 0 },
	{ "REQUEST_A_JOB_FEE", 5553, 0 },
	{ "MECHANIC_DAILY_FEE", 5554, 0 },
	{ "PLAYER_CASHDROP_CAP", 5555, 0 },
	{ "PLAYLIST_ENTRY_FEE", 5556, 0 },
	{ "MUGGER_AMOUNT_STEAL", 5557, 0 },
	{ "MUGGER_STEAL_CAP", 5558, 0 },
	{ "LOSE_WANTED_LEVEL_1_CAP", 5559, 0 },
	{ "LOSE_WANTED_LEVEL_2_CAP", 5560, 0 },
	{ "LOSE_WANTED_LEVEL_3_CAP", 5561, 0 },
	{ "LOSE_WANTED_LEVEL_4_CAP", 5562, 0 },
	{ "LOSE_WANTED_LEVEL_5_CAP", 5563, 0 },
	{ "BUSINESS2_THRUST_PRICE", 5565, 0 },
	{ "RP_REWARD_LIKE_CAP_PER_AWARD", 5566, 0 },
	{ "DISABLE_EVENT_CRATE_DROP", 5567, 2 },
	{ "DISABLE_EVENT_ARMOURED_TRUCK", 5568, 2 },
	{ "DISABLE_EVENT_HIGH_PRIORITY_VEHICLE", 5569, 2 },
	{ "DISABLE_EVENT_JOYRIDER", 5570, 2 },
	{ "PLAYLIST_EVENT_GIFT_ACTIVE", 5571, 2 },
	{ "VERSUS_MISSION_TIME_1", 5572, 1 },
	{ "VERSUS_MISSION_TIME_2", 5573, 1 },
	{ "VERSUS_MISSION_TIME_3", 5574, 1 },
	{ "VERSUS_MISSION_TIME_4", 5575, 1 },
	{ "VERSUS_MISSION_TIME_5", 5576, 1 },
	{ "VERSUS_MISSION_TIME_6", 5577, 1 },
	{ "VERSUS_WINNER_RP_DIVIDER_TIME_1", 5578, 1 },
	{ "VERSUS_WINNER_RP_DIVIDER_TIME_2", 5579, 1 },
	{ "VERSUS_WINNER_RP_DIVIDER_TIME_3", 5580, 1 },
	{ "VERSUS_WINNER_RP_DIVIDER_TIME_4", 5581, 1 },
	{ "VERSUS_WINNER_RP_DIVIDER_TIME_5", 5582, 1 },
	{ "VERSUS_WINNER_RP_DIVIDER_TIME_6", 5583, 1 },
	{ "VERSUS_WINNER_CASH_DIVIDER_TIME_1", 5584, 1 },
	{ "VERSUS_WINNER_CASH_DIVIDER_TIME_2", 5585, 1 },
	{ "VERSUS_WINNER_CASH_DIVIDER_TIME_3", 5586, 1 },
	{ "VERSUS_WINNER_CASH_DIVIDER_TIME_4", 5587, 1 },
	{ "VERSUS_WINNER_CASH_DIVIDER_TIME_5", 5588, 1 },
	{ "VERSUS_WINNER_CASH_DIVIDER_TIME_6", 5589, 1 },
	{ "VERSUS_LOSER_1_RP_DIVIDER_TIME_1", 5590, 1 },
	{ "VERSUS_LOSER_1_RP_DIVIDER_TIME_2", 5591, 1 },
	{ "VERSUS_LOSER_1_RP_DIVIDER_TIME_3", 5592, 1 },
	{ "VERSUS_LOSER_1_RP_DIVIDER_TIME_4", 5593, 1 },
	{ "VERSUS_LOSER_1_RP_DIVIDER_TIME_5", 5594, 1 },
	{ "VERSUS_LOSER_1_RP_DIVIDER_TIME_6", 5595, 1 },
	{ "VERSUS_LOSER_1_CASH_DIVIDER_TIME_1", 5596, 1 },
	{ "VERSUS_LOSER_1_CASH_DIVIDER_TIME_2", 5597, 1 },
	{ "VERSUS_LOSER_1_CASH_DIVIDER_TIME_3", 5598, 1 },
	{ "VERSUS_LOSER_1_CASH_DIVIDER_TIME_4", 5599, 1 },
	{ "VERSUS_LOSER_1_CASH_DIVIDER_TIME_5", 5600, 1 },
	{ "VERSUS_LOSER_1_CASH_DIVIDER_TIME_6", 5601, 1 },
	{ "VERSUS_LOSER_2_RP_DIVIDER_TIME_1", 5602, 1 },
	{ "VERSUS_LOSER_2_RP_DIVIDER_TIME_2", 5603, 1 },
	{ "VERSUS_LOSER_2_RP_DIVIDER_TIME_3", 5604, 1 },
	{ "VERSUS_LOSER_2_RP_DIVIDER_TIME_4", 5605, 1 },
	{ "VERSUS_LOSER_2_RP_DIVIDER_TIME_5", 5606, 1 },
	{ "VERSUS_LOSER_2_RP_DIVIDER_TIME_6", 5607, 1 },
	{ "VERSUS_LOSER_2_CASH_DIVIDER_TIME_1", 5608, 1 },
	{ "VERSUS_LOSER_2_CASH_DIVIDER_TIME_2", 5609, 1 },
	{ "VERSUS_LOSER_2_CASH_DIVIDER_TIME_3", 5610, 1 },
	{ "VERSUS_LOSER_2_CASH_DIVIDER_TIME_4", 5611, 1 },
	{ "VERSUS_LOSER_2_CASH_DIVIDER_TIME_5", 5612, 1 },
	{ "VERSUS_LOSER_2_CASH_DIVIDER_TIME_6", 5613, 1 },
	{ "VERSUS_LOSER_3_RP_DIVIDER_TIME_1", 5614, 1 },
	{ "VERSUS_LOSER_3_RP_DIVIDER_TIME_2", 5615, 1 },
	{ "VERSUS_LOSER_3_RP_DIVIDER_TIME_3", 5616, 1 },
	{ "VERSUS_LOSER_3_RP_DIVIDER_TIME_4", 5617, 1 },
	{ "VERSUS_LOSER_3_RP_DIVIDER_TIME_5", 5618, 1 },
	{ "VERSUS_LOSER_3_RP_DIVIDER_TIME_6", 5619, 1 },
	{ "VERSUS_LOSER_3_CASH_DIVIDER_TIME_1", 5620, 1 },
	{ "VERSUS_LOSER_3_CASH_DIVIDER_TIME_2", 5621, 1 },
	{ "VERSUS_LOSER_3_CASH_DIVIDER_TIME_3", 5622, 1 },
	{ "VERSUS_LOSER_3_CASH_DIVIDER_TIME_4", 5623, 1 },
	{ "VERSUS_LOSER_3_CASH_DIVIDER_TIME_5", 5624, 1 },
	{ "VERSUS_LOSER_3_CASH_DIVIDER_TIME_6", 5625, 1 },
	{ "DLC_FEMALE_HAIR_MESSY_BUN_CHESTNUT", 5930, 0 },
	{ "DLC_FEMALE_HAIR_MESSY_BUN_BLONDE", 5931, 0 },
	{ "DLC_FEMALE_HAIR_MESSY_BUN_AUBURN", 5932, 0 },
	{ "DLC_FEMALE_HAIR_MESSY_BUN_BLACK", 5933, 0 },
	{ "DLC_FEMALE_HAIR_MESSY_BUN_BROWN", 5934, 0 },
	{ "DLC_FEMALE_HAIR_PIN_UP_GIRL_CHESTNUT", 5935, 0 },
	{ "DLC_FEMALE_HAIR_PIN_UP_GIRL_BLONDE", 5936, 0 },
	{ "DLC_FEMALE_HAIR_PIN_UP_GIRL_AUBURN", 5937, 0 },
	{ "DLC_FEMALE_HAIR_PIN_UP_GIRL_BLACK", 5938, 0 },
	{ "DLC_FEMALE_HAIR_PIN_UP_GIRL_BROWN", 5939, 0 },
	{ "DLC_FEMALE_HAIR_TWISTED_BOB_CHESTNUT", 5940, 0 },
	{ "DLC_FEMALE_HAIR_TWISTED_BOB_BLACK", 5941, 0 },
	{ "DLC_FEMALE_HAIR_TWISTED_BOB_AUBURN", 5942, 0 },
	{ "DLC_FEMALE_HAIR_TWISTED_BOB_BROWN", 5943, 0 },
	{ "DLC_FEMALE_HAIR_TWISTED_BOB_BLONDE", 5944, 0 },
	{ "DLC_FEMALE_HAIR_TIGHT_BUN_CHESTNUT", 5945, 0 },
	{ "DLC_FEMALE_HAIR_TIGHT_BUN_BLONDE", 5946, 0 },
	{ "DLC_FEMALE_HAIR_TIGHT_BUN_AUBURN", 5947, 0 },
	{ "DLC_FEMALE_HAIR_TIGHT_BUN_BLACK", 5948, 0 },
	{ "DLC_FEMALE_HAIR_TIGHT_BUN_BROWN", 5949, 0 },
	{ "DLC_MALE_HAIR_SURFER_DUDE_DARK_BROWN", 5950, 0 },
	{ "DLC_MALE_HAIR_SURFER_DUDE_LIGHT_BROWN", 5951, 0 },
	{ "DLC_MALE_HAIR_SURFER_DUDE_AUBURN", 5952, 0 },
	{ "DLC_MALE_HAIR_SURFER_DUDE_BLONDE", 5953, 0 },
	{ "DLC_MALE_HAIR_SURFER_DUDE_BLACK", 5954, 0 },
	{ "DLC_MALE_HAIR_SHAGGY_CURLS_DARK_BROWN", 5955, 0 },
	{ "DLC_MALE_HAIR_SHAGGY_CURLS_LIGHT_BROWN", 5956, 0 },
	{ "DLC_MALE_HAIR_SHAGGY_CURLS_AUBURN", 5957, 0 },
	{ "DLC_MALE_HAIR_SHAGGY_CURLS_BLONDE", 5958, 0 },
	{ "DLC_MALE_HAIR_SHAGGY_CURLS_BLACK", 5959, 0 },
	{ "DLC_MALE_HAIR_HIGH_SLICKED_SIDES_DARK_BROWN", 5960, 0 },
	{ "DLC_MALE_HAIR_HIGH_SLICKED_SIDES_LIGHT_BROWN", 5961, 0 },
	{ "DLC_MALE_HAIR_HIGH_SLICKED_SIDES_AUBURN", 5962, 0 },
	{ "DLC_MALE_HAIR_HIGH_SLICKED_SIDES_BLONDE", 5963, 0 },
	{ "DLC_MALE_HAIR_HIGH_SLICKED_SIDES_BLACK", 5964, 0 },
	{ "DLC_MALE_HAIR_SHORT_SIDE_PART_DARK_BROWN", 5965, 0 },
	{ "DLC_MALE_HAIR_SHORT_SIDE_PART_LIGHT_BROWN", 5966, 0 },
	{ "DLC_MALE_HAIR_SHORT_SIDE_PART_AUBURN", 5967, 0 },
	{ "DLC_MALE_HAIR_SHORT_SIDE_PART_BLONDE", 5968, 0 },
	{ "DLC_MALE_HAIR_SHORT_SIDE_PART_BLACK", 5969, 0 },
	{ "DLC_WEAPON_TINT_GOLD_SNS_PISTOL", 5970, 0 },
	{ "DLC_WEAPON_TINT_PLATINUM_SNS_PISTOL", 5971, 0 },
	{ "DLC_WEAPON_TINT_ARMY_SNS_PISTOL", 5972, 0 },
	{ "DLC_WEAPON_TINT_GREEN_SNS_PISTOL", 5973, 0 },
	{ "DLC_WEAPON_TINT_ORANGE_SNS_PISTOL", 5974, 0 },
	{ "DLC_WEAPON_TINT_LSPD_SNS_PISTOL", 5975, 0 },
	{ "DLC_WEAPON_TINT_PINK_SNS_PISTOL", 5976, 0 },
	{ "DLC_WEAPON_TINT_GOLD_SPECIAL_CARBINE", 5977, 0 },
	{ "DLC_WEAPON_TINT_PLATINUM_SPECIAL_CARBINE", 5978, 0 },
	{ "DLC_WEAPON_TINT_ARMY_SPECIAL_CARBINE", 5979, 0 },
	{ "DLC_WEAPON_TINT_GREEN_SPECIAL_CARBINE", 5980, 0 },
	{ "DLC_WEAPON_TINT_ORANGE_SPECIAL_CARBINE", 5981, 0 },
	{ "DLC_WEAPON_TINT_LSPD_SPECIAL_CARBINE", 5982, 0 },
	{ "DLC_WEAPON_TINT_PINK_SPECIAL_CARBINE", 5983, 0 },
	{ "DLC_WEAPON_TINT_GOLD_HEAVY_PISTOL", 5984, 0 },
	{ "DLC_WEAPON_TINT_PLATINUM_HEAVY_PISTOL", 5985, 0 },
	{ "DLC_WEAPON_TINT_ARMY_HEAVY_PISTOL", 5986, 0 },
	{ "DLC_WEAPON_TINT_GREEN_HEAVY_PISTOL", 5987, 0 },
	{ "DLC_WEAPON_TINT_ORANGE_HEAVY_PISTOL", 5988, 0 },
	{ "DLC_WEAPON_TINT_LSPD_HEAVY_PISTOL", 5989, 0 },
	{ "DLC_WEAPON_TINT_PINK_HEAVY_PISTOL", 5990, 0 },
	{ "DLC_WEAPON_TINT_GOLD_BULLPUP_RIFLE", 5991, 0 },
	{ "DLC_WEAPON_TINT_PLATINUM_BULLPUP_RIFLE", 5992, 0 },
	{ "DLC_WEAPON_TINT_ARMY_BULLPUP_RIFLE", 5993, 0 },
	{ "DLC_WEAPON_TINT_GREEN_BULLPUP_RIFLE", 5994, 0 },
	{ "DLC_WEAPON_TINT_ORANGE_BULLPUP_RIFLE", 5995, 0 },
	{ "DLC_WEAPON_TINT_LSPD_BULLPUP_RIFLE", 5996, 0 },
	{ "DLC_WEAPON_TINT_PINK_BULLPUP_RIFLE", 5997, 0 },
	{ "DLC_APPARTMENTS_ECLIPSE_TOWERS_APT_3", 5998, 0 },
	{ "DLC_APPARTMENTS_DEL_PERRO_HEIGHTS_APT_4", 5999, 0 },
	{ "DLC_APPARTMENTS_RICHARDS_MAJESTIC_APT_2", 6000, 0 },
	{ "DLC_APPARTMENTS_TINSEL_TOWERS_APT_42", 6001, 0 },
	{ "DLC_FEMALE_TATTOOS_LOS_SANTOS_WREATH", 6003, 0 },
	{ "DLC_FEMALE_TATTOOS_HIBISCUS_FLOWER_DUO", 6004, 0 },
	{ "DLC_FEMALE_TATTOOS_TRIBAL_FLOWER", 6005, 0 },
	{ "DLC_FEMALE_TATTOOS_ROCK_SOLID", 6006, 0 },
	{ "DLC_FEMALE_TATTOOS_CATFISH", 6007, 0 },
	{ "DLC_FEMALE_TATTOOS_SHRIMP", 6008, 0 },
	{ "DLC_FEMALE_TATTOOS_LOVE_DAGGER", 6009, 0 },
	{ "DLC_FEMALE_TATTOOS_SCHOOL_OF_FISH", 6010, 0 },
	{ "DLC_FEMALE_TATTOOS_TRIBAL_BUTTERFLY", 6011, 0 },
	{ "DLC_FEMALE_TATTOOS_HIBISCUS_FLOWER", 6012, 0 },
	{ "DLC_FEMALE_TATTOOS_DOLPHIN", 6013, 0 },
	{ "DLC_FEMALE_TATTOOS_SEA_HORSES", 6014, 0 },
	{ "DLC_FEMALE_TATTOOS_ANCHOR", 6015, 0 },
	{ "DLC_FEMALE_TATTOOS_SWALLOW", 6016, 0 },
	{ "DLC_FEMALE_TATTOOS_TRIBAL_FISH", 6017, 0 },
	{ "DLC_FEMALE_TATTOOS_PARROT", 6018, 0 },
	{ "DLC_FEMALE_TATTOOS_HIGH_ROLLER", 6019, 0 },
	{ "DLC_FEMALE_TATTOOS_RESPECT", 6020, 0 },
	{ "DLC_FEMALE_TATTOOS_SINGLE", 6021, 0 },
	{ "DLC_FEMALE_TATTOOS_VALDEGRACE_LOGO", 6022, 0 },
	{ "DLC_FEMALE_TATTOOS_MONEY_ROSE", 6023, 0 },
	{ "DLC_FEMALE_TATTOOS_DIAMOND_CROWN", 6024, 0 },
	{ "DLC_FEMALE_TATTOOS_DOLLAR_SIGN", 6025, 0 },
	{ "DLC_FEMALE_TATTOOS_DIAMOND_JACK", 6026, 0 },
	{ "DLC_FEMALE_TATTOOS_MAKIN_MONEY", 6027, 0 },
	{ "DLC_FEMALE_TATTOOS_GOLD_DIGGER", 6028, 0 },
	{ "DLC_FEMALE_TATTOOS_GREED_IS_GOOD", 6029, 0 },
	{ "DLC_FEMALE_TATTOOS_LOVE_MONEY", 6030, 0 },
	{ "DLC_FEMALE_TATTOOS_SANTO_CAPRA_LOGO", 6031, 0 },
	{ "DLC_FEMALE_TATTOOS_MONEY_BAG", 6032, 0 },
	{ "DLC_FEMALE_TATTOOS_CREW_EMBLEM_CHEST", 6033, 0 },
	{ "DLC_FEMALE_TATTOOS_CREW_EMBLEM_ARM", 6034, 0 },
	{ "DLC_MALE_TATTOO_MERMAID_LS", 6035, 0 },
	{ "DLC_MALE_TATTOO_SHIP_ARMS", 6036, 0 },
	{ "DLC_MALE_TATTOO_TRIBAL_HAMMERHEAD", 6037, 0 },
	{ "DLC_MALE_TATTOO_TRIBAL_SHARK", 6038, 0 },
	{ "DLC_MALE_TATTOO_PIRATE_SKULL", 6039, 0 },
	{ "DLC_MALE_TATTOO_SURF_LS", 6040, 0 },
	{ "DLC_MALE_TATTOO_SWORDFISH", 6041, 0 },
	{ "DLC_MALE_TATTOO_TIKI_TOWER", 6042, 0 },
	{ "DLC_MALE_TATTOO_TRIBAL_TIKI_TOWER", 6043, 0 },
	{ "DLC_MALE_TATTOO_TRIBAL_SUN", 6044, 0 },
	{ "DLC_MALE_TATTOO_TRIBAL_STAR", 6045, 0 },
	{ "DLC_MALE_TATTOO_LITTLE_FISH", 6046, 0 },
	{ "DLC_MALE_TATTOO_SURFS_UP", 6047, 0 },
	{ "DLC_MALE_TATTOO_VESPUCCI_BEAUTY", 6048, 0 },
	{ "DLC_MALE_TATTOO_SHARK", 6049, 0 },
	{ "DLC_MALE_TATTOO_WHEEL", 6050, 0 },
	{ "DLC_MALE_TATTOO_CASH_KING", 6051, 0 },
	{ "DLC_MALE_TATTOO_HUSTLER", 6053, 0 },
	{ "DLC_MALE_TATTOO_MAKIN_PAPER", 6054, 0 },
	{ "DLC_MALE_TATTOO_BOLD_DOLLAR_SIGN", 6055, 0 },
	{ "DLC_MALE_TATTOO_SCRIPT_DOLLAR_SIGN", 6056, 0 },
	{ "DLC_MALE_TATTOO_DOLLAR_SKULL", 6058, 0 },
	{ "DLC_MALE_TATTOO_RICH", 6059, 0 },
	{ "DLC_MALE_TATTOO_DOLLAR_SIGNS", 6060, 0 },
	{ "DLC_MALE_TATTOO_ALLSEEING_EYE", 6061, 0 },
	{ "DLC_MALE_TATTOO_GREEN", 6062, 0 },
	{ "DLC_MALE_TATTOO_CREW_EMBLEM_CHEST", 6063, 0 },
	{ "DLC_MALE_TATTOO_CREW_EMBLEM_ARM", 6064, 0 },
	{ "DLC_CAR_MODS_CLASSICAL_HORN_1", 6065, 0 },
	{ "DLC_CAR_MODS_CLASSICAL_HORN_2", 6066, 0 },
	{ "DLC_CAR_MODS_CLASSICAL_HORN_3", 6067, 0 },
	{ "DLC_CAR_MODS_CLASSICAL_HORN_4", 6068, 0 },
	{ "DLC_CAR_MODS_CLASSICAL_HORN_5", 6069, 0 },
	{ "DLC_CAR_MODS_CLASSICAL_HORN_6", 6070, 0 },
	{ "DLC_CAR_MODS_CLASSICAL_HORN_7", 6071, 0 },
	{ "DLC_VEHICLE_BF_BIFTA", 6072, 0 },
	{ "DLC_VEHICLE_CANIS_KALAHARI", 6073, 0 },
	{ "DLC_VEHICLE_BRAVADO_PARADISE", 6074, 0 },
	{ "DLC_VEHICLE_PEGASSI_SPEEDER", 6075, 0 },
	{ "DLC_VEHICLE_DINKA_THRUST", 6076, 0 },
	{ "DLC_VEHICLE_COIL_VOLTIC_TOPLESS", 6077, 0 },
	{ "DLC_VEHICLE_BRAVADO_BANSHEE_TOPLESS", 6078, 0 },
	{ "DLC_VEHICLE_INVERTO_COQUETTE_TOPLESS", 6079, 0 },
	{ "DLC_VEHICLE_GROTTI_STINGER_TOPLESS", 6080, 0 },
	{ "DLC_VEHICLE_VAPID_DOMINATOR", 6081, 0 },
	{ "DLC_VEHICLE_SCHYSTER_FUSILADE", 6083, 0 },
	{ "DLC_VEHICLE_MAIBATSU_PENUMBRA", 6084, 0 },
	{ "DLC_VEHICLE_UBERMACHT_SENTINEL_XS", 6085, 0 },
	{ "DLC_VEHICLE_UBERMACHT_SENTINEL", 6086, 0 },
	{ "DLC_WEAPON_ADDON_SNS_PISTOL_EXTENDED_CLIP", 6087, 0 },
	{ "DLC_WEAPON_ADDON_SPECIAL_CARBINE_SUPPRESSOR", 6089, 0 },
	{ "DLC_WEAPON_ADDON_HEAVY_PISTOL_SUPPRESSOR", 6090, 0 },
	{ "DLC_WEAPON_ADDON_SPECIAL_CARBINE_SCOPE", 6091, 0 },
	{ "DLC_WEAPON_ADDON_SPECIAL_CARBINE_EXTENDED_CLIP", 6092, 0 },
	{ "DLC_WEAPON_ADDON_HEAVY_PISTOL_EXTENDED_CLIP", 6093, 0 },
	{ "DLC_WEAPON_ADDON_SPECIAL_CARBINE_GRIP", 6094, 0 },
	{ "DLC_WEAPON_ADDON_SPECIAL_CARBINE_FLASHLIGHT", 6095, 0 },
	{ "DLC_WEAPON_ADDON_HEAVY_PISTOL_FLASHLIGHT", 6097, 0 },
	{ "DLC_WEAPON_ADDON_BULLPUP_RIFLE_SUPPRESSOR", 6098, 0 },
	{ "DLC_WEAPON_ADDON_BULLPUP_RIFLE_SCOPE", 6099, 0 },
	{ "DLC_WEAPON_ADDON_BULLPUP_RIFLE_EXTENDED_CLIP", 6100, 0 },
	{ "DLC_WEAPON_ADDON_BULLPUP_RIFLE_GRIP", 6101, 0 },
	{ "DLC_WEAPON_ADDON_BULLPUP_RIFLE_FLASHLIGHT", 6103, 0 },
	{ "DLC_WEAPON_ADDON_SNS_PISTOL_AMMO", 6104, 0 },
	{ "DLC_WEAPON_ADDON_SPECIAL_CARBINE_AMMO", 6105, 0 },
	{ "DLC_WEAPON_ADDON_HEAVY_PISTOL_AMMO", 6106, 0 },
	{ "DLC_WEAPON_ADDON_BULLPUP_RIFLE_AMMO", 6107, 0 },
	{ "DLC_WEAPON_BROKEN_BOTTLE", 6108, 0 },
	{ "DLC_WEAPON_SNS_PISTOL", 6109, 0 },
	{ "DLC_WEAPON_HEAVY_PISTOL", 6110, 0 },
	{ "DLC_WEAPON_SPECIAL_CARBINE", 6111, 0 },
	{ "DLC_WEAPON_BULLPUP_RIFLE", 6112, 0 },
	{ "DLC_WEAPON_VINTAGE_PISTOL", 6113, 0 },
	{ "DLC_WEAPON_VINTAGE_PISTOL", 6113, 0 },
	{ "DLC_WEAPON_DAGGER", 6114, 0 },
	{ "DLC_WEAPON_DAGGER", 6114, 0 },
	{ "DLC_WEAPON_ADDON_VINTAGE_PISTOL_AMMO", 6115, 0 },
	{ "DLC_WEAPON_ADDON_VINTAGE_PISTOL_AMMO", 6115, 0 },
	{ "DLC_WEAPON_ADDON_DAGGER_AMMO", 6116, 0 },
	{ "DLC_WEAPON_TINT_ARMY_ASSUALTSMG", 6118, 0 },
	{ "DLC_WEAPON_TINT_GREEN_ASSUALTSMG", 6119, 0 },
	{ "DLC_WEAPON_TINT_ORANGE_ASSUALTSMG", 6120, 0 },
	{ "DLC_WEAPON_TINT_LSPD_ASSUALTSMG", 6121, 0 },
	{ "DLC_WEAPON_TINT_PINK_ASSUALTSMG", 6122, 0 },
	{ "DLC_WEAPON_TINT_GOLD_ASSUALTSMG", 6123, 0 },
	{ "DLC_WEAPON_TINT_PLATINUM_ASSUALTSMG", 6124, 0 },
	{ "LOTTERY_WEEK", 6125, 0 },
	{ "DISABLE_LOTTERY", 6126, 2 },
	{ "MAX_NUMBER_LOTTERY_TICKETS", 6127, 0 },
	{ "REQUEST_COPS_TURN_BLIND_EYE_FEE", 6128, 0 },
	{ "HORN_CNOTE_C1", 6136, 0 },
	{ "SPEC_CHANGE_SESSION_TIME", 6137, 0 },
	{ "MENTAL_STATE_RP_DIVIDER", 6138, 1 },
	{ "MENTAL_STATE_RP_MIN_THRESHOLD", 6139, 0 },
	{ "TOGGLE_RACE_CREATOR", 6140, 2 },
	{ "TOGGLE_DEATHMATCH_CREATOR", 6141, 2 },
	{ "DISABLE_JOB_BETTING", 6144, 2 },
	{ "SURVIVAL_RP_CAP_PER_WAVE", 6145, 0 },
	{ "DLC_hipster_modifier_Vulcar_Pigalle", 6549, 0 },
	{ "DLC_HIPSTER_CAR_MOD_VAPID_BLADE", 6550, 0 },
	{ "DLC_HIPSTER_CAR_MOD_BENEFACTOR_GLENDA", 6551, 0 },
	{ "DLC_HIPSTER_CAR_MOD_DECLASSE_RHAPSODY", 6552, 0 },
	{ "DLC_HIPSTER_CAR_MOD_VULCAR_WARRENER", 6553, 0 },
	{ "DLC_HIPSTER_CAR_MOD_BENEFACTOR_PANTO", 6554, 0 },
	{ "DLC_HIPSTER_CAR_MOD_DUBSTA3", 6555, 0 },
	{ "DLC_HIPSTER_CAR_MOD_BLAZER3", 6556, 0 },
	{ "DLC_HIPSTER_CAR_MOD_BUFFALO", 6557, 0 },
	{ "DLC_HIPSTER_CAR_MOD_BUFFALO2", 6558, 0 },
	{ "DLC_HIPSTER_CAR_MOD_PICADOR", 6559, 0 },
	{ "DLC_HIPSTER_CAR_MOD_PRIMO", 6560, 0 },
	{ "DLC_HIPSTER_CAR_MOD_REBEL2", 6561, 0 },
	{ "DLC_HIPSTER_CAR_MOD_REGINA", 6562, 0 },
	{ "DLC_HIPSTER_CAR_MOD_SURFER", 6563, 0 },
	{ "DLC_HIPSTER_CAR_MOD_TAILGATER", 6564, 0 },
	{ "DLC_HIPSTER_CAR_MOD_YOUGA", 6565, 0 },
	{ "DLC_HIPSTER_CAR_MOD_PURE_BLACK", 6566, 0 },
	{ "DLC_HIPSTER_CAR_MOD_JAZZ_HORN_1", 6567, 0 },
	{ "DLC_HIPSTER_CAR_MOD_JAZZ_HORN_2", 6568, 0 },
	{ "DLC_HIPSTER_CAR_MOD_JAZZ_HORN_3", 6569, 0 },
	{ "DLC_HIPSTER_CAR_MOD_JAZZ_HORN_4", 6570, 0 },
	{ "DLC_HIPSTER_CAR_MOD_PINK_TIRE_SMOKE", 6571, 0 },
	{ "DLC_HIPSTER_CAR_MOD_BROWN_TIRE_SMOKE", 6572, 0 },
	{ "DLC_HIPSTER_WEAPON_MOD_VINTAGE_PISTOL_EXTENDED_CLIP", 6573, 0 },
	{ "DLC_HIPSTER_WEAPON_MOD_VINTAGE_PISTOL_SUPPRESSOR", 6574, 0 },
	{ "DLC_HIPSTER_MALE_MASK_GREY_CAT", 6575, 0 },
	{ "DLC_HIPSTER_MALE_MASK_TABBY_CAT", 6576, 0 },
	{ "DLC_HIPSTER_MALE_MASK_RED_FOX", 6577, 0 },
	{ "DLC_HIPSTER_MALE_MASK_BROWN_FOX", 6578, 0 },
	{ "DLC_HIPSTER_MALE_MASK_BROWN_OWL", 6579, 0 },
	{ "DLC_HIPSTER_MALE_MASK_WHITE_OWL", 6580, 0 },
	{ "DLC_HIPSTER_MALE_MASK_GRAY_RACOON", 6581, 0 },
	{ "DLC_HIPSTER_MASK_BLACK_RACOON", 6582, 0 },
	{ "DLC_HIPSTER_FEMALE_MASK_GRAY_CAT", 6583, 0 },
	{ "DLC_HIPSTER_FEMALE_MASK_TABBY_CAT", 6584, 0 },
	{ "DLC_HIPSTER_FEMALE_MASK_RED_FOX", 6585, 0 },
	{ "DLC_HIPSTER_FEMALE_MASK_BROWN_FOX", 6586, 0 },
	{ "DLC_HIPSTER_FEMALE_MASK_BROWN_OWL", 6587, 0 },
	{ "DLC_HIPSTER_FEMALE_MASK_WHITE_OWL", 6588, 0 },
	{ "DLC_HIPSTER_FEMALE_MASK_GRAY_RACOON", 6589, 0 },
	{ "DLC_HIPSTER_FEMALE_MASK_BLACK_RACOON", 6590, 0 },
	{ "SET_ALL_PHONE_SERVICES_AVAILABLE", 6591, 2 },
	{ "TURN_ON_PROMOTIONAL_EYEFIND_HOMEPAGE", 6592, 2 },
	{ "REQUEST_A_HEIST_FEE", 6593, 0 },
	{ "EARNINGS_HEISTS_FINALE_FIRST_PLAY_CASH_REWARD", 6594, 1 },
	{ "EARNINGS_HEISTS_FINALE_REPLAY_CASH_REWARD", 6595, 1 },
	{ "EARNINGS_HEISTS_FINALE_MINIMUM_TOTAL_CASH_TAKE", 6596, 0 },
	{ "EARNINGS_HEISTS_FINALE_MAXIMUM_TOTAL_CASH_TAKE", 6597, 0 },
	{ "RP_HEISTS_HEIST_FAIL_RP_TIME_PERIOD_1", 6598, 0 },
	{ "RP_HEISTS_HEIST_FAIL_RP_TIME_PERIOD_2", 6599, 0 },
	{ "RP_HEISTS_HEIST_FAIL_RP_TIME_PERIOD_3", 6600, 0 },
	{ "RP_HEISTS_HEIST_FAIL_RP_TIME_PERIOD_4", 6601, 0 },
	{ "RP_HEISTS_HEIST_FAIL_RP_TIME_PERIOD_5", 6602, 0 },
	{ "RP_HEISTS_HEIST_FAIL_RP_TIME_PERIOD_6", 6603, 0 },
	{ "RP_HEISTS_GOLD_MEDAL_RP_MULTIPLIER", 6618, 1 },
	{ "RP_HEISTS_SILVER_MEDAL_RP_MULTIPLIER", 6619, 1 },
	{ "RP_HEISTS_BRONZE_MEDAL_RP_MULTIPLIER", 6620, 1 },
	{ "EXPENSES_HEIST_COST_PERCENTAGE_SERIES_A", 6624, 1 },
	{ "TOGGLE_HEISTS_OFF", 6626, 2 },
	{ "MAX_NONE_ROCK_PAYOUT", 6627, 0 },
	{ "UnlockbitchndogfoodtshirtEvent", 6628, 2 },
	{ "UnlockvinylcountdowntshirtEvent", 6629, 2 },
	{ "UnlockhomiessharptshirtEvent", 6630, 2 },
	{ "MENTAL_STATE_KILL_PLAYER_INCREASE_THRESHOLD", 6631, 1 },
	{ "MENTAL_STATE_KILL_PLAYER_INCREASE_AMOUNT", 6632, 1 },
	{ "MENTAL_STATE_KILL_PLAYER_INCREASE_UNDER_THRESHOLD", 6633, 1 },
	{ "MENTAL_STATE_KILL_PLAYER_INCREASE_DIVIDER", 6634, 1 },
	{ "MENTAL_STATE_BLOW_UP_VEHICLE_INCREASE_AMOUNT", 6635, 1 },
	{ "MENTAL_STATE_KILL_PED_INCREASE_AMOUNT", 6636, 1 },
	{ "MENTAL_STATE_DECREASE_AMOUNT", 6637, 1 },
	{ "MENTAL_STATE_DECREASE_RATE", 6638, 1 },
	{ "HIPSTER_MALE_OUTFIT_THE_ECO", 6639, 1 },
	{ "HIPSTER_MALE_OUTFIT_THE_IRONIC", 6640, 1 },
	{ "HIPSTER_MALE_OUTFIT_THE_AFICIONADO", 6641, 1 },
	{ "HIPSTER_MALE_OUTFIT_THE_NATURAL", 6642, 1 },
	{ "HIPSTER_MALE_OUTFIT_THE_POP_UP", 6643, 1 },
	{ "HIPSTER_MALE_OUTFIT_THE_ARTIST", 6644, 1 },
	{ "HIPSTER_MALE_OUTFIT_THE_ELITIST", 6645, 1 },
	{ "HIPSTER_MALE_OUTFIT_THE_ACTIVIST", 6646, 1 },
	{ "HIPSTER_MALE_OUTFIT_THE_URBAN_HIPPY", 6647, 1 },
	{ "HIPSTER_MALE_OUTFIT_THE_FITNESS", 6648, 1 },
	{ "HIPSTER_FEMALE_OUTFIT_THE_YUPPIE", 6649, 1 },
	{ "HIPSTER_FEMALE_OUTFIT_THE_PALMS", 6650, 1 },
	{ "HIPSTER_FEMALE_OUTFIT_THE_BUBBLEGUM", 6651, 1 },
	{ "HIPSTER_FEMALE_OUTFIT_THE_SAFARI", 6652, 1 },
	{ "HIPSTER_FEMALE_OUTFIT_THE_JUNGLE", 6653, 1 },
	{ "HIPSTER_FEMALE_OUTFIT_THE_VINTAGE", 6654, 1 },
	{ "HIPSTER_FEMALE_OUTFIT_THE_YOUTH", 6655, 1 },
	{ "HIPSTER_FEMALE_OUTFIT_THE_CRAZE", 6656, 1 },
	{ "HIPSTER_FEMALE_OUTFIT_THE_TROPICS", 6657, 1 },
	{ "HIPSTER_FEMALE_OUTFIT_THE_ROAR", 6658, 1 },
	{ "HIPSTER_VEHICLE_PURE_GOLD_METAL_RESPRAY", 6660, 0 },
	{ "HIPSTER_VEHICLE_BRUSHED_GOLD_METAL_RESPRAY", 6661, 0 },
	{ "NUMBER_OF_CHALLENGES_PER_DAY", 6662, 0 },
	{ "Car_impound_fee", 6663, 0 },
	{ "PILOT_SCHOOL_VEHICLE_HYDRA", 6664, 0 },
	{ "PILOT_SCHOOL_VEHICLE_BESRA", 6665, 0 },
	{ "PILOT_SCHOOL_VEHICLE_MILJET", 6666, 0 },
	{ "PILOT_SCHOOL_VEHICLE_COQUETTE2", 6667, 0 },
	{ "PILOT_SCHOOL_PLAYER_KIT_PARACHUTE_CANOPY_COLOR_1", 6668, 0 },
	{ "PILOT_SCHOOL_PLAYER_KIT_PARACHUTE_CANOPY_COLOR_2", 6669, 0 },
	{ "PILOT_SCHOOL_PLAYER_KIT_PARACHUTE_CANOPY_COLOR_3", 6670, 0 },
	{ "PILOT_SCHOOL_PLAYER_KIT_NAVY_CHUTE_BAG", 6671, 0 },
	{ "PILOT_SCHOOL_PLAYER_KIT_ORANGE_CHUTE_BAG", 6672, 0 },
	{ "PILOT_SCHOOL_PLAYER_KIT_YELLOW_CHUTE_BAG", 6673, 0 },
	{ "PILOT_SCHOOL_PLAYER_KIT_GREEN_CHUTE_BAG", 6674, 0 },
	{ "PILOT_SCHOOL_PLAYER_KIT_TEAL_CHUTE_BAG", 6675, 0 },
	{ "PILOT_SCHOOL_PLAYER_KIT_PINK_CHUTE_BAG", 6676, 0 },
	{ "PILOT_SCHOOL_PLAYER_KIT_RED_CHUTE_BAG", 6677, 0 },
	{ "ConstrainedKick_Warning1", 6678, 0 },
	{ "ConstrainedKick_Warning2", 6679, 0 },
	{ "ConstrainedKick_Warning3", 6680, 0 },
	{ "ConstrainedKick_Kick", 6681, 0 },
	{ "ROLLERCOASTERRIDECOST", 6682, 0 },
	{ "FERRISWHEELCOST", 6683, 0 },
	{ "rollercoasterridescreamrewardxp", 6684, 0 },
	{ "rollercoasterridescreamrewardcap", 6685, 0 },
	{ "KILLAGGRESSIVEPEDINCREASEAMOUNT", 6686, 1 },
	{ "KILLCOPINCREASEAMOUNT", 6687, 1 },
	{ "TOGGLE_ACTIVATE_INDEPENDENCE_PACK", 6688, 2 },
	{ "MAX_CARRIED_FIREWORKS", 6689, 0 },
	{ "PURCHASED_TATTOO_APPLICATION_FEE", 6691, 0 },
	{ "SURVIVAL_COMPLETE_BONUS", 6692, 1 },
	{ "INDEPENDENCE_DAY_FIREWORKS_TYPE_1", 6693, 0 },
	{ "INDEPENDENCE_DAY_FIREWORKS_TYPE_2", 6694, 0 },
	{ "INDEPENDENCE_DAY_FIREWORKS_TYPE_3", 6695, 0 },
	{ "INDEPENDENCE_DAY_FIREWORKS_TYPE_4", 6696, 0 },
	{ "INDEPENDENCE_DAY_DEACTIVATE_FIREWORKS_LAUNCHER", 6697, 2 },
	{ "INDEPENDENCE_DAY_DEACTIVATE_PLACED_FIREWORKS", 6698, 2 },
	{ "DISABLEROLLERCOASTER", 6699, 2 },
	{ "DISABLEFERRISWHEEL", 6700, 2 },
	{ "DISABLEFIREWORKS", 6701, 2 },
	{ "Toggle_activate_Western_sovereign", 6702, 2 },
	{ "Toggle_activate_Monster_truck", 6703, 2 },
	{ "CLOTHING_INDEPENDENCEDAY_GROUP", 6704, 1 },
	{ "HAIR_MAKEUP_INDEPENDENCEDAY_GROUP", 6705, 1 },
	{ "MASKS_INDEPENDENCEDAY_MASKS_GROUP", 6706, 1 },
	{ "VEHICLE_INDEPENDENCEDAY_MONSTER", 6707, 0 },
	{ "VEHICLE_INDEPENDENCEDAY_SOVEREIGN", 6708, 0 },
	{ "VEHICLEKIT_INDEPENDENCEDAY_PATRIOT_TIRE_SMOKE", 6709, 0 },
	{ "VEHICLEKIT_INDEPENDENCEDAY_HORN_1", 6710, 0 },
	{ "VEHICLEKIT_INDEPENDENCEDAY_HORN_2", 6711, 0 },
	{ "VEHICLEKIT_INDEPENDENCEDAY_HORN_3", 6712, 0 },
	{ "VEHICLEKIT_INDEPENDENCEDAY_HORN_4", 6713, 0 },
	{ "WEAPONS_INDEPENDENCEDAY_MUSKET", 6714, 0 },
	{ "WEAPONS_INDEPENDENCEDAY_MUSKET_AMMO", 6715, 0 },
	{ "WEAPONS_INDEPENDENCEDAY_FIREWORKLAUNCHER", 6716, 0 },
	{ "WEAPONS_INDEPENDENCEDAY_FIREWORKLAUNCHER_AMMO", 6717, 0 },
	{ "WEAPONS_INDEPENDENCEDAY_PATRIOT_PARACHUTE_SMOKE", 6718, 0 },
	{ "PROPERTY_3_ACE_JONES_DR", 6719, 0 },
	{ "PROPERTY_12_SUSTANCIA_RD", 6720, 0 },
	{ "PROPERTY_4584_PROCOPIO_DR", 6721, 0 },
	{ "PROPERTY_1893_GRAPESEED_AVE", 6725, 0 },
	{ "UNLOCKINDEPENDENCE_BEER_HAT_1", 6726, 2 },
	{ "UNLOCKINDEPENDENCE_BEER_HAT_2", 6727, 2 },
	{ "UNLOCKINDEPENDENCE_BEER_HAT_3", 6728, 2 },
	{ "UNLOCKINDEPENDENCE_BEER_HAT_4", 6729, 2 },
	{ "UNLOCKINDEPENDENCE_BEER_HAT_5", 6730, 2 },
	{ "UNLOCKINDEPENDENCE_BEER_HAT_6", 6731, 2 },
	{ "UNLOCKINDEPENDENCE_STATUE_HAPPINESS_SHIRT", 6732, 2 },
	{ "HEISTS_PREP_PERCENTAGE_CUT_SERIES_A", 6756, 1 },
	{ "MENTAL_BLOW_UP_AGGRESSIVE_VEH", 6759, 1 },
	{ "MENTAL_BLOW_UP_COP_VEH", 6760, 1 },
	{ "Contact_Mission_Time_Period_1", 6761, 0 },
	{ "Contact_Mission_Time_Period_2", 6762, 0 },
	{ "Contact_Mission_Time_Period_3", 6763, 0 },
	{ "Contact_Mission_Time_Period_4", 6764, 0 },
	{ "Contact_Mission_Time_Period_5", 6765, 0 },
	{ "Contact_Mission_Time_Period_6", 6766, 0 },
	{ "Contact_Mission_Time_Period_7", 6767, 0 },
	{ "Contact_Mission_Time_Period_8", 6768, 0 },
	{ "Contact_Mission_Time_Period_9", 6769, 0 },
	{ "Contact_Mission_Cash_Time_Period_1_PERCENTAGE", 6770, 1 },
	{ "Contact_Mission_Cash_Time_Period_2_PERCENTAGE", 6771, 1 },
	{ "Contact_Mission_Cash_Time_Period_3_PERCENTAGE", 6772, 1 },
	{ "Contact_Mission_Cash_Time_Period_4_PERCENTAGE", 6773, 1 },
	{ "Contact_Mission_Cash_Time_Period_5_PERCENTAGE", 6774, 1 },
	{ "Contact_Mission_Cash_Time_Period_6_PERCENTAGE", 6775, 1 },
	{ "Contact_Mission_Cash_Time_Period_7_PERCENTAGE", 6776, 1 },
	{ "Contact_Mission_Cash_Time_Period_8_PERCENTAGE", 6777, 1 },
	{ "Contact_Mission_Cash_Time_Period_9_PERCENTAGE", 6778, 1 },
	{ "Contact_Mission_Cash_Time_Period_10_PERCENTAGE", 6779, 1 },
	{ "CONTACT_MISSION_CASH_PLAYER_MULTIPLIER_1", 6780, 1 },
	{ "CONTACT_MISSION_CASH_PLAYER_MULTIPLIER_2", 6781, 1 },
	{ "CONTACT_MISSION_CASH_PLAYER_MULTIPLIER_3", 6782, 1 },
	{ "CONTACT_MISSION_CASH_PLAYER_MULTIPLIER_4", 6783, 1 },
	{ "CONTACT_MISSION_CASH_BASE_MULTIPLIER", 6784, 1 },
	{ "CONTACT_MISSION_CASH_RANK_CAP", 6785, 0 },
	{ "CONTACT_MISSION_CASH_BASIC_VALUE", 6786, 0 },
	{ "CONTACT_MISSION_CASH_DIFFICULTY_MULTIPLIER_EASY", 6787, 1 },
	{ "CONTACT_MISSION_CASH_DIFFICULTY_MULTIPLIER_NORMAL", 6788, 1 },
	{ "CONTACT_MISSION_CASH_DIFFICULTY_MULTIPLIER_HARD", 6789, 1 },
	{ "CONTACT_MISSION_FAIL_CASH_MINIMUM", 6790, 0 },
	{ "CONTACT_MISSION_FAIL_CASH_TIME_PERIOD_2_DIVIDER", 6791, 1 },
	{ "CONTACT_MISSION_FAIL_CASH_TIME_PERIOD_3_DIVIDER", 6792, 1 },
	{ "CONTACT_MISSION_FAIL_CASH_TIME_PERIOD_4_DIVIDER", 6793, 1 },
	{ "CONTACT_MISSION_FAIL_CASH_TIME_PERIOD_5_DIVIDER", 6794, 1 },
	{ "CONTACT_MISSION_FAIL_CASH_TIME_PERIOD_6_DIVIDER", 6795, 1 },
	{ "CONTACT_MISSION_FAIL_CASH_TIME_PERIOD_7_DIVIDER", 6796, 1 },
	{ "CONTACT_MISSION_FAIL_CASH_TIME_PERIOD_8_DIVIDER", 6797, 1 },
	{ "CONTACT_MISSION_FAIL_CASH_TIME_PERIOD_9_DIVIDER", 6798, 1 },
	{ "CONTACT_MISSION_FAIL_RP_MINIMUM", 6800, 0 },
	{ "CONTACT_MISSION_FAIL_RP_TIME_PERIOD_2_DIVIDER", 6801, 1 },
	{ "CONTACT_MISSION_FAIL_RP_TIME_PERIOD_3_DIVIDER", 6802, 1 },
	{ "CONTACT_MISSION_FAIL_RP_TIME_PERIOD_4_DIVIDER", 6803, 1 },
	{ "CONTACT_MISSION_FAIL_RP_TIME_PERIOD_5_DIVIDER", 6804, 1 },
	{ "CONTACT_MISSION_FAIL_RP_TIME_PERIOD_6_DIVIDER", 6805, 1 },
	{ "CONTACT_MISSION_FAIL_RP_TIME_PERIOD_7_DIVIDER", 6806, 1 },
	{ "CONTACT_MISSION_FAIL_RP_TIME_PERIOD_8_DIVIDER", 6807, 1 },
	{ "CONTACT_MISSION_FAIL_RP_TIME_PERIOD_9_DIVIDER", 6808, 1 },
	{ "TURNOFFSPECIALCRATES", 6810, 2 },
	{ "CONTACT_MISSION_RP_TIME_PERIOD_1_PERCENTAGE", 6811, 1 },
	{ "CONTACT_MISSION_RP_TIME_PERIOD_2_PERCENTAGE", 6812, 1 },
	{ "CONTACT_MISSION_RP_TIME_PERIOD_3_PERCENTAGE", 6813, 1 },
	{ "CONTACT_MISSION_RP_TIME_PERIOD_4_PERCENTAGE", 6814, 1 },
	{ "CONTACT_MISSION_RP_TIME_PERIOD_5_PERCENTAGE", 6815, 1 },
	{ "CONTACT_MISSION_RP_TIME_PERIOD_6_PERCENTAGE", 6816, 1 },
	{ "CONTACT_MISSION_RP_TIME_PERIOD_7_PERCENTAGE", 6817, 1 },
	{ "CONTACT_MISSION_RP_TIME_PERIOD_8_PERCENTAGE", 6818, 1 },
	{ "CONTACT_MISSION_RP_TIME_PERIOD_9_PERCENTAGE", 6819, 1 },
	{ "CONTACT_MISSION_RP_TIME_PERIOD_10_PERCENTAGE", 6820, 1 },
	{ "CONTACT_MISSION_RP_BASE_MULTIPLIER", 6821, 1 },
	{ "CONTACT_MISSION_RP_DIFFICULTY_MULTIPLIER_EASY", 6822, 1 },
	{ "CONTACT_MISSION_RP_DIFFICULTY_MULTIPLIER_NORMAL", 6823, 1 },
	{ "CONTACT_MISSION_RP_DIFFICULTY_MULTIPLIER_HARD", 6824, 1 },
	{ "CONTACT_MISSION_RP_RANK_CAP", 6825, 0 },
	{ "CONTACT_MISSION_RP_BASIC_VALUE", 6826, 0 },
	{ "PS_DEFAULT_RP_VALUE_MULTIPLIER", 6929, 1 },
	{ "PS_BRONZE_RP_MULTIPLIER", 6930, 1 },
	{ "PS_SILVER_RP_MULTIPLIER", 6931, 1 },
	{ "PS_GOLD_RP_MULTIPLIER", 6932, 1 },
	{ "PS_DEFAULT_CASH_VALUE_MULTIPLIER", 6933, 1 },
	{ "PS_BRONZE_CASH_MULTIPLIER", 6934, 1 },
	{ "PS_SILVER_CASH_MULTIPLIER", 6935, 1 },
	{ "PS_GOLD_CASH_MULTIPLIER", 6936, 1 },
	{ "PS_FIRST_CASH_BONUS_MULTIPLIER", 6937, 1 },
	{ "MUGGER_CASH_DROP_CAP", 6938, 0 },
	{ "PS_FLIGHT_CAP", 6939, 0 },
	{ "PS_FLIGHT_SUIT", 6940, 0 },
	{ "PS_EVENT_ITEM_ELITAS_TSHIRT", 6941, 0 },
	{ "PS_EVENT_ITEM_ELITAS_TOP", 6942, 0 },
	{ "PS_INVERTO_COQUETTE_CLASSIC", 6943, 0 },
	{ "PS_INVERTO_COQUETTE_CLASSIC_TOPLESS", 6944, 0 },
	{ "PS_WESTERN_BESRA", 6945, 0 },
	{ "PS_BUCKINGHAM_MILJET", 6946, 0 },
	{ "PS_SWIFT_LIVERY_1", 6947, 0 },
	{ "PS_SWIFT_LIVERY_2", 6948, 0 },
	{ "PS_AIR_FORCE_CHUTE", 6949, 0 },
	{ "PS_DESERT_CHUTE", 6950, 0 },
	{ "PS_SHADOW_CHUTE", 6951, 0 },
	{ "PS_HIGH_ALTITUDE_CHUTE", 6952, 0 },
	{ "PS_AIRBORNE_CHUTE", 6953, 0 },
	{ "PS_SUNRISE_CHUTE", 6954, 0 },
	{ "PS_USA_CHUTE_BAG", 6955, 0 },
	{ "PS_UNITED_KINGDOM_CHUTE_BAG", 6956, 0 },
	{ "PS_SCOTLAND_CHUTE_BAG", 6957, 0 },
	{ "PS_CANADA_CHUTE_BAG", 6958, 0 },
	{ "PS_FRANCE_CHUTE_BAG", 6959, 0 },
	{ "PS_GERMANY_CHUTE_BAG", 6960, 0 },
	{ "PS_SPAIN_CHUTE_BAG", 6961, 0 },
	{ "PS_AUSTRALIA_CHUTE_BAG", 6962, 0 },
	{ "PS_JAPAN_CHUTE_BAG", 6963, 0 },
	{ "PS_BRAZIL_CHUTE_BAG", 6964, 0 },
	{ "PS_ELITAS_CHUTE_BAG", 6965, 0 },
	{ "PS_FLIGHT_SCHOOL_CHUTE_BAG", 6966, 0 },
	{ "PS_EVENT_ITEM_HIGH_FLYER_CHUTE_BAG", 6967, 0 },
	{ "BLOCK_SELLING_VEHICLES", 6968, 2 },
	{ "DISABLE_EVENT_PLANE_TAKEDOWN", 6969, 2 },
	{ "DISABLE_EVENT_PLANE_TAKEDOWN", 6969, 2 },
	{ "PLANE_TAKEDOWN_REWARDS_CASH", 6970, 0 },
	{ "PLANE_TAKEDOWN_REWARDS_CASH", 6970, 0 },
	{ "PLANE_TAKEDOWN_REWARDS_XP", 6971, 0 },
	{ "PLANE_TAKEDOWN_REWARDS_XP", 6971, 0 },
	{ "DISABLE_EVENT_DISTRACT_COPS", 6974, 2 },
	{ "DISABLE_EVENT_DISTRACT_COPS", 6974, 2 },
	{ "DISABLEDESTROYVEHICLE", 6979, 2 },
	{ "NUMBER_OF_SCRIPTS_IN_HISTORY_LIST", 6985, 0 },
	{ "TIME_EVENT_FREQUENCY_AMBIENT_LAUNCHER", 6987, 0 },
	{ "GRENADE_AMMO_GIFTING", 6988, 0 },
	{ "SMKGRENADE_AMMO_GIFTING", 6989, 0 },
	{ "STKYBMB_AMMO_GIFTING", 6990, 0 },
	{ "MOLOTOV_AMMO_GIFTING", 6991, 0 },
	{ "PISTOL_AMMO_GIFTING", 6992, 0 },
	{ "SMG_AMMO_GIFTING", 6993, 0 },
	{ "RIFLE_AMMO_GIFTING", 6994, 0 },
	{ "MG_AMMO_GIFTING", 6995, 0 },
	{ "SHOTGUN_AMMO_GIFTING", 6996, 0 },
	{ "SNIPER_AMMO_GIFTING", 6997, 0 },
	{ "RPG_AMMO_GIFTING", 6998, 0 },
	{ "MINIGUNS_AMMO_GIFTING", 6999, 0 },
	{ "PETROLCAN_AMMO_GIFTING", 7000, 0 },
	{ "GRNLAUNCH_AMMO_GIFTING", 7002, 0 },
	{ "FIREWRK_AMMO_GIFTING", 7009, 0 },
	{ "ELEGY2_WEB_PRICE_MODIFIER", 7017, 0 },
	{ "KHAMELION_WEB_PRICE_MODIFIER", 7018, 0 },
	{ "HOTKNIFE_WEB_PRICE_MODIFIER", 7019, 0 },
	{ "CARBONRS_WEB_PRICE_MODIFIER", 7020, 0 },
	{ "CRATEDROPBASEWEIGHTING", 7024, 1 },
	{ "SECURITYVANBASEWEIGHTING", 7025, 1 },
	{ "IMPORTEXPORTBASEWEIGHTING", 7026, 1 },
	{ "JOYRIDERBASEWEIGHTING", 7027, 1 },
	{ "LESTERKILLTARGETBASEWEIGHTING", 7028, 1 },
	{ "PLANETAKEDOWNBASEWEIGHTING", 7029, 1 },
	{ "DISTRACTPOLICEBASEWEIGHTING", 7030, 1 },
	{ "PS_ITALY_CHUTE_BAG", 7063, 0 },
	{ "PS_SWITZERLAND_CHUTE_BAG", 7064, 0 },
	{ "PS_JAMAICA_CHUTE_BAG", 7065, 0 },
	{ "PS_COLOMBIA_CHUTE_BAG", 7066, 0 },
	{ "PS_NORWAY_CHUTE_BAG", 7067, 0 },
	{ "PS_SWEDEN_CHUTE_BAG", 7068, 0 },
	{ "PS_BELGIUM_CHUTE_BAG", 7069, 0 },
	{ "PS_MEXICO_CHUTE_BAG", 7070, 0 },
	{ "PS_AUSTRIA_CHUTE_BAG", 7071, 0 },
	{ "PS_RUSSIA_CHUTE_BAG", 7072, 0 },
	{ "PS_ARGENTINA_CHUTE_BAG", 7073, 0 },
	{ "PS_TURKEY_CHUTE_BAG", 7074, 0 },
	{ "PS_IRELAND_CHUTE_BAG", 7075, 0 },
	{ "PS_WALES_CHUTE_BAG", 7076, 0 },
	{ "PS_ENGLAND_CHUTE_BAG", 7077, 0 },
	{ "DISABLE_EVENT_KILL_TARGET", 7078, 2 },
	{ "toggle_on_bet_stake_gift_DM", 7092, 2 },
	{ "toggle_on_bet_stake_gift_RACES_CAR", 7093, 2 },
	{ "toggle_on_bet_stake_gift_RACES_CYCLE", 7094, 2 },
	{ "toggle_on_bet_stake_gift_RACES_AIR", 7095, 2 },
	{ "toggle_on_bet_stake_gift_RACES_SEA", 7096, 2 },
	{ "toggle_on_bet_stake_gift_MISSIONS", 7097, 2 },
	{ "toggle_on_bet_stake_gift_SURVIAL", 7098, 2 },
	{ "toggle_on_bet_stake_gift_BASEJUMP", 7099, 2 },
	{ "toggle_on_bet_stake_gift_CAPTURE", 7100, 2 },
	{ "toggle_on_bet_stake_gift_LTS", 7101, 2 },
	{ "CASH_REWARD_BET_STAKE_GIFT", 7102, 0 },
	{ "clothingcrewemblemsmall", 7104, 0 },
	{ "clothingcrewemblemlarge", 7105, 0 },
	{ "clothingcrewemblemback", 7106, 0 },
	{ "DISABLE_SCTV_FRIENDS_SPECTATE", 7107, 2 },
	{ "DISABLE_SCTV_GTAO_TV", 7108, 2 },
	{ "DISABLE_SCTV_DEV_SPECTATE", 7109, 2 },
	{ "LTS_M_BLACK_BULLETPROOF", 7112, 0 },
	{ "LTS_M_GRAY_BULLETPROOF", 7113, 0 },
	{ "LTS_M_CHARCOAL_BULLETPROOF", 7114, 0 },
	{ "LTS_M_TAN_BULLETPROOF", 7115, 0 },
	{ "LTS_M_FOREST_BULLETPROOF", 7116, 0 },
	{ "LTS_M_BLACK_COMBAT_PANTS", 7117, 0 },
	{ "LTS_M_GRAY_COMBAT_PANTS", 7118, 0 },
	{ "LTS_M_CHARCOAL_COMBAT_PANTS", 7119, 0 },
	{ "LTS_M_TAN_COMBAT_PANTS", 7120, 0 },
	{ "LTS_M_FOREST_COMBAT_PANTS", 7121, 0 },
	{ "LTS_M_BLACK_COMBAT_TOP", 7122, 0 },
	{ "LTS_M_GRAY_COMBAT_TOP", 7123, 0 },
	{ "LTS_M_CHARCOAL_COMBAT_TOP", 7124, 0 },
	{ "LTS_M_TAN_COMBAT_TOP", 7125, 0 },
	{ "LTS_M_FOREST_COMBAT_TOP", 7126, 0 },
	{ "LTS_M_BLACK_COMBAT_SWEATER", 7127, 0 },
	{ "LTS_M_GRAY_COMBAT_SWEATER", 7128, 0 },
	{ "LTS_M_CHARCOAL_COMBAT_SWEATER", 7129, 0 },
	{ "LTS_M_TAN_COMBAT_SWEATER", 7130, 0 },
	{ "LTS_M_GREEN_COMBAT_SWEATER", 7131, 0 },
	{ "LTS_M_BLACK_COMBAT_MASK", 7132, 0 },
	{ "LTS_M_GRAY_COMBAT_MASK", 7133, 0 },
	{ "LTS_M_CHARCOAL_COMBAT_MASK", 7134, 0 },
	{ "LTS_M_TAN_COMBAT_MASK", 7135, 0 },
	{ "LTS_M_FOREST_COMBAT_MASK", 7136, 0 },
	{ "LTS_M_BLACK_SKELETAL", 7137, 0 },
	{ "LTS_M_GRAY_SKELETAL", 7138, 0 },
	{ "LTS_M_CHARCOAL_SKELETAL", 7139, 0 },
	{ "LTS_M_TAN_SKELETAL", 7140, 0 },
	{ "LTS_M_GREEN_SKELETAL", 7141, 0 },
	{ "LTS_M_BLACK_TACT_GLOVES", 7142, 0 },
	{ "LTS_M_GRAY_TACT_GLOVES", 7143, 0 },
	{ "LTS_M_CHARCOAL_TACT_GLOVES", 7144, 0 },
	{ "LTS_M_TAN_TACT_GLOVES", 7145, 0 },
	{ "LTS_M_FOREST_TACT_GLOVES", 7146, 0 },
	{ "LTS_M_BLACK_WOOL_GLOVES", 7147, 0 },
	{ "LTS_M_GRAY_WOOL_GLOVES", 7148, 0 },
	{ "LTS_M_CHARCOAL_WOOL_GLOVES", 7149, 0 },
	{ "LTS_M_TAN_WOOL_GLOVES", 7150, 0 },
	{ "LTS_M_GREEN_WOOL_GLOVES", 7151, 0 },
	{ "LTS_F_BLACK_BULLETPROOF", 7152, 0 },
	{ "LTS_F_GRAY_BULLETPROOF", 7153, 0 },
	{ "LTS_F_CHARCOAL_BULLETPROOF", 7154, 0 },
	{ "LTS_F_TAN_BULLETPROOF", 7155, 0 },
	{ "LTS_F_FOREST_BULLETPROOF", 7156, 0 },
	{ "LTS_F_BLACK_COMBAT_PANTS", 7157, 0 },
	{ "LTS_F_GRAY_COMBAT_PANTS", 7158, 0 },
	{ "LTS_F_CHARCOAL_COMBAT_PANTS", 7159, 0 },
	{ "LTS_F_TAN_COMBAT_PANTS", 7160, 0 },
	{ "LTS_F_FOREST_COMBAT_PANTS", 7161, 0 },
	{ "LTS_F_BLACK_COMBAT_TOP", 7162, 0 },
	{ "LTS_F_GRAY_COMBAT_TOP", 7163, 0 },
	{ "LTS_F_CHARCOAL_COMBAT_TOP", 7164, 0 },
	{ "LTS_F_TAN_COMBAT_TOP", 7165, 0 },
	{ "LTS_F_FOREST_COMBAT_TOP", 7166, 0 },
	{ "LTS_F_BLACK_COMBAT_SWEATER", 7167, 0 },
	{ "LTS_F_GRAY_COMBAT_SWEATER", 7168, 0 },
	{ "LTS_F_CHARCOAL_COMBAT_SWEATER", 7169, 0 },
	{ "LTS_F_TAN_COMBAT_SWEATER", 7170, 0 },
	{ "LTS_F_GREEN_COMBAT_SWEATER", 7171, 0 },
	{ "LTS_F_BLACK_COMBAT_MASK", 7172, 0 },
	{ "LTS_F_GRAY_COMBAT_MASK", 7173, 0 },
	{ "LTS_F_CHARCOAL_COMBAT_MASK", 7174, 0 },
	{ "LTS_F_TAN_COMBAT_MASK", 7175, 0 },
	{ "LTS_F_FOREST_COMBAT_MASK", 7176, 0 },
	{ "LTS_F_BLACK_SKELETAL", 7177, 0 },
	{ "LTS_F_GRAY_SKELETAL", 7178, 0 },
	{ "LTS_F_CHARCOAL_SKELETAL", 7179, 0 },
	{ "LTS_F_TAN_SKELETAL", 7180, 0 },
	{ "LTS_F_GREEN_SKELETAL", 7181, 0 },
	{ "LTS_F_BLACK_TACT_GLOVES", 7182, 0 },
	{ "LTS_F_GRAY_TACT_GLOVES", 7183, 0 },
	{ "LTS_F_CHARCOAL_TACT_GLOVES", 7184, 0 },
	{ "LTS_F_TAN_TACT_GLOVES", 7185, 0 },
	{ "LTS_F_FOREST_TACT_GLOVES", 7186, 0 },
	{ "LTS_F_BLACK_WOOL_GLOVES", 7187, 0 },
	{ "LTS_F_GRAY_WOOL_GLOVES", 7188, 0 },
	{ "LTS_F_CHARCOAL_WOOL_GLOVES", 7189, 0 },
	{ "LTS_F_TAN_WOOL_GLOVES", 7190, 0 },
	{ "LTS_F_GREEN_WOOL_GLOVES", 7191, 0 },
	{ "LTS_M_THE_HEAVY_NIGHT", 7192, 1 },
	{ "LTS_M_THE_HEAVY_URBAN", 7193, 1 },
	{ "LTS_M_THE_HEAVY_STEEL", 7194, 1 },
	{ "LTS_M_THE_HEAVY_TUNDRA", 7195, 1 },
	{ "LTS_M_THE_HEAVY_FOREST", 7196, 1 },
	{ "LTS_M_THE_MASKED_NIGHT", 7197, 1 },
	{ "LTS_M_THE_MASKED_URBAN", 7198, 1 },
	{ "LTS_M_THE_MASKED_STEEL", 7199, 1 },
	{ "LTS_M_THE_MASKED_TUNDRA", 7200, 1 },
	{ "LTS_M_THE_MASKED_FOREST", 7201, 1 },
	{ "LTS_M_THE_NIGHT", 7202, 1 },
	{ "LTS_M_THE_URBAN", 7203, 1 },
	{ "LTS_M_THE_STEEL", 7204, 1 },
	{ "LTS_M_THE_TUNDRA", 7205, 1 },
	{ "LTS_M_THE_FOREST", 7206, 1 },
	{ "LTS_F_THE_HEAVY_NIGHT", 7207, 1 },
	{ "LTS_F_THE_HEAVY_URBAN", 7208, 1 },
	{ "LTS_F_THE_HEAVY_STEEL", 7209, 1 },
	{ "LTS_F_THE_HEAVY_TUNDRA", 7210, 1 },
	{ "LTS_F_THE_HEAVY_FOREST", 7211, 1 },
	{ "LTS_F_THE_MASKED_NIGHT", 7212, 1 },
	{ "LTS_F_THE_MASKED_URBAN", 7213, 1 },
	{ "LTS_F_THE_MASKED_STEEL", 7214, 1 },
	{ "LTS_F_THE_MASKED_TUNDRA", 7215, 1 },
	{ "LTS_F_THE_MASKED_FOREST", 7216, 1 },
	{ "LTS_F_THE_NIGHT", 7217, 1 },
	{ "LTS_F_THE_URBAN", 7218, 1 },
	{ "LTS_F_THE_STEEL", 7219, 1 },
	{ "LTS_F_THE_TUNDRA", 7220, 1 },
	{ "LTS_F_THE_FOREST", 7221, 1 },
	{ "LTS_M_EVENT_ITEM_VICTORY_FIST_TSHIRT", 7222, 0 },
	{ "LTS_F_EVENT_ITEM_VICTORY_FIST_TOP", 7223, 0 },
	{ "LTS_M_EVENT_ITEM_PLEASE_STOP_ME_HOCKEY", 7224, 0 },
	{ "LTS_LCC_INNOVATION", 7225, 0 },
	{ "LTS_SHITZU_HAKUCHOU", 7226, 0 },
	{ "LTS_LAMPADATI_FURORE_GT", 7227, 0 },
	{ "LTS_CANIS_KALAHARI_TOPLESS", 7228, 0 },
	{ "LTS_HEAVY_SHOTGUN", 7229, 0 },
	{ "LTS_HEAVY_SHOTGUN_EXTENDED_CLIP", 7230, 0 },
	{ "LTS_HEAVY_SHOTGUN_FLASHLIGHT", 7231, 0 },
	{ "LTS_HEAVY_SHOTGUN_SUPPRESSOR", 7232, 0 },
	{ "LTS_HEAVY_SHOTGUN_GRIP", 7233, 0 },
	{ "LTS_HEAVY_SHOTGUN_AMMO", 7234, 0 },
	{ "LTS_MARKSMAN_RIFLE", 7235, 0 },
	{ "LTS_MARKSMAN_RIFLE_EXTENDED_CLIP", 7236, 0 },
	{ "LTS_MARKSMAN_RIFLE_FLASHLIGHT", 7237, 0 },
	{ "LTS_MARKSMAN_RIFLE_SCOPE", 7238, 0 },
	{ "LTS_MARKSMAN_RIFLE_SUPPRESSOR", 7239, 0 },
	{ "LTS_MARKSMAN_RIFLE_GRIP", 7240, 0 },
	{ "LTS_MARKSMAN_RIFLE_AMMO", 7242, 0 },
	{ "LTS_FINLAND_CHUTE_BAG", 7243, 0 },
	{ "LTS_DENMARK_CHUTE_BAG", 7244, 0 },
	{ "LTS_NETHERLANDS_CHUTE_BAG", 7245, 0 },
	{ "LTS_PORTUGAL_CHUTE_BAG", 7246, 0 },
	{ "LTS_CHINA_CHUTE_BAG", 7247, 0 },
	{ "LTS_CROATIA_CHUTE_BAG", 7248, 0 },
	{ "LTS_CZECH_REPUBLIC_CHUTE_BAG", 7249, 0 },
	{ "LTS_HUNGARY_CHUTE_BAG", 7250, 0 },
	{ "LTS_LIECHTENSTEIN_CHUTE_BAG", 7251, 0 },
	{ "LTS_MALTA_CHUTE_BAG", 7252, 0 },
	{ "LTS_NEW_ZEALAND_CHUTE_BAG", 7253, 0 },
	{ "LTS_NIGERIA_CHUTE_BAG", 7254, 0 },
	{ "LTS_POLAND_CHUTE_BAG", 7255, 0 },
	{ "LTS_PUERTO_RICO_CHUTE_BAG", 7256, 0 },
	{ "LTS_SLOVAKIA_CHUTE_BAG", 7257, 0 },
	{ "LTS_SLOVENIA_CHUTE_BAG", 7258, 0 },
	{ "LTS_SOUTH_AFRICA_CHUTE_BAG", 7259, 0 },
	{ "LTS_SOUTH_KOREA_CHUTE_BAG", 7260, 0 },
	{ "LTS_PALESTINE_CHUTE_BAG", 7261, 0 },
	{ "LTS_ISRAEL_CHUTE_BAG", 7262, 0 },
	{ "DLC_WEAPON_TINT_GOLD_VINTAGE_PISTOL", 7264, 0 },
	{ "DLC_WEAPON_TINT_PLATINUM_VINTAGE_PISTOL", 7265, 0 },
	{ "DLC_WEAPON_TINT_ARMY_VINTAGE_PISTOL", 7266, 0 },
	{ "DLC_WEAPON_TINT_GREEN_VINTAGE_PISTOL", 7267, 0 },
	{ "DLC_WEAPON_TINT_ORANGE_VINTAGE_PISTOL", 7268, 0 },
	{ "DLC_WEAPON_TINT_LSPD_VINTAGE_PISTOL", 7269, 0 },
	{ "DLC_WEAPON_TINT_PINK_VINTAGE_PISTOL", 7270, 0 },
	{ "DLC_WEAPON_TINT_GOLD_MARKSMAN_RIFLE", 7271, 0 },
	{ "DLC_WEAPON_TINT_PLATINUM_MARKSMAN_RIFLE", 7272, 0 },
	{ "DLC_WEAPON_TINT_ARMY_MARKSMAN_RIFLE", 7273, 0 },
	{ "DLC_WEAPON_TINT_GREEN_MARKSMAN_RIFLE", 7274, 0 },
	{ "DLC_WEAPON_TINT_ORANGE_MARKSMAN_RIFLE", 7275, 0 },
	{ "DLC_WEAPON_TINT_LSPD_MARKSMAN_RIFLE", 7276, 0 },
	{ "DLC_WEAPON_TINT_PINK_MARKSMAN_RIFLE", 7277, 0 },
	{ "DLC_WEAPON_TINT_GOLD_HEAVY_SHOTGUN", 7278, 0 },
	{ "DLC_WEAPON_TINT_PLATINUM_HEAVY_SHOTGUN", 7279, 0 },
	{ "DLC_WEAPON_TINT_ARMY_HEAVY_SHOTGUN", 7280, 0 },
	{ "DLC_WEAPON_TINT_GREEN_HEAVY_SHOTGUN", 7281, 0 },
	{ "DLC_WEAPON_TINT_ORANGE_HEAVY_SHOTGUN", 7282, 0 },
	{ "DLC_WEAPON_TINT_LSPD_HEAVY_SHOTGUN", 7283, 0 },
	{ "DLC_WEAPON_TINT_PINK_HEAVY_SHOTGUN", 7284, 0 },
	{ "OBJECTIVE_POOL_SIZE", 7288, 0 },
	{ "DISABLE_QUEUING_SYSTEM", 7405, 2 },
	{ "DESTROYVEHICLEBASEWEIGHTING", 7411, 1 },
	{ "DISABLE_QUICK_FIX_VEH", 7412, 2 },
	{ "SKIP_SAVE_MIGRATION_STATUS", 7413, 2 },
	{ "USE_DAILY_OBJECTIVE_LIMITED_POOL", 7417, 2 },
	{ "NUM_JOB_OBJECTIVES_IN_POOL", 7418, 0 },
	{ "VEHICLES_HEIST_BRUTE_BOXVILLE", 7458, 0 },
	{ "VEHICLES_HEIST_DINKA_ENDURO", 7461, 0 },
	{ "VEHICLES_HEIST_MAMMOTH_HYDRA", 7464, 0 },
	{ "VEHICLES_HEIST_HVY_INSURGENT_PICKUP", 7465, 0 },
	{ "VEHICLES_HEIST_HVY_INSURGENT", 7466, 0 },
	{ "VEHICLES_HEIST_PRINCIPE_LECTRO", 7469, 0 },
	{ "VEHICLES_HEIST_MAIBATSU_MULE", 7470, 0 },
	{ "VEHICLES_HEIST_SAVAGE", 7471, 0 },
	{ "VEHICLES_HEIST_KARIN_TECHNICAL", 7472, 0 },
	{ "VEHICLES_HEIST_BUCKINGHAM_VALKYRIE", 7473, 0 },
	{ "Vehicles_Heist_Pbus", 7475, 0 },
	{ "VEHICLES_HEIST_MESA3", 7476, 0 },
	{ "DLC_WEAPON_MARKSMAN_PISTOL_AMMO", 7486, 0 },
	{ "DLC_WEAPON_REVOLVER_AMMO", 7494, 0 },
	{ "HEIST_SERIES_A_FUNDING_CASH_REWARD", 7504, 0 },
	{ "CASH_REWARD_OVERRIDE_ELITE_OBJECTIVES_SERIES_A", 7509, 0 },
	{ "toggle_gift_to_player_when_logging_on", 7548, 2 },
	{ "CGTONG_CHEVAL_MARSHALL", 7554, 0 },
	{ "VEHICLEWEBSITE_SALE", 7564, 2 },
	{ "DISABLE_PURCHASE_OF_THIRD_PROPERTY", 7751, 2 },
	{ "DISABLE_TRANSFER_VEHICLE_BETWEEN_GARAGE", 7752, 2 },
	{ "DISABLE_SNOWBALLS", 7753, 2 },
	{ "DISABLE_CHRISTMAS_TREE_PERISHING_SQUARE_SNOW", 7754, 2 },
	{ "DISABLE_CHRISTMAS_TREE_PERISHING_SQUARE", 7755, 2 },
	{ "DISABLE_CHRISTMAS_TREE_APARTMENT", 7756, 2 },
	{ "DISABLE_CHRISTMAS_CLOTHING", 7757, 2 },
	{ "DISABLE_CHRISTMAS_MASKS", 7758, 2 },
	{ "DISABLE_CHRISTMAS_VEHICLES", 7759, 2 },
	{ "MAX_NUMBER_OF_SNOWBALLS", 7760, 0 },
	{ "PICK_UP_NUMBER_OF_SNOWBALLS", 7761, 0 },
	{ "VEHICLE_XMAS14_DINKA_JESTER_RACECAR", 7762, 0 },
	{ "VEHICLE_XMAS14_DEWBAUCHEE_MASSACRO_RACECAR", 7763, 0 },
	{ "VEHICLE_XMAS14_RAT_TRUCK", 7764, 0 },
	{ "VEHICLE_XMAS14_SLAMVAN", 7765, 0 },
	{ "VEHICLE_XMAS14_BRAVADO_SPRUNK_BUFFALO", 7766, 0 },
	{ "VEHICLE_XMAS14_VAPID_PISSWASSER_DOMINATOR", 7767, 0 },
	{ "VEHICLE_XMAS14_BRAVADO_REDWOOD_GAUNTLET", 7768, 0 },
	{ "VEHICLE_XMAS14_DECLASSE_BURGER_SHOT_STALLION", 7769, 0 },
	{ "WEAPONS_XMAS14_HOMING_LAUNCHER", 7770, 0 },
	{ "WEAPONS_XMAS14_HOMING_LAUNCHER_AMMO", 7771, 0 },
	{ "WEAPONS_XMAS14_PROXIMITY_MINE", 7772, 0 },
	{ "WEAPONS_XMAS14_BLACK_COMBAT_CHUTE_BAG", 7773, 0 },
	{ "WEAPONS_XMAS14_GRAY_COMBAT_CHUTE_BAG", 7774, 0 },
	{ "WEAPONS_XMAS14_CHARCOAL_COMBAT_CHUTE_BAG", 7775, 0 },
	{ "WEAPONS_XMAS14_TAN_COMBAT_CHUTE_BAG", 7776, 0 },
	{ "WEAPONS_XMAS14_FOREST_COMBAT_CHUTE_BAG", 7777, 0 },
	{ "TATTOOS_XMAS14_SKULL_RIDER", 7778, 0 },
	{ "TATTOOS_XMAS14_SPIDER_OUTLINE", 7779, 0 },
	{ "TATTOOS_XMAS14_SPIDER_COLOR", 7780, 0 },
	{ "TATTOOS_XMAS14_SNAKE_OUTLINE", 7781, 0 },
	{ "TATTOOS_XMAS14_SNAKE_SHADED", 7782, 0 },
	{ "TATTOOS_XMAS14_CARP_OUTLINE", 7783, 0 },
	{ "TATTOOS_XMAS14_CARP_SHADED", 7784, 0 },
	{ "TATTOOS_XMAS14_LOS_MUERTOS", 7785, 0 },
	{ "TATTOOS_XMAS14_DEATH_BEFORE_DISHONOR", 7786, 0 },
	{ "TATTOOS_XMAS14_TIME_TO_DIE", 7787, 0 },
	{ "TATTOOS_XMAS14_ELECTRIC_SNAKE", 7788, 0 },
	{ "TATTOOS_XMAS14_ROARING_TIGER", 7789, 0 },
	{ "TATTOOS_XMAS14_8_BALL_SKULL", 7790, 0 },
	{ "TATTOOS_XMAS14_LIZARD", 7791, 0 },
	{ "TATTOOS_XMAS14_FLORAL_DAGGER", 7792, 0 },
	{ "TATTOOS_XMAS14_JAPANESE_WARRIOR", 7793, 0 },
	{ "TATTOOS_XMAS14_LOOSE_LIPS_OUTLINE", 7794, 0 },
	{ "TATTOOS_XMAS14_LOOSE_LIPS_COLOR", 7795, 0 },
	{ "TATTOOS_XMAS14_ROYAL_DAGGER_OUTLINE", 7796, 0 },
	{ "TATTOOS_XMAS14_ROYAL_DAGGER_COLOR", 7797, 0 },
	{ "TATTOOS_XMAS14_TIMES_UP_OUTLINE", 7798, 0 },
	{ "TATTOOS_XMAS14_TIMES_UP_COLOR", 7799, 0 },
	{ "TATTOOS_XMAS14_YOURE_NEXT_OUTLINE", 7800, 0 },
	{ "TATTOOS_XMAS14_YOURE_NEXT_COLOR", 7801, 0 },
	{ "TATTOOS_XMAS14_SNAKE_HEAD_OUTLINE", 7802, 0 },
	{ "TATTOOS_XMAS14_SNAKE_HEAD_COLOR", 7803, 0 },
	{ "TATTOOS_XMAS14_FUCK_LUCK_OUTLINE", 7804, 0 },
	{ "TATTOOS_XMAS14_FUCK_LUCK_COLOR", 7805, 0 },
	{ "TATTOOS_XMAS14_EXECUTIONER", 7806, 0 },
	{ "TATTOOS_XMAS14_BEAUTIFUL_DEATH", 7807, 0 },
	{ "TOGGLE_CHRISTMAS_EVE_GIFT", 7808, 2 },
	{ "TOGGLE_NEW_YEARS_EVE_GIFT", 7809, 2 },
	{ "TOGGLE_NEW_YEARS_DAY_GIFT", 7810, 2 },
	{ "HESIT_VEHICLE_PRICE_PRINCIPLE_NEMESIS", 8256, 0 },
	{ "HESIT_GEAR_PRICE_NIGHT_VISION", 8262, 0 },
	{ "HESIT_GEAR_PRICE_REBREATHER", 8263, 0 },
	{ "HESIT_GEAR_PRICE_LCD_EARPIECE", 8264, 0 },
	{ "HESIT_GEAR_PRICE_RED_EARPIECE", 8265, 0 },
	{ "HESIT_GEAR_PRICE_GRAY_EARPIECE", 8266, 0 },
	{ "MALE_UPPERS_STEALTH_UTILITY_VEST", 8302, 0 },
	{ "MALE_UPPERS_HEAVY_UTILITY_VEST", 8303, 0 },
	{ "FEMALE_UPPERS_STEALTH_UTILITY_VEST", 8429, 0 },
	{ "FEMALE_UPPERS_HEAVY_UTILITY_VEST", 8430, 0 },
	{ "MALE_AND_FEMALE_OUTFITS_THE_SCIENTIST", 8516, 0 },
	{ "MALE_AND_FEMALE_OUTFITS_THE_HAZARD", 8517, 0 },
	{ "MALE_AND_FEMALE_OUTFITS_THE_QUARANTINE", 8519, 0 },
	{ "MALE_AND_FEMALE_OUTFITS_FLIGHT_SUITS_THE_FIGHTER", 8548, 1 },
	{ "FEMALE_UPPERS_BLACK_HEAVY_UTILITY_VEST", 8761, 0 },
	{ "NUMBER_OF_VEHICLES_SOLD_IN_A_DAY", 8784, 0 },
	{ "CAPS_ARE_ENFORED", 8841, 2 },
	{ "THRESHOLD_NO_OF_CARS", 8842, 0 },
	{ "THRESHOLD_NO_OF_MINUTES", 8843, 0 },
	{ "CAP_FOR_EXPLOIT_LEVEL_1", 8846, 0 },
	{ "CAP_FOR_EXPLOIT_LEVEL_2", 8847, 0 },
	{ "CAP_FOR_EXPLOIT_LEVEL_3", 8848, 0 },
	{ "CAP_FOR_EXPLOIT_LEVEL_4", 8849, 0 },
	{ "CAP_FOR_EXPLOIT_LEVEL_5", 8850, 0 },
	{ "CAP_FOR_EXPLOIT_LEVEL_6", 8851, 0 },
	{ "CAP_FOR_EXPLOIT_LEVEL_7", 8852, 0 },
	{ "NUMBER_OF_MINUTES_FOR_CAP_RECOVERY", 8853, 0 },
	{ "CURRENTVEHICLESALESSEASON", 8862, 0 },
	{ "REPEAT_OFFENDERS_CAPS_ARE_ENFORCED", 8869, 2 },
	{ "CURRENTVEHICLESALESTUSEASON", 8880, 0 },
	{ "PERMANENTCAPREPEATOFFENDER1", 8881, 0 },
	{ "PERMANENTCAPREPEATOFFENDER2", 8882, 0 },
	{ "LUXE1_WEBSITE_BUCKINGHAM_LUXOR_DELUXE", 9227, 0 },
	{ "LUXE1_AMMO_COMBAT_PDW_AMMO", 9241, 0 },
	{ "ENABLEPVCLEANUP", 9244, 2 },
	{ "LUXE2_DINKA_VINDICATOR", 9518, 0 },
	{ "CHALLENGE_EOM_DEFAULT_RP_REWARD", 9559, 0 },
	{ "HOT_PROPERTY_EOM_DEFAULT_RP_REWARD", 9592, 0 },
	{ "KING_OF_THE_CASTLE_EOM_DEFAULT_RP_REWARD", 9621, 0 },
	{ "PASS_THE_PARCEL_EOM_DEFAULT_RP_REWARD", 9637, 0 },
	{ "PENNED_IN_PEN_FINISHING_SIZE", 9773, 1 },
	{ "KING_OF_THE_CASTLE_DISABLE_VARIANT_1", 9822, 2 },
	{ "KING_OF_THE_CASTLE_DISABLE_VARIANT_2", 9823, 2 },
	{ "KING_OF_THE_CASTLE_DISABLE_VARIANT_3", 9824, 2 },
	{ "KING_OF_THE_CASTLE_DISABLE_VARIANT_4", 9825, 2 },
	{ "KING_OF_THE_CASTLE_DISABLE_VARIANT_5", 9826, 2 },
	{ "KING_OF_THE_CASTLE_DISABLE_VARIANT_6", 9827, 2 },
	{ "KING_OF_THE_CASTLE_DISABLE_VARIANT_7", 9828, 2 },
	{ "KING_OF_THE_CASTLE_DISABLE_VARIANT_8", 9829, 2 },
	{ "HOT_TARGET_MINIMUM_PARTICIPATION_RP", 9876, 0 },
	{ "KILL_LIST_MINIMUM_PARTICIPATION_RP", 9883, 0 },
	{ "CHECKPOINT_MINIMUM_PARTICIPATION_RP", 9904, 0 },
	{ "HELICOPTER_HOT_TARGET_MINIMUM_PARTICIPATION_RP", 9910, 0 },
	{ "DEAD_DROP_MINIMUM_PARTICIPATION_RP", 9937, 0 },
	{ "COMP_KILL_LIST_MINIMUM_PARTICIPATION_RP", 9944, 0 },
	{ "HUNT_THE_BEAST_MINIMUM_PARTICIPATION_RP", 9964, 0 },
	{ "CRIMINAL_DAMAGE_EVENT_MULTIPLIER_RP", 10064, 1 },
	{ "HUNT_THE_BEAST_EVENT_MULTIPLIER_RP", 10066, 1 },
	{ "KILL_LIST_EVENT_MULTIPLIER_RP", 10068, 1 },
	{ "KILL_LIST_COMPETITIVE_EVENT_MULTIPLIER_RP", 10070, 1 },
	{ "PENNED_IN_EVENT_MULTIPLIER_RP", 10072, 1 },
	{ "CHECKPOINTS_EVENT_MULTIPLIER_RP", 10074, 1 },
	{ "CHALLENGE_EVENT_MULTIPLIER_RP", 10076, 1 },
	{ "MOVING_TARGET_EVENT_MULTIPLIER_RP", 10080, 1 },
	{ "HELI_MOVING_TARGET_EVENT_MULTIPLIER_RP", 10082, 1 },
	{ "HOLD_THE_WHEEL_EVENT_MULTIPLIER_RP", 10084, 1 },
	{ "HOT_PROPERTY_EVENT_MULTIPLIER_RP", 10086, 1 },
	{ "DEAD_DROP_EVENT_MULTIPLIER_RP", 10088, 1 },
	{ "KING_OF_THE_CASTLE_EVENT_MULTIPLIER_RP", 10090, 1 },
	{ "DLC_SHIRT_NELSON_IN_NAPLES", 10112, 2 },
	{ "DLC_SHIRT_AN_AMERICAN_DIVORCE", 10114, 2 },
	{ "TURN_ON_VALENTINE_WEAPON", 10182, 2 },
	{ "TURN_ON_VALENTINE_VEHICLE", 10183, 2 },
	{ "TURN_ON_VALENTINE_MASKS", 10184, 2 },
	{ "TURN_ON_VALENTINE_HAIR", 10185, 2 },
	{ "TURN_ON_VALENTINE_CLOTHING", 10186, 2 },
	{ "TURN_ON_HALLOWEEN_WEAPONS", 10203, 2 },
	{ "TURN_ON_HALLOWEEN_ANIMS", 10210, 2 },
	{ "CAR_MODS_BLACK_MARIACHI_BOBBLEHEAD", 10501, 0 },
	{ "CAR_MODS_GREEN_MARIACHI_BOBBLEHEAD", 10502, 0 },
	{ "CAR_MODS_BLUE_MARIACHI_BOBBLEHEAD", 10503, 0 },
	{ "CAR_MODS_BOARS_BOBBLEHEAD", 10504, 0 },
	{ "CAR_MODS_CORKERS_BOBBLEHEAD", 10505, 0 },
	{ "CAR_MODS_FEUD_BOBBLEHEAD", 10506, 0 },
	{ "CAR_MODS_PANIC_BOBBLEHEAD", 10507, 0 },
	{ "CAR_MODS_SALAMANDERS_BOBBLEHEAD", 10508, 0 },
	{ "CAR_MODS_LIBERTY_BOBBLEHEAD", 10509, 0 },
	{ "CAR_MODS_LS_SHRIMPS_BOBBLEHEAD", 10510, 0 },
	{ "CAR_MODS_LC_WRATH_BOBBLEHEAD", 10511, 0 },
	{ "CAR_MODS_POUNDERS_BOBBLEHEAD", 10512, 0 },
	{ "CAR_MODS_BOOKWORMS_BOBBLEHEAD", 10513, 0 },
	{ "CAR_MODS_MAGNETICS_BOBBLEHEAD", 10514, 0 },
	{ "CAR_MODS_LSC_BOBBLEHEAD", 10515, 0 },
	{ "CAR_MODS_OG_BOBBLEHEAD", 10516, 0 },
	{ "CAR_MODS_IMPOTENT_RAGE_BOBBLEHEAD", 10517, 0 },
	{ "CAR_MODS_VINTAGE_IMPOTENT_RAGE_BOBBLEHEAD", 10518, 0 },
	{ "CAR_MODS_WHITE_POGO_BOBBLEHEAD", 10519, 0 },
	{ "CAR_MODS_RED_POGO_BOBBLEHEAD", 10520, 0 },
	{ "CAR_MODS_GRIM_REAPER_BOBBLEHEAD", 10521, 0 },
	{ "CAR_MODS_SUPERMOD_SLOT_STOCK_COLUMN_SHIFT_LEVER", 10530, 0 },
	{ "CAR_MODS_SUPERMOD_SLOT_STOCK_PLAQUE", 10531, 0 },
	{ "PRIMARY_MACHINE_PISTOL", 10570, 0 },
	{ "AMMO_MACHINE_PISTOL_AMMO", 10572, 0 },
	{ "HALLOWEEN_2015_BRUNETTE_CORPSE_BRIDE_BOBBLEHEAD", 10708, 0 },
	{ "HALLOWEEN_2015_WHITE_CORPSE_BRIDE_BOBBLEHEAD", 10709, 0 },
	{ "HALLOWEEN_2015_PINK_CORPSE_BRIDE_BOBBLEHEAD", 10710, 0 },
	{ "HALLOWEEN_2015_WHITE_MASK_SLASHER_BOBBLEHEAD", 10711, 0 },
	{ "HALLOWEEN_2015_RED_MASK_SLASHER_BOBBLEHEAD", 10712, 0 },
	{ "HALLOWEEN_2015_YELLOW_MASK_SLASHER_BOBBLEHEAD", 10713, 0 },
	{ "HALLOWEEN_2015_BLUE_ZOMBIE_BOBBLEHEAD", 10714, 0 },
	{ "HALLOWEEN_2015_GREEN_ZOMBIE_BOBBLEHEAD", 10715, 0 },
	{ "HALLOWEEN_2015_PALE_ZOMBIE_BOBBLEHEAD", 10716, 0 },
	{ "HALLOWEEN_2015_POSSESSED_URCHIN_BOBBLEHEAD", 10717, 0 },
	{ "HALLOWEEN_2015_DEMONIC_URCHIN_BOBBLEHEAD", 10718, 0 },
	{ "HALLOWEEN_2015_GRUESOME_URCHIN_BOBBLEHEAD", 10719, 0 },
	{ "HALLOWEEN_2015_TUXEDO_FRANK_BOBBLEHEAD", 10720, 0 },
	{ "HALLOWEEN_2015_PURPLE_SUIT_FRANK_BOBBLEHEAD", 10721, 0 },
	{ "HALLOWEEN_2015_STRIPED_SUIT_FRANK_BOBBLEHEAD", 10722, 0 },
	{ "HALLOWEEN_2015_BLACK_MUMMY_BOBBLEHEAD", 10723, 0 },
	{ "HALLOWEEN_2015_WHITE_MUMMY_BOBBLEHEAD", 10724, 0 },
	{ "HALLOWEEN_2015_BROWN_MUMMY_BOBBLEHEAD", 10725, 0 },
	{ "HALLOWEEN_2015_PALE_WEREWOLF_BOBBLEHEAD", 10726, 0 },
	{ "HALLOWEEN_2015_DARK_WEREWOLF_BOBBLEHEAD", 10727, 0 },
	{ "HALLOWEEN_2015_GREY_WEREWOLF_BOBBLEHEAD", 10728, 0 },
	{ "HALLOWEEN_2015_FLESHY_VAMPIRE_BOBBLEHEAD", 10729, 0 },
	{ "TURN_ON_HALLOWEEN_SOUNDS", 10847, 2 },
	{ "XMAS2015_VEHICLE", 10855, 2 },
	{ "PROPERTYWEBSITE_SALE", 11325, 2 },
	{ "APARTMENT_WEBSITE_BENEFACTOR_SCHAFTER_TURRETED_LIMO", 11409, 0 },
	{ "APARTMENT_WEBSITE_BUCKINGHAM_SUPERVOLITO", 11417, 0 },
	{ "APARTMENT_WEBSITE_BUCKINGHAM_SUPERVOLITO_CARBON", 11418, 0 },
	{ "APARTMENT_CAR_MODSECLIPSE_TOWERS_PENTHOUSE_SUITE_1", 11457, 0 },
	{ "APARTMENT_CAR_MODSECLIPSE_TOWERS_PENTHOUSE_SUITE_2", 11458, 0 },
	{ "APARTMENT_CAR_MODSECLIPSE_TOWERS_PENTHOUSE_SUITE_3", 11459, 0 },
	{ "APARTMENT_CAR_MODSSTILT_3655_WILD_OATS_DRIVE", 11460, 0 },
	{ "APARTMENT_CAR_MODSSTILT_2044_NORTH_CONKER_AVENUE", 11461, 0 },
	{ "APARTMENT_CAR_MODSSTILT_2868_HILLCREST_AVENUE", 11462, 0 },
	{ "APARTMENT_CAR_MODSSTILT_2862_HILLCREST_AVENUE", 11463, 0 },
	{ "APARTMENT_CAR_MODSSTILT_3677_WHISPYMOUND_DRIVE", 11464, 0 },
	{ "APARTMENT_CAR_MODSSTILT_2117_MILTON_ROAD", 11465, 0 },
	{ "APARTMENT_CAR_MODSSTILT_2866_HILLCREST_AVENUE", 11466, 0 },
	{ "APARTMENT_CAR_MODSSTILT_2874_HILLCREST_AVENUE", 11467, 0 },
	{ "APARTMENT_CAR_MODSSTILT_2113_MAD_WAYNE_THUNDER_DRIVE", 11468, 0 },
	{ "APARTMENT_CAR_MODSSTILT_2045_NORTH_CONKER_AVENUE", 11469, 0 },
	{ "TURN_ON_VALENTINE_2016_CLOTHING", 11529, 2 },
	{ "TURN_ON_VALENTINE_2016_VEHICLE", 11530, 2 },
	{ "OPTOUT_VEHICLEWEBSITE_SALE0", 11541, 0 },
	{ "OPTOUT_VEHICLEWEBSITE_SALE1", 11542, 0 },
	{ "TURN_ON_BE_MY_VALENTINE", 11581, 2 },
	{ "TURN_ON_BE_MY_VALENTINE_JOBS_POSIX", 11582, 0 },
	{ "BE_MY_VALENTINE_INVITE_WEIGHT", 11584, 1 },
	{ "DAVIDS_VS_GOLIATH_INVITE_WEIGHT", 11780, 1 },
	{ "TURN_ON_DAVIDS_VS_GOLIATH", 11781, 2 },
	{ "TURN_ON_DAVIDS_VS_GOLIATH_JOBS_POSIX", 11782, 0 },
	{ "NPCFLOWINVITE1", 11786, 0 },
	{ "NPCFLOWINVITE2", 11787, 0 },
	{ "NPCFLOWINVITE3", 11788, 0 },
	{ "NPCFLOWINVITE4", 11789, 0 },
	{ "NPCFLOWINVITE5", 11790, 0 },
	{ "NPCFLOWINVITE6", 11791, 0 },
	{ "NPCFLOWINVITE7", 11792, 0 },
	{ "NPCFLOWINVITE8", 11793, 0 },
	{ "NPCFLOWINVITE9", 11794, 0 },
	{ "NPCFLOWINVITE10", 11795, 0 },
	{ "NPCFLOWINVITE11", 11796, 0 },
	{ "NPCFLOWINVITE12", 11797, 0 },
	{ "NPCFLOWINVITESTARTPOSIX", 11798, 0 },
	{ "NPCFLOWINVITEINTERVALINSECONDS", 11799, 0 },
	{ "NPCFLOWINVITETIMEUNTILINVITEINSECONDS", 11800, 0 },
	{ "NPCFLOWINVITEPLAYLISTACTIVE", 11801, 2 },
	{ "SALE_CLOTHING_MENU_LOCATE_TYPE_BODYARMOUR", 11946, 2 },
	{ "ENABLE_LOWRIDER2_VIRGO3", 12338, 2 },
	{ "ENABLE_LOWRIDER2_FACTION", 12342, 2 },
	{ "ENABLE_LOWRIDER2_SLAMVAN", 12343, 2 },
	{ "ENABLE_LOWRIDER2_VIRGO3_POSIX", 12350, 0 },
	{ "ENABLE_LOWRIDER2_SABREGT_POSIX", 12351, 0 },
	{ "ENABLE_LOWRIDER2_TORNADO5_POSIX", 12352, 0 },
	{ "ENABLE_LOWRIDER2_MINIVAN_POSIX", 12353, 0 },
	{ "ENABLE_LOWRIDER2_FACTION_POSIX", 12354, 0 },
	{ "ENABLE_LOWRIDER2_SLAMVAN_POSIX", 12355, 0 },
	{ "AMMO_COMPACT_RIFLE_AMMO", 12671, 0 },
	{ "AMMO_DOUBLE_BARREL_SHOTGUN_AMMO", 12674, 0 },
	{ "TURN_ON_SUMO", 12697, 2 },
	{ "TURN_ON_SUMO_POSIX", 12699, 0 },
	{ "PISTOL_AMMO_DISPLAY_SALES", 13686, 2 },
	{ "SMG_AMMO_DISPLAY_SALES", 13687, 2 },
	{ "RIFLE_AMMO_DISPLAY_SALES", 13688, 2 },
	{ "MG_AMMO_DISPLAY_SALES", 13689, 2 },
	{ "SHOTGUN_AMMO_DISPLAY_SALES", 13690, 2 },
	{ "SNIPER_AMMO_DISPLAY_SALES", 13691, 2 },
	{ "FLAREGUN_AMMO_DISPLAY_SALES", 13692, 2 },
	{ "GRENADELAUNCHER_AMMO_DISPLAY_SALES", 13693, 2 },
	{ "RPG_AMMO_DISPLAY_SALES", 13694, 2 },
	{ "MINIGUN_AMMO_DISPLAY_SALES", 13695, 2 },
	{ "HOMINGLAUNCHER_AMMO_DISPLAY_SALES", 13696, 2 },
	{ "Disable_Stunt_Tracks_and_Props_DM", 13713, 2 },
	{ "Disable_Stunt_Tracks_and_Props_CAPTURE", 13714, 2 },
	{ "Disable_Stunt_Tracks_and_Props_LTS", 13715, 2 },
	{ "NPCFLOWINVITETIMEUNTILINVITEINSECONDSFORCEO", 14391, 0 },
	{ "AVAILABLE_PURCHASE_JUMPSUIT_GOLD", 14436, 2 },
	{ "AVAILABLE_PURCHASE_JUMPSUIT_BLACK", 14437, 2 },
	{ "AVAILABLE_PURCHASE_JUMPSUIT_SILVER", 14439, 2 },
	{ "ENABLE_BIKER_PROPERTY", 15098, 2 },
	{ "CREATOR_ENABLE_BIKER_DEFILER", 15099, 2 },
	{ "CREATOR_ENABLE_BIKER_NIGHTBLADE", 15100, 2 },
	{ "CREATOR_ENABLE_BIKER_ZOMBIEA", 15101, 2 },
	{ "CREATOR_ENABLE_BIKER_AVARUS", 15103, 2 },
	{ "CREATOR_ENABLE_BIKER_ZOMBIEB", 15104, 2 },
	{ "CREATOR_ENABLE_BIKER_HAKUCHOU2", 15105, 2 },
	{ "CREATOR_ENABLE_BIKER_VORTEX", 15106, 2 },
	{ "CREATOR_ENABLE_BIKER_SHOTARO", 15107, 2 },
	{ "CREATOR_ENABLE_BIKER_CHIMERA", 15108, 2 },
	{ "CREATOR_ENABLE_BIKER_RAPTOR", 15109, 2 },
	{ "CREATOR_ENABLE_BIKER_WESTERNDAEMON", 15110, 2 },
	{ "CREATOR_ENABLE_BIKER_BLAZER4", 15111, 2 },
	{ "CREATOR_ENABLE_BIKER_MANCHEZ", 15113, 2 },
	{ "CREATOR_ENABLE_BIKER_YOUGA2", 15114, 2 },
	{ "CREATOR_ENABLE_BIKER_WOLFSBANE", 15115, 2 },
	{ "CREATOR_ENABLE_BIKER_FAGGIO3", 15116, 2 },
	{ "CREATOR_ENABLE_BIKER_FAGGIO", 15117, 2 },
	{ "CREATOR_ENABLE_BIKER_FAGGIO", 15117, 2 },
	{ "CREATOR_ENABLE_BIKER_TORNADO6", 15118, 2 },
	{ "CREATOR_ENABLE_BIKER_BAGGER", 15119, 2 },
	{ "CREATOR_ENABLE_BIKER_RATBIKE", 15120, 2 },
	{ "ENABLE_BIKER_DEFILER", 15121, 2 },
	{ "ENABLE_BIKER_NIGHTBLADE", 15122, 2 },
	{ "ENABLE_BIKER_ZOMBIEA", 15123, 2 },
	{ "ENABLE_BIKER_ESSKEY", 15124, 2 },
	{ "ENABLE_BIKER_AVARUS", 15125, 2 },
	{ "ENABLE_BIKER_ZOMBIEB", 15126, 2 },
	{ "ENABLE_BIKER_FAGGIO", 15127, 2 },
	{ "ENABLE_BIKER_FAGGIO", 15127, 2 },
	{ "ENABLE_BIKER_HAKUCHOU2", 15128, 2 },
	{ "ENABLE_BIKER_VORTEX", 15129, 2 },
	{ "ENABLE_BIKER_SHOTARO", 15130, 2 },
	{ "ENABLE_BIKER_CHIMERA", 15131, 2 },
	{ "ENABLE_BIKER_RAPTOR", 15132, 2 },
	{ "ENABLE_BIKER_WESTERNDAEMON", 15133, 2 },
	{ "ENABLE_BIKER_BLAZER4", 15134, 2 },
	{ "ENABLE_BIKER_MANCHEZ", 15136, 2 },
	{ "ENABLE_BIKER_YOUGA2", 15137, 2 },
	{ "ENABLE_BIKER_WOLFSBANE", 15138, 2 },
	{ "ENABLE_BIKER_FAGGIO3", 15139, 2 },
	{ "ENABLE_BIKER_TORNADO6", 15140, 2 },
	{ "ENABLE_BIKER_BAGGER", 15141, 2 },
	{ "ENABLE_BIKER_RATBIKE", 15142, 2 },
	{ "ENABLE_BIKER_DEFILER_POSIX", 15143, 0 },
	{ "ENABLE_BIKER_NIGHTBLADE_POSIX", 15144, 0 },
	{ "ENABLE_BIKER_ZOMBIEA_POSIX", 15145, 0 },
	{ "ENABLE_BIKER_ESSKEY_POSIX", 15146, 0 },
	{ "ENABLE_BIKER_AVARUS_POSIX", 15147, 0 },
	{ "ENABLE_BIKER_ZOMBIEB_POSIX", 15148, 0 },
	{ "ENABLE_BIKER_HAKUCHOU2_POSIX", 15149, 0 },
	{ "ENABLE_BIKER_VORTEX_POSIX", 15150, 0 },
	{ "ENABLE_BIKER_SHOTARO_POSIX", 15151, 0 },
	{ "ENABLE_BIKER_CHIMERA_POSIX", 15152, 0 },
	{ "ENABLE_BIKER_RAPTOR_POSIX", 15153, 0 },
	{ "ENABLE_BIKER_WESTERNDAEMON_POSIX", 15154, 0 },
	{ "ENABLE_BIKER_BLAZER4_POSIX", 15155, 0 },
	{ "ENABLE_BIKER_SANCTUS_POSIX", 15156, 0 },
	{ "ENABLE_BIKER_MANCHEZ_POSIX", 15157, 0 },
	{ "ENABLE_BIKER_YOUGA2_Posix", 15158, 0 },
	{ "ENABLE_BIKER_WOLFSBANE_Posix", 15159, 0 },
	{ "ENABLE_BIKER_FAGGIO3_Posix", 15160, 0 },
	{ "ENABLE_BIKER_FAGGIO_Posix", 15161, 0 },
	{ "ENABLE_BIKER_TORNADO6_Posix", 15162, 0 },
	{ "ENABLE_BIKER_RATBIKE_POSIX", 15164, 0 },
	{ "ENABLE_AUTOSHOTGUN", 15165, 2 },
	{ "ENABLE_AUTOSHOTGUN", 15165, 2 },
	{ "ENABLE_MINISMG", 15166, 2 },
	{ "ENABLE_MINISMG", 15166, 2 },
	{ "ENABLE_COMPACTLAUNCHER", 15167, 2 },
	{ "ENABLE_COMPACTLAUNCHER", 15167, 2 },
	{ "ENABLE_PIPEBOMB", 15168, 2 },
	{ "ENABLE_PIPEBOMB", 15168, 2 },
	{ "ENABLE_POOLCUE", 15169, 2 },
	{ "ENABLE_POOLCUE", 15169, 2 },
	{ "ENABLE_BATTLEAXE", 15170, 2 },
	{ "ENABLE_BATTLEAXE", 15170, 2 },
	{ "ENABLE_WRENCH", 15171, 2 },
	{ "ENABLE_WRENCH", 15171, 2 },
	{ "ENABLE_AUTOSHOTGUN_POSIX", 15172, 0 },
	{ "ENABLE_AUTOSHOTGUN_POSIX", 15172, 0 },
	{ "ENABLE_MINISMG_POSIX", 15173, 0 },
	{ "ENABLE_MINISMG_POSIX", 15173, 0 },
	{ "ENABLE_COMPACTLAUNCHER_POSIX", 15174, 0 },
	{ "ENABLE_COMPACTLAUNCHER_POSIX", 15174, 0 },
	{ "ENABLE_PIPEBOMB_POSIX", 15175, 0 },
	{ "ENABLE_PIPEBOMB_POSIX", 15175, 0 },
	{ "ENABLE_POOLCUE_POSIX", 15176, 0 },
	{ "ENABLE_POOLCUE_POSIX", 15176, 0 },
	{ "ENABLE_BATTLEAXE_POSIX", 15177, 0 },
	{ "ENABLE_BATTLEAXE_POSIX", 15177, 0 },
	{ "ENABLE_WRENCH_POSIX", 15178, 0 },
	{ "ENABLE_WRENCH_POSIX", 15178, 0 },
	{ "BIKER_AMMO_COMPACT_GRENADE_LAUNCHER_AMMO", 15553, 0 },
	{ "BIKER_AMMO_SWEEPER_SHOTGUN_AMMO", 15555, 0 },
	{ "BIKER_AMMO_MINI_SMG_AMMO", 15557, 0 },
	{ "BIKER_PRIMARY_PIPE_BOMB", 15558, 0 },
	{ "BIKER_WEBSITE_NAGASAKI_SHOTARO", 15577, 0 },
	{ "BIKER_BUSINESS_PAID_RESUPPLY_BASE", 15744, 0 },
	{ "BIKER_MC_POINTS_COMMIT_SUICIDE", 15814, 0 },
	{ "BIKER_PURCHASE_SUPPLIES_COST_PER_SEGMENT", 16592, 0 },
	{ "ENABLE_IE_VOLTIC2", 16770, 2 },
	{ "ENABLE_IE_VOLTIC2", 16770, 2 },
	{ "ENABLE_IE_RUINER2", 16771, 2 },
	{ "ENABLE_IE_RUINER2", 16771, 2 },
	{ "ENABLE_IE_DUNE4", 16772, 2 },
	{ "ENABLE_IE_DUNE4", 16772, 2 },
	{ "ENABLE_IE_DUNE5", 16773, 2 },
	{ "ENABLE_IE_DUNE5", 16773, 2 },
	{ "ENABLE_IE_PHANTOM2", 16774, 2 },
	{ "ENABLE_IE_PHANTOM2", 16774, 2 },
	{ "ENABLE_IE_TECHNICAL2", 16775, 2 },
	{ "ENABLE_IE_TECHNICAL2", 16775, 2 },
	{ "ENABLE_IE_BOXVILLE5", 16776, 2 },
	{ "ENABLE_IE_BOXVILLE5", 16776, 2 },
	{ "ENABLE_IE_WASTELANDER", 16777, 2 },
	{ "ENABLE_IE_WASTELANDER", 16777, 2 },
	{ "ENABLE_IE_BLAZER5", 16778, 2 },
	{ "ENABLE_IE_BLAZER5", 16778, 2 },
	{ "ENABLE_IE_DIABLOUS", 16781, 2 },
	{ "ENABLE_IE_DIABLOUS", 16781, 2 },
	{ "ENABLE_IE_DIABLOUS2", 16782, 2 },
	{ "ENABLE_IE_DIABLOUS2", 16782, 2 },
	{ "ENABLE_IE_ELEGY", 16783, 2 },
	{ "ENABLE_IE_ELEGY", 16783, 2 },
	{ "ENABLE_IE_ELEGY2", 16784, 2 },
	{ "ENABLE_IE_ELEGY2", 16784, 2 },
	{ "ENABLE_IE_PENETRATOR", 16791, 2 },
	{ "ENABLE_IE_PENETRATOR", 16791, 2 },
	{ "ENABLE_IE_TEMPESTA", 16794, 2 },
	{ "ENABLE_IE_TEMPESTA", 16794, 2 },
	{ "CREATOR_ENABLE_IE_COMET2", 16795, 2 },
	{ "CREATOR_ENABLE_IE_COMET2", 16795, 2 },
	{ "CREATOR_ENABLE_IE_DIABLOUS", 16797, 2 },
	{ "CREATOR_ENABLE_IE_DIABLOUS", 16797, 2 },
	{ "CREATOR_ENABLE_IE_DIABLOUS2", 16798, 2 },
	{ "CREATOR_ENABLE_IE_DIABLOUS2", 16798, 2 },
	{ "CREATOR_ENABLE_IE_ELEGY", 16799, 2 },
	{ "CREATOR_ENABLE_IE_ELEGY", 16799, 2 },
	{ "CREATOR_ENABLE_IE_ELEGY2", 16800, 2 },
	{ "CREATOR_ENABLE_IE_ELEGY2", 16800, 2 },
	{ "CREATOR_ENABLE_IE_PENETRATOR", 16807, 2 },
	{ "CREATOR_ENABLE_IE_PENETRATOR", 16807, 2 },
	{ "CREATOR_ENABLE_IE_TEMPESTA", 16810, 2 },
	{ "CREATOR_ENABLE_IE_TEMPESTA", 16810, 2 },
	{ "ENABLE_IE_VOLTIC2_POSIX", 16811, 0 },
	{ "ENABLE_IE_VOLTIC2_POSIX", 16811, 0 },
	{ "ENABLE_IE_RUINER2_POSIX", 16812, 0 },
	{ "ENABLE_IE_RUINER2_POSIX", 16812, 0 },
	{ "ENABLE_IE_DUNE4_POSIX", 16813, 0 },
	{ "ENABLE_IE_DUNE4_POSIX", 16813, 0 },
	{ "ENABLE_IE_DUNE5_POSIX", 16814, 0 },
	{ "ENABLE_IE_DUNE5_POSIX", 16814, 0 },
	{ "ENABLE_IE_PHANTOM2_POSIX", 16815, 0 },
	{ "ENABLE_IE_PHANTOM2_POSIX", 16815, 0 },
	{ "ENABLE_IE_TECHNICAL2_POSIX", 16816, 0 },
	{ "ENABLE_IE_TECHNICAL2_POSIX", 16816, 0 },
	{ "ENABLE_IE_BOXVILLE5_POSIX", 16817, 0 },
	{ "ENABLE_IE_BOXVILLE5_POSIX", 16817, 0 },
	{ "ENABLE_IE_WASTELANDER_POSIX", 16818, 0 },
	{ "ENABLE_IE_WASTELANDER_POSIX", 16818, 0 },
	{ "ENABLE_IE_BLAZER5_POSIX", 16819, 0 },
	{ "ENABLE_IE_BLAZER5_POSIX", 16819, 0 },
	{ "ENABLE_IE_COMET2_POSIX", 16820, 0 },
	{ "ENABLE_IE_COMET2_POSIX", 16820, 0 },
	{ "ENABLE_IE_DIABLOUS_POSIX", 16822, 0 },
	{ "ENABLE_IE_DIABLOUS_POSIX", 16822, 0 },
	{ "ENABLE_IE_DIABLOUS2_POSIX", 16823, 0 },
	{ "ENABLE_IE_DIABLOUS2_POSIX", 16823, 0 },
	{ "ENABLE_IE_ELEGY_POSIX", 16824, 0 },
	{ "ENABLE_IE_ELEGY_POSIX", 16824, 0 },
	{ "ENABLE_IE_ELEGY2_POSIX", 16825, 0 },
	{ "ENABLE_IE_ELEGY2_POSIX", 16825, 0 },
	{ "ENABLE_IE_PENETRATOR_POSIX", 16832, 0 },
	{ "ENABLE_IE_PENETRATOR_POSIX", 16832, 0 },
	{ "ENABLE_IE_TEMPESTA_POSIX", 16835, 0 },
	{ "ENABLE_IE_TEMPESTA_POSIX", 16835, 0 },
	{ "TURN_ON_TURFWARS", 16876, 2 },
	{ "IMPEXP_RUINER2_MISSILES", 17260, 0 },
	{ "IMPEXP_SELL_POST_MOD_TRANS_TIMEOUT", 17271, 0 },
	{ "ENABLE_VEHICLE_HELP_IELAUNCH", 17651, 2 },
};


int hhh = 0;
int mmm = 0;
int sss = 0;
bool loadScripts = true;
vector<string> scripts;
int scriptNumber;
bool reportdisplay = false;
bool ipdisplay = false;
int playerAlpha = 255;
bool slowMotion = false;
bool versionnumber = false;
bool lsc_primary = true;
bool lsc_secondary = true;




bool keyboardActive = false;
char* charResult = NULL;
int intResult = -1;
int keyboardTimer = timeGetTime();
std::function<void()> keyFunc;

void keyboard(std::function<void()> action) {
	//char* windowName = "", int maxInput = 21, char* defaultText = ""
	/*GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return "";
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();*/
	/*GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(1, "", "", "", "", "", "", 10);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return 0;
	return atof(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());*/
	keyFunc = action;
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, (char*)"", (char*)"", (char*)"", (char*)"", (char*)"", (char*)"", 21);
	keyboardActive = true;
}

char* CharKeyboard(char* windowName = "", int maxInput = 21, char* defaultText = "") {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return "";
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}

int NumberKeyboard() {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(1, "", "", "", "", "", "", 10);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return 0;
	return atof(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
}



int hrs = 0;
int mns = 0;
int scs = 0;

class intructions {
private:
	int32_t bc = 0;
	int32_t handle = 0;
public:
	void setup()
	{
		handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("instructional_buttons");
		GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(handle, 255, 255, 255, 255, 0);
		GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "CLEAR_ALL");
		GRAPHICS::END_SCALEFORM_MOVIE_METHOD();

		GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "SET_CLEAR_SPACE");
		GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(200);
		GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
	}

	void text_component(char* text)
	{
		GRAPHICS::BEGIN_TEXT_COMMAND_SCALEFORM_STRING("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((LPSTR)text);
		GRAPHICS::END_TEXT_COMMAND_SCALEFORM_STRING();
	}

	void add(char* text, int button)
	{
		GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "SET_DATA_SLOT");
		GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(bc);
		GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(button);
		text_component(text);
		GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
		bc++;
	}

	void add(char* text, char* button)
	{
		GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "SET_DATA_SLOT");
		GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(bc);
		text_component(button);
		text_component(text);
		GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
		bc++;
	}

	void draw() {
		GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "DRAW_INSTRUCTIONAL_BUTTONS");
		GRAPHICS::END_SCALEFORM_MOVIE_METHOD();

		GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "SET_BACKGROUND_COLOUR");
		GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(0);  // R
		GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(0);  // G
		GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(0);  // B
		GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(80); // A
		GRAPHICS::END_SCALEFORM_MOVIE_METHOD();

		bc = 0;
	}
};
std::unique_ptr<intructions> buttons = std::make_unique<intructions>();

#pragma endregion

char* player_name;
bool firsttime3 = true;
int widthkek = 24;
bool loadBlacklist = true;
bool deep_bl = true;
bool low_bl = false;
int smooth_scroll_kek = 10;

bool display_when_open = false;

bool debug_options_enabled = false;
std::string menu_version_ = "4.2.0";
std::vector<char*> mainhooker = { "IDP (Recommended)", "DCE (For coloading)" };
int key_display_test = 134;

bool firsttimeMs = true;

void MODIFY_VEHICLE(int LSCType, int LSCIndex)
{
	int vehid = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	VEHICLE::SET_VEHICLE_MOD_KIT(vehid, 0);
	VEHICLE::SET_VEHICLE_MOD(vehid, LSCType, LSCIndex, 0);
}

void main() {

	if (firsttime) {
		player_name = SOCIALCLUB::_SC_GET_NICKNAME();
		Features::notify("Press * to open the menu!", "X-Force", "X-Force loaded!", "___MENU", "CHAR_SOCIAL_CLUB", true, 4, 4);
		Features::loadFromINI();
		Log::Msg("Executed main function");
		menyooX = INI::GetFloat("X-Folder/title/config.ini", "theme", "menux") * 100;
		widthkek = INI::GetFloat("X-Folder/title/config.ini", "theme", "menuw") * 100;
		smooth_scroll_kek = INI::GetFloat("X-Folder/title/config.ini", "delay", "smooth") * 1000;
		display_when_open = INI::GetBool("X-Folder/title/config.ini", "display", "close");
		reportdisplay = INI::GetBool("X-Folder/title/config.ini", "display", "d_report");
		ipdisplay = INI::GetBool("X-Folder/title/config.ini", "display", "d_ip");
		Menu::Settings::selfInfo = INI::GetBool("X-Folder/title/config.ini", "display", "d_info");
		Log::Msg("Loaded YTD file: %s.ytd", Menu::Settings::ytdtheme);
		firsttime = false;
	}

	Thread::OnTick();

	switch (Menu::Settings::currentMenu) {
	case mainmenu:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Main Menu");
		Menu::MenuOption("Protection", protex);
		Menu::MenuOption("Self", self);
		Menu::MenuOption("Online Players", plist);
		Menu::MenuOption("All Online Players", aioplist);
		Menu::MenuOption("Vehicles", vehicles);
		Menu::MenuOption("Spawner", spawner);
		Menu::MenuOption("Weapons", weapons);
		Menu::MenuOption("Teleport", teleport);
		Menu::MenuOption("World", world);
		Menu::MenuOption("Misc", misc);
		Menu::MenuOption("Recovery", recoy);
		Menu::MenuOption("Settings", settings);
	}
	break;
#pragma region protection
	case protex:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Protection");	
		Menu::Toggle("Notify Events", Features::eventShieldBool, [] { Features::eventShield(); });
		Menu::VipToggle("Kick Protection", Features::antiKick, [] { Features::AntiKick(Features::antiKick); });
		Menu::VipToggle("Freeze Protection", Features::antiFreeze, [] { Features::AntiFreeze(Features::antiFreeze); });
		Menu::Toggle("Explosion Protection", Features::antiExplosion, [] { Features::AntiExplosion(Features::antiExplosion); });
		Menu::Toggle("Weather-Time Protection", Features::antiweatherTime, [] { Features::antiWeatherTime(Features::antiweatherTime); });
		Menu::VipToggle("Stat Protection", Features::antiStat, [] { Features::AntiStat(Features::antiStat); });
		Menu::Toggle("Control Protection", Features::antiControl, [] { Features::AntiControl(Features::antiControl); });
		Menu::Toggle("Weapon Protection", Features::antiWeapon, [] { Features::AntiWeapon(Features::antiWeapon); });
		Menu::Toggle("Wanted Protection", Features::antiStars, [] { Features::AntiStars(Features::antiStars); });
		Menu::Toggle("Particle Protection", Features::antiPtfx, [] { Features::AntiPtfx(Features::antiPtfx); });
		Menu::Toggle("Attachment Protection", Features::antiAttachment, [] { Features::AntiAttachment(Features::antiAttachment); });
		Menu::VipToggle("Rockstar Dev Protection", Features::devDisabled);
		Menu::Toggle("Vehicle Freeze Protection", Features::antivf);
		Menu::VipToggle("Crash Protection", Features::anticr);
		Menu::Toggle("Clone Protection", Features::antico);
		Menu::Toggle("Teleport Protection", Features::antitp);
		Menu::Toggle("Clear Protection", Features::anticl);
		Menu::Toggle("Invite Protection", Features::antiinv);
		Menu::Toggle("Moneydrop Protection", Features::moneyDropProtection);
	}
	break;
#pragma endregion

#pragma region self
	case self:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Self Options");
		Menu::Toggle("Godmode", Features::GodMode, [] { Features::godmode(Features::GodMode); }, 0);
		Menu::Toggle("Semi Godmode", Features::semiOn, 0);
		Menu::Toggle("Never Wanted", Features::neverwanted, [] { Features::NeverWanted(Features::neverwanted); });
		Menu::VipToggle("Off the Radar (Lester)", Features::orbool, [] { Features::OffRadar(Features::orbool); });
		Menu::Toggle("Off the Radar (Fake Death)", Features::otrd, [] { Features::otrdeath(); });
		Menu::Toggle("No Ragdoll", Features::playernoragdoll, [] { Features::NoRagdoll(Features::playernoragdoll); });
		if (Menu::Option("6 Stars")) {
			Memory::set_value<int>({ (2 * 4 * 2) / 2, 4 * 1000 + 280, 500 * 4 - 70 + 70 + 72 }, 5);
			GAMEPLAY::SET_FAKE_WANTED_LEVEL(6);
		}
		if (Menu::Int("Wanted Level", Features::wantedstars, 0, 6)) { Features::setWanted(Features::wantedstars); }
		Menu::Toggle("Invisibility", Features::playerinvisibility, [] { Features::Invisibility(Features::playerinvisibility); });
		Menu::Toggle("Super Jump", Features::Superjump, [] { Features::superjump(Features::Superjump); });
		Menu::Toggle("Fast Run", Features::fastRun, [] { Features::runFast(Features::fastRun); });
		Menu::Toggle("Tiny Player", Features::betiny, [] { Features::TinyPlayer(Features::betiny); });
		if (Menu::Option("Suicide")) {
			Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_ENTITY_HEALTH }, 0.0f);
		}
		Menu::Toggle("Anti AFK", Features::antiAFKbool, [] { Features::antiAFK(Features::antiAFKbool); });
		Menu::Toggle("Ignored by all Peds", Features::ignored, [] { Features::nobody(); });

		Menu::VipToggle("Karma", Features::kkkbool, [] { Features::ktest(); });
		if (Menu::Option("Clean player")) {
			Features::cleaner(PLAYER::PLAYER_PED_ID());
		}
		if (Menu::Option("Reset Player")) {
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			PED::SET_PED_DEFAULT_COMPONENT_VARIATION(playerPed);
			Features::cleaner(playerPed);
			ENTITY::SET_ENTITY_ALPHA(255, playerAlpha, 0);
		}
		if (Menu::Int("Player Alpha", playerAlpha, 0, 255)) { ENTITY::SET_ENTITY_ALPHA(PLAYER::PLAYER_PED_ID(), playerAlpha, 0); }
		Menu::Toggle("Mobile Radio", Features::mobRadio, [] { Features::mobileRadio(Features::mobRadio); });
		Menu::MenuOption("Animations", animationself);
		Menu::MenuOption("Model Changer", modelchanger);
		Menu::MenuOption("Walking Styles", walkstyles);
		Menu::MenuOption("Particles", ptfxself);
		Menu::MenuOption("Wardrobe", OutfitMenu);
	}
	break;
	case walkstyles:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Walking Styles");
		for (int i = 0; i < sizeof(walkDicts); i++) {
			if (Menu::Option(walkNames[i])) {
				STREAMING::REQUEST_ANIM_SET(walkDicts[i]);
				while (!STREAMING::HAS_ANIM_SET_LOADED(walkDicts[i])) WAIT(0);
				PED::SET_PED_MOVEMENT_CLIPSET(PLAYER::PLAYER_PED_ID(), walkDicts[i], 1.0f);
			}
		}
	}
	break;
	case modelchanger:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Model Changer");
		for (int i = 0; i < ARRAYSIZE(pedModels); i++)
		{
			if (Menu::Option(pedModels[i]))
			{
				DWORD model = GAMEPLAY::GET_HASH_KEY(pedModels[i]);
				STREAMING::REQUEST_MODEL(model);
				while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
				PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
				PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
				WAIT(10);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
				WAIT(10);
			}
		}
	}
	break;
	case ptfxself:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Particles");
		Menu::Toggle("Looped", Features::ptfxself);
		if (Menu::Option("Clown Appears"))Features::PTFXCALLO("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears", PLAYER::PLAYER_ID());
		if (Menu::Option("Firework 1"))Features::PTFXCALLO("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst", PLAYER::PLAYER_ID());
		if (Menu::Option("Firework 2"))Features::PTFXCALLO("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_burst_rgw", PLAYER::PLAYER_ID());
		if (Menu::Option("Firework 3"))Features::PTFXCALLO("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_spiral_burst_rgw", PLAYER::PLAYER_ID());
		if (Menu::Option("Banknotes"))Features::PTFXCALLO("scr_ornate_heist", "scr_ornate_heist", "scr_heist_ornate_banknotes", PLAYER::PLAYER_ID());
		if (Menu::Option("Truck Crash"))Features::PTFXCALLO("scr_fbi4", "scr_fbi4", "scr_fbi4_trucks_crash", PLAYER::PLAYER_ID());
		if (Menu::Option("Ped Sliced"))Features::PTFXCALLO("scr_michael2", "scr_michael2", "scr_abattoir_ped_sliced", PLAYER::PLAYER_ID());
		if (Menu::Option("Camera"))Features::PTFXCALLO("scr_rcpaparazzo1", "scr_rcpaparazzo1", "scr_rcpap1_camera", PLAYER::PLAYER_ID());
		if (Menu::Option("Alien 1"))Features::PTFXCALLO("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate", PLAYER::PLAYER_ID());
		if (Menu::Option("Alien 2"))Features::PTFXCALLO("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport", PLAYER::PLAYER_ID());
		if (Menu::Option("Electric Box"))Features::PTFXCALLO("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box", PLAYER::PLAYER_ID());
		if (Menu::Option("Water Splash"))Features::PTFXCALLO("scr_fbi5a", "scr_fbi5a", "scr_fbi5_ped_water_splash", PLAYER::PLAYER_ID());
		if (Menu::Option("Bubbles"))Features::PTFXCALLO("scr_fbi5a", "scr_fbi5a", "water_splash_ped_bubbles", PLAYER::PLAYER_ID());
		if (Menu::Option("Blood Entry"))Features::PTFXCALLO("scr_finalec2", "scr_finalec2", "scr_finale2_blood_entry", PLAYER::PLAYER_ID());
		if (Menu::Option("Sniper Impact"))Features::PTFXCALLO("scr_martin1", "scr_martin1", "scr_sol1_sniper_impact", PLAYER::PLAYER_ID());
		if (Menu::Option("Dirt Throw"))Features::PTFXCALLO("core_snow", "core_snow", "cs_mich1_spade_dirt_throw", PLAYER::PLAYER_ID());
		if (Menu::Option("Blood Stab"))Features::PTFXCALLO("scr_michael2", "scr_michael2", "scr_mich2_blood_stab", PLAYER::PLAYER_ID());
		if (Menu::Option("Meth Smoke"))Features::PTFXCALLO("scr_familyscenem", "scr_familyscenem", "scr_meth_pipe_smoke", PLAYER::PLAYER_ID());
		if (Menu::Option("Burial Dirt"))Features::PTFXCALLO("scr_reburials", "scr_reburials", "scr_burial_dirt", PLAYER::PLAYER_ID());
		if (Menu::Option("~w~Ghost Rider"))Features::PTFXCALLO("scr_agencyheist", "scr_agencyheist", "scr_fbi_dd_breach_smoke", PLAYER::PLAYER_ID());
	}
	break;
	case animationself:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Animations");
		if (Menu::Option("Clear Animation")) { Features::clearanim(); }
		if (Menu::Option("S** Receiver")) { Features::doAnimation("rcmpaparazzo_2", "shag_loop_poppy"); }
		if (Menu::Option("S** Giver")) { Features::doAnimation("rcmpaparazzo_2", "shag_loop_a"); }
		if (Menu::Option("Stripper Dance")) { Features::doAnimation("mini@strip_club@private_dance@part1", "priv_dance_p1"); }
		if (Menu::Option("Pole Dance")) { Features::doAnimation("mini@strip_club@pole_dance@pole_dance1", "pd_dance_01"); }
		if (Menu::Option("Push Ups")) { Features::doAnimation("amb@world_human_push_ups@male@base", "base"); }
		if (Menu::Option("Sit Ups")) { Features::doAnimation("amb@world_human_sit_ups@male@base", "base"); }
		if (Menu::Option("Celebrate")) { Features::doAnimation("rcmfanatic1celebrate", "celebrate"); }
		if (Menu::Option("Electrocution")) { Features::doAnimation("ragdoll@human", "electrocute"); }
		if (Menu::Option("Suicide")) { Features::doAnimation("mp_suicide", "pistol"); }
		if (Menu::Option("Showering")) { Features::doAnimation("mp_safehouseshower@male@", "male_shower_idle_b"); }
		if (Menu::Option("Paparizzi")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_PAPARAZZI", 0, true);
		if (Menu::Option("Drug Dealer")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_DRUG_DEALER_HARD", 0, true);
		if (Menu::Option("Drinking Coffee")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_AA_COFFEE", 0, true);
		if (Menu::Option("Playing Instruments")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MUSICIAN", 0, true);
		if (Menu::Option("Flexing")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MUSCLE_FLEX", 0, true);
		if (Menu::Option("Jogging")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_JOG_STANDING", 0, true);
		if (Menu::Option("Binoculars")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_BINOCULARS", 0, true);
		if (Menu::Option("Clipboard")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_CLIPBOARD", 0, true);
		if (Menu::Option("Bench Press")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS", 0, true);
		if (Menu::Option("Chin Ups")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_MUSCLE_CHIN_UPS", 0, true);
		if (Menu::Option("BBQ")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_BBQ", 0, true);
		if (Menu::Option("Superhero")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SUPERHERO", 0, true);
		if (Menu::Option("Fishing")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_STAND_FISHING", 0, true);
		if (Menu::Option("Security")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SECURITY_SHINE_TORCH", 0, true);
		if (Menu::Option("Leaf Blower")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_GARDENER_LEAF_BLOWER", 0, true);
		if (Menu::Option("Film Shocking")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MOBILE_FILM_SHOCKING", 0, true);
		if (Menu::Option("Idle Cop")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_COP_IDLES", 0, true);
		if (Menu::Option("Drinking")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_DRINKING", 0, true);
		if (Menu::Option("Golf Player")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_GOLF_PLAYER", 0, true);
		if (Menu::Option("Welding")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_WELDING", 0, true);
		if (Menu::Option("Smoking Pot")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SMOKING_POT", 0, true);
		if (Menu::Option("Hammering")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_HAMMERING", 0, true);
		if (Menu::Option("Tennis")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_TENNIS_PLAYER", 0, true);
		if (Menu::Option("Drilling")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_CONST_DRILL", 0, true);
	}
	break;
#pragma endregion	

#pragma region onlineplayer

	case plist:
	{
		//Features::LoadInfoplayer(PLAYER::GET_PLAYER_NAME(Menu::Settings::currentOption-1), Menu::Settings::currentOption-1);
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Player List");
		for (int i = 0; i < 32; ++i) {
			if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
				std::string heil_harald = PLAYER::GET_PLAYER_NAME(i);
				//Features::LoadInfoplayer(PLAYER::GET_PLAYER_NAME(i), i);
				bool frnd;
				if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID() && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i && USER::HAS_XFORCE(i)) {
					heil_harald.append(" ~b~[SELF] ~y~[HOST]" + USER::XFORCE_TAG(i));
					const char *cstr = heil_harald.c_str();
					if (NETWORK::NETWORK_IS_SIGNED_ONLINE() && PLAYER::IS_PLAYER_ONLINE() && NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS() > 1) {
						Menu::MenuOptions2(cstr, onlinemenu_selected, i) ? Features::Online::selectedPlayer = i : NULL;
					}
					else {
						Menu::ColorOption(cstr, onlinemenu_selected) ? Features::Online::selectedPlayer = i : NULL;
					}
				}
				else if (Features::isPlayerFriend(i, frnd) && frnd && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i && USER::HAS_XFORCE(i)) {
					heil_harald.append(" ~g~[FRIEND] ~y~[HOST]" + USER::XFORCE_TAG(i));
					const char *cstr = heil_harald.c_str();
					if (NETWORK::NETWORK_IS_SIGNED_ONLINE() && PLAYER::IS_PLAYER_ONLINE() && NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS() > 1) {
						Menu::MenuOptions2(cstr, onlinemenu_selected, i) ? Features::Online::selectedPlayer = i : NULL;
					}
					else {
						Menu::ColorOption(cstr, onlinemenu_selected) ? Features::Online::selectedPlayer = i : NULL;
					}
				}
				else if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID() && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i) {
					heil_harald.append(" ~b~[SELF] ~y~[HOST]");
					const char *cstr = heil_harald.c_str();
					if (NETWORK::NETWORK_IS_SIGNED_ONLINE() && PLAYER::IS_PLAYER_ONLINE() && NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS() > 1) {
						Menu::MenuOptions2(cstr, onlinemenu_selected, i) ? Features::Online::selectedPlayer = i : NULL;
					}
					else {
						Menu::ColorOption(cstr, onlinemenu_selected) ? Features::Online::selectedPlayer = i : NULL;
					}
				}
				else if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID() && USER::HAS_XFORCE(i)) {
					heil_harald.append(" ~b~[SELF]" + USER::XFORCE_TAG(i));
					const char *cstr = heil_harald.c_str();
					if (NETWORK::NETWORK_IS_SIGNED_ONLINE() && PLAYER::IS_PLAYER_ONLINE() && NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS() > 1) {
						Menu::MenuOptions2(cstr, onlinemenu_selected, i) ? Features::Online::selectedPlayer = i : NULL;
					}
					else {
						Menu::ColorOption(cstr, onlinemenu_selected) ? Features::Online::selectedPlayer = i : NULL;
					}
				}
				else if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID()) {
					heil_harald.append(" ~b~[SELF]");
					const char *cstr = heil_harald.c_str();
					if (NETWORK::NETWORK_IS_SIGNED_ONLINE() && PLAYER::IS_PLAYER_ONLINE() && NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS() > 1) {
						Menu::MenuOptions2(cstr, onlinemenu_selected, i) ? Features::Online::selectedPlayer = i : NULL;
					}
					else {
						Menu::ColorOption(cstr, onlinemenu_selected) ? Features::Online::selectedPlayer = i : NULL;
					}
				}
				else if (Features::isPlayerFriend(i, frnd) && frnd && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i) {
					heil_harald.append(" ~g~[FRIEND] ~y~[HOST]");
					const char *cstr = heil_harald.c_str();
					if (NETWORK::NETWORK_IS_SIGNED_ONLINE() && PLAYER::IS_PLAYER_ONLINE() && NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS() > 1) {
						Menu::MenuOptions2(cstr, onlinemenu_selected, i) ? Features::Online::selectedPlayer = i : NULL;
					}
					else {
						Menu::ColorOption(cstr, onlinemenu_selected) ? Features::Online::selectedPlayer = i : NULL;
					}
				}
				else if (Features::isPlayerFriend(i, frnd) && frnd && USER::HAS_XFORCE(i)) {
					heil_harald.append(" ~g~[FRIEND]" + USER::XFORCE_TAG(i));
					const char *cstr = heil_harald.c_str();
					if (NETWORK::NETWORK_IS_SIGNED_ONLINE() && PLAYER::IS_PLAYER_ONLINE() && NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS() > 1) {
						Menu::MenuOptions2(cstr, onlinemenu_selected, i) ? Features::Online::selectedPlayer = i : NULL;
					}
					else {
						Menu::ColorOption(cstr, onlinemenu_selected) ? Features::Online::selectedPlayer = i : NULL;
					}
				}
				else if (NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i && USER::HAS_XFORCE(i)) {
					heil_harald.append(" ~y~[HOST]" + USER::XFORCE_TAG(i));
					const char *cstr = heil_harald.c_str();
					if (NETWORK::NETWORK_IS_SIGNED_ONLINE() && PLAYER::IS_PLAYER_ONLINE() && NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS() > 1) {
						Menu::MenuOptions2(cstr, onlinemenu_selected, i) ? Features::Online::selectedPlayer = i : NULL;
					}
					else {
						Menu::ColorOption(cstr, onlinemenu_selected) ? Features::Online::selectedPlayer = i : NULL;
					}
				}
				else if (NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i) {
					heil_harald.append(" ~y~[HOST]");
					const char *cstr = heil_harald.c_str();
					if (NETWORK::NETWORK_IS_SIGNED_ONLINE() && PLAYER::IS_PLAYER_ONLINE() && NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS() > 1) {
						Menu::MenuOptions2(cstr, onlinemenu_selected, i) ? Features::Online::selectedPlayer = i : NULL;
					}
					else {
						Menu::ColorOption(cstr, onlinemenu_selected) ? Features::Online::selectedPlayer = i : NULL;
					}
				}
				else if (Features::isPlayerFriend(i, frnd) && frnd) {
					heil_harald.append(" ~g~[FRIEND]");
					const char *cstr = heil_harald.c_str();
					if (NETWORK::NETWORK_IS_SIGNED_ONLINE() && PLAYER::IS_PLAYER_ONLINE() && NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS() > 1) {
						Menu::MenuOptions2(cstr, onlinemenu_selected, i) ? Features::Online::selectedPlayer = i : NULL;
					}
					else {
						Menu::ColorOption(cstr, onlinemenu_selected) ? Features::Online::selectedPlayer = i : NULL;
					}
				}
				else if (USER::HAS_XFORCE(i)) {
					heil_harald.append(USER::XFORCE_TAG(i));
					const char *cstr = heil_harald.c_str();
					if (NETWORK::NETWORK_IS_SIGNED_ONLINE() && PLAYER::IS_PLAYER_ONLINE() && NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS() > 1) {
						Menu::MenuOptions2(cstr, onlinemenu_selected, i) ? Features::Online::selectedPlayer = i : NULL;
					}
					else {
						Menu::ColorOption(cstr, onlinemenu_selected) ? Features::Online::selectedPlayer = i : NULL;
					}
				}
				else {
					char* cstr = PLAYER::GET_PLAYER_NAME(i);
					if (NETWORK::NETWORK_IS_SIGNED_ONLINE() && PLAYER::IS_PLAYER_ONLINE() && NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS() > 1) {
						Menu::MenuOptions2(cstr, onlinemenu_selected, i) ? Features::Online::selectedPlayer = i : NULL;
					}
					else {
						Menu::ColorOption(cstr, onlinemenu_selected) ? Features::Online::selectedPlayer = i : NULL;
					}
				}
			}
		}
	}
	break;
	case onlinemenu_selected:
	{
		//Features::stillDontKnowAName = false;
		Features::LoadInfoplayer(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer), Features::Online::selectedPlayer);
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer));
		Menu::MenuOption("Teleport Options", playerTP);
		Menu::MenuOption("Griefing Options", grief);
		Menu::MenuOption("Peaceful Options", nice);
		if (Features::enableMoney) { Menu::MenuOption("Drop Options", dropmenyoo); }
		Menu::MenuOption("Attachments", trollattachments);
		Menu::MenuOption("ESP", playeresp);
		Menu::MenuOption("Remote Options", remote);
		Menu::Toggle("Spectate Player", Features::spectate[Features::Online::selectedPlayer], [] { Features::specter(Features::spectate[Features::Online::selectedPlayer]); });
	}
	break;
	case playeresp:
	{
		Features::LoadInfoplayer(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer), Features::Online::selectedPlayer);
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("ESP Menu");
		Menu::Toggle("ESP Box", Features::ESP::esp22bool[Features::Online::selectedPlayer]);
		Menu::Toggle("ESP Lines", Features::ESP::esp222bool[Features::Online::selectedPlayer]);
		Menu::Toggle("Name Tag ESP", Features::ESP::ntesp2bool[Features::Online::selectedPlayer]);
	}
	break;
	case dropmenyoo:
	{
		Features::LoadInfoplayer(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer), Features::Online::selectedPlayer);
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Drop Options");
		if (!Features::customRandom && !Features::customFakedrop) {
			Menu::Int("Amount", Features::customDropAmount, 0, 2500);
		}
		if (Features::customRandom || Features::customFakedrop) {
			int temp = 2500;
			Menu::Int("Amount", temp, 0, 2500);
		}
		Menu::Int("Delay", Features::customDropDelay, 0, 10000, 100);
		Menu::Int("Height", Features::customHeight, 0, 1000);
		Menu::Toggle("Enable Drop", Features::customDropBool[Features::Online::selectedPlayer], [] { Features::customDrop(Features::customDropBool[Features::Online::selectedPlayer]); });
		Menu::VipToggle("Fakedrop", Features::customFakedrop);
		//Menu::Option("Selected drop item:");
		switch (Features::MoneyItem) {
		case 0: Menu::Option("Selected drop item: Paper bag"); break;
		case 1: Menu::Option("Selected drop item: Paper bag 2"); break;
		case 2: Menu::Option("Selected drop item: Money case"); break;
		case 3: Menu::Option("Selected drop item: Alien egg"); break;
		case 4: Menu::Option("Selected drop item: Guitar"); break;
		case 5: Menu::Option("Selected drop item: Grave"); break;
		case 6: Menu::Option("Selected drop item: Dildo"); break;
		case 7: Menu::Option("Selected drop item: Dummy"); break;
		case 8: Menu::Option("Selected drop item: Toilet"); break;
		case 9: Menu::Option("Selected drop item: Weed package"); break;
		case 10: Menu::Option("Selected drop item: Oil"); break;
		case 11: Menu::Option("Selected drop item: EMP"); break;
		case 12: Menu::Option("Selected drop item: Ball"); break;
		case 13: Menu::Option("Selected drop item: Weed"); break;
		case 14: Menu::Option("Selected drop item: Safe"); break;
		case 15: Menu::Option("Selected drop item: UFO"); break;
		case 16: Menu::Option("Selected drop item: Xmas tree"); break;
		case 17: Menu::Option("Selected drop item: Radar"); break;
		case 18: Menu::Option("Selected drop item: Duffel"); break;
		case 19: Menu::Option("Selected drop item: Ramp"); break;
		case 20: Menu::Option("Selected drop item: Number 1"); break;
		case 21: Menu::Option("Selected drop item: Number 2"); break;
		case 22: Menu::Option("Selected drop item: Number 3"); break;
		case 23: Menu::Option("Selected drop item: Plane"); break;
		case 24: Menu::Option("Selected drop item: Cash pile"); break;
		case 25: Menu::Option("Selected drop item: Donut"); break;
		case 26: Menu::Option("Selected drop item: Ferris wheel"); break;
		}
		if (Menu::Option("Paper bag"))
		{
			Features::MoneyItem = 0;
		}
		if (Menu::Option("Alien egg"))
		{
			Features::MoneyItem = 3;
		}
		if (Menu::Option("Toilet"))
		{
			Features::MoneyItem = 8;
		}
		if (Menu::Option("Weed"))
		{
			Features::MoneyItem = 13;
		}
		if (Menu::Option("Xmas tree"))
		{
			Features::MoneyItem = 16;
		}

	}
	break;
	case playerTP:
	{
		Features::LoadInfoplayer(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer), Features::Online::selectedPlayer);
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Teleport options");
		Menu::Option("Teleport To Player", [] { Features::Online::TeleportToPlayer(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer)); });
		Menu::Option("Teleport into Vehicle", [] { Features::Online::TeleportIntoVehicle(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer)); });

	}
	break;
	case trollattachments:
	{
		Features::LoadInfoplayer(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer), Features::Online::selectedPlayer);
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Attachments");
		if (Menu::Option("Orange Ball")) { Features::attachobjects2("prop_juicestand"); }
		if (Menu::Option("Weed")) { Features::attachobjects2("prop_weed_01"); }
		if (Menu::Option("Safe")) { Features::attachobjects2("p_v_43_safe_s"); }
		if (Menu::Option("Ufo")) { Features::attachobjects2("p_spinning_anus_s"); }
		if (Menu::Option("Toilet")) { Features::attachobjects2("prop_ld_toilet_01"); }
		if (Menu::Option("Christmas Tree")) { Features::attachobjects2("prop_xmas_tree_int"); }
		if (Menu::Option("Windmill")) { Features::attachobjects2("prop_windmill_01"); }
	}
	break;
	case nice:
	{
		//Features::stillDontKnowAName = true;
		Features::LoadInfoplayer(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer), Features::Online::selectedPlayer);
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Peaceful Options");
		//if (Features::enableMoney) { Menu::Toggle("Moneydrop", Features::moneydrop[Features::Online::selectedPlayer], [] { Features::Moneydrop(Features::moneydrop[Features::Online::selectedPlayer]); }); }
		//if (Features::enableMoney) { Menu::Toggle("Spread drop", Features::spreaddrop[Features::Online::selectedPlayer], [] { Features::Spreaddrop(Features::spreaddrop[Features::Online::selectedPlayer]); }); }
		//if (Features::enableMoney) { Menu::Toggle("Rain drop", Features::cashrainbool[Features::Online::selectedPlayer], [] { Features::cashrain(Features::cashrainbool[Features::Online::selectedPlayer]); }); }
		if (Menu::Option("Give All Weapons")) {
			uint Weapons[] = { 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D };
			for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), Weapons[i], 9999, 1);
				WAIT(10);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), 9999, 1);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), GAMEPLAY::GET_HASH_KEY("weapon_assaultrifle_mk2"), 9999, 1);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), GAMEPLAY::GET_HASH_KEY("weapon_carbinerifle_mk2"), 9999, 1);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), GAMEPLAY::GET_HASH_KEY("weapon_combatmg_mk2"), 9999, 1);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), GAMEPLAY::GET_HASH_KEY("weapon_heavysniper_mk2"), 9999, 1);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), GAMEPLAY::GET_HASH_KEY("weapon_smg_mk2"), 9999, 1);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), 9999, 1);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), 9999, 1);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), 9999, 1);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), 9999, 1);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), 9999, 1);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), 9999, 1);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), 9999, 1);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 0x476BF155, 9999, 1);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 0xB62D1F67, 9999, 1);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 0xAF3696A1, 9999, 1);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 0x6D544C99, 9999, 1);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 0x3813FC08, 9999, 1);
			}
		}
		if (Menu::Option("Attach")) {
			ENTITY::ATTACH_ENTITY_TO_ENTITY(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 0, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, true, true, false, true, 2, true);
		}
		if (Menu::Option("Detach")) {
			ENTITY::DETACH_ENTITY(PLAYER::PLAYER_PED_ID(), true, true);
		}
		if (Menu::Option("Vehicle Godmode")) {
			RequestControlOfEnt(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer));
			RequestControlOfEnt(PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer)));
			Features::cargodmode2(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer));
		}
		//Menu::Toggle("Horn boost", Features::remoteCarboostbool[Features::Online::selectedPlayer], [] { Features::remoteCarboost(Features::remoteCarboostbool[Features::Online::selectedPlayer]); });
		Menu::VipToggle("Explosive Gun", Features::remoteExplobool[Features::Online::selectedPlayer], [] { Features::remoteExplo(Features::remoteExplobool[Features::Online::selectedPlayer]); });
		if (Menu::Option("Copy Outfit")) {
			Features::CopyOutfit(Features::Online::selectedPlayer);
		}
		if (Menu::Option("Blacklist")) { Features::addToBlacklist(Features::Online::selectedPlayer); XScript::getFileContent("X-Folder/friends/blacklist.txt", Features::blacklist_names); }
	}
	break;
	case grief:
	{
		//Features::stillDontKnowAName = true;
		Features::LoadInfoplayer(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer), Features::Online::selectedPlayer);
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Griefing options");
		if (Menu::Option("Explode")) {
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 29, 1000.f, true, false, 100.f);
		}
		if (Menu::Option("Burn")) {
			Features::beachFire(Features::Online::selectedPlayer);
		}
		if (Menu::Option("Blame")) {
			Features::blamee(Features::Online::selectedPlayer);
		}
		if (Menu::Option("Kick from Vehicle")) {
			RequestControlOfEnt(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer));
			AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer));
			AI::CLEAR_PED_TASKS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer));
			AI::CLEAR_PED_SECONDARY_TASK(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer));
		}
		if (Menu::Option("Cage in Box")) {
			Features::trapcage(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer));
		}
		Menu::Toggle("Water Loop", Features::playerwaterloop[Features::Online::selectedPlayer], [] {});
		if (Menu::Option("Clone"))
		{
			PED::CLONE_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 1, 1, 1);
		}
		int eclone[1000];
		int egcount = 1;
		if (Menu::Option("OH DAMN!!!")) {
			//Features::fuck_me_sideways(1);
			Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
			if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
			Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
			Hash pedm = GAMEPLAY::GET_HASH_KEY("U_M_M_Jesus_01");
			STREAMING::REQUEST_MODEL(pedm);
			while (!STREAMING::HAS_MODEL_LOADED(pedm))
				WAIT(0);
			eclone[egcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
			ENTITY::SET_ENTITY_INVINCIBLE(eclone[egcount], false);
			PED::SET_PED_COMBAT_ABILITY(eclone[egcount], 100);
			WEAPON::GIVE_WEAPON_TO_PED(eclone[egcount], railgun, railgun, 9999, 9999);
			PED::SET_PED_CAN_SWITCH_WEAPON(eclone[egcount], true);
			AI::TASK_COMBAT_PED(eclone[egcount], selectedplayer, 1, 1);
			PED::SET_PED_ALERTNESS(eclone[egcount], 1000);
			PED::SET_PED_COMBAT_RANGE(eclone[egcount], 1000);
			egcount++;
		}

		Menu::Toggle("Freeze", Features::freezed[Features::Online::selectedPlayer], [] {});
		if (Menu::VipOption("Taze")) {
			int currentAttempt = 0;
			int maxAttempts = 20;
			while (!ENTITY::IS_ENTITY_DEAD(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer)))
			{
				if (currentAttempt >= maxAttempts)
				{
					break;
				}
				else
				{
					Vector3 destination = PED::GET_PED_BONE_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), SKEL_ROOT, 0.0f, 0.0f, 0.0f);
					Vector3 origin = PED::GET_PED_BONE_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), SKEL_R_Hand, 0.0f, 0.0f, 0.2f);
					Hash tazerHash = GAMEPLAY::GET_HASH_KEY((char*)"WEAPON_STUNGUN");
					GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(origin.x, origin.y, origin.z, destination.x, destination.y, destination.z, 1, 0, tazerHash, PLAYER::PLAYER_PED_ID(), false, false, 1);
					currentAttempt++;
				}
				WAIT(0);
			}
		}
		if (Menu::Option("Pop Tires")) {
			Vehicle selectedlPlayerveh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
			bool isveh = PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
			if (isveh)
			{
				RequestControlOfEnt(selectedlPlayerveh);
				VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(selectedlPlayerveh, true);
				for (int i = 5; i--;)
					VEHICLE::SET_VEHICLE_TYRE_BURST(selectedlPlayerveh, i, true, 1000.f);

			}
		}
		if (Menu::Option("Slingshot Car")) {
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true));
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true)))
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true), 1, 0, 0, 20, 0, 0, 0, 1, false, true, true, true, true);
			}
		}
		Menu::Toggle("Explode Loop", Features::explodeLoopBool[Features::Online::selectedPlayer], [] {});
		if (Menu::VipOption("Hostile Buzzard")) {
			Features::hostilebuzzard = true;
			Features::vehspawncheck = true;
			if (Features::Hostilebuzzard(Features::Online::selectedPlayer))
			{
			}
			break;
		}
		//Menu::Toggle("Passive killer", Features::pussy1[Features::Online::selectedPlayer]);
		//Menu::Toggle("Killer NPCs", Features::killernpc[Features::Online::selectedPlayer]);
		/*if (Menu::Option("Hard vehicle control")) {
			Features::vehControl(Features::Online::selectedPlayer);
		}
		if (Menu::Option("Reset hard vehicle control")) {
			Features::playerinvisibility = false;
			Features::orbool = false;
			Features::fastRun = true;
			VEHICLE::SET_VEHICLE_DOORS_LOCKED_FOR_ALL_PLAYERS(PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer)), false);
		}*/
	}
	break;
	case remote:
	{
		Features::LoadInfoplayer(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer), Features::Online::selectedPlayer);
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Remote Options");
		if (Menu::Option("CEO Kick"))
		{
			Features::ceokick(Features::Online::selectedPlayer);
		}
		Menu::VipToggle("Disable CEO", Features::disableCEObool[Features::Online::selectedPlayer], [] { Features::disableCEO(Features::disableCEObool[Features::Online::selectedPlayer]); });
		if (Menu::Option("Non Host Kick"))
		{
			Features::kick(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer));
		}
		if (Menu::VipOption("Super Kick"))
		{
			Features::SUPERKICK(Features::Online::selectedPlayer);
		}
		if (Menu::Option("Invite")) {
			Features::inviteSpam(Features::Online::selectedPlayer, 8);
		}
		if (Menu::Option("Show Error")) {
			Features::trasactionSpam(Features::Online::selectedPlayer);
		}
		/*if (Menu::Option("Kick from Club")) {
			Features::clubkick(Features::Online::selectedPlayer);
		}
		if (Menu::Option("Crash")) {
			Features::remoteCrash(Features::Online::selectedPlayer);
		}*/
		/*if (Menu::Option("ss")) {
			unsigned int Bit = (1 << Features::Online::selectedPlayer);
			uint64_t args[10] = { -313275313, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), INT_MAX, 1000, 1, -1135378931, -856006867, 0, 1474183246, 1445302971 };
			Hooking::trigger_script_event(1, args, 10, Bit);
		}*/
		/*if (Menu::Option("idk lol")) {
			unsigned int Bit = (1 << Features::Online::selectedPlayer);
			uint64_t unkkek1 = globalHandle(2524719).At(2212).At(17).As<std::uint64_t>();
			uint64_t unkkek2 = globalHandle(2524719).At(2212).At(16).As<std::uint64_t>();
			uint64_t unkkek3 = globalHandle(2097152).At(0, 12745).At(12327).As<std::uint64_t>();
			Player p = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
			uint64_t args[7] = { 1808125173, p, -1, 0, unkkek1, unkkek2, unkkek3 };
			Hooking::trigger_script_event(1, args, 7, Bit);
		}*/
		if (Menu::Option("Give Wanted Level")) {
			Features::giveWanted(Features::Online::selectedPlayer);
		}
		if (Menu::VipOption("Steal Money")) {
			Features::remoteMoneyMsg(Features::Online::selectedPlayer, 2, r_amount);
		}
		if (Menu::Option("Gentle Kick from Vehicle")) {
			Features::gentleKick(Features::Online::selectedPlayer);
		}
		if (Menu::VipOption("Rotate Cam forward")) {
			Features::rotateCam(Features::Online::selectedPlayer);
		}
		if (Menu::Option("Teleport to Eclipse Tower")) { Features::remoteTP(Features::Online::selectedPlayer, 1); }
		if (Menu::Option("Clear Wanted Level")) {
			Features::remoteClearWanted(Features::Online::selectedPlayer);
		}
		if (Menu::Option("Spectate Message")) {
			Features::remoteSpectateMsg2(Features::Online::selectedPlayer);
		}
		if (Menu::Option("Send Cops")) {
			Features::remoteSendCops();
		}
		Menu::Toggle("Off the Radar", Features::remoteORbool[Features::Online::selectedPlayer]);
		/*if (Menu::Option("Bounty")) {
			auto var0 = globalHandle(2097152).At(0, 12745).At(12327).At(14).As<std::uint64_t>();
			auto var1 = globalHandle(1643357).At(9).As<std::uint64_t>();
			auto var2 = globalHandle(1643357).At(10).As<std::uint64_t>();
			Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
			unsigned int Bit = (1 << Features::Online::selectedPlayer);
			uint64_t args[22] = { -679747935, ped, PLAYER::PLAYER_ID(), 0, var0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, var1, var2 };
			Hooking::trigger_script_event(1, args, 22, Bit);
		}*/
	}
	break;

#pragma endregion

#pragma region aioplayer


	case weather:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Weather Options");
		Menu::Toggle("Asteroid Shower", Features::asteroidshower, [] { Features::AsteroidShower(Features::asteroidshower); });
		if (Menu::Option("Extra Sunny"))
		{
			Hooking::set_session_weather(1, 0, 76, 0);
		}
		if (Menu::Option("Clear"))
		{
			Hooking::set_session_weather(1, 1, 76, 0);
		}
		if (Menu::Option("Clouds"))
		{
			Hooking::set_session_weather(1, 2, 76, 0);
		}
		if (Menu::Option("Rain"))
		{
			Hooking::set_session_weather(1, 6, 76, 0);
		}
		if (Menu::Option("Thunder"))
		{
			Hooking::set_session_weather(1, 7, 76, 0);
		}
		if (Menu::VipOption("Xmas"))
		{
			Hooking::set_session_weather(1, 13, 76, 0);
		}
	}
	break;
	case loctime:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Time Options (Local)");
		Menu::Int("Hours", timeH, 0, 23);
		Menu::Int("Minutes", timeM, 0, 59);
		Menu::Int("Seconds", timeS, 0, 59);
		if (Menu::Option("Set Time")) {
			Hooking::settime(timeH, timeM, timeS);
		}
		Menu::Toggle("Freeze Time", Features::pauseTimeBool, [] { Features::pauseTime(Features::pauseTimeBool); });
		Menu::Toggle("Sync with System Time", Features::sync, [] { Features::syncTime(); });
	}
	break;
	case exclude:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Excludes");
		Menu::Toggle("Exclude Self", Features::excludeSelf);
		Menu::Toggle("Exclude Friends", Features::excludeFriends);
	}
	break;
	case aioplist:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("All Online Players");
		Menu::MenuOption("Excludes", exclude);
		Menu::MenuOption("Lobby Weather", weather);
		Menu::VipMenuOption("Lobby Time", lobbytime);
		Menu::MenuOption("Remote Options", remoteall);
		Menu::MenuOption("ESP", espmenu);
		if (Menu::Option("Explode Lobby")) {
			for (int i = 0; i < 33; i++)
			{
				if (Features::exclude(i))
				{
					Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
					FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 29, 1000.f, true, false, 100.f);
				}
			}
		}
		if (Menu::Option("Kick all from Vehicle")) {
			for (int i = 0; i < 33; i++)
			{
				if (Features::exclude(i))
				{
					RequestControlOfEnt(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
					AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
					AI::CLEAR_PED_TASKS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
					AI::CLEAR_PED_SECONDARY_TASK(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
				}
			}
		}
		if (Menu::Option("Clone Everyone")) {
			for (int i = 0; i < 33; i++) {
				if (Features::exclude(i)) {
					PED::CLONE_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 1, 1, 1);
				}
			}
		}
		int eclone2[1000];
		int egcount2 = 1;
		//Menu::MenuOption("Spawn custom attacker for everyone", allcustomenemy);
		if (Menu::Option("Ram everyone with Vehicle")) {
			for (int i = 0; i < 33; i++) {
				if (Features::exclude(i)) {
					Features::ramWithVeh(i);
				}
			}
		}
		Menu::Toggle("Fire Loop", Features::allfireloop, [] { Features::allFireLoop(Features::allfireloop); });
		Menu::Toggle("Water Loop", Features::allwaterloop, [] { Features::allWaterLoop(Features::allwaterloop); });
	}

	break;
	case allcustomenemy:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Spawn Attacker for Everyone");
		Menu::MenuOption("Select Model", allcustomenemymodel);
		Menu::MenuOption("Select Weapon", allcustomenemyweapon);
		Menu::Option(Features::enemyModel);
		Menu::Option(Features::enemyWeapon);
		if (Features::enemyModel != NULL && Features::enemyWeapon != NULL) {
			if (Menu::Option("Spawn Attacker for Everyone")) {
				for (int i = 0; i < 33; i++) {
					if (Features::exclude(i)) {
						Features::spawnEnemy(i, Features::enemyModel, Features::enemyWeapon);
					}
				}
			}
		}
		else {
			Menu::Option("Spawn Attacker for Everyone (Arguments missing!)");
		}
	}
	break;
	case allcustomenemyweapon:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(Features::enemyWeapon);
		if (Menu::Option("Pistol")) { Features::enemyWeapon = "WEAPON_PISTOL"; }
		if (Menu::Option("AP-Pistol")) { Features::enemyWeapon = "WEAPON_APPISTOL"; }
		if (Menu::Option("SMG")) { Features::enemyWeapon = "WEAPON_SMG"; }
		if (Menu::Option("Carbine")) { Features::enemyWeapon = "WEAPON_CARBINERIFLE"; }
		if (Menu::Option("MG")) { Features::enemyWeapon = "WEAPON_MG"; }
		if (Menu::Option("Pump shotgun")) { Features::enemyWeapon = "WEAPON_PUMPSHOTGUN"; }
		if (Menu::Option("Assault shotgun")) { Features::enemyWeapon = "WEAPON_ASSAULTSHOTGUN"; }
		if (Menu::Option("Stungun")) { Features::enemyWeapon = "WEAPON_STUNGUN"; }
		if (Menu::Option("Sniper")) { Features::enemyWeapon = "WEAPON_SNIPERRIFLE"; }
		if (Menu::Option("Heavy sniper")) { Features::enemyWeapon = "WEAPON_HEAVYSNIPER"; }
		if (Menu::Option("Grenade launcher")) { Features::enemyWeapon = "WEAPON_GRENADELAUNCHER"; }
		if (Menu::Option("RPG")) { Features::enemyWeapon = "WEAPON_RPG"; }
		if (Menu::Option("Minigun")) { Features::enemyWeapon = "WEAPON_MINIGUN"; }
		if (Menu::Option("Grenade")) { Features::enemyWeapon = "WEAPON_GRENADE"; }
		if (Menu::Option("Sticky bomb")) { Features::enemyWeapon = "WEAPON_STICKYBOMB"; }
		if (Menu::Option("Railgun")) { Features::enemyWeapon = "WEAPON_RAILGUN"; }
	}
	break;
	case allcustomenemymodel:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(Features::enemyModel);
		for (auto i : pedModels) { Menu::Option(i, [i] { Features::enemyModel = i; }); }
	}
	break;
	case lobbytime:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Lobby Time");
		//TO DO!
		Menu::Int("Time", hhh, 0, 23);
		if (Menu::Option("Set Time")) {
			Features::set_network_time(hhh, mmm, sss);
		}
	}
	break;
	case espmenu:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("ESP Menu");
		Menu::Toggle("ESP Box", Features::ESP::esp2b);
		Menu::Toggle("ESP Lines", Features::ESP::esper);
		Menu::Toggle("Name Tag ESP", Features::ESP::NameESP);
	}
	break;
	case espcolor:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("ESP Colors");
		Menu::Int("Red", Features::ESP::red, 0, 255);
		Menu::Int("Green", Features::ESP::green, 0, 255);
		Menu::Int("Blue", Features::ESP::blue, 0, 255);
	}
	break;
	case remoteall:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Remote Options");
		if (Menu::Option("Non Host Kick")) {
			Features::TSEall(769347061);
		}
		if (Menu::VipOption("Teleport to Eclipse Tower")) {
			for (int i = 0; i < 33; i++) {
				if (Features::exclude(i)) {
					Features::remoteTP(i, 1);
				}
			}
		}
		if (Menu::Option("Show Error")) {
			for (int i = 0; i < 33; i++) {
				if (Features::exclude(i)) {
					Features::trasactionSpam(i);
				}
			}
		}
		/*if (Menu::Option("Notification (Visible players)")) {
			for (int i = 0; i < 33; i++) {
				if (Features::exclude(i)) {
					Features::notification(Features::Online::selectedPlayer, 1);
				}
			}
		}
		if (Menu::Option("Notification (King killed)")) {
			for (int i = 0; i < 33; i++) {
				if (Features::exclude(i)) {
					Features::notification(i, 2);
				}
			}
		}
		if (Menu::Option("Notification (Off radar)")) {
			for (int i = 0; i < 33; i++) {
				if (Features::exclude(i)) {
					Features::notification(i, 3);
				}
			}
		}
		if (Menu::Option("Notification (Wanted)")) {
			for (int i = 0; i < 33; i++) {
				if (Features::exclude(i)) {
					Features::notification(i, 4);
				}
			}
		}
		if (Menu::Option("Notification (Mugger)")) {
			for (int i = 0; i < 33; i++) {
				if (Features::exclude(i)) {
					Features::notification(i, 5);
				}
			}
		}
		if (Menu::Option("Notification (Money bag)")) {
			for (int i = 0; i < 33; i++) {
				if (Features::exclude(i)) {
					Features::notification(i, 6);
				}
			}
		}
		if (Menu::Option("Notification (Into thing)")) {
			for (int i = 0; i < 33; i++) {
				if (Features::exclude(i)) {
					Features::notification(i, 7);
				}
			}
		}
		if (Menu::Option("Notification (Smuggler)")) {
			for (int i = 0; i < 33; i++) {
				if (Features::exclude(i)) {
					Features::notification(i, 8);
				}
			}
		}
		if (Menu::Option("Notification (Suicide)")) {
			for (int i = 0; i < 33; i++) {
				if (Features::exclude(i)) {
					Features::notification(i, 9);
				}
			}
		}
		if (Menu::Option("Notification (Truck)")) {
			for (int i = 0; i < 33; i++) {
				if (Features::exclude(i)) {
					Features::notification(i, 10);
				}
			}
		}*/
		if (Menu::Option("Clear Wanted Level")) {
			for (int i = 0; i < 33; i++) {
				if (Features::exclude(i)) {
					Features::remoteClearWanted(i);
				}
			}
		}
	}
	break;
	case attachall:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Attachments for everyone");
		if (Menu::Option("Plate")) { Features::attachobjects3("p_oil_slick_01"); }
		if (Menu::Option("EMP")) { Features::attachobjects3("hei_prop_heist_emp"); }
		if (Menu::Option("Orange Ball")) { Features::attachobjects3("prop_juicestand"); }
		if (Menu::Option("Weed")) { Features::attachobjects3("prop_weed_01"); }
		if (Menu::Option("Safe")) { Features::attachobjects3("p_v_43_safe_s"); }
		if (Menu::Option("Ufo")) { Features::attachobjects3("p_spinning_anus_s"); }
		if (Menu::Option("Toilet")) { Features::attachobjects3("prop_ld_toilet_01"); }
		if (Menu::Option("Christmas Tree")) { Features::attachobjects3("prop_xmas_tree_int"); }
		if (Menu::Option("Windmill")) { Features::attachobjects3("prop_windmill_01"); }
		if (Menu::Option("Radar")) { Features::attachobjects3("prop_air_bigradar"); }
		if (Menu::Option("Alien Egg")) { Features::attachobjects3("prop_alien_egg_01"); }
		if (Menu::Option("Beggers Sign")) { Features::attachobjects3("prop_beggers_sign_01"); }
		if (Menu::Option("Tramp Sign")) { Features::attachobjects3("prop_beggers_sign_02"); }
		if (Menu::Option("Egg Clock")) { Features::attachobjects3("prop_egg_clock_01"); }
		if (Menu::Option("Guitar")) { Features::attachobjects3("prop_acc_guitar_01_d1"); }
		if (Menu::Option("Duffel")) { Features::attachobjects3("prop_cs_duffel_01b"); }
		if (Menu::Option("Vending Dispenser")) { Features::attachobjects3("prop_juice_dispenser"); }
		if (Menu::Option("Boxing")) { Features::attachobjects3("prop_boxing_glove_01"); }
		if (Menu::Option("Dingy")) { Features::attachobjects3("prop_byard_dingy"); }
		if (Menu::Option("Dildo")) { Features::attachobjects3("prop_cs_dildo_01"); }
		if (Menu::Option("Dumpster")) { Features::attachobjects3("prop_cs_dumpster_01a"); }
		if (Menu::Option("DJ")) { Features::attachobjects3("prop_dj_deck_02"); }
		if (Menu::Option("Plane")) { Features::attachobjects3("prop_dummy_plane"); }
		if (Menu::Option("Ramp")) { Features::attachobjects3("PROP_MP_RAMP_03"); }
		if (Menu::Option("Ramp2")) { Features::attachobjects3("PROP_MP_RAMP_02"); }
		if (Menu::Option("Ramp3")) { Features::attachobjects3("PROP_MP_RAMP_01"); }
		if (Menu::Option("Skip")) { Features::attachobjects3("PROP_SKIP_08A"); }
		if (Menu::Option("Number 1")) { Features::attachobjects3("PROP_MP_NUM_1"); }
		if (Menu::Option("Number 2")) { Features::attachobjects3("PROP_MP_NUM_2"); }
		if (Menu::Option("Number 3")) { Features::attachobjects3("PROP_MP_NUM_3"); }
		if (Menu::Option("Number 4")) { Features::attachobjects3("PROP_MP_NUM_4"); }
		if (Menu::Option("Number 5")) { Features::attachobjects3("PROP_MP_NUM_5"); }
		if (Menu::Option("Number 6")) { Features::attachobjects3("PROP_MP_NUM_6"); }
		if (Menu::Option("Number 7")) { Features::attachobjects3("PROP_MP_NUM_7"); }
		if (Menu::Option("Number 8")) { Features::attachobjects3("PROP_MP_NUM_8"); }
		if (Menu::Option("Number 9")) { Features::attachobjects3("PROP_MP_NUM_9"); }
		if (Menu::Option("Beer Neon")) { Features::attachobjects3("prop_beer_neon_01"); }
		if (Menu::Option("Dummy Plane")) { Features::attachobjects3("prop_dummy_plane"); }
		if (Menu::Option("Cash Pile")) { Features::attachobjects3("prop_anim_cash_pile_02"); }
		if (Menu::Option("Asteroid")) { Features::attachobjects3("prop_asteroid_01"); }
		if (Menu::Option("Weed Palet")) { Features::attachobjects3("prop_weed_pallet"); }
		if (Menu::Option("Ferris Wheel")) { Features::attachobjects3("prop_Ld_ferris_wheel"); }
		if (Menu::Option("Donut")) { Features::attachobjects3("prop_amb_donut"); }
		if (Menu::Option("Basejump")) { Features::attachobjects3("prop_basejump_target_01"); }
		if (Menu::Option("Handbag")) { Features::attachobjects3("prop_amb_handbag_01"); }
		if (Menu::Option("Cargo")) { Features::attachobjects3("prop_air_cargo_01a"); }
		if (Menu::Option("Stunt Ramp BIG")) { Features::attachobjects3("stt_prop_ramp_multi_loop_rb"); }
		if (Menu::Option("Crashed Heli")) { Features::attachobjects3("prop_crashed_heli"); }
		if (Menu::Option("Crashed Heli 2")) { Features::attachobjects3("prop_crashed_heli_s"); }
		if (Menu::Option("Train")) { Features::attachobjects3("prop_rail_boxcar3"); }
		if (Menu::Option("Roller")) { Features::attachobjects3("prop_roller_car_02"); }
		if (Menu::Option("Para")) { Features::attachobjects3("p_cargo_chute_s"); }
		if (Menu::Option("Delete Attachments")) {
			char* objects[136] = { "prop_bskball_01", "PROP_MP_RAMP_03", "PROP_MP_RAMP_02", "PROP_MP_RAMP_01", "PROP_JETSKI_RAMP_01", "PROP_WATER_RAMP_03", "PROP_VEND_SNAK_01", "PROP_TRI_START_BANNER", "PROP_TRI_FINISH_BANNER", "PROP_TEMP_BLOCK_BLOCKER", "PROP_SLUICEGATEL", "PROP_SKIP_08A", "PROP_SAM_01", "PROP_RUB_CONT_01B", "PROP_ROADCONE01A", "PROP_MP_ARROW_BARRIER_01", "PROP_HOTEL_CLOCK_01", "PROP_LIFEBLURB_02", "PROP_COFFIN_02B", "PROP_MP_NUM_1", "PROP_MP_NUM_2", "PROP_MP_NUM_3", "PROP_MP_NUM_4", "PROP_MP_NUM_5", "PROP_MP_NUM_6", "PROP_MP_NUM_7", "PROP_MP_NUM_8", "PROP_MP_NUM_9", "prop_xmas_tree_int", "prop_bumper_car_01", "prop_beer_neon_01", "prop_space_rifle", "prop_dummy_01", "prop_rub_trolley01a", "prop_wheelchair_01_s", "PROP_CS_KATANA_01", "PROP_CS_DILDO_01", "prop_armchair_01", "prop_bin_04a", "prop_chair_01a", "prop_dog_cage_01", "prop_dummy_plane", "prop_golf_bag_01", "prop_arcade_01", "hei_prop_heist_emp", "prop_alien_egg_01", "prop_air_towbar_01", "hei_prop_heist_tug", "prop_air_luggtrolley", "PROP_CUP_SAUCER_01", "prop_wheelchair_01", "prop_ld_toilet_01", "prop_acc_guitar_01", "prop_bank_vaultdoor", "p_v_43_safe_s", "p_spinning_anus_s", "prop_can_canoe", "prop_air_woodsteps", "Prop_weed_01", "prop_a_trailer_door_01", "prop_apple_box_01", "prop_air_fueltrail1", "prop_barrel_02a", "prop_barrel_float_1", "prop_barrier_wat_03b", "prop_air_fueltrail2", "prop_air_propeller01", "prop_windmill_01", "prop_Ld_ferris_wheel", "p_tram_crash_s", "p_oil_slick_01", "p_ld_stinger_s", "p_ld_soc_ball_01", "prop_juicestand", "p_oil_pjack_01_s", "prop_barbell_01", "prop_barbell_100kg", "p_parachute1_s", "p_cablecar_s", "prop_beach_fire", "prop_lev_des_barge_02", "prop_lev_des_barge_01", "prop_a_base_bars_01", "prop_beach_bars_01", "prop_air_bigradar", "prop_weed_pallet", "prop_artifact_01", "prop_attache_case_01", "prop_large_gold", "prop_roller_car_01", "prop_water_corpse_01", "prop_water_corpse_02", "prop_dummy_01", "prop_atm_01", "hei_prop_carrier_docklight_01", "hei_prop_carrier_liferafts", "hei_prop_carrier_ord_03", "hei_prop_carrier_defense_02", "hei_prop_carrier_defense_01", "hei_prop_carrier_radar_1", "hei_prop_carrier_radar_2", "hei_prop_hei_bust_01", "hei_prop_wall_alarm_on", "hei_prop_wall_light_10a_cr", "prop_afsign_amun", "prop_afsign_vbike", "prop_aircon_l_01", "prop_aircon_l_02", "prop_aircon_l_03", "prop_aircon_l_04", "prop_airhockey_01", "prop_air_bagloader", "prop_air_blastfence_01", "prop_air_blastfence_02", "prop_air_cargo_01a", "prop_air_chock_01", "prop_air_chock_03", "prop_air_gasbogey_01", "prop_air_generator_03", "prop_air_stair_02", "prop_amb_40oz_02", "prop_amb_40oz_03", "prop_amb_beer_bottle", "prop_amb_donut", "prop_amb_handbag_01", "prop_amp_01", "prop_anim_cash_pile_02", "prop_asteroid_01", "prop_arm_wrestle_01", "prop_ballistic_shield", "prop_bank_shutter", "prop_barier_conc_02b", "prop_barier_conc_05a", "prop_barrel_01a", "prop_bar_stool_01", "prop_basejump_target_01" };
			for (int h = 0; h < 33; h++) {
				for (int i = 0; i < 5; i++) {
					Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(h), 1);
					GAMEPLAY::CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 2, 0);
					GAMEPLAY::CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 2, 0);
					GAMEPLAY::CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 2, 0, 0, 0, 0, 0);
					for (int i = 0; i < 136; i++) {
						Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 4.0, GAMEPLAY::GET_HASH_KEY(objects[i]), 0, 0, 1);

						if (ENTITY::DOES_ENTITY_EXIST(obj) && ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(obj, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(h))) {
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
			}
		}
	}
	break;

#pragma endregion

#pragma region vehicle

	case cargobobmods:
	{
		char* cargobob[4] = { "CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4" };
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Cargobob Mods");
		Vehicle veh;
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) { veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()); }
		if (Menu::Option("Spawn Cargobob")) {
			Features::spawnincar = true;
			Features::spawn_vehicle(cargobob[0]);
			VEHICLE::CREATE_PICK_UP_ROPE_FOR_CARGOBOB(veh, 0);
		}
		if (Menu::Option("Attach Magnet")) {
			VEHICLE::CREATE_PICK_UP_ROPE_FOR_CARGOBOB(veh, 1);
		}
	}
	break;
	case vehicles:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Vehicle Options");
		if (Menu::Option("Vehicle Godmode"))
		{
			Features::cargodmode();
		}
		if (Menu::Option("Fix Vehicle")) {
			uint Vehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
			VEHICLE::SET_VEHICLE_FIXED(Vehicle);
			VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(Vehicle);
			VEHICLE::SET_VEHICLE_DIRT_LEVEL(Vehicle, 0);
		}
		if (Menu::Option("Max Vehicle"))
		{
			Features::maxvehicle1();
		}
		Menu::Toggle("Rainbow Color", Features::Rcolor, [] { Features::RainbowColor(Features::Rcolor); });
		Menu::Toggle("Horn Boost", Features::boostbool, [] { Features::carboost(Features::boostbool); });
		if (Menu::Int("Hornboost Speed", Features::hornboostInput, 1, 100)) {
			Features::setHornboostSpeed(Features::hornboostInput);
		}
		Menu::Toggle("Vehicle Jump", Features::vehjump, [] { Features::VehJump(Features::vehjump); });
		Menu::Toggle("Drive on Water", Features::dowbool, [] { Features::DriveOnWater(Features::dowbool); });
		Menu::VipToggle("Invisible Vehicle", Features::carinvisbool, [] { Features::carinvis(Features::carinvisbool); });
		Menu::Toggle("Stick to Ground", Features::stickToGround, [] { Features::vehStuckToGround(); });
		Menu::VipToggle("Bomber Mode", Features::bomber);
		Menu::VipMenuOption("Cargobob Mods", cargobobmods);
		Menu::VipMenuOption("Speedometer", speedometa);
		Menu::MenuOption("Vehicle Weapons", vehicleweapons);
		Menu::MenuOption("Vehicle Color", customcarcolor);
	}
	break;
	case speedometa:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Speedometer");
		Menu::MenuOption("Select Unit", unit);
		Menu::Toggle("On Numberplate", Features::numberplateSp);
		Menu::Toggle("Enable Speedometer", Features::Speedometer);
	}
	break;
	case unit:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Unit");
		if (Menu::Option("Kilometer per Hour")) { Features::unitt = "KM/H"; }
		if (Menu::Option("Meter per Second")) { Features::unitt = "M/S"; }
		if (Menu::Option("Miles per Hour")) { Features::unitt = "MPH"; }
	}
	break;
	case xmlvehicles:
	{
		//Features::stillDontKnowAName = true;
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("INI Vehicles");
		if (firsttime2) {
			Features::loadNames();
			Log::Msg("Successfully loaded vehicle data.");
			firsttime2 = false;
		}
		for (int i = 0; i < Features::ini1.size(); i++) {
			if (Menu::Option(Features::ini1[i].c_str())) {
				Features::LoadPreset(Features::ini1[Menu::Settings::currentOption - 1]);
			}
		}
	}
	break;
	case vehicleweapons:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Vehicle Weapons");
		Menu::StringVector("Select Hotkey", Features::keynames, Features::keyIndex);
		Menu::Toggle("Shoot Rockets", Features::ShootR, [] { Features::ShootRocket(Features::ShootR); }); //
		Menu::Toggle("Shoot Fireworks", Features::ShootT, [] { Features::ShootTanks(Features::ShootT); }); //
		Menu::Toggle("Shoot red Laser", Features::llcar, [] { Features::LLCar(Features::llcar); }); //
	}
	break;
	case customcarcolor:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Custom Vehicle Color");
		Menu::MenuOption("Colors", carpaint);
		if (Menu::ColorOption("Select Color", vehiclecolorr)) {
			Menu::Settings::selectPressed = false;
		}
		Menu::Int("Red", Features::cccred, 0, 255);
		Menu::Int("Green", Features::cccgreen, 0, 255);
		Menu::Int("Blue", Features::cccblue, 0, 255);
		if (Menu::Option("Set primary Color")) {
			Features::setColor(PLAYER::PLAYER_PED_ID(), Features::cccred, Features::cccgreen, Features::cccblue, true);
		}
		Menu::Int("Red", Features::cccred2, 0, 255);
		Menu::Int("Green", Features::cccgreen2, 0, 255);
		Menu::Int("Blue", Features::cccblue2, 0, 255);
		if (Menu::Option("Set primary Color")) {
			Features::setColor(PLAYER::PLAYER_PED_ID(), Features::cccred2, Features::cccgreen2, Features::cccblue2, false);
		}
		Menu::Int("Red", Features::cccred3, 0, 255);
		Menu::Int("Green", Features::cccgreen3, 0, 255);
		Menu::Int("Blue", Features::cccblue3, 0, 255);
		if (Menu::Option("Set both Colors")) {
			Features::setColor(PLAYER::PLAYER_PED_ID(), Features::cccred3, Features::cccgreen3, Features::cccblue3, false);
			Features::setColor(PLAYER::PLAYER_PED_ID(), Features::cccred3, Features::cccgreen3, Features::cccblue3, true);
		}
	}
	break;
	case vehiclecolorr:
	{
		/*colorTick++;
		if (colorTick > 80) {
			Menu::Settings::canSelect = true;
			colorTick = 0;
		}*/
		RGBA col = Menu::colors();
		if (col.r != -1 && col.g != -1 && col.b != -1 && col.a != -1) {
			Features::setColor(PLAYER::PLAYER_PED_ID(), col.r, col.g, col.b, true);
			Features::setColor(PLAYER::PLAYER_PED_ID(), col.r, col.g, col.b, false);
			//fromCol = true;
			//fromCol = false;
			//Menu::MenuLevelHandler::BackMenu();
		}

	}
	break;
	case carpaint:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Colors");
		if (Menu::Option("Random")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);
			if (VEHICLE::GET_IS_VEHICLE_SECONDARY_COLOUR_CUSTOM(veh))
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);
		}
		if (Menu::Option("Chrome")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_COLOURS(veh, 120, 120);
		}
		if (Menu::Option("Black")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 0, 0, 0);
		}
		if (Menu::Option("White")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 255, 255);
		}
		if (Menu::Option("Red")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 0, 0);
		}
		if (Menu::Option("Green")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 0, 255, 0);
		}
		if (Menu::Option("Blue")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 0, 0, 255);
		}
		if (Menu::Option("Orange")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 128, 0);
		}
		if (Menu::Option("Yellow")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 255, 0);
		}
		if (Menu::Option("Purple")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 204, 0, 204);
		}
		if (Menu::Option("Grey")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 96, 96, 96);
		}
		if (Menu::Option("Brown")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 165, 42, 42);
		}
		if (Menu::Option("Pink")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 51, 255);
		}
		if (Menu::Option("Cool Green")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 0, 255, 196);
		}
		if (Menu::Option("Hot Pink")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 0, 145);
		}
		if (Menu::Option("Lime")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 128, 255, 0);
		}
		if (Menu::Option("Lava Red")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 60, 0);
		}
		if (Menu::Option("Mint Green")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 0, 255, 119);
		}
		if (Menu::Option("Neon Green")) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 187, 255, 0);
		}
	}
	break;

#pragma endregion

#pragma region weapon

	case weapons:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Weapon Options");
		Menu::VipMenuOption("Remote Gun", remote_gun);
		Menu::VipMenuOption("Kill Spoofer", kill_spoofer);
		if (Menu::Option("Give All Weapons")) {
			Hash ass = GAMEPLAY::GET_HASH_KEY("weapon_assaultrifle_mk2");
			Hash car = GAMEPLAY::GET_HASH_KEY("weapon_carbinerifle_mk2");
			Hash com = GAMEPLAY::GET_HASH_KEY("weapon_combatmg_mk2﻿");
			Hash heavy = GAMEPLAY::GET_HASH_KEY("weapon_heavysniper_mk2");
			Hash pis = GAMEPLAY::GET_HASH_KEY("weapon_pistol_mk2");
			Hash smg = GAMEPLAY::GET_HASH_KEY("weapon_smg_mk2");
			Hash bull = GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2");
			Hash pump = GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2");
			Hash mark = GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2");
			Hash lasercarbine = 0x476BF155;
			Hash laserminigun = 0xB62D1F67;
			Hash laserpistol = 0xAF3696A1;
			Hash railgun = 0x6D544C99;
			Hash hatchet = 0x3813FC08;
			uint Weapons[] = { 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D };
			for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), Weapons[i], 9999, 1);
			}
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), pump, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), mark, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), bull, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), ass, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), car, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), com, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), heavy, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), pis, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), smg, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), lasercarbine, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), laserminigun, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), laserpistol, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), railgun, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), hatchet, 9999, 1);
		}
		if (Menu::Option("Give MK2 Weapons")) {
			Hash ass = GAMEPLAY::GET_HASH_KEY("weapon_assaultrifle_mk2");
			Hash car = GAMEPLAY::GET_HASH_KEY("weapon_carbinerifle_mk2");
			Hash com = GAMEPLAY::GET_HASH_KEY("weapon_combatmg_mk2﻿");
			Hash heavy = GAMEPLAY::GET_HASH_KEY("weapon_heavysniper_mk2");
			Hash pis = GAMEPLAY::GET_HASH_KEY("weapon_pistol_mk2");
			Hash smg = GAMEPLAY::GET_HASH_KEY("weapon_smg_mk2");
			Hash bull = GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2");
			Hash pump = GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2");
			Hash mark = GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2");
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), pump, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), mark, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), bull, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), ass, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), car, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), com, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), heavy, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), pis, 9999, 1);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), smg, 9999, 1);
		}
		if (Menu::Option("Max Ammo"))
		{
			Hash weaponhash;
			WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &weaponhash, 1);
			WEAPON::SET_PED_AMMO(PLAYER::PLAYER_PED_ID(), weaponhash, 9999);
		}
		Menu::Toggle("Infinite Ammo", Features::infammo, [] { Features::Infammo(Features::infammo); });
		Menu::Toggle("Rapid Fire", Features::rapidfirer, [] { Features::rapidmaker(Features::rapidfirer); });

		if (Features::enableMoney) { Menu::Toggle("Money gun", Features::moneygun, [] { Features::MoneyGun(Features::moneygun); }); }
		Menu::VipToggle("Minecraft Gun", Features::mgun, [] { Features::Mcgun(); });
		Menu::VipToggle("Triggerbot", Features::Triggerbot, [] { Features::TriggerBot(Features::Triggerbot); });
		Menu::Toggle("Delete Gun", Features::delgun, [] { Features::DelGun(); });
		Menu::Toggle("Kick Gun", Features::kickGunBool, [] { Features::kickGun(); });
		Menu::Toggle("Explosive Melee", Features::ffs3);
		Menu::Toggle("Explosive Ammo", Features::ffs1);
		Menu::VipToggle("Ped swap Gun", Features::pedswap);
		Menu::VipToggle("Missile Gun", Features::VALKYIREROCKET, [] { Features::valkyirerocket(Features::VALKYIREROCKET); });
		Menu::Toggle("Meow Gun", Features::meowBool);
	}
	break;
	case kill_spoofer:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Kill Spoofer");
		Menu::Toggle("Enable Kill Spoofer", Features::killSpooferOn);
		ostringstream s_killer; s_killer << "Selected: " << PLAYER::GET_PLAYER_NAME(Features::spoofKiller);
		Menu::Option(s_killer.str().c_str());
		for (int i = 0; i < 33; i++) {
			if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
				if (Menu::Option(PLAYER::GET_PLAYER_NAME(i))) {
					Features::spoofKiller = i;
				}
			}
		}
	}
	break;
	case remote_gun:
	{
		Menu::Title(Menu::Settings::menuname);
		switch (Features::remoteGunId) {
		case 0: Menu::Break("Selected Event: CEO Ban"); break;
		case 1: Menu::Break("Selected Event: CEO Kick"); break;
		case 2: Menu::Break("Selected Event: Non Host Kick"); break;
		case 3: Menu::Break("Selected Event: Singleplayer Kick"); break;
		case 4: Menu::Break("Selected Event: Super Kick"); break;
		case 5: Menu::Break("Selected Event: Infinite Loading Screen"); break;
		case 6: Menu::Break("Selected Event: Teleport to Apartment"); break;
		case 7: Menu::Break("Selected Event: CEO Ban Notification"); break;
		case 8: Menu::Break("Selected Event: CEO Kick Notification"); break;
		case 9: Menu::Break("Selected Event: Gentle Kick from Vehicle"); break;
		case 10: Menu::Break("Selected Event: Invite"); break;
		case 11: Menu::Break("Selected Event: Rotate Cam forward"); break;
		case 12: Menu::Break("Selected Event: Show Error"); break;
		case 13: Menu::Break("Selected Event: Send Money Notification (Banked)"); break;
		case 14: Menu::Break("Selected Event: Send Money Notification (Withdrawn)"); break;
		case 15: Menu::Break("Selected Event: Send Money Notification (Stolen)"); break;
		case 16: Menu::Break("Selected Event: Send to Mission"); break;
		case 17: Menu::Break("Selected Event: Blackscreen"); break;
		case 18: Menu::Break("Selected Event: Spectate Message"); break;
		case 19: Menu::Break("Selected Event: Clear Wanted Level"); break;
		default: Menu::Break("~r~if you see this, you broke the menu"); break;
		}
		Menu::Toggle("Enable Remote Gun", Features::remoteGunOn);
		if (Menu::Option("CEO Kick")) {
			Features::remoteGunId = 1;
			Features::remoteGunSomething = false;
			Features::remoteGunKek = false;
			__int64 args[9] = { -1190833098, 0, 6, 0, 0, 0, 0, 0, 0 };
			for (int i = 0; i < ARRAYSIZE(Features::remoteGunEvent); i++) {
				Features::remoteGunEvent[i] = args[i];
			}
		}
		if (Menu::Option("Non Host Kick")) {
			Features::remoteGunId = 2;
			Features::remoteGunSomething = false;
			Features::remoteGunKek = false;
			__int64 args[9] = { 769347061, 0, 0, 0, 0, 0, 0, 0, 0 };
			for (int i = 0; i < ARRAYSIZE(Features::remoteGunEvent); i++) {
				Features::remoteGunEvent[i] = args[i];
			}
		}
		if (Menu::Option("Teleport to Apartment")) {
			Features::remoteGunId = 6;
			Features::remoteGunSomething = false;
			Features::remoteGunKek = false;
			__int64 args[9] = { 1000837481, 0, -1, 1, 1, 0, 0, 0, 0 };
			for (int i = 0; i < ARRAYSIZE(Features::remoteGunEvent); i++) {
				Features::remoteGunEvent[i] = args[i];
			}
		}
		if (Menu::Option("Invite")) {
			Features::remoteGunId = 10;
			__int64 args[9] = { 4119492672, 1, 0, 0, 0, 0, 0, 0, 0 };
			Features::remoteGunSomething = false;
			Features::remoteGunKek = false;
			for (int i = 0; i < ARRAYSIZE(Features::remoteGunEvent); i++) {
				Features::remoteGunEvent[i] = args[i];
			}
		}
		if (Menu::Option("Show Error")) {
			Features::remoteGunId = 12;
			Features::remoteGunSomething = true;
			Features::remoteGunKek = false;
			__int64 args[9] = { -1920290846, 10000, 0, 0, -1, -1, -1, 0, 0 };
			for (int i = 0; i < ARRAYSIZE(Features::remoteGunEvent); i++) {
				Features::remoteGunEvent[i] = args[i];
			}
		}
		if (Menu::Option("Clear Wanted Level")) {
			Features::remoteGunId = 19;
			Features::remoteGunSomething = false;
			Features::remoteGunKek = true;
			__int64 args[9] = { 1475266103, 0, 0, 0, 0, 0, 0, 0, 0 };
			for (int i = 0; i < ARRAYSIZE(Features::remoteGunEvent); i++) {
				Features::remoteGunEvent[i] = args[i];
			}
		}
	}
	break;

#pragma endregion

#pragma region spawner

	case spawner:
	{
		//Features::stillDontKnowAName = true;
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Spawner");
		Menu::MenuOption("Spawner Settings", spawnsettings);
		Menu::MenuOption("Spawn Manager", spawnmanager);
		Menu::VipMenuOption("DLCs", dlc_main);
		Menu::MenuOption("Super", Supers);
		Menu::MenuOption("Sports", Sports);
		Menu::MenuOption("Sport Classic", SportClassic);
		Menu::MenuOption("Offroad", Offroad);
		Menu::MenuOption("Sedans", Sedans);
		Menu::MenuOption("Coupes", Coupes);
		Menu::MenuOption("Muscle", Muscle);
		Menu::MenuOption("Boats", Boats);
		Menu::MenuOption("Commercial", Commercial);
		Menu::MenuOption("Compacts", Compacts);
		Menu::MenuOption("Cycles", Cycles);
		Menu::MenuOption("Emergency", Emergency);
		Menu::MenuOption("Helicopters", Helicopters);
		Menu::MenuOption("Industrial", Industrial);
		Menu::MenuOption("Military", Military);
		Menu::MenuOption("Motorcycles", Motorcycles);
		Menu::MenuOption("Planes", Planes);
		Menu::MenuOption("Service", Service);
		Menu::MenuOption("SUV", SUV);
		Menu::MenuOption("Trailer", Trailer);
		Menu::MenuOption("Trains", Trains);
		Menu::MenuOption("Utility", Utility);
		Menu::MenuOption("Vans", Vans);
		Menu::MenuOption("Trucks", trucks);
		if (Menu::Option("Input Vehicle"))
		{
			//Features::fuck_me_sideways(1);

			Hash model = GAMEPLAY::GET_HASH_KEY(CharKeyboard());
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
				RequestControlOfEnt(veh);
				VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
				VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
				DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
				auto networkId = NETWORK::VEH_TO_NET(veh);
				ENTITY::_SET_ENTITY_SOMETHING(veh, true);

				Features::spawned[Features::spawnIndex] = veh;
				Features::spawnedHash[Features::spawnIndex] = model;
				Features::spawnIndex++;

				if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(veh))
					NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);
				if (Features::spawnincar)
				{
					PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
				}
				if (Features::spawnmaxed)
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
				if (Features::cargodmodebool) {
					Features::cargodmode3(veh);
				}
				WAIT(150);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
			}

		}
		break;

	case arenawar0:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Arena War");
		for (auto car : arenawar) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case afterhours0:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Afterhours");
		for (auto car : afterhrs) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Doomsday:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Doomsday");
		for (auto car : Doomsday1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case ImportEx1:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Import Export");
		for (auto car : IMPORTEXPORT1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case CunningStunts1:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Cunning Stunts");
		for (auto car : CUNNINGSTUNTS1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case GunRunning1:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Gunrunning");
		for (auto car : GUNRUNNING1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case SmuglerRun1:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Smugglers Run");
		for (auto car : SMUGLERSRUN1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Service:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Service");
		for (auto car : Service1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case san:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("San Andreas Super Sport");
		for (auto car : SOUTHERNSAN) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Supers:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Super");
		for (auto car : Super1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Sports:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Sport");
		for (auto car : Sports1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case SportClassic:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Sport Classic");
		for (auto car : SportsClassics1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Offroad:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Offroad");
		for (auto car : OffRoad1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Sedans:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Sedan");
		for (auto car : Sedans1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Coupes:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Coupe");
		for (auto car : Coupes1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Muscle:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Muscle");
		for (auto car : Muscle1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Boats:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Boat");
		for (auto car : Boats1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Commercial:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Commercial");
		for (auto car : Commercial1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Compacts:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Compact");
		for (auto car : Compacts1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Cycles:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Cycle");
		for (auto car : Cycles1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Emergency:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Emergency");
		for (auto car : Emergency1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Helicopters:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Helicopter");
		for (auto car : Helicopters1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Industrial:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Industrial");
		for (auto car : Industrial1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Military:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Military");
		for (auto car : Military1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Motorcycles:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Motorcycle");
		for (auto car : Motorcycles1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Planes:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Plane");
		for (auto car : Planes1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;

	case SUV:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("SUV");
		for (auto car : SUVs1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Trailer:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Trailer");
		for (auto car : Trailer1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Trains:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Train");
		for (auto car : Trains1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Utility:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Utility");
		for (auto car : Utility1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Vans:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Van");
		for (auto car : Vans1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case trucks:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Truck");
		for (auto car : trucks1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case Ulti:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Modded");
		if (Menu::Option("Wheelchair")) {
			int Handle = PLAYER::PLAYER_PED_ID();
			Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle, 0.0, 5.0, 0.0);
			Vehicle zentorno = Features::SpawnVehicle("SURANO", Ocoords, Features::spawnincar, 0.0f);
			ENTITY::SET_ENTITY_VISIBLE(zentorno, false);
			//ENTITY::SET_ENTITY_ALPHA(zentorno, 0.0f, 1);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(zentorno, 1);
			Object model = Features::SpawnObject("prop_wheelchair_01", Ocoords);
			if (freezespawned) {
				ENTITY::FREEZE_ENTITY_POSITION(model, true);
			}
			Features::AttachThingToThing(model, zentorno, -0.5f, -0.7f, -0.4f, 0.0f, 0.0f, 180.0f);
			if (Features::spawnincar)
			{
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), zentorno, -1);
			}
			if (Features::cargodmodebool) {
				Features::cargodmode3(zentorno);
			}
		}
		if (Menu::Option("Cup Car")) {
			int Handle = PLAYER::PLAYER_PED_ID();
			Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle, 0.0, 5.0, 0.0);
			Vehicle zentorno = Features::SpawnVehicle("SURANO", Ocoords, Features::spawnincar, 0.0f);
			ENTITY::SET_ENTITY_VISIBLE(zentorno, false);
			//ENTITY::SET_ENTITY_ALPHA(zentorno, 0.0f, 1);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(zentorno, 1);
			Object model = Features::SpawnObject("PROP_CUP_SAUCER_01", Ocoords);
			if (freezespawned) {
				ENTITY::FREEZE_ENTITY_POSITION(model, true);
			}
			Features::AttachThingToThing(model, zentorno, -0.4f, -0.5f, -0.4f, 0.0f, 0.0f, 180.0f);
			if (Features::spawnincar)
			{
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), zentorno, -1);
			}
			if (Features::cargodmodebool) {
				Features::cargodmode3(zentorno);
			}
		}
		if (Menu::Option("Flyable UFO")) {
			int Handle = PLAYER::PLAYER_PED_ID();
			Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle, 0.0, 5.0, 0.0);
			Vehicle zentorno = Features::SpawnVehicle("HYDRA", Ocoords, Features::spawnincar, 0.0f);
			ENTITY::SET_ENTITY_VISIBLE(zentorno, true);
			//ENTITY::SET_ENTITY_ALPHA(zentorno, 0.0f, 1);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(zentorno, 1);
			Object model = Features::SpawnObject("p_spinning_anus_s", Ocoords);
			if (freezespawned) {
				ENTITY::FREEZE_ENTITY_POSITION(model, true);
			}
			Features::AttachThingToThing(model, zentorno, -0.4f, -0.5f, -0.4f, 0.0f, 0.0f, 180.0f);
			if (Features::spawnincar)
			{
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), zentorno, -1);
			}
			if (Features::cargodmodebool) {
				Features::cargodmode3(zentorno);
			}
		}
		if (Menu::Option("Poop Car")) {
			int Handle = PLAYER::PLAYER_PED_ID();
			Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle, 0.0, 5.0, 0.0);
			Vehicle zentorno = Features::SpawnVehicle("SURANO", Ocoords, Features::spawnincar, 0.0f);
			ENTITY::SET_ENTITY_VISIBLE(zentorno, false);
			//ENTITY::SET_ENTITY_ALPHA(zentorno, 0.0f, 1);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(zentorno, 1);
			Object model = Features::SpawnObject("prop_ld_toilet_01", Ocoords);
			if (freezespawned) {
				ENTITY::FREEZE_ENTITY_POSITION(model, true);
			}
			Features::AttachThingToThing(model, zentorno, -0.5f, -0.8f, -0.4f, 0.0f, 0.0f, 180.0f);
			if (Features::spawnincar)
			{
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), zentorno, -1);
			}
			if (Features::cargodmodebool) {
				Features::cargodmode3(zentorno);
			}
		}
		if (Menu::Option("Bumper Cart")) {
			int Handle = PLAYER::PLAYER_PED_ID();
			Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle, 0.0, 5.0, 0.0);
			Vehicle zentorno = Features::SpawnVehicle("SURANO", Ocoords, Features::spawnincar, 0.0f);
			ENTITY::SET_ENTITY_VISIBLE(zentorno, false);
			//ENTITY::SET_ENTITY_ALPHA(zentorno, 0.0f, 1);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(zentorno, 1);
			Object model = Features::SpawnObject("PROP_BUMPER_CAR_01", Ocoords);
			if (freezespawned) {
				ENTITY::FREEZE_ENTITY_POSITION(model, true);
			}
			Features::AttachThingToThing(model, zentorno, -0.5f, -0.8f, -0.4f, 0.0f, 0.0f, 180.0f);
			if (Features::spawnincar)
			{
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), zentorno, -1);
			}
			if (Features::cargodmodebool) {
				Features::cargodmode3(zentorno);
			}
		}
		if (Menu::Option("Sofa Car")) {
			int Handle = PLAYER::PLAYER_PED_ID();
			Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle, 0.0, 5.0, 0.0);
			Vehicle zentorno = Features::SpawnVehicle("SURANO", Ocoords, Features::spawnincar, 0.0f);
			ENTITY::SET_ENTITY_VISIBLE(zentorno, false);
			//ENTITY::SET_ENTITY_ALPHA(zentorno, 0.0f, 1);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(zentorno, 1);
			Object model = Features::SpawnObject("PROP_YACHT_SEAT_01", Ocoords);
			if (freezespawned) {
				ENTITY::FREEZE_ENTITY_POSITION(model, true);
			}
			Features::AttachThingToThing(model, zentorno, -0.5f, -0.8f, -0.4f, 0.0f, 0.0f, 180.0f);
			if (Features::spawnincar)
			{
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), zentorno, -1);
			}
			if (Features::cargodmodebool) {
				Features::cargodmode3(zentorno);
			}
		}
		if (Menu::Option("Trolley")) {

			uint Handle = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = 0, a.z = 0;
			Vector3 b; b.x = 0, b.y = 2, b.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("carbonrs");
			int hash2 = GAMEPLAY::GET_HASH_KEY("prop_rub_trolley01a");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
			{
				int Object = OBJECT::CREATE_OBJECT(hash2, null.x, null.y, null.z, 1, 1, 1);
				if (ENTITY::DOES_ENTITY_EXIST(Object))
				{
					int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
					{
						if (Features::spawnincar)
						{
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						}
						if (Features::cargodmodebool) {
							Features::cargodmode3(Vehicle);
						}
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, false);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::SET_ENTITY_VISIBLE(Handle, true);

					}

				}

			}

		}

		if (Menu::Option("6x6 War RC")) {
			int Handle = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = 0, a.z = 0.03f;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("dune2");
			int hash2 = GAMEPLAY::GET_HASH_KEY("t20");
			int hash3 = GAMEPLAY::GET_HASH_KEY("dune2");
			int hash4 = GAMEPLAY::GET_HASH_KEY("dune2");
			int hash5 = GAMEPLAY::GET_HASH_KEY("monster");
			int hash6 = GAMEPLAY::GET_HASH_KEY("monster");


			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			STREAMING::REQUEST_MODEL(hash3);
			STREAMING::REQUEST_MODEL(hash4);
			STREAMING::REQUEST_MODEL(hash5);
			STREAMING::REQUEST_MODEL(hash6);


			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5) && STREAMING::HAS_MODEL_LOADED(hash6))
			{
				int Object1 = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object2 = VEHICLE::CREATE_VEHICLE(hash3, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object3 = VEHICLE::CREATE_VEHICLE(hash4, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object4 = VEHICLE::CREATE_VEHICLE(hash5, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object5 = VEHICLE::CREATE_VEHICLE(hash6, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);



				if (ENTITY::DOES_ENTITY_EXIST(Object1) && ENTITY::DOES_ENTITY_EXIST(Object2) && ENTITY::DOES_ENTITY_EXIST(Object3) && ENTITY::DOES_ENTITY_EXIST(Object4) && ENTITY::DOES_ENTITY_EXIST(Object5))
				{
					int Vehicle = VEHICLE::CREATE_VEHICLE(hash2, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
					{
						if (Features::spawnincar)
						{
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						}
						if (Features::cargodmodebool) {
							Features::cargodmode3(Vehicle);
						}
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
					}

				}

			}
		}
		if (Menu::Option("Speeder Prototype")) {
			int Handle = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = 0, a.z = 0.03f;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("seashark");
			int hash1 = GAMEPLAY::GET_HASH_KEY("seashark");
			int hash2 = GAMEPLAY::GET_HASH_KEY("turismor");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash1);
			STREAMING::REQUEST_MODEL(hash2);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash1) && STREAMING::HAS_MODEL_LOADED(hash2))
			{
				int Object = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object1 = VEHICLE::CREATE_VEHICLE(hash1, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Object))
				{
					int Vehicle = VEHICLE::CREATE_VEHICLE(hash2, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
					{
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 255, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 255, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 255, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 255, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object1, 255, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object1, 255, 0, 0);
						if (Features::spawnincar)
						{
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						}
						if (Features::cargodmodebool) {
							Features::cargodmode3(Vehicle);
						}
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y + 1.37f, a.z + 0.59f, b.x - 14.33f, b.y + 541.20f, b.z - 1.42f, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a.x, a.y - 0.79f, a.z + 0.83f, b.x + 9.72f, b.y + 539.03f, b.z - 0.16f, 0, 1, 0, 0, 2, 1);
					}
				}
			}
		}
		if (Menu::Option("Snow Scooter")) {
			int Handle = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = 0, a.z = 0.03f;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("seashark");
			int hash2 = GAMEPLAY::GET_HASH_KEY("sanchez");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
			{
				int Object = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Object))
				{
					int Vehicle = VEHICLE::CREATE_VEHICLE(hash2, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
					{
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 255, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 255, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 255, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 255, 0, 0);
						if (Features::spawnincar)
						{
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						}
						if (Features::cargodmodebool) {
							Features::cargodmode3(Vehicle);
						}
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x - 0.02f, a.y - 0.08f, a.z - 0.36f, b.x - 0.21f, b.y + 1.83f, b.z - 0.21f, 0, 1, 0, 0, 2, 1);

					}
				}
			}
		}
		if (Menu::Option("Military Flightsquad")) {
			int Handle = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = 0, a.z = 0.03f;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("hydra");
			int hash1 = GAMEPLAY::GET_HASH_KEY("hydra");
			int hash2 = GAMEPLAY::GET_HASH_KEY("hydra");
			int hash3 = GAMEPLAY::GET_HASH_KEY("hydra");
			int hash4 = GAMEPLAY::GET_HASH_KEY("hydra");
			int hash5 = GAMEPLAY::GET_HASH_KEY("hydra");
			int hash6 = GAMEPLAY::GET_HASH_KEY("hydra");
			int hash7 = GAMEPLAY::GET_HASH_KEY("hydra");
			int hash8 = GAMEPLAY::GET_HASH_KEY("hydra");

			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			STREAMING::REQUEST_MODEL(hash1);
			STREAMING::REQUEST_MODEL(hash3);
			STREAMING::REQUEST_MODEL(hash4);
			STREAMING::REQUEST_MODEL(hash5);
			STREAMING::REQUEST_MODEL(hash6);
			STREAMING::REQUEST_MODEL(hash7);
			STREAMING::REQUEST_MODEL(hash8);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash1) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5) && STREAMING::HAS_MODEL_LOADED(hash6) && STREAMING::HAS_MODEL_LOADED(hash7) && STREAMING::HAS_MODEL_LOADED(hash8))
			{
				int Object = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object1 = VEHICLE::CREATE_VEHICLE(hash1, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object2 = VEHICLE::CREATE_VEHICLE(hash3, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object3 = VEHICLE::CREATE_VEHICLE(hash4, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object4 = VEHICLE::CREATE_VEHICLE(hash5, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object5 = VEHICLE::CREATE_VEHICLE(hash6, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object6 = VEHICLE::CREATE_VEHICLE(hash7, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object7 = VEHICLE::CREATE_VEHICLE(hash8, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Object))
				{
					int Vehicle = VEHICLE::CREATE_VEHICLE(hash2, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
					{

						if (Features::spawnincar)
						{
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						}

						if (Features::cargodmodebool) {
							Features::cargodmode3(Vehicle);
						}
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y + 15.541162f, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a.x, a.y + 30.541162f, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object2, Vehicle, 0, a.x - 15.0f, a.y + 15.541162f, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object3, Vehicle, 0, a.x + 15.0f, a.y + 15.541162f, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object4, Vehicle, 0, a.x + 15.0f, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object5, Vehicle, 0, a.x + 30.0f, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object6, Vehicle, 0, a.x - 15.0f, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object7, Vehicle, 0, a.x - 30.0f, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);

					}
				}
			}
		}
		if (Menu::Option("Bike Robot")) {
			int Handle = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = 0, a.z = 0.03f;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("bati");
			int hash1 = GAMEPLAY::GET_HASH_KEY("bati");
			int hash2 = GAMEPLAY::GET_HASH_KEY("bati");
			int hash3 = GAMEPLAY::GET_HASH_KEY("bati");
			int hash4 = GAMEPLAY::GET_HASH_KEY("bati");
			int hash5 = GAMEPLAY::GET_HASH_KEY("bati");
			int hash6 = GAMEPLAY::GET_HASH_KEY("bati");
			int hash7 = GAMEPLAY::GET_HASH_KEY("bati");
			int hash8 = GAMEPLAY::GET_HASH_KEY("bati");
			int hash9 = GAMEPLAY::GET_HASH_KEY("bati");
			int hash10 = GAMEPLAY::GET_HASH_KEY("bati");
			int hash11 = GAMEPLAY::GET_HASH_KEY("bati");
			int hash12 = GAMEPLAY::GET_HASH_KEY("bati");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash1);
			STREAMING::REQUEST_MODEL(hash2);
			STREAMING::REQUEST_MODEL(hash2);
			STREAMING::REQUEST_MODEL(hash3);
			STREAMING::REQUEST_MODEL(hash4);
			STREAMING::REQUEST_MODEL(hash5);
			STREAMING::REQUEST_MODEL(hash6);
			STREAMING::REQUEST_MODEL(hash7);
			STREAMING::REQUEST_MODEL(hash8);
			STREAMING::REQUEST_MODEL(hash9);
			STREAMING::REQUEST_MODEL(hash10);
			STREAMING::REQUEST_MODEL(hash11);
			STREAMING::REQUEST_MODEL(hash12);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash1) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5) && STREAMING::HAS_MODEL_LOADED(hash6) && STREAMING::HAS_MODEL_LOADED(hash7) && STREAMING::HAS_MODEL_LOADED(hash8) && STREAMING::HAS_MODEL_LOADED(hash9) && STREAMING::HAS_MODEL_LOADED(hash10) && STREAMING::HAS_MODEL_LOADED(hash11))
			{
				int Object = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object1 = VEHICLE::CREATE_VEHICLE(hash1, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object2 = VEHICLE::CREATE_VEHICLE(hash3, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object3 = VEHICLE::CREATE_VEHICLE(hash4, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object4 = VEHICLE::CREATE_VEHICLE(hash5, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object5 = VEHICLE::CREATE_VEHICLE(hash6, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object6 = VEHICLE::CREATE_VEHICLE(hash7, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object7 = VEHICLE::CREATE_VEHICLE(hash8, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object8 = VEHICLE::CREATE_VEHICLE(hash9, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object9 = VEHICLE::CREATE_VEHICLE(hash10, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object10 = VEHICLE::CREATE_VEHICLE(hash11, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Object11 = VEHICLE::CREATE_VEHICLE(hash12, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Object))
				{
					int Vehicle = VEHICLE::CREATE_VEHICLE(hash2, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
					{
						if (Features::spawnincar)
						{
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						}
						if (Features::cargodmodebool) {
							Features::cargodmode3(Vehicle);
						}
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z + 1.16f, b.x + 62.0f, b.y, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a.x + 2.5f, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object3, Vehicle, 0, a.x + 2.5f, a.y, a.z + 1.16f, b.x + 62.0f, b.y, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object4, Vehicle, 0, a.x + 0.5f, a.y + 0.5f, a.z + 2.27f, b.x + 50.0f, b.y - 70.0f, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object5, Vehicle, 0, a.x + 1.95f, a.y + 0.5f, a.z + 2.27f, b.x + 50.0f, b.y + 70.0f, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object6, Vehicle, 0, a.x + 1.24f, a.y + 0.8f, a.z + 5.0f, b.x + 90.0f, b.y, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object7, Vehicle, 0, a.x + 1.24f, a.y + 0.8f, a.z + 3.5f, b.x + 90.0f, b.y, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object8, Vehicle, 0, a.x + 1.24f, a.y + 0.8f, a.z + 6.0f, b.x - 15.0f, b.y, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object9, Vehicle, 0, a.x + 2.0f, a.y + 0.8f, a.z + 4.43f, b.x - 30.0f, b.y - 50.0f, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object10, Vehicle, 0, a.x + 0.6f, a.y + 0.8f, a.z + 4.43f, b.x - 30.0f, b.y + 50.0f, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object2, Vehicle, 0, a.x, a.y + 2.1f, a.z + 3.7f, b.x - 10.0f, b.y + 12.8f, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object11, Vehicle, 0, a.x + 2.8f, a.y + 1.9f, a.z + 3.7f, b.x - 10.0f, b.y - 13.6f, b.z, 0, 1, 0, 0, 2, 1);
					}
				}
			}
		}
		if (Menu::Option("Bumper Buggy")) {
			uint Handle = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = -0.34, a.y = 0.32, a.z = -0.25;
			Vector3 b; b.x = 0, b.y = 0, b.z = 180;
			Vector3 Tire; Tire.x = 0.0, Tire.y = 0.0; Tire.z = 0.0;//Right Front(inner tire)
			Vector3 TireA; TireA.x = 0.40, TireA.y = 1.0, TireA.z = -0.51;//X Coord - Y Coord - Z Coord
			Vector3 TireB; TireB.x = 0.0, TireB.y = 0.0, TireB.z = 88.0;//Pitch - Roll - Yaw
			Vector3 Tire01; Tire01.x = 0.0, Tire01.y = 0.0; Tire01.z = 0;//Right Front(outter tire)
			Vector3 TireC; TireC.x = 0.59, TireC.y = 1.0, TireC.z = -0.51;//X Coord - Y Coord - Z Coord
			Vector3 TireD; TireD.x = 0.0, TireD.y = 0.0, TireD.z = -90.0;//Pitch - Roll - Yaw
			Vector3 Tire02; Tire02.x = 0.0, Tire02.y = 0.0; Tire02.z = 0.0;//Left Front(inner tire)
			Vector3 TireE; TireE.x = -1.09, TireE.y = 1.0, TireE.z = -0.50;//X Coord - Y Coord - Z Coord
			Vector3 TireF; TireF.x = 0.0, TireF.y = 0.0, TireF.z = -88.0;//Pitch - Roll - Yaw
			Vector3 Tire03; Tire03.x = 0.0, Tire03.y = 0.0; Tire03.z = 0.0;//Left Front(outter tire)
			Vector3 TireG; TireG.x = -1.264, TireG.y = 1.0, TireG.z = -0.50;//X Coord - Y Coord - Z Coord
			Vector3 TireH; TireH.x = 0.0, TireH.y = 0.0, TireH.z = 92.0;//Pitch - Roll - Yaw
			Vector3 Engine1; Engine1.x = 0.0, Engine1.y = 0.0; Engine1.z = 0.0;//Engine
			Vector3 EngineA; EngineA.x = -0.39, EngineA.y = -1.60, EngineA.z = -0.70;//X Coord - Y Coord - Z Coord
			Vector3 EngineB; EngineB.x = 0.0, EngineB.y = 0.0, EngineB.z = 0.0;//Pitch - Roll - Yaw
			Vector3 Tire04; Tire04.x = 0.0, Tire04.y = 0.0; Tire04.z = 0.0;//Right Rear(inner tire)
			Vector3 TireI; TireI.x = 0.22, TireI.y = -1.40, TireI.z = -0.50;//X Coord - Y Coord - Z Coord
			Vector3 TireJ; TireJ.x = 0.0, TireJ.y = 0.0, TireJ.z = -88.0;//Pitch - Roll - Yaw
			Vector3 Tire05; Tire05.x = 0.0, Tire05.y = 0.0; Tire05.z = 0.0;//Right Rear(middle tire)
			Vector3 TireK; TireK.x = 0.42, TireK.y = -1.40, TireK.z = -0.50;//X Coord - Y Coord - Z Coord
			Vector3 TireL; TireL.x = 0.0, TireL.y = 0.0, TireL.z = 90.0;//Pitch - Roll - Yaw
			Vector3 Tire06; Tire06.x = 0.0, Tire06.y = 0.0; Tire06.z = 0.0;//Right Rear(outter tire)
			Vector3 TireM; TireM.x = 0.593, TireM.y = -1.40, TireM.z = -0.50;//X Coord - Y Coord - Z Coord
			Vector3 TireN; TireN.x = 0.0, TireN.y = 0.0, TireN.z = -89.0;//Pitch - Roll - Yaw
			Vector3 Tire07; Tire07.x = 0.0, Tire07.y = 0.0; Tire07.z = 0.0;//Left Rear(inner tire)
			Vector3 TireO; TireO.x = -0.81, TireO.y = -1.40, TireO.z = -0.50;//X Coord - Y Coord - Z Coord
			Vector3 TireP; TireP.x = 0.0, TireP.y = 0.0, TireP.z = 88.0;//Pitch - Roll - Yaw
			Vector3 Tire08; Tire08.x = 0.0, Tire08.y = 0.0; Tire08.z = 0.0;//Left Rear(middle tire)
			Vector3 TireQ; TireQ.x = -1.01, TireQ.y = -1.40, TireQ.z = -0.50;//X Coord - Y Coord - Z Coord
			Vector3 TireR; TireR.x = 0.0, TireR.y = 0.0, TireR.z = -91.0;//Pitch - Roll - Yaw
			Vector3 Tire09; Tire09.x = 0.0, Tire09.y = 0.0; Tire09.z = 0.0;//Left Rear(outter tire)
			Vector3 TireSs; TireSs.x = -1.184, TireSs.y = -1.40, TireSs.z = -0.50;//X Coord - Y Coord - Z Coord
			Vector3 TireT; TireT.x = 0.0, TireT.y = 0.0, TireT.z = 88.0;//Pitch - Roll - Yaw
			Vector3 Hood1; Hood1.x = 0, Hood1.y = 0; Hood1.z = 0;//Hood
			Vector3 HoodA; HoodA.x = -0.34, HoodA.y = 1.2, HoodA.z = -0.40;//X Coord - Y Coord - Z Coord
			Vector3 HoodB; HoodB.x = -24.0, HoodB.y = 0.0, HoodB.z = 0.0;//Pitch - Roll - Yaw
			Vector3 Battery1; Battery1.x = 0.0, Battery1.y = 0.0; Battery1.z = 0.0;//Battery
			Vector3 BatteryA; BatteryA.x = -0.34, BatteryA.y = 1.06, BatteryA.z = -0.06;//X Coord - Y Coord - Z Coord
			Vector3 BatteryB; BatteryB.x = -24.0, BatteryB.y = 0.0, BatteryB.z = 0.0;//Pitch - Roll - Yaw
			int hash = GAMEPLAY::GET_HASH_KEY("blista");
			int hash2 = GAMEPLAY::GET_HASH_KEY("prop_bumper_car_01");
			int Tires = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");
			int Engine = GAMEPLAY::GET_HASH_KEY("prop_car_engine_01");
			int Hood = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");
			int Battery = GAMEPLAY::GET_HASH_KEY("prop_power_cell");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			STREAMING::REQUEST_MODEL(Tires);
			STREAMING::REQUEST_MODEL(Engine);
			STREAMING::REQUEST_MODEL(Hood);
			STREAMING::REQUEST_MODEL(Battery);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(Tires) && STREAMING::HAS_MODEL_LOADED(Engine) && STREAMING::HAS_MODEL_LOADED(Hood) && STREAMING::HAS_MODEL_LOADED(Battery))
			{
				int Object = OBJECT::CREATE_OBJECT(hash2, null.x, null.y, null.z, 1, 0, 1);
				int Tire1 = OBJECT::CREATE_OBJECT(Tires, Tire.x, Tire.y, Tire.z, 1, 0, 1);//Right Front(inner tire)
				int Tire2 = OBJECT::CREATE_OBJECT(Tires, Tire01.x, Tire01.y, Tire01.z, 1, 0, 1);//right Front(outter tire)
				int Tire3 = OBJECT::CREATE_OBJECT(Tires, Tire02.x, Tire02.y, Tire02.z, 1, 0, 1);//Left Front(inner tire)
				int Tire4 = OBJECT::CREATE_OBJECT(Tires, Tire03.x, Tire03.y, Tire03.z, 1, 0, 1);//Left Front(outter tire)
				int Engine01 = OBJECT::CREATE_OBJECT(Engine, Engine1.x, Engine1.y, Engine1.z, 1, 0, 1);//Engine
				int Tire5 = OBJECT::CREATE_OBJECT(Tires, Tire04.x, Tire04.y, Tire04.z, 1, 0, 1);//Right Rear(inner tire)
				int Tire6 = OBJECT::CREATE_OBJECT(Tires, Tire05.x, Tire05.y, Tire05.z, 1, 0, 1);//Right Rear(middle tire)
				int Tire7 = OBJECT::CREATE_OBJECT(Tires, Tire06.x, Tire06.y, Tire06.z, 1, 0, 1);//Right Rear(outter tire)
				int Tire8 = OBJECT::CREATE_OBJECT(Tires, Tire07.x, Tire07.y, Tire07.z, 1, 0, 1);//Left Rear(inner tire)
				int Tire9 = OBJECT::CREATE_OBJECT(Tires, Tire08.x, Tire08.y, Tire08.z, 1, 0, 1);//Left Rear(middle tire)
				int Tire10 = OBJECT::CREATE_OBJECT(Tires, Tire09.x, Tire09.y, Tire09.z, 1, 0, 1);//Left Rear(outter tire)
				int Hood01 = OBJECT::CREATE_OBJECT(Hood, Hood1.x, Hood1.y, Hood1.z, 1, 0, 1);//Hood
				int Battery01 = OBJECT::CREATE_OBJECT(Battery, Battery1.x, Battery1.y, Battery1.z, 1, 0, 1);//Battery
				if (ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Tire1) && ENTITY::DOES_ENTITY_EXIST(Tire2) && ENTITY::DOES_ENTITY_EXIST(Tire3) && ENTITY::DOES_ENTITY_EXIST(Tire4) && ENTITY::DOES_ENTITY_EXIST(Engine01) && ENTITY::DOES_ENTITY_EXIST(Tire5) && ENTITY::DOES_ENTITY_EXIST(Tire6) && ENTITY::DOES_ENTITY_EXIST(Tire7) && ENTITY::DOES_ENTITY_EXIST(Tire8) && ENTITY::DOES_ENTITY_EXIST(Tire9) && ENTITY::DOES_ENTITY_EXIST(Tire10) && ENTITY::DOES_ENTITY_EXIST(Hood01) && ENTITY::DOES_ENTITY_EXIST(Battery01))
				{
					int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
					{
						if (Features::spawnincar)
						{
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						}
						if (Features::cargodmodebool) {
							Features::cargodmode3(Vehicle);
						}
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, false);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire1, Vehicle, 0, TireA.x, TireA.y, TireA.z, TireB.x, TireB.y, TireB.z, 0, 1, 0, 0, 2, 1);//Right Front(inner tire)
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire2, Vehicle, 0, TireC.x, TireC.y, TireC.z, TireD.x, TireD.y, TireD.z, 0, 1, 0, 0, 2, 1);//right Front(outter tire)
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire3, Vehicle, 0, TireE.x, TireE.y, TireE.z, TireF.x, TireF.y, TireF.z, 0, 1, 0, 0, 2, 1);//Left Front(inner tire)
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire4, Vehicle, 0, TireG.x, TireG.y, TireG.z, TireH.x, TireH.y, TireH.z, 0, 1, 0, 0, 2, 1);//Left Front(outter tire)
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Engine01, Vehicle, 0, EngineA.x, EngineA.y, EngineA.z, EngineB.x, EngineB.y, EngineB.z, 0, 1, 0, 0, 2, 1);//Engine
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire5, Vehicle, 0, TireI.x, TireI.y, TireI.z, TireJ.x, TireJ.y, TireJ.z, 0, 1, 0, 0, 2, 1);//Right Rear(inner tire)
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire6, Vehicle, 0, TireK.x, TireK.y, TireK.z, TireL.x, TireL.y, TireL.z, 0, 1, 0, 0, 2, 1);//Right Rear(middle tire)
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire7, Vehicle, 0, TireM.x, TireM.y, TireM.z, TireN.x, TireN.y, TireN.z, 0, 1, 0, 0, 2, 1);//Right Rear(outter tire)
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire8, Vehicle, 0, TireO.x, TireO.y, TireO.z, TireP.x, TireP.y, TireP.z, 0, 1, 0, 0, 2, 1);//Left Rear(inner tire)
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire9, Vehicle, 0, TireQ.x, TireQ.y, TireQ.z, TireR.x, TireR.y, TireR.z, 0, 1, 0, 0, 2, 1);//Left Rear(middle tire)
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire10, Vehicle, 0, TireSs.x, TireSs.y, TireSs.z, TireT.x, TireT.y, TireT.z, 0, 1, 0, 0, 2, 1);//Left Rear(outter tire)
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Hood01, Vehicle, 0, HoodA.x, HoodA.y, HoodA.z, HoodB.x, HoodB.y, HoodB.z, 0, 1, 0, 0, 2, 1);//Hood
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Battery01, Vehicle, 0, BatteryA.x, BatteryA.y, BatteryA.z, BatteryB.x, BatteryB.y, BatteryB.z, 0, 1, 0, 0, 2, 1);//Battery
						ENTITY::SET_ENTITY_VISIBLE(Handle, true);

					}

				}

			}

		}
		if (Menu::Option("Modded T20")) {
			uint Handle = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			//hash2_EMP
			Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
			Vector3 a; a.x = 0.0, a.y = 1.61, a.z = -0.12;//X Coord - Y Coord - Z Coord
			Vector3 b; b.x = -12.0, b.y = 0.0, b.z = 0.0;//Pitch - Roll - Yaw
														 //hash3_MiniGun
			Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
			Vector3 a1; a1.x = -0.60, a1.y = 1.60, a1.z = 0.20;
			Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 88.0;
			//hash3_MiniGun2
			Vector3 null0; null0.x = 0.0, null0.y = 0.0; null0.z = 0.0;
			Vector3 a0; a0.x = 0.60, a0.y = 1.60, a0.z = 0.20;
			Vector3 b0; b0.x = 0.0, b0.y = 0.0, b0.z = 88.0;
			//hash4_FLWheel1
			Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
			Vector3 a2; a2.x = -0.94, a2.y = 1.32, a2.z = -0.25;
			Vector3 b2; b2.x = 9.0, b2.y = -28.0, b2.z = 87.0;
			//hash4_RLWheel1
			Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
			Vector3 a3; a3.x = -0.95, a3.y = -1.34, a3.z = -0.25f;
			Vector3 b3; b3.x = 9.0, b3.y = 38.0, b3.z = 87.0;
			//hash4_RFWheel1
			Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
			Vector3 a4; a4.x = 0.95, a4.y = 1.33, a4.z = -0.23;
			Vector3 b4; b4.x = 11.0, b4.y = 26.0, b4.z = -89.0;
			//hash4_RRWheel1
			Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
			Vector3 a5; a5.x = 0.96, a5.y = -1.31, a5.z = -0.23;
			Vector3 b5; b5.x = 10.0, b5.y = 20.0, b5.z = -92.0;

			int hash_T20 = GAMEPLAY::GET_HASH_KEY("t20");
			int hash2_EMP = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");
			int hash3_MiniGun = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");
			int hash4_Wheel = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");

			STREAMING::REQUEST_MODEL(hash_T20);
			STREAMING::REQUEST_MODEL(hash2_EMP);
			STREAMING::REQUEST_MODEL(hash3_MiniGun);
			STREAMING::REQUEST_MODEL(hash4_Wheel);

			if (STREAMING::HAS_MODEL_LOADED(hash_T20) && STREAMING::HAS_MODEL_LOADED(hash2_EMP) && STREAMING::HAS_MODEL_LOADED(hash3_MiniGun) && STREAMING::HAS_MODEL_LOADED(hash4_Wheel))
			{
				int EMP = OBJECT::CREATE_OBJECT(hash2_EMP, null.x, null.y, null.z, 1, 0, 1);
				int MiniGun = OBJECT::CREATE_OBJECT(hash3_MiniGun, null1.x, null1.y, null1.z, 1, 0, 1);
				int MiniGun2 = OBJECT::CREATE_OBJECT(hash3_MiniGun, null0.x, null0.y, null0.z, 1, 0, 1);
				int FLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null2.x, null2.y, null2.z, 1, 0, 1);
				int RLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null3.x, null3.y, null3.z, 1, 0, 1);
				int RFWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null4.x, null4.y, null4.z, 1, 0, 1);
				int RRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null5.x, null5.y, null5.z, 1, 0, 1);

				if (ENTITY::DOES_ENTITY_EXIST(EMP) && ENTITY::DOES_ENTITY_EXIST(MiniGun) && ENTITY::DOES_ENTITY_EXIST(MiniGun2) && ENTITY::DOES_ENTITY_EXIST(FLWheel1) && ENTITY::DOES_ENTITY_EXIST(RLWheel1) && ENTITY::DOES_ENTITY_EXIST(RFWheel1) && ENTITY::DOES_ENTITY_EXIST(RRWheel1))
				{
					int Vehicle = VEHICLE::CREATE_VEHICLE(hash_T20, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

					if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
					{
						if (Features::spawnincar)
						{
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						}
						if (Features::cargodmodebool) {
							Features::cargodmode3(Vehicle);
						}
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash_T20);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
						ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true);

						ENTITY::ATTACH_ENTITY_TO_ENTITY(EMP, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun2, Vehicle, 0, a0.x, a0.y, a0.z, b0.x, b0.y, b0.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(FLWheel1, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel1, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(RFWheel1, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel1, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);

					}

				}

			}

		}
		if (Menu::Option("Roller Coaster Car")) {
			uint Handle = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			//hash2_RollerCar
			Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
			Vector3 a; a.x = 0.0, a.y = 0.0, a.z = -0.5;//X Coord - Y Coord - Z Coord
			Vector3 b; b.x = 0.0, b.y = 0.0, b.z = 180.0;//Pitch - Roll - Yaw
														 //hash3_Seats
			Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
			Vector3 a1; a1.x = 0.0, a1.y = 0.0, a1.z = 0.0;
			Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 0.0;
			//hash3_FLWheel1
			Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
			Vector3 a2; a2.x = -0.97, a2.y = 1.0, a2.z = -0.25;
			Vector3 b2; b2.x = 0.0, b2.y = 0.0, b2.z = -89.0;
			//hash3_RLWheel1
			Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
			Vector3 a3; a3.x = -1.00, a3.y = -1.10, a3.z = -0.24;
			Vector3 b3; b3.x = 0.0, b3.y = 0.0, b3.z = -89.0;
			//hash3_RFWheel1
			Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
			Vector3 a4; a4.x = 0.97, a4.y = 1.00, a4.z = -0.24;
			Vector3 b4; b4.x = 0.0, b4.y = 0.0, b4.z = 89.0;
			//hash3_RRWheel1
			Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
			Vector3 a5; a5.x = 1.00, a5.y = -1.10, a5.z = -0.24;
			Vector3 b5; b5.x = 0.0, b5.y = 0.0, b5.z = 89.0;
			int hash_T20 = GAMEPLAY::GET_HASH_KEY("t20");
			int hash2_RollerCar = GAMEPLAY::GET_HASH_KEY("ind_prop_dlc_roller_car");
			int hash3_Seats = GAMEPLAY::GET_HASH_KEY("prop_hd_seats_01");
			int hash4_Wheel = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");
			STREAMING::REQUEST_MODEL(hash_T20);
			STREAMING::REQUEST_MODEL(hash2_RollerCar);
			STREAMING::REQUEST_MODEL(hash3_Seats);
			STREAMING::REQUEST_MODEL(hash4_Wheel);
			if (STREAMING::HAS_MODEL_LOADED(hash_T20) && STREAMING::HAS_MODEL_LOADED(hash2_RollerCar) && STREAMING::HAS_MODEL_LOADED(hash3_Seats) && STREAMING::HAS_MODEL_LOADED(hash4_Wheel))
			{
				int RollerCar = OBJECT::CREATE_OBJECT(hash2_RollerCar, null.x, null.y, null.z, 1, 0, 1);
				int Seats = OBJECT::CREATE_OBJECT(hash3_Seats, null1.x, null1.y, null1.z, 1, 0, 1);
				int FLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null2.x, null2.y, null2.z, 1, 0, 1);
				int RLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null3.x, null3.y, null3.z, 1, 0, 1);
				int RFWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null4.x, null4.y, null4.z, 1, 0, 1);
				int RRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null5.x, null5.y, null5.z, 1, 0, 1);
				if (ENTITY::DOES_ENTITY_EXIST(RollerCar) && ENTITY::DOES_ENTITY_EXIST(Seats) && ENTITY::DOES_ENTITY_EXIST(FLWheel1) && ENTITY::DOES_ENTITY_EXIST(RLWheel1) && ENTITY::DOES_ENTITY_EXIST(RFWheel1) && ENTITY::DOES_ENTITY_EXIST(RRWheel1))
				{
					int Vehicle = VEHICLE::CREATE_VEHICLE(hash_T20, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
					{
						if (Features::spawnincar)
						{
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						}
						if (Features::cargodmodebool) {
							Features::cargodmode3(Vehicle);
						}
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash_T20);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, false);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(RollerCar, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Seats, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(FLWheel1, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel1, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(RFWheel1, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel1, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
						ENTITY::SET_ENTITY_VISIBLE(Handle, true);

					}

				}

			}

		}
		if (Menu::Option("Boat And Trailer")) {
			uint Me = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = -0.61, a.z = 0.28;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("boattrailer");
			int hash2 = GAMEPLAY::GET_HASH_KEY("suntrap");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
				{
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
					ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);

				}

			}

		}

		if (Menu::Option("FlatBed And T20")) {
			uint Me = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = -2.0, a.z = 1.1;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			Vector3 null1; null1.x = 0, null1.y = 0; null1.z = 0;
			Vector3 a1; a1.x = -1.06, a1.y = -0.1, a1.z = 0.46;
			Vector3 b1; b1.x = 91.0, b1.y = 0, b1.z = 0;
			Vector3 null2; null2.x = 0, null2.y = 0; null2.z = 0;
			Vector3 a2; a2.x = -0.9, a2.y = 0.61, a2.z = 0.62;
			Vector3 b2; b2.x = 0.0, b2.y = 100.0, b2.z = 0;
			Vector3 null3; null3.x = 0, null3.y = 0; null3.z = 0;
			Vector3 a3; a3.x = 0.9, a3.y = 0.8, a3.z = 0.41;
			Vector3 b3; b3.x = -25.0, b3.y = 0, b3.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("flatbed");
			int hash2 = GAMEPLAY::GET_HASH_KEY("t20");
			int hash3 = GAMEPLAY::GET_HASH_KEY("prop_tool_broom");
			int hash4 = GAMEPLAY::GET_HASH_KEY("prop_roadcone01a");
			int hash5 = GAMEPLAY::GET_HASH_KEY("prop_tool_box_02");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			STREAMING::REQUEST_MODEL(hash3);
			STREAMING::REQUEST_MODEL(hash4);
			STREAMING::REQUEST_MODEL(hash5);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Broom = OBJECT::CREATE_OBJECT(hash3, null1.x, null1.y, null1.z, 1, 0, 1);
				int Cone = OBJECT::CREATE_OBJECT(hash4, null2.x, null2.y, null2.z, 1, 0, 1);
				int Tool = OBJECT::CREATE_OBJECT(hash5, null3.x, null3.y, null3.z, 1, 0, 1);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Broom) && ENTITY::DOES_ENTITY_EXIST(Cone) && ENTITY::DOES_ENTITY_EXIST(Tool))
				{
					if (Features::spawnincar)
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					}
					if (Features::cargodmodebool) {
						Features::cargodmode3(Vehicle);
					}
					VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
					VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Broom, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, false, 0, 0, 2, true);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Cone, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, false, 0, 0, 2, true);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Tool, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, false, 0, 0, 2, true);
					ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);

				}

			}

		}
		if (Menu::Option("JetSki And Trailer")) {
			uint Me = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0.;
			Vector3 a; a.x = -0.625, a.y = -1.9, a.z = -0.09;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			Vector3 a1; a1.x = 0.625, a1.y = -1.9, a1.z = -0.09;
			Vector3 b1; b1.x = 0, b1.y = 0, b1.z = 0;

			Vector3 a2; a2.x = 0.0, a2.y = 0.9, a2.z = -0.45;
			Vector3 b2; b2.x = 0, b2.y = 0, b2.z = 180.0;

			int hash = GAMEPLAY::GET_HASH_KEY("boattrailer");
			int hash2 = GAMEPLAY::GET_HASH_KEY("seashark");
			int hash3 = GAMEPLAY::GET_HASH_KEY("prop_tool_box_05");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			STREAMING::REQUEST_MODEL(hash3);

			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object1 = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object2 = OBJECT::CREATE_OBJECT(hash3, null.x, null.y, null.z, 1, 0, 1);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Object1) && ENTITY::DOES_ENTITY_EXIST(Object2))
				{
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, false, 0, 0, 2, true);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object2, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, false, 0, 0, 2, true);
					ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);
					ENTITY::SET_ENTITY_COLLISION(Object1, 1, 0);

				}

			}

		}
		if (Menu::Option("Ramp Truck")) {
			uint Me = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = 10.0, a.z = -0.3;
			Vector3 b; b.x = 0, b.y = -147.0, b.z = 90.0;
			int hash = GAMEPLAY::GET_HASH_KEY("phantom");
			int hash2 = GAMEPLAY::GET_HASH_KEY("prop_lev_des_barge_01");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object = OBJECT::CREATE_OBJECT(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
				{
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					if (Features::spawnincar)
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					}
					if (Features::cargodmodebool) {
						Features::cargodmode3(Vehicle);
					}
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
					ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);

				}

			}

		}
		if (Menu::Option("Monster Swat")) {
			uint Me = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = 0, a.z = 0;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("monster");
			int hash2 = GAMEPLAY::GET_HASH_KEY("riot");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
				{
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					if (Features::spawnincar)
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					}
					if (Features::cargodmodebool) {
						Features::cargodmode3(Vehicle);
					}
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
					VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
					VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

				}

			}

		}
		if (Menu::Option("Buffulo Police")) {
			uint Me = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = 0, a.z = 0;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("police2");
			int hash2 = GAMEPLAY::GET_HASH_KEY("buffalo2");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
				{
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					if (Features::spawnincar)
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					}
					if (Features::cargodmodebool) {
						Features::cargodmode3(Vehicle);
					}
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
					VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
					VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
					VEHICLE::SET_VEHICLE_WINDOW_TINT(Vehicle, 5);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
					VEHICLE::SET_VEHICLE_EXTRA_COLOURS(Object, 0, 0);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

				}

			}

		}
		if (Menu::Option("Insurgent 3")) {
			uint Me = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = 0, a.z = 0;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("insurgent");
			int hash2 = GAMEPLAY::GET_HASH_KEY("insurgent2");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
				{
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					if (Features::spawnincar)
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					}
					if (Features::cargodmodebool) {
						Features::cargodmode3(Vehicle);
					}
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
					VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
					VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

				}

			}

		}
		if (Menu::Option("Super 1")) {
			uint Me = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = 0, a.z = -0.25;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("t20");
			int hash2 = GAMEPLAY::GET_HASH_KEY("cheetah");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
				{
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					if (Features::spawnincar)
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					}
					if (Features::cargodmodebool) {
						Features::cargodmode3(Vehicle);
					}
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
					VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
					VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

				}

			}

		}
		if (Menu::Option("Super 2")) {
			uint Me = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = 0, a.z = 0;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("feltzer2");
			int hash2 = GAMEPLAY::GET_HASH_KEY("rapidgt");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
				{
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					if (Features::spawnincar)
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					}
					if (Features::cargodmodebool) {
						Features::cargodmode3(Vehicle);
					}
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
					VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
					VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

				}

			}

		}
		if (Menu::Option("Muscle 1")) {
			uint Me = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = 0, a.z = -0.2;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("hotknife");
			int hash2 = GAMEPLAY::GET_HASH_KEY("jb700");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
				{
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					if (Features::spawnincar)
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					}
					if (Features::cargodmodebool) {
						Features::cargodmode3(Vehicle);
					}
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
					VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
					VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

				}

			}

		}
		if (Menu::Option("Muscle 2")) {
			uint Me = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = 0, a.z = 2.0;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("coquette2");
			int hash2 = GAMEPLAY::GET_HASH_KEY("hotknife");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
				{
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					if (Features::spawnincar)
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					}
					if (Features::cargodmodebool) {
						Features::cargodmode3(Vehicle);
					}
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
					VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
					VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

				}

			}

		}
		if (Menu::Option("Special")) {
			uint Me = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = 0, a.z = 0;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("zentorno");
			int hash2 = GAMEPLAY::GET_HASH_KEY("kuruma2");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
				{
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					if (Features::spawnincar)
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					}
					if (Features::cargodmodebool) {
						Features::cargodmode3(Vehicle);
					}
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
					VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
					VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

				}

			}

		}
		if (Menu::Option("Sub Copter")) {
			uint Me = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = 1, a.z = 0.8;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("buzzard");
			int hash2 = GAMEPLAY::GET_HASH_KEY("submersible");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
				{
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					if (Features::spawnincar)
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					}
					if (Features::cargodmodebool) {
						Features::cargodmode3(Vehicle);
					}
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
					VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
					VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 255, 149, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

				}

			}

		}
		if (Menu::Option("Slamvan")) {
			uint Me = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = -2.0, a.z = 1.1;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			Vector3 null1; null1.x = 0, null1.y = 0; null1.z = 0;
			Vector3 a1; a1.x = -1.06, a1.y = -0.1, a1.z = 0.46;
			Vector3 b1; b1.x = 91.0, b1.y = 0, b1.z = 0;
			Vector3 null2; null2.x = 0, null2.y = 0; null2.z = 0;
			Vector3 a2; a2.x = -0.9, a2.y = 0.61, a2.z = 0.62;
			Vector3 b2; b2.x = 0.0, b2.y = 100.0, b2.z = 0;
			Vector3 null3; null3.x = 0, null3.y = 0; null3.z = 0;
			Vector3 a3; a3.x = 0.9, a3.y = 0.8, a3.z = 0.41;
			Vector3 b3; b3.x = -25.0, b3.y = 0, b3.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("flatbed");
			int hash2 = GAMEPLAY::GET_HASH_KEY("slamvan2");
			int hash3 = GAMEPLAY::GET_HASH_KEY("prop_tool_broom");
			int hash4 = GAMEPLAY::GET_HASH_KEY("prop_roadcone01a");
			int hash5 = GAMEPLAY::GET_HASH_KEY("prop_tool_box_02");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			STREAMING::REQUEST_MODEL(hash3);
			STREAMING::REQUEST_MODEL(hash4);
			STREAMING::REQUEST_MODEL(hash5);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Broom = OBJECT::CREATE_OBJECT(hash3, null1.x, null1.y, null1.z, 1, 0, 1);
				int Cone = OBJECT::CREATE_OBJECT(hash4, null2.x, null2.y, null2.z, 1, 0, 1);
				int Tool = OBJECT::CREATE_OBJECT(hash5, null3.x, null3.y, null3.z, 1, 0, 1);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Broom) && ENTITY::DOES_ENTITY_EXIST(Cone) && ENTITY::DOES_ENTITY_EXIST(Tool))
				{
					if (Features::spawnincar)
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					}
					if (Features::cargodmodebool) {
						Features::cargodmode3(Vehicle);
					}
					VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 8, 17, 30);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 30, 1);
					VEHICLE::SET_VEHICLE_EXTRA_COLOURS(Object, 92, 0);
					VEHICLE::SET_VEHICLE_COLOURS(Object, 12, 53);
					VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(Object, 1);
					VEHICLE::TOGGLE_VEHICLE_MOD(Object, 18, 1);
					VEHICLE::TOGGLE_VEHICLE_MOD(Object, 22, 1);
					VEHICLE::SET_VEHICLE_MOD(Object, 11, 3, 0);
					VEHICLE::SET_VEHICLE_MOD(Object, 14, 14, 0);
					VEHICLE::SET_VEHICLE_MOD(Object, 15, 3, 0);
					VEHICLE::SET_VEHICLE_MOD(Object, 13, 2, 0);
					VEHICLE::SET_VEHICLE_WHEEL_TYPE(Object, 6);
					VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
					VEHICLE::SET_VEHICLE_MOD(Object, 23, 18, 1);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Broom, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, false, 0, 0, 2, true);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Cone, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, false, 0, 0, 2, true);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Tool, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, false, 0, 0, 2, true);

				}

			}

		}
		if (Menu::Option("Flying 5 Seater")) {
			uint Me = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0.;

			Vector3 a; a.x = 0.0, a.y = 0.0, a.z = 0.6;		// seashark 1 - 0.7 worked just hard to get on .. infront and behind wings only way to get on the sharks ...
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;

			Vector3 a1; a1.x = 0.0, a1.y = -4.0, a1.z = 0.6;  // seashark 2
			Vector3 b1; b1.x = 0, b1.y = 0, b1.z = 0;


			Vector3 a2; a2.x = 0.0, a2.y = 0.9, a2.z = -0.45;
			Vector3 b2; b2.x = 0, b2.y = 0, b2.z = 180.0;

			int hash = GAMEPLAY::GET_HASH_KEY("hydra");
			int hash2 = GAMEPLAY::GET_HASH_KEY("seashark");
			int hash3 = GAMEPLAY::GET_HASH_KEY("prop_tool_box_05"); // turn this into something usefull maybe another sea shark ...
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			STREAMING::REQUEST_MODEL(hash3);

			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object1 = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object2 = OBJECT::CREATE_OBJECT(hash3, null.x, null.y, null.z, 1, 0, 1);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Object1) && ENTITY::DOES_ENTITY_EXIST(Object2))
				{
					if (Features::spawnincar)
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					}
					if (Features::cargodmodebool) {
						Features::cargodmode3(Vehicle);
					}
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, false, 0, 0, 2, true);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object2, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, false, 0, 0, 2, true);
					ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);
					ENTITY::SET_ENTITY_COLLISION(Object1, 1, 0);

				}

			}

		}
		if (Menu::Option("Panto/HotKnife")) {
			uint Handle = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			//hash2_PANTO
			Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
			Vector3 a; a.x = 0.0, a.y = 0.0, a.z = -0.2;//X Coord - Y Coord - Z Coord
			Vector3 b; b.x = 0.0, b.y = 0.0, b.z = 0.0;//Pitch - Roll - Yaw
													   //hash3_MiniGun
			Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
			Vector3 a1; a1.x = -0.60, a1.y = 1.60, a1.z = 0.20;
			Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 88.0;
			//hash3_MiniGun2
			Vector3 null0; null0.x = 0.0, null0.y = 0.0; null0.z = 0.0;
			Vector3 a0; a0.x = 0.60, a0.y = 1.60, a0.z = 0.20;
			Vector3 b0; b0.x = 0.0, b0.y = 0.0, b0.z = 88.0;
			//hash4_WindScreen _ VANISHED NEEDS FIXING
			Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
			Vector3 a2; a2.x = 0.3, a2.y = 0.41, a2.z = 0.50;
			Vector3 b2; b2.x = -45.3, b2.y = 0.0, b2.z = -179.0;//87
																//hash4_RLWheel1
			Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
			Vector3 a3; a3.x = -0.90, a3.y = -1.2, a3.z = 0.0; // -0.23
			Vector3 b3; b3.x = 0.0, b3.y = 0.0, b3.z = 86.0;
			//hash4_RFWindScreen 
			Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
			Vector3 a4; a4.x = -0.3, a4.y = 0.41, a4.z = 0.5;
			Vector3 b4; b4.x = -45.3, b4.y = 0.0, b4.z = -179.0;
			//hash4_RRWheel1
			Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
			Vector3 a5; a5.x = 0.92, a5.y = -1.2, a5.z = 0.01;
			Vector3 b5; b5.x = 0.0, b5.y = 0.0, b5.z = -92.0;
			//PUNTO -- FUCK UP NEEDS FIXING 
			Vector3 null6; null6.x = 0, null6.y = 0; null6.z = 0;
			Vector3 a6; a6.x = 0.0, a6.y = 0.0, a6.z = -0.2;
			Vector3 b6; b6.x = 0.0, b6.y = 0.0, b6.z = 0.0;
			//SIDES LEFT
			Vector3 null7; null7.x = 0, null7.y = 0; null7.z = 0;
			Vector3 a7; a7.x = -0.75, a7.y = 0.7, a7.z = -0.3;
			Vector3 b7; b7.x = 90.0, b7.y = 0.0, b7.z = 0.0;
			//SIDES RIGHT
			Vector3 null8; null8.x = 0, null8.y = 0; null8.z = 0;
			Vector3 a8; a8.x = 0.75, a8.y = 0.7, a8.z = -0.3;
			Vector3 b8; b8.x = 90.0, b8.y = 0.0, b8.z = 0.0;

			int hash = GAMEPLAY::GET_HASH_KEY("hotknife");
			int hash2_EMP = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");
			int hash3_MiniGun = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");
			int hash4_Wheel = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");
			int hash2 = GAMEPLAY::GET_HASH_KEY("panto");
			int hashWindow = GAMEPLAY::GET_HASH_KEY("prop_ballistic_shield");
			int hashSides = GAMEPLAY::GET_HASH_KEY("prop_cons_plank");




			STREAMING::REQUEST_MODEL(hashWindow);// WINDOW
			STREAMING::REQUEST_MODEL(hash2_EMP); // PANTO
			STREAMING::REQUEST_MODEL(hash3_MiniGun); // GUNS
			STREAMING::REQUEST_MODEL(hash4_Wheel); // back wheels
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			STREAMING::REQUEST_MODEL(hashSides); // SIDE SKIRTS

			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hashSides) && STREAMING::HAS_MODEL_LOADED(hashWindow) && STREAMING::HAS_MODEL_LOADED(hash2_EMP) && STREAMING::HAS_MODEL_LOADED(hash3_MiniGun) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash4_Wheel))
			{
				int EMP = OBJECT::CREATE_OBJECT(hash2_EMP, null.x, null.y, null.z, 1, 0, 1);
				int MiniGun = OBJECT::CREATE_OBJECT(hash3_MiniGun, null1.x, null1.y, null1.z, 1, 0, 1);
				int MiniGun2 = OBJECT::CREATE_OBJECT(hash3_MiniGun, null0.x, null0.y, null0.z, 1, 0, 1);
				int WINDOW_1 = OBJECT::CREATE_OBJECT(hashWindow, null2.x, null2.y, null2.z, 1, 0, 1);
				int RLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null3.x, null3.y, null3.z, 1, 0, 1);
				int WINDOW_2 = OBJECT::CREATE_OBJECT(hashWindow, null4.x, null4.y, null4.z, 1, 0, 1);
				int RRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null5.x, null5.y, null5.z, 1, 0, 1);
				int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int LeftSide = OBJECT::CREATE_OBJECT(hashSides, null7.x, null7.y, null7.z, 1, 0, 1);
				int RightSide = OBJECT::CREATE_OBJECT(hashSides, null8.x, null8.y, null8.z, 1, 0, 1);


				if (ENTITY::DOES_ENTITY_EXIST(EMP) && ENTITY::DOES_ENTITY_EXIST(LeftSide) && ENTITY::DOES_ENTITY_EXIST(RightSide) && ENTITY::DOES_ENTITY_EXIST(MiniGun) && ENTITY::DOES_ENTITY_EXIST(MiniGun2) && ENTITY::DOES_ENTITY_EXIST(WINDOW_1) && ENTITY::DOES_ENTITY_EXIST(RLWheel1) && ENTITY::DOES_ENTITY_EXIST(WINDOW_2) && ENTITY::DOES_ENTITY_EXIST(RRWheel1))
				{
					int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

					if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
					{
						if (Features::spawnincar)
						{
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						}
						if (Features::cargodmodebool) {
							Features::cargodmode3(Vehicle);
						}
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
						ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true);
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
						VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
						VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Vehicle, "sm");
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "sm");
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(Vehicle, 1);
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(Object, 1);

						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(EMP, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun2, Vehicle, 0, a0.x, a0.y, a0.z, b0.x, b0.y, b0.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(WINDOW_1, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel1, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(WINDOW_2, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel1, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(LeftSide, Vehicle, 0, a7.x, a7.y, a7.z, b7.x, b7.y, b7.z, 0, 1, 0, 0, 2, 1);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(RightSide, Vehicle, 0, a8.x, a8.y, a8.z, b8.x, b8.y, b8.z, 0, 1, 0, 0, 2, 1);


					}

				}

			}

		}
		if (Menu::Option("Monster Digger")) {
			uint Handle = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			//hash2_Dozer
			Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
			Vector3 a; a.x = 0.0, a.y = 0.0, a.z = -0.4;   //X Coord - Y Coord - Z Coord
			Vector3 b; b.x = 0.0, b.y = 0.0, b.z = 0.0;   //Pitch - Roll - Yaw
														  //hash3_MiniGun LEFT
			Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
			Vector3 a1; a1.x = -0.70, a1.y = 1.80, a1.z = 0.98;
			Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 88.0;
			//hash3_MiniGun2 RIGHT
			Vector3 null0; null0.x = 0.0, null0.y = 0.0; null0.z = 0.0;
			Vector3 a0; a0.x = 0.70, a0.y = 1.80, a0.z = 0.98;
			Vector3 b0; b0.x = 0.0, b0.y = 0.0, b0.z = 88.0;
			//hash4_Left BLUE left
			Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
			Vector3 a2; a2.x = -0.31, a2.y = 2.51, a2.z = 0.55;
			Vector3 b2; b2.x = 0.0, b2.y = 0.0, b2.z = -175.0;//87 - 179
															  //hash4_NIONS LEFT/back
			Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
			Vector3 a3; a3.x = 0.5, a3.y = -3.0, a3.z = -0.36; // -0.23
			Vector3 b3; b3.x = 0.0, b3.y = 0.0, b3.z = 86.0;
			//hash4_Right BLUE LIGHT
			Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
			Vector3 a4; a4.x = 0.31, a4.y = 2.51, a4.z = 0.55;
			Vector3 b4; b4.x = 0.0, b4.y = 0.0, b4.z = -175.0;
			//hash4_NIONS RIGHT
			Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
			Vector3 a5; a5.x = 0.92, a5.y = -2.0, a5.z = 0.01;
			Vector3 b5; b5.x = 0.0, b5.y = 0.0, b5.z = 89.0;
			//ENGINE
			Vector3 null6; null6.x = 0, null6.y = 0; null6.z = 0;
			Vector3 a6; a6.x = 0.0, a6.y = 1.76, a6.z = 0.86;
			Vector3 b6; b6.x = -0.0, b6.y = 0.0, b6.z = 0.0;
			//SIDES LEFT EMP
			Vector3 null7; null7.x = 0, null7.y = 0; null7.z = 0;
			Vector3 a7; a7.x = -0.88, a7.y = -1.8, a7.z = 1.0;
			Vector3 b7; b7.x = 0.0, b7.y = -51.9, b7.z = 0.0;
			//SIDES RIGHT EMP
			Vector3 null8; null8.x = 0, null8.y = 0; null8.z = 0;
			Vector3 a8; a8.x = 0.88, a8.y = -1.8, a8.z = 1.0;
			Vector3 b8; b8.x = 0.0, b8.y = 51.9, b8.z = 0.0;
			//BEAR
			Vector3 null9; null9.x = 0, null9.y = 0; null9.z = 0;
			Vector3 a9; a9.x = -1.0, a9.y = 2.7, a9.z = -0.4;
			Vector3 b9; b9.x = 0.0, b9.y = 0.0, b9.z = 156.5;
			//SPIKES
			Vector3 null10; null10.x = 0, null10.y = 0; null10.z = 0;
			Vector3 a10; a10.x = -0.12, a10.y = 0.59, a10.z = 1.9;
			Vector3 b10; b10.x = 0.0, b10.y = 0.0, b10.z = 0.0;

			int hash = GAMEPLAY::GET_HASH_KEY("monster");				// Monster Truck
			int hash1 = GAMEPLAY::GET_HASH_KEY("prop_car_engine_01");	// Car Engine
			int hash2 = GAMEPLAY::GET_HASH_KEY("bulldozer");			// Dozer
																		//int hash3 = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");		// Mini GUn 
																		//int hash4 = GAMEPLAY::GET_HASH_KEY("v_ilev_uvcheetah");		// Nion Lights <-- needs changing
																		//int hash5 = GAMEPLAY::GET_HASH_KEY("prop_air_lights_05a");	// Blue Lights	
																		//int hash6 = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");	// Emp Lights	
																		//int hash7 = GAMEPLAY::GET_HASH_KEY("prop_mem_teddy_02");	// Large Teddy	
																		//int hash8 = GAMEPLAY::GET_HASH_KEY("p_stinger_04");			// Stinger Spikes

			STREAMING::REQUEST_MODEL(hash); 	// MONSTER
			STREAMING::REQUEST_MODEL(hash1); 	// Car Engine
			STREAMING::REQUEST_MODEL(hash2); 	// DOZER
												//STREAMING::REQUEST_MODEL(hash3); 	// GUNS
												//STREAMING::REQUEST_MODEL(hash4); 	// Nion Lights
												//STREAMING::REQUEST_MODEL(hash5);	// Blue Lights
												//STREAMING::REQUEST_MODEL(hash6); 	// Emp Lights
												//STREAMING::REQUEST_MODEL(hash7); 	// Large Teddy
												//STREAMING::REQUEST_MODEL(hash8); 	// SPIKES

			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash1) && STREAMING::HAS_MODEL_LOADED(hash2))
			{
				int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				int Ebox = OBJECT::CREATE_OBJECT(hash1, null.x, null.y, null.z, 1, 0, 1);
				/*				int GunL = OBJECT::CREATE_OBJECT(hash3, null1.x, null1.y, null1.z, 1, 0, 1);
				int GunR = OBJECT::CREATE_OBJECT(hash3, null0.x, null0.y, null0.z, 1, 0, 1);
				int LSign = OBJECT::CREATE_OBJECT(hash4, null3.x, null3.y, null3.z, 1, 0, 1);
				int RSign = OBJECT::CREATE_OBJECT(hash4, null5.x, null5.y, null5.z, 1, 0, 1);
				int LBlight = OBJECT::CREATE_OBJECT(hash5, null2.x, null2.y, null2.z, 1, 0, 1);
				int RBlight = OBJECT::CREATE_OBJECT(hash5, null4.x, null4.y, null4.z, 1, 0, 1);
				int LeftEmp = OBJECT::CREATE_OBJECT(hash6, null7.x, null7.y, null7.z, 1, 0, 1);
				int RightEmp = OBJECT::CREATE_OBJECT(hash6, null8.x, null8.y, null8.z, 1, 0, 1);
				int Teddy = OBJECT::CREATE_OBJECT(hash7, null9.x, null9.y, null9.z, 1, 0, 1);
				int Spikes = OBJECT::CREATE_OBJECT(hash8, null10.x, null10.y, null10.z, 1, 0, 1);*/

				if (ENTITY::DOES_ENTITY_EXIST(Ebox) && ENTITY::DOES_ENTITY_EXIST(Object))
				{
					int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

					if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
					{
						if (Features::spawnincar)
						{
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						}
						if (Features::cargodmodebool) {
							Features::cargodmode3(Vehicle);
						}
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
						ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true);
						VEHICLE::SET_VEHICLE_MOD_KIT(Vehicle, 5);
						VEHICLE::SET_VEHICLE_WINDOW_TINT(Vehicle, 5);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);

						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Ebox, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
					}

				}

			}

		}
		if (Menu::Option("Train")) {
			uint Me = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = 0, a.z = 0;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("massacro2");
			int hash2 = GAMEPLAY::GET_HASH_KEY("freight");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
				{
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					if (Features::spawnincar)
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					}
					if (Features::cargodmodebool) {
						Features::cargodmode();
					}
					ENTITY::SET_ENTITY_VISIBLE(Object, true);
					VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
					VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "sm");
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

				}

			}

		}
		if (Menu::Option("Classic Car Mix")) {
			uint Me = PLAYER::PLAYER_PED_ID();
			Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 null; null.x = 0, null.y = 0; null.z = 0;
			Vector3 a; a.x = 0, a.y = 0, a.z = 0;
			Vector3 b; b.x = 0, b.y = 0, b.z = 0;
			int hash = GAMEPLAY::GET_HASH_KEY("ztype");
			int hash2 = GAMEPLAY::GET_HASH_KEY("btype");
			STREAMING::REQUEST_MODEL(hash);
			STREAMING::REQUEST_MODEL(hash2);
			if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				int Object = VEHICLE::CREATE_VEHICLE(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
				{
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					if (Features::spawnincar)
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					}
					if (Features::cargodmodebool) {
						Features::cargodmode3(Vehicle);
					}
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
					VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
					VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

				}

			}

		}
	}
	break;

	}
	break;
	case dlc_main:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("DLC Spawner");
		Menu::MenuOption("Spawner Settings", spawnsettings);
		Menu::MenuOption("Spawn Manager", spawnmanager);
		if (!versionnumber) {
			Menu::MenuOption(dlcnames[0], dlc_beachbum);
			Menu::MenuOption(dlcnames[1], dlc_valentine1);
			Menu::MenuOption(dlcnames[2], dlc_business);
			Menu::MenuOption(dlcnames[3], dlc_highlife);
			Menu::MenuOption(dlcnames[4], dlc_nothipster);
			Menu::MenuOption(dlcnames[5], dlc_independence);
			Menu::MenuOption(dlcnames[6], dlc_flightschool);
			Menu::MenuOption(dlcnames[7], dlc_lastteamstanding);
			Menu::MenuOption(dlcnames[8], dlc_festive2014);
			Menu::MenuOption(dlcnames[9], dlc_heist);
			Menu::MenuOption(dlcnames[10], dlc_illgg);
			Menu::MenuOption(dlcnames[11], dlc_lowrider);
			Menu::MenuOption(dlcnames[12], dlc_halloween);
			Menu::MenuOption(dlcnames[13], dlc_executive);
			Menu::MenuOption(dlcnames[14], dlc_festive2015);
			Menu::MenuOption(dlcnames[15], dlc_dropzone);
			Menu::MenuOption(dlcnames[16], dlc_valentine2);
			Menu::MenuOption(dlcnames[17], dlc_customclassics);
			Menu::MenuOption(dlcnames[18], dlc_finance);
			Menu::MenuOption(dlcnames[19], dlc_cunningstunts);
			Menu::MenuOption(dlcnames[20], dlc_bikers);
			Menu::MenuOption(dlcnames[21], dlc_import);
			Menu::MenuOption(dlcnames[22], dlc_specialveh);
			Menu::MenuOption(dlcnames[23], dlc_gunrunning);
			Menu::MenuOption(dlcnames[24], dlc_smugglersrun);
			Menu::MenuOption(dlcnames[25], dlc_doomsday);
			Menu::MenuOption(dlcnames[26], dlc_southernsan);
			Menu::MenuOption(dlcnames[27], dlc_afterhours);
			Menu::MenuOption(dlcnames[28], dlc_arenawar);
		}
		else {
			Menu::MenuOption(dlcnames2[0], dlc_beachbum);
			Menu::MenuOption(dlcnames2[1], dlc_valentine1);
			Menu::MenuOption(dlcnames2[2], dlc_business);
			Menu::MenuOption(dlcnames2[3], dlc_highlife);
			Menu::MenuOption(dlcnames2[4], dlc_nothipster);
			Menu::MenuOption(dlcnames2[5], dlc_independence);
			Menu::MenuOption(dlcnames2[6], dlc_flightschool);
			Menu::MenuOption(dlcnames2[7], dlc_lastteamstanding);
			Menu::MenuOption(dlcnames2[8], dlc_festive2014);
			Menu::MenuOption(dlcnames2[9], dlc_heist);
			Menu::MenuOption(dlcnames2[10], dlc_illgg);
			Menu::MenuOption(dlcnames2[11], dlc_lowrider);
			Menu::MenuOption(dlcnames2[12], dlc_halloween);
			Menu::MenuOption(dlcnames2[13], dlc_executive);
			Menu::MenuOption(dlcnames2[14], dlc_festive2015);
			Menu::MenuOption(dlcnames2[15], dlc_dropzone);
			Menu::MenuOption(dlcnames2[16], dlc_valentine2);
			Menu::MenuOption(dlcnames2[17], dlc_customclassics);
			Menu::MenuOption(dlcnames2[18], dlc_finance);
			Menu::MenuOption(dlcnames2[19], dlc_cunningstunts);
			Menu::MenuOption(dlcnames2[20], dlc_bikers);
			Menu::MenuOption(dlcnames2[21], dlc_import);
			Menu::MenuOption(dlcnames2[22], dlc_specialveh);
			Menu::MenuOption(dlcnames2[23], dlc_gunrunning);
			Menu::MenuOption(dlcnames2[24], dlc_smugglersrun);
			Menu::MenuOption(dlcnames2[25], dlc_doomsday);
			Menu::MenuOption(dlcnames2[26], dlc_southernsan);
			Menu::MenuOption(dlcnames2[27], dlc_afterhours);
			Menu::MenuOption(dlcnames2[28], dlc_arenawar);
		}
		break;
	case dlc_beachbum:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[0]);
		for (auto car : beachbum) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_valentine1:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[1]);
		for (auto car : valetinesmassacre) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_business:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[2]);
		for (auto car : business) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_highlife:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[3]);
		for (auto car : highlife) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_nothipster:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[4]);
		for (auto car : notahipster) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_independence:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[5]);
		for (auto car : independence) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_flightschool:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[6]);
		for (auto car : saflightschool) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_lastteamstanding:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[7]);
		for (auto car : lastteamstanding) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_festive2014:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[8]);
		for (auto car : festive2014) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_heist:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[9]);
		for (auto car : heist) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_illgg:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[10]);
		for (auto car : illgg) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_lowrider:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[11]);
		for (auto car : lowriders) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_halloween:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[12]);
		for (auto car : halloween) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_executive:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[13]);
		for (auto car : executives) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_festive2015:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[14]);
		for (auto car : festive2015) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_dropzone:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[15]);
		for (auto car : dropzone) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_valentine2:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[16]);
		for (auto car : bemyvalentine) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_customclassics:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[17]);
		for (auto car : customclassics) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_finance:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[18]);
		for (auto car : financefelony) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_cunningstunts:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[19]);
		for (auto car : CUNNINGSTUNTS1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_bikers:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[20]);
		for (auto car : bikers) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_import:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[21]);
		for (auto car : IMPORTEXPORT1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_specialveh:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[22]);
		for (auto car : specialvcircuit) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_gunrunning:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[23]);
		for (auto car : GUNRUNNING1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_smugglersrun:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[24]);
		for (auto car : SMUGLERSRUN1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_doomsday:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[25]);
		for (auto car : Doomsday1) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_southernsan:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[26]);
		for (auto car : SOUTHERNSAN) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_afterhours:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[27]);
		for (auto car : afterhrs) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	case dlc_arenawar:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(dlcnames[28]);
		for (auto car : arenawar) { Menu::Option(Features::vehicleNames ? VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(car)) : car, [car] {Features::spawn_vehicle(car); }); }
		break;
	}
	break;
	case spawnsettings:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Spawner Settings");
		Menu::Toggle("Spawn with Godmode", Features::cargodmodebool);
		Menu::Toggle("Spawn Maxed", Features::spawnmaxed);
	}
	break;
	case spawnmanager:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Spawn Manager");
		for (int i = 0; i < Features::spawnIndex; i++) {
			if (ENTITY::DOES_ENTITY_EXIST(Features::spawned[i])) {
				Menu::MenuOption(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(Features::spawnedHash[i]), spawnm_sub) ? Features::selectedVehicle = i : NULL;
			}
		}
	}
	break;
	case spawnm_sub:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Spawn Manager");
		if (Menu::Option("Teleport to Vehicle")) {
			Vector3 coords = coordsOf(Features::spawned[Features::selectedVehicle]);
			TPto(coords);
		}
		if (Menu::Option("Kick Passengers")) {
			Ped driver = VEHICLE::GET_PED_IN_VEHICLE_SEAT(Features::spawned[Features::selectedVehicle], -1);
			RequestControlOfEnt(driver);
			AI::CLEAR_PED_TASKS_IMMEDIATELY(driver);
			AI::CLEAR_PED_TASKS(driver);
			AI::CLEAR_PED_SECONDARY_TASK(driver);
		}
		if (Menu::Option("Slingshot Vehicle")) {
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Features::spawned[Features::selectedVehicle]);
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Features::spawned[Features::selectedVehicle]))
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(Features::spawned[Features::selectedVehicle], 1, 0, 0, 20, 0, 0, 0, 1, false, true, true, true, true);
			}
		}
		if (Menu::Option("Close Doors")) {
			VEHICLE::SET_VEHICLE_DOORS_SHUT(Features::spawned[Features::selectedVehicle], true);
		}
		if (Menu::Option("Open Doors")) {
			VEHICLE::SET_VEHICLE_DOOR_OPEN(Features::spawned[Features::selectedVehicle], 0, true, false);
			VEHICLE::SET_VEHICLE_DOOR_OPEN(Features::spawned[Features::selectedVehicle], 1, true, false);
			VEHICLE::SET_VEHICLE_DOOR_OPEN(Features::spawned[Features::selectedVehicle], 2, true, false);
			VEHICLE::SET_VEHICLE_DOOR_OPEN(Features::spawned[Features::selectedVehicle], 3, true, false);
			VEHICLE::SET_VEHICLE_DOOR_OPEN(Features::spawned[Features::selectedVehicle], 4, true, false);
			VEHICLE::SET_VEHICLE_DOOR_OPEN(Features::spawned[Features::selectedVehicle], 5, true, false);
			VEHICLE::SET_VEHICLE_DOOR_OPEN(Features::spawned[Features::selectedVehicle], 6, true, false);
			VEHICLE::SET_VEHICLE_DOOR_OPEN(Features::spawned[Features::selectedVehicle], 7, true, false);
		}
	}
	break;
	//END VEHICLE SPAWNER

#pragma endregion

#pragma region teleport

	case teleport:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Teleport Options");
		if (Menu::Option("Teleport to Waypoint")) { Features::Teleport_to_marker(); }
		if (Menu::Option("Teleport to Objective")) {
			Features::teleport_to_objective();
		}
		Menu::StringVector("Select Teleport Hotkey", Features::keynames, Features::keyIndex2);
		Menu::Toggle("Teleport with Hotkey", Features::tpbool, [] { Features::tpHotkey(Features::tpbool, Features::keyz[Features::keyIndex]); });
		if (Menu::Option("Mount Chiliad")) {
			Vector3 Coords;
			Coords.x = 496.75f; Coords.y = 5591.17f; Coords.z = 795.03f;
			TPto(Coords);
		}
		Features::drawMap(5, "mount_chiliad");
		if (Menu::Option("Maze Bank")) {
			Vector3 Coords;
			Coords.x = -74.94243f; Coords.y = -818.63446f; Coords.z = 326.174347f;
			TPto(Coords);
		}
		Features::drawMap(6, "maze_bank");
		if (Menu::Option("Military Base")) {
			Vector3 Coords;
			Coords.x = -2012.8470f; Coords.y = 2956.5270f; Coords.z = 32.8101f;
			TPto(Coords);
		}
		Features::drawMap(7, "m_base");
		if (Menu::Option("Zancudo Tower")) {
			Vector3 Coords;
			Coords.x = -2356.0940; Coords.y = 3248.645; Coords.z = 101.4505;
			TPto(Coords);
		}
		Features::drawMap(8, "zancudo_tower");
		if (Menu::Option("Mask Shop")) {
			Vector3 Coords;
			Coords.x = -1338.16; Coords.y = -1278.11; Coords.z = 4.87;
			TPto(Coords);
		}
		Features::drawMap(9, "mask_shop");
		if (Menu::Option("LS Customs")) {
			Vector3 Coords;
			Coords.x = -373.01; Coords.y = -124.91; Coords.z = 38.31;
			TPto(Coords);
		}
		Features::drawMap(10, "l_s_c");
		if (Menu::Option("Ammunation")) {
			Vector3 Coords;
			Coords.x = 247.3652; Coords.y = -45.8777; Coords.z = 69.9411;
			TPto(Coords);
		}
		Features::drawMap(11, "ammu_nation");
		if (Menu::Option("Airport")) {
			Vector3 Coords;
			Coords.x = -1102.2910f; Coords.y = -2894.5160f; Coords.z = 13.9467f;
			TPto(Coords);
		}
		Features::drawMap(12, "airport");
		if (Menu::Option("Ponsonbys")) {
			Vector3 Coords;
			Coords.x = -718.91; Coords.y = -158.16; Coords.z = 37.00;
			TPto(Coords);
		}
		Features::drawMap(13, "shop");
		if (Menu::Option("Waterfall")) {
			Vector3 Coords;
			Coords.x = -597.9525f; Coords.y = 4475.2910f; Coords.z = 25.6890f;
			TPto(Coords);
		}
		Features::drawMap(14, "waterfall");
		if (Menu::Option("FBI")) {
			Vector3 Coords;
			Coords.x = 135.5220f; Coords.y = -749.0003f; Coords.z = 260.0000f;
			TPto(Coords);
		}
		Features::drawMap(15, "fib");
		if (Menu::Option("Human Labs")) {
			Vector3 Coords;
			Coords.x = 3617.231f; Coords.y = 3739.871f; Coords.z = 28.6901f;
			TPto(Coords);
		}
		Features::drawMap(16, "h_labs");
		if (Menu::Option("MMI")) {
			Vector3 Coords;
			Coords.x = -222.1977; Coords.y = -1185.8500; Coords.z = 23.0294;
			TPto(Coords);
		}
		Features::drawMap(17, "mmi");
		if (Menu::Option("Sandy Shores Airfield")) {
			Vector3 Coords;
			Coords.x = 1741.4960f; Coords.y = 3269.2570f; Coords.z = 41.6014f;
			TPto(Coords);
		}
		Features::drawMap(18, "airport2");
		if (Menu::Option("Bennys Garage")) {
			Vector3 Coords;
			Coords.x = -196.349442f; Coords.y = -1303.103271f; Coords.z = 30.650515f;
			TPto(Coords);
		}
		Features::drawMap(19, "benny");
		if (Menu::Option("Strip Club")) {
			Vector3 Coords;
			Coords.x = 135.548096f; Coords.y = -1308.388306f; Coords.z = 28.344141f;
			TPto(Coords);
		}
		Features::drawMap(20, "club");
	}

	break;
#pragma endregion

#pragma region world

	case blacklist_:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Session Blacklist");
		if (low_bl) {
			deep_bl = true;
			low_bl = false;
		}
		if (loadBlacklist) {
			std::string spath = "X-Folder/friends/blacklist_cfg.ini";
			std::string skey[] = { "kick", "warn", "freeze", "blame", "explode" };
			for (int i = 0; i < 999; i++) {
				Features::b_player[i].kick = false;
				Features::b_player[i].warn = false;
				Features::b_player[i].freeze = false;
				Features::b_player[i].blame = false;
				Features::b_player[i].explode = false;
			}
			XScript::getFileContent("X-Folder/friends/blacklist.txt", Features::blacklist_names);
			for (int i = 0; i < Features::blacklist_names.size(); i++) {
				std::string sapp = Features::blacklist_names[i];
				if (INI::GetInt(spath, sapp, skey[0]) == 1) {
					Features::b_player[i].kick = true;
				}
				else {
					Features::b_player[i].kick = false;
				}

				if (INI::GetInt(spath, sapp, skey[1]) == 1) {
					Features::b_player[i].warn = true;
				}
				else {
					Features::b_player[i].warn = false;
				}

				if (INI::GetInt(spath, sapp, skey[2]) == 1) {
					Features::b_player[i].freeze = true;
				}
				else {
					Features::b_player[i].freeze = false;
				}

				if (INI::GetInt(spath, sapp, skey[3]) == 1) {
					Features::b_player[i].blame = true;
				}
				else {
					Features::b_player[i].blame = false;
				}

				if (INI::GetInt(spath, sapp, skey[4]) == 1) {
					Features::b_player[i].explode = true;
				}
				else {
					Features::b_player[i].explode = false;
				}
			}
			loadBlacklist = false;
		}
		for (int i = 0; i < Features::blacklist_names.size(); i++) {
			if (Features::blacklist_names[i] != "") {
				if (Menu::MenuOption(Features::blacklist_names[i].c_str(), blacklist_kek)) {
					Features::blacklistID = i;
					Features::selectedBlacklist = Features::player_id_from_name((char*)Features::blacklist_names[i].c_str());
				}
			}
		}
		if (Menu::Option("Reload Blacklist")) {
			for (int i = 0; i < Features::blacklist_names.size(); i++) {
				Features::blacklist_names[i] = "";
			}
			deep_bl = true;
			XScript::getFileContent("X-Folder/friends/blacklist.txt", Features::blacklist_names);
		}
		Menu::Toggle("Enable Blacklist", Features::turn_on_blacklist);
	}
	break;
	case blacklist_kek:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break((char*)Features::blacklist_names[Features::blacklistID].c_str());
		std::string spath = "X-Folder/friends/blacklist_cfg.ini";
		std::string sapp = Features::blacklist_names[Features::blacklistID];
		std::string skey[] = { "kick", "warn", "freeze", "blame", "explode" };
		//Features::loadBlacklistOptions2((char*)Features::blacklist_names[Features::blacklistID].c_str(), Features::blacklistID);
		if (deep_bl) {

			if (INI::GetInt(spath, sapp, skey[0]) == 1) {
				Features::b_player[Features::blacklistID].kick = true;
			}
			else {
				Features::b_player[Features::blacklistID].kick = false;
			}

			if (INI::GetInt(spath, sapp, skey[1]) == 1) {
				Features::b_player[Features::blacklistID].warn = true;
			}
			else {
				Features::b_player[Features::blacklistID].warn = false;
			}

			if (INI::GetInt(spath, sapp, skey[2]) == 1) {
				Features::b_player[Features::blacklistID].freeze = true;
			}
			else {
				Features::b_player[Features::blacklistID].freeze = false;
			}

			if (INI::GetInt(spath, sapp, skey[3]) == 1) {
				Features::b_player[Features::blacklistID].blame = true;
			}
			else {
				Features::b_player[Features::blacklistID].blame = false;
			}

			if (INI::GetInt(spath, sapp, skey[4]) == 1) {
				Features::b_player[Features::blacklistID].explode = true;
			}
			else {
				Features::b_player[Features::blacklistID].explode = false;
			}
			low_bl = true;
			deep_bl = false;
		}
		Menu::Toggle("Kick", Features::b_player[Features::blacklistID].kick, [&]
		{
			if (Features::b_player[Features::blacklistID].kick) {
				INI::WriteInt(spath, 1, sapp, skey[0]);
			}
			else {
				INI::WriteInt(spath, 0, sapp, skey[0]);
			}
		});
		Menu::Toggle("Warn", Features::b_player[Features::blacklistID].warn, [&]
		{
			if (Features::b_player[Features::blacklistID].warn) {
				INI::WriteInt(spath, 1, sapp, skey[1]);
			}
			else {
				INI::WriteInt(spath, 0, sapp, skey[1]);
			}
		});
		Menu::Toggle("Freeze", Features::b_player[Features::blacklistID].freeze, [&]
		{
			if (Features::b_player[Features::blacklistID].freeze) {
				INI::WriteInt(spath, 1, sapp, skey[2]);
			}
			else {
				INI::WriteInt(spath, 0, sapp, skey[2]);
			}
		});
	}
	break;
	case world:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("World Options");
		Menu::MenuOption("IPL Loader", ipls);
		Menu::MenuOption("Map Mods", mapmods);
		Menu::MenuOption("Blacklist", blacklist_);
		Menu::MenuOption("Merryweather", merryweather);
		Menu::MenuOption("Model Swap", modelswap_1);
		Menu::MenuOption("Drive Train", driveTrain);
		if (Menu::Option("Private Public Session")) {
			Sleep(10000);
			WAIT(250);
		}
		Menu::VipInt("Max Players", Features::playerCount, 1, 30);
		Menu::VipToggle("Set Max Players", Features::maxPlayers);
	}
	break;
	case modelswap_1:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Model Swap");
		//Menu::Toggle("Enable Model Swap", Features::modelSwapCompletelyOn);
		Menu::Float("Model Swap Radius", Features::ms_radius, 1, 1000, 1);
		if (firsttimeMs) {
			Features::initModelSwap();
			firsttimeMs = false;
		}
		for (int i = 0; i < ARRAYSIZE(objects2); i++) {
			if (Menu::MenuOption(objects2[i], modelswap_2)) {
				Features::modelID = i;
				Features::modelName = objects2[i];
			}
		}
		/*for (int j = 0; j < 656; j++) {
			if (Menu::MenuOption(Features::VEHICLE_NAMES[j].c_str(), modelswap_3)) {
				Features::modelID2 = j;
				Features::modelName2 = (char*)Features::VEHICLE_NAMES[j].c_str();
			}
		}*/
	}
	break;
	case modelswap_2:
	{
		Menu::Title(Menu::Settings::menuname);
		ostringstream ss; ss << "Swap " << Features::modelName;
		Menu::Break(ss.str().c_str());
		Menu::Float("Model Swap Radius", Features::ms_radius, 1, 1000, 0.1f);
		/*if (Menu::Option("Reset Model Swap")) {
			Features::removeModelSwap(objects2[Features::modelID]);
		}*/
		for (int i = 0; i < ARRAYSIZE(objects2); i++) {
			if (Menu::Option(objects2[i])) {
				Features::createModelSwap(objects2[Features::modelID], objects2[i]);
				Features::modelSwapOn[Features::s_model_ptr] = true;
				Features::s_model_ptr++;
			}
		}
	}
	break;
	case modelswap_3:
	{
		Menu::Title(Menu::Settings::menuname);
		ostringstream ss; ss << "Swap " << Features::modelName2;
		Menu::Break(ss.str().c_str());
		Menu::Float("Model Swap Radius", Features::ms_radius, 1, 1000, 0.1f);
		/*if (Menu::Option("Reset Model Swap")) {
			Features::removeModelSwap((char*)Features::VEHICLE_NAMES[Features::modelID2].c_str());
		}*/
		for (int i = 0; i < 656; i++) {
			if (Menu::Option(Features::VEHICLE_NAMES[i].c_str())) {
				Features::createModelSwap((char*)Features::VEHICLE_NAMES[Features::modelID2].c_str(), (char*)Features::VEHICLE_NAMES[i].c_str());
				Features::modelSwapOn[Features::s_model_ptr] = true;
				Features::s_model_ptr++;
			}
		}
	}
	break;
	case merryweather:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Merryweather Options");
		if (Menu::Option("Ammo Drop")) { Features::merryweather("AMMO"); }
		if (Menu::Option("Airstrike")) { Features::merryweather("AIRSTRIKE"); }
		if (Menu::Option("Boat Pickup")) { Features::merryweather("BOAT"); }
		if (Menu::Option("Heli Pickup")) { Features::merryweather("HELI"); }
	}
	break;
	case driveTrain:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Train Options");
		Menu::Float("Train Speed", Features::trainSpeed, 1.0f, 1000.0f);
		if (Menu::Option("Delete Train")) {
			Features::deleteTrain();
		}
		if (Menu::Option("Spawn Train 1")) { Features::spawnTrain(Freight0); }
		if (Menu::Option("Spawn Train 2")) { Features::spawnTrain(Freight01); }
		if (Menu::Option("Spawn Train 3")) { Features::spawnTrain(Freight02); }
		if (Menu::Option("Spawn Train 4")) { Features::spawnTrain(Freight03); }
		if (Menu::Option("Spawn Train 5")) { Features::spawnTrain(Freight04); }
		if (Menu::Option("Spawn Metro 1")) { Features::spawnTrain(Metro0); }
		if (Menu::Option("Spawn Metro 2")) { Features::spawnTrain(Metro01); }

	}
	break;

	case phone:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Phone Options");
		if (Menu::Option("Default Phone")) {
			Features::handy = -1;
			MOBILE::DESTROY_MOBILE_PHONE();
			Features::setPhone(-1);
		}
		if (Menu::Option("Michael's Phone")) {
			Features::handy = 0;
			Features::setPhone(0);
		}
		if (Menu::Option("Trevor's Phone")) {
			Features::handy = 1;
			Features::setPhone(1);
		}
		if (Menu::Option("Franklin's Phone")) {
			Features::handy = 2;
			Features::setPhone(2);
		}
		if (Menu::Option("Old Phone")) {
			Features::handy = 3;
			Features::setPhone(3);
		}
		Menu::Toggle("Disable Phone", Features::disablephone);
		Features::setPhone(Features::handy);
	}
	break;
	case ipls:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("IPLs");
		if (Menu::Option("North Yankton")) {
			STREAMING::REQUEST_IPL("prologue01");
			STREAMING::REQUEST_IPL("Prologue01c");
			STREAMING::REQUEST_IPL("Prologue01d");
			STREAMING::REQUEST_IPL("Prologue01e");
			STREAMING::REQUEST_IPL("Prologue01f");
			STREAMING::REQUEST_IPL("Prologue01g");
			STREAMING::REQUEST_IPL("prologue01h");
			STREAMING::REQUEST_IPL("prologue01i");
			STREAMING::REQUEST_IPL("prologue01j");
			STREAMING::REQUEST_IPL("prologue01k");
			STREAMING::REQUEST_IPL("prologue01z");
			STREAMING::REQUEST_IPL("prologue02");
			STREAMING::REQUEST_IPL("prologue03");
			STREAMING::REQUEST_IPL("prologue03b");
			STREAMING::REQUEST_IPL("prologue03_grv_cov");
			STREAMING::REQUEST_IPL("prologue03_grv_dug");
			STREAMING::REQUEST_IPL("prologue03_grv_fun");
			STREAMING::REQUEST_IPL("prologue04");
			STREAMING::REQUEST_IPL("prologue04b");
			STREAMING::REQUEST_IPL("prologue04_cover");
			STREAMING::REQUEST_IPL("prologue05");
			STREAMING::REQUEST_IPL("prologue05b");
			STREAMING::REQUEST_IPL("prologue06");
			STREAMING::REQUEST_IPL("prologue06b");
			STREAMING::REQUEST_IPL("prologue06_int");
			STREAMING::REQUEST_IPL("prologuerd");
			STREAMING::REQUEST_IPL("prologuerdb");
			STREAMING::REQUEST_IPL("prologue_DistantLights");
			STREAMING::REQUEST_IPL("prologue_grv_torch");
			STREAMING::REQUEST_IPL("prologue_m2_door");
			STREAMING::REQUEST_IPL("prologue_LODLights");
			STREAMING::REQUEST_IPL("DES_ProTree_start");
			Vector3 Coords;
			Coords.x = 3595.39673f; Coords.y = -4893.727f; Coords.z = 115.838394f;
			TPto(Coords);
		}
		if (Menu::Option("Porn Yacht")) {
			STREAMING::REQUEST_IPL("smboat");
			Vector3 Coords;
			Coords.x = -2045.8f; Coords.y = -1031.2f; Coords.z = 11.9f;
			TPto(Coords);
		}
		if (Menu::Option("Aircraft Carrier")) {
			STREAMING::REQUEST_IPL("hei_carrier");
			STREAMING::REQUEST_IPL("hei_carrier_DistantLights");
			STREAMING::REQUEST_IPL("hei_Carrier_int1");
			STREAMING::REQUEST_IPL("hei_Carrier_int2");
			STREAMING::REQUEST_IPL("hei_Carrier_int3");
			STREAMING::REQUEST_IPL("hei_Carrier_int4");
			STREAMING::REQUEST_IPL("hei_Carrier_int5");
			STREAMING::REQUEST_IPL("hei_Carrier_int6");
			STREAMING::REQUEST_IPL("hei_carrier_LODLights");
			Vector3 Coords;
			Coords.x = 3069.330f; Coords.y = -4632.4f; Coords.z = 15.043f;
			TPto(Coords);
		}
		if (Menu::Option("Sunken Cargoship")) {
			STREAMING::REQUEST_IPL("sunkcargoship");
			Vector3 Coords;
			Coords.x = -162.8918f; Coords.y = -2365.769f; Coords.z = 0.0f;
			TPto(Coords);
		}
		if (Menu::Option("Hospital")) {
			STREAMING::REQUEST_IPL("RC12B_HospitalInterior");
			STREAMING::REQUEST_IPL("RC12B_Destroyed");
			Vector3 Coords;
			Coords.x = 356.8f; Coords.y = -590.1f; Coords.z = 43.3f;
			TPto(Coords);
		}
		if (Menu::Option("Oneil Farm")) {
			STREAMING::REMOVE_IPL("farm_burnt");
			STREAMING::REMOVE_IPL("farm_burnt_props");
			STREAMING::REQUEST_IPL("farm");
			STREAMING::REQUEST_IPL("farm_props");
			STREAMING::REQUEST_IPL("farmint");
			STREAMING::REQUEST_IPL("farmint_cap");
			Vector3 Coords;
			Coords.x = 2441.2f; Coords.y = 4968.5f; Coords.z = 51.7f;
			TPto(Coords);
		}
		if (Menu::Option("Life Invader Office")) {
			STREAMING::REQUEST_IPL("facelobby");
			STREAMING::REQUEST_IPL("facelobbyfake");
			Vector3 Coords;
			Coords.x = -1047.9f; Coords.y = -233.0f; Coords.z = 39.0f;
			TPto(Coords);
		}
		if (Menu::Option("Cargoship")) {
			STREAMING::REQUEST_IPL("cargoship");
			Vector3 Coords;
			Coords.x = -162.8918f; Coords.y = -2365.769f; Coords.z = 9.3192f;
			TPto(Coords);
		}
		if (Menu::Option("Jewelry Store")) {
			STREAMING::REQUEST_IPL("jewel2fake");
			STREAMING::REQUEST_IPL("post_hiest_unload");
			STREAMING::REQUEST_IPL("bh1_16_refurb");
			Vector3 Coords;
			Coords.x = -630.4f; Coords.y = -236.7f; Coords.z = 40.0f;
			TPto(Coords);
		}
		if (Menu::Option("Morgue")) {
			STREAMING::REQUEST_IPL("Coroner_Int_on");
			Vector3 Coords;
			Coords.x = 244.9f; Coords.y = -1374.7f; Coords.z = 39.5f;
			TPto(Coords);
		}
	}
	break;

#pragma endregion

#pragma region misc

	case misc:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Misc Options");
		Menu::VipMenuOption("Stat Viewer", statview);
		Menu::MenuOption("Edit Phone", phone);
		//Menu::MenuOption("Event dumper (DEBUG)", debug);
		if (Menu::Option("Is this Account flagged?")) {
			if (Features::isBanned()) {
				notifyMap("~g~Account is NOT flagged!");
			}
			else {
				notifyMap("~r~DANGER! Account is flagged!");
			}
		}
		Menu::Toggle("Show FPS", Features::DisplayFPS, [] { Features::fDisplayFPS(Features::DisplayFPS); });
		Menu::Toggle("Nightvision", Features::nightvisionbool, [] { Features::nightvision(Features::nightvisionbool); });
		//Menu::Toggle("Thermal Vision", Features::thermalvisionbool, [] { Features::thermalvision(Features::thermalvisionbool); });
		Menu::VipToggle("Unlimited Orbital Cannon", Features::unlimitedorbitalcannon, [] { Features::UnlimitedORbitalCannon(Features::unlimitedorbitalcannon); });
		if (Menu::Option("Reset Vehicle sell Time")) {
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VEHICLE_SELL_TIME"), 0, true);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MONEY_EARN_SELLING_VEH"), 50000, true);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MONEY_EARN_SELLING_VEH"), 50000, true);
		}
		Menu::Toggle("Hide Hud", Features::HudBool, [] { Features::HideHud(); });
		if (Menu::Option("Skip Online Tutorial")) {
			Features::skipTutorial();
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NO_MORE_TUTORIALS"), 1, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_NO_MORE_TUTORIALS"), 1, 1);
		}
		if (Menu::Option("Max Singleplayer Money")) {
			Hash stat0 = $("SP0_TOTAL_CASH");
			Hash stat1 = $("SP1_TOTAL_CASH");
			Hash stat2 = $("SP2_TOTAL_CASH");
			STATS::STAT_SET_INT(stat0, INT_MAX, 1);
			STATS::STAT_SET_INT(stat1, INT_MAX, 1);
			STATS::STAT_SET_INT(stat2, INT_MAX, 1);
		}
		if (Menu::VipOption("Max Office Money")) {
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_LIFETIME_BUY_COMPLETE"), 1223, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_LIFETIME_BUY_UNDERTAKEN"), 1223, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_LIFETIME_SELL_COMPLETE"), 434, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_LIFETIME_SELL_UNDERTAKEN"), 434, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_LIFETIME_CONTRA_EARNINGS"), 1220000000, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_LIFETIME_BUY_COMPLETE"), 1223, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_LIFETIME_BUY_UNDERTAKEN"), 1223, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_LIFETIME_SELL_COMPLETE"), 434, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_LIFETIME_SELL_UNDERTAKEN"), 434, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_LIFETIME_CONTRA_EARNINGS"), 1220000000, 0);
		}
		Menu::VipToggle("Rockstar Dev Mode", Hooking::rdev);
		if (Menu::Option("Remove Transaction Loading")) {
			Features::removeLoading();
		}
		int Zoom;

		if (Menu::Int("Minimap Zoom", Zoom, 0, 1)) {
			UI::SET_RADAR_ZOOM(Zoom);
		}

	}
	break;
	case statview:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Stat Viewer");

		int reportkek1;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_REPORT_STRENGTH"), &reportkek1, -1);
		const auto& reportstringkek1 = "Report Strength: "s + std::to_string(reportkek1);
		Menu::Option(reportstringkek1.c_str());

		int reportkek2;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_COMMEND_STRENGTH"), &reportkek2, -1);
		const auto& reportstringkek2 = "Commend Strength: "s + std::to_string(reportkek2);
		Menu::Option(reportstringkek2.c_str());

		int reportkek;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), &reportkek, -1);
		const auto& reportstringkek = "Exploits: "s + std::to_string(reportkek);
		Menu::Option(reportstringkek.c_str());

		int reportkek3;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_FRIENDLY"), &reportkek3, -1);
		const auto& reportstringkek3 = "Friendly Commends: "s + std::to_string(reportkek3);
		Menu::Option(reportstringkek3.c_str());


		int reportkek4;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_HELPFUL"), &reportkek4, -1);
		const auto& reportstringkek4 = "Helpful Commends: "s + std::to_string(reportkek4);
		Menu::Option(reportstringkek4.c_str());

		int reportkek5;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_GRIEFING"), &reportkek5, -1);
		const auto& reportstringkek5 = "Griefing: "s + std::to_string(reportkek5);
		Menu::Option(reportstringkek5.c_str());

		int reportkek6;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_LANGUAGE"), &reportkek6, -1);
		const auto& reportstringkek6 = "Offensive Language: "s + std::to_string(reportkek6);
		Menu::Option(reportstringkek6.c_str());

		int reportkek7;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_UGC"), &reportkek7, -1);
		const auto& reportstringkek7 = "Offensive UGC: "s + std::to_string(reportkek7);
		Menu::Option(reportstringkek7.c_str());

		int reportkek8;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VC_HATE"), &reportkek8, -1);
		const auto& reportstringkek8 = "VC Hate: "s + std::to_string(reportkek8);
		Menu::Option(reportstringkek8.c_str());

		int reportkek9;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_ISPUNISHED"), &reportkek9, -1);

		const auto& reportstringkek9 = "Punished: "s + std::to_string(reportkek9);
		Menu::Option(reportstringkek9.c_str());
	}
	break;
	case OutfitMenu:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Outfit menu");
		Menu::StringVector("Gender", gender, genderPos);
		if (Menu::Option("Reset Outfit")) { PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID()); }
		if (genderPos == 0) {
			if (Menu::Option("Extreme Detach Everything"))
			{
				DWORD model = GAMEPLAY::GET_HASH_KEY("mp_m_freemode_01");
				STREAMING::REQUEST_MODEL(model);
				while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
				PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
				PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
				WAIT(10);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
			}
		}
		if (genderPos == 1) {
			if (Menu::Option("Extreme Detach Everything"))
			{
				DWORD model = GAMEPLAY::GET_HASH_KEY("mp_f_freemode_01");
				STREAMING::REQUEST_MODEL(model);
				while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
				PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
				PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
				WAIT(10);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
			}
		}
		if (Menu::Option("Random Outfit")) { PED::SET_PED_RANDOM_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), true); }
		Menu::MenuOption("Modded Outfits", premadeoutfit);
		Menu::MenuOption("Outfit Creator", OutfitCreator);
	}
	break;
	case premadeoutfit:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Modded Outfits");
		if (genderPos == 0) {
			if (Menu::Option("Outfit 1")) {
				Features::changeClothes("MASK", 38, 0);
				Features::changeClothes("LEGS", 34, 0);
				Features::changeClothes("SPECIAL3", 1, 1);
				Features::changeClothes("TORSO2", 53, 0);
				Features::changeClothes("SHOES", 25, 0);
				Features::changeClothes("SPECIAL2", 129, 0);
			}
			if (Menu::Option("Outfit 2")) {
				Features::changeClothes("LEGS", 34, 0);
				Features::changeClothes("SPECIAL3", 1, 1);
				Features::changeClothes("TORSO2", 53, 0);
				Features::changeClothes("SHOES", 25, 0);
				Features::changeClothes("SPECIAL2", 129, 0);
			}
			if (Menu::Option("Cop 1")) {
				Features::changeClothes("HATS", 47, 0);
				Features::changeClothes("TORSO2", 55, 0);
				Features::changeClothes("LEGS", 35, 0);
				Features::changeClothes("SHOES", 51, 0);
				Features::changeClothes("SPECIAL2", 58, 0);
			}
			if (Menu::Option("Cop 2")) {
				Features::changeClothes("TORSO2", 55, 0);
				Features::changeClothes("LEGS", 35, 0);
				Features::changeClothes("SHOES", 51, 0);
				Features::changeClothes("SPECIAL2", 58, 0);
			}
			if (Menu::Option("Swat")) {
				Features::changeClothes("TORSO", 17, 0);
				Features::changeClothes("MASK", 56, 1);
				Features::changeClothes("HATS", 40, 0);
				Features::changeClothes("HAIR", 0, 0);
				Features::changeClothes("TORSO", 19, 0);
				Features::changeClothes("GLASSES", 0, 1);
				Features::changeClothes("LEGS", 34, 0);
				Features::changeClothes("SHOES", 25, 0);
				Features::changeClothes("SPECIAL", 0, 0);
				Features::changeClothes("SPECIAL2", 58, 0);
				Features::changeClothes("SPECIAL3", 4, 1);
				Features::changeClothes("TORSO2", 55, 0);
				Features::changeClothes("HANDS", 0, 0);
			}
			if (Menu::Option("Ghost")) {
				Features::changeClothes("TORSO", 17, 0);
				Features::changeClothes("MASK", 29, 0);
				Features::changeClothes("HATS", 28, 0);
				Features::changeClothes("HAIR", 0, 0);
				Features::changeClothes("GLASSES", 0, 1);
				Features::changeClothes("LEGS", 31, 0);
				Features::changeClothes("SHOES", 24, 0);
				Features::changeClothes("SPECIAL", 30, 2);
				Features::changeClothes("SPECIAL2", 15, 0);
				Features::changeClothes("TORSO2", 50, 0);
				Features::changeClothes("HANDS", 0, 0);
			}
			if (Menu::Option("Penguin")) {
				Features::changeClothes("TORSO", 0, 0);
				Features::changeClothes("MASK", 31, 0);
				Features::changeClothes("HATS", 0, 0);
				Features::changeClothes("HAIR", 0, 0);
				Features::changeClothes("GLASSES", 0, 0);
				Features::changeClothes("LEGS", 32, 0);
				Features::changeClothes("SHOES", 17, 0);
				Features::changeClothes("SPECIAL1", 0, 0);
				Features::changeClothes("SPECIAL2", 57, 0);
				Features::changeClothes("TEXTURES", 0, 0);
				Features::changeClothes("TORSO2", 51, 0);
				Features::changeClothes("HANDS", 0, 0);
			}
			if (Menu::Option("Pilot")) {
				Features::changeClothes("HATS", 20, 0);
				Features::changeClothes("GLASSES", 6, 0);
				Features::changeClothes("TORSO", 16, 0);
				Features::changeClothes("LEGS", 30, 0);
				Features::changeClothes("HANDS", 39, 4);
				Features::changeClothes("SHOES", 24, 0);
				Features::changeClothes("SPECIAL2", 15, 0);
				Features::changeClothes("TORSO2", 48, 0);
			}
			if (Menu::Option("Splinter")) {
				Features::changeClothes("TORSO", 96, 0);
				Features::changeClothes("MASK", 57, 0);
				Features::changeClothes("HATS", 0, 0);
				Features::changeClothes("HAIR", 23, 0);
				Features::changeClothes("GLASSES", 0, 1);
				Features::changeClothes("LEGS", 31, 0);
				Features::changeClothes("SHOES", 25, 0);
				Features::changeClothes("SPECIAL1", 0, 0);
				Features::changeClothes("SPECIAL2", 58, 0);
				Features::changeClothes("TEXTURES", 3, 0);
				Features::changeClothes("TORSO2", 50, 0);
				Features::changeClothes("HANDS", 0, 0);
			}
			if (Menu::Option("Special 1")) {
				Features::changeClothes("TORSO", 96, 0);
				Features::changeClothes("HATS", 40, 0);
				Features::changeClothes("MASK", 54, 0);
				Features::changeClothes("GLASSES", 0, 1);
				Features::changeClothes("LEGS", 34, 0);
				Features::changeClothes("SHOES", 25, 0);
				Features::changeClothes("SPECIAL1", 0, 0);
				Features::changeClothes("SPECIAL2", 15, 0);
				Features::changeClothes("TORSO2", 53, 0);
				Features::changeClothes("HANDS", 51, 0);
			}
			if (Menu::Option("Special 2")) {
				Features::changeClothes("HATS", 40, 0);
				Features::changeClothes("MASK", 28, 0);
				Features::changeClothes("TORSO", 44, 0);
				Features::changeClothes("LEGS", 34, 0);
				Features::changeClothes("HANDS", 45, 0);
				Features::changeClothes("SHOES", 25, 0);
				Features::changeClothes("SPECIAL2", 56, 1);
				Features::changeClothes("TORSO2", 53, 0);
			}
			if (Menu::Option("Balla")) {
				Features::changeClothes("HATS", 10, 7);
				Features::changeClothes("GLASSES", 17, 6);
				Features::changeClothes("MASK", 51, 6);
				Features::changeClothes("TORSO", 14, 0);
				Features::changeClothes("LEGS", 5, 9);
				Features::changeClothes("SHOES", 9, 5);
				Features::changeClothes("SPECIAL2", 23, 0);
				Features::changeClothes("TORSO2", 7, 9);
			}
			if (Menu::Option("Elf")) {
				Features::changeClothes("MASK", 34, 0);
				Features::changeClothes("TORSO", 4, 0);
				Features::changeClothes("LEGS", 19, 1);
				Features::changeClothes("SHOES", 22, 1);
				Features::changeClothes("SPECIAL1", 18, 0);
				Features::changeClothes("SPECIAL2", 28, 8);
				Features::changeClothes("TORSO2", 19, 1);
			}
			if (Menu::Option("Thug")) {
				Features::changeClothes("HATS", 46, 1);
				Features::changeClothes("GLASSES", 17, 6);
				Features::changeClothes("MASK", 51, 7);
				Features::changeClothes("TORSO", 22, 0);
				Features::changeClothes("LEGS", 7, 0);
				Features::changeClothes("HANDS", 44, 0);
				Features::changeClothes("SHOES", 12, 6);
				Features::changeClothes("SPECIAL2", 15, 0);
				Features::changeClothes("TORSO2", 14, 7);
			}
			if (Menu::Option("Santa")) {
				Features::changeClothes("MASK", 8, 0);
				Features::changeClothes("TORSO", 12, 0);
				Features::changeClothes("LEGS", 19, 0);
				Features::changeClothes("SHOES", 4, 4);
				Features::changeClothes("SPECIAL1", 10, 0);
				Features::changeClothes("SPECIAL2", 21, 2);
				Features::changeClothes("TORSO2", 19, 0);
			}
			if (Menu::Option("Snowman")) {
				Features::changeClothes("MASK", 10, 0);
				Features::changeClothes("TORSO", 12, 0);
				Features::changeClothes("LEGS", 20, 0);
				Features::changeClothes("SHOES", 18, 1);
				Features::changeClothes("SPECIAL1", 24, 2);
				Features::changeClothes("SPECIAL2", 22, 4);
				Features::changeClothes("TORSO2", 25, 7);
			}
			if (Menu::Option("FBI")) {
				Features::changeClothes("SPECIAL1", 125, 0);
				Features::changeClothes("SPECIAL2", 122, 0);
			}
		}
		if (genderPos == 1) {
			if (Menu::Option("Outfit 1")) {
				Features::changeClothes("MASK", 38, 0);
				Features::changeClothes("LEGS", 33, 0);
				Features::changeClothes("SPECIAL3", 1, 1);
				Features::changeClothes("TORSO2", 46, 0);
				Features::changeClothes("SHOES", 24, 0);
				Features::changeClothes("SPECIAL2", 159, 0);
			}
			if (Menu::Option("Outfit 2")) {
				Features::changeClothes("LEGS", 33, 0);
				Features::changeClothes("SPECIAL3", 1, 1);
				Features::changeClothes("TORSO2", 46, 0);
				Features::changeClothes("SHOES", 24, 0);
				Features::changeClothes("SPECIAL2", 159, 0);
			}
			if (Menu::Option("Cop 1")) {
				Features::changeClothes("HATS", 46, 0);
				Features::changeClothes("TORSO2", 48, 0);
				Features::changeClothes("LEGS", 34, 0);
				Features::changeClothes("SHOES", 55, 0);
				Features::changeClothes("SPECIAL2", 35, 0);
			}
			if (Menu::Option("Cop 2")) {
				Features::changeClothes("TORSO2", 48, 0);
				Features::changeClothes("LEGS", 34, 0);
				Features::changeClothes("SHOES", 55, 0);
				Features::changeClothes("SPECIAL2", 35, 0);
			}
			if (Menu::Option("Prison 1")) {
				Features::changeClothes("TORSO2", 4, 14);
				Features::changeClothes("LEGS", 3, 15);
				Features::changeClothes("SHOES", 3, 0);
			}
			if (Menu::Option("Prison 2")) {
				Features::changeClothes("SPECIAL2", 159, 0);
				Features::changeClothes("TORSO2", 4, 14);
				Features::changeClothes("LEGS", 3, 15);
				Features::changeClothes("SHOES", 3, 0);
			}
			if (Menu::Option("Special")) {
				Features::changeClothes("TORSO2", 4, 14);
				Features::changeClothes("LEGS", 3, 41);
				Features::changeClothes("SHOES", 3, 0);
			}
			if (Menu::Option("FBI")) {
				Features::changeClothes("SPECIAL1", 95, 0);
				Features::changeClothes("SPECIAL2", 152, 0);
			}
		}
		/*
		0: HATS
		1: GLASSES
		2: EARS

		0: FACE
		1: MASK
		2: HAIR
		3: TORSO
		4: LEGS
		5: HANDS
		6: SHOES
		7: SPECIAL1
		8: SPECIAL2
		9: SPECIAL3
		10: TEXTURE
		11: TORSO2
		*/
	}
	break;
	case OutfitCreator:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Outfit creator");
		if (Menu::Int("Hats", Face_, 0, 255)) { Features::changeClothes("HATS", Face_, FaceTex_); }
		if (Menu::Int("Hats Texture", FaceTex_, 0, 255)) { Features::changeClothes("HATS", Face_, FaceTex_); }
		if (Menu::Int("Glasses", Glasses_, 0, 255)) { Features::changeClothes("GLASSES", Glasses_, GlassesTex_); }
		if (Menu::Int("Glasses Texture", GlassesTex_, 0, 255)) { Features::changeClothes("GLASSES", Glasses_, GlassesTex_); }
		if (Menu::Int("Ears", Ears_, 0, 255)) { Features::changeClothes("EARS", Ears_, EarsTex_); }
		if (Menu::Int("Ears Texture", EarsTex_, 0, 255)) { Features::changeClothes("EARS", Ears_, EarsTex_); }
		if (Menu::Int("Torso invisible", Torso_, 0, 255)) { Features::changeClothes("TORSO", Torso_, TorsoTex_); }
		if (Menu::Int("Torso invisible Texture", TorsoTex_, 0, 255)) { Features::changeClothes("TORSO", Torso_, TorsoTex_); }
		if (Menu::Int("Torso", Torso2_, 0, 255)) { Features::changeClothes("TORSO2", Torso2_, Torso2Tex_); }
		if (Menu::Int("Torso Texture", Torso2Tex_, 0, 255)) { Features::changeClothes("TORSO2", Torso2_, Torso2Tex_); }
		if (Menu::Int("Legs", Legs_, 0, 255)) { Features::changeClothes("LEGS", Legs_, LegsTex_); }
		if (Menu::Int("Legs Texture", LegsTex_, 0, 255)) { Features::changeClothes("LEGS", Legs_, LegsTex_); }
		if (Menu::Int("Parachutes", Hands_, 0, 255)) { Features::changeClothes("HANDS", Hands_, HandsTex_); }
		if (Menu::Int("Parachutes Texture", HandsTex_, 0, 255)) { Features::changeClothes("HANDS", Hands_, HandsTex_); }
		if (Menu::Int("Shoes", Watches_, 0, 255)) { Features::changeClothes("SHOES", Watches_, WatchesTex_); }
		if (Menu::Int("Shoes Texture", WatchesTex_, 0, 255)) { Features::changeClothes("SHOES", Watches_, WatchesTex_); }
		if (Menu::Int("Special 1", Special1_, 0, 255)) { Features::changeClothes("SPECIAL1", Special1_, Special1Tex_); }
		if (Menu::Int("Special 1 Texture", Special1Tex_, 0, 255)) { Features::changeClothes("SPECIAL1", Special1_, Special1Tex_); }
		if (Menu::Int("Special 2", Special2_, 0, 255)) { Features::changeClothes("SPECIAL2", Special2_, Special2Tex_); }
		if (Menu::Int("Special 2 Texture", Special2Tex_, 0, 255)) { Features::changeClothes("SPECIAL2", Special2_, Special2Tex_); }
		if (Menu::Int("Special 3", Special3_, 0, 255)) { Features::changeClothes("SPECIAL3", Special3_, Special3Tex_); }
		if (Menu::Int("Special 3 Texture", Special3Tex_, 0, 255)) { Features::changeClothes("SPECIAL3", Special3_, Special3Tex_); }
	}
	break;

#pragma endregion

#pragma region recover

	case recoy:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Recovery Options");
		Menu::VipMenuOption("Money", customstealth);
		Menu::MenuOption("Levels", r_levels);
		Menu::MenuOption("Unlocks", r_unlocks);
		Menu::VipMenuOption("Full Stat Editor", extendedstat);
		Menu::VipMenuOption("Bunker Research", bunkerresearch);
		Menu::VipMenuOption("Spoof Stats", spoofer);
	}
	break;
	case spoofer:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Spoof Stats");
		Menu::Toggle("Spoof Level", Features::sp_level);
		Menu::Toggle("Spoof Kills", Features::sp_kills);
		Menu::Toggle("Spoof Deaths", Features::sp_deaths);
	}
	break;
	case bunkerresearch:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Bunker Research");
		if (!Features::rchar) {
			switch (Features::researchId(0)) {
			case 0: Menu::Option("Researching (Char1): APC SAM turret"); break;
			case 1: Menu::Option("Researching (Char1): Ballistic armor"); break;
			case 2: Menu::Option("Researching (Char1): Halftrack quad turret"); break;
			case 3: Menu::Option("Researching (Char1): Tampa Double minigun"); break;
			case 4: Menu::Option("Researching (Char1): Tampa Rear mortar"); break;
			case 5: Menu::Option("Researching (Char1): Tampa missiles"); break;
			case 6: Menu::Option("Researching (Char1): Tampa armor"); break;
			case 7: Menu::Option("Researching (Char1): Buggy grenadelauncher"); break;
			case 8: Menu::Option("Researching (Char1): Buggy minigun"); break;
			case 9: Menu::Option("Researching (Char1): Insurgent minigun"); break;
			case 10: Menu::Option("Researching (Char1): Insurgent armor"); break;
			case 11: Menu::Option("Researching (Char1): Technical minigun"); break;
			case 12: Menu::Option("Researching (Char1): Technical ram bar"); break;
			case 13: Menu::Option("Researching (Char1): Technical brute bar"); break;
			case 14: Menu::Option("Researching (Char1): Technical armor"); break;
			case 15: Menu::Option("Researching (Char1): Oppressor missiles"); break;
			case 16: Menu::Option("Researching (Char1): Fractal camo"); break;
			case 17: Menu::Option("Researching (Char1): Digital camo"); break;
			case 18: Menu::Option("Researching (Char1): Geometric camo"); break;
			case 19: Menu::Option("Researching (Char1): Nature camo"); break;
			case 20: Menu::Option("Researching (Char1): Naval camo"); break;
			case 21: Menu::Option("Researching (Char1): AA-trailer gun"); break;
			case 22: Menu::Option("Researching (Char1): AA-trailer missiles"); break;
			case 23: Menu::Option("Researching (Char1): MOC rear turrets"); break;
			case 24: Menu::Option("Researching (Char1): Incendiary ammo"); break;
			case 25: Menu::Option("Researching (Char1): Hollow point ammo"); break;
			case 26: Menu::Option("Researching (Char1): Armor piercing ammo"); break;
			case 27: Menu::Option("Researching (Char1): Full metal ammo"); break;
			case 28: Menu::Option("Researching (Char1): Explosive ammo"); break;
			case 29: Menu::Option("Researching (Char1): Pistol scope"); break;
			case 30: Menu::Option("Researching (Char1): Pistol compensator"); break;
			case 31: Menu::Option("Researching (Char1): SMG scope"); break;
			case 32: Menu::Option("Researching (Char1): SMG heavy barrel"); break;
			case 33: Menu::Option("Researching (Char1): Sniper nightvision scope"); break;
			case 34: Menu::Option("Researching (Char1): Sniper thermal scope"); break;
			case 35: Menu::Option("Researching (Char1): Sniper heavy barrel"); break;
			case 36: Menu::Option("Researching (Char1): MG scope"); break;
			case 37: Menu::Option("Researching (Char1): MG heavy barrel"); break;
			case 38: Menu::Option("Researching (Char1): Assaultrifle scope"); break;
			case 39: Menu::Option("Researching (Char1): Assaultrifle heavy barrel"); break;
			case 40: Menu::Option("Researching (Char1): Carbine scope"); break;
			case 41: Menu::Option("Researching (Char1): Carbine heavy barrel"); break;
			case 42: Menu::Option("Researching (Char1): Proxymity mines"); break;
			case 43: Menu::Option("Researching (Char1): Brush weaponcamo"); break;
			case 44: Menu::Option("Researching (Char1): Skull weaponcamo"); break;
			case 45: Menu::Option("Researching (Char1): Sessanta weaponcamo"); break;
			case 46: Menu::Option("Researching (Char1): Perseus weaponcamo"); break;
			case 47: Menu::Option("Researching (Char1): Leopard weaponcamo"); break;
			case 48: Menu::Option("Researching (Char1): Zebra weaponcamo"); break;
			case 49: Menu::Option("Researching (Char1): Geometric weaponcamo"); break;
			case 50: Menu::Option("Researching (Char1): Boom weaponcamo"); break;
			}
		}
		else {
			switch (Features::researchId(1)) {
			case 0: Menu::Option("Researching (Char2): APC SAM turret"); break;
			case 1: Menu::Option("Researching (Char2): Ballistic armor"); break;
			case 2: Menu::Option("Researching (Char2): Halftrack quad turret"); break;
			case 3: Menu::Option("Researching (Char2): Tampa Double minigun"); break;
			case 4: Menu::Option("Researching (Char2): Tampa Rear mortar"); break;
			case 5: Menu::Option("Researching (Char2): Tampa missiles"); break;
			case 6: Menu::Option("Researching (Char2): Tampa armor"); break;
			case 7: Menu::Option("Researching (Char2): Buggy grenadelauncher"); break;
			case 8: Menu::Option("Researching (Char2): Buggy minigun"); break;
			case 9: Menu::Option("Researching (Char2): Insurgent minigun"); break;
			case 10: Menu::Option("Researching (Char2): Insurgent armor"); break;
			case 11: Menu::Option("Researching (Char2): Technical minigun"); break;
			case 12: Menu::Option("Researching (Char2): Technical ram bar"); break;
			case 13: Menu::Option("Researching (Char2): Technical brute bar"); break;
			case 14: Menu::Option("Researching (Char2): Technical armor"); break;
			case 15: Menu::Option("Researching (Char2): Oppressor missiles"); break;
			case 16: Menu::Option("Researching (Char2): Fractal camo"); break;
			case 17: Menu::Option("Researching (Char2): Digital camo"); break;
			case 18: Menu::Option("Researching (Char2): Geometric camo"); break;
			case 19: Menu::Option("Researching (Char2): Nature camo"); break;
			case 20: Menu::Option("Researching (Char2): Naval camo"); break;
			case 21: Menu::Option("Researching (Char2): AA-trailer gun"); break;
			case 22: Menu::Option("Researching (Char2): AA-trailer missiles"); break;
			case 23: Menu::Option("Researching (Char2): MOC rear turrets"); break;
			case 24: Menu::Option("Researching (Char2): Incendiary ammo"); break;
			case 25: Menu::Option("Researching (Char2): Hollow point ammo"); break;
			case 26: Menu::Option("Researching (Char2): Armor piercing ammo"); break;
			case 27: Menu::Option("Researching (Char2): Full metal ammo"); break;
			case 28: Menu::Option("Researching (Char2): Explosive ammo"); break;
			case 29: Menu::Option("Researching (Char2): Pistol scope"); break;
			case 30: Menu::Option("Researching (Char2): Pistol compensator"); break;
			case 31: Menu::Option("Researching (Char2): SMG scope"); break;
			case 32: Menu::Option("Researching (Char2): SMG heavy barrel"); break;
			case 33: Menu::Option("Researching (Char2): Sniper nightvision scope"); break;
			case 34: Menu::Option("Researching (Char2): Sniper thermal scope"); break;
			case 35: Menu::Option("Researching (Char2): Sniper heavy barrel"); break;
			case 36: Menu::Option("Researching (Char2): MG scope"); break;
			case 37: Menu::Option("Researching (Char2): MG heavy barrel"); break;
			case 38: Menu::Option("Researching (Char2): Assaultrifle scope"); break;
			case 39: Menu::Option("Researching (Char2): Assaultrifle heavy barrel"); break;
			case 40: Menu::Option("Researching (Char2): Carbine scope"); break;
			case 41: Menu::Option("Researching (Char2): Carbine heavy barrel"); break;
			case 42: Menu::Option("Researching (Char2): Proxymity mines"); break;
			case 43: Menu::Option("Researching (Char2): Brush weaponcamo"); break;
			case 44: Menu::Option("Researching (Char2): Skull weaponcamo"); break;
			case 45: Menu::Option("Researching (Char2): Sessanta weaponcamo"); break;
			case 46: Menu::Option("Researching (Char2): Perseus weaponcamo"); break;
			case 47: Menu::Option("Researching (Char2): Leopard weaponcamo"); break;
			case 48: Menu::Option("Researching (Char2): Zebra weaponcamo"); break;
			case 49: Menu::Option("Researching (Char2): Geometric weaponcamo"); break;
			case 50: Menu::Option("Researching (Char2): Boom weaponcamo"); break;
			}
		}
		if (Menu::Option("APC SAM turret")) { Features::research(0); }
		if (Menu::Option("Ballistic armor")) { Features::research(1); }
		if (Menu::Option("Halftrack quad turret")) { Features::research(2); }
		if (Menu::Option("Tampa Double minigun")) { Features::research(3); }
		if (Menu::Option("Tampa Rear mortar")) { Features::research(4); }
		if (Menu::Option("Tampa missiles")) { Features::research(5); }
		if (Menu::Option("Tampa armor")) { Features::research(6); }
		if (Menu::Option("Buggy grenadelauncher")) { Features::research(7); }
		if (Menu::Option("Buggy minigun")) { Features::research(8); }
		if (Menu::Option("Insurgent minigun")) { Features::research(9); }
		if (Menu::Option("Insurgent armor")) { Features::research(10); }
		if (Menu::Option("Technical minigun")) { Features::research(11); }
		if (Menu::Option("Technical ram bar")) { Features::research(12); }
		if (Menu::Option("Technical brute bar")) { Features::research(13); }
		if (Menu::Option("Technical armor")) { Features::research(14); }
		if (Menu::Option("Oppressor missiles")) { Features::research(15); }
	}
	break;
	case extendedstat:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Full Stat Editor");
		for (int i = 0; i < sizeof(TunableList) / sizeof(*TunableList); i++) {

			switch (TunableList[i].type) {
			case 0:
			{
				static int tunableValue = TUNABLE::NETWORK_GET_TUNABLE<int>(TunableList[i].index);
				if (Menu::Int(TunableList[i].label, tunableValue, -1, INT_MAX)) { TUNABLE::NETWORK_SET_TUNABLE<int>(TunableList[i].index, tunableValue); }
			}
			break;
			case 1:
			{
				static float tunableValue = TUNABLE::NETWORK_GET_TUNABLE<float>(TunableList[i].index);
				if (Menu::Float(TunableList[i].label, tunableValue, -1.f, 999999.f, 0.1f)) { TUNABLE::NETWORK_SET_TUNABLE<float>(TunableList[i].index, tunableValue); }
			}
			break;
			case 2:
			{
				static bool tunableValue = TUNABLE::NETWORK_GET_TUNABLE<bool>(TunableList[i].index);
				if (Menu::Toggle(TunableList[i].label, tunableValue)) { TUNABLE::NETWORK_SET_TUNABLE<bool>(TunableList[i].index, tunableValue); }
			}
			break;
			}

		}
	}
	break;
	case customstealth:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Custom Stealth");
		Menu::Int("Amount", Features::stealthAmount, 100000, 10000000, 100000);
		Menu::Toggle("Remove Money", Features::removee);
		Menu::Toggle("Stealth Loop", Features::stealthBool, [] { Features::stealthLoop(Features::stealthBool); });
		if (Menu::Option("Stealth")) {
			Features::stealthMoney(Features::stealthAmount);
		}
	}
	break;
	case r_levels:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Level Options");
		Menu::Toggle("RP Loop", Features::RPLoop, [] { Features::rpLoop(); });
		if (Menu::Option("Input Level"))
		{
			int result = NumberKeyboard();
			Features::SetRank(result);
			//notifyMap("New level set! Change lobby to apply it!");

		}
		if (Menu::Option("Rank 1")) {
			Features::SetRank(1);
		}
		if (Menu::Option("Rank 10")) {
			Features::SetRank(10);
		}
		if (Menu::Option("Rank 50")) {
			Features::SetRank(50);
		}
		if (Menu::Option("Rank 100")) {
			Features::SetRank(100);
		}
		if (Menu::Option("Rank 200")) {
			Features::SetRank(200);
		}
		if (Menu::Option("Rank 300")) {
			Features::SetRank(300);
		}
		if (Menu::Option("Rank 500")) {
			Features::SetRank(500);
		}
		if (Menu::Option("Rank 1000")) {
			Features::SetRank(1000);
		}
		if (Menu::Option("Rank 2000")) {
			Features::SetRank(2000);
		}
		if (Menu::Option("Rank 3000")) {
			Features::SetRank(3000);
		}
		if (Menu::Option("Rank 4000")) {
			Features::SetRank(4000);
		}
		if (Menu::Option("Rank 5000")) {
			Features::SetRank(5000);
		}
		if (Menu::Option("Rank 6000")) {
			Features::SetRank(6000);
		}
		if (Menu::Option("Rank 7000")) {
			Features::SetRank(7000);
		}
		if (Menu::Option("Rank 8000")) {
			Features::SetRank(8000);
		}
	}
	break;
	case r_unlocks:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Unlock Options");
		if (Menu::Option("Max Skills")) {
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STAM"), 100, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_SCRIPT_INCREASE_LUNG"), 100, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_SCRIPT_INCREASE_DRIV"), 100, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_SCRIPT_INCREASE_FLY"), 100, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_SCRIPT_INCREASE_SHO"), 100, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STL"), 100, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_script_increase_stam"), 100, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_script_increase_strn"), 100, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_script_increase_lung"), 100, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_script_increase_driv"), 100, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_script_increase_fly"), 100, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_script_increase_sho"), 100, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_script_increase_stl"), 100, 1);

			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STAM"), 100, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STRN"), 100, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_LUNG"), 100, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_DRIV"), 100, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_FLY"), 100, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_SHO"), 100, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STL"), 100, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_script_increase_stam"), 100, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_script_increase_strn"), 100, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_script_increase_lung"), 100, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_script_increase_driv"), 100, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_script_increase_fly"), 100, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_script_increase_sho"), 100, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("M00_script_increase_stl"), 100, 1);
		}
		if (Menu::Option("Unlock LSC Parts")) {
			STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_ENEMYDRIVEBYKILLS"), 600, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_USJS_COMPLETED"), 50, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_USJS_FOUND"), 50, 0);
			STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINALLRACEMODES"), 1, 0);
			STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DB_PLAYER_KILLS"), 1000, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_KILLS_PLAYERS"), 1000, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMHORDWAVESSURVIVE"), 21, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_MVP"), 60, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_HOLD_UP_SHOPS"), 20, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_RACES_WON"), 101, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_NO_ARMWRESTLING_WINS"), 21, 0);
			STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMATTGANGHQ"), 1, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMBBETWIN"), 50000, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 51, 0);
			STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMFULLYMODDEDCAR"), 1, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_TOTALKILLS"), 500, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_DM_TOTAL_DEATHS"), 412, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PLAYER_HEADSHOTS"), 623, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 63, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_WINS"), 13, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GTA_RACES_WON"), 12, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GOLF_WON"), 2, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_TG_WON"), 2, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_RT_WON"), 2, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_CT_WON"), 2, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_GRAN_WON"), 2, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TENNIS_WON"), 2, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TENNIS_MATCHES_WON"), 2, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_WON"), 101, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_LOST"), 36, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_25_KILLS_STICKYBOMBS"), 50, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_50_KILLS_GRENADES"), 50, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS "), 50, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_20_KILLS_MELEE"), 50, 0);
		}
		if (Menu::Option("Unlock Chrome Rims"))
		{
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_WIN_CAPTURES"), 25, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_DROPOFF_CAP_PACKAGES"), 100, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_KILL_CARRIER_CAPTURE"), 100, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FINISH_HEISTS"), 50, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FINISH_HEIST_SETUP_JOB"), 50, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_NIGHTVISION_KILLS, 100"), 1, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_WIN_LAST_TEAM_STANDINGS"), 50, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_ONLY_PLAYER_ALIVE_LTS"), 50, 1);
		}
		if (Menu::VipOption("Unlock office money")) {
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_LIFETIME_BUY_COMPLETE"), 1223, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_LIFETIME_BUY_UNDERTAKEN"), 1223, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_LIFETIME_SELL_COMPLETE"), 434, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_LIFETIME_SELL_UNDERTAKEN"), 434, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_LIFETIME_CONTRA_EARNINGS"), 1220000000, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_LIFETIME_BUY_COMPLETE"), 1223, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_LIFETIME_BUY_UNDERTAKEN"), 1223, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_LIFETIME_SELL_COMPLETE"), 434, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_LIFETIME_SELL_UNDERTAKEN"), 434, 0);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_LIFETIME_CONTRA_EARNINGS"), 1220000000, 0);
		}
		if (Menu::Option("Clear badsport")) {
			STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MPPLY_OVERALL_BADSPORT"), 0.0f, TRUE);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_DESTROYED_PVEHICLES"), 0, TRUE);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_BADSPORT_MESSAGE"), 0, TRUE);
		}
		if (Menu::Option("Unlock Exclusive Stuff")) {
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_VEHICLE_1_UNLCK"), -1, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_VEHICLE_2_UNLCK"), -1, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_FM_VEHICLE_1_UNLCK"), -1, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_FM_VEHICLE_2_UNLCK"), -1, 1);
		}
		if (Menu::Option("Unlock UFO Mission")) {
			Features::unlockSpecialMission();
		}
		if (Menu::Option("Enable Roosevelt in Phone")) {
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VEHICLE_ID_ADMIN_WEB"), 117401876, 1);
		}
		if (Menu::VipOption("Redesign Character")) {
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FM_CHANGECHAR_ASKED"), 0, 1);
			STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_FM_CHANGECHAR_ASKED"), 0, 1);
		}
	}
	break;

#pragma endregion

#pragma region long_stuff_2

#pragma region mapmodz
	case mapmods:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Map mods");
		Menu::MenuOption("Maze Bank Small Ramp", ramp1);
		Menu::MenuOption("Maze Bank Roof Ramp", ramp2);
		Menu::MenuOption("Beach Ramp", ramp3);
		Menu::MenuOption("Mount Chilliad Ramp", ramp4);
		Menu::MenuOption("Airport Mini Ramp", ramp5);
		Menu::MenuOption("Airport Gate Ramp", ramp6);
		Menu::MenuOption("Space Tower", ramp7);
		Menu::MenuOption("Exploit Quad Ramp", ramp8);
		Menu::MenuOption("Exploit Fort", ramp9);
		Menu::MenuOption("Halfpipe", ramp10);
		Menu::MenuOption("Airport Loop Ramp", ramp11);
		Menu::MenuOption("Mega Ramp", ramp12);
	}
	break;
	case ramp1:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(" ");
		if (Menu::Option("Load")) {
			mapmod1();
		}
		if (Menu::Option("Teleport")) {
			ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -74.94243f, -818.63446f, 326.174347f, 1, 0, 0, 1);
		}
		break;
	case ramp2:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(" ");
		if (Menu::Option("Load")) {
			mapmod2();
		}
		if (Menu::Option("Teleport")) {
			ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -74.94243f, -818.63446f, 326.174347f, 1, 0, 0, 1);
		}
		break;
	case ramp3:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(" ");
		if (Menu::Option("Load")) {
			mapmod3();
		}
		if (Menu::Option("Teleport")) {
			ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1513.0f, -1192.0f, 1.0f, 1, 0, 0, 1);
		}
		break;
	case ramp4:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(" ");
		if (Menu::Option("Load")) {
			mapmod4();
		}
		if (Menu::Option("Teleport")) {
			ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 500, 5593, 795, 1, 0, 0, 1);
		}
		break;
	case ramp5:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(" ");
		if (Menu::Option("Load")) {
			mapmod5();
		}
		if (Menu::Option("Teleport")) {
			ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1208, -2950, 13, 1, 0, 0, 1);
		}
		break;
	case ramp6:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(" ");
		if (Menu::Option("Load")) {
			mapmod6();
		}
		if (Menu::Option("Teleport")) {
			ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1046, -2538, 20, 1, 0, 0, 1);
		}
		break;
	case ramp7:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(" ");
		if (Menu::Option("Load")) {
			mapmod7();
		}
		if (Menu::Option("Teleport")) {
			ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 70, -674, 680, 1, 0, 0, 1);
		}
		break;
	case ramp8:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(" ");
		if (Menu::Option("Load")) {
			mapmod8();
		}
		if (Menu::Option("Teleport")) {
			ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -74.94243f, -818.63446f, 326.174347f, 1, 0, 0, 1);
		}
		break;
	case ramp9:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(" ");
		if (Menu::Option("Load")) {
			mapmod9();
		}
		if (Menu::Option("Teleport")) {
			ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -2731, 3259, 32, 1, 0, 0, 1);
		}
		break;
	case ramp10:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(" ");
		if (Menu::Option("Load")) {
			mapmod10();
		}
		if (Menu::Option("Teleport")) {
			ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1003, -2916, 14, 1, 0, 0, 1);
		}
		break;
	case ramp11:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(" ");
		if (Menu::Option("Load")) {
			mapmod11();
		}
		if (Menu::Option("Teleport")) {
			ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1074, -3201, 13, 1, 0, 0, 1);
		}
		break;
	case ramp12:
		Menu::Title(Menu::Settings::menuname);
		Menu::Break(" ");
		if (Menu::Option("Load")) {
			mapmod12();
		}
		if (Menu::Option("Teleport")) {
			ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -74.94243f, -818.63446f, 326.174347f, 1, 0, 0, 1);
		}
		break;
#pragma endregion

#pragma endregion

#pragma region Settings Menu
	case settings:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Settings");
		Menu::MenuOption("Info", settings_sysinfo);
		Menu::MenuOption("Themes", themeloader);
		Menu::MenuOption("Control", control_settings);
		Menu::MenuOption("Colors", settingskek);
		Menu::Toggle("Show Globe", Menu::Settings::showGlobe);
		Menu::Toggle("Show Instructions", Features::show_tips);
		if (Menu::Option("Save Theme")) {
			Features::saveToINI();
			INI::WriteBool("X-Folder/title/config.ini", display_when_open, "display", "close");
			INI::WriteBool("X-Folder/title/config.ini", reportdisplay, "display", "d_report");
			INI::WriteBool("X-Folder/title/config.ini", ipdisplay, "display", "d_ip");
			INI::WriteBool("X-Folder/title/config.ini", Menu::Settings::selfInfo, "display", "d_info");
		}
		if (Menu::Option("Load Theme")) {
			menyooX = INI::GetFloat("X-Folder/title/config.ini", "theme", "menux") * 100;
			widthkek = INI::GetFloat("X-Folder/title/config.ini", "theme", "menuw") * 100;
			smooth_scroll_kek = INI::GetFloat("X-Folder/title/config.ini", "delay", "smooth") * 1000;
			display_when_open = INI::GetBool("X-Folder/title/config.ini", "display", "close");
			reportdisplay = INI::GetBool("X-Folder/title/config.ini", "display", "d_report");
			ipdisplay = INI::GetBool("X-Folder/title/config.ini", "display", "d_ip");
			Menu::Settings::selfInfo = INI::GetBool("X-Folder/title/config.ini", "display", "d_info");
			Features::loadFromINI();
		}
		Menu::Int("Menu X", menyooX, 17, 81);
		Menu::Int("Menu Y", menyooY, 0, 30);
		Menu::Int("Menu Width", widthkek, 11, 50);
		Menu::Settings::menuWidth = (float)widthkek / 100;
		Menu::Settings::scrollbarWidthIndex = (float)(Menu::Settings::menuWidth / 2) + 0.015f;
		Menu::Settings::menuY = (float)(menyooY - 4) / 100;
		Menu::Settings::menuX = (float)menyooX / 100;
		Menu::Settings::GlareX = (Menu::Settings::menuX - 0.17f) + 0.5050f;
	}
	break;
	case control_settings:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Control Settings");
		if (Menu::Option("Set Open Key")) {
			Menu::setOpenKey();
		}
		if (Menu::Int("Scroll Delay", Menu::Settings::keyPressDelay2, 1, 200))
		{
			if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
				//Menu::Settings::keyPressDelay2 = NumberKeyboard();
			}
		}
		Menu::Int("Smooth Scroll Delay", smooth_scroll_kek, 1, 200);
		Menu::Settings::ScrollerSpeed = (float)smooth_scroll_kek / 1000;
		Menu::Toggle("Smooth Scroller", Menu::Settings::enable_smooth);
	}
	break;
	case settings_sysinfo:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Info");
		std::string nogNig(player_name);
		std::string nagger = "Socialclub Account: " + nogNig;
		std::string nigNog(PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID()));
		std::string nigger = "Player Name: " + nigNog;
		std::string nibNob(UNK3::_GET_ONLINE_VERSION());
		std::string nibba = "Game Version: " + nibNob;
		std::string ficker(menu_version_);
		std::string fucker = "Menu Version: " + ficker;
		Menu::Option(nigger.c_str());
		//Menu::Option(nagger.c_str());
		Menu::Option(nibba.c_str());
		GetModuleHandleA("steam_api64.dll") ? Menu::Option("Game Type: Steam") : Menu::Option("Game Type: Rockstar");
		Menu::Option(fucker.c_str());
		Hooking::found_idp ? Menu::Option("IDP Hook: Active") : Menu::Option("IDP Hook: Inactive");
		Hooking::found_dce ? Menu::Option("DCE Hook: Active") : Menu::Option("DCE Hook: Inactive");
		Hooking::found_ssi ? Menu::Option("SSI Hook: Active") : Menu::Option("SSI Hook: Inactive");
		Hooking::found_sge ? Menu::Option("SGE Hook: Active") : Menu::Option("SGE Hook: Inactive");
		Hooking::found_gcm ? Menu::Option("GCT Hook: Active") : Menu::Option("GCM Hook: Inactive");
		Hooking::found_glt ? Menu::Option("GLT Hook: Active") : Menu::Option("GLT Hook: Inactive");
		Hooking::found_gsh ? Menu::Option("GSH Hook: Active") : Menu::Option("GSH Hook: Inactive");
		Hooking::found_ged ? Menu::Option("GED Hook: Active") : Menu::Option("GED Hook: Inactive");
		Hooking::found_nts ? Menu::Option("NTV Hook: Active") : Menu::Option("NTV Hook: Inactive");
		Hooking::found_prw ? Menu::Option("PRW Hook: Active") : Menu::Option("PRW Hook: Inactive");
	}
	break;
	case settingskek:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Colors");
		Menu::MenuOption("Selection Box", settingsscroller);
		Menu::MenuOption("Option Text", settingsoptiontext);
		Menu::MenuOption("Info Title", settingsinfocolor);
	}
	break;
	case settingsmenuend:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Menu End");
		if (Menu::Option("X-Force")) {
			Menu::Settings::menuend = "menuend_x";
		}
		if (Menu::Option("d3sk1ng")) {
			Menu::Settings::menuend = "menuend_desking";
		}
		if (Menu::Option("Weed")) {
			Menu::Settings::menuend = "menuend_weed";
		}
		if (Menu::Option("Arrows")) {
			Menu::Settings::menuend = "menuend_arrows";
		}
		if (Menu::Option("Evolve")) {
			Menu::Settings::menuend = "menuend_evolve";
		}
		if (Menu::Option("Kaese")) {
			Menu::Settings::menuend = "menuend_kaese";
		}
		if (Menu::Option("Russia")) {
			Menu::Settings::menuend = "menuend_russia";
		}
	}
	break;
	case menutoggles:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Toggle Settings");
		if (Menu::Option("Tick")) {
			Menu::Settings::toggleYTD = "commonmenu";
			Menu::Settings::toggleON = "shop_box_tick";
			Menu::Settings::toggleOFF = "shop_box_blank";
		}
		if (Menu::Option("Ammo")) {
			Menu::Settings::toggleYTD = "commonmenu";
			Menu::Settings::toggleON = "shop_ammo_icon_a";
			Menu::Settings::toggleOFF = "shop_ammo_icon_b";
		}
		if (Menu::Option("Cross")) {
			Menu::Settings::toggleYTD = "commonmenu";
			Menu::Settings::toggleON = "shop_box_cross";
			Menu::Settings::toggleOFF = "shop_box_blank";
		}
		if (Menu::Option("Switch")) {
			Menu::Settings::toggleYTD = "customheader";
			Menu::Settings::toggleON = "toggle_on4";
			Menu::Settings::toggleOFF = "toggle_off4";
		}
		if (Menu::Option("Tick and Cross")) {
			Menu::Settings::toggleYTD = "commonmenu";
			Menu::Settings::toggleON = "shop_box_tick";
			Menu::Settings::toggleOFF = "shop_box_cross";
		}
	}
	break;
	case settingsinfocolor:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Info title");
		if (Menu::Int("Red", Menu::Settings::infocolor.r, 0, 255))
		{
			if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
				Menu::Settings::infocolor.r = NumberKeyboard();
			}
		}
		if (Menu::Int("Green", Menu::Settings::infocolor.g, 0, 255))
		{
			if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
				Menu::Settings::infocolor.g = NumberKeyboard();
			}
		}
		if (Menu::Int("Blue", Menu::Settings::infocolor.b, 0, 255))
		{
			if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
				Menu::Settings::infocolor.b = NumberKeyboard();
			}
		}
		if (Menu::Int("Opacity", Menu::Settings::infocolor.a, 0, 255))
		{
			if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
				Menu::Settings::infocolor.a = NumberKeyboard();
			}
		}
	}
	break;
	case themeloader:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Themes");
		Menu::VipMenuOption("Custom Header", i_like_seys);
		if (Menu::Option("Black 1")) {
			Menu::Settings::menuname = "";
			Menu::Settings::ytdtheme = "xforce1";
			Menu::Settings::scroller = { 0, 0, 0, 255 };
			Menu::Settings::infocolor = { 0, 0, 0, 255 };
			Menu::Settings::menuend = "menuend_x";
			Menu::Settings::showGlobe = true;
			Menu::Settings::lightning = false;
			Menu::Settings::evolve = false;
			Menu::Settings::phantom = false;
			Menu::Settings::city = false;
		}
		if (Menu::Option("Black 2")) {
			Menu::Settings::menuname = "";
			Menu::Settings::ytdtheme = "xforce2";
			Menu::Settings::scroller = { 0, 0, 0, 255 };
			Menu::Settings::infocolor = { 0, 0, 0, 255 };
			Menu::Settings::menuend = "menuend_x";
			Menu::Settings::showGlobe = true;
			Menu::Settings::lightning = false;
			Menu::Settings::evolve = false;
			Menu::Settings::phantom = false;
			Menu::Settings::city = false;
		}
		if (Menu::Option("Skyline")) {
			Menu::Settings::menuname = "";
			Menu::Settings::ytdtheme = "lightning_un";
			Menu::Settings::scroller = { 0, 0, 20, 255 };
			Menu::Settings::infocolor = { 0, 0, 20, 255 };
			Menu::Settings::menuend = "menuend_x";
			Menu::Settings::showGlobe = false;
			Menu::Settings::lightning = false;
			Menu::Settings::evolve = false;
			Menu::Settings::phantom = false;
			Menu::Settings::city = false;
		}
		if (Menu::Option("Forest 1")) {
			Menu::Settings::menuname = "";
			Menu::Settings::ytdtheme = "Xforceheader001";
			Menu::Settings::scroller = { 102, 153, 153, 255 };
			Menu::Settings::infocolor = { 102, 153, 153, 255 };
			Menu::Settings::menuend = "menuend_x";
			Menu::Settings::showGlobe = false;
			Menu::Settings::lightning = false;
			Menu::Settings::evolve = false;
			Menu::Settings::phantom = true;
			Menu::Settings::city = false;
		}
		if (Menu::Option("Forest 2")) {
			Menu::Settings::menuname = "";
			Menu::Settings::ytdtheme = "forest";
			Menu::Settings::scroller = { 102, 153, 153, 255 };
			Menu::Settings::infocolor = { 102, 153, 153, 255 };
			Menu::Settings::menuend = "menuend_x";
			Menu::Settings::showGlobe = false;
			Menu::Settings::lightning = false;
			Menu::Settings::evolve = false;
			Menu::Settings::phantom = false;
			Menu::Settings::city = false;
		}
		if (Menu::Option("3D")) {
			Menu::Settings::menuname = "";
			Menu::Settings::ytdtheme = "xforce3d";
			Menu::Settings::scroller = { 96, 0, 134, 255 };
			Menu::Settings::infocolor = { 96, 0, 134, 255 };
			Menu::Settings::menuend = "menuend_x";
			Menu::Settings::showGlobe = true;
			Menu::Settings::lightning = false;
			Menu::Settings::evolve = false;
			Menu::Settings::phantom = false;
			Menu::Settings::city = false;
		}
		if (Menu::Option("Evolve")) {
			Menu::Settings::menuname = "";
			Menu::Settings::ytdtheme = "eforce1";
			Menu::Settings::scroller = { 255, 0, 0, 255 };
			Menu::Settings::infocolor = { 255, 0, 0, 255 };
			Menu::Settings::menuend = "menuend_x";
			Menu::Settings::showGlobe = false;
			Menu::Settings::lightning = false;
			Menu::Settings::evolve = true;
			Menu::Settings::phantom = false;
			Menu::Settings::city = false;
		}
		if (Menu::Option("Profit")) {
			Menu::Settings::menuname = "";
			Menu::Settings::ytdtheme = "profit";
			Menu::Settings::scroller = { 0, 0, 0, 255 };
			Menu::Settings::infocolor = { 0, 0, 0, 255 };
			Menu::Settings::menuend = "menuend_x";
			Menu::Settings::showGlobe = false;
			Menu::Settings::lightning = false;
			Menu::Settings::evolve = false;
			Menu::Settings::phantom = false;
			Menu::Settings::city = false;
		}
		if (Menu::Option("Anime 1")) {
			Menu::Settings::menuname = "";
			Menu::Settings::ytdtheme = "anime1";
			Menu::Settings::scroller = { 255, 102, 255, 255 };
			Menu::Settings::infocolor = { 255, 102, 255, 255 };
			Menu::Settings::menuend = "menuend_x";
			Menu::Settings::showGlobe = false;
			Menu::Settings::lightning = false;
			Menu::Settings::evolve = false;
			Menu::Settings::phantom = false;
			Menu::Settings::city = false;
		}
		if (Menu::Option("Anime 2")) {
			Menu::Settings::menuname = "";
			Menu::Settings::ytdtheme = "anime2";
			Menu::Settings::scroller = { 255, 102, 255, 255 };
			Menu::Settings::infocolor = { 255, 102, 255, 255 };
			Menu::Settings::menuend = "menuend_x";
			Menu::Settings::showGlobe = false;
			Menu::Settings::lightning = false;
			Menu::Settings::evolve = false;
			Menu::Settings::phantom = false;
			Menu::Settings::city = false;
		}
		if (Menu::Option("Anime 3")) {
			Menu::Settings::menuname = "";
			Menu::Settings::ytdtheme = "anime3";
			Menu::Settings::scroller = { 255, 102, 255, 255 };
			Menu::Settings::infocolor = { 255, 102, 255, 255 };
			Menu::Settings::menuend = "menuend_x";
			Menu::Settings::showGlobe = false;
			Menu::Settings::lightning = false;
			Menu::Settings::evolve = false;
			Menu::Settings::phantom = false;
			Menu::Settings::city = false;
		}
		if (Menu::Option("Hackerman")) {
			Menu::Settings::menuname = "";
			Menu::Settings::ytdtheme = "hackerman";
			Menu::Settings::scroller = { 153, 51, 255, 255 };
			Menu::Settings::infocolor = { 153, 51, 255, 255 };
			Menu::Settings::menuend = "menuend_x";
			Menu::Settings::showGlobe = true;
			Menu::Settings::lightning = false;
			Menu::Settings::evolve = false;
			Menu::Settings::phantom = false;
			Menu::Settings::city = false;
		}
		if (Menu::Option("Skull")) {
			Menu::Settings::menuname = "";
			Menu::Settings::ytdtheme = "skull";
			Menu::Settings::scroller = { 0, 25, 51, 255 };
			Menu::Settings::infocolor = { 0, 25, 51, 255 };
			Menu::Settings::menuend = "menuend_x";
			Menu::Settings::showGlobe = true;
			Menu::Settings::lightning = false;
			Menu::Settings::evolve = false;
			Menu::Settings::phantom = false;
			Menu::Settings::city = false;
		}
		if (Menu::Option("City")) {
			Menu::Settings::menuname = "";
			Menu::Settings::ytdtheme = "city1";
			Menu::Settings::scroller = { 0, 102, 255, 255 };
			Menu::Settings::infocolor = { 0, 102, 255, 255 };
			Menu::Settings::menuend = "menuend_x";
			Menu::Settings::showGlobe = false;
			Menu::Settings::lightning = false;
			Menu::Settings::evolve = false;
			Menu::Settings::phantom = false;
			Menu::Settings::city = true;
		}
	}
	break;
	case i_like_seys:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Custom Header");
		Menu::Toggle("Enable custom Header", Menu::Settings::c_enable);
		/*if (Menu::Option("Header File")) {
			Menu::Settings::c_name = CharKeyboard();
		}*/
		if (Menu::Option("Header Image")) {
			Menu::Settings::c_pict = CharKeyboard();
		}
		Menu::Toggle("Animated Header", Menu::Settings::c_animation);
		Menu::Int("Frames", Menu::Settings::c_frames, 0, 150);
		if (Menu::Option("Header Text")) {
			Menu::Settings::menuname = CharKeyboard();
		}
		Menu::Toggle("Globe", Menu::Settings::showGlobe);
		Menu::Int("Scroller Red", Menu::Settings::scroller.r, 0, 255);
		Menu::Int("Scroller Green", Menu::Settings::scroller.g, 0, 255);
		Menu::Int("Scroller Blue", Menu::Settings::scroller.b, 0, 255);
		Menu::Int("Scroller Opacity", Menu::Settings::scroller.a, 0, 255);
		Menu::Int("Info Red", Menu::Settings::infocolor.r, 0, 255);
		Menu::Int("Info Green", Menu::Settings::infocolor.g, 0, 255);
		Menu::Int("Info Blue", Menu::Settings::infocolor.b, 0, 255);
		Menu::Int("Info Opacity", Menu::Settings::infocolor.a, 0, 255);
	}
	break;
	case settingstitlerect:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Title Rect");
		if (Menu::Int("Red", Menu::Settings::titleRect.r, 0, 255))
		{
			if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
				Menu::Settings::titleRect.r = NumberKeyboard();
			}
		}
		if (Menu::Int("Green", Menu::Settings::titleRect.g, 0, 255))
		{
			if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
				Menu::Settings::titleRect.g = NumberKeyboard();
			}
		}
		if (Menu::Int("Blue", Menu::Settings::titleRect.b, 0, 255))
		{
			if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
				Menu::Settings::titleRect.b = NumberKeyboard();
			}
		}
		if (Menu::Int("Opacity", Menu::Settings::titleRect.a, 0, 255))
		{
			if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
				Menu::Settings::titleRect.a = NumberKeyboard();
			}
		}
	}
	break;
	case settingsoptiontext:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Option Text");
		if (Menu::Int("Red", Menu::Settings::optionText.r, 0, 255))
		{
			if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
				Menu::Settings::optionText.r = NumberKeyboard();
			}
		}
		if (Menu::Int("Green", Menu::Settings::optionText.g, 0, 255))
		{
			if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
				Menu::Settings::optionText.g = NumberKeyboard();
			}
		}
		if (Menu::Int("Blue", Menu::Settings::optionText.b, 0, 255))
		{
			if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
				Menu::Settings::optionText.b = NumberKeyboard();
			}
		}
		if (Menu::Int("Opacity", Menu::Settings::optionText.a, 0, 255))
		{
			if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
				Menu::Settings::optionText.a = NumberKeyboard();
			}
		}
		//Menu::MenuOption("Font", font);
	}
	break;
	/*case font:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Font");
		if (Menu::Option("Chalet London")) { Menu::Settings::optionText.f = 0; }
		if (Menu::Option("House Script")) { Menu::Settings::optionText.f = 1; }
		if (Menu::Option("Monospace")) { Menu::Settings::optionText.f = 2; }
		if (Menu::Option("Wing Dings")) { Menu::Settings::optionText.f = 3; }
		if (Menu::Option("Chalet Comprime Cologne")) { Menu::Settings::optionText.f = 4; }
		if (Menu::Option("Pricedown")) { Menu::Settings::optionText.f = 7; }
	}
	break;*/
	case settingsscroller:
	{
		Menu::Title(Menu::Settings::menuname);
		Menu::Break("Scroller");
		if (Menu::Int("Red", Menu::Settings::scroller.r, 0, 255))
		{
			if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
				Menu::Settings::scroller.r = NumberKeyboard();
			}
		}
		if (Menu::Int("Green", Menu::Settings::scroller.g, 0, 255))
		{
			if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
				Menu::Settings::scroller.g = NumberKeyboard();
			}
		}
		if (Menu::Int("Blue", Menu::Settings::scroller.b, 0, 255))
		{
			if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
				Menu::Settings::scroller.b = NumberKeyboard();
			}
		}
		if (Menu::Int("Opacity", Menu::Settings::scroller.a, 0, 255))
		{
			if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
				Menu::Settings::scroller.a = NumberKeyboard();
			}
		}
	}
	break;
#pragma endregion
	}
	Menu::End();
	WAIT(0);
}

void ScriptMain() {
	while (true) {
		main();
	}
}



bool ControlScript::IsInitialized() {
	return s_initialized;
}

void ControlScript::Initialize() {
	s_initialized = true;
}

void ControlScript::Destroy() {

}

void ControlScript::Tick() {
	Menu::Checks::Controlls();
}



bool UpdateScript::IsInitialized() {
	return s_initialized;
}

void UpdateScript::Initialize() {
	s_initialized = true;
}

void UpdateScript::Destroy() {

}

void UpdateScript::Tick() {
	Features::UpdateLoop();
}



bool DisplayScript::IsInitialized() {
	return s_initialized;
}

void DisplayScript::Initialize() {
	s_initialized = true;
}

void DisplayScript::Destroy() {

}

void DisplayScript::Tick() {

	if (!display_when_open) {
		reportdisplay ? Menu::reportMenu() : NULL;
		ipdisplay ? Menu::IPMenu() : NULL;
		Menu::Settings::selfInfo ? Menu::selfInfo(true) : NULL;
	}
	else if (display_when_open && Menu::Settings::menuLevel > 0) {
		reportdisplay ? Menu::reportMenu() : NULL;
		ipdisplay ? Menu::IPMenu() : NULL;
		Menu::Settings::selfInfo ? Menu::selfInfo(true) : NULL;
	}

	if (Features::show_tips) {
		buttons->setup();
		buttons->add((char*)"Open", 134);
		if (Menu::Settings::menuLevel > 0) {
			buttons->add((char*)"Scroll Up", 144);
			buttons->add((char*)"Scroll Down", 138);
			buttons->add((char*)"Select", 141);
			buttons->add((char*)"Left", 140);
			buttons->add((char*)"Right", 142);
			buttons->add((char*)"Back", 136);
		}
		buttons->draw();
	}
}



bool HotkeyScript::IsInitialized() {
	return s_initialized;
}

void HotkeyScript::Initialize() {
	s_initialized = true;
}

void HotkeyScript::Destroy() {

}

void HotkeyScript::Tick() {

}

void initToggle() {

}