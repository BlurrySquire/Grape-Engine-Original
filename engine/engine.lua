project "Engine"
	kind		"StaticLib"
	language	"C++"
	cppdialect	"c++latest"
	warnings	"Extra"

	files
	{
		"source/**.hpp",
		"source/**.cpp"
	}

    includedirs
	{
		"%{prj.location}/source",
		"%{IncludeDirectories.spdlog}",
		"%{IncludeDirectories.vulkan}",
		"%{IncludeDirectories.glfw}"
	}

	libdirs
	{
		path.join(os.getenv("VULKAN_SDK"), "Lib"),
		"%{wks.location}/.build/bin/GLFW"
	}

    links
	{
		"vulkan-1",
		"GLFW"
	}

	filter "system:windows"
		removefiles
		{
			"source/platform/linux/*.hpp",
			"source/platform/linux/*.cpp"
		}

	filter "system:linux"
		removefiles
		{
			"source/platform/windows/*.hpp",
			"source/platform/windows/*.cpp"
		}