#include"scripthookv.hpp"
namespace big::shv
{
	ScriptHookV::ScriptHookV()
	{
		if (GetModuleHandleA("ScriptHookV.dll") == NULL)
		{
			char buffer[64];
			sprintf_s(buffer, "%s\\dll\\ScriptHookV.dll", MENU_PATH);
			shvHmodule = LoadLibraryA(buffer);
			if (shvHmodule == NULL)
			{
				throw std::runtime_error("ScriptHookV装载失败");
			}
		}
		g_ScriptHookV = this;
	}

	ScriptHookV::~ScriptHookV()
	{
		for (HMODULE asi : asiHmodules)
		{
			FreeLibrary(asi);
			LOG(INFO) << "Asi卸载成功:" << asi;
		}
		g_ScriptHookV = nullptr;
	}

	bool ScriptHookV::loadAsi(std::string fileName)
	{
		char buffer[64];
		sprintf_s(buffer, "%s\\plugin\\%s.asi", MENU_PATH, fileName.c_str());
		HMODULE asiHmodule = LoadLibraryA(buffer);
		if (asiHmodule != NULL)
		{
			asiHmodules.push_back(asiHmodule);
			LOG(INFO) << fileName << "装载成功:" << asiHmodule;
			return true;
		}
		else
		{
			LOG(INFO) << fileName << "装载失败";
			return false;
		}
	}
}