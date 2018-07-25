//
// spriteRenderSystem.cpp
// jackbengine
//
// Created by Damien Bendejacq on 21/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "spriteRenderSystem.hpp"
#include "component/view/spriteComponent.hpp"
#include "component/body/transformComponent.hpp"
#include "component/layout/zOrderComponent.hpp"

using namespace Jackbengine;

SpriteRenderSystem::SpriteRenderSystem(const Renderer& renderer)
    : m_renderer {renderer}
{
}

int SpriteRenderSystem::order() const
{
    return (int) SystemOrder::SpriteRender;
}

void SpriteRenderSystem::frame(float)
{
    sortByZOrder();

    for (const auto&[entity, components] : entities())
    {
        const auto sprite = components->get<SpriteComponent>();
        const auto transform = components->get<TransformComponent>();

        m_renderer.renderTexture(
            (int) transform->positionX(),
            (int) transform->positionY(),
            sprite->texture(),
            transform->angle()
        );
    }
}

bool SpriteRenderSystem::hasRequiredComponents(ComponentCollection& components) const
{
    return components.any<SpriteComponent>()
           && components.any<TransformComponent>()
           && components.any<ZOrderComponent>();
}

void SpriteRenderSystem::sortByZOrder()
{
    const auto lambda = [](
        const std::pair<Entity, ComponentCollection *>& left,
        const std::pair<Entity, ComponentCollection *>& right
    )
    {
        const auto leftZOrder = left.second->get<ZOrderComponent>();
        const auto rightZOrder = right.second->get<ZOrderComponent>();

        return leftZOrder->index() < rightZOrder->index();
    };

    sort(lambda);
}
