#pragma once
#include "gta\joaat.hpp"
#include "natives.hpp"
#include "gui.hpp"
#include"rbg.hpp"
const static std::string BRAKES_AND_TRANS_PREFIXES[] = { "Street", "Sports", "Race", "Super" };

const static std::string SUSP_PREFIXES[] = { "Lowered", "Street", "Sports", "Competition", "Race" };

const static std::string PLATE_NAMES[] = { "Blue on White", "Yellow/Black", "Gold/Blue", "Blue/White SA Caps", "Blue/White SA Exempt", "Blue/White Yankton" };

struct PaintColour
{
	std::string name;
	int mainValue;
	int pearlAddition;
};

const std::vector<PaintColour> PAINTS_NORMAL{
	{ "Black", 0, 0 },
	{ "Carbon Black", 147, 0 },
	{ "Graphite Black", 1, 0 },
	{ "Anthracite Black", 11, 0 },
	{ "Black Steel", 2, 0 },
	{ "Dark Steel", 3, 2 },
	{ "Silver", 4, 4 },
	{ "Bluish Silver", 5, 5 },
	{ "Rolled Steel", 6, 0 },
	{ "Shadow Silver", 7, 0 },
	{ "Stone Silver", 8, 0 },
	{ "Midnight Silver", 9, 0 },
	{ "Cast Iron Silver", 10, 0 },
	{ "Red", 27, 0 },
	{ "Torino Red", 28, 0 },
	{ "Formula Red", 29, 0 },
	{ "Lava Red", 150, 0 },
	{ "Blaze Red", 30, 0 },
	{ "Grace Red", 31, 0 },
	{ "Garnet Red", 32, 0 },
	{ "Sunset Red", 33, 0 },
	{ "Cabernet Red", 34, 0 },
	{ "Wine Red", 143, 0 },
	{ "Candy Red", 35, 0 },
	{ "Hot Pink", 135, 0 },
	{ "Pfister Pink", 137, 0 },
	{ "Salmon Pink", 136, 0 },
	{ "Sunrise Orange", 36, 0 },
	{ "Orange", 38, 0 },
	{ "Bright Orange", 138, 0 },
	{ "Gold", 99, 99 },
	{ "Bronze", 90, 102 },
	{ "Yellow", 88, 0 },
	{ "Race Yellow", 89, 0 },
	{ "Dew Yellow", 91, 0 },
	{ "Dark Green", 49, 0 },
	{ "Racing Green", 50, 0 },
	{ "Sea Green", 51, 0 },
	{ "Olive Green", 52, 0 },
	{ "Bright Green", 53, 0 },
	{ "Gasoline Green", 54, 0 },
	{ "Lime Green", 92, 0 },
	{ "Midnight Blue", 141, 0 },
	{ "Galaxy Blue", 61, 0 },
	{ "Dark Blue", 62, 0 },
	{ "Saxon Blue", 63, 0 },
	{ "Blue", 64, 0 },
	{ "Mariner Blue", 65, 0 },
	{ "Harbor Blue", 66, 0 },
	{ "Diamond Blue", 67, 0 },
	{ "Surf Blue", 68, 0 },
	{ "Nautical Blue", 69, 0 },
	{ "Racing Blue", 73, 0 },
	{ "Ultra Blue", 70, 0 },
	{ "Light Blue", 74, 0 },
	{ "Chocolate Brown", 96, 0 },
	{ "Bison Brown", 101, 0 },
	{ "Creek Brown", 95, 0 },
	{ "Feltzer Brown", 94, 0 },
	{ "Maple Brown", 97, 0 },
	{ "Beechwood Brown", 103, 0 },
	{ "Sienna Brown", 104, 0 },
	{ "Saddle Brown", 98, 0 },
	{ "Moss Brown", 100, 0 },
	{ "Woodbeech Brown", 102, 0 },
	{ "Straw Brown", 99, 0 },
	{ "Sandy Brown", 105, 0 },
	{ "Bleached Brown", 106, 0 },
	{ "Schafter Purple", 71, 0 },
	{ "Spinnaker Purple", 72, 0 },
	{ "Midnight Purple", 142, 0 },
	{ "Bright Purple", 145, 0 },
	{ "Cream", 107, 0 },
	{ "Ice White", 111, 0 },
	{ "Frost White", 112, 0 }
};

