//
//  AGFFileLoaderLibrary.cpp
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#include "AGFFileLoaderLibrary.h"

namespace AGF
{
    void FileLoaderLibrary::addLoader(const FileLoaderPtr &loader)
    {
        if (!loader)
            throw std::runtime_error("null loader sent.");
        
        FileLoaderPtr found = findLoader(loader->name());
        if (found)
            throw std::runtime_error("loader already registered.");
        
        std::lock_guard<std::mutex> lock(m_mutex);
        m_fileloaders.push_back(loader);
    }
    
    void FileLoaderLibrary::removeLoader(const std::string &name)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        
        auto iter = std::find_if(m_fileloaders.begin(), m_fileloaders.end(), [name](auto& rhs){
            return rhs->name() == name;
        });
        
        if (iter != m_fileloaders.end())
            m_fileloaders.erase(iter);
    }
    
    FileLoaderPtr FileLoaderLibrary::findLoader(const std::string &name)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        
        auto iter = std::find_if(m_fileloaders.begin(), m_fileloaders.end(), [name](auto& rhs){
            return rhs->name() == name;
        });
        
        return iter == m_fileloaders.end() ? nullptr : *iter;
    }
    
    void FileLoaderLibrary::reset()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_fileloaders.clear();
    }
}
