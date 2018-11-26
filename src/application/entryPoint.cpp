//
// entryPoint.cpp
// jackbengine
//
// Created by Damien Bendejacq on 21/11/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#include "entryPoint.hpp"

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

void parseArguments(int argc, char **argv, bool *fullscreen)
{
    const auto FullscreenOption = "-fullscreen";

    for (auto i = 1; i < argc; ++i)
    {
        auto arg = argv[i];
        if (strstr(arg, FullscreenOption) == arg)
        {
            *fullscreen = true;
        }
    }
}

#ifdef EMSCRIPTEN

Jackbengine::Application *applicationPtr;
void loop()
{
    applicationPtr->loop();
}

#endif

int main(int argc, char **argv)
{
    auto fullscreen = false;
    parseArguments(argc, argv, &fullscreen);

    auto application = Jackbengine::CreateApplication(fullscreen);

#ifdef EMSCRIPTEN
    applicationPtr = application.get();
    emscripten_set_main_loop(loop, 0, 1);
#else
    while (application->running())
    {
        application->loop();
    }
#endif

    return 0;
}
