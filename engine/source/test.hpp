#pragma once

#include <iostream>

#ifdef GRAPE_EXPORT
    #define GRAPE_API __declspec(dllexport)
#else
    #define GRAPE_API __declspec(dllimport)
#endif

GRAPE_API void PrintTest();