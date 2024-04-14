#include "application.hpp"

namespace GRAPE {
	Application::Application(std::string title, uint32_t width, uint32_t height)
	: m_logger("grape-engine_log"), m_title(title), m_width(width), m_height(height) {
	}

	Application::~Application() {
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