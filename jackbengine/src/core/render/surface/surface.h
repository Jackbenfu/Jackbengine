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
#include "core/io/rwops.h"

namespace Jackbengine {

class Surface
{
public:
    explicit Surface(const std::string &file);
    explicit Surface(const RWops &rwops);
    Surface(int width, int height, int depth);
    Surface(const Font &font, const std::string &text, Color foreground);
    ~Surface();

    [[nodiscard]] void *nativeObject() const;

private:
    void *m_surface {nullptr};
};

}

#endif // __SURFACE_H__