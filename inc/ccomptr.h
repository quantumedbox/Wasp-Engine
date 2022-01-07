#pragma once

#include <cstddef>

template<class TInterface>
class CComPtr
{
private:
    TInterface* m_pointer;
public:
    // CComPtr(const CComPtr&) = delete; // Copy constructor
    // CComPtr& operator= (const CComPtr&) = delete; // Copy assignment
    // CComPtr(CComPtr&&) = delete; // Move constructor
    // CComPtr& operator= (CComPtr&&) = delete; // Move assignment

    void* operator new(std::size_t) = delete;
    void* operator new[](std::size_t) = delete;

    void operator delete(void *ptr) = delete;
    void operator delete[](void *ptr) = delete;

    CComPtr()
    {
        m_pointer = nullptr;
    }

    CComPtr(TInterface* pointer)
    {
        m_pointer = pointer;
    }

    ~CComPtr()
    {
        if (m_pointer)
        {
            m_pointer->Release();
            m_pointer = nullptr;
        }
    }

    Attach(TInterface* pointer)
    {
        m_pointer = pointer;
    }

    operator TInterface*()
    {
        return m_pointer;
    }

    operator TInterface*() const
    {
        return m_pointer;
    }

    TInterface& operator*()
    {
        return *m_pointer;
    }

    TInterface& operator*() const
    {
        return *m_pointer;
    }

    TInterface** operator&()
    {
        return &m_pointer;
    }

    TInterface** operator&() const
    {
        return &m_pointer;
    }

    TInterface* operator->()
    {
        return m_pointer;
    }

    TInterface* operator->() const
    {
        return m_pointer;
    }

    void Release()
    {
        ~CComPtr();
    }
};
