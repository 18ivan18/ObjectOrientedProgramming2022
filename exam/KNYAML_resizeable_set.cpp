#include "KNYAML_resizeable_set.h"
#include <iostream>

KNYAMLSpec::KNYAMLSpec(std::vector<SimplePair *> pairs) : ResizeableSet()
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        this->add(pairs[i]->clone());
    }
}

KNYAMLSpec::KNYAMLSpec(const KNYAMLSpec &other) : ResizeableSet()
{
    for (size_t i = 0; i < other.size; i++)
    {
        this->add(other.data[i]->clone());
    }
}

KNYAMLSpec &KNYAMLSpec::operator=(const KNYAMLSpec &rhs)
{
    if (this != &rhs)
    {
        free();
        capacity = defaultCapacity;
        data = new SimplePair *[capacity];

        for (size_t i = 0; i < rhs.size; i++)
        {
            this->add(rhs.data[i]->clone());
        }
    }
    return *this;
}

void KNYAMLSpec::free()
{
    for (size_t i = 0; i < size; i++)
    {
        delete data[i];
    }

    delete[] data;
    data = nullptr;
    size = 0;
}

KNYAMLSpec::~KNYAMLSpec()
{
    free();
}

void KNYAMLSpec::operator[](const std::string &key)
{
    for (size_t i = 0; i < size; i++)
    {
        if (*data[i] == key)
        {
            data[i]->printValue();
        }
    }
}

int KNYAMLSpec::find(SimplePair *const &elem)
{
    for (size_t i = 0; i < size; i++)
    {
        if (*data[i] == *elem)
        {
            return i;
        }
    }
    return -1;
}

bool KNYAMLSpec::remove(int idx)
{
    if (idx == -1)
    {
        return false;
    }
    delete data[idx];
    for (size_t i = idx; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    data[size - 1] = nullptr;
    size--;

    return true;
}

bool KNYAMLSpec::remove(const std::string &key)
{
    int idx = -1;
    for (size_t i = 0; i < size; i++)
    {
        if (*data[i] == key)
        {
            idx = i;
            break;
        }
    }
    return remove(idx);
}

bool KNYAMLSpec::remove(SimplePair *const &el)
{
    return remove(find(el));
}