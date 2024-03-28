#include <defines.hpp>
#include <core/logger.hpp>

#include <windows.h>

int main(void)
{
    // NOTE: Logger testing.
    Logger::Fatal("Fatal Error test.\n");
    Logger::Error("Error test.\n");
    Logger::Warn("Warn test.\n");
    Logger::Info("Info test.\n");
    Logger::Debug("Debug test.\n\n");

    // NOTE: Test to make sure we can enable and disable debug mode.
    Logger::Debug("You cannot see this message in release.\n");
    Logger::Debug("You can see this debug message in release.\n", true);

    return EXIT_SUCCESS;
}