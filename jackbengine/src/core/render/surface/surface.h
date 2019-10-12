//
// surface.h
// jackbengine
//
// Created by Damien Bendejacq on 15/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SURFACE_H__
#define __SURFACE_H__

#include "core/render/font/font.h"
#include "core/render/color.h"
#include "core/render/window/window.h"
#include "core/io/rwops.h"

typedef struct SDL_Surface SDL_Surface;

namespace Jackbengine::details {

class Surface
{
public:
    explicit Surface(const std::string &file);
    explicit Surface(const RWops &rwops);
    explicit Surface(const Window &window);
    Surface(int width, int height, int depth);
    Surface(const Font &font, const std::string &text, Color foreground);
    ~Surface();

    [[nodiscard]] SDL_Surface *nativeObject() const;

private:
    bool m_mustBeFreed {true};

    SDL_Surface *m_surface {nullptr};
};

}

#endif // __SURFACE_H__
