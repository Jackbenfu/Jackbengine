//
// numericalComponent.hpp
// jackbengine
//
// Created by Damien Bendejacq on 29/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __NUMERICAL_COMPONENT_H__
#define __NUMERICAL_COMPONENT_H__

#include "component/component2.hpp"

namespace Jackbengine {

template<typename T>
class NumericalComponent : public Component2
{
    static_assert(std::is_arithmetic<T>::value);

    DISALLOW_COPY_AND_MOVE(NumericalComponent)

public:
    NumericalComponent(T value);
    ~NumericalComponent() override = default;

    T get() const;
    void set(T value);

    void increment(T by);
    void decrement(T by);

private:
    T m_value;
};

template<typename T>
using Numerical = NumericalComponent<T>;

#include "numericalComponent.tpp"

} // namespace Jackbengine

#endif // __NUMERICAL_COMPONENT_H__
