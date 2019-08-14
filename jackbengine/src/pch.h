//
// pch.h
// jackbengine
//
// Created by Damien Bendejacq on 14/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __PCH_H__
#define __PCH_H__

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

// Platform specific includes
#if defined(__APPLE__)

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <CoreFoundation/CFBundle.h>

#elif defined(_WIN32)

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <windows.h>

#elif defined(EMSCRIPTEN)

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <emscripten.h>

#endif

#endif // __PCH_H__
