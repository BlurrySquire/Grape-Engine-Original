#pragma once

// NOTE: Credit goes to Travis Vroman for the design and structure
// of this file. I have modified it for use with C++ and to
// better suit my game engine.
// Changes Made:
// - I use variable types from 'cstdint' from std rather than custom types.
// - I don't check for the Posix, Mac or IOS platforms.
// - I use 'GRAPE_API' instead of 'KAPI'.
// - I don't static assert to ensure the data types are the correct size.

// NOTE: This file contains basic data structures and macros that
// are common the the entire engine. There is also checks in place
// to detect what platform it is being ran on.

// Common Variable Types
#include <cstdint>

// Static Assertion
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// DLL Export & Import
#ifdef GRAPE_EXPORT
    #ifdef _MSC_VER
        #define GRAPE_API __declspec(dllexport)
    #else
        #define GRAPE_API __attribute__((visibility("default")))
    #endif
#else
    #ifdef _MSC_VER
        #define GRAPE_API __declspec(dllimport)
    #else
        #define GRAPE_API
    #endif
#endif

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