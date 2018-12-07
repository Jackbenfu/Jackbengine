//
// zIndexComponent.hpp
// jackbengine
//
// Created by Damien Bendejacq on 29/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __Z_INDEX_COMPONENT_H__
#define __Z_INDEX_COMPONENT_H__

#include "component/component.hpp"

namespace Jackbengine {

class ZIndexComponent : public Component
{
DISALLOW_COPY_AND_MOVE(ZIndexComponent)

public:
    ZIndexComponent() = default;
    explicit ZIndexComponent(uint index);

    ~ZIndexComponent() override = default;

    uint index() const;
    void setIndex(uint index);

private:
    uint m_index {0};
};

using ZIndex = ZIndexComponent;

}

#endif // __Z_INDEX_COMPONENT_H__
