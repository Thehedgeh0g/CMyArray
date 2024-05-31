//
// Created by ilyalezhnin on 31.05.24.
//

#include "CMyArray.h"

#include "CMyArrayException.h"

template <typename T>
CMyArray<T>::CMyArray(): m_count(0), m_size(1), m_data(nullptr)
{
}

template <typename T>
CMyArray<T>::CMyArray(const CMyArray& other): m_count(other.m_count), m_size(other.m_size), m_data(other.m_data)
{
}

template <typename T>
CMyArray<T>::CMyArray(CMyArray&& other) noexcept: m_count(other.m_count), m_size(other.m_size), m_data(other.m_data)
{
    other.Clear();
}

template <typename T>
CMyArray<T>::~CMyArray()
{
    Clear();
}

template <typename T>
void CMyArray<T>::Resize(const size_t newSize)
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

template <typename T>
void CMyArray<T>::Clear()
{
    delete[] m_data;
    m_size = 1;
    m_count = 0;
}

template <typename T>
size_t CMyArray<T>::Size() const
{
    return m_size;
}

template <typename T>
size_t CMyArray<T>::Count() const
{
    return m_count;
}

template <typename T>
CMyArrayIterator<T> CMyArray<T>::begin()
{
    return {m_data, false};
}

template <typename T>
CMyArrayIterator<T>CMyArray<T>::end()
{
    return {nullptr, false};
}

template <typename T>
CMyArrayIterator<T> CMyArray<T>::rbegin()
{
    return {nullptr, true};
}

template <typename T>
CMyArrayIterator<T> CMyArray<T>::rend()
{
    return {m_data, true};
}

template <typename T>
T& CMyArray<T>::operator[](size_t index) const
{
    auto it = this->begin();
    return *it[index];
}
