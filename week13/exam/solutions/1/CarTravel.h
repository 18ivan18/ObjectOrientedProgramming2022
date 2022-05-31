#ifndef CAR_TRAVEL_H
#define CAR_TRAVEL_H
#include "String.h"
#include "Travel.h"

class CarTravel : public Travel
{
private:
    int distance, duration;
    char regNumb[5];

public:
    CarTravel(const char regnum[5], int distance, int duration);
    CarTravel(const CarTravel &other);
    CarTravel &operator=(const CarTravel &rhs);
    int getDuration() override;
    void print() override;
};

#endif