//
//  sound.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 18/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __SOUND_H__
#define __SOUND_H__

#include "common.h"

NS_BEGIN_JKB

class Sound
{
public:
    virtual ~Sound();

    virtual bool load(const char *file) = 0;
    virtual void play(bool loop) = 0;

    static Sound* create();

protected:
    Sound();
};

NS_END_JKB

#endif // __SOUND_H__