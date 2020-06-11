//
// layerManager.cpp
// jackbengine
//
// Created by Damien Bendejacq on 22/09/2019.
//

#include "core/profile/profile.h"
#include "layerManager.h"

namespace Jackbengine::details {

void LayerManager::update(float delta)
{
    PROFILE("LayerManager::update");

    for (auto& layer : m_layers)
    {
        layer->update(delta);
    }
}

void LayerManager::onEvent(Event& e)
{
    for (auto it = m_layers.rbegin(); it != m_layers.rend(); ++it)
    {
        (*it)->onEvent(e);
        if (e.handled)
        {
            return;
        }
    }
}

}
