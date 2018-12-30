//
// textDebugSystem.hpp
// jackbengine
//
// Created by Damien Bendejacq on 20/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __TEXT_DEBUG_SYSTEM_H__
#define __TEXT_DEBUG_SYSTEM_H__

#include "system/system.hpp"
#include "core/render/renderer/renderer.hpp"

namespace Jackbengine {

class TextDebugSystem final : public System
{
public:
    explicit TextDebugSystem(const Renderer& renderer);
    TextDebugSystem(const Renderer& renderer, Color color);
    ~TextDebugSystem() override = default;

    int order() const final;

private:
    void frame(float delta) override;
    bool hasRequiredComponents(ComponentCollection& components) const override;

    const Renderer& m_renderer;
    Color m_color;
};

}

#endif // __TEXT_DEBUG_SYSTEM_H__
