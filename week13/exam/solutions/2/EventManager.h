#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H
#include "Event.h"

class EventManager
{
private:
    int size, capacity;
    Event **events;

    void erase();

public:
    EventManager(int capacity);
    EventManager(const EventManager &other);
    EventManager(EventManager &&other);
    EventManager &operator=(const EventManager &rhs);
    EventManager &operator=(EventManager &&rhs);
    ~EventManager();
    bool addEvent(Event *event);
    int ongoingEvents(const Time &t);
};

#endif