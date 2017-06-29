#pragma once
#include <Entities\GameEntity.h>

namespace aie {
	class Renderer2D;
	class Texture;
}
class IGameState;

class Player : public GameEntity {
public:
	Player();
	Player(aie::Texture *tex, IGameState *_app);
	~Player();

	virtual void render(aie::Renderer2D *renderer);
	virtual void update(float dt);
};

