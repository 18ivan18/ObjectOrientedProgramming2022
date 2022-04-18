#ifndef VEHICLE_LIST_H
#define VEHICLE_LIST_H

#include "Vehicle.cpp"

class VehicleList
{
private:
    size_t mSize, mCapacity;
    Vehicle **mVehicles;

    void validateUniqueVehicle(const char *str);

public:
    VehicleList(size_t capacity);
    void insert(const char *regnum, const char *description);
    const Vehicle &at(size_t index) const;
    const Vehicle &operator[](size_t pos) const;
    bool empty() const;
    std::size_t size() const;
    std::size_t capacity() const;
    const Vehicle *find(const Registration &regnum) const;
    ~VehicleList();
};

#endif