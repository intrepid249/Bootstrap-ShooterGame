#pragma once
#include <Components\CComponent.h>
#include <map>
#include <Nodes\Node.h>
#include <memory>

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
	void addState(const char *name, std::shared_ptr<IAIState> state);
	/** Set the currently active state*/
	void setState(const char *name);

	/** Function returns a pointer to the matching value mapped to the given index (if found)
	 if no match is found, returns nullptr*/
	IAIState *getRegisteredState(const char * name) const;

private:
	std::map<const char *, std::shared_ptr<IAIState>> m_states;
	IAIState *m_activeState;
};

