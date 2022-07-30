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
#include <imgui.h>
#include"memory/native_memory.hpp"
#include "features.hpp"
#include "lists.hpp"
#include"util/util.hpp"
#include"modvehicle.hpp"

//void playerInfoTab()
//{
//	if (ImGui::BeginTabItem(TRANSLATES("详细信息")))
//	{
//		ImGui::Checkbox(TRANSLATES("观战"), &g_settings.player.spectating);
//		tPlayerData data = features::playerData[g_settings.SelectedPlayer];
//		if (data.IsConnected && data.IsValid)
//		{
//			ImGui::BeginChild(TRANSLATES("玩家信息"), ImVec2(0, 0), true); //childHeaderFont->FontSize + ImGui::GetTextLineHeightWithSpacing() * 26 + ImGui::GetStyle().ItemSpacing.y * 4
//			//ImGui::PushFont(childHeaderFont); ImGui::Text(data.playerName.c_str()); ImGui::PopFont();
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("Player ID: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%lld", data.playerId);
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("战局主机: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%s", data.IsHost ? "是" : "否");
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("脚本主机: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%s", data.IsScriptHost ? "是" : "否");
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("RID: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%lld", data.rockstar_id);
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("IPv4: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%d.%d.%d.%d", data.online_ip.m_field1, data.online_ip.m_field2, data.online_ip.m_field3, data.online_ip.m_field4);
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("端口: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%hu", data.online_port);
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("无敌: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%s", data.godmode ? "是" : "否");
//
//			/*ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "等级: "); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%d", data.level);*/
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("K/D: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%.2f", data.ratio);
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("击杀: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%d", data.kills);
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("死亡: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%d", data.deaths);
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("现金: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%lld$", data.wallet);
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("银行: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%lld$", data.totalCash - data.wallet);
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("全部资产: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%lld$", data.totalCash);
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("存活: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%s", data.alive ? "是" : "否");
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("生命值: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%.0f%hs", 100 * ((data.health - 100.f) / (data.maxHealth - 100.f)), "%");
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("通缉等级: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%d", data.wantedLevel);
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("是否在载具内: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%s", data.IsInVehicle ? "是" : "否");
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("是否在室内: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%s", data.IsInInterrior ? "是" : "否");
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("移速: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%.1f", data.speed);
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("距离: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%.0f", data.distance);
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("X坐标: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%.3f", data.position.x);
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("Y坐标: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%.3f", data.position.y);
//
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), TRANSLATES("Z坐标: ")); ImGui::SameLine();
//			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%.3f", data.position.z);
//
//			ImGui::EndChild();
//		}
//
//		ImGui::EndTabItem();
//	}
//}
//

#define IM_ARRAYSIZE2(_ARR)          ((int)(sizeof(_ARR)/sizeof(*_ARR)))

bool ImGuiSaveStyle2(const char* filename, const ImGuiStyle& style)
{
	// Write .style file
	FILE* f = fopen(filename, "wt");
	if (!f)  return false;

	fprintf(f, "[Alpha]\n%1.3f\n", style.Alpha);
	fprintf(f, "[WindowPadding]\n%1.3f %1.3f\n", style.WindowPadding.x, style.WindowPadding.y);
	fprintf(f, "[WindowMinSize]\n%1.3f %1.3f\n", style.WindowMinSize.x, style.WindowMinSize.y);
	fprintf(f, "[FramePadding]\n%1.3f %1.3f\n", style.FramePadding.x, style.FramePadding.y);
	fprintf(f, "[FrameRounding]\n%1.3f\n", style.FrameRounding);
	fprintf(f, "[ItemSpacing]\n%1.3f %1.3f\n", style.ItemSpacing.x, style.ItemSpacing.y);
	fprintf(f, "[ItemInnerSpacing]\n%1.3f %1.3f\n", style.ItemInnerSpacing.x, style.ItemInnerSpacing.y);
	fprintf(f, "[TouchExtraPadding]\n%1.3f %1.3f\n", style.TouchExtraPadding.x, style.TouchExtraPadding.y);
	fprintf(f, "[WindowRounding]\n%1.3f\n", style.WindowRounding);
	fprintf(f, "[ColumnsMinSpacing]\n%1.3f\n", style.ColumnsMinSpacing);

	for (int i = 0; i != ImGuiCol_COUNT; i++)
	{
		const ImVec4& c = style.Colors[i];
		fprintf(f, "[%s]\n", ImGui::GetStyleColorName(i));
		fprintf(f, "%1.3f %1.3f %1.3f %1.3f\n", c.x, c.y, c.z, c.w);
	}

	fprintf(f, "\n");
	fclose(f);

	return true;
}

