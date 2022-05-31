#include "CarTravel.h"
#include <cstring>
#include <iostream>

CarTravel::CarTravel(const char regnum[5], int distance, int duration) : distance{distance}, duration{duration}
{
    strcpy(regNumb, regnum);
}
CarTravel::CarTravel(const CarTravel &other) : CarTravel(other.regNumb, other.distance, other.duration)
{
}
CarTravel &CarTravel::operator=(const CarTravel &rhs)
{
    if (this != &rhs)
    {
        strcpy(regNumb, rhs.regNumb);
        distance = rhs.distance;
        duration = rhs.duration;
    }
    return *this;
}
int CarTravel::getDuration()
{
    return duration;
}

void CarTravel::print()
{
    std::cout << "Car travel durtaion is " << duration << ", the regnum is: " << regNumb << " and the durtaion is " << duration << '\n';
}