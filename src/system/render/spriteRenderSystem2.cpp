//
// spriteRenderSystem2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 21/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "spriteRenderSystem2.hpp"
#include "component/view/spriteComponent2.hpp"
#include "component/body/transformComponent2.hpp"

using namespace Jackbengine;

SpriteRenderSystem2::SpriteRenderSystem2(Renderer2& renderer)
    : m_renderer {renderer}
{
    // Nothing
}

void SpriteRenderSystem2::frame(float delta)
{
    UNUSED(delta);

    for (const auto entity : m_entities)
    {
        const auto components = entity.second;

        const auto& sprite = components->get<SpriteComponent2>();
        const auto& transform = components->get<TransformComponent2>();

        m_renderer.renderTexture(
            (int) transform.positionX(),
            (int) transform.positionY(), sprite.texture(), transform.angle()
        );
    }
}

bool SpriteRenderSystem2::hasRequiredComponents(ComponentCollection& components) const
{
    return components.any<SpriteComponent2>()
        && components.any<TransformComponent2>();
}
