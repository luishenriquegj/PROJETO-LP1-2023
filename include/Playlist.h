#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "List.h"
#include "Music.h"
#include <string>
#include <iostream>


class Playlist {  

    private:
        std::string name;
        List <Music> data;
    public:
        Playlist();
        Playlist(std::string name);
        void setName(std::string name); 
        std::string getKey();
        void addSong(Node<Music>* newMusic );
        friend std::ostream& operator<<(std::ostream& os, const Playlist& playlist) {
        os << "Playlist Name: " << playlist.name << "\n";
        return os;
        }

};



#endif