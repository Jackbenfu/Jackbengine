//
// common.h
// jackbengine
//
// Created by Damien Bendejacq on 28/01/2015.
// Copyright © 2015 Damien Bendejacq. All rights reserved.
//

#ifndef __COMMON_H__
#define __COMMON_H__

namespace Jackbengine {

#define GET_TYPE_ID(T)      typeid(T).hash_code()
#define GET_TYPE_NAME(T)    typeid(T).name()

}

#endif // __COMMON_H__
