#include <Entities\EnemyFactory.h>
#include <Entities\Enemies\Gargant.h>

EnemyFactory::EnemyFactory() {
}


EnemyFactory::~EnemyFactory() {
}

std::shared_ptr<GameEntity> EnemyFactory::spawn(const char * id, aie::Texture * tex) {
	if (id == "gargant")
		return std::shared_ptr<Gargant>(new Gargant(tex));
}
