#include "platform.hpp"

#ifdef GRAPE_PLATFORM_WINDOWS

#include <windows.h>
#include <windowsx.h>

namespace Platform {
    void Init() {

    }

    void Close() {

    }

    namespace Console {
        void Write(std::string text, uint8 colour) {
            HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
            uint64 length = strlen(text.c_str());
            LPDWORD number_written = 0;

            SetConsoleTextAttribute(console_handle, colour);
            WriteConsoleA(console_handle, text.c_str(), (DWORD)length, number_written, 0);

        }

        void WriteError(std::string text, uint8 colour) {
            HANDLE console_handle = GetStdHandle(STD_ERROR_HANDLE);
            uint64 length = strlen(text.c_str());
            LPDWORD number_written = 0;

            SetConsoleTextAttribute(console_handle, colour);
            WriteConsoleA(console_handle, text.c_str(), (DWORD)length, number_written, 0);
        }
    }
}

#endif