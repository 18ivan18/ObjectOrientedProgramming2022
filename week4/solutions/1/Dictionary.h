#ifndef TASK_1_DICTIONARY
#define TASK_1_DICTIONARY

#include "Record.h"
#define MAX_CAPACITY 500

class Dictionary
{
private:
    Record data[MAX_CAPACITY];
    int size = 0;

public:
    void init(Record *, int);
    void print() const;
    bool add(const Record &);
    bool remove(const char *);
    char *findMeaning(const char *) const;
    char *getByIndex(int) const;
    void sort();
    void deleteDynamic();
};

#endif