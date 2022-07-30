#include "stdafx.h"

//globo
float Menu::Settings::GlareX = (Menu::Settings::menuX - 0.17f) + 0.5050f; //Esquerda
float GlareY = 0.4954f; //Direita
float Glarewidth = 1.0240f; //Largura do brilho
float Glareheight = 1.0215f; //Altura do brilho
 
int lightningID = 1;

namespace Globe
{
	int gGlareHandle; // int
	float gGlareDir;

	// Function(s)
	float conv360(float base, float min, float max) {		
		float fVar0;
		if (min == max) return min;
		fVar0 = max - min;

		if (base < min) base += fVar0;
		return base;
	}
	void drawGlare(float pX, float pY, float sX = 1, float sY = 1, int r = 255, int g = 255, int b = 255) {

		gGlareHandle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_MENU_GLARE");

		Vector3 rot = CAM::_GET_GAMEPLAY_CAM_ROT(2);

		float dir = conv360(rot.z, 0, 360);

		if ((gGlareDir == 0 || gGlareDir - dir > 0.5) || gGlareDir - dir < -0.5) {

			gGlareDir = dir;

			GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(gGlareHandle, "SET_DATA_SLOT");

			GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_FLOAT(gGlareDir);

			GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
		}

		GRAPHICS::DRAW_SCALEFORM_MOVIE(gGlareHandle, pX, pY, sX, sY, r, g, b, 255, 0);

	}
};

void Menu::Drawing::Text(const char * text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center, bool rightAlign, bool outline)
{
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_COLOUR(rgbaf.r, rgbaf.g, rgbaf.b, rgbaf.a);
	UI::SET_TEXT_FONT(rgbaf.f);
	UI::SET_TEXT_SCALE(size.w, size.h);
	if (outline && Menu::Settings::DrawTextOutline) {
		UI::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 0);
		UI::SET_TEXT_EDGE(1, 0, 0, 0, 0);
		UI::SET_TEXT_OUTLINE();
	}
	if (rightAlign) {
		UI::SET_TEXT_RIGHT_JUSTIFY(TRUE);
		UI::SET_TEXT_WRAP(Menu::Settings::menuX, Menu::Settings::menuX + 0.085f);
	}
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(position.x, position.y);
}

void Menu::DRAW_TEXTURE(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)Streamedtexture.c_str()))
	{
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char*)Streamedtexture.c_str(), false);
	}
	else
	{
		GRAPHICS::DRAW_SPRITE((char*)Streamedtexture.c_str(), (char*)textureName.c_str(), x, y, width, height, rotation, r, g, b, a);
	}
}

void Menu::Drawing::Spriter(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)Streamedtexture.c_str()))
	{
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char*)Streamedtexture.c_str(), false);
	}
	else
	{
		GRAPHICS::DRAW_SPRITE((char*)Streamedtexture.c_str(), (char*)textureName.c_str(), x, y, width, height, rotation, r, g, b, a);
	}
}

void Menu::Drawing::Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size)
{
	GRAPHICS::DRAW_RECT(position.x, position.y, size.w, size.h, rgba.r, rgba.g, rgba.b, rgba.a);
}

float gGlareDir;
float conv360(float base, float min, float max)
{
	float fVar0;
	if (min == max) return min;
	fVar0 = max - min;
	base -= SYSTEM::ROUND(base - min / fVar0) * fVar0;
	if (base < min) base += fVar0;
	return base;
}

static fpFileRegister file_register = (fpFileRegister)(Memory::pattern("48 89 5C 24 ? 48 89 6C 24 ? 48 89 7C 24 ? 41 54 41 56 41 57 48 83 EC 50 48 8B EA 4C 8B FA 48 8B D9 4D 85 C9").count(1).get(0).get<decltype(file_register)>());
bool FileExists(const std::string& fileName)
{
	struct stat buffer;
	return (stat(fileName.c_str(), &buffer) == 0);
}
void YTD()
{
	std::string path = "X-Folder/title/";
	std::string name = "customheader.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
}
void YTD2() {
	std::string path = "X-Folder/title/";
	std::string name = "map.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
}
void YTD3(std::string path, std::string name) {
	const std::string fullPath = path + name;
	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
}

bool Menu::Settings::DrawTextOutline = false;
float Menu::Settings::menuX = 0.17f;
float Menu::Settings::menuY = 0.0f;
bool Menu::Settings::selectPressed = false;
bool Menu::Settings::leftPressed = false;
bool Menu::Settings::rightPressed = false;
bool Menu::Settings::displayEnd = true;
bool firstopen = true;
int Menu::Settings::maxVisOptions = 16;
int Menu::Settings::currentOption = 0;
int Menu::Settings::optionCount = 0;
SubMenus Menu::Settings::currentMenu;
int Menu::Settings::menuLevel = 0;
int Menu::Settings::optionsArray[1000];
SubMenus Menu::Settings::menusArray[1000];

RGBAF Menu::Settings::count{ 255, 255, 255, 255, 0 };
RGBAF Menu::Settings::titleText{ 255, 255, 255, 255, 7 };
RGBA Menu::Settings::titleRect{ 0, 0, 0, 255 };
RGBA Menu::Settings::breakrect{ 0, 0, 0, 180 };
RGBAF Menu::Settings::optionText{ 255, 255, 255, 255, 0 };
RGBAF Menu::Settings::breakText{ 255, 255, 255, 255, 0 }; //f = 1
RGBAF Menu::Settings::arrow{ 255, 255, 255, 255, 3 };                          // Mod Menu Colors 
RGBA Menu::Settings::optionRect{ 0, 0, 0, 150 };
RGBA Menu::Settings::scroller{ 0, 0, 0, 180 };
RGBAF Menu::Settings::integre{ 255, 255, 255, 255, 0 };
RGBA Menu::Settings::line{ 255, 255, 255, 255 };
RGBA Menu::Settings::primary{ 255, 0, 0, 255 };
RGBA Menu::Settings::secondary{ 0, 0, 0, 255 };
char* Menu::Settings::ytdtheme = "xforce2";
char* Menu::Settings::menuname = "";
int Menu::Settings::subtitleCount = 0;

std::string Menu::Settings::toggleYTD = "commonmenu";
std::string Menu::Settings::toggleON = "shop_box_tick";
std::string Menu::Settings::toggleOFF = "shop_box_blank";

int Menu::Settings::cursorMenuX = (Menu::Settings::menuX * 100)*15;
std::string Menu::Settings::menuend = "menuend_x";
bool Menu::Settings::showGlobe = true;

RGBA Menu::Settings::Nothing{ 0, 0, 0, 0 }; //Info

RGBA Menu::Settings::infocolor{ 0, 0, 0, 255 };

enum Font
{
	ChaletLondon = 0,
	HouseScript = 1,
	Monospace = 2,
	Wingdings = 3,
	ChaletComprimeCologne = 4,
	Pricedown = 7
};

void DrawRect(float x, float y, float width, float height, RGBA color)
{
	GRAPHICS::DRAW_RECT(x, y, width, height, color.r, color.g, color.b, color.a);
}

void DrawSprite(const char* dict, const char* texture, float x, float y, float width, float height, RGBA color, float rotation)
{
	if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)dict))
	{
		GRAPHICS::DRAW_SPRITE((char*)dict, (char*)texture, x, y, width, height, rotation, color.r, color.g, color.b, color.a);
	}
	else
	{
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char*)dict, false);
	}
}

