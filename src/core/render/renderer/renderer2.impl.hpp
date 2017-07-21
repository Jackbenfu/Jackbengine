//
// renderer2.impl.hpp
// jackbengine
//
// Created by Damien Bendejacq on 12/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __RENDERER_2_IMPL_H__
#define __RENDERER_2_IMPL_H__

#include "renderer2.hpp"
#include "platform.hpp"
#include "core/render/color.hpp"

namespace Jackbengine {

class Renderer2::Impl
{
public:
    Impl(const Window2& window);
    ~Impl();

    void clear();
    void present();

    void setClearColor(Color color);
    void setRenderColor(Color color);

    void renderTexture(int x, int y, const Texture2& texture);
    void renderTexture(int x, int y, const Texture2& texture, double angle);
    void renderLine(float x1, float y1, float x2, float y2, Color color);
    void renderPoint(float x, float y, Color color);

    SDL_Renderer* getInternalObject() const;

private:
    SDL_Renderer *m_renderer {nullptr};

    Color m_clearColor {Color_Black};
};

} // namespace Jackbengine

#endif // __RENDERER_2_IMPL_H__
