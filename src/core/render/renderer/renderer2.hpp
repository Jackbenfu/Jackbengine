//
// renderer2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 12/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __RENDERER_2_H__
#define __RENDERER_2_H__

#include <memory>
#include "core/render/color.hpp"
#include "core/render/window/window2.hpp"

namespace Jackbengine {

class Texture2;
class Renderer2
{
    friend class Texture2;

    DISALLOW_COPY_AND_MOVE(Renderer2)

public:
    explicit Renderer2(const Window2& window);
    ~Renderer2();

    void clear();
    void present();

    void setClearColor(Color color);
    void setRenderColor(Color color);

    void renderTexture(int x, int y, const Texture2& texture);
    void renderTexture(int x, int y, const Texture2& texture, double angle);
    void renderLine(float x1, float y1, float x2, float y2, Color color);
    void renderPoint(float x, float y, Color color);

private:
    void* getInternalObject() const;

    class Impl;
    std::unique_ptr<Impl> m_impl;
};

} // namespace Jackbengine

#endif // __RENDERER_2_H__
