//
// audioSourceComponent.hpp
// jackbengine
//
// Created by Damien Bendejacq on 21/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __AUDIO_SOURCE_COMPONENT_H__
#define __AUDIO_SOURCE_COMPONENT_H__

#include "component/component.hpp"
#include "core/audio/sound.hpp"

namespace Jackbengine {

class AudioSourceComponent : public Component
{
public:
    explicit AudioSourceComponent(const std::string& file);
    AudioSourceComponent(const void *data, size_t dataSize);

    ~AudioSourceComponent() override = default;

    void play() const;
    void play(bool loop) const;

private:
    std::unique_ptr<Sound> m_sound;
};

using AudioSource = AudioSourceComponent;

}

#endif // __AUDIO_SOURCE_COMPONENT_H__
