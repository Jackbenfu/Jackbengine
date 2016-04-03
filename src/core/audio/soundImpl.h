//
//  soundImpl.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 18/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __SOUND_IMPL_H__
#define __SOUND_IMPL_H__

#include "common.h"
#include "sound.h"

NS_BEGIN_JKB

class SoundImpl : public Sound
{
    friend class Sound;

public:
    ~SoundImpl();

    bool load(const char *file) override;
    void play(bool loop) override;

private:
    SoundImpl();

    Mix_Chunk *m_chunk = nullptr;
    bool m_isInitialized = false;
};

NS_END_JKB

#endif // __SOUND_IMPL_H__