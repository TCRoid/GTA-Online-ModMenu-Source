#include "XMLStuff.h"

namespace fs = std::filesystem;
using namespace tinyxml2;

void XML::refreshXMLFiles()
{
	//std::filesystem::create_directories((std::string(getenv("APPDATA")) + "\\Cherax\\Vehicles"));
	//auto savepath = (std::string(getenv("APPDATA")) + "\\Cherax\\Vehicles\\" + name + ".xml");

	xmlVehicles.clear();
	std::string path = (std::string(getenv("APPDATA")) + "\\Cherax\\Vehicles\\");
	for (const auto& entry : fs::directory_iterator(path))
	{
		std::string str = entry.path().generic_string();
		if (str.find(".xml"))
		{
			std::size_t found = str.find_last_of(".xml");
			str = str.substr(0, found - 3);

			found = str.find_last_of("/\\");
			str = str.substr(found + 1);
			xmlVehicles.push_back(str);
		}
	}
		
}

tinyxml2::XMLError XML::save_current_vehicle(std::string name)
{
	VehicleData vehicle = g_vehicles.currVeh;

	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* pRoot;

	pRoot = doc.NewElement("Vehicle");
	doc.LinkEndChild(pRoot);
	pRoot->SetAttribute("name", vehicle.displayName.c_str());
	pRoot->SetAttribute("hash", vehicle.model);

	{
		tinyxml2::XMLElement* pColourElem = doc.NewElement("Colours");
		pRoot->LinkEndChild(pColourElem);
		{
			tinyxml2::XMLElement* pTempElem;

			if (pTempElem = doc.NewElement("Primary_Colour"))
			{
				pColourElem->LinkEndChild(pTempElem);
				pTempElem->SetAttribute("id", vehicle.colours.primary);
				pTempElem->SetAttribute("custom", vehicle.colours.isPrimaryCustom);
				pTempElem->SetAttribute("r", vehicle.colours.customPrimary.R);
				pTempElem->SetAttribute("g", vehicle.colours.customPrimary.G);
				pTempElem->SetAttribute("b", vehicle.colours.customPrimary.B);
			}
			if (pTempElem = doc.NewElement("Secondary_Colour"))
			{
				pColourElem->LinkEndChild(pTempElem);
				pTempElem->SetAttribute("id", vehicle.colours.secondary);
				pTempElem->SetAttribute("custom", vehicle.colours.isSecondaryCustom);
				pTempElem->SetAttribute("r", vehicle.colours.customSecondary.R);
				pTempElem->SetAttribute("g", vehicle.colours.customSecondary.G);
				pTempElem->SetAttribute("b", vehicle.colours.customSecondary.B);
			}
			if (pTempElem = doc.NewElement("Tyre_Smoke"))
			{
				pColourElem->LinkEndChild(pTempElem);
				pTempElem->SetAttribute("enabled", vehicle.togglemods.tyreSmoke);
				pTempElem->SetAttribute("r", vehicle.colours.tyreSmoke.R);
				pTempElem->SetAttribute("g", vehicle.colours.tyreSmoke.G);
				pTempElem->SetAttribute("b", vehicle.colours.tyreSmoke.B);
			}
			if (pTempElem = doc.NewElement("Neon_Lights"))
			{
				pColourElem->LinkEndChild(pTempElem);
				pTempElem->SetAttribute("left", vehicle.togglemods.neonLights[0]);
				pTempElem->SetAttribute("right", vehicle.togglemods.neonLights[1]);
				pTempElem->SetAttribute("front", vehicle.togglemods.neonLights[2]);
				pTempElem->SetAttribute("back", vehicle.togglemods.neonLights[3]);
				pTempElem->SetAttribute("r", vehicle.colours.neonLights.R);
				pTempElem->SetAttribute("g", vehicle.colours.neonLights.G);
				pTempElem->SetAttribute("b", vehicle.colours.neonLights.B);
			}
			if (pTempElem = doc.NewElement("Head_Lights"))
			{
				pColourElem->LinkEndChild(pTempElem);
				pTempElem->SetAttribute("enabled", vehicle.togglemods.xenonHeadLights);
				pTempElem->SetAttribute("id", vehicle.colours.headlights);			
			}
			if (pTempElem = doc.NewElement("Wheels"))
			{
				pColourElem->LinkEndChild(pTempElem);
				pTempElem->SetAttribute("type", vehicle.other.wheeltype);
				pTempElem->SetAttribute("id", vehicle.colours.wheels);
			}
			if (pTempElem = doc.NewElement("Window_Tint"))
			{
				pColourElem->LinkEndChild(pTempElem);
				pTempElem->SetAttribute("id", vehicle.colours.windowTint);
			}
			if (pTempElem = doc.NewElement("Pearlescent"))
			{
				pColourElem->LinkEndChild(pTempElem);
				pTempElem->SetAttribute("id", vehicle.colours.pearlescent);
			}
		}	
	}

	{
		tinyxml2::XMLElement* pOtherElem = doc.NewElement("Other");
		pRoot->LinkEndChild(pOtherElem);
		{
			tinyxml2::XMLElement* pTempElem;

			if (pTempElem = doc.NewElement("Plate_Text"))
			{
				pOtherElem->LinkEndChild(pTempElem);
				pTempElem->SetAttribute("id", vehicle.other.plateTextIndex);
				pTempElem->SetAttribute("text", vehicle.other.plateText.c_str());
			}
			if (pTempElem = doc.NewElement("Turbo"))
			{
				pOtherElem->LinkEndChild(pTempElem);
				pTempElem->SetAttribute("enabled", vehicle.togglemods.turbo);
			}
		}
	}

	{
		tinyxml2::XMLElement* pModElem = doc.NewElement("Mods");
		pRoot->LinkEndChild(pModElem);
		for (int i = 0; i < 49; i++)
		{
			std::string name = vehicle.mods[i].name.empty() ? "Unk" : vehicle.mods[i].name;
			name.erase(remove(name.begin(), name.end(), ' '), name.end());
			if (tinyxml2::XMLElement* pTempElem = doc.NewElement(name.c_str()))
			{
				pModElem->LinkEndChild(pTempElem);
				//pTempElem->SetAttribute("item_name", vehicle.mods[i].itemName.c_str());
				pTempElem->SetAttribute("id", vehicle.mods[i].index);
				//pTempElem->SetAttribute("item_options", vehicle.mods[i].options);
			}
		}
	}

	{
		tinyxml2::XMLElement* pAttachElem = doc.NewElement("Attachments");
		pRoot->LinkEndChild(pAttachElem);
		{
			if (tinyxml2::XMLElement* pObjElem = doc.NewElement("Objects"))
			{
				pAttachElem->LinkEndChild(pObjElem);

				tinyxml2::XMLElement* pTempElem;
				for (ObjectAttachInfo attach : vehicle.attachments.objectsAttached)
				{
					if (pTempElem = doc.NewElement("Model"))
					{
						pObjElem->LinkEndChild(pTempElem);
						pTempElem->SetAttribute("hash", attach.model);
					}
					if (pTempElem = doc.NewElement("Coords"))
					{
						pObjElem->LinkEndChild(pTempElem);
						pTempElem->SetAttribute("x", attach.X);
						pTempElem->SetAttribute("y", attach.Y);
						pTempElem->SetAttribute("z", attach.Z);
					}
					if (pTempElem = doc.NewElement("Rotation"))
					{
						pObjElem->LinkEndChild(pTempElem);
						pTempElem->SetAttribute("pitch", attach.Pitch);
						pTempElem->SetAttribute("roll", attach.Roll);
						pTempElem->SetAttribute("yaw", attach.Yaw);
					}
					if (pTempElem = doc.NewElement("Bone"))
					{
						pObjElem->LinkEndChild(pTempElem);
						pTempElem->SetAttribute("id", attach.boneIndex);
					}
					if (pTempElem = doc.NewElement("Toggles"))
					{
						pObjElem->LinkEndChild(pTempElem);
						pTempElem->SetAttribute("invis", attach.invis);
						pTempElem->SetAttribute("dynamic", attach.dynamic);
						pTempElem->SetAttribute("collisionEnabled", attach.collisionEnabled);
						pTempElem->SetAttribute("destroyVar", attach.destroyVar);
					}
				}
			}

			if (tinyxml2::XMLElement* pVehElem = doc.NewElement("Vehicles"))
			{
				pAttachElem->LinkEndChild(pVehElem);

				tinyxml2::XMLElement* pTempElem;
				for (VehicleAttachInfo attach : vehicle.attachments.vehiclesAttached)
				{
					if (pTempElem = doc.NewElement("Model"))
					{
						pVehElem->LinkEndChild(pTempElem);
						pTempElem->SetAttribute("hash", attach.model);
					}
					if (pTempElem = doc.NewElement("Coords"))
					{
						pVehElem->LinkEndChild(pTempElem);
						pTempElem->SetAttribute("x", attach.X);
						pTempElem->SetAttribute("y", attach.Y);
						pTempElem->SetAttribute("z", attach.Z);
					}
					if (pTempElem = doc.NewElement("Rotation"))
					{
						pVehElem->LinkEndChild(pTempElem);
						pTempElem->SetAttribute("pitch", attach.Pitch);
						pTempElem->SetAttribute("roll", attach.Roll);
						pTempElem->SetAttribute("yaw", attach.Yaw);
					}
					if (pTempElem = doc.NewElement("Bone"))
					{
						pVehElem->LinkEndChild(pTempElem);
						pTempElem->SetAttribute("id", attach.boneIndex);
					}
					if (pTempElem = doc.NewElement("Colours"))
					{
						pVehElem->LinkEndChild(pTempElem);
						pTempElem->SetAttribute("primary", attach.primCol);
						pTempElem->SetAttribute("secondary", attach.secCol);
					}
					if (pTempElem = doc.NewElement("Toggles"))
					{
						pVehElem->LinkEndChild(pTempElem);
						pTempElem->SetAttribute("invis", attach.invis);
						pTempElem->SetAttribute("dynamic", attach.dynamic);
						pTempElem->SetAttribute("collisionEnabled", attach.collisionEnabled);
					}
				}
			}
		}
	}

	std::filesystem::create_directories((std::string(getenv("APPDATA")) + "\\Cherax\\Vehicles"));
	auto savepath = (std::string(getenv("APPDATA")) + "\\Cherax\\Vehicles\\" + name + ".xml");
	auto res = doc.SaveFile(savepath.c_str());
	return res;
}

