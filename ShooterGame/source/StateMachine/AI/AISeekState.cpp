#include <StateMachine\AI\AISeekState.h>



AISeekState::AISeekState(GameEntity *_parent) : IAIState(_parent) {
}


AISeekState::~AISeekState() {
}

void AISeekState::entryActions() {
}

void AISeekState::doActions(float dt) {
}

void AISeekState::exitActions() {
}

const char * AISeekState::checkConditions() {
	return nullptr;
}
