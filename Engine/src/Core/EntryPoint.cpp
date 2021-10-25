#include <iostream>

#include "Application.h"

int main() {

	std::cout << "Starting program...\n";
	Application* app = new Application();
	app->Run();
	delete app;

	std::cout << "Finishing program...\n";
	return 0;
}