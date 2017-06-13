#pragma once
#include "CComponent.h"
#include <Nodes\Node.h>
#include <Entities\Weapons\Bullet.h>
#include <memory>
#include <map>
#include <ArrayList\ArrayList.hpp>
#include <Vector2.h>

namespace aie {
	class Renderer2D;
	class Texture;
	class Input;
	enum EInputCodes;
}

/** This will act as the spawner + controller for shooting bullets
* @author Jack McCall*/
class CWeapon : public Node, public CComponent {
public:
	CWeapon();
	virtual ~CWeapon();

	void update(float dt);
	void render(aie::Renderer2D *renderer);

	void setControls(bool useMouseInput, aie::EInputCodes primaryFire, aie::EInputCodes secondaryFire);
	void setPrimaryDelay(float delay);
	void setSecondaryDelay(float delay);

	void addBulletSpawner(Vector2<float> pos);

private:
	bool mouseInput;
	void updateControls(aie::Input *input);
	void reset();
	void shootPrimary();

	enum class EControlID { PRIMARY_FIRE, SECONDARY_FIRE, RELOAD };
	std::map<EControlID, aie::EInputCodes> m_controls;

	std::shared_ptr<aie::Texture> bTex;

	float primaryDelay, secondaryDelay;
	bool isShootingPrimary, canShootPrimary;
	ArrayList<Bullet*> m_bullets;
	ArrayList<Node*> m_bulletSpawners;
};

