#include "logger.h"

Logger::Logger()
{
	AllocConsole();
	freopen_s(&fp,"CONOUT$", "w", stdout);

	g_logger = this;
}

Logger::~Logger()
{
	FreeConsole();
	g_logger = nullptr;
}
