#include <StateMachine\AI\AIWanderState.h>
#include <Entities\GameEntity.h>
#include <Vector2.h>
#include <Components\AIController.h>


AIWanderState::AIWanderState(GameEntity *parent) : IAIState(parent) {
}

AIWanderState::~AIWanderState() {
}

void AIWanderState::entryActions() {
}

void AIWanderState::doActions(float dt) {
	m_parent->translate(Vector2<float>(100, 0) * dt);
}

void AIWanderState::exitActions() {

}

const char * AIWanderState::checkConditions() {
	// TODO: if (condition) { return "newStateName"; }

	// No conditions match, return nullptr
	return nullptr;
}
