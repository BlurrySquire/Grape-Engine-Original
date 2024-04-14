#pragma once

#include "logger_macros.hpp"
#include <spdlog/spdlog.h>

#include <spdlog/fmt/ostr.h>

namespace GRAPE {
	class [[nodiscard]] Logger final {
	public:
		Logger() noexcept = delete;

		/*
		* @brief Initialises the logging system which uses spdlog. The extension '.log' is added to the given filename.
		* @param const std::string&: The filename of the log file ('.log' extension is added).
		* @returns Nothing
		* 
		* @method: Logger
		* @fullname: GRAPE::Logger::Logger
		* @qualifier: noexcept
		*/
		explicit Logger(const std::string& fileName) noexcept;

		Logger(const Logger&) noexcept = delete;
		Logger(Logger&&) noexcept = delete;
		Logger& operator = (const Logger&) noexcept = delete;
		Logger& operator = (Logger&&) noexcept = delete;

		/*
		* @brief Drops all spdlog loggers when called.
		* @returns Nothing.
		* 
		* @method: ~Logger
		* @fullname: GRAPE::Logger::~Logger
		* @qualifier: noexcept
		*/
		~Logger() noexcept;

		/*
		* @brief Returns a const reference to the pointer of the logger.
		* @returns const std::unique_ptr<spdlog>&: pointer to the spdlog logger.
		* 
		* @method: GetLogger
		* @fullname: GRAPE::Logger::GetLogger
		* @qualifier: noexcept
		*/
		[[nodiscard]] static const std::unique_ptr<spdlog::logger>& GetLogger() noexcept;
	private:
		std::vector<spdlog::sink_ptr> m_Sinks{};
		static inline std::unique_ptr<spdlog::logger> s_Logger = nullptr;
	};
} // namespace GRAPE