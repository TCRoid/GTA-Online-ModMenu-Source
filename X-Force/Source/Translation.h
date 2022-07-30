#pragma once
#include "stdafx.h"

struct path_leaf_string
{
	std::string operator()(const std::experimental::filesystem::directory_entry& entry) const
	{
		return entry.path().filename().string();
	}
};

inline std::vector<std::string> get_files_in_dir(const std::string& dir)
{
	std::vector<std::string> out;
	std::experimental::filesystem::path p(dir);
	std::experimental::filesystem::directory_iterator start(p);
	std::experimental::filesystem::directory_iterator end;
	std::transform(start, end, std::back_inserter(out), path_leaf_string());
	return out;
}

class CTranslator {
private:
	nlohmann::json translations_;
public:
	void load(const std::string& file);
	std::string get(const std::string& str);
	void dump();
};

extern std::unique_ptr<CTranslator> translator;

#define lang(x) translator->get(x)