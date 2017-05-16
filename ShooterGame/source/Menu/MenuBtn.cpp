#include <Menu\MenuBtn.h>
#include <Renderer2D.h>

MenuBtn::MenuBtn() {
}

MenuBtn::~MenuBtn() {
}

void MenuBtn::render(aie::Renderer2D * renderer) {
	renderer->setUVRect(0, 0, 1, 1);
	renderer->setRenderColour(m_tintColour);
	renderer->drawSprite(m_tex, m_bounds.x, m_bounds.y, m_bounds.width, m_bounds.height);
	renderer->setRenderColour(0xffffffff);
	renderer->drawText(m_font, &m_labelText[0u], m_bounds.x - m_font->getTextureWidth() / 4, m_bounds.y - 5);
}

bool MenuBtn::hasFocus(MPoint mousePos) {
	return m_bounds.contains(mousePos);
}

void MenuBtn::setTint(unsigned int colour) {
	m_tintColour = colour;
}

RECT MenuBtn::getBounds() {
	return m_bounds;
}
