#pragma once
#include <StateMachine\AI\IAIState.h>

class GameEntity;

class AIWanderState : public IAIState {
public:
	AIWanderState(GameEntity *parent);
	~AIWanderState();

	void entryActions();
	void doActions(float dt);
	void exitActions();
	const char * checkConditions();
};

