#pragma once
#include <Entities\GameEntity.h>
#include <Entities\Enemies\Gargant.h>

namespace aie {
	class Texture;
}

class EnemyFactory : public GameEntity {
public:
	EnemyFactory();
	~EnemyFactory();

	static std::shared_ptr<GameEntity> spawn(const char *id, aie::Texture *tex);
};

