//
// profile.h
// jackbengine
//
// Created by Damien Bendejacq on 02/07/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __PROFILE_H__
#define __PROFILE_H__

#include <time.h>
#include "common.h"

NS_BEGIN_JKB

class Profile
{
public:
    explicit Profile(const char *name)
    {
        _name = name;
        _start = clock();
    }

    ~Profile()
    {
        clock_t diff = clock() - _start;
        u_long ms = diff * 1000 / CLOCKS_PER_SEC;
        LOG_DEBUG(
            "Time taken for %s: %lu seconds %lu milliseconds",
            _name,
            ms / 1000, ms % 1000
        );
    }

private:
    const char *_name;
    clock_t _start;

};

#define PROFILE(name) Profile __profile__(name)

NS_END_JKB

#endif // __PROFILE_H__
