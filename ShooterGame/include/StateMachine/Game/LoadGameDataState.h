#pragma once
#include "IGameState.h"
#include <memory>

class ShooterGameApp;

namespace aie {
	class Renderer2D;
	class Font;
	class Texture;
}

class LoadGameDataState :
	public IGameState {
public:
	LoadGameDataState(ShooterGameApp *_app);
	virtual ~LoadGameDataState();

	virtual void update(float dt);
	virtual void render(aie::Renderer2D *renderer);

private:
	float m_elapsedTime;
	const char *m_displayText;
	std::unique_ptr<aie::Font> m_font;

	const float delayTime = 0.3f;

	void updateLoadText(float dt);
	void updateStateTimer(float dt);
};

