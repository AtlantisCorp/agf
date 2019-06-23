//
//  AGFError.cpp
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#include "AGFError.h"

namespace AGF
{
    Error::Error(const std::string& emitter, const std::string& message): m_id(NewId()), m_emitter(emitter), m_message(message)
    {
        
    }
    
    std::uint64_t Error::NewId()
    {
        static std::atomic < std::uint64_t > current_id(0);
        return current_id.fetch_add(1);
    }
    
    std::uint64_t Error::id() const
    {
        return m_id;
    }
    
    const std::string& Error::emitter() const
    {
        return m_emitter;
    }
    
    const char* Error::what() const noexcept
    {
        return m_message.data();
    }
}
