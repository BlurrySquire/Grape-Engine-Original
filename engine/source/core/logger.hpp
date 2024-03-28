#include "../defines.hpp"
#include "../platform/platform.hpp"

#include <sstream>
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

    GRAPE_API void LogMessage(const std::string& text, const LogLevel level);

    GRAPE_API void Fatal(const std::string& text);
    GRAPE_API void Error(const std::string& text);
    GRAPE_API void Warn(const std::string& text);
    GRAPE_API void Info(const std::string& text);
    GRAPE_API void Debug(const std::string& text);
}