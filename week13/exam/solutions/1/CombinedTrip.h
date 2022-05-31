#ifndef COMBINED_TRIP
#define COMBINED_TRIP
#include "String.h"
#include "AirTravel.h"
#include "CarTravel.h"

class CombinedTrip : public AirTravel, public CarTravel
{
private:
    String destinations;
    int freeTime;

public:
    CombinedTrip(String flightNumber, int airDurtaion, const char regnum[4], int distance, int carDuration, String, int);
    int getDuration() override;
    void print();
};

#endif