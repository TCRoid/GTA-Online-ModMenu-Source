#pragma once
#include "common.hpp"

namespace big
{
	struct NotificationTemplate
	{
		ULONGLONG m_Timer;
		const char* m_Title;
		const char* m_Message;
	};
	class gui
	{
	public:
		void dx_init();
		void dx_on_tick();
		void topmenu();
		void users();
		void backgroundOverlay();
		void playerList();

		void SendNotification(const char* Title, const char* Message);
		void NotifyWindow();

		void script_init();
		void script_on_tick();
		static void script_func();
		void selfTab();
		void weaponTab();
		void vehicleTab();
		void teleportTab();
		void onlineTab();
		void missionTab();
		void worldTab();
		void recoveryTab();
		void menuTab();
		void otherTab();
		void initCar();
		void initiniCar();
		void initxmlCar();
		void inittheme();
		void refresh_asiFiles();
	public:
		bool m_opened{};

		float logohight = 167;
		ImVec2 mainWindowPos;
		ImVec2 mainWindowSize;

		ImVec2 maxWindowPos;
		ImVec2 maxWindowSize;

		ImU32 u32_crosshairColor{};

		std::string menus[12] = { "自我选项", "武器选项", "载具选项", "传送选项", "线上模式", "玩家列表", "任务选项", "防护选项", "世界选项", "恢复选项", "其他选项", "菜单设置" };

		ImVec4 espColor = ImGui::ColorConvertU32ToFloat4(ImColor(0, 255, 0, 255));

		ImVec4 crosshairColor = ImGui::ColorConvertU32ToFloat4(ImColor(255, 80, 0, 255));

		std::int64_t NotifyCount = 4;
		std::vector<NotificationTemplate> m_Notifications;
		ImVec4 NotificationRect = ImColor(44, 50, 59, 205);
		ImVec4 NotificationTopText = ImColor(100, 186, 240, 255);
		ImVec4 NotificationBottomText = ImColor(255, 255, 255, 255);
		ImVec2 m_Position = { 0, 0 };

		ImFont* font{};
		ImFont* icon{};

		float resizefloat(float val);
		void NotificationOverlay(const char* text, const char* text2, float pos);
		void FillRect(ImVec4 Color, ImVec4 Color2, ImVec2 Pos, ImVec2 Size, bool Filled = true);

		BOOL DrawLine(tPlayerData data, ImVec2 a, ImVec2 b);
		BOOL Draw2DBox(tPlayerData data, ImVec2 head, ImVec2 feet);
		BOOL drawHealthBar(tPlayerData data, ImVec2 head, ImVec2 feet);
		BOOL DrawDistanceAndName(tPlayerData data, ImVec2 head, ImVec2 feet);
		ImVec2 WorldToScreen(Vector3 pos);
		ImVec2 resizeVec(ImVec2 vec2);
		void DrarTop(const char* pText);
		float getBoxHeight(float count);
		float m_BoxWidth = 260.f;
	};

	inline gui g_gui;
}