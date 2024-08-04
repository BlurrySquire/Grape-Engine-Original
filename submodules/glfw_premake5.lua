project "GLFW"
    location    "%{wks.location}/submodules/glfw"
    kind        "StaticLib"
    language    "C"

    files
    {
        "%{prj.location}/src/**.c"
    }

    includedirs
    {
        "%{prj.location}/include",
        "%{prj.location}/src"
    }

    filter "system:windows"
        defines
        {
            "_GLFW_WIN32",
            "_CRT_SECURE_NO_WARNINGS"
        }

        removefiles
        {
            "%{prj.location}/src/cocoa**.c",
            "%{prj.location}/src/gl**.c",
            "%{prj.location}/src/linux**.c",
            "%{prj.location}/src/posix**.c",
            "%{prj.location}/src/wl**.c",
            "%{prj.location}/src/x11**.c",
            "%{prj.location}/src/xkb**.c",
        }
    
    filter "system:linux"
        defines
        {
            "_GLFW_X11",
        }