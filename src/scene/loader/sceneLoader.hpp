//
// sceneLoader.hpp
// jackbengine
//
// Created by Damien Bendejacq on 25/07/2016.
// Copyright © 2016 Damien Bendejacq. All rights reserved.
//

#ifndef __SCENE_LOADER_H__
#define __SCENE_LOADER_H__

#include <map>
#include <string>

#include "scene/scene.hpp"

namespace Jackbengine {

class SceneLoader
{
public:
    explicit SceneLoader(Scene& scene);
    virtual ~SceneLoader();

    virtual bool loadContents() = 0;

    Scene& scene() const;

    bool hasBinaryResource(const std::string& name) const;
    const std::pair<unsigned char*, size_t>* binaryResource(const std::string& name);

    bool addResourceDependency(const std::string& name, unsigned char *data);
    bool addResourceDependency(const std::string& name, unsigned char *data, size_t dataSize);

private:
    std::map<std::string, unsigned char*> m_textResources;
    std::map<std::string, std::pair<unsigned char*, size_t>> m_binaryResources;

    Scene& m_scene;
};

} // namespace Jackbengine

#endif // __SCENE_LOADER_H__
