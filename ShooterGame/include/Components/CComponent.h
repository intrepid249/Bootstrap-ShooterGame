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

	//virtual void setSize(const Vector2<float> &size) = 0;
	//virtual Vector2<float>& getSize() = 0;

	//virtual void setOrigin(const Vector2<float> &origin) = 0;
	//virtual Vector2<float>& getOrigin() = 0;

	//virtual aie::Texture* getTexture() = 0;
};


// Forward declarations for utilising components
class CSpriteNode;