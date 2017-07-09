#include <Components\CPlayerController.h>

#include <Matrix3.h>
#include <Utility.h>
#include <Input.h>

#include <Entities\GameEntity.h>
#include <Components\CSpriteNode.h>


CPlayerController::CPlayerController() : m_speed(125), m_moveFW(false), m_moveBW(false), m_moveL(false), m_moveR(false) {
}

CPlayerController::~CPlayerController() {
}

void CPlayerController::update(float dt) {
	Node::update(dt);
	Matrix3<float> gMat = m_parent->getTransform();
	float rot = gMat.getRotationZ();

	// Update movement according to flags and rotation
	Vector2<float> velocity;
	if (m_moveFW)
		velocity = Vector2<float>(cosf(degToRad(rot)) * m_speed * dt, sinf(degToRad(rot)) * m_speed * dt);
	if (m_moveBW)
		velocity = Vector2<float>(-cosf(degToRad(rot)) * m_speed * dt, -sinf(degToRad(rot)) * m_speed * dt);
	if (m_moveL)
		velocity = Vector2<float>(sinf(degToRad(rot)) * m_speed * dt, cosf(degToRad(rot)) * m_speed * dt);
	if (m_moveR)
		velocity = Vector2<float>(-sinf(degToRad(rot)) * m_speed * dt, -cosf(degToRad(rot)) * m_speed * dt);


	if (m_parent != nullptr)
		m_parent->translate(velocity);
	else
		translate(velocity);

	// Update the controls and aim the player at the mouse
	aie::Input *input = aie::Input::getInstance();
	updateControls(input);
	faceAtMouse(input->getMouseX(), input->getMouseY());
}

void CPlayerController::setControls(aie::EInputCodes up, aie::EInputCodes down, aie::EInputCodes left, aie::EInputCodes right) {
	// Set the input control scheme for the PlayerController
	m_controls[EControlID::UP] = up;
	m_controls[EControlID::DOWN] = down;
	m_controls[EControlID::LEFT] = left;
	m_controls[EControlID::RIGHT] = right;
}

void CPlayerController::updateControls(aie::Input * input) {
	// Set movement flags to true on key-press
	if (input->isKeyDown(m_controls[EControlID::UP]))
		m_moveFW = true;
	if (input->isKeyDown(m_controls[EControlID::DOWN]))
		m_moveBW = true;
	if (input->isKeyDown(m_controls[EControlID::LEFT]))
		m_moveL = true;
	if (input->isKeyDown(m_controls[EControlID::RIGHT]))
		m_moveR = true;

	// Set movement flags to false on key-release
	if (input->isKeyUp(m_controls[EControlID::UP]))
		m_moveFW = false;
	if (input->isKeyUp(m_controls[EControlID::DOWN]))
		m_moveBW = false;
	if (input->isKeyUp(m_controls[EControlID::LEFT]))
		m_moveL = false;
	if (input->isKeyUp(m_controls[EControlID::RIGHT]))
		m_moveR = false;
}

void CPlayerController::faceAtMouse(int mouseX, int mouseY) {
	Matrix3<float> gMat = m_parent->getTransform();
	Vector2<float> pos = gMat.getTranslation();


	float rot = atan2(mouseY - pos.y, mouseX - pos.x);

	m_parent->setRotate(rot);
	static_cast<GameEntity*>(m_parent)->getComponentOfType<CSpriteNode>()->setRotate(rot);
	// TODO: Refactor OBB to a component -> Or have RigidBody handle collision???
	//static_cast<GameEntity*>(m_parent)->getComponentOfType<OBB>()->setRotate(rot);
}
