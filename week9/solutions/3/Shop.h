#ifndef SHOP_H
#define SHOP_H
#include <cstddef>
#include "Item.cpp"

const int DEFAULT_CAPACITY = 8;

class Shop
{
private:
    size_t size, capacity;
    Item **items;

public:
    Shop(size_t capacity = DEFAULT_CAPACITY);
    Shop(std::fstream &is);
    bool findItem(const Item &);
    bool addItem(const Item &);
    void saveToFile(const char *fileName);

    ~Shop();

    friend std::ostream &operator<<(std::ostream &os, const Shop &s);
};
#endif