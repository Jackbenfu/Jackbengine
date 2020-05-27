//
// rwops.cpp
// jackbengine
//
// Created by Damien Bendejacq on 15/07/2017.
//

#include <stdexcept>

#include "rwops.h"
#include "core/sdl/sdlinc.h"

namespace Jackbengine::details {

RWops::RWops(const void *data, size_t dataSize)
{
    m_rwops = SDL_RWFromConstMem(data, (int) dataSize);

    if (nullptr == m_rwops)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

RWops::~RWops()
{
    SDL_RWclose(m_rwops);
}

SDL_RWops *RWops::nativeObject() const
{
    return m_rwops;
}

void RWops::seekBegin()
{
    if (-1 == SDL_RWseek(m_rwops, 0, RW_SEEK_SET))
    {
        throw std::runtime_error(SDL_GetError());
    }
}

}
