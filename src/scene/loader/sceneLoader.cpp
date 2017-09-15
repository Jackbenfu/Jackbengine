//
// sceneLoader.cpp
// jackbengine
//
// Created by Damien Bendejacq on 25/07/2016.
// Copyright © 2016 Damien Bendejacq. All rights reserved.
//

#include "sceneLoader.hpp"

using namespace std;
using namespace Jackbengine;

SceneLoader::SceneLoader(Scene& scene)
    : m_scene(scene)
{
    // Nothing
}

SceneLoader::~SceneLoader() = default;

bool SceneLoader::addResourceDependency(const string& name, unsigned char *data)
{
    if (m_textResources.end() != m_textResources.find(name))
    {
        LOG_ERROR("Text resource %s already exists", name.c_str())
        return false;
    }

    m_textResources[name] = data;
    return true;
}

bool SceneLoader::addResourceDependency(const string& name, unsigned char *data, size_t dataSize)
{
    if (m_binaryResources.end() != m_binaryResources.find(name))
    {
        LOG_ERROR("Binary resource %s already exists", name.c_str())
        return false;
    }

    m_binaryResources[name] = make_pair(data, dataSize);
    return true;
}

bool SceneLoader::hasBinaryResource(const string& name) const
{
    return m_binaryResources.end() != m_binaryResources.find(name);
}

const pair<unsigned char*, size_t>* SceneLoader::binaryResource(const string& name)
{
    if (!hasBinaryResource(name))
    {
        LOG_ERROR("Binary resource %s does not exist", name.c_str());
        return nullptr;
    }

    return &m_binaryResources[name];
}

Scene& SceneLoader::scene() const
{
    return m_scene;
}
