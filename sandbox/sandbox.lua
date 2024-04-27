project "Sandbox"
	kind		"ConsoleApp"
	language	"C++"
	cppdialect	"C++latest"
	warnings	"Extra"

	files
	{
		"source/**.hpp",
		"source/**.cpp"
	}

	includedirs
	{
		"%{prj.location}/source",
		"%{IncludeDirectories.engine}",
		"%{IncludeDirectories.glfw}",
		"%{IncludeDirectories.spdlog}"
	}

	dependson	"Engine"
	links		"Engine"