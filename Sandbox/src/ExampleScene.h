#pragma once

#include "EngineAPI.h"

#define DLL_EXPORT __declspec(dllexport)

class DLL_EXPORT ExampleScene: public Scene
{
public:
	ExampleScene();
	virtual ~ExampleScene();

	virtual void OnUpdate() override;
};

