#pragma once
#include <Nodes/Node.h>
#include <memory>
#include <vector>
#include <Vector2.h>

class CComponent;
class OBB;
namespace aie {
	class Texture;
}
class IGameState;

/** An object on-screen with a sprite image and an Oriented Bounding Box for collision
* @author Jack McCall*/
class GameEntity : public Node {
public:
	GameEntity();
	GameEntity(aie::Texture *tex, IGameState *_app);
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


	/** Attain external access to a component of a defined type*/
	template<typename T>
	T * getComponentOfType();

	/** Return any entities that are nearby*/
	GameEntity *getNearbyEntity(float range = 100.0);


	/** Get a pointer to the particle texture*/
	virtual aie::Texture* getParticleType();

	/** Add components to define behaviour*/
	virtual void addComponent(CComponent *component);

	IGameState *getAppState() { return m_app; }

protected:
	aie::Texture *m_particleType;
	Vector2<float> m_size;

	OBB *m_collider;

	std::vector<CComponent*> m_components;

	IGameState *m_app;
};

template<typename T>
inline T * GameEntity::getComponentOfType() {
	for (auto iter = m_components.begin(); iter != m_components.end(); iter++) {
		if (dynamic_cast<T*>(*iter) != nullptr) {
			return dynamic_cast<T*>(*iter);
		}
	}
	return nullptr;
}