cmake_minimum_required(VERSION 3.14)
project(imgui)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../../cmake)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES
        imgui_widgets.cpp
        imgui_draw.cpp
        imgui_demo.cpp
        imgui.cpp
        imgui_impl_sdl.cpp
        )

add_library(imgui STATIC ${SOURCE_FILES})
target_link_libraries(imgui ${SDL2_LIBRARY})
