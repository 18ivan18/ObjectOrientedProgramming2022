#include "Event.h"
#include <exception>
#include <iostream>

Event::Event(const Time &start, const Time &end) : start{start}, end{end}
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

void Event::validate()
{
    if (start > end)
    {
        throw std::exception();
    }
}

const Time &Event::getStart()
{
    return start;
}

const Time &Event::getEnd()
{
    return end;
}

Event *Event::copy()
{
    return new Event(*this);
}

bool Event::isOngoing(const Time &t)
{
    return t <= end && t >= start;
}
