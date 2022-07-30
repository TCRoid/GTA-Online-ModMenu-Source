#pragma once

#include <string>
#include <vector>

namespace TeleportLocations
{
	class TeleLocation
	{
	public:
		std::string name;
		float x;
		float y;
		float z;
		std::vector<const char*> iplsToLoad;
		std::vector<const char*> iplsToRemove;
		std::vector<const char*> interiorProps;
		bool bOnTheLine;
		bool bOffTheLine;
		bool bInterior;
	public:
		TeleLocation(bool pbOnTheLine, float pX, float pY, float pZ, const std::string& pName)
			: name(pName), x(pX), y(pY), z(pZ), bOnTheLine(pbOnTheLine), bOffTheLine(false), bInterior(false)
		{
		}
		TeleLocation(const std::string& pName, float pX, float pY, float pZ, bool pbOnTheLine = false, bool pbOffTheLine = false, bool pbInterior = false)
			: name(pName), x(pX), y(pY), z(pZ), bOnTheLine(pbOnTheLine), bOffTheLine(pbOffTheLine), bInterior(pbInterior)
		{
		}
		TeleLocation(const std::string& pName, float pX, float pY, float pZ, std::vector<const char*> pIplsToLoad, std::vector<const char*> pIplsToRemove, bool pbOnTheLine = false, bool pbOffTheLine = false, bool pbInterior = false)
			: name(pName), x(pX), y(pY), z(pZ), iplsToLoad(pIplsToLoad), iplsToRemove(pIplsToRemove), bOnTheLine(pbOnTheLine), bOffTheLine(pbOffTheLine), bInterior(pbInterior)
		{
		}
		TeleLocation(const std::string& pName, float pX, float pY, float pZ, std::vector<const char*> pIplsToLoad, std::vector<const char*> pIplsToRemove, std::vector<const char*> pInteriorProps, bool pbOnTheLine = false, bool pbOffTheLine = false, bool pbInterior = false)
			: name(pName), x(pX), y(pY), z(pZ), iplsToLoad(pIplsToLoad), iplsToRemove(pIplsToRemove), interiorProps(pInteriorProps), bOnTheLine(pbOnTheLine), bOffTheLine(pbOffTheLine), bInterior(pbInterior)
		{
		}
	};

	class NamedTeleLocationList
	{
	public:
		std::string categoryName;
		const std::vector<TeleLocation>* locList_ptr;
		const std::vector<NamedTeleLocationList>* nextNamedLocListList;
	};

}
