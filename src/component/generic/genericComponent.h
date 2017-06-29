//
// genericComponent.h
// jackbengine
//
// Created by Damien Bendejacq on 06/07/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __GENERIC_COMPONENT_H__
#define __GENERIC_COMPONENT_H__

#include "component/component.h"
#include "common.h"

template<typename T>
class GenericComponent :
    public Component,
    public TypedObject<GenericComponent<T>>
{
public:
    GenericComponent() { }
    ~GenericComponent() { }

    T get() const;
    void set(T value);

    void increment(T by);
    void decrement(T by);

private:
    T _value;
};

template <typename T>
T GenericComponent<T>::get() const
{
    return _value;
}

template <typename T>
void GenericComponent<T>::set(T value)
{
    _value = value;
}

template <typename T>
void GenericComponent<T>::increment(T by)
{
    _value += by;
}

template <typename T>
void GenericComponent<T>::decrement(T by)
{
    _value -= by;
}

using ByteComponent = GenericComponent<byte>;
using IntComponent = GenericComponent<int>;
using UintComponent = GenericComponent<uint>;
using FloatComponent = GenericComponent<float>;

#endif // __GENERIC_COMPONENT_H__
