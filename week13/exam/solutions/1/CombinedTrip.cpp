#include "CombinedTrip.h"
#include <iostream>

CombinedTrip::CombinedTrip(String flightNumber, int airDuration, const char regnum[4], int distance, int carDuration, String destinations, int freeTime)
    : AirTravel(flightNumber, airDuration), CarTravel(regnum, distance, carDuration), freeTime{freeTime}, destinations(destinations)
{
}
int CombinedTrip::getDuration()
{
    return AirTravel::getDuration() + CarTravel::getDuration() + freeTime;
}
void CombinedTrip::print()
{
    AirTravel::print();
    CarTravel::print();
    std::cout << "The free time is " << freeTime << " and the destinations were: " << destinations
              << '\n';
}