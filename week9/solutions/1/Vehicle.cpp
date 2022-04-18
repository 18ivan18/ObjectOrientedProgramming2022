#include "Vehicle.h"

Vehicle::Vehicle(const char *regnum, const char *description) : reg(regnum), description(description)
{
}

bool Vehicle::operator==(const Registration &regnum) const
{
    return reg == regnum;
}
