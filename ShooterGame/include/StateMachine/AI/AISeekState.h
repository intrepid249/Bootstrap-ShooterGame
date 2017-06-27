#pragma once
#include "IAIState.h"

class GameEntity;

class AISeekState :
	public IAIState {
public:
	AISeekState(GameEntity *_parent);
	~AISeekState();

	void entryActions();
	void doActions(float dt);
	void exitActions();
	const char * checkConditions();
};

