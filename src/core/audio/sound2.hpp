//
// sound2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 15/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SOUND_2_H__
#define __SOUND_2_H__

#include <memory>
#include "common.hpp"

namespace Jackbengine {

class Sound2
{
    DISALLOW_COPY_AND_MOVE(Sound2)

public:
    explicit Sound2(const std::string& file);
    Sound2(const void *data, size_t dataSize);

    ~Sound2();

    void play(bool loop) const;

private:
    class Impl;
    std::unique_ptr<Impl> m_impl;
};

} // namespace Jackbengine

#endif // __SOUND_2_H__
