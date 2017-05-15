#pragma once
#include "IGameState.h"
#include <memory>

namespace aie {
	class Font;
}

class GameState : public IGameState {
public:
	GameState(ShooterGameApp *app);
	virtual ~GameState();

	virtual void update(float dt);
	virtual void render(aie::Renderer2D *renderer);

protected:
	std::unique_ptr<aie::Font>	m_font;
};

