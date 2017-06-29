#include <Components\CWeapon.h>
#include <Input.h>
#include <Texture.h>
#include <Renderer2D.h>
#include <ResourceManager.h>
#include <Timer.h>

#include<iostream>

CWeapon::CWeapon() {
	isShootingPrimary = false;
	canShootPrimary = true;

	bTex = ResourceManager::loadSharedResource<aie::Texture>("./textures/rock_small.png");
}

CWeapon::~CWeapon() {
	for (auto iter = m_bullets.begin(); iter != m_bullets.end(); ++iter)
		delete (*iter);
	for (auto iter = m_bulletSpawners.begin(); iter != m_bulletSpawners.end(); ++iter)
		delete (*iter);
}

void CWeapon::update(float dt) {
	aie::Input *input = aie::Input::getInstance();
	
	if (isShootingPrimary && canShootPrimary) 
		shootPrimary();

	updateControls(input);

	for (auto iter = m_bullets.begin(); iter != m_bullets.end(); ++iter)
		//iter->value.update(dt)
		(*iter)->update(dt);
}

void CWeapon::render(aie::Renderer2D * renderer) {
	Node::render(renderer);
	CComponent::render(renderer);
	renderer->setRenderColour(0xff0000ff);
	for (auto spawner : m_bulletSpawners)
		spawner->render(renderer);
	renderer->setRenderColour(0xffffffff);

	for (auto iter = m_bullets.begin(); iter != m_bullets.end(); ++iter)
		(*iter)->render(renderer);
}

void CWeapon::setControls(bool useMouseInput, aie::EInputCodes primaryFire, aie::EInputCodes secondaryFire) {
	mouseInput = useMouseInput;
	m_controls[EControlID::PRIMARY_FIRE] = primaryFire;
	m_controls[EControlID::SECONDARY_FIRE] = secondaryFire;
}

void CWeapon::setPrimaryDelay(float delay) {
	primaryDelay = delay;
}

void CWeapon::setSecondaryDelay(float delay) {
	secondaryDelay = delay;
}

void CWeapon::addBulletSpawner(Vector2<float> pos) {
	Node* temp = new Node();
	temp->translate(pos);

	m_bulletSpawners.push_back(temp);
}

void CWeapon::updateControls(aie::Input * input) {
	if (!mouseInput) {
		if (input->isKeyDown(m_controls[EControlID::PRIMARY_FIRE]))
			isShootingPrimary = true;

		if (input->isKeyUp(m_controls[EControlID::PRIMARY_FIRE]))
			isShootingPrimary = false;
	} else {
		if (input->isMouseButtonDown(m_controls[EControlID::PRIMARY_FIRE]))
				isShootingPrimary = true;

		if (input->isMouseButtonUp(m_controls[EControlID::PRIMARY_FIRE]))
			isShootingPrimary = false;
	}
}

void CWeapon::shootPrimary() {
	canShootPrimary = false;
	std::cout << "Shoot\n";
	Bullet *b = new Bullet(bTex.get(), dynamic_cast<GameEntity*>(m_parent)->getAppState());
	b->setLifetime(5);
	b->setMoveSpeed(200);
	b->translate(calculateGlobalTransform().getTranslation());
	b->setRotate(m_parent->getTransform().getRotationZ());
	m_bullets.push_back(b);

	Timer t;
	t.schedule([this]() { canShootPrimary = true; }, (unsigned int)primaryDelay);
}
