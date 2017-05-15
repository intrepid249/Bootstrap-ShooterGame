#include "ShooterGameApp.h"
#include <Input.h>
#include <Font.h>
#include <Settings.h>
#include <ResourceManager\ResourceManager.h>
#include <StateMachine\Game\GameStateManager.h>

#include <StateMachine\Game\SplashState.h>
#include <StateMachine\Game\GameState.h>

ShooterGameApp::ShooterGameApp() {
	
}

ShooterGameApp::~ShooterGameApp() {

}

bool ShooterGameApp::startup() {
	m_renderer = std::unique_ptr<aie::Renderer2D>(new aie::Renderer2D());

	m_gameStateManager = std::unique_ptr<GameStateManager>(new GameStateManager());
	m_gameStateManager->setState((int)eGameStateID::SPLASH_STATE, new SplashState(this));
	m_gameStateManager->setState((int)eGameStateID::GAME_STATE, new GameState(this));

	m_gameStateManager->pushState((int)eGameStateID::SPLASH_STATE);
	//m_gameStateManager->pushState((int)eGameStateID::GAME_STATE);4

	return true;
}

void ShooterGameApp::shutdown() {
}

void ShooterGameApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_gameStateManager->updateGameStates(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void ShooterGameApp::draw() {
	// wipe the screen to the background colour
	clearScreen();

	m_renderer->begin();
	m_gameStateManager->renderGameStates(m_renderer.get());
	m_renderer->end();
}