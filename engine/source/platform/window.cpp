#include "window.hpp"

void glfw_WindowErrorCallback(int error_code, const char* description) {
	GRAPE_LOG_CRITICAL(
		"GLFW v{0}.{1}.{2} Error {3}: {4}",
		GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION,
		error_code, description
	);
}

Window::Window(const GRAPE::AppInfo& appinfo) {
	GRAPE_LOG_TRACE(
		"Initializing GLFW v{0}.{1}.{2}.",
		GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION
	);

	glfwSetErrorCallback(glfw_WindowErrorCallback);

	if (!glfwInit()) {
		GRAPE_LOG_CRITICAL(
			"GLFW v{0}.{1}.{2} init failed.",
			GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION
		);
	}

	if (appinfo.resizable == true) {
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	}
	else {
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	}

	GRAPE_LOG_TRACE(
		"Opening {0} window '{1}' of size ({2}x{3}).",
		appinfo.resizable ? "resizable" : "non-resizable",
		appinfo.win_title,
		appinfo.win_width, appinfo.win_height
	);

	m_window = glfwCreateWindow(appinfo.win_width, appinfo.win_height, appinfo.win_title.c_str(), NULL, NULL);

	if (m_window == NULL) {
		GRAPE_LOG_CRITICAL(
			"GLFW v{0}.{1}.{2} window creation failed.",
			GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION
		);
	}
}

Window::~Window() {
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void Window::UpdateTitle(const std::string& title) {
	glfwSetWindowTitle(m_window, title.c_str());
}

void Window::UpdateSize(const int& width, const int& height) {
	int win_width, win_height;
	glfwGetWindowSize(m_window, &win_width, &win_height);

	if (width == NULL && height != NULL) {
		glfwSetWindowSize(m_window, win_width, height);
	}
	else if (width != NULL && height == NULL) {
		glfwSetWindowSize(m_window, width, win_height);
	}
}

std::string Window::GetTitle() {
	return glfwGetWindowTitle(m_window);
}

void Window::GetSize(int* width, int* height) {
	glfwGetWindowSize(m_window, width, height);
}

bool Window::PollMessages() {
	glfwPollEvents();

	if (glfwWindowShouldClose(m_window)) {
		return false;
	}
	else {
		return true;
	}
}

void Window::ProcessEvents() {

}