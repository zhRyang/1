project "DAQSysBenchmarkDemo"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"


	targetdir ("..bin/" .. outputdir .. "/%{prj.name}")
	objdir ("..bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
        "src/Test.cpp"	
    }

    includedirs
    {
        "%{IncludeDir.GLM}",
        "%{wks.location}/DAQSysBenchmarkCore/src",
        "%{wks.location}/DAQSysBenchmarkCore/vendor",
        "%{wks.location}/DAQSysBenchmarkCore/vendor/spdlog/include",
    }
    
    links
    {
        "DAQSysBenchmarkCore",
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
