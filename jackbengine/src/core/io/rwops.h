//
// rwops.h
// jackbengine
//
// Created by Damien Bendejacq on 15/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __RWOPS_H__
#define __RWOPS_H__

#include <cstddef>

typedef struct SDL_RWops SDL_RWops;

namespace Jackbengine::details {

class RWops
{
public:
    RWops(const void *data, size_t dataSize);
    ~RWops() = default;

    [[nodiscard]] SDL_RWops *nativeObject() const;

private:
    SDL_RWops *m_rwops {nullptr};
};

}

#endif // __RWOPS_H__
