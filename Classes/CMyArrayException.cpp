//
// Created by ilyalezhnin on 31.05.24.
//

#include "CMyArrayException.h"

const std::string OUT_OF_BOUNDS_EXCEPTION_MSG = "Out of bounds";
const std::string INVALID_NEW_CAPACITY_EXCEPTION_MSG = "Invalid new capacity, it can't be less than old";

CMyArrayException CMyArrayException::OutOfBoundsException()
{
    return CMyArrayException(OUT_OF_BOUNDS_EXCEPTION_MSG);
}

CMyArrayException CMyArrayException::InvalidNewCapacityException()
{
    return CMyArrayException(INVALID_NEW_CAPACITY_EXCEPTION_MSG);
}

CMyArrayException::CMyArrayException(std::string const& message) : std::invalid_argument(message)
{
}
