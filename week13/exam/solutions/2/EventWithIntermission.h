#ifndef EventWithIntermission_H
#define EventWithIntermission_H
#include "Event.h"

class EventWithIntermission : public Event
{
protected:
    Time intermissionStart, intermissionEnd;
    void validate() override;

public:
    EventWithIntermission(const Time &start, const Time &intermissionStart, const Time &intermissionend, const Time &end);
    const Time &getIntermissionStart();
    const Time &getIntermissionEnd();
    Event *copy() override;
    bool isOngoing(const Time &t) override;
};

#endif