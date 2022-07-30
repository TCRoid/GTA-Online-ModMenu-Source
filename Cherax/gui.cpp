#include "gui.h"
#include "pointers.h"
#include "D3DHooking.h"
#include "fonts.h"
#include "script.h"
#include "fiber_pool.h"
#include "nativeFuncs.h"
#include "gta_util.h"
#include "vehicles.h"
#include "script_global.h"
#include "Locations.h"
#include "XMLStuff.h"


using namespace std::chrono_literals;

void GUI::init()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	io.IniFilename = NULL;

	ImGui_ImplDX11_Init(g_renderer->m_d3d_device.Get(), g_renderer->m_d3d_device_context.Get());
	ImGui_ImplWin32_Init(g_pointers->m_hwnd);

	initStyle();
	initFonts();
	initTextures();

	initDone = true;
}


void GUI::initStyle()
{
	//ImGui::GetStyle().WindowTitleAlign = ImVec2(0.5, 0.5);
	ImGui::GetStyle().SelectableTextAlign = ImVec2(0.5f, 0.5f);
	ImGui::GetStyle().WindowRounding = 0.f;
	ImGui::GetStyle().WindowBorderSize = 1.f;
	ImGui::GetStyle().ChildRounding = 1.f;
	/*ImGui::GetStyle().AntiAliasedLines = true;
	ImGui::GetStyle().AntiAliasedFill = true;
	ImGui::GetStyle().CurveTessellationTol = 0.f;*/
	ImGuiIO& io = ImGui::GetIO();

	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Border] = ImGui::ColorConvertU32ToFloat4(ImColor(89, 66, 250, 204));
	colors[ImGuiCol_CheckMark] = ImGui::ColorConvertU32ToFloat4(ImColor(89, 34, 255, 255));
	colors[ImGuiCol_SliderGrab] = ImGui::ColorConvertU32ToFloat4(ImColor(89, 34, 255, 255));
	//colors[ImGuiCol_Button] = ImGui::ColorConvertU32ToFloat4(ImColor(89, 34, 255, 255));
	//colors[ImGuiCol_ChildBg] = ImColor(0, 0, 0, 255);
}

void GUI::initFonts()
{

	tabFont = ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF((void*)nasalization_compressed_data, nasalization_compressed_size, 19.0f, NULL, ImGui::GetIO().Fonts->GetGlyphRangesJapanese());
	childHeaderFont = ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF((void*)verdanab_compressed_data, verdanab_compressed_size, 18.0f, NULL, ImGui::GetIO().Fonts->GetGlyphRangesJapanese());
	textFont = ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF((void*)verdana_compressed_data, verdana_compressed_size, 17.0f, NULL, ImGui::GetIO().Fonts->GetGlyphRangesJapanese());
	//textFont = io.Fonts->AddFontFromMemoryCompressedTTF((void*)verdanab_compressed_data, verdanab_compressed_size, 19.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
	//textFont = io.Fonts->AddFontFromMemoryCompressedTTF((void*)CodeBold_compressed_data, CodeBold_compressed_size, 19.0f);
	//textFont = io.Fonts->AddFontFromMemoryCompressedTTF((void*)zrni_compressed_data, zrni_compressed_size, 19.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
	//textFont = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\Arial.ttf", 18.f, NULL, io.Fonts->GetGlyphRangesJapanese());  //times calibril
	//headerFont = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\Arialbi.ttf", 19.f, NULL, io.Fonts->GetGlyphRangesJapanese());  //times calibril
	//speedFont = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ARIALNB.ttf", 120.f, NULL, io.Fonts->GetGlyphRangesJapanese());
}

