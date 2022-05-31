#ifndef AIR_TRAVEL_H
#define AIR_TRAVEL_H
#include "String.h"
#include "Travel.h"

class AirTravel : public Travel
{
private:
    String flightNumber;
    int duration;

public:
    AirTravel(String flightNumber, int duration);
    int getDuration() override;
    void print() override;
};

#endif