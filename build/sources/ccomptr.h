// Copyright (c) .NET Foundation and contributors. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

/*
The MIT License (MIT)

Copyright (c) 2016 Microsoft

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

template<class TInterface>
class CComPtr
{
private:
    TInterface* pointer;
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
        this->pointer = nullptr;
    }

    CComPtr(TInterface* pointer)
    {
        this->pointer = pointer;
    }

    ~CComPtr()
    {
        if (this->pointer)
        {
            this->pointer->Release();
            this->pointer = nullptr;
        }
    }

    operator TInterface*()
    {
        return this->pointer;
    }

    operator TInterface*() const
    {
        return this->pointer;
    }

    TInterface& operator *()
    {
        return *this->pointer;
    }

    TInterface& operator *() const
    {
        return *this->pointer;
    }

    TInterface** operator&()
    {
        return &this->pointer;
    }

    TInterface** operator&() const
    {
        return &this->pointer;
    }

    TInterface* operator->()
    {
        return this->pointer;
    }

    TInterface* operator->() const
    {
        return this->pointer;
    }

    void Release()
    {
        this->~CComPtr();
    }
};
