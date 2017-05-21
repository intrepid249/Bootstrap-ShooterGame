#pragma once
#include <Nodes\Node.h>
#include <string>


namespace aie {
	class Renderer2D;
}

/** This will act as the spawner + controller for shooting bullets
* @author Jack McCall*/
class Weapon : public Node {
public:
	Weapon();
	~Weapon();

	void update(float dt);
	void render(aie::Renderer2D *renderer);

	void setName(std::string name);
	std::string getName();

	void setFireRate(float delay);
	float getFireRate();

private:
	std::string m_name;
	float m_shotDelay, m_shotTimer;
	bool m_canShoot;
};

