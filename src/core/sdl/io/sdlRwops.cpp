//
// sdlRwops.cpp
// jackbengine
//
// Created by Damien Bendejacq on 15/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include <stdexcept>

#include "core/sdl/sdl.hpp"
#include "sdlRwops.hpp"

namespace Jackbengine {

SdlRwops::SdlRwops(const void *data, size_t dataSize)
{
    m_rwops = SDL_RWFromConstMem(data, (int) dataSize);

    if (nullptr == m_rwops)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

void *SdlRwops::internalObject() const
{
    return m_rwops;
}

}
