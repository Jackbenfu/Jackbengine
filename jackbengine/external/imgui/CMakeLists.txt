cmake_minimum_required(VERSION 3.14)
project(imgui)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../../cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra -Wpedantic")

find_package(SDL2 REQUIRED)

include_directories(
    ${SDL2_INCLUDE_DIR}
    ../glad/include
)

set(
    SOURCE_FILES
    imgui_widgets.cpp
    imgui_draw.cpp
    imgui_demo.cpp
    imgui.cpp
    imgui_impl_sdl.cpp
    imgui_impl_opengl3.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
