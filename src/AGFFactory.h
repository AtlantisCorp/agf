//
//  AGFFactory.h
//  agf
//
//  Created by jacques tronconi on 01/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFFactory_h
#define AGFFactory_h

#include "AGFIncludes.h"

namespace AGF
{
    /** @brief Defines a base structure for a factory. */
    class FactoryBase
    {
        //! @brief The type that this factory should create.
        std::type_index m_type;
        
    public:
        /** @brief Constructs a new factory. */
        FactoryBase(const std::type_info& info);
        
        /** @brief Returns true if this factory creates the given type. */
        bool is(const std::type_info& rhs) const;
    };
    
    /** @brief Templated class for all factories. */
    template < class Class >
    struct Factory : public FactoryBase {
        Factory(): FactoryBase(typeid(Class)) { }
    };
}

#endif /* AGFFactory_h */
