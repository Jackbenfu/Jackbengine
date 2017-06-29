//
// tmxSceneLoader.h
// jackbengine
//
// Created by Damien Bendejacq on 30/07/2016.
// Copyright © 2016 Damien Bendejacq. All rights reserved.
//

#ifndef __TMX_SCENE_LOADER_H__
#define __TMX_SCENE_LOADER_H__

#include "scene/loader/sceneLoader.h"
#include "core/tmx/tmxMap.h"

#include "component/view/textComponent.h"

NS_BEGIN_JKB

class TmxSceneLoader : public SceneLoader
{
public:
    TmxSceneLoader(Scene *scene);
    ~TmxSceneLoader();

    bool loadFromFile(const char *file);
    bool loadFromMemory(const unsigned char *data);

protected:
    virtual bool loadContents() = 0;

    TmxMap* map() const;

    void createImageEntityFromLayer(const char *layerName, const char *tilesetFile);

    void createTextEntityFromObject(const char *groupName, const char *objectName);
    void setTextValue(TextComponent *component, const TmxPropertyGroup *properties);
    void setTextColor(TextComponent *component, const TmxPropertyGroup *properties);
    void setTextLayout(TextComponent *component, const TmxPropertyGroup *properties);
    void setTextFont(TextComponent *component, const TmxPropertyGroup *properties);

private:
    TmxMap *m_map {nullptr};

    const Color DEFAULT_TEXT_COLOR = Color_White;
    const TextLayout DEFAULT_TEXT_LAYOUT = TextLayout::LeftTop;
    const int DEFAULT_TEXT_SIZE = 18;

    const char *PROPERTY_TEXT_VALUE = "textValue";
    const char *PROPERTY_TEXT_COLOR = "textColor";
    const char *PROPERTY_TEXT_LAYOUT = "textLayout";
    const char *PROPERTY_TEXT_FONT = "textFont";
    const char *PROPERTY_TEXT_SIZE = "textSize";
    const char *TEXT_LAYOUT_LEFT_TOP = "LeftTop";
    const char *TEXT_LAYOUT_LEFT_CENTER = "LeftCenter";
    const char *TEXT_LAYOUT_LEFT_BOTTOM = "LeftBottom";
    const char *TEXT_LAYOUT_CENTER_TOP = "CenterTop";
    const char *TEXT_LAYOUT_CENTER_CENTER = "CenterCenter";
    const char *TEXT_LAYOUT_CENTER_BOTTOM = "CenterBottom";
    const char *TEXT_LAYOUT_RIGHT_TOP = "RightTop";
    const char *TEXT_LAYOUT_RIGHT_CENTER = "RightCenter";
    const char *TEXT_LAYOUT_RIGHT_BOTTOM = "RightBottom";
};

NS_END_JKB

#endif // __TMX_SCENE_LOADER_H__
