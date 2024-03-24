#include <defines.hpp>
#include <platform/platform.hpp>

#include <windows.h>

int main()
{
    // TODO: Move the logging colours to platform layer.
    uint8 fatal_colour = BACKGROUND_RED | 0;
    uint8 error_colour = FOREGROUND_RED;
    uint8 warn_colour = FOREGROUND_RED | FOREGROUND_GREEN;
    uint8 debug_colour = FOREGROUND_GREEN;
    uint8 info_colour = FOREGROUND_INTENSITY;

    // TODO: Move the logging over to a custom logger
    // rather than doing it this way.
    Platform::Console::Write("Fatal message.\n", fatal_colour);
    Platform::Console::Write("Error message.\n", error_colour);
    Platform::Console::Write("Warn message.\n", warn_colour);
    Platform::Console::Write("Debug message.\n", debug_colour);
    Platform::Console::Write("Info message.\n", info_colour);

    return EXIT_SUCCESS;
}