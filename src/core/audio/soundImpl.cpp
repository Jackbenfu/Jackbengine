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

bool SoundImpl::load(const char *file)
{
    if (!m_isInitialized)
    {
        m_chunk = Mix_LoadWAV(file);
        if (!m_chunk)
        {
            printf("%s\n", Mix_GetError());
            return false;
        }

        m_isInitialized = true;
        return true;
    }

    return false;
}

void SoundImpl::play(bool loop)
{
    Mix_PlayChannel(MIX_DEFAULT_CHANNELS, m_chunk, loop ? 1 : 0);
}
