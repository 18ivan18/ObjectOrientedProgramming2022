#ifndef TIME_H
#define TIME_H
#include <iostream>

class Time
{
private:
    unsigned hh, mm, ss;

public:
    Time(unsigned hh = 0, unsigned mm = 0, unsigned ss = 0);
    Time operator+(const Time &);
    Time operator-(const Time &);
    friend bool operator<(const Time &lhs, const Time &rhs);
    friend bool operator>(const Time &lhs, const Time &rhs);
    friend bool operator<=(const Time &lhs, const Time &rhs);
    friend bool operator>=(const Time &lhs, const Time &rhs);
    friend bool operator==(const Time &lhs, const Time &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Time &rhs);
};

#endif