#include "Registration.h"
#include <exception>
#include <cctype>
#include <cstring>

Registration::Registration(const char *str)
{
    validateBegininigOfReg(str);
    strcpy(reg, str);
}

void Registration::validateBegininigOfReg(const char *str)
{
    int size = strlen(str);

    if (size != 7 && size != 8)
    {
        throw std::exception();
    }
    if (size == 7)
    {
        if (!isUppercaseChar(str[0]))
        {
            throw std::exception();
        }
        validate(str + 1);
    }
    if (size == 8)
    {
        if (!isUppercaseChar(str[0]) || !isUppercaseChar(str[1]))
        {
            throw std::exception();
        }
        validate(str + 2);
    }
}

void Registration::validate(const char *str)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (!isDigit(str[i]))
        {
            throw std::exception();
        }
    }
    for (size_t i = 4; i < 6; i++)
    {
        if (!isUppercaseChar(str[i]))
        {
            throw std::exception();
        }
    }
}

bool Registration::isUppercaseChar(char c)
{
    return c <= 'Z' && c >= 'A';
}

bool Registration::isDigit(char c)
{
    return isdigit(c);
}

Registration &Registration::operator=(const char *str)
{
    validateBegininigOfReg(str);
    strcpy(reg, str);
    return *this;
}

bool Registration::operator==(const Registration &rhs) const
{
    return strcmp(reg, rhs.reg) == 0;
}

const char *Registration::toString() const
{
    return reg;
}