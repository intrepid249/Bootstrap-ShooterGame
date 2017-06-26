#pragma once
#include "CComponent.h"
#include <Vector2.h>

namespace aie {
	class Renderer2D;
}

class CRigidBody :
	public CComponent {
public:
	CRigidBody();
	virtual ~CRigidBody();

	void update(float dt);
	void render();

	/** Increase the objects velocity by a force*/
	void addForce(float x, float y);
	void addForce(Vector2<float> force);

private:
	Vector2<float> m_velocity, maxVelocity;

};

