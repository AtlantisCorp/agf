//
//  AGFDrawIndexedCommand.cpp
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#include "AGFDrawIndexedCommand.h"

namespace AGF
{
    DrawIndexedCommand::DrawIndexedCommand(const IndexDescriptor& indDesc, const BufferPtr& indBuffer, const VertexDescriptor& vertDesc, const BufferPtr& vertBuff): Command(typeid(DrawIndexedCommand))
    {
        m_vertexes = vertBuff;
        m_vert_descriptor = vertDesc;
        m_indexes = indBuffer;
        m_ind_descriptor = indDesc;
    }
}
