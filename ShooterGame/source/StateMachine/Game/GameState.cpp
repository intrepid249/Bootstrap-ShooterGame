#include <Settings.h>
#include <ShooterGameApp.h>

#include <StateMachine\Game\GameState.h>
#include <ResourceManager.h>
#include <StateMachine\Game\GameStateManager.h>

#include <Renderer2D.h>
#include <Font.h>
#include <Input.h>

#include <Components\CComponent.h>
#include <Components\CSpriteNode.h>
#include <Entities\GameEntity.h>
#include <Entities\Player.h>
#include <Entities\Enemies\Gargant.h>

#include <Entities\EnemyFactory.h>

#include <imgui.h>
#include <ShooterGameApp.h>
#include <GLFW\glfw3.h>

GameState::GameState(ShooterGameApp *app) : IGameState(app) {
	m_font = ResourceManager::loadUniqueResource<aie::Font>("./font/consolas.ttf", 32);
	m_elapsedTime = 0;

	m_textures[PLAYER_TEX] = ResourceManager::loadSharedResource<aie::Texture>("./textures/player_handgun.png");
	m_player = std::unique_ptr<Player>(new Player(m_textures[PLAYER_TEX].get()));
	m_player->translate(Vector2<float>(500, 500));

	m_textures[GARGANT_TEX] = ResourceManager::loadSharedResource<aie::Texture>("./textures/gargant.png");
	//m_gargant = std::unique_ptr<Gargant>(new Gargant(m_textures[GARGANT_TEX].get()));
	m_gargant = EnemyFactory::spawn("gargant", m_textures[GARGANT_TEX].get());
	m_gargant->translate(Vector2<float>(300, 300));

	strcpy_s(m_windowTitle, "Endlesssss");
}

GameState::~GameState() {
}

void GameState::update(float dt) {

	//https://github.com/ocornut/imgui/blob/master/examples/opengl3_example/main.cpp
	//https://eliasdaler.github.io/using-imgui-with-sfml-pt1/
	//https://eliasdaler.github.io/using-imgui-with-sfml-pt2/
	ImGui::SetWindowPos(ImVec2(0, 0));
	ImGui::SetWindowSize(ImVec2(350, 600));
	ImGui::Text("Hello World");

	ImGui::InputText("Window Title", m_windowTitle, 255);

	if (ImGui::Button("Update Window Title"))
		glfwSetWindowTitle(getApp()->getWindowPtr(), m_windowTitle);


	if (getApp()->getGameStateManager()->getTopState() != this) return;

	m_elapsedTime += dt;
		
	aie::Input *input = aie::Input::getInstance();

	/// Pause the game
	if (input->wasKeyPressed(aie::INPUT_KEY_ESCAPE)) {
		getApp()->getGameStateManager()->pushState((int)eGameStateID::PAUSE_STATE);
	}

	m_player->update(dt);
	m_gargant->update(dt);

	ImGui::Render();
}

void GameState::render(aie::Renderer2D * renderer) {
	char buffer[255];
	sprintf_s(buffer, "%.2f", m_elapsedTime);

	m_player->render(renderer);
	m_gargant->render(renderer);

	renderer->drawText(m_font.get(), buffer, 10, 30);
	renderer->drawText(m_font.get(), "Game State", 10, 10);
}
