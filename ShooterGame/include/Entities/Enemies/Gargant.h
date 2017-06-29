#pragma once
#include <Entities\GameEntity.h>

namespace aie {
	class Texture;
	class Renderer2D;
}
class IGameState;

class Gargant :
	public GameEntity {
public:
	Gargant();
	Gargant(aie::Texture *tex, IGameState *_app);
	~Gargant();

	virtual void render(aie::Renderer2D *renderer);
	virtual void update(float dt);
};

