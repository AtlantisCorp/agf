//
//  AGFCommandList.cpp
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#include "AGFCommandList.h"

namespace AGF
{
    CommandList::CommandList(const RenderTargetPtr& target): Command(typeid(CommandList)), m_rendertarget(target)
    {
        
    }
    
    CommandList::CommandList(const CommandList& rhs): Command(typeid(CommandList)), m_rendertarget(rhs.m_rendertarget), m_commands(rhs.m_commands)
    {
        
    }
    
    void CommandList::execute()
    {
        wait();
        
        // Launch a new thread that will wait for each command to execute freely.
        
        std::async(std::launch::async, [this](){
            m_is_executing = true;
            if (m_rendertarget)
                m_rendertarget->bind();
            
            for (auto command : m_commands)
            {
                command->execute();
                m_last_error = command->wait();
                
                if (m_last_error.isError() && m_break_on_error)
                    break;
            }
            
            m_is_executing = false;
        });
    }
    
    CommandExecutionError CommandList::wait()
    {
        while (!isFinished()) ;
        return m_last_error;
    }
    
    bool CommandList::isFinished() const
    {
        return !m_is_executing;
    }
    
    void CommandList::addCommand(const CommandPtr &command)
    {
        if (command)
            m_commands.push_back(command);
    }
}
