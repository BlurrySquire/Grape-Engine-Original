#include "application.hpp"

namespace GRAPE {
	Application::Application(const AppInfo& appinfo)
	: m_appinfo(appinfo), m_logger("grape-engine_log"), m_window(appinfo) {
	}

	Application::~Application() {
	}

	void Application::Run() {
		GRAPE_LOG_INFO("Application started.");

		while (m_window.PollMessages()) {
			// Loop application
		}

		GRAPE_LOG_INFO("Application closed.");
	}

	void Application::TimeSleep(const uint32_t milliseconds) {
		Platform::Time_Sleep(milliseconds);
	}

	SystemTime Application::GetLocalTime() {
		return Platform::Time_GetLocal();
	}

	SystemDate Application::GetLocalDate() {
		return Platform::Time_GetDate();
	}

	std::string Application::GetWinTitle() {
		return m_window.GetTitle();
	}

	void Application::GetWinSize(int* width, int* height) {
		return m_window.GetSize(width, height);
	}

	void Application::UpdateWinTitle(const std::string& title) {
		m_appinfo.win_title = title;
		m_window.UpdateTitle(title);
	}

	void Application::UpdateWinSize(const int& width, const int& height) {
		if (width == NULL && height != NULL) {
			m_appinfo.win_height = height;
		}
		else if (width != NULL && height == NULL) {
			m_appinfo.win_width = width;
		}

		m_window.UpdateSize(width, height);
	}

	AppInfo Application::GetApplicationInfo() {
		return m_appinfo;
	}
}