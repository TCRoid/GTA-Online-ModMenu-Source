#pragma once

#include "TeleLocation.h"

#include <string>
#include <vector>

namespace TeleportLocations
{
	class TeleLocation;
	class NamedTeleLocationList;

	namespace IplNames
	{
		extern const std::vector<const char*> vYacht_Smboat1;
		extern const std::vector<const char*> vYacht_Heist1;
		extern const std::vector<const char*> vYacht_Heist2;
		extern const std::vector<const char*> vAircraftCarrier1;
		extern const std::vector<const char*> vNorthYankton;
		extern const std::vector<const char*> vAllCustomisableApartments1;
		extern const std::vector<const char*> vAllOffices1;
		extern const std::vector<const char*> vAllOfficeGarages1;
	}

	namespace Locations
	{
		extern const std::vector<TeleLocation> vApartmentInteriors;
		extern const std::vector<NamedTeleLocationList> vAllCategories;
	}

	namespace restore
	{
		inline std::vector<const char*> IplsToRemove;
		inline std::vector<const char*> IplsToLoad;
	}

}