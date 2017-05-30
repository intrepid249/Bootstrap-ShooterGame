#include "ShooterGameApp.h"
#include <Settings.h>
#include <GLFW\glfw3.h>

#include <signal.h>
#include <Windows.h>

///////////////////////////////////////////////////////////////////////////////////
////	Created by:		Jack McCall
////	Description:	A simple top-down shooter game. Defend your base from the enemy
////					waves. Earn cash to purchase upgrades and survive longer
////	Credits:
////					Images from https://opengameart.org/
////

ShooterGameApp *app;

/** This function handles safe cleaning of memory in the event of system crash*/
void cleanMemory(int signum) {
	wchar_t buffer[256];
	swprintf(buffer, L" Signal interrupt code (%d)\nPress ok to exit the application safely", signum);

	MessageBox(NULL, buffer, L"Error", MB_ICONERROR | MB_TASKMODAL | MB_OK);
	
	app->shutdown();

	exit(signum);
}

int main() {
	// Activate the signals to handle memory when the program encounters an error
	signal(SIGINT, cleanMemory); /// Detection of interactive attention signal
	signal(SIGABRT, cleanMemory); /// Abnormal termination
	signal(SIGFPE, cleanMemory); /// Erroneous arithmetic operation
	signal(SIGILL, cleanMemory); /// Illegal instruction
	signal(SIGTERM, cleanMemory); /// Termination request
	signal(SIGSEGV, cleanMemory); /// Invalid access to storage

	///OpenGL
	// initialise GLFW so we can tweak some OpenGL settings
	glfwInit();
	// disable the window resizing
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	//==========================================================
	app = new ShooterGameApp();
	app->run(APPTITLE, SCREENWIDTH, SCREENHEIGHT, FULLSCREEN);
	delete app;

	return 0;
}