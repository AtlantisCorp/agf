//
//  AGFVariant.cpp
//  agf
//
//  Created by jacques tronconi on 02/06/2019.
//  Copyright © 2019 jacques tronconi. All rights reserved.
//

#include "AGFVariant.h"

namespace AGF
{
    Variant::Variant(): m_holder(nullptr), m_value(nullptr)
    {
        
    }
    
    Variant::Variant(const Variant& rhs): m_holder(nullptr), m_value(nullptr)
    {
        if (!rhs.isNull())
        {
            m_holder = rhs.m_holder->clone();
            m_value = m_holder->copy(rhs.m_value);
            assert(m_value && "no copy available for type.");
        }
    }
    
    Variant::Variant(Variant&& rhs): m_holder(nullptr), m_value(nullptr)
    {
        using std::swap;
        swap(m_holder, rhs.m_holder);
        swap(m_value, rhs.m_value);
    }
    
    Variant::~Variant()
    {
        if (m_holder && m_value)
        {
            m_holder->destruct(m_value);
            delete m_holder;
        }
    }
    
    bool Variant::isNull() const
    {
        return !m_holder && !m_value;
    }
    
    void Variant::reset()
    {
        if (!isNull())
        {
            m_holder->destruct(m_value);
            delete m_holder;
            
            m_holder = nullptr;
            m_value = nullptr;
        }
    }
    
    bool Variant::operator==(const Variant &rhs) const
    {
        if (isNull() && rhs.isNull())
            return true;
        else if (isNull() || rhs.isNull())
            return false;
        else if (m_holder->type_info() != rhs.m_holder->type_info())
            return false;
        else
            return m_holder->areEqual(m_value, rhs.m_value);
    }
}
