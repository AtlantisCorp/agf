//
//  AGFModuleManager.cpp
//  agf
//
//  Created by jacques tronconi on 07/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#include "AGFModuleManager.h"

namespace AGF
{
    ModuleManager::ModuleManager(std::vector < std::string > const& dirs, ErrorManager& errmanager)
    : m_modulesDirs(dirs), m_errManager(errmanager)
    {
        
    }
    
    std::uint32_t ModuleManager::fillLibrary(FileLoaderLibrary &library) const
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        std::uint32_t loaders_loaded = 0;
        
        for (auto module : m_modules)
        {
            loaders_loaded += module->fillLibrary(library);
        }
        
        return loaders_loaded;
    }
}
