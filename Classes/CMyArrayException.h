//
// Created by ilyalezhnin on 31.05.24.
//

#ifndef CMYARRAYEXCEPTION_H
#define CMYARRAYEXCEPTION_H
#include <stdexcept>
#include <string>


class CMyArrayException : public std::invalid_argument
{
public:
    static CMyArrayException OutOfBoundsException();
    static CMyArrayException InvalidNewCapacityException();
private:
    explicit CMyArrayException(std::string const& message);
};


#endif //CMYARRAYEXCEPTION_H
