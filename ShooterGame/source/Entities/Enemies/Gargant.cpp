#include <Entities\Enemies\Gargant.h>

#include <memory>

#include <Components\AIController.h>
#include <StateMachine\AI\AIWanderState.h>


Gargant::Gargant() {
}

Gargant::Gargant(aie::Texture * tex) : GameEntity(tex) {
	std::unique_ptr<AIController> gController = std::unique_ptr<AIController>(new AIController);
	gController->addState("wander", new AIWanderState(this));
	gController->setState("wander");

	addComponent(std::move(gController));
}

Gargant::~Gargant() {
}

void Gargant::render(aie::Renderer2D * renderer) {
	GameEntity::render(renderer);
}

void Gargant::update(float dt) {
	GameEntity::update(dt);
}
