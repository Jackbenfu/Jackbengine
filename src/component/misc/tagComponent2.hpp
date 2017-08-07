//
// tagComponent2.hpp
// jackbengine
//
// Created by Damien Bendejacq on 29/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __TAG_COMPONENT_2_H__
#define __TAG_COMPONENT_2_H__

#include "component/generic/stringComponent.hpp"

namespace Jackbengine {

class TagComponent2 : public Component2
{
    DISALLOW_COPY_AND_MOVE(TagComponent2)

public:
    explicit TagComponent2(const std::string& tag);
    ~TagComponent2() override = default;

    const std::string& get() const;
    void set(const std::string& tag);

private:
    StringComponent m_value;
};

} // namespace Jackbengine

#endif // __TAG_COMPONENT_2_H__
