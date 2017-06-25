#pragma once

class GameEntity;
namespace aie {
	class Renderer2D;
}

class IAIState {
public:
	IAIState(GameEntity *parent) : m_parent(parent) {}
	virtual ~IAIState() = default;

	virtual void entryActions() = 0;
	virtual void doActions(float dt) = 0;
	virtual void exitActions() = 0;
	virtual const char * checkConditions() = 0;

protected:
	GameEntity *m_parent;
};