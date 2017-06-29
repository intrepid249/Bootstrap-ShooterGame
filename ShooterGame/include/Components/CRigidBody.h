#pragma once
#include "CComponent.h"
#include <Nodes\Node.h>
#include <Vector2.h>

namespace aie {
	class Renderer2D;
}

class CRigidBody :
	public CComponent, public Node {
public:
	CRigidBody();
	virtual ~CRigidBody();

	void update(float dt);
	void render();

	/** Increase the objects velocity by a force*/
	void addForce(float x, float y);
	void addForce(Vector2<float> force);

	Vector2<float> getVelocity() const;

	void setMaxVelocity(Vector2<float> _maxVelocity = Vector2<float>(150, 150));
	Vector2<float> getMaxVelocity() const;

	void setMaxForce(Vector2<float> _maxForce = Vector2<float>(20, 20));
	Vector2<float> getMaxForce() const;

private:
	Vector2<float> m_velocity, m_maxVelocity, m_maxForce;

};

