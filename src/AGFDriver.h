//
//  AGFDriver.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFDriver_h
#define AGFDriver_h

#include "AGFBuffer.h"
#include "AGFVariant.h"
#include "AGFDrawIndexedCommand.h"
#include "AGFDrawCommand.h"
#include "AGFResult.h"

namespace AGF
{
    /** @brief Defines an object that handles a specific rendering API (like OpenGL, Metal, Vulkan, D3D, ...).
     *
     *  The driver is responsible for the management of all objects created specifically for an API. Take as an example
     *  the buffers on your GPU. Those buffers are created inside the driver's mechanism, and are destroyed when the
     *  driver doesn't need them anymore.
     *
     *  The buffers are all attached to a buffer's id. This id corresponds to the GF::Buffer instance they are created
     *  from. When the original GF::Buffer is modified (dirty, or touched or whatever) the driver's buffer is updated
     *  to ensure its data is up-to-date.
     *
     */
    class Driver
    {
        //! @brief The buffers created by this driver and associated to another buffer.
        std::map < std::uint64_t, BufferPtr > m_associated_buffers;
        
        //! @brief The buffers created by this driver but not associated to any other buffer.
        std::vector < BufferPtr > m_buffers;
        
        //! @brief Protects the data.
        mutable std::mutex m_mutex;
        
    public:
        
        //! @brief Shortcut for return types. 
        template < typename T >
        using R = Result < T >;
        
        //! @brief Constructs a new driver.
        //! Default implementation does nothing, but derived classes should initialize their data. A dictionnary is
        //! always available to ensure custom arguments are available to the front user.
        Driver(const Dictionnary& args);
        
        //! @brief Deleted copy constructor.
        Driver(const Driver&) = delete;
        
        //! @brief Deleted move constructor.
        Driver(Driver&&) = delete;
        
        //! @brief Destructs the driver.
        virtual ~Driver() = default;
        
        //! @brief Creates a new buffer associated to the logical buffer.
        virtual BufferPtr makeBuffer(const BufferPtr& rhs) = 0;
        
        //! @brief Creates a new buffer not associated to any logical buffer.
        //!
        //!     @param role
        //!     The role of the buffer. \see BufferRole for more explanation.
        //!     @param usage
        //!     The previsionned usage for this buffer. A buffer used to stream data may use the BUStream while a static
        //!     buffer (buffer that won't be modified) should use BUStatic.
        //!     @param size
        //!     The size of the data, in bytes. If this size is not available, this function fails and returns a null
        //!     buffer (no exception is thrown).
        //!     @param data
        //!     The data that may be stored in this buffer. If null, the buffer is filled with zeroes.
        //!
        //!     @return The new buffer or a null pointer.
        //!
        virtual BufferPtr makeBuffer(BufferRole role, BufferUsage usage, std::size_t size, const void* data) = 0;
        
        //! @brief Creates a draw command.
        virtual R<std::shared_ptr<DrawCommand>> makeDrawCommand(const VertexDescriptor& desc, const BufferPtr& buffer) = 0;
        
        //! @brief Creates a draw indexed command.
        virtual R<std::shared_ptr<DrawIndexedCommand>> makeDrawIndexedCommand(const VertexDescriptor& desc,
                                                                              const BufferPtr& buffer,
                                                                              const IndexDescriptor& idesc,
                                                                              const BufferPtr& ibuffer) = 0;
    };
}

#endif /* AGFDriver_h */
