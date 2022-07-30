#pragma once

namespace big::util
{
	float degToRad(float degs);
	ImVec2 addImVec2(ImVec2* vectorA, ImVec2* vectorB);
	Vector3 rottt_to_direction(Vector3* rot);
	Vector3 multiply(Vector3* vector, float x);
	Vector3 add(Vector3* vectorA, Vector3* vectorB);
	Vector3 CombineVector(float x, float y, float z);
	double wDegreeToRadian(double n);
	void requestControlOfid(Entity netid);
	void requestControlOfEnt(Entity entity);
	void applyForceToEntity(Entity e, float x, float y, float z);
	Vector3 wRotationToDirection(Vector3 rot);
	Vector3 waddVector(Vector3 vector, Vector3 vector2);
	Vector3 wmultiplyVector(Vector3 vector, float inc);
	Object createObject(char* ObjectName, Vector3 Coordinates);
	char* vehlablename(const char* name);
	rage::Blip_t* getBlipObjective();
	Vector3 getBlipMarker();
}