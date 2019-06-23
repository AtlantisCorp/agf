//
//  AGFSurface.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFSurface_h
#define AGFSurface_h

#include "AGFIncludes.h"
#include "AGFRenderTarget.h"
#include "AGFPixFormat.h"

namespace AGF
{
    enum SurfaceAttributes
    {
        SADefault
    };
    
    /** @brief Defines a surface where the user can draw something on the screen. */
    class Surface : public RenderTarget
    {
        
    };
    
    typedef std::shared_ptr<Surface> SurfacePtr;
    
    /** @brief The factory that creates a new surface. */
    template < > struct Factory < Surface > : public FactoryBase {
        Factory(): FactoryBase(typeid(Surface)) {}
        virtual ~Factory() = default;
        virtual SurfacePtr initialize(const std::string& title, const Size& size,
                                      PixFormat color, PixFormat depth,
                                      bool multisampled, short samples, short sampbuffers,
                                      unsigned mask) = 0;
    };
}

#endif /* AGFSurface_h */
