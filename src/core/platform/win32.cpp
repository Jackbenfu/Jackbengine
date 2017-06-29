//
// win32.cpp
// jackbengine
//
// Created by Damien Bendejacq on 31/05/16.
// Copyright © 2016 Damien Bendejacq. All rights reserved.
//

#include "win32.h"

char* strdup(const char *str)
{
    size_t len = strlen(str) + 1;
    char *copy = (char*)malloc(len);

    if (NULL == copy)
    {
        return NULL;
    }

    memcpy(copy, str, len);
    copy[len] = 0;

    return copy;
}
