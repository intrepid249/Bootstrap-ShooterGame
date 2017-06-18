#pragma once
#include "IGameState.h"

class ShooterGameApp;

class LoadState :
	public IGameState {
public:
	LoadState(ShooterGameApp *_app);
	~LoadState();
};

