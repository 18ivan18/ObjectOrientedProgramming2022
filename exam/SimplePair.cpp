#include "SimplePair.h"
#include <iostream>

void SimplePair::validate()
{
    for (auto &&i : key)
    {
        if (!islower(i) && i != '_')
        {
            throw std::exception();
        }
    }
}

SimplePair::SimplePair(const std::string &key, const std::string &value) : key{key}, value{value}
{
    validate();
}

SimplePair *SimplePair::clone()
{
    return new SimplePair(*this);
}

void SimplePair::printValue()
{
    std::cout << value << '\n';
}

bool SimplePair::operator==(const SimplePair &sp)
{
    return key == sp.key;
}

bool SimplePair::operator==(const std::string &key)
{
    return this->key == key;
}

SimplePair::~SimplePair()
{
}
