cmake_minimum_required(VERSION 3.14)
project(glad)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_RELEASE} -Wall -Wextra -Wpedantic")

include_directories(include)

add_library(glad STATIC src/glad.c)
