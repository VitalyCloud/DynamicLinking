//
//  DLL.hpp
//  Engine
//
//  Created by Vitaly Cloud on 26.10.2021.
//

#ifndef LoadDLL_hpp
#define LoadDLL_hpp

#include "PlatformDetection.h"
#ifdef EN_PLATFORM_WINDOWS
    #include <Windows.h>
#elif defined(EN_PLATFORM_MACOSX)
    #include <dlfcn.h>
#else
    #error "Platform is not supported!"
#endif

#include <string>
#include <iostream>

class DLL {
public:
    static void* Load(const char* path) {
        #ifdef EN_PLATFORM_MACOSX
            return dlopen(path, RTLD_NOW);
        #elif defined(EN_PLATFORM_WINDOWS)
            return LoadLibraryA(path);
        #else
            #error "Platform is not supported!"
        #endif
    }

    static int Unload(void* handle) {
        #ifdef EN_PLATFORM_MACOSX
            return dlclose(handle);
        #elif defined(EN_PLATFORM_WINDOWS)
            return FreeLibrary((HMODULE)handle);
        #else
            #error "Platform is not supported!"
        #endif
    }

    static void* GetFunction(void* handle, const char* name) {
        #ifdef EN_PLATFORM_MACOSX
            return dlsym(handle, name);
        #elif defined(EN_PLATFORM_WINDOWS)
            return GetProcAddress((HMODULE)handle, name);
        #else
            #error "Platform is not supported!"
        #endif
    }
};



#endif /* DLL_hpp */
