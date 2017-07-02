//
// zOrderComponent.hpp
// jackbengine
//
// Created by Damien Bendejacq on 26/09/2016.
// Copyright © 2016 Damien Bendejacq. All rights reserved.
//

#ifndef __Z_ORDER_COMPONENT_H__
#define __Z_ORDER_COMPONENT_H__

#include "component/component.hpp"

namespace Jackbengine {

class ZOrderComponent : public Component
{
public:
    ZOrderComponent();
    ~ZOrderComponent();

    int getIndex() const;
    void setIndex(int index);

private:
    int m_index = 0;
};

} // namespace Jackbengine

#endif // __Z_ORDER_COMPONENT_H__
