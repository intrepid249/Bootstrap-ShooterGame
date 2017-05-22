#include <Components/CSpriteNode.h>
#include <Texture.h>
#include <Renderer2D.h>

CSpriteNode::CSpriteNode() {
}

CSpriteNode::CSpriteNode(aie::Texture *m_tex) : m_sprite(m_tex), m_size(Vector2<float>((float)m_tex->getWidth(), (float)m_tex->getHeight())) {
}


CSpriteNode::~CSpriteNode() {
}

void CSpriteNode::render(aie::Renderer2D * renderer) {
	Matrix3<float> gMat = calculateGlobalTransform();

	renderer->drawSpriteTransformed3x3(m_sprite, (float*)gMat, m_size.x, m_size.y, 0, m_origin.x, m_origin.y);

	Node::render(renderer);
}

void CSpriteNode::setSize(const Vector2<float> & size) {
	m_size = size;
}

Vector2<float> & CSpriteNode::getSize() {
	return m_size;
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
