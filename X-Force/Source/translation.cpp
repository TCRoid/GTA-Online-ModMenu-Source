#include "stdafx.h"
#include "Translation.h"

#include "JSON/json.hpp"
using json = nlohmann::json;

std::unique_ptr<CTranslator> translator = std::make_unique<CTranslator>();


void CTranslator::load(const std::string& file)
{
	std::ostringstream path;
	path << get_gta_dir() << "\\X-Force\\translations\\" << file;
	std::ifstream i(path.str());
	if (!i.good()) return;
	i >> translations_;
}

std::string CTranslator::get(const std::string& str)
{
	try {
		auto trans = translations_[str].get<std::string>();

		if (!trans.empty()) {
			return trans;
		}
		else {
			return str;
		}
	}
	catch (...) {
		return str;
	}
}

void CTranslator::dump()
{
	std::ostringstream dmp;
	dmp << std::setw(4) << translations_;
	Log::Msg("%s", dmp.str().c_str());
}