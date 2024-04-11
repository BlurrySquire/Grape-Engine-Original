#include "platform.hpp"

#ifdef GRAPE_PLATFORM_WINDOWS

#include <windows.h>
#include <windowsx.h>

#include <sstream>
#include <string>

LRESULT CALLBACK WindowProc(HWND hwnd, uint32_t msg, WPARAM w_param, LPARAM l_param);

// Write text to the console. Optionally write to the std error stream.
// 'text' is the text to write to the console.
// 'colour' is an index in an array of Windows API console colours.
// 'as_error' defaults to false and decides if we should use the std error stream or not.
void Platform::Console_Write(const std::string& text, uint8_t colour, bool as_error) {
    uint8_t log_colours[6] = {
        BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,   // FATAL
        FOREGROUND_RED,                                                         // ERROR 
        FOREGROUND_RED | FOREGROUND_GREEN,                                      // WARN
        FOREGROUND_GREEN,                                                       // INFO
        FOREGROUND_BLUE,                                                        // DEBUG
        FOREGROUND_INTENSITY                                                    // TRACE
    };

    HANDLE console_handle;
    if (as_error == true) {
        console_handle = GetStdHandle(STD_ERROR_HANDLE);
    } else {
        console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    }

    LPDWORD number_written = 0;
    CONSOLE_SCREEN_BUFFER_INFO info;

    // Record the previous console colour.
    GetConsoleScreenBufferInfo(console_handle, &info);

    // Set text colour then write the text to the console.
    SetConsoleTextAttribute(console_handle, log_colours[colour]);
    WriteConsoleA(console_handle, text.c_str(), static_cast<DWORD>(text.size()), number_written, 0);

    // Set the console colour to its previous colour.
    SetConsoleTextAttribute(console_handle, info.wAttributes);
}

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

#endif