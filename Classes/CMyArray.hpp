//
// Created by ilyalezhnin on 31.05.24.
//
#ifndef CMYARRAY_H
#define CMYARRAY_H

#include "CMyArrayException.h"
#include "CMyArrayIterator.hpp"

template <typename T>
class CMyArray
{
public:
    CMyArray(): m_count(0), m_size(1), m_data(nullptr)
    {
    }

    CMyArray(const CMyArray& other)
    {
        m_size = other.m_size;
        m_count = other.m_count;
        m_data = new T[m_size];
        for (size_t i = 0; i < m_size; i++)
        {
            m_data[i] = other.m_data[i];
        }
    }

    CMyArray(CMyArray&& other) noexcept
    {
        m_data = new T[other.m_size];
        std::swap(m_size, other.m_size);
        std::swap(m_count, other.m_count);
        std::swap(m_data, other.m_data);
    }

    ~CMyArray()
    {
        Clear();
    }

    void Resize(size_t newSize)
    {
        if (newSize < m_count)
        {
            throw CMyArrayException::InvalidNewCapacityException();
        }
        T* newData = new T[newSize];
        for (size_t i = 0; i < newSize; i++)
        {
            newData[i] = (i < m_count) ? m_data[i] : T();
        }
        delete[] m_data;
        m_data = newData;
        m_size = newSize;
    }

    void Clear()
    {
        delete[] m_data;
        m_size = 1;
        m_count = 0;
    }

    [[nodiscard]] size_t Size() const
    {
        return m_size;
    }

    [[nodiscard]] size_t Count() const
    {
        return m_count;
    }

    CMyArrayIterator<T> begin()
    {
        return {m_data, false};
    }

    CMyArrayIterator<T> end()
    {
        return {m_data + m_size, false};
    }

    CMyArrayIterator<T> rbegin()
    {
        return {m_data + m_size, true};
    }

    CMyArrayIterator<T> rend()
    {
        return {m_data, true};
    }

    T& operator[](size_t index)
    {
        if (index >= m_size)
        {
            throw CMyArrayException::OutOfBoundsException();
        }
        return m_data[index];
    };

    const T& operator[](size_t index) const
    {
        if (index >= m_size)
        {
            throw CMyArrayException::OutOfBoundsException();
        }
        return m_data[index];
    };

    void pushBack(T value)
    {
        if (m_count + 1 == m_size)
        {
            Resize(m_size * 2);
        }
        m_data[m_count] = value;
        m_count++;
    }


    CMyArray& operator=(const CMyArray& other)
    {
        if (std::addressof(other) == this)
        {
            return *this;
        }
        m_count = other.m_count;
        m_size = other.m_size;
        m_data = new T[m_size];
        for (size_t i = 0; i < m_size; i++)
        {
            m_data[i] = other.m_data[i];
        }
        return *this;
    }

    CMyArray& operator=(CMyArray&& other) noexcept
    {
        if (std::addressof(other) == this)
        {
            return *this;
        }
        delete[] m_data;
        m_data = nullptr;
        m_size = 2;
        m_count = 0;
        std::swap(m_data, other.m_data);
        std::swap(m_size, other.m_size);
        std::swap(m_count, other.m_count);
        return *this;
    }

private:
    size_t m_count;
    size_t m_size;
    T* m_data;
};


#endif //CMYARRAY_H
