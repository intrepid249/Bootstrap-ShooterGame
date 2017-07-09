#include <Components\AIController.h>
#include <StateMachine\AI\IAIState.h>


AIController::AIController() {
	m_activeState = nullptr;
}


AIController::~AIController() {
}

void AIController::update(float dt) {
	if (m_activeState == nullptr) return; // Can't update -> no active state

	// Process the current state's behaviours
	m_activeState->doActions(dt);

	// Check if we meet the conditions to change between states
	const char* newStateName = m_activeState->checkConditions();
	if (newStateName != nullptr)
		setState(newStateName);
}

void AIController::addState(const char * name, std::shared_ptr<IAIState> state) {
	m_states[name] = std::move(state);
}

void AIController::setState(const char * newStateName) {
	if (m_activeState != nullptr)
		// Perform shutdown actions for the currently active state
		m_activeState->exitActions();

	// Switch to the new state and perform startup actions
	m_activeState = m_states[newStateName].get();
	m_activeState->entryActions();
}

IAIState * AIController::getRegisteredState(const char * name) const {
	if (m_states.find(name)->first != nullptr)
		return m_states.find(name)->second.get();

	return nullptr;
}
