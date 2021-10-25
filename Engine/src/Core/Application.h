#pragma once

#include "Scene.h"

class Application
{
public:
	Application();
	virtual ~Application();

	void Run();

private:
	Scene* m_ActiveScene;
};

