#include <Components\CRigidBody.h>
#include <jm_utility.h>

using namespace math_utils;


CRigidBody::CRigidBody(Vector2<float> _maxVelocity, Vector2<float> _maxForce) : maxVelocity(_maxVelocity), maxForce(_maxForce) {}


CRigidBody::~CRigidBody() {}

void CRigidBody::update(float dt) {
	// Clamp velocity
	m_velocity = Vector2<float>(clamp(m_velocity.x, 0.0f, maxVelocity.x), clamp(m_velocity.y, 0.0f, maxVelocity.y));
}

void CRigidBody::render() {}

void CRigidBody::addForce(float x, float y) {
	m_velocity.x += x;
	m_velocity.y += y;
}

void CRigidBody::addForce(Vector2<float> force) {
	m_velocity += force;
}

void CRigidBody::setMaxVelocity(Vector2<float> _maxVelocity) {
	maxVelocity = _maxVelocity;
}

void CRigidBody::setMaxForce(Vector2<float> _maxForce) {
	maxForce = _maxForce;
}
