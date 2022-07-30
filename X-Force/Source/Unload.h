#pragma once
namespace Unload {
	extern LPVOID yoink;
	extern bool do_it;
	void unload_handler();
	DWORD WINAPI main(const LPVOID lpvoid);
}