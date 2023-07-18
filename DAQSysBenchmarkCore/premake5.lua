project "DAQSysBenchmarkCore"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"


    targetdir ("..bin/" .. outputdir .. "/%{prj.name}")
    objdir ("..bin-int/" .. outputdir .. "/%{prj.name}")

-- not use precompiled header

    pchheader "pch.h"
    pchsource "src/pch.cpp"

    files 
    {
        "src/pch.h",
        "src/pch.cpp",
        "src/DAQSysBenchmarkCore.h",

        -- Core file include
        "src/DAQSysBenchmarkCore/Core/**.h", 
        "src/DAQSysBenchmarkCore/Core/**.cpp", 

        -- Debug
        "src/DAQSysBenchmarkCore/Debug/**.h",
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "NMROS_PROFILE_ON",
        "AF_IMP_WITH_DEFINITION",
    }

    includedirs
    {
        "src",
        "vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.IMGUI}",
        "%{IncludeDir.GLM}",
        "%{IncludeDir.STB_IMAGE}",
        "%{IncludeDir.EIGEN}",
        "%{IncludeDir.MAGICENUM}",
    }

    links
    {
        "GLFW",
        "GLAD",
        "IMGUI",
    }

    filter "system:windows"
        systemversion "latest"
        
    filter "configurations:Debug"
        defines "NMROS_DEBUG"
        runtime "Debug"
        symbols "on"
        staticruntime "off"

    filter "configurations:Release"
        defines "NMROS_RELEASE"
        runtime "Release"
        optimize "on"
        staticruntime "on"
