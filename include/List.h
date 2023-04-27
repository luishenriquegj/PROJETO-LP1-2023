#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <string>

template <typename T> 

class List {    
    public:
        Node<T>* head;
        Node<T>* tail;
        Node<T>* data;
        List();
        int print();
        void add(T data);
        int findSong();
        int removeSong();
        ~List();
        

};
        #include"list.inl"


#endif