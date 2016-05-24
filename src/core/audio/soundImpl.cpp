//
//  soundImpl.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 18/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#include "soundImpl.h"

SoundImpl::SoundImpl()
{
}

SoundImpl::~SoundImpl()
{
    Mix_FreeChunk(m_chunk);
}

bool SoundImpl::loadFromFile(const char *file)
{
    if (m_isInitialized)
    {
        return errorAlreadyLoaded();
    }

    m_chunk = Mix_LoadWAV(file);
    if (!m_chunk)
    {
        printf("%s\n", Mix_GetError());
        return false;
    }

    m_isInitialized = true;
    return true;
}

bool SoundImpl::loadFromMemory(const void *data, size_t dataSize)
{
    if (m_isInitialized)
    {
        return errorAlreadyLoaded();
    }

    auto *rWops = SDL_RWFromConstMem(data, dataSize);
    if (!rWops)
    {
        printf("%s\n", SDL_GetError());
        return false;
    }

    m_chunk = Mix_LoadWAV_RW(rWops, 1);
    if (!m_chunk)
    {
        printf("%s\n", Mix_GetError());
        return false;
    }

    m_isInitialized = true;
    return true;
}

void SoundImpl::play(bool loop)
{
    Mix_PlayChannel(MIX_DEFAULT_CHANNELS, m_chunk, loop ? 1 : 0);
}

bool SoundImpl::errorAlreadyLoaded() const
{
    printf("Error: Sound instance already loaded\n");
    return false;
}
