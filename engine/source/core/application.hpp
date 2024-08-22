#pragma once

#include <string>

#include "../defines.hpp"
#include "logger.hpp"
#include "../platform/platform.hpp"
#include "../platform/window.hpp"

namespace GRAPE {	
	class Application {
	private:
		std::string Title;
		std::uint32_t Width;
		std::uint32_t Height;

		bool IsRunning;

		Logger Logger;
		Window Window;
	public:
		Application(const std::string& title, std::uint32_t width, std::uint32_t height);
		~Application();

		virtual void Init();
		void Run();

		virtual void Update();
		virtual void Render();

		virtual void OnKeyPress();
		virtual void OnMouseMove();
		virtual void OnMouseClick();
		
		virtual void OnWindowClose();

		void CloseApplication();

		// TO-DO
		void UpdateWindowTitle();
		void UpdateWindowWidth();
		void UpdateWindowHeight();
		void UpdateWindowSize();
	};
}