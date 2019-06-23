//
//  AGFIndexDescriptor.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFIndexDescriptor_h
#define AGFIndexDescriptor_h

#include "AGFIncludes.h"

namespace AGF
{
    enum class IndexElementType
    {
        Unsigned16,
        Signed16,
        
        Unsigned32,
        Signed32
    };
    
    class IndexDescriptor
    {
        IndexElementType m_type;
        std::uint32_t m_index_count;
        
    public:
        
        std::uint32_t indexCount() const;
    };
}

#endif /* AGFIndexDescriptor_h */
