#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include "Playlist.h"
#include <string>

template <typename T> 

class List {    
    public:
        Node<T>* head;
        Node<T>* tail;
        List();
        int print();
        //passa end memoria
        void add(Node<T> *newNode);
        int printItem();
        Node<T>* findItem();
        int removeSong();
        ~List();
        

};
        #include"list.inl"


#endif