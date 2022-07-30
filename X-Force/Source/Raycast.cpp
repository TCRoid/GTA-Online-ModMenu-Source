#include "stdafx.h"

/*
* Copyright (C) 2015 crosire
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*/
/*
* ALTERED SOURCE
* Menyoo PC - Grand Theft Auto V single-player trainer mod
* Copyright (C) 2019  MAFINS
*/
#include "Raycast.h"
//#include "GTAped.h"
//#include "GTAvehicle.h"

RaycastResult::RaycastResult()
	: mResult(0), mDidHit(false)
{
}

RaycastResult::RaycastResult(const RaycastResult& handle)
	: mResult(handle.mResult), mDidHit(handle.mDidHit), mHitEntity(handle.mHitEntity), mHitCoords(handle.mHitCoords), mSurfaceNormal(handle.mSurfaceNormal)
{
}

RaycastResult::RaycastResult(int handle)
{
	int hitsomething = 0;
	int enthandle = 0;
	Vector3 hitCoords, surfaceNormal;

	this->mResult = WORLDPROBE::GET_SHAPE_TEST_RESULT(handle, &hitsomething, &hitCoords, &surfaceNormal, &enthandle);

	this->mDidHit = hitsomething != 0;
	this->mHitCoords = hitCoords;
	this->mSurfaceNormal = surfaceNormal;

	if (ENTITY::DOES_ENTITY_EXIST(enthandle) && (ENTITY::IS_ENTITY_A_PED(enthandle) || ENTITY::IS_ENTITY_A_VEHICLE(enthandle) || ENTITY::IS_ENTITY_AN_OBJECT(enthandle)))
	{
		this->mHitEntity = enthandle;
	}
	else
	{
		this->mHitEntity = NULL;

	}
}


int RaycastResult::Result()
{
	return this->mResult;
}
bool RaycastResult::DidHitEntity()
{
	return mHitEntity != 0;
}
bool RaycastResult::DidHitAnything()
{
	return this->mDidHit;
}
Entity RaycastResult::HitEntity()
{
	return this->mHitEntity;
}
Vector3 RaycastResult::HitCoords()
{
	return this->mHitCoords;
}
Vector3 RaycastResult::SurfaceNormal()
{
	return this->mSurfaceNormal;
}


RaycastResult RaycastResult::Raycast(const Vector3 source, const Vector3 target, IntersectOptions options, Entity ignoreEntity)
{
	return RaycastResult(WORLDPROBE::_CAST_RAY_POINT_TO_POINT(source.x, source.y, source.z, target.x, target.y, target.z, static_cast<int>(options), ignoreEntity, 7));
}
RaycastResult RaycastResult::Raycast(const Vector3& source, const Vector3& direction, float maxDistance, IntersectOptions options, Entity ignoreEntity)
{
	Vector3 kekk;
	kekk.x = direction.x * maxDistance;
	kekk.y = direction.y * maxDistance;
	kekk.z = direction.z * maxDistance;
	Vector3 kekkk;
	kekkk.x = source.x + kekk.x;
	kekkk.y = source.y + kekk.y;
	kekkk.z = source.z + kekk.z;
	Vector3& target = kekkk;
	return RaycastResult(WORLDPROBE::_CAST_RAY_POINT_TO_POINT(source.x, source.y, source.z, target.x, target.y, target.z, static_cast<int>(options), ignoreEntity, 7));
}
RaycastResult RaycastResult::RaycastCapsule(const Vector3& source, const Vector3& target, float radius, IntersectOptions options, Entity ignoreEntity)
{
	return RaycastResult(WORLDPROBE::START_SHAPE_TEST_CAPSULE(source.x, source.y, source.z, target.x, target.y, target.z, radius, static_cast<int>(options), ignoreEntity, 7));
}
RaycastResult RaycastResult::RaycastCapsule(const Vector3& source, const Vector3& direction, float maxDistance, float radius, IntersectOptions options, Entity ignoreEntity)
{
	Vector3 kekk;
	kekk.x = direction.x * maxDistance;
	kekk.y = direction.y * maxDistance;
	kekk.z = direction.z * maxDistance;
	Vector3 kekkk;
	kekkk.x = source.x + kekk.x;
	kekkk.y = source.y + kekk.y;
	kekkk.z = source.z + kekk.z;
	Vector3& target = kekkk;
	return RaycastResult(WORLDPROBE::START_SHAPE_TEST_CAPSULE(source.x, source.y, source.z, target.x, target.y, target.z, radius, static_cast<int>(options), ignoreEntity, 7));
}


