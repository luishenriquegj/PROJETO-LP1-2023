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


Playlist::Playlist(Playlist *playlistToCopy){
    this->name = playlistToCopy->name;
    this->size = playlistToCopy->size;
    this->data = playlistToCopy->data;
}

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


/**
* @brief getData(), funcao que retorna a data classe playlist.
*/
List<Music> Playlist::getData(){
    return this->data;
}

/**
* @brief getKey(), funcao que retorna o nome  playlist.
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
    this->size +=1;
}

void Playlist::addSong(Playlist&playlist) {
    Node<Music>* current = this->data.tail;
    Node<Music>* aux = playlist.data.head;
    while(aux->next!=nullptr){
        current->next = aux;
        aux = aux->next;
        this->size +=1;
    }
    
    this->data.tail = playlist.data.tail;
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

//3b
void Playlist::removeSongFromPlaylist(Playlist &playlist) {
    Node<Music>* current = this->data.head;
    Node<Music>* current2 = playlist.data.head;
    while(current->next != nullptr){
        if(current->data.getKey() == current2->data.getKey()){
            this->data.removeItem(current->data.getKey());
        }
        if(current2->next== nullptr){
            current2 = playlist.data.head;
            current = this->data.head;
        }else{
            current2 =current2->next;
            current = current->next;
        }
    }
}


