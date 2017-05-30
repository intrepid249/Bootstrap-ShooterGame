#include <Entities\Player.h>

#include <Input.h>

#include <Components\CPlayerController.h>
#include <Components\CWeapon.h>


Player::Player() {
}

Player::Player(aie::Texture * tex) : GameEntity(tex) {
	/// COMPONENTS
	// Add a player controller component
	std::shared_ptr<CPlayerController> pController = std::shared_ptr<CPlayerController>(new CPlayerController());
	pController->setControls(aie::INPUT_KEY_W, aie::INPUT_KEY_S, aie::INPUT_KEY_A, aie::INPUT_KEY_D);
	pController->setParent(this);

	// Add a weapon component
	std::shared_ptr<CWeapon> pWeapon = std::shared_ptr<CWeapon>(new CWeapon());
	pWeapon->setControls(true, aie::INPUT_MOUSE_BUTTON_LEFT, aie::INPUT_MOUSE_BUTTON_RIGHT);
	pWeapon->setPrimaryDelay(300);
	pWeapon->setParent(this);

	addComponent(std::move(pWeapon));
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
