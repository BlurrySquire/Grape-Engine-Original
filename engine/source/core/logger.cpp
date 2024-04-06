#include "logger.hpp"

Logger::Logger(const std::string& filepath) noexcept {
    this->m_filepath = filepath;
    this->m_backlog.clear();

    // Make sure the file exists by creating a blank one.
    std::fstream file(this->m_filepath, std::ios::out);
    if (file.is_open()) {
        file.write("", 0);
        file.close();
    }
}

Logger::~Logger() {
    this->WriteBacklog();
}

void Logger::LogMessage(const std::string& text, LogLevel log_level) {
    if (log_level < LogLevel::WARN) {
        Platform::Console::WriteError(text, log_level);
    } else {
        Platform::Console::Write(text, log_level);
    }
    
    this->m_backlog.emplace_back(text);

    if (this->m_backlog.size() == 5) {
        this->WriteBacklog();
    }
}

void Logger::ClearBacklog() {
    this->m_backlog.clear();
}

void Logger::WriteBacklog() {
    std::fstream file(this->m_filepath, std::ios::app);
    if (file.is_open()) {
        int backlog_size = this->m_backlog.size();
        for (int i = 0; i < backlog_size; i++) {
            std::string text = this->m_backlog[i];
            file.write(text.c_str(), text.size());
        }
        file.close();
    }
    this->ClearBacklog();
}

void Logger::Fatal(const std::string& text) {
    this->LogMessage("[FATAL]: " + text, LogLevel::FATAL);
}

void Logger::Error(const std::string& text) {
    this->LogMessage("[ERROR]: " + text, LogLevel::ERROR);
}

void Logger::Warn(const std::string& text) {
    this->LogMessage("[WARN]: " + text, LogLevel::WARN);
}

void Logger::Info(const std::string& text) {
    this->LogMessage("[INFO]: " + text, LogLevel::INFO);
}

void Logger::Debug(const std::string& text) {
    if (GRAPE_LOGGER_DEBUG == 1) {
        this->LogMessage("[DEBUG]: " + text, LogLevel::DEBUG);
    }
}

void Logger::Trace(const std::string& text) {
    if (GRAPE_LOGGER_DEBUG == 1) {
        this->LogMessage("[TRACE]: " + text, LogLevel::TRACE);
    }
}