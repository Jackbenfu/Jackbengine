//
// applicationCloseEvent.h
// jackbengine
//
// Created by Damien Bendejacq on 21/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __APPLICATION_CLOSE_EVENT_H__
#define __APPLICATION_CLOSE_EVENT_H__

#include "core/event/event.h"

namespace Jackbengine {

class ApplicationCloseEvent : public details::Event
{
public:
    EVENT_CLASS_TYPE(EventType::ApplicationClose)

    [[nodiscard]] std::string toString() const override
    {
        return "ApplicationCloseEvent";
    }
};

}

#endif // __APPLICATION_CLOSE_EVENT_H__
