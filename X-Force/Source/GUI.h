#pragma once

#pragma warning (disable: 4091)
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
	void DRAW_TEXTURE(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
	namespace Drawing {
		void Text(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center, bool rightAlign = false, bool outline = true);
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
		extern bool DrawTextOutline;
		extern bool displayEnd;

		extern int maxVisOptions;
		extern int currentOption;
		extern int optionCount;

		extern SubMenus currentMenu;
		extern int menuLevel;
		extern int optionsArray[1000];
		extern SubMenus menusArray[1000];

		extern float menuX;
		extern RGBAF count;
		extern RGBAF titleText;
		extern RGBA titleRect;
		extern RGBAF breakText;
		extern RGBA breakrect;
		extern RGBAF optionText;
		extern RGBA selectedText;
		extern RGBAF arrow;
		extern RGBAF integre;
		extern RGBA optionRect;
		extern RGBA scroller;
		extern RGBA line;
		extern RGBA primary;
		extern RGBA secondary;

		extern RGBA Nothing; //Info

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
		extern char* ytdtheme;
		extern char* menuname;
		extern std::string toggleYTD;
		extern std::string toggleON;
		extern std::string toggleOFF;
		extern int cursorMenuX;
		extern int subtitleCount;
		extern bool canSelect;
		extern RGBA infocolor;
		extern std::string menuend;
		extern bool showGlobe;
		extern float GlareX;
		extern bool selfInfo;
		extern bool playerInfoActive;
		extern bool lightning;
		extern bool fadeIn;
		extern bool fadeOut;
		extern int fadeAlpha;
		extern float scrollBarPos;
		extern float menuY;
		extern float menuWidth;
		extern float headerHeight;
		extern int headerTransparancy;
		extern float scrollbarWidthIndex;
		extern float textSize;
		extern bool evolve;		
		extern bool phantom;
		extern bool c_enable;
		extern bool c_animation;
		extern std::string c_name;
		extern std::string c_pict;
		extern int c_frames;
		extern int c_ID;
		extern bool enable_scrollbar;
		extern float ScrollerSpeed;
		extern bool enable_smooth;
		extern bool city;
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
	void Title(const char* title);
	void info(const char * title);
	void Vehicle(std::string texture1, std::string texture2);
	void Speedometer(char* text);
	void fps(char* text);
	void AddSmallTitle(char* text);
	void AddSmallInfo(char* text, short line);
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
	void Map(std::string texture1, std::string texture2);
	bool ListVector(const char * option, std::vector<std::string> Vector, int & position);
	void Log(char* msg);
	void logMessage(char* msg);
	void addText(std::string txt, bool withN);
	void statsinfo();
	void PlayerInfoTitle(char* text);
	void PlayerInfoLine(char* text, short line);
	bool Subtitle(const char * title);
	RGBA colors();
	RGBA Colors(RGBA colors[16]);
	bool ColorOption(const char * option, SubMenus newSub);
	void reportMenu();
	void IPMenu();
	bool MenuOptions2(const char * option, SubMenus newSub, int pid);
	void drawScrollbar(int max_options, int option_count);
	void lightning(int delay, bool fade);
	void selfInfo(bool toggle);
	void selfInfoLine(char* text, short line);
	bool fade(bool fadein);
	void TitleFade(const char * title);
	bool BreakFade(const char * title);
	bool MenuOptionFade(const char * option, SubMenus newSub);
	void OptionInfo(const char * info); //Info
	void OptionInfo2(const char * info); //Info
	void symbols();
	void SimpleSmoothScrolling();
	void Evolve();
	void Phantom();
	bool VipOption(const char * option);
	bool VipOption(const char * option, std::function<void()> function);
	bool VipToggle(const char * option, bool & b00l);
	bool VipToggle(const char * option, bool & b00l, std::function<void()> function);
	bool VipInt(const char * option, int & _int, int min, int max);
	bool VipInt(const char * option, int & _int, int min, int max, int step);
	bool VipInt(const char * option, int & _int, int min, int max, std::function<void()> function);
	bool VipInt(const char * option, int & _int, int min, int max, int step, std::function<void()> function);
	bool VipMenuOption(const char * option, SubMenus newSub);
	int pressedKey();
	void addHotkey(std::string name);
	void removeHotkey(std::string name);
	void checkHotkey(std::string name, bool & b00l);
	void checkHotkey(std::string name, bool & b00l, std::function<void()> func);
	void checkHotkey(std::string name, std::function<void()> func);
	bool checkHotkey(std::string name);
	bool Toggle(const char * option, bool & b00l, bool hotkey);
	bool Toggle(const char * option, bool & b00l, std::function<void()> function, bool hotkey);
	bool VipToggle(const char * option, bool & b00l, bool hotkey);
	bool VipToggle(const char * option, bool & b00l, std::function<void()> function, bool hotkey);
	void loadCustomHeader();
	void scroll(int* prev, const int cur);
	bool TpOption(const char * option, Vector3 coords, std::string pic);
	void setOpenKey();
	void City();
	void customNotification(char *text);
	typedef struct
	{
		std::string dict;
		std::string texture;
	} sprite_info;
	typedef struct
	{
		std::string option, value;
		sprite_info sprite;
	} extra_option_args;
	void extra_title(const std::string& text);
	void extra_option(const extra_option_args args);
	void end_extra_menu();
}
