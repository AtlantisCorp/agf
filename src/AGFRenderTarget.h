//
//  AGFRenderTarget.h
//  agf
//
//  Created by jacques tronconi on 01/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFRenderTarget_h
#define AGFRenderTarget_h

#include "AGFIncludes.h"

namespace AGF
{
    /** @brief Defines a target where something can be draw into.
     *  The render target must be bound before using it.
     */
    class RenderTarget
    {
    public:
        /** @brief Default destructor. */
        virtual ~RenderTarget() = default;
        
        /** @brief Binds the render target. */
        virtual void bind() const = 0;
    };
    
    typedef std::shared_ptr<RenderTarget> RenderTargetPtr;
}

#endif /* AGFRenderTarget_h */
