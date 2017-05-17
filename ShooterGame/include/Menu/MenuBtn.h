#pragma once
#include <Settings.h>
#include <functional>
#include <string>
#include <Vector4.h>
#include <Colour.h>

namespace aie {
	class Texture;
	class Font;
	class Renderer2D;
}

class MenuBtn {
public:
	MenuBtn();
	/**Construct a new button
	* @param labelText - the text to display on the button
	* @param btnFont - a pointer to the font that will be used (memory handled elsewhere)
	* @param link - function pointer to bind to the onClick callback
	* @param x, y, width, height - the boundaries of the button
	* @param tex - a pointer to the background texture that will be used (memory handled elsewhere)*/
	MenuBtn(const char *labelText, aie::Font *btnFont, std::function<void()> onClickCallback, 
		float x = 0, float y = 0, float width = 0, float height = 0, aie::Texture *tex = nullptr);
	~MenuBtn();

	std::function<void()> onClick;

	void render(aie::Renderer2D *renderer);

	bool hasFocus(MPoint mousePos);

	MRECT getBounds();

private:
	MRECT m_bounds;
	std::string m_labelText;

	aie::Texture	*m_tex;
	aie::Font		*m_font;

	Colour m_tintColour;
};

