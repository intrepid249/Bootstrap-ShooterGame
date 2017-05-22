#include <Entities\Player.h>

#include <Input.h>

#include <Components\CPlayerController.h>


Player::Player() {
}

Player::Player(aie::Texture * tex) : GameEntity(tex) {
	/// COMPONENTS
	// Add a player controller component
	std::shared_ptr<CPlayerController> pController = std::shared_ptr<CPlayerController>(new CPlayerController());
	pController->setControls(aie::INPUT_KEY_W, aie::INPUT_KEY_S, aie::INPUT_KEY_A, aie::INPUT_KEY_D);
	pController->setParent(this);
	addComponent(std::move(pController));
}


Player::~Player() {
}

void Player::render(aie::Renderer2D * renderer) {
	GameEntity::render(renderer);
}

void Player::update(float dt) {
	GameEntity::update(dt);
}
