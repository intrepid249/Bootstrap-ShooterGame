#include <Components\AIController.h>
#include <StateMachine\AI\IAIState.h>


AIController::AIController() {
	m_activeState = nullptr;
}


AIController::~AIController() {
	for (auto iter = m_states.begin(); iter != m_states.end(); iter++)
		delete (*iter).second;
	m_states.clear();
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

void AIController::addState(const char * name, IAIState * state) {
	m_states[name] = state;
}

void AIController::setState(const char * newStateName) {
	if (m_activeState != nullptr)
		// Perform shutdown actions for the currently active state
		m_activeState->exitActions();

	// Switch to the new state and perform startup actions
	m_activeState = m_states[newStateName];
	m_activeState->entryActions();
}
