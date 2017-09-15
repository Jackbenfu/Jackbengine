//
// application.tpp
// jackbengine
//
// Created by Damien Bendejacq on 30/06/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __APPLICATION_TPP__
#define __APPLICATION_TPP__

#include "exception/sceneExistsException.hpp"

using namespace std;

template<typename TScene>
void Application::addScene()
{
    ASSERT_IS_BASE_OF(Scene, TScene);

    const auto typeId = GET_TYPE_ID(TScene);

    const auto predicate = [&](const auto& pair)
    {
        return pair.first == typeId;
    };

    if (any_of(m_scenes.begin(), m_scenes.end(), predicate))
    {
        throw SceneExistsException<TScene>();
    }

    auto scene = new TScene();
    setSceneFeatures(*scene);

    /*if (getScene(scene->name()))
    {
        DELETE_SAFE(scene);
        return false;
    }*/

    m_scenes.insert(make_pair(typeId, scene));

    if (1 == m_scenes.size())
    {
        m_currentScene = scene;
    }
}

#endif // __APPLICATION_TPP__
