#include "logger.hpp"

namespace Logger {
    void LogMessage(std::string text, uint8 level) {
        // Some OSes have a std output stream for errors.
        // We want to use it for errors and fatal errors where possible.
        if (level < LogLevel::WARN) {
            Platform::Console::WriteError(text, level);
        } else {
            Platform::Console::Write(text, level);
        }
    }

    void Fatal(std::string text) {
        LogMessage(text, LogLevel::FATAL);
    }

    void Error(std::string text) {
        LogMessage(text, LogLevel::ERROR);
    }

    void Warn(std::string text) {
        LogMessage(text, LogLevel::WARN);
    }

    void Info(std::string text) {
        LogMessage(text, LogLevel::INFO);
    }

    void Debug(std::string text) {
        if (GRAPE_LOGGER_DEBUG == 1) {
            LogMessage(text, LogLevel::DEBUG);
        }
    }
}