#pragma once

#include "EngineAPI.h"

class ExampleScene: public Scene
{
public:
	ExampleScene() {}
	virtual ~ExampleScene() {} 

	virtual void OnUpdate() override {
		std::cout << "ExampleScene::OnUpdate() from EXPORT_SCENE(ExampleScene)\n";
	}
};

EXPORT_SCENE(ExampleScene)


