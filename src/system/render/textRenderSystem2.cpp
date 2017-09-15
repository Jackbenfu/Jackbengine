//
// textRenderSystem2.cpp
// jackbengine
//
// Created by Damien Bendejacq on 21/08/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#include "textRenderSystem2.hpp"
#include "component/layout/containerComponent2.hpp"
#include "component/view/textComponent2.hpp"

using namespace Jackbengine;

TextRenderSystem2::TextRenderSystem2(Renderer2& renderer)
    : m_renderer {renderer}
{
    // Nothing
}

void TextRenderSystem2::frame(float delta)
{
    UNUSED(delta);

    for (const auto entity : m_entities)
    {
        const auto components = entity.second;

        const auto& text = components->get<TextComponent2>();
        const auto& container = components->get<ContainerComponent2>();

        Vec2f position;
        const auto angle = 0.0;

        switch (text.layout())
        {
            case TextLayout2::LeftTop:
            {
                position.x = container.x();
                position.y = container.y();
                break;
            }

            case TextLayout2::LeftCenter:
            {
                position.x = container.x();
                position.y = container.y() + container.height() / 2 - text.height() / 2 +
                    text.topWhiteSpace() / 2;
                break;
            }

            case TextLayout2::LeftBottom:
            {
                position.x = container.x();
                position.y = container.y() + container.height() - text.height();
                break;
            }

            case TextLayout2::CenterTop:
            {
                position.x = container.x() + container.width() / 2 - text.width() / 2 +
                    text.rightWhiteSpace() / 2;
                position.y = container.y();
                break;
            }

            case TextLayout2::CenterCenter:
            {
                position.x = container.x() + container.width() / 2 - text.width() / 2 +
                    text.rightWhiteSpace() / 2;
                position.y = container.y() + container.height() / 2 - text.height() / 2 +
                    text.topWhiteSpace() / 2;
                break;
            }

            case TextLayout2::CenterBottom:
            {
                position.x = container.x() + container.width() / 2 - text.width() / 2 +
                    text.rightWhiteSpace() / 2;
                position.y = container.y() + container.height() - text.height();
                break;
            }

            case TextLayout2::RightTop:
            {
                position.x = container.x() + container.width() - text.width();
                position.y = container.y();
                break;
            }

            case TextLayout2::RightCenter:
            {
                position.x = container.x() + container.width() - text.width();
                position.y = container.y() + container.height() / 2 - text.height() / 2 +
                    text.topWhiteSpace() / 2;
                break;
            }

            case TextLayout2::RightBottom:
            {
                position.x = container.x() + container.width() - text.width();
                position.y = container.y() + container.height() - text.height();
                break;
            }
        }

        m_renderer.renderTexture(
            (int)position.x,
            (int)position.y,
            text.texture(),
            angle
        );
    }
}

bool TextRenderSystem2::hasRequiredComponents(ComponentCollection& components) const
{
    auto hasText = components.any<TextComponent2>();
    auto hasContainer = components.any<ContainerComponent2>();

    return hasText && hasContainer;
//   return components.any<TextComponent2>()
//        && components.any<ContainerComponent2>();
}
