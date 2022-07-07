#ifndef RESIZEABLE_SET_H
#define RESIZEABLE_SET_H
#include <stdexcept>

const int defaultCapacity = 8;

template <typename T>
class ResizeableSet
{
protected:
    int size, capacity;
    T *data;

    virtual int find(const T &elem);
    void resize(int newCapacity);

public:
    ResizeableSet(int capacity = defaultCapacity);
    ResizeableSet(const ResizeableSet &other) = delete;
    ResizeableSet &operator=(const ResizeableSet &other) = delete;
    ~ResizeableSet();

    bool empty();

    bool operator[](const T &el);

    void add(const T &el);
    virtual bool remove(const T &el);
};

template <typename T>
bool ResizeableSet<T>::empty()
{
    return size == 0;
}

template <typename T>
bool ResizeableSet<T>::operator[](const T &el)
{
    return find(el) != -1;
}

template <typename T>
int ResizeableSet<T>::find(const T &elem)
{
    for (size_t i = 0; i < size; i++)
    {
        if (data[i] == elem)
        {
            return i;
        }
    }
    return -1;
}
template <typename T>
void ResizeableSet<T>::resize(int newCapacity)
{
    capacity = newCapacity;
    T *data = new T[capacity];
    for (size_t i = 0; i < size; i++)
    {
        data[i] = this->data[i];
    }
    delete[] this->data;
    this->data = data;
}

template <typename T>
ResizeableSet<T>::ResizeableSet(int capacity) : capacity{capacity}, size{0}, data{new T[capacity]} {}

template <typename T>
ResizeableSet<T>::~ResizeableSet()
{
    delete[] data;
}

template <typename T>
void ResizeableSet<T>::add(const T &el)
{
    if (size == capacity)
    {
        resize(capacity * 2);
    }

    if (!empty() && find(el) != -1)
    {
        throw std::runtime_error("Element already in the set.\n");
    }
    data[size++] = el;
}

template <typename T>
bool ResizeableSet<T>::remove(const T &el)
{
    int idx = find(el);
    if (idx == -1)
    {
        return false;
    }
    for (size_t i = idx; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    size--;

    return true;
}

#endif