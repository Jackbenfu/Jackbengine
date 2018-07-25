//
// sceneManager.hpp
// jackbengine
//
// Created by Damien Bendejacq on 13/09/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include <functional>
#include <memory>
#include "common.hpp"

namespace Jackbengine {

template<typename TBase>
class SceneManager
{
    friend class Scene;

DISALLOW_COPY_AND_MOVE(SceneManager)

public:
    SceneManager() = default;

    template<typename TDerived, typename ...Args>
    void loadScene(Args&& ...args);

    TBase& current() const;

private:
    void loadNextSceneIfRequired();

    std::unique_ptr<TBase> m_currentScene;
    std::function<void()> m_sceneInitializer;
};

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

    m_sceneInitializer = initializer;
}

template<typename TBase>
TBase& SceneManager<TBase>::current() const
{
    return *m_currentScene;
}

template<typename TBase>
void SceneManager<TBase>::loadNextSceneIfRequired()
{
    if (nullptr != m_sceneInitializer)
    {
        m_sceneInitializer();
        m_sceneInitializer = nullptr;
    }
}

} // namespace Jackbengine

#endif // __SCENE_MANAGER_H__
