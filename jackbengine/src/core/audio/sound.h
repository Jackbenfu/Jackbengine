//
// sound.h
// jackbengine
//
// Created by Damien Bendejacq on 15/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SOUND_H__
#define __SOUND_H__

#include <string>
#include "core/sdl/sdl.h"
#include "common.h"

namespace Jackbengine {

class Sound
{
public:
    explicit Sound(const std::string &file);
    Sound(const void *data, size_t dataSize);

    ~Sound();

    void play(bool loop) const;

private:
    Mix_Chunk *m_chunk {nullptr};
};

}

#endif // __SOUND_H__
