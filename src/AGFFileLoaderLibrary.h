//
//  AGFFileLoaderLibrary.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFFileLoaderLibrary_h
#define AGFFileLoaderLibrary_h

#include "AGFFileLoader.h"

namespace AGF
{
    class FileLoaderLibrary
    {
        std::vector < FileLoaderPtr > m_fileloaders;
        mutable std::mutex m_mutex;
        
    public:
        
        FileLoaderLibrary() = default;
        
        virtual ~FileLoaderLibrary() = default;
        
        virtual void addLoader(const FileLoaderPtr& loader);
        
        virtual void removeLoader(const std::string& name);
        
        virtual FileLoaderPtr findLoader(const std::string& name);
        
        virtual void reset();
        
        template < typename T >
        std::shared_ptr<T> findLoader(const std::string& name)
        {
            FileLoaderPtr found = findLoader(name);
            return details::reinterpret_pointer_cast<T>(found);
        }
    };
}

#endif /* AGFFileLoaderLibrary_h */
