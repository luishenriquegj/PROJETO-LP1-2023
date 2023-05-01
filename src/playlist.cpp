#include "Playlist.h"
#include "List.h"
#include <string>
#include "Music.h"

using namespace std;

Playlist::Playlist(){
    this->name = "";
}
Playlist::Playlist(string name){
    this->name = "";
}

string Playlist::getKey(){
    return this->name;
};

void Playlist::setName(string name){
    this->name = name;
    
};

void Playlist::addSong(Music &music){
    Node<Music>* newMusic = new Node<Music>({music.getKey(),music.getAuthor()});
    cout<<newMusic<<endl;
    this->musics->add(newMusic);
}


