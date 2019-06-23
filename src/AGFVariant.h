//
//  AGFVariant.h
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#ifndef AGFVariant_h
#define AGFVariant_h

#include "AGFIncludes.h"

namespace AGF
{
    namespace details
    {
        struct VariantHolderBase
        {
            virtual ~VariantHolderBase() = default;
            virtual void* copy(const void* rhs) const = 0;
            virtual void destruct(void* rhs) const = 0;
            virtual VariantHolderBase* clone() const = 0;
            virtual const std::type_info& type_info() const = 0;
            virtual bool areEqual(const void* lhs, const void* rhs) const = 0;
        };
        
        template < typename T >
        struct VariantHolder : public VariantHolderBase
        {
            virtual ~VariantHolder() = default;
            virtual void* copy(const void* rhs) const { return new T(reinterpret_cast<const T*>(rhs)); }
            virtual void destruct(void* rhs) const { delete (T*)rhs; }
            virtual VariantHolderBase* clone() const { return new VariantHolder<T>(); }
            virtual const std::type_info& type_info() const { return typeid(T); }
            virtual bool areEqual(const void* lhs, const void* rhs) const { return (const T*)lhs == (const T*)rhs; }
        };
    }
    
    class Variant
    {
        details::VariantHolderBase* m_holder;
        void* m_value;
        
    public:
        
        Variant();
        
        Variant(const Variant& rhs);
        
        Variant(Variant&& rhs);
        
        template < typename T >
        explicit Variant(const T& value)
        {
            m_holder = new details::VariantHolder<T>();
            m_value = m_holder->copy(&value);
            assert(m_value && "no copy available for type.");
        }
        
        ~Variant();
        
        bool isNull() const;
        
        void reset();
        
        template < typename T >
        void reset(const T& value)
        {
            reset();
            m_holder = new details::VariantHolder<T>();
            m_value = m_holder->copy(&value);
        }
        
        template < typename T >
        bool is() const
        {
            if (isNull())
                return false;
            return m_holder->type_info() == typeid(T);
        }
        
        template < typename T >
        T& to()
        {
            if (isNull())
                throw std::runtime_error("null variant tried to be converted.");
            if (!is<T>())
                throw std::runtime_error("bad variant type cast.");
            return *reinterpret_cast<T*>(m_value);
        }
        
        template < typename T >
        const T& to() const
        {
            if (isNull())
                throw std::runtime_error("null variant tried to be converted.");
            if (!is<T>())
                throw std::runtime_error("bad variant type cast.");
            return *reinterpret_cast<const T*>(m_value);
        }
        
        bool operator == (const Variant& rhs) const;
    };
    
    typedef std::map < std::string, Variant > Dictionnary;
}

#endif /* AGFVariant_h */
