//
// applicationConfig.cpp
// jackbengine
//
// Created by Damien Bendejacq on 17/08/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#include "applicationConfig.hpp"

using namespace Jackbengine;

ApplicationConfig::ApplicationConfig()
{
    general_title = "<Insert title here!>";

    render_width = 640;
    render_height = 480;
    render_fullscreen = false;

    core_fps = 60;
}
