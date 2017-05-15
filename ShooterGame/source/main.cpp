#include "ShooterGameApp.h"
#include <Settings.h>
#include <GLFW\glfw3.h>

///////////////////////////////////////////////////////////////////////////////////
////	Created by:		Jack McCall
////	Description:	A simple top-down shooter game. Defend your base from the enemy
////					waves. Earn cash to purchase upgrades and survive longer
////

int main() {
	// initialise GLFW so we can tweak some OpenGL settings
	glfwInit();
	// disable the window resizing
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	auto app = new ShooterGameApp();
	app->run(APPTITLE, SCREENWIDTH, SCREENHEIGHT, FULLSCREEN);
	delete app;

	return 0;
}