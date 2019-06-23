//
//  AGFMesh.cpp
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#include "AGFMesh.h"
#include "AGFDriver.h"
#include "AGFCommandList.h"

#include "AGFErrorCenter.h"

namespace AGF
{
    Result < CommandPtr > Mesh::makeCommand(Driver& driver)
    {
        CommandListPtr command = std::make_shared<CommandList>(nullptr);
        std::lock_guard<std::mutex> lock(m_mutex);
        
        for (auto geometry : m_geometries)
        {
            if (geometry->isIndexed())
            {
                auto subcommand = driver.makeDrawIndexedCommand(geometry->vertexDescriptor(),
                                                                geometry->vertexBuffer(),
                                                                geometry->indexDescriptor(),
                                                                geometry->indexBuffer());
                
                
                
                if (!subcommand.isValid())
                {
                    ErrorCenter::Throw(subcommand.error());
                    return Result < CommandPtr >(nullptr);
                }
                
                command->addCommand(details::reinterpret_pointer_cast<Command>(subcommand.get()));
            }
            
            else if (geometry->hasVertexes())
            {
                auto subcommand = driver.makeDrawCommand(geometry->vertexDescriptor(), geometry->vertexBuffer());
                
                if (subcommand.isError())
                {
                    ErrorCenter::Throw(subcommand.error());
                    return Result < CommandPtr >(nullptr);
                }
                
                command->addCommand(details::reinterpret_pointer_cast<Command>(subcommand.get()));
            }
        }
        
        return details::reinterpret_pointer_cast<Command>(command);
    }
    
    std::string MeshLoader::category() const
    {
        return "Mesh";
    }
}
