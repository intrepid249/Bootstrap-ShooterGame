#pragma once
#include <Entities\GameEntity.h>

namespace aie {
	class Texture;
	class Renderer2D;
}

class Gargant :
	public GameEntity {
public:
	Gargant();
	Gargant(aie::Texture *tex);
	~Gargant();

	virtual void render(aie::Renderer2D *renderer);
	virtual void update(float dt);
};

