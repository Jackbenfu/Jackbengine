//
// abstractApplication.h
// jackbengine
//
// Created by Damien Bendejacq on 12/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __ABSTRACT_APPLICATION_H__
#define __ABSTRACT_APPLICATION_H__

#include "common/common.h"

namespace Jackbengine {

class AbstractApplication
{
public:
    AbstractApplication();
    virtual ~AbstractApplication();

private:
    static void initSDL();
};

}

#endif // __ABSTRACT_APPLICATION_H__