void DrawLeftText(const char* text, float x, float y, float size, int font, RGBA color, bool outline, bool shadow)
{
	UI::SET_TEXT_SCALE(size, size);
	UI::SET_TEXT_FONT(static_cast<int>(font));
	UI::SET_TEXT_COLOUR(color.r, color.g, color.b, color.a);
	if (outline)
		UI::SET_TEXT_OUTLINE();
	if (shadow)
		UI::SET_TEXT_DROP_SHADOW();

	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT((char*)"STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}

void DrawCenteredText(const char* text, float x, float y, float size, int font, RGBA color, bool outline, bool shadow)
{
	UI::SET_TEXT_CENTRE(true);
	DrawLeftText(text, x, y, size, font, color, outline, shadow);
}

void DrawRightText(const char* text, float x, float y, float size, int font, RGBA color, bool outline, bool shadow)
{
	UI::SET_TEXT_WRAP(0.f, x);
	UI::SET_TEXT_RIGHT_JUSTIFY(true);
	DrawLeftText(text, x, y, size, font, color, outline, shadow);
}

float GetTextHeight(Font font, float size)
{
	return UI::_GET_TEXT_SCALE_HEIGHT(size, static_cast<int>(font));
}

VECTOR2 GetSpriteScale(float size)
{
	int x;
	int y;
	GRAPHICS::_GET_ACTIVE_SCREEN_RESOLUTION(&x, &y);

	return { (static_cast<float>(y) / static_cast<float>(x)) * size, size };
}

float Menu::Settings::menuWidth = 0.24f; //0.21f
float Menu::Settings::headerHeight = 0.085f;
int Menu::Settings::headerTransparancy = 255;
float Menu::Settings::scrollbarWidthIndex = 0.135f; //0.12f
float Menu::Settings::textSize = 0.35f - 0.07f;

float yyyyy = 0.349f;
void Menu::drawScrollbar(int max_options, int option_count) {
	int curopt = Settings::currentOption;
	float space = 0.035f;
	float scroll = ((((curopt * (max_options * space)) / option_count)));
	/*if (option_count > max_options) {
		Drawing::Rect({ 0, 0, 0, 255 }, { Settings::menuX - 0.12f, yyyyy }, { 0.012f, (max_options * 0.035f + 0.039f) });
		Drawing::Rect(Settings::scroller, { Settings::menuX - 0.12f, scroll + 0.138f }, { 0.007f, 0.039f });
		//Drawing::Rect(Settings::scroller, { Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + (scroll + 0.138f) }, { 0.008f, 0.035f });
	}*/

	if (option_count > max_options) {
		Drawing::Rect({ 45, 45, 45, 165 }, { Settings::menuX + 0.112f, Settings::menuY + yyyyy }, { 0.012f, max_options * 0.035f });
		Drawing::Rect(Settings::scroller, { Settings::menuX + 0.112f, scroll + Settings::menuY + 0.138f }, { 0.007f, 0.035f });
	}

	/*int curopt = Settings::currentOption;
	float space = 0.04f;
	float scroll = ((((curopt * (max_options * space)) / option_count)));
	bool onThis = curopt == option_count ? true : false;
	if (curopt <= 16 && Settings::optionCount <= 16) {
		//Drawing::Rect({ 0, 0, 0, 255 }, { Settings::menuX - 0.12f, yyyyy }, { 0.012f, (max_options * 0.035f + 0.039f) });
		//Drawing::Rect(Settings::scroller, { Settings::menuX - 0.12f, scroll + 0.138f }, { 0.007f, 0.039f });
		if (onThis) {
			Drawing::Rect(Settings::scroller, { Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + (option_count)*0.035f + 0.1415f }, { 0.008f, 0.035f });
		}
	}
	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
	{
		if (onThis) {
			Drawing::Rect(Settings::scroller, { Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + (scroll + 0.138f) }, { 0.008f, 0.035f });
		}
	}*/
}

void Menu::Title(const char * title)
{
	Drawing::Text(title, Settings::titleText, { Settings::menuX, 0.065f }, { 0.50f, 0.50f }, true);
	//Drawing::Rect(Settings::titleRect, { Settings::menuX, +0.0820f }, { 0.21f, 0.085f }); //Title coords STANDART: +0.0810 PERFECT?: +0.0820

	/*
	float scroll = ((Menu::Settings::currentOption * (16 * 0.035f)) / Menu::Settings::optionCount);
	Drawing::Rect(Menu::Settings::scroller, { Menu::Settings::menuX - Menu::Settings::scrollbarWidthIndex, Menu::Settings::menuY + (scroll + 0.1f) }, { 0.008f, 0.035f });
	*/
	if (Settings::c_enable) {
		Menu::loadCustomHeader();
	}
	else {
		if (Menu::Settings::evolve) {
			Menu::Evolve();
		}
		else if (Menu::Settings::lightning) {
			Menu::lightning(35000000, false);
		}
		else if (Menu::Settings::phantom) {
			Menu::Phantom();
		}
		else if (Menu::Settings::city) {
			Menu::City();
		}
		else {
			Drawing::Spriter("customheader", Menu::Settings::ytdtheme, Settings::menuX, Settings::menuY + 0.0820f, Settings::menuWidth, Settings::headerHeight, 0.f, 255, 255, 255, Settings::headerTransparancy); //YTD loader
		}
	}

	if (Settings::enable_scrollbar) {
		Drawing::Rect(Settings::secondary, { Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + 0.1500f }, { 0.01f, 0.019f });
		Drawing::Text("3", Settings::arrow, { Settings::menuX - Settings::scrollbarWidthIndex - 0.005f, Settings::menuY + 0.137f }, { 0.30f, 0.30f }, false);
	}

	if (Settings::showGlobe) {
		Globe::drawGlare(Settings::GlareX + (Settings::scrollbarWidthIndex - 0.12f), Settings::menuY + GlareY, Glarewidth, Glareheight, 255, 255, 255);
	}

	//drawScrollbar(Menu::Settings::currentOption, Menu::Settings::optionCount);

	YTD();
	// Disable Controls
	UI::HIDE_HELP_TEXT_THIS_FRAME();
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(10);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_NEXT_CAMERA, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_CHARACTER_WHEEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_LIGHT, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_HEAVY, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MULTIPLAYER_INFO, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_ALTERNATE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_CIN_CAM, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MAP_POI, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_RADIO_WHEEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_HEADLIGHT, true);
}

/*
float yyyyy = 0.349f;
void script::drawScrollbar(int max_options, int option_count) {
	if (script::cur_sub != subs::closed) {
		int curopt = script::currentOption;
		float space = 0.040f;
		float scroll = ((((curopt * (max_options * space)) / option_count)));
		if (option_count > max_options) {
			rect({ 45, 45, 45, 165 }, { menuPos.x + 0.112f, menuPos.y + yyyyy }, { 0.012f, (max_options * 0.040f + 0.039f) });
			rect(titleRect, { menuPos.x + 0.112f, scroll + menuPos.y + 0.138f }, { 0.007f, 0.039f });
		}
	}
}
*/

int hotkeyKey = VK_F12; //F12

int Menu::pressedKey() {
	int retKey = -1;
	for (int i = 0x00; i < 0xFF; i++) {
		if (IsKeyPressed(i) && i != 0x00 && i != hotkeyKey) {
			retKey = i;
		}
	}
	return retKey;
}

void Menu::addHotkey(std::string name) {
	std::string keypath = "X-Folder/keys.ini";
	int key = pressedKey();
	while (key == -1) {
		key = pressedKey();
		WAIT(0);
	}
	INI::WriteInt(keypath, key, "hotkeys", name);
}

int pressedKey2() {
	int retKey = -1;
	for (int i = 0x00; i < 0xFF; i++) {
		if (IsKeyPressed(i) && i != 0x00 && i != VK_NUMPAD5) {
			retKey = i;
		}
	}
	return retKey;
}

void Menu::setOpenKey() {
	int key = pressedKey2();
	while (key == -1) {
		key = pressedKey2();
		WAIT(0);
	}
	Menu::Settings::openKey = key;
}

void Menu::removeHotkey(std::string name) {
	std::string keypath = "X-Folder/keys.ini";
	INI::WriteInt(keypath, 0x00, "hotkeys", name);
}

int hotkeyPressed = GetTickCount();
int hotkeyDelay = 200;
void Menu::checkHotkey(std::string name, bool & b00l) {
	std::string keypath = "X-Folder/keys.ini";
	int key = INI::GetInt(keypath, "hotkeys", name);
	if (GetTickCount() - hotkeyPressed > hotkeyDelay) {
		if (key != hotkeyKey && key != 0x00 && IsKeyPressed(key)) {
			b00l = !b00l;
			hotkeyPressed = GetTickCount();
		}
	}
}

void Menu::checkHotkey(std::string name, bool & b00l, std::function<void()> func) {
	std::string keypath = "X-Folder/keys.ini";
	int key = INI::GetInt(keypath, "hotkeys", name);
	if (GetTickCount() - hotkeyPressed > hotkeyDelay) {
		if (key != hotkeyKey && key != 0x00 && IsKeyPressed(key)) {
			func();
			b00l = !b00l;
			hotkeyPressed = GetTickCount();
		}
	}
}

void Menu::checkHotkey(std::string name, std::function<void()> func) {
	std::string keypath = "X-Folder/keys.ini";
	int key = INI::GetInt(keypath, "hotkeys", name);
	if (GetTickCount() - hotkeyPressed > hotkeyDelay) {
		if (key != hotkeyKey && key != 0x00 && IsKeyPressed(key)) {
			func();
			hotkeyPressed = GetTickCount();
		}
	}
}

bool Menu::checkHotkey(std::string name) {
	std::string keypath = "X-Folder/keys.ini";
	int key = INI::GetInt(keypath, "hotkeys", name);
	if (GetTickCount() - hotkeyPressed > hotkeyDelay) {
		if (key != hotkeyKey && key != 0x00 && IsKeyPressed(key)) {
			return true;
			hotkeyPressed = GetTickCount();
		}
	}
	return false;
}

bool Menu::VipOption(const char * option) {
	if (USER::VIP_TEST || USER::VERSION_TO_INT(current_version) > 0) {
		return Menu::Option(option);
	}
	else {
		ostringstream txt; txt << "~p~[VIP] ~m~" << option;
		Menu::Option(txt.str().c_str());
	}
	return false;
}

bool Menu::VipOption(const char * option, std::function<void()> function) {
	if (USER::VIP_TEST || USER::VERSION_TO_INT(current_version) > 0) {
		return Menu::Option(option, function);
	}
	else {
		ostringstream txt; txt << "~p~[VIP] ~m~" << option;
		Menu::Option(txt.str().c_str());
	}
	return false;
}

bool Menu::VipToggle(const char * option, bool & b00l) {
	if (USER::VIP_TEST || USER::VERSION_TO_INT(current_version) > 0) {
		return Menu::Toggle(option, b00l);
	}
	else {
		bool alwaysfalse = false;
		ostringstream txt; txt << "~p~[VIP] ~m~" << option;
		Menu::Toggle(txt.str().c_str(), alwaysfalse);
	}
	return false;
}

bool Menu::VipToggle(const char * option, bool & b00l, std::function<void()> function) {
	if (USER::VIP_TEST || USER::VERSION_TO_INT(current_version) > 0) {
		return Menu::Toggle(option, b00l, function);
	}
	else {
		bool alwaysfalse = false;
		ostringstream txt; txt << "~p~[VIP] ~m~" << option;
		Menu::Toggle(txt.str().c_str(), alwaysfalse);
	}
	return false;
}

bool Menu::VipToggle(const char * option, bool & b00l, bool hotkey) {
	if (USER::VIP_TEST || USER::VERSION_TO_INT(current_version) > 0) {
		return Menu::Toggle(option, b00l, hotkey);
	}
	else {
		bool alwaysfalse = false;
		ostringstream txt; txt << "~p~[VIP] ~m~" << option;
		Menu::Toggle(txt.str().c_str(), alwaysfalse);
	}
	return false;
}

bool Menu::VipToggle(const char * option, bool & b00l, std::function<void()> function, bool hotkey) {
	if (USER::VIP_TEST || USER::VERSION_TO_INT(current_version) > 0) {
		return Menu::Toggle(option, b00l, function, hotkey);
	}
	else {
		bool alwaysfalse = false;
		ostringstream txt; txt << "~p~[VIP] ~m~" << option;
		Menu::Toggle(txt.str().c_str(), alwaysfalse);
	}
	return false;
}

bool Menu::VipInt(const char * option, int & _int, int min, int max) {
	if (USER::VIP_TEST || USER::VERSION_TO_INT(current_version) > 0) {
		return Menu::Int(option, _int, min, max);
	}
	else {
		int alwayszero = 0;
		ostringstream txt; txt << "~p~[VIP] ~m~" << option;
		Menu::Int(txt.str().c_str(), alwayszero, 0, 0);
	}
	return false;
}

bool Menu::VipInt(const char * option, int & _int, int min, int max, int step) {
	if (USER::VIP_TEST || USER::VERSION_TO_INT(current_version) > 0) {
		return Menu::Int(option, _int, min, max, step);
	}
	else {
		int alwayszero = 0;
		ostringstream txt; txt << "~p~[VIP] ~m~" << option;
		Menu::Int(txt.str().c_str(), alwayszero, 0, 0);
	}
	return false;
}

bool Menu::VipInt(const char * option, int & _int, int min, int max, std::function<void()> function) {
	if (USER::VIP_TEST || USER::VERSION_TO_INT(current_version) > 0) {
		return Menu::Int(option, _int, min, max, 1, function);
	}
	else {
		int alwayszero = 0;
		ostringstream txt; txt << "~p~[VIP] ~m~" << option;
		Menu::Int(txt.str().c_str(), alwayszero, 0, 0);
	}
	return false;
}

bool Menu::VipInt(const char * option, int & _int, int min, int max, int step, std::function<void()> function) {
	if (USER::VIP_TEST || USER::VERSION_TO_INT(current_version) > 0) {
		return Menu::Int(option, _int, min, max, step, function);
	}
	else {
		int alwayszero = 0;
		ostringstream txt; txt << "~p~[VIP] ~m~" << option;
		Menu::Int(txt.str().c_str(), alwayszero, 0, 0);
	}
	return false;
}

bool Menu::VipMenuOption(const char * option, SubMenus newSub) {
	if (USER::VIP_TEST || USER::VERSION_TO_INT(current_version) > 0) {
		return Menu::MenuOption(option, newSub);
	}
	else {
		ostringstream txt; txt << "~p~[VIP] ~m~" << option;
		Menu::Option(txt.str().c_str());
		if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
			Drawing::Text("2", Settings::arrow, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.023f), Settings::menuY + Settings::optionCount * 0.035f + 0.120f }, { Settings::textSize + 0.1f, Settings::textSize + 0.1f }, true);
		else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
			Drawing::Text("2", Settings::arrow, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.023f), Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.125f }, { Settings::textSize + 0.1f, Settings::textSize + 0.1f }, true);
	}
	return false;
}

bool Menu::TpOption(const char * option, Vector3 coords, std::string pic) {
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	Option(option);
	if (onThis && Settings::selectPressed) {
		if (pic != "") {
			Features::drawMap(Menu::Settings::currentOption, pic);
		}
		if (Settings::selectPressed) {
			Entity handle;
			PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : PLAYER::PLAYER_PED_ID();
			ENTITY::SET_ENTITY_COORDS(handle, coords.x, coords.y, coords.z, false, false, false, false);
			return true;
		}
	}
	return false;
}


//Smooth Scrolling
float Menu::Settings::ScrollerSpeed = 0.01f; //Or change it.
bool Menu::Settings::enable_smooth = true;
float prevf;
int prevOption = 0; //Add prevOption = 1 to open key on Menu::Checks::Controlls in gui.cpp and on numpad0 (back)
void Menu::scroll(int* prev, const int cur)
{
	if (prevf == NULL)
		prevf = *prev * 0.035f + 0.1415f;
	const auto curf = cur * 0.035f + 0.1415f;
	if (*prev != cur)
	{
		//Drawing::Rect(Settings::scroller, { Settings::menuX, Settings::menuY + (cur)*0.035f + 0.1415f }, { Menu::Settings::menuWidth, 0.035f }); //0.038f
		if (prevf < curf)
		{
			if (prevf + Settings::ScrollerSpeed > curf)
				prevf = prevf + (curf - prevf);
			else
				prevf = prevf + Settings::ScrollerSpeed;
			Drawing::Rect(Settings::scroller, { Settings::menuX, Settings::menuY + prevf }, { Menu::Settings::menuWidth, 0.035f }); //0.038f
			if (Settings::enable_scrollbar) {
				Drawing::Rect(Settings::scroller, { Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + prevf }, { 0.008f, 0.035f });
			}
			if (prevf >= curf)
			{
				prevf = curf;
				*prev = cur;
			}
		}
		if (prevf > curf)
		{
			if (prevf - Settings::ScrollerSpeed < curf)
				prevf = prevf - (prevf - curf);
			prevf = prevf - Settings::ScrollerSpeed;
			Drawing::Rect(Settings::scroller, { Settings::menuX, Settings::menuY + prevf }, { Menu::Settings::menuWidth, 0.035f }); //0.038f
			if (Settings::enable_scrollbar) {
				Drawing::Rect(Settings::scroller, { Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + prevf }, { 0.008f, 0.035f });
			}
			if (prevf <= curf)
			{
				prevf = curf;
				*prev = cur;
			}
		}
	}
	else
	{
		*prev = cur;
		Drawing::Rect(Settings::scroller, { Settings::menuX, Settings::menuY + (cur)*0.035f + 0.1415f }, { Menu::Settings::menuWidth, 0.035f });
		if (Settings::enable_scrollbar) {
			Drawing::Rect(Settings::scroller, { Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + (cur)*0.035f + 0.1415f }, { 0.008f, 0.035f });
		}
	}
}

bool Menu::Option(const char * option)
{
	Settings::optionCount++;
	//Menu::drawScrollbar(16, Menu::Settings::optionCount);
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	//Menu::drawScrollbar(12, Menu::Settings::optionCount);

	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
	{
		Drawing::Text(option, Settings::optionText, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.02f), Settings::menuY + (Settings::optionCount)*0.035f + 0.128f }, { Settings::textSize, Settings::textSize }, false);
		Drawing::Rect(Settings::optionRect, { Settings::menuX, Settings::menuY + (Settings::optionCount)*0.035f + 0.1415f }, { Menu::Settings::menuWidth, 0.035f });

		if (Settings::enable_scrollbar) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + (Settings::optionCount)*0.035f + 0.1415f }, { 0.01f, 0.035f });
		}

		/*if (onThis) {
			Drawing::Rect(Settings::scroller, { Settings::menuX, Settings::menuY + (Settings::optionCount)*0.035f + 0.1415f }, { Menu::Settings::menuWidth, 0.035f });
			if (Settings::enable_scrollbar) {
				Drawing::Rect(Settings::scroller, { Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + (Settings::optionCount)*0.035f + 0.1415f }, { 0.008f, 0.035f });
			}
		}*/

		if (Settings::enable_smooth) {
			if (Settings::optionCount >= 16) {
				if (onThis) {
					Drawing::Rect(Settings::scroller, { Settings::menuX, Settings::menuY + (Settings::optionCount)*0.035f + 0.1415f }, { Menu::Settings::menuWidth, 0.035f });
					if (Settings::enable_scrollbar) {
						Drawing::Rect(Settings::scroller, { Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + (Settings::optionCount)*0.035f + 0.1415f }, { 0.008f, 0.035f });
					}
				}
			}
			else if (Settings::optionCount > 0) {
				onThis ? scroll(&prevOption, Menu::Settings::currentOption) : NULL;
			}
		}
		else {
			if (onThis) {
				Drawing::Rect(Settings::scroller, { Settings::menuX, Settings::menuY + (Settings::optionCount)*0.035f + 0.1415f }, { Menu::Settings::menuWidth, 0.035f });
				if (Settings::enable_scrollbar) {
					Drawing::Rect(Settings::scroller, { Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + (Settings::optionCount)*0.035f + 0.1415f }, { 0.008f, 0.035f });
				}
			}
		}
	}
	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
	{
		Drawing::Text(option, Settings::optionText, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.02f), Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.128f }, { Settings::textSize, Settings::textSize }, false);
		Drawing::Rect(Settings::optionRect, { Settings::menuX, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { Menu::Settings::menuWidth, 0.035f });
		
		if (Settings::enable_scrollbar) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.01f, 0.035f });
		}

		/*if (onThis) {
			Drawing::Rect(Settings::scroller, { Settings::menuX, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { Menu::Settings::menuWidth, 0.035f });			
			if (Settings::enable_scrollbar) {
				Drawing::Rect(Settings::scroller, { Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.008f, 0.035f });
			}
		}*/

		if (Settings::enable_smooth) {
			if (Settings::optionCount >= 16) {
				if (onThis) {
					Drawing::Rect(Settings::scroller, { Settings::menuX, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { Menu::Settings::menuWidth, 0.035f });
					if (Settings::enable_scrollbar) {
						Drawing::Rect(Settings::scroller, { Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.008f, 0.035f });
					}
				}
			}
			else if (Settings::optionCount > 0) {
				onThis ? scroll(&prevOption, Menu::Settings::currentOption) : NULL;
			}
		}
		else {
			if (onThis) {
				Drawing::Rect(Settings::scroller, { Settings::menuX, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { Menu::Settings::menuWidth, 0.035f });
				if (Settings::enable_scrollbar) {
					Drawing::Rect(Settings::scroller, { Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.008f, 0.035f });
				}
			}
		}
	}
	if (Settings::currentOption == Settings::optionCount)
	{
		if (Settings::selectPressed)
		{
			return true;
		}
	}
	return false;
}

