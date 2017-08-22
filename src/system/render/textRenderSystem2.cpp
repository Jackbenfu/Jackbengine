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

    for (auto entity : m_entities)
    {
        auto components = entity.second;

        auto& text = components->get<TextComponent2>();
        auto& container = components->get<ContainerComponent2>();

        Vec2f position;
        auto angle = 0.0;

        switch (text.getLayout())
        {
            case TextLayout2::LeftTop:
            {
                position.x = static_cast<float>(container.getX());
                position.y = static_cast<float>(container.getY());
                break;
            }

            case TextLayout2::LeftCenter:
            {
                position.x = static_cast<float>(container.getX());
                position.y = static_cast<float>(container.getY()) +
                        container.getHeight() / 2 -
                        text.getHeight() / 2 +
                        text.getTopWhiteSpace() / 2;
                break;
            }

            case TextLayout2::LeftBottom:
            {
                position.x = static_cast<float>(container.getX());
                position.y = static_cast<float>(container.getY()) +
                        container.getHeight() -
                        text.getHeight();
                break;
            }

            case TextLayout2::CenterTop:
            {
                position.x = static_cast<float>(container.getX()) +
                        container.getWidth() / 2 -
                        text.getWidth() / 2 +
                        text.getRightWhiteSpace() / 2;
                position.y = static_cast<float>(container.getY());
                break;
            }

            case TextLayout2::CenterCenter:
            {
                position.x = static_cast<float>(container.getX()) +
                        container.getWidth() / 2 -
                        text.getWidth() / 2 +
                        text.getRightWhiteSpace() / 2;
                position.y = static_cast<float>(container.getY()) +
                        container.getHeight() / 2 -
                        text.getHeight() / 2 +
                        text.getTopWhiteSpace() / 2;
                break;
            }

            case TextLayout2::CenterBottom:
            {
                position.x = static_cast<float>(container.getX()) +
                        container.getWidth() / 2 -
                        text.getWidth() / 2 +
                        text.getRightWhiteSpace() / 2;
                position.y = static_cast<float>(container.getY()) +
                        container.getHeight() -
                        text.getHeight();
                break;
            }

            case TextLayout2::RightTop:
            {
                position.x = static_cast<float>(container.getX()) +
                        container.getWidth() -
                        text.getWidth();
                position.y = static_cast<float>(container.getY());
                break;
            }

            case TextLayout2::RightCenter:
            {
                position.x = static_cast<float>(container.getX()) +
                        container.getWidth() -
                        text.getWidth();
                position.y = static_cast<float>(container.getY()) +
                        container.getHeight() / 2 -
                        text.getHeight() / 2 +
                        text.getTopWhiteSpace() / 2;
                break;
            }

            case TextLayout2::RightBottom:
            {
                position.x = static_cast<float>(container.getX()) +
                        container.getWidth() -
                        text.getWidth();
                position.y = static_cast<float>(container.getY()) +
                        container.getHeight() -
                        text.getHeight();
                break;
            }
        }

        m_renderer.renderTexture(
            (int)position.x,
            (int)position.y,
            text.getTexture(),
            angle
        );
    }
}

bool TextRenderSystem2::hasRequiredComponents(ComponentCollection& components) const
{
    return components.any<TextComponent2>()
        && components.any<ContainerComponent2>();
}
