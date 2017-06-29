#pragma once
#include "IAIState.h"
#include "Behaviours\ISteeringForce.h"
#include <Vector2.h>

class GameEntity;

class AISeekState :
	public IAIState, public ISteeringForce {
public:
	AISeekState(GameEntity *_parent);
	~AISeekState();

	void entryActions();
	void doActions(float dt);
	void exitActions();
	const char * checkConditions();

	void setTarget(Vector2<float> _target);
	Vector2<float> getTarget() const;

	virtual Vector2<float> getForce() const;
};