void Menu::SimpleSmoothScrolling() {
	float toPos;
	if (Settings::currentOption <= 16 && Settings::optionCount <= 16) {
		if (Menu::Settings::currentOption > Menu::Settings::maxVisOptions) {
			toPos = ((Menu::Settings::maxVisOptions * 0.035f) + 0.1415f);
		}
		else {
			toPos = ((Menu::Settings::currentOption * 0.035f) + 0.1415f);
		}
	}
	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption) {
		toPos = (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415;
	}
	if (Menu::Settings::scrollBarPos > toPos || Settings::currentOption > 16) {
		Menu::Settings::scrollBarPos -= 0.005f;
	}
	if (Menu::Settings::scrollBarPos < toPos) {
		Menu::Settings::scrollBarPos += 0.005f;
	}
}
float Menu::Settings::scrollBarPos = 0.0f;

bool Menu::Option(const char * option, std::function<void()> function)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}

bool Menu::Break(const char * title)
{
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::currentOption <= 99999 && Settings::optionCount <= 99999)
	{
		Drawing::Text(title, Settings::breakText, { Settings::menuX, Settings::menuY + (Settings::optionCount)*0.035f + 0.128f }, { 0.3f, 0.3f }, true);
		Drawing::Rect(Settings::breakrect, { Settings::menuX, Settings::menuY + (Settings::optionCount)*0.035f + 0.1415f }, { Settings::menuWidth, 0.035f });
	}
	/*else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
	{
		//Standart
		Drawing::Text(title, Settings::optionText, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.02f), Settings::menuY + (Settings::optionCount)*0.035f + 0.128f }, { 0.3f, 0.3f }, false);
		Drawing::Rect(Settings::breakrect, { Settings::menuX, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { Settings::menuWidth, 0.035f });
	}*/
	return false;
}
bool Menu::MenuOption(const char * option, SubMenus newSub)
{
	Option(option);

	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text("2", onThis ? Settings::arrow : Settings::arrow, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.023f), Settings::menuY + Settings::optionCount * 0.035f + 0.120f }, { Settings::textSize + 0.1f, Settings::textSize + 0.1f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text("2", onThis ? Settings::arrow : Settings::arrow, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.023f), Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.125f }, { Settings::textSize + 0.1f, Settings::textSize + 0.1f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		MenuLevelHandler::MoveMenu(newSub);
		return true;
	}
	return false;
}

void Menu::PlayerOption(int i) {
	if (Menu::Option(PLAYER::GET_PLAYER_NAME(i))) {
		selectedPlayer = i;
		MenuLevelHandler::MoveMenu(pmenu);
	}
}

void addToggleState(const char *option, bool b00l) {
	ostringstream ss; ss << option;
	if (IsKeyPressed(VK_F11)) {
		INI::WriteBool("X-Folder/toggles.ini", b00l, "toggles", ss.str());
	}
}

bool Menu::Toggle(const char * option, bool & b00l)
{
	Option(option);
	if (b00l)
	{
		if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
			Drawing::Spriter(Menu::Settings::toggleYTD, Menu::Settings::toggleON, Settings::menuX + (Settings::scrollbarWidthIndex - 0.028f), Settings::menuY + (Settings::optionCount * 0.035f + 0.141f), 0.03f, 0.05f, 0, 255, 255, 255, 255);
			//Drawing::Spriter("commonmenu", "shop_box_tick", Settings::menuX + 0.092f, (Settings::optionCount * 0.035f + 0.141f), 0.030f, 0.050f, 0, 255, 255, 255, 255);
		else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
			Drawing::Spriter(Menu::Settings::toggleYTD, Menu::Settings::toggleON, Settings::menuX + (Settings::scrollbarWidthIndex - 0.028f), Settings::menuY + ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.03f, 0.05f, 0, 255, 255, 255, 255);
			//Drawing::Spriter("commonmenu", "shop_box_tick", Settings::menuX + 0.092f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.030f, 0.050f, 0, 255, 255, 255, 255);
	}
	else
	{
		if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
			Drawing::Spriter(Menu::Settings::toggleYTD, Menu::Settings::toggleOFF, Settings::menuX + (Settings::scrollbarWidthIndex - 0.028f), Settings::menuY + (Settings::optionCount * 0.035f + 0.141f), 0.03f, 0.05f, 0, 255, 255, 255, 255);
			//Drawing::Spriter("commonmenu", "shop_box_blank", Settings::menuX + 0.092f, (Settings::optionCount * 0.035f + 0.141f), 0.030f, 0.050f, 0, 255, 255, 255, 255);
		else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
			Drawing::Spriter(Menu::Settings::toggleYTD, Menu::Settings::toggleOFF, Settings::menuX + (Settings::scrollbarWidthIndex - 0.028f), Settings::menuY + ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.03f, 0.05f, 0, 255, 255, 255, 255);
			//Drawing::Spriter("commonmenu", "shop_box_blank", Settings::menuX + 0.092f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.030f, 0.050f, 0, 255, 255, 255, 255);
	}
	if (Settings::optionCount == Settings::currentOption) {
		addToggleState(option, b00l);
		if (Settings::selectPressed) {
			b00l ^= 1;
			return true;
		}
	}
	return false;
}

bool Menu::Toggle(const char * option, bool & b00l, std::function<void()> function)
{
	Toggle(option, b00l);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}

bool Menu::Toggle(const char * option, bool & b00l, bool hotkey) {
	Toggle(option, b00l);
	//checkHotkey(b00l, name);
	if (Settings::optionCount == Settings::currentOption) {
		if (IsKeyPressed(hotkeyKey)) {
			ostringstream ss;
			ss << option;
			addHotkey(ss.str());
		}
		if (Settings::selectPressed) {
			return true;
		}
	}
	return false;
}

bool Menu::Toggle(const char * option, bool & b00l, std::function<void()> function, bool hotkey) {
	Toggle(option, b00l);
	//checkHotkey(b00l, name, function);
	if (Settings::optionCount == Settings::currentOption) {
		if (IsKeyPressed(hotkeyKey)) {
			ostringstream ss;
			ss << option;
			addHotkey(ss.str());
		}
		if (Settings::selectPressed) {
			function();
			return true;
		}
	}
	return false;
}

bool Menu::Int(const char * option, int & _int, int min, int max)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_int < max ? _int++ : _int = min;
		}
		if (Settings::rightPressed) {
			_int >= min ? _int-- : _int = max;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.052f), Settings::menuY + Settings::optionCount * 0.035f + 0.128f }, { Settings::textSize - 0.003f, Settings::textSize - 0.003f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.052f), Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { Settings::textSize - 0.003f, Settings::textSize - 0.003f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::Int(const char * option, int & _int, int min, int max, int step)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_int < max ? _int += step : _int = min;
		}
		if (Settings::rightPressed) {
			_int >= min ? _int -= step : _int = max;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.052f), Settings::menuY + Settings::optionCount * 0.035f + 0.125f }, { Settings::textSize - 0.003f, Settings::textSize - 0.003f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.052f), Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { Settings::textSize - 0.003f, Settings::textSize - 0.003f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::Int(const char * option, int & _int, int min, int max, std::function<void()> function)
{
	Int(option, _int, min, max);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::Int(const char * option, int & _int, int min, int max, int step, std::function<void()> function)
{
	Int(option, _int, min, max, step);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
#pragma warning(disable: 4244)
bool Menu::Float(const char * option, float & _float, int min, int max)
{
	Option(option); //swapped left / right

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::rightPressed) {
			_float <= min ? _float = max : _float -= 0.1f;
		}
		if (Settings::leftPressed) {
			_float >= max ? _float = min : _float += 0.1f;
		}
		_float < min ? _float = max : _float > max ? _float = min : NULL;
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_float) + " >"), Settings::optionText, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.052f), Settings::menuY + Settings::optionCount * 0.035f + 0.128f }, { Settings::textSize - 0.003f, Settings::textSize - 0.003f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_float) + " >"), Settings::optionText, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.052f), Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { Settings::textSize - 0.003f, Settings::textSize - 0.003f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::Float(const char * option, float & _float, int min, int max, int step)
{
	Option(option); //swapped left / right

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::rightPressed) {
			_float <= min ? _float = max : _float -= 0.1f;
		}
		if (Settings::leftPressed) {
			_float >= max ? _float = min : _float += 0.1f;
		}
		_float < min ? _float = max : _float > max ? _float = min : NULL;
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_float) + " >"), Settings::optionText, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.052f), Settings::menuY + Settings::optionCount * 0.035f + 0.128f }, { Settings::textSize - 0.003f, Settings::textSize - 0.003f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_float) + " >"), Settings::optionText, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.052f), Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { Settings::textSize - 0.003f, Settings::textSize - 0.003f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
#pragma warning(default: 4244)
#pragma warning(disable: 4267)
bool Menu::IntVector(const char * option, std::vector<int> Vector, int & position)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		int max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.052f), Settings::menuY + Settings::optionCount * 0.035f + 0.125f }, { Settings::textSize - 0.003f, Settings::textSize - 0.003f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.052f), Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { Settings::textSize - 0.003f, Settings::textSize - 0.003f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::FloatVector(const char * option, std::vector<float> Vector, int & position)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar("<" + std::to_string(Vector[position]) + ">"), Settings::optionText, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.052f), Settings::menuY + Settings::optionCount * 0.035f + 0.125f }, { Settings::textSize - 0.003f, Settings::textSize - 0.003f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar("<" + std::to_string(Vector[position]) + ">"), Settings::optionText, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.052f), Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { Settings::textSize - 0.003f, Settings::textSize - 0.003f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::StringVector(const char * option, std::vector<std::string> Vector, int & position)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar("<" + (Vector[position]) + ">"), Settings::optionText, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.052f), (Settings::menuY + Settings::optionCount * 0.035f + 0.125f) }, { Settings::textSize - 0.003f, Settings::textSize - 0.003f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar("<" + (Vector[position]) + ">"), Settings::optionText, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.052f), (Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f) }, { Settings::textSize - 0.003f, Settings::textSize - 0.003f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::StringVector(const char * option, std::vector<char*> Vector, int & position)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}
	ostringstream ss; ss << "<" << Vector[position] << ">";
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text((char*)ss.str().c_str(), Settings::optionText, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.052f), (Settings::menuY + Settings::optionCount * 0.035f + 0.125f) }, { Settings::textSize - 0.003f, Settings::textSize - 0.003f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text((char*)ss.str().c_str(), Settings::optionText, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.052f), (Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f) }, { Settings::textSize - 0.003f, Settings::textSize - 0.003f }, true); //0.5 = old

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
#pragma warning(default: 4267)
bool Menu::Teleport(const char * option, Vector3 coords)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		Entity handle;
		PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : PLAYER::PLAYER_PED_ID();
		ENTITY::SET_ENTITY_COORDS(handle, coords.x, coords.y, coords.z, false, false, false, false);
		return true;
	}
	return false;
}
bool Menu::Teleport(const char * option, Vector3 coords, std::function<void()> function)
{
	Teleport(option, coords);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}
void Menu::info(const char * info)
{
	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
	{
		if (bool onThis = true) { Drawing::Text(info, Settings::optionText, { Settings::menuX - 0.100f, Settings::menuY + 17 * 0.035f + 0.1600f }, { 0.25f, 0.25f }, false); }
	}
	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
	{
		if (bool onThis = true) { Drawing::Text(info, Settings::optionText, { Settings::menuX - 0.100f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1300f }, { 0.25f, 0.25f }, false); }
	}
}
void Menu::End()
{
	if (Menu::Settings::displayEnd) {
		int opcount = Settings::optionCount;
		int currop = Settings::currentOption;
		if (opcount >= 16) {
			if (Settings::enable_scrollbar) { Drawing::Rect(Settings::secondary, { Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + 17 * 0.035f + 0.1330f }, { 0.01f, 0.018f }); }
			if (Settings::enable_scrollbar) { Drawing::Text("4", Settings::arrow, { Settings::menuX - Settings::scrollbarWidthIndex - 0.005f, Settings::menuY + 17 * 0.035f + 0.1160f }, { 0.30f, 0.30f }, false); }

			Drawing::Text(Tools::StringToChar(std::to_string(currop) + "/" + std::to_string(opcount)), Settings::count, { Settings::menuX + 0.087f + (Settings::scrollbarWidthIndex - 0.12f), Settings::menuY + 17 * 0.035f - 0.467f }, { 0.3f, 0.3f }, true);
			Drawing::Rect(Settings::breakrect, { Settings::menuX, Settings::menuY + 17 * 0.035f + 0.1365f }, { Settings::menuWidth, 0.025f });
			//Drawing::Rect(Settings::breakrect, { Settings::menuX, 17 * 0.035f + 0.1780f }, { 0.21f, 0.050f });
			Drawing::Spriter("customheader", Settings::menuend, Settings::menuX, Settings::menuY + ((16 + 1) * 0.035f + 0.136f), 0.02f, 0.035f, 180, Settings::arrow.r, Settings::arrow.g, Settings::arrow.b, Settings::arrow.a);
		}
		else if (opcount > 0) {
			if (Settings::enable_scrollbar) { Drawing::Rect(Settings::secondary, { Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + (Settings::optionCount + 1) * 0.035f + 0.1330f }, { 0.01f, 0.019f }); }
			if (Settings::enable_scrollbar) { Drawing::Text("4", Settings::arrow, { Settings::menuX - Settings::scrollbarWidthIndex - 0.005f, Settings::menuY + (Settings::optionCount + 1) * 0.035f + 0.1160f }, { 0.30f, 0.30f }, false); }

			Drawing::Text(Tools::StringToChar(std::to_string(currop) + "/" + std::to_string(opcount)), Settings::count, { Settings::menuX + 0.087f + (Settings::scrollbarWidthIndex - 0.12f), Settings::menuY + 17 * 0.035f - 0.467f }, { 0.3f, 0.3f }, true);
			Drawing::Rect(Settings::breakrect, { Settings::menuX, Settings::menuY + (Settings::optionCount + 1) * 0.035f + 0.1365f }, { Settings::menuWidth, 0.025f });
			//Drawing::Rect(Settings::breakrect, { Settings::menuX, (Settings::optionCount + 1) * 0.035f + 0.1780f }, { 0.21f, 0.050f });
			Drawing::Spriter("customheader", Settings::menuend, Settings::menuX, Settings::menuY + ((Settings::optionCount + 1) * 0.035f + 0.136f), 0.020f, 0.035f, 180, Settings::arrow.r, Settings::arrow.g, Settings::arrow.b, Settings::arrow.a);
		}
	}
}

