#pragma once
namespace big::shv
{
	class ScriptHookV
	{
	public:
		ScriptHookV();
		~ScriptHookV();
		bool loadAsi(std::string fileName);
	private:
		HMODULE shvHmodule;
		std::vector<HMODULE> asiHmodules;
	};
	inline ScriptHookV* g_ScriptHookV;
}