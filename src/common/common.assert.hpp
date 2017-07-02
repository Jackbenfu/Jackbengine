//
// common.assert.hpp
// jackbengine
//
// Created by Damien Bendejacq on 30/06/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __COMMON_ASSERT_H__
#define __COMMON_ASSERT_H__

namespace Jackbengine {

#define ASSERT_IS_BASE_OF(Base, Derived)    static_assert(std::is_base_of<Base, Derived>::value)

} // namespace Jackbengine

#endif // __COMMON_ASSERT_H__
