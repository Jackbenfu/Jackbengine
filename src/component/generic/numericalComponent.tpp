//
// numericalComponent.tpp
// jackbengine
//
// Created by Damien Bendejacq on 29/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __NUMERICAL_COMPONENT_TPP__
#define __NUMERICAL_COMPONENT_TPP__

template <typename T>
T NumericalComponent<T>::get() const
{
    return m_value;
}

template <typename T>
void NumericalComponent<T>::set(T value)
{
    m_value = value;
}

template <typename T>
void NumericalComponent<T>::increment(T by)
{
    m_value += by;
}

template <typename T>
void NumericalComponent<T>::decrement(T by)
{
    m_value -= by;
}

#endif // __NUMERICAL_COMPONENT_TPP__
