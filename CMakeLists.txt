cmake_minimum_required(VERSION 3.14)
project(sandbox)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(${PROJECT_SOURCE_DIR}/jackbengine)

add_executable(sandbox sandbox/src/main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} jackbengine)
