#pragma once
#include "ISteeringForce.h"

class CRigidBody;

class SteeringBehaviour :
	public ISteeringForce {
public:
	SteeringBehaviour();
	~SteeringBehaviour();

	Vector2<float> getForce(CRigidBody *obj);
};