bool Menu::ListVector(const char * option, std::vector<std::string> Vector, int & position)
{
	constexpr static const VECTOR2_2 textSize = { 0.45f, 0.45f };
	bool onThis = Menu::Settings::currentOption == Menu::Settings::optionCount + 1 ? true : false;
	Menu::Option("");

	if (Menu::Settings::optionCount == Menu::Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Menu::Settings::rightPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Menu::Settings::leftPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Menu::Settings::currentOption <= Menu::Settings::maxVisOptions && Menu::Settings::optionCount <= Menu::Settings::maxVisOptions) {
		std::string SelectedChar
			= UI::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Vector[position])));
		if (SelectedChar == "NULL") SelectedChar = Vector[position];

		UI::SET_TEXT_COLOUR(255, 255, 255, 255);
		UI::SET_TEXT_FONT(6);
		UI::SET_TEXT_SCALE(textSize.w, textSize.h);
		UI::SET_TEXT_CENTRE(false);
		if (Menu::Settings::DrawTextOutline) {
			UI::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 0);
			UI::SET_TEXT_EDGE(1, 0, 0, 0, 0);
			UI::SET_TEXT_OUTLINE();
		}
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		std::string s = option;
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Tools::StringToChar(s + "  [" + SelectedChar + "] ~bold~<>"));
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(Menu::Settings::menuX - 0.09f, Menu::Settings::optionCount * 0.035f + 0.125f);
	}
	else if (Menu::Settings::optionCount > Menu::Settings::currentOption - Menu::Settings::maxVisOptions && Menu::Settings::optionCount <= Menu::Settings::currentOption) {
		std::string SelectedChar
			= UI::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Vector[position])));
		if (SelectedChar == "NULL") SelectedChar = Vector[position];

		UI::SET_TEXT_COLOUR(255, 255, 255, 255);
		UI::SET_TEXT_FONT(6);
		UI::SET_TEXT_SCALE(textSize.w, textSize.h);
		UI::SET_TEXT_CENTRE(false);
		UI::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 0);
		UI::SET_TEXT_EDGE(1, 0, 0, 0, 0);
		UI::SET_TEXT_OUTLINE();
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		std::string s = option;
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Tools::StringToChar(s + "  [" + SelectedChar + "] ~bold~<>"));
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(Menu::Settings::menuX - 0.09f, (Menu::Settings::optionCount - (Menu::Settings::currentOption - Menu::Settings::maxVisOptions))*0.035f + 0.125f);
	}

	if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::selectPressed) return true;
	else if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::leftPressed) return false;
	else if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::rightPressed) return false;
	return false;
}

int IconNotification(char *text, char *text2, char *Subject)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG("CHAR_GANGAPP", "CHAR_GANGAPP", false, 7, text2, Subject, 1.0, "___Menu");
	return UI::_DRAW_NOTIFICATION(1, 1);
}
void PlaySoundFrontend_default(char* sound_name)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, sound_name, "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
}
void PlaySoundFrontend_default2(char* sound_name)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, sound_name, "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS", 0);
}

int Menu::Settings::keyPressDelay = 200;
int Menu::Settings::keyPressPreviousTick = GetTickCount();
int Menu::Settings::keyPressDelay2 = 100;
int Menu::Settings::keyPressPreviousTick2 = GetTickCount();
int Menu::Settings::keyPressDelay3 = 140;
int Menu::Settings::keyPressPreviousTick3 = GetTickCount();
int Menu::Settings::openKey = VK_MULTIPLY;
int Menu::Settings::backKey = VK_NUMPAD0;
int Menu::Settings::upKey = VK_NUMPAD8;
int Menu::Settings::downKey = VK_NUMPAD2;
int Menu::Settings::leftKey = VK_NUMPAD4;
int Menu::Settings::rightKey = VK_NUMPAD6;
int Menu::Settings::selectKey = VK_NUMPAD5;
int Menu::Settings::arrowupKey = VK_UP;
int Menu::Settings::arrowdownKey = VK_DOWN;
int Menu::Settings::arrowleftKey = VK_LEFT;
int Menu::Settings::arrowrightKey = VK_RIGHT;
int Menu::Settings::enterKey = VK_RETURN;
int Menu::Settings::deleteKey = VK_BACK;

#pragma endregion

bool Menu::Settings::controllerinput = true;
void Menu::Checks::Controlls()
{
	Settings::selectPressed = false;
	Settings::leftPressed = false;
	Settings::rightPressed = false;
	if (GetTickCount() - Settings::keyPressPreviousTick > Settings::keyPressDelay) {
		if (GetTickCount() - Settings::keyPressPreviousTick2 > Settings::keyPressDelay2) {
			if (GetTickCount() - Settings::keyPressPreviousTick3 > Settings::keyPressDelay3) {
				if (IsKeyPressed(Menu::Settings::openKey) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlScriptRB) && CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight) && Settings::controllerinput) {
					Settings::menuLevel == 0 ? MenuLevelHandler::MoveMenu(SubMenus::mainmenu) : Settings::menuLevel == 1 ? MenuLevelHandler::BackMenu() : NULL;
					/*if (Settings::menuLevel == 0) {
						MenuLevelHandler::MoveMenu(SubMenus::mainmenu);
					}
					else {
						if (Settings::menuLevel == 1) {
							MenuLevelHandler::BackMenu();
						}
					}*/
					prevOption = 1;
					Settings::keyPressPreviousTick = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD0) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendCancel) && Settings::controllerinput) {
					Settings::menuLevel > 0 ? MenuLevelHandler::BackMenu() : NULL;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("BACK");

					prevOption = 1;
					Settings::keyPressPreviousTick = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD8) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendUp) && Settings::controllerinput) {
					Settings::currentOption > 1 ? Settings::currentOption-- : Settings::currentOption = Settings::optionCount;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("NAV_UP_DOWN");

					Settings::keyPressPreviousTick2 = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD2) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown) && Settings::controllerinput) {
					Settings::currentOption < Settings::optionCount ? Settings::currentOption++ : Settings::currentOption = 1;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("NAV_UP_DOWN");

					Settings::keyPressPreviousTick2 = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD6) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight) && Settings::controllerinput) {
					Settings::leftPressed = true;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("NAV_UP_DOWN");

					Settings::keyPressPreviousTick3 = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD4) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneLeft) && Settings::controllerinput) {
					Settings::rightPressed = true;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("NAV_UP_DOWN");

					Settings::keyPressPreviousTick3 = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept) && Settings::controllerinput) {
					Settings::selectPressed = true;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("SELECT");

					Settings::keyPressPreviousTick = GetTickCount();
				}
			}
		}
	}
	Settings::optionCount = 0;
}
#pragma warning(default : 4018)
void Menu::MenuLevelHandler::MoveMenu(SubMenus menu)
{
	Settings::menusArray[Settings::menuLevel] = Settings::currentMenu;
	Settings::optionsArray[Settings::menuLevel] = Settings::currentOption;
	Settings::menuLevel++;
	Settings::currentMenu = menu;
	Settings::currentOption = 1;
}

void Menu::MenuLevelHandler::BackMenu()
{
	Settings::menuLevel--;
	Settings::currentMenu = Settings::menusArray[Settings::menuLevel];
	Settings::currentOption = Settings::optionsArray[Settings::menuLevel];
}

char * Menu::Tools::StringToChar(std::string string)
{
	return _strdup(string.c_str());
}

void Menu::Files::WriteStringToIni(std::string string, std::string file, std::string app, std::string key)
{
	WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), file.c_str());
}

std::string Menu::Files::ReadStringFromIni(std::string file, std::string app, std::string key)
{
	char buf[100];
	GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, file.c_str());
	return (std::string)buf;
}

void Menu::Files::WriteIntToIni(int intValue, std::string file, std::string app, std::string key)
{
	WriteStringToIni(std::to_string(intValue), file, app, key);
}

int Menu::Files::ReadIntFromIni(std::string file, std::string app, std::string key)
{
	return std::stoi(ReadStringFromIni(file, app, key));
}

void Menu::Files::WriteFloatToIni(float floatValue, std::string file, std::string app, std::string key)
{
	WriteStringToIni((std::to_string(floatValue)), file, app, key);
}

float Menu::Files::ReadFloatFromIni(std::string file, std::string app, std::string key)
{
	return std::stof(ReadStringFromIni(file, app, key));
}

void Menu::Files::WriteBoolToIni(bool b00l, std::string file, std::string app, std::string key)
{
	WriteStringToIni(b00l ? "true" : "false", file, app, key);
}

bool Menu::Files::ReadBoolFromIni(std::string file, std::string app, std::string key)
{
	return ReadStringFromIni(file, app, key) == "true" ? true : false;
}

