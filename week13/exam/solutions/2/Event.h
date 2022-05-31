#ifndef EVENT_H
#define EVENT_H
#include "Time.h"

class Event
{
protected:
    Time start, end;
    virtual void validate();

public:
    Event(const Time &start, const Time &end);
    const Time &getStart();
    const Time &getEnd();
    virtual Event *copy();
    virtual bool isOngoing(const Time &t);
};

#endif