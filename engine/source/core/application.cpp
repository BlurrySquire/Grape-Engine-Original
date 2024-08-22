#include "application.hpp"

#include <memory>

namespace GRAPE {
	Application::Application(const std::string& title, std::uint32_t width, std::uint32_t height)
		: Title(title), Width(width), Height(height), Logger(title), Window(title, width, height, this) {
		IsRunning = false;
	}

	Application::~Application() {

	}

	void Application::Init() {
		GRAPE_LOG_INFO("Application: Initialised.");
		Run();
	}

	void Application::Run() {
		IsRunning = true;

		while (IsRunning) {
			Window.PollEvents();
			Update();
			Render();
		}
	}

	void Application::Update() {

	}
	
	void Application::Render() {

	}

	void Application::OnKeyPress() {
		GRAPE_LOG_INFO("Key pressed.");
	}
	
	void Application::OnMouseMove() {
		GRAPE_LOG_INFO("Mouse moved.");
	}

	void Application::OnMouseClick() {
		GRAPE_LOG_INFO("Mouse Clicked.");
	}

	void Application::OnWindowClose() {
		GRAPE_LOG_INFO("Window closed.");
		CloseApplication();
	}

	void Application::CloseApplication() {
		IsRunning = false;
	}

	void UpdateWindowTitle() {

	}

	void UpdateWindowWidth() {

	}

	void UpdateWindowHeight() {

	}

	void UpdateWindowSize() {

	}

}