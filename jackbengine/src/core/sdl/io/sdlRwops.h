//
// sdlRwops.h
// jackbengine
//
// Created by Damien Bendejacq on 15/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SDL_RWOPS_H__
#define __SDL_RWOPS_H__

namespace Jackbengine {

class SdlRwops
{
public:
    SdlRwops(const void *data, size_t dataSize);
    ~SdlRwops() = default;

    [[nodiscard]] void *nativeObject() const;

private:
    void *m_rwops {nullptr};
};

}

#endif // __SDL_RWOPS_H__
