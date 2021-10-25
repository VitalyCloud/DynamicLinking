#include "Application.h"

#include <Windows.h>



typedef Scene*(*FNPTR)();

Application::Application()
{
	//m_ActiveScene = new Scene();


	HINSTANCE hInst = LoadLibrary(L"Sandbox.dll");
	if (!hInst) {
		std::cout << "Failed to load library\n"; 
		std::exit(-1);
	}

	FNPTR fn = (FNPTR)GetProcAddress(hInst, "CreateExampleScene");
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

