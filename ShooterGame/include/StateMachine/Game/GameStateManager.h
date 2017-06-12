#pragma once
#include <Map\map.hpp>
#include <Queue\Queue.hpp>

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

	IGameState *getTopState();

private:
	// A database of states that have been stored within the manager
	Map<int, IGameState*>				m_registeredStates;
	// A stack of all the states that will be actively updated and drawn
	ArrayList<IGameState*>				m_activeStateStack;

#pragma region Command Queues
	void processCommands();

	void processSetState(int ID, IGameState *state);
	void processPushState(int ID);
	void processPopState();

	enum class ECommand { PUSH, POP, SET };

	struct Command {
		ECommand cmd;
		int ID;
		IGameState *pState;
	};

	ArrayList<Command> m_commands;
#pragma endregion
};
