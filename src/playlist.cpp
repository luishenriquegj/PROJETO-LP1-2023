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

void Playlist::addSong(Node<Music> *music){
    this->musics->add(music);
}

void Playlist::printPlaylistSongs(){
    if(this->musics->head == nullptr) {
            std::cout<<"unable to display playlist, playlist is empty"<<std::endl;
            return;
    }
    Node<Music>* current = this->musics->head;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        std::cout << "--------------------------------"<< std::endl;
        current = current->next;
        sleep(1);
    }
}