const std::vector<PaintColour> PAINTS_METALLIC{
	{ "Black", 0, 10 },
	{ "Carbon Black", 147, 4 },
	{ "Graphite Black", 1, 5 },
	{ "Anthracite Black", 11, 2 },
	{ "Black Steel", 2, 5 },
	{ "Dark Steel", 3, 6 },
	{ "Silver", 4, 111 },
	{ "Bluish Silver", 5, 111 },
	{ "Rolled Steel", 6, 4 },
	{ "Shadow Silver", 7, 5 },
	{ "Stone Silver", 8, 5 },
	{ "Midnight Silver", 9, 7 },
	{ "Cast Iron Silver", 10, 7 },
	{ "Red", 27, 36 },
	{ "Torino Red", 28, 28 },
	{ "Formula Red", 29, 28 },
	{ "Lava Red", 150, 42 },
	{ "Blaze Red", 30, 36 },
	{ "Grace Red", 31, 27 },
	{ "Garnet Red", 32, 25 },
	{ "Sunset Red", 33, 47 },
	{ "Cabernet Red", 34, 47 },
	{ "Wine Red", 143, 31 },
	{ "Candy Red", 35, 25 },
	{ "Hot Pink", 135, 135 },
	{ "Pfister Pink", 137, 3 },
	{ "Salmon Pink", 136, 5 },
	{ "Sunrise Orange", 36, 26 },
	{ "Orange", 38, 37 },
	{ "Bright Orange", 138, 89 },
	{ "Gold", 37, 106 },
	{ "Bronze", 90, 102 },
	{ "Yellow", 88, 88 },
	{ "Race Yellow", 89, 88 },
	{ "Dew Yellow", 91, 91 },
	{ "Dark Green", 49, 52 },
	{ "Racing Green", 50, 53 },
	{ "Sea Green", 51, 66 },
	{ "Olive Green", 52, 59 },
	{ "Bright Green", 53, 59 },
	{ "Gasoline Green", 54, 60 },
	{ "Lime Green", 92, 92 },
	{ "Midnight Blue", 141, 73 },
	{ "Galaxy Blue", 61, 63 },
	{ "Dark Blue", 62, 68 },
	{ "Saxon Blue", 63, 87 },
	{ "Blue", 64, 68 },
	{ "Mariner Blue", 65, 87 },
	{ "Harbor Blue", 66, 60 },
	{ "Diamond Blue", 67, 67 },
	{ "Surf Blue", 68, 68 },
	{ "Nautical Blue", 69, 74 },
	{ "Racing Blue", 73, 73 },
	{ "Ultra Blue", 70, 70 },
	{ "Light Blue", 74, 74 },
	{ "Chocolate Brown", 96, 95 },
	{ "Bison Brown", 101, 95 },
	{ "Creek Brown", 95, 97 },
	{ "Feltzer Brown", 94, 104 },
	{ "Maple Brown", 97, 98 },
	{ "Beechwood Brown", 103, 104 },
	{ "Sienna Brown", 104, 104 },
	{ "Saddle Brown", 98, 95 },
	{ "Moss Brown", 100, 100 },
	{ "Woodbeech Brown", 102, 105 },
	{ "Straw Brown", 99, 106 },
	{ "Sandy Brown", 105, 105 },
	{ "Bleached Brown", 106, 106 },
	{ "Schafter Purple", 71, 145 },
	{ "Spinnaker Purple", 72, 64 },
	{ "Midnight Purple", 146, 145 },
	{ "Bright Purple", 145, 74 },
	{ "Cream", 107, 107 },
	{ "Ice White", 111, 0 },
	{ "Frost White", 112, 0 }
};

