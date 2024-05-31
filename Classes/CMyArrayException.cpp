//
// Created by ilyalezhnin on 31.05.24.
//

#include "CMyArrayException.h"

CMyArrayException CMyArrayException::OutOfBoundsException()
{
    return CMyArrayException("Out of bounds");
}

CMyArrayException CMyArrayException::InvalidNewCapacityException()
{
    return CMyArrayException("Invalid new capacity, it can't be less than old");
}

CMyArrayException::CMyArrayException(std::string const& message) : std::invalid_argument(message)
{
}
