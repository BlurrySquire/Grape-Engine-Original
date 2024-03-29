#include "logger.hpp"

// TODO: Move logging over to a separate thread as writing to a file takes a long time.

namespace Logger {
    void InitFile(const std::string& filename) {
        log_file = std::fstream(filename, std::ios::out);
        Info("Grape Engine Logger Init.\n");
    }

    void CloseFile() {
        Info("Grape Engine Logger Close.\n");
        log_file.close();
    }

    // Base function for logging strings, uses platform layer functions.
    void LogMessage(const std::string& text, const LogLevel level) {
        // Some OSes have a std output stream for errors.
        // We want to use it for errors and fatal errors where possible.
        if (level < LogLevel::WARN) {
            Platform::Console::WriteError(text, level);

            std::string log_time = Platform::Time::GetLocal();
            log_file.write(log_time.c_str(), log_time.size());
            log_file.write(text.c_str(), text.size());
        } else {
            Platform::Console::Write(text, level);
            
            std::string log_time = Platform::Time::GetLocal();
            log_file.write(log_time.c_str(), log_time.size());
            log_file.write(text.c_str(), text.size());
        }
    }

    // Logger message types: [Fatal, Error, Warn, Info, Debug, Trace]

    void Fatal(const std::string& text) {
        LogMessage("[FATAL]: " + text, LogLevel::FATAL);
    }

    void Error(const std::string& text) {
        LogMessage("[ERROR]: " + text, LogLevel::ERROR);
    }

    void Warn(const std::string& text) {
        LogMessage("[WARN]: " + text, LogLevel::WARN);
    }

    void Info(const std::string& text) {
        LogMessage("[INFO]: " + text, LogLevel::INFO);
    }

    void Debug(const std::string& text) {
        // NOTE: Only show debug messages if we are in debug mode.
        if (GRAPE_LOGGER_DEBUG == 1) {
            LogMessage("[DEBUG]: " + text, LogLevel::DEBUG);
        }
    }

    void Trace(const std::string& text) {
        // NOTE: Only show trace messages if we are in debug mode.
        if (GRAPE_LOGGER_DEBUG == 1) {
            LogMessage("[TRACE]: " + text, LogLevel::TRACE);
        }
    }
}