#!/bin/bash

if [ $# = 0 ]
then
    printf "Usage: create_macos_bundle.sh {target_directory} {target_name}\n"
    exit
fi

target_directory=$1
target_name=$2
bundle_framework_dir=${target_name}.app/Contents/Frameworks
bundle_target_dir=${target_name}.app/Contents/MacOS
bundle_executable=${bundle_target_dir}/${target_name}

printf "Building target bundle\n"
cmake --build ${target_directory} --target ${target_name} -- -j 4

printf "Copying frameworks into target bundle\n"
copyFramework() {
    printf "  Copying $1\n"

    framework_name=$1
    framework_system_path=$2
    framework_dir=${target_directory}/${bundle_framework_dir}/${framework_name}.framework

    rm -rf ${framework_dir}
    mkdir -p ${framework_dir}
    cp -R ${framework_system_path}${framework_name}.framework/ ${framework_dir}
}
copyFramework "SDL2" "/Library/Frameworks/"
copyFramework "SDL2_image" "/Library/Frameworks/"
copyFramework "SDL2_ttf" "/Library/Frameworks/"
copyFramework "SDL2_mixer" "/Library/Frameworks/"

printf "Relocating frameworks\n"
function relocateFramework() {
    printf "  Relocating $1\n"

    framework_name=$1
    framework_version=$2
    framework_name_with_path=$1.framework/Versions/${framework_version}/$1

    install_name_tool -change @rpath/${framework_name_with_path} @executable_path/../Frameworks/${framework_name_with_path} ${target_directory}/${bundle_executable}
}
relocateFramework "SDL2" "A"
relocateFramework "SDL2_image" "A"
relocateFramework "SDL2_ttf" "A"
relocateFramework "SDL2_mixer" "A"

printf "Copying libraries into target bundle\n"
copyLibrary() {
    printf "  Copying $1\n"

    library_system_path=$2
    framework_dir=${target_directory}/${bundle_framework_dir}/$1

    mkdir -p ${framework_dir}
    cp -f ${library_system_path}$1 ${framework_dir}
}
copyLibrary "libc++.1.dylib" "/usr/lib/"
copyLibrary "libSystem.B.dylib" "/usr/lib/"

printf "Relocating libraries\n"
function relocateLibrary() {
    printf "  Relocating $1\n"
    install_name_tool -change $2$1 @executable_path/../Frameworks/$1 ${target_directory}/${bundle_executable}
}
relocateLibrary "libc++.1.dylib" "/usr/lib/"
relocateLibrary "libSystem.B.dylib" "/usr/lib/"

printf "Archiving target\n"
archiveName="${target_name}.tar.gz"
cd ${target_directory}
tar -czf ${archiveName} ${target_name}.app/*

printf "Archive ${archiveName} is available in folder: ${target_directory}\n"
