//
// entryPoint.cpp
// jackbengine
//
// Created by Damien Bendejacq on 21/11/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#include "pch.h"
#include "entryPoint.h"

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
void frame()
{
    applicationPtr->frame();
}

void frameMock()
{
}

#endif

int main(int argc, char **argv)
{
    auto fullscreen = false;
    parseArguments(argc, argv, &fullscreen);

#ifdef EMSCRIPTEN
    emscripten_set_main_loop(frameMock, 0, 0);
#endif


    auto application = Jackbengine::CreateApplication(fullscreen);
    auto wrapper = Jackbengine::details::ApplicationWrapper(application.get());

#ifdef EMSCRIPTEN
    applicationPtr = application.get();
    emscripten_cancel_main_loop();
    emscripten_set_main_loop(frame, 0, 1);
#else
    while (wrapper.running())
    {
        wrapper.frame();
    }
#endif

    return 0;
}
