#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <List.h>
#include <string>


class Playlist {    
    public:
        std::string name;
        List <Music*> musics;
        Playlist();
        Playlist(List <Music*> musics,string name);

};



#endif