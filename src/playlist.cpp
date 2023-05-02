#include "Playlist.h"
#include "List.h"
#include <string>
#include "Music.h"

using namespace std;

/*!
    Playlist() é uma função responsavel por inicilizar a playlist com seu nome vazio.
    Existe uma sobrecarga para que posso ser inicializado também passando o nome da PLaylist;
*/

Playlist::Playlist(){
    this->name = "";
}

Playlist::Playlist(string name){
    this->name = name;
}

/*!
    getKey() é uma função responsavel pegar o elemento nome da Playlist
    Essa função retorna o nome da playlist;
*/

string Playlist::getKey(){
    return this->name;
};
/*!
    addSong() é uma função responsavel por adicionar uma música a uma playlist, essa função recebe como parâmetro um Node do tipo Musica
    e adiciona esse Node a uma Lista de playlist;
    
*/
void Playlist::addSong(Node<Music>*newMusic ) {
    this->data.add(newMusic);
}
/*!
    RemoveSongFromPlayList() é uma função responsavel por remover uma música de uma playlist, essa função recebe como parâmetro uma string
    com o nome da musica 
    e adiciona esse Node a uma Lista de playlist;
    
*/
void Playlist::removeSongFromPlaylist(string key) {
    this->data.removeSong(key);
}


