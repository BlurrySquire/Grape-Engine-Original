# Grape-Engine
A W.I.P 2D Game engine created in C, and uses Vulkan for rendering.

## The Plan
Here is some of the features I have planned:
- Modular runtime for the engine (your project only includes the parts of the engine that it uses).
- Plug and play renderer. Multiple rendering backends which can be swapped out. (DLL that uses a specific API for interracting with engine).

## Building
You need the [mingw w64devkit](https://github.com/skeeto/w64devkit/releases/tag/v1.21.0). You must add the bin directory to path.
Simply run ``make`` to build the engine.