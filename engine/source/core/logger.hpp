#include "../defines.hpp"
#include "../platform/platform.hpp"

#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// NOTE: We only want to show debug messages if we are in debug mode.
#ifdef GRAPE_DEBUG
    #define GRAPE_LOGGER_DEBUG 1
#else
    #define GRAPE_LOGGER_DEBUG 0
#endif

class [[nodiscard]] Logger {
private:
    enum LogLevel : uint8_t {
        FATAL = 0,
        ERROR = 1,
        WARN = 2,
        INFO = 3,
        DEBUG = 4,
        TRACE = 5
    };

    std::string m_filepath;
    std::vector<std::string> m_backlog;

    void LogMessage(const std::string& text, LogLevel log_level);

public:
    explicit Logger(const std::string& filepath = "grape_log.txt") noexcept;
    ~Logger();

    void Fatal(const std::string& text);
    void Error(const std::string& text);
    void Warn(const std::string& text);
    void Info(const std::string& text);
    void Debug(const std::string& text);
    void Trace(const std::string& text);

    /*
        Clears all saved log messages from the backlog.
    */
    void ClearBacklog();

    /*
        Writes all log messages from the backlog to the log file then clears it.
    */
    void WriteBacklog();
};