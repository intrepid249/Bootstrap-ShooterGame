#pragma once
#include "CComponent.h"
#include <Nodes\Node.h>
#include <LinkedList\LinkedList.h>
#include <Entities\Weapons\Bullet.h>
#include <memory>
#include <map>
#include <vector>

namespace aie {
	class Renderer2D;
	class Texture;
	class Input;
	enum EInputCodes;
}

class CWeapon : public Node, public CComponent {
public:
	CWeapon();
	virtual ~CWeapon();

	void update(float dt);
	void render(aie::Renderer2D *renderer);

	void setControls(bool useMouseInput, aie::EInputCodes primaryFire, aie::EInputCodes secondaryFire);
	void setPrimaryDelay(float delay);
	void setSecondaryDelay(float delay);

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
	std::vector<Bullet*> m_bullets;
};

