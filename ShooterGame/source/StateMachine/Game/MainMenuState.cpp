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
	m_font = ResourceManager::loadUniqueResource<aie::Font>("./font/consolas.ttf", 32);
}

MainMenuState::~MainMenuState() {
}

void MainMenuState::update(float dt) {
	
}

void MainMenuState::render(aie::Renderer2D * renderer) {
	renderer->drawText(m_font.get(), "Main Menu", 10, 10);
}
