//
// genericComponent.tpp
// jackbengine
//
// Created by Damien Bendejacq on 30/06/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __GENERIC_COMPONENT_TPP__
#define __GENERIC_COMPONENT_TPP__

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

#endif // __GENERIC_COMPONENT_TPP__
