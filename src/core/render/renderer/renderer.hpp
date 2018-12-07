//
// renderer.hpp
// jackbengine
//
// Created by Damien Bendejacq on 12/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <memory>
#include "core/render/color.hpp"
#include "core/render/window/window.hpp"

namespace Jackbengine {

class Texture;

class Renderer
{
    friend class Texture;

DISALLOW_COPY_AND_MOVE(Renderer)

public:
    explicit Renderer(const Window& window);
    ~Renderer();

    void clear();
    void present();

    void setClearColor(Color color);
    void setRenderColor(Color color);

    void renderTexture(int x, int y, const Texture& texture) const;
    void renderTexture(int x, int y, const Texture& texture, double angle) const;
    void renderLine(float x1, float y1, float x2, float y2, Color color) const;
    void renderPoint(float x, float y, Color color) const;

    int width() const;
    int height() const;

private:
    void *internalObject() const;

    class Impl;

    std::unique_ptr<Impl> m_impl;
};

}

#endif // __RENDERER_H__
