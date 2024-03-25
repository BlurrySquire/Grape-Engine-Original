#include <defines.hpp>
#include <core/logger.hpp>

#include <windows.h>

int main()
{
    Logger::Fatal("Fatal Error test.\n");
    Logger::Error("Error test.\n");
    Logger::Warn("Warn test.\n");
    Logger::Info("Info test.\n");
    Logger::Debug("Debug test.\n");

    return EXIT_SUCCESS;
}