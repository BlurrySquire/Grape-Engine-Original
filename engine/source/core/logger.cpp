#include "logger.hpp"

namespace Logger {
    void LogMessage(const std::string& text, uint8 level) {
        // Some OSes have a std output stream for errors.
        // We want to use it for errors and fatal errors where possible.
        if (level < LogLevel::WARN) {
            Platform::Console::WriteError(text, level);
        } else {
            Platform::Console::Write(text, level);
        }
    }

    void Fatal(const std::string& text) {
        LogMessage(text, LogLevel::FATAL);
    }

    void Error(const std::string& text) {
        LogMessage(text, LogLevel::ERROR);
    }

    void Warn(const std::string& text) {
        LogMessage(text, LogLevel::WARN);
    }

    void Info(const std::string& text) {
        LogMessage(text, LogLevel::INFO);
    }

    void Debug(const std::string& text, bool override) {
        // NOTE: Only show debug messages if we are in debug mode.
        // We can also override this if needed, so we can
        // print debug messages when we are in release mode.
        if (GRAPE_LOGGER_DEBUG == 1 || override == true) {
            LogMessage(text, LogLevel::DEBUG);
        }
    }
}