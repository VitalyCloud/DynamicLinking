project "Sandbox"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.hpp",
        "src/**.cpp"
    }

    includedirs
	{
		"%{wks.location}/Engine/src"
    }

    links
	{
		"Engine"
	}

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Engine")
    }

    defines
    {
        "EN_BUILD_DLL"
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
