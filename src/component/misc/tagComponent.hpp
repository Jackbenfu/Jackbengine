//
// tagComponent.hpp
// jackbengine
//
// Created by Damien Bendejacq on 12/05/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __TAG_COMPONENT_H__
#define __TAG_COMPONENT_H__

#include "component/component.hpp"

namespace Jackbengine {

class TagComponent : public Component
{
public:
    TagComponent();
    ~TagComponent();

    const char* getTag() const;
    void setTag(const char *tag);

private:
    char *m_tag = nullptr;
};

} // namespace Jackbengine

#endif // __TAG_COMPONENT_H__
