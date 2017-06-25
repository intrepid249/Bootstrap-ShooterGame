#include "ShooterGameApp.h"
#include <Input.h>
#include <Font.h>
#include <Settings.h>
#include <ResourceManager.h>
#include <StateMachine\Game\GameStateManager.h>

#include <StateMachine\Game\SplashState.h>
#include <StateMachine\Game\GameState.h>
#include <StateMachine\Game\PauseState.h>
#include <StateMachine\Game\MainMenuState.h>
#include <StateMachine\Game\LoadGameDataState.h>

ShooterGameApp::ShooterGameApp() {
}

ShooterGameApp::~ShooterGameApp() {
}

bool ShooterGameApp::startup() {
	m_renderer = std::unique_ptr<aie::Renderer2D>(new aie::Renderer2D());

	m_gameStateManager = std::unique_ptr<GameStateManager>(new GameStateManager());
	//m_gameStateManager->setState((int)eGameStateID::SPLASH_STATE, new SplashState(this));
	m_gameStateManager->setState((int)eGameStateID::GAME_STATE, new GameState(this));
	//m_gameStateManager->setState((int)eGameStateID::PAUSE_STATE, new PauseState(this));
	//m_gameStateManager->setState((int)eGameStateID::MAIN_MENU_STATE, new MainMenuState(this));
	//m_gameStateManager->setState((int)eGameStateID::LOAD_GAME_DATA, new LoadGameDataState(this));

	m_gameStateManager->pushState((int)eGameStateID::GAME_STATE);

	return true;
}

void ShooterGameApp::shutdown() {
}

void ShooterGameApp::update(float deltaTime) {
	m_gameStateManager->updateGameStates(deltaTime);
}

void ShooterGameApp::draw() {
	// wipe the screen to the background colour
	clearScreen();

	m_renderer->begin();
	m_gameStateManager->renderGameStates(m_renderer.get());
	m_renderer->end();
}