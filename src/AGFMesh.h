//
//  AGFMesh.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFMesh_h
#define AGFMesh_h

#include "AGFGeometry.h"
#include "AGFCommand.h"
#include "AGFFileLoader.h"
#include "AGFVariant.h"
#include "AGFResult.h"

namespace AGF
{
    class Driver;
    
    class Mesh
    {
        std::vector < GeometryPtr > m_geometries;
        mutable std::mutex m_mutex;
        
    public:
        
        //! @brief Makes a new Command that will draw this mesh for the specified driver.
        Result < CommandPtr > makeCommand(Driver&);
    };
    
    typedef std::shared_ptr<Mesh> MeshPtr;
    
    class MeshLoader : public FileLoader
    {
    public:
        virtual ~MeshLoader() = default;
        
        virtual MeshPtr load(const std::string& name, const std::string& file, const Dictionnary& args) = 0;
        
        std::string category() const;
    };
}

#endif /* AGFMesh_h */
