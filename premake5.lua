IncludeDirectories = {}
IncludeDirectories["engine"] = "%{wks.location}/engine"
IncludeDirectories["vulkan"] = path.join(os.getenv("VULKAN_SDK"), "Include")
IncludeDirectories["spdlog"] = "%{wks.location}/submodules/spdlog/include"
IncludeDirectories["glfw"]   = "%{wks.location}/submodules/glfw/include"

workspace "Grape-Engine"
	architecture	"x86_64"
	startproject	"Sandbox"

	targetdir		".build/bin/%{cfg.system}/%{cfg.buildcfg}/%{prj.name}"
	objdir			".build/obj/%{cfg.system}"

	flags
	{
		"MultiProcessorCompile",
		"FatalWarnings"
	}

	configurations
	{
		"Debug",
		"Release"
	}
	
	filter "configurations:Debug"
		defines		"GRAPE_DEBUG"
		optimize	"Off"
		runtime		"Debug"
		symbols		"Full"

	filter "configurations:Release"
		defines		"GRAPE_RELEASE"
		optimize	"Full"
		runtime		"Release"
		symbols		"Off"

	filter "system:windows"
		systemversion	"latest"
		staticruntime	"On"
		
		defines
		{
			"GRAPE_PLATFORM_WINDOWS",
			"_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS"
		}

include "engine/engine.lua"
include "sandbox/sandbox.lua"

include "submodules/glfw_premake5.lua"