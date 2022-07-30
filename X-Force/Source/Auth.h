#pragma once
class MenuAuth
{
public:
	static int is_authed(const std::string& username, const std::string& password);
};

extern const char* current_version;
