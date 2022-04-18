#ifndef SONG_H
#define SONG_H
#include <cstddef>
#include <fstream>

class Song
{
private:
    char *singerName, id[10];
    size_t songNumber, chartsNumber;

    bool validateId(const char[10]);

public:
    Song(const char *, const char[10], size_t songNumber, size_t chartsNumber);
    Song(const Song &);
    Song &operator=(const Song &);
    ~Song();

    size_t getSongNumber() const;
    size_t getChartsNumber() const;
    const char *getId() const;

    void print() const;

    void save(std::ofstream &os) const;
};

#endif