void Menu::Vehicle(std::string texture1, std::string texture2)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		/*if (Menu::Settings::optionCount == Menu::Settings::currentOption) {*/ Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX + 0.24f, Settings::menuY + 0.2f, 0.11f, 0.11f, 0, 255, 255, 255, 255); //}
	}
	else { 
	/*if (Menu::Settings::optionCount == Menu::Settings::currentOption) {*/ Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX - 0.24f, Settings::menuY + 0.2f, 0.11f, 0.11f, 0, 255, 255, 255, 255); //} 
    }
}
void Menu::Map(std::string texture1, std::string texture2)
{
	YTD2();
	if (Menu::Settings::menuX < 0.78f)
	{
		/*if (Menu::Settings::optionCount == Menu::Settings::currentOption) {*/ Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX + 0.22f, Settings::menuY + 0.24f, 0.20f, 0.40f, 0, 255, 255, 255, 255); //}
	}
	else {
		/*if (Menu::Settings::optionCount == Menu::Settings::currentOption) {*/ Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX - 0.22f, Settings::menuY + 0.24f, 0.11f, 0.40f, 0, 255, 255, 255, 255); //} 
	}
}
void Menu::Speedometer(char* text)
{
	Drawing::Text(text, Settings::titleText, { 0.84f, 0.8800f }, { 0.70f, 0.70f }, false);
}
void Menu::fps(char* text)
{
	Drawing::Text(text, Settings::optionText, { 0.84f, 0.050f }, { 0.70f, 0.70f }, false);
}
void Menu::AddSmallTitle(char* text)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.175f, Settings::menuY + 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX + 0.175f, Settings::menuY + 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
	else
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.175f, Settings::menuY + 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX - 0.175f, Settings::menuY + 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
}
void Menu::AddSmallInfo(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, Settings::menuY + ((16 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 16 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, Settings::menuY + (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, ((16 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 16 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}
void Menu::AddSmallTitle2(char* text)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.175f, Settings::menuY + 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX + 0.175f, Settings::menuY + 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
	else
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX - 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
}

void Menu::AddSmallInfo2(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, Settings::menuY + ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, Settings::menuY + (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{

		void Menu::AddSmallTitle3(char* text)
			;
		if (Menu::Settings::menuX < 0.78f)
		{
			Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
			Drawing::Spriter("CommonMenu", "", Settings::menuX + 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
		}
		else
		{
			Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
			Drawing::Spriter("CommonMenu", "", Settings::menuX - 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
		}
	}

	void Menu::AddSmallInfo3(char* text, short line)
		;
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, ((11 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 11 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, ((11 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 11 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}


//Info
void Menu::OptionInfo(const char * info)
{
	if (Menu::Settings::displayEnd) {
		int opcount = Settings::optionCount;
		int currop = Settings::currentOption;
		if (opcount >= 16) {
			Drawing::Rect(Settings::breakrect, { Settings::menuX, Settings::menuY + 17 * 0.035f + 0.1870f }, { 0.21f, 0.050f });
			if (bool onThis = true) { Drawing::Text(info, Settings::optionText, { Settings::menuX - 0.100f, Settings::menuY + 17 * 0.035f + 0.1670f }, { 0.25f, 0.25f }, false); }
		}
		else if (opcount > 0) {
			Drawing::Rect(Settings::breakrect, { Settings::menuX, Settings::menuY + (Settings::optionCount + 1) * 0.035f + 0.1870f }, { 0.21f, 0.050f });
			if (bool onThis = true) { Drawing::Text(info, Settings::optionText, { Settings::menuX - 0.100f, Settings::menuY + (Settings::optionCount + 1) * 0.035f + 0.1670f }, { 0.25f, 0.25f }, false); }
		}
	}
}

void Menu::OptionInfo2(const char * info)
{
	if (Menu::Settings::displayEnd) {
		int opcount = Settings::optionCount;
		int currop = Settings::currentOption;
		if (opcount >= 16) {
			Drawing::Rect(Settings::Nothing, { Settings::menuX, Settings::menuY + 17 * 0.035f + 0.1870f }, { 0.21f, 0.050f });
			if (bool onThis = true) { Drawing::Text(info, Settings::optionText, { Settings::menuX - 0.100f, Settings::menuY + 17 * 0.035f + 0.1870f }, { 0.25f, 0.25f }, false); }
		}
		else if (opcount > 0) {
			Drawing::Rect(Settings::Nothing, { Settings::menuX, Settings::menuY + (Settings::optionCount + 1) * 0.035f + 0.1870f }, { 0.21f, 0.050f });
			if (bool onThis = true) { Drawing::Text(info, Settings::optionText, { Settings::menuX - 0.100f, Settings::menuY + (Settings::optionCount + 1) * 0.035f + 0.1870f }, { 0.25f, 0.25f }, false); }
		}
	}
}

VECTOR2 logCoords = { 0.80f, 17 * 0.035f + 0.1870f };
VECTOR2_2 logSize = { 0.31f, 0.20f };
std::string onscreen[5] = { "", "", "", "", "" };
float txtsize = 0.50;
int onscreenLog = 0;
bool backslashN = true;
void Menu::Log(char* msg) {
	Menu::Drawing::Rect({ 0, 0, 0, 180 }, logCoords, logSize);
	logMessage(" ");
}

void Menu::logMessage(char* msg) {	
	std::string textt;
	if (backslashN) {
		textt = onscreen[0] + "\n" + onscreen[1] + "\n" + onscreen[2] + "\n" + onscreen[3] + "\n" + onscreen[4] + "\n";
	}
	else {
		textt = onscreen[0] + onscreen[1] + onscreen[2] + onscreen[3] + onscreen[4];
	}
	Drawing::Text(textt.c_str(), Settings::optionText, { logCoords.x - 0.15f, logCoords.y - 0.099f }, { txtsize, txtsize }, false);	
}

void Menu::addText(std::string txt, bool withN) {
	bool success = false;
	backslashN = withN;
	for (int i = 0; i < ARRAYSIZE(onscreen); i++) {
		if (onscreen[i] == "") {
			onscreen[i] = txt;
			i = 100000;
			success = true;
		}
	}
	if (!success) {
		for (int i = 0; i < ARRAYSIZE(onscreen)-1; i++) {
			onscreen[i] = onscreen[i + 1];
		}
		onscreen[4] = txt;
	}
}

VECTOR2 statCoords = { 0.80f, 16 * 0.035f + 0.1870f };
VECTOR2_2 statSize = { 0.31f, 0.60f };
float stattxtsize = 0.5;
void Menu::statsinfo() {

	std::string textt;

	int reportkekrp;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), &reportkekrp, -1);
	const auto& reportstringkekrp = "RP: "s + std::to_string(reportkekrp);

	int reportkek;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), &reportkek, -1);
	const auto& reportstringkek = "Exploits: "s + std::to_string(reportkek);

	int reportkek1;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_REPORT_STRENGTH"), &reportkek1, -1);
	const auto& reportstringkek1 = "Report Strength: "s + std::to_string(reportkek1);

	int reportkek2;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_COMMEND_STRENGTH"), &reportkek2, -1);
	const auto& reportstringkek2 = "Commend Strength: "s + std::to_string(reportkek2);

	int reportkek3;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_FRIENDLY"), &reportkek3, -1);
	const auto& reportstringkek3 = "Friendly Commends: "s + std::to_string(reportkek3);

	int reportkek4;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_HELPFUL"), &reportkek4, -1);
	const auto& reportstringkek4 = "Helpfull Commends: "s + std::to_string(reportkek4);

	int reportkek5;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_GRIEFING"), &reportkek5, -1);
	const auto& reportstringkek5 = "Griefing: "s + std::to_string(reportkek5);

	int reportkek6;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_LANGUAGE"), &reportkek6, -1);
	const auto& reportstringkek6 = "Offensive Language: "s + std::to_string(reportkek6);

	int reportkek7;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_UGC"), &reportkek7, -1);
	const auto& reportstringkek7 = "Offensive UGC: "s + std::to_string(reportkek7);

	int reportkek8;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VC_HATE"), &reportkek8, -1);
	const auto& reportstringkek8 = "VC Hate: "s + std::to_string(reportkek8);

	int reportkek9;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_ISPUNISHED"), &reportkek9, -1);

	const auto& reportstringkek9 = "Ispunished: "s + std::to_string(reportkek9);

	int reportkek10;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_KILLS_PLAYERS"), &reportkek10, -1);
	const auto& reportstringkek10 = "Kills: "s + std::to_string(reportkek10);

	int reportkek11;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("AWD_RACES_WON"), &reportkek11, -1);
	const auto& reportstringkek11 = "Won Races: "s + std::to_string(reportkek11);

	int reportkek22;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_TOTAL_EVC"), &reportkek22, -1);
	const auto& reportstringkek22 = "Money earn in Jobs: "s + std::to_string(reportkek22);

	int reportkek113;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_TOTAL_EVC"), &reportkek113, -1);
	const auto& reportstringkek113 = "Total earned Money: "s + std::to_string(reportkek113);




	int reportkek12;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("AWD_NO_ARMWRESTLING_WINS"), &reportkek12, -1);
	const auto& reportstringkek12 = "Armwrestling Wins: "s + std::to_string(reportkek12);

	int reportkek13;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("AWD_FM_DM_WINS"), &reportkek13, -1);
	const auto& reportstringkek13 = "Deathmatch Wins: "s + std::to_string(reportkek13);

	int reportkek14;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_TOTAL_DEATHMATCH_LOST"), &reportkek14, -1);
	const auto& reportstringkek14 = "Deathmatch Losses: "s + std::to_string(reportkek14);


	int reportkek15;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("AWD_FM_DM_TOTALKILLS"), &reportkek15, -1);
	const auto& reportstringkek15 = "Death Match Kills: "s + std::to_string(reportkek15);

	int reportkek16;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_DM_TOTAL_DEATHS"), &reportkek16, -1);
	const auto& reportstringkek16 = "Death Match Deaths: "s + std::to_string(reportkek16);

	int reportkek17;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("AWD_FM_GOLF_WON"), &reportkek17, -1);
	const auto& reportstringkek17 = "Golf Wins: "s + std::to_string(reportkek17);

	int reportkek18;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("AWD_FM_SHOOTRANG_TG_WON"), &reportkek18, -1);
	const auto& reportstringkek18 = "Range Wins: "s + std::to_string(reportkek18);

	int reportkek19;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_TENNIS_MATCHES_WON"), &reportkek19, -1);
	const auto& reportstringkek19 = "Tennis Wins: "s + std::to_string(reportkek19);

	int reportkek21;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("CLUB_POPULARITY"), &reportkek21, -1);
	const auto& reportstringkek21 = "Club Popularity: "s + std::to_string(reportkek21);

	textt = reportstringkekrp + "\n" + reportstringkek + "\n" + reportstringkek1 + "\n" + reportstringkek2 + "\n" + reportstringkek3 + "\n" + reportstringkek4 + "\n" + reportstringkek5 + "\n" + reportstringkek6 + "\n" + reportstringkek7 + "\n" + reportstringkek8 + "\n" + reportstringkek9 + "\n" + reportstringkek10 + "\n" + reportstringkek11 + "\n" + reportstringkek12 + "\n" + reportstringkek13 + "\n" + reportstringkek14 + "\n" + reportstringkek15 + "\n" + reportstringkek16 + "\n" + reportstringkek17 + "\n" + reportstringkek18 + "\n" + reportstringkek19 + "\n" + reportstringkek21 + "\n" + reportstringkek22 + "\n" + reportstringkek113 + "\n";

	Menu::Drawing::Rect({ 0, 0, 0, 180 }, statCoords, statSize);
	Drawing::Text(textt.c_str(), Settings::optionText, { statCoords.x - 0.15f, statCoords.y - 0.299f }, { stattxtsize, stattxtsize }, false);
}


void Menu::PlayerInfoTitle(char* title)
{
	Drawing::Rect(Settings::infocolor, { Settings::menuX + (Settings::scrollbarWidthIndex + 0.049f), Settings::menuY + 0.0620f }, { 0.125f, 0.045f });
	Drawing::Text(title, Settings::titleText, { Settings::menuX + (Settings::scrollbarWidthIndex + 0.049f), Settings::menuY + 0.0500f }, { 0.450f, 0.450f }, true);
}

void Menu::PlayerInfoLine(char* text, short line)
{
	if (line == 1) {
		Drawing::Rect(Settings::optionRect, { Settings::menuX + (Settings::scrollbarWidthIndex + 0.049f), Settings::menuY + 0.3340f }, { 0.125f, 17 * 0.042f + -0.213f }); //0.2840f
		//Drawing::Rect(Settings::optionRect, { Settings::menuX + (Settings::scrollbarWidthIndex + 0.049f), Settings::menuY + 0.3060f }, { 0.125f, 16 * 0.041f + -0.213f }); //0.2840f
	}
	Drawing::Text(text, Settings::count, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.01f), Settings::menuY + (line * 0.020f) + 0.085f }, { 0.25f, 0.25f }, false);
}

bool Menu::Subtitle(const char * title)
{
	Settings::optionCount++;
	Settings::subtitleCount++;
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	bool overThis = Settings::currentOption == Settings::optionCount+1 ? true : false;
	bool underThis = Settings::currentOption == Settings::optionCount-1 ? true : false;
	if (underThis && IsKeyPressed(VK_NUMPAD8) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendUp) && Settings::controllerinput) {
		Settings::currentOption--;
	}
	if (overThis && IsKeyPressed(VK_NUMPAD2) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown) && Settings::controllerinput) {
		Settings::currentOption++;
	}
	if (Settings::currentOption <= 150 && Settings::optionCount <= 150)
	{
		Drawing::Text(title, Settings::optionText, { Settings::menuX - 0.100f, (Settings::optionCount)*0.035f + 0.128f }, { 0.35f, 0.35f }, false);
		Drawing::Rect(Settings::breakrect, { Settings::menuX, (Settings::optionCount)*0.035f + 0.1415f }, { 0.21f, 0.035f });
	}
	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
	{

		Drawing::Text(title, Settings::optionText, { Settings::menuX - 0.100f, (Settings::optionCount)*0.035f + 0.128f }, { 0.35f, 0.35f }, false);
		Drawing::Rect(Settings::breakrect, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.21f, 0.035f });
	}
	return false;
}

/*
COLORS:
- 12, 0, 255
- 255, 20, 31
- 255, 255, 255
- 84, 255, 33
- 255, 179, 17
- 255, 28, 228
- 64, 64, 64
- 53, 255, 251
- 0, 0, 0
- 124, 42, 49
- 127, 106, 0
- 221, 255, 33
- 72, 0, 255
- 113, 124, 81
- 128, 128, 128
- 91, 127, 0
*/

/*
  1/4 2/4 3/4 4/4
  1/3 2/3 3/3 4/3
  1/2 2/2 3/2 4/2
  1/1 2/1 3/1 4/1

  04 08 12 16
  03 07 11 15
  02 06 10 14
  01 05 09 13
*/

