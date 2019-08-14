//
// common.macro.h
// jackbengine
//
// Created by Damien Bendejacq on 29/06/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __COMMON_MACRO_H__
#define __COMMON_MACRO_H__

namespace Jackbengine {

#define GET_TYPE_ID(T)      typeid(T).hash_code()
#define GET_TYPE_NAME(T)    typeid(T).name()

}

#endif // __COMMON_MACRO_H__
