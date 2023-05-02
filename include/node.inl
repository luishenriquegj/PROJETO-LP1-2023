
/**
* @brief Node() é uma estrutura de dados que contém um template T data e um ponteiro Next.
* @param T que é do tipo template<typename T > .  
*/

#include "Node.h"

template <typename T> 
Node<T>::Node( T data){
    this->data = data;
    this->next = nullptr;
}
