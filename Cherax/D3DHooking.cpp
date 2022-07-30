#include "D3DHooking.h"
#include "hooking.h"


DX::D3DHooking::D3DHooking(int D3DXX)
{
	g_d3dHooking = this;

	if (g_renderType == NULL)
	{
		if (g_renderType == NULL)
		{
			WNDCLASSEX windowClass;
			windowClass.cbSize = sizeof(WNDCLASSEX);
			windowClass.style = CS_HREDRAW | CS_VREDRAW;
			windowClass.lpfnWndProc = DefWindowProc;
			windowClass.cbClsExtra = 0;
			windowClass.cbWndExtra = 0;
			windowClass.hInstance = GetModuleHandle(NULL);
			windowClass.hIcon = NULL;
			windowClass.hCursor = NULL;
			windowClass.hbrBackground = NULL;
			windowClass.lpszMenuName = NULL;
			windowClass.lpszClassName = "ImCytox";
			windowClass.hIconSm = NULL;

			::RegisterClassEx(&windowClass);

			HWND window = ::CreateWindow(windowClass.lpszClassName, "D3D Window", WS_OVERLAPPEDWINDOW, 0, 0, 100, 100, NULL, NULL, windowClass.hInstance, NULL);

			if (g_renderType == NULL && ((D3DXX == 0) || (D3DXX == D3D9)))
			{
				printf("Checking for D3D9\n");

				HMODULE libD3D9;
				if ((libD3D9 = ::GetModuleHandle("d3d9.dll")) == NULL)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Failed GetModuleHandle d3d.dll\n");
					system("pause");
#endif			
					return;
				}

				void* Direct3DCreate9;
				if ((Direct3DCreate9 = ::GetProcAddress(libD3D9, "Direct3DCreate9")) == NULL)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
					system("pause");
#endif		
					return;
				}

				LPDIRECT3D9 direct3D9;
				if ((direct3D9 = ((LPDIRECT3D9(__stdcall*)(uint32_t))(Direct3DCreate9))(D3D_SDK_VERSION)) == NULL)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
					system("pause");
#endif		
					return;
				}

				D3DDISPLAYMODE displayMode;
				if (direct3D9->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &displayMode) < 0)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
#endif		
					return;
				}

				D3DPRESENT_PARAMETERS params;
				params.BackBufferWidth = 0;
				params.BackBufferHeight = 0;
				params.BackBufferFormat = displayMode.Format;
				params.BackBufferCount = 0;
				params.MultiSampleType = D3DMULTISAMPLE_NONE;
				params.MultiSampleQuality = NULL;
				params.SwapEffect = D3DSWAPEFFECT_DISCARD;
				params.hDeviceWindow = window;
				params.Windowed = 1;
				params.EnableAutoDepthStencil = 0;
				params.AutoDepthStencilFormat = D3DFMT_UNKNOWN;
				params.Flags = NULL;
				params.FullScreen_RefreshRateInHz = 0;
				params.PresentationInterval = 0;

				LPDIRECT3DDEVICE9 device;
				if (direct3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, window, D3DCREATE_SOFTWARE_VERTEXPROCESSING | D3DCREATE_DISABLE_DRIVER_MANAGEMENT, &params, &device) < 0)
				{
					direct3D9->Release();
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
#endif		
					return;
				}

				g_methodsTable = (uintptr_t*)::calloc(119, sizeof(uintptr_t));
				::memcpy(g_methodsTable, *(uintptr_t**)device, 119 * sizeof(uintptr_t));


				direct3D9->Release();
				direct3D9 = NULL;

				device->Release();
				device = NULL;

				g_renderType = D3D9;

				::DestroyWindow(window);
				::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);

				return;
			}
			else if (g_renderType == NULL && ((D3DXX == 0) || (D3DXX == D3D10)))
			{
				printf("Checking for D3D10\n");

				HMODULE libDXGI;
				HMODULE libD3D10;
				if ((libDXGI = ::GetModuleHandle("dxgi.dll")) == NULL || (libD3D10 = ::GetModuleHandle("d3d10.dll")) == NULL)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Failed GetModuleHandle d3d10.dll or dxgi.dll\n");
					system("pause");
#endif		
					return;
				}

				void* CreateDXGIFactory;
				if ((CreateDXGIFactory = ::GetProcAddress(libDXGI, "CreateDXGIFactory")) == NULL)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
					system("pause");
#endif		
					return;
				}

				IDXGIFactory* factory;
				if (((long(__stdcall*)(const IID&, void**))(CreateDXGIFactory))(__uuidof(IDXGIFactory), (void**)&factory) < 0)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
					system("pause");
#endif		
					return;
				}

				IDXGIAdapter* adapter;
				if (factory->EnumAdapters(0, &adapter) == DXGI_ERROR_NOT_FOUND)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
					system("pause");
