#include <StateMachine\Game\MainMenuState.h>
#include <ResourceManager\ResourceManager.h>
#include <ShooterGameApp.h>
#include <StateMachine\Game\GameStateManager.h>
#include <Settings.h>
#include <Colour.h>

#include <Menu\Menu.h>
#include <Menu\MenuBtn.h>

#include <Renderer2D.h>
#include <Font.h>

MainMenuState::MainMenuState(ShooterGameApp *app) : IGameState(app) {
	m_statusFont = ResourceManager::loadUniqueResource<aie::Font>("./font/consolas.ttf", 32);
	m_menu = std::unique_ptr<Menu>(new Menu("Endless"));
	/// Menu Buttons
	// New Game
	m_menu->addButton(std::unique_ptr<MenuBtn>(new MenuBtn("New Game", std::bind(&MainMenuState::newGameFunc, this), 
		m_menu->getBounds().x + m_menu->getBounds().width / 2,  m_menu->getNextButtonY(), 0xff0000ff)));
	// Load Game
	m_menu->addButton(std::unique_ptr<MenuBtn>(new MenuBtn("Load Game", std::bind(&MainMenuState::loadGameFunc, this),
		m_menu->getBounds().x + m_menu->getBounds().width / 2, m_menu->getNextButtonY())));
	// Quit
	m_menu->addButton(std::unique_ptr<MenuBtn>(new MenuBtn("Quit", std::bind(&MainMenuState::quitFunc, this),
		m_menu->getBounds().x + m_menu->getBounds().width / 2, m_menu->getNextButtonY())));
}

MainMenuState::~MainMenuState() {
}

void MainMenuState::update(float dt) {
	m_menu->update(dt);
}

void MainMenuState::render(aie::Renderer2D * renderer) {
	m_menu->render(renderer);
	renderer->drawText(m_statusFont.get(), "Main Menu", 10, 10);
}

#pragma region ButtonFunctions
void MainMenuState::newGameFunc() {
	std::cout << "Add code to overwrite save file\n";
	getApp()->getGameStateManager()->popState();
	getApp()->getGameStateManager()->pushState((int)eGameStateID::LOAD_GAME_DATA);
}

void MainMenuState::loadGameFunc() {
	std::cout << "Load saved game\n";
}

void MainMenuState::quitFunc() {
	getApp()->quit();
}
#pragma endregion