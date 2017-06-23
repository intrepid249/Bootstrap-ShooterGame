#pragma once
#include "IGameState.h"
#include <ResourceManager.h>
#include <memory>
#include <Map\map.hpp>

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
	enum eTexID { PLAYER_TEX };

	float m_elapsedTime;

	std::unique_ptr<aie::Font> m_font;
	Map<eTexID, std::unique_ptr<aie::Texture>> m_textures;
	std::unique_ptr<Player> m_player;
};