#endif		
					return;
				}

				void* D3D10CreateDeviceAndSwapChain;
				if ((D3D10CreateDeviceAndSwapChain = ::GetProcAddress(libD3D10, "D3D10CreateDeviceAndSwapChain")) == NULL)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
					system("pause");
#endif		
					return;
				}

				DXGI_RATIONAL refreshRate;
				refreshRate.Numerator = 60;
				refreshRate.Denominator = 1;

				DXGI_MODE_DESC bufferDesc;
				bufferDesc.Width = 100;
				bufferDesc.Height = 100;
				bufferDesc.RefreshRate = refreshRate;
				bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
				bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
				bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

				DXGI_SAMPLE_DESC sampleDesc;
				sampleDesc.Count = 1;
				sampleDesc.Quality = 0;

				DXGI_SWAP_CHAIN_DESC swapChainDesc;
				swapChainDesc.BufferDesc = bufferDesc;
				swapChainDesc.SampleDesc = sampleDesc;
				swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
				swapChainDesc.BufferCount = 1;
				swapChainDesc.OutputWindow = window;
				swapChainDesc.Windowed = 1;
				swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
				swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

				IDXGISwapChain* swapChain;
				ID3D10Device* device;

				if (((long(__stdcall*)(
					IDXGIAdapter*,
					D3D10_DRIVER_TYPE,
					HMODULE,
					UINT,
					UINT,
					DXGI_SWAP_CHAIN_DESC*,
					IDXGISwapChain**,
					ID3D10Device**))(D3D10CreateDeviceAndSwapChain))(adapter, D3D10_DRIVER_TYPE_HARDWARE, NULL, 0, D3D10_SDK_VERSION, &swapChainDesc, &swapChain, &device) < 0)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
					system("pause");
#endif		
					return;
				}

				g_methodsTable = (uintptr_t*)::calloc(116, sizeof(uintptr_t));
				::memcpy(g_methodsTable, *(uintptr_t**)swapChain, 18 * sizeof(uintptr_t));
				::memcpy(g_methodsTable + 18, *(uintptr_t**)device, 98 * sizeof(uintptr_t));

				swapChain->Release();
				swapChain = NULL;

				device->Release();
				device = NULL;

				::DestroyWindow(window);
				::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);

				g_renderType = D3D10;

				return;
			}
			else if (g_renderType == NULL && ((D3DXX == 0) || (D3DXX == D3D11)))
			{
				printf("Checking for D3D11\n");

				HMODULE libD3D11;
				if ((libD3D11 = ::GetModuleHandle("d3d11.dll")) == NULL)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Failed GetModuleHandle d3d11.dll\n");
					system("pause");
#endif		
					return;
				}

				void* D3D11CreateDeviceAndSwapChain;
				if ((D3D11CreateDeviceAndSwapChain = ::GetProcAddress(libD3D11, "D3D11CreateDeviceAndSwapChain")) == NULL)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
					system("pause");
#endif		
					return;
				}

				D3D_FEATURE_LEVEL featureLevel;
				const D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_11_0 };

				DXGI_RATIONAL refreshRate;
				refreshRate.Numerator = 60;
				refreshRate.Denominator = 1;

				DXGI_MODE_DESC bufferDesc;
				bufferDesc.Width = 100;
				bufferDesc.Height = 100;
				bufferDesc.RefreshRate = refreshRate;
				bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
				bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
				bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

				DXGI_SAMPLE_DESC sampleDesc;
				sampleDesc.Count = 1;
				sampleDesc.Quality = 0;

				DXGI_SWAP_CHAIN_DESC swapChainDesc;
				swapChainDesc.BufferDesc = bufferDesc;
				swapChainDesc.SampleDesc = sampleDesc;
				swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
				swapChainDesc.BufferCount = 1;
				swapChainDesc.OutputWindow = window;
				swapChainDesc.Windowed = 1;
				swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
				swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

				IDXGISwapChain* swapChain;
				ID3D11Device* device;
				ID3D11DeviceContext* context;

				if (((long(__stdcall*)(
					IDXGIAdapter*,
					D3D_DRIVER_TYPE,
					HMODULE,
					UINT,
					const D3D_FEATURE_LEVEL*,
					UINT,
					UINT,
					const DXGI_SWAP_CHAIN_DESC*,
					IDXGISwapChain**,
					ID3D11Device**,
					D3D_FEATURE_LEVEL*,
					ID3D11DeviceContext**))(D3D11CreateDeviceAndSwapChain))(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, featureLevels, 1, D3D11_SDK_VERSION, &swapChainDesc, &swapChain, &device, &featureLevel, &context) < 0)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
					system("pause");
