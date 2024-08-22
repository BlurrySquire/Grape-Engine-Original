#pragma once

#include <string>

#include "../defines.hpp"
#include "../core/logger.hpp"

#include <GLFW/glfw3.h>

namespace GRAPE {
	class Application;
}

class Window {
private:
	GLFWwindow* m_window;
	GRAPE::Application* m_app;
public:
	Window(const std::string& title, std::uint32_t width, std::uint32_t height, GRAPE::Application* app);
	~Window();

	void UpdateTitle(const std::string& title);
	void UpdateSize(std::uint32_t width, std::uint32_t height);

	std::string GetTitle();
	void GetSize(int* width, int* height);

	void PollEvents();
};