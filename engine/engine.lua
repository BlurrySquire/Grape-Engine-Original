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
		"%{VULKAN_SDK}/Include"
	}

	libdirs
	{
		"$(VULKAN_SDK)/Lib"
	}

    links
	{
		"vulkan-1.lib"
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