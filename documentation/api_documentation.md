# Grape Engine Docs - API
- [Return to README](https://github.com/BlurrySquire/Grape-Engine)
- [Return to Documentation](https://github.com/BlurrySquire/Grape-Engine/blob/main/documentation/documentation.md)

This area is a work in progress. Not everything will be documented at this point.

## Using the Logger
```c++
#include <core/logger.hpp>

int main(void) {
    // Optionally create a log file.
    Logger::InitFile("filename.txt");

    // Standard log message types
    Logger::Fatal("Fatal Error test.\n");
    Logger::Error("Error test.\n");
    Logger::Warn("Warn test.\n");
    Logger::Info("Info test.\n");
    Logger::Debug("Debug test.\n");
    Logger::Trace("Trace test.\n\n");

    // Normal message. Second argument to Logger::LogMessage() defaults to LogLevel::DEFAULT.
    Logger::LogMessage("This message is printed as default text.\n");

    // Close the file we are using as a log file.
    Logger::CloseFile();
    return 0;
}
```