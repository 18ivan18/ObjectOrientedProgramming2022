#include "EventWithFixedIntermission.h"
#include <exception>
#include <iostream>

EventWithFixedIntermission::EventWithFixedIntermission(const Time &start, const Time &intermissionStart, const Time &end) : Event(start, end), intermissionStart{intermissionStart}
{
    try
    {
        validate();
    }
    catch (const std::exception &e)
    {
        // std::cerr << e.what() << '\n';
        this->start = this->end = this->intermissionStart = Time();
    }
}

void EventWithFixedIntermission::validate()
{
    if (start > intermissionStart || intermissionStart + Time(0, 20) > end)
    {
        throw std::exception();
    }
}

const Time &EventWithFixedIntermission::getIntermissionStart()
{
    return intermissionStart;
}

Event *EventWithFixedIntermission::copy()
{
    return new EventWithFixedIntermission(*this);
}

bool EventWithFixedIntermission::isOngoing(const Time &t)
{
    return (t >= start && t < intermissionStart) || (t >= intermissionStart + Time(0, 20) && t < end);
}
