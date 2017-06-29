//
// zOrderComponent.h
// jackbengine
//
// Created by Damien Bendejacq on 26/09/2016.
// Copyright © 2016 Damien Bendejacq. All rights reserved.
//

#ifndef __Z_ORDER_COMPONENT_H__
#define __Z_ORDER_COMPONENT_H__

#include "component/component.h"

NS_BEGIN_JKB

class ZOrderComponent :
    public Component,
    public TypedObject<ZOrderComponent>
{
public:
    ZOrderComponent();
    ~ZOrderComponent();

    int getIndex() const;
    void setIndex(int index);

private:
    int m_index {0};
};

NS_END_JKB

#endif // __Z_ORDER_COMPONENT_H__
