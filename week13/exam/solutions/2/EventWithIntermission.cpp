#include "EventWithIntermission.h"
#include <exception>
#include <iostream>

EventWithIntermission::EventWithIntermission(const Time &start, const Time &intermissionStart, const Time &intermissionEnd, const Time &end) : Event(start, end), intermissionStart{intermissionStart}, intermissionEnd{intermissionEnd}
{
    try
    {
        validate();
    }
    catch (const std::exception &e)
    {
        // std::cerr << e.what() << '\n';
        this->start = this->end = this->intermissionStart = this->intermissionEnd = Time();
    }
}

void EventWithIntermission::validate()
{
    const Time intermissionTime = intermissionEnd - intermissionStart;

    if (intermissionTime > Time(1) || intermissionTime < Time(0, 30))
    {
        throw std::exception();
    }

    if (end - start - intermissionTime > Time(6))
    {
        throw std::exception();
    }
}

const Time &EventWithIntermission::getIntermissionStart()
{
    return intermissionStart;
}

const Time &EventWithIntermission::getIntermissionEnd()
{
    return intermissionEnd;
}

Event *EventWithIntermission::copy()
{
    return new EventWithIntermission(*this);
}

bool EventWithIntermission::isOngoing(const Time &t)
{
    return (t >= start && t <= intermissionStart) || (t >= intermissionEnd && t <= end);
}
