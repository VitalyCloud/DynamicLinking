#pragma once

#include <iostream>

class Scene {
public:
    Scene() {}
    virtual ~Scene() = default;

    virtual void OnUpdate() {
        std::cout << "Default: Scene::OnUpdate()\n";
    }
};
 	
