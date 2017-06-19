#include <StateMachine\Game\LoadState.h>
#include <ResourceManager\ResourceManager.hpp>
#include <Settings.h>

#include <Font.h>

using namespace RM;

LoadState::LoadState(ShooterGameApp *_app) : IGameState(_app) {
	//ResourceManager<aie::Font>::load(GS_FONT_MAIN, "./font/consolas.ttf", 32);
}


LoadState::~LoadState() {
}
