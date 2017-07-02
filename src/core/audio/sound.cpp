//
// sound.cpp
// jackbengine
//
// Created by Damien Bendejacq on 18/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#include "sound.hpp"
#include "soundImpl.hpp"

using namespace Jackbengine;

Sound::Sound() = default;

Sound::~Sound() = default;

Sound* Sound::create()
{
    return new SoundImpl();
}
