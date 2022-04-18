#include "Song.h"
#include <cstring>
#include <iostream>

bool Song::validateId(const char[10]) { return true; }

Song::Song(const char *singersName, const char albumId[10], size_t songNumber, size_t chartsNumber) : singerName{nullptr}, songNumber{songNumber}, chartsNumber{chartsNumber}
{
    validateId(albumId);
    singerName = new char[strlen(singersName) + 1];
    strcpy(singerName, singersName);
    strcpy(id, albumId);
}

Song::Song(const Song &other) : Song(other.singerName, other.id, other.songNumber, other.chartsNumber) {}

Song &Song::operator=(const Song &rhs)
{
    // ...
    return *this;
}

Song::~Song()
{
    delete[] singerName;
}

const char *Song::getId() const
{
    return id;
}

size_t Song::getSongNumber() const
{
    return songNumber;
}

void Song::print() const
{
    std::cout << singerName << " " << songNumber << " " << chartsNumber << " " << id << '\n';
}

size_t Song::getChartsNumber() const
{
    return chartsNumber;
}

void Song::save(std::ofstream &os) const
{
    int size = strlen(singerName);
    os.write((char *)&size, sizeof(size));
    os.write(singerName, size);
    os.write(id, sizeof(id));
    os.write((char *)&songNumber, sizeof(songNumber));
    os.write((char *)&chartsNumber, sizeof(chartsNumber));
}
