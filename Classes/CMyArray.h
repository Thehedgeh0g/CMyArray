//
// Created by ilyalezhnin on 31.05.24.
//
#ifndef CMYARRAY_H
#define CMYARRAY_H

#include "CMyArrayIterator.h"

template <typename T>
class CMyArray
{
public:
    CMyArray();

    CMyArray(const CMyArray& other);

    CMyArray(CMyArray&& other) noexcept;

    ~CMyArray();

    void Resize(size_t newSize);

    void Clear();

    [[nodiscard]] size_t Size() const;

    [[nodiscard]] size_t Count() const;

    friend class CMyArrayIterator<T>;

    CMyArrayIterator<T> begin();

    CMyArrayIterator<T> end();

    CMyArrayIterator<T> rbegin();

    CMyArrayIterator<T> rend();

    T& operator[](size_t index) const;

private:
    size_t m_count;
    size_t m_size;
    T* m_data;
};


#endif //CMYARRAY_H
