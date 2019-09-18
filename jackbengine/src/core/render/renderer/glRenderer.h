//
// glRenderer.h
// jackbengine
//
// Created by Damien Bendejacq on 13/09/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __GL_RENDERER_H__
#define __GL_RENDERER_H__

#include "core/render/window/window.h"

namespace Jackbengine::details {

class GlRenderer
{
public:
    explicit GlRenderer(const Window &window);
    ~GlRenderer();

    static void clear();
    void present();

    void initTest();
    static void test();

private:
    static unsigned int createProgram(const char *vertexShader, const char *fragmentShader);
    static unsigned int compileShader(unsigned int type, const char *source);
    static void logError(const char *function, const char *file, int line);

    const Window &m_window;
    unsigned int m_program {0};
};

}

#endif // __GL_RENDERER_H__
