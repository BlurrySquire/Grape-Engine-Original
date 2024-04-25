#include "application.hpp"

namespace GRAPE {
	Application::Application(std::wstring title, uint32_t width, uint32_t height)
	: m_logger("grape-engine_log"), m_title(title), m_width(width), m_height(height) {
		m_window = new Window(m_title, m_width, m_height);
	}

	Application::~Application() {
		delete m_window;
	}

	void Application::ProcessEvents() {
		m_window->PollMessages();
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
}