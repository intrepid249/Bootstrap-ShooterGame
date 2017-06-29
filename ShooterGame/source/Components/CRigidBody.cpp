#include <Components\CRigidBody.h>
#include <jm_utility.h>
#include <Utility.h>


CRigidBody::CRigidBody() : m_velocity(Vector2<float>(0, 0)) {
	setMaxForce();
	setMaxVelocity();
}


CRigidBody::~CRigidBody() {}

void CRigidBody::update(float dt) {
	// Clamp velocity
	m_velocity = Vector2<float>(
		math_utils::clamp(m_velocity.x, -m_maxVelocity.x, m_maxVelocity.x), 
		math_utils::clamp(m_velocity.y, -m_maxVelocity.y, m_maxVelocity.y));

	float rot = m_parent->getLocRot();

	//m_parent->translate(Vector2<float>(cosf(degToRad(rot)) * m_velocity.x * dt, sinf(degToRad(rot)* m_velocity.y * dt)));
	m_parent->translate(m_velocity * dt);
}

void CRigidBody::render() {}

void CRigidBody::addForce(float x, float y) {
	m_velocity.x += x;
	m_velocity.y += y;
}

void CRigidBody::addForce(Vector2<float> force) {
	m_velocity += force;
}

Vector2<float> CRigidBody::getVelocity() const {
	return m_velocity;
}

void CRigidBody::setMaxVelocity(Vector2<float> _maxVelocity) {
	m_maxVelocity = _maxVelocity;
}

Vector2<float> CRigidBody::getMaxVelocity() const {
	return m_maxVelocity;
}

void CRigidBody::setMaxForce(Vector2<float> _maxForce) {
	m_maxForce = _maxForce;
}

Vector2<float> CRigidBody::getMaxForce() const {
	return m_maxForce;
}
