#include <StateMachine/Game/SplashState.h>
#include <Renderer2D.h>
#include <Font.h>
#include <ShooterGameApp.h>
#include <Settings.h>
#include <ResourceManager\ResourceManager.hpp>
#include <StateMachine\Game\GameStateManager.h>
#include <assert.h>

SplashState::SplashState(ShooterGameApp *app) : IGameState(app) {
	//m_font = ResourceManager::loadUniqueResource<aie::Font>("./font/consolas.ttf", 32);
	m_elapsedTime = 0.0f;
}

SplashState::~SplashState() {
}

void SplashState::update(float dt) {
	m_elapsedTime += dt;
	if (m_elapsedTime >= 2.0f) {
		getApp()->getGameStateManager()->popState();
		getApp()->getGameStateManager()->pushState((int)eGameStateID::MAIN_MENU_STATE);
	}
}

void SplashState::render(aie::Renderer2D *renderer) {
	char buffer[32];
	sprintf_s(buffer, "%0.2f", m_elapsedTime);

	renderer->drawText(m_font.get(), buffer, 10, 30);
	renderer->drawText(m_font.get(), "Splash State", 10, 10);
}
