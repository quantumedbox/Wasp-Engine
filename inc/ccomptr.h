#pragma once

#include <cstddef>
#include <utility>

template<class TInterface>
class CComPtr
{
private:
    TInterface* m_pointer;
public:
    CComPtr(const CComPtr& c) noexcept
    {
        m_pointer = c.m_pointer;
        if (m_pointer != nullptr)
            m_pointer->AddRef();
    }

    CComPtr& operator= (const CComPtr& c) noexcept
    {
        if (c.m_pointer != m_pointer) {
            if (m_pointer != nullptr)
                Release();
            m_pointer = c.m_pointer;
            if (m_pointer != nullptr)
                m_pointer->AddRef();
        }
        return *this;
    }

    CComPtr(CComPtr&& c) noexcept
    {
        m_pointer = std::exchange(c.m_pointer, nullptr);
    }

    CComPtr& operator= (CComPtr&& c) noexcept
    {
        m_pointer = std::move(c.m_pointer);
        return *this;
    }

    void* operator new(std::size_t) = delete;
    void* operator new[](std::size_t) = delete;

    void operator delete(void *ptr) = delete;
    void operator delete[](void *ptr) = delete;

    CComPtr() noexcept
    {
        m_pointer = nullptr;
    }

    CComPtr(TInterface* pointer)
    {
        if (pointer != nullptr)
            pointer->AddRef();
        m_pointer = pointer;
    }

    ~CComPtr()
    {
        if (m_pointer != nullptr) {
            m_pointer->Release();
            m_pointer = nullptr;
        }
    }

    void Attach(TInterface* pointer) noexcept
    {
        m_pointer = pointer;
    }

    void Release()
    {
        this->~CComPtr();
    }

    operator TInterface*() noexcept
    {
        return m_pointer;
    }

    operator TInterface*() const noexcept
    {
        return m_pointer;
    }

    TInterface& operator*() noexcept
    {
        return *m_pointer;
    }

    TInterface& operator*() const noexcept
    {
        return *m_pointer;
    }

    TInterface** operator&() noexcept
    {
        return &m_pointer;
    }

    TInterface** operator&() const noexcept
    {
        return &m_pointer;
    }

    TInterface* operator->() noexcept
    {
        return m_pointer;
    }

    TInterface* operator->() const noexcept
    {
        return m_pointer;
    }

};
