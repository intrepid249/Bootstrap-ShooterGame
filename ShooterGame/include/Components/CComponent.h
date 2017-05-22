#pragma once
#include <Vector2.h>

namespace aie {
	class Renderer2D;
	class Texture;
}

class CComponent {
public:
	CComponent();
	virtual ~CComponent();

	virtual void update(float dt);
	virtual void render(aie::Renderer2D *renderer);
};