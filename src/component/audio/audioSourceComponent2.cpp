//
// audioSourceComponent2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 21/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "audioSourceComponent2.hpp"

using namespace Jackbengine;

AudioSourceComponent2::AudioSourceComponent2(const std::string& file)
    : m_sound2 {file}
{
    // Nothing
}

AudioSourceComponent2::AudioSourceComponent2(const void *data, size_t dataSize)
    : m_sound2 {data, dataSize}
{
    // Nothing
}

void AudioSourceComponent2::play() const
{
    m_sound2.play(false);
}

void AudioSourceComponent2::play(bool loop) const
{
    m_sound2.play(loop);
}
