//
//  AGFModuleManager.h
//  agf
//
//  Created by jacques tronconi on 07/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFModuleManager_h
#define AGFModuleManager_h

#include "AGFModule.h"
#include "AGFErrorManager.h"

namespace AGF
{
    class ModuleManager
    {
        std::vector < std::string > m_modulesDirs;
        ErrorManager& m_errManager;
        mutable std::mutex m_mutex;
        std::vector < Module* > m_modules;
        
    public:
        ModuleManager(std::vector < std::string > const& dirs, ErrorManager& errmanager);
        
        //! @brief Initializes a new instance of a class found in one of the modules.
        //! If multiple modules defines a prototype for this class, the first definition is used. You may ensure
        //! only one prototype is loaded through your modules.
        template < class Class, typename... Args >
        std::shared_ptr < Class > initialize(Args&&... args)
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            
            for (auto module : m_modules)
            {
                if (module->has(typeid(Class)))
                {
                    return module->initialize<Class>(std::forward<Args>(args)...);
                }
            }
            
            auto message = m_errManager.format("Class %s not found in any module.", typeid(Class).name());
            m_errManager.onError("ModuleManager", "NoModuleFound", message.data());
            
            return nullptr;
        }
        
        std::uint32_t fillLibrary(FileLoaderLibrary& library) const;
    };
}

#endif /* AGFModuleManager_h */
