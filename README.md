### ***[v2](https://github.com/Jackbenfu/Jackbengine/tree/v2) is under development with lots of changes (low level rendering instead of SDL2's one, use of libraries such as [imgui](https://github.com/ocornut/imgui), [spdlog](https://github.com/gabime/spdlog), [fmt](https://github.com/fmtlib/fmt), [enTT](https://github.com/skypjack/entt)...).***

# Jackbengine
A multi-platform C++ 2D game engine.

## Features

#### Multi-platform
The engine runs and was successfully tested on the following platforms:
- OS X, macOS
- Windows (MinGW)
- Web (Emscripten)

#### ECS pattern implementation
Summary of the Entity-component-system approach:
- _Entities_ are made up of one or more components
- _Components_ contain data to store the state of an entity
- _Systems_ contain the logic and operate on entities that have the required components

The engine provides standard components and systems usually needed in a game:
* Components: `Transform`, `Velocity`, `BoxShape`, `Sprite`, `Text`, `MouseListener`, `AudioSource` etc.
* Systems: `Motion`, `SpriteRender`, `TextRender`, `MouseEventTrigger`, `AABBCollision`, `DebugProfile`, `DebugSprite` etc.

This collection of components and systems can be extended.

#### Resource management
- Resources can be loaded from files or embedded resources.
- Embedded resources can be generated using the [ResourceGenerator](https://github.com/Jackbenfu/ResourceGenerator) tool.
 
## Development information
- All targets (except Web) are compiled using [CMake](https://cmake.org/).
- Web targets are compiled using [Emscripten](http://emscripten.org/) and Makefiles.
- My main IDE is [CLion](https://www.jetbrains.com/clion/), the powerfull cross-platform C/C++ IDE from JetBrains!

## External dependencies
The engine relies on the following awesome libraries and tools:
- [Emscripten](http://emscripten.org/)
- [SDL2](https://www.libsdl.org/)
- [SDL2_image](https://www.libsdl.org/projects/SDL_image/)
- [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/)
- [SDL2_mixer](https://www.libsdl.org/projects/SDL_mixer/)
