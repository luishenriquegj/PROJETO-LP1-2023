#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "List.h"
#include "Music.h"
#include <string>


class Playlist {    
    public:
        std::string name;
        List <Music> musics;
        Playlist();
        Playlist(List <Music> musics,std::string name);
        void add(List <Music> p1,std::string name);

};



#endif