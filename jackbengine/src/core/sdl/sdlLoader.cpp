//
// sdlLoader.cpp
// jackbengine
//
// Created by Damien Bendejacq on 27/09/2019.
//

#include <stdexcept>
#include "core/sdl/sdlinc.h"

namespace Jackbengine::details {

void initSDL()
{
#ifdef EMSCRIPTEN
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO) < 0)
#else
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
#endif
    {
        throw std::runtime_error(SDL_GetError());
    }

    if (0 == IMG_Init(IMG_INIT_PNG))
    {
        throw std::runtime_error(IMG_GetError());
    }

    if (TTF_Init() < 0)
    {
        throw std::runtime_error(TTF_GetError());
    }

#ifndef EMSCRIPTEN
    if (0 == Mix_Init((unsigned) MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG))
    {
        throw std::runtime_error(Mix_GetError());
    }

    if (-1 == Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024))
    {
        throw std::runtime_error(Mix_GetError());
    }
#endif
}

void destroySDL()
{
#ifndef EMSCRIPTEN
    Mix_Quit();
#endif

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

}
