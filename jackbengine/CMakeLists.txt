cmake_minimum_required(VERSION 3.14)
project(jackbengine)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(cotire)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(/D__DEBUG__)
elseif (CMAKE_BUILD_TYPE STREQUAL "ReleaseProfile")
    add_definitions(/D__PROFILE__)
endif ()

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories(
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
        ${SDL2_MIXER_INCLUDE_DIR}
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/external)

set(SOURCE_FILES
        src/core/sdl/io/sdlRwops.cpp
        src/core/sdl/surface/sdlSurface.cpp
        src/core/audio/sound.cpp
        src/core/input/input.cpp
        src/core/log/log.cpp
        src/core/render/color.cpp
        src/core/render/cursor/cursor.cpp
        src/core/render/font/defaultFont.cpp
        src/core/render/font/font.cpp
        src/core/render/renderer/renderer.cpp
        src/core/render/texture/texture.cpp
        src/core/render/window/window.cpp
        src/core/time/timer.cpp
        src/application/abstract/abstractApplication.cpp
        src/application/application.cpp
        src/application/entryPoint.cpp)

add_library(jackbengine STATIC ${SOURCE_FILES})
target_link_libraries(jackbengine ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_MIXER_LIBRARY})
cotire(jackbengine)
