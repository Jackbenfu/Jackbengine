//
// entryPoint.cpp
// jackbengine
//
// Created by Damien Bendejacq on 21/11/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

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
void update()
{
    applicationPtr->update();
}

void updateMock()
{
}

#endif

int main(int argc, char **argv)
{
    auto fullscreen = false;
    parseArguments(argc, argv, &fullscreen);

#ifdef EMSCRIPTEN
    emscripten_set_main_loop(updateMock, 0, 0);
#endif

    auto application = Jackbengine::createApplication(fullscreen);
    auto wrapper = Jackbengine::details::ApplicationWrapper(application.get());

#ifdef EMSCRIPTEN
    applicationPtr = application.get();
    emscripten_cancel_main_loop();
    emscripten_set_main_loop(update, 0, 1);
#else
    while (wrapper.running())
    {
        wrapper.update();
    }
#endif

    return 0;
}
