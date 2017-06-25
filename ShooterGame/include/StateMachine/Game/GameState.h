#pragma once
#include "IGameState.h"
#include <ResourceManager.h>
#include <memory>
#include <Map\TreeMap.hpp>

class GameEntity;
class Player;
class Gargant;
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
	enum eTexID { PLAYER_TEX, GARGANT_TEX };

	float m_elapsedTime;

	std::unique_ptr<aie::Font> m_font;
	TreeMap<eTexID, std::shared_ptr<aie::Texture>> m_textures;
	std::unique_ptr<Player>		m_player;
	std::unique_ptr<Gargant>	m_gargant;
};

