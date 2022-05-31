#ifndef SIMPLE_EVENT_H
#define SIMPLE_EVENT_H
#include "Event.h"

class SimpleEvent : public Event
{
protected:
    void validate() override;

public:
    SimpleEvent(const Time &start, const Time &end);
    Event *copy() override;
};

#endif