#include <defines.hpp>
#include <core/logger.hpp>

int main(void)
{
    // NOTE: Test to make sure logger works with no file
    Logger::Info("Test logger with no file open.\n\n");

    Logger::InitFile("logger_test.txt");

    // NOTE: Logger testing.
    Logger::Fatal("Fatal Error test.\n");
    Logger::Error("Error test.\n");
    Logger::Warn("Warn test.\n");
    Logger::Info("Info test.\n");
    Logger::Debug("Debug test.\n");
    Logger::Trace("Trace test.\n\n");

    Logger::LogMessage("This message is printed as default text.\n");

    Logger::CloseFile();

    return EXIT_SUCCESS;
}