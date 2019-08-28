//
// app.cpp
// sandbox
//
// Created by Damien Bendejacq on 13/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#include "app.h"

namespace Jackbengine {

std::unique_ptr<Application> createApplication(bool fullscreen)
{
    ApplicationConfig config {"Sandbox", 640, 480, fullscreen};

    return std::make_unique<Sandbox::App>(config);
}

}

Sandbox::App::App(Jackbengine::ApplicationConfig &config)
    : Application(config)
{
}

void Sandbox::App::frame(float)
{
}
