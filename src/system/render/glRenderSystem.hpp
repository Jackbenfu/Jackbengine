//
// glRenderSystem.hpp
// jackbengine
//
// Created by Damien Bendejacq on 30/12/2018.
// Copyright © 2018 Damien Bendejacq. All rights reserved.
//

#ifndef __GL_RENDER_SYSTEM_H__
#define __GL_RENDER_SYSTEM_H__

#include "system/system.hpp"
#include "core/render/window/window.hpp"

namespace Jackbengine {

class GlRenderSystem final : public System
{
public:
    GlRenderSystem() = delete;
    explicit GlRenderSystem(const Window& window);
    ~GlRenderSystem() override;

    int order() const final;

private:
    void frame(float delta) override;
    bool hasRequiredComponents(ComponentCollection& components) const override;

    uint createProgram(const std::string& vertexShader, const std::string& fragmentShader);
    uint compileShader(uint type, const std::string& source);

    void sortByZIndex();

    const Window& m_window;

    uint program;
};

}

#endif // __GL_RENDER_SYSTEM_H__
