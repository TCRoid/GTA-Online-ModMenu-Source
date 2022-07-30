#pragma once
#include "common.hpp"
namespace big
{
	class translates
	{
	public:
		explicit translates() = default;
		~translates() = default;

		nlohmann::json language;
		const char* get(const char* key)
		{
			if (language[key].is_string())
			{
				return language[key].get<std::string>().c_str();
			}
			else
			{
				return key;
			}
		}

		bool load(std::string translates_file)
		{
			translates_file = std::string(MENU_PATH) + "\\translates\\" + translates_file;
			std::ifstream file(translates_file);

			if (!file.is_open())
			{
				file.open(translates_file);
			}
			file >> language;
			return true;
		}
	private:
	};

	inline translates g_translates;

#define TRANSLATES(label) g_translates.get(label)
}