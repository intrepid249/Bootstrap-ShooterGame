#pragma once
#include <memory>

namespace aie {
	class Texture;
}
class IGameState;
class GameEntity;

class EnemyFactory {
public:
	EnemyFactory();
	~EnemyFactory();

	static std::shared_ptr<GameEntity> spawn(const char *id, aie::Texture *tex, IGameState *_app);
};

