#pragma once
#include "common.h"
#include "vehicles.h"

namespace XML
{
	inline std::vector<std::string> xmlVehicles;
	void refreshXMLFiles();
	

	tinyxml2::XMLError save_current_vehicle(std::string name);
	void delete_xml_file(std::string file);
	VehicleData load_vehicle(std::string name);
}