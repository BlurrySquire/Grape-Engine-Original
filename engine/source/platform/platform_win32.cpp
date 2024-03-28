#include "platform.hpp"

#ifdef GRAPE_PLATFORM_WINDOWS

#include <windows.h>
#include <windowsx.h>

#include <string>

LRESULT CALLBACK WindowProc(HWND hwnd, uint32_t msg, WPARAM w_param, LPARAM l_param);

namespace Platform {

    void Init() {

    }

    void Close() {

    }

    namespace Console {
        uint8_t LoggerColours[6] = {
            BACKGROUND_RED | 0,                 // FATAL
            FOREGROUND_RED,                     // ERROR 
            FOREGROUND_RED | FOREGROUND_GREEN,  // WARN
            FOREGROUND_GREEN,                   // INFO
            FOREGROUND_BLUE,                    // DEBUG
            FOREGROUND_INTENSITY                // TRACE
        };

        void Write(const std::string& text, uint8_t colour) {
            HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
            LPDWORD number_written = 0;

            SetConsoleTextAttribute(console_handle, LoggerColours[colour]);
            WriteConsoleA(console_handle, text.c_str(), static_cast<DWORD>(text.size()), number_written, 0);

        }

        void WriteError(const std::string& text, uint8_t colour) {
            HANDLE console_handle = GetStdHandle(STD_ERROR_HANDLE);
            LPDWORD number_written = 0;

            SetConsoleTextAttribute(console_handle, LoggerColours[colour]);
            WriteConsoleA(console_handle, text.c_str(), static_cast<DWORD>(text.size()), number_written, 0);
        }
    }
}

#endif