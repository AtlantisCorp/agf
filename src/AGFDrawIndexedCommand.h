//
//  AGFDrawIndexedCommand.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFDrawIndexedCommand_h
#define AGFDrawIndexedCommand_h

#include "AGFCommand.h"
#include "AGFBuffer.h"
#include "AGFVertexDescriptor.h"
#include "AGFIndexDescriptor.h"

namespace AGF
{
    class DrawIndexedCommand : public Command
    {
        BufferPtr m_vertexes;
        VertexDescriptor m_vert_descriptor;
        BufferPtr m_indexes;
        IndexDescriptor m_ind_descriptor;
        
    public:
        
        DrawIndexedCommand(const IndexDescriptor& indDesc, const BufferPtr& indBuffer, const VertexDescriptor& vertDesc, const BufferPtr& vertBuff);
    };
}

#endif /* AGFDrawIndexedCommand_h */
