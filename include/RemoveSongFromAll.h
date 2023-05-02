#ifndef REMOVESONG_H
#define REMOVESONG_H

#include"Playlist.h"
#include"List.h"
#include <string>


/**
* @brief removeSongFromAll() é uma função responsável remover uma música de todas as Playlists
* ela recebe como parametros uma Lista de playlist que é são as playlist de onde a música ira sair, no caso vai ser 
* retirada de todas as playlist, e uma string key que é o nome da música que será removida de todas as playlist
* @param List<Playlist>& playlist
* @param string key
* @return 0;
*/

int removeSongFromAll(List<Playlist>& playlists, std::string key);

#endif