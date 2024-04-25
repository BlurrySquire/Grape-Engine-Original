#include "../window.hpp"

#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, uint32_t msg, WPARAM w_param, LPARAM l_param) {
	return DefWindowProc(hwnd, msg, w_param, l_param);
}

WNDCLASSEX wndclass;
HWND hwnd;

Window::Window(std::wstring title, int width, int height)
	: m_title(title), m_width(width), m_height(height) {
	wndclass = { NULL };

	wndclass.cbSize = sizeof(WNDCLASSEXA);
	wndclass.style = CS_DBLCLKS;
	wndclass.lpfnWndProc = WindowProc;
	wndclass.hInstance = GetModuleHandle(NULL);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = L"Grape-Engine Window Class";

	ATOM result = RegisterClassEx(&wndclass);
	if (result == NULL) {
		GRAPE_LOG_CRITICAL("Window Class Registration Failed: {0}", GetLastError());
	}

	m_x = (GetSystemMetrics(SM_CXSCREEN) / 2) - (m_width / 2);
	m_y = (GetSystemMetrics(SM_CYSCREEN) / 2) - (m_height / 2);

	hwnd = CreateWindowEx(
		WS_EX_OVERLAPPEDWINDOW,
		wndclass.lpszClassName,
		m_title.c_str(),
		WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX,
		m_x, m_y,
		m_width, m_height,
		NULL,
		NULL,
		wndclass.hInstance,
		NULL
	);

	ShowWindow(hwnd, SW_SHOWNORMAL);
}

Window::~Window() {
	DestroyWindow(hwnd);
	UnregisterClass(wndclass.lpszClassName, wndclass.hInstance);
}

std::wstring Window::GetWinTitle() {
	return m_title;
}

int Window::GetWinWidth() {
	return m_width;
}

int Window::GetWinHeight() {
	return m_height;
}