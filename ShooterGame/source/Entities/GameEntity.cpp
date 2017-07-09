#include <Renderer2D.h>
#include <Texture.h>
#include <Vector2.h>


#include <Colliders\OBB.h>
#include <Entities\GameEntity.h>
#include <Components\AllComponents.h>

#include <StateMachine\Game\GameState.h>
#include <jm_utility.h>
using namespace instanceof;


GameEntity::GameEntity() {
}

GameEntity::GameEntity(aie::Texture * tex, IGameState *_app) : m_particleType(tex), m_app(_app) {
	/// COMPONENTS
	// Add a sprite component to draw the entity
	CSpriteNode *sprite = new CSpriteNode(tex);
	sprite->setOrigin(Vector2<float>(0.35f, 0.4f));
	sprite->setParent(this);

	// OBB
	//OBB *obb = new OBB((float)tex->getWidth() * sprite->getScale().x, (float)tex->getHeight() * sprite->getScale().y);
	OBB *obb = new OBB((float)tex->getWidth() * sprite->getSize().x, (float)tex->getHeight() * sprite->getSize().y);
	m_collider = obb;
	obb->setParent(this);

	addComponent(std::move(sprite));
	addComponent(std::move(obb));
}


GameEntity::~GameEntity() {
	for (auto iter = m_components.begin(); iter != m_components.end(); iter++)
		delete (*iter);
}

void GameEntity::update(float dt) {
	if (m_isDrawn) {
		Node::update(dt);
		for (size_t i = 0; i < m_components.size(); ++i)
			m_components[i]->update(dt);
	}
}

void GameEntity::render(aie::Renderer2D * renderer) {
	if (m_isDrawn) {
		Node::render(renderer);
		for (size_t i = 0; i < m_components.size(); ++i)
			m_components[i]->render(renderer);
	}
}

void GameEntity::setSize(const Vector2<float>& size) {
	m_size = size;
}

Vector2<float>& GameEntity::getSize() {
	return m_size;
}

OBB* GameEntity::getCollider() {
	return m_collider;
}

#include <iostream>

GameEntity * GameEntity::getNearbyEntity(float range) {
	Vector2<float> myPos = calculateGlobalTransform().getTranslation();
	for (auto entity : static_cast<GameState*>(getAppState())->getWorldEntities()) {
		if (entity.get() != this) { // Don't target ourself
			Vector2<float> otherPos = entity->calculateGlobalTransform().getTranslation();
			auto t = math_utils::distanceOf(myPos, otherPos);
			if (math_utils::distanceOf(myPos, otherPos) < range) {
#if 0
				std::cout << myPos.x << ", " << myPos.y << "\t" << entity->calculateGlobalTransform().getTranslation().x <<
					entity->calculateGlobalTransform().getTranslation().y << "\n";
#endif
				std::cout << "Target found!";
				return entity.get();
			}
		}
	}

	return nullptr;
}

aie::Texture * GameEntity::getParticleType() {
	return m_particleType;
}

void GameEntity::addComponent(CComponent *component) {
	m_components.push_back(component);
}