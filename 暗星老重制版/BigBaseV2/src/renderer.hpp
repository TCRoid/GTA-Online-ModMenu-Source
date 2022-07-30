#pragma once
#include "common.hpp"
#include <imgui.h>

namespace big
{
	struct imgDimensions
	{
		int     x, y;
		imgDimensions() { x = y = 0; }
		imgDimensions(int _x, int _y) { x = _x; y = _y; }
	};
	class renderer
	{
	public:
		explicit renderer();
		~renderer();

		void on_present();
		void inittexture();
		void pre_reset();
		void post_reset();

		void wndproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
		bool LoadTextureFromFile(const char* filename, ID3D11ShaderResourceView** out_srv, int* w, int* h);
	public:
		ImFont* m_font;
		ImFont* m_title_font;
		ImFont* m_monospace_font;
		ID3D11ShaderResourceView* ImageHeader{};
		imgDimensions pHeaderSize = { 0, 0 };
	private:
		comptr<IDXGISwapChain> m_dxgi_swapchain;
		comptr<ID3D11Device> m_d3d_device;
		comptr<ID3D11DeviceContext> m_d3d_device_context;
	};

	inline renderer* g_renderer{};
}