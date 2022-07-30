#pragma once

enum SubMenus { //Add Sub Menus in here
	NOMENU,
	mainmenu,
	self,
	world,
	teleport,
	spawn,
	flip,
	vision,
	recovery,
	weapon,
	vehicle,
	misc,
	hotkey,
	protection,
	settings,
	exitgta,
	settingstheme,
	Credits,
	themeloader,
	settingstitlerect,
	settingsscroller,
	settingsoptiontext,
	font,
	plist,
	pmenu,
	//自我
	modelchanger,
	animation,
	animalmodel,
	pedmodel,
	onlinemodel,
	health,
	wanted,
	funny,
	movement,
	other,
	//武器
	trollgun,
	objgun,
	//线上
	drop,
	tp,
	troll,
	car,
	peaceful,
	vehtroll,
	kicks,
	crashes,
	attach,
	attachobj,
	attachflag,
	remote,
	Esp,
	attachself,
	spawner,
	spawnenemy,
	spawnveh,
	attachveh,
	cages,
	entityspam,
	help,
	sessionstarter,
	sessiontroll,
	//世界
	weatherchange,
	//恢复
	dcheists,
	casino_scheme,
	casino_target,
	casino_driver,
	casino_gun,
	casino_hacker,
	attributes,
	unlock,
	assetmanager,
	CEO,
	heistseditor,
	doomheist,
	cayoheist,
	arenaWareditor,
	RP,
	cayoinfo,
	cayotarget,
	cayomaintarget,
	cayoganrao,
	cayoweapon,
	//刷车
	moddedcar,
	super,
	helicopter,
	plane,
	suv,
	bike,
	offroad,
	motorbike,
	boat,
	Commercial,
	service,
	Compacts,
	Coupes,
	Emergency,
	Industrial,
	Military,
	Muscle,
	Sedans,
	Sports,
	SportsClassics,
	Trailer,
	Trains,
	Utility,
	Vans,
	SmugglersDLC,
	GunrunningDLC,
	DoomsdayDLC,
	SportSeries,
	ArenaWarDLC,
	CasinoHeistDLC,
	Tuner,
	spanwsetting,
	//传送常用地点
	commonteleport,
	Internaltp,
    //战局
	session,
	//保护
	scriptprotection,
	networkprotection,
	otherprotection,
	crashprotection,
};
extern enum SubMenus;
typedef struct VECTOR2 {
	float x, y;
};
typedef struct VECTOR2_2 {
	float w, h;
};
typedef struct RGBAF {
	int r, g, b, a, f;
};
typedef struct RGBA {
	int r, g, b, a;
};
typedef struct RGB {
	int r, g, b;
};
namespace Menu {
	void OptionInfo(const std::string text);
	namespace Drawing {
		void Text(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center,...);
		void Title(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center);
		void Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size);
		void Spriter(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
	}
	namespace Settings {
		extern bool selectPressed;
		extern bool leftPressed;
		extern bool rightPressed;
		extern bool center;
		extern bool controllerinput;

		extern int maxVisOptions;
		extern int currentOption;
		extern int optionCount;

		extern SubMenus currentMenu;
		extern int menuLevel;
		extern int optionsArray[1000];
		extern SubMenus menusArray[1000];

		extern float m_OptionTextSize;
		extern float m_SubmenuBarTextSize;
		extern float menuX;
		extern float menuY;
		extern float menuXscale;
		extern RGBAF count;
		extern RGBAF titleText;
		extern RGBA titleRect;
		extern RGBAF breakText;
		extern RGBAF optionText;
		extern RGBA selectedText;
		extern RGBAF arrow;
		extern RGBAF integre;
		extern RGBA optionRect;
		extern RGBA scroller;
		extern RGBA line;
		extern RGBA primary;
		extern RGBA secondary;
		extern int ScrollerR;
		extern int ScrollerG;
		extern int ScrollerB;
		extern int ScrollerA;

