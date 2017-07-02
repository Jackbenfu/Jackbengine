//
// soundImpl.hpp
// jackbengine
//
// Created by Damien Bendejacq on 18/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __SOUND_IMPL_H__
#define __SOUND_IMPL_H__

#include "common.hpp"
#include "sound.hpp"
#include "platform.hpp"

namespace Jackbengine {

class SoundImpl : public Sound
{
    friend class Sound;

public:
    ~SoundImpl() override;

    bool loadFromFile(const char *file) override;
    bool loadFromMemory(const void *data, size_t dataSize) override;

    void play(bool loop) override;

private:
    SoundImpl();

    Mix_Chunk *m_chunk = nullptr;
    bool m_isInitialized = false;

    bool errorAlreadyLoaded() const;
};

} // namespace Jackbengine

#endif // __SOUND_IMPL_H__
