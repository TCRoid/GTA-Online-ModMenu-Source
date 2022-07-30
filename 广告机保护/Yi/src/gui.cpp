/*by holywu*/
#include "common.hpp"
#include "fiber_pool.hpp"
#include "gta/player.hpp"
#include "gta_util.hpp"
#include "gui.hpp"
#include "logger.hpp"
#include "memory/module.hpp"
#include "memory/pattern.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "renderer.hpp"
#include "script.hpp"
#include ".//fonts.hpp"
#include <imgui.h>
#include "features.hpp"
#include "fiber_pool.hpp"
#include "gui/base_tab.h"
#include "hwd.h"
#include "Ini.h"
char notice[2048];
ImFont* test{};
int yanz = 0;
void gui::dx_init()
{
	ImGuiIO& io = ImGui::GetIO();
	test = io.Fonts->AddFontFromFileTTF("c:/windows/fonts/simhei.ttf", 17.0f, NULL, io.Fonts->GetGlyphRangesChineseSimplifiedCommon());

	auto &style = ImGui::GetStyle();
	style.WindowPadding = { 10.f, 10.f };
	style.PopupRounding = 0.f;
	style.FramePadding = { 8.f, 4.f };
	style.ItemSpacing = { 10.f, 8.f };
	style.ItemInnerSpacing = { 6.f, 6.f };
	style.TouchExtraPadding = { 0.f, 0.f };
	style.IndentSpacing = 21.f;
	style.ScrollbarSize = 15.f;
	style.GrabMinSize = 8.f;
	style.WindowBorderSize = 1.f;
	style.ChildBorderSize = 0.f;
	style.PopupBorderSize = 1.f;
	style.FrameBorderSize = 0.f;
	style.TabBorderSize = 0.f;
	style.WindowRounding = 0.f;
	style.ChildRounding = 0.f;
	style.FrameRounding = 0.f;
	style.ScrollbarRounding = 0.f;
	style.GrabRounding = 0.f;
	style.TabRounding = 0.f;
	style.WindowTitleAlign = { 0.5f, 0.5f };
	style.ButtonTextAlign = { 0.5f, 0.5f };
	style.DisplaySafeAreaPadding = { 3.f, 3.f };

	auto &colors = style.Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(1.00f, 0.90f, 0.19f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
	colors[ImGuiCol_Border] = ImVec4(0.30f, 0.30f, 0.30f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.21f, 0.21f, 0.21f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.21f, 0.21f, 0.21f, 0.78f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.28f, 0.27f, 0.27f, 0.54f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.17f, 0.17f, 0.17f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.19f, 0.19f, 0.19f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.39f, 0.38f, 0.38f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.41f, 0.41f, 0.41f, 0.74f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.41f, 0.41f, 0.41f, 0.78f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.41f, 0.41f, 0.41f, 0.87f);
	colors[ImGuiCol_Header] = ImVec4(0.37f, 0.37f, 0.37f, 0.31f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.38f, 0.38f, 0.38f, 0.37f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.37f, 0.37f, 0.37f, 0.51f);
	colors[ImGuiCol_Separator] = ImVec4(0.38f, 0.38f, 0.38f, 0.50f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.46f, 0.46f, 0.46f, 0.50f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.46f, 0.46f, 0.46f, 0.64f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.26f, 0.26f, 1.00f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);
	colors[ImGuiCol_Tab] = ImVec4(0.21f, 0.21f, 0.21f, 0.86f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.27f, 0.27f, 0.27f, 0.86f);
	colors[ImGuiCol_TabActive] = ImVec4(0.34f, 0.34f, 0.34f, 0.86f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.10f, 0.10f, 0.10f, 0.97f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
	//a5cb5165c7bdfcd0a0e4d78e7ed02482
	bool initState = hwd_init("", 80, "", "", "", false, false, true, 0);

	if (!initState) {
		char errorMsg[1024];
		hwd_getLastErrorMsg(errorMsg, 1024);
		LOG(INFO) << errorMsg;
		system("pause");
	}
	features::LoadINI();
	LOG(INFO) << features::chongzhika;
	if (hwd_login(features::chongzhika, "", "", "V1.0")) {
		yanz = 1;
	}
}


float resizefloat(float val)
{
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	float newScale = (io.DisplaySize.x * io.DisplaySize.y) / (1920.f * 1080.f);

	if (newScale > 1.0f)
		newScale = 1.f;

	if (false)
		return val * newScale;
	else
		return val;
}

ImVec4 enemyColor = ImGui::ColorConvertU32ToFloat4(ImColor(255, 0, 0, 255));
ImVec4 teamColor = ImGui::ColorConvertU32ToFloat4(ImColor(0, 0, 255, 255));
ImVec4 friendColor = ImGui::ColorConvertU32ToFloat4(ImColor(0, 255, 0, 255));
ImVec4 NpcColor = ImGui::ColorConvertU32ToFloat4(ImColor(0, 255, 162, 255));
ImVec4 CopColor = ImGui::ColorConvertU32ToFloat4(ImColor(0, 107, 255, 255));
ImVec4 yourColor = ImGui::ColorConvertU32ToFloat4(ImColor(89, 66, 250, 204));
ImVec4 crosshairColor = ImGui::ColorConvertU32ToFloat4(ImColor(255, 80, 0, 255));

//char account[1024];
//char password[1024];
//char email[1024];
//char* lefttime = new char[128];
int tips = 0;
void gui::dx_on_tick()
{
	ImGui::SetNextWindowSize(ImVec2(600, 600), ImGuiCond_FirstUseEver);
	ImGui::PushFont(test);
	if (ImGui::Begin("科技广告机"))
	{
		if (yanz == 0)
		{
			ImGui::BeginTabBar("tabbar1");
			if (ImGui::BeginTabItem("登入"))
			{
				ImGui::InputText("充值卡", features::chongzhika, 150);
				if (ImGui::Button("登入"))
				{
					if (hwd_login(features::chongzhika, "", "", "V1.0")) {
						INI::WriteChar("C:\\ggj\\load.ini", features::chongzhika, "Auth", "Key");
						hwd_heartbeat(0, "");
						yanz = 1;
					}
					else
					{
						tips = 1;
					}
				}
				if (ImGui::Button("关闭"))
				{
					g_running = false;
				}
				ImGui::Separator();
				if (tips == 0)
				{
					ImGui::Text("科技广告机欢迎您的使用");
				}
				else if (tips == 1)
				{
					ImGui::Text("登入失败，请尝试检测充值卡是否正确或已到期");
				}
				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}
		if (yanz == 1)
		{
			ImGui::BeginTabBar("tabbar");
			base_tab::render_base_tab();
			ImGui::EndTabBar();
		}
	}
	ImGui::End();
}

void gui::script_init()
{
}

void gui::script_on_tick()
{
	TRY_CLAUSE
	{
		if (g_gui.m_opened)
		{
			PAD::DISABLE_ALL_CONTROL_ACTIONS(0);
		}
	}
	EXCEPT_CLAUSE
}

void gui::script_func()
{
	g_gui.script_init();
	while (true)
	{
		g_gui.script_on_tick();
		script::get_current()->yield();
	}
}

