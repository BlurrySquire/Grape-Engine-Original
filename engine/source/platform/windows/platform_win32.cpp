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
        .hour = static_cast<uint8_t>(time.wHour),
        .minute = static_cast<uint8_t>(time.wMinute),
        .second = static_cast<uint8_t>(time.wSecond),
        .millisecond = static_cast<uint8_t>(time.wMilliseconds)
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