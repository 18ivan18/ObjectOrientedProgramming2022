#include "EventManager.h"

EventManager::EventManager(int capacity) : size{0}, capacity{capacity}, events{new Event *[capacity]} {}

EventManager::EventManager(const EventManager &other) : size{other.size}, capacity{other.capacity}, events{new Event *[capacity]}
{
    for (size_t i = 0; i < size; i++)
    {
        events[i] = other.events[i]->copy();
    }
}

EventManager::EventManager(EventManager &&other) : size{other.size}, capacity{other.capacity}, events{other.events}
{
    other.events = nullptr;
    other.size = 0;
    other.capacity = 0;
}

EventManager &EventManager::operator=(const EventManager &rhs)
{
    if (this != &rhs)
    {
        erase();
        size = rhs.size;
        capacity = rhs.capacity;
        events = new Event *[capacity];
        for (size_t i = 0; i < size; i++)
        {
            events[i] = rhs.events[i]->copy();
        }
    }
    return *this;
}

EventManager &EventManager::operator=(EventManager &&rhs)
{
    size = rhs.size;
    capacity = rhs.capacity;
    events = rhs.events;

    rhs.events = nullptr;
    rhs.size = 0;
    rhs.capacity = 0;
    return *this;
}

EventManager::~EventManager()
{
    erase();
}

bool EventManager::addEvent(Event *event)
{
    if (size == capacity)
    {
        return false;
    }
    events[size++] = event->copy();
    return true;
}

void EventManager::erase()
{
    for (size_t i = 0; i < size; i++)
    {
        delete events[i];
    }
    delete[] events;
}

int EventManager::ongoingEvents(const Time &t)
{
    int cnt = 0;
    for (size_t i = 0; i < size; i++)
    {
        cnt += events[i]->isOngoing(t);
    }
    return cnt;
}
