//
// sceneManager.hpp
// jackbengine
//
// Created by Damien Bendejacq on 13/09/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include "common.hpp"
#include <functional>

namespace Jackbengine {

template<typename TBase>
class SceneManager
{
    friend class Scene2;

    DISALLOW_COPY_AND_MOVE(SceneManager)

public:
    SceneManager() = default;

    template<typename TDerived, typename ...Args>
    void loadScene(Args&& ...args);

    TBase& current() const;

private:
    void trySetNextScene();

    std::unique_ptr<TBase> m_currentScene;
    std::function<void()> m_SceneInitializer;
};

#include "sceneManager.tpp"

} // namespace Jackbengine

#endif // __SCENE_MANAGER_H__
