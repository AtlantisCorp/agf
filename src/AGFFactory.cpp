//
//  AGFFactory.cpp
//  agf
//
//  Created by jacques tronconi on 01/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#include "AGFFactory.h"

namespace AGF
{
    FactoryBase::FactoryBase(const std::type_info& info): m_type(info)
    {
        
    }
    
    bool FactoryBase::is(const std::type_info &rhs) const
    {
        return m_type == rhs;
    }
}
