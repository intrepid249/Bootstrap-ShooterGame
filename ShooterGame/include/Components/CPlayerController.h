#pragma once
#include <Nodes\Node.h>
#include <Components\CComponent.h>

#include <map>

namespace aie {
	class Renderer2D;
	enum EInputCodes;
	class Input;
}

class CPlayerController : public Node, public CComponent {
public:
	CPlayerController();
	~CPlayerController();

	void update(float dt);

	void setControls(aie::EInputCodes up, aie::EInputCodes down, aie::EInputCodes left, aie::EInputCodes right);
	
private:
	void updateControls(aie::Input *input);
	void faceAtMouse(int mouseX, int mouseY);

	enum class EControlID { UP, DOWN, LEFT, RIGHT, INTERACT };
	std::map<EControlID, aie::EInputCodes> m_controls;

	float m_speed;
	bool m_moveFW, m_moveBW, m_moveL, m_moveR;
};

