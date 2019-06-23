//
//  AGFIncludes.h
//  agf
//
//  Created by jacques tronconi on 01/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFIncludes_h
#define AGFIncludes_h

#include <stdio.h>
#include <iostream>
#include <atomic>
#include <memory>
#include <future>
#include <vector>
#include <string>
#include <mutex>
#include <typeinfo>
#include <typeindex>
#include <cstdarg>
#include <map>
#include <type_traits>
#include <exception>
#include <algorithm>

namespace AGF
{
    namespace details
    {
        /** @brief Creates a new instance of std::shared_ptr whose stored pointer is obtained from r's stored pointer
         *  using a cast expression.
         *
         *  If r is empty, so is the new shared_ptr (but its stored pointer is not necessarily null). Otherwise, the new
         *  shared_ptr will share ownership with the initial value of r, except that it is empty if the dynamic_cast
         *  performed by dynamic_pointer_cast returns a null pointer.
         */
        template< class T, class U >
        std::shared_ptr<T> reinterpret_pointer_cast( const std::shared_ptr<U>& r ) noexcept
        {
            auto p = reinterpret_cast<typename std::shared_ptr<T>::element_type*>(r.get());
            return std::shared_ptr<T>(r, p);
        }
    }
}

#endif /* AGFIncludes_h */
