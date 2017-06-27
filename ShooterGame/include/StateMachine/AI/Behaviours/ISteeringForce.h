#pragma once
#include <Vector2.h>

class CRigidBody;

class ISteeringForce {
	virtual Vector2<float> getForce(CRigidBody *obj) = 0;
};