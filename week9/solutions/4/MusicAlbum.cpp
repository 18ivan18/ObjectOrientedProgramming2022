#include "MusicAlbum.h"
#include <fstream>

MusicAlbum::MusicAlbum(const char id[10], const char dateTime[16]) : size{0}, songs{new Song *[capacity]}
{
    strcpy(this->id, id);
    strcpy(this->dateTime, dateTime);
}

MusicAlbum::MusicAlbum(const MusicAlbum &other) : size{other.size}, capacity{other.capacity}, songs{new Song *[other.size]}
{
    strcpy(id, other.id);
    strcpy(dateTime, other.dateTime);
    for (size_t i = 0; i < capacity; i++)
    {
        if (other.songs[i])
        {
            songs[i] = new Song(*other.songs[i]);
        }
    }
}

MusicAlbum &MusicAlbum::operator=(const MusicAlbum &rhs)
{
    if (this != &rhs)
    {
        // TODO: implement
    }
    return *this;
}

MusicAlbum::~MusicAlbum()
{
    for (size_t i = 0; i < capacity; i++)
    {
        delete songs[i];
    }
}

bool newSong(const Song &s, MusicAlbum &ma)
{
    if (strcmp(ma.id, s.getId()) != 0)
    {
        return false;
    }
    ma.songs[s.getSongNumber()] = new Song(s);
    ma.size++;
    return true;
}

int MusicAlbum::getSongCount() const
{
    return size;
}

void MusicAlbum::print() const
{
    for (size_t i = 0; i < capacity; i++)
    {
        if (songs[i])
        {
            songs[i]->print();
        }
    }
}

bool MusicAlbum::operator>(const MusicAlbum &other) const
{
    int thiSum = 0, otherSum = 0;
    for (size_t i = 0; i < capacity; i++)
    {
        if (songs[i])
        {
            thiSum += songs[i]->getChartsNumber();
        }
    }
    for (size_t i = 0; i < other.capacity; i++)
    {
        if (other.songs[i])
        {
            otherSum += other.songs[i]->getChartsNumber();
        }
    }
    return thiSum < otherSum;
}

void MusicAlbum::saveToFile(const char *fileName) const
{
    std::string name = std::string(fileName) + ".data";
    std::ofstream os(name.c_str(), std::ios::binary);
    if (!os)
    {
        throw std::exception();
    }
    os.write((char *)&size, sizeof(size));
    os.write((char *)&capacity, sizeof(capacity));
    os.write(id, sizeof(id));
    os.write(dateTime, sizeof(dateTime));
    for (size_t i = 0; i < capacity; i++)
    {
        if (songs[i])
        {
            songs[i]->save(os);
        }
    }

    os.close();
}

MusicAlbum::MusicAlbum(const char *fileName)
{
    std::string name = std::string(fileName) + ".data";
    std::ifstream is(name.c_str(), std::ios::binary);
    if (!is)
    {
        throw std::exception();
    }
    is.read((char *)&size, sizeof(size));
    is.read((char *)&capacity, sizeof(capacity));
    songs = new Song *[capacity];
    is.read(id, sizeof(id));
    is.read(dateTime, sizeof(dateTime));
    for (size_t i = 0; i < size; i++)
    {
        int songSingerSize;
        is.read((char *)&songSingerSize, sizeof(songSingerSize));
        char *singerName = new char[songSingerSize + 1];
        is.read(singerName, songSingerSize);
        char id[10];
        is.read(id, sizeof(id));
        size_t songNumber;
        is.read((char *)&songNumber, sizeof(songNumber));
        size_t chartsNumber;
        is.read((char *)&chartsNumber, sizeof(chartsNumber));
        // std::cout << songSingerSize << " " << singerName << " " << id << " " << songNumber << " " << chartsNumber << '\n';
        songs[songNumber] = new Song(singerName, id, songNumber, chartsNumber);
        delete[] singerName;
    }

    is.close();
}
