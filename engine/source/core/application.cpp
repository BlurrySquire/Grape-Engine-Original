#include "application.hpp"

namespace GRAPE {
	Application::Application(std::string title, uint32_t width, uint32_t height)
	: m_title(title), m_width(width), m_height(height) {
		this->m_logger = new Logger("grape-engine_log");
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