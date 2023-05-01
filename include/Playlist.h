#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "List.h"
#include "Music.h"
#include <string>
#include <iostream>


class Playlist {  

    private:
        std::string name;
        List <Music>* musics;
    public:
        Playlist();
        Playlist(std::string name);
        std::string getKey();
        void addSong(Music &music);
        void setName(std::string name);
        friend std::ostream& operator<<(std::ostream& os, const Playlist& playlist) {
        os<<"playlsit name:"<< playlist.name<< "\n";
        return os;
        }

};



#endif