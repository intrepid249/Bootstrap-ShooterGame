#include "PathFindingApp.h"
#include <iostream>

int main() {
	auto app = new PathFindingApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}