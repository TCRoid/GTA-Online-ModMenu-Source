#include "stdafx.h"
struct IUnknown;
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_ERRORS
#pragma warning(disable: 4996)
#include <iostream>
#include <string>
#include <Windows.h>
#include <atlutil.h>
#include <sstream>
#include <iomanip>
#include <locale>
#include <codecvt>
#include <chrono>
#include <stdlib.h>
#include <stdio.h>
#include "Auth/Networking/sha512.hh"
#include "Auth/Networking/WinHttpClient.h"
#include "Auth/Networking/Web2.0.h"
using std::string;
#define URL L"klexxy.bplaced.net/menu/auth.php"

const char* staff_version = "Ak2YwshAQyldGnBN6KodnE6VLQINRTKlyRqTZaTaZMXJp";
const char* dev_version = "bVvr3f4XPVGWhEmnkxR933mQqFnunItaWtc76wO2FpXn1";
const char* pro_version = "uE7V7WkEQI32AUYWDydrsqLKOpA6fui7SrJyNu4KN6OSV";
const char* normal_version = "v1TVNBpLXX1jhJRqokFHP13NATC4afqR8yGdFON4YSE90";
const char* bad_version = "8cCAxwZVSiHY4MwojfK3YNKCVzhTPw2gYDT6erpIqUZ6m";
const char* no_version = "r5Jv0wid8Q7HJAcpFDSvAeoCOiC3j0uQzI4m6OUepgdLz";

const char* current_version = no_version;

std::wstring StringToWString(const std::string &s)
{
	std::wstring wsTmp(s.begin(), s.end());
	return wsTmp;
}

int MenuAuth::is_authed(const std::string& username, const std::string& password) {
	char hwid[4096];
	char* HWID;
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	sprintf_s(hwid, "%I64i", statex.ullTotalPhys / 1024);

	TCHAR volumename[MAX_PATH + 1] = { 0 };
	TCHAR filesystemname[MAX_PATH + 1] = { 0 };
	DWORD serialnumber = 0, maxcomponentlen = 0, filesystemflags = 0;
	sprintf_s(hwid, "a%s%li%ws%li", hwid, serialnumber, filesystemname,
		maxcomponentlen);

	TCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName) / sizeof(computerName[0]);
	GetComputerName(computerName, &size);
	sprintf_s(hwid, "%s%ws", hwid, computerName);
	HWID = (char*)sw::sha512::calculate(hwid).c_str();

	net::requests m_request(
			L"X-Force ist das beste Menu dass es jemals geben wird amk xd",
			false);
	auto answer = m_request.Post(false,
	URL, "?HTsXP=%s", HWID);

	Log::Msg(sw::sha512::calculate(hwid).c_str());
	Log::Msg((char*)answer.c_str());

	if (answer == L"bVvr3f4XPVGWhEmnkxR933mQqFnunItaWtc76wO2FpXn1") {
		Log::Msg("Authed as Dev");
		current_version = dev_version;
	}
	if (answer == L"Ak2YwshAQyldGnBN6KodnE6VLQINRTKlyRqTZaTaZMXJp") {
		Log::Msg("Authed as Staff");
		current_version = staff_version;
	}
	if (answer == L"uE7V7WkEQI32AUYWDydrsqLKOpA6fui7SrJyNu4KN6OSV") {
		Log::Msg("Authed as Pro");
		current_version = pro_version;
	}
	if (answer == L"v1TVNBpLXX1jhJRqokFHP13NATC4afqR8yGdFON4YSE90") {
		Log::Msg("Authed as Normal");
		current_version = pro_version;
	}
	if (answer == L"8cCAxwZVSiHY4MwojfK3YNKCVzhTPw2gYDT6erpIqUZ6m") {
		Log::Msg("Banned from X-Force");
		current_version = no_version;
		exit(0);
	}
	if (answer == L"r5Jv0wid8Q7HJAcpFDSvAeoCOiC3j0uQzI4m6OUepgdLz") {
		Log::Msg("No Menu Access");
		current_version = no_version;
		exit(0);
	}

	return 0;
}