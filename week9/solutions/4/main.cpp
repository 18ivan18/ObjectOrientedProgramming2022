#include "MusicAlbum.cpp"
#include <iostream>

int main()
{
    MusicAlbum ma("679ADZ8", "05-07-2019 19:30");
    newSong({"Поли Генова", "679ADZ8", 6, 10}, ma);
    newSong({"Владимир Ампов - Графа", "679ADZ8", 2, 15}, ma);
    std::cout << ma.getSongCount() << '\n';
    ma.print();
    ma.saveToFile("album");
    MusicAlbum ma1("album");
    ma1.print();
}