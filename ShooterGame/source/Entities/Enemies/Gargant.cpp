#include <Entities\Enemies\Gargant.h>

#include <memory>

#include <Components\AIController.h>
#include <StateMachine\AI\AIWanderState.h>
#include <StateMachine\AI\AISeekState.h>

#include <Components\CRigidBody.h>

Gargant::Gargant() {
}

Gargant::Gargant(aie::Texture * tex, IGameState *_app) : GameEntity(tex, _app) {
	AIController *gController = new AIController;
	gController->addState("wander", std::shared_ptr<AIWanderState>(new AIWanderState(this)));

	std::shared_ptr<AISeekState> seek = std::shared_ptr<AISeekState>(new AISeekState(this));
	seek->setAgroRange(150);
	seek->setParent(this);
	gController->addState("seek", std::move(seek));
	gController->setState("wander");

	CRigidBody *rigidbody = new CRigidBody();
	rigidbody->setParent(this);

	addComponent(std::move(gController));
	addComponent(std::move(rigidbody));
}

Gargant::~Gargant() {
}

void Gargant::render(aie::Renderer2D * renderer) {
	GameEntity::render(renderer);
}

void Gargant::update(float dt) {
	GameEntity::update(dt);
}
