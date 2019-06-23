//
//  AGFDrawCommand.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFDrawCommand_h
#define AGFDrawCommand_h

#include "AGFVertexDescriptor.h"
#include "AGFBuffer.h"

namespace AGF
{
    class DrawCommand : public Command
    {
        BufferPtr m_vertexes;
        VertexDescriptor m_vert_descriptor;
        
    public:
        
        DrawCommand(const VertexDescriptor& vertDesc, const BufferPtr& vertBuffer);
    };
}

#endif /* AGFDrawCommand_h */
