#pragma once
#include <Components\CComponent.h>
#include <Map\TreeMap.hpp>
#include <Nodes\Node.h>

class IAIState;

/** State machine component for the AI controlling mechanics. This is the "brain" behind the AI*/
class AIController :
	public Node, public CComponent {
public:
	AIController();
	~AIController();

	/** Process the current active state*/
	void update(float dt);
	/** Register a new state*/
	void addState(const char *name, IAIState *state);
	/** Set the currently active state*/
	void setState(const char *name);

private:
	TreeMap<const char *, IAIState*> m_states;
	IAIState *m_activeState;
};

