//
//  AGFCommandExecutionError.cpp
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#include "AGFCommandExecutionError.h"

namespace AGF
{
    CommandExecutionError::CommandExecutionError(): m_is_error(false), m_error_type(0)
    {
        
    }
    
    CommandExecutionError::CommandExecutionError(std::uint32_t type, const std::string& message): m_is_error(true), m_error_type(type), m_error_message(message)
    {
        
    }
    
    bool CommandExecutionError::isError() const
    {
        return m_is_error;
    }
    
    std::uint32_t CommandExecutionError::type() const
    {
        return m_error_type;
    }
    
    std::string CommandExecutionError::message() const
    {
        return m_error_message;
    }
}
