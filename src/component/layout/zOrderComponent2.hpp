//
// zOrderComponent2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 29/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __Z_ORDER_COMPONENT_2_H__
#define __Z_ORDER_COMPONENT_2_H__

#include "component/component2.hpp"

namespace Jackbengine {

class ZOrderComponent2 : public Component2
{
    DISALLOW_COPY_AND_MOVE(ZOrderComponent2)

public:
    ZOrderComponent2() = default;
    ZOrderComponent2(int index);

    ~ZOrderComponent2() override = default;

    int index() const;
    void setIndex(int index);

private:
    int m_index {0};
};

using ZOrder = ZOrderComponent2;

} // namespace Jackbengine

#endif // __Z_ORDER_COMPONENT_2_H__
