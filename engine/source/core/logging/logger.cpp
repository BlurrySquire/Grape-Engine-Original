#include "logger.hpp"

#if defined(GRAPE_DEBUG)
    #include <spdlog/sinks/stdout_color_sinks.h>
#endif

#include <spdlog/sinks/basic_file_sink.h>

namespace GRAPE
{
	Logger::Logger(const std::string& fileName) noexcept
	{
#if defined(GRAPE_DEBUG)
		m_Sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		m_Sinks.back()->set_pattern("%^%L: %v%$");
#endif

		m_Sinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(fileName + ".log", true));
		m_Sinks.back()->set_pattern("%L: %v");

		s_Logger = std::make_unique<spdlog::logger>("Logger", m_Sinks.begin(), m_Sinks.end());

#if defined(GRAPE_DEBUG)
		s_Logger->set_level(spdlog::level::trace);
		s_Logger->flush_on(spdlog::level::trace);
#elif defined(GRAPE_RELEASE)
		s_Logger->set_level(spdlog::level::info);
		s_Logger->flush_on(spdlog::level::info);
#endif
	}

	Logger::~Logger() noexcept
	{
		spdlog::drop_all();
	}

	const std::unique_ptr<spdlog::logger>& Logger::GetLogger() noexcept
	{
		return s_Logger;
	}
} // namespace GRAPE