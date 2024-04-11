IncludeDirectories = {}
IncludeDirectories["engine"] = "%{wks.location}/engine/source"

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
			"GRAPE_PLATFORM_WINDOWS"
		}

include "engine/engine.lua"
include "sandbox/sandbox.lua"