#pragma once

// DLL Export & Import
#ifdef GRAPE_EXPORT
    #ifdef _MSC_VER
        #define GRAPE_API __declspec(dllexport)
    #else
        #define GRAPE_API __attribute__((visibility("default")))
    #endif
#endif

// Static Assertions
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// Booleans
#define TRUE 1
#define FALSE 0

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
    #define GRAPE_PLATFORM_UNIX
#else
    #define GRAPE_PLATFORM_UNKNOWN 1
    #error "Unsupported or unknown platform."
#endif