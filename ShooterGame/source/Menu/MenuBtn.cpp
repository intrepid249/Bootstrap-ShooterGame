#include <Menu\MenuBtn.h>
#include <Renderer2D.h>
#include <Font.h>
#include <Texture.h>
#include <Input.h>
#include <ResourceManager\ResourceManager.h>

MenuBtn::MenuBtn() {
}

MenuBtn::MenuBtn(const char * labelText, std::function<void()> onClickCallback,
	float x, float y, Colour col, aie::Texture * tex)
	: m_labelText(labelText), onClick(onClickCallback), m_tex(tex), m_tintColour(col) {
	m_font = ResourceManager::loadUniqueResource<aie::Font>("./font/consolas.ttf", 32);
	if (tex != nullptr)
		m_bounds = MRECT{ x, y, (float)tex->getWidth(), (float)tex->getHeight() };
	else
		m_bounds = MRECT{ x, y, (float)m_font->getStringWidth(labelText) + xBorderPadding * 2, 
								(float)m_font->getStringHeight(labelText) + yBorderPadding * 2 };
}

MenuBtn::~MenuBtn() {
}

void MenuBtn::render(aie::Renderer2D * renderer) {
	MPoint mousePos;
	aie::Input* input = aie::Input::getInstance();
	input->getMouseXY(&mousePos.x, &mousePos.y);

	renderer->setRenderColour((hasFocus(mousePos)) ? m_tintColour.darken() : m_tintColour);
	if (m_tex != nullptr) {
		renderer->setUVRect(0, 0, 1, 1);
		renderer->drawSprite(m_tex, m_bounds.x, m_bounds.y, m_bounds.width, m_bounds.height);
	} else {
		// Top
		renderer->drawLine(m_bounds.x - m_bounds.width / 2, m_bounds.y + m_bounds.height / 2, 
			m_bounds.x + m_bounds.width / 2, m_bounds.y + m_bounds.height / 2);
		// Left
		renderer->drawLine(m_bounds.x - m_bounds.width / 2, m_bounds.y + m_bounds.height / 2,
			m_bounds.x - m_bounds.width / 2, m_bounds.y - m_bounds.height / 2);
		// Right
		renderer->drawLine(m_bounds.x + m_bounds.width / 2, m_bounds.y + m_bounds.height / 2,
			m_bounds.x + m_bounds.width / 2, m_bounds.y - m_bounds.height / 2);
		// Bottom
		renderer->drawLine(m_bounds.x - m_bounds.width / 2, m_bounds.y - m_bounds.height / 2,
			m_bounds.x + m_bounds.width / 2, m_bounds.y - m_bounds.height / 2);
	}
	renderer->drawText(m_font.get(), &m_labelText[0u],
		m_bounds.x - m_font->getStringWidth(&m_labelText[0u]) / 2, m_bounds.y - m_font->getStringHeight(&m_labelText[0u]) / 2);
	renderer->setRenderColour(0xffffffff);
}

bool MenuBtn::hasFocus(MPoint mousePos) {
	return m_bounds.contains(mousePos);
}

MRECT MenuBtn::getBounds() {
	return m_bounds;
}

void MenuBtn::setColour(Colour c) {
	m_tintColour = c;
}
