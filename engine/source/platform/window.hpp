#pragma once

#include <string>

#include "../defines.hpp"
#include "../core/logging/logger.hpp"

class Window {
private:
	std::wstring m_title;
	int m_width, m_height;
	int m_x, m_y;
public:
	Window(std::wstring title, int width, int height);
	~Window();

	void PollMessages();

	std::wstring GetWinTitle();
	int GetWinWidth();
	int GetWinHeight();
};

#if defined(GRAPE_PLATFORM_WINDOWS)
	#include <Windows.h>
	LRESULT CALLBACK WindowProc(HWND hwnd, uint32_t msg, WPARAM w_param, LPARAM l_param);
#endif