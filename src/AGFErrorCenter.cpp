//
//  AGFErrorCenter.cpp
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#include "AGFErrorCenter.h"

namespace AGF
{
    ErrorCenter ErrorCenter::m_center;
    
    void ErrorCenter::throwError(const Error &error)
    {
#ifndef AGF_THROW_ON_ERROR
        std::lock_guard<std::mutex> lock(m_mutex);
        
        for (auto listener : m_listeners)
        {
            if (!listener.expired())
            {
                listener.lock()->onError(error);
            }
        }
#else
        throw error;
#endif
    }
    
    void ErrorCenter::Throw(const Error &error)
    {
        m_center.throwError(error);
    }
}
