//
// debugLayer.h
// jackbengine
//
// Created by Damien Bendejacq on 22/09/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
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
    DebugLayer(const details::Timer *timer, const details::Window *window);
    ~DebugLayer() override = default;

    void update(float delta) override;
    void onEvent(Event &e) override;

private:
    bool onKeyDownEvent(const KeyDownEvent &e);
    bool onKeyUpEvent(const KeyUpEvent &e);
    bool onMouseMotionEvent(const MouseMotionEvent &e);
    bool onMouseDownEvent(const MouseDownEvent &e);
    bool onMouseUpEvent(const MouseUpEvent &e);

    const details::Timer *m_timer;
    const details::Window *m_window;
};

}

#endif // __DEBUG_LAYER_H__
