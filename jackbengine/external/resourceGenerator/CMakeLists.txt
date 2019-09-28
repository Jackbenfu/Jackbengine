cmake_minimum_required(VERSION 3.14)
project(resourceGenerator)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_RELEASE} -Wall -Wextra -Wpedantic")

add_executable(resourceGenerator.c)
