//
//  AGFErrorManager.h
//  agf
//
//  Created by jacques tronconi on 01/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFErrorManager_h
#define AGFErrorManager_h

#include "AGFIncludes.h"

namespace AGF
{
    /** @brief Defines an error handler. */
    class ErrorManager
    {
    public:
        /** @brief Default destructor. */
        virtual ~ErrorManager() = default;
        
        /** @brief Handles an error.
         *
         *  @param clss
         *  The class that emits this error.
         *  @param type
         *  The custom type for this error.
         *  @param message
         *  The message associated to this error.
         */
        virtual void onError(const char* clss, const char* type, const char* message) = 0;
        
        /** @brief Formats a string with vsnprintf and returns a std string. */
        virtual std::string format(const char* f, ...);
    };
    
    /** @brief Defines a handler that outputs the error to a stream. */
    class OstreamErrorManager : public ErrorManager
    {
        //! @brief The stream to output the error.
        std::ostream& m_output;
        //! @brief Protects the stream from data race.
        std::mutex m_mutex;
        
    public:
        /** @brief Constructs the handler with a stream. */
        OstreamErrorManager(std::ostream& output);
        
        /** @brief Destructs the handler and flush the stream. */
        virtual ~OstreamErrorManager();
        
        /** @brief Writes the error to the stream. */
        virtual void onError(const char* clss, const char* type, const char* message);
    };
}

#endif /* AGFErrorManager_h */
