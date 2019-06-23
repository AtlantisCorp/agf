//
//  AGFResult.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFResult_h
#define AGFResult_h

#include "AGFError.h"

namespace AGF
{
    /** @brief Defines a class that englobates an object OR an error but never both. */
    template < typename T >
    class Result
    {
        union
        {
            //! @brief The value of the result, if valid.
            T m_value;
            
            //! @brief The error of the result, if invalid.
            Error m_error;
        };
        
        //! @brief Boolean indicating if we have an error or a value.
        bool m_is_error;
        
    public:
        
        /** @brief Default constructor. */
        Result(const T& value): m_is_error(false)
        {
            new(&m_value) T(value);
        }
        
        /** @brief Constructs from a moved object. */
        Result(T&& value): m_is_error(false), m_value(std::move(value))
        {
            
        }
        
        /** @brief Constructs from an error. */
        Result(const Error& error): m_is_error(true)
        {
            new(&m_error) Error(error);
        }
        
        /** @brief Copy constructor. */
        Result(const Result& rhs): m_is_error(rhs.m_is_error)
        {
            if (m_is_error) new(&m_error) Error(rhs.m_error);
            else new(&m_value) T(rhs.m_value);
        }
        
        /** @brief Move constructor. */
        Result(Result&& rhs): m_is_error(std::move(rhs.m_is_error))
        {
            if (m_is_error) new(&m_error) Error(std::move(rhs.m_error));
            else new(&m_value) T(std::move(rhs.m_value));
        }
        
        /** @brief Default destructor. */
        ~Result()
        {
            
        }
        
        /** @brief Returns true if this result is an error. */
        bool isError() const
        {
            return m_is_error;
        }
        
        /** @brief Returns true if this result is not an error. */
        bool isValid() const
        {
            return !m_is_error;
        }
        
        /** @brief Returns the error. */
        const Error& error() const
        {
            return m_error;
        }
        
        /** @brief Returns the value. */
        T& get()
        {
            return m_value;
        }
        
        /** @brief Returns the value. */
        const T& get() const
        {
            return m_value;
        }
    };
}

#endif /* AGFResult_h */
