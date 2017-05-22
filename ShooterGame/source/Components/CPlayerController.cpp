#include <Components\CPlayerController.h>

#include <Matrix3.h>
#include <Utility.h>
#include <Input.h>


CPlayerController::CPlayerController() : m_speed(125), m_moveFW(false), m_moveBW(false), m_moveL(false), m_moveR(false) {
}

CPlayerController::~CPlayerController() {
}

void CPlayerController::update(float dt) {
	Node::update(dt);
	Matrix3<float> gMat = m_parent->getTransform();
	float rot = gMat.getRotationZ();

	if (m_moveFW)
		m_parent->translate(Vector2<float>(cosf(degToRad(rot)) * m_speed * dt, sinf(degToRad(rot)) * m_speed * dt));
	if (m_moveBW)
		m_parent->translate(Vector2<float>(-cosf(degToRad(rot)) * m_speed * dt, -sinf(degToRad(rot)) * m_speed * dt));
	if (m_moveL)
		m_parent->translate(Vector2<float>(sinf(degToRad(rot)) * m_speed * dt, cosf(degToRad(rot)) * m_speed * dt));
	if (m_moveR)
		m_parent->translate(Vector2<float>(-sinf(degToRad(rot)) * m_speed * dt, -cosf(degToRad(rot)) * m_speed * dt));

	// Update the controls
	aie::Input *input = aie::Input::getInstance();
	updateControls(input);
	faceAtMouse(input->getMouseX(), input->getMouseY());
}

void CPlayerController::setControls(aie::EInputCodes up, aie::EInputCodes down, aie::EInputCodes left, aie::EInputCodes right) {
	m_controls[EControlID::UP] = up;
	m_controls[EControlID::DOWN] = down;
	m_controls[EControlID::LEFT] = left;
	m_controls[EControlID::RIGHT] = right;
}

void CPlayerController::updateControls(aie::Input * input) {
	if (input->isKeyDown(m_controls[EControlID::UP]))
		m_moveFW = true;
	if (input->isKeyDown(m_controls[EControlID::DOWN]))
		m_moveBW = true;
	if (input->isKeyDown(m_controls[EControlID::LEFT]))
		m_moveL = true;
	if (input->isKeyDown(m_controls[EControlID::RIGHT]))
		m_moveR = true;

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

	m_parent->setRotate(atan2(mouseY - pos.y, mouseX - pos.x));
}
