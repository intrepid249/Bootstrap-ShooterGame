#pragma once
#include "IGameState.h"
#include <ResourceManager.h>
#include <memory>
#include <map>
#include <vector>

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

	std::vector<std::shared_ptr<GameEntity>> getWorldEntities();

protected:
	enum eTexID { PLAYER_TEX, GARGANT_TEX };

	float m_elapsedTime;

	std::unique_ptr<aie::Font> m_font;
	std::map<eTexID, std::shared_ptr<aie::Texture>> m_textures;

	std::vector<std::shared_ptr<GameEntity>> m_entities;

	char m_windowTitle[255];
	int *m_windowWidth, *m_windowHeight;
	bool *m_windowFullscreen;
};

