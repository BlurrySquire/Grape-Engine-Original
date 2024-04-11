#include "../platform.hpp"

#include <windows.h>
#include <windowsx.h>

#include <sstream>

LRESULT CALLBACK WindowProc(HWND hwnd, uint32_t msg, WPARAM w_param, LPARAM l_param);

std::string Platform::Time_GetLocal() {
    SYSTEMTIME time;
    std::stringstream time_str;

    GetLocalTime(&time);

    time_str << "[";
    time_str << time.wDay << "/" << time.wMonth << "/" << time.wYear;
    time_str << ", " << time.wHour << ":" << time.wMinute << ":" << time.wSecond;
    time_str << "]";

    return time_str.str();
}