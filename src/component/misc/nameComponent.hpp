//
// nameComponent.hpp
// jackbengine
//
// Created by Damien Bendejacq on 20/07/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __NAME_COMPONENT_H__
#define __NAME_COMPONENT_H__

#include "component/component.hpp"
#include "common.hpp"

namespace Jackbengine {

class NameComponent : public Component
{
public:
    NameComponent();
    ~NameComponent();

    const char* getName() const;
    void setName(const char *name);

private:
    char *m_name = nullptr;
};

} // namespace Jackbengine

#endif // __NAME_COMPONENT_H__
