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
	m_parent->getComponentOfType<CRigidBody>()->addForce(getForce());

	// Rotate to face direction
	Vector2<float> myPos = m_parent->calculateGlobalTransform().getTranslation();
	Vector2<float> dir = m_target - myPos;
	

	// Rotate according to current velocity direction

	aie::Input *input = aie::Input::getInstance();
	int x, y;
	input->getMouseXY(&x, &y);
	setTarget(Vector2<float>((float)x, (float)y));
}

void AISeekState::exitActions() {
}

const char * AISeekState::checkConditions() {
	if (m_target.x >= 0 && m_target.y >= 0) { // target location has to be on screen
		// Check if the target has left seek range
		Vector2<float> myPos = m_parent->calculateGlobalTransform().getTranslation();

		Vector2<float> diff = m_target - myPos;
		float distance = sqrt(diff.x * diff.x + diff.y * diff.y);

		if (distance > m_agroRange && m_agroRange > 0)
			// If target leaves the agro range, then switch to wander
			// TODO: Implement FOV
			return "wander";
	}

	return nullptr;
}

void AISeekState::setTarget(Vector2<float> _target) {
	m_target = _target;
}

Vector2<float> AISeekState::getTarget() const {
	return m_target;
}

Vector2<float> AISeekState::getForce() const {
	if (m_target.x >= 0 && m_target.y >= 0) { // target location has to be on screen
		// Calculate a force towards the target object
		Vector2<float> myPos = m_parent->calculateGlobalTransform().getTranslation();

		Vector2<float> t = (m_target - myPos).normalise();
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