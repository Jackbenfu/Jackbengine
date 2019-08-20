//
// eventManager.h
// jackbengine
//
// Created by Damien Bendejacq on 20/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __EVENT_MANAGER_H__
#define __EVENT_MANAGER_H__

#include "eventImpl.h"

namespace Jackbengine::details {

class EventManager
{
    friend class Application;

public:
    using EventCallbackFunc = std::function<void(Event &)>;

    explicit EventManager(EventCallbackFunc callbackFunc);
    ~EventManager() = default;

    void update();

private:
    EventCallbackFunc m_callbackFunc;
};

}

#endif // __EVENT_MANAGER_H__
