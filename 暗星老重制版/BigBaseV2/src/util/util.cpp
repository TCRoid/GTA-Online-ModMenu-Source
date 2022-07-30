#include"util.hpp"
#include <pointers.hpp>

namespace big::util
{
	rage::Blip_t* getBlipObjective()
	{
		rage::Blip_t* r = nullptr;
		for (int i = 0; i < 0x400; i++)
		{
			if (rage::BlipList* blipList = g_pointers->m_blip_list)
			{
				if (rage::Blip_t* blip = blipList->m_Blips[i].m_pBlip)
				{
					auto colour = blip->m_color;
					auto icon = blip->m_icon;

					if ((colour == ColorYellowMission && icon == SpriteStandard) ||
						(colour == ColorYellowMission2 && icon == SpriteStandard) ||
						(colour == ColorYellow && icon == SpriteStandard) ||
						(colour == ColorWhite && icon == SpriteRaceFinish) ||
						(colour == ColorGreen && icon == SpriteStandard) ||
						(colour == ColorBlue && icon == SpriteStandard) ||
						(icon == SpriteCrateDrop))

					{
						r = blip;
						break;
					}
				}
			}
		}
		return r;
	}
	Vector3 getBlipMarker()
	{
		static Vector3 zero;
		Vector3 coords;

		bool blipFound = false;
		int blipIterator = HUD::_GET_WAYPOINT_BLIP_SPRITE();
		for (Blip i = HUD::GET_FIRST_BLIP_INFO_ID(blipIterator); HUD::DOES_BLIP_EXIST(i) != 0; i = HUD::GET_NEXT_BLIP_INFO_ID(blipIterator))
		{
			if (HUD::GET_BLIP_INFO_ID_TYPE(i) == 4)
			{
				coords = HUD::GET_BLIP_INFO_ID_COORD(i);
				blipFound = true;
				break;
			}
		}
		if (blipFound)
		{
			return coords;
		}

		return zero;
	}
	char* vehlablename(const char* name)
	{
		return (char*)HUD::_GET_LABEL_TEXT(name);
	}
	float degToRad(float degs)
	{
		return degs * 3.141592653589793f / 180.f;
	}
	ImVec2 addImVec2(ImVec2* vectorA, ImVec2* vectorB)
	{
		ImVec2 result;
		result.x = vectorA->x;
		result.y = vectorA->y;
		result.x += vectorB->x;
		result.y += vectorB->y;
		return result;
	}

	Vector3 rottt_to_direction(Vector3* rot)
	{
		float radiansZ = rot->z * 0.0174532924f;
		float radiansX = rot->x * 0.0174532924f;
		float num = std::abs((float)std::cos((double)radiansX));
		Vector3 dir;
		dir.x = (float)((double)((float)(-(float)std::sin((double)radiansZ))) * (double)num);
		dir.y = (float)((double)((float)std::cos((double)radiansZ)) * (double)num);
		dir.z = (float)std::sin((double)radiansX);
		return dir;
	}

	Vector3 multiply(Vector3* vector, float x) {
		Vector3 result;
		result.x = vector->x;
		result.y = vector->y;
		result.z = vector->z;
		result.x *= x;
		result.y *= x;
		result.z *= x;
		return result;
	}

	Vector3 add(Vector3* vectorA, Vector3* vectorB) {
		Vector3 result;
		result.x = vectorA->x;
		result.y = vectorA->y;
		result.z = vectorA->z;
		result.x += vectorB->x;
		result.y += vectorB->y;
		result.z += vectorB->z;
		return result;
	}

	Vector3 CombineVector(float x, float y, float z)
	{
		Vector3 returnVector;
		returnVector.x = x;
		returnVector.y = y;
		returnVector.z = z;
		return returnVector;
	}

	double wDegreeToRadian(double n) {
		return n * 0.017453292519943295;
	}

	void requestControlOfid(Entity netid)
	{
		int tick = 0;

		while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
		{
			NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
			tick++;
		}
	}

	void requestControlOfEnt(Entity entity)
	{
		int tick = 0;
		while (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(entity) && tick <= 25)
		{
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(entity);
			tick++;
		}
		if (NETWORK::NETWORK_IS_SESSION_STARTED())
		{
			int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(entity);
			requestControlOfid(netID);
			NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
		}
	}

	void applyForceToEntity(Entity e, float x, float y, float z)
	{
		if (e != PLAYER::PLAYER_PED_ID() && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(e) == FALSE)
		{
			requestControlOfEnt(e);
		}

		ENTITY::APPLY_FORCE_TO_ENTITY(e, 1, x, y, z, 0, 0, 0, 0, 1, 1, 1, 0, 1);
	}

	Vector3 wRotationToDirection(Vector3 rot) {
		double num = wDegreeToRadian(rot.z);
		double num2 = wDegreeToRadian(rot.x);
		double val = cos(num2);
		double num3 = abs(val);
		rot.x = (float)(-(float)sin(num) * num3);
		rot.y = (float)(cos(num) * num3);
		rot.z = (float)sin(num2);
		return rot;
	}

	Vector3 waddVector(Vector3 vector, Vector3 vector2) {
		vector.x += vector2.x;
		vector.y += vector2.y;
		vector.z += vector2.z;
		return vector;
	}

	Vector3 wmultiplyVector(Vector3 vector, float inc) {
		vector.x *= inc;
		vector.y *= inc;
		vector.z *= inc;
		return vector;
	}

	Object createObject(char* ObjectName, Vector3 Coordinates)
	{
		Object returnObj{};
		Hash ObjectHash = MISC::GET_HASH_KEY(ObjectName);
		if (STREAMING::IS_MODEL_IN_CDIMAGE(ObjectHash))
		{
			if (STREAMING::IS_MODEL_VALID(ObjectHash))
			{
				STREAMING::REQUEST_MODEL(ObjectHash);
				if (STREAMING::HAS_MODEL_LOADED(ObjectHash))
				{
					returnObj = OBJECT::CREATE_OBJECT(ObjectHash, Coordinates.x, Coordinates.y, Coordinates.z, 1, 1, 0);
				}
				else
				{
					returnObj = 0;
				}
			}
		}
		return returnObj;
	}
}