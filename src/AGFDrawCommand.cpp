//
//  AGFDrawCommand.cpp
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#include "AGFDrawCommand.h"

namespace AGF
{
    DrawCommand::DrawCommand(const VertexDescriptor& vertDesc, const BufferPtr& vertBuffer): Command(typeid(DrawCommand))
    {
        m_vertexes = vertBuffer;
        m_vert_descriptor = vertDesc;
    }
}
