//
// debugLayer.h
// jackbengine
//
// Created by Damien Bendejacq on 22/09/2019.
//

#ifndef __DEBUG_LAYER_H__
#define __DEBUG_LAYER_H__

#include "core/layer/layer.h"
#include "core/time/timer.h"
#include "core/render/window/window.h"
#include "core/event/impl/eventImpl.h"

namespace Jackbengine {

class DebugLayer : public Layer
{
public:
    DebugLayer(const details::Timer* timer, const details::Window* window, bool demo = false);
    ~DebugLayer() override = default;

    void update(float delta) override;
    void onEvent(Event& e) override;

private:
    void printTiming();
    void printSampleProfiler();

    const details::Timer* m_timer;
    const details::Window* m_window;
    bool m_demo {false};
};

}

#endif // __DEBUG_LAYER_H__
