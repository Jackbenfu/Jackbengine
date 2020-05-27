cmake_minimum_required(VERSION 3.14)
project(sandbox)

set(CMAKE_CXX_STANDARD 20)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(/D__DEBUG__)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Wpedantic")
elseif (CMAKE_BUILD_TYPE STREQUAL "ReleaseProfile")
    add_definitions(/D__RELEASE_PROFILE__)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra -Wpedantic")
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(/D__RELEASE__)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra -Wpedantic")
endif ()

add_subdirectory(${PROJECT_SOURCE_DIR}/jackbengine)

file(GLOB_RECURSE SOURCE_FILES sandbox/*.cpp)

add_executable(sandbox ${SOURCE_FILES})
target_link_libraries(sandbox jackbengine)
