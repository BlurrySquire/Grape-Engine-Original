#include "../platform.hpp"

#include <windows.h>
#include <windowsx.h>

#include <sstream>

LRESULT CALLBACK WindowProc(HWND hwnd, uint32_t msg, WPARAM w_param, LPARAM l_param);

void Platform::Time_Sleep(const uint32_t milliseconds) {
    Sleep(milliseconds);
}

GRAPE::SystemTime Platform::Time_GetLocalTime() {
    SYSTEMTIME time;
    GetLocalTime(&time);

    return GRAPE::SystemTime{
        .hour = time.wHour,
        .minute = time.wMinute,
        .second = time.wSecond,
        .millisecond = time.wMilliseconds
    };
}

GRAPE::SystemDate Platform::Time_GetDate() {
    SYSTEMTIME time;
    GetLocalTime(&time);

    return GRAPE::SystemDate{
        .day = time.wDay,
        .month = time.wMonth,
        .year = time.wYear,
        .dayOfWeek = time.wDayOfWeek
    };
}