		extern int keyPressDelay;
		extern int keyPressPreviousTick;
		extern int keyPressDelay2;
		extern int keyPressPreviousTick2;
		extern int keyPressDelay3;
		extern int keyPressPreviousTick3;
		extern int openKey;
		extern int backKey;
		extern int upKey;
		extern int downKey;
		extern int leftKey;
		extern int rightKey;
		extern int selectKey;
		extern int arrowupKey;
		extern int arrowdownKey;
		extern int arrowleftKey;
		extern int arrowrightKey;
		extern int enterKey;
		extern int deleteKey;
		extern int openpress;
		extern int downpress;
		extern int uppress;
		extern int backpress;
		extern int click;
		extern int leftpress;
		extern int rightpress;

	}
	namespace MenuLevelHandler {
		void MoveMenu(SubMenus menu);
		void BackMenu();
	}
	namespace Checks {
		void Controlls();
	}
	namespace Tools {
		char* StringToChar(std::string string);
	}
	namespace Files {
		void WriteStringToIni(std::string string, std::string file, std::string app, std::string key);
		std::string ReadStringFromIni(std::string file, std::string app, std::string key);
		void WriteIntToIni(int intValue, std::string file, std::string app, std::string key);
		int ReadIntFromIni(std::string file, std::string app, std::string key);
		void WriteFloatToIni(float floatValue, std::string file, std::string app, std::string key);
		float ReadFloatFromIni(std::string file, std::string app, std::string key);
		void WriteBoolToIni(bool b00l, std::string file, std::string app, std::string key);
		bool ReadBoolFromIni(std::string file, std::string app, std::string key);
	}
	void Titlesky(const char* title);
	void ammobanner();
	void heistbanner();
	void cross();
	void Title(const char* title);
	void info(const char * title);
	void Vehicle(std::string texture1, std::string texture2);
	void Speedometer(char* text);
	void fps(char* text);
	void AddSmallTitle(char* text);
	void AddSmallInfo(char* text, short line,...);
	void AddSmallTitle2(char* text);
	void AddSmallInfo2(char* text, short line);
	void AddSmallTitle3(char* text);
	void AddSmallInfo3(char* text, short line);
	bool Break(const char* option);
	bool Option(const char* option);
	bool Option(const char* option, std::function<void()> function);
	bool MenuOption(const char* option, SubMenus newSub);
	void PlayerOption(int i);
	bool MenuOption(const char* option, SubMenus newSub, std::function<void()> function);
	bool Toggle(const char* option, bool& b00l);
	bool Toggle(const char* option, bool& b00l, std::function<void()> function);
	bool Int(const char* option, int& _int, int min, int max);
	bool Int(const char* option, int& _int, int min, int max, int step);
	bool Int(const char* option, int& _int, int min, int max, std::function<void()> function);
	bool Int(const char* option, int& _int, int min, int max, int step, std::function<void()> function);
	bool Float(const char* option, float& _float, int min, int max);
	bool Float(const char* option, float& _float, int min, int max, int step);
	bool Float(const char* option, float& _float, int min, int max, std::function<void()> function);
	bool Float(const char* option, float& _float, int min, int max, int step, std::function<void()> function);
	bool IntVector(const char* option, std::vector<int> Vector, int& position);
	bool IntVector(const char* option, std::vector<int> Vector, int& position, std::function<void()> function);
	bool FloatVector(const char* option, std::vector<float> Vector, int& position);
	bool FloatVector(const char* option, std::vector<float> Vector, int& position, std::function<void()> function);
	bool StringVector(const char* option, std::vector<std::string> Vector, int& position);
	bool StringVector(const char* option, std::vector<std::string> Vector, int& position, std::function<void()> function);
	bool StringVector(const char* option, std::vector<char*> Vector, int& position);
	bool StringVector(const char* option, std::vector<char*> Vector, int& position, std::function<void()> function);
	bool Teleport(const char* option, Vector3 coords);
	bool Teleport(const char* option, Vector3 coords, std::function<void()> function);
	void End();
	bool FileExists(const std::string& fileName);
}
