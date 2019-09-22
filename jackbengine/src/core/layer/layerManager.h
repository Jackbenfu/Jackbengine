//
// layerManager.h
// jackbengine
//
// Created by Damien Bendejacq on 22/09/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __LAYER_MANAGER_H__
#define __LAYER_MANAGER_H__

#include <vector>

#include "layer.h"

namespace Jackbengine::details {

class LayerManager
{
public:
    LayerManager() = default;
    ~LayerManager() = default;

    void update(float delta);
    void onEvent(Event &e);

    template<typename TLayer, typename ...Args>
    void add(Args &&...args);

    template<typename TLayer>
    void remove();

private:
    std::vector<std::unique_ptr<Layer>> m_layers;
};

template<typename TLayer, typename... Args>
void LayerManager::add(Args &&... args)
{
    m_layers.emplace_back(
        std::make_unique<TLayer>(std::forward<Args>(args)...)
    );
}

template<typename TLayer>
void LayerManager::remove()
{
    auto it = std::find<TLayer>(m_layers.begin(), m_layers.end());
    m_layers.erase(it);
}

}

#endif // __LAYER_MANAGER_H__
