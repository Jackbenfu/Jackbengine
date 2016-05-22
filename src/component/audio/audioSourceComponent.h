//
//  audioSourceComponent.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 04/06/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __AUDIO_SOURCE_COMPONENT_H__
#define __AUDIO_SOURCE_COMPONENT_H__

#include "component/component.h"
#include "core/audio/sound.h"

NS_BEGIN_JKB

class AudioSourceComponent :
    public Component,
    public TypedObject<AudioSourceComponent>
{
public:
    AudioSourceComponent();
    ~AudioSourceComponent();

    bool loadFromFile(const char *file) const;
    bool loadFromMemory(const void *data, size_t dataSize) const;

    void play() const;
    void play(bool loop) const;

private:
    Sound *m_sound;
};

NS_END_JKB

#endif // __AUDIO_SOURCE_COMPONENT_H__
