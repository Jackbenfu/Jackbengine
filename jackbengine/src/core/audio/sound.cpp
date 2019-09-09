//
// sound.cpp
// jackbengine
//
// Created by Damien Bendejacq on 15/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "sound.h"
#include "core/io/rwops.h"
#include "core/sdl/sdlinc.h"

namespace Jackbengine::details {

Sound::Sound(const std::string &file)
{
    m_chunk = Mix_LoadWAV(file.c_str());
    if (nullptr == m_chunk)
    {
        throw std::runtime_error(Mix_GetError());
    }
}

Sound::Sound(const void *data, size_t dataSize)
{
    const auto sdlRwops = std::make_unique<RWops>(data, dataSize);

    m_chunk = Mix_LoadWAV_RW((SDL_RWops *) sdlRwops->nativeObject(), 1);
    if (nullptr == m_chunk)
    {
        throw std::runtime_error(Mix_GetError());
    }
}

Sound::~Sound()
{
    Mix_FreeChunk(m_chunk);
}

void Sound::play(bool loop) const
{
    Mix_PlayChannel(MIX_DEFAULT_CHANNELS, m_chunk, loop ? 1 : 0);
}

}