inline bool exists(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

void GUI::initTextures()
{
	static HANDLE handle = CreateThread(nullptr, 0, [](PVOID) -> DWORD
	{
			try
			{
				printf("Initializing textures\n");

				std::filesystem::create_directories((std::string(getenv("APPDATA")) + "\\Cherax\\Assets\\Icons"));
				std::filesystem::create_directories((std::string(getenv("APPDATA")) + "\\Cherax\\Assets\\Animations\\opening"));
				std::filesystem::create_directories((std::string(getenv("APPDATA")) + "\\Cherax\\Assets\\Animations\\idle"));
		
				Download:
				for (std::string str : g_gui.iconList)
				{
					const char* filePath = (std::string(getenv("APPDATA")) + "\\Cherax\\Assets\\Icons\\" + str + ".png").c_str();
					if (!exists(filePath))
					{
						char fileLink[256];
						sprintf_s(fileLink, 256, "https://raw.githubusercontent.com/theHorizonGTA/AHUFDWS/master/icons/%s.png", str.c_str());

						URLDownloadToFile(NULL,
							fileLink,
							filePath,
							0,
							NULL);
					}
				}

				for (int i = 0; i < 200; i++)
				{
					const char* filePath = (std::string(getenv("APPDATA")) + "\\Cherax\\Assets\\Animations\\idle\\idle (" + std::to_string(i) + ").gif").c_str();
					if (!exists(filePath))
					{
						const char* fileLink = (std::string("https://github.com/theHorizonGTA/AHUFDWS/raw/master/Animations/idle/idle%20(") + std::to_string(i) + ").gif").c_str();

						URLDownloadToFile(NULL,
							fileLink,
							filePath,
							0,
							NULL);
					}
				}

				for (int i = 0; i < 200; i++)
				{
					const char* filePath = (std::string(getenv("APPDATA")) + "\\Cherax\\Assets\\Animations\\opening\\opening (" + std::to_string(i) + ").gif").c_str();
					if (!exists(filePath))
					{
						const char* fileLink = (std::string("https://github.com/theHorizonGTA/AHUFDWS/raw/master/Animations/opening/opening%20(") + std::to_string(i) + ").gif").c_str();

						URLDownloadToFile(NULL,
							fileLink,
							filePath,
							0,
							NULL);
					}
				}
				
				Sleep(100);

				for (std::string str : g_gui.iconList)
				{
					ID3D11ShaderResourceView* Icon{};
					if (D3DX11CreateShaderResourceViewFromFile(g_renderer->m_d3d_device.Get(), (std::string(getenv("APPDATA")) + "\\Cherax\\Assets\\Icons\\" + str + ".png").c_str(), NULL, NULL, &Icon, NULL) != S_OK)
					{
						printf("Failed to initialize texture %hs", (std::string(getenv("APPDATA")) + "\\Cherax\\Assets\\Icons\\" + str + ".png\n").c_str());
						printf("retrying\n");
						g_gui.Icons.clear();
						goto Download;
					}
						
					g_gui.Icons.insert(	std::pair<std::string, ID3D11ShaderResourceView*>(str, Icon));
				}

				for (int i = 0; i < 200; i++)
				{
					const char* filePath = (std::string(getenv("APPDATA")) + "\\Cherax\\Assets\\Animations\\idle\\idle (" + std::to_string(i) + ").gif").c_str();

					ID3D11ShaderResourceView* idle{};
					if (D3DX11CreateShaderResourceViewFromFile(g_renderer->m_d3d_device.Get(), filePath, NULL, NULL, &idle, NULL) != S_OK)
					{
						printf("Failed to initialize texture %hs\n", filePath);
						printf("retrying\n");
						g_gui.idleHeader.clear();
						goto Download;
					}		
					else
						g_gui.idleHeader.push_back(idle);		
				}

				for (int i = 0; i < 200; i++)
				{
					const char* filePath = (std::string(getenv("APPDATA")) + "\\Cherax\\Assets\\Animations\\opening\\opening (" + std::to_string(i) + ").gif").c_str();
					
					ID3D11ShaderResourceView* opening{};
					if (D3DX11CreateShaderResourceViewFromFile(g_renderer->m_d3d_device.Get(), filePath, NULL, NULL, &opening, NULL) != S_OK)
					{
						printf("Failed to initialize texture %hs\n", filePath);
						printf("retrying\n");
						g_gui.openingHeader.clear();
						goto Download;
					}
					else
						g_gui.openingHeader.push_back(opening);
				}

				g_gui.resourceInitDone = true;
				printf("Textures initialized\n");
			}
			catch (std::exception const& ex)
			{
				printf("%s", ex.what());
				MessageBoxA(g_pointers->m_hwnd, ex.what(), nullptr, MB_OK | MB_ICONEXCLAMATION);
				system("pause");
			}

	}, nullptr, 0, NULL);
}

void GUI::on_frame()
{
	if (!initDone)
		return;

	if (g_gui.m_opened)
	{
		ImGui::GetIO().MouseDrawCursor = true;
		ImGui::GetIO().ConfigFlags &= ~ImGuiConfigFlags_NoMouse;
	}
	else
	{
		ImGui::GetIO().MouseDrawCursor = false;
		ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouse;
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	g_renderer->resizeImGui();

	g_gui.backgroundOverlay();
	if (g_gui.m_opened)
		mainMenu();

	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

void GUI::mainMenu()
{
	static bool oncePos = true;
	if (oncePos)
	{
		ImGui::SetNextWindowPos(ImVec2(resizefloat(217), 50));
		oncePos = false;
	}

	ImGui::SetNextWindowSize(resizeVec(ImVec2(660.f, 600.f)));
	if (ImGui::Begin("Cherax", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar))
	{
		ImGui::SetScrollX(0.f);
		mainWindowPos = ImGui::GetWindowPos();
		mainWindowSize = ImGui::GetWindowSize();

		ImGuiWindow* window = ImGui::GetCurrentWindow();
		window->DrawList->AddRectFilledMultiColor(ImVec2(ImGui::GetWindowPos().x, ImGui::GetWindowPos().y), ImVec2(ImGui::GetWindowPos().x + ImGui::GetWindowSize().x, ImGui::GetWindowPos().y + resizefloat(10)), ImColor(025, 025, 112), ImColor(138, 043, 226), ImColor(138, 043, 226), ImColor(025, 025, 112)); // header bar

		ImGui::Dummy(ImVec2(ImGui::GetWindowSize().x, resizefloat(10) - resizefloat(8)));
		ImGui::Separator();

		ImGui::Columns(4, NULL, false);
		ImGui::SetColumnOffset(1, resizefloat(150));
		ImGui::SetColumnOffset(2, resizefloat(180));
		ImGui::SetColumnOffset(3, resizefloat(420));
		{ /// tabs

			float Tabheight = ImGui::GetContentRegionAvail().y / 14.f;
			ImVec2 start1;
			ImVec2 start2;
			ImVec2 end1;
			ImVec2 end2;

			start1 = ImGui::GetCursorScreenPos();
			ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
			int i = 0;
			for (std::string str : menus)
			{
				bool pushColor = false;
				if (selectedTab == i)
				{
					end1 = ImGui::GetCursorScreenPos();
					pushColor = true;
				}

				if (pushColor)
					ImGui::PushStyleColor(ImGuiCol_Button, ImGuiCol_WindowBg);
				else
					ImGui::PushStyleColor(ImGuiCol_Button, ImGui::ColorConvertU32ToFloat4(ImColor(0,0,0,255)));

				if (ImGui::Button(str.c_str(), ImVec2(resizefloat(150), Tabheight)))
					selectedTab = i;
				ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);

				ImGui::PopStyleColor();


				if (selectedTab == i)
					start2 = ImGui::GetCursorScreenPos();
				
				i++;
			}
			ImGui::PopStyleVar();
			end2 = ImGui::GetCursorScreenPos();

			if (start1.y != end1.y)
				window->DrawList->AddRect(ImVec2(start1.x, start1.y), ImVec2(end1.x + resizefloat(150) - resizefloat(8) - 1.f, end1.y), ImGui::ColorConvertFloat4ToU32(ImGui::GetStyle().Colors[ImGuiCol_Border]), 0.f, 15, 2.f);
			if (start2.y != end2.y)
				window->DrawList->AddRect(ImVec2(start2.x, start2.y), ImVec2(end2.x + resizefloat(150) - resizefloat(8) - 1.f, end2.y), ImGui::ColorConvertFloat4ToU32(ImGui::GetStyle().Colors[ImGuiCol_Border]), 0.f, 15, 2.f);
		}
		ImGui::NextColumn();
		ImGui::NextColumn();
		ImGui::PushFont(textFont);
		switch (selectedTab)
		{
		case 0:
			Self();
			break;

		case 1:
			break;

		case 2:
			PlayerList();
			break;

		case 3:
			Weapon();
			break;

		case 4:
			Visuals();
			break;

		case 5:
			Spawner();
			break;

		case 6:
			VehicleMenu();
			break;

		case 7:
			World();
			break;

		case 8:
			Teleport();
			break;

		case 9:
			break;

		case 10:
			Misc();
			break;

		case 11:
			Protections();
			break;

		case 12:
			break;

		case 13:
			Settings();
			break;

		default:
			break;
		}
		ImGui::PopFont();
		ImGui::Columns();
		ImGui::End();
	}
}

void GUI::backgroundOverlay()
{
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0.0f, 0.0f });
	ImGui::PushStyleColor(ImGuiCol_WindowBg, enableScreenFilter ? screenFilter : ImVec4(0.0f, 0.0f, 0.0f, 0.0f));

	ImGuiIO& io = ImGui::GetIO();
	ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
	ImGui::SetNextWindowSize(ImVec2(io.DisplaySize.x, io.DisplaySize.y), ImGuiCond_Always);
	if (ImGui::Begin("##BackgroundOverlay", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoInputs))
	{
		ImGui::PushFont(textFont);
		ImGuiWindow* window = ImGui::GetCurrentWindow();

		u32_enemyColor = ImGui::ColorConvertFloat4ToU32(enemyColor);
		u32_teamColor = ImGui::ColorConvertFloat4ToU32(teamColor);
		u32_friendColor = ImGui::ColorConvertFloat4ToU32(friendColor);
		u32_NpcColor = ImGui::ColorConvertFloat4ToU32(NpcColor);
		u32_CopColor = ImGui::ColorConvertFloat4ToU32(CopColor);
		u32_yourColor = ImGui::ColorConvertFloat4ToU32(yourColor);
		u32_crosshairColor = ImGui::ColorConvertFloat4ToU32(crosshairColor);

		if (features::bMiscCrosshair)
		{
			if (features::localData.alive)
			{
				if (g_pointers->m_menuPtr)
				{
					if (!*g_pointers->m_menuPtr)
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
	

		if (features::drawHeader)
		{
			static bool reopening = true;
			static int reopeningFrame = 0;
			static int idleFrame = 0;
			if (!g_gui.m_opened)
			{
				reopening = true;
				reopeningFrame = 0;
				idleFrame = 0;
			}			
			else
			{
				static bool timer_reset = true;
				static std::chrono::system_clock::time_point timer_Start;

				if (timer_reset)
				{
					timer_Start = std::chrono::system_clock::now();
					timer_reset = false;
				}

				if (reopening)
				{
					window->DrawList->AddImage((ImTextureID)openingHeader.at(reopeningFrame), ImVec2(mainWindowPos.x - resizefloat(167), mainWindowPos.y), ImVec2(mainWindowPos.x, mainWindowPos.y + mainWindowSize.y));

					std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - timer_Start;
					if (elapsed_seconds.count() >= 0.019)
					{
						reopeningFrame++;
						if (reopeningFrame == 200)
						{
							reopening = false;
							reopeningFrame = 0;
						}
						timer_reset = true;
					}
				}
				else
				{
					window->DrawList->AddImage((ImTextureID)idleHeader.at(idleFrame), ImVec2(mainWindowPos.x - resizefloat(167), mainWindowPos.y), ImVec2(mainWindowPos.x, mainWindowPos.y + mainWindowSize.y));

					std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - timer_Start;
					if (elapsed_seconds.count() >= 0.019)
					{
						idleFrame++;
						if (idleFrame == 200)
							idleFrame = 0;
						timer_reset = true;
					}
				}
			}
		}

		if (features::drawFPS)
		{
			//	//% .3f ms / frame(% .1f FPS), 1000.0f / ,
			int framerate = ImGui::GetIO().Framerate;
			std::string fps = (std::to_string(framerate) + " FPS");
			window->DrawList->AddText(ImVec2(io.DisplaySize.x - ImGui::CalcTextSize(fps.c_str()).x, 2), ImColor(255, 255, 255), fps.c_str());
		}
			

		if (features::drawWatermark)
			window->DrawList->AddText(ImVec2(2,2), ImColor(255, 255, 255), watermark.c_str());

		if (features::drawCurrentTime)
			window->DrawList->AddText(ImVec2(io.DisplaySize.x / 2, 2), ImColor(255, 255, 255), features::currentTime().c_str());
	
		if (*g_pointers->m_is_session_started)
		{
			for (tPlayerData data : features::playerData)
			{
				if (data.IsValid && data.IsConnected)
				{
					if (data.distance < features::ESPRange)
					{
						if (data.playerId == features::localData.localId)
						{
							if (features::ESPonYou)
								goto renderVisuals;
						}
						else if (data.IsFriend)
						{
							if (data.IsFriend && features::ESPonFriends)
								goto renderVisuals;
						}
						else if (features::isTeamGameModeRunning)
						{
							if (data.IsTeam && features::ESPonTeam)
								goto renderVisuals;
						}
						else if (features::ESPonEnemies)
						{
						renderVisuals:
							if (features::ESPTracers)
							{
								DrawLine(data, WorldToScreen({ features::localData.visualPos.x, NULL, features::localData.visualPos.y, NULL, features::localData.visualPos.z, NULL }), WorldToScreen({ data.position.x, NULL, data.position.y, NULL, data.position.z, NULL }));
							}

							if (features::ESPSkeleton)
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

							if (features::ESPRotation)
							{
								float forward = 3.f;
								float xVector = forward * sin(features::degToRad(data.heading)) * -1.f;
								float yVector = forward * cos(features::degToRad(data.heading));
								Vector3 tmpVec = { data.head.x + xVector, NULL, data.head.y + yVector, NULL, data.head.z, NULL };
								DrawLine(data, WorldToScreen(data.head), WorldToScreen(tmpVec));
							}

							if (features::ESP2DBoxes)
							{
								if (data.IsInVehicle)
									Draw2DBox(data, WorldToScreen({ data.head.x, NULL, data.head.y, NULL, data.head.z + 0.2f, NULL }), WorldToScreen({ data.head.x, NULL, data.head.y, NULL, data.lFoot.z - 0.1f, NULL }));
								else
									Draw2DBox(data, WorldToScreen({ data.position.x, NULL, data.position.y, NULL, data.position.z + 0.9f, NULL }), WorldToScreen({ data.position.x, NULL, data.position.y, NULL, data.position.z - 1.2f, NULL }));
								//	Draw2DBox(data, WorldToScreen({ data.head.x, NULL, data.head.y, NULL, data.head.z + 0.2f, NULL }), WorldToScreen({ data.head.x, NULL, data.head.y, NULL, data.head.z - 1.8f, NULL }));	
							}

							if (features::ESP3DBoxes)
							{
								if (data.IsInVehicle)
								{
									ImVec2 top1world = WorldToScreen({ data.position.x + 0.3f, NULL, data.position.y + 0.3f, NULL, data.position.z + .8f, NULL });
									ImVec2 top2world = WorldToScreen({ data.position.x - 0.3f, NULL, data.position.y + 0.3f, NULL, data.position.z + .8f, NULL });
									ImVec2 top3world = WorldToScreen({ data.position.x + 0.3f, NULL, data.position.y - 0.3f, NULL, data.position.z + .8f, NULL });
									ImVec2 top4world = WorldToScreen({ data.position.x - 0.3f, NULL, data.position.y - 0.3f, NULL, data.position.z + .8f, NULL });
									ImVec2 bottom1world = WorldToScreen({ data.position.x + 0.3f, NULL, data.position.y + 0.3f, NULL, data.lFoot.z - 0.1f, NULL });
									ImVec2 bottom2world = WorldToScreen({ data.position.x - 0.3f, NULL, data.position.y + 0.3f, NULL, data.lFoot.z - 0.1f, NULL });
									ImVec2 bottom3world = WorldToScreen({ data.position.x + 0.3f, NULL, data.position.y - 0.3f, NULL, data.lFoot.z - 0.1f, NULL });
									ImVec2 bottom4world = WorldToScreen({ data.position.x - 0.3f, NULL, data.position.y - 0.3f, NULL, data.lFoot.z - 0.1f, NULL });

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
									ImVec2 top1world = WorldToScreen({ data.position.x + 0.3f, NULL, data.position.y + 0.3f, NULL, data.position.z + .8f, NULL });
									ImVec2 top2world = WorldToScreen({ data.position.x - 0.3f, NULL, data.position.y + 0.3f, NULL, data.position.z + .8f, NULL });
									ImVec2 top3world = WorldToScreen({ data.position.x + 0.3f, NULL, data.position.y - 0.3f, NULL, data.position.z + .8f, NULL });
									ImVec2 top4world = WorldToScreen({ data.position.x - 0.3f, NULL, data.position.y - 0.3f, NULL, data.position.z + .8f, NULL });
									ImVec2 bottom1world = WorldToScreen({ data.position.x + 0.3f, NULL, data.position.y + 0.3f, NULL, data.position.z - 1.0f, NULL });
									ImVec2 bottom2world = WorldToScreen({ data.position.x - 0.3f, NULL, data.position.y + 0.3f, NULL, data.position.z - 1.0f, NULL });
									ImVec2 bottom3world = WorldToScreen({ data.position.x + 0.3f, NULL, data.position.y - 0.3f, NULL, data.position.z - 1.0f, NULL });
									ImVec2 bottom4world = WorldToScreen({ data.position.x - 0.3f, NULL, data.position.y - 0.3f, NULL, data.position.z - 1.0f, NULL });

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

							if (features::ESPHealthbar)
							{
								if (data.IsInVehicle)
									drawHealthBar(data, WorldToScreen({ data.head.x, NULL, data.head.y, NULL, data.head.z + 0.2f, NULL }), WorldToScreen({ data.head.x, NULL, data.head.y, NULL, data.lFoot.z - 0.1f, NULL }));
								else
									drawHealthBar(data, WorldToScreen({ data.position.x, NULL, data.position.y, NULL, data.position.z + 0.9f, NULL }), WorldToScreen({ data.position.x, NULL, data.position.y, NULL, data.position.z - 1.2f, NULL }));
							}

							if (features::ESPArmorbar)
							{
								if (data.IsInVehicle)
									drawAmourBar(data, WorldToScreen({ data.head.x, NULL, data.head.y, NULL, data.head.z + 0.2f, NULL }), WorldToScreen({ data.head.x, NULL, data.head.y, NULL, data.lFoot.z - 0.1f, NULL }));
								else
									drawAmourBar(data, WorldToScreen({ data.position.x, NULL, data.position.y, NULL, data.position.z + 0.9f, NULL }), WorldToScreen({ data.position.x, NULL, data.position.y, NULL, data.position.z - 1.2f, NULL }));
							}

							if (features::ESPName || features::ESPDistance)
							{
								if (data.IsInVehicle)
									DrawDistanceAndName(data, WorldToScreen({ data.head.x, NULL, data.head.y, NULL, data.head.z + 0.2f, NULL }), WorldToScreen({ data.head.x, NULL, data.head.y, NULL, data.lFoot.z - 0.1f, NULL }));
								else
									DrawDistanceAndName(data, WorldToScreen({ data.position.x, NULL, data.position.y, NULL, data.position.z + 0.9f, NULL }), WorldToScreen({ data.position.x, NULL, data.position.y, NULL, data.position.z - 1.2f, NULL }));
							}
						}
					}
				}
			}
		}
		
		for (tPlayerData data : features::nearbyPeds)
		{
			if (data.distance < features::ESPPedRange)
			{
				if (data.IsCop)
				{
					if (features::ESPonCops)
						goto renderNPCVisuals;
				}
				else if (data.IsNPC && features::ESPonNPCs)
				{
				renderNPCVisuals:

					if (features::ESPTracers)
					{
						DrawLine(data, WorldToScreen({ features::localData.visualPos.x, NULL, features::localData.visualPos.y, NULL, features::localData.visualPos.z, NULL }), WorldToScreen({ data.position.x, NULL, data.position.y, NULL, data.position.z, NULL }));
					}

					if (features::ESPSkeleton)
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

					if (features::ESPRotation)
					{
						float forward = 3.f;
						float xVector = forward * sin(features::degToRad(data.heading)) * -1.f;
						float yVector = forward * cos(features::degToRad(data.heading));
						Vector3 tmpVec = { data.head.x + xVector, NULL, data.head.y + yVector, NULL, data.head.z, NULL };
						DrawLine(data, WorldToScreen(data.head), WorldToScreen(tmpVec));
					}

					if (features::ESP2DBoxes)
					{
						if (data.IsInVehicle)
							Draw2DBox(data, WorldToScreen({ data.head.x, NULL, data.head.y, NULL, data.head.z + 0.2f, NULL }), WorldToScreen({ data.head.x, NULL, data.head.y, NULL, data.lFoot.z - 0.1f, NULL }));
						else
							Draw2DBox(data, WorldToScreen({ data.position.x, NULL, data.position.y, NULL, data.position.z + 0.9f, NULL }), WorldToScreen({ data.position.x, NULL, data.position.y, NULL, data.position.z - 1.2f, NULL }));
						//	Draw2DBox(data, WorldToScreen({ data.head.x, NULL, data.head.y, NULL, data.head.z + 0.2f, NULL }), WorldToScreen({ data.head.x, NULL, data.head.y, NULL, data.head.z - 1.8f, NULL }));	
					}

					if (features::ESP3DBoxes)
					{
						if (data.IsInVehicle)
						{
							ImVec2 top1world = WorldToScreen({ data.position.x + 0.3f, NULL, data.position.y + 0.3f, NULL, data.position.z + .8f, NULL });
							ImVec2 top2world = WorldToScreen({ data.position.x - 0.3f, NULL, data.position.y + 0.3f, NULL, data.position.z + .8f, NULL });
							ImVec2 top3world = WorldToScreen({ data.position.x + 0.3f, NULL, data.position.y - 0.3f, NULL, data.position.z + .8f, NULL });
							ImVec2 top4world = WorldToScreen({ data.position.x - 0.3f, NULL, data.position.y - 0.3f, NULL, data.position.z + .8f, NULL });
							ImVec2 bottom1world = WorldToScreen({ data.position.x + 0.3f, NULL, data.position.y + 0.3f, NULL, data.lFoot.z - 0.1f, NULL });
							ImVec2 bottom2world = WorldToScreen({ data.position.x - 0.3f, NULL, data.position.y + 0.3f, NULL, data.lFoot.z - 0.1f, NULL });
							ImVec2 bottom3world = WorldToScreen({ data.position.x + 0.3f, NULL, data.position.y - 0.3f, NULL, data.lFoot.z - 0.1f, NULL });
							ImVec2 bottom4world = WorldToScreen({ data.position.x - 0.3f, NULL, data.position.y - 0.3f, NULL, data.lFoot.z - 0.1f, NULL });

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
							ImVec2 top1world = WorldToScreen({ data.position.x + 0.3f, NULL, data.position.y + 0.3f, NULL, data.position.z + .8f, NULL });
							ImVec2 top2world = WorldToScreen({ data.position.x - 0.3f, NULL, data.position.y + 0.3f, NULL, data.position.z + .8f, NULL });
							ImVec2 top3world = WorldToScreen({ data.position.x + 0.3f, NULL, data.position.y - 0.3f, NULL, data.position.z + .8f, NULL });
							ImVec2 top4world = WorldToScreen({ data.position.x - 0.3f, NULL, data.position.y - 0.3f, NULL, data.position.z + .8f, NULL });
							ImVec2 bottom1world = WorldToScreen({ data.position.x + 0.3f, NULL, data.position.y + 0.3f, NULL, data.position.z - 1.0f, NULL });
							ImVec2 bottom2world = WorldToScreen({ data.position.x - 0.3f, NULL, data.position.y + 0.3f, NULL, data.position.z - 1.0f, NULL });
							ImVec2 bottom3world = WorldToScreen({ data.position.x + 0.3f, NULL, data.position.y - 0.3f, NULL, data.position.z - 1.0f, NULL });
							ImVec2 bottom4world = WorldToScreen({ data.position.x - 0.3f, NULL, data.position.y - 0.3f, NULL, data.position.z - 1.0f, NULL });

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

					if (features::ESPHealthbar)
					{
						if (data.IsInVehicle)
							drawHealthBar(data, WorldToScreen({ data.head.x, NULL, data.head.y, NULL, data.head.z + 0.2f, NULL }), WorldToScreen({ data.head.x, NULL, data.head.y, NULL, data.lFoot.z - 0.1f, NULL }));
						else
							drawHealthBar(data, WorldToScreen({ data.position.x, NULL, data.position.y, NULL, data.position.z + 0.9f, NULL }), WorldToScreen({ data.position.x, NULL, data.position.y, NULL, data.position.z - 1.2f, NULL }));
					}

					if (features::ESPName || features::ESPDistance)
					{
						if (data.IsInVehicle)
							DrawDistanceAndName(data, WorldToScreen({ data.head.x, NULL, data.head.y, NULL, data.head.z + 0.2f, NULL }), WorldToScreen({ data.head.x, NULL, data.head.y, NULL, data.lFoot.z - 0.1f, NULL }));
						else
							DrawDistanceAndName(data, WorldToScreen({ data.position.x, NULL, data.position.y, NULL, data.position.z + 0.9f, NULL }), WorldToScreen({ data.position.x, NULL, data.position.y, NULL, data.position.z - 1.2f, NULL }));
					}
				}	
			}	
		}
		
		ImGui::PopFont();
		ImGui::End();
	}
	ImGui::PopStyleColor();
	ImGui::PopStyleVar();
	ImGui::PopStyleVar();
}

void GUI::Self()
{

	{
		ImGui::BeginChild("SelfOptions", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 18 + ImGui::GetStyle().ItemSpacing.y * 5 + ImGui::GetTextLineHeightWithSpacing()), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushFont(childHeaderFont); ImGui::Text("Self Options"); ImGui::PopFont(); ImGui::Separator();
		ImGui::Checkbox("God Mode", &features::bSelfgodMode);
		ImGui::Checkbox("No Ragdoll", &features::bSelfNoRagdoll);
		ImGui::Checkbox("Invisible", &features::bSelfInvisible);
		ImGui::Checkbox("Seatbelt", &features::bSelfSeatbelt);
		ImGui::Checkbox("Infinity Stamina", &features::bSelfStamina);
		ImGui::Checkbox("Run Multiplier", &features::bSelfRunMultiplier);
		ImGui::Checkbox("Swim Multiplier", &features::bSelfSwimMultiplier);
		ImGui::Checkbox("Super Jump", &features::bSelfSuperJump);
		if (ImGui::Checkbox("Never Wanted", &features::bSelfNeverWanted)) features::bSelfAlwaysWanted = false;
		if (ImGui::Checkbox("Always Wanted", &features::bSelfAlwaysWanted)) features::bSelfNeverWanted = false;
		ImGui::Checkbox("Tiny Player", &features::bSelfTinyPlayer); 
		ImGui::Checkbox("Fire Breath", &features::bSelfFireBreath);
		ImGui::Checkbox("Off Radar", &features::bSelfOffRadar);
		ImGui::Checkbox("Instant BST", &features::bSelfInstantBST);
		ImGui::Checkbox("No Clip", &features::bSelfNoClip);			

		ImGui::NewLine();

		if (ImGui::Button("Refill Health", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
		{
			g_fiber_pool->queue_job([]
				{
					ENTITY::SET_ENTITY_HEALTH(features::localData.localPed, PED::GET_PED_MAX_HEALTH(features::localData.localPed));
				});
		}
		if (ImGui::Button("Refill Armour", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
		{
			g_fiber_pool->queue_job([]
				{
					PED::ADD_ARMOUR_TO_PED(features::localData.localPed, PLAYER::GET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_ID()) - PED::GET_PED_ARMOUR(features::localData.localPed));
				});
		}
		if (ImGui::Button("Clean Ped", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
		{
			g_fiber_pool->queue_job([]
				{
					PED::CLEAR_PED_WETNESS(features::localData.localPed);
					PED::CLEAR_PED_BLOOD_DAMAGE(features::localData.localPed);
					PED::RESET_PED_VISIBLE_DAMAGE(features::localData.localPed);
				});
		}
		ImGui::EndChild();
	}
	ImGui::NextColumn();
	{
		ImGui::BeginChild("SelfMultiplier", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 5 + ImGui::GetStyle().ItemSpacing.y * 10 + textFont->FontSize * 5), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushFont(childHeaderFont); ImGui::Text("Multiplier"); ImGui::PopFont(); ImGui::Separator();
		ImGui::Text("Run Speed Multiplier");
		ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f)); ImGui::SliderFloat("##runfactor", &features::fSelfRunMultiplier, 0.1f, 5.0f, "%.1f");
		ImGui::Text("Swim Speed Multiplier");
		ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f)); ImGui::SliderFloat("##swimfactor", &features::fSelfSwimMultiplier, 0.1f, 5.0f, "%.1f");
		ImGui::Text("Health Recharge Multiplier");
		ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f)); ImGui::SliderFloat("##healthrechargefactor", &features::fSelfHealthRechargeMultiplier, 0.1f, 5.0f, "%.1f");
		if (features::localData.factory)
			if (features::localData.factory)
				if (features::localData.factory->m_local_ped)
				{
					ImGui::Text("Wanted Level");
					ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f)); if (ImGui::SliderInt("##WantedLevel", &features::localData.factory->m_local_ped->pCPlayerInfo->m_wanted_level, 0, 5))
					{
						features::bSelfAlwaysWanted = false; features::bSelfNeverWanted = false;
					}
				}
		ImGui::Text("Fake Wanted Level");
		ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f)); ImGui::SliderInt("##fakeWantedLevel", &features::iSelfFakeWantedLevel, 0, 6);
		ImGui::EndChild();

		ImGui::NewLine();

		ImGui::BeginChild("SelfOther", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 3 + ImGui::GetStyle().ItemSpacing.y * 8 + textFont->FontSize * 3), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushFont(childHeaderFont); ImGui::Text("Other"); ImGui::PopFont(); ImGui::Separator();
		ImGui::PushItemWidth(ImGui::GetContentRegionAvailWidth());
		ImGui::Text("PTFX");
		if (ImGui::BeginCombo("##ptfx", features::PTFXDisplayName.c_str()))
		{
			for (tPTFX ptfx : ePTFX)
			{
				if (ImGui::Selectable(ptfx.DisplayName.c_str(), (ptfx.DisplayName == features::PTFXDisplayName)))
				{
					features::PTFXDisplayName = ptfx.DisplayName;
					features::PTFXName = ptfx.PTFXName;
					features::PTFXCall = ptfx.PTFXCall;
				}
			}
			ImGui::EndCombo();
		}

		{
			static std::string selectedAnimDisplayName("Stop Animation");
			ImGui::Text("Animations");
			if (ImGui::BeginCombo("##Animations", selectedAnimDisplayName.c_str()))
			{
				static std::string selectedAnimName("Stop Animation");
				static std::string  selectedAnimId("Stop Animation");
				for (tAnimation anim : eAnimation)
				{
					if (ImGui::Selectable(anim.DisplayName.c_str(), (anim.DisplayName == selectedAnimDisplayName)))
					{
						selectedAnimDisplayName = anim.DisplayName;
						selectedAnimName = anim.AnimationName;
						selectedAnimId = anim.AnimationId;

						g_fiber_pool->queue_job([]
							{
								if (selectedAnimDisplayName == std::string("Stop Animation"))
									AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
								else
								{
									STREAMING::REQUEST_ANIM_DICT(selectedAnimName.c_str());
									while (!STREAMING::HAS_ANIM_DICT_LOADED(selectedAnimName.c_str()))
										script::get_current()->yield();
									AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), selectedAnimName.c_str(), selectedAnimId.c_str(), 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
								}					
							});
					}
				}
				ImGui::EndCombo();
			}
		}

		{
			static std::string selectedScenarioDisplayName("Stop Scenario");
			ImGui::Text("Scenarios");
			if (ImGui::BeginCombo("##Scenarios", selectedScenarioDisplayName.c_str()))
			{
				static std::string selectedScenarioName("Stop Scenario");
				for (tScenario scenario : eScenario)
				{
					if (ImGui::Selectable(scenario.DisplayName.c_str(), (scenario.DisplayName == selectedScenarioDisplayName)))
					{
						selectedScenarioDisplayName = scenario.DisplayName;
						selectedScenarioName = scenario.Scenario;

						g_fiber_pool->queue_job([]
							{
								if (selectedScenarioDisplayName == std::string("Stop Scenario"))
									AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
								else
									AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), selectedScenarioName.c_str(), 0, true);
							});
					}
				}
				ImGui::EndCombo();
			}
		}
		
		ImGui::PopItemWidth();
		ImGui::EndChild();
	}	
}

