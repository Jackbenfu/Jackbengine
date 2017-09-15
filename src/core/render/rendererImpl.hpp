//
// rendererImpl.hpp
// jackbengine
//
// Created by Damien Bendejacq on 14/04/14.
// Copyright © 2014 Damien Bendejacq. All rights reserved.
//

#ifndef __RENDERER_IMPL_H__
#define __RENDERER_IMPL_H__

#include "renderer.hpp"
#include "color32.hpp"
#include "platform.hpp"

namespace Jackbengine {

class RendererImpl : public Renderer
{
    friend class Renderer;

public:
    ~RendererImpl() override;

    bool init(const Window *window) override;
    void clear() override;
    void setClearColor(Color32 color) override;
    void present() override;

    void setRenderColor(Color32 color) override;

    void renderTexture(int x, int y, const Texture *texture) override;
    void renderTexture(int x, int y, const Texture *texture, double angle) override;
    void renderLine(float x1, float y1, float x2, float y2, Color32 color) override;
    void renderPoint(float x, float y, Color32 color) override;

    int getWidth() const override;
    int getHeight() const override;

    SDL_Renderer* getRawRenderer() const;

private:
    RendererImpl();

    SDL_Renderer *m_renderer = nullptr;

    Color32 m_clearColor;

    int m_width = 0;
    int m_height = 0;
};

} // namespace Jackbengine

#endif // __RENDERER_IMPL_H__
