#include <StateMachine\Game\LoadGameDataState.h>
#include <Renderer2D.h>
#include <Font.h>
#include <ShooterGameApp.h>
#include <StateMachine\Game\GameStateManager.h>
#include <Settings.h>


LoadGameDataState::LoadGameDataState(ShooterGameApp *_app) : IGameState(_app) {
	m_font = std::unique_ptr<aie::Font>(new aie::Font("./font/consolas.ttf", 24));

	m_displayText = "Loading";
	m_elapsedTime = 0;
}


LoadGameDataState::~LoadGameDataState() {
}

void LoadGameDataState::update(float dt) {
	updateLoadText(dt);
	updateStateTimer(dt);
}

void LoadGameDataState::render(aie::Renderer2D * renderer) {
	char buffer[32];
	sprintf_s(buffer, "%2.2f", m_elapsedTime);

	renderer->drawText(m_font.get(), buffer, 10, 50);
	renderer->drawText(m_font.get(), m_displayText, 10, 10);
}

void LoadGameDataState::updateLoadText(float dt) {
	static float updateClock;
	static int checkNum;
	updateClock += dt;

	if (updateClock < delayTime) return;

	switch (checkNum) {
	case 0:
		m_displayText = "Loading";
		break;
	case 1:
		m_displayText = "Loading .";
		break;
	case 2:
		m_displayText = "Loading . .";
		break;
	case 3:
		m_displayText = "Loading . . .";
		checkNum = -1;
		break;
	}
	checkNum++;
	updateClock = 0;
}

void LoadGameDataState::updateStateTimer(float dt) {
	m_elapsedTime += dt;

	if (m_elapsedTime < 5) return;

	getApp()->getGameStateManager()->popState();
	getApp()->getGameStateManager()->pushState((int)eGameStateID::GAME_STATE);
}
