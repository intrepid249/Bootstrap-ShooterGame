#pragma once
#include <StateMachine\AI\IAIState.h>
#include <StateMachine\AI\Behaviours\ISteeringForce.h>
#include <Vector2.h>

class GameEntity;

class AIWanderState : public IAIState, public ISteeringForce {
public:
	AIWanderState(GameEntity *parent);
	~AIWanderState();

	void entryActions();
	void doActions(float dt);
	void exitActions();
	const char * checkConditions();

	Vector2<float> getForce() const;
};

