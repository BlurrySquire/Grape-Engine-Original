#include "defines.hpp"

#include <iostream>

#include <GLFW/glfw3.h>

namespace GRAPE {
	void Init() {
		if (!glfwInit()) {
			std::cout << "GRAPE::Init: GLFW Error." << std::endl;
		}
	}
}