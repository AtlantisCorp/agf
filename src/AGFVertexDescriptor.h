//
//  AGFVertexDescriptor.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFVertexDescriptor_h
#define AGFVertexDescriptor_h

#include "AGFIncludes.h"

namespace AGF
{
    enum class VertexElementType
    {
        Float,
        Double,
        
        Unsigned,
        Signed,
        
        FloatMat2x2,
        FloatMat2x3,
        FloatMat2x4,
        FloatMat3x2,
        FloatMat3x3,
        FloatMat3x4,
        FloatMat4x2,
        FloatMat4x3,
        FloatMat4x4
    };
    
    class VertexElement
    {
        VertexElementType m_type;
        std::uint8_t m_element_count;
        std::string m_element_role;
        bool m_is_normalized;
    };
    
    class VertexDescriptor
    {
        std::vector < VertexElement > m_elements;
        std::size_t m_vertexes_count;
        
    public:
        
        std::size_t count() const;
    };
}

#endif /* AGFVertexDescriptor_h */
