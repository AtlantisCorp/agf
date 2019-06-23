//
//  AGFFileLoader.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFFileLoader_h
#define AGFFileLoader_h

#include "AGFIncludes.h"

namespace AGF
{
    class FileLoader
    {
    public:
        virtual ~FileLoader() = default;
        
        virtual std::string category() const = 0;
        
        virtual std::vector < std::string > supportedExtensions() const = 0;
        
        virtual std::string name() = 0;
    };
    
    typedef std::shared_ptr<FileLoader> FileLoaderPtr;
}

#endif /* AGFFileLoader_h */
