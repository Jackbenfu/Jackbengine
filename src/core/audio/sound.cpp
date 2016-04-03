//
//  sound.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 18/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#include "sound.h"
#include "soundImpl.h"

Sound::Sound()
{
}

Sound::~Sound()
{
}

Sound* Sound::create()
{
    return new SoundImpl();
}
