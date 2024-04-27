#pragma once

#include <string>

#include "../defines.hpp"
#include "../core/logger.hpp"

#include <GLFW/glfw3.h>

class Window {
private:
	GLFWwindow* m_window;
public:
	Window(const GRAPE::AppInfo& appinfo);
	~Window();

	void UpdateTitle(const std::string& title);
	void UpdateSize(const int& width, const int& height);

	std::string GetTitle();
	void GetSize(int* width, int* height);

	bool PollMessages();

	void ProcessEvents();
};