//
// sound.h
// jackbengine
//
// Created by Damien Bendejacq on 15/07/2017.
//

#ifndef __SOUND_H__
#define __SOUND_H__

#include <string>

struct Mix_Chunk;

namespace Jackbengine::details {

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
