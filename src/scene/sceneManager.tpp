//
// sceneManager.tpp
// jackbengine
//
// Created by Damien Bendejacq on 16/09/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SCENE_MANAGER_TPP__
#define __SCENE_MANAGER_TPP__

template<typename TBase>
template<typename TDerived, typename ...Args>
void SceneManager<TBase>::loadScene(Args&& ...args)
{
    static const auto initializer = [&]()
    {
        m_currentScene = std::make_unique<TDerived>(std::forward<Args>(args)...);
    };

    if (nullptr == m_currentScene)
    {
        initializer();
        return;
    }

    m_SceneInitializer = initializer;
}

template<typename TBase>
TBase& SceneManager<TBase>::current() const
{
    return *m_currentScene;
}

template<typename TBase>
void SceneManager<TBase>::trySetNextScene()
{
    if (nullptr != m_SceneInitializer)
    {
        m_SceneInitializer();
        m_SceneInitializer = nullptr;
    }
}

#endif // __SCENE_MANAGER_TPP__
