//
// tmxSceneLoader.cpp
// jackbengine
//
// Created by Damien Bendejacq on 30/07/2016.
// Copyright © 2016 Damien Bendejacq. All rights reserved.
//

#include "tmxSceneLoader.h"
#include "core/resource/importResource.h"

#include "component/layout/containerComponent.h"
#include "component/body/transformComponent.h"
#include "component/view/spriteComponent.h"

IMPORT_BINARY_RESOURCE(default_font);

TmxSceneLoader::TmxSceneLoader(Scene *scene)
    : SceneLoader(scene)
{
}

TmxSceneLoader::~TmxSceneLoader()
{
    DELETE_SAFE(m_map);
}

bool TmxSceneLoader::loadFromFile(const char *file)
{
    m_map = new TmxMap();

    auto result = m_map->loadFromFile(file);
    loadContents();

    return result;
}

bool TmxSceneLoader::loadFromMemory(const unsigned char *data)
{
    m_map = new TmxMap();

    auto result = m_map->loadFromMemory(data);
    loadContents();

    return result;
}

TmxMap* TmxSceneLoader::map() const
{
    return m_map;
}

void TmxSceneLoader::createImageEntityFromLayer(const char *layerName, const char *tilesetFile)
{
    auto background = scene()->addEntity(layerName);

    scene()->addComponent<TransformComponent>(background);

    auto tileset = getBinaryResource(tilesetFile);
    scene()->addComponent<SpriteComponent>(background)->loadFromLayer(
        scene()->renderer(),
        map(),
        layerName,
        tileset->first,
        tileset->second
    );
}

void TmxSceneLoader::createTextEntityFromObject(const char *groupName, const char *objectName)
{
    auto object = map()->getObjectGroup(groupName)->getObject(objectName);
    auto objectProperties = object->getProperties();

    auto entity = scene()->addEntity(objectName);

    scene()->addComponent<ContainerComponent>(entity)->setRect(
        object->getX(),
        object->getY(),
        object->getWidth(),
        object->getHeight()
    );

    auto text = scene()->addComponent<TextComponent>(entity);
    setTextValue(text, objectProperties);
    setTextLayout(text, objectProperties);
    setTextLayout(text, objectProperties);
    setTextColor(text, objectProperties);
    setTextFont(text, objectProperties);
}

void TmxSceneLoader::setTextValue(TextComponent *component, const TmxPropertyGroup *properties)
{
    auto text = properties->getProperty(PROPERTY_TEXT_VALUE);
    component->setText(text);
}
void TmxSceneLoader::setTextColor(TextComponent *component, const TmxPropertyGroup *properties)
{
    auto color = DEFAULT_TEXT_COLOR;
    if (properties->hasProperty(PROPERTY_TEXT_COLOR))
    {
        auto hexColor = properties->getProperty(PROPERTY_TEXT_COLOR);
        auto intColor = strtol(hexColor + 3, nullptr, 16);

        auto r = (byte)((intColor >> 16) & 0xFF);
        auto g = (byte)((intColor >> 8) & 0xFF);
        auto b = (byte)(intColor & 0xFF);

        color = Color(r, g, b);
    }

    component->setForeground(color);
}

void TmxSceneLoader::setTextLayout(TextComponent *component, const TmxPropertyGroup *properties)
{
    if (properties->hasProperty(PROPERTY_TEXT_LAYOUT))
    {
        auto textLayoutString = properties->getProperty(PROPERTY_TEXT_LAYOUT);
        auto layout = DEFAULT_TEXT_LAYOUT;

        if (0 == strcmp(TEXT_LAYOUT_LEFT_TOP, textLayoutString))
        {
            layout = TextLayout::LeftTop;
        }
        else if (0 == strcmp(TEXT_LAYOUT_LEFT_CENTER, textLayoutString))
        {
            layout = TextLayout::LeftCenter;
        }
        else if (0 == strcmp(TEXT_LAYOUT_LEFT_BOTTOM, textLayoutString))
        {
            layout = TextLayout::LeftBottom;
        }
        else if (0 == strcmp(TEXT_LAYOUT_CENTER_TOP, textLayoutString))
        {
            layout = TextLayout::CenterTop;
        }
        else if (0 == strcmp(TEXT_LAYOUT_CENTER_CENTER, textLayoutString))
        {
            layout = TextLayout::CenterCenter;
        }
        else if (0 == strcmp(TEXT_LAYOUT_CENTER_BOTTOM, textLayoutString))
        {
            layout = TextLayout::CenterBottom;
        }
        else if (0 == strcmp(TEXT_LAYOUT_RIGHT_TOP, textLayoutString))
        {
            layout = TextLayout::RightTop;
        }
        else if (0 == strcmp(TEXT_LAYOUT_RIGHT_CENTER, textLayoutString))
        {
            layout = TextLayout::RightCenter;
        }
        else if (0 == strcmp(TEXT_LAYOUT_RIGHT_BOTTOM, textLayoutString))
        {
            layout = TextLayout::RightBottom;
        }

        component->setLayout(layout);
    }
}

void TmxSceneLoader::setTextFont(TextComponent *component, const TmxPropertyGroup *properties)
{
    auto textSize = DEFAULT_TEXT_SIZE;
    if (properties->hasProperty(PROPERTY_TEXT_SIZE))
    {
        properties->getIntProperty(PROPERTY_TEXT_SIZE, &textSize);
    }

    if (properties->hasProperty(PROPERTY_TEXT_FONT))
    {
        auto textFont = properties->getProperty(PROPERTY_TEXT_FONT);

        if (hasBinaryResource(textFont))
        {
            auto pair = getBinaryResource(textFont);
            component->setFontFromMemory(
                scene()->renderer(),
                pair->first,
                pair->second,
                textSize
            );
        }
        else
        {
            component->setFontFromFile(
                scene()->renderer(),
                properties->getProperty(PROPERTY_TEXT_FONT),
                textSize
            );
        }
    }
    else
    {
        component->setFontFromMemory(
            scene()->renderer(),
            default_font,
            default_font_size,
            textSize
        );
    }
}
