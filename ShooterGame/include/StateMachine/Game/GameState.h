#pragma once
#include "IGameState.h"
#include <ResourceManager\ResourceManager.hpp>
#include <memory>

class GameEntity;
class Player;
namespace aie {
	class Font;
	class Texture;
}

class GameState : public IGameState {
public:
	GameState(ShooterGameApp *app);
	virtual ~GameState();

	virtual void update(float dt);
	virtual void render(aie::Renderer2D *renderer);

protected:
	float m_elapsedTime;

	std::unique_ptr<ResourceManager<aie::Font>> m_fonts;
	//ResourceManager<aie::Texture> m_textures;

	std::unique_ptr<Player> m_player;
};