void GUI::PlayerList()
{
	static int selectePlayerId{};

	{
		ImGui::BeginChild("PlayerList", ImVec2(0, 0), true);

		if (*g_pointers->m_is_session_started)
		{
			int i = 1;
			for (tPlayerData data : features::playerData)
			{
				if (data.IsConnected && data.IsValid && !data.playerName.empty())
				{
					if (data.playerId == features::localData.localId)
						ImGui::PushStyleColor(ImGuiCol_Text, yourColor);
					else if (data.IsFriend)
						ImGui::PushStyleColor(ImGuiCol_Text, friendColor);
					else if (data.IsTeam)
						ImGui::PushStyleColor(ImGuiCol_Text, teamColor);
					else
						ImGui::PushStyleColor(ImGuiCol_Text, enemyColor);

					float offset = ImGui::GetCursorPosX() + resizefloat(30.f);
					ImGui::Text("%d. ", i); ImGui::SameLine(offset);
					if (ImGui::Selectable(data.playerName.c_str(), (selectePlayerId == data.playerId)))
						selectePlayerId = data.playerId;

					ImGui::PopStyleColor();

					if (data.IsHost)
					{
						ImGui::SameLine();
						ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(65, 105, 255, 255)), "[Host]");
					}

					if (data.godmode)
					{
						ImGui::SameLine();
						ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 174, 66, 255)), "[God]");
					}

					if (data.IsInInterrior)
					{
						ImGui::SameLine();
						ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(0, 205, 209, 255)), "[Interrior]");
					}

					i++;
				}
			}
		}
		ImGui::EndChild();
	}
	ImGui::NextColumn();
	{
		tPlayerData data = features::playerData[selectePlayerId];
		if (data.IsConnected && data.IsValid)
		{
			ImGui::BeginChild("PlayerInfo", ImVec2(0, 0), true, ImGuiWindowFlags_NoScrollbar); //childHeaderFont->FontSize + ImGui::GetTextLineHeightWithSpacing() * 26 + ImGui::GetStyle().ItemSpacing.y * 4
			ImGui::PushFont(childHeaderFont); ImGui::Text(data.playerName.c_str()); ImGui::PopFont();

			float rescale = resizefloat(0.5);

			ImGui::Image((ImTextureID)Icons.find("host")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Session Host: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%s", data.IsHost ? "Yes" : "No");

			ImGui::Image((ImTextureID)Icons.find("host")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Script Host: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%s", data.IsScriptHost ? "Yes" : "No");

			ImGui::Image((ImTextureID)Icons.find("rockstar")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Rockstar Id: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%lld", data.rockstar_id);

			ImGui::Image((ImTextureID)Icons.find("ip")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "IPv4: "); ImGui::SameLine();
			(data.playerId == features::localData.localId) ? ImGui::Text("Hidden") : ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%d.%d.%d.%d", data.online_ip.m_field1, data.online_ip.m_field2, data.online_ip.m_field3, data.online_ip.m_field4);

			ImGui::Image((ImTextureID)Icons.find("port")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Port: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%hu", data.online_port);

			/*ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Modder: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%s", data.IsModder ? "Yes" : "No");

			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Godmode: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%s", data.godmode ? "Yes" : "No");

			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Friend: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%s", data.IsFriend ? "Yes" : "No");

			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Team: ");
			ImGui::SameLine(); ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%s", data.IsTeam ? "Yes" : "No");*/

			ImGui::Image((ImTextureID)Icons.find("rp")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Level: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%d", data.level);

			ImGui::Image((ImTextureID)Icons.find("kdratio")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "K/D: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%.2f", data.ratio);

			ImGui::Image((ImTextureID)Icons.find("kills")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Kills: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%d", data.kills);

			ImGui::Image((ImTextureID)Icons.find("deaths")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Deaths: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%d", data.deaths);

			ImGui::Image((ImTextureID)Icons.find("wallet")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Wallet: "); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(80));
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%lld$", data.wallet);

			ImGui::Image((ImTextureID)Icons.find("bank")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Bank: "); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(80));
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%lld$", data.totalCash - data.wallet);

			ImGui::Image((ImTextureID)Icons.find("totalmoney")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Total: "); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(80));
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%lld$", data.totalCash);

			ImGui::Image((ImTextureID)Icons.find("alive")->second, ImVec2(30 * rescale, 33 * rescale)); ; ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Alive: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%s", data.alive ? "Yes" : "No");

			ImGui::Image((ImTextureID)Icons.find("health")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Health: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%.0f%hs", 100 * ((data.health - 100.f) / (data.maxHealth - 100.f)), "%");

			ImGui::Image((ImTextureID)Icons.find("armour")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Armor: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%.0f%hs", 100 * (data.armour / data.maxArmour), "%");

			ImGui::Image((ImTextureID)Icons.find("wantedlevel")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Wanted Level: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%d", data.wantedLevel);

			ImGui::Image((ImTextureID)Icons.find("invehicle")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "In Vehicle: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%s", data.IsInVehicle ? "Yes" : "No");

			ImGui::Image((ImTextureID)Icons.find("interior")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "In Interrior: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%s", data.IsInInterrior ? "Yes" : "No");

			ImGui::Image((ImTextureID)Icons.find("speed")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Speed: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%.1f", data.speed);

			ImGui::Image((ImTextureID)Icons.find("distance")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Distance: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%.0f", data.distance);

			ImGui::Image((ImTextureID)Icons.find("coords")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "X: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%.3f", data.position.x);

			ImGui::Image((ImTextureID)Icons.find("coords")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Y: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%.3f", data.position.y);

			ImGui::Image((ImTextureID)Icons.find("coords")->second, ImVec2(30 * rescale, 33 * rescale)); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "Z: "); ImGui::SameLine();
			ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(ImColor(255, 255, 255, 255)), "%.3f", data.position.z);

			ImGui::EndChild();
		}
	}
}

void GUI::Weapon()
{
	static int WeaponTab = 0;

	{
		{
			if (WeaponTab == 0)
				ImGui::PushStyleColor(ImGuiCol_Button, ImGuiCol_WindowBg);
			else
				ImGui::PushStyleColor(ImGuiCol_Button, ImGui::ColorConvertU32ToFloat4(ImColor(0, 0, 0, 255)));
			ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);
			if (ImGui::Button("Aim", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
				WeaponTab = 0;
			ImGui::PopStyleVar();
			ImGui::PopStyleColor();
			ImGui::NewLine();
		}
	

		if (WeaponTab == 0)
		{
			ImGui::BeginChild("WeaponTargets", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 5 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
			ImGui::PushFont(childHeaderFont); ImGui::Text("Targets"); ImGui::PopFont(); ImGui::Separator();
			radioButton("Shoot At Players", &features::bAimbotShootAtPlayers);
			radioButton("Shoot At Ally", &features::bAimbotShootAtAlly);
			radioButton("Shoot At NPCs", &features::bAimbotShootAtNPCs);
			radioButton("Shoot At Cops", &features::bAimbotShootAtCops);
			radioButton("Shoot At Enemies", &features::bAimbotShootAtEnemies);
			ImGui::EndChild();

			ImGui::NewLine();

			ImGui::BeginChild("WeaponAimer", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 5 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
			ImGui::PushFont(childHeaderFont); ImGui::Text("Aimer"); ImGui::PopFont(); ImGui::Separator();
			ImGui::Checkbox("Triggerbot", &features::bWeaponTriggerbot);
			ImGui::Checkbox("Aimbot", &features::bWeaponAimbot);
			ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f)); radioButton("pSilent Aim", &features::bAimbotpSilentAim);
			ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f)); radioButton("Auto Shoot", &features::bAimbotAutoShoot);
			static const char* Hitbox_name = "Head";
			ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f));  if (ImGui::BeginCombo("##hitbox", Hitbox_name, ImGuiComboFlags_NoArrowButton))
			{
				{
					bool is_selected = (features::bAimBotBone == SKEL_Head);
					if (ImGui::Selectable("Head", is_selected))
					{
						Hitbox_name = "Head";
						features::bAimBotBone = SKEL_Head;
					}
					if (is_selected)
						ImGui::SetItemDefaultFocus();
				}

				{
					bool is_selected = (features::bAimBotBone == SKEL_Neck_1);
					if (ImGui::Selectable("Neck", is_selected))
					{
						Hitbox_name = "Neck";
						features::bAimBotBone = SKEL_Neck_1;
					}
					if (is_selected)
						ImGui::SetItemDefaultFocus();
				}

				{
					bool is_selected = (features::bAimBotBone == SKEL_Spine1);
					if (ImGui::Selectable("Spine", is_selected))
					{
						Hitbox_name = "Spine";
						features::bAimBotBone = SKEL_Spine1;
					}
					if (is_selected)
						ImGui::SetItemDefaultFocus();
				}

				{
					bool is_selected = (features::bAimBotBone == SKEL_Pelvis);
					if (ImGui::Selectable("Pelvis", is_selected))
					{
						Hitbox_name = "Pelvis";
						features::bAimBotBone = SKEL_Pelvis;
					}
					if (is_selected)
						ImGui::SetItemDefaultFocus();
				}

				ImGui::EndCombo();
			}
			ImGui::EndChild();

			ImGui::NewLine();

			ImGui::BeginChild("WeaponAssistance", ImVec2(0, 0), true);
			ImGui::PushFont(childHeaderFont); ImGui::Text("Assistance"); ImGui::PopFont(); ImGui::Separator();
			if (ImGui::Checkbox("No Recoil", &features::bWeaponNoRecoil)) features::bWeaponEnableCustomRecoil = false;
			if (ImGui::Checkbox("No Spread", &features::bWeaponNoSpread)) features::bWeaponEnableCustomSpread = false;
			if (ImGui::Checkbox("Instant Reload", &features::bWeaponInstantReload)) features::bWeaponEnableCustomReload = false;
			if (ImGui::Checkbox("Unlimited Range", &features::bWeaponUnlimitedRange)) features::bWeaponEnableCustomRange = false;		
			ImGui::EndChild();
		}
		else
		{
			ImGui::BeginChild("WeaponMods", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 8 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
			ImGui::PushFont(childHeaderFont); ImGui::Text("Mods"); ImGui::PopFont(); ImGui::Separator();
			ImGui::Checkbox("bWeaponDeadlyExplosions", &features::bWeaponDeadlyExplosions);
			ImGui::Checkbox("bWeaponRapidFire", &features::bWeaponRapidFire);
			ImGui::Checkbox("bWeaponInfinityAmmo", &features::bWeaponInfinityAmmo);
			ImGui::Checkbox("bMeleeOneHitKill", &features::bMeleeOneHitKill);
			ImGui::Checkbox("bMeleeMegaKnockback", &features::bMeleeMegaKnockback);
			if (ImGui::Checkbox("bWeaponOneShotKill", &features::bWeaponOneShotKill)) { features::bWeaponEnableCustomBulletDamage = features::bWeaponRubberBullets = false; }
			if (ImGui::Checkbox("bWeaponRubberBullets", &features::bWeaponRubberBullets)) { features::bWeaponOneShotKill = features::bWeaponEnableCustomBulletDamage = false; }
			if (ImGui::Button("Give All Weapons", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
			{
				g_fiber_pool->queue_job([]
					{
						for (Hash weapon : Weapons)
						{
							int maxAmmo;
							if (!WEAPON::GET_MAX_AMMO(features::localData.localPed, weapon, &maxAmmo))
								maxAmmo = 0;

							if (!WEAPON::HAS_PED_GOT_WEAPON(features::localData.localPed, weapon, 0))
								WEAPON::GIVE_WEAPON_TO_PED(features::localData.localPed, weapon, maxAmmo, 0, 0);
						}
					});		
			}
			ImGui::EndChild();


			ImGui::NewLine();

			ImGui::BeginChild("WeaponGuns", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 6 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
			ImGui::PushFont(childHeaderFont); ImGui::Text("Guns"); ImGui::PopFont(); ImGui::Separator();
			ImGui::Checkbox("bWeaponMoneyGun", &features::bWeaponMoneyGun);
			ImGui::Checkbox("bWeaponTeleportGun", &features::bWeaponTeleportGun);
			ImGui::Checkbox("bWeaponGravityGun", &features::bWeaponGravityGun);
			ImGui::Checkbox("bWeaponDeleteGun", &features::bWeaponDeleteGun);
			ImGui::Checkbox("bWeaponVehicleGun", &features::bWeaponVehicleGun);
			ImGui::Checkbox("bWeaponBlockGun", &features::bWeaponBlockGun);


			ImGui::EndChild();

		}
	}
	ImGui::NextColumn();
	{
		{
			if (WeaponTab == 1)
				ImGui::PushStyleColor(ImGuiCol_Button, ImGuiCol_WindowBg);
			else
				ImGui::PushStyleColor(ImGuiCol_Button, ImGui::ColorConvertU32ToFloat4(ImColor(0, 0, 0, 255)));
			ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);
			if (ImGui::Button("Other", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
				WeaponTab = 1;
			ImGui::PopStyleVar();
			ImGui::PopStyleColor();
			ImGui::NewLine();
		}

		if (WeaponTab == 0)
		{
			{
				ImGui::BeginChild("WeaponSettings", ImVec2(0, 0), true);
				ImGui::PushFont(childHeaderFont); ImGui::Text("Settings"); ImGui::PopFont(); ImGui::Separator();

				ImGui::Text("Aimbot Smooth Speed");
				ImGui::Checkbox("##enableSmoothAIm", &features::bAimerEnableSmoothAim); ImGui::SameLine();
				ImGui::SliderFloat("##fAimerSmoothSpeed", &features::fAimerSmoothSpeed, 4.f, 100.f, "%.0f");

				ImGui::Text("Aimbot FOV"); bool active = (features::bWeaponAimbot || features::bWeaponTriggerbot);
				ImGui::Checkbox("##enableFov", &active); ImGui::SameLine();
				ImGui::SliderFloat("##fAimerMaxFov", &features::fAimerMaxFov, 1.f, 1000.f, "%.0f");

				ImGui::Text("Aimbot Max Range"); active = (features::bWeaponAimbot || features::bWeaponTriggerbot);
				ImGui::Checkbox("##enableAimbotRange", &active); ImGui::SameLine();
				ImGui::SliderFloat("##Aimbotrange", &features::fAimerMaxRange, 1.f, 2000.f, "%.0f");

				ImGui::Text("Custom Bullet Range");
				if (ImGui::Checkbox("##enablecustomRange", &features::bWeaponEnableCustomRange)) { features::bWeaponUnlimitedRange = false; }  ImGui::SameLine();
				ImGui::SliderFloat("##range", &features::fWeaponCustomRange, 1.f, 2000.f, "%.0f");

				ImGui::Text("Custom Bullet Damage");
				if (ImGui::Checkbox("##enablecustomdamage", &features::bWeaponEnableCustomBulletDamage)) { features::bWeaponOneShotKill = features::bWeaponRubberBullets = false; }  ImGui::SameLine();
				ImGui::SliderFloat("##damage", &features::fWeaponCustomBulletDamage, 0.0f, 400.f, "%.0f");

				ImGui::Text("Custom Reload Speed");
				if (ImGui::Checkbox("##enablecustomReload", &features::bWeaponEnableCustomReload)) { features::bWeaponInstantReload = false; }  ImGui::SameLine();
				ImGui::SliderFloat("##reload", &features::fWeaponCustomReload, 0.5f, 10.f, "%.1f");	

				ImGui::Text("Custom Recoil");
				if (ImGui::Checkbox("##enablecustomRecoil", &features::bWeaponEnableCustomRecoil)) { features::bWeaponNoRecoil = false; }  ImGui::SameLine();
				ImGui::SliderFloat("##recoilmmultiplier", &features::fWeaponCustomRecoil, 0.0f, 5.f, "%.1f");

				ImGui::Text("Custom Spread");
				if (ImGui::Checkbox("##enablecustomSpread", &features::bWeaponEnableCustomSpread)) { features::bWeaponNoSpread = false; }  ImGui::SameLine();
				ImGui::SliderFloat("##spreadmmultiplier", &features::fWeaponCustomSpread, 0.0f, 5.f, "%.1f");

				ImGui::Text("Force on Ped");
				ImGui::Checkbox("##forceOnPed", &features::bWeaponForceOnPed);  ImGui::SameLine();
				ImGui::SliderFloat("##forceOnPedSlider", &features::fWeaponForceOnPed, 1.0f, 1000.f, "%.0f");

				ImGui::Text("Force on Vehicle");
				ImGui::Checkbox("##forceOnVehicle", &features::bWeaponForceOnVehicle);  ImGui::SameLine();
				ImGui::SliderFloat("##forceOnVehicleSlider", &features::fWeaponForceOnVehicle, 1.0f, 1000.f, "%.0f");

				ImGui::Text("Force on Heli");
				ImGui::Checkbox("##forceOnHeli", &features::bWeaponForceOnHeli);  ImGui::SameLine();
				ImGui::SliderFloat("##forceOnHeliSlider", &features::fWeaponForceOnHeli, 1.0f, 1000.f, "%.0f");

				ImGui::EndChild();
			}
		
		}
		else
		{
			ImGui::BeginChild("WeaponImpacts", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 11 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
			ImGui::PushFont(childHeaderFont); ImGui::Text("Impacts"); ImGui::PopFont(); ImGui::Separator();
			ImGui::Checkbox("bWeaponExplosiveMelee", &features::bWeaponExplosiveMelee);
			ImGui::Checkbox("bWeaponExplosiveAmmo", &features::bWeaponExplosiveAmmo);
			ImGui::Checkbox("bWeaponFireAmmo", &features::bWeaponFireAmmo);
			ImGui::Checkbox("bWeaponFlameImpact", &features::bWeaponFlameImpact);
			ImGui::Checkbox("bWeaponMolotovImpact", &features::bWeaponMolotovImpact);
			ImGui::Checkbox("bWeaponFlareImpact", &features::bWeaponFlareImpact);
			ImGui::Checkbox("bWeaponSmokeImpact", &features::bWeaponSmokeImpact);
			ImGui::Checkbox("bWeaponFireWorkImpact", &features::bWeaponFireWorkImpact);
			ImGui::Checkbox("bWeaponGrenadeImpact", &features::bWeaponGrenadeImpact);
			ImGui::Checkbox("bWeaponRocketImpact", &features::bWeaponRocketImpact);
			ImGui::Checkbox("bWeaponTankShellImpact", &features::bWeaponTankShellImpact);
			ImGui::EndChild();
		}
	}
}

void GUI::Visuals()
{
	ImGui::PushStyleVar(ImGuiStyleVar_SelectableTextAlign, ImVec2());
	{
		ImGui::BeginChild("ESP", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 9 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushFont(childHeaderFont); ImGui::Text("ESP"); ImGui::PopFont(); ImGui::Separator();
		ImGui::Checkbox("2D Boxes", &features::ESP2DBoxes);
		ImGui::Checkbox("3D Boxes", &features::ESP3DBoxes);
		ImGui::Checkbox("Skeleton", &features::ESPSkeleton);	
		ImGui::Checkbox("Health bar", &features::ESPHealthbar);
		ImGui::Checkbox("Armour bar", &features::ESPArmorbar);	
		ImGui::Checkbox("Name", &features::ESPName);
		ImGui::Checkbox("Distance", &features::ESPDistance);
		ImGui::Checkbox("Rotation", &features::ESPRotation);
		ImGui::Checkbox("Tracers", &features::ESPTracers);
		ImGui::EndChild();

		ImGui::NewLine();

		ImGui::BeginChild("HUD", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 7 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushFont(childHeaderFont); ImGui::Text("HUD"); ImGui::PopFont(); ImGui::Separator();
		ImGui::Checkbox("Hide HUD & Radar", &features::bMiscDisableHud);
		ImGui::Checkbox("Crosshair", &features::bMiscCrosshair);
		ImGui::Checkbox("Screen Filter", &enableScreenFilter);
		ImGui::Checkbox("FPS", &features::drawFPS);
		ImGui::Checkbox("System Time", &features::drawCurrentTime);
		ImGui::Checkbox("Watermark", &features::drawWatermark);	
		ImGui::Checkbox("Cherax Header", &features::drawHeader);
		ImGui::EndChild();

	}
	ImGui::NextColumn();
	{
		
		ImGui::BeginChild("VisualTargets", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 8 + ImGui::GetStyle().ItemSpacing.y*5), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushFont(childHeaderFont); ImGui::Text("Targets"); ImGui::PopFont(); ImGui::Separator();
		radioButton("On Enemies", &features::ESPonEnemies);
		radioButton("On Team", &features::ESPonTeam);
		radioButton("On Friends", &features::ESPonFriends);
		radioButton("On NPCs", &features::ESPonNPCs);
		radioButton("On Cops", &features::ESPonCops);
		radioButton("On You", &features::ESPonYou);
		ImGui::PushItemWidth(ImGui::GetContentRegionAvailWidth());
		ImGui::SliderInt("Player Range", &features::ESPRange, 100, 10000, "Player %d");
		ImGui::SliderInt("NPC Range", &features::ESPPedRange, 10, 1000, "NPC %d");
		ImGui::PopItemWidth();
		ImGui::EndChild();

		ImGui::NewLine();

		ImGui::BeginChild("VisualColors", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 8 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushFont(childHeaderFont); ImGui::Text("Colors"); ImGui::PopFont(); ImGui::Separator();
		ImGui::ColorEdit4("##Enemy", (float*)&enemyColor, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::Text("Enemy");
		ImGui::ColorEdit4("##Team", (float*)&teamColor, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::Text("Team");
		ImGui::ColorEdit4("##Friend", (float*)&friendColor, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::Text("Friend");
		ImGui::ColorEdit4("##Npcs", (float*)&NpcColor, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::Text("Npcs");
		ImGui::ColorEdit4("##Cops", (float*)&CopColor, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::Text("Cops");
		ImGui::ColorEdit4("##You", (float*)&yourColor, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::Text("You");
		ImGui::ColorEdit4("##crosshair", (float*)&crosshairColor, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::Text("Crosshair");
		ImGui::ColorEdit4("##screenFilter", (float*)&screenFilter, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::Text("Screen Filter");
		ImGui::EndChild();
	}
	ImGui::PopStyleVar();
}

void GUI::Spawner()
{
	static rage::joaat_t hash{};
	static std::string selected_name{};
	static std::string hovered_name{};
	bool HoveredThisFrame{};

	{
		ImGui::BeginChild("SpawnOptions", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 9 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushFont(childHeaderFont); ImGui::Text("Spawn Options"); ImGui::PopFont(); ImGui::Separator();
		ImGui::Checkbox("Preview Vehicle", &features::bPreviewVehicle);
		ImGui::Checkbox("Despawn Bypass", &features::bvehicleDespawnBypass);
		ImGui::Checkbox("Delete Old", &features::bSpawnDeleteOld);
		ImGui::Checkbox("In Vehicle", &features::bSpawnInVehicle);
		ImGui::Checkbox("With Car God Mode", &features::bSpawnWithCarGodMode);
		ImGui::Checkbox("With Engine On", &features::bSpawnWithEngineOn);
		ImGui::Checkbox("With Max Upgrades", &features::bSpawnWithMaxUpgrades);
		ImGui::Checkbox("With Effect", &features::bSpawnWithEffect);
		ImGui::Checkbox("Clean Vehicle", &features::bSpawnCleanVehicle);
		//ImGui::Checkbox("bSpawnClearArea", &features::bSpawnClearArea);
		ImGui::EndChild();

		ImGui::NewLine();
		{
			ImGui::BeginChild("XMLVehicles", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 4 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
			ImGui::PushFont(childHeaderFont); ImGui::Text("XML-Vehicles"); ImGui::PopFont(); ImGui::Separator();

			static char VehicleFileName[32];
			ImGui::PushItemWidth(ImGui::GetContentRegionAvailWidth());
			ImGui::InputTextWithHint("##vehiclesafename", "File Name", VehicleFileName, 32);
			ImGui::PopItemWidth();

			if (ImGui::Button("Save Current Vehicle", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
			{
				if (features::localData.IsInVehicle)
				{
					if (!std::string(VehicleFileName).empty())
					{
						//g_vehicles.allocateAttachments(&g_vehicles.currVeh.attachments, features::localData.vehicle);
						XML::save_current_vehicle(VehicleFileName);
						XML::refreshXMLFiles();
					}
					else
					{
						g_fiber_pool->queue_job([]
							{
								features::notifyAboveMap("Enter Any Name", FALSE);
							});
					}
				}
				else
				{
					g_fiber_pool->queue_job([]
						{
							features::notifyAboveMap("Enter Any Vehicle", FALSE);
						});
				}
			}

			if (ImGui::Button("Refresh Files", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
			{
				XML::refreshXMLFiles();
			}

			if (ImGui::Button("Delete File", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
			{
				XML::delete_xml_file(g_vehicles.selectedXmlFile);
				XML::refreshXMLFiles();
			}
			ImGui::EndChild();
		}
		ImGui::NewLine();
		{
			if (ImGui::Button("Spawn Vehicle", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
			{
				g_fiber_pool->queue_job([]
					{
						if (g_gui.xmlSpawnerTabActive)
						{
							std::string savepath = (std::string(getenv("APPDATA")) + "\\Cherax\\Vehicles\\" + g_vehicles.selectedXmlFile + ".xml");
							if (exists(savepath) && !g_vehicles.selectedXmlFile.empty())
							{
								VehicleData data = XML::load_vehicle(savepath);
								if (g_vehicles.spawnCustomVehicle(data))
								{
									// features::notifyAboveMap("Successfully Spawned", FALSE);
								}
							}
							else
							{
								features::notifyAboveMap("No File Selected", FALSE);
							}
						}
						else
						{
							if (STREAMING::IS_MODEL_VALID(hash))
								features::spawnVehicle(hash);
							else
							{
								features::notifyAboveMap("No Vehicle Selected", FALSE);
							}
						}
					});
			}
		}
	}

	ImGui::NextColumn();
	{
		ImGui::BeginChild("Vehicles", ImVec2(), true);
		ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
		if (ImGui::BeginTabBar("Vehicles", tab_bar_flags))
		{
			if (ImGui::BeginTabItem("Normal"))
			{		
				xmlSpawnerTabActive = false;

				for (VehicleClass vehClass : g_vehicles.classes)
				{
					if (ImGui::TreeNode(vehClass.className.c_str()))
					{
						for (VehiclePack vehPack : vehClass.vehicles)
						{
							if (ImGui::Selectable((vehPack.labelText + "##" + std::to_string(vehPack.hash)).c_str(), (hash == vehPack.hash)))
							{
								hash = vehPack.hash;
								selected_name = vehPack.name;
								features::lastSelectedVehicleHash = vehPack.hash;
							}

							if (ImGui::IsItemHovered())
							{
								HoveredThisFrame = true;
								hovered_name = vehPack.name;
							}

						}
						ImGui::TreePop();
						ImGui::Separator();
					}
				}
				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Custom"))
			{
				xmlSpawnerTabActive = false;

				if (ImGui::TreeNode("Funny Vehicles"))
				{			
					if (ImGui::TreeNode("Kurumas"))
					{
						if (ImGui::Selectable("EnturumaXF"))
						{
							g_fiber_pool->queue_job([]
								{
									g_funnyVehicles.EnturumaXF();
								});
						}

						if (ImGui::Selectable("Adderuma"))
						{
							g_fiber_pool->queue_job([]
								{
									g_funnyVehicles.Adderuma();
								});
						}

						if (ImGui::Selectable("Zentornuma"))
						{
							g_fiber_pool->queue_job([]
								{
									g_funnyVehicles.Zentornuma();
								});
						}

						if (ImGui::Selectable("TurismoRuma"))
						{
							g_fiber_pool->queue_job([]
								{
									g_funnyVehicles.TurismoRuma();
								});
						}

						if (ImGui::Selectable("Osirisuma"))
						{
							g_fiber_pool->queue_job([]
								{
									g_funnyVehicles.Osirisuma();
								});
						}

						if (ImGui::Selectable("T20uma"))
						{
							g_fiber_pool->queue_job([]
								{
									g_funnyVehicles.T20uma();
								});
						}

						if (ImGui::Selectable("Feltzeruma"))
						{
							g_fiber_pool->queue_job([]
								{
									g_funnyVehicles.Feltzeruma();
								});
						}

						if (ImGui::Selectable("Banshuma"))
						{
							g_fiber_pool->queue_job([]
								{
									g_funnyVehicles.Banshuma();
								});
						}

						if (ImGui::Selectable("Nightshuma"))
						{
							g_fiber_pool->queue_job([]
								{
									g_funnyVehicles.Nightshuma();
								});
						}

						if (ImGui::Selectable("Bulletuma"))
						{
							g_fiber_pool->queue_job([]
								{
									g_funnyVehicles.Bulletuma();
								});
						}

						ImGui::TreePop();
						ImGui::Separator();
					}

					if (ImGui::TreeNode("Monster Trucks"))
					{
						if (ImGui::Selectable("Boat Chassis"))
						{
							g_fiber_pool->queue_job([]
								{
									g_funnyVehicles.MonsterTruck_BoatChassis();
								});
						}

						if (ImGui::Selectable("Tank Chassis"))
						{
							g_fiber_pool->queue_job([]
								{
									g_funnyVehicles.MonsterTruck_TankChassis();
								});
						}

						if (ImGui::Selectable("Helicopter Chassis"))
						{
							g_fiber_pool->queue_job([]
								{
									g_funnyVehicles.MonsterTruck_HelicopterChassis();
								});
						}

						if (ImGui::Selectable("RV Chassis"))
						{
							g_fiber_pool->queue_job([]
								{
									g_funnyVehicles.MonsterTruck_RVChassis();
								});
						}

						if (ImGui::Selectable("Fighter Jet Chassis"))
						{
							g_fiber_pool->queue_job([]
								{
									g_funnyVehicles.MonsterTruck_FighterJetChassis();
								});
						}

						if (ImGui::Selectable("Monster Train Truck"))
						{
							g_fiber_pool->queue_job([]
								{
									g_funnyVehicles.MonsterTrainTruck();
								});
						}

						ImGui::TreePop();
						ImGui::Separator();
					}

					if (ImGui::Selectable("Go Kart"))
					{
						g_fiber_pool->queue_job([]
							{
								g_funnyVehicles.GoKart();
							});
					}

					if (ImGui::Selectable("Weed Wheels Bike"))
					{
						g_fiber_pool->queue_job([]
							{
								g_funnyVehicles.WeedWheelsBike();
							});
					}

					if (ImGui::Selectable("Yacht Air ship"))
					{
						g_fiber_pool->queue_job([]
							{
								g_funnyVehicles.YachtAirship();
							});
					}

					if (ImGui::Selectable("Yacht Airship With Fans"))
					{
						g_fiber_pool->queue_job([]
							{
								g_funnyVehicles.YachtAirshipWithFans();
							});
					}

					if (ImGui::Selectable("Black Noisy UFO"))
					{
						g_fiber_pool->queue_job([]
							{
								g_funnyVehicles.BlackNoisyUFO();
							});
					}

					if (ImGui::Selectable("Toy Car"))
					{
						g_fiber_pool->queue_job([]
							{
								g_funnyVehicles.ToyCar();
							});
					}

					if (ImGui::Selectable("LandJetski"))
					{
						g_fiber_pool->queue_job([]
							{
								g_funnyVehicles.LandJetski();
							});
					}

					if (ImGui::Selectable("ChinoODeath"))
					{
						g_fiber_pool->queue_job([]
							{
								g_funnyVehicles.ChinoODeath();
							});
					}

					if (ImGui::Selectable("RV Building"))
					{
						g_fiber_pool->queue_job([]
							{
								g_funnyVehicles.RVBuilding();
							});
					}

					if (ImGui::Selectable("Fib Building"))
					{
						g_fiber_pool->queue_job([]
							{
								g_funnyVehicles.FibBuilding();
							});
					}


					ImGui::TreePop();
					ImGui::Separator();
				}

				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Saved"))
			{
				xmlSpawnerTabActive = true;

				for (std::string str : XML::xmlVehicles)
				{
					if (ImGui::Selectable(str.c_str(), (str == g_vehicles.selectedXmlFile)))
						g_vehicles.selectedXmlFile = str;
				}
				
				ImGui::EndTabItem();
			}

			ImGui::EndTabBar();
		}
		ImGui::EndChild();
	}

	{
		if (features::bPreviewVehicle)
		{
			static std::string current;
			static ID3D11ShaderResourceView* preview = NULL;
			static HRESULT res = S_FALSE;

			if (HoveredThisFrame)
			{
				if (current != hovered_name)
				{
					current = hovered_name;
					res = D3DX11CreateShaderResourceViewFromFile(g_renderer->m_d3d_device.Get(), (std::string(getenv("APPDATA")) + "\\Cherax\\Assets\\Vehicle Images\\" + current + ".png").c_str(), NULL, NULL, &preview, NULL);
				}
			}
			else
			{
				if (current != selected_name)
				{
					current = selected_name;
					res = D3DX11CreateShaderResourceViewFromFile(g_renderer->m_d3d_device.Get(), (std::string(getenv("APPDATA")) + "\\Cherax\\Assets\\Vehicle Images\\" + current + ".png").c_str(), NULL, NULL, &preview, NULL);
				}
			}

			ImGui::SetNextWindowPos(ImVec2(ImGui::GetWindowPos().x + ImGui::GetWindowSize().x, ImGui::GetWindowPos().y));
			if (res != S_OK)
			{
				ImGui::PushStyleColor(ImGuiCol_WindowBg, ImGui::ColorConvertU32ToFloat4(ImColor(105, 105, 105, 0)));
				ImGui::PushStyleColor(ImGuiCol_Border, ImGui::ColorConvertU32ToFloat4(ImColor(105, 105, 105, 0)));
			}
			if (ImGui::Begin("##prewviewVehicle", nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoMove))
			{
				if (res == S_OK)
					ImGui::Image((ImTextureID)preview, resizeVec(ImVec2(350, 197)));
				ImGui::End();
			}
			if (res != S_OK)
			{
				ImGui::PopStyleColor();
				ImGui::PopStyleColor();
			}

		}
	}
}

void GUI::VehicleMenu()
{
	{
		ImGui::BeginChild("VehicleOptions", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 15 + ImGui::GetStyle().ItemSpacing.y * 5 + ImGui::GetTextLineHeightWithSpacing() * 3), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushFont(childHeaderFont); ImGui::Text("Options"); ImGui::PopFont(); ImGui::Separator();
		ImGui::Checkbox("Vehicle God Mode", &features::bVehicleGodMode);
		ImGui::Checkbox("Bullet Proof Tyres", &features::bVehicleBulletProoftyres);
		ImGui::Checkbox("Horn Boost", &features::bHornBoost);
		if (ImGui::Checkbox("Invisible", &features::bVehicleInvisible))
		{
			g_fiber_pool->queue_job([]
				{
					if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
					{
						Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
						ENTITY::SET_ENTITY_VISIBLE(veh, !features::bVehicleInvisible, 0);
						NETWORK::_NETWORK_SET_ENTITY_VISIBLE_TO_NETWORK(veh, !features::bVehicleInvisible);
					}
				});
		}
		ImGui::Checkbox("Engine Always On", &features::bEngineAlwaysOn);
		ImGui::Checkbox("Auto Repair", &features::bAutoRepairCar);
		ImGui::Checkbox("Police Mode", &features::bPolicemode);
		ImGui::Checkbox("Drive On Water", &features::bDriveOnWater);
		ImGui::Checkbox("Stick To Ground", &features::bSticktoground);

		ImGui::NewLine();

		ImGui::Text("Wheels PTFX");
		ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f));
		if (ImGui::BeginCombo("##ptfx", features::VehiclePTFXDisplayName.c_str()))
		{
			for (tPTFX ptfx : ePTFX)
			{
				if (ImGui::Selectable(ptfx.DisplayName.c_str(), (ptfx.DisplayName == features::VehiclePTFXDisplayName)))
				{
					features::VehiclePTFXDisplayName = ptfx.DisplayName;
					features::VehiclePTFXName = ptfx.PTFXName;
					features::VehiclePTFXCall = ptfx.PTFXCall;
				}
			}
			ImGui::EndCombo();
		}
		//ImGui::Checkbox("bGroupUp", &features::bGroupUp);
		
		ImGui::NewLine();
		
		if (ImGui::Button("Repair", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
		{
			g_fiber_pool->queue_job([]
				{
					features::repairCar(false);
				});
		}
		if (ImGui::Button("Clean", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
		{
			g_fiber_pool->queue_job([]
				{
					if (features::localData.IsInVehicle)
						VEHICLE::SET_VEHICLE_DIRT_LEVEL(features::localData.vehicle, 0.f);
				});
		}
		if (ImGui::Button("Flip Up", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
		{
			g_fiber_pool->queue_job([]
				{
					features::flipup();
				});
		}
		if (ImGui::Button("Instant Stop", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
		{
			g_fiber_pool->queue_job([]
				{
					features::instantbreak();
				});
		}
		if (ImGui::Button("Max Upgrades", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
		{
			g_fiber_pool->queue_job([]
				{
					if (features::localData.IsInVehicle)
					{
						VEHICLE::SET_VEHICLE_MOD_KIT(features::localData.vehicle, 0);
						for (int i = 0; i < 49; i++)
						{
							if (i > 16 && i < 23)
								continue;

							VEHICLE::SET_VEHICLE_MOD(features::localData.vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(features::localData.vehicle, i) - 1, false);
						}
					}
				});
		}
		ImGui::EndChild();
	}
	ImGui::NextColumn();	
	{
		ImGui::PushStyleVar(ImGuiStyleVar_SelectableTextAlign, ImVec2());
		ImGui::BeginChild("LSCChild", ImVec2(0, 0), true);
		ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
		if (ImGui::BeginTabBar("LSC", tab_bar_flags))
		{
			if (ImGui::BeginTabItem("Parts"))
			{
				for (int i = 0; i < 49; i++)
				{
					if (!g_vehicles.currVeh.mods[i].name.empty())
					{
						if (i > 16 && i < 23)
							continue;

						if (g_vehicles.currVeh.mods[i].name == std::to_string(i))
							continue;

						if (i == 23)
						{
							ImGui::Text("Wheel Type");
							ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f));
							ImGui::PushItemWidth(ImGui::GetContentRegionAvailWidth());
							if (ImGui::BeginCombo("##WheelTypes", g_vehicles.currVeh.other.wheelTypeName.c_str()))
							{													
								for (tWheelTypes type : eWheelTypes)
								{
									if ((type.wheelType == 6) && !g_vehicles.currVeh.isBike)
										continue;

									if (ImGui::Selectable(type.displayName.c_str(), (g_vehicles.currVeh.other.wheeltype == type.wheelType)))
									{
										features::bFlashParts = false;	
										g_vehicles.currVeh.lastSelectedModNames.clear();
										g_vehicles.currVeh.other.wheeltype = type.wheelType;
										g_vehicles.currVeh.mods[23].index = -1;
										if (g_vehicles.currVeh.isBike)
											g_vehicles.currVeh.mods[24].index = -1;
										g_vehicles.writeData = features::localData.IsInVehicle;
									}
								}						
								ImGui::EndCombo();
								ImGui::PopItemWidth();
							}
						}

						ImGui::Text(g_vehicles.currVeh.mods[i].name.c_str());
						ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f));
						ImGui::PushItemWidth(ImGui::GetContentRegionAvailWidth());
						if (ImGui::BeginCombo(("##label" + g_vehicles.currVeh.mods[i].name).c_str(), g_vehicles.currVeh.mods[i].itemName.c_str()))
						{
							g_vehicles.currVeh.lastSelectedCategory = i;
							static int lastCategory = -1;
							if ((lastCategory != g_vehicles.currVeh.lastSelectedCategory) || g_vehicles.currVeh.lastSelectedModNames.empty())
							{
								lastCategory = g_vehicles.currVeh.lastSelectedCategory;
								g_vehicles.currVeh.isRefreshed = false;
							}				

							if (g_vehicles.currVeh.isRefreshed)
							{
								int maxcount = (g_vehicles.currVeh.mods[i].options - 1);
								for (int j = -1; j <= maxcount; j++)
								{
									if (ImGui::Selectable(g_vehicles.currVeh.lastSelectedModNames.at(j + 1).c_str(), (g_vehicles.currVeh.mods[i].index == j)))
									{
										features::bFlashParts = false;
										if (i == 48)
											features::bFlashLivery = false;
									
										g_vehicles.currVeh.mods[i].index = j;
										if ((i == 23) && g_vehicles.currVeh.isBike)
											g_vehicles.currVeh.mods[24].index = j;

										g_vehicles.writeData = features::localData.IsInVehicle;
									}
								}
							}
							ImGui::EndCombo();
							ImGui::PopItemWidth();
						}
									
					}	
				}

				ImGui::Text("Plate Type");
				ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f));
				ImGui::PushItemWidth(ImGui::GetContentRegionAvailWidth());
				if (ImGui::BeginCombo("##textplate", g_vehicles.currVeh.other.plateTextIndexName.c_str()))
				{
					int i = 0;
					for (std::string str : PLATE_NAMES)
					{		
						if (ImGui::Selectable(str.c_str(), (g_vehicles.currVeh.other.plateTextIndex == i)))
						{
							g_vehicles.currVeh.other.plateTextIndex = i;
							g_vehicles.writeData = features::localData.IsInVehicle;
						}
						i++;
					}
					ImGui::EndCombo();
					ImGui::PopItemWidth();
				}

				ImGui::Text("Plate Text");
				ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f));
				ImGui::PushItemWidth(ImGui::GetContentRegionAvailWidth());
				static char buf[9];
				strcpy_s(buf, 9, g_vehicles.currVeh.other.plateText.c_str());
				if (ImGui::InputText("##platetext", buf, 9))
				{
					g_vehicles.currVeh.other.plateText = buf;
					g_vehicles.writeData = features::localData.IsInVehicle;
				}
					
				ImGui::PopItemWidth();

				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Colours"))
			{
				ImVec4 bufVec;
				
				ImGui::Text("Primary Paint");
				ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f));
				if (ImGui::BeginCombo("##primarypaint", g_vehicles.currVeh.colours.primaryName.c_str()))
				{
					for (tPaintTypes paint : ePaintTypes)
					{
						if (paint.paintType == 2)
							continue;

						if (ImGui::BeginMenu(paint.displayName.c_str()))
						{
							for (PaintColour col : paint.colors)
							{
								if (ImGui::Selectable(col.name.c_str(), (g_vehicles.currVeh.colours.primary == col.mainValue)))
								{
									features::bFlashVehicle = false;
									features::bRainbowVehicle = false;

									g_vehicles.currVeh.colours.primary = col.mainValue;
									g_vehicles.currVeh.colours.primaryName = col.name;
									g_vehicles.currVeh.colours.pearlescent = col.pearlAddition;
									g_vehicles.currVeh.colours.primaryPaintTypeName = paint.displayName;
									g_vehicles.currVeh.colours.primaryPaintType = paint.paintType;
									g_vehicles.currVeh.colours.isPrimaryCustom = false;
									g_vehicles.writeData = features::localData.IsInVehicle;
								}
							}
							ImGui::EndMenu();
						}
					}
					ImGui::EndCombo();
				}

				ImGui::Text("Secondary Paint");
				ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f));
				if (ImGui::BeginCombo("##secondarypaint", g_vehicles.currVeh.colours.secondaryName.c_str()))
				{
					for (tPaintTypes paint : ePaintTypes)
					{
						if (paint.paintType == 2)
							continue;

						if (ImGui::BeginMenu(paint.displayName.c_str()))
						{
							for (PaintColour col : paint.colors)
							{
								if (ImGui::Selectable(col.name.c_str(), (g_vehicles.currVeh.colours.secondary == col.mainValue)))
								{
									features::bFlashVehicle = false;
									features::bRainbowVehicle = false;

									g_vehicles.currVeh.colours.secondary = col.mainValue;
									g_vehicles.currVeh.colours.secondaryName = col.name;
									g_vehicles.currVeh.colours.pearlescent = col.pearlAddition;

									g_vehicles.currVeh.colours.secondaryPaintTypeName = paint.displayName;
									g_vehicles.currVeh.colours.secondaryPaintType = paint.paintType;
									g_vehicles.currVeh.colours.isSecondaryCustom = false;
									g_vehicles.writeData = features::localData.IsInVehicle;
								}
							}
							ImGui::EndMenu();
						}
					}
					ImGui::EndCombo();
				}				

				ImGui::Text("Pearlescent");
				ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f));
				if (ImGui::BeginCombo("##pearlescent", g_vehicles.currVeh.colours.pearlescentName.c_str()))
				{
					for (PaintColour col : ePaintTypes[2].colors)
					{
						if (ImGui::Selectable(col.name.c_str(), (g_vehicles.currVeh.colours.pearlescent == col.pearlAddition)))
						{
							g_vehicles.currVeh.colours.pearlescent = col.pearlAddition;
							g_vehicles.writeData = features::localData.IsInVehicle;
						}
					}
					ImGui::EndCombo();
				}

				ImGui::Text("Headlights", g_vehicles.currVeh.colours.headlights);
				ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f));
				if (ImGui::BeginCombo("##Headlights", g_vehicles.currVeh.colours.headlightsName.c_str()))
				{
					for (PaintColour col : PAINTS_Headlights)
					{
						if (ImGui::Selectable(col.name.c_str(), (g_vehicles.currVeh.colours.headlights == col.mainValue)))
						{
							features::bFlashHeadlights = false;
							g_vehicles.currVeh.togglemods.xenonHeadLights = true;
							g_vehicles.currVeh.colours.headlights = col.mainValue;
							g_vehicles.writeData = features::localData.IsInVehicle;
						}		
					}

					ImGui::EndCombo();
				}

				ImGui::Text("Wheels");
				ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f));
				if (ImGui::BeginCombo("##wheels", g_vehicles.currVeh.colours.wheelName.c_str()))
				{
					for (PaintColour col : PAINTS_WHEELS)
					{
						if (ImGui::Selectable(col.name.c_str(), (g_vehicles.currVeh.colours.wheels == col.mainValue)))
						{
							g_vehicles.currVeh.colours.wheelName = col.name;
							g_vehicles.currVeh.colours.wheels = col.mainValue;
							g_vehicles.writeData = features::localData.IsInVehicle;
						}
					}
					ImGui::EndCombo();
				}

				ImGui::Text("Window Tint");
				ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f));
				if (ImGui::BeginCombo("##windowTint", g_vehicles.currVeh.colours.windowTintName.c_str()))
				{
					for (PaintColour col : PAINTS_WindowTints)
					{
						if (ImGui::Selectable(col.name.c_str(), (g_vehicles.currVeh.colours.windowTint == col.mainValue)))
						{
							g_vehicles.currVeh.colours.windowTintName = col.name;
							g_vehicles.currVeh.colours.windowTint = col.mainValue;
							g_vehicles.writeData = features::localData.IsInVehicle;
						}
					}
					ImGui::EndCombo();
				}

				ImGui::NewLine();

				{
					bufVec = ImGui::ColorConvertU32ToFloat4(ImColor(g_vehicles.currVeh.colours.customPrimary.R, g_vehicles.currVeh.colours.customPrimary.G, g_vehicles.currVeh.colours.customPrimary.B, 255));
					float col[4] = { bufVec.x, bufVec.y, bufVec.z, bufVec.w };
					if (ImGui::ColorEdit3("##Custom Primary", col, ImGuiColorEditFlags_NoInputs))
					{
						features::bFlashVehicle = false;
						features::bRainbowVehicle = false;

						g_vehicles.currVeh.colours.isPrimaryCustom = true;
						RGBA temp = DWORD2RGBA(ImGui::ColorConvertFloat4ToU32(ImVec4(col[0], col[1], col[2], 1.0f)));
						g_vehicles.currVeh.colours.customPrimary.R = temp.R;
						g_vehicles.currVeh.colours.customPrimary.G = temp.G;
						g_vehicles.currVeh.colours.customPrimary.B = temp.B;
						g_vehicles.writeData = features::localData.IsInVehicle;
					}
					ImGui::SameLine(); ImGui::Text("Custom Primary");
				}
			
				{
					bufVec = ImGui::ColorConvertU32ToFloat4(ImColor(g_vehicles.currVeh.colours.customSecondary.R, g_vehicles.currVeh.colours.customSecondary.G, g_vehicles.currVeh.colours.customSecondary.B, 255));
					float col[4] = { bufVec.x, bufVec.y, bufVec.z, bufVec.w };
					if (ImGui::ColorEdit3("##Custom Secondary", col, ImGuiColorEditFlags_NoInputs))
					{
						features::bFlashVehicle = false;
						features::bRainbowVehicle = false;

						g_vehicles.currVeh.colours.isSecondaryCustom = true;
						RGBA temp = DWORD2RGBA(ImGui::ColorConvertFloat4ToU32(ImVec4(col[0], col[1], col[2], 1.0f)));
						g_vehicles.currVeh.colours.customSecondary.R = temp.R;
						g_vehicles.currVeh.colours.customSecondary.G = temp.G;
						g_vehicles.currVeh.colours.customSecondary.B = temp.B;
						g_vehicles.writeData = features::localData.IsInVehicle;
					}
					ImGui::SameLine(); ImGui::Text("Custom Secondary");						
				}

				{
					bufVec = ImGui::ColorConvertU32ToFloat4(ImColor(g_vehicles.currVeh.colours.neonLights.R, g_vehicles.currVeh.colours.neonLights.G, g_vehicles.currVeh.colours.neonLights.B, 255));
					float col[4] = { bufVec.x, bufVec.y, bufVec.z, bufVec.w };
					if (ImGui::ColorEdit3("##neonkits", col, ImGuiColorEditFlags_NoInputs))
					{
						features::bRainbowNeonKits = false;
						features::bFlashNeonKits = false;

						g_vehicles.currVeh.colours.isSecondaryCustom = true;
						RGBA temp = DWORD2RGBA(ImGui::ColorConvertFloat4ToU32(ImVec4(col[0], col[1], col[2], 1.0f)));
						g_vehicles.currVeh.colours.neonLights.R = temp.R;
						g_vehicles.currVeh.colours.neonLights.G = temp.G;
						g_vehicles.currVeh.colours.neonLights.B = temp.B;
						g_vehicles.writeData = features::localData.IsInVehicle;
					}
					ImGui::SameLine(); ImGui::Text("Neon Kits");
				}

				{
					bufVec = ImGui::ColorConvertU32ToFloat4(ImColor(g_vehicles.currVeh.colours.tyreSmoke.R, g_vehicles.currVeh.colours.tyreSmoke.G, g_vehicles.currVeh.colours.tyreSmoke.B, 255));
					float col[4] = { bufVec.x, bufVec.y, bufVec.z, bufVec.w };
					if (ImGui::ColorEdit3("##tyresmoke", col, ImGuiColorEditFlags_NoInputs))
					{
						features::bRainbowTyresmoke = false;
						features::bFlashTyresmoke = false;
		
						g_vehicles.currVeh.colours.isSecondaryCustom = true;
						RGBA temp = DWORD2RGBA(ImGui::ColorConvertFloat4ToU32(ImVec4(col[0], col[1], col[2], 1.0f)));
						g_vehicles.currVeh.colours.tyreSmoke.R = temp.R;
						g_vehicles.currVeh.colours.tyreSmoke.G = temp.G;
						g_vehicles.currVeh.colours.tyreSmoke.B = temp.B;
						g_vehicles.writeData = features::localData.IsInVehicle;
					}
					ImGui::SameLine(); ImGui::Text("Tyre Smoke");
				}
				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Miscs"))
			{
				if (ImGui::Checkbox("Turo", &g_vehicles.currVeh.togglemods.turbo))
					g_vehicles.writeData = features::localData.IsInVehicle;
				if (ImGui::Checkbox("Tyre Smoke", &g_vehicles.currVeh.togglemods.tyreSmoke))
					g_vehicles.writeData = features::localData.IsInVehicle;
				if (ImGui::Checkbox("Xenon Headlights", &g_vehicles.currVeh.togglemods.xenonHeadLights))
					g_vehicles.writeData = features::localData.IsInVehicle;

				ImGui::NewLine();

				if (ImGui::Checkbox("Neon Lights Left", &g_vehicles.currVeh.togglemods.neonLights[0]))
					g_vehicles.writeData = features::localData.IsInVehicle;
				if (ImGui::Checkbox("Neon Lights Right", &g_vehicles.currVeh.togglemods.neonLights[1]))
					g_vehicles.writeData = features::localData.IsInVehicle;
				if (ImGui::Checkbox("Neon Lights Front", &g_vehicles.currVeh.togglemods.neonLights[2]))
					g_vehicles.writeData = features::localData.IsInVehicle;
				if (ImGui::Checkbox("Neon Lights Back", &g_vehicles.currVeh.togglemods.neonLights[3]))
					g_vehicles.writeData = features::localData.IsInVehicle;

				ImGui::NewLine();

				ImGui::Text("Flash Delay");
				ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f)); ImGui::SliderInt("##flashdelay", &features::fFlashDelay, 100, 5000, "%d ms");
				ImGui::Text("Fade Delay");
				ImGui::Dummy(ImVec2()); ImGui::SameLine(ImGui::GetCursorPosX() + resizefloat(10.f)); ImGui::SliderInt("##smoothdelay", &features::fSmoothDelay, 10, 100, "%d ms");

				ImGui::NewLine();

				ImGui::Checkbox("Flash Parts", &features::bFlashParts);
				ImGui::Checkbox("Flash Livery", &features::bFlashLivery);
				ImGui::Checkbox("Flash Headlights", &features::bFlashHeadlights);
				ImGui::Checkbox("Flash Wheels", &features::bFlashWheels);
				if (ImGui::Checkbox("Flash Colours", &features::bFlashVehicle))
					features::bRainbowVehicle = false;
				if (ImGui::Checkbox("Flash Neon Kits", &features::bFlashNeonKits))
					features::bRainbowNeonKits = false;
				if (ImGui::Checkbox("Flash Tyre Smoke", &features::bFlashTyresmoke))
					features::bRainbowTyresmoke = false;	
				if (ImGui::Checkbox("Fade Colours", &features::bRainbowVehicle))
					features::bFlashVehicle = false;
				if (ImGui::Checkbox("Fade Neon Kits", &features::bRainbowNeonKits))
					features::bFlashNeonKits = false;		
				if (ImGui::Checkbox("Fade Tyre Smoke", &features::bRainbowTyresmoke))
					features::bFlashTyresmoke = false;		
			

				ImGui::EndTabItem();
			}

			ImGui::EndTabBar();
		}
		ImGui::EndChild();
		ImGui::PopStyleVar();
	}
}

void GUI::World()
{
	{
		ImGui::BeginChild("WorldNetwork", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 2 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushFont(childHeaderFont); ImGui::Text("Network"); ImGui::PopFont(); ImGui::Separator();
		ImGui::Checkbox("Sync Time", &features::sync_time_with_network);
		ImGui::Checkbox("Sync Weather", &features::sync_weather_with_network);
		ImGui::EndChild();

		ImGui::NewLine();

		bool value_changed{};
		ImGui::BeginChild("WorldTime", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 6 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushFont(childHeaderFont); ImGui::Text("Time"); ImGui::PopFont(); ImGui::Separator();
		if (ImGui::InputInt("Hours", &features::clock_hours, 1, 2)) value_changed = true;
		if (ImGui::InputInt("Minutes", &features::clock_minutes, 1, 2)) value_changed = true;
		if (ImGui::InputInt("Seconds", &features::clock_seconds, 1, 2)) value_changed = true;
		ImGui::NewLine();
		if (ImGui::Checkbox("Freeze Time", &features::freezeTime)) features::timeCycleModifer = 0;
		if (ImGui::SliderInt("##timeLapse", &features::timeCycleModifer, 0, 100, "Time Speed %d"))
			features::freezeTime = false;		
		ImGui::EndChild();

		if (features::clock_hours > 23) features::clock_hours = 0; if (features::clock_hours < 0) features::clock_hours = 23;
		if (features::clock_minutes > 59) features::clock_minutes = 0; if (features::clock_minutes < 0) features::clock_minutes = 59;
		if (features::clock_seconds > 59) features::clock_seconds = 0; if (features::clock_seconds < 0) features::clock_seconds = 59;

		if (value_changed)
		{
			g_fiber_pool->queue_job([]
				{
					if (features::freezeTime)
					{
						features::clock_hours_freeze = features::clock_hours;
						features::clock_minutes_freeze = features::clock_minutes;
						features::clock_seconds_freeze = features::clock_seconds;
					}

					if (features::sync_time_with_network && *g_pointers->m_is_session_started)
					{
						features::defuseEvent(GAME_CLOCK_EVENT, false);
						NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(features::clock_hours, features::clock_minutes, features::clock_seconds);					
						g_pointers->m_setSessionTime(1, 0);
						script::get_current()->yield(500ms);
						features::defuseEvent(GAME_CLOCK_EVENT, features::bProtectionClock);
					}
					else {
						if (*g_pointers->m_is_session_started)
							NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(features::clock_hours, features::clock_minutes, features::clock_seconds);
						else
							TIME::SET_CLOCK_TIME(features::clock_hours, features::clock_minutes, features::clock_seconds);
					}			
				});
		}
	}
	ImGui::NextColumn();
	{
		static std::string weatherLabelNames[] = { "Extra Sunny", "Clear", "Clouds", "Smog", "Foggy", "Overcast", "Rain", "Thunder", "Light Rain", "Smoggy Light Rain", "Very Light Snow", "Windy Light Snow",
			"Light Snow", "X-Mas", "Halloween", "Black Screen", "Lobby fucker/crasher" };
		std::string weathers[] = { "EXTRASUNNY", "CLEAR", "CLOUDS", "SMOG", "FOGGY", "OVERCAST", "RAIN", "Thunder", "CLEARING",  "NEUTRAL", "SNOWLIGHT", "BLIZZARD", "SNOW", "XMAS", "HALLOWEEN", "NULL", "NULL"};

		static int selectedWeather{};
		static std::string selectedWeatherName{ "EXTRASUNNY" };
		ImGui::BeginChild("WorldWeather", ImVec2(0, childHeaderFont->FontSize + textFont->FontSize * 17 + ImGui::GetStyle().ItemSpacing.y * 22), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushFont(childHeaderFont); ImGui::Text("Weathers"); ImGui::PopFont(); ImGui::Separator();
		int i{};
		for (std::string str : weatherLabelNames)
		{
			if (ImGui::Selectable(str.c_str(), (selectedWeather == i), 0, ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
			{
				selectedWeather = i;
				selectedWeatherName = weathers[i];
			}
			i++;
		}

		ImGui::EndChild();

		if (ImGui::Button("Change Weather", ImVec2(ImGui::GetContentRegionAvailWidth(),0)))
		{
			g_fiber_pool->queue_job([]
			{			
					*script_global::script_global(262145 + 4723).as<bool*>() = false;				
					if (features::sync_weather_with_network && *g_pointers->m_is_session_started)
					{
						features::defuseEvent(GAME_WEATHER_EVENT, false);
						g_pointers->m_changeSessionWeather(1, selectedWeather, 76, 0);
						script::get_current()->yield(500ms);
						features::defuseEvent(GAME_WEATHER_EVENT, features::bProtectionWeather);
					}				
					else
						GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST(selectedWeatherName.c_str());							
			});
		}
	}	
}

void GUI::Teleport()
{
	ImGui::BeginChild("TeleportOptions", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 6 + ImGui::GetStyle().ItemSpacing.y * 5 + ImGui::GetTextLineHeightWithSpacing() * 1), true, ImGuiWindowFlags_NoScrollbar);
	ImGui::PushFont(childHeaderFont); ImGui::Text("Options"); ImGui::PopFont(); ImGui::Separator();
	ImGui::Checkbox("Auto Teleport to Waypoint", &features::bAutoTeleport);
	ImGui::Checkbox("Auto Restore Original IPLs", &features::bAutoRestoreOriginalIpls);

	ImGui::NewLine();

	if (ImGui::Button("Teleport to Waypoint", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
	{
		g_fiber_pool->queue_job([]
			{

				Entity ent = PLAYER::PLAYER_PED_ID();
				if (PED::IS_PED_IN_ANY_VEHICLE(ent, FALSE))
					ent = PED::GET_VEHICLE_PED_IS_IN(ent, FALSE);
				Vector3 coords = features::get_blip_marker();

				if (coords.x != 0 || coords.y != 0)
				{
					bool groundFound = false;
					static float groundCheckHeight[] =
					{ 100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
					for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
					{
						ENTITY::SET_ENTITY_COORDS_NO_OFFSET(ent, coords.x, coords.y, groundCheckHeight[i], 0, 0, 1);
						script::get_current()->yield(75ms);
						if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0))
						{
							groundFound = true;
							coords.z += 3.0;
							break;
						}
					}
					// if ground not found then set Z in air and give player a parachute
					if (!groundFound)
					{
						coords.z = 1000.0;
						WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xFBAB5776, 1, 0);
					}
					//do it
					features::teleport_to_coords(ent, coords);
					UI::SET_WAYPOINT_OFF();
				}
				else
					features::notifyAboveMap("Waypoint not found.", 0);
				
			});
	}
	if (ImGui::Button("Teleport to Objective", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
	{
		g_fiber_pool->queue_job([]
			{
				features::teleport_to_objective();
			});
	}
	if (ImGui::Button("Teleport to Personal Vehicle", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
	{
		g_fiber_pool->queue_job([]
			{
				features::teleport_to_personal_vehicle();
			});
	}
	if (ImGui::Button("Restore Original IPLs", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
	{
		g_fiber_pool->queue_job([]
			{
				for (const char* str : TeleportLocations::restore::IplsToRemove)
					STREAMING::REMOVE_IPL(str);

				for (const char* str : TeleportLocations::restore::IplsToLoad)
					STREAMING::REQUEST_IPL(str);

				TeleportLocations::restore::IplsToRemove.clear();
				TeleportLocations::restore::IplsToLoad.clear();
			});
	}
	ImGui::EndChild();

	ImGui::NewLine();

	ImGui::BeginChild("TeleportCustom", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 4 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
	ImGui::PushFont(childHeaderFont); ImGui::Text("Custom"); ImGui::PopFont(); ImGui::Separator();
	static float x, y, z;
	ImGui::InputFloat("X-Coord", &x, 1, 100, 3, ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_CharsDecimal);
	ImGui::InputFloat("Y-Coord", &y, 1, 100, 3, ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_CharsDecimal);
	ImGui::InputFloat("Z-Coord", &z, 1, 100, 3, ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_CharsDecimal);
	if (ImGui::Button("Teleport to Coords", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
	{
		g_fiber_pool->queue_job([]
			{
				Entity ent = PLAYER::PLAYER_PED_ID();
				if (PED::IS_PED_IN_ANY_VEHICLE(ent, FALSE))
					ent = PED::GET_VEHICLE_PED_IS_IN(ent, FALSE);

				features::teleport_to_coords(ent, { x, NULL, y, NULL, z, NULL });
			});
	}
	ImGui::EndChild();

	ImGui::NewLine();

	ImGui::BeginChild("TeleportForward", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 2 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
	ImGui::PushFont(childHeaderFont); ImGui::Text("Forward"); ImGui::PopFont(); ImGui::Separator();
	static float forward = 5.f;
	ImGui::SliderFloat("Forward", &forward, -5.f, 10.f, "%.0f");
	if (ImGui::Button("Teleport Forward", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
	{
		g_fiber_pool->queue_job([]
			{
				Entity ent = PLAYER::PLAYER_PED_ID();
				if (PED::IS_PED_IN_ANY_VEHICLE(ent, FALSE))
					ent = PED::GET_VEHICLE_PED_IS_IN(ent, FALSE);

				Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
				float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
				float xVector = forward * sin(features::degToRad(heading)) * -1.f;
				float yVector = forward * cos(features::degToRad(heading));

				features::teleport_to_coords(ent, { ourCoords.x + xVector, NULL, ourCoords.y + yVector, NULL, ourCoords.z, NULL });
			});
	}
	ImGui::EndChild();

	ImGui::NextColumn();
	{
		ImGui::PushStyleVar(ImGuiStyleVar_SelectableTextAlign, ImVec2(0, 0.5f));
		ImGui::BeginChild("Locations", ImVec2(), true);
		for (TeleportLocations::NamedTeleLocationList cat : TeleportLocations::Locations::vAllCategories)
		{
			if (ImGui::TreeNode(cat.categoryName.c_str()))
			{
				if (cat.locList_ptr != nullptr)
				{
					for (auto loc : *cat.locList_ptr)
					{
						if (ImGui::MenuItem(loc.name.c_str()))
						{
							static auto location = loc;
							location = loc;
							g_fiber_pool->queue_job([]
								{
									if (features::bAutoRestoreOriginalIpls)
									{
										for (const char* str : TeleportLocations::restore::IplsToRemove)
											STREAMING::REMOVE_IPL(str);

										for (const char* str : TeleportLocations::restore::IplsToLoad)									
											STREAMING::REQUEST_IPL(str);
										
										TeleportLocations::restore::IplsToRemove.clear();
										TeleportLocations::restore::IplsToLoad.clear();
									}

									for (const char* str : location.iplsToRemove)
									{
										STREAMING::REMOVE_IPL(str);
										TeleportLocations::restore::IplsToLoad.push_back(str);
									}
										

									for (const char* str : location.iplsToLoad)
									{
										STREAMING::REQUEST_IPL(str);
										TeleportLocations::restore::IplsToRemove.push_back(str);
									}
										
					
									for (const char* str : location.interiorProps)
										STREAMING::REQUEST_MODEL(rage::joaat(str));								

									Entity ent = PLAYER::PLAYER_PED_ID();
									if (PED::IS_PED_IN_ANY_VEHICLE(ent, FALSE))
										ent = PED::GET_VEHICLE_PED_IS_IN(ent, FALSE);
									features::teleport_to_coords(ent, { location.x, NULL, location.y, NULL, location.z, NULL });

								});
						}
					}
				}

				ImGui::TreePop();
				ImGui::Separator();
			}
		}
		ImGui::EndChild();
		ImGui::PopStyleVar();
	}
	/*MAIN VAULT  2517.84, -238.99, -70.56*/
}

void GUI::Misc()
{
	{
		{
			ImGui::BeginChild("MiscNetwork", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 3 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
			ImGui::PushFont(childHeaderFont); ImGui::Text("Network"); ImGui::PopFont(); ImGui::Separator();
			if (ImGui::Button("Name Changer", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
				ImGui::OpenPopup("Change_Name");

			if (ImGui::BeginPopup("Change_Name"))
			{
				ImGui::Text("Name:");
				ImGui::Separator();
				static char buf[19];

				ImGui::InputText("###name", buf, 19);

				ImGui::SameLine();
				if (ImGui::Button("Apply"))
				{
					g_fiber_pool->queue_job([]
						{
							features::setSpoofName(std::string(buf));
						});

				}

				ImGui::EndPopup();
			}

			if (ImGui::Button("Join By Rockstar ID", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
				ImGui::OpenPopup("rid_joiner");

			if (ImGui::BeginPopup("rid_joiner"))
			{
				ImGui::Text("Rockstar Id:");
				ImGui::Separator();
				ImGui::InputInt("##rid", &features::bMiscRockstarID);
				if (ImGui::Button("Join"))
				{
					if (features::bMiscRockstarID > 0)
					{
						g_fiber_pool->queue_job([]
							{
								if (g_pointers->m_menuPtr)
								{
									do
									{								
										UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
										script::get_current()->yield(1s);

										if (*g_pointers->m_menuPtr)
										{
											int hash = -632792895;
											int64_t ptr = *g_pointers->m_menuPtr;
											g_pointers->m_ridJoiner(&ptr, &hash);
										}
									} while (!*g_pointers->m_menuPtr);
								}
							});
					}
				}
				ImGui::EndPopup();
			}

			if (ImGui::Button("View Social Club Profile", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
				ImGui::OpenPopup("sc_profile_rid");

			if (ImGui::BeginPopup("sc_profile_rid"))
			{
				static int rockstarid;

				ImGui::Text("Rockstar Id:");
				ImGui::Separator();
				ImGui::InputInt("##rid", &rockstarid);
				ImGui::SameLine();
				if (ImGui::Button("View##1"))
				{
					if (rockstarid > 0)
					{
						g_fiber_pool->queue_job([]
							{
								int netHandle[13];
								NETWORK::NETWORK_HANDLE_FROM_MEMBER_ID(std::to_string(rockstarid).c_str(), netHandle, 13);
								NETWORK::NETWORK_SHOW_PROFILE_UI(netHandle);				
							});
					}
				}
				ImGui::EndPopup();
			}
			ImGui::EndChild();
		}
		ImGui::NewLine();
		{
			ImGui::BeginChild("MiscOther", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 8 + ImGui::GetStyle().ItemSpacing.y * 5 + ImGui::GetTextLineHeightWithSpacing()), true, ImGuiWindowFlags_NoScrollbar);
			ImGui::PushFont(childHeaderFont); ImGui::Text("Other"); ImGui::PopFont(); ImGui::Separator();
			ImGui::Checkbox("Upgrade Nearby Vehicles", &features::bMiscUpgradeNearbyVehicles);
			ImGui::Checkbox("Explode Nearby Vehicles", &features::bMiscExplodeNearbyVehicles);
			ImGui::Checkbox("Delete Nearby Vehicles", &features::bMiscDeleteNearbyVehicles);
			if (ImGui::Checkbox("Destroy Phone", &features::bMiscDestroyPhone))
			{
				g_fiber_pool->queue_job([]
					{
						if (features::bMiscDestroyPhone)
						{
							MOBILE::DESTROY_MOBILE_PHONE();
						}
						else
						{
							MOBILE::CREATE_MOBILE_PHONE(0);
						}
					});
			}

			ImGui::NewLine();

			if (ImGui::Button("Clear Orbital Cooldown", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
			{
				g_fiber_pool->queue_job([]
					{
						STATS::STAT_SET_INT(RAGE_JOAAT("MP0_ORBITAL_CANNON_COOLDOWN"), 0, TRUE);
						STATS::STAT_SET_INT(RAGE_JOAAT("MP1_ORBITAL_CANNON_COOLDOWN"), 0, TRUE);
					});
			}
			if (ImGui::Button("Allow Gender Change", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
			{
				g_fiber_pool->queue_job([]
					{
						STATS::STAT_SET_INT(RAGE_JOAAT("MP0_ALLOW_GENDER_CHANGE"), 52, TRUE);
						STATS::STAT_SET_INT(RAGE_JOAAT("MP1_ALLOW_GENDER_CHANGE"), 52, TRUE);
					});
			}
			if (ImGui::Button("Skip cutscene", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
			{
				g_fiber_pool->queue_job([]
					{
						CUTSCENE::STOP_CUTSCENE_IMMEDIATELY();
					});
			}

			if (ImGui::Button("Spawn Bodyguard", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
			{
				g_fiber_pool->queue_job([]
					{
						features::MiscSpawnBodyGuard();
					});		
			}

			//ImGui::Checkbox("bMiscsSetAllRandomPedsFlee", &features::bMiscsSetAllRandomPedsFlee);
			ImGui::EndChild();
		}
	}
	ImGui::NextColumn();
	{
		ImGui::BeginChild("MiscAuto", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 3 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushFont(childHeaderFont); ImGui::Text("Auto"); ImGui::PopFont(); ImGui::Separator();
		ImGui::Checkbox("bMiscAutoTeams", &features::bMiscAutoTeams);
		ImGui::Checkbox("bMiscAutoFriends", &features::bMiscAutoFriends);
		if (ImGui::Button("Reset Friends & Team", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
		{
			for (int i = 0; i < 32; i++)
			{
				features::playerData[i].IsTeam = false;
				features::playerData[i].IsFriend = false;
			}
		}
		ImGui::EndChild();
	}
}

void GUI::Protections()
{
	{

		ImGui::BeginChild("Protection", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 2 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushFont(childHeaderFont); ImGui::Text("Protections"); ImGui::PopFont(); ImGui::Separator();
		ImGui::Checkbox("bProtectionReportBlocker", &features::bProtectionReportBlocker);
		ImGui::Checkbox("bProtectionRockstarDev", &features::bProtectionRockstarDev);
		ImGui::EndChild();

		ImGui::NewLine();

		ImGui::BeginChild("ScriptProtections", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 2 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushFont(childHeaderFont); ImGui::Text("Script Events"); ImGui::PopFont(); ImGui::Separator();
		ImGui::Checkbox("bProtectionNonHostKick", &features::bProtectionNonHostKick);
		ImGui::Checkbox("bProtectionTeleport", &features::bProtectionTeleport);
		ImGui::EndChild();	
	}
	ImGui::NextColumn();
	{
		ImGui::BeginChild("NetworkProtections", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 9 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushFont(childHeaderFont); ImGui::Text("Network Events"); ImGui::PopFont(); ImGui::Separator();
		if (ImGui::Checkbox("bProtectionVoteKick", &features::bProtectionVoteKick))
			features::ProtectionCallback();
		if (ImGui::Checkbox("bProtectionWeather", &features::bProtectionWeather))
			features::ProtectionCallback();
		if (ImGui::Checkbox("bProtectionTime", &features::bProtectionClock))
			features::ProtectionCallback();
		if (ImGui::Checkbox("bProtectionFreeze", &features::bProtectionFreeze))
			features::ProtectionCallback();
		if (ImGui::Checkbox("bProtectionRequestControl", &features::bProtectionRequestControl))
			features::ProtectionCallback();
		if (ImGui::Checkbox("bProtectionExplosion", &features::bProtectionExplosion))
			features::ProtectionCallback();
		if (ImGui::Checkbox("bProtectionFire", &features::bProtectionFire))
			features::ProtectionCallback();
		if (ImGui::Checkbox("bProtectionPTFX", &features::bProtectionPTFX))
			features::ProtectionCallback();
		ImGui::Checkbox("Anti Attach", &features::bProtectionAntiAttach);
		ImGui::EndChild();

		ImGui::NewLine();

		ImGui::BeginChild("ProtectionOther", ImVec2(0, childHeaderFont->FontSize + ImGui::GetFrameHeightWithSpacing() * 2 + ImGui::GetStyle().ItemSpacing.y * 5), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushFont(childHeaderFont); ImGui::Text("Other"); ImGui::PopFont(); ImGui::Separator();
		ImGui::Checkbox("bProtectionShowAsCheraxUser", &features::bProtectionShowAsCheraxUser);
		ImGui::Checkbox("bProtectionShowNotifications", &features::bProtectionShowNotifications);
		ImGui::EndChild();
	}
}

void GUI::Settings()
{
	{
		ImGui::Checkbox("Auto Resize", &autoResize);
	}
	ImGui::NextColumn();
	ImGui::BeginChild("Settings", ImVec2(0,0), true);
	ImGuiStyle& custom = ImGui::GetStyle();
	for (int i = 0; i < ImGuiCol_COUNT; i++)
	{
		const char* name = ImGui::GetStyleColorName(i);
		ImGui::ColorEdit4((std::string("##") + name).c_str() , (float*)&custom.Colors[i], ImGuiColorEditFlags_NoInputs);
		ImGui::SameLine(); ImGui::Text(name);
	}

	ImGui::EndChild();
}

void GUI::script_init()
{
	g_vehicles.initialize();
	XML::refreshXMLFiles();
}

void GUI::script_func()
{
	g_gui.script_init();
	while (true)
	{
		g_gui.run_tick();
		script::get_current()->yield();
	}
}

void GUI::run_tick()
{
}

ImVec2 GUI::resizeVec(ImVec2 vec2)
{
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	float newScale = (io.DisplaySize.x * io.DisplaySize.y) / (1920.f * 1080.f);

	if (newScale > 1.0f)
		newScale = 1.f;

	if (autoResize)
		return ImVec2(vec2.x * newScale, vec2.y * newScale);
	else
		return vec2;
}

float GUI::resizefloat(float val)
{
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	float newScale = (io.DisplaySize.x * io.DisplaySize.y) / (1920.f * 1080.f);

	if (newScale > 1.0f)
		newScale = 1.f;

	if (autoResize)
		return val * newScale;
	else
		return val;
}

bool GUI::radioButton(const char* label, bool* v)
{
	if (ImGui::RadioButton(label, *v))
	{
		*v = !*v;
		return true;
	}
	return false;
}

ImVec2 GUI::WorldToScreen(Vector3 pos)
{
	auto& io = ImGui::GetIO();
	ImVec2 tempVec2;
	g_pointers->m_world2Screen({pos.x, pos.y, pos.z}, &tempVec2.x, &tempVec2.y);
	tempVec2.x *= io.DisplaySize.x;
	tempVec2.y *= io.DisplaySize.y;
	return tempVec2;
}

BOOL GUI::Draw2DBox(tPlayerData data, ImVec2 head, ImVec2 feet)
{
	if ((head.x < 0) || (head.y < 0) || (feet.x < 0) || (feet.y < 0))
		return FALSE;

	float height = head.y - feet.y;
	float width = height / 2.6;
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	ImU32 color;
	if (!data.IsNPC)
		color = ((data.playerId == features::localData.localId) ? u32_yourColor : (data.IsFriend ? u32_friendColor : (!features::isTeamGameModeRunning ? u32_enemyColor : (data.IsTeam ? u32_teamColor : u32_enemyColor))));
	else {
		if (data.IsCop)
			color = u32_CopColor;
		else
			color = u32_NpcColor;
	}

	window->DrawList->AddLine(ImVec2(head.x - width / 2, head.y), ImVec2(head.x + width / 2, head.y), color);
	window->DrawList->AddLine(ImVec2(feet.x - width / 2, feet.y), ImVec2(feet.x + width / 2, feet.y), color);
	window->DrawList->AddLine(ImVec2(head.x - width / 2, head.y), ImVec2(feet.x - width / 2, feet.y), color);
	window->DrawList->AddLine(ImVec2(head.x + width / 2, head.y), ImVec2(feet.x + width / 2, feet.y), color);
	return TRUE;
}

BOOL GUI::DrawLine(tPlayerData data, ImVec2 a, ImVec2 b)
{
	if ((a.x < 0) || (a.y < 0) || (b.x < 0) || (b.y < 0))
		return FALSE;

	ImU32 color;
	if (!data.IsNPC)
		color = ((data.playerId == features::localData.localId) ? u32_yourColor : (data.IsFriend ? u32_friendColor : (!features::isTeamGameModeRunning ? u32_enemyColor : (data.IsTeam ? u32_teamColor : u32_enemyColor))));
	else {
		if (data.IsCop)
			color = u32_CopColor;
		else
			color = u32_NpcColor;
	}

	ImGuiWindow* window = ImGui::GetCurrentWindow();
	window->DrawList->AddLine(a, b, color);
	return TRUE;
}

BOOL GUI::drawHealthBar(tPlayerData data, ImVec2 head, ImVec2 feet)
{
	if ((head.x < 0) || (head.y < 0) || (feet.x < 0) || (feet.y < 0))
		return FALSE;

	ImGuiWindow* window = ImGui::GetCurrentWindow();

	if (0)
	{
		float height = head.y - feet.y;
		float width = height / 2.6;

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


BOOL GUI::drawAmourBar(tPlayerData data, ImVec2 head, ImVec2 feet)
{
	if ((head.x < 0) || (head.y < 0) || (feet.x < 0) || (feet.y < 0))
		return FALSE;

	

	ImGuiWindow* window = ImGui::GetCurrentWindow();

	if (0)
	{
		float height = head.y - feet.y;
		float width = height / 2.6;
		float barHeight = height / 25 - height / 40;
		float armourhpercent = data.armour / data.maxArmour;
		float length = (feet.x + width / 2) - (feet.x - width / 2);
		length *= armourhpercent;

		if (features::ESPHealthbar)
		{
			window->DrawList->AddRectFilledMultiColor(ImVec2(feet.x - width / 2, feet.y - height / 40 - barHeight * 2), ImVec2(feet.x + width / 2, feet.y - height / 25 - barHeight * 2), ImColor(0, 102, 204), ImColor(0, 25, 204), ImColor(0, 25, 204), ImColor(0, 102, 204));
			window->DrawList->AddRect(ImVec2(feet.x - width / 2, feet.y - height / 40 - barHeight * 2), ImVec2(feet.x + width / 2, feet.y - height / 25 - barHeight * 2), ImColor(0, 0, 0, 255));
		}
		else
		{
			window->DrawList->AddRectFilledMultiColor(ImVec2(feet.x - width / 2, feet.y - height / 40), ImVec2(feet.x + width / 2, feet.y - height / 25), ImColor(0, 102, 204), ImColor(0, 25, 204), ImColor(0, 25, 204), ImColor(0, 102, 204));
			window->DrawList->AddRect(ImVec2(feet.x - width / 2, feet.y - height / 40), ImVec2(feet.x + width / 2, feet.y - height / 25), ImColor(0, 0, 0, 255));
		}
	}
	else
	{
		float height = head.y - feet.y;
		float width = resizefloat(-75);
		float barHeight = height / 25 - height / 40;
		float armourhpercent = data.armour / data.maxArmour;
		float length = (feet.x + width / 2) - (feet.x - width / 2);
		length *= armourhpercent;

		if (features::ESPHealthbar)
		{
			window->DrawList->AddRectFilledMultiColor(ImVec2(feet.x - width / 2, feet.y - height / 40 + 7.5), ImVec2(feet.x + width / 2, feet.y - height / 40 + 12.5f), ImColor(0, 102, 204), ImColor(0, 25, 204), ImColor(0, 25, 204), ImColor(0, 102, 204));
			window->DrawList->AddRect(ImVec2(feet.x - width / 2, feet.y - height / 40 + 7.5), ImVec2(feet.x + width / 2, feet.y - height / 40 + 12.5f), ImColor(0, 0, 0, 255));
			window->DrawList->AddRectFilled(ImVec2(feet.x + width / 2 - length, feet.y - height / 40 + 7.5), ImVec2(feet.x - width / 2, feet.y - height / 40 + 12.5f), ImColor(0, 0, 0, 180));
		}
		else
		{
			window->DrawList->AddRectFilledMultiColor(ImVec2(feet.x - width / 2, feet.y - height / 40), ImVec2(feet.x + width / 2, feet.y - height / 40 + 5.f), ImColor(0, 102, 204), ImColor(0, 25, 204), ImColor(0, 25, 204), ImColor(0, 102, 204));
			window->DrawList->AddRect(ImVec2(feet.x - width / 2, feet.y - height / 40), ImVec2(feet.x + width / 2, feet.y - height / 40 + 5.f), ImColor(0, 0, 0, 255));
			window->DrawList->AddRectFilled(ImVec2(feet.x + width / 2 - length, feet.y - height / 40), ImVec2(feet.x - width / 2, feet.y - height / 40 + 5.f), ImColor(0, 0, 0, 100));
		}
	}

	
	return TRUE;
}

BOOL GUI::DrawDistanceAndName(tPlayerData data, ImVec2 head, ImVec2 feet)
{
	if ((head.x < 0) || (head.y < 0) || (feet.x < 0) || (feet.y < 0))
		return FALSE;

	ImGuiWindow* window = ImGui::GetCurrentWindow();
	float height = feet.y - head.y;
	float width = resizefloat(75);

	ImU32 color;
	if (!data.IsNPC)
		color = ((data.playerId == features::localData.localId) ? u32_yourColor : (data.IsFriend ? u32_friendColor : (!features::isTeamGameModeRunning ? u32_enemyColor : (data.IsTeam ? u32_teamColor : u32_enemyColor))));
	else {
		if (data.IsCop)
			color = u32_CopColor;
		else
			color = u32_NpcColor;
	}


	if (features::ESPName && features::ESPDistance)
	{
		std::string info = '[' + std::to_string((int)data.distance) + "] " + data.playerName;
		window->DrawList->AddText(ImVec2(head.x - width / 2, head.y - height / 10 - ImGui::GetTextLineHeight()), color, info.c_str());
	}
	else if (features::ESPName)
	{
		window->DrawList->AddText(ImVec2(head.x - width / 2, head.y - height / 10 - ImGui::GetTextLineHeight()), color, data.playerName.c_str());
	}	
	else
	{
		std::string distance = '[' + std::to_string((int)data.distance) + ']';
		window->DrawList->AddText(ImVec2(head.x - width / 2, head.y - height / 10 - ImGui::GetTextLineHeight()), color, distance.c_str());
	}
	return TRUE;
}

bool GUI::ToggleButton(const char* str_id, bool* v)
{
	bool returnVal = false;
	ImVec2 p = ImGui::GetCursorScreenPos();
	ImDrawList* draw_list = ImGui::GetWindowDrawList();

	float height = ImGui::GetFrameHeight();
	float width = height * 1.55f;
	float radius = height * 0.50f;

	ImGui::InvisibleButton(str_id, ImVec2(width, height));
	if (ImGui::IsItemClicked())
	{
		*v = !*v;
		returnVal = true;
	}
		

	float t = *v ? 1.0f : 0.0f;

	ImGuiContext& g = *GImGui;
	float ANIM_SPEED = 0.08f;
	if (g.LastActiveId == g.CurrentWindow->GetID(str_id))// && g.LastActiveIdTimer < ANIM_SPEED)
	{
		float t_anim = ImSaturate(g.LastActiveIdTimer / ANIM_SPEED);
		t = *v ? (t_anim) : (1.0f - t_anim);
	}

	ImU32 col_bg;
	if (ImGui::IsItemHovered())
		col_bg = ImGui::GetColorU32(ImLerp(ImVec4(0.78f, 0.78f, 0.78f, 1.0f), ImVec4(0.64f, 0.83f, 0.34f, 1.0f), t));
	else
		col_bg = ImGui::GetColorU32(ImLerp(ImVec4(0.85f, 0.85f, 0.85f, 1.0f), ImVec4(0.56f, 0.83f, 0.26f, 1.0f), t));

	draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.5f);
	draw_list->AddCircleFilled(ImVec2(p.x + radius + t * (width - radius * 2.0f), p.y + radius), radius - 1.5f, IM_COL32(255, 255, 255, 255));

	ImGui::SameLine();
	ImGui::Text(str_id);

	return returnVal;
}

int* GUI::hsi_to_rgb(float H, float S, float I)
{
	int rgb[3];
	if (H > 360) {
		H = H - 360;
	}
	// Serial.println("H: "+String(H));
	H = fmod(H, 360); // cycle H around to 0-360 degrees
	H = 3.14159 * H / (float)180; // Convert to radians.
	S = S > 0 ? (S < 1 ? S : 1) : 0; // clamp S and I to interval [0,1]
	I = I > 0 ? (I < 1 ? I : 1) : 0;
	if (H < 2.09439) {
		rgb[0] = 255 * I / 3 * (1 + S * cos(H) / cos(1.047196667 - H));
		rgb[1] = 255 * I / 3 * (1 + S * (1 - cos(H) / cos(1.047196667 - H)));
		rgb[2] = 255 * I / 3 * (1 - S);
	}
	else if (H < 4.188787) {
		H = H - 2.09439;
		rgb[1] = 255 * I / 3 * (1 + S * cos(H) / cos(1.047196667 - H));
		rgb[2] = 255 * I / 3 * (1 + S * (1 - cos(H) / cos(1.047196667 - H)));
		rgb[0] = 255 * I / 3 * (1 - S);
	}
	else {
		H = H - 4.188787;
		rgb[2] = 255 * I / 3 * (1 + S * cos(H) / cos(1.047196667 - H));
		rgb[0] = 255 * I / 3 * (1 + S * (1 - cos(H) / cos(1.047196667 - H)));
		rgb[1] = 255 * I / 3 * (1 - S);
	}
	return rgb;
}

RGBA GUI::DWORD2RGBA(unsigned long dwColor)
{
	RGBA tmp;
	tmp.R = dwColor & 0xFF; dwColor >>= 8;
	tmp.G = dwColor & 0xFF; dwColor >>= 8;
	tmp.B = dwColor & 0xFF; dwColor >>= 8;
	tmp.A = dwColor & 0xFF; /* dwColor >>= 8; */
	return tmp;
}
