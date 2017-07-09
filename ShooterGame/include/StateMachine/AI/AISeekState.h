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

	/** Set the target as a position to move towards*/
	void setTarget(Vector2<float> _target);
	Vector2<float> getTarget() const;
	/** Set the target as an entity to move towards*/
	void setTargetEntity(GameEntity *_entity);
	GameEntity *getTargetEntity() const;

	virtual Vector2<float> getForce() const;
};

