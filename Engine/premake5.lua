project "Engine"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.hpp",
        "src/**.cpp",
    }

    includedirs
    {
        "src",
    }

    filter "system:windows"
        systemversion "latest"

    filter "system:macosx"
        systemversion "10.14"

    filter "configurations:Debug"
        defines { "EN_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "EN_NDEBUG" }
        optimize "On"
