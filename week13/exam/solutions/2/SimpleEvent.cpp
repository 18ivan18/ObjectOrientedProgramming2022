#include "SimpleEvent.h"
#include <exception>
#include <iostream>

SimpleEvent::SimpleEvent(const Time &start, const Time &end) : Event(start, end)
{
    try
    {
        validate();
    }
    catch (const std::exception &e)
    {
        // std::cerr << e.what() << '\n';
        this->start = this->end = Time();
    }
}

void SimpleEvent::validate()
{
    if (end - start > Time(2))
    {
        throw std::exception();
    }
}

Event *SimpleEvent::copy()
{
    return new SimpleEvent(*this);
}
