//
// audioSourceComponent.hpp
// jackbengine
//
// Created by Damien Bendejacq on 04/06/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __AUDIO_SOURCE_COMPONENT_H__
#define __AUDIO_SOURCE_COMPONENT_H__

#include "component/component.hpp"
#include "core/audio/sound.hpp"

namespace Jackbengine {

class AudioSourceComponent : public Component
{
public:
    AudioSourceComponent();
    ~AudioSourceComponent();

    bool loadFromFile(const char *file) const;
    bool loadFromMemory(const void *data, size_t dataSize) const;

    void play() const;
    void play(bool loop) const;

private:
    Sound *m_sound = nullptr;
};

} // namespace Jackbengine

#endif // __AUDIO_SOURCE_COMPONENT_H__
