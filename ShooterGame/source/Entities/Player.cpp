#include <Entities\Player.h>

#include <Input.h>

#include <Components\CPlayerController.h>
#include <Components\CWeapon.h>
#include <Components\CSpriteNode.h>


Player::Player() {
}

Player::Player(aie::Texture * tex, IGameState *_app) : GameEntity(tex, _app) {
	/// COMPONENTS
	getComponentOfType<CSpriteNode>()->scale(Vector2<float>(0.2f, 0.2f));

	// Add a player controller component
	CPlayerController *pController = new CPlayerController();
	pController->setControls(aie::INPUT_KEY_W, aie::INPUT_KEY_S, aie::INPUT_KEY_A, aie::INPUT_KEY_D);
	pController->setParent(this);

	// Add a weapon component
	CWeapon *pWeapon = new CWeapon();
	pWeapon->setControls(true, aie::INPUT_MOUSE_BUTTON_LEFT, aie::INPUT_MOUSE_BUTTON_RIGHT);
	pWeapon->setPrimaryDelay(300);
	pWeapon->addBulletSpawner(Vector2<float>(getSize().x * getScale().x, getSize().y / 2 * getScale().y));
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
