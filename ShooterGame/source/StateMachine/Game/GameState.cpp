#include <StateMachine\Game\GameState.h>
#include <ResourceManager\ResourceManager.h>
#include <Renderer2D.h>
#include <Font.h>
#include <Input.h>
#include <ShooterGameApp.h>
#include <StateMachine\Game\GameStateManager.h>
#include <Settings.h>

GameState::GameState(ShooterGameApp *app) : IGameState(app){
	m_font = ResourceManager::loadUniqueResource<aie::Font>("./font/consolas.ttf", 32);
	m_elapsedTime = 0;
}

GameState::~GameState() {
}

void GameState::update(float dt) {
	if (getApp()->getGameStateManager()->getTopState() != this) return;

	m_elapsedTime += dt;
		
	aie::Input *input = aie::Input::getInstance();
	/// Exit the application
	//if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	//	getApp()->quit();
	/// Pause the game
	if (input->isKeyDown(aie::INPUT_KEY_P)) {
		getApp()->getGameStateManager()->pushState((int)eGameStateID::PAUSE_STATE);
	}
}

void GameState::render(aie::Renderer2D * renderer) {
	char buffer[255];
	sprintf_s(buffer, "%.2f", m_elapsedTime);

	renderer->drawText(m_font.get(), buffer, 10, 30);
	renderer->drawText(m_font.get(), "Game State", 10, 10);
}
