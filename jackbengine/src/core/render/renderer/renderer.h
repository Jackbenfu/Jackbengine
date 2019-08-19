//
// renderer.h
// jackbengine
//
// Created by Damien Bendejacq on 12/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "core/render/color.h"
#include "core/render/window/window.h"

namespace Jackbengine {

class Texture;

class Renderer
{
    friend class Texture;

public:
    explicit Renderer(const Window &window);
    ~Renderer();

    void clear();
    void present();

    void setClearColor(Color color);
    void setRenderColor(Color color) const;

    void renderTexture(int x, int y, const Texture &texture) const;
    void renderTexture(int x, int y, const Texture &texture, double angle) const;
    void renderLine(float x1, float y1, float x2, float y2, Color color) const;
    void renderPoint(float x, float y, Color color) const;

    int width() const;
    int height() const;

private:
    SDL_Renderer *m_renderer {nullptr};

    mutable Color m_clearColor {Color(0, 0, 0)};

    int m_width {0};
    int m_height {0};
};

}

#endif // __RENDERER_H__
