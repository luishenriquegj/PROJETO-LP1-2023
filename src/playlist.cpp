#include "Playlist.h"
#include "List.h"
#include <string>
#include "Music.h"

using namespace std;
/**
* @brief Construtor padrão da clase Playlist, a classe playlista é formada 
* por uma string com o nome uma Lista de Musica chamada data.
* é uma função responsavel por inicilizar a playlist com seu nome vazio.
* Existe Uma sobrecarga do construtor Playlist para que ela possa ser inicializado também passando o nome da PLaylist.
* @param name é o nome da Playlist.
*/

Playlist::Playlist(){
    this->name = "";
    this->size = 0;
}

Playlist::Playlist(string name){
    this->name = name;
    this->size = 1;
}
/**
* @brief getKey() é uma função responsavel pegar o elemento nome da Playlist
* @return Essa função retorna o nome da playlist;
*/

string Playlist::getKey(){
    return this->name;
};

/**
* @brief addSong() é uma função responsavel por adicionar um Node Musica a uma Lista de Playlist.
* @param Node<Musica>* newMusic
*/
void Playlist::addSong(Node<Music>*newMusic ) {
    this->data.add(newMusic);
    this ->size +=1;
}

/**
* @brief RemoveSongFromPlayList() é uma função responsavel por remover uma música de uma playlist, 
* recebendo uma string com o nome da musica, para conseguir remover essa música das playlists
* @param string key.
*/
void Playlist::removeSongFromPlaylist(string key) {
    if(this->size > 0){
        this->data.removeItem(key);
        this->size -=1;
    }else {
        cout<<"unable to remove a song from an empty playlist"<<endl;
    }
}