int keypressC = GetTickCount();
int keypress2 = 0;
bool Menu::Settings::canSelect = false;
RGBA color = { -1, -1, -1, -1 };
int selected[2] = { 1, 1 };
RGBA Menu::colors() {
	int selectedId;
	RGBA colors[16] = { { 12, 0, 255, 255 }, { 255, 20, 31, 255 }, { 255, 255, 255, 255 }, { 84, 255, 33, 255 }, { 255, 179, 17, 255 }, { 255, 28, 228, 255 }, { 64, 64, 64, 255 }, { 53, 255, 251, 255 }, { 0, 0, 0, 255 }, { 124, 42, 49, 255 }, { 127, 106, 0, 255 }, { 221, 255, 33, 255 }, { 72, 0, 255, 255 }, { 113, 124, 81, 255 }, { 128, 128, 128, 255 }, { 91, 127, 0, 255 } };
	//Drawing::Rect({ 0, 0, 0, 180 }, { 0.52f, 8 * 0.035f + 0.1870f }, { 0.20f, 0.38f });
	RGBA c = { 0, 0, 0, 255 };
	VECTOR2_2 s1 = { 0.02f, 0.038f };
	VECTOR2_2 s2 = { 0.017f, 0.033f };

	Drawing::Rect(colors[0], { 0.52f, 8 * 0.035f + 0.1870f }, { 0.02f, 0.038f });                  //1/1
	Drawing::Rect(colors[1], { 0.03f + 0.52f, 8 * 0.035f + 0.1870f }, { 0.02f, 0.038f });          //1/2
	Drawing::Rect(colors[2], { 0.06f + 0.52f, 8 * 0.035f + 0.1870f }, { 0.02f, 0.038f });          //1/3
	Drawing::Rect(colors[3], { 0.09f + 0.52f, 8 * 0.035f + 0.1870f }, { 0.02f, 0.038f });          //1/4

	Drawing::Rect(colors[4], { 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, { 0.02f, 0.038f });         //2/1
	Drawing::Rect(colors[5], { 0.03f + 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, { 0.02f, 0.038f }); //2/2
	Drawing::Rect(colors[6], { 0.06f + 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, { 0.02f, 0.038f }); //2/3
	Drawing::Rect(colors[7], { 0.09f + 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, { 0.02f, 0.038f }); //2/4

	Drawing::Rect(colors[8], { 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, { 0.02f, 0.038f });          //3/1
	Drawing::Rect(colors[9], { 0.03f + 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, { 0.02f, 0.038f });  //3/2
	Drawing::Rect(colors[10], { 0.06f + 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, { 0.02f, 0.038f }); //3/3
	Drawing::Rect(colors[11], { 0.09f + 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, { 0.02f, 0.038f }); //3/4

	Drawing::Rect(colors[12], { 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, { 0.02f, 0.038f });         //4/1
	Drawing::Rect(colors[13], { 0.03f + 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, { 0.02f, 0.038f }); //4/2
	Drawing::Rect(colors[14], { 0.06f + 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, { 0.02f, 0.038f }); //4/3
	Drawing::Rect(colors[15], { 0.09f + 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, { 0.02f, 0.038f }); //4/4

	if (GetTickCount() - keypressC > Settings::keyPressDelay3) {
		if (IsKeyPressed(VK_NUMPAD8)) {
			keypressC = GetTickCount();
			if (selected[0] > 3) {
				selected[0] = 1;
			}
			else {
				selected[0]++;
			}
		}
		if (IsKeyPressed(VK_NUMPAD2)) {
			keypressC = GetTickCount();
			if (selected[0] < 2) {
				selected[0] = 4;
			}
			else {
				selected[0]--;
			}
		}
		if (IsKeyPressed(VK_NUMPAD4)) {
			keypressC = GetTickCount();
			if (selected[1] < 2) {
				selected[1] = 4;
			}
			else {
				selected[1]--;
			}
		}
		if (IsKeyPressed(VK_NUMPAD6)) {
			keypressC = GetTickCount();
			if (selected[1] > 3) {
				selected[1] = 1;
			}
			else {
				selected[1]++;
			}
		}
	}

	switch (selected[0]) {
	case 1:
	{
		switch (selected[1]) {
		case 1: selectedId = 1; break;
		case 2: selectedId = 2; break;
		case 3: selectedId = 3; break;
		case 4: selectedId = 4; break;
		}
	}
	break;
	case 2:
	{
		switch (selected[1]) {
		case 1: selectedId = 5; break;
		case 2: selectedId = 6; break;
		case 3: selectedId = 7; break;
		case 4: selectedId = 8; break;
		}
	}
	break;
	case 3:
	{
		switch (selected[1]) {
		case 1: selectedId = 9; break;
		case 2: selectedId = 10; break;
		case 3: selectedId = 11; break;
		case 4: selectedId = 12; break;
		}
	}
	break;
	case 4:
	{
		switch (selected[1]) {
		case 1: selectedId = 13; break;
		case 2: selectedId = 14; break;
		case 3: selectedId = 15; break;
		case 4: selectedId = 16; break;
		}
	}
	break;
	}

	switch (selectedId) {
	case 1:
		Drawing::Rect(c, { 0.52f, 8 * 0.035f + 0.1870f }, s1);
		Drawing::Rect(colors[0], { 0.52f, 8 * 0.035f + 0.1870f }, s2);
		break;
	case 2:
		Drawing::Rect(c, { 0.03f + 0.52f, 8 * 0.035f + 0.1870f }, s1);
		Drawing::Rect(colors[1], { 0.03f + 0.52f, 8 * 0.035f + 0.1870f }, s2);
		break;
	case 3:
		Drawing::Rect(c, { 0.06f + 0.52f, 8 * 0.035f + 0.1870f }, s1);
		Drawing::Rect(colors[2], { 0.06f + 0.52f, 8 * 0.035f + 0.1870f }, s2);
		break;
	case 4:
		Drawing::Rect(c, { 0.09f + 0.52f, 8 * 0.035f + 0.1870f }, s1);
		Drawing::Rect(colors[3], { 0.09f + 0.52f, 8 * 0.035f + 0.1870f }, s2);
		break;
	case 5:
		Drawing::Rect(c, { 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, s1);
		Drawing::Rect(colors[4], { 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, s2);
		break;
	case 6:
		Drawing::Rect(c, { 0.03f + 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, s1);
		Drawing::Rect(colors[5], { 0.03f + 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, s2);
		break;
	case 7:
		Drawing::Rect(c, { 0.06f + 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, s1);
		Drawing::Rect(colors[6], { 0.06f + 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, s2);
		break;
	case 8:
		Drawing::Rect(c, { 0.09f + 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, s1);
		Drawing::Rect(colors[7], { 0.09f + 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, s2);
		break;
	case 9:
		Drawing::Rect(c, { 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, s1);
		Drawing::Rect(colors[8], { 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, s2);
		break;
	case 10:
		Drawing::Rect(c, { 0.03f + 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, s1);
		Drawing::Rect(colors[9], { 0.03f + 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, s2);
		break;
	case 11:
		Drawing::Rect(c, { 0.06f + 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, s1);
		Drawing::Rect(colors[10], { 0.06f + 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, s2);
		break;
	case 12:
		Drawing::Rect(c, { 0.09f + 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, s1);
		Drawing::Rect(colors[11], { 0.09f + 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, s2);
		break;
	case 13:
		Drawing::Rect(c, { 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, s1);
		Drawing::Rect(colors[12], { 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, s2);
		break;
	case 14:
		Drawing::Rect(c, { 0.03f + 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, s1);
		Drawing::Rect(colors[13], { 0.03f + 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, s2);
		break;
	case 15:
		Drawing::Rect(c, { 0.06f + 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, s1);
		Drawing::Rect(colors[14], { 0.06f + 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, s2);
		break;
	case 16:
		Drawing::Rect(c, { 0.09f + 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, s1);
		Drawing::Rect(colors[15], { 0.09f + 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, s2);
		break;
	}
		if (Settings::selectPressed) {
			//notifyMap("%i, %i; %i", selected[0], selected[1], selectedId);
			//notifyMap("~r~%i~s~, ~g~%i~s~, ~b~%i", colors[selectedId - 1].r, colors[selectedId - 1].g, colors[selectedId - 1].b);
			color = colors[selectedId - 1];
			//Settings::keyPressPreviousTick = GetTickCount();
		}
	return color;
}

RGBA Menu::Colors(RGBA colors[16]) {
	int selectedId;
	//RGBA colors[16] = { { 12, 0, 255, 255 }, { 255, 20, 31, 255 }, { 255, 255, 255, 255 }, { 84, 255, 33, 255 }, { 255, 179, 17, 255 }, { 255, 28, 228, 255 }, { 64, 64, 64, 255 }, { 53, 255, 251, 255 }, { 0, 0, 0, 255 }, { 124, 42, 49, 255 }, { 127, 106, 0, 255 }, { 221, 255, 33, 255 }, { 72, 0, 255, 255 }, { 113, 124, 81, 255 }, { 128, 128, 128, 255 }, { 91, 127, 0, 255 } };
	//Drawing::Rect({ 0, 0, 0, 180 }, { 0.52f, 8 * 0.035f + 0.1870f }, { 0.20f, 0.38f });
	RGBA c = { 0, 0, 0, 255 };
	VECTOR2_2 s1 = { 0.02f, 0.038f };
	VECTOR2_2 s2 = { 0.017f, 0.033f };

	Drawing::Rect(colors[0], { 0.52f, 8 * 0.035f + 0.1870f }, { 0.02f, 0.038f });                  //1/1
	Drawing::Rect(colors[1], { 0.03f + 0.52f, 8 * 0.035f + 0.1870f }, { 0.02f, 0.038f });          //1/2
	Drawing::Rect(colors[2], { 0.06f + 0.52f, 8 * 0.035f + 0.1870f }, { 0.02f, 0.038f });          //1/3
	Drawing::Rect(colors[3], { 0.09f + 0.52f, 8 * 0.035f + 0.1870f }, { 0.02f, 0.038f });          //1/4

	Drawing::Rect(colors[4], { 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, { 0.02f, 0.038f });         //2/1
	Drawing::Rect(colors[5], { 0.03f + 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, { 0.02f, 0.038f }); //2/2
	Drawing::Rect(colors[6], { 0.06f + 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, { 0.02f, 0.038f }); //2/3
	Drawing::Rect(colors[7], { 0.09f + 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, { 0.02f, 0.038f }); //2/4

	Drawing::Rect(colors[8], { 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, { 0.02f, 0.038f });          //3/1
	Drawing::Rect(colors[9], { 0.03f + 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, { 0.02f, 0.038f });  //3/2
	Drawing::Rect(colors[10], { 0.06f + 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, { 0.02f, 0.038f }); //3/3
	Drawing::Rect(colors[11], { 0.09f + 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, { 0.02f, 0.038f }); //3/4

	Drawing::Rect(colors[12], { 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, { 0.02f, 0.038f });         //4/1
	Drawing::Rect(colors[13], { 0.03f + 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, { 0.02f, 0.038f }); //4/2
	Drawing::Rect(colors[14], { 0.06f + 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, { 0.02f, 0.038f }); //4/3
	Drawing::Rect(colors[15], { 0.09f + 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, { 0.02f, 0.038f }); //4/4

	if (GetTickCount() - keypressC > Settings::keyPressDelay3) {
		if (IsKeyPressed(VK_NUMPAD8)) {
			keypressC = GetTickCount();
			if (selected[0] > 3) {
				selected[0] = 1;
			}
			else {
				selected[0]++;
			}
		}
		if (IsKeyPressed(VK_NUMPAD2)) {
			keypressC = GetTickCount();
			if (selected[0] < 2) {
				selected[0] = 4;
			}
			else {
				selected[0]--;
			}
		}
		if (IsKeyPressed(VK_NUMPAD4)) {
			keypressC = GetTickCount();
			if (selected[1] < 2) {
				selected[1] = 4;
			}
			else {
				selected[1]--;
			}
		}
		if (IsKeyPressed(VK_NUMPAD6)) {
			keypressC = GetTickCount();
			if (selected[1] > 3) {
				selected[1] = 1;
			}
			else {
				selected[1]++;
			}
		}
	}

	switch (selected[0]) {
	case 1:
	{
		switch (selected[1]) {
		case 1: selectedId = 1; break;
		case 2: selectedId = 2; break;
		case 3: selectedId = 3; break;
		case 4: selectedId = 4; break;
		}
	}
	break;
	case 2:
	{
		switch (selected[1]) {
		case 1: selectedId = 5; break;
		case 2: selectedId = 6; break;
		case 3: selectedId = 7; break;
		case 4: selectedId = 8; break;
		}
	}
	break;
	case 3:
	{
		switch (selected[1]) {
		case 1: selectedId = 9; break;
		case 2: selectedId = 10; break;
		case 3: selectedId = 11; break;
		case 4: selectedId = 12; break;
		}
	}
	break;
	case 4:
	{
		switch (selected[1]) {
		case 1: selectedId = 13; break;
		case 2: selectedId = 14; break;
		case 3: selectedId = 15; break;
		case 4: selectedId = 16; break;
		}
	}
	break;
	}

	switch (selectedId) {
	case 1:
		Drawing::Rect(c, { 0.52f, 8 * 0.035f + 0.1870f }, s1);
		Drawing::Rect(colors[0], { 0.52f, 8 * 0.035f + 0.1870f }, s2);
		break;
	case 2:
		Drawing::Rect(c, { 0.03f + 0.52f, 8 * 0.035f + 0.1870f }, s1);
		Drawing::Rect(colors[1], { 0.03f + 0.52f, 8 * 0.035f + 0.1870f }, s2);
		break;
	case 3:
		Drawing::Rect(c, { 0.06f + 0.52f, 8 * 0.035f + 0.1870f }, s1);
		Drawing::Rect(colors[2], { 0.06f + 0.52f, 8 * 0.035f + 0.1870f }, s2);
		break;
	case 4:
		Drawing::Rect(c, { 0.09f + 0.52f, 8 * 0.035f + 0.1870f }, s1);
		Drawing::Rect(colors[3], { 0.09f + 0.52f, 8 * 0.035f + 0.1870f }, s2);
		break;
	case 5:
		Drawing::Rect(c, { 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, s1);
		Drawing::Rect(colors[4], { 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, s2);
		break;
	case 6:
		Drawing::Rect(c, { 0.03f + 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, s1);
		Drawing::Rect(colors[5], { 0.03f + 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, s2);
		break;
	case 7:
		Drawing::Rect(c, { 0.06f + 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, s1);
		Drawing::Rect(colors[6], { 0.06f + 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, s2);
		break;
	case 8:
		Drawing::Rect(c, { 0.09f + 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, s1);
		Drawing::Rect(colors[7], { 0.09f + 0.52f, 7 * 0.035f + 0.1870f - 0.022f }, s2);
		break;
	case 9:
		Drawing::Rect(c, { 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, s1);
		Drawing::Rect(colors[8], { 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, s2);
		break;
	case 10:
		Drawing::Rect(c, { 0.03f + 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, s1);
		Drawing::Rect(colors[9], { 0.03f + 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, s2);
		break;
	case 11:
		Drawing::Rect(c, { 0.06f + 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, s1);
		Drawing::Rect(colors[10], { 0.06f + 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, s2);
		break;
	case 12:
		Drawing::Rect(c, { 0.09f + 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, s1);
		Drawing::Rect(colors[11], { 0.09f + 0.52f, 5 * 0.035f + 0.1870f - 0.011f }, s2);
		break;
	case 13:
		Drawing::Rect(c, { 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, s1);
		Drawing::Rect(colors[12], { 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, s2);
		break;
	case 14:
		Drawing::Rect(c, { 0.03f + 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, s1);
		Drawing::Rect(colors[13], { 0.03f + 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, s2);
		break;
	case 15:
		Drawing::Rect(c, { 0.06f + 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, s1);
		Drawing::Rect(colors[14], { 0.06f + 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, s2);
		break;
	case 16:
		Drawing::Rect(c, { 0.09f + 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, s1);
		Drawing::Rect(colors[15], { 0.09f + 0.52f, 3 * 0.035f + 0.1870f - 0.000f }, s2);
		break;
	}
	if (Settings::selectPressed) {
		//notifyMap("%i, %i; %i", selected[0], selected[1], selectedId);
		//notifyMap("~r~%i~s~, ~g~%i~s~, ~b~%i", colors[selectedId - 1].r, colors[selectedId - 1].g, colors[selectedId - 1].b);
		color = colors[selectedId - 1];
		//Settings::keyPressPreviousTick = GetTickCount();
	}
	return color;
}

bool Menu::ColorOption(const char * option, SubMenus newSub)
{
	Option(option);

	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		MenuLevelHandler::MoveMenu(newSub);
		return true;
	}
	return false;
}

float reportXpos = 0.869f;
void NigNog(char* text, short line)
{
	if (line == 1) {
		//Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.167f, 0.2860f }, { 0.125f, 13 * 0.041f + -0.130f });
		Menu::Drawing::Rect(Menu::Settings::optionRect, { /*Menu::Settings::menuX + 0.169f*/ reportXpos, 0.1625f }, { 0.125f, 9 * 0.041f + -0.213f }); //0.2440f
	}
	Menu::Drawing::Text(text, Menu::Settings::count, { reportXpos - 0.06f, (line * 0.020f) + 0.085f }, { 0.25f, 0.25f }, false);
}
void Menu::reportMenu() {
	Drawing::Rect(Settings::infocolor, { /*Menu::Settings::menuX + 0.169f*/ reportXpos,  +0.0620f }, { 0.125f, 0.045f });
	Drawing::Text("Report display", Settings::titleText, { reportXpos, +0.0500f }, { 0.450f, 0.450f }, true);

	int reportkek;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), &reportkek, -1);
	const auto& reportstringkek = "Exploits: "s + std::to_string(reportkek);
	int reportkek5;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_GRIEFING"), &reportkek5, -1);
	const auto& reportstringkek5 = "Griefing: "s + std::to_string(reportkek5);
	int reportkek6;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_LANGUAGE"), &reportkek6, -1);
	const auto& reportstringkek6 = "Offensive Language: "s + std::to_string(reportkek6);
	int reportkek7;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_UGC"), &reportkek7, -1);
	const auto& reportstringkek7 = "Offensive UGC: "s + std::to_string(reportkek7);
	int reportkek8;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VC_HATE"), &reportkek8, -1);
	const auto& reportstringkek8 = "VC Hate: "s + std::to_string(reportkek8);
	int reportkek9;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_ISPUNISHED"), &reportkek9, -1);
	const auto& reportstringkek9 = "Punished: "s + std::to_string(reportkek9);
	int reportkek1;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_REPORT_STRENGTH"), &reportkek1, -1);
	const auto& reportstringkek1 = "Report Strength: "s + std::to_string(reportkek1);

	ostringstream ss1, ss2, ss3, ss4, ss5, ss6, ss7;
	if (NETWORK::NETWORK_IS_SIGNED_ONLINE()) {
		ss1 << reportstringkek;
		ss2 << reportstringkek5;
		ss3 << reportstringkek6;
		ss4 << reportstringkek7;
		ss5 << reportstringkek8;
		ss6 << reportstringkek9;
		ss7 << reportstringkek1;
	}
	else {
		ss1 << "Exploits: 0";
		ss2 << "Griefing: 0";
		ss3 << "Offensive Language: 0";
		ss4 << "Offensive UGC: 0";
		ss5 << "VC Hate: 0";
		ss6 << "Punished: 0";
		ss7 << "Report Strength: 0";
	}

	NigNog((char*)ss1.str().c_str(), 0);
	NigNog((char*)ss2.str().c_str(), 1);
	NigNog((char*)ss3.str().c_str(), 2);
	NigNog((char*)ss4.str().c_str(), 3);
	NigNog((char*)ss5.str().c_str(), 4);
	NigNog((char*)ss6.str().c_str(), 5);
	NigNog((char*)ss7.str().c_str(), 6);
}

float reportYpos = 0.3f;
void Nigger(char* text, short line)
{
	if (line == 1) {
		//Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.167f, 0.2860f }, { 0.125f, 13 * 0.041f + -0.130f });
		
	}
	Menu::Drawing::Text(text, Menu::Settings::count, { reportXpos - 0.06f, (line * 0.020f) + 0.085f + reportYpos }, { 0.25f, 0.25f }, false);
}

void Menu::IPMenu() {
	Drawing::Rect(Settings::infocolor, { /*Menu::Settings::menuX + 0.169f*/ reportXpos,  +0.0620f + reportYpos }, { 0.125f, 0.045f });
	Drawing::Text("IP display", Settings::titleText, { reportXpos, +0.0500f + reportYpos }, { 0.450f, 0.450f }, true);
	Menu::Drawing::Rect(Menu::Settings::optionRect, { /*Menu::Settings::menuX + 0.169f*/ reportXpos, 0.3875f + reportYpos }, { 0.125f, 20 * 0.041f + -0.213f }); //0.2440f
	if (NETWORK::NETWORK_IS_SIGNED_ONLINE()) {
		int pcount = -1;
		for (int i = 0; i < 30; i++) {
			if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
				pcount++;
				Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
				char ipBuf[32] = {};
				static auto IPadre = (std::uintptr_t(*)(int))(Memory::pattern("40 53 48 83 EC 20 33 DB 38 1D ? ? ? ? 74 1C").count(1).get(0).get<void>(0));
				auto ipadre_ = IPadre(i);

				if (NETWORK::NETWORK_IS_PLAYER_CONNECTED(i)) {
					if (ipadre_) {
						auto faggot = *(uintptr_t*)(ipadre_ + 0x10b8);
						if (faggot) {
							auto ip = (BYTE*)(faggot + 0x44);
							std::snprintf(ipBuf, sizeof(ipBuf) - 1, "%u.%u.%u.%u", ip[3], ip[2], ip[1], *ip);
						}
					}
				}
				std::string content = (std::string)PLAYER::GET_PLAYER_NAME(i) + ": " + ipBuf;
				ostringstream ss; ss << PLAYER::GET_PLAYER_NAME(i) << ": " << ipBuf;
				Nigger((char*)ss.str().c_str(), pcount);
			}
			/*else {
				Nigger("**INVALID**: 255.255.255.255", i);
			}*/
		}
	}	
}

bool Menu::MenuOptions2(const char * option, SubMenus newSub, int pid)
{
	char* GPic = "CHAR_MULTIPLAYER";
	int index = 1379955;
	for (int i = 0; i <= 150; i += 5)
	{
		__int64* base = globalHandle(index + i).Get<__int64>();
		int playerId = *base;
		if (playerId == pid)
		{
			__int64* logo = globalHandle(index + i + 1).Get<__int64>();
			GPic = PED::GET_PEDHEADSHOT_TXD_STRING(*logo);
			break;
		}
		if (playerId == -1)
			break;
	}
	Option(option);
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Spriter(GPic, GPic, (Settings::menuX + (Settings::scrollbarWidthIndex - 0.042f)), Settings::menuY + (Settings::optionCount * 0.035f + 0.142f), 0.015f, 0.027f, 0, 255, 255, 255, 255);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Spriter(GPic, GPic, (Settings::menuX + (Settings::scrollbarWidthIndex - 0.042f)), Settings::menuY + ((Settings::optionCount - (Settings::currentOption - 16))* 0.035f + 0.142f), 0.015f, 0.027f, 0, 255, 255, 255, 255);
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		MenuLevelHandler::MoveMenu(newSub);
		return true;
	}
	return false;
}

int drawLN(int id) {
	if (id >= 0 && id <= 10) {
		return 1;
	}
	else if (id >= 11 && id <= 20) {
		return 2;
	}
	else if (id >= 21 && id <= 30) {
		return 3;
	}
	else if (id >= 31 && id <= 40) {
		return 4;
	}
	else if (id >= 41 && id <= 50) {
		return 5;
	}
	else if (id >= 51 && id <= 60) {
		return 6;
	}
	else if (id >= 61 && id <= 70) {
		return 7;
	}
	else if (id >= 71 && id <= 80) {
		return 8;
	}
	else {
		return 1;
	}
}

bool Menu::Settings::lightning = false;
void Menu::lightning(int delay, bool fade) {
	std::string ln = "lightning";
	if (fade) {
		Drawing::Spriter("customheader", ln + std::to_string(drawLN(lightningID)), Settings::menuX, Settings::menuY + 0.0820f, Settings::menuWidth, Settings::headerHeight, 0.f, 255, 255, 255, Settings::headerTransparancy);
	}
	else {
		Drawing::Spriter("customheader", ln + std::to_string(drawLN(lightningID)), Settings::menuX, Settings::menuY + 0.0820f, Settings::menuWidth, Settings::headerHeight, 0.f, 255, 255, 255, Settings::headerTransparancy);
	}
	std::chrono::milliseconds interval(delay); //350
	if (lightningID <= 80) {
		lightningID++;
	}
	else {
		lightningID = 1;
	}
}

float selfXPos = 0.719f;

void Menu::selfInfoLine(char* text, short line)
{
	if (line == 1) {
		//Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.167f, 0.2860f }, { 0.125f, 13 * 0.041f + -0.130f });
		//Drawing::Rect(Settings::optionRect, { selfXPos, 0.3060f }, { 0.125f, 16 * 0.041f + -0.213f }); //0.2840f
		Drawing::Rect(Settings::optionRect, { selfXPos, 0.3340f }, { 0.125f, 17 * 0.042f + -0.213f }); //0.2840f
	}
	Drawing::Text(text, Settings::count, { selfXPos - 0.06f, (line * 0.020f) + 0.085f }, { 0.25f, 0.25f }, false);
}

bool Menu::Settings::selfInfo = false;
bool Menu::Settings::playerInfoActive = false;
void Menu::selfInfo(bool toggle) {
	if (toggle || !toggle) { //lol
		Player p = PLAYER::PLAYER_ID();
		Ped ped = PLAYER::PLAYER_PED_ID();

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
		Ped playerPed = PLAYER::PLAYER_PED_ID(); //F
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
		float distance = 0.0f;
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

		ostringstream totalrp; totalrp << "RP:~s~ " << rp;
		ostringstream rplevel; rplevel << "Level:~s~ " << lvl;
		ostringstream richness; richness << "Money:~s~ " << money;
		ostringstream killer; killer << "Kills:~s~ " << kills;
		ostringstream yoink; yoink << "Deaths:~s~ " << deaths;
		ostringstream clingclang; clingclang << "K/D:~s~ " << kd;
		ostringstream tiptoe; tiptoe << "Off radar:~s~ " << sotr;
		ostringstream nigger; nigger << "Banked Money:~s~ " << bankMoney;
		ostringstream kys; kys << "Port:~s~ " << port_str;
		ostringstream ridkek; ridkek << "Rockstar ID:~s~ " << rockstarID;

		Drawing::Rect(Settings::infocolor, { selfXPos,  +0.0620f }, { 0.125f, 0.045f });
		Drawing::Text("Self info", Settings::titleText, { selfXPos, +0.0500f }, { 0.450f, 0.450f }, true);
		Menu::selfInfoLine((char*)Health.str().c_str(), 0);
		Menu::selfInfoLine((char*)Armor.str().c_str(), 1);
		Menu::selfInfoLine((char*)Alive.str().c_str(), 2);
		Menu::selfInfoLine((char*)IsInAVehicle.str().c_str(), 3);
		Menu::selfInfoLine((char*)VehicleModel.str().c_str(), 4);
		Menu::selfInfoLine((char*)Speed.str().c_str(), 5);
		Menu::selfInfoLine((char*)WantedLevel.str().c_str(), 6);
		Menu::selfInfoLine((char*)Weapon.str().c_str(), 7);
		Menu::selfInfoLine((char*)Zone.str().c_str(), 8);
		Menu::selfInfoLine((char*)Street.str().c_str(), 9);
		Menu::selfInfoLine((char*)Distance.str().c_str(), 10);
		Menu::selfInfoLine(ipBuf, 11);
		Menu::selfInfoLine((char*)kys.str().c_str(), 12);
		Menu::selfInfoLine(Coord_buf, 13);
		Menu::selfInfoLine(Invincibilitytext, 14);
		Menu::selfInfoLine((char*)totalrp.str().c_str(), 15);
		Menu::selfInfoLine((char*)rplevel.str().c_str(), 16);
		Menu::selfInfoLine((char*)richness.str().c_str(), 17);
		Menu::selfInfoLine((char*)nigger.str().c_str(), 18);
		Menu::selfInfoLine((char*)killer.str().c_str(), 19);
		Menu::selfInfoLine((char*)yoink.str().c_str(), 20);
		Menu::selfInfoLine((char*)clingclang.str().c_str(), 21);
		Menu::selfInfoLine((char*)tiptoe.str().c_str(), 22);
		Menu::selfInfoLine((char*)ridkek.str().c_str(), 23);
	}
}

bool Menu::Settings::fadeIn = true;
bool Menu::Settings::fadeOut = true;
int Menu::Settings::fadeAlpha = 0;

/*
	if (Settings::currentOption <= 150 && Settings::optionCount <= 150)
	{
		if (alphaaa <= 255) {
			alphaaa++;
		}
		else {
			alphaaa = 0;
		}
		Drawing::Text(title, { Settings::optionText.r, Settings::optionText.g, Settings::optionText.b, alphaaa }, { Settings::menuX - 0.100f, (Settings::optionCount)*0.035f + 0.128f }, { 0.35f, 0.35f }, false);
		Drawing::Rect({ Settings::breakrect.r, Settings::breakrect.g, Settings::breakrect.b, alphaaa }, { Settings::menuX, (Settings::optionCount)*0.035f + 0.1415f }, { 0.21f, 0.035f });
	}
	return false;
*/

bool Menu::fade(bool fadein) {
	if (fadein && Settings::fadeAlpha <= 255) {
		Settings::fadeAlpha += 5;
		if (Settings::fadeAlpha >= 255) {
			return true;
		}
	}
	if (!fadein && Settings::fadeAlpha >= 0) {
		Settings::fadeAlpha -= 5;
		if (Settings::fadeAlpha <= 0) {
			return true;
		}
	}
	return false;
}

void Menu::TitleFade(const char * title) {
	Drawing::Text(title, { Settings::titleText.r, Settings::titleText.g, Settings::titleText.b, Settings::fadeAlpha, Settings::titleText.f }, { Settings::menuX, 0.065f }, { 0.50f, 0.50f }, true);
	//Drawing::Rect(Settings::titleRect, { Settings::menuX, +0.0820f }, { 0.21f, 0.085f }); //Title coords STANDART: +0.0810 PERFECT?: +0.0820

	if (!Menu::Settings::lightning) {
		Drawing::Spriter("customheader", Menu::Settings::ytdtheme, Settings::menuX, +0.0820f, 0.21f, 0.085f, 0.f, 255, 255, 255, Settings::fadeAlpha); //YTD loader
	}
	else {
		Menu::lightning(35000000, true);
	}

	Drawing::Rect({ Settings::secondary.r, Settings::secondary.g, Settings::secondary.b, Settings::fadeAlpha }, { Settings::menuX - 0.120f,  +0.1500f }, { 0.01f, 0.019f });
	Drawing::Text("3", { Settings::arrow.r, Settings::arrow.g, Settings::arrow.b, Settings::fadeAlpha }, { Settings::menuX - 0.125f, 0.137f }, { 0.30f, 0.30f }, false);

	if (Settings::showGlobe) {
		Globe::drawGlare(Settings::GlareX, GlareY, Glarewidth, Glareheight, 255, 255, 255);
	}

	//drawScrollbar(Menu::Settings::currentOption, Menu::Settings::optionCount);

	YTD();
	// Disable Controls
	UI::HIDE_HELP_TEXT_THIS_FRAME();
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(10);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_NEXT_CAMERA, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_CHARACTER_WHEEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_LIGHT, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_HEAVY, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MULTIPLAYER_INFO, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_ALTERNATE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_CIN_CAM, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MAP_POI, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_RADIO_WHEEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_HEADLIGHT, true);
}

bool Menu::BreakFade(const char * title) {
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::currentOption <= 150 && Settings::optionCount <= 150)
	{
		Drawing::Text(title, { Settings::optionText.r, Settings::optionText.g, Settings::optionText.b, Settings::fadeAlpha }, { Settings::menuX - 0.100f, (Settings::optionCount)*0.035f + 0.128f }, { 0.35f, 0.35f }, false);
		Drawing::Rect({ Settings::breakrect.r, Settings::breakrect.g, Settings::breakrect.b, Settings::fadeAlpha }, { Settings::menuX, (Settings::optionCount)*0.035f + 0.1415f }, { 0.21f, 0.035f });
	}
	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
	{

		Drawing::Text(title, { Settings::optionText.r, Settings::optionText.g, Settings::optionText.b, Settings::fadeAlpha }, { Settings::menuX - 0.100f, (Settings::optionCount)*0.035f + 0.128f }, { 0.35f, 0.35f }, false);
		Drawing::Rect({ Settings::breakrect.r, Settings::breakrect.g, Settings::breakrect.b, Settings::fadeAlpha }, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.21f, 0.035f });
	}
	return false;
}

bool Menu::MenuOptionFade(const char * option, SubMenus newSub) {
	Settings::optionCount++;
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
	{
		Drawing::Text(option, { Settings::optionText.r, Settings::optionText.g, Settings::optionText.b, Settings::fadeAlpha }, { Settings::menuX - 0.100f, (Settings::optionCount)*0.035f + 0.128f }, { 0.35f, 0.35f }, false);
		Drawing::Rect({ Settings::optionRect.r, Settings::optionRect.g, Settings::optionRect.b, Settings::fadeAlpha }, { Settings::menuX, (Settings::optionCount)*0.035f + 0.1415f }, { 0.21f, 0.035f });
		Drawing::Rect({ Settings::optionRect.r, Settings::optionRect.g, Settings::optionRect.b, Settings::fadeAlpha }, { Settings::menuX - 0.120f, (Settings::optionCount)*0.035f + 0.1415f }, { 0.007f, 0.035f });
		if (onThis) {
			Drawing::Rect({ Settings::scroller.r, Settings::scroller.g, Settings::scroller.b, Settings::fadeAlpha }, { Settings::menuX, (Settings::optionCount)*0.035f + 0.1415f }, { 0.21f, 0.035f });
			Drawing::Rect({ Settings::scroller.r, Settings::scroller.g, Settings::scroller.b, Settings::fadeAlpha }, { Settings::menuX - 0.120f, (Settings::optionCount)*0.035f + 0.1415f }, { 0.007f, 0.035f });
		}
	}
	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
	{
		Drawing::Text(option, { Settings::optionText.r, Settings::optionText.g, Settings::optionText.b, Settings::fadeAlpha }, { Settings::menuX - 0.100f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.128f }, { 0.35f, 0.35f }, false);
		Drawing::Rect({ Settings::optionRect.r, Settings::optionRect.g, Settings::optionRect.b, Settings::fadeAlpha }, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.21f, 0.035f });
		Drawing::Rect({ Settings::optionRect.r, Settings::optionRect.g, Settings::optionRect.b, Settings::fadeAlpha }, { Settings::menuX - 0.120f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.007f, 0.035f });
		if (onThis) {
			Drawing::Rect({ Settings::scroller.r, Settings::scroller.g, Settings::scroller.b, Settings::fadeAlpha }, { Settings::menuX, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.21f, 0.035f });
			Drawing::Rect({ Settings::scroller.r, Settings::scroller.g, Settings::scroller.b, Settings::fadeAlpha }, { Settings::menuX - 0.120f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.007f, 0.035f });
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text("2", /*onThis ? Settings::arrow : Settings::arrow*/{ Settings::arrow.r, Settings::arrow.g, Settings::arrow.b, Settings::fadeAlpha, Settings::arrow.f }, { Settings::menuX + 0.097f, Settings::optionCount * 0.035f + 0.120f }, { 0.45f, 0.45f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text("2", /*onThis ? Settings::arrow : Settings::arrow*/{ Settings::arrow.r, Settings::arrow.g, Settings::arrow.b, Settings::fadeAlpha, Settings::arrow.f }, { Settings::menuX + 0.097f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.125f }, { 0.45f, 0.45f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		MenuLevelHandler::MoveMenu(newSub);
		return true;
	}
	return false;
}

void Menu::symbols() {
	//Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.139f, 0.3630f }, { 0.050f, 16 * 0.041f + -0.220f });
	Drawing::Spriter("customheader", "menuend_x", 0.005f, 0.0f, 0.05f, 0.041f + -0.220f, 0.f, 255, 255, 255, 255);
	//Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.139f, (Settings::optionCount)*0.035f + 0.1415f }, { 0.05f, 0.035f });
	Drawing::Rect(Settings::optionRect, { 0.0f, 0.3630f }, { 0.050f, 37 * 0.041f + -0.220f });
}

float width_ = 0.255f;
RGBA Optionz = { 0, 0, 0, 150 };
RGBA NSOT = { 255, 255, 255, 255 };

void str(const std::string& str, const int font, const float x, const float y, const float sx, const float sy,
	const int r, const int g, const int b, const int a, const bool outline, const bool shadow,
	const bool center)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(sx, sy);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	if (outline)
		UI::SET_TEXT_OUTLINE();
	if (shadow)
		UI::SET_TEXT_DROP_SHADOW();
	if (center)
		UI::SET_TEXT_CENTRE(1);
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT(static_cast<char*>("STRING"));
	const auto drawing_text = str.c_str();
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(const_cast<char*>(drawing_text));
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}

void in_game_img(const std::string& dict, const std::string& texture, const float x, const float y,
	const float sx, const float sy,
	const int r, const int g, const int b, const int a, const float heading)
{
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(const_cast<char*>(dict.c_str())))
	{
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(const_cast<char*>(dict.c_str()), false);
	}
	else
	{
		GRAPHICS::DRAW_SPRITE(const_cast<char*>(dict.c_str()), const_cast<char*>(texture.c_str()), x, y, sx, sy, heading, r, g, b, a);
	}
}

void Menu::extra_title(const std::string& text)
{
	invoke<Void>(0x3A618A217E5154F0, Settings::menuX - 0.205f, 0.075f, width_ - 0.1f, 0.05f, 128, 0, 128, 130);

	str(text, 1, Settings::menuX - 0.205f, 0.06f, 0.6, 0.6, 255, 255, 255, 255, false, false, true);
}

std::vector<std::string> exoptions;

void Menu::extra_option(const extra_option_args args)
{
	exoptions.push_back(args.option);
	invoke<Void>(0x3A618A217E5154F0, Settings::menuX - 0.205f, exoptions.size() * 0.02f + 0.09f, width_ - 0.1f, 0.02f, Optionz.r, Optionz.g, Optionz.b, Optionz.a);
	str(args.option + ": " + args.value, 0, Settings::menuX - 0.27f, exoptions.size() * 0.02f + 0.079f, 0.3, 0.3,
		NSOT.r, NSOT.g, NSOT.b,
		NSOT.a, false, false, false);
	in_game_img(args.sprite.dict, args.sprite.texture, Settings::menuX - 0.2755f, exoptions.size() * 0.02f + 0.09f, 0.013f, 0.0175f,
		255, 255, 255, 255, 0);
}

void Menu::end_extra_menu()
{
	//rect(menux_ - 0.205f, exoptions.size()* 0.02f + 0.09f, width_ - 0.1f, 0.02f, 0, 0, 0, 155);
	invoke<Void>(0x3A618A217E5154F0, Settings::menuX - 0.205f, (exoptions.size() + 1) * 0.02f + 0.09f,
		width_ - 0.1f, 0.02f, 128, 0, 128, 130);
}

int drawEV(int id) {
	if (id >= 0 && id <= 10) {
		return 1;
	}
	else if (id >= 11 && id <= 20) {
		return 2;
	}
	else if (id >= 21 && id <= 30) {
		return 3;
	}
	else if (id >= 31 && id <= 40) {
		return 4;
	}
	else if (id >= 41 && id <= 50) {
		return 5;
	}
	else {
		return 1;
	}
}

bool Menu::Settings::evolve = false;
int evolveID = 1;
void Menu::Evolve() {
	std::string ln = "eforce";
	Drawing::Spriter("customheader", ln + std::to_string(drawEV(evolveID)), Settings::menuX, Settings::menuY + 0.0820f, Settings::menuWidth, Settings::headerHeight, 0.f, 255, 255, 255, Settings::headerTransparancy);
	std::chrono::milliseconds interval(350000); //350
	if (evolveID <= 50) {
		evolveID++;
	}
	else {
		evolveID = 1;
	}
}

int drawPX(int id) {
	return id;
}

bool Menu::Settings::phantom = false;
int phanID = 0;
void Menu::Phantom() {
	std::string ln = "Xforceheader00";
	YTD3("X-Folder/title/", "x1.ytd");
	YTD3("X-Folder/title/", "x2.ytd");
	if (phanID <= 9) {
		ln = "Xforceheader00";
	}
	else if (phanID >= 9 && phanID <= 99) {
		ln = "Xforceheader0";
	}
	else {
		ln = "Xforceheader";
	}
	if (phanID <= 149) {
		Drawing::Spriter("x1", ln + std::to_string(drawPX(phanID)), Settings::menuX, Settings::menuY + 0.0820f, Settings::menuWidth, Settings::headerHeight, 0.f, 255, 255, 255, Settings::headerTransparancy);
	}
	else {
		Drawing::Spriter("x2", ln + std::to_string(drawPX(phanID)), Settings::menuX, Settings::menuY + 0.0820f, Settings::menuWidth, Settings::headerHeight, 0.f, 255, 255, 255, Settings::headerTransparancy);
	}
	if (phanID < 299) {
		phanID++;
	}
	else {
		phanID = 0;
	}
}

template <typename T>
bool addOption(T option) {
	return false;
}

bool addSubmenu(SubMenus sub, std::function<void()> action) {
	if (Menu::Settings::currentMenu == sub) {
		action();
		return true;
	}
	return false;
}

//CUSTOMHEADER

bool Menu::Settings::c_enable = false;
bool Menu::Settings::c_animation = false;
std::string Menu::Settings::c_name = "custom_header"; //header
std::string Menu::Settings::c_pict = ""; //img
int Menu::Settings::c_frames = 2;
int Menu::Settings::c_ID = 0;

void Menu::loadCustomHeader() {
	std::string header_ = Menu::Settings::c_name + ".ytd";
	YTD3("X-Folder/", header_);
	if (!Menu::Settings::c_animation) {
		Menu::Drawing::Spriter(Menu::Settings::c_name, Menu::Settings::c_pict, Menu::Settings::menuX, Menu::Settings::menuY + 0.0820f, Menu::Settings::menuWidth, Menu::Settings::headerHeight, 0.f, 255, 255, 255, Menu::Settings::headerTransparancy);
	}
	else {
		Menu::Drawing::Spriter(Menu::Settings::c_name, Menu::Settings::c_pict + "_" + std::to_string(Menu::Settings::c_ID), Menu::Settings::menuX, Menu::Settings::menuY + 0.0820f, Menu::Settings::menuWidth, Menu::Settings::headerHeight, 0.f, 255, 255, 255, Menu::Settings::headerTransparancy);
		if (Menu::Settings::c_ID < Menu::Settings::c_frames) {
			Menu::Settings::c_ID += 1;
		}
		else {
			Menu::Settings::c_ID = 0;
		}
	}
}

bool Menu::Settings::enable_scrollbar = false;

int drawCT(int id) {
	/*if (id >= 0 && id <= 10) {
		return 1;
	}
	else if (id >= 11 && id <= 20) {
		return 2;
	}
	else if (id >= 21 && id <= 30) {
		return 3;
	}
	else if (id >= 31 && id <= 40) {
		return 4;
	}
	else if (id >= 41 && id <= 50) {
		return 5;
	}
	else {
		return 1;
	}*/
	return id;
}

bool Menu::Settings::city = false;
int cityID = 1;
void Menu::City() {
	std::string ln = "city";
	Drawing::Spriter("customheader", ln + std::to_string(drawCT(cityID)), Settings::menuX, Settings::menuY + 0.0820f, Settings::menuWidth, Settings::headerHeight, 0.f, 255, 255, 255, Settings::headerTransparancy);
	std::chrono::milliseconds interval(350000); //350
	if (cityID < 5) {
		cityID++;
	}
	else {
		cityID = 1;
	}
}

float notXpos = 0;
void Menu::customNotification(char *text) {
	Drawing::Rect({ 0, 0, 0, 180 }, { 0, 0 }, { 0, 0 });
}