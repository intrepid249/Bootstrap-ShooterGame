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
#include <INI.h>

GameState::GameState(ShooterGameApp *app) : IGameState(app) {
	m_font = ResourceManager::loadUniqueResource<aie::Font>("./font/consolas.ttf", 32);
	m_elapsedTime = 0;

	INI<> ini("config/settings.ini", true);
	/// PATHFINDING
	ini.select("Level");
	m_mapSize.x = ini.get("MapWidth", 1);
	m_mapSize.y = ini.get("MapHeight", 1);
	std::cout << "Map: " << m_mapSize.x << ", " << m_mapSize.y << "\n";

	m_gridCellSize = Vector2<int>(32, 32);
	m_gridSize = Vector2<int>(m_mapSize.x / m_gridCellSize.x, m_mapSize.y / m_gridCellSize.y);


	m_textures[PLAYER_TEX] = ResourceManager::loadSharedResource<aie::Texture>("./textures/player_handgun.png");
	std::shared_ptr<Player> player = std::shared_ptr<Player>(new Player(m_textures[PLAYER_TEX].get(), this));
	player->translate(Vector2<float>(500, 500));

	m_entities.push_back(player);

	m_textures[GARGANT_TEX] = ResourceManager::loadSharedResource<aie::Texture>("./textures/gargant.png");
	//m_gargant = std::unique_ptr<Gargant>(new Gargant(m_textures[GARGANT_TEX].get()));
	std::shared_ptr<GameEntity> gargant = EnemyFactory::spawn("gargant", m_textures[GARGANT_TEX].get(), this);
	gargant->translate(Vector2<float>(300, 300));
	gargant->scale(Vector2<float>(2, 2));


	m_entities.push_back(gargant);

	strcpy_s(m_windowTitle, "");
}

GameState::~GameState() {
}

void GameState::update(float dt) {

// Display ImGUI editing window in debug mode
#ifdef _DEBUG
	//https://github.com/ocornut/imgui/blob/master/examples/opengl3_example/main.cpp
	//https://eliasdaler.github.io/using-imgui-with-sfml-pt1/
	//https://eliasdaler.github.io/using-imgui-with-sfml-pt2/
	ImGui::SetWindowPos(ImVec2(0, 0));
	ImGui::SetWindowSize(ImVec2(350, 600));
	ImGui::Text("Hello World");

	ImGui::InputText("Window Title", m_windowTitle, 255);

	if (ImGui::Button("Update Window Title"))
		glfwSetWindowTitle(getApp()->getWindowPtr(), m_windowTitle);

	// Show a menu to allow for background sprite tile editing
	ImGui::Begin("Background Tile Editor", (bool*)1);
	{
		// TODO: Implement a background tile-sheet editor
	}
	ImGui::End();

#endif // _DEBUG



	if (getApp()->getGameStateManager()->getTopState() != this) return;

	m_elapsedTime += dt;
		
	aie::Input *input = aie::Input::getInstance();

	/// Pause the game
	if (input->wasKeyPressed(aie::INPUT_KEY_ESCAPE)) {
		getApp()->getGameStateManager()->pushState((int)eGameStateID::PAUSE_STATE);
	}

	for (auto iter = m_entities.begin(); iter != m_entities.end(); iter++)
		(*iter)->update(dt);

	ImGui::Render();
}

void GameState::render(aie::Renderer2D * renderer) {
	char buffer[255];
	sprintf_s(buffer, "%.2f", m_elapsedTime);

	for (auto iter = m_entities.begin(); iter != m_entities.end(); iter++)
		(*iter)->render(renderer);

	renderer->drawText(m_font.get(), buffer, 10, 30);
	renderer->drawText(m_font.get(), "Game State", 10, 10);

#ifdef _DEBUG
	renderer->setRenderColour(0xff0000ff);
	for (int x = 1; x <= m_gridSize.x; ++x) {
		renderer->drawLine(x * m_gridCellSize.x, 0, x * m_gridCellSize.x, m_mapSize.y, 1, 1);
	}
	for (int y = 1; y <= m_gridSize.y; ++y) {
		renderer->drawLine(0, y * m_gridCellSize.y, m_mapSize.x, y * m_gridCellSize.y, 1, 1);
	}
	renderer->setRenderColour(0xffffffff);

#endif
}

std::vector<std::shared_ptr<GameEntity>> GameState::getWorldEntities() {
	return m_entities;
}
