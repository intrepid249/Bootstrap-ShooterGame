#include <StateMachine\Game\MainMenuState.h>
#include <ResourceManager\ResourceManager.h>
#include <ShooterGameApp.h>
#include <Settings.h>
#include <Colour.h>

#include <Menu\Menu.h>
#include <Menu\MenuBtn.h>

#include <Renderer2D.h>
#include <Font.h>

MainMenuState::MainMenuState(ShooterGameApp *app) : IGameState(app) {
	m_statusFont = ResourceManager::loadUniqueResource<aie::Font>("./font/consolas.ttf", 32);
	m_menu = std::unique_ptr<Menu>(new Menu("Endless"));
	m_menu->addButton(std::unique_ptr<MenuBtn>(new MenuBtn("New Game", std::bind(&newGameFunc, m_menu), 
		m_menu->getBounds().x + m_menu->getBounds().width / 2, m_menu->getBounds().y + m_menu->getBounds().height / 2)));
}

MainMenuState::~MainMenuState() {
}

void MainMenuState::update(float dt) {
	
}

void MainMenuState::render(aie::Renderer2D * renderer) {
	m_menu->render(renderer);
	renderer->drawText(m_statusFont.get(), "Main Menu", 10, 10);
}
