#include "Playlist.h"
#include "List.h"
#include <string>
#include "Music.h"

using namespace std;

Playlist::Playlist(){
    this->name = "";
}

Playlist::Playlist(string name){
    this->name = name;
}

string Playlist::getKey(){
    return this->name;
};

void Playlist::setName(string name){
    this->name = name;
    
};


void Playlist::addSong(Node<Music>*newMusic ) {
    this->data.add(newMusic);
}
void Playlist::removeSongFromPlaylist(string key) {
    this->data.removeSong(key);
}


