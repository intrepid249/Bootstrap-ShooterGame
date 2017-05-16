#pragma once
#include <Settings.h>
#include <functional>
#include <string>

namespace aie {
	class Texture;
	class Font;
	class Renderer2D;
}

class MenuBtn {
public:
	MenuBtn();
	MenuBtn(const char *labelText);
	~MenuBtn();

	std::function<void()> onClick;

	void render(aie::Renderer2D *renderer);

	bool hasFocus(MPoint mousePos);

	void setTint(unsigned int colour);

	RECT getBounds();

private:
	RECT m_bounds;
	std::string m_labelText;

	aie::Texture	*m_tex;
	aie::Font		*m_font;

	unsigned int m_tintColour;
};

