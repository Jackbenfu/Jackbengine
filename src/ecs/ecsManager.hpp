//
// ecsManager.hpp
// jackbengine
//
// Created by Damien Bendejacq on 17/09/2016.
// Copyright © 2016 Damien Bendejacq. All rights reserved.
//

#ifndef __ECS_MANAGER_H__
#define __ECS_MANAGER_H__

#include <vector>
#include "entity/entity.hpp"
#include "system/system.hpp"

namespace Jackbengine {

class EcsManager
{
public:
    EcsManager();
    ~EcsManager();

    // Entity
    bool isEntityEnabled(Entity *entity) const;
    Entity* getEntity(const char *name) const;
    Entity* addEntity(const char *name);
    bool removeEntity(Entity *entity);
    bool removeEntity(const char *name);
    void enableEntity(Entity *entity);
    void enableEntity(const char *name);
    void disableEntity(Entity *entity);
    void disableEntity(const char *name);

    // Component
    template<typename TComponent> TComponent* getComponent(Entity *entity, bool returnIfDisabled = true) const;
    template<typename TComponent> TComponent* getComponentIfEnabled(Entity *entity) const;
    template<typename TComponent> TComponent* addComponent(Entity *entity);
    template<typename TComponent, typename TParam> TComponent* addComponent(Entity *entity, TParam param);
    template<typename TComponent> bool setComponent(Entity *entity, TComponent *component);
    template<typename TComponent> bool removeComponent(Entity *entity) const;
    template<typename TComponent> bool enableComponent(Entity *entity) const;
    template<typename TComponent> bool disableComponent(Entity *entity) const;

    // System
    template<typename TSystem> TSystem* getSystem();
    template<typename TSystem> TSystem* addSystem();
    template<typename TSystem> void removeSystem();
    template<typename TSystem> void enableSystem();
    template<typename TSystem> void disableSystem();

    void update(float delta);

    void clear();

private:
    std::vector<Entity*> m_entities;
    std::vector<System*> m_systems;
    std::vector<size_t> m_systemTypes;

    std::vector<Entity*>::iterator getEntityIteratorByPtr(Entity *entity);
    std::vector<Entity*>::const_iterator getEntityIteratorByName(const char *name) const;
    std::vector<Entity*>::iterator getEntityIteratorByName(const char *name);
};

#include "ecsManager.tpp"

} // namespace Jackbengine

#endif // __ECS_MANAGER_H__
