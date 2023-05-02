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
        std::string getKey();
        void addSong(Node<Music>* newMusic );
        void removeSongFromPlaylist(std::string key);
        friend std::ostream& operator<<(std::ostream& os, const Playlist& playlist) {
        os << "Playlist Name: " << playlist.name << "\n";
        Node<Music>* current = playlist.data.head;
        os << "musics:" << "\n";
        while (current != nullptr) {
            os << current->data.getKey() << "\n";
            current = current->next;
        }
        return os;
    }

};



#endif