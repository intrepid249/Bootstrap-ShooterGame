#pragma once

#include <Application.h>
#include <Renderer2D.h>
#include <memory>

class aie::Font;

class IGameState;
class GameStateManager;

class ShooterGameApp : public aie::Application {
public:

	ShooterGameApp();
	virtual ~ShooterGameApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	GameStateManager *getGameStateManager() { return m_gameStateManager.get(); }

protected:

	std::unique_ptr<aie::Renderer2D>	m_renderer;
	std::unique_ptr<GameStateManager>	m_gameStateManager;
};