//
//  AGFCommandExecutionError.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFCommandExecutionError_h
#define AGFCommandExecutionError_h

#include "AGFIncludes.h"

namespace AGF
{
    class CommandExecutionError
    {
        bool m_is_error;
        
        std::uint32_t m_error_type;
        
        std::string m_error_message;
        
    public:
        
        CommandExecutionError();
        
        CommandExecutionError(std::uint32_t type, const std::string& message);
        
        bool isError() const;
        
        std::uint32_t type() const;
        
        std::string message() const;
    };
}

#endif /* AGFCommandExecutionError_h */
