//
//  AGFErrorListener.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFErrorListener_h
#define AGFErrorListener_h

#include "AGFError.h"

namespace AGF
{
    /** @brief A simple listener that listen to errors. */
    class ErrorListener
    {
    public:
        /** @brief Default destructor. */
        virtual ~ErrorListener() = default;
        
        /** @brief Handles an error. */
        virtual void onError(const Error& error) {}
    };
}

#endif /* AGFErrorListener_h */
