#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item
{
private:
    char *name;
    double price;

public:
    Item(const char *, double);
    Item(const Item &);
    Item &operator=(const Item &);
    ~Item();

    double getPrice() const;

    bool operator==(const Item &) const;
    friend std::ostream &operator<<(std::ostream &os, const Item &item);
    friend std::istream &operator>>(std::istream &is, Item &item);
};

#endif