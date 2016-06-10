#!/bin/bash

set -e

NORMAL=$(tput sgr0)
BOLD=$(tput bold)
MAGENTA=$(tput setaf 5)
printTitle() {
    printf "${BOLD}${MAGENTA}$1\n${NORMAL}"
}
printText() {
    printf "${NORMAL}$1\n"
}

if [ $# != 2 ]
then
    printText "Usage: create_macos_bundle.sh project_path target_name"
    printText ""
    printText "  project_path  The path to the CMake project."
    printText "  target_name   The CMake target to build."
    exit
fi

if [ ! -d $1 ]
then
    printText "Project path ($1) does not exist!"
    exit
fi

project_path=$1
target_name=$2
bundle_framework_dir=${target_name}.app/Contents/Frameworks
bundle_target_dir=${target_name}.app/Contents/MacOS
bundle_executable=${bundle_target_dir}/${target_name}

printTitle "Configuring CMake"
cmake -D CMAKE_BUILD_TYPE:STRING=Release ${project_path}

printTitle "Building target bundle"
cmake --build ${project_path} --target ${target_name} -- -j 4

printTitle "Copying frameworks into target bundle"
copyFramework() {
    printText "  Copying $1"

    framework_name=$1
    framework_system_path=$2
    framework_dir=${project_path}/${bundle_framework_dir}/${framework_name}.framework

    rm -rf ${framework_dir}
    mkdir -p ${framework_dir}
    cp -R ${framework_system_path}${framework_name}.framework/ ${framework_dir}
}
copyFramework "SDL2" "/Library/Frameworks/"
copyFramework "SDL2_image" "/Library/Frameworks/"
copyFramework "SDL2_ttf" "/Library/Frameworks/"
copyFramework "SDL2_mixer" "/Library/Frameworks/"

printTitle "Relocating frameworks"
function relocateFramework() {
    printText "  Relocating $1"

    framework_name=$1
    framework_version=$2
    framework_name_with_path=$1.framework/Versions/${framework_version}/$1

    install_name_tool -change @rpath/${framework_name_with_path} @executable_path/../Frameworks/${framework_name_with_path} ${project_path}/${bundle_executable}
}
relocateFramework "SDL2" "A"
relocateFramework "SDL2_image" "A"
relocateFramework "SDL2_ttf" "A"
relocateFramework "SDL2_mixer" "A"

printTitle "Copying libraries into target bundle"
copyLibrary() {
    printText "  Copying $1"

    library_system_path=$2
    framework_dir=${project_path}/${bundle_framework_dir}/$1

    mkdir -p ${framework_dir}
    cp -f ${library_system_path}$1 ${framework_dir}
}
copyLibrary "libc++.1.dylib" "/usr/lib/"
copyLibrary "libSystem.B.dylib" "/usr/lib/"

printTitle "Relocating libraries"
function relocateLibrary() {
    printText "  Relocating $1"
    install_name_tool -change $2$1 @executable_path/../Frameworks/$1 ${project_path}/${bundle_executable}
}
relocateLibrary "libc++.1.dylib" "/usr/lib/"
relocateLibrary "libSystem.B.dylib" "/usr/lib/"

printTitle "Checking relocation results"
otool -L ${project_path}/${bundle_executable}

printTitle "Archiving target"
archiveName="${target_name}.tar.gz"
cd ${project_path}
tar -czf ${archiveName} ${target_name}.app/*

printTitle "Archive ${archiveName} is available in folder: ${project_path}"
