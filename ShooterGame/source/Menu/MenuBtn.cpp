#include <Menu\MenuBtn.h>
#include <Renderer2D.h>
#include <Font.h>

MenuBtn::MenuBtn() {
}

MenuBtn::MenuBtn(const char * labelText, aie::Font * btnFont, std::function<void()> link,
	float x, float y, float width, float height, aie::Texture * tex)
	: m_labelText(labelText), m_font(btnFont), onClick(link), m_bounds({ x, y, width, height }), m_tex(tex) {}

MenuBtn::~MenuBtn() {
}

void MenuBtn::render(aie::Renderer2D * renderer) {
	renderer->setUVRect(0, 0, 1, 1);
	renderer->setRenderColour(m_tintColour);
	renderer->drawSprite(m_tex, m_bounds.x, m_bounds.y, m_bounds.width, m_bounds.height);
	renderer->setRenderColour(0xffffffff);
	renderer->drawText(m_font, &m_labelText[0u], m_bounds.x - m_font->getStringWidth(&m_labelText[0u]) / 2, m_bounds.y - 5);
}

bool MenuBtn::hasFocus(MPoint mousePos) {
	return m_bounds.contains(mousePos);
}

void MenuBtn::setTint(unsigned int colour) {
	m_tintColour = colour;
}

MRECT MenuBtn::getBounds() {
	return m_bounds;
}
