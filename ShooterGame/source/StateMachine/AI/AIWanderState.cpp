#include <StateMachine\AI\AIWanderState.h>
#include <Entities\GameEntity.h>
#include <Vector2.h>
#include <Components\AIController.h>
#include <Components\CRigidBody.h>
#include <jm_utility.h>

#include <random>
#include <functional>
#include <time.h>

#include <StateMachine\Game\IGameState.h>
#include <ShooterGameApp.h>


#include <iostream>

std::default_random_engine generator;
std::uniform_int_distribution<> dirDistrib(0, 1);
auto chanceRandomDir = std::bind(dirDistrib, generator);

AIWanderState::AIWanderState(GameEntity *parent) : IAIState(parent), ISteeringForce() {
	srand((unsigned int)time(NULL));
}

AIWanderState::~AIWanderState() {
}

void AIWanderState::entryActions() {
}

void AIWanderState::doActions(float dt) {
	static float interval;
	interval += dt;

	m_parent->getComponentOfType<CRigidBody>()->addForce(getForce());

	if (interval < 0.3) return; // Every 2 seconds have a chance to change direction

	if (chanceRandomDir() == 0) {
		// Get a random destination within the screen bounds
		m_target = Vector2<float>(
			(float)(rand() % m_parent->getAppState()->getApp()->getWindowWidth()),
			(float)(rand() % m_parent->getAppState()->getApp()->getWindowHeight()));

		std::cout << "New destination: " << m_target.x << "," << m_target.y << "\n";
	}
	interval = 0;
	
}

void AIWanderState::exitActions() {

}

const char * AIWanderState::checkConditions() {
	// TODO: if (condition) { return "newStateName"; }

	// No conditions match, return nullptr
	return nullptr;
}

Vector2<float> AIWanderState::getForce() const {
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