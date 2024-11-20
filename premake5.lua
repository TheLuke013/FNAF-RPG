workspace "FNAF-RPG"
	startproject "Game"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

group "Libs"
	include "ThirdParty/ImGui"
group ""

project "Engine"
	location "Engine"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/")
	objdir ("obj/")

	files
	{
		"%{prj.name}/include/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS",
		"_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING",
		"GAME_DEVELOPMENT"
	}

	includedirs
	{
		"%{prj.name}/include",
		"ThirdParty/ImGui/include",
		"ThirdParty/SDL2/include",
		"ThirdParty/SDL2/include/SDL",
		"ThirdParty/spdlog/include"
	}

	links
	{
		"ThirdParty/SDL2/lib/SDL2.lib",
		"ThirdParty/SDL2/lib/SDL2main.lib",
		"DearImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
        systemversion "latest"
        links
		{
            "Winmm", "Imm32", "Version"
        }

		postbuildcommands
		{
			"{COPY} ../ThirdParty/SDL2/lib/SDL2.dll ../bin/"
		}

    filter "system:linux"
        links
		{
            "pthread", "dl", "m", "X11"
        }

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"

project "Game"
	location "Game"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/")
	objdir ("obj/")

	files
	{
		"%{prj.name}/include/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS",
		"_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING"
	}

	includedirs
	{
		"Engine/include",
		"ThirdParty/ImGui/include",
		"ThirdParty/SDL2/include",
		"ThirdParty/SDL2/include/SDL",
		"ThirdParty/spdlog/include"
	}

	links
	{
		"Engine"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"	
