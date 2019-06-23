//
//  AGFGeometry.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFGeometry_h
#define AGFGeometry_h

#include "AGFBuffer.h"
#include "AGFVertexDescriptor.h"
#include "AGFIndexDescriptor.h"

namespace AGF
{
    class Geometry
    {
        BufferPtr m_vertexes;
        VertexDescriptor m_vert_descriptor;
        BufferPtr m_indexes;
        IndexDescriptor m_ind_descriptor;
        
    public:
        
        bool isIndexed() const;
        
        IndexDescriptor indexDescriptor() const;
        
        BufferPtr indexBuffer() const;
        
        VertexDescriptor vertexDescriptor() const;
        
        BufferPtr vertexBuffer() const;
        
        bool hasVertexes() const;
    };
    
    typedef std::shared_ptr<Geometry> GeometryPtr;
}

#endif /* AGFGeometry_h */
