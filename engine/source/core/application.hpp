#pragma once

#include <string>

#include "../defines.hpp"
#include "logger.hpp"
#include "../platform/platform.hpp"
#include "../platform/window.hpp"

namespace GRAPE {
	class Application {
	private:
		Logger m_logger;
		Window m_window;
		AppInfo m_appinfo;

		bool m_isrunning = false;
	public:
		/*
		* @brief Creates a grape application on construction.
		* @param GRAPE::AppInfo: a struct containing application info.
		* @returns Nothing
		* 
		* @method: Application
		* @fullname: GRAPE::Application::Application
		*/
		Application(const AppInfo& appinfo);

		/*
		* @brief Exits the application upon destruction.
		* @returns Nothing
		*
		* @method: ~Application
		* @fullname: GRAPE::Application::~Application
		*/
		~Application();

		/*
		* @brief Application entry point.
		* @returns Nothing
		* 
		* @method: Run
		* @fullname: GRAPE::Application::Run
		*/
		void Run();

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

		/*
		* @brief Wrapper for the window class method 'Window::GetTitle'.
		* @returns std::string: The window title.
		*/
		std::string GetWinTitle();

		/*
		* @brief Wrapper for window class method 'Window::GetSize'.
		* @param int*: Pointer to an integer to store the width in.
		* @param int*: Pointer to an integer to store the height in.
		* @returns Nothing.
		*/
		void GetWinSize(int* width, int* height);

		/*
		* @brief Wrapper for window class method 'Window::UpdateTitle'.
		* @param const std::string&: The new window title.
		* @returns Nothing.
		*/
		void UpdateWinTitle(const std::string& title);

		/*
		* @brief Wrapper for window class method 'Window::UpdateSize'
		* @param const int&: The width of the window, NULL if not updated.
		* @param const int&: The height of the window, NULL if not updated.
		* @returns Nothing.
		*/
		void UpdateWinSize(const uint32_t width, const uint32_t height);

		/*
		* @brief Returns the current application info.
		* @returns AppInfo: the application info as a struct.
		*/
		AppInfo GetApplicationInfo();
	};
}