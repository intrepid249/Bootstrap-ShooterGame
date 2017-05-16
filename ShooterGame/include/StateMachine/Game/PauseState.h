#pragma once
#include <StateMachine\Game\IGameState.h>
#include <memory>

namespace aie {
	class Font;
}

class PauseState : public IGameState {
public:
	PauseState(ShooterGameApp *app);
	virtual ~PauseState();

	virtual void update(float dt);
	virtual void render(aie::Renderer2D *renderer);
private:
	std::unique_ptr<aie::Font>	m_font;
};

