#include <Components/CSpriteNode.h>
#include <Texture.h>
#include <Renderer2D.h>
#include <Entities\GameEntity.h>

CSpriteNode::CSpriteNode() {
}

CSpriteNode::CSpriteNode(aie::Texture *m_tex) : m_sprite(m_tex), m_rotation(0), m_parent(nullptr),
	m_size(Vector2<float>((float)m_tex->getWidth(), (float)m_tex->getHeight())) {
}


CSpriteNode::~CSpriteNode() {
}

void CSpriteNode::render(aie::Renderer2D * renderer) {
	Vector2<float> pos = m_parent->calculateGlobalTransform().getTranslation();

	renderer->drawSprite(m_sprite, pos.x, pos.y, m_size.x, m_size.y, m_rotation, 0.0f, m_origin.x, m_origin.y);
}

void CSpriteNode::setSize(const Vector2<float> & size) {
	m_size = size;
}

Vector2<float> & CSpriteNode::getSize() {
	return m_size;
}

void CSpriteNode::scale(Vector2<float> _scale) {
	m_size.x *= _scale.x;
	m_size.y *= _scale.y;
}

void CSpriteNode::setOrigin(const Vector2<float> &origin) {
	m_origin = origin;
}

Vector2<float> & CSpriteNode::getOrigin() {
	return m_origin;
}

aie::Texture * CSpriteNode::getTexture() {
	return m_sprite;
}

void CSpriteNode::setParent(GameEntity * _parent) {
	m_parent = _parent;
}

GameEntity * CSpriteNode::getParent() {
	return m_parent;
}

void CSpriteNode::rotate(float _amt) {
	m_rotation += _amt;
}

void CSpriteNode::setRotate(float _angle) {
	m_rotation = _angle;
}

float CSpriteNode::getRotation() {
	return m_rotation;
}
