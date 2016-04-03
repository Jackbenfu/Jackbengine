//
//  audioSourceComponent.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 04/06/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#include "audioSourceComponent.h"

AudioSourceComponent::AudioSourceComponent()
{
    m_sound = Sound::create();
}

AudioSourceComponent::~AudioSourceComponent()
{
    DELETE_SAFE(m_sound);
}

bool AudioSourceComponent::load(const char *file) const
{
    return m_sound->load(file);
}

void AudioSourceComponent::play() const
{
    m_sound->play(false);
}

void AudioSourceComponent::play(bool loop) const
{
    m_sound->play(loop);
}
