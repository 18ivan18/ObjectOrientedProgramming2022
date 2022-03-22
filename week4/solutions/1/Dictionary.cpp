#include "Dictionary.h"
#include <iostream>
#include <cstring>
void Dictionary::init(Record *array, int size)
{
    this->size = size;
    for (size_t i = 0; i < size; i++)
    {
        data[i] = array[i].copy();
    }
}

void Dictionary::print() const
{
    for (size_t i = 0; i < size; i++)
    {
        data[i].print();
    }
}

bool Dictionary::add(const Record &r)
{
    if (size == MAX_CAPACITY)
    {
        return false;
    }
    data[size++] = r.copy();
    return true;
}

bool Dictionary::remove(const char *word)
{
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(word, data[i].getWord()) == 0)
        {
            for (size_t j = i; j < size - 1; j++)
            {
                data[j] = data[j + 1];
            }
            data[size - 1].deleteDynamic();
            size--;
            return true;
        }
    }

    return false;
}

char *Dictionary::findMeaning(const char *word) const
{
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(data[i].getWord(), word) == 0)
        {
            return data[i].getMeaning();
        }
    }

    return nullptr;
}

char *Dictionary::getByIndex(int index) const
{
    if (index > size)
    {
        return nullptr;
    }
    return data[index].getMeaning();
}

template <typename T>
void swap(T *xp, T *yp)
{
    T temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Dictionary::sort()
{
    int n = size;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(data[j].getWord(), data[j + 1].getWord()) > 0)
            {
                swap(data + j, data + j + 1);
            }
        }
    }
}

void Dictionary::deleteDynamic()
{
    for (size_t i = 0; i < size; i++)
    {
        data[i].deleteDynamic();
    }
}