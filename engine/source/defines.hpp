#pragma once

/*
NOTE: Credit goes to Travis Vroman for the design and structure
of this file. I have modified it for use with C++ and to
better suit my game engine.
Changes Made:
    - I use variable types from 'cstdint' from std rather than custom types.
    - I don't check for the Posix, Mac or IOS platforms.
    - My engine is a static library so I don't export/import functions from shared library.
    - I don't static assert to ensure the data types are the correct size.
*/

#include <string>
#include <cstdint>

using float32_t = float;
using float64_t = double;

namespace GRAPE {
    void Init();
}

// Static Assertion
#if defined(__clang__) || defined(__gcc__)
    #define STATIC_ASSERT _Static_assert
#else
    #define STATIC_ASSERT static_assert
#endif

// Check what platform we are using.
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
    #define GRAPE_PLATFORM_WINDOWS 1
    #ifndef _WIN64
        #error "64-Bit Windows is required."
    #endif
#elif defined(__linux__) || defined(__gnu_linux__)
    #if not defined(__ANDROID__)
        #define GRAPE_PLATFORM_LINUX 1
    #else
        #define GRAPE_PLATFORM_ANDROID 1
    #endif
#elif defined(__unix__)
    #define GRAPE_PLATFORM_UNIX 1
#else
    #define GRAPE_PLATFORM_UNKNOWN 1
    #error "Unsupported or unknown platform."
#endif