//
// eventImpl.h
// jackbengine
//
// Created by Damien Bendejacq on 20/08/2019.
// Copyright © 2019 Damien Bendejacq. All rights reserved.
//

#ifndef __EVENT_IMPL_H__
#define __EVENT_IMPL_H__

#include "event.h"

namespace Jackbengine {

class ApplicationClosedEvent : public Event
{
public:
    EVENT_CLASS_TYPE(EventType::ApplicationClosed)
};

}

#endif // __EVENT_IMPL_H__
