# Grape-Engine
A 2D Game Engine created with C++ and Vulkan.

## Attributions/Contributions
Thank you to [Travis Vroman](https://github.com/travisvroman) for the ``defines.hpp`` file. It was designed for use with C and [Kohi](https://github.com/travisvroman/kohi), I modified it to better suit my engine and C++. If you would like a list of the modifications made they are in the top comment of ``engine/source/defines.hpp``.

## The Plan
Here is some of the features I have planned:
- Modular runtime for the engine (your project only includes the parts of the engine that it uses).
- Plug and play renderer. Multiple rendering backends which can be swapped out. (DLL that uses a specific API for interracting with engine).

## Building Grape-Engine
Please refer to either [building setup (Windows)](https://github.com/BlurrySquire/Grape-Engine#Building_Setup_(Windows)) or [building setup (Linux)](https://github.com/BlurrySquire/Grape-Engine#Building_Setup_(Linux)) before starting.
1. To start with clone the [repository](https://github.com/BlurrySquire/Grape-Engine).
2. If you use VS Code then open the repository and press Crtl+Shift+B to bring up the build options. Select either all, engine or sandbox.
3. If you don't use VS Code or don't want to use Ctrl+Shift+B, then hop into the terminal and run the ``make`` command. The Makefile in the root directory builds the engine and the sandbox application. To only build the engine then run the Makefile in the engine directory. The same applies for the sandbox application but in the sandbox directory.

## Building Setup (Windows)
- Ensure you have [MinGW W64Devkit](https://github.com/skeeto/w64devkit/releases) installed. Optionally, you can use a different distribution of the MinGW GCC toolchain that includes make.
- Ensure you have the [LunarG Vulkan SDK](https://vulkan.lunarg.com/#new_tab) installed.

## Building Setup (Linux)
- Ensure you have the GCC compiler toolchain and make installed, ``sudo apt-get install build-essential``.
- Ensure you have the [LunarG Vulkan SDK](https://vulkan.lunarg.com/#new_tab) installed.