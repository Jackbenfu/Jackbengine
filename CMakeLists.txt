cmake_minimum_required(VERSION 3.14)
project(sandbox)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/jackbengine/cmake)

include(cotire)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(/D__DEBUG__)
elseif (CMAKE_BUILD_TYPE STREQUAL "ReleaseProfile")
    add_definitions(/D__PROFILE__)
endif ()

add_subdirectory(${PROJECT_SOURCE_DIR}/jackbengine)

include_directories(${PROJECT_SOURCE_DIR}/jackbengine/src ${PROJECT_SOURCE_DIR}/jackbengine/external)

set(SOURCE_FILES
        sandbox/src/app.cpp)

add_executable(sandbox ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} jackbengine)
cotire(sandbox)
