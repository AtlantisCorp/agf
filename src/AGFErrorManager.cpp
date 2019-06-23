//
//  AGFErrorManager.cpp
//  agf
//
//  Created by jacques tronconi on 01/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#include "AGFErrorManager.h"

namespace AGF
{
    std::string ErrorManager::format(const char *f, ...)
    {
        va_list ap;
        va_start(ap, f);
        char* buffer = new char[2048];
        memset(buffer, 0, 2048);
        vsnprintf(buffer, 2048, f, ap);
        va_end(ap);
        
        std::string string(buffer);
        delete [] buffer;
        return string;
    }
    
    OstreamErrorManager::OstreamErrorManager(std::ostream& output): m_output(output)
    {
        
    }
    
    OstreamErrorManager::~OstreamErrorManager()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_output.flush();
    }
    
    void OstreamErrorManager::onError(const char *clss, const char *type, const char *message)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_output << "[" << clss << "]" << "(" << type << ") " << message << std::endl;
    }
}
