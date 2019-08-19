//
// sound.cpp
// jackbengine
//
// Created by Damien Bendejacq on 15/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "pch.h"
#include "sound.h"
#include "core/sdl/io/sdlRwops.h"

namespace Jackbengine {

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
    const auto sdlRwops = std::make_unique<SdlRwops>(data, dataSize);

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
