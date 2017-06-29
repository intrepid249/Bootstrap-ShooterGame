#include <Entities\EnemyFactory.h>
#include <Entities\Enemies\Gargant.h>

EnemyFactory::EnemyFactory() {
}


EnemyFactory::~EnemyFactory() {
}

std::shared_ptr<GameEntity> EnemyFactory::spawn(const char * id, aie::Texture * tex, IGameState *_app) {
	if (id == "gargant")
		return std::shared_ptr<Gargant>(new Gargant(tex, _app));
	return nullptr;
}
