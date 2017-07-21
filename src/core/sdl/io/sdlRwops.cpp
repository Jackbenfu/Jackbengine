//
// sdlRwops.cpp
// jackbengine
//
// Created by Damien Bendejacq on 15/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "sdlRwops.hpp"

using namespace Jackbengine;

SdlRwops::SdlRwops(const void *data, size_t dataSize)
{
    m_rwops = SDL_RWFromConstMem(data, (int)dataSize);

    if (nullptr == m_rwops)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

SdlRwops::~SdlRwops()
{
    SDL_RWclose(m_rwops);
}

SDL_RWops* SdlRwops::getInternalObject() const
{
    return m_rwops;
}