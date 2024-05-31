//
// Created by ilyalezhnin on 31.05.24.
//

#include "CMyArrayIterator.h"

#include "CMyArrayException.h"

template <typename T>
CMyArrayIterator<T>::CMyArrayIterator(T* ptr, bool isReversed) : m_ptr(ptr), m_isReversed(isReversed) {}

template <typename T>
CMyArrayIterator<T>::CMyArrayIterator(const CMyArrayIterator& other) : m_ptr(other.m_ptr), m_isReversed(other.m_isReversed) {}

template <typename T>
CMyArrayIterator<T>::CMyArrayIterator(CMyArrayIterator&& other) noexcept : m_ptr(other.m_ptr), m_isReversed(other.m_isReversed) {
    other.m_ptr = nullptr;
}

template <typename T>
CMyArrayIterator<T>::~CMyArrayIterator() = default;

template <typename T>
CMyArrayIterator<T>& CMyArrayIterator<T>::operator=(const CMyArrayIterator& other) {
    m_ptr = other.m_ptr;
    return *this;
}

template <typename T>
T& CMyArrayIterator<T>::operator[](size_t index) const {
    if (m_ptr + index == nullptr) {
        throw std::out_of_range("Iterator out of bounds");
    }
    return *(m_ptr + index);
}

template <typename T>
T& CMyArrayIterator<T>::operator*() const {
    return *m_ptr;
}

template <typename T>
CMyArrayIterator<T> CMyArrayIterator<T>::operator+(int num) const {
    CMyArrayIterator temp(*this);
    temp += num;
    return temp;
}

template <typename T>
CMyArrayIterator<T> CMyArrayIterator<T>::operator-(int num) const {
    CMyArrayIterator temp(*this);
    temp -= num;
    return temp;
}

template <typename T>
CMyArrayIterator<T>& CMyArrayIterator<T>::operator+=(int num) {
    m_ptr += num;
    return *this;
}

template <typename T>
CMyArrayIterator<T>& CMyArrayIterator<T>::operator-=(int num) {
    m_ptr -= num;
    return *this;
}

template <typename T>
bool CMyArrayIterator<T>::operator==(const CMyArrayIterator& other) const {
    return m_ptr == other.m_ptr;
}

template <typename T>
bool CMyArrayIterator<T>::operator!=(const CMyArrayIterator& other) const {
    return m_ptr != other.m_ptr;
}

template <typename T>
bool CMyArrayIterator<T>::operator<(const CMyArrayIterator& other) const {
    return m_ptr < other.m_ptr;
}

template <typename T>
bool CMyArrayIterator<T>::operator>(const CMyArrayIterator& other) const {
    return m_ptr > other.m_ptr;
}

template <typename T>
bool CMyArrayIterator<T>::operator<=(const CMyArrayIterator& other) const {
    return m_ptr <= other.m_ptr;
}

template <typename T>
bool CMyArrayIterator<T>::operator>=(const CMyArrayIterator& other) const {
    return m_ptr >= other.m_ptr;
}

template <typename T>
CMyArrayIterator<T>& CMyArrayIterator<T>::operator++() {
    if (m_isReversed) {
        PtrDecrement();
    } else {
        PtrIncrement();
    }
    return *this;
}

template <typename T>
CMyArrayIterator<T> CMyArrayIterator<T>::operator++(int) {
    CMyArrayIterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
CMyArrayIterator<T>& CMyArrayIterator<T>::operator--() {
    if (m_isReversed) {
        PtrIncrement();
    } else {
        PtrDecrement();
    }
    return *this;
}

template <typename T>
CMyArrayIterator<T> CMyArrayIterator<T>::operator--(int) {
    CMyArrayIterator temp = *this;
    --(*this);
    return temp;
}

template <typename T>
void CMyArrayIterator<T>::PtrIncrement() {
    ++m_ptr;
}

template <typename T>
void CMyArrayIterator<T>::PtrDecrement() {
    --m_ptr;
}