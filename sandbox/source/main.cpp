#include <defines.hpp>
#include <platform/platform.hpp>

#include <windows.h>

int main()
{
    // TODO: Move the logging over to a custom logger
    // rather than doing it this way.
    Platform::Console::Write("Fatal message.\n", 0);
    Platform::Console::Write("Error message.\n", 1);
    Platform::Console::Write("Warn message.\n", 2);
    Platform::Console::Write("Debug message.\n", 3);
    Platform::Console::Write("Info message.\n", 4);

    return EXIT_SUCCESS;
}