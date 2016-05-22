//
//  typedObject.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 20/02/2016.
//  Copyright (c) 2016 Damien Bendejacq. All rights reserved.
//

#ifndef __TYPED_OBJECT_H__
#define __TYPED_OBJECT_H__

#include "common.h"
#include <typeinfo>

template<typename T>
class TypedObject
{
public:
    static uint getType()
    {
        static uint type = (uint)typeid(T).hash_code();
        return type;
    }
};

#endif // __TYPED_OBJECT_H__
