#pragma once
#include "IGameState.h"
#include <memory>

class GameEntity;
class Player;
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
	aie::Font	*m_font;
	float m_elapsedTime;

	std::unique_ptr<aie::Texture> m_tex;
	std::unique_ptr<Player> m_player;
};

