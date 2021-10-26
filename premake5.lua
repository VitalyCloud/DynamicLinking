workspace "DynamicLinking"
    architecture "x64"
     startproject "Engine"
    configurations
    {
        "Debug",
        "Release"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    include "Engine"
    include "Sandbox"

rmdirs = {
    'bin',
    'bin-int',
}

if _ACTION == "clean" then
    for _, dir in ipairs(rmdirs) do
        os.rmdir(dir)
    end
end