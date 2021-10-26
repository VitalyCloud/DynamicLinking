#include "Application.h"
#include "LoadDLL.hpp"

typedef Scene*(*CreateSceneFn)();

static void* dll = nullptr;

Application::Application()
{
    
#ifdef EN_PLATFORM_WINDOWS
    const char path[] = "Sandbox.dll";
#elif defined(EN_PLATFORM_MACOSX)
    const char path[] = "libSandbox.dylib";
#endif

    dll = DLL::Load(path);
    if(!dll) {
        std::cout << "Failed to load library:" << path << std::endl;
        std::exit(-1);
    }
    CreateSceneFn fn = (CreateSceneFn)DLL::GetFunction(dll, "CreateScene");
    if(!fn) {
        std::cout << "Failed to load function\n";
        std::exit(-1);
    }
    m_ActiveScene = fn();

}

Application::~Application()
{
    delete m_ActiveScene;
    DLL::Unload(dll);
}

void Application::Run()
{
	m_ActiveScene->OnUpdate();
}

