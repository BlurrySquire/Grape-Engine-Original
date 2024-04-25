#pragma once

#include "../defines.hpp"
#include "logging/logger.hpp"
#include "../platform/platform.hpp"
#include "../platform/window.hpp"

namespace GRAPE {
	class Application {
	private:
		Logger m_logger;
		Window* m_window;

		std::wstring m_title;
		uint32_t m_width, m_height;
	public:
		/*
		* @brief Creates a grape application on construction.
		* @param std::wstring: The title of the application.
		* @param uint32_t: The width of the rendering canvas.
		* @param uint32_t: The height of the rendering canvas.
		* @returns Nothing
		* 
		* @method: Application
		* @fullname: GRAPE::Application::Application
		* @qualifier: Nothing
		*/
		Application(std::wstring title, uint32_t width, uint32_t height);

		/*
		* @brief Exits the application upon destruction.
		* @returns Nothing
		*
		* @method: ~Application
		* @fullname: GRAPE::Application::~Application
		* @qualifier: Nothing
		*/
		~Application();

		/*
		* @brief Wrapper for the platform layer method 'Platform::Time_Sleep'.
		* @param uint32_t: The number of milliseconds to sleep for.
		* @returns Nothing
		*/
		void TimeSleep(const uint32_t milliseconds);

		/*
		* @brief Wrapper for the platform layer method 'Platform::Time_GetLocal'.
		* @returns struct containing hour, minute, second, and millisecond.
		*/
		SystemTime GetLocalTime();

		/*
		* @brief Wrapper for the platform layer method 'Platform::Time_GetDate'.
		* @returns struct containing day, week, month, year, and day of week.
		*/
		SystemDate GetLocalDate();
	};
}