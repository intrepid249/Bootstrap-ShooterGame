#pragma once
#include "IGameState.h"
#include <memory>
class Menu;
class MenuBtn;
class ShooterGameApp;

namespace aie {
	class Font;
	class Renderer2D;
}

class MainMenuState :
	public IGameState {
public:
	MainMenuState(ShooterGameApp *app);
	~MainMenuState();

	virtual void update(float dt);
	virtual void render(aie::Renderer2D *renderer);

private:
	std::unique_ptr<aie::Font> m_font;
};

