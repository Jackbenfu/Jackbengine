//
// applicationConfig.hpp
// jackbengine
//
// Created by Damien Bendejacq on 17/08/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __APPLICATION_CONFIG_H__
#define __APPLICATION_CONFIG_H__

#include <string>
#include "common.hpp"

namespace Jackbengine {

struct ApplicationConfig
{
    ApplicationConfig();

    std::string general_title;

    uint render_width;
    uint render_height;
    bool render_fullscreen;

    uint core_fps;
};

} // namespace Jackbengine

#endif // __APPLICATION_CONFIG_H__
