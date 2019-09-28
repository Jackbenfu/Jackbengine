#!/usr/bin/env bash

NC='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'

pwd=$(pwd)

echo ${pwd}

debug=0
release_profile=0
release=0

build() {
  if [[ ${debug} == 1 ]]; then
    make -f Makefile.emscripten debug
  elif [[ ${release_profile} == 1 ]]; then
    make -f Makefile.emscripten release_profile
  elif [[ ${release} == 1 ]]; then
    make -f Makefile.emscripten release
  fi
}

if [[ $1 == "debug" ]]; then
  debug=1
  echo -e "${RED}/!\ DEBUG MODE ENABLED${NC}"
elif [[ $1 == "release_profile" ]]; then
  release_profile=1
  echo -e "${YELLOW}/!\ RELEASE PROFILE MODE ENABLED${NC}"
elif [[ $1 == "release" ]]; then
  release=1
  echo -e "${GREEN}/!\ RELEASE MODE ENABLED${NC}"
else
  echo -e "${RED}Usage: emscripten.sh {debug|release_profile|release}${NC}"
  exit 42
fi

echo -e "${GREEN}Building ImGui...${NC}"
cd ${pwd}/jackbengine/external/imgui
make -f Makefile.emscripten

echo -e "${GREEN}Building Jackbengine...${NC}"
cd ${pwd}/jackbengine
build

echo -e "${GREEN}Building application...${NC}"
cd ${pwd}
build

echo -ne '\007'
