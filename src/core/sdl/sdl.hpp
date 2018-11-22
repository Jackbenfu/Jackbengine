//
// sdl.hpp
// jackbengine
//
// Created by Damien Bendejacq on 21/11/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#ifndef __SDL_H__
#define __SDL_H__

#if defined(__APPLE__)

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>

#elif defined(_WIN32)

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#elif defined(EMSCRIPTEN)

// SDL2
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

// SDL1 for mixer
#include <SDL/SDL_mixer.h>

#endif

#endif // __SDL_H__
