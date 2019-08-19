//
// sdlApplication.h
// jackbengine
//
// Created by Damien Bendejacq on 12/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SDL_APPLICATION_H__
#define __SDL_APPLICATION_H__

namespace Jackbengine::details {

class SDLApplication
{
public:
    SDLApplication();
    virtual ~SDLApplication();

private:
    static void init();
};

}

#endif // __SDL_APPLICATION_H__
