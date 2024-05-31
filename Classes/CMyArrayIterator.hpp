//
// Created by ilyalezhnin on 31.05.24.
//

#ifndef CMYARRAYCMyArrayIterator_H
#define CMYARRAYCMyArrayIterator_H

#include <iterator>

template <typename T>
class CMyArrayIterator : public std::iterator<std::input_iterator_tag, T>
{
public:
    typedef CMyArrayIterator self_type;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::forward_iterator_tag iterator_category;
    typedef int difference_type;

    CMyArrayIterator(T* ptr, bool isReversed = false) : m_ptr(ptr), m_isReversed(isReversed)
    {
    }


    CMyArrayIterator(const CMyArrayIterator& other) : m_ptr(other.m_ptr), m_isReversed(other.m_isReversed)
    {
    }


    CMyArrayIterator(CMyArrayIterator&& other) noexcept : m_ptr(other.m_ptr), m_isReversed(other.m_isReversed)
    {
        other.m_ptr = nullptr;
    }

    ~CMyArrayIterator() = default;

    CMyArrayIterator& operator=(const CMyArrayIterator& other)
    {
        m_ptr = other.m_ptr;
        return *this;
    }

    T& operator[](size_t index) const
    {
        if (m_ptr + index == nullptr)
        {
            throw CMyArrayException::OutOfBoundsException();
        }
        return *(m_ptr + index);
    }

    T& operator*() const
    {
        return *m_ptr;
    }

    CMyArrayIterator operator+(int num) const
    {
        CMyArrayIterator temp(*this);
        temp += num;
        return temp;
    }

    CMyArrayIterator operator-(int num) const
    {
        CMyArrayIterator temp(*this);
        temp -= num;
        return temp;
    }

    CMyArrayIterator& operator+=(int num)
    {
        try
        {
            m_ptr += num;
        }
        catch (...)
        {
            throw CMyArrayException::InvalidNewCapacityException();
        }
        return *this;
    }

    CMyArrayIterator& operator-=(int num)
    {
        try
        {
            m_ptr -= num;
        }
        catch (...)
        {
            throw CMyArrayException::InvalidNewCapacityException();
        }
        return *this;
    }

    friend CMyArrayIterator operator+(int num, CMyArrayIterator iter)
    {
        return num + iter;
    }

    friend CMyArrayIterator operator-(int num, CMyArrayIterator iter)
    {
        return num - iter;
    }

    bool operator==(const CMyArrayIterator& other) const
    {
        return m_ptr == other.m_ptr;
    }

    bool operator!=(const CMyArrayIterator& other) const
    {
        return m_ptr != other.m_ptr;
    }

    bool operator<(const CMyArrayIterator& other) const
    {
        return m_ptr < other.m_ptr;
    }

    bool operator>(const CMyArrayIterator& other) const
    {
        return m_ptr > other.m_ptr;
    }

    bool operator<=(const CMyArrayIterator& other) const
    {
        return m_ptr <= other.m_ptr;
    }

    bool operator>=(const CMyArrayIterator& other) const
    {
        return m_ptr >= other.m_ptr;
    }

    CMyArrayIterator& operator++()
    {
        if (m_isReversed)
        {
            PtrDecrement();
        }
        else
        {
            PtrIncrement();
        }
        return *this;
    }

    CMyArrayIterator operator++(int)
    {
        CMyArrayIterator temp = *this;
        ++(*this);
        return temp;
    }

    CMyArrayIterator& operator--()
    {
        if (m_isReversed)
        {
            PtrIncrement();
        }
        else
        {
            PtrDecrement();
        }
        return *this;
    }

    CMyArrayIterator operator--(int)
    {
        CMyArrayIterator temp = *this;
        --(*this);
        return temp;
    }

private:
    T* m_ptr;
    bool m_isReversed;

    void PtrIncrement()
    {
        try
        {
            ++m_ptr;
        }
        catch (...)
        {
            throw CMyArrayException::InvalidNewCapacityException();
        }
    }

    void PtrDecrement()
    {
        try
        {
            --m_ptr;
        }
        catch (...)
        {
            throw CMyArrayException::InvalidNewCapacityException();
        }
    }
};


#endif //CMYARRAYCMyArrayIterator_H
