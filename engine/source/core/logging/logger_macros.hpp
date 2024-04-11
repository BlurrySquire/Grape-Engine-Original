#pragma once

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