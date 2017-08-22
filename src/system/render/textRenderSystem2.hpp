//
// textRenderSystem2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 21/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __TEXT_RENDER_SYSTEM_2_H__
#define __TEXT_RENDER_SYSTEM_2_H__

#include "system/system2.hpp"
#include "core/render/renderer/renderer2.hpp"

namespace Jackbengine {

class TextRenderSystem2 : public System2
{
    DISALLOW_COPY_AND_MOVE(TextRenderSystem2)

public:
    explicit TextRenderSystem2(Renderer2& renderer);
    ~TextRenderSystem2() override = default;

private:
    void frame(float delta) override;
    bool hasRequiredComponents(ComponentCollection& components) const override;

    Renderer2& m_renderer;
};

} // namespace Jackbengine

#endif // __TEXT_RENDER_SYSTEM_2_H__
