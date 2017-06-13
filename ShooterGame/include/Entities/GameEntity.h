#pragma once
#include <Nodes/Node.h>
#include <memory>
#include <LinkedList\LinkedList.hpp>

class CComponent;
class OBB;
namespace aie {
	class Texture;
}

/** An object on-screen with a sprite image and an Oriented Bounding Box for collision
* @author Jack McCall*/
class GameEntity : public Node {
public:
	GameEntity();
	GameEntity(aie::Texture *tex);
	virtual ~GameEntity();

	/**Override the parent's update function
	* @see MathDemo::Node#update(float)*/
	virtual void update(float dt);
	/**Override the parent's render function
	* @see MathDemo::Node#render(aie::Renderer2D)*/
	virtual void render(aie::Renderer2D *renderer);

	/*Set the size of the Game Object*/
	void setSize(const Vector2<float> &size);
	/*Get the size of the Game Object*/
	Vector2<float>& getSize();

	/** Get a pointer to the collider box*/
	OBB* getCollider();

	/** Get a pointer to the particle texture*/
	virtual aie::Texture* getParticleType();

	virtual void addComponent(std::shared_ptr<CComponent> component);

protected:
	aie::Texture *m_particleType;
	Vector2<float> m_size;

	OBB *m_collider;

	LinkedList<std::shared_ptr<CComponent>> m_components;
};