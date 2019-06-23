//
//  AGFErrorCenter.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFErrorCenter_h
#define AGFErrorCenter_h

#include "AGFErrorListener.h"

namespace AGF
{
    /** @brief A center that handles global errors. */
    class ErrorCenter
    {
        //! @brief The instance of the error center.
        static ErrorCenter m_center;
        
        //! @brief The listeners that do something when an error is thrown.
        std::vector < std::weak_ptr < ErrorListener > > m_listeners;
        
        //! @brief Protects the listeners.
        mutable std::mutex m_mutex;
        
    public:
        /** @brief Default destructor. */
        ~ErrorCenter() = default;
        
        /** @brief Throws an error to the listeners.
         *  If AGF_THROW_ON_ERROR is set, uses the throw mechanism to throw the error.
         */
        void throwError(const Error& error);
        
        /** @brief Throws an error with the default center. */
        static void Throw(const Error& error);
    };
}

#endif /* AGFErrorCenter_h */
