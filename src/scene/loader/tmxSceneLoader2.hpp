//
// tmxSceneLoader2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 04/10/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __TMX_SCENE_LOADER_2_H__
#define __TMX_SCENE_LOADER_2_H__

#include <unordered_map>
#include "core/tmx/tmxMap.hpp"
#include "component/view/textComponent2.hpp"
#include "scene/scene2.hpp"

namespace Jackbengine {

class TmxSceneLoader2
{
    DISALLOW_COPY_AND_MOVE(TmxSceneLoader2)

public:
    TmxSceneLoader2(
        Scene2& scene, const unsigned char *tmxData,
        const void *tilesetData, size_t tilesetDataSize,
        const void *fontData, size_t fontDataSize
    );

    ~TmxSceneLoader2() = default;

    Entity2 entity(const char *name);

private:
    void loadContents();
    void loadSystems();
    void loadLayer(int index);
    void loadObjectGroup(int index);
    void loadEntityFromObjectGroup(const TmxObjectGroup *objectGroup);
    void loadEntityFromObject(const TmxObject *object);
    void loadTextFromObject(const TmxObject *object, Entity2 entity);

    bool hasObjectGroupChildGid(const TmxObjectGroup *objectGroup) const;
    TextLayout2 getTextLayout(const TmxText *text) const;
    Color32 getTextColor(const TmxText *text) const;

    Scene2& m_scene;
    TmxMap m_map;

    const void *m_tilesetData;
    const size_t m_tilesetDataSize;

    const void *m_fontData;
    const size_t m_fontDataSize;

    std::unordered_map<std::string, Entity2> m_entities;
};

} // namespace Jackbengine

#endif // __TMX_SCENE_LOADER_2_H__
