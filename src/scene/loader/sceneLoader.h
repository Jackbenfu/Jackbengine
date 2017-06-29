//
// loader.h
// jackbengine
//
// Created by Damien Bendejacq on 25/07/2016.
// Copyright © 2016 Damien Bendejacq. All rights reserved.
//

#ifndef __SCENE_LOADER_H__
#define __SCENE_LOADER_H__

#include <map>
#include <string>

#include "scene/scene.h"

NS_BEGIN_JKB
NS_STD

class SceneLoader
{
public:
    explicit SceneLoader(Scene *scene);
    virtual ~SceneLoader();

    virtual bool loadContents() = 0;

    Scene* scene() const;

    bool hasBinaryResource(const string& name) const;
    const pair<unsigned char*, size_t>* getBinaryResource(const string& name);

    bool addResourceDependency(const string& name, unsigned char *data);
    bool addResourceDependency(const string& name, unsigned char *data, size_t dataSize);

private:
    map<string, unsigned char*> m_textResources;
    map<string, pair<unsigned char*, size_t>> m_binaryResources;

    Scene *m_scene {nullptr};
};

NS_END_JKB

#endif // __SCENE_LOADER_H__
