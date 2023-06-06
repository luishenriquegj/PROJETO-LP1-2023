#ifndef COMPAREPLAYLIST_H
#define COMPAREPLAYLIST_H

#include "List.h"
#include "Music.h"


/**
* @brief compareLists() é uma função responsável compara todos os itens entre duas listas
* ela recebe como parametros duas listas e retorna true caso ache itens iguais, false caso a as listas sejam completamente diferentes
* @param <Playlist> &list1
* @param <Playlist> &list2
* @return 0;
*/

bool compareLists(List<Music>& list1, List<Music>& list2);

#endif