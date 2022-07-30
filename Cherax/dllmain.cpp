#pragma once
#include "common.h"
#include "pointers.h"
#include "D3DHooking.h"
#include "logger.h"
#include "hooking.h"
#include "gui.h"
#include "script_mgr.h"
#include "fiber_pool.h"
#include "features.h"
#include "AntiDbg.h"

using namespace std::chrono_literals;

BOOL APIENTRY DllMain(HMODULE hmod, DWORD reason, PVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hmod);

		std::this_thread::yield();

		g_hmodule = hmod;
		g_main_thread = CreateThread(nullptr, 0, [](PVOID) -> DWORD
			{

				HANDLE hMutex = OpenMutex(SYNCHRONIZE, FALSE, "ABUIEDT");
				//if (hMutex != NULL)
				{
					CloseHandle(hMutex);
					try
					{
						auto logger_instance = std::make_unique<Logger>();
						printf("Logger initialized.\n");
						auto pointers_instance = std::make_unique<pointers>();
						printf("Pointers initialized.\n");
						auto renderer_instance = std::make_unique<DX::DX11Renderer>();
						printf("DX renderer instance created.\n");
						//auto dxHooks_instance = std::make_unique<DX::D3DHooking>(DX::D3D11);
						//printf("DX hookings initialized.\n");
						auto fiber_pool_instance = std::make_unique<fiber_pool>(5);
						printf("Fiber pool initialized.\n");
						g_script_mgr.add_script(std::make_unique<script>(&features::script_func));
						g_script_mgr.add_script(std::make_unique<script>(&GUI::script_func));
						printf("Scripts registered.\n");
						if (MH_Initialize() == MH_OK) 
							printf("Minhook initialized\n");
						auto hooking_instance = std::make_unique<hooking>();
						printf("hooking initialized.\n");

						static bool test = NULL;
						PMEMORY_BASIC_INFORMATION p{};
						VirtualQuery(&test, p, sizeof(p));

						while (g_running)
						{
							if (GetKeyState(VK_NUMPAD0))
								g_running = false;

							g_hooking->ensure_dynamic_hooks();
							//AntiDbg();

							std::this_thread::sleep_for(10ms);
						}
						std::this_thread::sleep_for(100ms);

						features::ProtectionsReset();
						hooking_instance.reset();
						printf("hooking uninitialized\n");
						g_script_mgr.remove_all_scripts();
						printf("Scripts uninitialized\n");
						fiber_pool_instance.reset();
						printf("fiber pool uninitialized\n");
						//dxHooks_instance.reset();
						//printf("DX hookings uninitialized\n");
						renderer_instance.reset();
						printf("DX renderer uninitialized\n");
						pointers_instance.reset();
						printf("pointers uninitialized\n");
						logger_instance.reset();
					}
					catch (std::exception const& ex)
					{
						printf("%s", ex.what());
						MessageBoxA(g_pointers->m_hwnd, ex.what(), nullptr, MB_OK | MB_ICONEXCLAMATION);
						system("pause");
					}
				}

				CloseHandle(g_main_thread);
				FreeLibraryAndExitThread(g_hmodule, 0);
			}, nullptr, 0, &g_main_thread_id);
	}

	return true;
}
