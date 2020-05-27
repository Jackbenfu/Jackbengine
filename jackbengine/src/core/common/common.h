//
// common.h
// jackbengine
//
// Created by Damien Bendejacq on 28/01/2015.
//

#ifndef __COMMON_H__
#define __COMMON_H__

namespace Jackbengine {

#define GET_TYPE_ID(T)      typeid(T).hash_code()
#define GET_TYPE_NAME(T)    typeid(T).name()

#define TOKENPASTE_(x, y)   x##y
#define TOKENPASTE(x, y)    TOKENPASTE_(x, y)

}

#endif // __COMMON_H__
