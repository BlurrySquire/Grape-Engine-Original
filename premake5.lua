workspace "Grape-Engine"
    architecture "x86_64"
    configurations { "Debug", "Release" }
    flags { "MultiProcessorCompile" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Engine"
    location "engine/"
    kind "StaticLib"
    language "C++"
    warnings "Extra"

    targetdir ("bin/" .. outputdir)
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files { "%{prj.name}/source/**.hpp", "%{prj.name}/source/**.cpp" }

    includedirs { "%{prj.name}/source", "%{VULKAN_SDK}/Include" }
    libdirs { "$(VULKAN_SDK)/Lib" }

    links { "vulkan-1.lib" }

    defines { "GRAPE_EXPORT" }

    filter "system:windows"
        cppdialect "C++20"
        systemversion "latest"
    
    filter "configurations:Debug"
        defines { "GRAPE_DEBUG" }
        symbols "On"
    
    filter "configurations:Release"
        defines { "GRAPE_RELEASE" }
        optimize "On"

project "Sandbox"
    location "sandbox/"
    kind "ConsoleApp"
    language "C++"
    warnings "Extra"

    targetdir ("bin/" .. outputdir)
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files { "%{prj.name}/source/**.hpp", "%{prj.name}/source/**.cpp" }

    includedirs { "%{prj.name}/source", "engine/source" }

    links { "Engine" }

    defines { "GRAPE_IMPORT" }

    filter "system:windows"
        cppdialect "C++20"
        systemversion "latest"
    
    filter "configurations:Debug"
        defines { "GRAPE_DEBUG" }
        symbols "On"
    
    filter "configurations:Release"
        defines { "GRAPE_RELEASE" }
        optimize "On"