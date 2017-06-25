#pragma once
#include <Entities\GameEntity.h>

namespace aie {
	class Renderer2D;
	class Texture;
}

class IAI : public GameEntity {
public:
	IAI() = default;
	IAI(aie::Texture *tex) : GameEntity(tex) {}
	virtual ~IAI() = default;

	virtual void update(float dt) { GameEntity::update(dt); }
	virtual void render(aie::Renderer2D *renderer) { GameEntity::render(renderer); }
};