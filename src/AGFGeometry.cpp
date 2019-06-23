//
//  AGFGeometry.cpp
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#include "AGFGeometry.h"

namespace AGF
{
    IndexDescriptor Geometry::indexDescriptor() const
    {
        return m_ind_descriptor;
    }
    
    BufferPtr Geometry::indexBuffer() const
    {
        return m_indexes;
    }
    
    VertexDescriptor Geometry::vertexDescriptor() const
    {
        return m_vert_descriptor;
    }
    
    BufferPtr Geometry::vertexBuffer() const
    {
        return m_vertexes;
    }
    
    bool Geometry::isIndexed() const
    {
        return m_ind_descriptor.indexCount() > 0;
    }
    
    bool Geometry::hasVertexes() const
    {
        return m_vert_descriptor.count() > 0;
    }
}