const std::vector<PaintColour> PAINTS_MATTE{
	{ "Black", 12, 0 },
	{ "Gray", 13, 0 },
	{ "Light Gray", 14, 0 },
	{ "Ice White", 131, 0 },
	{ "Blue", 83, 0 },
	{ "Dark Blue", 82, 0 },
	{ "Midnight Blue", 84, 0 },
	{ "Midnight Purple", 149, 0 },
	{ "Schafter Purple", 148, 0 },
	{ "Red", 39, 0 },
	{ "Dark Red", 40, 0 },
	{ "Orange", 41, 0 },
	{ "Yellow", 42, 0 },
	{ "Lime Green", 55, 0 },
	{ "Green", 128, 0 },
	{ "Forest Green", 151, 0 },
	{ "Foliage Green", 155, 0 },
	{ "Olive Drab", 152, 0 },
	{ "Dark Earth", 153, 0 },
	{ "Desert Tan", 154, 0 }
};

const std::vector<PaintColour> PAINTS_METAL{
	{ "Brushed Steel", 117, 18 },
	{ "Brushed Black Steel", 118, 3 },
	{ "Brushed Aluminum", 119, 5 },
	{ "Pure Gold", 158, 160 },
	{ "Brushed Gold", 159, 160 }
};

const std::vector<PaintColour> PAINTS_PEARL{
	{ "Black", -1, 0 },
	{ "Carbon Black", -1, 147 },
	{ "Graphite Black", -1, 1 },
	{ "Anthracite Black", -1, 11 },
	{ "Black Steel", -1, 2 },
	{ "Dark Steel", -1, 3 },
	{ "Silver", -1, 4 },
	{ "Bluish Silver", -1, 5 },
	{ "Rolled Steel", -1, 6 },
	{ "Shadow Silver", -1, 7 },
	{ "Stone Silver", -1, 8 },
	{ "Midnight Silver", -1, 9 },
	{ "Cast Iron Silver", -1, 10 },
	{ "Red", -1, 27 },
	{ "Torino Red", -1, 28 },
	{ "Formula Red", -1, 29 },
	{ "Lava Red", -1, 150 },
	{ "Blaze Red", -1, 30 },
	{ "Grace Red", -1, 31 },
	{ "Garnet Red", -1, 32 },
	{ "Sunset Red", -1, 33 },
	{ "Cabernet Red", -1, 34 },
	{ "Wine Red", -1, 143 },
	{ "Candy Red", -1, 35 },
	{ "Hot Pink", -1, 135 },
	{ "Pfister Pink", -1, 137 },
	{ "Salmon Pink", -1, 136 },
	{ "Sunrise Orange", -1, 36 },
	{ "Orange", -1, 38 },
	{ "Bright Orange", -1, 138 },
	{ "Gold", -1, 37 },
	{ "Bronze", -1, 90 },
	{ "Yellow", -1, 88 },
	{ "Race Yellow", -1, 89 },
	{ "Dew Yellow", -1, 91 },
	{ "Dark Green", -1, 49 },
	{ "Racing Green", -1, 50 },
	{ "Sea Green", -1, 51 },
	{ "Olive Green", -1, 52 },
	{ "Bright Green", -1, 53 },
	{ "Gasoline Green", -1, 54 },
	{ "Lime Green", -1, 92 },
	{ "Midnight Blue", -1, 141 },
	{ "Galaxy Blue", -1, 61 },
	{ "Dark Blue", -1, 62 },
	{ "Saxon Blue", -1, 63 },
	{ "Blue", -1, 64 },
	{ "Mariner Blue", -1, 65 },
	{ "Harbor Blue", -1, 66 },
	{ "Diamond Blue", -1, 67 },
	{ "Surf Blue", -1, 68 },
	{ "Nautical Blue", -1, 69 },
	{ "Racing Blue", -1, 73 },
	{ "Ultra Blue", -1, 70 },
	{ "Light Blue", -1, 74 },
	{ "Chocolate Brown", -1, 96 },
	{ "Bison Brown", -1, 101 },
	{ "Creek Brown", -1, 95 },
	{ "Feltzer Brown", -1, 94 },
	{ "Maple Brown", -1, 97 },
	{ "Beechwood Brown", -1, 103 },
	{ "Sienna Brown", -1, 104 },
	{ "Saddle Brown", -1, 98 },
	{ "Moss Brown", -1, 100 },
	{ "Woodbeech Brown", -1, 102 },
	{ "Straw Brown", -1, 99 },
	{ "Sandy Brown", -1, 105 },
	{ "Bleached Brown", -1, 106 },
	{ "Schafter Purple", -1, 71 },
	{ "Spinnaker Purple", -1, 72 },
	{ "Midnight Purple", -1, 146 },
	{ "Bright Purple", -1, 145 },
	{ "Cream", -1, 107 },
	{ "Ice White", -1, 111 },
	{ "Frost White", -1, 112 },
	{ "Secret Gold", -1, 160 }
};

