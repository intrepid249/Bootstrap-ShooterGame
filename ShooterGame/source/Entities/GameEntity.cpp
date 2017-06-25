#include <Renderer2D.h>
#include <Texture.h>
#include <Vector2.h>


#include <Colliders\OBB.h>
#include <Entities\GameEntity.h>
#include <Components\CComponent.h>
#include <Components\CSpriteNode.h>
#include <Components\CPlayerController.h>


GameEntity::GameEntity() {
}

GameEntity::GameEntity(aie::Texture * tex) : m_particleType(tex) {
	/// COMPONENTS
	// Add a sprite component to draw the entity
	std::shared_ptr<CSpriteNode> sprite = std::shared_ptr<CSpriteNode>(new CSpriteNode(tex));
	sprite->setOrigin(Vector2<float>(0.35f, 0.4f));
	sprite->scale(Vector2<float>(0.4f, 0.4f));
	sprite->setParent(this);

	// OBB
	std::shared_ptr<OBB> obb = std::shared_ptr<OBB>(new OBB((float)tex->getWidth() * sprite->getScale().x, (float)tex->getHeight() * sprite->getScale().y));
	m_collider = obb.get();
	obb->setParent(this);

	addComponent(std::move(sprite));
	addComponent(std::move(obb));
}


GameEntity::~GameEntity() {
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

aie::Texture * GameEntity::getParticleType() {
	return m_particleType;
}

void GameEntity::addComponent(std::shared_ptr<CComponent> component) {
	m_components.push_back(component);
}
