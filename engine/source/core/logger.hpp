#pragma once

#include <spdlog/spdlog.h>

#include <spdlog/fmt/ostr.h>

#if defined(GRAPE_DEBUG)
#define GRAPE_LOG_TRACE(...)	GRAPE::Logger::GetLogger()->trace(__VA_ARGS__)
#define GRAPE_LOG_DEBUG(...)	GRAPE::Logger::GetLogger()->debug(__VA_ARGS__)
#define GRAPE_LOG_INFO(...)		GRAPE::Logger::GetLogger()->info(__VA_ARGS__)
#define GRAPE_LOG_WARN(...)		GRAPE::Logger::GetLogger()->warn(__VA_ARGS__)
#define GRAPE_LOG_ERROR(...)	GRAPE::Logger::GetLogger()->error(__VA_ARGS__)
#define GRAPE_LOG_CRITICAL(...)	GRAPE::Logger::GetLogger()->critical(__VA_ARGS__)
#elif defined(GRAPE_RELEASE)
#define GRAPE_LOG_TRACE(...)
#define GRAPE_LOG_DEBUG(...)
#define GRAPE_LOG_INFO(...)		GRAPE::Logger::GetLogger()->info(__VA_ARGS__)
#define GRAPE_LOG_WARN(...)		GRAPE::Logger::GetLogger()->warn(__VA_ARGS__)
#define GRAPE_LOG_ERROR(...)	GRAPE::Logger::GetLogger()->error(__VA_ARGS__)
#define GRAPE_LOG_CRITICAL(...)	GRAPE::Logger::GetLogger()->critical(__VA_ARGS__)
#endif

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