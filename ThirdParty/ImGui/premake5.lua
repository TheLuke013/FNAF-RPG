project "DearImGui"
	kind "StaticLib"
	language "C++"

	targetdir ("../../bin/")
	objdir ("../../obj/")

	files
	{
		"include/**.h",
		"src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS",
		"_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING"
	}

	includedirs
	{
		"include/ImGui",
		"../SDL2/include/SDL"
	}

	links
	{
		"../SDL2/lib/SDL2.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"