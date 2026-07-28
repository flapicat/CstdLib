workspace "CstdLib"
    architecture "x64"
    startproject "CstdLib"

    configurations { 
        "Debug", 
        "Release" 
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CstdLib"
	location "CstdLib"
    kind "ConsoleApp"
    language "C"
    cdialect "C11"
    
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files{
        "%{prj.name}/src/**.c",
        "%{prj.name}/include/**.h"
    }
    
    includedirs{
		"%{prj.name}/src",
		"%{prj.name}/include",
    }

	filter "system:windows"
		systemversion "latest"
		buildoptions "/utf-8"

		filter "configurations:Debug"
			defines "DEBUG"
			runtime "Debug"
			symbols "On"

		filter "configurations:Release"
			defines "RELEASE"
			runtime "Release"
			optimize "On"