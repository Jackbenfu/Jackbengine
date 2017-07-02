//
// genericComponent.hpp
// jackbengine
//
// Created by Damien Bendejacq on 06/07/15.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __GENERIC_COMPONENT_H__
#define __GENERIC_COMPONENT_H__

#include "component/component.hpp"

namespace Jackbengine {

template<typename T>
class GenericComponent : public Component
{
public:
    T get() const;
    void set(T value);

    void increment(T by);
    void decrement(T by);

private:
    T _value;
};

using ByteComponent = GenericComponent<byte>;
using IntComponent = GenericComponent<int>;
using UintComponent = GenericComponent<uint>;
using FloatComponent = GenericComponent<float>;

#include "genericComponent.tpp"

} // namespace Jackbengine

#endif // __GENERIC_COMPONENT_H__
