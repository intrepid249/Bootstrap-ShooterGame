#pragma once
#include <Entities\GameEntity.h>

namespace aie {
	class Renderer2D;
	class Texture;
}

class Player : public GameEntity {
public:
	Player();
	Player(aie::Texture *tex);
	~Player();

	virtual void render(aie::Renderer2D *renderer);
	virtual void update(float dt);
};