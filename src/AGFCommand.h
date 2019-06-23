//
//  AGFCommand.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFCommand_h
#define AGFCommand_h

#include "AGFCommandExecutionError.h"

namespace AGF
{
    class Command
    {
        //! @brief The type_info of this command.
        std::type_index m_type;
        
    public:
        Command(const std::type_info& type);
        
        virtual ~Command() = default;
        
        virtual void execute() = 0;
        
        virtual CommandExecutionError wait() = 0;
    };
    
    typedef std::shared_ptr<Command> CommandPtr;
}

#endif /* AGFCommand_h */
