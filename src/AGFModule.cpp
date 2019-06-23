//
//  AGFModule.cpp
//  agf
//
//  Created by jacques tronconi on 07/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#include "AGFModule.h"

namespace AGF
{
    bool Module::has(const std::type_info& info) const
    {
        return factoryOf(info) != nullptr;
    }
    
    const FactoryBase* Module::factoryOf(const std::type_info &info) const
    {
        return const_cast<Module*>(this)->factoryOf(info);
    }
    
    std::uint32_t Module::fillLibrary(FileLoaderLibrary &) const
    {
        return 0;
    }
}
