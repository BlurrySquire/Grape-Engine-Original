# Grape Engine Docs - Building
- [Return to README](https://github.com/BlurrySquire/Grape-Engine)
- [Return to Documentation](https://github.com/BlurrySquire/Grape-Engine/blob/main/documentation/documentation.md)

Please refer to either [building setup (Windows)](https://github.com/BlurrySquire/Grape-Engine/blob/main/documentation/building.md#building-setup-windows) or [building setup (Linux)](https://github.com/BlurrySquire/Grape-Engine/blob/main/documentation/building.md#building-setup-linux) before starting.

1. To start with clone the [repository](https://github.com/BlurrySquire/Grape-Engine).
2. Next, install Premake.
3. Now, run ``premake --file=premake5.lua <export>``. Replace ``<export>`` with the build system you want to use. (e.g. ``vs2022`` to build with Visual Studio 2022).

## Building Setup (Windows)
- Ensure you have some form of C++ compiler (e.g. Visual Studio IDE).
- Ensure you have the [LunarG Vulkan SDK](https://vulkan.lunarg.com/#new_tab) installed.

## Building Setup (Linux)
- Ensure you have some form of C++ compiler. ``sudo apt-get install build-essential``.
- Ensure you have the [LunarG Vulkan SDK](https://vulkan.lunarg.com/#new_tab) installed.