/*!
    Node() é uma estrutura de dados que contém um template T data e um ponteiro Next;
    É inicializada com data de qualquer tipo, e o next é inicializado sendo Nullptr para iniciar apontando para nada!

*/
#include "Node.h"

template <typename T> 
Node<T>::Node( T data){
    this->data = data;
    this->next = nullptr;
}