const std::vector<PaintColour> PAINTS_WHEELS
{
	{ "Default", 156, -1 },
	{ "Black", 0, -1 },
	{ "Carbon Black", 1, -1 },
	{ "Anthracite Black", 11, -1 },
	{ "Black Steel", 2, -1 },
	{ "Stone Silver", 8, -1 },
	{ "Frost White", 122, -1 },
	{ "Red", 27, -1 },
	{ "Blaze Red", 30, -1 },
	{ "Garnet Red", 45, -1 },
	{ "Candy Red", 35, -1 },
	{ "Sunset Red", 33, -1 },
	{ "Salmon Pink", 136, -1 },
	{ "Hot Pink", 135, -1 },
	{ "Sunrise Orange", 36, -1 },
	{ "Orange", 41, -1 },
	{ "Bright Orange", 138, -1 },
	{ "Gold", 37, -1 },
	{ "Straw Brown", 99, -1 },
	{ "Dark Copper", 90, -1 },
	{ "Dark Ivory", 95, -1 },
	{ "Dark Brown", 115, -1 },
	{ "Bronze", 109, -1 },
	{ "Dark Earth", 153, -1 },
	{ "Desert Tan", 154, -1 },
	{ "Yellow", 88, -1 },
	{ "Race Yellow", 89, -1 },
	{ "Yellow Bird", 91, -1 },
	{ "Lime Green", 55, -1 },
	{ "Pea Green", 125, -1 },
	{ "Green", 53, -1 },
	{ "Dark Green", 56, -1 },
	{ "Olive Green", 151, -1 },
	{ "Midnight Blue", 82, -1 },
	{ "Royal Blue", 64, -1 },
	{ "Baby Blue", 87, -1 },
	{ "Bright Blue", 70, -1 },
	{ "Flourescent Blue", 140, -1 },
	{ "Slate Blue", 81, -1 },
	{ "Schafter Purple", 145, -1 },
	{ "Midnight Purple", 142, -1 }
};

const std::vector<PaintColour> PAINTS_CHROME = { {"Chrome", 120, 0} };

const std::vector<PaintColour> PAINTS_Headlights
{
	{"Default", 255, 0},
	{"White",  0, 0},
	{"Blue",  1, 0},
	{"Electric Blue",  2, 0},
	{"Mint Green",  3, 0},
	{"Lime Green",  4, 0},
	{"Yellow",  5, 0},
	{"Golden Shower",  6, 0},
	{"Orange",  7, 0},
	{"Red",  8, 0},
	{"Pony Pink", 9, 0},
	{"Hot Pink",  10, 0},
	{"Purple",  11, 0},
	{"Blacklight",  12, 0}
};

