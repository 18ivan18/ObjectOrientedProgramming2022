#include "Item.h"
#include <cstring>
#include <iomanip>

Item::Item(const char *name, double price) : name{new char[strlen(name) + 1]}, price{price}
{
    strcpy(this->name, name);
}

Item::Item(const Item &other) : Item(other.name, other.price)
{
}

Item &Item::operator=(const Item &rhs)
{
    if (this != &rhs)
    {
        delete[] name;
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
        price = rhs.price;
    }
    return *this;
}

Item::~Item()
{
    delete[] name;
}

double Item::getPrice() const
{
    return price;
}

bool Item::operator==(const Item &item) const
{
    return price == item.price && strcmp(item.name, name) == 0;
}

std::ostream &operator<<(std::ostream &os, const Item &item)
{
    os << item.name << "." << std::setprecision(2) << std::fixed << item.price << '\n';
    return os;
}

std::istream &operator>>(std::istream &is, Item &item)
{
    char name[256];
    is.getline(name, 256, '.');
    double price;
    is >> price;
    item = Item(name, price);
    return is;
}