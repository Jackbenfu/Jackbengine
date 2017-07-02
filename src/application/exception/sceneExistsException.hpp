//
// sceneExistsException.hpp
// jackbengine
//
// Created by Damien Bendejacq on 30/06/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SCENE_EXISTS_EXCEPTION_H__
#define __SCENE_EXISTS_EXCEPTION_H__

#include "common.hpp"

template<typename TScene>
class SceneExistsException : public std::exception
{
public:
    SceneExistsException<TScene>()
        : typeInfo(typeid(TScene))
    {
        // Nothing
    }

    virtual ~SceneExistsException() throw() = default;

    virtual const char* what() const throw()
    {
        return typeInfo.name();
    }

private:
    const std::type_info& typeInfo;
};

#endif // __SCENE_EXISTS_EXCEPTION_H__
