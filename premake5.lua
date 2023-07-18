include "./vendor/premake_customization/solution_items.lua"

workspace "DAQSysBenchmark"
    architecture "x86_64"
    startproject "DAQSysBenchmarkDemo"

    configurations
    {
        "Debug",
        "Release",
    }

    solution_items
    {
        ".editorconfig"
    }

    flags
    {
        "MultiProcessorCompile"
    }

    defines
    {
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    -- Include directories relative to root folder (solution directory)
    IncludeDir = {}
    IncludeDir["GLFW"]                  = "%{wks.location}/DAQSysBenchmarkCore/vendor/glfw/include"
    IncludeDir["GLAD"]                  = "%{wks.location}/DAQSysBenchmarkCore/vendor/glad/include"
    IncludeDir["IMGUI"]                 = "%{wks.location}/DAQSysBenchmarkCore/vendor/imgui"
    IncludeDir["GLM"]                   = "%{wks.location}/DAQSysBenchmarkCore/vendor/glm"
    IncludeDir["STB_IMAGE"]             = "%{wks.location}/DAQSysBenchmarkCore/vendor/stb_image"
    IncludeDir["EIGEN"]                 = "%{wks.location}/DAQSysBenchmarkCore/vendor/eigen"
    IncludeDir["MAGICENUM"]             = "%{wks.location}/DAQSysBenchmarkCore/vendor/magic_enum/include"

    -- projects
    group "Dependencies"
        include "DAQSysBenchmarkCore/vendor/glfw"
        include "DAQSysBenchmarkCore/vendor/glad"
        include "DAQSysBenchmarkCore/vendor/imgui"
    group ""


    include "DAQSysBenchmarkCore"
    include "DAQSysBenchmarkDemo"
