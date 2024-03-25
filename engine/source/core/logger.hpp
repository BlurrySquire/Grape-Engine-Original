#include "../defines.hpp"
#include "../platform/platform.hpp"

#include <string>

// We only want to show debug messages if we are in debug mode.
#ifdef GRAPE_DEBUG
    #define GRAPE_LOGGER_DEBUG 1
#else
    #define GRAPE_LOGGER_DEBUG 0
#endif

namespace Logger {
    enum LogLevel {
        FATAL = 0,
        ERROR = 1,
        WARN = 2,
        INFO = 3,
        DEBUG = 4
    };

    GRAPE_API void LogMessage(std::string text, uint8 level);

    GRAPE_API void Fatal(std::string text);
    GRAPE_API void Error(std::string text);
    GRAPE_API void Warn(std::string text);
    GRAPE_API void Info(std::string text);
    GRAPE_API void Debug(std::string text);
}