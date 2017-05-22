#pragma once
#include "IGameState.h"
#include <memory>

class GameEntity;
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
	float m_elapsedTime;

	std::unique_ptr<aie::Texture> m_tex;
	std::unique_ptr<GameEntity> m_player;
};

