#pragma once
#include "IGameState.h"
#include <memory>

namespace aie {
	class Font;
}

class SplashState : public IGameState {
public:
	SplashState(ShooterGameApp *app);
	virtual ~SplashState();

	virtual void update(float dt);
	virtual void render(aie::Renderer2D *renderer);

protected:
	std::unique_ptr<aie::Font>	m_font;
	float m_elapsedTime;
};

 