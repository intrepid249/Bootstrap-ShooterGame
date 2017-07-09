#pragma once
#include <Vector2.h>

class CRigidBody;
class GameEntity;

class ISteeringForce {
public:
	ISteeringForce() : m_targetPos(Vector2<float>(-1, -1)), m_targetObj(nullptr), m_agroRange(-1) {}
	virtual ~ISteeringForce() = default;

	virtual Vector2<float> getForce() const = 0;

	void setAgroRange(float _val) { m_agroRange = _val; }
	float getAgroRange() const { return m_agroRange; }

protected:
	float m_agroRange;
	Vector2<float> m_targetPos;
	GameEntity *m_targetObj;
};