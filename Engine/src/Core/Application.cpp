#include "Application.h"

#include <Windows.h>



typedef Scene*(*CreateSceneFn)();

Application::Application()
{
	const char* dll = "Sandbox.dll";
	HINSTANCE hInst = LoadLibraryA(dll);
	if (!hInst) {
		std::cout << "Failed to load library\n"; 
		std::exit(-1);
	}

	CreateSceneFn fn = (CreateSceneFn)GetProcAddress(hInst, "CreateScene");
	if (!fn)
	{
		std::cout << "Failed to load function\n";
		std::exit(-1);
	}

	m_ActiveScene = fn();

}

Application::~Application()
{
	delete m_ActiveScene;
}

void Application::Run()
{
	m_ActiveScene->OnUpdate();
}

