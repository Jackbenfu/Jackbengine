//
//  textRenderSystem.cpp
//  Jackbengine
//
//  Created by Damien Bendejacq on 14/06/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#include "textRenderSystem.h"
#include "component/layout/containerComponent.h"
#include "component/view/textComponent.h"
#include "component/body/transformComponent.h"

TextRenderSystem::TextRenderSystem()
{
}

TextRenderSystem::~TextRenderSystem()
{
}

void TextRenderSystem::update(float delta)
{
    UNUSED(delta)

    for (auto entity : m_entities)
    {
        if (em()->isEntityEnabled(entity))
        {
            auto text = em()->getComponentIfEnabled<TextComponent>(entity);
            if (!text)
            {
                continue;
            }

            Vec2f pos;
            auto rotation = 0.0;

            auto transform = em()->getComponentIfEnabled<TransformComponent>(entity);
            auto container = em()->getComponentIfEnabled<ContainerComponent>(entity);
            if (container)
            {
                switch (text->getLayout())
                {
                    case TextLayout::LeftTop:
                    {
                        pos.x = static_cast<float>(container->getX());
                        pos.y = static_cast<float>(container->getY());
                        break;
                    }

                    case TextLayout::LeftCenter:
                    {
                        pos.x = static_cast<float>(container->getX());
                        pos.y = static_cast<float>(container->getY()) +
                                container->getHeight() / 2 -
                                text->getHeight() / 2 +
                                text->getTopWhiteSpace() / 2;
                        break;
                    }

                    case TextLayout::LeftBottom:
                    {
                        pos.x = static_cast<float>(container->getX());
                        pos.y = static_cast<float>(container->getY()) +
                                container->getHeight() -
                                text->getHeight();
                        break;
                    }

                    case TextLayout::CenterTop:
                    {
                        pos.x = static_cast<float>(container->getX()) +
                                container->getWidth() / 2 -
                                text->getWidth() / 2 +
                                text->getRightWhiteSpace() / 2;
                        pos.y = static_cast<float>(container->getY());
                        break;
                    }

                    case TextLayout::CenterCenter:
                    {
                        pos.x = static_cast<float>(container->getX()) +
                                container->getWidth() / 2 -
                                text->getWidth() / 2 +
                                text->getRightWhiteSpace() / 2;
                        pos.y = static_cast<float>(container->getY()) +
                                container->getHeight() / 2 -
                                text->getHeight() / 2 +
                                text->getTopWhiteSpace() / 2;
                        break;
                    }

                    case TextLayout::CenterBottom:
                    {
                        pos.x = static_cast<float>(container->getX()) +
                                container->getWidth() / 2 -
                                text->getWidth() / 2 +
                                text->getRightWhiteSpace() / 2;
                        pos.y = static_cast<float>(container->getY()) +
                                container->getHeight() -
                                text->getHeight();
                        break;
                    }

                    case TextLayout::RightTop:
                    {
                        pos.x = static_cast<float>(container->getX()) +
                                container->getWidth() -
                                text->getWidth();
                        pos.y = static_cast<float>(container->getY());
                        break;
                    }

                    case TextLayout::RightCenter:
                    {
                        pos.x = static_cast<float>(container->getX()) +
                                container->getWidth() -
                                text->getWidth();
                        pos.y = static_cast<float>(container->getY()) +
                                container->getHeight() / 2 -
                                text->getHeight() / 2 +
                                text->getTopWhiteSpace() / 2;
                        break;
                    }

                    case TextLayout::RightBottom:
                    {
                        pos.x = static_cast<float>(container->getX()) +
                                container->getWidth() -
                                text->getWidth();
                        pos.y = static_cast<float>(container->getY()) +
                                container->getHeight() -
                                text->getHeight();
                        break;
                    }
                }

                if (transform)
                {
                    rotation = transform->getRotation();
                }
            }
            else if (transform)
            {
                pos = transform->getPosition();
                rotation = transform->getRotation();
            }

            m_renderer->renderTexture(
                static_cast<int>(pos.x),
                static_cast<int>(pos.y),
                text->getTexture(),
                rotation
            );
        }
    }
}

bool TextRenderSystem::hasRequiredComponents(Entity *entity)
{
    return em()->getComponentIfEnabled<TextComponent>(entity) &&
        (em()->getComponentIfEnabled<ContainerComponent>(entity) ||
         em()->getComponentIfEnabled<TransformComponent>(entity));
}

void TextRenderSystem::setRenderer(Renderer *renderer)
{
    m_renderer = renderer;
}
