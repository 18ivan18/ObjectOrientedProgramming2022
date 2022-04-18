#include "VehicleList.h"

VehicleList::VehicleList(size_t capacity) : mVehicles{new Vehicle *[capacity]}, mSize{0}, mCapacity{capacity}
{
}

void VehicleList::insert(const char *regnum, const char *description)
{
    if (mSize == mCapacity)
    {
        throw std::exception();
    }
    validateUniqueVehicle(regnum);
    mVehicles[mSize++] = new Vehicle(regnum, description);
}

const Vehicle &VehicleList::at(size_t index) const
{
    if (index >= mSize)
    {
        throw std::exception();
    }
    return (*this)[index];
}

bool VehicleList::empty() const
{
    return mSize == 0;
}

std::size_t VehicleList::capacity() const
{
    return mCapacity;
}

std::size_t VehicleList::size() const
{
    return mSize;
}

const Vehicle &VehicleList::operator[](size_t pos) const
{
    return *mVehicles[pos];
}

const Vehicle *VehicleList::find(const Registration &regnum) const
{
    for (size_t i = 0; i < mSize; i++)
    {
        if (*mVehicles[i] == regnum)
        {
            return mVehicles[i];
        }
    }
    return nullptr;
}
VehicleList::~VehicleList()
{
    for (size_t i = 0; i < mSize; i++)
    {
        delete mVehicles[i];
    }
    delete[] mVehicles;
}

void VehicleList::validateUniqueVehicle(const char *str)
{
    for (size_t i = 0; i < mSize; i++)
    {
        if (*mVehicles[i] == str)
        {
            throw std::exception();
        }
    }
}
