# Grape-Engine
A 2D Game Engine created with C++ and Vulkan.

## Attributions/Contributions
Thank you to [Travis Vroman](https://github.com/travisvroman) for the ``defines.hpp`` file. It was designed for use with C and [Kohi](https://github.com/travisvroman/kohi), I modified it to better suit my engine and C++. If you would like a list of the modifications made they are in the top comment of ``engine/source/defines.hpp``.

## The Plan
Here is some of the features I have planned:
- Modular runtime for the engine (your project only includes the parts of the engine that it uses).
- Plug and play renderer. Multiple rendering backends which can be swapped out. (DLL that uses a specific API for interracting with engine).

## Building
You need the [mingw w64devkit](https://github.com/skeeto/w64devkit/releases/tag/v1.21.0). You must add the bin directory to path.
Simply run ``make`` to build the engine.