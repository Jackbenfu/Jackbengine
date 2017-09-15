//
// tmxSceneLoader.hpp
// jackbengine
//
// Created by Damien Bendejacq on 30/07/2016.
// Copyright © 2016 Damien Bendejacq. All rights reserved.
//

#ifndef __TMX_SCENE_LOADER_H__
#define __TMX_SCENE_LOADER_H__

#include "scene/loader/sceneLoader.hpp"
#include "core/tmx/tmxMap.hpp"

#include "component/view/textComponent.hpp"

namespace Jackbengine {

class TmxSceneLoader : public SceneLoader
{
public:
    explicit TmxSceneLoader(Scene& scene);
    ~TmxSceneLoader() override = default;

    void loadFromFile(const char *file);
    void loadFromMemory(const unsigned char *data);

protected:
    TmxMap* map() const;

    void createImageEntityFromLayer(const char *layerName, const char *tilesetFile);

    void createTextEntityFromObject(const char *groupName, const char *objectName);
    void setTextValue(TextComponent *component, const TmxPropertyGroup *properties);
    void setTextColor(TextComponent *component, const TmxPropertyGroup *properties);
    void setTextLayout(TextComponent *component, const TmxPropertyGroup *properties);
    void setTextFont(TextComponent *component, const TmxPropertyGroup *properties);

private:
    std::unique_ptr<TmxMap> m_map;

    const Color32 DEFAULT_TEXT_COLOR = Color_White;
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

} // namespace Jackbengine

#endif // __TMX_SCENE_LOADER_H__
