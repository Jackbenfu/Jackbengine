//
// nameComponent2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 29/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __NAME_COMPONENT_2_H__
#define __NAME_COMPONENT_2_H__

#include "component/generic/stringComponent.hpp"

namespace Jackbengine {

class NameComponent2 : public Component2
{
    DISALLOW_COPY_AND_MOVE(NameComponent2)

public:
    explicit NameComponent2(const std::string& name);
    ~NameComponent2() override = default;

    const std::string& get() const;
    void set(const std::string& name);

private:
    StringComponent m_value;
};

} // namespace Jackbengine

#endif // __NAME_COMPONENT_2_H__
