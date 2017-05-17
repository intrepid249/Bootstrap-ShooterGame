#include <Menu\Menu.h>
#include <ResourceManager\ResourceManager.h>
#include <Font.h>
#include <Renderer2D.h>

Menu::Menu() {
}

Menu::Menu(aie::Texture * titleImage, float x, float y, float width, float height) 
	: m_titleImage(titleImage), m_bounds({ x, y, width, height }), m_titleFont(nullptr), m_titleAnimTimer(0), m_titleText("") {
}

Menu::Menu(const char * title, float x, float y, float width, float height)
	: m_titleImage(nullptr), m_bounds({ x, y, width, height }), m_titleAnimTimer(0), m_titleText(title) {
	m_titleFont = ResourceManager::loadUniqueResource<aie::Font>("./font/consolas.ttf", 60);
	
}

Menu::~Menu() {
}

void Menu::update(float dt) {

}

void Menu::render(aie::Renderer2D * renderer) {
	if (m_titleImage != nullptr) {
		if (m_useSpriteSheet)
			renderer->setUVRect(int(m_titleAnimTimer * m_numCells) % )
	}
}

void Menu::setAnimation(bool useSpriteSheet = false, int numCells = 1, int numTracks = 1) {
	m_useSpriteSheet = useSpriteSheet;
	if (m_titleImage != nullptr) {
		m_numCells = numCells;
		m_numTracks = numTracks;
	}
}

void Menu::addButton(std::unique_ptr<MenuBtn> btn) {
	m_buttons.push_back(std::move(btn));
}
