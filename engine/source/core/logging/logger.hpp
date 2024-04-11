#pragma once

#include "logger_macros.hpp"
#include <spdlog/spdlog.h>

namespace GRAPE
{
	class [[nodiscard]] Logger final
	{
	public:
		Logger() noexcept = delete;

		//************************************
		// Initializes the logging system upon construction which uses spdlog (https://github.com/gabime/spdlog).
		// The extension ".log" gets added to the given file name.
		// Method:    Logger
		// FullName:  GRAPE::Logger::Logger
		// Access:    public
		// Returns:   
		// Qualifier: noexcept
		// Parameter: const std::string& fileName
		//************************************
		explicit Logger(const std::string& fileName) noexcept;

		Logger(const Logger&) noexcept = delete;
		Logger(Logger&&) noexcept = delete;
		Logger& operator = (const Logger&) noexcept = delete;
		Logger& operator = (Logger&&) noexcept = delete;

		//************************************
		// Drops all loggers upon destruction.
		// Method:    ~Logger
		// FullName:  GRAPE::Logger::~Logger
		// Access:    public
		// Returns:   
		// Qualifier: noexcept
		//************************************
		~Logger() noexcept;

		//************************************
		// Returns a const reference to the pointer of the logger.
		// Method:    GetLogger
		// FullName:  GRAPE::Logger::GetLogger
		// Access:    public
		// Returns:   const std::unique_ptr<spdlog>&
		// Qualifier: noexcept
		//************************************
		[[nodiscard]] static const std::unique_ptr<spdlog::logger>& GetLogger() noexcept;
	private:
		std::vector<spdlog::sink_ptr> m_Sinks{};
		static inline std::unique_ptr<spdlog::logger> s_Logger = nullptr;
	};
} // namespace GRAPE