bool ImGuiLoadStyle2(const char* filename, ImGuiStyle& style)
{
	if (!filename)  return false;

	FILE* f;
	if ((f = fopen(filename, "rt")) == NULL) return false;
	if (fseek(f, 0, SEEK_END)) {
		fclose(f);
		return false;
	}
	const long f_size_signed = ftell(f);
	if (f_size_signed == -1) {
		fclose(f);
		return false;
	}
	size_t f_size = (size_t)f_size_signed;
	if (fseek(f, 0, SEEK_SET)) {
		fclose(f);
		return false;
	}
	char* f_data = (char*)ImGui::MemAlloc(f_size + 1);
	f_size = fread(f_data, 1, f_size, f);
	fclose(f);
	if (f_size == 0) {
		ImGui::MemFree(f_data);
		return false;
	}
	f_data[f_size] = 0;

	char name[128]; name[0] = '\0';
	const char* buf_end = f_data + f_size;
	for (const char* line_start = f_data; line_start < buf_end; )
	{
		const char* line_end = line_start;
		while (line_end < buf_end && *line_end != '\n' && *line_end != '\r')
			line_end++;

		if (name[0] == '\0' && line_start[0] == '[' && line_end > line_start && line_end[-1] == ']')
		{
			ImFormatString(name, IM_ARRAYSIZE2(name), "%.*s", line_end - line_start - 2, line_start + 1);
		}
		else if (name[0] != '\0')
		{
			float* pf[4] = { 0,0,0,0 };
			int npf = 0;
			{
				if (strcmp(name, "Alpha") == 0) { npf = 1; pf[0] = &style.Alpha; }
				else if (strcmp(name, "WindowPadding") == 0) { npf = 2; pf[0] = &style.WindowPadding.x; pf[1] = &style.WindowPadding.y; }
				else if (strcmp(name, "WindowMinSize") == 0) { npf = 2; pf[0] = &style.WindowMinSize.x; pf[1] = &style.WindowMinSize.y; }
				else if (strcmp(name, "FramePadding") == 0) { npf = 2; pf[0] = &style.FramePadding.x; pf[1] = &style.FramePadding.y; }
				else if (strcmp(name, "FrameRounding") == 0) { npf = 1; pf[0] = &style.FrameRounding; }
				else if (strcmp(name, "ItemSpacing") == 0) { npf = 2; pf[0] = &style.ItemSpacing.x; pf[1] = &style.ItemSpacing.y; }
				else if (strcmp(name, "ItemInnerSpacing") == 0) { npf = 2; pf[0] = &style.ItemInnerSpacing.x; pf[1] = &style.ItemInnerSpacing.y; }
				else if (strcmp(name, "TouchExtraPadding") == 0) { npf = 2; pf[0] = &style.TouchExtraPadding.x; pf[1] = &style.TouchExtraPadding.y; }
				else if (strcmp(name, "WindowRounding") == 0) { npf = 1; pf[0] = &style.WindowRounding; }
				else if (strcmp(name, "ColumnsMinSpacing") == 0) { npf = 1; pf[0] = &style.ColumnsMinSpacing; }
				else {
					for (int j = 0; j < ImGuiCol_COUNT; j++) {
						if (strcmp(name, ImGui::GetStyleColorName(j)) == 0) {
							npf = 4;
							ImVec4& color = style.Colors[j];
							pf[0] = &color.x; pf[1] = &color.y; pf[2] = &color.z; pf[3] = &color.w;
							break;
						}
					}
				}
			}

			float x, y, z, w;
			switch (npf) {
			case 1:
				if (sscanf(line_start, "%f", &x) == npf) {
					*pf[0] = x;
				}
				else fprintf(stderr, "Warning in ImGui::LoadStyle(\"%s\"): skipped [%s] (parsing error).\n", filename, name);
				break;
			case 2:
				if (sscanf(line_start, "%f %f", &x, &y) == npf) {
					*pf[0] = x; *pf[1] = y;
				}
				else fprintf(stderr, "Warning in ImGui::LoadStyle(\"%s\"): skipped [%s] (parsing error).\n", filename, name);
				break;
			case 3:
				if (sscanf(line_start, "%f %f %f", &x, &y, &z) == npf) {
					*pf[0] = x; *pf[1] = y; *pf[2] = z;
				}
				else fprintf(stderr, "Warning in ImGui::LoadStyle(\"%s\"): skipped [%s] (parsing error).\n", filename, name);
				break;
			case 4:
				if (sscanf(line_start, "%f %f %f %f", &x, &y, &z, &w) == npf) {
					*pf[0] = x; *pf[1] = y; *pf[2] = z; *pf[3] = w;
				}
				else fprintf(stderr, "Warning in ImGui::LoadStyle(\"%s\"): skipped [%s] (parsing error).\n", filename, name);
				break;
			default:
				fprintf(stderr, "Warning in ImGui::LoadStyle(\"%s\"): skipped [%s] (unknown field).\n", filename, name);
				break;
			}
			name[0] = '\0';
		}

		line_start = line_end + 1;
	}

	ImGui::MemFree(f_data);
	return true;
}
namespace big
{
	void gui::dx_init()
	{
		ImGuiStyle* style = &ImGui::GetStyle();
		style->WindowTitleAlign = ImVec2(0.5f, 0.5f);
		style->WindowPadding = ImVec2(15, 15);
		style->WindowRounding = 5.0f;
		style->ChildRounding = 5.0f;
		style->ChildBorderSize = 0.f;
		style->PopupRounding = 5.0f;
		style->FramePadding = ImVec2(5, 5);
		style->FrameRounding = 4.0f;
		style->ItemSpacing = ImVec2(12, 8);
		style->ItemInnerSpacing = ImVec2(8, 6);
		style->IndentSpacing = 25.0f;
		style->ScrollbarSize = 15.0f;
		style->ScrollbarRounding = 9.0f;
		style->GrabMinSize = 5.0f;
		style->GrabRounding = 3.0f;

		ImVec4* colors = style->Colors;

		colors[ImGuiCol_Text] = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
		colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.85f);
		colors[ImGuiCol_ChildBg] = ImVec4(0.240f, 0.240f, 0.240f, 1.000f);
		colors[ImGuiCol_PopupBg] = ImVec4(0.11f, 0.11f, 0.14f, 0.92f);
		colors[ImGuiCol_Border] = ImVec4(0.50f, 0.50f, 0.50f, 0.50f);
		colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_FrameBg] = ImVec4(0.43f, 0.43f, 0.43f, 0.39f);
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.47f, 0.47f, 0.69f, 0.40f);
		colors[ImGuiCol_FrameBgActive] = ImVec4(0.42f, 0.41f, 0.64f, 0.69f);
		colors[ImGuiCol_TitleBg] = ImVec4(0.27f, 0.27f, 0.54f, 0.83f);
		colors[ImGuiCol_TitleBgActive] = ImVec4(0.32f, 0.32f, 0.63f, 0.87f);
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.40f, 0.40f, 0.80f, 0.20f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.40f, 0.40f, 0.55f, 0.80f);
		colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.25f, 0.30f, 0.60f);
		colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.40f, 0.40f, 0.80f, 0.30f);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.80f, 0.40f);
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.41f, 0.39f, 0.80f, 0.60f);
		colors[ImGuiCol_CheckMark] = ImVec4(0.90f, 0.90f, 0.90f, 0.50f);
		colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 1.00f, 1.00f, 0.30f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(0.41f, 0.39f, 0.80f, 0.60f);
		colors[ImGuiCol_Button] = ImVec4(0.35f, 0.40f, 0.61f, 0.62f);
		colors[ImGuiCol_ButtonHovered] = ImVec4(0.40f, 0.48f, 0.71f, 0.79f);
		colors[ImGuiCol_ButtonActive] = ImVec4(0.46f, 0.54f, 0.80f, 1.00f);
		colors[ImGuiCol_Header] = ImVec4(0.40f, 0.40f, 0.90f, 0.45f);
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.45f, 0.45f, 0.90f, 0.80f);
		colors[ImGuiCol_HeaderActive] = ImVec4(0.53f, 0.53f, 0.87f, 0.80f);
		colors[ImGuiCol_Separator] = ImVec4(0.50f, 0.50f, 0.50f, 0.60f);
		colors[ImGuiCol_SeparatorHovered] = ImVec4(0.60f, 0.60f, 0.70f, 1.00f);
		colors[ImGuiCol_SeparatorActive] = ImVec4(0.70f, 0.70f, 0.90f, 1.00f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.10f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.78f, 0.82f, 1.00f, 0.60f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(0.78f, 0.82f, 1.00f, 0.90f);
		colors[ImGuiCol_Tab] = ImLerp(colors[ImGuiCol_Header], colors[ImGuiCol_TitleBgActive], 0.80f);
		colors[ImGuiCol_TabHovered] = colors[ImGuiCol_HeaderHovered];
		colors[ImGuiCol_TabActive] = ImLerp(colors[ImGuiCol_HeaderActive], colors[ImGuiCol_TitleBgActive], 0.60f);
		colors[ImGuiCol_TabUnfocused] = ImLerp(colors[ImGuiCol_Tab], colors[ImGuiCol_TitleBg], 0.80f);
		colors[ImGuiCol_TabUnfocusedActive] = ImLerp(colors[ImGuiCol_TabActive], colors[ImGuiCol_TitleBg], 0.40f);
		colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
		colors[ImGuiCol_TableHeaderBg] = ImVec4(0.27f, 0.27f, 0.38f, 1.00f);
		colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.45f, 1.00f);   // Prefer using Alpha=1.0 here
		colors[ImGuiCol_TableBorderLight] = ImVec4(0.26f, 0.26f, 0.28f, 1.00f);   // Prefer using Alpha=1.0 here
		colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.07f);
		colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);
		colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
		colors[ImGuiCol_NavHighlight] = colors[ImGuiCol_HeaderHovered];
		colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);
		//style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);//文本颜色
		////style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		//style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);//主背景
		//style->Colors[ImGuiCol_ChildBg] = ImVec4(0.07f, 0.17f, 0.09f, 1.00f);//子窗口背景
		////style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
		//style->Colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);//描边颜色
		//style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);//阴影
		////style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 1.00f, 1.00f);
		///*style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		//style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);*/
		//style->Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 0.f);//标题颜色
		//style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.07f, 0.07f, 0.09f, .0f);//标题收缩颜色
		//style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 0.f);

		//style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);//顶部菜单颜色
		//style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);//滑块背景
		//style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);//滑块按下颜色
		//style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);//滑块触碰颜色
		//style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);//滑块滑动颜色
		//style->Colors[ImGuiCol_CheckMark] = ImColor(117, 125, 255, 255);//开关选中颜色
		//style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);//横滑块
		//style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);//横滑块
		//style->Colors[ImGuiCol_Button] = ImVec4(0.37f, 0.37f, 0.37f, 1.00);//按钮颜色
		//style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f); // 按钮触碰颜色
		//style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);// 按钮按下颜色
		////style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		////style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		////style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		//style->Colors[ImGuiCol_Separator] = ImGui::ColorConvertU32ToFloat4(ImColor(180, 180, 180, 180));//分隔符

		////style->Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
		////style->Colors[ImGuiCol_SeparatorActive] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
		////style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		////style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		////style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		////style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
		////style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
		////style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
		////style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
		////style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(1.00f, 0.60f, 0.00f, 0.43f);
		////style->Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);
		//style->Colors[ImGuiCol_Tab] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);//标签颜色
		//style->Colors[ImGuiCol_TabHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);//标签触碰颜色
		//style->Colors[ImGuiCol_TabActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);//标签按下颜色

		//ImGuiIO& get_io = ImGui::GetIO();

		//static const ImWchar icons_ranges[] = { 0xe005, 0xf8ff, 0 };
		//ImFontConfig icons_config; icons_config.MergeMode = true; icons_config.PixelSnapH = true;
		////icon = get_io.Fonts->AddFontFromFileTTF("C:\\DarkStar\\biaoti.ttf", 18.0f, &icons_config, icons_ranges);
		////font = get_io.Fonts->AddFontFromFileTTF("C:\\DarkStar\\moren.ttf", 20.f, NULL, get_io.Fonts->GetGlyphRangesChineseFull());
		g_gui.refresh_asiFiles();
		g_gui.initiniCar();
		g_gui.initxmlCar();
		g_gui.inittheme();
	}

	void gui::FillRect(ImVec4 Color, ImVec4 Color2, ImVec2 Pos, ImVec2 Size, bool Filled)
	{
		ImVec2 size = ImGui::CalcItemSize(ImVec2(Size.x, Size.y), 0.0f, 0.0f);
		const ImRect c_IM(ImVec2(Pos.x + m_Position.x, Pos.y + m_Position.y), util::addImVec2(&ImVec2(Pos.x + m_Position.x, Pos.y + m_Position.y), &size));
		if (!Filled) ImGui::GetCurrentWindow()->DrawList->AddRectFilled(c_IM.Max, c_IM.Min, ImGui::GetColorU32(Color));
		else ImGui::GetCurrentWindow()->DrawList->AddRectFilledMultiColor(c_IM.Max, c_IM.Min, ImGui::GetColorU32(Color), ImGui::GetColorU32(Color2), ImGui::GetColorU32(Color2), ImGui::GetColorU32(Color));
	}

	void gui::NotificationOverlay(const char* text, const char* text2, float pos)
	{
		std::string tmp = " " + static_cast<std::string>(text);
		std::string tmp2 = " " + static_cast<std::string>(text2);
		rage::RGBA fadeoutcolor = { 44, 50, 59, 205 };
		DWORD fadeoutTimer = 0;
		if ((GetTickCount64() - fadeoutTimer) > 5000)
		{
			rage::RGBA fadeoutcolor = { 44, 50, 59, 255 };
			if (fadeoutcolor.a > 0)
			{
				fadeoutcolor.a--;
			}

			ImVec4 fadecolor = ImColor(fadeoutcolor.r, fadeoutcolor.g, fadeoutcolor.b, fadeoutcolor.a);
			NotificationRect = fadecolor;
			FillRect(NotificationRect, NotificationRect, ImVec2(1600, 60.f + pos), ImVec2(355, 50));

			rage::RGBA fadeoutcolor1 = { 138, 043, 226, 255 };

			ImVec4 fadecolor1 = ImColor(fadeoutcolor1.r, fadeoutcolor1.g, fadeoutcolor1.b, fadeoutcolor1.a);
			ImVec4 fadecolor2 = ImColor(025, 025, 112, 255);
			FillRect(fadecolor1, fadecolor2, ImVec2(1600, 60.f + pos - 10.f), ImVec2(355, 10));

			ImGui::GetWindowDrawList()->AddText({ ImVec2(1605, 60.f + pos + 5.f) }, ImGui::GetColorU32(NotificationTopText), tmp.c_str());
			ImGui::GetWindowDrawList()->AddText({ ImVec2(1610, 83.f + pos + 5.f) }, ImGui::GetColorU32(NotificationBottomText), tmp2.c_str());
		}
	}

	void gui::NotifyWindow()
	{
		ImGui::SetNextWindowPos(ImVec2(1510, 0));
		ImGui::SetNextWindowSize(ImVec2(500.f, 1100.f));
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(ImColor(0, 0, 0, 0)));
		ImGui::GetStyle().WindowBorderSize = 0.f;
		if (ImGui::Begin("Notify System", NULL, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar))
		{
			if (NotifyCount > 7) NotifyCount = 0;
			for (NotificationTemplate& notify : m_Notifications)
			{
				if ((GetTickCount64() - notify.m_Timer) < 5000)
				{
					NotificationOverlay(notify.m_Title, notify.m_Message, NotifyCount * 22.f);
					NotifyCount++;
					NotifyCount++;
					NotifyCount++;
					NotifyCount++;
				}
			}
		}
		ImGui::End();
		ImGui::PopStyleColor();
	}

	float gui::resizefloat(float val)
	{
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		float newScale = (io.DisplaySize.x * io.DisplaySize.y) / (1920.f * 1080.f);

		if (newScale > 1.0f)
			newScale = 1.f;

		return val * newScale;
	}

	void gui::SendNotification(const char* Title, const char* Message)
	{
		m_Notifications.insert(m_Notifications.begin(), {
			GetTickCount64(), TRANSLATES(Title), TRANSLATES(Message)
			});
		NotifyCount++;
	}

	void gui::topmenu()
	{
		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("战局"))
			{
				for (const SessionType& session_type : sessions)
				{
					if (ImGui::MenuItem(session_type.name))
					{
						QUEUE_JOB_BEGIN_CLAUSE(&)
						{
							features::joinType(session_type);
						}QUEUE_JOB_END_CLAUSE
					}
				}

				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("窗口"))
			{
				ImGui::MenuItem("主窗口", nullptr, &g_settings.window.main);
				ImGui::MenuItem("玩家列表", nullptr, &g_settings.window.users);
				/*ImGui::MenuItem("Logs", nullptr, &g_settings.window.log);
				ImGui::MenuItem("Debug", nullptr, &g_settings.window.debug);*/

				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("其他"))
			{
				if (ImGui::MenuItem("跳过动画"))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						CUTSCENE::STOP_CUTSCENE_IMMEDIATELY();
					}
					QUEUE_JOB_END_CLAUSE
				}
				if (ImGui::MenuItem("跳出黑屏"))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						CAM::DO_SCREEN_FADE_IN(1000);
					}
					QUEUE_JOB_END_CLAUSE
				}
				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("退出"))
			{
				if (ImGui::MenuItem("退出暗星"))
				{
					g_settings.save();
					g_running = false;
				}

				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}
	}

	void gui::playerList()
	{
		ImGui::BeginChild("PlayerList", ImVec2(260, 0), true);
		CPlayer players[32];
		std::copy(std::begin(g_settings.players), std::end(g_settings.players), std::begin(players));
		std::sort(std::begin(players), std::end(players));
		DrarTop("玩家列表");
		for (CPlayer& player : players)
		{
			if (player.is_online)
			{
				if (ImGui::Selectable(player.name, (g_settings.selected_player.id == player.id)))
				{
					g_settings.selected_player = player;
					g_settings.window.player = true;
					g_settings.SelectedPlayer = g_settings.selected_player.id;
				}
			}
		}
		ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild("PlayerList1", ImVec2(260, 0), true);
		ImGui::BeginTabBar("##1");
		if (ImGui::BeginTabItem("移除选项"))
		{
			if (CNetGamePlayer* net_player = g_settings.selected_player.net_player; net_player != nullptr)
			{
				if (CPlayerInfo* player_info = net_player->m_player_info; player_info != nullptr)
				{
					if (net_player->is_host())
					{
						if (ImGui::Button(TRANSLATES("针对战局主机"), ImVec2(0, 0)))
						{
							QUEUE_JOB_BEGIN_CLAUSE()
							{
								Ped vic = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
								TASK::CLEAR_PED_TASKS_IMMEDIATELY(vic);
								TASK::CLEAR_PED_TASKS(vic);
								TASK::CLEAR_PED_SECONDARY_TASK(vic);

								CAM::DO_SCREEN_FADE_OUT(0);
								Ped myped = PLAYER::PLAYER_PED_ID();
								Vector3 mycords = ENTITY::GET_ENTITY_COORDS(myped, 1);

								Vector3 cords5 = { -6170.000f,-40.000f,10837.000f };
								ENTITY::SET_ENTITY_COORDS(vic, cords5.x, cords5.y, cords5.z, 0, 0, 0, 0);
								script::get_current()->yield(2000ms);

								Vector3 cords6 = { -6170.000f,-40.000f,10837.000f };
								ENTITY::SET_ENTITY_COORDS(vic, cords6.x, cords6.y, cords6.z, 0, 0, 0, 0);

								script::get_current()->yield(2000ms);

								Vector3 cords7 = { -6170.000f,-40.000f,10837.000f };
								ENTITY::SET_ENTITY_COORDS(vic, cords7.x, cords7.y, cords7.z, 0, 0, 0, 0);

								features::teleportToCoords(vic, mycords);
								script::get_current()->yield(2000ms);
								CAM::DO_SCREEN_FADE_IN(1000);
							}QUEUE_JOB_END_CLAUSE
						}
					}
				}
			}

			if (ImGui::Button(TRANSLATES("老鬼崩"), ImVec2(0, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					CAM::DO_SCREEN_FADE_OUT(0);
					Ped myped = PLAYER::PLAYER_PED_ID();
					Vehicle veh = features::spawnVehicle(1784254509);
					features::attachEntity(veh);
					script::get_current()->yield(300ms);

					Vector3 mycoords = ENTITY::GET_ENTITY_COORDS(myped, 1);

					for (int i = 1; i < 50; i++)
					{
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_settings.selected_player.id), 1);
						pos.z -= 10;
						features::teleportToCoords(myped, pos);
						script::get_current()->yield(50ms);
					}
					features::teleportToCoords(myped, mycoords);

					CAM::DO_SCREEN_FADE_IN(1000);
				}QUEUE_JOB_END_CLAUSE
			}

			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
		ImGui::EndChild();
	}

	void gui::users()
	{
		//static const float height_correction = 28.f;
		//static const float width = 200.f;
		//if (g_settings.window.users)
		//{
		//	ImGuiIO& io = ImGui::GetIO(); (void)io;
		//	//float newScale = (io.DisplaySize.x * io.DisplaySize.y) / (1920.f * 1080.f);

		//	ImGui::SetNextWindowSize({ width, io.DisplaySize.y - height_correction }, ImGuiCond_Always);
		//	ImGui::SetNextWindowPos({ io.DisplaySize.x - width, height_correction }, ImGuiCond_Always);
		//	if (ImGui::Begin("###player_menu", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoNav))
		//	{
		//		auto vecButtonWidth = ImVec2(ImGui::GetWindowSize().x - 25.f, 0.0f);
		//		CPlayer players[32];
		//		std::copy(std::begin(g_settings.players), std::end(g_settings.players), std::begin(players));
		//		std::sort(std::begin(players), std::end(players));

		//		char title[64];
		//		sprintf(title, "好友 (%d)###好友列表", g_settings.friend_count);
		//		if (ImGui::TreeNode(title))
		//		{
		//			ImGui::Unindent();

		//			bool friendInLobby = false;

		//			for (auto& player : players)
		//			{
		//				if (player.is_friend && player.is_online)
		//				{
		//					friendInLobby = true;

		//					if (ImGui::Button(player.name, vecButtonWidth))
		//					{
		//						g_settings.selected_player = player;

		//						g_settings.window.player = true;
		//						g_settings.SelectedPlayer = g_settings.selected_player.id;
		//					}
		//				}
		//			}

		//			if (!friendInLobby)
		//			{
		//				ImGui::TextColored({ 180,180,180,255 }, "此战局内没有好友.");
		//			}

		//			ImGui::Indent();
		//			ImGui::TreePop();
		//			ImGui::Separator();
		//		}

		//		for (int i = 0; i < 32; i++)
		//		{
		//			tPlayerData data = features::playerData[i];
		//			if (data.IsConnected && data.IsValid)
		//			{
		//				if (data.IsHost)
		//				{
		//					if (ImGui::TreeNode("战局主机 (1)###战局主机"))
		//					{
		//						ImGui::Unindent();

		//						for (auto& player : players)
		//						{
		//							if (player.id == data.playerId)
		//							{
		//								if (ImGui::Button(player.name, vecButtonWidth))
		//								{
		//									g_settings.selected_player = player;
		//									//LOG(INFO) << g_settings.selected_player.id;
		//									g_settings.window.player = true;
		//									g_settings.SelectedPlayer = g_settings.selected_player.id;
		//								}
		//							}
		//						}

		//						ImGui::Indent();
		//						ImGui::TreePop();
		//					}
		//				}
		//			}
		//		}
		//		//sprintf(title, "战局主机 (1)###战局主机");
		//		////ImGui::SetNextItemOpen(true);
		//		//if (ImGui::TreeNode(title))
		//		//{
		//		//	ImGui::Unindent();

		//		//	for (auto& player : players)
		//		//	{
		//		//		if (player.net_player->is_host())
		//		//		{
		//		//			if (ImGui::Button(player.name, vecButtonWidth))
		//		//			{
		//		//				g_settings.selected_player = player;
		//		//
		//		//				g_settings.window.player = true;
		//		//				g_settings.SelectedPlayer = g_settings.selected_player.id;
		//		//			}
		//		//		}
		//		//	}

		//		//	ImGui::Indent();
		//		//	ImGui::TreePop();
		//		//}

		//		sprintf(title, "全部玩家 (%d)###玩家列表", g_settings.player_count);
		//		//ImGui::SetNextItemOpen(true);
		//		if (ImGui::TreeNode(title))
		//		{
		//			ImGui::Unindent();

		//			for (auto& player : players)
		//			{
		//				if (player.is_online)
		//				{
		//					if (ImGui::Button(player.name, vecButtonWidth))
		//					{
		//						g_settings.selected_player = player;
		//						//LOG(INFO) << g_settings.selected_player.id;
		//						g_settings.window.player = true;
		//						g_settings.SelectedPlayer = g_settings.selected_player.id;
		//					}
		//				}
		//			}

		//			ImGui::Indent();
		//			ImGui::TreePop();
		//		}

		//		ImGui::End();
		//	}
		//}
	}

	BOOL gui::DrawLine(tPlayerData data, ImVec2 a, ImVec2 b)
	{
		if ((a.x < 0) || (a.y < 0) || (b.x < 0) || (b.y < 0))
			return FALSE;

		ImU32 color = ImGui::ColorConvertFloat4ToU32(g_gui.espColor);

		ImGuiWindow* window = ImGui::GetCurrentWindow();
		window->DrawList->AddLine(a, b, color);
		return TRUE;
	}

	BOOL gui::Draw2DBox(tPlayerData data, ImVec2 head, ImVec2 feet)
	{
		if ((head.x < 0) || (head.y < 0) || (feet.x < 0) || (feet.y < 0))
			return FALSE;

		float height = head.y - feet.y;
		float width = height / 2.6f;
		ImGuiWindow* window = ImGui::GetCurrentWindow();

		ImU32 color = ImGui::ColorConvertFloat4ToU32(g_gui.espColor);

		window->DrawList->AddLine(ImVec2(head.x - width / 2, head.y), ImVec2(head.x + width / 2, head.y), color);
		window->DrawList->AddLine(ImVec2(feet.x - width / 2, feet.y), ImVec2(feet.x + width / 2, feet.y), color);
		window->DrawList->AddLine(ImVec2(head.x - width / 2, head.y), ImVec2(feet.x - width / 2, feet.y), color);
		window->DrawList->AddLine(ImVec2(head.x + width / 2, head.y), ImVec2(feet.x + width / 2, feet.y), color);
		return TRUE;
	}

	BOOL gui::drawHealthBar(tPlayerData data, ImVec2 head, ImVec2 feet)
	{
		if ((head.x < 0) || (head.y < 0) || (feet.x < 0) || (feet.y < 0))
			return FALSE;

		ImGuiWindow* window = ImGui::GetCurrentWindow();

		if (0)
		{
			float height = head.y - feet.y;
			float width = height / 2.6f;

			float healthpercent = (data.health - 100.f) / (data.maxHealth - 100.f);
			float length = (feet.x + width / 2) - (feet.x - width / 2);
			length *= healthpercent;

			window->DrawList->AddRectFilledMultiColor(ImVec2(feet.x - width / 2, feet.y - height / 40), ImVec2(feet.x + width / 2, feet.y - height / 25 + 1.f), ImColor(0, 255, 0), ImColor(255, 0, 0), ImColor(255, 0, 0), ImColor(0, 255, 0));
			window->DrawList->AddRect(ImVec2(feet.x - width / 2, feet.y - height / 40), ImVec2(feet.x + width / 2, feet.y - height / 25 + 1.f), ImColor(0, 0, 0, 255));
			window->DrawList->AddRectFilled(ImVec2(feet.x + width / 2 - length, feet.y - height / 40), ImVec2(feet.x - width / 2, feet.y - height / 25 + 1.f), ImColor(0, 0, 0, 180));
		}
		else
		{
			float height = head.y - feet.y;
			float width = resizefloat(-75);
			float healthpercent = (data.health - 100.f) / (data.maxHealth - 100.f);
			float length = (feet.x + width / 2) - (feet.x - width / 2);
			length *= healthpercent;

			window->DrawList->AddRectFilledMultiColor(ImVec2(feet.x - width / 2, feet.y - height / 40), ImVec2(feet.x + width / 2, feet.y - height / 40 + 5.f), ImColor(0, 255, 0), ImColor(255, 0, 0), ImColor(255, 0, 0), ImColor(0, 255, 0));
			window->DrawList->AddRect(ImVec2(feet.x - width / 2, feet.y - height / 40), ImVec2(feet.x + width / 2, feet.y - height / 40 + 5.f), ImColor(0, 0, 0, 255));
			window->DrawList->AddRectFilled(ImVec2(feet.x + width / 2 - length, feet.y - height / 40), ImVec2(feet.x - width / 2, feet.y - height / 40 + 5.f), ImColor(0, 0, 0, 180));
		}

		return TRUE;
	}

	BOOL gui::DrawDistanceAndName(tPlayerData data, ImVec2 head, ImVec2 feet)
	{
		if ((head.x < 0) || (head.y < 0) || (feet.x < 0) || (feet.y < 0))
			return FALSE;

		ImGuiWindow* window = ImGui::GetCurrentWindow();
		float height = feet.y - head.y;
		float width = resizefloat(75);

		ImU32 color = ImGui::ColorConvertFloat4ToU32(g_gui.espColor);

		std::string info = '[' + std::to_string((int)data.distance) + "m] " + data.playerName;
		window->DrawList->AddText(ImVec2(head.x - width / 2, head.y - height / 10 - ImGui::GetTextLineHeight()), color, info.c_str());

		return TRUE;
	}

	ImVec2 gui::WorldToScreen(Vector3 pos)
	{
		auto& io = ImGui::GetIO();
		ImVec2 tempVec2;
		g_pointers->m_world_to_screen({ pos.x, pos.y, pos.z }, &tempVec2.x, &tempVec2.y);
		tempVec2.x *= io.DisplaySize.x;
		tempVec2.y *= io.DisplaySize.y;
		return tempVec2;
	}

	void gui::backgroundOverlay()
	{
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0.0f, 0.0f });
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));

		ImGuiIO& io = ImGui::GetIO();
		ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
		ImGui::SetNextWindowSize(ImVec2(io.DisplaySize.x, io.DisplaySize.y), ImGuiCond_Always);

		if (ImGui::Begin("##BackgroundOverlay", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoInputs))
		{
			//ImGui::PushFont(textFont);
			ImGuiWindow* window = ImGui::GetCurrentWindow();
			maxWindowPos = ImGui::GetWindowPos();
			maxWindowSize = ImGui::GetWindowSize();

			u32_crosshairColor = ImGui::ColorConvertFloat4ToU32(crosshairColor);

			if (g_settings.options["crosshair"])
			{
				if (features::localData.alive)
				{
					if (g_pointers->m_menu_ptr)
					{
						if (!*g_pointers->m_menu_ptr)
						{
							static float size = 16;

							ImVec2 line1_start(io.DisplaySize.x / 2 - size / 2, io.DisplaySize.y / 2);
							ImVec2 line1_end(io.DisplaySize.x / 2 + size / 2, io.DisplaySize.y / 2);
							window->DrawList->AddLine(line1_start, line1_end, u32_crosshairColor);

							ImVec2 line2_start(io.DisplaySize.x / 2, io.DisplaySize.y / 2 - size / 2);
							ImVec2 line2_end(io.DisplaySize.x / 2, io.DisplaySize.y / 2 + size / 2);
							window->DrawList->AddLine(line2_start, line2_end, u32_crosshairColor);
						}
					}
				}
			}

			if (g_settings.options["esp_fps"])
			{
				//	//% .3f ms / frame(% .1f FPS), 1000.0f / ,
				float framerate = ImGui::GetIO().Framerate;
				std::string fps = (std::to_string(framerate) + " FPS");
				window->DrawList->AddText(ImVec2(io.DisplaySize.x - ImGui::CalcTextSize(fps.c_str()).x, 2), ImColor(255, 255, 255), fps.c_str());
			}

			if (*g_pointers->m_is_session_started)
			{
				for (tPlayerData data : features::playerData)
				{
					if (data.IsValid && data.IsConnected)
					{
						if (data.distance < 2500)
						{
							if (g_settings.options["2dbox"])
							{
								if (data.IsInVehicle)
									Draw2DBox(data, WorldToScreen({ data.head.x, data.head.y, data.head.z + 0.2f }), WorldToScreen({ data.head.x, data.head.y, data.lFoot.z - 0.1f }));
								else
									Draw2DBox(data, WorldToScreen({ data.position.x, data.position.y, data.position.z + 0.9f }), WorldToScreen({ data.position.x, data.position.y, data.position.z - 1.2f }));
							}

							if (g_settings.options["3dbox"])
							{
								if (data.IsInVehicle)
								{
									ImVec2 top1world = WorldToScreen({ data.position.x + 0.3f, data.position.y + 0.3f, data.position.z + .8f });
									ImVec2 top2world = WorldToScreen({ data.position.x - 0.3f, data.position.y + 0.3f, data.position.z + .8f });
									ImVec2 top3world = WorldToScreen({ data.position.x + 0.3f, data.position.y - 0.3f, data.position.z + .8f });
									ImVec2 top4world = WorldToScreen({ data.position.x - 0.3f, data.position.y - 0.3f, data.position.z + .8f });
									ImVec2 bottom1world = WorldToScreen({ data.position.x + 0.3f, data.position.y + 0.3f, data.lFoot.z - 0.1f });
									ImVec2 bottom2world = WorldToScreen({ data.position.x - 0.3f, data.position.y + 0.3f, data.lFoot.z - 0.1f });
									ImVec2 bottom3world = WorldToScreen({ data.position.x + 0.3f, data.position.y - 0.3f, data.lFoot.z - 0.1f });
									ImVec2 bottom4world = WorldToScreen({ data.position.x - 0.3f, data.position.y - 0.3f, data.lFoot.z - 0.1f });

									DrawLine(data, top1world, top2world);
									DrawLine(data, top2world, top4world);
									DrawLine(data, top3world, top4world);
									DrawLine(data, top3world, top1world);

									DrawLine(data, bottom1world, bottom2world);
									DrawLine(data, bottom2world, bottom4world);
									DrawLine(data, bottom3world, bottom4world);
									DrawLine(data, bottom3world, bottom1world);

									DrawLine(data, bottom1world, top1world);
									DrawLine(data, bottom2world, top2world);
									DrawLine(data, bottom3world, top3world);
									DrawLine(data, bottom4world, top4world);
								}
								else
								{
									ImVec2 top1world = WorldToScreen({ data.position.x + 0.3f, data.position.y + 0.3f, data.position.z + .8f });
									ImVec2 top2world = WorldToScreen({ data.position.x - 0.3f, data.position.y + 0.3f, data.position.z + .8f });
									ImVec2 top3world = WorldToScreen({ data.position.x + 0.3f, data.position.y - 0.3f, data.position.z + .8f });
									ImVec2 top4world = WorldToScreen({ data.position.x - 0.3f, data.position.y - 0.3f, data.position.z + .8f });
									ImVec2 bottom1world = WorldToScreen({ data.position.x + 0.3f, data.position.y + 0.3f, data.position.z - 1.0f });
									ImVec2 bottom2world = WorldToScreen({ data.position.x - 0.3f, data.position.y + 0.3f, data.position.z - 1.0f });
									ImVec2 bottom3world = WorldToScreen({ data.position.x + 0.3f, data.position.y - 0.3f, data.position.z - 1.0f });
									ImVec2 bottom4world = WorldToScreen({ data.position.x - 0.3f, data.position.y - 0.3f, data.position.z - 1.0f });

									DrawLine(data, top1world, top2world);
									DrawLine(data, top2world, top4world);
									DrawLine(data, top3world, top4world);
									DrawLine(data, top3world, top1world);

									DrawLine(data, bottom1world, bottom2world);
									DrawLine(data, bottom2world, bottom4world);
									DrawLine(data, bottom3world, bottom4world);
									DrawLine(data, bottom3world, bottom1world);

									DrawLine(data, bottom1world, top1world);
									DrawLine(data, bottom2world, top2world);
									DrawLine(data, bottom3world, top3world);
									DrawLine(data, bottom4world, top4world);
								}
							}

							if (g_settings.options["Skeleton"])
							{
								DrawLine(data, WorldToScreen(data.head), WorldToScreen(data.neck));
								DrawLine(data, WorldToScreen(data.neck), WorldToScreen(data.stomach));
								DrawLine(data, WorldToScreen(data.stomach), WorldToScreen(data.pelvis));
								DrawLine(data, WorldToScreen(data.pelvis), WorldToScreen(data.lThigh));
								DrawLine(data, WorldToScreen(data.pelvis), WorldToScreen(data.rThigh));
								DrawLine(data, WorldToScreen(data.lThigh), WorldToScreen(data.lCalf));
								DrawLine(data, WorldToScreen(data.rThigh), WorldToScreen(data.rCalf));
								DrawLine(data, WorldToScreen(data.lCalf), WorldToScreen(data.lFoot));
								DrawLine(data, WorldToScreen(data.rCalf), WorldToScreen(data.rFoot));
								DrawLine(data, WorldToScreen(data.neck), WorldToScreen(data.lClavicle));
								DrawLine(data, WorldToScreen(data.neck), WorldToScreen(data.rClavicle));
								DrawLine(data, WorldToScreen(data.lClavicle), WorldToScreen(data.lUpperArm));
								DrawLine(data, WorldToScreen(data.rClavicle), WorldToScreen(data.rUpperArm));
								DrawLine(data, WorldToScreen(data.lUpperArm), WorldToScreen(data.lForeArm));
								DrawLine(data, WorldToScreen(data.rUpperArm), WorldToScreen(data.rForeArm));
								DrawLine(data, WorldToScreen(data.lForeArm), WorldToScreen(data.lHand));
								DrawLine(data, WorldToScreen(data.rForeArm), WorldToScreen(data.rHand));
								DrawLine(data, WorldToScreen(data.head), WorldToScreen(data.neck));
								DrawLine(data, WorldToScreen(data.head), WorldToScreen(data.neck));
							}

							if (g_settings.options["Health bar"])
							{
								if (data.IsInVehicle)
									drawHealthBar(data, WorldToScreen({ data.head.x, data.head.y, data.head.z + 0.2f }), WorldToScreen({ data.head.x, data.head.y, data.lFoot.z - 0.1f }));
								else
									drawHealthBar(data, WorldToScreen({ data.position.x, data.position.y, data.position.z + 0.9f }), WorldToScreen({ data.position.x, data.position.y, data.position.z - 1.2f }));
							}
							if (g_settings.options["nameesp"])
							{
								if (data.IsInVehicle)
									DrawDistanceAndName(data, WorldToScreen({ data.head.x, data.head.y, data.head.z + 0.2f }), WorldToScreen({ data.head.x, data.head.y, data.lFoot.z - 0.1f }));
								else
									DrawDistanceAndName(data, WorldToScreen({ data.position.x, data.position.y, data.position.z + 0.9f }), WorldToScreen({ data.position.x, data.position.y, data.position.z - 1.2f }));
							}
							if (g_settings.options["Tracers"])
							{
								DrawLine(data, WorldToScreen({ features::localData.visualPos.x, features::localData.visualPos.y, features::localData.visualPos.z }), WorldToScreen({ data.position.x, data.position.y, data.position.z }));
							}
						}
					}
				}
			}

			if (g_gui.m_opened && g_settings.window.main)
			{
				ImGuiWindow* window = ImGui::GetCurrentWindow();
				//window->DrawList->AddRectFilled(ImVec2(mainWindowPos.x - resizefloat(167), mainWindowPos.y), ImVec2(mainWindowPos.x, mainWindowPos.y + mainWindowSize.y), ImColor(255, 255, 255, 180));
				//	window->DrawList->AddImage();

				window->DrawList->AddImage(g_renderer->ImageHeader, ImVec2(mainWindowPos.x - resizefloat(static_cast<float>(g_renderer->pHeaderSize.x)), mainWindowPos.y), ImVec2(mainWindowPos.x, mainWindowPos.y + mainWindowSize.y));
			}

			/*if (true)
				window->DrawList->AddText(ImVec2(io.DisplaySize.x / 2, 2), ImColor(255, 255, 255), features::currentTime().c_str());*/

				//ImGui::PopFont();
			ImGui::End();
		}

		ImGui::PopStyleColor();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
	}

	void gui::dx_on_tick()
	{
		gui::topmenu();
		ImGui::SetNextWindowSize(ImVec2(940.f, 680.f));
		if (g_settings.window.main && ImGui::Begin("###Dark Star", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoFocusOnAppearing))
		{
			ImGui::SetScrollX(0.f);
			mainWindowPos = ImGui::GetWindowPos();
			mainWindowSize = ImGui::GetWindowSize();

			static int tab_number = 0;

			ImGui::Columns(2, 0, false);
			ImGui::SetColumnOffset(1, 120.f);

			ImGui::PushFont(g_renderer->m_title_font);
			ImGuiStyle* style = &ImGui::GetStyle();
			float Tabheight = ImGui::GetContentRegionAvail().y / 12.f;
			ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
			int i = 0;
			for (std::string& str : menus)
			{
				if (tab_number == i)
				{
					ImGui::PushStyleColor(ImGuiCol_Button, style->Colors[ImGuiCol_ButtonHovered]);
				}
				else
				{
					ImGui::PushStyleColor(ImGuiCol_Button, style->Colors[ImGuiCol_Button]);
				}
				if (ImGui::Button(menus[i].c_str(), ImVec2(100.0f, Tabheight))) tab_number = i;
				ImGui::PopStyleColor();
				i++;
			}
			ImGui::PopStyleVar();
			ImGui::PopFont();
			ImGui::NextColumn();

			switch (tab_number)
			{
			case 0:
				selfTab();
				break;
			case 1:
				weaponTab();
				break;
			case 2:
				vehicleTab();
				break;
			case 3:
				teleportTab();
				break;
			case 4:
				onlineTab();
				break;
			case 5:
				playerList();
				break;
			case 6:
				missionTab();
				break;
			case 7:

				break;
			case 8:
				worldTab();
				break;
			case 9:
				recoveryTab();
				break;
			case 10:
				otherTab();
				break;
			case 11:
				menuTab();
				break;
			}
		}
		ImGui::End();
	}

	void gui::script_init()
	{
		g_vehicles.initialize();
		initCar();
	}

	ImVec2 gui::resizeVec(ImVec2 vec2)
	{
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		float newScale = (io.DisplaySize.x * io.DisplaySize.y) / (1920.f * 1080.f);

		if (newScale > 1.0f)
			newScale = 1.f;

		return ImVec2(vec2.x * newScale, vec2.y * newScale);
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

	void gui::DrarTop(const char* pText)
	{
		ImGui::PushFont(g_renderer->m_title_font);
		ImGui::Text(TRANSLATES(pText));
		ImGui::PopFont();
		ImGui::Separator();
	}

	float gui::getBoxHeight(float f)
	{
		return g_renderer->m_font->FontSize + ImGui::GetFrameHeightWithSpacing() * (f - 0.5f) + ImGui::GetStyle().ItemSpacing.y * 5;
	}

	void gui::recoveryTab()
	{
		static int test = 400;
		ImGui::BeginChild("###p1", ImVec2(260, getBoxHeight(2)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("等级");
			ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
			static int value = 0;
			if (ImGui::InputInt(TRANSLATES("等级"), &value))
			{
				if (value > 8000)
				{
					value = 0;
				}
				else if (value < 0)
				{
					value = 8000;
				}
			}
			ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);
			if (ImGui::Button(TRANSLATES("更改等级"), ImVec2(219, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE(= )
				{
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CHAR_SET_RP_GIFT_ADMIN"), online::Levels[value - 1], true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_SET_RP_GIFT_ADMIN"), online::Levels[value - 1], true);
				}QUEUE_JOB_END_CLAUSE
					g_gui.SendNotification("更改等级成功", "请手动更换战局生效");
			}
			ImGui::SameLine();
			features::HelpMarker("直接输入等级数值即可，更换战局生效\n注意：此功能为危险功能");
		}
		ImGui::EndChild();
	}

	void gui::initCar()
	{
		g_settings.CarList.clear();
		std::ifstream in(std::string(MENU_PATH) + "\\TXT\\car.txt");
		char str[32] = { 0 };

		while (in.getline(str, sizeof(str), '\n'))
		{
			g_settings.CarList.push_back({ StringToChar(str) , util::vehlablename(str) });
		}
		in.close();
	}

	void gui::inittheme()
	{
		g_settings.themeList.clear();
		std::string path = (std::string(MENU_PATH) + "\\theme\\");
		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			std::string str = entry.path().generic_string();
			if (str.find(".style"))
			{
				std::size_t found = str.find_last_of(".style");
				str = str.substr(0, found - 5);

				found = str.find_last_of("/\\");
				str = str.substr(found + 1);
				g_settings.themeList.push_back(str);
			}
		}
	}

	void  gui::initxmlCar()
	{
		g_settings.XmlCarList.clear();
		std::string path = (std::string(MENU_PATH) + "\\Vehicle\\XMLVeh\\");
		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			std::string str = entry.path().generic_u8string();
			if (str.find(".xml"))
			{
				std::size_t found = str.find_last_of(".xml");
				str = str.substr(0, found - 3);

				found = str.find_last_of("/\\");
				str = str.substr(found + 1);
				g_settings.XmlCarList.push_back(str);
			}
		}
	}

	void  gui::initiniCar()
	{
		g_settings.IniCarList.clear();
		std::string path = (std::string(MENU_PATH) + "\\Vehicle\\BigMod\\");
		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			std::string str = entry.path().generic_u8string();
			if (str.find(".ini"))
			{
				std::size_t found = str.find_last_of(".ini");
				str = str.substr(0, found - 3);

				found = str.find_last_of("/\\");
				str = str.substr(found + 1);
				g_settings.IniCarList.push_back(str);
			}
		}

		g_settings.IniSmallCarList.clear();
		std::string path1 = (std::string(MENU_PATH) + "\\Vehicle\\SmallMod\\");
		for (const auto& entry1 : std::filesystem::directory_iterator(path1))
		{
			std::string str1 = entry1.path().generic_string();
			if (str1.find(".ini"))
			{
				std::size_t found1 = str1.find_last_of(".ini");
				str1 = str1.substr(0, found1 - 3);

				found1 = str1.find_last_of("/\\");
				str1 = str1.substr(found1 + 1);
				g_settings.IniSmallCarList.push_back(str1);
			}
		}
	}

	void gui::refresh_asiFiles()//初始化sai文件
	{
		g_settings.AsiList.clear();
		std::string path = (std::string(MENU_PATH) + "\\plugin\\");
		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			std::string str = entry.path().generic_u8string();
			if (str.find(".asi"))
			{
				std::size_t found = str.find_last_of(".asi");
				str = str.substr(0, found - 3);

				found = str.find_last_of("/\\");
				str = str.substr(found + 1);
				g_settings.AsiList.push_back(str);
			}
		}
	}

	void gui::otherTab()
	{
		ImGui::BeginChild("###p1_1", ImVec2(260, getBoxHeight(6.f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("ASI拓展");

			ImGui::BeginChild("###p1_1_1", ImVec2(260, getBoxHeight(3.f)), true, ImGuiWindowFlags_NoScrollbar);
			{
				for (std::string str : g_settings.AsiList)
				{
					if (ImGui::Selectable(str.c_str(), (str == g_settings.asiname)))
					{
						g_settings.asiname = str;
					}
				}
			}
			ImGui::EndChild();

			if (ImGui::Button(TRANSLATES("加载"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				g_fiber_pool->queue_job([=]
					{
						shv::g_ScriptHookV->loadAsi(g_settings.asiname);
					});
			}
		}
		ImGui::EndChild();
	}

	void gui::selfTab()
	{
		ImGui::BeginGroup();
		{
			ImGui::BeginChild("###p1", ImVec2(260, getBoxHeight(11.5f)), true, ImGuiWindowFlags_NoScrollbar);
			DrarTop("基础");
			if (ImGui::Checkbox(TRANSLATES("无敌模式"), g_settings.options["god bool"].get<bool*>()))
			{
				memory::set_value<int>({ 0x08, 0x189 }, 0);
			}
			ImGui::Checkbox(TRANSLATES("半无敌"), g_settings.options["hgod bool"].get<bool*>());
			if (ImGui::Checkbox(TRANSLATES("永不通缉"), g_settings.options["Never Wanted bool"].get<bool*>()))
			{
				PLAYER::SET_MAX_WANTED_LEVEL(5);
			}
			ImGui::SameLine();
			ImGui::SetNextItemWidth(130);
			if (ImGui::InputInt("###警星数量", &features::wantervalue))
			{
				if (features::wantervalue > 5)
				{
					features::wantervalue = 0;
				}
				if (features::wantervalue < 0)
				{
					features::wantervalue = 5;
				}
				g_local_player->m_player_info->m_wanted_level = features::wantervalue;
			}
			ImGui::PushItemWidth(130);
			ImGui::Separator();
			if (ImGui::Button(TRANSLATES("加满血量"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), ENTITY::GET_ENTITY_MAX_HEALTH(PLAYER::PLAYER_PED_ID()), 0);
			}
			if (ImGui::Button(TRANSLATES("加满护甲"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				PED::ADD_ARMOUR_TO_PED(PLAYER::PLAYER_PED_ID(), 400);
			}
			if (ImGui::Button(TRANSLATES("清洁身体"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				PED::CLEAR_ALL_PED_PROPS(PLAYER::PLAYER_PED_ID());
				PED::CLEAR_PED_BLOOD_DAMAGE(PLAYER::PLAYER_PED_ID());
				PED::CLEAR_PED_WETNESS(PLAYER::PLAYER_PED_ID());
				PED::CLEAR_PED_DECORATIONS(PLAYER::PLAYER_PED_ID());
				PED::CLEAR_PED_DECORATIONS_LEAVE_SCARS(PLAYER::PLAYER_PED_ID());
			}
			if (ImGui::Button(TRANSLATES("自杀"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 0, 0);
			}
			ImGui::Separator();

			float huakuaikuan = 180.f;
			ImGui::SetNextItemWidth(huakuaikuan);
			if (ImGui::SliderFloat(TRANSLATES("移动速度"), &features::runSpeed, 1.f, 10.f))
			{
				memory::set_value<float>({ 0x8,0x10C8,0xCF0 }, features::runSpeed);
			}
			ImGui::PushItemWidth(huakuaikuan);

			ImGui::SetNextItemWidth(huakuaikuan);
			if (ImGui::SliderFloat(TRANSLATES("游泳速度"), &features::swimSpeed, 1.f, 10.f))
			{
				memory::set_value<float>({ 0x8,0x10C8,0x170 }, features::swimSpeed);
			}
			ImGui::PushItemWidth(huakuaikuan);

			ImGui::SetNextItemWidth(huakuaikuan);
			if (ImGui::SliderFloat(TRANSLATES("潜行速度"), &features::sneakSpeed, 1.f, 10.f))
			{
				memory::set_value<float>({ 0x8,0x10C8,0x18C }, features::sneakSpeed);
			}
			ImGui::PushItemWidth(huakuaikuan);

			ImGui::SetNextItemWidth(huakuaikuan);
			static int playeralpha = 255;
			const int min = 0, max = 255;
			if (ImGui::SliderScalar(TRANSLATES("不透明度"), ImGuiDataType_S32, &playeralpha, &min, &max))
			{
				ENTITY::SET_ENTITY_ALPHA(features::localData.localPed, playeralpha, 0);
			}
			ImGui::PushItemWidth(huakuaikuan);
			ImGui::EndChild();
		}

		ImGui::BeginChild("###p1_2", ImVec2(260, getBoxHeight(3.0f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("播放动作");
			static int item_current = 0;
			ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
			ImGui::Combo("###播放动作", &item_current, animOutputList, IM_ARRAYSIZE(animOutputList));
			ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);
			if (ImGui::Button(TRANSLATES("播放"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::DoScenario(animDictList[item_current], animNameList[item_current]);
				}QUEUE_JOB_END_CLAUSE
			}
			if (ImGui::Button(TRANSLATES("停止"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					TASK::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
				}QUEUE_JOB_END_CLAUSE
			}
		}
		ImGui::EndChild();
		ImGui::EndGroup();

		ImGui::SameLine();
		{
			ImGui::BeginGroup();
			ImGui::BeginChild("###p2", ImVec2(260, getBoxHeight(8.0f)), true, ImGuiWindowFlags_NoScrollbar);
			DrarTop("控制");
			if (ImGui::Checkbox(TRANSLATES("无布娃娃"), g_settings.options["nobo"].get<bool*>()))
			{
				PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), true);
				PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), true);
				PLAYER::GIVE_PLAYER_RAGDOLL_CONTROL(PLAYER::PLAYER_ID(), true);
			}
			if (ImGui::Checkbox(TRANSLATES("隐身"), g_settings.options["yinshen"].get<bool*>()))
			{
				ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), 1, 0);
				NETWORK::_NETWORK_SET_ENTITY_INVISIBLE_TO_NETWORK(PLAYER::PLAYER_PED_ID(), 1);
			}
			if (ImGui::Checkbox(TRANSLATES("无视墙体"), g_settings.options["chuanqiang"].get<bool*>()))
			{
				memory::set_value<float>({ 0x8,0x30,0x10,0x20,0x70,0x0,0x2C }, 0.25);
			}
			ImGui::SameLine();
			features::HelpMarker("小心不要掉入地下");
			if (ImGui::Checkbox(TRANSLATES("自由视角"), g_settings.options["ziyoucam"].get<bool*>()))
			{
				auto ped = PLAYER::PLAYER_PED_ID();
				if (PED::IS_PED_IN_ANY_VEHICLE(ped, 0))
				{
					ped = PED::GET_VEHICLE_PED_IS_USING(ped);
				}
				ENTITY::SET_ENTITY_VISIBLE(ped, 1, 0);
				NETWORK::_NETWORK_SET_ENTITY_INVISIBLE_TO_NETWORK(ped, 1);
			}
			ImGui::SameLine();
			features::HelpMarker("鼠标控制方向，W前进");
			ImGui::Checkbox(TRANSLATES("超级移速"), g_settings.options["superrun"].get<bool*>());
			ImGui::Checkbox(TRANSLATES("超级跳跃"), g_settings.options["chaojitiao"].get<bool*>());
			ImGui::Checkbox(TRANSLATES("超人跳跃"), g_settings.options["chaorentiao"].get<bool*>());
			ImGui::Checkbox(TRANSLATES("空中行走"), g_settings.options["qzzou"].get<bool*>());
			ImGui::SameLine();
			features::HelpMarker("Q上升，Z下降，空中可移动");
			ImGui::EndChild();

			ImGui::BeginChild("###p3", ImVec2(260, getBoxHeight(2)), true, ImGuiWindowFlags_NoScrollbar);
			DrarTop("更换模型");
			static int item_current = 0;
			ImGui::SetNextItemWidth(219);
			ImGui::Combo("###更换模型", &item_current, playerModels, IM_ARRAYSIZE(playerModels));
			ImGui::PushItemWidth(219);
			ImGui::SameLine();
			features::HelpMarker("换战局即可恢复");
			if (ImGui::Button(TRANSLATES("切换"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					Hash hash = MISC::GET_HASH_KEY(playerModels[item_current]);
					if (STREAMING::IS_MODEL_IN_CDIMAGE(hash) && STREAMING::IS_MODEL_VALID(hash))
					{
						STREAMING::REQUEST_MODEL(hash);
						while (!STREAMING::HAS_MODEL_LOADED(hash)) script::get_current()->yield(0ms);
						PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), hash);
						PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
						ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), ENTITY::GET_ENTITY_MAX_HEALTH(PLAYER::PLAYER_PED_ID()), 0);
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						char info[255];
						sprintf(info, "成功更换模型为：%s", playerModels[item_current]);
						//g_gui.SendNotification("更换模型", info);
					}
				}QUEUE_JOB_END_CLAUSE
			}
			ImGui::EndChild();
			ImGui::EndGroup();
		}
	}

	void gui::weaponTab()
	{
		ImGui::BeginGroup();
		ImGui::BeginChild("###p1", ImVec2(260, getBoxHeight(9.5f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("基础");
			if (ImGui::Button(TRANSLATES("获取全部武器"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::getAllWeapon(PLAYER::PLAYER_ID());
				}QUEUE_JOB_END_CLAUSE
			}

			if (ImGui::Button(TRANSLATES("移除全部武器"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::removeAllWeapon(PLAYER::PLAYER_ID());
				}QUEUE_JOB_END_CLAUSE
			}
			if (ImGui::Button(TRANSLATES("加满所有子弹"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::getFullAmmo(PLAYER::PLAYER_ID());
				}QUEUE_JOB_END_CLAUSE
			}
			if (ImGui::Button(TRANSLATES("满配MK2武器"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				std::uint32_t ped = PLAYER::PLAYER_PED_ID();
				const char* weaponAddons[] = { "COMPONENT_AT_SCOPE_MACRO" ,"COMPONENT_AT_SCOPE_MACRO_02" ,"COMPONENT_AT_SCOPE_SMALL" ,"COMPONENT_AT_SCOPE_SMALL_02" ,"COMPONENT_AT_SCOPE_MEDIUM" ,"COMPONENT_AT_SCOPE_LARGE" ,"COMPONENT_AT_SCOPE_MAX" ,"COMPONENT_AT_RAILCOVER_01" ,"COMPONENT_AT_AR_AFGRIP" ,"COMPONENT_AT_PI_FLSH" ,"COMPONENT_AT_AR_FLSH" ,"COMPONENT_PISTOL_CLIP_02" ,"COMPONENT_COMBATPISTOL_CLIP_02" ,"COMPONENT_APPISTOL_CLIP_02" ,"COMPONENT_MICROSMG_CLIP_02" ,"COMPONENT_SMG_CLIP_02" ,"COMPONENT_ASSAULTRIFLE_CLIP_02" ,"COMPONENT_CARBINERIFLE_CLIP_02" ,"COMPONENT_ADVANCEDRIFLE_CLIP_02" ,"COMPONENT_MG_CLIP_02" ,"COMPONENT_COMBATMG_CLIP_02" ,"COMPONENT_ASSAULTSHOTGUN_CLIP_02" ,"COMPONENT_PISTOL50_CLIP_02" ,"COMPONENT_ASSAULTSMG_CLIP_02" ,"COMPONENT_SNSPISTOL_CLIP_02" ,"COMPONENT_COMBATPDW_CLIP_02" ,"COMPONENT_HEAVYPISTOL_CLIP_02" ,"COMPONENT_SPECIALCARBINE_CLIP_02" ,"COMPONENT_BULLPUPRIFLE_CLIP_02" ,"COMPONENT_VINTAGEPISTOL_CLIP_02" ,"COMPONENT_MARKSMANRIFLE_CLIP_02" ,"COMPONENT_HEAVYSHOTGUN_CLIP_02" ,"COMPONENT_GUSENBERG_CLIP_02" };
				Hash hash = WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &hash, 1);

				for (const char* addonHash : weaponAddons)
				{
					Hash hash = MISC::GET_HASH_KEY(addonHash);
					if (WEAPON::DOES_WEAPON_TAKE_WEAPON_COMPONENT(hash, hash))
						WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(ped, hash, hash);
				}
				const char* silencers[] = { "COMPONENT_AT_PI_SUPP","COMPONENT_AT_PI_SUPP_02","COMPONENT_AT_AR_SUPP","COMPONENT_AT_SR_SUPP","COMPONENT_AT_AR_SUPP_02" };
				for (const char* silencerHash : silencers)
				{
					Hash hash = MISC::GET_HASH_KEY(silencerHash);
					//错误
					if (WEAPON::DOES_WEAPON_TAKE_WEAPON_COMPONENT((char)weapon::allWeapons, hash)) {
						if (hash != WEAPON_ADVANCEDRIFLE && WEAPON::GET_WEAPONTYPE_GROUP(hash) != 160)
							WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(ped, hash, hash);
					}
				}
				Hash hashes = MISC::GET_HASH_KEY("COMPONENT_AT_AR_SUPP_02");
				if (hash == WEAPON_SNIPERRIFLE || hash == WEAPON_MICROSMG)
					WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(ped, hash, hashes);
				std::vector<Hash> pistolMk2{ 1329061674, 2396306288, 1140676955, 1709866683, 568543123, 2467084625 };
				std::vector<Hash> smgMk2{ 190476639, 2076495324, 2681951826, 3842157419, 1038927834, 1303784126, 2774849419, 966612367 };
				std::vector<Hash> assltRifleMk2{ 1675665560, 2640679034, 2076495324, 1108334355, 77277509, 3328927042, 2805810788, 1303784126, 1447477866, 3115408816 };
				std::vector<Hash> carbineRifleMk2{ 1141059345, 2640679034, 2076495324, 1108334355, 77277509, 3328927042, 2205435306, 1303784126, 2335983627, 3663056191 };
				std::vector<Hash> combatMgMk2{ 1475288264, 2640679034, 1108334355, 1060929921, 3328927042, 1303784126, 3051509595, 3607349581 };
				std::vector<Hash> heavySniperMk2{ 2313935527, 2193687427, 3159677559, 3061846192, 776198721, 2890063729, 1764221345, 277524638, 1815270123 };
				std::vector<Hash> WeaponHash{ 0xBFE256D4, 0x78A97CD0, 0xDBBD7280, 0x394F415C, 0xFAD1F1C9, 0xA914799 };

				for (Hash hash : pistolMk2)
					WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_PISTOL_MK2"), hash);

				for (Hash hash : smgMk2)
					WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_SMG_MK2"), hash);

				for (Hash hash : assltRifleMk2)
					WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), hash);

				for (Hash hash : carbineRifleMk2)
					WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), hash);

				for (Hash hash : combatMgMk2)
					WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), hash);

				for (Hash hash : heavySniperMk2)
					WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), hash);

				for (Hash hash : WeaponHash)
					WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), hash, 9999, 0);
			}

			ImGui::Separator();

			if (ImGui::Checkbox(TRANSLATES("爆炸子弹"), g_settings.options["baozhazidan"].get<bool*>()))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::removeFlameFlag(eFrameFlagExplosiveAmmo);
				}QUEUE_JOB_END_CLAUSE
			}
			ImGui::SameLine();
			ImGui::Checkbox(TRANSLATES("一枪毙命"), g_settings.options["miaosha"].get<bool*>());

			ImGui::Checkbox(TRANSLATES("无限子弹"), g_settings.options["wuxianzidan"].get<bool*>());
			ImGui::SameLine();
			if (ImGui::Checkbox(TRANSLATES("快速射击"), g_settings.options["kuaishe"].get<bool*>()))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_ID(), 0);
				}QUEUE_JOB_END_CLAUSE
			}
			ImGui::SameLine();
			features::HelpMarker("无视换弹CD，按下鼠标右键即可持续射击");

			ImGui::Separator();

			float huakuaikuan = 180;
			static float houzuoli = 0.;

			ImGui::SetNextItemWidth(huakuaikuan);
			if (ImGui::SliderFloat(TRANSLATES("后坐力"), &houzuoli, 0.f, 5.f))
			{
				memory::set_value<float>({ 0x08, 0x10D8,0x20,0x2F4 }, houzuoli);
			}
			ImGui::PushItemWidth(huakuaikuan);

			static float shanghai = 0.;

			ImGui::SetNextItemWidth(huakuaikuan);
			if (ImGui::SliderFloat(TRANSLATES("伤害倍数"), &shanghai, 0.f, 500.f))
			{
				memory::set_value<float>({ 0x8, 0x10D8, 0x20,0xB0 }, shanghai);
			}
			ImGui::PushItemWidth(huakuaikuan);

			static float chongneng = 0.;

			ImGui::SetNextItemWidth(huakuaikuan);
			if (ImGui::SliderFloat(TRANSLATES("充能时间"), &chongneng, 0.f, 5.f))
			{
				memory::set_value<float>({ 0x08, 0x10D8,0x20,0x13C }, chongneng);
			}
			ImGui::PushItemWidth(huakuaikuan);
		}
		ImGui::EndChild();

		ImGui::EndGroup();

		ImGui::SameLine();
		ImGui::BeginChild("###p2", ImVec2(260, getBoxHeight(7.0f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("特殊效果");
			ImGui::Checkbox(TRANSLATES("彩虹枪"), g_settings.options["rainbowgun"].get<bool*>());
			ImGui::Checkbox(TRANSLATES("随机PED枪"), g_settings.options["pedgun"].get<bool*>());
			ImGui::Checkbox(TRANSLATES("载具枪"), g_settings.options["cargun"].get<bool*>());
			ImGui::Checkbox(TRANSLATES("删除目标物体"), g_settings.options["delgun"].get<bool*>());
			ImGui::Checkbox(TRANSLATES("绳索枪（传送）"), g_settings.options["tpgun"].get<bool*>());
			ImGui::Checkbox(TRANSLATES("喷漆枪"), g_settings.options["Paintgun"].get<bool*>());
			ImGui::SameLine(); features::HelpMarker("对载具进行随机喷漆");
			ImGui::Checkbox(TRANSLATES("重力控制枪"), g_settings.options["Gravitygun"].get<bool*>());
		}
		ImGui::EndChild();
	}

	void gui::worldTab()
	{
		//static int test = 400;
		//ImGui::SliderInt("Opacity", &test, 0, 600);
		ImGui::BeginGroup();
		ImGui::BeginChild("###p1_1", ImVec2(260, getBoxHeight(6.f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("附近NPC");
			if (ImGui::Button(TRANSLATES("杀死附近npc"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::killNearbyPeds();
				}QUEUE_JOB_END_CLAUSE
			}
			if (ImGui::Button(TRANSLATES("删除附近npc"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::deleteNearbyPeds();
				}QUEUE_JOB_END_CLAUSE
			}
			if (ImGui::Button(TRANSLATES("将附近的NPC传送到自己"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::pedStpme();
				}QUEUE_JOB_END_CLAUSE
			}
			if (ImGui::Button(TRANSLATES("爆炸附近的NPC"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::explodeNearbyPeds();
				}QUEUE_JOB_END_CLAUSE
			}

			if (ImGui::Button(TRANSLATES("让附近的司机下车"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::exitCar();
				}QUEUE_JOB_END_CLAUSE
			}
			if (ImGui::Button(TRANSLATES("让附近的司机去导航点"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					int WaypointHandle = HUD::GET_FIRST_BLIP_INFO_ID(8);
					Ped Driver = PLAYER::PLAYER_PED_ID();
					Vector3 waypoint1 = HUD::GET_BLIP_COORDS(WaypointHandle);
					const int ElementAmount = 10;
					const int ArrSize = ElementAmount * 2 + 2;

					Ped* peds = new Ped[ArrSize];
					peds[0] = ElementAmount;

					int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

					for (int i = 0; i < PedFound; i++)
					{
						int OffsetID = i * 2 + 2;
						util::requestControlOfEnt(peds[OffsetID]);
					}
					for (int i = 0; i < PedFound; i++)
					{
						int OffsetID = i * 2 + 2;
						util::requestControlOfEnt(peds[OffsetID]);
						Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(peds[OffsetID]);
						if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
						{
							TASK::TASK_VEHICLE_DRIVE_TO_COORD(peds[OffsetID], veh, waypoint1.x, waypoint1.y, waypoint1.z, 40, 1, ENTITY::GET_ENTITY_MODEL(veh), 7, 6, -1);
						}
					}
				}QUEUE_JOB_END_CLAUSE
			}
		}
		ImGui::EndChild();

		ImGui::BeginChild("###p1_2", ImVec2(260, getBoxHeight(3.f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("附近载具");
			if (ImGui::Button(TRANSLATES("升级附近的载具"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::upgradeNearbyVehicles();
				}QUEUE_JOB_END_CLAUSE
			}
			if (ImGui::Button(TRANSLATES("删除附近的载具"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::deleteNearbyVehicles();
				}QUEUE_JOB_END_CLAUSE
			}
			if (ImGui::Button(TRANSLATES("让附近的载具爆炸"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::explodeNearbyVehicles();
				}QUEUE_JOB_END_CLAUSE
			}
		}
		ImGui::EndChild();

		ImGui::BeginChild("###p1_3", ImVec2(260, getBoxHeight(3.f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("天气");

			const char* tianqi[] =
			{
				"晴朗", "干净", "多云", "小雾", "大雾", "阴天", "小雨", "雷雨", "温室", "小雪", "暴雪", "雪光", "万圣"
			};
			const char* weather[] =
			{
				 "ExtraSunny", "Clear", "Clouds", "Smog", "Foggy", "Overcast", "Rain", "Thunder", "Neutral", "Snow", "Blizzard", "SnowLight", "Halloween"
			};
			static int tianqi_current = 0;
			ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
			ImGui::Combo("###天气", &tianqi_current, tianqi, IM_ARRAYSIZE(tianqi));
			ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);
			if (ImGui::Button(TRANSLATES("设定天气"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE(weather)
				{
					MISC::SET_OVERRIDE_WEATHER(weather[tianqi_current]);
					MISC::SET_WEATHER_TYPE_NOW(weather[tianqi_current]);
					MISC::SET_WEATHER_TYPE_NOW_PERSIST(weather[tianqi_current]);
				}QUEUE_JOB_END_CLAUSE
			}
			if (ImGui::Button(TRANSLATES("来一发闪电"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				MISC::FORCE_LIGHTNING_FLASH();
			}
		}
		ImGui::EndChild();
		ImGui::EndGroup();
		ImGui::SameLine();

		ImGui::BeginGroup();
		ImGui::BeginChild("###p2_1", ImVec2(260, getBoxHeight(4.f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("时间");

			ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);

			static int hour = 0;
			if (ImGui::InputInt(TRANSLATES("小时"), &hour))
			{
				if (hour > 24)
				{
					hour = 0;
				}
				if (hour < 0)
				{
					hour = 24;
				}
				int clock_hours = CLOCK::GET_CLOCK_HOURS();
				int clock_minutes = CLOCK::GET_CLOCK_MINUTES();
				int clock_seconds = CLOCK::GET_CLOCK_SECONDS();
				CLOCK::SET_CLOCK_TIME(hour, clock_minutes, clock_seconds);
				NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(hour, clock_minutes, clock_seconds);
			}
			ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);

			ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
			static int minutes = 0;
			if (ImGui::InputInt(TRANSLATES("分"), &minutes))
			{
				if (minutes > 60)
				{
					minutes = 0;
				}
				if (minutes < 0)
				{
					minutes = 60;
				}
				int clock_hours = CLOCK::GET_CLOCK_HOURS();
				int clock_minutes = CLOCK::GET_CLOCK_MINUTES();
				int clock_seconds = CLOCK::GET_CLOCK_SECONDS();
				CLOCK::SET_CLOCK_TIME(clock_hours, minutes, clock_seconds);
				NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(clock_hours, minutes, clock_seconds);
			}
			ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);

			ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
			static int seconds = 0;
			if (ImGui::InputInt(TRANSLATES("秒"), &seconds))
			{
				if (seconds > 60)
				{
					seconds = 0;
				}
				if (seconds < 0)
				{
					seconds = 60;
				}
				int clock_hours = CLOCK::GET_CLOCK_HOURS();
				int clock_minutes = CLOCK::GET_CLOCK_MINUTES();
				int clock_seconds = CLOCK::GET_CLOCK_SECONDS();
				CLOCK::SET_CLOCK_TIME(clock_hours, clock_minutes, seconds);
				NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(clock_hours, clock_minutes, seconds);
			}
			ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);

			if (ImGui::Button(TRANSLATES("同步系统时间"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				time_t     now = time(0);
				struct tm  tstruct;

				localtime_s(&tstruct, &now);
				CLOCK::SET_CLOCK_TIME(tstruct.tm_hour, tstruct.tm_min, tstruct.tm_sec);
				NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(tstruct.tm_hour, tstruct.tm_min, tstruct.tm_sec);
			}
		}
		ImGui::EndChild();

		ImGui::BeginChild("###p2_2", ImVec2(260, getBoxHeight(3.f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("世界参数");
			static float orcanlevel = 0;
			static float rainlevel = 0;
			static float windlevel = 0;
			if (ImGui::SliderFloat(TRANSLATES("海浪强度"), &orcanlevel, 0.f, 100.f))
			{
				g_fiber_pool->queue_job([=]
					{
						WATER::SET_DEEP_OCEAN_SCALER(orcanlevel);
					});
			}
			if (ImGui::SliderFloat(TRANSLATES("雨水强度"), &rainlevel, 0.f, 100.f))
			{
				g_fiber_pool->queue_job([=]
					{
						MISC::_SET_RAIN_FX_INTENSITY(rainlevel);
					});
			}
			if (ImGui::SliderFloat(TRANSLATES("风强度"), &windlevel, 0.f, 100.f))
			{
				g_fiber_pool->queue_job([=]
					{
						MISC::SET_WIND_SPEED(windlevel);
					});
			}
		}
		ImGui::EndChild();
		ImGui::BeginChild("###p2_3", ImVec2(260, getBoxHeight(2.f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("视觉效果");

			static int item_current = 0;
			ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
			ImGui::Combo("###视觉效果", &item_current, visual_ch, IM_ARRAYSIZE(visual_ch));
			ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);
			if (ImGui::Button(TRANSLATES("切换"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				GRAPHICS::SET_TIMECYCLE_MODIFIER(visual_en[item_current]);
			}
		}
		ImGui::EndChild();

		ImGui::EndGroup();
	}

	void gui::missionTab()
	{
		ImGui::BeginTabBar("##renwuxuanxiang");
		if (ImGui::BeginTabItem("名钻赌场"))
		{
			ImGui::BeginGroup();
			ImGui::BeginChild("###p1", ImVec2(260, getBoxHeight(7.0f)), true, ImGuiWindowFlags_NoScrollbar);
			DrarTop("第一块板");
			ImGui::Text(TRANSLATES("抢劫方式"));
			const char* fangshi[] =
			{
				"隐匿潜踪","兵不厌诈","气势汹汹"
			};
			static int fangshi_current = 0;
			ImGui::SetNextItemWidth(140);
			ImGui::Combo("###抢劫方式", &fangshi_current, fangshi, IM_ARRAYSIZE(fangshi));
			ImGui::PushItemWidth(140);

			ImGui::SameLine();
			ImGui::Checkbox(TRANSLATES("困难"), g_settings.options["dckunnan"].get<bool*>());

			ImGui::Text(TRANSLATES("抢劫目标"));
			const char* mubiao[] =
			{
				"钻石","艺术品","黄金","现金"
			};
			static int mubiao_current = 0;
			ImGui::SetNextItemWidth(200);
			ImGui::Combo("###抢劫目标", &mubiao_current, mubiao, IM_ARRAYSIZE(mubiao));
			ImGui::PushItemWidth(200);
			static int dian = 0;
			ImGui::RadioButton(TRANSLATES("所有探查点"), &dian, 0);
			ImGui::SameLine();
			ImGui::RadioButton(TRANSLATES("所有兴趣点"), &dian, 1);

			if (ImGui::Button(TRANSLATES("完成第一板"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				if (fangshi[fangshi_current] == "隐匿潜踪")
				{
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_APPROACH"), 1, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_APPROACH"), 1, true);
					if (g_settings.options["dckunnan"].get<bool*>())
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3_LAST_APPROACH"), 3, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3_LAST_APPROACH"), 3, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3_HARD_APPROACH"), 1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3_HARD_APPROACH"), 1, true);
					}
				}
				if (fangshi[fangshi_current] == "兵不厌诈")
				{
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_APPROACH"), 2, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_APPROACH"), 2, true);
					if (g_settings.options["dckunnan"].get<bool*>())
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3_LAST_APPROACH"), 1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3_LAST_APPROACH"), 1, true);

						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3_HARD_APPROACH"), 2, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3_HARD_APPROACH"), 2, true);
					}
				}
				if (fangshi[fangshi_current] == "气势汹汹")
				{
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_APPROACH"), 3, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_APPROACH"), 3, true);
					if (g_settings.options["dckunnan"].get<bool*>())
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3_LAST_APPROACH"), 2, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3_LAST_APPROACH"), 2, true);

						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3_HARD_APPROACH"), 3, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3_HARD_APPROACH"), 3, true);
					}
				}
				if (mubiao[mubiao_current] == "钻石")
				{
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_TARGET"), 3, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_TARGET"), 3, true);
				}
				if (mubiao[mubiao_current] == "艺术品")
				{
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_TARGET"), 2, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_TARGET"), 2, true);
				}
				if (mubiao[mubiao_current] == "黄金")
				{
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_TARGET"), 1, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_TARGET"), 1, true);
				}
				if (mubiao[mubiao_current] == "现金")
				{
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_TARGET"), 0, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_TARGET"), 0, true);
				}
				if (dian == 0)
				{
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_ACCESSPOINTS"), -1, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_ACCESSPOINTS"), -1, true);
				}
				if (dian == 1)
				{
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_POI"), -1, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_POI"), -1, true);
				}
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_BITSET1"), -1, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_BITSET1"), -1, true);
				g_gui.SendNotification("名钻赌场豪劫", "设置第一块板成功！");
			}

			if (ImGui::Button(TRANSLATES("重置第一板"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_BITSET1"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_BITSET1"), 0, true);
				g_gui.SendNotification("名钻赌场豪劫", "已重置第一块板");
			}

			ImGui::EndChild();

			ImGui::BeginChild("###p1_1", ImVec2(260, getBoxHeight(4.f)), true, ImGuiWindowFlags_NoScrollbar);
			DrarTop("分红");
			//ImGui::Text("玩家1分红");
			ImGui::SetNextItemWidth(150);

			static int wanjia1dc = 0;
			if (ImGui::InputInt(TRANSLATES("玩家1分红"), &wanjia1dc))
			{
				*script_global(1966718).at(1497).at(736).at(92).at(1).as<int*>() = wanjia1dc;
			}
			ImGui::PushItemWidth(150);

			//ImGui::Text("玩家2分红");
			ImGui::SetNextItemWidth(150);

			static int wanjia2dc = 0;
			if (ImGui::InputInt(TRANSLATES("玩家2分红"), &wanjia2dc))
			{
				*script_global(1966718).at(1497).at(736).at(92).at(2).as<int*>() = wanjia2dc;
			}
			ImGui::PushItemWidth(150);

			//ImGui::Text("玩家3分红");
			ImGui::SetNextItemWidth(150);

			static int wanjia3dc = 0;
			if (ImGui::InputInt(TRANSLATES("玩家3分红"), &wanjia3dc))
			{
				*script_global(1966718).at(1497).at(736).at(92).at(3).as<int*>() = wanjia3dc;
			}
			ImGui::PushItemWidth(150);

			//ImGui::Text("玩家4分红");
			ImGui::SetNextItemWidth(150);

			static int wanjia4dc = 0;
			if (ImGui::InputInt(TRANSLATES("玩家4分红"), &wanjia4dc))
			{
				*script_global(1966718).at(1497).at(736).at(92).at(4).as<int*>() = wanjia4dc;
			}
			ImGui::PushItemWidth(150);

			ImGui::EndChild();

			ImGui::EndGroup();

			ImGui::SameLine();
			ImGui::BeginGroup();

			ImGui::BeginChild("###p2", ImVec2(260, getBoxHeight(10.0f)), true, ImGuiWindowFlags_NoScrollbar);
			{
				DrarTop("第二块版");
				const char* dengji[] =
				{
					"差劲","良好","优秀"
				};
				ImGui::Text(TRANSLATES("枪手等级"));

				static int qiang_current = 0;
				ImGui::SetNextItemWidth(195);
				ImGui::Combo("###枪手等级", &qiang_current, dengji, IM_ARRAYSIZE(dengji));
				ImGui::PushItemWidth(195);

				ImGui::Text(TRANSLATES("车手等级"));

				static int che_current = 0;
				ImGui::SetNextItemWidth(195);
				ImGui::Combo("###车手等级", &che_current, dengji, IM_ARRAYSIZE(dengji));
				ImGui::PushItemWidth(195);

				ImGui::Text(TRANSLATES("黑客等级"));

				static int heike_current = 0;
				ImGui::SetNextItemWidth(195);
				ImGui::Combo("###黑客等级", &heike_current, dengji, IM_ARRAYSIZE(dengji));
				ImGui::PushItemWidth(195);

				if (ImGui::Button(TRANSLATES("削弱敌人装甲[杜根货物]"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_DISRUPTSHIP"), 3, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_DISRUPTSHIP"), 3, true);
					g_gui.SendNotification("名钻赌场豪劫", "削弱敌人装甲成功！");
				}
				if (ImGui::Button(TRANSLATES("获取二级门禁"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_KEYLEVELS"), 2, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_KEYLEVELS"), 2, true);
					g_gui.SendNotification("名钻赌场豪劫", "获取二级门禁成功！");
				}
				if (ImGui::Button(TRANSLATES("完成第二板"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					if (dengji[qiang_current] == "差劲")
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_CREWWEAP"), 1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_CREWWEAP"), 1, true);
					}
					if (dengji[qiang_current] == "良好")
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_CREWWEAP"), 3, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_CREWWEAP"), 3, true);
					}
					if (dengji[qiang_current] == "优秀")
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_CREWWEAP"), 4, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_CREWWEAP"), 4, true);
					}
					if (dengji[che_current] == "差劲")
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_CREWDRIVER"), 1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_CREWDRIVER"), 1, true);
					}
					if (dengji[che_current] == "良好")
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_CREWDRIVER"), 3, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_CREWDRIVER"), 3, true);
					}
					if (dengji[che_current] == "优秀")
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_CREWDRIVER"), 5, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_CREWDRIVER"), 5, true);
					}
					if (dengji[heike_current] == "差劲")
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_CREWHACKER"), 1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_CREWHACKER"), 1, true);
					}
					if (dengji[heike_current] == "良好")
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_CREWHACKER"), 3, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_CREWHACKER"), 3, true);
					}
					if (dengji[heike_current] == "优秀")
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_CREWHACKER"), 4, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_CREWHACKER"), 4, true);
					}
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_BITSET0"), -1, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_BITSET0"), -1, true);

					g_gui.SendNotification("名钻赌场豪劫", "设置第二块板成功！");
				}

				if (ImGui::Button(TRANSLATES("重置第二板"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_BITSET0"), 0, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_BITSET0"), 0, true);
					g_gui.SendNotification("名钻赌场豪劫", "已重置第二块板");
				}
			}

			ImGui::EndChild();
			ImGui::BeginChild("###p2_1", ImVec2(260, getBoxHeight(3.0f)), true, ImGuiWindowFlags_NoScrollbar);
			DrarTop("实时收入");
			ImGui::Text(TRANSLATES("设置收入")); ImGui::SameLine();
			features::HelpMarker("离开游戏厅，进入名钻之前提交，若进入名钻后未显示，请在名钻内再次提交");
			ImGui::SetNextItemWidth(250);

			static int dcshouru = 4320000;
			ImGui::InputInt("###设置收入", &dcshouru);
			ImGui::PushItemWidth(250);
			if (ImGui::Button(TRANSLATES("提交"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				auto addr = (uintptr_t)g_pointers->m_script_globals - 0x120;
				memory::set_selfvalue(addr, { 0x1180,0x2B2D8 }, dcshouru);
				g_gui.SendNotification("名钻赌场豪劫", "自定义设置收入成功！");
			}

			ImGui::EndChild();
			ImGui::EndGroup();

			ImGui::SameLine();

			ImGui::BeginGroup();
			ImGui::BeginChild("###p3", ImVec2(260, getBoxHeight(4.0f)), true, ImGuiWindowFlags_NoScrollbar);
			DrarTop("其他");
			if (ImGui::Button(TRANSLATES("删除NPC分红"), ImVec2(ImGui::GetContentRegionAvail().x, 30)))
			{
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_CREWWEAP"), 6, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_CREWWEAP"), 6, true);

				STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_CREWDRIVER"), 6, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_CREWDRIVER"), 6, true);

				STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_CREWHACKER"), 6, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_CREWHACKER"), 6, true);
				g_gui.SendNotification("名钻赌场豪劫", "删除NPC分红成功！");
			}
			if (ImGui::Button(TRANSLATES("刷新任务冷却时间"), ImVec2(219, 30)))
			{
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3_COMPLETEDPOSIX"), -1, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3_COMPLETEDPOSIX"), -1, true);
				g_gui.SendNotification("名钻赌场豪劫", "删除NPC分红成功！");
			} ImGui::SameLine();
			features::HelpMarker("离开游戏厅退出CEO/摩托帮后再点击");

			if (ImGui::Button(TRANSLATES("修复侦察照片无法发送"), ImVec2(219, 30)))
			{
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_ACCESSPOINTS"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_ACCESSPOINTS"), 0, true);

				STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H3OPT_POI"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H3OPT_POI"), 0, true);
				g_gui.SendNotification("名钻赌场豪劫", "修复侦察照片无法发送的情况成功！");
			} ImGui::SameLine();
			features::HelpMarker("点击修复之后，在重新开启侦察任务\n此功能也可修复切换出入口卡死游戏的情况");
			ImGui::EndChild();
			ImGui::EndGroup();

			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("佩里克岛"))
		{
			ImGui::BeginGroup();
			/*static int test = 400;
			ImGui::SliderInt("Opacity", &test, 0, 600);*/
			if (ImGui::Button(TRANSLATES("传送到虎鲸面板"), ImVec2(210.f, 30)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					Ped e = PLAYER::PLAYER_PED_ID();
					if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
					{
						e = PED::GET_VEHICLE_PED_IS_USING(e);
					}
					Vector3 Coords;
					Coords.x = 1563.92f; Coords.y = 383.266f; Coords.z = -49.68f;
					features::teleportToCoords(e, Coords);
				}QUEUE_JOB_END_CLAUSE
			}
			ImGui::EndGroup();
			ImGui::Separator();

			ImGui::BeginChild("###p1", ImVec2(260, getBoxHeight(13.f)), true, ImGuiWindowFlags_NoScrollbar);
			{
				DrarTop("前置");

				ImGui::BeginGroup();

				if (ImGui::Button(TRANSLATES("解锁所有点位"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4CNF_BS_GEN"), 131071, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4CNF_BS_ENTR"), 63, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4CNF_APPROACH"), -1, true);

						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4CNF_BS_GEN"), 131071, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4CNF_BS_ENTR"), 63, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4CNF_APPROACH"), -1, true);
						g_gui.SendNotification("佩里克岛", "已解锁所有~b~兴趣点+入侵点+逃离点");
					}QUEUE_JOB_END_CLAUSE
				}
				if (ImGui::Button(TRANSLATES("解锁团队支持"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4CNF_BS_ABIL"), 63, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4CNF_BS_ABIL"), 63, true);

						g_gui.SendNotification("佩里克岛", "已解锁团队支持");
					}QUEUE_JOB_END_CLAUSE
				}

				const char* hdzhuyao[] =
				{
					"西西米托龙舌兰90W","红宝石项链100W","不记名债券110W","粉钻130W","玛德拉索文件110W","猎豹雕像190万"
				};
				ImGui::Text("主要目标");

				static int hdzhuyao_current = 5;
				ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
				ImGui::Combo("###主要目标", &hdzhuyao_current, hdzhuyao, IM_ARRAYSIZE(hdzhuyao));
				ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);

				ImGui::Text(TRANSLATES("次要目标"));
				ImGui::SameLine(); features::HelpMarker("不建议全选！");

				static bool xianjin{};
				ImGui::Checkbox(TRANSLATES("现金"), &xianjin);
				ImGui::SameLine();
				static bool huangjin{};
				ImGui::Checkbox(TRANSLATES("黄金"), &huangjin);
				ImGui::SameLine();
				static bool dama{};
				ImGui::Checkbox(TRANSLATES("大麻"), &dama);
				static bool huazuo{};
				ImGui::Checkbox(TRANSLATES("画作"), &huazuo);
				ImGui::SameLine();
				static bool kekayin{};
				ImGui::Checkbox(TRANSLATES("可卡因"), &kekayin);
				//ImGui::NewLine();
				const char* hdwuqi[] =
				{
					"连发霰弹枪+连发手枪+手雷+砍刀","军用步枪+单发手枪+粘弹+指虎","轻型狙击步枪+连发手枪+燃烧瓶+小刀","MK2冲锋枪+单发手枪+土制炸弹+小刀",
					"MK2突击步枪+单发手枪+土质炸弹+砍刀"
				};
				ImGui::Text(TRANSLATES("选择武器"));

				static int hdwuqi_current = 4;
				ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);

				ImGui::Combo("###选择武器", &hdwuqi_current, hdwuqi, IM_ARRAYSIZE(hdwuqi));
				ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);

				const char* hdkache[] =
				{
					"机场","北船坞","东码头","西码头",
				};
				ImGui::Text(TRANSLATES("选择运货卡车位置"));

				static int hdkache_current = 0;
				ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
				ImGui::Combo("###选择运货卡车位置", &hdkache_current, hdkache, IM_ARRAYSIZE(hdkache));
				ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);

				if (ImGui::Button(TRANSLATES("开启终章"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					/*QUEUE_JOB_BEGIN_CLAUSE()
					{*/

					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4CNF_TARGET"), hdzhuyao_current, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4CNF_TARGET"), hdzhuyao_current, true);
					if (xianjin)
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4LOOT_CASH_I"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4LOOT_CASH_C"), -1, true);

						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4LOOT_CASH_I"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4LOOT_CASH_C"), -1, true);

						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4LOOT_CASH_I_SCOPED"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4LOOT_CASH_C_SCOPED"), -1, true);

						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4LOOT_CASH_I_SCOPED"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4LOOT_CASH_C_SCOPED"), -1, true);

						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4LOOT_CASH_V"), 90000, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4LOOT_CASH_V"), 90000, true);
					}
					if (huangjin)
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4LOOT_GOLD_I"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4LOOT_GOLD_C"), -1, true);

						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4LOOT_GOLD_I_SCOPED"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4LOOT_GOLD_C_SCOPED"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4LOOT_GOLD_V"), 320000, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4LOOT_GOLD_V"), 320000, true);
					}
					if (dama)
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4LOOT_WEED_I"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4LOOT_WEED_C"), -1, true);

						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4LOOT_WEED_I_SCOPED"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4LOOT_WEED_C_SCOPED"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4LOOT_WEED_V"), 145000, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4LOOT_WEED_V"), 145000, true);
					}
					if (kekayin)
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4LOOT_COKE_I"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4LOOT_COKE_C"), -1, true);

						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4LOOT_COKE_I_SCOPED"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4LOOT_COKE_C_SCOPED"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4LOOT_COKE_V"), 220000, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4LOOT_COKE_V"), 220000, true);
					}
					if (huazuo)
					{
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4LOOT_PAINT"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4LOOT_PAINT_SCOPED"), -1, true);

						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4LOOT_PAINT"), -1, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4LOOT_PAINT_SCOPED"), -1, true);

						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4LOOT_PAINT_V"), 180000, true);
						STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4LOOT_PAINT_V"), 180000, true);
					}
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4CNF_WEAPONS"), hdwuqi_current + 1, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4CNF_WEAPONS"), hdwuqi_current + 1, true);

					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4CNF_TROJAN"), hdkache_current + 1, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4CNF_TROJAN"), hdkache_current + 1, true);

					//终章
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4_PROGRESS"), 131055, true);

					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4_MISSIONS"), 65535, true);

					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4CNF_WEP_DISRP"), 3, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4CNF_ARM_DISRP"), 3, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4CNF_HEL_DISRP"), 3, true);

					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4CNF_GRAPPEL"), -1, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4CNF_UNIFORM"), -1, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4CNF_BOLTCUT"), -1, true);

					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4_PLAYTHROUGH_STATUS"), 10, true);

					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4_PROGRESS"), 131055, true);

					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4_MISSIONS"), 65535, true);

					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4CNF_WEP_DISRP"), 3, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4CNF_ARM_DISRP"), 3, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4CNF_HEL_DISRP"), 3, true);

					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4CNF_GRAPPEL"), -1, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4CNF_UNIFORM"), -1, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4CNF_BOLTCUT"), -1, true);

					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4_PLAYTHROUGH_STATUS"), 10, true);

					g_gui.SendNotification("佩里克岛", "已开启终章，请重新进入虎鲸");
					/*}QUEUE_JOB_END_CLAUSE*/
				}
				if (ImGui::Button(TRANSLATES("重置面板"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4_MISSIONS"), 0, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4_PROGRESS"), 0, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4_PLAYTHROUGH_STATUS"), 0, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4_H4CNF_APPROACH"), 0, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4CNF_BS_ENTR"), 0, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP1_H4CNF_BS_GEN"), 0, true);

					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4_MISSIONS"), 0, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4_PROGRESS"), 0, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4_PLAYTHROUGH_STATUS"), 0, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4_H4CNF_APPROACH"), 0, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4CNF_BS_ENTR"), 0, true);
					STATS::STAT_SET_INT(MISC::GET_HASH_KEY((char*)"MP0_H4CNF_BS_GEN"), 0, true);
					g_gui.SendNotification("佩里克岛", "已重置，请重新进入虎鲸");
				}

				ImGui::EndGroup();
			}
			ImGui::EndChild();

			ImGui::SameLine();

			ImGui::BeginChild("###p2", ImVec2(260, getBoxHeight(13.f)), true, ImGuiWindowFlags_NoScrollbar);
			{
				DrarTop("调值");

				ImGui::BeginGroup();
				ImGui::Text(TRANSLATES("玩家1分红"));
				ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);

				static int wanjia1hd = 0;
				if (ImGui::InputInt("##hd玩家1分红", &wanjia1hd))
				{
					*script_global(1973496).at(823).at(56).at(1).as<int*>() = wanjia1hd;
				}
				ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);

				ImGui::Text(TRANSLATES("玩家2分红"));
				ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);

				static int wanjia2dh = 0;
				if (ImGui::InputInt("##hd玩家2分红", &wanjia2dh))
				{
					*script_global(1973496).at(823).at(56).at(2).as<int*>() = wanjia2dh;
				}
				ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);

				ImGui::Text(TRANSLATES("玩家3分红"));
				ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);

				static int wanjia3dh = 0;
				if (ImGui::InputInt("##hd玩家3分红", &wanjia3dh))
				{
					*script_global(1973496).at(823).at(56).at(3).as<int*>() = wanjia3dh;
				}
				ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);

				ImGui::Text(TRANSLATES("玩家4分红"));
				ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);

				static int wanjia4dh = 0;
				if (ImGui::InputInt("##hd玩家4分红", &wanjia4dh))
				{
					*script_global(1973496).at(823).at(56).at(4).as<int*>() = wanjia4dh;
				}
				ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);

				//ImGui::NewLine();

				ImGui::Text(TRANSLATES("背包容量")); ImGui::SameLine(); features::HelpMarker("建议1800-7200之间");
				ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);

				static int hdbeibao = 1800;
				if (ImGui::InputInt("##hd背包容量", &hdbeibao))
				{
					*script_global(262145).at(29379).as<int*>() = hdbeibao;
				}
				ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);

				//ImGui::NewLine();

				ImGui::Text(TRANSLATES("设置收入"));
				static int hdshouru = 0;
				ImGui::InputInt("###hd设置收入", &hdshouru);
				ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);
				if (ImGui::Button(TRANSLATES("提交"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					auto addr = (uintptr_t)g_pointers->m_script_globals - 0x120;
					memory::set_selfvalue(addr, { 0x1180,0x50858 }, hdshouru);
					g_gui.SendNotification("佩里克岛", "自定义设置收入成功！");
				}

				ImGui::EndGroup();
			}
			ImGui::EndChild();

			ImGui::SameLine();

			ImGui::SameLine();

			ImGui::BeginChild("###p3", ImVec2(260, getBoxHeight(5.f)), true, ImGuiWindowFlags_NoScrollbar);
			{
				ImGui::BeginGroup();
				DrarTop("其他");
				if (ImGui::Button(TRANSLATES("杀死队友"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						features::explodeNearbyPeds();
					}QUEUE_JOB_END_CLAUSE
				}
				if (ImGui::Button(TRANSLATES("传送到入口：大门"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						features::teleportToObjective();
					}QUEUE_JOB_END_CLAUSE
				}
				if (ImGui::Button(TRANSLATES("传送到主要目标"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						Vector3 Coords;                 Coords.x = 5006.744f; Coords.y = -5756.1079f; Coords.z = 15.48f;
						Entity e = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
						if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
						{
							e = PED::GET_VEHICLE_PED_IS_USING(e);
						}
						features::teleportToCoords(e, Coords);
					}QUEUE_JOB_END_CLAUSE
				}
				if (ImGui::Button(TRANSLATES("传送到大门出口"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						Vector3 Coords;                  Coords.x = 4991.881f; Coords.y = -5718.831f; Coords.z = 19.8802f;
						Entity e = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
						if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
						{
							e = PED::GET_VEHICLE_PED_IS_USING(e);
						}
						features::teleportToCoords(e, Coords);
					}QUEUE_JOB_END_CLAUSE
				}
				if (ImGui::Button(TRANSLATES("传送到海里[逃离佩里科岛]"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						Vector3 Coords;                   Coords.x = 4430.3916f; Coords.y = -6138.72f; Coords.z = -0.307f;
						Entity e = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
						if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
						{
							e = PED::GET_VEHICLE_PED_IS_USING(e);
						}
						features::teleportToCoords(e, Coords);
					}QUEUE_JOB_END_CLAUSE
				}
				ImGui::EndGroup();
			}
			ImGui::EndChild();

			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}

	void gui::onlineTab()
	{
		ImGui::BeginGroup();
		ImGui::BeginChild("###p1", ImVec2(260, getBoxHeight(9.f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("CEO技能");
			if (ImGui::Checkbox(TRANSLATES("关闭雷达"), g_settings.options["renjianzhengfa"].get<bool*>()))
			{
				*script_global(2689156).at(PLAYER::GET_PLAYER_INDEX(), 453).at(209).as<int*>() = 0;
			}
			if (ImGui::Checkbox(TRANSLATES("显示其他玩家"), g_settings.options["xianshiwanjia"].get<bool*>()))
			{
				*script_global(2689156).at(PLAYER::GET_PLAYER_INDEX(), 449).at(212).as<int*>() = 0;
			}
			if (ImGui::Button(TRANSLATES("呼叫空袭"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					g_gui.SendNotification("CEO技能", "请将信号弹扔到目标区域~");
					*script_global(2810287).at(4455).as<int*>() = 1;
				}QUEUE_JOB_END_CLAUSE
			}
			if (ImGui::Button(TRANSLATES("呼叫直升机支援"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					g_gui.SendNotification("CEO技能", "直升机支援马上就来，请稍后~");
					*script_global(2810287).at(4454).as<int*>() = 1;
				}QUEUE_JOB_END_CLAUSE
			}
			if (ImGui::Button(TRANSLATES("请求重型防弹装甲"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					g_gui.SendNotification("CEO技能", "重型防弹装甲马上就来，请稍后~");
					*script_global(2810287).at(884).as<int*>() = 1;
				}QUEUE_JOB_END_CLAUSE
			}
			if (ImGui::Button(TRANSLATES("请求牛鲨睾酮"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					g_gui.SendNotification("CEO技能", "牛鲨睾酮马上就来，请稍后~");
					*script_global(2810287).at(882).as<int*>() = 1;
				}QUEUE_JOB_END_CLAUSE
			}
			if (ImGui::Button(TRANSLATES("请求弹药"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					g_gui.SendNotification("CEO技能", "弹药马上就来，请稍后~");
					*script_global(2810287).at(874).as<int*>() = 1;
				}QUEUE_JOB_END_CLAUSE
			}
			if (ImGui::Button(TRANSLATES("请求船只"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					g_gui.SendNotification("CEO技能", "船只马上就来，请稍后~");
					*script_global(2810287).at(875).as<int*>() = 1;
				}QUEUE_JOB_END_CLAUSE
			}
			if (ImGui::Button(TRANSLATES("请求直升机"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					g_gui.SendNotification("CEO技能", "直升机马上就来，请稍后~");
					*script_global(2810287).at(876).as<int*>() = 1;
				}QUEUE_JOB_END_CLAUSE
			}
		}
		ImGui::EndChild();
		ImGui::BeginChild("###p1_2", ImVec2(260, getBoxHeight(3.f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("赌场转盘");
			if (ImGui::Button(TRANSLATES("先点我进行初始化"), ImVec2(222, 0)))
			{
				features::turntableInit();
			}
			ImGui::SameLine();
			features::HelpMarker("1:进入名钻赌场\n2:手动转一次转盘抽奖\n3:等待手动抽奖结束后，点击初始化\n4:在离开名钻之前，可获取任意奖品");
			const char* prize[] =
			{
				"展台载具",
				"筹码10000","筹码15000","筹码20000","筹码25000",
				"现金20000","现金30000","现金40000",
				"经验2500","经验5000","经验7500","经验10000","经验15000",
				"服装1","服装2","服装3","服装4",
				"折扣奖励","神秘奖励"
			};
			static int prize_current = 0;
			ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
			ImGui::Combo("###转盘奖品", &prize_current, prize, IM_ARRAYSIZE(prize));
			ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);
			char Str[512];
			sprintf(Str, "获取奖品:%s", prize[prize_current]);
			if (ImGui::Button(Str, ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				int i = 0;
				if (prize_current == 0)
				{
					i = 18;
				}
				if (prize_current == 1)
				{
					i = 3;
				}
				if (prize_current == 2)
				{
					i = 7;
				}
				if (prize_current == 3)
				{
					i = 10;
				}
				if (prize_current == 4)
				{
					i = 15;
				}
				if (prize_current == 5)
				{
					i = 2;
				}
				if (prize_current == 6)
				{
					i = 6;
				}
				if (prize_current == 7)
				{
					i = 14;
				}
				if (prize_current == 8)
				{
					i = 1;
				}
				if (prize_current == 9)
				{
					i = 5;
				}
				if (prize_current == 10)
				{
					i = 9;
				}
				if (prize_current == 11)
				{
					i = 13;
				}
				if (prize_current == 12)
				{
					i = 17;
				}
				if (prize_current == 13)
				{
					i = 0;
				}
				if (prize_current == 14)
				{
					i = 8;
				}
				if (prize_current == 15)
				{
					i = 12;
				}
				if (prize_current == 16)
				{
					i = 16;
				}
				if (prize_current == 17)
				{
					i = 4;
				}
				if (prize_current == 18)
				{
					i = 11;
				}
				features::getTurntable(i);
			}
		}
		ImGui::EndChild();
		ImGui::EndGroup();
		ImGui::SameLine();

		ImGui::BeginGroup();
		ImGui::BeginChild("###p2_1", ImVec2(260, getBoxHeight(9.f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("虚假信息");
			static char name[20];

			strcpy_s(name, sizeof(name), g_settings.spoofing.username.c_str());
			ImGui::Text(TRANSLATES("虚假昵称:"));
			ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
			ImGui::InputText("##昵称输入", name, sizeof(name));
			//ImGui::InputTextWithHint("##name_", "输入昵称", StringToChar(g_settings.spoofing.username), 32);
			ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);
			ImGui::Checkbox(TRANSLATES("开启虚假昵称"), &g_settings.spoofing.spoof_username);
			if (name != g_settings.spoofing.username)
				g_settings.spoofing.username = std::string(name);

			ImGui::Text(TRANSLATES("虚假IP地址:"));
			ImGui::DragInt4("##IP地址输入", g_settings.spoofing.ip_address, 0, 255);
			ImGui::Checkbox(TRANSLATES("开启虚假IP"), &g_settings.spoofing.spoof_ip);

			ImGui::Text(TRANSLATES("虚假RID:"));
			ImGui::InputScalar("##虚假RID输入", ImGuiDataType_U64, &g_settings.spoofing.rockstar_id);
			ImGui::Checkbox(TRANSLATES("开启虚假RID"), &g_settings.spoofing.spoof_rockstar_id);
		}
		ImGui::EndChild();

		ImGui::BeginChild("###p2_2", ImVec2(260, getBoxHeight(1.f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("全局崩溃");

			if (ImGui::Button(TRANSLATES("切换模型全局崩溃"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::playerModelCrashAll();
				}QUEUE_JOB_END_CLAUSE
			}
		}
		ImGui::EndChild();

		ImGui::EndGroup();
		ImGui::SameLine();

		ImGui::BeginGroup();
		ImGui::BeginChild("###p3_1", ImVec2(260, getBoxHeight(2.f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("战局追踪");
			//ImGui::Text("RID:"); ImGui::SameLine();
			ImGui::InputInt(TRANSLATES("目标RID"), &features::bMiscRockstarID);
			if (ImGui::Button(TRANSLATES("加入目标RID战局"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				if (features::bMiscRockstarID > 0)
				{
					g_fiber_pool->queue_job([]
						{
							if (g_pointers->m_menu_ptr)
							{
								do
								{
									HUD::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
									script::get_current()->yield(1s);

									if (*g_pointers->m_menu_ptr)
									{
										int hash = -632792895;
										int64_t ptr = *g_pointers->m_menu_ptr;
										g_pointers->m_rid_joiner(&ptr, &hash);
									}
								} while (!*g_pointers->m_menu_ptr);
							}
						});
				}
			}
		}
		ImGui::EndChild();
		ImGui::BeginChild("###p3_2", ImVec2(260, getBoxHeight(1.f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("战局管理");
			ImGui::Checkbox(TRANSLATES("此战局禁止RID加入"), g_settings.options["BlockSCIDJoins"].get<bool*>());
		}
		ImGui::EndChild();

		ImGui::BeginChild("###p3_3", ImVec2(260, getBoxHeight(5.f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("绘制");

			ImGui::BeginGroup();
			ImGui::Checkbox(TRANSLATES("2D方框"), g_settings.options["2dbox"].get<bool*>());
			ImGui::Checkbox(TRANSLATES("骨骼"), g_settings.options["Skeleton"].get<bool*>());
			ImGui::Checkbox(TRANSLATES("名字"), g_settings.options["nameesp"].get<bool*>());
			ImGui::Checkbox(TRANSLATES("准星"), g_settings.options["crosshair"].get<bool*>());
			ImGui::EndGroup();
			ImGui::SameLine();
			ImGui::BeginGroup();
			ImGui::Checkbox(TRANSLATES("3D方框"), g_settings.options["3dbox"].get<bool*>());
			ImGui::Checkbox(TRANSLATES("血条"), g_settings.options["Health bar"].get<bool*>());
			ImGui::Checkbox(TRANSLATES("线条"), g_settings.options["Tracers"].get<bool*>());
			ImGui::Checkbox(TRANSLATES("FPS"), g_settings.options["esp_fps"].get<bool*>());

			ImGui::EndGroup();

			static float esp[4] = { 0.07f, 0.07f, 0.09f, 1.00f };
			if (ImGui::ColorEdit4(TRANSLATES("ESP颜色"), esp))
			{
				espColor = ImVec4(esp[0], esp[1], esp[2], esp[3]);
			}
		}
		ImGui::EndChild();

		ImGui::EndGroup();
	}

	void gui::teleportTab()
	{
		ImGui::BeginGroup();
		ImGui::BeginChild("###p1", ImVec2(260, getBoxHeight(4.f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("基础");

			ImGui::Checkbox(TRANSLATES("自动传送到导航点"), g_settings.options["autotp"].get<bool*>());

			if (ImGui::Button(TRANSLATES("传送到导航点"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::tpToWaypoint();
				}QUEUE_JOB_END_CLAUSE
			}
			if (ImGui::Button(TRANSLATES("传送到任务点"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::teleportToObjective();
				}QUEUE_JOB_END_CLAUSE
			}
			if (ImGui::Button(TRANSLATES("传送个人载具"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				Vector3 CoordBlip = HUD::GET_BLIP_INFO_ID_COORD(HUD::GET_FIRST_BLIP_INFO_ID(225));
				int VehicleHandle = VEHICLE::GET_CLOSEST_VEHICLE(CoordBlip.x, CoordBlip.y, CoordBlip.z, 1, 0, 71);
				if (VehicleHandle == 0) {
					Vector3 coordveh = HUD::GET_BLIP_INFO_ID_COORD(HUD::GET_FIRST_BLIP_INFO_ID(226));
					int VehicleHandleMoto = VEHICLE::GET_CLOSEST_VEHICLE(coordveh.x, coordveh.y, coordveh.z, 1, 0, 71);
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
		}
		ImGui::EndChild();

		ImGui::BeginChild("###p2", ImVec2(260, getBoxHeight(4.f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("自定义");

			ImGui::InputFloat(TRANSLATES("X坐标: "), &g_settings.custom_x, 1, 100, "%.3f", ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_CharsDecimal);
			ImGui::InputFloat(TRANSLATES("Y坐标: "), &g_settings.custom_y, 1, 100, "%.3f", ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_CharsDecimal);
			ImGui::InputFloat(TRANSLATES("Z坐标: "), &g_settings.custom_z, 1, 100, "%.3f", ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_CharsDecimal);
			if (ImGui::Button(TRANSLATES("传送"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				g_fiber_pool->queue_job([]
					{
						Entity ent = PLAYER::PLAYER_PED_ID();
						if (PED::IS_PED_IN_ANY_VEHICLE(ent, FALSE))
							ent = PED::GET_VEHICLE_PED_IS_IN(ent, FALSE);

						features::teleportToCoords(ent, { g_settings.custom_x, g_settings.custom_y, g_settings.custom_z });
					});
			}
		}
		ImGui::EndChild();

		ImGui::BeginChild("###p3", ImVec2(260, 0), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("本地位置");
			static char coordsname[20];

			ImGui::InputText(TRANSLATES("坐标重命名"), coordsname, sizeof(coordsname));
			if (ImGui::Button(TRANSLATES("保存当前位置"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				g_fiber_pool->queue_job([]
					{
						std::ofstream write;
						write.open(std::string(MENU_PATH) + "\\TXT\\coord.txt", std::ios::app);
						write << coordsname << std::endl;
						write.close();
						Vector3 p = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
						//WAIT(100);
						script::get_current()->yield(100ms);
						INI::WriteVector3(std::string(MENU_PATH) + "\\TXT\\coords.ini", p, coordsname);
						g_gui.SendNotification("本地位置", "成功将此位置保存到本地！");
					});
			}
			ImGui::BeginChild("###p6", ImVec2(260, 0), true, ImGuiWindowFlags_NoScrollbar);
			{
				std::ifstream in(std::string(MENU_PATH) + "\\TXT\\coord.txt");
				char str[1024] = { 0 };

				while (in.getline(str, sizeof(str), '\n'))
				{
					if (ImGui::Selectable(str))
					{
						g_fiber_pool->queue_job([str]
							{
								Vector3 coord = INI::GetVector3(std::string(MENU_PATH) + "\\TXT\\coords.ini", str);
								g_settings.custom_x = coord.x;
								g_settings.custom_y = coord.y;
								g_settings.custom_z = coord.z;
								//g_settings.currentinicoord = str;
							});
					}
				}
				in.close();
			}
			ImGui::EndChild();
		}
		ImGui::EndChild();

		ImGui::EndGroup();
		ImGui::SameLine();

		ImGui::BeginGroup();
		ImGui::BeginChild("###p4", ImVec2(260, getBoxHeight(9.f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("加载IPL");
			if (ImGui::Button(TRANSLATES("北杨克顿"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
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
				PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 3595.39673f, -4893.727f, 115.838394f);
			}
			if (ImGui::Button(TRANSLATES("佩里克岛"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				g_fiber_pool->queue_job([]
					{
						STREAMING::REQUEST_IPL("h4_islandx_terrain_01_lod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_01_slod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_02");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_02_lod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_02_slod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_03");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_03_lod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_04");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_04_lod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_04_slod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_05");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_05_lod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_05_slod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_06");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_01_grass_0");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_01_grass_1");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_02_grass_0");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_02_grass_1");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_02_grass_2");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_02_grass_3");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_04_grass_0");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_04_grass_1");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_05_grass_0");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_06_grass_0");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_06_lod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_06_slod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_a");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_a_lod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_b");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_b_lod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_c");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_c_lod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_d");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_d_lod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_d_slod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_e");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_e_lod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_e_slod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_f");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_f_lod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_f_slod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_06_a");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_06_a_lod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_06_a_slod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_06_b");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_06_b_lod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_06_b_slod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_06_c");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_06_c_lod");
						STREAMING::REQUEST_IPL("h4_islandx_terrain_props_06_c_slod");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_01");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_01_long_0");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_02");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_03");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_04");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_05");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_06");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_06_strm_0");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_lod");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_00");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_01");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_02");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_03");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_04");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_05");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_06");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_07");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_08");
						STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_09");
						STREAMING::REQUEST_IPL("h4_boatblockers");
						STREAMING::REQUEST_IPL("h4_islandx");
						STREAMING::REQUEST_IPL("h4_islandx_disc_strandedshark");
						STREAMING::REQUEST_IPL("h4_islandx_disc_strandedshark_lod");
						STREAMING::REQUEST_IPL("h4_islandx_disc_strandedwhale");
						STREAMING::REQUEST_IPL("h4_islandx_disc_strandedwhale_lod");
						STREAMING::REQUEST_IPL("h4_islandx_props");
						STREAMING::REQUEST_IPL("h4_islandx_props_lod");
						STREAMING::REQUEST_IPL("h4_islandx_sea_mines");
						STREAMING::REQUEST_IPL("h4_mph4_island");
						STREAMING::REQUEST_IPL("h4_mph4_island_long_0");
						STREAMING::REQUEST_IPL("h4_mph4_island_strm_0");
						STREAMING::REQUEST_IPL("h4_aa_guns");
						STREAMING::REQUEST_IPL("h4_aa_guns_lod");
						STREAMING::REQUEST_IPL("h4_beach");
						STREAMING::REQUEST_IPL("h4_beach_bar_props");
						STREAMING::REQUEST_IPL("h4_beach_lod");
						STREAMING::REQUEST_IPL("h4_beach_party");
						STREAMING::REQUEST_IPL("h4_beach_party_lod");
						STREAMING::REQUEST_IPL("h4_beach_props");
						STREAMING::REQUEST_IPL("h4_beach_props_lod");
						STREAMING::REQUEST_IPL("h4_beach_props_party");
						STREAMING::REQUEST_IPL("h4_beach_props_slod");
						STREAMING::REQUEST_IPL("h4_beach_slod");
						STREAMING::REQUEST_IPL("h4_islandairstrip");
						STREAMING::REQUEST_IPL("h4_islandairstrip_doorsclosed");
						STREAMING::REQUEST_IPL("h4_islandairstrip_doorsclosed_lod");
						STREAMING::REQUEST_IPL("h4_islandairstrip_doorsopen");
						STREAMING::REQUEST_IPL("h4_islandairstrip_doorsopen_lod");
						STREAMING::REQUEST_IPL("h4_islandairstrip_hangar_props");
						STREAMING::REQUEST_IPL("h4_islandairstrip_hangar_props_lod");
						STREAMING::REQUEST_IPL("h4_islandairstrip_hangar_props_slod");
						STREAMING::REQUEST_IPL("h4_islandairstrip_lod");
						STREAMING::REQUEST_IPL("h4_islandairstrip_props");
						STREAMING::REQUEST_IPL("h4_islandairstrip_propsb");
						STREAMING::REQUEST_IPL("h4_islandairstrip_propsb_lod");
						STREAMING::REQUEST_IPL("h4_islandairstrip_propsb_slod");
						STREAMING::REQUEST_IPL("h4_islandairstrip_props_lod");
						STREAMING::REQUEST_IPL("h4_islandairstrip_props_slod");
						STREAMING::REQUEST_IPL("h4_islandairstrip_slod");
						STREAMING::REQUEST_IPL("h4_islandxcanal_props");
						STREAMING::REQUEST_IPL("h4_islandxcanal_props_lod");
						STREAMING::REQUEST_IPL("h4_islandxcanal_props_slod");
						STREAMING::REQUEST_IPL("h4_islandxdock");
						STREAMING::REQUEST_IPL("h4_islandxdock_lod");
						STREAMING::REQUEST_IPL("h4_islandxdock_props");
						STREAMING::REQUEST_IPL("h4_islandxdock_props_2");
						STREAMING::REQUEST_IPL("h4_islandxdock_props_2_lod");
						STREAMING::REQUEST_IPL("h4_islandxdock_props_2_slod");
						STREAMING::REQUEST_IPL("h4_islandxdock_props_lod");
						STREAMING::REQUEST_IPL("h4_islandxdock_props_slod");
						STREAMING::REQUEST_IPL("h4_islandxdock_slod");
						STREAMING::REQUEST_IPL("h4_islandxdock_water_hatch");
						STREAMING::REQUEST_IPL("h4_islandxtower");
						STREAMING::REQUEST_IPL("h4_islandxtower_lod");
						STREAMING::REQUEST_IPL("h4_islandxtower_slod");
						STREAMING::REQUEST_IPL("h4_islandxtower_veg");
						STREAMING::REQUEST_IPL("h4_islandxtower_veg_lod");
						STREAMING::REQUEST_IPL("h4_islandxtower_veg_slod");
						STREAMING::REQUEST_IPL("h4_islandx_barrack_hatch");
						STREAMING::REQUEST_IPL("h4_islandx_barrack_props");
						STREAMING::REQUEST_IPL("h4_islandx_barrack_props_lod");
						STREAMING::REQUEST_IPL("h4_islandx_barrack_props_slod");
						STREAMING::REQUEST_IPL("h4_islandx_checkpoint");
						STREAMING::REQUEST_IPL("h4_islandx_checkpoint_lod");
						STREAMING::REQUEST_IPL("h4_islandx_checkpoint_props");
						STREAMING::REQUEST_IPL("h4_islandx_checkpoint_props_lod");
						STREAMING::REQUEST_IPL("h4_islandx_checkpoint_props_slod");
						STREAMING::REQUEST_IPL("h4_islandx_maindock");
						STREAMING::REQUEST_IPL("h4_islandx_maindock_lod");
						STREAMING::REQUEST_IPL("h4_islandx_maindock_props");
						STREAMING::REQUEST_IPL("h4_islandx_maindock_props_2");
						STREAMING::REQUEST_IPL("h4_islandx_maindock_props_2_lod");
						STREAMING::REQUEST_IPL("h4_islandx_maindock_props_2_slod");
						STREAMING::REQUEST_IPL("h4_islandx_maindock_props_lod");
						STREAMING::REQUEST_IPL("h4_islandx_maindock_props_slod");
						STREAMING::REQUEST_IPL("h4_islandx_maindock_slod");
						STREAMING::REQUEST_IPL("h4_islandx_mansion");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_b");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_b_lod");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_b_side_fence");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_b_slod");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_entrance_fence");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_guardfence");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_lights");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_lockup_01");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_lockup_01_lod");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_lockup_02");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_lockup_02_lod");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_lockup_03");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_lockup_03_lod");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_lod");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_office");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_office_lod");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_props");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_props_lod");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_props_slod");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_slod");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_vault");
						STREAMING::REQUEST_IPL("h4_islandx_mansion_vault_lod");
						STREAMING::REQUEST_IPL("h4_island_padlock_props");
						STREAMING::REQUEST_IPL("h4_mansion_gate_broken");
						STREAMING::REQUEST_IPL("h4_mansion_gate_closed");
						STREAMING::REQUEST_IPL("h4_mansion_remains_cage");
						STREAMING::REQUEST_IPL("h4_mph4_airstrip");
						STREAMING::REQUEST_IPL("h4_mph4_airstrip_interior_0_airstrip_hanger");
						STREAMING::REQUEST_IPL("h4_mph4_beach");
						STREAMING::REQUEST_IPL("h4_mph4_dock");
						STREAMING::REQUEST_IPL("h4_mph4_island_lod");
						STREAMING::REQUEST_IPL("h4_mph4_island_ne_placement");
						STREAMING::REQUEST_IPL("h4_mph4_island_nw_placement");
						STREAMING::REQUEST_IPL("h4_mph4_island_se_placement");
						STREAMING::REQUEST_IPL("h4_mph4_island_sw_placement");
						STREAMING::REQUEST_IPL("h4_mph4_mansion");
						STREAMING::REQUEST_IPL("h4_mph4_mansion_b");
						STREAMING::REQUEST_IPL("h4_mph4_mansion_b_strm_0");
						STREAMING::REQUEST_IPL("h4_mph4_mansion_strm_0");
						STREAMING::REQUEST_IPL("h4_mph4_wtowers");
						STREAMING::REQUEST_IPL("h4_ne_ipl_00");
						STREAMING::REQUEST_IPL("h4_ne_ipl_00_lod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_00_slod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_01");
						STREAMING::REQUEST_IPL("h4_ne_ipl_01_lod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_01_slod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_02");
						STREAMING::REQUEST_IPL("h4_ne_ipl_02_lod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_02_slod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_03");
						STREAMING::REQUEST_IPL("h4_ne_ipl_03_lod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_03_slod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_04");
						STREAMING::REQUEST_IPL("h4_ne_ipl_04_lod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_04_slod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_05");
						STREAMING::REQUEST_IPL("h4_ne_ipl_05_lod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_05_slod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_06");
						STREAMING::REQUEST_IPL("h4_ne_ipl_06_lod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_06_slod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_07");
						STREAMING::REQUEST_IPL("h4_ne_ipl_07_lod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_07_slod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_08");
						STREAMING::REQUEST_IPL("h4_ne_ipl_08_lod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_08_slod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_09");
						STREAMING::REQUEST_IPL("h4_ne_ipl_09_lod");
						STREAMING::REQUEST_IPL("h4_ne_ipl_09_slod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_00");
						STREAMING::REQUEST_IPL("h4_nw_ipl_00_lod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_00_slod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_01");
						STREAMING::REQUEST_IPL("h4_nw_ipl_01_lod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_01_slod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_02");
						STREAMING::REQUEST_IPL("h4_nw_ipl_02_lod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_02_slod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_03");
						STREAMING::REQUEST_IPL("h4_nw_ipl_03_lod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_03_slod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_04");
						STREAMING::REQUEST_IPL("h4_nw_ipl_04_lod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_04_slod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_05");
						STREAMING::REQUEST_IPL("h4_nw_ipl_05_lod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_05_slod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_06");
						STREAMING::REQUEST_IPL("h4_nw_ipl_06_lod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_06_slod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_07");
						STREAMING::REQUEST_IPL("h4_nw_ipl_07_lod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_07_slod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_08");
						STREAMING::REQUEST_IPL("h4_nw_ipl_08_lod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_08_slod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_09");
						STREAMING::REQUEST_IPL("h4_nw_ipl_09_lod");
						STREAMING::REQUEST_IPL("h4_nw_ipl_09_slod");
						STREAMING::REQUEST_IPL("h4_se_ipl_00");
						STREAMING::REQUEST_IPL("h4_se_ipl_00_lod");
						STREAMING::REQUEST_IPL("h4_se_ipl_00_slod");
						STREAMING::REQUEST_IPL("h4_se_ipl_01");
						STREAMING::REQUEST_IPL("h4_se_ipl_01_lod");
						STREAMING::REQUEST_IPL("h4_se_ipl_01_slod");
						STREAMING::REQUEST_IPL("h4_se_ipl_02");
						STREAMING::REQUEST_IPL("h4_se_ipl_02_lod");
						STREAMING::REQUEST_IPL("h4_se_ipl_02_slod");
						STREAMING::REQUEST_IPL("h4_se_ipl_03");
						STREAMING::REQUEST_IPL("h4_se_ipl_03_lod");
						STREAMING::REQUEST_IPL("h4_se_ipl_03_slod");
						STREAMING::REQUEST_IPL("h4_se_ipl_04");
						STREAMING::REQUEST_IPL("h4_se_ipl_04_lod");
						STREAMING::REQUEST_IPL("h4_se_ipl_04_slod");
						STREAMING::REQUEST_IPL("h4_se_ipl_05");
						STREAMING::REQUEST_IPL("h4_se_ipl_05_lod");
						STREAMING::REQUEST_IPL("h4_se_ipl_05_slod");
						STREAMING::REQUEST_IPL("h4_se_ipl_06");
						STREAMING::REQUEST_IPL("h4_se_ipl_06_lod");
						STREAMING::REQUEST_IPL("h4_se_ipl_06_slod");
						STREAMING::REQUEST_IPL("h4_se_ipl_07");
						STREAMING::REQUEST_IPL("h4_se_ipl_07_lod");
						STREAMING::REQUEST_IPL("h4_se_ipl_07_slod");
						STREAMING::REQUEST_IPL("h4_se_ipl_08");
						STREAMING::REQUEST_IPL("h4_se_ipl_08_lod");
						STREAMING::REQUEST_IPL("h4_se_ipl_08_slod");
						STREAMING::REQUEST_IPL("h4_se_ipl_09");
						STREAMING::REQUEST_IPL("h4_se_ipl_09_lod");
						STREAMING::REQUEST_IPL("h4_se_ipl_09_slod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_00");
						STREAMING::REQUEST_IPL("h4_sw_ipl_00_lod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_00_slod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_01");
						STREAMING::REQUEST_IPL("h4_sw_ipl_01_lod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_01_slod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_02");
						STREAMING::REQUEST_IPL("h4_sw_ipl_02_lod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_02_slod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_03");
						STREAMING::REQUEST_IPL("h4_sw_ipl_03_lod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_03_slod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_04");
						STREAMING::REQUEST_IPL("h4_sw_ipl_04_lod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_04_slod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_05");
						STREAMING::REQUEST_IPL("h4_sw_ipl_05_lod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_05_slod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_06");
						STREAMING::REQUEST_IPL("h4_sw_ipl_06_lod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_06_slod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_07");
						STREAMING::REQUEST_IPL("h4_sw_ipl_07_lod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_07_slod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_08");
						STREAMING::REQUEST_IPL("h4_sw_ipl_08_lod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_08_slod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_09");
						STREAMING::REQUEST_IPL("h4_sw_ipl_09_lod");
						STREAMING::REQUEST_IPL("h4_sw_ipl_09_slod");
						STREAMING::REQUEST_IPL("h4_underwater_gate_closed");
						STREAMING::REQUEST_IPL("h4_islandx_placement_01");
						STREAMING::REQUEST_IPL("h4_islandx_placement_02");
						STREAMING::REQUEST_IPL("h4_islandx_placement_03");
						STREAMING::REQUEST_IPL("h4_islandx_placement_04");
						STREAMING::REQUEST_IPL("h4_islandx_placement_05");
						STREAMING::REQUEST_IPL("h4_islandx_placement_06");
						STREAMING::REQUEST_IPL("h4_islandx_placement_07");
						STREAMING::REQUEST_IPL("h4_islandx_placement_08");
						STREAMING::REQUEST_IPL("h4_islandx_placement_09");
						STREAMING::REQUEST_IPL("h4_islandx_placement_10");
						STREAMING::REQUEST_IPL("h4_mph4_island_placement");
						Vector3 Coords;
						Coords.x = 4892.064f; Coords.y = -4923.567; Coords.z = 3.500f;
						features::tpToVector3(Coords);
					});
			}
			if (ImGui::Button(TRANSLATES("豪华游轮"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				STREAMING::REQUEST_IPL("smboat");
				Vector3 Coords;
				Coords.x = -2045.8f; Coords.y = -1031.2f; Coords.z = 11.9f;
				PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), Coords.x, Coords.y, Coords.z);
			}
			if (ImGui::Button(TRANSLATES("入侵者办公室"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				STREAMING::REQUEST_IPL("facelobby");
				STREAMING::REQUEST_IPL("facelobbyfake");
				Vector3 Coords;
				Coords.x = -1047.9f; Coords.y = -233.0f; Coords.z = 39.0f;
				PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), Coords.x, Coords.y, Coords.z);
			}
			if (ImGui::Button(TRANSLATES("废弃货船"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				STREAMING::REQUEST_IPL("cargoship");
				Vector3 Coords;
				Coords.x = -162.8918f; Coords.y = -2365.769f; Coords.z = 9.3192f;
				PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), Coords.x, Coords.y, Coords.z);
			}
			if (ImGui::Button(TRANSLATES("废弃别墅"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				STREAMING::REMOVE_IPL("farm_burnt");
				STREAMING::REMOVE_IPL("farm_burnt_props");
				STREAMING::REQUEST_IPL("farm");
				STREAMING::REQUEST_IPL("farm_props");
				STREAMING::REQUEST_IPL("farmint");
				STREAMING::REQUEST_IPL("farmint_cap");
				Vector3 Coords;
				Coords.x = 2441.2f; Coords.y = 4968.5f; Coords.z = 51.7f;
				PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), Coords.x, Coords.y, Coords.z);
			}
			if (ImGui::Button(TRANSLATES("废弃医院"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				STREAMING::REQUEST_IPL("RC12B_HospitalInterior");
				STREAMING::REQUEST_IPL("RC12B_Destroyed");
				Vector3 Coords;
				Coords.x = 356.8f; Coords.y = -590.1f; Coords.z = 43.3f;
				PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), Coords.x, Coords.y, Coords.z);
			}
			if (ImGui::Button(TRANSLATES("珠宝店"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				STREAMING::REQUEST_IPL("jewel2fake");
				STREAMING::REQUEST_IPL("post_hiest_unload");
				STREAMING::REQUEST_IPL("bh1_16_refurb");
				Vector3 Coords;
				Coords.x = -630.4f; Coords.y = -236.7f; Coords.z = 40.0f;
				PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), Coords.x, Coords.y, Coords.z);
			}
			if (ImGui::Button(TRANSLATES("停尸房"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				STREAMING::REQUEST_IPL("Coroner_Int_on");
				Vector3 Coords;
				Coords.x = 244.9f; Coords.y = -1374.7f; Coords.z = 39.5f;
				PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), Coords.x, Coords.y, Coords.z);
			}
		}
		ImGui::EndChild();

		//ImGui::SameLine();
		ImGui::BeginChild("###p5", ImVec2(260, getBoxHeight(2.f)), true, ImGuiWindowFlags_NoScrollbar);
		{
			DrarTop("微距离闪现");
			static float forward = 5.f;
			ImGui::SliderFloat(TRANSLATES("距离"), &forward, -5.f, 10.f, "%.2f");
			if (ImGui::Button(TRANSLATES("闪现"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				g_fiber_pool->queue_job([]
					{
						Entity ent = PLAYER::PLAYER_PED_ID();
						if (PED::IS_PED_IN_ANY_VEHICLE(ent, FALSE))
							ent = PED::GET_VEHICLE_PED_IS_IN(ent, FALSE);

						Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
						float xVector = forward * sin(util::degToRad(heading)) * -1.f;
						float yVector = forward * cos(util::degToRad(heading));

						features::teleportToCoords(ent, { ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z });
					});
			}
		}
		ImGui::EndChild();
		ImGui::EndGroup();
	}

	void gui::vehicleTab()
	{
		ImGui::BeginTabBar("zaijuxuanx");
		if (ImGui::BeginTabItem(TRANSLATES("基础选项")))
		{
			static int test = 400;
			ImGui::BeginChild("###p1", ImVec2(260, getBoxHeight(8.0f)), true, ImGuiWindowFlags_NoScrollbar);
			{
				DrarTop("基础");
				//ImGui::SliderInt("Opacity", &test, 0, 600);
				if (ImGui::Checkbox(TRANSLATES("载具无敌"), g_settings.options["cargod bool"].get<bool*>()))
				{
					memory::set_value<int>({ 0x08, 0xD30,0x189 }, 0);
				}

				if (ImGui::Checkbox(TRANSLATES("安全带"), g_settings.options["anquandai"].get<bool*>()))
				{
					PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID(), 1);
					memory::set_value<BYTE>({ 0x8,0x145C }, -56);
				}

				ImGui::Checkbox(TRANSLATES("无限氮气"), g_settings.options["wuxiandanqi"].get<bool*>());
				ImGui::SameLine(); features::HelpMarker("具有喷射功能的载具可一直喷射，空格停喷");

				ImGui::Checkbox(TRANSLATES("按9提速"), g_settings.options["jiaosudu"].get<bool*>());
				ImGui::SameLine(); features::HelpMarker("按9持续提高速度,按3立刻停止");

				ImGui::Checkbox(TRANSLATES("彩虹载具"), g_settings.options["caihongzaiju"].get<bool*>());
				ImGui::SameLine(); features::HelpMarker("彩虹主色调+副色调+霓虹灯");
				ImGui::Checkbox(TRANSLATES("载具飞行"), g_settings.options["flycar"].get<bool*>());
				static int zuowei = -1;
				const int min = -1, max = 10;
				ImGui::Text(TRANSLATES("座位位置")); ImGui::SameLine(); features::HelpMarker("-1为司机");

				ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
				if (ImGui::SliderScalar("###座位位置", ImGuiDataType_S32, &zuowei, &min, &max))
				{
					if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
					{
						Vehicle car = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), car, zuowei);
					}
				}
				ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);

				ImGui::EndChild();
			}ImGui::SameLine();

			ImGui::BeginChild("###p2", ImVec2(260, getBoxHeight(9.0f)), true, ImGuiWindowFlags_NoScrollbar);
			{
				DrarTop("控制");
				if (ImGui::Button(TRANSLATES("升级当前载具"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, FALSE);
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						for (int i = 0; i < 50; i++)
						{
							VEHICLE::SET_VEHICLE_MOD(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
						}
					}QUEUE_JOB_END_CLAUSE
				}
				if (ImGui::Button(TRANSLATES("删除当前载具"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						Vehicle pedVeh = PED::GET_VEHICLE_PED_IS_IN(playerPed, FALSE);
						ENTITY::SET_ENTITY_AS_MISSION_ENTITY(pedVeh, true, true);
						VEHICLE::DELETE_VEHICLE(&pedVeh);
					}QUEUE_JOB_END_CLAUSE
				}
				if (ImGui::Button(TRANSLATES("修理当前载具"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
						//修复
						VEHICLE::SET_VEHICLE_FIXED(veh);
						VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(veh);
						//清灰
						VEHICLE::SET_VEHICLE_DIRT_LEVEL(veh, 0);
					}QUEUE_JOB_END_CLAUSE
				}
				if (ImGui::Button(TRANSLATES("弄脏载具"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
						VEHICLE::SET_VEHICLE_DIRT_LEVEL(veh, 15.0f);
					}QUEUE_JOB_END_CLAUSE
				}
				if (ImGui::Button(TRANSLATES("修正载具"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
						{
							Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
							VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(vehicle, 1);
						}
					}QUEUE_JOB_END_CLAUSE
				}ImGui::SameLine(); features::HelpMarker("翻车时使用");
					if (ImGui::Button(TRANSLATES("打开所有门"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
							{
								VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0, true, false);
								VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 1, true, false);
								VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 2, true, false);
								VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 3, true, false);
								VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 4, true, false);
								VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 5, true, false);
								VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 6, true, false);
								VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 7, true, false);
							}
						}QUEUE_JOB_END_CLAUSE
					}
					if (ImGui::Button(TRANSLATES("关闭所有门"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
							{
								VEHICLE::SET_VEHICLE_DOORS_SHUT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), true);
							}
						}QUEUE_JOB_END_CLAUSE
					}
					if (ImGui::Button(TRANSLATES("所有车门上锁"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
							VEHICLE::SET_VEHICLE_DOORS_LOCKED(veh, 2);
							VEHICLE::SET_VEHICLE_DOORS_LOCKED(veh, 3);
							VEHICLE::SET_VEHICLE_DOORS_LOCKED(veh, 4);
						}QUEUE_JOB_END_CLAUSE
					}
					if (ImGui::Button(TRANSLATES("所有车门解锁"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
					{
						QUEUE_JOB_BEGIN_CLAUSE()
						{
							Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
							VEHICLE::SET_VEHICLE_DOORS_LOCKED(veh, 1);
						}QUEUE_JOB_END_CLAUSE
					}
					ImGui::EndChild();
			}

			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("生成选项"))
		{
			//static int test = 400;
			//ImGui::SliderInt("Opacity", &test, 0, 600);
			ImGui::BeginGroup();
			ImGui::BeginChild("###p1", ImVec2(260, getBoxHeight(4.0f)), true, ImGuiWindowFlags_NoScrollbar);
			{
				DrarTop("生成选项");
				ImGui::Checkbox(TRANSLATES("生成的载具无敌"), g_settings.options["spwancargod"].get<bool*>());
				ImGui::Checkbox(TRANSLATES("生成的载具满改装"), g_settings.options["spwancarmax"].get<bool*>());
				ImGui::Checkbox(TRANSLATES("驾驶生成的载具"), g_settings.options["spwancarin"].get<bool*>());
				ImGui::Checkbox(TRANSLATES("删除上一辆载具"), g_settings.options["spwancardel"].get<bool*>());
			}
			ImGui::EndChild();

			//ImGui::NewLine();

			ImGui::BeginChild("###p1_1", ImVec2(260, getBoxHeight(3.0f)), true, ImGuiWindowFlags_NoScrollbar);
			{
				DrarTop("选择载具");
				ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);
				ImGui::InputTextWithHint("##vehiclename", "请勿手动输入", g_settings.list_VehicleName, 32);
				ImGui::PopItemWidth();

				if (ImGui::Button(TRANSLATES("保存当前载具到本地"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					std::ofstream write;
					char filename[64];
					sprintf_s(filename, "%s\\TXT\\car.txt", MENU_PATH);
					write.open(filename, std::ios::app);
					write << g_settings.list_VehicleName << std::endl;
					write.close();
					g_gui.initCar();
				}

				char NameBuffer[255];
				sprintf_s(NameBuffer, "创建载具:%s", g_settings.list_VehiclelabelName);
				if (ImGui::Button(NameBuffer, ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						features::spawnVehicle(g_settings.list_VehicleName);
					}QUEUE_JOB_END_CLAUSE
				}
			}
			ImGui::EndChild();

			ImGui::EndGroup();

			ImGui::SameLine();

			ImGui::BeginChild("###p2", ImVec2(260, 0));
			{
				DrarTop("载具列表");
				static rage::joaat_t hash{};
				static std::string selected_name{};
				for (VehicleClass vehClass : g_vehicles.classes)
				{
					if (ImGui::TreeNode(vehClass.className.c_str()))
					{
						for (VehiclePack vehPack : vehClass.vehicles)
						{
							if (ImGui::Selectable((vehPack.labelText + "##" + std::to_string(vehPack.hash)).c_str(), (vehPack.hash == hash)))
							{
								hash = rage::joaat(vehPack.name);
								g_settings.list_VehicleName = StringToChar(vehPack.name);
								g_settings.list_VehiclelabelName = StringToChar(vehPack.labelText);
							}
						}
						ImGui::TreePop();
						ImGui::Separator();
					}
				}
			}
			ImGui::EndChild();

			ImGui::SameLine();

			ImGui::BeginChild("###p3", ImVec2(260, 0));
			ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
			if (ImGui::BeginTabBar("Other_Vehicles", tab_bar_flags))
			{
				if (ImGui::BeginTabItem("INI载具"))
				{
					ImGui::Checkbox(TRANSLATES("创建时删除上一个模组载具"), g_settings.options["spwancardel_mod"].get<bool*>());
					if (ImGui::Button(TRANSLATES("创建选中的INI载具"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
					{
						char filename[64];
						sprintf_s(filename, "%s\\Vehicle\\%s\\%s.ini", MENU_PATH, g_settings._small_ ? "SmallMod\\" : "BigMod\\", g_settings.currentiniveh.c_str());
						QUEUE_JOB_BEGIN_CLAUSE(filename)
						{
							modvehicle::createIniVehicle(filename);
						}QUEUE_JOB_END_CLAUSE
					}
					ImGui::BeginChild("###p3_1_", ImVec2(260, 0));
					{
						DrarTop("INI载具列表");
						if (ImGui::TreeNode(TRANSLATES("大型MOD")))
						{
							for (std::string veh : g_settings.IniCarList)
							{
								if (ImGui::Selectable(veh.c_str(), (veh == g_settings.currentiniveh)))
								{
									g_settings.currentiniveh = veh;
									g_settings._small_ = false;
								}
							}

							ImGui::TreePop();
						}
						if (ImGui::TreeNode(TRANSLATES("小型载具")))
						{
							for (std::string veh1 : g_settings.IniSmallCarList)
							{
								if (ImGui::Selectable(veh1.c_str(), (veh1 == g_settings.currentiniveh)))
								{
									g_settings.currentiniveh = veh1;
									g_settings._small_ = true;
								}
							}
							ImGui::TreePop();
						}
					}
					ImGui::EndChild();
					ImGui::EndTabItem();
				}

				if (ImGui::BeginTabItem("XML载具"))
				{
					ImGui::Checkbox(TRANSLATES("创建时删除上一个模组载具"), g_settings.options["spwancardel_mod"].get<bool*>());

					if (ImGui::Button(TRANSLATES("创建选中的XML载具"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
					{
						char filename[64];
						sprintf_s(filename, "%s\\Vehicle\\XMLVeh\\%s.xml", MENU_PATH, g_settings.currentxmlveh.c_str());
						QUEUE_JOB_BEGIN_CLAUSE(filename)
						{
							modvehicle::createXmlVehicle(filename);
						}QUEUE_JOB_END_CLAUSE
					}

					ImGui::BeginChild("###p3_1_", ImVec2(260, 0));
					{
						DrarTop("XML载具列表");

						for (std::string veh : g_settings.XmlCarList)
						{
							if (ImGui::Selectable(veh.c_str(), (veh == g_settings.currentxmlveh)))
							{
								g_settings.currentxmlveh = veh;
							}
						}
					}
					ImGui::EndChild();

					ImGui::EndTabItem();
				}

				if (ImGui::BeginTabItem("本地载具"))
				{
					for (myCar& car : g_settings.CarList)
					{
						if (ImGui::Selectable(car.VehiclelabelName.c_str()))
						{
							g_settings.list_VehicleName = StringToChar(car.VehicleName);
							g_settings.list_VehiclelabelName = (char*)car.VehiclelabelName.c_str();
						}
					}

					ImGui::EndTabItem();
				}

				ImGui::EndTabBar();
			}
			ImGui::EndChild();

			ImGui::EndTabItem();
		}

		//tab_player::tab_teleport();
		//tab_player::tab_toxic();
		ImGui::EndTabBar();
	}

	void gui::menuTab()
	{
		ImGui::BeginTabBar("shezhi");
		if (ImGui::BeginTabItem(TRANSLATES("颜色")))
		{
			ImGui::BeginChild("###p1", ImVec2(ImVec2(260, 0)));
			{
				ImGuiStyle& custom = ImGui::GetStyle();
				for (int i = 0; i < ImGuiCol_COUNT; i++)
				{
					const char* name = ImGui::GetStyleColorName(i);
					ImGui::ColorEdit4((std::string("##") + name).c_str(), (float*)&custom.Colors[i], ImGuiColorEditFlags_NoInputs);
					ImGui::SameLine(); ImGui::Text(name);
				}
			}

			ImGui::EndChild();

			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem(TRANSLATES("其他")))
		{
			ImGui::BeginChild("###p1", ImVec2(260, getBoxHeight(5)), true, ImGuiWindowFlags_NoScrollbar);
			{
				DrarTop("贴图");
				ImGui::BeginChild("###p1_1", ImVec2(260, 0));
				{
					for (std::string Img : g_settings.HeadImgList)
					{
						if (ImGui::Selectable(Img.c_str(), (Img == g_settings.currentHeadImgList)))
						{
							g_settings.currentHeadImgList = Img;
							char filename[64];
							sprintf_s(filename, "%s\\img\\%s.jpg", MENU_PATH, g_settings.currentHeadImgList.c_str());
							g_renderer->LoadTextureFromFile(filename, &g_renderer->ImageHeader, &g_renderer->pHeaderSize.x, &g_renderer->pHeaderSize.y);
						}
					}
				}
				ImGui::EndChild();
				/*if (ImGui::Button(TRANSLATES("保存配置")))
				{
					ImGuiSaveStyle2("C:\\DarkStar\\theme\\theme.style", ImGui::GetStyle());
				}
				ImGui::SameLine();
				if (ImGui::Button(TRANSLATES("加载配置")))
				{
					ImGuiLoadStyle2("C:\\DarkStar\\theme\\theme.style", ImGui::GetStyle());
				}*/
			}
			ImGui::EndChild();
			ImGui::SameLine();

			ImGui::BeginGroup();
			ImGui::BeginChild("###p2", ImVec2(260, getBoxHeight(2.f)), true, ImGuiWindowFlags_NoScrollbar);
			{
				DrarTop("保存");

				static char filename[20];
				ImGui::InputText(TRANSLATES("主题重命名"), filename, sizeof(filename));
				if (ImGui::Button(TRANSLATES("保存当前主题配置"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
				{
					char file_name[64];
					sprintf_s(file_name, "%s\\theme\\%s.style", MENU_PATH, filename);
					ImGuiSaveStyle2(file_name, ImGui::GetStyle());
					g_gui.inittheme();
				}
			}
			ImGui::EndChild();

			ImGui::BeginChild("###p2_1", ImVec2(260, getBoxHeight(5.f)), true, ImGuiWindowFlags_NoScrollbar);
			{
				DrarTop("加载");

				ImGui::BeginChild("###p2_1_1", ImVec2(260, 0));
				{
					for (std::string theme : g_settings.themeList)
					{
						if (ImGui::Selectable(theme.c_str(), (theme == g_settings.currenttheme)))
						{
							g_settings.currenttheme = theme;
							char filename[64];
							sprintf_s(filename, "%s\\theme\\%s.style", MENU_PATH, g_settings.currenttheme.c_str());
							ImGuiLoadStyle2(filename, ImGui::GetStyle());
						}
					}
				}
			}
			ImGui::EndChild();
			ImGui::EndGroup();
			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}
}