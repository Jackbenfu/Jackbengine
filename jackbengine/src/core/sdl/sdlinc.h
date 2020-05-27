//
// sdlinc.h
// jackbengine
//
// Created by Damien Bendejacq on 23/08/2019.
//

#ifndef __SDL_H__
#define __SDL_H__

#if defined(__APPLE__)

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#elif defined(_WIN32)

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#elif defined(EMSCRIPTEN)

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#endif

#endif // __SDL_H__
