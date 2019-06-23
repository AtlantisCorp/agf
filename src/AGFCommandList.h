//
//  AGFCommandList.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFCommandList_h
#define AGFCommandList_h

#include "AGFIncludes.h"
#include "AGFRenderTarget.h"
#include "AGFCommand.h"

namespace AGF
{
    class CommandList : public Command
    {
        //! @brief The command's list render target to execute the command to.
        RenderTargetPtr m_rendertarget;
        
        //! @brief The commands to execute in this list, by order of execution.
        std::vector < CommandPtr > m_commands;
        
        //! @brief Boolean indicating wether this command list is being executed.
        std::atomic_bool m_is_executing;
        
        //! @brief The last execution error.
        CommandExecutionError m_last_error;
        
        //! @brief Boolean indicating wether we should break when an error is spotted.
        std::atomic_bool m_break_on_error;
        
    public:
        
        CommandList(const RenderTargetPtr& target);
        
        CommandList(const CommandList& rhs);
        
        virtual ~CommandList() = default;
        
        virtual void execute();
        
        virtual CommandExecutionError wait();
        
        virtual bool isFinished() const;
        
        virtual void addCommand(const CommandPtr& command);
    };
    
    typedef std::shared_ptr<CommandList> CommandListPtr;
}

#endif /* AGFCommandList_h */
