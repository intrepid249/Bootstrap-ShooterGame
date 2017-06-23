#include <Menu\Menu.h>
#include <ResourceManager.h>
#include <Font.h>
#include <Texture.h>
#include <Renderer2D.h>
#include <Menu\MenuBtn.h>
#include <Input.h>

Menu::Menu() {
}

Menu::Menu(aie::Texture * titleImage, float x, float y, float width, float height) 
	//: m_titleImage(titleImage), m_bounds({ x, y, width, height }), m_titleFont(nullptr), m_titleAnimTimer(0), m_titleText("") {
{}

Menu::Menu(const char * title, float x, float y, float width, float height)
	//: m_titleImage(nullptr), m_bounds({ x, y, width, height }), m_titleAnimTimer(0), m_titleText(title) {
	//int fontSize = 60;
	//m_titleFont = ResourceManager::loadUniqueResource<aie::Font>("./font/consolas.ttf", fontSize);
	//m_nextButtonY = height - fontSize - TOP_BORDER_PADDING - 160;
{}

Menu::~Menu() {
}

void Menu::update(float dt) {
	//if (m_useSpriteSheet)
	//	m_titleAnimTimer += dt;

	//MPoint mousePos;
	//aie::Input* input = aie::Input::getInstance();
	//input->getMouseXY(&mousePos.x, &mousePos.y);

	//for (auto iter = m_buttons.begin(); iter != m_buttons.end(); iter++) {
	//	auto btn = (*iter).get();
	//	if (btn->hasFocus(mousePos) && input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT)) {
	//		btn->onClick();
	//	}
	//}
}

void Menu::render(aie::Renderer2D * renderer) {
	//if (m_titleImage != nullptr) {
	//	if (m_useSpriteSheet)
	//		renderer->setUVRect((float)(int(m_titleAnimTimer * 10) % m_numCells / m_numCells), 0.f, 1.f / m_numCells, 1.f / m_numTracks);
	//	else
	//		renderer->setUVRect(0, 0, 1, 1);
	//	renderer->drawSprite(m_titleImage.get(), m_bounds.x + (m_bounds.width / 2), 
	//		m_bounds.y + (m_bounds.height - m_titleHeight - TOP_BORDER_PADDING),
	//		m_titleWidth / m_numCells);
	//} else if (m_titleFont.get() != nullptr && m_titleText != "") {
	//	m_titleFont->getStringSize(m_titleText, m_titleWidth, m_titleHeight);
	//	renderer->drawText(m_titleFont.get(), m_titleText, (m_bounds.x + m_bounds.width / 2) - m_titleWidth / 2,
	//		m_bounds.y + m_bounds.height - m_titleHeight - TOP_BORDER_PADDING);
	//}

	//for (auto iter = m_buttons.begin(); iter != m_buttons.end(); iter++)
	//	(*iter)->render(renderer);
}

void Menu::setAnimation(bool useSpriteSheet = false, int numCells = 1, int numTracks = 1) {
	//m_useSpriteSheet = useSpriteSheet;
	//if (m_titleImage != nullptr) {
	//	m_titleWidth = (float)m_titleImage->getWidth() / numCells;
	//	m_titleHeight = (float)m_titleImage->getHeight() / numTracks;
	//	m_numCells = numCells;
	//	m_numTracks = numTracks;
	//}
}

void Menu::addButton(std::unique_ptr<MenuBtn> btn) {
	m_buttons.push_back(std::move(btn));
	m_nextButtonY -= 75;
}
