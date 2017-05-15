#include <StateMachine\Game\GameStateManager.h>
#include <Renderer2D.h>
#include <assert.h>
#include <StateMachine\Game\IGameState.h>

GameStateManager::GameStateManager() {
}


GameStateManager::~GameStateManager() {
}

void GameStateManager::updateGameStates(float dt) {
	for (auto iter = m_activeStateStack.begin(); iter != m_activeStateStack.end(); ++iter)
		(*iter)->update(dt);
}

void GameStateManager::renderGameStates(aie::Renderer2D * renderer) {
	for (auto iter = m_activeStateStack.begin(); iter != m_activeStateStack.end(); ++iter)
		(*iter)->render(renderer);
}

void GameStateManager::setState(int ID, IGameState * state) {
	auto iter = m_registeredStates.find(ID);
	if (iter != m_registeredStates.end()) {
		// Erase the old state if it already exists
		delete iter->second;
	}
	m_registeredStates[ID] = state;
}

void GameStateManager::pushState(int ID) {
	auto iter = m_registeredStates.find(ID);
	if (iter != m_registeredStates.end()) {
		// Push the state back onto the stack
		m_activeStateStack.push_back(iter->second);
	} else {
		assert(ID && "State ID not found");
	}
}

void GameStateManager::popState() {
	if (m_activeStateStack.size() > 0)
		m_activeStateStack.pop_back();
}
