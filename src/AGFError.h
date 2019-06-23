//
//  AGFError.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFError_h
#define AGFError_h

#include "AGFIncludes.h"

namespace AGF
{
    /** @brief Defines a basic error message. */
    class Error : public std::exception
    {
        //! @brief The id of the error. This identifier is unique to the error emitted.
        std::uint64_t m_id;
        
        //! @brief The emitter of the error. This is the class that sent this error primarly.
        std::string m_emitter;
        
        //! @brief The message associated to this error.
        std::string m_message;
        
    public:
        /** @brief Constructs a new Error. */
        Error(const std::string& emitter, const std::string& message);
        
        /** @brief Copy constructor. */
        Error(const Error&) = default;
        
        /** @brief Move constructor. */
        Error(Error&&) = default;
        
        /** @brief Returns a new id for a new error. */
        static std::uint64_t NewId();
        
        /** @brief Returns the id of this error. */
        std::uint64_t id() const;
        
        /** @brief Returns the emitter of this error. */
        const std::string& emitter() const;
        
        /** @brief Returns the message from this error. */
        const char* what() const noexcept;
    };
}

#endif /* AGFError_h */
