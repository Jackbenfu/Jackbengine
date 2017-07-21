//
// sound2.impl.hpp
// jackbengine
//
// Created by Damien Bendejacq on 15/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SOUND_2_IMPL_H__
#define __SOUND_2_IMPL_H__

#include "sound2.hpp"
#include "platform.hpp"

namespace Jackbengine {

class Sound2::Impl
{
public:
    Impl(const std::string& file);
    Impl(const void *data, size_t dataSize);

    ~Impl();

    void play(bool loop) const;

private:
    Mix_Chunk *m_chunk {nullptr};
};

} // namespace Jackbengine

#endif // __SOUND_2_IMPL_H__