#endif		
					return;
				}

				g_methodsTable = (uintptr_t*)::calloc(205, sizeof(uintptr_t));
				::memcpy(g_methodsTable, *(uintptr_t**)swapChain, 18 * sizeof(uintptr_t));
				::memcpy(g_methodsTable + 18, *(uintptr_t**)device, 43 * sizeof(uintptr_t));
				::memcpy(g_methodsTable + 18 + 43, *(uintptr_t**)context, 144 * sizeof(uintptr_t));
				printf("D3D methods table initialized\n");

				printf("Present @ 0x%.12llX\n", g_methodsTable[8]);
				printf("ResizeBuffers @ 0x%.12llX\n", g_methodsTable[13]);

				swapChain->Release();
				swapChain = NULL;

				device->Release();
				device = NULL;

				context->Release();
				context = NULL;

				::DestroyWindow(window);
				::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);

				g_renderType = D3D11;

				return;
			}
			else if (g_renderType == NULL && ((D3DXX == 0) || (D3DXX == D3D12)))
			{
				printf("Checking for D3D12\n");

				HMODULE libDXGI;
				HMODULE libD3D12;
				if ((libDXGI = ::GetModuleHandle("dxgi.dll")) == NULL || (libD3D12 = ::GetModuleHandle("d3d12.dll")) == NULL)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Failed GetModuleHandle d3d11.dll or dxgi.dll\n");
					system("pause");
#endif	
					return;
				}

				void* CreateDXGIFactory;
				if ((CreateDXGIFactory = ::GetProcAddress(libDXGI, "CreateDXGIFactory")) == NULL)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
					system("pause");
#endif	
					return;
				}

				IDXGIFactory* factory;
				if (((long(__stdcall*)(const IID&, void**))(CreateDXGIFactory))(__uuidof(IDXGIFactory), (void**)&factory) < 0)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
					system("pause");
#endif	
					return;
				}

				IDXGIAdapter* adapter;
				if (factory->EnumAdapters(0, &adapter) == DXGI_ERROR_NOT_FOUND)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
					system("pause");
#endif	
					return;
				}

				void* D3D12CreateDevice;
				if ((D3D12CreateDevice = ::GetProcAddress(libD3D12, "D3D12CreateDevice")) == NULL)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
					system("pause");
#endif	
					return;
				}

				ID3D12Device* device;
				if (((long(__stdcall*)(IUnknown*, D3D_FEATURE_LEVEL, const IID&, void**))(D3D12CreateDevice))(adapter, D3D_FEATURE_LEVEL_11_0, __uuidof(ID3D12Device), (void**)&device) < 0)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
					system("pause");
#endif	
					return;
				}

				D3D12_COMMAND_QUEUE_DESC queueDesc;
				queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
				queueDesc.Priority = 0;
				queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
				queueDesc.NodeMask = 0;

				ID3D12CommandQueue* commandQueue;
				if (device->CreateCommandQueue(&queueDesc, __uuidof(ID3D12CommandQueue), (void**)&commandQueue) < 0)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
					system("pause");
#endif	
					return;
				}

				ID3D12CommandAllocator* commandAllocator;
				if (device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, __uuidof(ID3D12CommandAllocator), (void**)&commandAllocator) < 0)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
					system("pause");
#endif	
					return;
				}

				ID3D12GraphicsCommandList* commandList;
				if (device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, commandAllocator, NULL, __uuidof(ID3D12GraphicsCommandList), (void**)&commandList) < 0)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
					system("pause");
#endif	
					return;
				}

				DXGI_RATIONAL refreshRate;
				refreshRate.Numerator = 60;
				refreshRate.Denominator = 1;

				DXGI_MODE_DESC bufferDesc;
				bufferDesc.Width = 100;
				bufferDesc.Height = 100;
				bufferDesc.RefreshRate = refreshRate;
				bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
				bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
				bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

				DXGI_SAMPLE_DESC sampleDesc;
				sampleDesc.Count = 1;
				sampleDesc.Quality = 0;

				DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
				swapChainDesc.BufferDesc = bufferDesc;
				swapChainDesc.SampleDesc = sampleDesc;
				swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
				swapChainDesc.BufferCount = 2;
				swapChainDesc.OutputWindow = window;
				swapChainDesc.Windowed = 1;
				swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
				swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

				IDXGISwapChain* swapChain;
				if (factory->CreateSwapChain(commandQueue, &swapChainDesc, &swapChain) < 0)
				{
					::DestroyWindow(window);
					::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
#ifdef DbgMessages
					printf("Unknown error\n");
					system("pause");
#endif	
					return;
				}

				g_methodsTable = (uintptr_t*)::calloc(150, sizeof(uintptr_t));
				::memcpy(g_methodsTable, *(uintptr_t**)device, 44 * sizeof(uintptr_t));
				::memcpy(g_methodsTable + 44, *(uintptr_t**)commandQueue, 19 * sizeof(uintptr_t));
				::memcpy(g_methodsTable + 44 + 19, *(uintptr_t**)commandAllocator, 9 * sizeof(uintptr_t));
				::memcpy(g_methodsTable + 44 + 19 + 9, *(uintptr_t**)commandList, 60 * sizeof(uintptr_t));
				::memcpy(g_methodsTable + 44 + 19 + 9 + 60, *(uintptr_t**)swapChain, 18 * sizeof(uintptr_t));

				device->Release();
				device = NULL;

				commandQueue->Release();
				commandQueue = NULL;

				commandAllocator->Release();
				commandAllocator = NULL;

				commandList->Release();
				commandList = NULL;

				swapChain->Release();
				swapChain = NULL;

				::DestroyWindow(window);
				::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);

				g_renderType = D3D12;

				return;
			}

			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);

			return;
		}
	}
}

