#include <StateMachine\AI\AISeekState.h>
#include <Entities\GameEntity.h>
#include <jm_utility.h>
#include <Components\CRigidBody.h>
#include <Components\CSpriteNode.h>

#include <Input.h>

AISeekState::AISeekState(GameEntity *_parent) : IAIState(_parent), ISteeringForce() {
}


AISeekState::~AISeekState() {
}

void AISeekState::entryActions() {
}

void AISeekState::doActions(float dt) {

	// TODO: fix so that it updates for the target moving around (i.e. player.)
	// For some reason it only remembers where it originally sees the player

	m_parent->getComponentOfType<CRigidBody>()->addForce(getForce());

	// Rotate to face direction
	Vector2<float> myPos = m_parent->calculateGlobalTransform().getTranslation();
	Vector2<float> dir = m_targetPos - myPos;
	

	// TODO: Rotate according to current velocity direction -> will need to modify sprite component
}

void AISeekState::exitActions() {
}

const char * AISeekState::checkConditions() {
	if (m_targetObj != nullptr)
		m_targetPos = m_targetObj->calculateGlobalTransform().getTranslation();

	if (m_targetPos.x >= 0 && m_targetPos.y >= 0) { // target location has to be on screen
		// Check if the target has left seek range
		Vector2<float> myPos = m_parent->calculateGlobalTransform().getTranslation();

		Vector2<float> diff = m_targetPos - myPos;
		float distance = sqrt(diff.x * diff.x + diff.y * diff.y);

		if (distance > m_agroRange && m_agroRange > 0)
			// If target leaves the agro range, then switch to wander
			// TODO: Implement FOV
			return "wander";
	}

	return nullptr;
}

void AISeekState::setTarget(Vector2<float> _target) {
	m_targetPos = _target;
}

Vector2<float> AISeekState::getTarget() const {
	return m_targetPos;
}

void AISeekState::setTargetEntity(GameEntity * _entity) {
	m_targetObj = _entity;
}

GameEntity * AISeekState::getTargetEntity() const {
	return m_targetObj;
}



Vector2<float> AISeekState::getForce() const {
	if (m_targetPos.x >= 0 && m_targetPos.y >= 0) { // target location has to be on screen
		// Calculate a force towards the target object
		Vector2<float> myPos = m_parent->calculateGlobalTransform().getTranslation();

		Vector2<float> t = (m_targetPos - myPos).normalise();
		Vector2<float> x = m_parent->getComponentOfType<CRigidBody>()->getMaxVelocity();
		Vector2<float> desiredVelocity = Vector2<float>(t.x * x.x, t.y * x.y);
		Vector2<float> steering = desiredVelocity - m_parent->getComponentOfType<CRigidBody>()->getVelocity();

		return Vector2<float>(
			math_utils::clamp(steering.x, -m_parent->getComponentOfType<CRigidBody>()->getMaxForce().x,
				m_parent->getComponentOfType<CRigidBody>()->getMaxForce().x),
			math_utils::clamp(steering.y, -m_parent->getComponentOfType<CRigidBody>()->getMaxForce().y,
				m_parent->getComponentOfType<CRigidBody>()->getMaxForce().y));
	}
	return Vector2<float>();
}