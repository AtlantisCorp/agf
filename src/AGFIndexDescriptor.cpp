//
//  AGFIndexDescriptor.cpp
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#include "AGFIndexDescriptor.h"

namespace AGF
{
    std::uint32_t IndexDescriptor::indexCount() const
    {
        return m_index_count;
    }
}
