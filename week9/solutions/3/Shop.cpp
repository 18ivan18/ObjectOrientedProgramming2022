#include "Shop.h"
#include <fstream>

bool Shop::findItem(const Item &item)
{
    for (size_t i = 0; i < size; i++)
    {
        if (*items[i] == item)
        {
            return true;
        }
    }
    return false;
}

bool Shop::addItem(const Item &item)
{
    if (size == capacity)
    {
        return false;
    }
    for (size_t i = 0; i < size; i++)
    {
        if (item.getPrice() > items[i]->getPrice())
        {
            for (size_t j = size; j > i; j--)
            {
                items[j] = items[j - 1];
            }
            items[i] = new Item(item);
            size++;
            return true;
        }
    }
    return items[size++] = new Item(item);
}

void Shop::saveToFile(const char *fileName)
{
    std::ofstream os(fileName);
    if (!os)
    {
        throw std::exception();
    }
    os << *this;
    os.close();
}

Shop::Shop(size_t capacity) : capacity{capacity}, size{0}, items{new Item *[capacity]}
{
}

Shop::Shop(std::fstream &is)
{
    is >> size >> capacity;
    is.ignore();
    items = new Item *[capacity];
    for (size_t i = 0; i < size; i++)
    {
        char name[256];
        is.getline(name, 256, '.');
        double price;
        is >> price;
        is.ignore();
        items[i] = new Item(name, price);
    }
}

void Shop::del()
{
    for (size_t i = 0; i < size; i++)
    {
        delete items[i];
    }
    delete[] items;
}

Shop::~Shop()
{
    del();
}

std::ostream &operator<<(std::ostream &os, const Shop &s)
{
    os << s.size << " " << s.capacity << '\n';
    for (size_t i = 0; i < s.size; i++)
    {
        os << *s.items[i];
    }
    return os;
}

Shop &Shop::operator=(const Shop &rhs)
{
    if (this != &rhs)
    {
        del();
        size = rhs.size;
        capacity = rhs.capacity;
        items = new Item *[capacity];
        for (size_t i = 0; i < size; i++)
        {
            items[i] = new Item(*rhs.items[i]);
        }
    }
    return *this;
}

Shop::Shop(const Shop &s) : capacity{s.capacity}, size{s.size}, items{new Item *[s.size]}
{
    for (size_t i = 0; i < size; i++)
    {
        items[i] = new Item(*s.items[i]);
    }
}
