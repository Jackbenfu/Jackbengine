//
//  tagComponent.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 12/05/15.
//  Copyright (c) 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __TAG_COMPONENT_H__
#define __TAG_COMPONENT_H__

#include "component/component.h"

NS_BEGIN_JKB

class TagComponent :
    public Component,
    public TypedObject<TagComponent>
{
public:
    TagComponent();
    ~TagComponent();

    const char* getTag() const;
    void setTag(const char *tag);

private:
    char *m_tag = nullptr;
};

NS_END_JKB

#endif // __TAG_COMPONENT_H__
