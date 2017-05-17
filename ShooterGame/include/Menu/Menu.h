#pragma once
#include <Settings.h>
#include <vector>
#include <memory>

class MenuBtn;
namespace aie {
	class Texture;
	class Renderer2D;
	class Font;
}

class Menu {
public:
	Menu();
	Menu(aie::Texture *titleImage, float x = 0, float y = 0, float width = SCREENWIDTH, float HEIGHT = SCREENHEIGHT);
	Menu(const char *title, float x = 0, float y = 0, float width = SCREENWIDTH, float height = SCREENHEIGHT);
	~Menu();

	void update(float dt);
	void render(aie::Renderer2D *renderer);

	/** Sets the animation state of the title image (if not a nullptr)
	* @param useSpriteSheet - whether or not to use a sprite sheet for animation (if false, image will be static)
	* @param numCells - horizontal cell count
	* @param numTracks - number of animation tracks*/
	void setAnimation(bool useSpriteSheet, int numCells, int numTracks);

	void addButton(std::unique_ptr<MenuBtn> btn);

private:
	std::unique_ptr<aie::Texture>			m_titleImage;
	float m_titleAnimTimer;
	int m_numCells, m_numTracks;
	std::unique_ptr<aie::Font>				m_titleFont;
	const char *m_titleText;
	bool m_useSpriteSheet;
	
	std::vector<std::unique_ptr<MenuBtn>>	m_buttons;

	MRECT m_bounds;
};

