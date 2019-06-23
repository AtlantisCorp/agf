//
//  AGFSize.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFSize_h
#define AGFSize_h

#include "AGFIncludes.h"

namespace AGF
{
    /** @brief Defines a floating point size with a width and a height. */
    struct Size
    {
        float width, height;
        
        Size(float w, float h): width(w), height(h) {}
    };
}

#endif /* AGFSize_h */
