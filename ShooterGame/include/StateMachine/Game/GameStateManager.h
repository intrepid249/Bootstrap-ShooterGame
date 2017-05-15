#pragma once
#include <map>
#include <vector>

namespace aie {
	class Renderer2D;
}
class IGameState;

class GameStateManager {
public:
	GameStateManager();
	~GameStateManager();

	void updateGameStates(float dt);
	void renderGameStates(aie::Renderer2D *renderer);

	void setState(int ID, IGameState *state);
	void pushState(int ID);
	void popState();

private:
	// A database of states that have been stored within the manager
	std::map<int, IGameState*>		m_registeredStates;
	// A stack of all the states that will be actively updated and drawn
	std::vector<IGameState*>				m_activeStateStack;
};

