//
//  AGFModule.h
//  agf
//
//  Created by jacques tronconi on 07/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFModule_h
#define AGFModule_h

#include "AGFIncludes.h"
#include "AGFFactory.h"
#include "AGFFileLoaderLibrary.h"

namespace AGF
{
    class Module
    {
    public:
        
        virtual bool has(const std::type_info&) const;
        
        template < class Class, typename... Args >
        std::shared_ptr<Class> initialize(Args&&... args)
        {
            auto factory = reinterpret_cast < Factory<Class>* >(factoryOf(typeid(Class)));
            assert(factory && "Null factory. Did you call Module::has() before?");
            return factory->initialize(std::forward<Args>(args)...);
        }
        
        virtual FactoryBase* factoryOf(const std::type_info&) = 0;
        
        virtual const FactoryBase* factoryOf(const std::type_info& info) const;
        
        virtual std::uint32_t fillLibrary(FileLoaderLibrary& library) const;
    };
}

#endif /* AGFModule_h */
