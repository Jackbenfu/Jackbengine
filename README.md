# Jackbengine
A multi-platform C++ 2D game engine that I develop in my spare time.

## Features

#### Multi-platform
The engine runs and was successfully tested on the following platforms:
- OS X
- Windows (MinGW)
- Web (Emscripten)

#### ECS pattern implementation
Summary of the Entity-component-system approach:
- Entities are made up of one or more components
- Components contain data to store the state of an entity
- Systems contain the logic and operate on entities that have the required components

The engine provides standard components and systems usually needed in a game:
* Components: `Transform`, `Velocity`, `BoxShape`, `Sprite`, `Text`, `MouseListener`, `AudioSource` etc.
* Systems: `Motion`, `SpriteRender`, `TextRender`, `MouseEventTrigger`, `AABBCollision`, `DebugProfile`, `DebugSprite` etc.

This collection of components and systems can be extended.

#### Scene management
- Scenes can be used to split the game in logical parts (menus, in-game, options etc.) and/or functional parts (levels, screens etc.).
- A scene has its own context and cannot interact with other scenes.
- Transitions between scenes is possible by loading a scene from the current one (the previous scene being automatically unloaded).

#### Resource management
- Resources can be loaded from files or embedded resources.
- Embedded resources can be generated using the [ResourceGenerator](https://github.com/Jackbenfu/ResourceGenerator) tool.

#### Tile Map XML basic support (see [official reference](http://doc.mapeditor.org/reference/tmx-map-format/))
* Current implementation supports loading of following nodes:
 * `Map`
 * `Tileset` (only one per file)
 * `Layer`
 * `Object` and `ObjectGroup`
 * `Property` and `Properties`
 
#### WebSocket client
- The class `WebSocket` wraps a web socket connection and allows to bind one `deserializer` and one `callback` per typed network message.

## Development information
- OS X and Windows targets are compiled using [CMake](https://cmake.org/).
- Web targets are compiled using [Emscripten](http://emscripten.org/) and Makefiles.
- My main IDE is [CLion](https://www.jetbrains.com/clion/), the powerfull cross-platform C/C++ IDE from JetBrains!

## TODO
I have a huge list of things I'd like to add in the engine (maybe when I'll have more free time), including:
- [ ] Add animation system.
- [ ] Check for memory leaks using dedicated tools.
- [ ] Add documentation.
- [ ] Monitor and improve overall performance (reduce draw calls, use texture atlases...).
- [ ] Add string interning mechanism.
- [ ] Add state management.
- [ ] Support gamepads.
- [ ] Integrate physics engines ([Box2D](http://box2d.org/), [Chipmunk](https://chipmunk-physics.net/)...).
- [ ] Add unit tests.

## External dependencies
The engine relies on the following awesome libraries and tools:
- [SDL2](https://www.libsdl.org/)
- [SDL2_image](https://www.libsdl.org/projects/SDL_image/)
- [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/)
- [SDL2_mixer](https://www.libsdl.org/projects/SDL_mixer/)
- [TinyXML](https://sourceforge.net/projects/tinyxml/)
- [easywsclient](https://github.com/dhbaird/easywsclient)
- [Emscripten](http://emscripten.org/)
