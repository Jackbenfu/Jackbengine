//
//  nameComponent.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 20/07/2015.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __NAME_COMPONENT_H__
#define __NAME_COMPONENT_H__

#include "component/component.h"
#include "common.h"

NS_BEGIN_JKB

class NameComponent :
    public Component,
    public TypedObject<NameComponent>
{
public:
    NameComponent();
    ~NameComponent();

    const char* getName() const;
    void setName(const char *name);

private:
    char *m_name = nullptr;
};

NS_END_JKB

#endif // __NAME_COMPONENT_H__
