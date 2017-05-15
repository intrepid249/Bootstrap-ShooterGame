#pragma once
namespace aie {
	class Renderer2D;
}
class ShooterGameApp;

class IGameState {
public:
	IGameState(ShooterGameApp *app) : m_app(app) {}
	virtual ~IGameState() = default;

	virtual void update(float dt) = 0;
	virtual void render(aie::Renderer2D *renderer) = 0;

	ShooterGameApp *getApp() { return m_app; }

protected:
	ShooterGameApp *m_app;
};

