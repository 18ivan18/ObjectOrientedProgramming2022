#ifndef MUSIC_ALBUM_H
#define MUSIC_ALBUM_H
#include "Song.cpp"

class MusicAlbum
{
private:
    char id[10], dateTime[16];
    size_t size, capacity = 20;
    Song **songs;

public:
    MusicAlbum(const char id[10], const char dateTime[16]);
    MusicAlbum(const MusicAlbum &);
    MusicAlbum &operator=(const MusicAlbum &);
    ~MusicAlbum();

    int getSongCount() const;
    bool operator>(const MusicAlbum &) const;

    void print() const;

    friend bool newSong(const Song &s, MusicAlbum &ma);

    // serialize binary
    void saveToFile(const char *fileName) const;
    // deserialize binary
    MusicAlbum(const char *fileName);
};

#endif
