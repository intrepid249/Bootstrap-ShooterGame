#include <Settings.h>
#include <ShooterGameApp.h>

#include <StateMachine\Game\GameState.h>
#include <ResourceManager\ResourceManager.h>
#include <StateMachine\Game\GameStateManager.h>

#include <Renderer2D.h>
#include <Font.h>
#include <Input.h>

#include <Components\CComponent.h>
#include <Components\CSpriteNode.h>
#include <Entities\GameEntity.h>


GameState::GameState(ShooterGameApp *app) : IGameState(app){
	m_font = ResourceManager::loadUniqueResource<aie::Font>("./font/consolas.ttf", 32);
	m_elapsedTime = 0;

	m_tex = ResourceManager::loadUniqueResource<aie::Texture>("./textures/player_handgun.png");
	m_player = std::unique_ptr<GameEntity>(new GameEntity(m_tex.get()));
	m_player->translate(Vector2<float>(500, 500));
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
	if (input->wasKeyPressed(aie::INPUT_KEY_ESCAPE)) {
		getApp()->getGameStateManager()->pushState((int)eGameStateID::PAUSE_STATE);
	}
}

void GameState::render(aie::Renderer2D * renderer) {
	char buffer[255];
	sprintf_s(buffer, "%.2f", m_elapsedTime);

	m_player->render(renderer);

	renderer->drawText(m_font.get(), buffer, 10, 30);
	renderer->drawText(m_font.get(), "Game State", 10, 10);
}