DX::D3DHooking::~D3DHooking()
{
	g_d3dHooking = nullptr;
}

int DX::D3DHooking::getRenderType()
{
	return g_d3dHooking->g_renderType;
}

uintptr_t* DX::D3DHooking::get_methodes_table()
{
	return g_d3dHooking->g_methodsTable;
}

//=========================================================================================================================//

DX::DX11Renderer::DX11Renderer()
{
	g_renderer = this;
}
DX::DX11Renderer::~DX11Renderer()
{
	g_renderer = nullptr;
}

//=========================================================================================================================//

HRESULT __stdcall DX::DX11Renderer::hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	static bool InitOnce = true;
	if (InitOnce)
	{
		printf("Present hook called\n");
		InitOnce = false;

		void* d3d_device{};
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), &d3d_device)))
		{
			g_renderer->m_d3d_device.Attach(static_cast<ID3D11Device*>(d3d_device));
		}
		else
		{
			throw std::runtime_error("Failed to get D3D device.");
		}

		g_renderer->m_d3d_device->GetImmediateContext(g_renderer->m_d3d_device_context.GetAddressOf());
		g_gui.init();
	}

	
	if (g_running)
	{
		g_gui.on_frame();
	}

	//auto res = g_renderer->oPresent(pSwapChain, SyncInterval, Flags);
	//return res;
	return g_hooking->m_swapchain_hook.get_original<decltype(&hkPresent)>(8)(pSwapChain, SyncInterval, Flags);
}

//=========================================================================================================================//

void DX::DX11Renderer::pre_reset()
{
	ImGui_ImplDX11_InvalidateDeviceObjects();
}

void DX::DX11Renderer::post_reset()
{
	ImGui_ImplDX11_CreateDeviceObjects();
}

void DX::DX11Renderer::resizeImGui()
{
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	float rescale = (io.DisplaySize.x * io.DisplaySize.y) / (1920.f * 1080.f);

	if (rescale > 1.0f)
		rescale = 1.f;

	if (g_gui.autoResize)
	{
		ImGui::GetStyle().ScaleAllSizes2(rescale);
		g_gui.tabFont->Scale = rescale;
		g_gui.textFont->Scale = rescale;
		g_gui.childHeaderFont->Scale = rescale;
	}
}

HRESULT __stdcall DX::DX11Renderer::hkResizebuffers(IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags)
{
	if (g_running)
	{
		printf("Resize Buffers hook called\n");

		g_renderer->pre_reset();

		auto result = g_hooking->m_swapchain_hook.get_original<decltype(&hkResizebuffers)>(13)(pSwapChain, BufferCount, Width, Height, NewFormat, SwapChainFlags);
		if (SUCCEEDED(result))
		{
			g_renderer->post_reset();
		}
		return result;
	}

	//return g_renderer->oResizebuffers(pSwapChain, BufferCount, Width, Height, NewFormat, SwapChainFlags);
	return g_hooking->m_swapchain_hook.get_original<decltype(&hkResizebuffers)>(13)(pSwapChain, BufferCount, Width, Height, NewFormat, SwapChainFlags);
}

//=========================================================================================================================//

IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT DX::DX11Renderer::wndproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	if (g_running)
	{
		if (msg == WM_KEYUP && wparam == VK_DELETE)
			if (g_gui.resourceInitDone)
				g_gui.m_opened = !g_gui.m_opened;

		if (g_gui.m_opened)
		{
			if (SUCCEEDED(ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam)))
				return 1L;
		}
	}

	return CallWindowProcW(g_renderer->oWndproc, hwnd, msg, wparam, lparam);
}

//=========================================================================================================================//