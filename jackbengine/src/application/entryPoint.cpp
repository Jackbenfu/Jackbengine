//
// entryPoint.cpp
// jackbengine
//
// Created by Damien Bendejacq on 21/11/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#include "entryPoint.h"

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

void loopMock()
{
}

#endif

int main(int argc, char **argv)
{
    auto fullscreen = false;
    parseArguments(argc, argv, &fullscreen);

#ifdef EMSCRIPTEN
    emscripten_set_main_loop(loopMock, 0, 0);
#endif

    auto application = Jackbengine::CreateApplication(fullscreen);

#ifdef EMSCRIPTEN
    applicationPtr = application.get();
    emscripten_cancel_main_loop();
    emscripten_set_main_loop(loop, 0, 1);
#else
    while (application->running())
    {
        application->loop();
    }
#endif

    return 0;
}
