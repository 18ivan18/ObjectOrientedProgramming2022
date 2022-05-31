#ifndef EVENTWITHFIXEDINTERMISSION_H
#define EVENTWITHFIXEDINTERMISSION_H
#include "Event.h"

class EventWithFixedIntermission : public Event
{
private:
    Time intermissionStart;
    void validate() override;

public:
    EventWithFixedIntermission(const Time &start, const Time &intermissionStart, const Time &end);
    const Time &getIntermissionStart();
    Event *copy() override;
    bool isOngoing(const Time &t);
};

#endif