void XML::delete_xml_file(std::string file)
{
	std::string filePath = (std::string(getenv("APPDATA")) + "\\Cherax\\Vehicles\\" + file + ".xml");
	remove(filePath.c_str());
}

VehicleData XML::load_vehicle(std::string name)
{
	VehicleData vehicle;

	tinyxml2::XMLDocument doc;
	auto res = doc.LoadFile(name.c_str());

	tinyxml2::XMLElement* pRoot;
	if (pRoot = doc.RootElement())
	{
		if (pRoot->QueryAttribute("hash", &vehicle.model)) {};

		tinyxml2::XMLElement* pSeblingIterator;
		if (pSeblingIterator = pRoot->FirstChildElement())
		{
			tinyxml2::XMLElement* pTempElem;

			if (pTempElem = pSeblingIterator->FirstChildElement())
			{
				if (pTempElem->QueryAttribute("id", &vehicle.colours.primary)) {};
				if (pTempElem->QueryAttribute("custom", &vehicle.colours.isPrimaryCustom)) {};
				if (pTempElem->QueryAttribute("r", &vehicle.colours.customPrimary.R)) {};
				if (pTempElem->QueryAttribute("g", &vehicle.colours.customPrimary.G)) {};
				if (pTempElem->QueryAttribute("b", &vehicle.colours.customPrimary.B)) {};
			}
			if (pTempElem = pTempElem->NextSiblingElement())
			{
				if (pTempElem->QueryAttribute("id", &vehicle.colours.secondary)) {};
				if (pTempElem->QueryAttribute("custom", &vehicle.colours.isSecondaryCustom)) {};
				if (pTempElem->QueryAttribute("r", &vehicle.colours.customSecondary.R)) {};
				if (pTempElem->QueryAttribute("g", &vehicle.colours.customSecondary.G)) {};
				if (pTempElem->QueryAttribute("b", &vehicle.colours.customSecondary.B)) {};
			}
			if (pTempElem = pTempElem->NextSiblingElement())
			{
				if (pTempElem->QueryAttribute("enabled", &vehicle.togglemods.tyreSmoke)) {};
				if (pTempElem->QueryAttribute("r", &vehicle.colours.tyreSmoke.R)) {};
				if (pTempElem->QueryAttribute("g", &vehicle.colours.tyreSmoke.G)) {};
				if (pTempElem->QueryAttribute("b", &vehicle.colours.tyreSmoke.B)) {};
			}
			if (pTempElem = pTempElem->NextSiblingElement())
			{
				if (pTempElem->QueryAttribute("left", &vehicle.togglemods.neonLights[0])) {};
				if (pTempElem->QueryAttribute("right", &vehicle.togglemods.neonLights[1])) {};
				if (pTempElem->QueryAttribute("front", &vehicle.togglemods.neonLights[2])) {};
				if (pTempElem->QueryAttribute("back", &vehicle.togglemods.neonLights[3])) {};
				if (pTempElem->QueryAttribute("r", &vehicle.colours.neonLights.R)) {};
				if (pTempElem->QueryAttribute("g", &vehicle.colours.neonLights.G)) {};
				if (pTempElem->QueryAttribute("b", &vehicle.colours.neonLights.B)) {};
			}
			if (pTempElem = pTempElem->NextSiblingElement())
			{
				if (pTempElem->QueryAttribute("enabled", &vehicle.togglemods.xenonHeadLights)) {};
				if (pTempElem->QueryAttribute("id", &vehicle.colours.headlights)) {};			
			}
			if (pTempElem = pTempElem->NextSiblingElement())
			{
				if (pTempElem->QueryAttribute("type", &vehicle.other.wheeltype)) {};
				if (pTempElem->QueryAttribute("id", &vehicle.colours.wheels)) {};
			}
			if (pTempElem = pTempElem->NextSiblingElement())
			{
				if (pTempElem->QueryAttribute("id", &vehicle.colours.windowTint)) {};
			}
			if (pTempElem = pTempElem->NextSiblingElement())
			{
				if (pTempElem->QueryAttribute("id", &vehicle.colours.pearlescent)) {};
			}
		}
		if (pSeblingIterator = pSeblingIterator->NextSiblingElement())
		{
			tinyxml2::XMLElement* pTempElem;

			if (pTempElem = pSeblingIterator->FirstChildElement())
			{
				if (pTempElem->QueryAttribute("id", &vehicle.other.plateTextIndex)) {};
				vehicle.other.plateText = pTempElem->Attribute("text");		
			}
			if (pTempElem = pTempElem->NextSiblingElement())
			{
				if (pTempElem->QueryAttribute("enabled", &vehicle.togglemods.turbo)) {};
			}
		}
		if (pSeblingIterator = pSeblingIterator->NextSiblingElement())
		{
			tinyxml2::XMLElement* pTempElem;

			if (pTempElem = pSeblingIterator->FirstChildElement())
			{
				if (pTempElem->QueryAttribute("id", &vehicle.mods[0].index)) {};
			}
			for (int i = 1; i < 49; i++)
			{
				if (pTempElem = pTempElem->NextSiblingElement())
				{
					if (pTempElem->QueryAttribute("id", &vehicle.mods[i].index)) {};
				}
			}			
		}
	}

	return vehicle;
}
