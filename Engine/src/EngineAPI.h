
#include "Core/PlatformDetection.h"
#ifdef EN_PLATFORM_WINDOWS
	#define EXPORT_DLL __declspec(dllexport)
#elif EN_PLATFORM_MACOSX
	#define EXPORT_DLL __attribute__ ((visibility ("default")))
#endif

#include "Core/Scene.h"
#define EXPORT_SCENE(x) extern "C" { EXPORT_DLL Scene* CreateScene() { return new x(); } }