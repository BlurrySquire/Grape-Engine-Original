#include "window.hpp"

#include "../core/application.hpp"

void glfw_WindowErrorCallback(int error_code, const char* description) {
	GRAPE_LOG_CRITICAL(
		"GLFW v{0}.{1}.{2} Error {3}: {4}",
		GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION,
		error_code, description
	);
}

Window::Window(const std::string& title, std::uint32_t width, std::uint32_t height,GRAPE::Application* app) {
	m_app = app;

	GRAPE_LOG_TRACE(
		"Window: Initializing GLFW v{0}.{1}.{2}.",
		GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION
	);

	glfwSetErrorCallback(glfw_WindowErrorCallback);

	if (!glfwInit()) {
		GRAPE_LOG_CRITICAL(
			"Window: GLFW v{0}.{1}.{2} init failed.",
			GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION
		);
		exit(-1);
	}

	GRAPE_LOG_INFO(
		"Window: GLFW v{0}.{1}.{2} init complete.",
		GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION
	);

	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	GRAPE_LOG_TRACE(
		"Window: Opening window '{0}' of size ({1}x{2}).",
		title,
		width, height
	);

	m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	if (m_window == nullptr) {
		GRAPE_LOG_CRITICAL(
			"Window: GLFW v{0}.{1}.{2} window creation failed.",
			GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION
		);
	}

	GRAPE_LOG_INFO(
		"Window: Opened window."
	);
}

Window::~Window() {
	GRAPE_LOG_TRACE("Window: Closing Window.");
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void Window::UpdateTitle(const std::string& title) {
	glfwSetWindowTitle(m_window, title.c_str());
}

void Window::UpdateSize(std::uint32_t width, std::uint32_t height) {
		glfwSetWindowSize(m_window, width, height);
}

std::string Window::GetTitle() {
	return glfwGetWindowTitle(m_window);
}

void Window::GetSize(int* width, int* height) {
	glfwGetWindowSize(m_window, width, height);
}

void Window::PollEvents() {
	glfwPollEvents();

	if (glfwWindowShouldClose(m_window)) {
		glfwSetWindowShouldClose(m_window, GLFW_FALSE);
		GRAPE_LOG_TRACE("Window: Sent 'Window Close' event.");
		m_app->OnWindowClose();
	}
}