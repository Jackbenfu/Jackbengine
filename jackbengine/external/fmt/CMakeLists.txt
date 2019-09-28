cmake_minimum_required(VERSION 3.14)
project(fmt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra -Wpedantic")

add_library(fmt INTERFACE)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
)
