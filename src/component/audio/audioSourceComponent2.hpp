//
// audioSourceComponent2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 21/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __AUDIO_SOURCE_COMPONENT_2_H__
#define __AUDIO_SOURCE_COMPONENT_2_H__

#include "component/component2.hpp"
#include "core/audio/sound2.hpp"

namespace Jackbengine {

class AudioSourceComponent2 : public Component2
{
    DISALLOW_COPY_AND_MOVE(AudioSourceComponent2)

public:
    explicit AudioSourceComponent2(const std::string& file);
    AudioSourceComponent2(const void *data, size_t dataSize);

    ~AudioSourceComponent2() = default;

    void play() const;
    void play(bool loop) const;

private:
    Sound2 m_sound2;
};

} // namespace Jackbengine

#endif // __AUDIO_SOURCE_COMPONENT_2_H__
