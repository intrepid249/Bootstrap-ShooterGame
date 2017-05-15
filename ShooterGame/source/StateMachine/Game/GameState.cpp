#include <StateMachine\Game\GameState.h>
#include <ResourceManager\ResourceManager.h>
#include <Renderer2D.h>
#include <Font.h>

GameState::GameState(ShooterGameApp *app) : IGameState(app){
	m_font = ResourceManager::loadUniqueResource<aie::Font>("./font/consolas.ttf", 32);
}


GameState::~GameState() {
}

void GameState::update(float dt) {
}

void GameState::render(aie::Renderer2D * renderer) {
	renderer->drawText(m_font.get(), "Game State", 10, 10);
}
