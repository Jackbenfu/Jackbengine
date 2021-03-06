//
// textRenderSystem.hpp
// jackbengine
//
// Created by Damien Bendejacq on 21/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __TEXT_RENDER_SYSTEM_H__
#define __TEXT_RENDER_SYSTEM_H__

#include "system/system.hpp"
#include "core/render/renderer/renderer.hpp"

namespace Jackbengine {

class TextRenderSystem final : public System
{
public:
    TextRenderSystem() = delete;
    explicit TextRenderSystem(const Renderer& renderer);
    ~TextRenderSystem() override = default;

    int order() const final;

private:
    void frame(float delta) override;
    bool hasRequiredComponents(ComponentCollection& components) const override;

    const Renderer& m_renderer;
};

}

#endif // __TEXT_RENDER_SYSTEM_H__
