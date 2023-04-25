#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Node.h"
#include "List.h"
#include <string>

template <typename T> 

class Playlist {    
    public:
        
        List list;
        std::string nome;
        Playlist(List list, std::string nome);
        Playlist(List list);
        

};
        #include"list.inl"


#endif