#include "ExampleScene.h"

#include <iostream>

ExampleScene::ExampleScene()
{
}

ExampleScene::~ExampleScene()
{
}

void ExampleScene::OnUpdate()
{
	std::cout << "ExampleScene::OnUpdate()\n";
}

extern "C" {
	DLL_EXPORT Scene* CreateExampleScene() {
		return new ExampleScene();
	}
}







