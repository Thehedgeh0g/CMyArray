//
// Created by ilyalezhnin on 31.05.24.
//

#ifndef CMYARRAYCMyArrayIterator_H
#define CMYARRAYCMyArrayIterator_H

#include <iterator>
#include "CMyArray.h"


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

    CMyArrayIterator(T* ptr, bool isReversed = false);

    CMyArrayIterator(const CMyArrayIterator& other);

    CMyArrayIterator(CMyArrayIterator&& other) noexcept;

    ~CMyArrayIterator();

    CMyArrayIterator& operator=(const CMyArrayIterator& other);

    T& operator[](size_t index) const;

    T& operator*() const;

    CMyArrayIterator operator+(int num) const;

    CMyArrayIterator operator-(int num) const;

    CMyArrayIterator& operator+=(int num);

    CMyArrayIterator& operator-=(int num);

    friend CMyArrayIterator operator+(int num, CMyArrayIterator iter)
    {
        return num += iter;
    }

    friend CMyArrayIterator operator-(int num, CMyArrayIterator iter)
    {
        return num -= iter;
    }

    bool operator==(const CMyArrayIterator& other) const;

    bool operator!=(const CMyArrayIterator& other) const;

    bool operator<(const CMyArrayIterator& other) const;

    bool operator>(const CMyArrayIterator& other) const;

    bool operator<=(const CMyArrayIterator& other) const;

    bool operator>=(const CMyArrayIterator& other) const;

    CMyArrayIterator& operator++();

    CMyArrayIterator operator++(int);

    CMyArrayIterator& operator--();

    CMyArrayIterator operator--(int);

private:
    T* m_ptr;
    bool m_isReversed;

    void PtrIncrement();
    void PtrDecrement();
};


#endif //CMYARRAYCMyArrayIterator_H
