//
// sdlApplication.cpp
// jackbengine
//
// Created by Damien Bendejacq on 12/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "pch.h"
#include "sdlApplication.h"

namespace Jackbengine::details {

SDLApplication::SDLApplication()
{
    Log::init();

    PROFILE("SDLApplication::ctor", true, {
        init();
    })
}

SDLApplication::~SDLApplication()
{
    PROFILE("SDLApplication::dtor", true, {
        Mix_Quit();
        TTF_Quit();
        SDL_Quit();
    })
}

void SDLApplication::init()
{
#ifdef EMSCRIPTEN
    if (SDL_Init(SDL_INIT_EVERYTHING & ~(SDL_INIT_TIMER | SDL_INIT_HAPTIC)) < 0)
#else
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
#endif
    {
        throw std::runtime_error(SDL_GetError());
    }

    if (TTF_Init() < 0)
    {
        throw std::runtime_error(TTF_GetError());
    }

    if (0 == Mix_Init((unsigned) MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG))
    {
        throw std::runtime_error(Mix_GetError());
    }

    if (-1 == Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024))
    {
        throw std::runtime_error(Mix_GetError());
    }
}

}
