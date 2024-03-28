# Grape Engine Docs - Building
- [Return to README](https://github.com/BlurrySquire/Grape-Engine/tree/main?tab=readme-ov-file)
- [Return to Documentation](https://github.com/BlurrySquire/Grape-Engine/blob/main/documentation/documentation.md)

Please refer to either [building setup (Windows)](https://github.com/BlurrySquire/Grape-Engine/blob/main/documentation/building.md#building-setup-windows) or [building setup (Linux)](https://github.com/BlurrySquire/Grape-Engine/blob/main/documentation/building.md#building-setup-linux) before starting.

1. To start with clone the [repository](https://github.com/BlurrySquire/Grape-Engine).
2. If you use VS Code then open the repository and press Crtl+Shift+B to bring up the build options. Select either all, engine or sandbox.
3. If you don't use VS Code or don't want to use Ctrl+Shift+B, then hop into the terminal and run the ``make`` command. The Makefile in the root directory builds the engine and the sandbox application. To only build the engine then run the Makefile in the engine directory. The same applies for the sandbox application but in the sandbox directory.

## Building Setup (Windows)
- Ensure you have [MinGW W64Devkit](https://github.com/skeeto/w64devkit/releases) installed. Optionally, you can use a different distribution of the MinGW GCC toolchain that includes make. You need to have the bin directory of the installation set in path.
- Ensure you have the [LunarG Vulkan SDK](https://vulkan.lunarg.com/#new_tab) installed.

## Building Setup (Linux)
- Ensure you have the GCC compiler toolchain and make installed, ``sudo apt-get install build-essential``.
- Ensure you have the [LunarG Vulkan SDK](https://vulkan.lunarg.com/#new_tab) installed.