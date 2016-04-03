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
            bool doRender = false;

            TextComponent *text = em()->getComponent<TextComponent>(entity);
            ContainerComponent *container = em()->getComponent<ContainerComponent>(entity);

            Vec2f pos;

            if (container && container->isEnabled())
            {
                doRender = true;

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
            }
            else
            {
                TransformComponent *transform = em()->getComponent<TransformComponent>(entity);

                if (transform->isEnabled())
                {
                    doRender = true;
                    pos = transform->getPosition();
                }
            }

            if (doRender)
            {
                m_renderer->renderTexture(
                    static_cast<int>(pos.x),
                    static_cast<int>(pos.y),
                    text->getTexture()
                );
            }
        }
    }
}

bool TextRenderSystem::hasRequiredComponents(Entity *entity)
{
    return em()->getComponent<TextComponent>(entity) &&
        (em()->getComponent<ContainerComponent>(entity) ||
         em()->getComponent<TransformComponent>(entity));
}

void TextRenderSystem::setRenderer(Renderer *renderer)
{
    m_renderer = renderer;
}
