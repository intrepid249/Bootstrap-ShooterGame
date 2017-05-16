#include <StateMachine\Game\PauseState.h>
#include <ShooterGameApp.h>
#include <Font.h>
#include <Renderer2D.h>
#include <ResourceManager\ResourceManager.h>
#include <Settings.h>
#include <Input.h>
#include <ShooterGameApp.h>
#include <StateMachine\Game\GameStateManager.h>

PauseState::PauseState(ShooterGameApp *app) : IGameState(app) {
	m_font = ResourceManager::loadUniqueResource<aie::Font>("./font/consolas.ttf", 16);
}

PauseState::~PauseState() {}

void PauseState::update(float dt) {
	//if (getApp()->getGameStateManager()->getTopState() != this) return;

	aie::Input *input = aie::Input::getInstance();
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE)) {
		getApp()->getGameStateManager()->popState();
	}
}

void PauseState::render(aie::Renderer2D * renderer) {
	const char * text = "Pause State";
	renderer->drawText(m_font.get(), text, SCREENWIDTH/2 - m_font->getStringWidth(text)/2, SCREENHEIGHT/2 - m_font->getStringHeight(text)/2);
}

