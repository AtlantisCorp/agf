//
//  AGFBuffer.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFBuffer_h
#define AGFBuffer_h

#include "AGFIncludes.h"

namespace AGF
{
    enum class BufferRole
    {
        Vertex,
        Index,
        Uniform
    };
    
    enum class BufferUsage
    {
        Static, Dynamic, Stream
    };
    
    class Buffer
    {
    public:
        //! @brief Default destructor.
        virtual ~Buffer() = default;
        
        //! @brief Returns the role of this buffer.
        virtual BufferRole role() const = 0;
        
        //! @brief Returns the usage of this buffer.
        virtual BufferUsage usage() const = 0;
        
        //! @brief Returns the size of this buffer.
        virtual std::size_t size() const = 0;
        
        //! @brief Updates the internal data in this buffer.
        //!
        //!     @param offset
        //!     The offset in the buffer to emplace data. Zero corresponds to the beginning of this buffer.
        //!     @param size
        //!     The size of the data to place in the buffer. The total size of the buffer will be offset + size + 1.
        //!     @param data
        //!     The data to place in this buffer.
        //!
        //! @return True on success, false otherwise.
        virtual bool emplace(std::uintptr_t offset, std::size_t size, const void* data) = 0;
        
        //! @brief Locks the buffer and returns a pointer to it.
        virtual const void* lockForRead(std::uintptr_t offset) const = 0;
        
        //! @brief Locks the buffer for writing and returns a writable pointer to it.
        virtual void* lockForWrite(std::uintptr_t offset) = 0;
        
        //! @brief Unlocks the buffer if it was locked for reading. The buffer is left unmodified.
        virtual void unlockForRead() const = 0;
        
        //! @brief Unlocks the buffer if it was locked for writing. The buffer is considered modified.
        virtual void unlockForWrite() = 0;
        
        //! @brief Returns true if the buffer has been modified.
        virtual bool isModified() const = 0;
        
        //! @brief Tells the buffer its related content has been updated and this buffer shouldn't be considered
        //! as dirty anymore.
        virtual void clean() = 0;
    };
    
    typedef std::shared_ptr<Buffer> BufferPtr;
}

#endif /* AGFBuffer_h */
