//
//  renderer.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 14/04/14.
//  Copyright (c) 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "window.h"
#include "color.h"

NS_BEGIN_JKB

class Texture;

class Renderer
{
public:
    virtual ~Renderer();

    virtual bool init(const Window *window) = 0;
    virtual void clear() = 0;
    virtual void setClearColor(Color color) = 0;
    virtual void present() = 0;

    virtual void setRenderColor(Color color) = 0;

    virtual void renderTexture(int x, int y, const Texture *texture) = 0;
    virtual void renderLine(float x1, float y1, float x2, float y2, Color color) = 0;
    virtual void renderPoint(float x, float y, Color color) = 0;

    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;

    static Renderer* create();

protected:
    Renderer();
};

NS_END_JKB

#endif // __RENDERER_H__