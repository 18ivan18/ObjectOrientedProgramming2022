#include "Time.h"
#include <iostream>

Time::Time(unsigned hh, unsigned mm, unsigned ss) : hh{hh}, mm{mm}, ss{ss}
{
    if (hh > 24)
    {
        // std::cerr << "Hours are from 0 to 24\nDefault value of 0 is set.\n";
        // hh = 0;
        throw std::exception();
    }
    if (mm >= 60)
    {
        // std::cerr << "Minutes are from 0 to 60\nDefault value of 0 is set.\n";
        // mm = 0;
        throw std::exception();
    }
    if (ss >= 60)
    {
        // std::cerr << "Seconds are from 0 to 60\nDefault value of 0 is set.\n";
        // ss = 0;
        throw std::exception();
    }
}

Time Time::operator+(const Time &time)
{
    int seconds = (ss + time.ss);
    int minutes = (mm + time.mm + seconds / 60);
    int hours = (hh + time.hh + minutes / 60);
    return Time(hours, minutes % 60, seconds % 60);
}

Time Time::operator-(const Time &time)
{
    if (*this < time)
    {
        // std::cerr << "You cannot subtract from an earlier time\nReturning default.";
        // return Time();
        throw std::exception();
    }
    int seconds = (ss + 60 - time.ss);
    int minutes = (mm + seconds / 60 - 1 + 60 - time.mm);
    int hours = (hh + minutes / 60 - 1 - time.hh);
    return Time(hours, minutes % 60, seconds % 60);
}

bool operator<(const Time &lhs, const Time &rhs)
{
    return lhs.hh < rhs.hh || (lhs.hh == rhs.hh && lhs.mm < rhs.mm) || (lhs.hh == rhs.hh && lhs.mm == rhs.mm && lhs.ss < rhs.ss);
}
bool operator>(const Time &lhs, const Time &rhs) { return rhs < lhs; }
bool operator<=(const Time &lhs, const Time &rhs) { return !(lhs > rhs); }
bool operator>=(const Time &lhs, const Time &rhs) { return !(lhs < rhs); }

std::ostream &operator<<(std::ostream &os, const Time &rhs)
{
    os << rhs.hh << ":" << (rhs.mm < 10 ? "0" : "") << rhs.mm;
    return os;
}

bool operator==(const Time &lhs, const Time &rhs)
{
    return lhs.hh == rhs.hh && lhs.mm == rhs.mm;
}
