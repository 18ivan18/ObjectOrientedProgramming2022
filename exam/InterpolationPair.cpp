#include "InterpolationPair.h"
#include <iostream>

void InterpolationPair::validate()
{
    interpolations = TextProcessor("%{", "}").getAllTags(value);

    if (interpolations.empty())
    {
        // must have atleast 1 interpolation
        throw std::exception();
    }

    for (size_t i = 0; i < interpolations.size(); i++)
    {
        validateInterpolatedStringsCorrectness(interpolations[i].tagString);
        for (size_t j = 0; j < interpolations.size(); j++)
        {
            if (i != j && interpolations[i].tagString == interpolations[j].tagString)
            {
                // interpolations must be unique
                throw std::exception();
            }
        }
    }
}

void InterpolationPair::validateInterpolatedStringsCorrectness(const std::string &s)
{
    if (s.size() == 2)
    {
        // empty interpolation string
        throw std::exception();
    }
    for (size_t i = 2; i < s.size(); i++)
    {
        if (!islower(s[i]))
        {
            // only small english letters allowed
            throw std::exception();
        }
    }
}

InterpolationPair::InterpolationPair(const std::string &key, const std::string &value) : SimplePair(key, value)
{
    validate();
}

std::string InterpolationPair::interpolate(const std::string &value)
{
    std::string output;
    std::vector<char[100]> replacements(interpolations.size());
    for (int i = 0; i < interpolations.size(); i++)
    {

        std::cout << interpolations[i].tagString.c_str() + 2 << ": ";
        std::cin.getline(replacements[i], 100);
    }
    int interpolationIndex = 0;
    bool print = true;
    for (auto &&i : value)
    {
        if (i == '%')
        {
            print = false;
            output += replacements[interpolationIndex++];
        }
        if (print)
        {
            output += i;
        }
        if (i == '}')
        {
            print = true;
        }
    }
    return output;
}

void InterpolationPair::printValue()
{
    std::cout << interpolate(value) << '\n';
}

SimplePair *InterpolationPair::clone()
{
    return new InterpolationPair(*this);
}
