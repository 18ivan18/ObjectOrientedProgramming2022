#include "AirTravel.h"
#include <iostream>

AirTravel::AirTravel(String flightNumber, int duration) : flightNumber(flightNumber), duration{duration} {}

int AirTravel::getDuration() { return duration; }

void AirTravel::print()
{
    std::cout << "Air travel durtaion is " << duration << " and the flight number is: " << flightNumber << '\n';
}
