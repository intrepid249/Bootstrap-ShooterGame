#include <Menu\MenuBtn.h>
#include <Renderer2D.h>
#include <Font.h>
#include <ResourceManager\ResourceManager.h>

MenuBtn::MenuBtn() {
}

MenuBtn::MenuBtn(const char * labelText, std::function<void()> link,
	float x, float y, float width, float height, aie::Texture * tex)
	: m_labelText(labelText), onClick(link), m_bounds({ x, y, width, height }), m_tex(tex) {
	m_font = ResourceManager::loadUniqueResource<aie::Font>("./font/consolas.ttf", 32);
}

MenuBtn::~MenuBtn() {
}

void MenuBtn::render(aie::Renderer2D * renderer) {
	renderer->setRenderColour(m_tintColour);
	if (m_tex != nullptr) {
		renderer->setUVRect(0, 0, 1, 1);
		renderer->drawSprite(m_tex, m_bounds.x, m_bounds.y, m_bounds.width, m_bounds.height);
	} else {
		// Top
		renderer->drawLine(m_bounds.x, m_bounds.y, m_bounds.x + m_bounds.width, m_bounds.y);
		// Left
		renderer->drawLine(m_bounds.x, m_bounds.y, m_bounds.x, m_bounds.y + m_bounds.height);
		// Right
		renderer->drawLine(m_bounds.x + m_bounds.width, m_bounds.y, m_bounds.x + m_bounds.width, m_bounds.y + m_bounds.height);
		// Bottom
		renderer->drawLine(m_bounds.x, m_bounds.y + m_bounds.height, m_bounds.x + m_bounds.width, m_bounds.y + m_bounds.height);
	}
	renderer->drawText(m_font.get(), &m_labelText[0u], m_bounds.x - m_font->getStringWidth(&m_labelText[0u]) / 2, m_bounds.y - 5);
	renderer->setRenderColour(0xffffffff);
}

bool MenuBtn::hasFocus(MPoint mousePos) {
	return m_bounds.contains(mousePos);
}

MRECT MenuBtn::getBounds() {
	return m_bounds;
}
