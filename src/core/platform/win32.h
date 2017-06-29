//
// win32.h
// jackbengine
//
// Created by Damien Bendejacq on 11/07/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __WIN32_H__
#define __WIN32_H__

// SDL2
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <shlwapi.h>
#include <stdlib.h>

extern "C" char* strdup(const char *str);

#define snprintf _snprintf

#endif // __WIN32_H__
