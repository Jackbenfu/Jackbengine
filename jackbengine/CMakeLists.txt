cmake_minimum_required(VERSION 3.14)
project(jackbengine)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

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

add_definitions(/DFMT_HEADER_ONLY)

add_subdirectory(${PROJECT_SOURCE_DIR}/external/imgui)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/glad)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/fmt)

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
    ${PROJECT_SOURCE_DIR}/external
    ${PROJECT_SOURCE_DIR}/external/glad/include
    ${PROJECT_SOURCE_DIR}/external/fmt
)

add_executable(
    resourceGenerator
    ${PROJECT_SOURCE_DIR}/external/resourceGenerator/resourceGenerator.c
)

add_custom_command(
    OUTPUT ${PROJECT_SOURCE_DIR}/resources.cpp
    COMMAND resourceGenerator
    ${PROJECT_SOURCE_DIR}/resources.cpp
    -t${PROJECT_SOURCE_DIR}/src/core/render/shader/glsl/color.vertex.default.glsl
    -t${PROJECT_SOURCE_DIR}/src/core/render/shader/glsl/color.fragment.default.glsl
    -t${PROJECT_SOURCE_DIR}/src/core/render/shader/glsl/texture.vertex.default.glsl
    -t${PROJECT_SOURCE_DIR}/src/core/render/shader/glsl/texture.fragment.default.glsl
    -t${PROJECT_SOURCE_DIR}/src/core/render/shader/glsl/texture.fragment.grayscale.glsl
    -t${PROJECT_SOURCE_DIR}/src/core/render/shader/glsl/texture.fragment.pixelate.glsl
    -b${PROJECT_SOURCE_DIR}/resource/aquarelle_damien_square.png
    -b${PROJECT_SOURCE_DIR}/resource/aquarelle_damien_square_alpha.png
    DEPENDS
    ${PROJECT_SOURCE_DIR}/src/core/render/shader/glsl/color.vertex.default.glsl
    ${PROJECT_SOURCE_DIR}/src/core/render/shader/glsl/color.fragment.default.glsl
    ${PROJECT_SOURCE_DIR}/src/core/render/shader/glsl/texture.vertex.default.glsl
    ${PROJECT_SOURCE_DIR}/src/core/render/shader/glsl/texture.fragment.default.glsl
    ${PROJECT_SOURCE_DIR}/src/core/render/shader/glsl/texture.fragment.grayscale.glsl
    ${PROJECT_SOURCE_DIR}/src/core/render/shader/glsl/texture.fragment.pixelate.glsl
    ${PROJECT_SOURCE_DIR}/resource/aquarelle_damien_square.png
    ${PROJECT_SOURCE_DIR}/resource/aquarelle_damien_square_alpha.png
)

set(
    RESOURCE_FILES
    ${PROJECT_SOURCE_DIR}/resources.cpp
)
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_library(jackbengine STATIC ${SOURCE_FILES} ${RESOURCE_FILES})
target_link_libraries(
    ${PROJECT_NAME}
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
    ${SDL2_TTF_LIBRARY}
    ${SDL2_MIXER_LIBRARY}
    imgui
    glad
    fmt
)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE src
    INTERFACE external
)
