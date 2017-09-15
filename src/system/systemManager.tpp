//
// systemManager.tpp
// jackbengine
//
// Created by Damien Bendejacq on 25/07/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __SYSTEM_MANAGER_TPP__
#define __SYSTEM_MANAGER_TPP__

template<typename TSystem, typename ...Args>
void SystemManager::addSystem(Args&& ...args)
{
    m_systems.add<TSystem>(std::forward<Args>(args)...);
}

template<typename TSystem>
void SystemManager::removeSystem()
{
    m_systems.remove<TSystem>();
}

template<typename TSystem>
void SystemManager::enableSystem()
{
    m_systems.enable<TSystem>();
}

template<typename TSystem>
void SystemManager::disableSystem()
{
    m_systems.disable<TSystem>();
}

#endif // __SYSTEM_MANAGER_TPP__
