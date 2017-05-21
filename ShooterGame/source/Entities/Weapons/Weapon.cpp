#include <Entities\Weapons\Weapon.h>
#include <Renderer2D.h>


Weapon::Weapon() {
	m_shotDelay = m_shotTimer = 0;
	m_canShoot = true;
}


Weapon::~Weapon() {
}

void Weapon::update(float dt) {
	m_shotTimer += dt;

	if (m_shotTimer < m_shotDelay) return;
}

void Weapon::render(aie::Renderer2D *renderer) {
}

void Weapon::setName(std::string name) {
	m_name = name;
}

std::string Weapon::getName() {
	return m_name;
}

void Weapon::setFireRate(float delay) {
	m_shotDelay = delay;
}

float Weapon::getFireRate() {
	return m_shotDelay;
}