const std::vector<PaintColour> PAINTS_WindowTints
{
	{"Stock",  -1, 0},
	{"Pure Black",  1, 1},
	{"Dark Smoke",  2, 2},
	{"Light Smoke",  3, 3},
	{"Limo",  5, 5},
};

struct tPaintTypes {
	std::string displayName;
	int paintType;
	std::vector<PaintColour> colors;
};

static tPaintTypes ePaintTypes[6] = {
	{"Normal", 0, PAINTS_NORMAL },
	{"Metallic", 1, PAINTS_METALLIC},
	{"Pearl", 2, PAINTS_PEARL },
	{"Matte", 3, PAINTS_MATTE },
	{"Metal", 4, PAINTS_METAL },
	{"Chrome", 5, PAINTS_CHROME },
};

struct tWheelTypes {
	std::string displayName;
	int wheelType;
};

static tWheelTypes eWheelTypes[8] = {
	{"Sport", 0 },
	{"Muscle", 1 },
	{"Lowrider", 2 },
	{"SUV", 3 },
	{"Offroad", 4 },
	{"Tuner", 5 },
	{"Bike Wheels", 6 },
	{"High End", 7 },
};

struct VehicleColours
{
	std::string primaryName;
	std::string secondaryName;
	int primary;
	int secondary;

	std::string primaryPaintTypeName;
	std::string secondaryPaintTypeName;
	int primaryPaintType;
	int secondaryPaintType;

	bool isPrimaryCustom;
	bool isSecondaryCustom;
	rage::RGBAD customPrimary;
	rage::RGBAD customSecondary;

	std::string pearlescentName;
	int pearlescent;

	std::string headlightsName;
	int headlights;

	std::string windowTintName;
	int windowTint;

	std::string wheelName;
	int wheels;

	rage::RGBAD tyreSmoke;
	rage::RGBAD neonLights;
};

struct toggleMods {
	bool turbo;
	bool tyreSmoke;
	bool xenonHeadLights;
	bool neonLights[4];
};

struct otherMods {
	bool isCustomTyre;
	std::string wheelTypeName;
	int wheeltype;

	std::string plateText;
	std::string plateTextIndexName;
	int plateTextIndex;
};

struct mods {
	std::string name;
	int category;
	int options;
	int index = -1;
	std::string itemName;
};

struct VehicleAttachInfo {
	Hash model;
	int primCol;
	int secCol;
	float X;
	float Y;
	float Z;
	float Pitch;
	float Roll;
	float Yaw;
	bool invis;
	int boneIndex;
	bool dynamic;
	bool collisionEnabled;
};

struct ObjectAttachInfo {
	Hash model;
	float X;
	float Y;
	float Z;
	float Pitch;
	float Roll;
	float Yaw;
	bool invis;
	int boneIndex;
	bool dynamic;
	bool collisionEnabled;
	bool destroyVar;
};

struct VehicleData;
struct Attachments {
	std::vector<VehicleAttachInfo> vehiclesAttached;
	std::vector<ObjectAttachInfo> objectsAttached;
};

struct VehicleData
{
	Vehicle handle;
	Hash model;
	std::string displayName;
	bool isBike;
	VehicleColours colours;
	toggleMods togglemods;
	mods mods[49];
	otherMods other;

	Attachments attachments;

	bool isRefreshed;
	int lastSelectedCategory{ -1 };
	std::vector<std::string> lastSelectedModNames;
};

struct VehiclePack {
	std::string name{};
	std::string labelText{};
	rage::joaat_t hash{};
};

struct VehicleClass {
	std::string className;
	std::vector<VehiclePack> vehicles;
};

class Vehicles {
public:
	void initialize();
	void refreshVehicle(VehicleData* vehData, Vehicle veh);
	void allocateAttachments(Attachments* attachments, Entity to);
	Vehicle spawnCustomVehicle(VehicleData data);
public:
	std::vector<VehicleClass> classes;
	VehicleData currVeh;
	std::string selectedXmlFile{};

public:
	bool writeData{};
};
inline Vehicles g_vehicles{};